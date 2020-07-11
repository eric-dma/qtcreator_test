#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QToolButton>
#include <QSpinBox>
#include <QTextEdit>
#include <QMdiSubWindow>
#include <QLabel>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QMenu *editMenu = ui->menubar->addMenu(tr("Edit(&E)"));
    QAction *action_Open = editMenu->addAction(QIcon(":/image/images/funny.png"),tr("Open File(&O)"));
    action_Open->setShortcut(QKeySequence("Ctrl+O"));
    ui->toolBar->addAction(action_Open);

    QActionGroup * group = new QActionGroup(this);
    QAction * action_L = group->addAction(tr("Left Allign(&L)"));
    action_L->setCheckable(true);
    QAction * action_R = group->addAction(tr("Right Allign(&R)"));
    action_R->setCheckable(true);
    QAction * action_C = group->addAction(tr("Centro Allign(&C)"));
    action_C->setCheckable(true);
    action_L->setChecked(true);
    editMenu->addSeparator();
    editMenu->addAction(action_L);
    editMenu->addAction(action_R);
    editMenu->addAction(action_C);

    QToolButton * toolBtn = new QToolButton(this);
    toolBtn->setText(tr("Color"));
    QMenu * colorMenu = new QMenu(this);
    colorMenu->addAction(tr("red"));
    colorMenu->addAction(tr("blue"));
    toolBtn->setMenu(colorMenu);
    toolBtn->setPopupMode(QToolButton::MenuButtonPopup);
    ui->toolBar->addWidget(toolBtn);
    QSpinBox * spinBox = new QSpinBox(this);
    ui->toolBar->addWidget(spinBox);

    ui->statusbar->showMessage(tr("welcome use this software ! welcome use this software ! welcome use this software !"));
    QLabel * permanent = new QLabel(this);
    permanent->setFrameStyle(QFrame::Box | QFrame::Sunken);
    permanent->setText("www.qter.com");
    ui->statusbar->addPermanentWidget(permanent);
    ui->statusbar->setSizeGripEnabled(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_action_New_triggered()
{
    QTextEdit * edit = new QTextEdit(this);
    QMdiSubWindow * child = ui->mdiArea->addSubWindow(edit);
    child->setWindowTitle(tr("mulit sub window"));
    child->show();
}

void MainWindow::on_actionshow_dock_triggered()
{
    ui->dockWidget->show();
}
