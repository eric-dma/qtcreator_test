/********************************************************************************
** Form generated from reading UI file 'subdialog1.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SUBDIALOG1_H
#define UI_SUBDIALOG1_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_subDialog1
{
public:
    QTextEdit *textEdit;
    QPushButton *exitButtonSub;

    void setupUi(QDialog *subDialog1)
    {
        if (subDialog1->objectName().isEmpty())
            subDialog1->setObjectName(QString::fromUtf8("subDialog1"));
        subDialog1->resize(400, 300);
        textEdit = new QTextEdit(subDialog1);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(30, 20, 181, 41));
        exitButtonSub = new QPushButton(subDialog1);
        exitButtonSub->setObjectName(QString::fromUtf8("exitButtonSub"));
        exitButtonSub->setGeometry(QRect(250, 30, 80, 16));

        retranslateUi(subDialog1);
        QObject::connect(exitButtonSub, SIGNAL(clicked()), subDialog1, SLOT(close()));

        QMetaObject::connectSlotsByName(subDialog1);
    } // setupUi

    void retranslateUi(QDialog *subDialog1)
    {
        subDialog1->setWindowTitle(QCoreApplication::translate("subDialog1", "Dialog", nullptr));
        textEdit->setHtml(QCoreApplication::translate("subDialog1", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:6pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:22pt; font-weight:600;\">\345\255\220\345\257\271\350\257\235\346\241\2061</span></p></body></html>", nullptr));
        exitButtonSub->setText(QCoreApplication::translate("subDialog1", "Exit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class subDialog1: public Ui_subDialog1 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SUBDIALOG1_H
