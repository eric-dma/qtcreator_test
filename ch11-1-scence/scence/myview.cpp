#include "myview.h"
#include <QMouseEvent>
#include <QGraphicsItem>
#include <QDebug>

MyView::MyView()
{

}

void MyView::mousePressEvent(QMouseEvent *event)
{
    QPoint viewPos = event->pos();
    qDebug() << "viewPos: " << viewPos;
    QPointF scenePos = mapToScene(viewPos);
    qDebug() << "scenePos: " << scenePos;
    QGraphicsItem * item = scene()->itemAt(scenePos,QTransform());
    if(item) {
        QPointF itemPos = mapFromScene(scenePos);
        qDebug() << "itemPos: " << itemPos;
    }
}
