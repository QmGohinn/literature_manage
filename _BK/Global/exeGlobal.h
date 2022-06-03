#ifndef EXEGLOBAL_H
#define EXEGLOBAL_H

#include <QVector>
#include <QString>
#include <_BK/UserModule/user.h>
#include <_BK/Reference/Reference.h>

class PRMS{

public:
    PRMS(){ ;; };
    ~PRMS(){ ;; };

public:
    static int g_currentRole;
    static QVector<User> g_UserList;
    static void init();
    static QVector<Reference> g_referenceList;
};


#endif // EXEGLOBAL_H
