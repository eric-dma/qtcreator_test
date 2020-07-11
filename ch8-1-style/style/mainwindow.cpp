#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QStyleFactory>
#include <QFile>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //ui->progressBar->setStyle(QStyleFactory::create("fusion"));
    qssFile = new QFile(":/qss/my.qss");
    qssFile->open(QFile::ReadOnly);
    QString styleSheet = QString(qssFile->readAll());
    qApp->setStyleSheet(styleSheet);
    qssFile->close();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    if(qssFile->fileName() == ":/qss/my.qss")
        qssFile->setFileName(":/qss/my1.qss");
    else qssFile->setFileName(":/qss/my.qss");
    qssFile->open(QFile::ReadOnly);
    QString styleSheet = QString(qssFile->readAll());
    qApp->setStyleSheet(styleSheet);
    qssFile->close();
}
