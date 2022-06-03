#ifndef EXEGLOBAL_H
#define EXEGLOBAL_H

#include <QVector>
#include <QString>
#include <_BK/UserModule/user.h>
#include <_BK/Reference/Reference.h>

#include <QJsonObject>
#include <QJsonDocument>
#include <QByteArray>
#include <QFile>
#include <QJsonArray>

class PRMS{

public:
    PRMS(){ ;; };
    ~PRMS(){ ;; };

public:
    static int g_currentRole;
    static QVector<User> g_UserList;
    static void init();
    static QVector<Reference> g_referenceList;

    static void readUserFromJson(QString _file);
    static void readReferenceFromJson(QString _file);
};


#endif // EXEGLOBAL_H
