/*
* �������ڣ�2016-12-24
* ����޸ģ�2016-12-28
* ��    �ߣ�syf
* ��    ����
*/
#include "widget.h"
#include "ui_widget.h"


/*
* ������parent��������ָ��
* ���أ�
* ���ܣ����캯��
*/
Widget::Widget(QWidget *parent) 
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
	ui->lineEdit_windowSize->setValidator(new QIntValidator(1, 64, this));
	ui->lineEdit_threshold->setValidator(new QIntValidator(1, 255, this));
	ui->lineEdit_fillValue->setValidator(new QIntValidator(0, 255, this));
	ui->lineEdit_interCoeff->setValidator(new QIntValidator(2, 8, this));

	m_pImage = new Image();


	connect(ui->pushButton_openImg, &QPushButton::clicked, this, &Widget::OnBtnOpenImageClicked);
	connect(ui->pushButton_showSrcImg, &QPushButton::clicked, this, &Widget::OnBtnShowImageSrcClicked);
	connect(ui->pushButton_rgb2grayscale, &QPushButton::clicked, this, &Widget::OnBtnConvertToGrayScaleClicked);
	connect(ui->pushButton_clearTextEdit, &QPushButton::clicked, ui->textEdit, &QTextEdit::clear);
	connect(ui->pushButton_threshold, &QPushButton::clicked, this, &Widget::OnBtnThretholdClicked);
	connect(ui->pushButton_fill, &QPushButton::clicked, this, &Widget::OnBtnFillClicked);
	connect(ui->pushButton_interpolation, &QPushButton::clicked, this, &Widget::OnBtnLinearInterpolationClicked);
	connect(ui->pushButton_showImageSize, &QPushButton::clicked, this, &Widget::OnBtnShowImageSizeClicked);
	connect(ui->pushButton_saveImage, &QPushButton::clicked, this, &Widget::OnBtnSaveImageClicked);
}


/*
* ������
* ���أ�
* ���ܣ���������
*/
Widget::~Widget()
{
    delete ui;
}


/*
* ������
* ���أ�
* ���ܣ���ʾѡ���ͼƬ
*/
void  Widget::ShowImage(const Mat& image)
{
	//image = m_pCamera->GetImage();

	if (image.data)
	{
		bool state = true;
		int channel = image.channels();
		int w = image.cols;
		int h = image.rows;
		int bytesPerLine = image.step;
		QImage qimg;

		if (1 == channel)
		{
			qimg = QImage(image.data, w, h, image.step, QImage::Format_Grayscale8);
		}
		else if (3 == channel)
		{
			qimg = QImage(image.data, w, h, bytesPerLine, QImage::Format_RGB888).rgbSwapped();
		}
		else
		{
			state = false;
		}

		if (state)
		{
			ui->label_showImg->setPixmap(QPixmap::fromImage(qimg));
			ui->label_showImg->resize(w, h);
		}
	}
	else
	{
		ui->textBrowser_message->setText(QStringLiteral("ͼ�����ݴ����޷���ʾ��"));
	}
}



/*****************************************************�� �� ��***********************************************************/

/*
* ������
* ���أ�
* ���ܣ��ۺ�������ͼƬ����ʾ
*/
void Widget::OnBtnOpenImageClicked()
{
	bool state = false;
	int flag;

	if (ui->checkBox_grayscale->isChecked())
	{
		flag = 1;
	}
	else
	{
		flag = 0;
	}

	QString fileName = QFileDialog::getOpenFileName(this, QStringLiteral("ѡ��ͼƬ"), "./", "Images (*.png *.bmp *.jpg)");
	state = m_pImage->SetImage(fileName, flag);

	if (false == state)
	{
		ui->textBrowser_message->setText(QStringLiteral("��ͼ��ʧ�ܣ�"));
	}
	else
	{
		m_pImage->GetImageSrc().copyTo(m_image);
		ShowImage(m_image);
	}
}



/*
* ������
* ���أ�
* ���ܣ��ۺ�������ʾԭͼ
*/
void Widget::OnBtnShowImageSrcClicked()
{
	if (NULL != m_pImage)
	{
		m_pImage->GetImageSrc().copyTo(m_image);
		ShowImage(m_image);
	}
}


/*
* ������
* ���أ�
* ���ܣ��ۺ�������ɫͼת�Ҷ�ͼ
*/
void  Widget::OnBtnConvertToGrayScaleClicked()
{
	if (NULL != m_image.data)
	{
		if (3 == m_image.channels())
		{
			cvtColor(m_image, m_image, COLOR_BGR2GRAY);
			ShowImage(m_image);

			ui->textBrowser_message->setText(QStringLiteral("ת����ɣ�"));
		}
		else if (1 == m_image.channels())
		{
			ui->textBrowser_message->setText(QStringLiteral("ԭͼΪ�Ҷ�ͼ������ת����"));
		}
		else
		{
			ui->textBrowser_message->setText(QStringLiteral("��3ͨ����ɫͼ���޷�ת��Ϊ�Ҷ�ͼ��"));
		}
	}
	else
	{
		ui->textBrowser_message->setText(QStringLiteral("ͼ�����ݴ����޷�ת��Ϊ�Ҷ�ͼ��"));
	}
}

/*
* ������
* ���أ�
* ���ܣ��ۺ�������ֵ��
*/
void Widget::OnBtnThretholdClicked()
{
	int thresh = ui->lineEdit_threshold->text().toInt();

	if (NULL == m_image.data)
	{
		ui->textBrowser_message->setText(QStringLiteral("ͼ�����ݴ����޷���ֵ����"));
	}
	else
	{
		threshold(m_image, m_image, static_cast<double>(thresh), 255.0, THRESH_BINARY);
		ShowImage(m_image);

		ui->textBrowser_message->setText(QStringLiteral("��ֵ����ɣ�"));
	}
}

/*
* ������
* ���أ�
* ���ܣ��ۺ������׶����
*/
void Widget::OnBtnFillClicked()
{
	if (NULL == m_image.data)
	{
		ui->textBrowser_message->setText(QStringLiteral("ͼ�����ݴ����޷�������䣡"));
	}
	else
	{
		if (m_image.channels() > 1)
		{
			ui->textBrowser_message->setText(QStringLiteral("�Ƕ�ֵ��ͼ���޷���䣡"));
			return;
		}

		//int row = m_image.rows;
		//int col = m_image.cols;

		//Mat tmpImage = zeros();
		//int value = ui->lineEdit_fillValue->text().toInt();
		Mat tmpImage = m_image.clone();
		//floodFill(m_image, Point(0, 0), Scalar(static_cast<double>(value)));
		floodFill(m_image, Point(0, 0), Scalar(0));
		m_image |= ~tmpImage;
		m_image = ~m_image;
		ShowImage(m_image);

		ui->textBrowser_message->setText(QStringLiteral("�����ɣ�"));
	}
}

/*
* ������
* ���أ�
* ���ܣ��ۺ��������Բ�ֵ
*/
void Widget::OnBtnLinearInterpolationClicked()
{
	int k = ui->lineEdit_interCoeff->text().toInt();
	Mat out;
	m_pImage->LinearInterpolation(m_image, out, k);
	out.copyTo(m_image);
	ShowImage(m_image);
}

/*
* ������
* ���أ�
* ���ܣ��ۺ�������ʾͼ��ߴ��С
*/
void Widget::OnBtnShowImageSizeClicked()
{
	if (NULL != m_image.data)
	{
		ui->textEdit->append(QStringLiteral("ͼ����Ϊ��") + QString::number(m_image.cols));
		ui->textEdit->append(QStringLiteral("ͼ��߶�Ϊ��") + QString::number(m_image.rows));
		ui->textEdit->append("    ");
	}
	else
	{
		ui->textEdit->append(QStringLiteral("��ͼ������!"));
		ui->textEdit->append("    ");
	}
}

/*
* ������
* ���أ�
* ���ܣ��ۺ���������ͼƬ
*/
void Widget::OnBtnSaveImageClicked()
{
	if (NULL != m_image.data)
	{
		QString fileName = QFileDialog::getSaveFileName(this, QStringLiteral("����ͼƬ"), "1", "(*.bmp)");

		
		//vector<int> params;
		//params.push_back(IMWRITE_JPEG_QUALITY);
		if (!fileName.isNull())
		{
			imwrite(fileName.toStdString(), m_image);
		}	
	}
	else
	{
		ui->textBrowser_message->setText(QStringLiteral("ͼ������Ϊ�գ��޷����棡"));
	}
}

/*
* ����������¼�
* ���أ�
* ���ܣ�������¼���������
*/
void Widget::mousePressEvent(QMouseEvent* event)
{
	if (Qt::LeftButton == event->button())
	{
		if (NULL == m_image.data)
		{
			ui->textEdit->append(QStringLiteral("��ͼ�����ݣ�"));
			return;
		}

		QPoint labelPos = ui->label_showImg->pos();
		QPoint scrollAreaPos = ui->scrollArea->pos();
		QPoint mousePos = event->pos();

		int scrollAreaw = ui->scrollArea->width();
		int scrollAreah = ui->scrollArea->height();

		if ((mousePos.x() > labelPos.x()) && (mousePos.y() > labelPos.y()) && (mousePos.x() < labelPos.x() + scrollAreaw) && (mousePos.y() < labelPos.y() + scrollAreah))
		{
			// x���򣬼�ȥscrollArea��label�ı߾�
			int x = mousePos.x() - labelPos.x() - scrollAreaPos.x() + ui->scrollArea->horizontalScrollBar()->value();
			// ����mainwidow��y���򣬼�ȥscrollArea��label�ı߾࣬�Լ�toolbar��menubar�Ŀ��
			//int y = mousePos.y() - labelPos.y() - scrollAreaPos.y() + ui->scrollArea->verticalScrollBar()->value() - ui->mainToolBar->size().height() - ui->menuBar->size().height();
			// ����widget��y���򣬼�ȥscrollArea��label�ı߾�
			int y = mousePos.y() - labelPos.y() - scrollAreaPos.y() + ui->scrollArea->verticalScrollBar()->value();

			if ((x >= 0) && (y >= 0))
			{
				//Mat roi = m_pImage->GetRoi(x, y, ui->lineEdit_windowSize->text().toInt());
				int w = ui->lineEdit_windowSize->text().toInt();
				if (x > m_image.cols - 1)
				{
					x = m_image.cols - 1;
				}

				if (y > m_image.rows - 1)
				{
					y = m_image.rows - 1;
				}

				if (x + w > m_image.cols - 1)
				{
					w = 1;
				}

				if (y + w > m_image.rows - 1)
				{
					w = 1;
				}
				Mat roi = m_image(Rect(x, y, w, w));
				ui->textEdit->append("x:" + QString::number(x) + "  " + "y:" + QString::number(y));

				if (roi.data)
				{
					int w = roi.cols;
					int h = roi.rows;
					int channel = roi.channels();
					QString str = "";

					for (int i = 0; i < h; i++)
					{
						uchar* data = roi.ptr<uchar>(i);
						for (int j = 0; j < w * channel; j += channel)
						{
							if (3 == channel)
							{
								str += "(" + QString::number(data[j]) + " " + QString::number(data[j + 1]) + " " + QString::number(data[j + 2]) + ")" + " ";
							}
							else
							{
								str += QString::number(data[j]) + " ";
							}
						}

						ui->textEdit->append(str);
						str = "";
					}

					ui->textEdit->append("----------");
				}
			}
		}
	}
}





