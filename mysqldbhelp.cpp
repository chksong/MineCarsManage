#include "mysqldbhelp.h"

#include <QApplication>
#include <QtSql/QSqlDatabase>
#include <QDebug>
#include <QCoreApplication>
#include <QString>
#include <QSqlQuery>


MysqlDBHelp::MysqlDBHelp()
{

}



bool MysqlDBHelp::testMysqlAvailabe()
{

    QString app =  QApplication::applicationFilePath();
    QCoreApplication::addLibraryPath(app ) ;


    qDebug() << "Available drivers:";
    QStringList drivers = QSqlDatabase::drivers();
    foreach(QString driver, drivers)
       qDebug() << driver;

    //建立数据库连接
    _db = QSqlDatabase::addDatabase("QMYSQL");
    _db.setHostName("localhost");
    _db.setDatabaseName("DB_MineCars");
    _db.setUserName("root");
    _db.setPassword("123456");
    if (!_db.open()) {
        qDebug() << "Failed t connect to root mysql admin";
        return false;
    }
    else
       qDebug() << "connect to DB_MineCars sucessful";

    return true ;
}


bool MysqlDBHelp::initTables()
{
    //1 车的类型的表格
    QString sqlcarclass =" CREATE TABLE IF NOT EXISTS `tb_carsclass` (  \
                `id` int(11) NOT NULL,  \
                `name` varchar(255) DEFAULT NULL,  \
                PRIMARY KEY (`id`)    \
              ) ENGINE=InnoDB DEFAULT CHARSET=latin1; " ;

    QSqlQuery query(_db);
    auto ret_carClass = query.exec(sqlcarclass) ;




    return false  ;
}
