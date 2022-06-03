#ifndef LOGINUI_H
#define LOGINUI_H

#include <QDialog>

namespace Ui {
class UserLoginForm;
}

class UserLoginForm : public QDialog
{
    Q_OBJECT

public:
    explicit UserLoginForm(QWidget *parent = nullptr);
    ~UserLoginForm();

private slots:
    void on_m_LoginBtn_clicked();
    void on_m_ExitBtn_clicked();

private:
    Ui::UserLoginForm *ui;
};

#endif // LOGINUI_H
