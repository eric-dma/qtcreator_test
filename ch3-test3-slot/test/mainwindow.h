#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "subdialog1.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    subDialog1 * dialogsub;
public slots:
    void showChildDialog();
    void on_showchild2_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
