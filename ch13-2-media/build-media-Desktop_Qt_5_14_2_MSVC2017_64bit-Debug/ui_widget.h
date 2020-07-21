/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSlider>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QSlider *brightnessSlider;
    QSlider *hueSlider;
    QSlider *contrastSlider;
    QSlider *saturationSlider;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(600, 400);
        label = new QLabel(Widget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 326, 31, 20));
        label_2 = new QLabel(Widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 360, 36, 8));
        label_3 = new QLabel(Widget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(300, 330, 36, 8));
        label_4 = new QLabel(Widget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(300, 360, 36, 8));
        brightnessSlider = new QSlider(Widget);
        brightnessSlider->setObjectName(QString::fromUtf8("brightnessSlider"));
        brightnessSlider->setGeometry(QRect(50, 330, 160, 16));
        brightnessSlider->setMinimum(-100);
        brightnessSlider->setMaximum(100);
        brightnessSlider->setOrientation(Qt::Horizontal);
        hueSlider = new QSlider(Widget);
        hueSlider->setObjectName(QString::fromUtf8("hueSlider"));
        hueSlider->setGeometry(QRect(50, 360, 160, 16));
        hueSlider->setMinimum(-100);
        hueSlider->setMaximum(100);
        hueSlider->setOrientation(Qt::Horizontal);
        contrastSlider = new QSlider(Widget);
        contrastSlider->setObjectName(QString::fromUtf8("contrastSlider"));
        contrastSlider->setGeometry(QRect(340, 330, 160, 16));
        contrastSlider->setMinimum(-100);
        contrastSlider->setMaximum(100);
        contrastSlider->setOrientation(Qt::Horizontal);
        saturationSlider = new QSlider(Widget);
        saturationSlider->setObjectName(QString::fromUtf8("saturationSlider"));
        saturationSlider->setGeometry(QRect(340, 360, 160, 16));
        saturationSlider->setMinimum(-100);
        saturationSlider->setMaximum(100);
        saturationSlider->setOrientation(Qt::Horizontal);

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        label->setText(QCoreApplication::translate("Widget", "\344\272\256\345\272\246", nullptr));
        label_2->setText(QCoreApplication::translate("Widget", "\350\211\262\347\233\270", nullptr));
        label_3->setText(QCoreApplication::translate("Widget", "\345\257\271\346\257\224\345\272\246", nullptr));
        label_4->setText(QCoreApplication::translate("Widget", "\351\245\261\345\222\214\345\272\246", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
