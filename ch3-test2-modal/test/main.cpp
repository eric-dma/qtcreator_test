#include "mywidget.h"

#include <QApplication>
#include <QDialog>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MyWidget w;

    QDialog dialog4(&w);
    dialog4.setModal(true);
    dialog4.show();
    w.show();
    return a.exec();
}
