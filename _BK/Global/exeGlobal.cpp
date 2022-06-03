#include <_BK/Global/exeGlobal.h>
#include <QMessageBox>

int PRMS::g_currentRole;
/// 用户列表
QVector<User> PRMS::g_UserList;
/// 文献列表
QVector<Reference> PRMS::g_referenceList;

void PRMS::init()
{
    readUserFromJson("..\\json\\admin.json");
    readReferenceFromJson("..\\json\\Reference.json");
}

void PRMS::readUserFromJson(QString _file)
{
    QFile file(_file);
    file.open(QIODevice::ReadOnly);
    QByteArray data = file.readAll();
    file.close();

    QJsonParseError parseError;
    QJsonDocument doc = QJsonDocument::fromJson(data, &parseError);
    if(parseError.error != QJsonParseError::NoError){
        return;
    }
    QJsonObject obj = doc.object();
    if(obj.contains("User"))
    {
        QJsonValue arrayTemp = obj.value("User");
        QJsonArray array = arrayTemp.toArray();

        for(int i = 0; i < array.size(); ++i){
            QJsonValue sub = array.at(i);
            QJsonObject subObj = sub.toObject();
            QJsonValue name = subObj.value("name");
            QJsonValue pwd = subObj.value("pwd");
            QJsonValue role = subObj.value("role");

            User* _user = new User(name.toString(), pwd.toString(), role.toInt());
            g_UserList.push_back(*_user);
        }
    }
}

void PRMS::readReferenceFromJson(QString _file)
{
    QFile file(_file);
    file.open(QIODevice::ReadOnly);
    QByteArray data = file.readAll();
    file.close();

    QJsonParseError parseError;
    QJsonDocument doc = QJsonDocument::fromJson(data, &parseError);
    if(parseError.error != QJsonParseError::NoError){
        QMessageBox::warning(nullptr, "提 示", "JSON文件格式错误!", "知道了");
        return;
    }
    QJsonObject obj = doc.object();
    if(obj.contains("Reference"))
    {
        QJsonValue arrayTemp = obj.value("Reference");
        QJsonArray array = arrayTemp.toArray();

        g_referenceList.clear();

        for(int i = 0; i < array.size(); ++i){
            QJsonValue sub = array.at(i);
            QJsonObject subObj = sub.toObject();
            QJsonValue doi = subObj.value("doi");
            QJsonValue author = subObj.value("author");
            QJsonValue title = subObj.value("title");
            QJsonValue journal = subObj.value("journal");
            QJsonValue year = subObj.value("year");
            QJsonValue type = subObj.value("type");

            Reference* _r = new Reference(doi.toString(), author.toString(), title.toString(), journal.toString(), year.toString(), type.toString());
            g_referenceList.push_back(*_r);
        }
    }
    else{
        QMessageBox::warning(nullptr, "提 示", "导入的json文件格式不正确!", "知道了");
        return;
    }
}
