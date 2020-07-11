#ifndef SUBDIALOG1_H
#define SUBDIALOG1_H

#include <QDialog>

namespace Ui {
class subDialog1;
}

class subDialog1 : public QDialog
{
    Q_OBJECT

public:
    explicit subDialog1(QWidget *parent = nullptr);
    ~subDialog1();

private slots:
    void on_exitButtonSub_clicked();

private:
    Ui::subDialog1 *ui;
};

#endif // SUBDIALOG1_H
