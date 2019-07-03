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
               `id` int(11) NOT NULL AUTO_INCREMENT,  \
               `name` varchar(255) DEFAULT NULL,  \
                PRIMARY KEY (`id`)    \
              ) ENGINE=InnoDB AUTO_INCREMENT=13 DEFAULT CHARSET=utf8; " ;

    QSqlQuery query(_db);
    auto ret_carClass = query.exec(sqlcarclass) ;


//    DROP TABLE IF EXISTS `tb_carswork`;
//    CREATE TABLE `tb_carswork` (
//      `id` int(11) NOT NULL AUTO_INCREMENT,
//      `date` date NOT NULL,
//      `addtime` datetime NOT NULL,
//      `carid` int(11) NOT NULL,
//      `carclass` varchar(100) NOT NULL,
//      `people` varchar(50) DEFAULT NULL,
//      `hoursOfMonth` int(11) DEFAULT NULL,
//      `rz_where` varchar(100) DEFAULT NULL,
//      `rz_type` varchar(50) DEFAULT NULL,
//      `tk_carnums` int(11) DEFAULT NULL,
//      `tk_tons` double DEFAULT NULL,
//      `xk_carnums` int(11) DEFAULT NULL,
//      `xk_tons` double DEFAULT NULL,
//      `wk_carnums` int(11) DEFAULT NULL,
//      `wk_tons` double DEFAULT NULL,
//      `by_carnums` int(11) DEFAULT NULL,
//      `by_tons` double DEFAULT NULL,
//      `rg_where` varchar(100) DEFAULT NULL,
//      `rg_type` varchar(50) DEFAULT NULL,
//      `rg_hours` double DEFAULT NULL,
//      `hoursofdays` double DEFAULT NULL,
//      `diesel_oil` double DEFAULT NULL,
//      `materials` double DEFAULT NULL,
//      `repair` double DEFAULT NULL,
//      `comment` varchar(300) DEFAULT NULL,
//      PRIMARY KEY (`id`)
//    ) ENGINE=InnoDB DEFAULT CHARSET=latin1;




    return false  ;
}
