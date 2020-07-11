#include "mywidget.h"
#include "ui_mywidget.h"
#include <QDialog>

MyWidget::MyWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MyWidget)
{
/*    ui->setupUi(this);
    QDialog dialog1(this);
    dialog1.setWindowTitle(QObject::tr("new object dialog1"));
    dialog1.show();

    QDialog *dialog2 = new QDialog(this);
    dialog2->setWindowTitle("new pointer dialog2");
    dialog2->show();

    QDialog dialog3(this);
    //dialog3.setWindowIconText(QObject::tr("new object exec dialog3"));
    dialog3.exec();
    QDialog dialog5(this);
    dialog5.exec();

    //通过setModal设置模态对话框，测试不行
    QDialog *dialog4 = new QDialog(this);
    dialog4->setModal(true);
    dialog4->show();*/
}

MyWidget::~MyWidget()
{
    delete ui;
}

