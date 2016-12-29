/*
* 创建日期：2016-08-16
* 最后修改：2016-12-28
* 作    者：syf
* 描    述：
*/
#ifndef IMAGE_H
#define IMAGE_H

#include <QObject>
#include <QString>
#include <QTextCodec>

#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <windows.h>

using namespace cv;

class Image : public QObject
{
	Q_OBJECT

public:	
	Image(QObject *parent = 0);
	~Image();

	bool SetImage(const QString& path, int flag);
	bool SetImage(const Mat& image);

	Mat& GetImageSrc();
	Mat& GetImage();
	Mat& GetRoi(int x, int y, int size);

	bool LinearInterpolation(Mat &input, Mat &out, int k);
private:
	Mat m_imageSrc;
	Mat m_image;
	Mat m_imageDst;
	Mat m_imageRoi;
};

#endif // IMAGE_H
