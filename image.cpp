/*
* 创建日期：2016-08-16
* 最后修改：2016-12-28
* 作    者：syf
* 描    述：
*/
#include "image.h"


/*
* 参数：
* 返回：
* 功能：构造函数
*/
Image::Image(QObject *parent)
	: QObject(parent)
{
	
}


/*
* 参数：
* 返回：
* 功能：析构函数
*/
Image::~Image()
{

}


/*
* 参数：path--图像文件路径
* 返回：0--图像打开失败
*       1--图像打开成功
* 功能：根据path指定的路径和文件名，打开图像
*/
bool Image::SetImage(const QString& path, int flag)
{
	bool state = false;

	// 用于支持中文路径
	QTextCodec* codec = QTextCodec::codecForName("gb18030");
	string fileName = codec->fromUnicode(path).data();

	m_imageSrc.release();

	if (1 == flag)
	{
		m_imageSrc = imread(fileName, IMREAD_GRAYSCALE);
	}
	else if (0 == flag)
	{
		
		m_imageSrc = imread(fileName, IMREAD_COLOR);
	}
	else
	{
		return state;
	}

	if (NULL != m_imageSrc.data)
	{
		state = true;

		m_imageSrc.copyTo(m_image);
	}

	return state;	
}


/*
* 参数：image--Mat类型的图像
* 返回：0--图像打开失败
*       1--图像打开成功
* 功能：复制Mat类型的图像
*/
bool Image::SetImage(const Mat& image)
{
	bool state = false;

	if (image.data)
	{
		image.copyTo(m_imageSrc);
		state = true;
	}

	return state;
}


/*
* 参数：
* 返回：
* 功能：返回原图
*/
Mat& Image::GetImageSrc()
{
	return m_imageSrc;
}


/*
* 参数：
* 返回：
* 功能：返回处理过的中间图
*/
Mat& Image::GetImage()
{
	return m_image;
}


/*
* 参数：x-列坐标，y-行坐标，size-窗口大小
* 返回：Roi区域
* 功能：从打开的图像中获取指定位置，指定大小的Roi区域
*/
Mat& Image::GetRoi(int x, int y, int size)
{
	if (m_image.data)
	{
		if (x > m_image.cols - 1)
		{
			x = m_image.cols - 1;
		}

		if (y > m_image.rows - 1)
		{
			y = m_image.rows - 1;
		}

		if (x + size > m_image.cols - 1)
		{
			size = 1;
		}

		if (y + size > m_image.rows - 1)
		{
			size = 1;
		}
		m_imageRoi = m_image(Rect(x, y, size, size));
	}

	return m_imageRoi;
}


/*
* 参数：input-输入图像，out-输出图像，k-插值倍数
* 返回：1--成功，0-失败
* 功能：图像通过双线性插值扩大k倍
*/
bool Image::LinearInterpolation(Mat &in, Mat &out, int k)
{
	bool state = false;

	if (NULL == in.data)
	{
		return state;
	}

	out.release();

	int row0 = in.rows;
	int col0 = in.cols;

	int row1 = row0 + (row0 - 1) * (k - 1);
	int col1 = col0 + (col0 - 1) * (k - 1);

	out = Mat(row1, col1, in.type());

	if (1 == in.channels())
	{
		for (int i = 0; i < row0 - 1; i++)
		{
			uchar *pIn1 = in.ptr<uchar>(i);
			uchar *pIn2 = in.ptr<uchar>(i + 1);

			vector<uchar*> pOut;

			for (int l = 0; l < k; l++)
			{
				pOut.push_back(out.ptr<uchar>(i * k + l));
			}

			for (int j = 0; j < col0 - 1; j++)
			{
				uchar pix00 = *(pIn1 + j);
				uchar pix01 = *(pIn1 + j + 1);
				uchar pix10 = *(pIn2 + j);
				uchar pix11 = *(pIn2 + j + 1);

				*(pOut[0] + j * k) = pix00;
				*(pOut[0] + (j + 1) * k) = pix01;

				for (int n = 1; n < k; n++)
				{
					double q1 = (k - n) / static_cast<double>(k);
					double q2 = n / static_cast<double>(k);

					*(pOut[n] + j * k) = static_cast<uchar>(q1 * pix00 + q2 * pix10);
					*(pOut[n] + (j + 1) * k) = static_cast<uchar>(q1 * pix01 + q2 * pix11);
				}

				for (int n = 0; n < k; n++)
				{
					uchar pix0 = *(pOut[n] + j * k);
					uchar pix1 = *(pOut[n] + (j + 1) * k);

					for (int m = 1; m < k; m++)
					{
						double p1 = (k - m) / static_cast<double>(k);
						double p2 = m / static_cast<double>(k);

						*(pOut[n] + j * k + m) = static_cast<uchar>(p1 * pix0 + p2 * pix1);
					}
				}
			}
		}

		uchar* pIn = in.ptr<uchar>(row0 - 1);
		uchar* pOut = out.ptr<uchar>(row1 - 1);
		for (int j = 0; j < col0 - 1; j++)
		{
			uchar pix0 = *(pIn + j);
			uchar pix1 = *(pIn + j + 1);

			*(pOut + j * k) = pix0;

			for (int m = 1; m < k; m++)
			{
				double p1 = (k - m) / static_cast<double>(k);
				double p2 = m / static_cast<double>(k);

				*(pOut + j * k + m) = static_cast<uchar>(p1 * pix0 + p2 * pix1);
			}
		}
	}
	else if (3 == in.channels())
	{
		for (int i = 0; i < row0 - 1; i++)
		{
			uchar *pIn1 = in.ptr<uchar>(i);
			uchar *pIn2 = in.ptr<uchar>(i + 1);

			vector<uchar*> pOut;

			for (int l = 0; l < k; l++)
			{
				pOut.push_back(out.ptr<uchar>(i * k + l));
			}

			for (int j = 0; j < col0 - 1; j++)
			{
				uchar b00 = *(pIn1 + 3 * j);
				uchar b01 = *(pIn1 + 3 * (j + 1));
				uchar b10 = *(pIn2 + 3 * j);
				uchar b11 = *(pIn2 + 3 * (j + 1));

				uchar g00 = *(pIn1 + 3 * j + 1);
				uchar g01 = *(pIn1 + 3 * (j + 1) + 1);
				uchar g10 = *(pIn2 + 3 * j + 1);
				uchar g11 = *(pIn2 + 3 * (j + 1) + 1);

				uchar r00 = *(pIn1 + 3 * j + 2);
				uchar r01 = *(pIn1 + 3 * (j + 1) + 2);
				uchar r10 = *(pIn2 + 3 * j + 2);
				uchar r11 = *(pIn2 + 3 * (j + 1) + 2);

				*(pOut[0] + 3 * j * k) = b00;
				*(pOut[0] + 3 * j * k + 1) = g00;
				*(pOut[0] + 3 * j * k + 2) = r00;
				*(pOut[0] + 3 * (j + 1) * k) = b01;
				*(pOut[0] + 3 * (j + 1) * k + 1) = g01;
				*(pOut[0] + 3 * (j + 1) * k + 2) = r01;

				for (int n = 1; n < k; n++)
				{
					double q1 = (k - n) / static_cast<double>(k);
					double q2 = n / static_cast<double>(k);

					*(pOut[n] +3 * j * k) = static_cast<uchar>(q1 * b00 + q2 * b10);
					*(pOut[n] + 3 * (j + 1) * k) = static_cast<uchar>(q1 * b01 + q2 * b11);

					*(pOut[n] + 3 * j * k + 1) = static_cast<uchar>(q1 * g00 + q2 * g10);
					*(pOut[n] + 3 * (j + 1) * k + 1) = static_cast<uchar>(q1 * g01 + q2 * g11);

					*(pOut[n] +3 *  j * k + 2) = static_cast<uchar>(q1 * r00 + q2 * r10);
					*(pOut[n] + 3 * (j + 1) * k + 2) = static_cast<uchar>(q1 * r01 + q2 * r11);
				}

				for (int n = 0; n < k; n++)
				{
					uchar b0 = *(pOut[n] + 3 * j * k);
					uchar b1 = *(pOut[n] + 3 * (j + 1) * k);

					uchar g0 = *(pOut[n] + 3 * j * k + 1);
					uchar g1 = *(pOut[n] + 3 * (j + 1) * k + 1);

					uchar r0 = *(pOut[n] + 3 * j * k + 2);
					uchar r1 = *(pOut[n] + 3 * (j + 1) * k + 2);

					for (int m = 1; m < k; m++)
					{
						double p1 = (k - m) / static_cast<double>(k);
						double p2 = m / static_cast<double>(k);

						*(pOut[n] + 3 * j * k + 3 * m) = static_cast<uchar>(p1 * b0 + p2 * b1);
						*(pOut[n] + 3 * j * k + 3 * m + 1) = static_cast<uchar>(p1 * g0 + p2 * g1);
						*(pOut[n] + 3 * j * k + 3 * m + 2) = static_cast<uchar>(p1 * r0 + p2 * r1);
					}
				}
			}
		}

		uchar* pIn = in.ptr<uchar>(row0 - 1);
		uchar* pOut = out.ptr<uchar>(row1 - 1);
		for (int j = 0; j < col0 - 1; j++)
		{
			uchar b0 = *(pIn +3 *  j);
			uchar b1 = *(pIn + 3 * (j + 1));

			uchar g0 = *(pIn + 3 * j + 1);
			uchar g1 = *(pIn + 3 * (j + 1) + 1);

			uchar r0 = *(pIn + 3 * j + 2);
			uchar r1 = *(pIn + 3 * (j + 1) + 2);

			*(pOut + 3 * j * k) = b0;
			*(pOut + 3 * j * k + 1) = g0;
			*(pOut + 3 * j * k + 2) = r0;

			for (int m = 1; m < k; m++)
			{
				double p1 = (k - m) / static_cast<double>(k);
				double p2 = m / static_cast<double>(k);

				*(pOut + 3 * j * k + 3 * m) = static_cast<uchar>(p1 * b0 + p2 * b1);
				*(pOut + 3 * j * k + 3 * m + 1) = static_cast<uchar>(p1 * g0 + p2 * g1);
				*(pOut + 3 * j * k + 3 * m + 2) = static_cast<uchar>(p1 * r0 + p2 * r1);
			}
		}
	}

	return true;
}