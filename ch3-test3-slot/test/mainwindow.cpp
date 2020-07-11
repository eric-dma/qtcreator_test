#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "subdialog1.h"
#include <QDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->showChildButton, &QPushButton::clicked, this, &MainWindow::showChildDialog);
    dialogsub = new subDialog1(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}
//method 1: use connect function
void MainWindow::showChildDialog()
{
    /*dialog->setWindowTitle(QObject::tr("child1 dialog"));
    QLabel *label = new QLabel(dialog);
    label->setText(QObject::tr("this is child dialog1"));
    label->show();*/
    dialogsub->show();

}

void MainWindow::on_showchild2_clicked()
{
    QDialog * dialog = new QDialog(this);
    dialog->setWindowTitle(QObject::tr("child2 dialog"));
    QLabel *label = new QLabel(dialog);
    label->setText(QObject::tr("this is child dialog2"));
    label->show();
    dialog->show();
}
