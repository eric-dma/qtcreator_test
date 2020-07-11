#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "myaction.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    MyAction *action = new MyAction;
    QMenu *editMenu = ui->menubar->addMenu(tr("Edit(&E)"));
    editMenu->addAction(action);
    connect(action, SIGNAL(getText(QString)),this, SLOT(setText(QString)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setText(const QString &string)
{
    ui->textEdit->setText(string);
}

