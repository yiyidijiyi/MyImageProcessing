/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QGridLayout *gridLayout;
    QLabel *label_showImg;
    QPushButton *pushButton_showSrcImg;
    QPushButton *pushButton_rgb2grayscale;
    QTextBrowser *textBrowser_message;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_openImg;
    QCheckBox *checkBox_grayscale;
    QTabWidget *tabWidget;
    QWidget *tab;
    QPushButton *pushButton_threshold;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *lineEdit_threshold;
    QWidget *tab_2;
    QGroupBox *groupBox;
    QWidget *layoutWidget2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QLineEdit *lineEdit_fillValue;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *pushButton_fill;
    QSpacerItem *horizontalSpacer;
    QWidget *layoutWidget3;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QLineEdit *lineEdit_interCoeff;
    QHBoxLayout *horizontalLayout_6;
    QPushButton *pushButton_interpolation;
    QSpacerItem *horizontalSpacer_2;
    QTextEdit *textEdit;
    QPushButton *pushButton_showImageSize;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_8;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label;
    QLineEdit *lineEdit_windowSize;
    QPushButton *pushButton_clearTextEdit;
    QPushButton *pushButton_saveImage;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QStringLiteral("Widget"));
        Widget->resize(1280, 720);
        scrollArea = new QScrollArea(Widget);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setGeometry(QRect(10, 10, 820, 620));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 818, 618));
        gridLayout = new QGridLayout(scrollAreaWidgetContents);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label_showImg = new QLabel(scrollAreaWidgetContents);
        label_showImg->setObjectName(QStringLiteral("label_showImg"));
        label_showImg->setFrameShape(QFrame::NoFrame);
        label_showImg->setFrameShadow(QFrame::Plain);

        gridLayout->addWidget(label_showImg, 0, 0, 1, 1);

        scrollArea->setWidget(scrollAreaWidgetContents);
        pushButton_showSrcImg = new QPushButton(Widget);
        pushButton_showSrcImg->setObjectName(QStringLiteral("pushButton_showSrcImg"));
        pushButton_showSrcImg->setGeometry(QRect(840, 40, 75, 23));
        pushButton_rgb2grayscale = new QPushButton(Widget);
        pushButton_rgb2grayscale->setObjectName(QStringLiteral("pushButton_rgb2grayscale"));
        pushButton_rgb2grayscale->setGeometry(QRect(920, 40, 75, 23));
        textBrowser_message = new QTextBrowser(Widget);
        textBrowser_message->setObjectName(QStringLiteral("textBrowser_message"));
        textBrowser_message->setGeometry(QRect(10, 640, 820, 70));
        layoutWidget = new QWidget(Widget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(840, 10, 154, 25));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        pushButton_openImg = new QPushButton(layoutWidget);
        pushButton_openImg->setObjectName(QStringLiteral("pushButton_openImg"));

        horizontalLayout->addWidget(pushButton_openImg);

        checkBox_grayscale = new QCheckBox(layoutWidget);
        checkBox_grayscale->setObjectName(QStringLiteral("checkBox_grayscale"));

        horizontalLayout->addWidget(checkBox_grayscale);

        tabWidget = new QTabWidget(Widget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(840, 310, 430, 400));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        pushButton_threshold = new QPushButton(tab);
        pushButton_threshold->setObjectName(QStringLiteral("pushButton_threshold"));
        pushButton_threshold->setGeometry(QRect(10, 40, 75, 23));
        layoutWidget1 = new QWidget(tab);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(10, 10, 177, 22));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(layoutWidget1);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_2->addWidget(label_2);

        lineEdit_threshold = new QLineEdit(layoutWidget1);
        lineEdit_threshold->setObjectName(QStringLiteral("lineEdit_threshold"));

        horizontalLayout_2->addWidget(lineEdit_threshold);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        groupBox = new QGroupBox(tab_2);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(10, 10, 405, 161));
        layoutWidget2 = new QWidget(groupBox);
        layoutWidget2->setObjectName(QStringLiteral("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(10, 20, 121, 55));
        verticalLayout = new QVBoxLayout(layoutWidget2);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_3 = new QLabel(layoutWidget2);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_3->addWidget(label_3);

        lineEdit_fillValue = new QLineEdit(layoutWidget2);
        lineEdit_fillValue->setObjectName(QStringLiteral("lineEdit_fillValue"));

        horizontalLayout_3->addWidget(lineEdit_fillValue);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        pushButton_fill = new QPushButton(layoutWidget2);
        pushButton_fill->setObjectName(QStringLiteral("pushButton_fill"));

        horizontalLayout_5->addWidget(pushButton_fill);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout_5);

        layoutWidget3 = new QWidget(groupBox);
        layoutWidget3->setObjectName(QStringLiteral("layoutWidget3"));
        layoutWidget3->setGeometry(QRect(10, 90, 133, 55));
        verticalLayout_2 = new QVBoxLayout(layoutWidget3);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_4 = new QLabel(layoutWidget3);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout_4->addWidget(label_4);

        lineEdit_interCoeff = new QLineEdit(layoutWidget3);
        lineEdit_interCoeff->setObjectName(QStringLiteral("lineEdit_interCoeff"));

        horizontalLayout_4->addWidget(lineEdit_interCoeff);


        verticalLayout_2->addLayout(horizontalLayout_4);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        pushButton_interpolation = new QPushButton(layoutWidget3);
        pushButton_interpolation->setObjectName(QStringLiteral("pushButton_interpolation"));

        horizontalLayout_6->addWidget(pushButton_interpolation);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_2);


        verticalLayout_2->addLayout(horizontalLayout_6);

        tabWidget->addTab(tab_2, QString());
        groupBox->raise();
        textEdit = new QTextEdit(Widget);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setGeometry(QRect(840, 99, 430, 201));
        pushButton_showImageSize = new QPushButton(Widget);
        pushButton_showImageSize->setObjectName(QStringLiteral("pushButton_showImageSize"));
        pushButton_showImageSize->setGeometry(QRect(840, 70, 75, 23));
        widget = new QWidget(Widget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(1080, 40, 191, 25));
        horizontalLayout_8 = new QHBoxLayout(widget);
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        horizontalLayout_8->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        label = new QLabel(widget);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout_7->addWidget(label);

        lineEdit_windowSize = new QLineEdit(widget);
        lineEdit_windowSize->setObjectName(QStringLiteral("lineEdit_windowSize"));

        horizontalLayout_7->addWidget(lineEdit_windowSize);


        horizontalLayout_8->addLayout(horizontalLayout_7);

        pushButton_clearTextEdit = new QPushButton(widget);
        pushButton_clearTextEdit->setObjectName(QStringLiteral("pushButton_clearTextEdit"));

        horizontalLayout_8->addWidget(pushButton_clearTextEdit);

        pushButton_saveImage = new QPushButton(Widget);
        pushButton_saveImage->setObjectName(QStringLiteral("pushButton_saveImage"));
        pushButton_saveImage->setGeometry(QRect(920, 70, 75, 23));

        retranslateUi(Widget);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", 0));
        label_showImg->setText(QString());
        pushButton_showSrcImg->setText(QApplication::translate("Widget", "\346\230\276\347\244\272\345\216\237\345\233\276", 0));
        pushButton_rgb2grayscale->setText(QApplication::translate("Widget", "\350\275\254\344\270\272\347\201\260\345\272\246\345\233\276", 0));
        pushButton_openImg->setText(QApplication::translate("Widget", "\346\211\223\345\274\200\345\233\276\347\211\207", 0));
        checkBox_grayscale->setText(QApplication::translate("Widget", "\347\201\260\345\272\246\346\226\271\345\274\217", 0));
        pushButton_threshold->setText(QApplication::translate("Widget", "\351\230\210\345\200\274\344\272\214\345\200\274\345\214\226", 0));
        label_2->setText(QApplication::translate("Widget", "\351\230\210\345\200\274\357\274\232", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("Widget", "Tab 1", 0));
        groupBox->setTitle(QApplication::translate("Widget", "\346\274\253\346\260\264\345\241\253\345\205\205", 0));
        label_3->setText(QApplication::translate("Widget", "\345\241\253\345\205\205\345\200\274\357\274\232", 0));
        lineEdit_fillValue->setText(QApplication::translate("Widget", "128", 0));
        pushButton_fill->setText(QApplication::translate("Widget", "\345\255\224\346\264\236\345\241\253\345\205\205", 0));
        label_4->setText(QApplication::translate("Widget", "\347\272\277\346\200\247\346\217\222\345\200\274\347\263\273\346\225\260\357\274\232", 0));
        lineEdit_interCoeff->setText(QApplication::translate("Widget", "2", 0));
        pushButton_interpolation->setText(QApplication::translate("Widget", "\347\272\277\346\200\247\346\217\222\345\200\274", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("Widget", "Tab 2", 0));
        pushButton_showImageSize->setText(QApplication::translate("Widget", "\345\233\276\345\203\217\345\260\272\345\257\270", 0));
        label->setText(QApplication::translate("Widget", "\347\252\227\345\217\243\345\244\247\345\260\217\357\274\232", 0));
        lineEdit_windowSize->setText(QApplication::translate("Widget", "1", 0));
        pushButton_clearTextEdit->setText(QApplication::translate("Widget", "\346\270\205\351\231\244\346\230\276\347\244\272", 0));
        pushButton_saveImage->setText(QApplication::translate("Widget", "\344\277\235\345\255\230\345\233\276\345\203\217", 0));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
