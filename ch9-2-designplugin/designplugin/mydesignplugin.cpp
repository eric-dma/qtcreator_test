#include "mydesignplugin.h"
#include <QPushButton>
#include <QHBoxLayout>

MyDesignPlugin::MyDesignPlugin(QWidget *parent) :
    QWidget(parent)
{
    QPushButton * button1 = new QPushButton(this);
    QPushButton * button2 = new QPushButton(this);
    button1->setText("hello");
    button2->setText("Qt!");
    QHBoxLayout * layer = new QHBoxLayout;
    layout->addWidget(button1);
    layout->addWidget(button2);
    setLayout(layout);
}
