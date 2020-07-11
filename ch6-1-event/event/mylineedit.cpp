#include "mylineedit.h"
#include <QKeyEvent>
#include <QDebug>

MyLineEdit::MyLineEdit(QWidget *parent) :
    QLineEdit(parent)
{

}

bool MyLineEdit::event(QEvent *event)
{
    if(event->type() == QEvent::KeyPress)
        qDebug() << tr("===MyLineEdit=== event function");
    return QLineEdit::event(event);
}

void MyLineEdit::keyPressEvent(QKeyEvent * event)
{
    qDebug() << tr("===MyLineEdit== key press event");
    QLineEdit::keyPressEvent(event);
    event->ignore();
}
