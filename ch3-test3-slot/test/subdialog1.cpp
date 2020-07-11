#include "subdialog1.h"
#include "ui_subdialog1.h"

subDialog1::subDialog1(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::subDialog1)
{
    ui->setupUi(this);
}

subDialog1::~subDialog1()
{
    delete ui;
}

void subDialog1::on_exitButtonSub_clicked()
{
    accept();
}
