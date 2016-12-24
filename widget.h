/*
* 创建日期：2016-12-23
* 最后修改：2016-12-24
* 作    者：syf
* 描    述：
*/
#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QFileDialog>
#include <QMouseEvent>
#include <QScrollBar>

#include <image.h>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

	void ShowImage(const Mat& image);

public slots:
	void OnBtnOpenImageClicked();
	void OnBtnShowImageSrcClicked();
	void OnBtnConvertToGrayScaleClicked();
	void OnBtnThretholdClicked();
	void OnBtnFillClicked();
protected:
	void mousePressEvent(QMouseEvent* event);

private:
    Ui::Widget *ui;

	Image* m_pImage;
	Mat m_image;
};

#endif // WIDGET_H
