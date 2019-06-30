#include "mainwindow.h"
#include <QApplication>


#include <QtSql/QSqlDatabase>
#include <QDebug>



bool initMySQLDB()
{
    qDebug() << "Available drivers:";
    QStringList drivers = QSqlDatabase::drivers();
    foreach(QString driver, drivers)
       qDebug() << driver;


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
