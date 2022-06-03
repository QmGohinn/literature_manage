#ifndef REFERADD_H
#define REFERADD_H

#include <QDialog>

namespace Ui {
class ReferAdd;
}

class ReferAdd : public QDialog
{
    Q_OBJECT

public:
    explicit ReferAdd(QWidget *parent = nullptr);
    ~ReferAdd();

public:
    void clearThis();

private slots:
    void on_pushButton_2_clicked();
    void on_pushButton_clicked();

private:
    Ui::ReferAdd *ui;
};

#endif // REFERADD_H
