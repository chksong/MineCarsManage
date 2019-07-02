
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <carsclassdialog.h>

#include <QDebug>




MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    dlgCarsClass = nullptr    ;

    // 关联按钮
    connect(ui->actionCarsClass, &QAction::triggered , this ,&MainWindow::carsClassManage) ;
    connect(ui->actionAddOneDay, &QAction::triggered, this,  &MainWindow::addOneDayWork)  ;
}

MainWindow::~MainWindow()
{
    delete ui;
}




// 添加车的类型
void MainWindow::carsClassManage(bool var)
{
  //  qDebug() <<" carsClassManage " << var <<  endl ;
    if(dlgCarsClass) {
        dlgCarsClass->show() ;
    }
    else {
        dlgCarsClass = new CarsClassDialog (this) ;
        dlgCarsClass->show();
    }
}

// 添加每日工作
void MainWindow::addOneDayWork(bool var)
{
    if(dlgAddDayWorkDlg) {
        dlgAddDayWorkDlg->show() ;
    }
    else {
        dlgAddDayWorkDlg = new AddDayWorkDialog () ;
        dlgAddDayWorkDlg->show() ;
    }
}
