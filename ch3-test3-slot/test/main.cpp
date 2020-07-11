#include "mainwindow.h"
#include "subdialog1.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    if(w.dialogsub->exec() == QDialog::Accepted) {
        w.show();
        return a.exec();
    } else
        return 0;
}
