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
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTextEdit>
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
    QPushButton *pushButton_fill;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QLineEdit *lineEdit_fillValue;
    QTextEdit *textEdit;
    QLabel *label;
    QLineEdit *lineEdit_windowSize;
    QPushButton *pushButton_clearTextEdit;

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
        tabWidget->setGeometry(QRect(840, 230, 430, 400));
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
        groupBox->setGeometry(QRect(10, 10, 405, 141));
        pushButton_fill = new QPushButton(groupBox);
        pushButton_fill->setObjectName(QStringLiteral("pushButton_fill"));
        pushButton_fill->setGeometry(QRect(10, 50, 75, 23));
        widget = new QWidget(groupBox);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(10, 20, 121, 22));
        horizontalLayout_3 = new QHBoxLayout(widget);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(widget);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_3->addWidget(label_3);

        lineEdit_fillValue = new QLineEdit(widget);
        lineEdit_fillValue->setObjectName(QStringLiteral("lineEdit_fillValue"));

        horizontalLayout_3->addWidget(lineEdit_fillValue);

        tabWidget->addTab(tab_2, QString());
        textEdit = new QTextEdit(Widget);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setGeometry(QRect(840, 70, 430, 150));
        label = new QLabel(Widget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(1151, 50, 60, 20));
        lineEdit_windowSize = new QLineEdit(Widget);
        lineEdit_windowSize->setObjectName(QStringLiteral("lineEdit_windowSize"));
        lineEdit_windowSize->setGeometry(QRect(1215, 50, 53, 20));
        pushButton_clearTextEdit = new QPushButton(Widget);
        pushButton_clearTextEdit->setObjectName(QStringLiteral("pushButton_clearTextEdit"));
        pushButton_clearTextEdit->setGeometry(QRect(1070, 48, 75, 23));

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
        pushButton_fill->setText(QApplication::translate("Widget", "\345\255\224\346\264\236\345\241\253\345\205\205", 0));
        label_3->setText(QApplication::translate("Widget", "\345\241\253\345\205\205\345\200\274\357\274\232", 0));
        lineEdit_fillValue->setText(QApplication::translate("Widget", "128", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("Widget", "Tab 2", 0));
        label->setText(QApplication::translate("Widget", "\347\252\227\345\217\243\345\244\247\345\260\217\357\274\232", 0));
        lineEdit_windowSize->setText(QApplication::translate("Widget", "1", 0));
        pushButton_clearTextEdit->setText(QApplication::translate("Widget", "\346\270\205\351\231\244\346\230\276\347\244\272", 0));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
