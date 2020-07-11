#include "widget.h"
#include "ui_widget.h"
#include "mydialog.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    MyDialog * dlg = new MyDialog(this);
    // method1:
    //connect(dlg, SIGNAL(dlgRetrun(int)), this, SLOT(showValue(int)));
    // method2:
//    connect(dlg,&MyDialog::dlgRetrun,this,&Widget::showValue);
    // method3: Lambda
    QMetaObject::Connection ret = connect(dlg,&MyDialog::dlgRetrun,[ = ](int value){
        ui->label->setText(tr("set value: %1").arg(value));
    });
    dlg->show();
    //disconnect(dlg,0,0,0);
    //dlg->disconnect(SIGNAL(dlgRetrun(int)));
    disconnect(ret);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::showValue(int value)
{
    ui->label->setText(tr("get the string: %1").arg(value));
}

