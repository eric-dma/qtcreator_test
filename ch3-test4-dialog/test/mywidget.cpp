#include "mywidget.h"
#include "ui_mywidget.h"
#include <QDialog>
#include <QColorDialog>
#include <QDebug>
#include <QFileDialog>
#include <QFontDialog>
#include <QInputDialog>
#include <QMessageBox>
#include <QProgressDialog>
#include <QErrorMessage>

MyWidget::MyWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MyWidget)
{
    errordlg = new QErrorMessage(this);
    ui->setupUi(this);
}

MyWidget::~MyWidget()
{
    delete ui;
}


void MyWidget::on_pushButton_clicked()
{
//用类的静态函数
    //QColor color = QColorDialog::getColor(Qt::red, this, tr("颜色对话"),QColorDialog::ShowAlphaChannel);
//创建对象的模态方式
    QColorDialog dialog(Qt::red,this);
    dialog.setOption(QColorDialog::ShowAlphaChannel);
    dialog.exec();
    QColor color = dialog.currentColor();

    qDebug() << "color: " << color;
}

void MyWidget::on_pushButton_2_clicked()
{
    //QString fileName = QFileDialog::getOpenFileName(this, tr("文本对话"), "D:", tr("文件(*cpp *h)"));
    //qDebug() << "filename: " << fileName;

    QStringList fileNames = QFileDialog::getOpenFileNames(this, tr("文本对话"), "D:", tr("文件(*cpp *h)"));
    qDebug() << "filenames: " << fileNames;
}

void MyWidget::on_pushButton_3_clicked()
{
    bool ok;
    QFont font = QFontDialog::getFont(&ok,this);
    if(ok) ui->pushButton_3->setFont(font);
    else qDebug() << tr("没有可选得字体!");
}

void MyWidget::on_pushButton_4_clicked()
{
    bool ok;
    QString string = QInputDialog::getText(this, tr("输入"),tr("请输入："), QLineEdit::Normal, tr("admin"), &ok);
    if(ok) qDebug() << "string" << string;

    int value1 = QInputDialog::getInt(this, tr("输入整数对话"),tr("请输入整数："),100,-1000,1000,2,&ok);
    if(ok) qDebug() << "value1:" << value1;

    double value2 = QInputDialog::getDouble(this, tr("输入"),tr("请输入："),1.00,-1000,1000,10,&ok);
    if(ok) qDebug() << "value2:" << value2;
}

void MyWidget::on_pushButton_5_clicked()
{
    int ret1 = QMessageBox::question(this, tr("question box"), tr("do u know qt?"), QMessageBox::No, QMessageBox::Yes);
    if(ret1 == QMessageBox::Yes) qDebug()<<tr("Question!");

    int ret2 = QMessageBox::information(this, tr("information box"), tr("this is information"), QMessageBox::Ok);
    if(ret2 == QMessageBox::Ok) qDebug()<<tr("Information!");

    int ret3 = QMessageBox::warning(this, tr("warning box"), tr("this is warning"), QMessageBox::Abort);
    if(ret3 == QMessageBox::Abort) qDebug()<<tr("warning!");

    int ret4 = QMessageBox::critical(this, tr("critical box"), tr("this is critical error"),QMessageBox::YesAll);
    if(ret4 == QMessageBox::YesAll) qDebug()<<"error!";

    QMessageBox::about(this, tr("about box"), tr("this is about box"));
    QMessageBox::aboutQt(this, tr("this is about qt"));
}

void MyWidget::on_pushButton_6_clicked()
{
    QProgressDialog dialog(tr("file copy progress"), tr("cancel"), 0, 5000, this);
    dialog.setWindowTitle(tr("progress dialog"));
    dialog.setWindowModality(Qt::WindowModal);
    dialog.show();
    for(int i=0; i<5000; i++) {
        dialog.setValue(i);
        QCoreApplication::processEvents();
        if(dialog.wasCanceled()) break;
    }
    dialog.setValue(5000);
    qDebug()<<tr("copy end");
}

void MyWidget::on_pushButton_7_clicked()
{
    errordlg->setWindowTitle(tr("error info box"));
    errordlg->showMessage(tr("this is error info"));
}

QWizardPage *MyWidget::createPage1()
{
    QWizardPage *page = new QWizardPage;
    page->setTitle(tr("introduction"));
    return page;
}

QWizardPage *MyWidget::createPage2()
{
    QWizardPage *page = new QWizardPage;
    page->setTitle(tr("install"));
    return page;
}

QWizardPage *MyWidget::createPage3()
{
    QWizardPage *page = new QWizardPage;
    page->setTitle(tr("launch"));
    return page;
}

void MyWidget::on_pushButton_8_clicked()
{
    QWizard wizard(this);
    wizard.setWindowTitle(tr("wizard box"));
    wizard.addPage(createPage1());
    wizard.addPage(createPage2());
    wizard.addPage(createPage3());
    wizard.exec();
}
