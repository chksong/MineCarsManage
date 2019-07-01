#ifndef MYSQLDBHELP_H
#define MYSQLDBHELP_H

#include <QtSql/QSqlDatabase>


class MysqlDBHelp
{
public:
    MysqlDBHelp();
    bool  testMysqlAvailabe()  ;

    bool initTables() ;
private:
    QSqlDatabase  _db  ;
};

#endif // MYSQLDBHELP_H
