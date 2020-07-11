#include <QtWidgets>
#include <QDebug>

int main(int argc, char * argv[])
{
    QApplication a(argc, argv);
    //QWidget *widget = new QWidget();
    QWidget *widget = new QWidget(0, Qt::Dialog);
    widget->setWindowTitle(QObject::tr("我是 widget"));

    //QLabel *label = new QLabel();
    //QLabel *label = new QLabel(0, Qt::SplashScreen); //没有边框
    QLabel *label = new QLabel(0, Qt::SplashScreen | Qt::WindowStaysOnTopHint); //一直显示在其他窗口的上面
    //QLabel *label = new QLabel(widget);  //两串字会重合
    label->setWindowTitle(QObject::tr("我是 label"));
    label->setText(QObject::tr("label：我是个窗口"));
    label->resize(200,60);

    QLabel *label1 = new QLabel(widget);
    //label1->setWindowTitle(QObject::tr("label1 window title"));  //没有作用
    label1->setText(QObject::tr("我不是独立窗口，是widget的子部件"));
    label1->resize(250,60);

    label->show();
    widget->show();

    int ret = a.exec();

    qDebug() << "pos:" << widget->pos() << endl << "rect:" << widget->rect() << endl << "size:"
             << widget->size() << endl << "width:" << widget->width() << endl << "height:" << widget->height();

    delete label;
    delete widget;

    return ret;
}
