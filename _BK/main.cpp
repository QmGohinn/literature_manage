#include <_APL/mainUI/mainuiform.h>
#include <_APL/LoginUI/loginui.h>

#include <QApplication>
#include <QThread>
#include <_BK/UserModule/user.h>
#include <_BK/Global/exeGlobal.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    PRMS::init();
    /// 登录界面
    UserLoginForm* _userLoginForm = new UserLoginForm;
    /// 登录失败 或 点击退出
    if(_userLoginForm->exec() != QDialog::Accepted)
    {
        return 0;
    }
    QThread::sleep(2);

    mainUIForm w;
    w.show();
    return a.exec();
}
