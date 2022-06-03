#ifndef REFERENCE_H
#define REFERENCE_H

#include <QString>

class Reference{

public:
    Reference(QString _DOI, QString _author, QString _title, QString _journal, QString _year, QString _type)
        :m_DOI(_DOI), m_author(_author), m_title{_title}, m_journal(_journal), m_year(_year), m_type(_type){};
    ~Reference(){};

private:
    QString m_DOI = "";
    QString m_author = "";
    QString m_title = "";
    QString m_journal = "";
    QString m_year = "";
    QString m_type = "";

public:
    QString getDOI() const{
        return m_DOI;
    }

    QString getAuthor(){
        return m_author;
    }

    QString getTitle(){
        return m_title;
    }

    QString getJournal(){
        return m_journal;
    }

    QString getYear(){
        return m_year;
    }

    QString getType(){
        return m_type;
    }
};

#endif // REFERENCE_H
