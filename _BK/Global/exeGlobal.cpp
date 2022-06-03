#include <_BK/Global/exeGlobal.h>

int PRMS::g_currentRole;
/// 用户列表
QVector<User> PRMS::g_UserList;
/// 文献列表
QVector<Reference> PRMS::g_referenceList;

void PRMS::init()
{
    User* _simple = new User("simple", "simple", 0);
    User* _admin = new User("admin", "admin", 1);

    g_UserList.push_back(*_simple);
    g_UserList.push_back(*_admin);

    Reference* _r1 = new Reference("DOI1", "author1", "title1", "journal1", "year1", "Article");
    Reference* _r2 = new Reference("DOI2", "author2", "title2", "journal2", "year2", "Review");
    Reference* _r3 = new Reference("DOI3", "author3", "title3", "journal3", "year3", "Review");
    Reference* _r4 = new Reference("DOI4", "author4", "title4", "journal4", "year4", "Article");
    Reference* _r5 = new Reference("DOI5", "author5", "title5", "journal5", "year5", "Review");

    Reference* _r6 = new Reference("DOI6", "author6", "title6", "journal6", "year6", "Review");
    Reference* _r7 = new Reference("DOI7", "author7", "title7", "journal7", "year7", "Article");
    Reference* _r8 = new Reference("DOI8", "author8", "title8", "journal8", "year8", "Review");
    Reference* _r9 = new Reference("DOI9", "author9", "title9", "journal9", "year9", "Review");
    Reference* _ra = new Reference("DOIa", "authora", "titlea", "journala", "yeara", "Review");

    g_referenceList.push_back(*_r1);
    g_referenceList.push_back(*_r2);
    g_referenceList.push_back(*_r3);
    g_referenceList.push_back(*_r4);
    g_referenceList.push_back(*_r5);

    g_referenceList.push_back(*_r6);
    g_referenceList.push_back(*_r7);
    g_referenceList.push_back(*_r8);
    g_referenceList.push_back(*_r9);
    g_referenceList.push_back(*_ra);
}
