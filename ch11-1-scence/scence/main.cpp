#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsView>
#include <QDebug>
#include "myview.h"
#include "myitem.h"

int main(int argc, char * argv[]) {
//    // 1
//    QApplication app(argc, argv);
//    QGraphicsScene scene;
//    QGraphicsItem * item = new QGraphicsRectItem(0,0,100,100);
//    scene.addItem(item);
//    qDebug() << scene.itemAt(50,50,QTransform());

//    QGraphicsView view(&scene);
//    view.setForegroundBrush(QColor(255,255,0,100));
//    view.setBackgroundBrush(QPixmap("../../images/backlight.jpg"));
//    view.resize(400,300);
//    view.show();

//    QGraphicsView view2(&scene);
//    view2.resize(400,300);
//    view2.show();
//    scene.setForegroundBrush(QColor(255,0,255,100));
//    scene.setBackgroundBrush(QPixmap("../../images/light.jpg"));

    //2
    QApplication app(argc, argv);
    QGraphicsScene scene;
    scene.setSceneRect(0,0,400,300);
    MyItem * item = new MyItem;
    item->setZValue(1);
    scene.addItem(item);
    item->setPos(10,10);
    QGraphicsRectItem * rectItem = scene.addRect(QRect(0,0,100,100), QPen(Qt::blue),QBrush(Qt::green));
    item->setParentItem(rectItem);
    rectItem->setRotation(45);

    rectItem->setPos(20,20);
    MyView view;
    view.setScene(&scene);
    view.setForegroundBrush(QColor(100,100,0,100));
    view.setBackgroundBrush(QPixmap("../../images/light.jpg"));
    view.resize(400,300);
    view.show();

    return app.exec();
}
