#ifndef MYACTION_H
#define MYACTION_H

#include <QWidget>
#include <QWidgetAction>

class QLineEdit;

class MyAction : public QWidgetAction
{
    Q_OBJECT
public:
    explicit MyAction(QObject * parent = 0);
protected:
    QWidget * createWidget(QWidget *parent) override;
signals:
    void getText(const QString &string);
private slots:
    void sendText();
private:
    QLineEdit * lineEdt;
};

#endif // MYACTION_H
