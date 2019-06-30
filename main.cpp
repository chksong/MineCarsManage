#include "mainwindow.h"
#include <QApplication>


#include <QtSql/QSqlDatabase>
#include <QDebug>
#include <QCoreApplication>
#include <QString>


#include "mysqldbhelp.h"

bool initMySQLDB()
{
    MysqlDBHelp  help ;
    help.testMysqlAvailabe()  ;
    help.initTables()  ;




    return  true ;
}


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    initMySQLDB() ;


    MainWindow w;
    w.show();

    return a.exec();
}
