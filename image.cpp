/*
* 创建日期：2016-08-16
* 最后修改：2016-12-23
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