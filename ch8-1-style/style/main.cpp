#include "mainwindow.h"
#include <QStyleFactory>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    //a.setStyle(QStyleFactory::create("fusion"));
    w.show();
    return a.exec();
}
