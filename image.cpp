/*
* �������ڣ�2016-08-16
* ����޸ģ�2016-12-23
* ��    �ߣ�syf
* ��    ����
*/
#include "image.h"


/*
* ������
* ���أ�
* ���ܣ����캯��
*/
Image::Image(QObject *parent)
	: QObject(parent)
{
	
}


/*
* ������
* ���أ�
* ���ܣ���������
*/
Image::~Image()
{

}


/*
* ������path--ͼ���ļ�·��
* ���أ�0--ͼ���ʧ��
*       1--ͼ��򿪳ɹ�
* ���ܣ�����pathָ����·�����ļ�������ͼ��
*/
bool Image::SetImage(const QString& path, int flag)
{
	bool state = false;

	// ����֧������·��
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
* ������image--Mat���͵�ͼ��
* ���أ�0--ͼ���ʧ��
*       1--ͼ��򿪳ɹ�
* ���ܣ�����Mat���͵�ͼ��
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
* ������
* ���أ�
* ���ܣ�����ԭͼ
*/
Mat& Image::GetImageSrc()
{
	return m_imageSrc;
}


/*
* ������
* ���أ�
* ���ܣ����ش�������м�ͼ
*/
Mat& Image::GetImage()
{
	return m_image;
}


/*
* ������x-�����꣬y-�����꣬size-���ڴ�С
* ���أ�Roi����
* ���ܣ��Ӵ򿪵�ͼ���л�ȡָ��λ�ã�ָ����С��Roi����
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