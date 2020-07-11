#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "mylineedit.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class MyLineEdit;

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    bool eventFilter(QObject * obj, QEvent * event);

private:
    Ui::Widget *ui;
    MyLineEdit * lineEdit;
    QPoint offset;
    bool keyUp;
    bool keyLeft;
    bool move;

protected:
    void keyPressEvent(QKeyEvent * event);
    void keyReleaseEvent(QKeyEvent *event);

    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void mouseDoubleClickEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void wheelEvent(QWheelEvent *event);


};
#endif // WIDGET_H
