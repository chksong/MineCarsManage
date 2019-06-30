
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <carsclassdialog.h>

#include <QDebug>




MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // 关联按钮
    connect(ui->actionCarsClass, &QAction::triggered , this ,&MainWindow::carsClassManage) ;
}

MainWindow::~MainWindow()
{
    delete ui;
}




// 添加车的类型
void MainWindow::carsClassManage(bool var)
{
    qDebug() <<" carsClassManage " << var <<  endl ;

    CarsClassDialog *dlg  = new CarsClassDialog() ;
    dlg->show() ;


}
