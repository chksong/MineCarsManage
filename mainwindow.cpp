
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "carsclassdialog.h"
#include "carsmanagedialog.h"
#include "peopledialog.h"


#include <QDebug>
#include <QSqlTableModel>



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    resize(1024,768);

    dlgCarsClass = nullptr    ;


    // 初始化表格
    initTable() ;


    // 关联按钮
    connect(ui->actionCarsClass, &QAction::triggered , this ,&MainWindow::carsClassManage) ;
    connect(ui->actionAddOneDay, &QAction::triggered, this,  &MainWindow::addOneDayWork)  ;
    connect(ui->actionCarsManag, &QAction::triggered, this,  &MainWindow::carsManage) ;
    connect(ui->actionPeople ,   &QAction::triggered ,this,  &MainWindow::peopleManage )  ;



}

MainWindow::~MainWindow()
{
    delete ui;
}


// 初始哈表格·
void MainWindow::initTable()
{
    // 初始化数据库的表格管理
    model = new QSqlTableModel(this);
    model->setTable("tb_carswork");
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);

    ui->tableView->setModel(model);
  //  ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers); //使其不可编辑
    ui->tableView->setColumnHidden(0, true);
    ui->tableView->setColumnHidden(2, true);
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);


  //  model->setHeaderData(0, Qt::Horizontal, "ID");
    model->setHeaderData(1, Qt::Horizontal, QStringLiteral("日期"));
    model->setHeaderData(3, Qt::Horizontal, QStringLiteral("车号"));
    model->setHeaderData(4, Qt::Horizontal, QStringLiteral("品牌类型"));
    model->setHeaderData(5, Qt::Horizontal, QStringLiteral("员工号"));
    model->setHeaderData(6, Qt::Horizontal, QStringLiteral("月初小时数"));

    model->setHeaderData(7, Qt::Horizontal, QStringLiteral("日装 工作地点"));
    model->setHeaderData(8, Qt::Horizontal, QStringLiteral("日装 工作类型"));

    model->setHeaderData(9, Qt::Horizontal, QStringLiteral("铁原矿车数"));
    model->setHeaderData(10, Qt::Horizontal, QStringLiteral("铁原矿吨数"));

    model->setHeaderData(11, Qt::Horizontal, QStringLiteral("细矿石车数"));
    model->setHeaderData(12, Qt::Horizontal, QStringLiteral("细矿石吨数"));

    model->setHeaderData(13, Qt::Horizontal, QStringLiteral("尾矿车数"));
    model->setHeaderData(14, Qt::Horizontal, QStringLiteral("尾矿吨数"));

    model->setHeaderData(15, Qt::Horizontal, QStringLiteral("剥岩车数"));
    model->setHeaderData(16, Qt::Horizontal, QStringLiteral("剥岩吨数"));


    model->setHeaderData(17, Qt::Horizontal, QStringLiteral("日工工作地点"));
    model->setHeaderData(18, Qt::Horizontal, QStringLiteral("日工工作类型"));
    model->setHeaderData(19, Qt::Horizontal, QStringLiteral("日工工时数"));

    model->setHeaderData(20, Qt::Horizontal, QStringLiteral("本日工作时长"));

    model->setHeaderData(21, Qt::Horizontal, QStringLiteral("柴油用量"));
    model->setHeaderData(22, Qt::Horizontal, QStringLiteral("材料费"));
    model->setHeaderData(23, Qt::Horizontal, QStringLiteral("修理费"));
    model->setHeaderData(24, Qt::Horizontal, QStringLiteral("备注"));



    model->select(); //选取整个表的所有行

}


// 车辆管理
void  MainWindow::carsManage(bool var)
{
    CarsManageDialog *dlg = new CarsManageDialog(this) ;
    dlg->exec() ;
}

void MainWindow::peopleManage(bool var)
{

}


//  车的类型
void MainWindow::carsClassManage(bool var)
{

    dlgCarsClass = new CarsClassDialog (this) ;
    dlgCarsClass->exec()  ;
}

// 添加每日工作
void MainWindow::addOneDayWork(bool var)
{
 //  https://blog.csdn.net/hebbely/article/details/54285855
 // 模式非模式对话框

    dlgAddDayWorkDlg = new AddDayWorkDialog () ;
    dlgAddDayWorkDlg->exec() ;

    {
         model->select(); //选取整个表的所有行
    }
}

// 刷新
void MainWindow::on_PB_refresh_clicked()
{
   model->select(); //选取整个表的所有行
}



