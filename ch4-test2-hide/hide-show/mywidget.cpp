#include "mywidget.h"
#include "ui_mywidget.h"

MyWidget::MyWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MyWidget)
{
    ui->setupUi(this);
    ui->textEdit->setVisible(false);
}

MyWidget::~MyWidget()
{
    delete ui;
}


void MyWidget::on_pushButton_toggled(bool checked)
{
    ui->textEdit->setVisible(checked);
    if(checked) ui->pushButton->setText(tr("hide"));
    else ui->pushButton->setText(tr("show"));
}
