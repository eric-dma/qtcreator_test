#include "widget.h"
#include "ui_widget.h"
#include <QKeyEvent>
#include <QDebug>
#include <QMouseEvent>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    keyUp = false;
    keyLeft = false;
    move = false;

    ui->setupUi(this);

    lineEdit = new MyLineEdit(this);
    lineEdit->move(100,100);

    lineEdit->installEventFilter(this);

    QCursor cursor;
    cursor.setShape(Qt::OpenHandCursor);
    setCursor(cursor);

    setMouseTracking(true);

    setFocus();
}

Widget::~Widget()
{
    delete ui;
}

bool Widget::eventFilter(QObject *obj, QEvent *event)
{
    if(obj == lineEdit) {
        if(event->type() == QEvent::KeyPress)
            qDebug() << tr("===Widget=== event function");
    }
    return QWidget::eventFilter(obj,event);
}

void Widget::keyPressEvent(QKeyEvent *event)
{
    Q_UNUSED(event);

    if(event->modifiers() == Qt::ControlModifier) {
        if(event->key() == Qt::Key_M)
            setWindowState(Qt::WindowMaximized);
    }
    else if(event->key() == Qt::Key_Up) {
        qDebug() << "press:" << event->isAutoRepeat();
        if(event->isAutoRepeat()) return;
        keyUp = true;
    }
    else if(event->key() == Qt::Key_Left) {
        if(event->isAutoRepeat()) return;
        keyLeft = true;
    }
    else QWidget::keyPressEvent(event);

    qDebug() << tr("===Widget== key press event");
}

void Widget::keyReleaseEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Up) {
        qDebug() << "release:" << event->isAutoRepeat();
        qDebug() << "up";
        if(event->isAutoRepeat()) return;
        keyUp = false;
        if(move) {
            move = false;
            return;
        }
        if(keyLeft) {
            ui->pushButton->move(30,80);
            move = true;
        } else {
            ui->pushButton->move(120,80);
        }
    }
    else if(event->key() == Qt::Key_Left) {
        if(event->isAutoRepeat()) return;
        keyLeft = false;
        if(move) {
            move = false;
            return;
        }
        if(keyUp) {
            ui->pushButton->move(30,80);
            move = true;
        } else {
            ui->pushButton->move(30,120);
        }
    }
    else if(event->key() == Qt::Key_Down) {
        ui->pushButton->move(120,120);
    }
}

void Widget::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton) {
        QCursor cursor;
        cursor.setShape(Qt::ClosedHandCursor);
        QApplication::setOverrideCursor(cursor);
        offset = event->globalPos() - pos();
    }
    else if(event->button() == Qt::RightButton) {
        QCursor cursor(QPixmap("../images/simle.png"));
        QApplication::setOverrideCursor(cursor);
    }
}

void Widget::mouseReleaseEvent(QMouseEvent *event)
{
    Q_UNUSED(event);
    QApplication::restoreOverrideCursor();
}

void Widget::mouseDoubleClickEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton) {
        if(windowState() != Qt::WindowFullScreen)
            setWindowState(Qt::WindowFullScreen);
        else setWindowState(Qt::WindowNoState);
    }
}

void Widget::mouseMoveEvent(QMouseEvent *event)
{
    if(event->button() & Qt::LeftButton) {
        QPoint temp;
        temp = event->globalPos() - offset;
        //move(temp);
    }
}

void Widget::wheelEvent(QWheelEvent *event)
{
    if(event->delta() > 0) {
        ui->textEdit->zoomIn();
    }
    else {
        ui->textEdit->zoomOut();
    }
}
