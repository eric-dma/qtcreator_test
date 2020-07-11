/********************************************************************************
** Form generated from reading UI file 'mywidget.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYWIDGET_H
#define UI_MYWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFontComboBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MyWidget
{
public:
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout;
    QLabel *nameNLabel;
    QLineEdit *nameNLineEdit;
    QLabel *xingbiSLabel;
    QComboBox *xingbiSComboBox;
    QLabel *ageALabel;
    QSpinBox *ageASpinBox;
    QLabel *mailMLabel;
    QLineEdit *mailMLineEdit;
    QHBoxLayout *horizontalLayout;
    QFontComboBox *fontComboBox;
    QPushButton *pushButton;
    QTextEdit *textEdit;

    void setupUi(QWidget *MyWidget)
    {
        if (MyWidget->objectName().isEmpty())
            MyWidget->setObjectName(QString::fromUtf8("MyWidget"));
        MyWidget->resize(487, 280);
        verticalLayout = new QVBoxLayout(MyWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        nameNLabel = new QLabel(MyWidget);
        nameNLabel->setObjectName(QString::fromUtf8("nameNLabel"));

        formLayout->setWidget(0, QFormLayout::LabelRole, nameNLabel);

        nameNLineEdit = new QLineEdit(MyWidget);
        nameNLineEdit->setObjectName(QString::fromUtf8("nameNLineEdit"));

        formLayout->setWidget(0, QFormLayout::FieldRole, nameNLineEdit);

        xingbiSLabel = new QLabel(MyWidget);
        xingbiSLabel->setObjectName(QString::fromUtf8("xingbiSLabel"));

        formLayout->setWidget(1, QFormLayout::LabelRole, xingbiSLabel);

        xingbiSComboBox = new QComboBox(MyWidget);
        xingbiSComboBox->setObjectName(QString::fromUtf8("xingbiSComboBox"));

        formLayout->setWidget(1, QFormLayout::FieldRole, xingbiSComboBox);

        ageALabel = new QLabel(MyWidget);
        ageALabel->setObjectName(QString::fromUtf8("ageALabel"));

        formLayout->setWidget(2, QFormLayout::LabelRole, ageALabel);

        ageASpinBox = new QSpinBox(MyWidget);
        ageASpinBox->setObjectName(QString::fromUtf8("ageASpinBox"));

        formLayout->setWidget(2, QFormLayout::FieldRole, ageASpinBox);

        mailMLabel = new QLabel(MyWidget);
        mailMLabel->setObjectName(QString::fromUtf8("mailMLabel"));

        formLayout->setWidget(3, QFormLayout::LabelRole, mailMLabel);

        mailMLineEdit = new QLineEdit(MyWidget);
        mailMLineEdit->setObjectName(QString::fromUtf8("mailMLineEdit"));

        formLayout->setWidget(3, QFormLayout::FieldRole, mailMLineEdit);


        verticalLayout->addLayout(formLayout);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        fontComboBox = new QFontComboBox(MyWidget);
        fontComboBox->setObjectName(QString::fromUtf8("fontComboBox"));

        horizontalLayout->addWidget(fontComboBox);

        pushButton = new QPushButton(MyWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        horizontalLayout->addWidget(pushButton);


        verticalLayout->addLayout(horizontalLayout);

        textEdit = new QTextEdit(MyWidget);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));

        verticalLayout->addWidget(textEdit);
        textEdit->hide();

#if QT_CONFIG(shortcut)
        nameNLabel->setBuddy(nameNLineEdit);
        xingbiSLabel->setBuddy(xingbiSComboBox);
        ageALabel->setBuddy(ageASpinBox);
        mailMLabel->setBuddy(mailMLineEdit);
#endif // QT_CONFIG(shortcut)
        QWidget::setTabOrder(textEdit, mailMLineEdit);
        QWidget::setTabOrder(mailMLineEdit, nameNLineEdit);
        QWidget::setTabOrder(nameNLineEdit, xingbiSComboBox);
        QWidget::setTabOrder(xingbiSComboBox, ageASpinBox);
        QWidget::setTabOrder(ageASpinBox, fontComboBox);
        QWidget::setTabOrder(fontComboBox, pushButton);

        retranslateUi(MyWidget);

        QMetaObject::connectSlotsByName(MyWidget);
    } // setupUi

    void retranslateUi(QWidget *MyWidget)
    {
        MyWidget->setWindowTitle(QCoreApplication::translate("MyWidget", "MyWidget", nullptr));
        nameNLabel->setText(QCoreApplication::translate("MyWidget", "Name(&N)", nullptr));
        xingbiSLabel->setText(QCoreApplication::translate("MyWidget", "xingbi(&S)", nullptr));
        ageALabel->setText(QCoreApplication::translate("MyWidget", "age(&A)", nullptr));
        mailMLabel->setText(QCoreApplication::translate("MyWidget", "Mail(&M)", nullptr));
        pushButton->setText(QCoreApplication::translate("MyWidget", "PushButton", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MyWidget: public Ui_MyWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYWIDGET_H
