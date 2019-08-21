#include "mysqldbhelp.h"

#include <QApplication>
#include <QtSql/QSqlDatabase>
#include <QDebug>
#include <QCoreApplication>
#include <QString>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlDatabase>
#include <QMessageLogger>
#include "qreadxmlcfg.h"

#include "cominc.h"

MysqlDBHelp::MysqlDBHelp()
{

}



bool MysqlDBHelp::testMysqlAvailabe()
{

    QString app =  QApplication::applicationFilePath();
    QCoreApplication::addLibraryPath(app ) ;


    qDebug() << "Available drivers:";
    QStringList drivers = QSqlDatabase::drivers();
    foreach(QString driver, drivers) {
       LOGI  << driver.toStdString()  ;
       qDebug() << driver;
    }

    // 创建数据库
    {
       QSqlDatabase check_db = QSqlDatabase::addDatabase("QMYSQL");
       check_db.setHostName(QReadXMLCfg::GetInstance()->strMysqlHost);
       check_db.setUserName(QReadXMLCfg::GetInstance()->strUser);
       check_db.setPassword(QReadXMLCfg::GetInstance()->strPasswd);
       if(!check_db.open())   {
           qDebug() << "Failed t open to   mysql  ";
           LOGE << "Failed t open to   mysql  ";
           return false ;
       } else  {
           qDebug()<<"open succeeded";
       }


       auto querystring = "CREATE DATABASE IF NOT EXISTS DB_MineCars DEFAULT CHARSET utf8 COLLATE utf8_general_ci";
       check_db.exec(querystring);
       if (check_db.lastError().isValid())
       {
           qDebug() << check_db.lastError();
           qDebug() << "Create database failed.";
           return false ;
       }
       else
       {
           qDebug() << "connect to DB_MineCars sucessful";
           LOGI  << "connect to DB_MineCars sucessful";
       }
       check_db.close() ;
    }

    //建立数据库连接
    _db = QSqlDatabase::addDatabase("QMYSQL");
    _db.setHostName(QReadXMLCfg::GetInstance()->strMysqlHost);
    _db.setDatabaseName("DB_MineCars");
    _db.setUserName(QReadXMLCfg::GetInstance()->strUser);
    _db.setPassword(QReadXMLCfg::GetInstance()->strPasswd);
    if (!_db.open()) {
        qDebug() << "Failed t connect to root mysql admin";
        LOGE << "Failed t connect to root mysql admin";

        return false ;
    }
    else{

       qDebug() << "connect to DB_MineCars sucessful";
       LOGI  << "connect to DB_MineCars sucessful";
    }

    return true ;
}


bool MysqlDBHelp::initTables()
{
    //0 建立数据看
    // "CREATE DATABASE IF NOT EXISTS DB_MineCars DEFAULT CHARSET utf8 COLLATE utf8_general_ci"

     QSqlQuery query(_db);

    {
        //1 车的类型的表格
        QString sqlcarclass =" CREATE TABLE IF NOT EXISTS `tb_carsclass` (  \
                   `id` int(11) NOT NULL AUTO_INCREMENT,  \
                   `name` varchar(255) DEFAULT NULL,  \
                    PRIMARY KEY (`id`)    \
                  ) ENGINE=InnoDB AUTO_INCREMENT=13 DEFAULT CHARSET=utf8; " ;


        auto ret_carClass = query.exec(sqlcarclass) ;
        qDebug()  << "  ret_carClass=="  << ret_carClass  ;
    }





    {
        //3 车的表格
        QString sqlcars =" CREATE TABLE IF NOT EXISTS `tb_cars` (  \
                   `id` int(11) NOT NULL AUTO_INCREMENT,  \
                   `name` varchar(255) DEFAULT NULL,  \
                    `carsclassid`  int(11)  NOT NULL , \
                    FOREIGN KEY(carsclassid) REFERENCES tb_carsclass(id) ,\
                    PRIMARY KEY (`id`)    \
                  ) ENGINE=InnoDB AUTO_INCREMENT=13 DEFAULT CHARSET=utf8; " ;


       auto ret_cars = query.exec(sqlcars) ;
       qDebug()  << "  ret_cars=="  << ret_cars  ;
    }


    {
        //4 人的表格
        QString sqlpeople =" CREATE TABLE IF NOT EXISTS `tb_people` (  \
                   `id` int(11) NOT NULL AUTO_INCREMENT,  \
                   `name` varchar(255) DEFAULT NULL,  \
                   `carid` int(11)  NOT NULL, \
                    FOREIGN KEY(carid) REFERENCES tb_cars(id) ,\
                    PRIMARY KEY (`id`)    \
                  ) ENGINE=InnoDB AUTO_INCREMENT=13 DEFAULT CHARSET=utf8; " ;


        auto ret_people = query.exec(sqlpeople) ;
        qDebug()  << "  ret_people=="  << ret_people  ;
    }


    {
    //5 日常工作
    //    DROP TABLE IF EXISTS `tb_carswork`;
   QString sql_carswork =  "CREATE TABLE IF NOT EXISTS `tb_carswork` ( \
          `id` int(11) NOT NULL AUTO_INCREMENT,      \
          `date` date NOT NULL,                      \
          `addtime` datetime NOT NULL,               \
          `carid` int(11) NOT NULL,                  \
           FOREIGN KEY(carid) REFERENCES tb_cars(id) ,\
          `peopleid` int(11) NOT NULL,        \
           FOREIGN KEY(peopleid) REFERENCES tb_people(id) ,\
          `rz_where` varchar(100) DEFAULT NULL,     \
          `rz_type` varchar(50) DEFAULT NULL,       \
          `yk_carnums` int(11) DEFAULT NULL,        \
          `yk_tons` double DEFAULT NULL,            \
          `xk_carnums` int(11) DEFAULT NULL,        \
          `xk_tons` double DEFAULT NULL,            \
          `wk_carnums` int(11) DEFAULT NULL,        \
          `wk_tons` double DEFAULT NULL,            \
          `by_carnums` int(11) DEFAULT NULL,        \
          `by_tons` double DEFAULT NULL,            \
          `rg_where` varchar(100) DEFAULT NULL,     \
          `rg_type` varchar(50) DEFAULT NULL,       \
          `rg_hours` double DEFAULT NULL,           \
          `hoursofdays` double DEFAULT NULL,        \
          `diesel_oil` double DEFAULT NULL,         \
          `materials` double DEFAULT NULL,          \
          `repair` double DEFAULT NULL,             \
          `comment` varchar(300) DEFAULT NULL,      \
           PRIMARY KEY (`id`)                       \
        ) ENGINE=InnoDB AUTO_INCREMENT=13 DEFAULT CHARSET=utf8; " ;

        auto ret_carswork = query.exec(sql_carswork) ;

   }

    return false  ;
}
