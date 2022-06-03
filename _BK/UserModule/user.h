#ifndef USER_H
#define USER_H

#include <QString>
#include <QVector>

class User{

public:
    User(QString _name, QString _PWD, int _role):m_name(_name), m_PWD(_PWD), m_role(_role){ ;; };
    ~User(){ ;; };

private:
    QString m_name = "";
    QString m_PWD = "";
    int m_role = 0;

public:
    QString getName(){
        return m_name;
    }

    QString getPWD(){
        return m_PWD;
    }

    int getRole(){
        return m_role;
    }
};

#endif // USER_H
