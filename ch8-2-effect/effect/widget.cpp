#include "widget.h"
#include "ui_widget.h"
#include <QPixmap>
#include <QBitmap>
#include <QPainter>
#include <QGraphicsDropShadowEffect>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

//    QPixmap pixmap(":/image/images/chiplight.jpg");

//    ui->label->setPixmap(pixmap);
//    ui->label->setMask(pixmap.mask());

//    QPixmap pix;
//    pix.load(":/image/images/funny.png");
//    resize(pix.size());
//    setMask(pix.mask());

    setWindowOpacity(0.5);
    setWindowFlag(Qt::FramelessWindowHint);
    setAttribute(Qt::WA_TranslucentBackground);

    QGraphicsDropShadowEffect *effect = new QGraphicsDropShadowEffect;
    effect->setColor(QColor(100,100,100,100));
    effect->setBlurRadius(2);
    effect->setOffset(10);
    ui->label->setGraphicsEffect(effect);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::paintEvent(QPaintEvent *event)
{
    //QPainter painter(this);
    //painter.drawPixmap(0,0,QPixmap(":/image/images/chiplight.jpg"));

    QPainter painter(this);
    painter.fillRect(rect(),QColor(255,255,255,100));
}

void Widget::mousePressEvent(QMouseEvent *event)
{
    close();
}
