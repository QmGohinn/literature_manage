#include "loginui.h"
#include "ui_loginui.h"

#include <QMessageBox>
#include <_BK/UserModule/user.h>
#include <_BK/Global/exeGlobal.h>

UserLoginForm::UserLoginForm(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::UserLoginForm)
{
    ui->setupUi(this);
    this->setWindowIcon(QIcon(":/res/titleico/people.ico"));
    ui->m_LoginBtn->setDefault(true);

    /// 方便起见 给UI预设账号 密码
    ui->m_AccountLineEdit->setText("admin");
    ui->m_PasswordLineEdit->setText("admin");
}

UserLoginForm::~UserLoginForm()
{
    delete ui;
}

/// 登录按钮
void UserLoginForm::on_m_LoginBtn_clicked()
{
    QString input_Account = ui->m_AccountLineEdit->text().trimmed();
    QString input_Password = ui->m_PasswordLineEdit->text();

    if(input_Account == "" || input_Password == "")
    {
        QMessageBox::critical(this, "提示", "账号和密码不能为空!", tr("确定"));
        return;
    }

    bool _loginFlg = false;
    for(auto& _it : PRMS::g_UserList){
        if(_it.getName().compare(input_Account) == 0
                && _it.getPWD().compare(input_Password) == 0){
            _loginFlg = true;
            PRMS::g_currentRole = _it.getRole();
            break;
        }
    }

    if(_loginFlg)
    {
        QDialog::accept();
    }
    else
    {
        QMessageBox::warning(this, "提示", "用户不存在或密码错误!", tr("确定"));
    }
}

/// 退出按钮
void UserLoginForm::on_m_ExitBtn_clicked()
{
    QDialog::reject();
}
