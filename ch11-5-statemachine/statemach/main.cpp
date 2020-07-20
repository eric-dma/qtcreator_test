#include <QApplication>
#include <QPushButton>
#include <QState>
#include <QStateMachine>
#include <QSignalTransition>
#include <QPropertyAnimation>

int main(int argc, char *argv[])
{
    QApplication app(argc,argv);
    QPushButton button("State Machine");
    QStateMachine machine;
    QState * s1 = new QState(&machine);
    QState * s2 = new QState(&machine);
    QState * s3 = new QState(&machine);
    s1->assignProperty(&button, "geometry", QRect(100,100,120,50));
    s2->assignProperty(&button, "geometry", QRect(300,100,120,50));
    s3->assignProperty(&button, "geometry", QRect(200,100,120,50));
    s1->addTransition(&button,SIGNAL(clicked()),s2);
    s2->addTransition(&button,SIGNAL(clicked()),s3);
    s3->addTransition(&button,SIGNAL(clicked()),s1);
    QObject::connect(s3,&QState::entered,&button,&QPushButton::showMinimized);
    machine.setInitialState(s1);
    machine.start();
    button.show();
    return app.exec();
}
