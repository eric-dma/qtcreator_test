#include "mywidget.h"
#include "ui_mywidget.h"

MyWidget::MyWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MyWidget)
{
    ui->setupUi(this);
    ui->frame->setFrameShape(QFrame::Box);
    ui->frame->setFrameShadow(QFrame::Sunken);
    ui->frame->setLineWidth(5);
    ui->frame->setMidLineWidth(10);

    QFont font;
    font.setFamily("huawenxingkai");
    font.setPointSize(10);
    font.setBold(true);
    font.setItalic(true);
    ui->label->setFont(font);

    QString string = tr("111111111112222222222222222222224444444444444444");
    QString str = ui->label->fontMetrics().elidedText(string, Qt::ElideLeft,10);
    ui->label->setText(str);
}

MyWidget::~MyWidget()
{
    delete ui;
}

