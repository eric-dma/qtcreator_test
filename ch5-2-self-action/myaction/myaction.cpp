#include "myaction.h"
#include <QLineEdit>
#include <QSplitter>
#include <QLabel>

MyAction::MyAction(QObject * parent) :
    QWidgetAction(parent)
{
    lineEdt = new QLineEdit;
    connect(lineEdt, &QLineEdit::returnPressed, this, &MyAction::sendText);
}

QWidget *MyAction::createWidget(QWidget *parent)
{
    if(parent->inherits("Qmenu") || parent->inherits("QToolBar")) {
        QSplitter * splitter = new QSplitter(parent);
        QLabel * label = new QLabel;
        label->setText(tr("insert word"));
        splitter->addWidget(label);
        splitter->addWidget(lineEdt);
        return splitter;
    }
    return 0;
}

void MyAction::sendText()
{
    emit getText(lineEdt->text());
    lineEdt->clear();
}
