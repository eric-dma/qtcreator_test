#include "myitem.h"
#include <QPainter>

MyItem::MyItem()
{

}

QRectF MyItem::boundingRect() const
{
    qreal penWidth = 1;
    return QRectF(0 - penWidth/2.0, 0 - penWidth/2.0, 20 + penWidth, 20 + penWidth);
}

void MyItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    painter->setBrush(Qt::red);
    painter->drawRect(0,0,20,20);
}
