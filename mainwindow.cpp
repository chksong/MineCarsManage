
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "carsclassdialog.h"
#include "carsmanagedialog.h"
#include "peopledialog.h"


#include <QDebug>
#include <QSqlTableModel>
#include <QResizeEvent>
#include <QDesktopWidget>
#include <QSqlQuery>
#include <QTableWidgetItem>

#include <QGuiApplication>
#include <QScreen>
#include <QDialog>

#include "dialoghelp.h"

#include "HTableview/HHeaderModel.h"
#include "HTableview/HHeaderView.h"
#include "HTableview/TcTabelModel.h"

enum {
    COL_CARID       =   3 ,
    COL_PEOPLE      =   4 ,
    COL_RZ_WHERE    =   5 ,
} ;

const  int Col_Nums =17 ;




MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

//    旧有的API
//    QRect deskRect = QApplication::desktop()->screenGeometry();
//    this->setGeometry(deskRect);
    setGeometry( QGuiApplication::primaryScreen()->geometry()) ;

    // 初始化表格
    initTable() ;

    // 关联按钮
    connect(ui->actionCarsClass, &QAction::triggered , this ,&MainWindow::carsClassManage) ;
    connect(ui->actionAddOneDay, &QAction::triggered, this,  &MainWindow::addOneDayWork)  ;
    connect(ui->actionCarsManag, &QAction::triggered, this,  &MainWindow::carsManage) ;
    connect(ui->actionPeople ,   &QAction::triggered ,this,  &MainWindow::peopleManage )  ;
    connect(ui->actionhelp,      &QAction::triggered ,this, &MainWindow::dohelp) ;


    // 初始化tableWight的右键
    tableViewRightMenu = new QMenu() ;
    QAction* editAction = new QAction(QStringLiteral("编辑本行"),this);
    QAction* deleteAction = new QAction(QStringLiteral("删除本行"),this);

    tableViewRightMenu->addAction(editAction);
    tableViewRightMenu->addAction(deleteAction);

    connect(editAction ,   &QAction::triggered ,this, &MainWindow::on_menu_edit_clicked )  ;
    connect(deleteAction,  &QAction::triggered ,this, &MainWindow::on_menu_del_clicked) ;

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::getCarNameTypeByID(quint32 carID, QString &carType, QString &carName)
{
    QString strSql =QString("SELECT A.name AS CarName, B.name AS CarClassName  FROM tb_cars A, tb_carsclass B WHERE A.carsclassid = B.id and A.id ='%1'").arg(carID)  ;

    QSqlQuery  query ;
    query.exec(strSql) ;

    while (query.next()) {
        carName = query.value(0).toString() ;
        carType = query.value(1).toString() ;
    }
}

//加载数据
void MainWindow::reloadTableData()
{
    mMapRowWithRID.clear()  ;
    for ( int i = 0; i < ui->tableWidget->rowCount(); ++i )
    {
        ui->tableWidget->removeRow(i);
    }


    QString str = QString("select * from tb_carswork")  ;
    QSqlQuery query ;
    query.exec(str) ;


    ui->tableWidget->setColumnCount(22) ;

    for( int row_index = 0 ; query.next(); row_index++)
    {
        int RowCont=ui->tableWidget->rowCount();
        ui->tableWidget->insertRow(RowCont);//增加一行

        mMapRowWithRID.insert(row_index,   query.value(0).toULongLong());

        QString strCarName ,strCarType ;
        quint32  carid = query.value(COL_CARID).toUInt()  ;
        getCarNameTypeByID(carid,strCarType ,strCarName)  ;

        ui->tableWidget->setItem(row_index,0, new QTableWidgetItem(strCarName)) ;
        ui->tableWidget->setItem(row_index,1, new QTableWidgetItem(strCarType)) ;
        //一共显示20列
        for (int col_index= 0; col_index <=Col_Nums; col_index++)
        {
             ui->tableWidget->setItem(row_index,3+col_index,new QTableWidgetItem(query.value(COL_RZ_WHERE + col_index).toString())) ;
        }  // end for col_index

    }  // end for row_index
}


// 初始哈表格·
void MainWindow::initTable()
{
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers); //使其不可编辑
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    initHeadView(ui->tableWidget);
    reloadTableData();


    // 添加右键
    ui->tableWidget->setContextMenuPolicy(Qt::CustomContextMenu);
    connect(ui->tableWidget, &QTableWidget::customContextMenuRequested,this,&MainWindow::clicked_rightMenu)  ;
    return ;
}



void MainWindow::initHeadView(QTableWidget *pTableView)
{
    HHeaderView *pHeadView = new HHeaderView(Qt::Horizontal);
    HHeaderModel *pModel = new HHeaderModel();

    pModel->setItem(0,0, QStringLiteral("车号"));
    pModel->setItem(0,1, QStringLiteral("品牌型号"));
    pModel->setItem(0,2, QStringLiteral("月初小时数"));

    pModel->setSpan(0,0,3,1);  // 车号
    pModel->setSpan(0,1,3,1);  // 品牌型号
    pModel->setSpan(0,2,3,1);  // 品牌型号

    pModel->setItem(0,3, QStringLiteral("日装矿量"));
    pModel->setSpan(0,3,1,10);

    pModel->setItem(1,3, QStringLiteral(""));
    pModel->setItem(2,3, QStringLiteral("工作地点"));
    pModel->setItem(1,4, QStringLiteral(""));
    pModel->setItem(2,4, QStringLiteral("工作类型"));



    pModel->setItem(1,5, QStringLiteral("原铁矿"));
    pModel->setSpan(1,5,1,2); // 原铁矿
    pModel->setItem(2,5, QStringLiteral("车数"));
    pModel->setItem(2,6, QStringLiteral("吨数"));

    pModel->setItem(1,7, QStringLiteral("细铁矿"));
    pModel->setSpan(1,7,1,2);
    pModel->setItem(2,7, QStringLiteral("车数"));
    pModel->setItem(2,8, QStringLiteral("吨数"));

    pModel->setItem(1,9, QStringLiteral("尾矿"));
    pModel->setSpan(1,9,1,2);
    pModel->setItem(2,9, QStringLiteral("车数"));
    pModel->setItem(2,10, QStringLiteral("吨数"));

    pModel->setItem(1,11, QStringLiteral("剥岩"));
    pModel->setSpan(1,11,1,2);
    pModel->setItem(2,11, QStringLiteral("车数"));
    pModel->setItem(2,12, QStringLiteral("吨数"));


    pModel->setItem(0,13, QStringLiteral("日工时数"));
    pModel->setSpan(0,13,1,3);
    pModel->setItem(1,13, QStringLiteral(""));
    pModel->setItem(2,13, QStringLiteral("工作地点"));
    pModel->setItem(1,14, QStringLiteral(""));
    pModel->setItem(2,14, QStringLiteral("工作类型"));
    pModel->setItem(1,15, QStringLiteral(""));
    pModel->setItem(2,15, QStringLiteral("工时数"));


    pModel->setItem(0,16, QStringLiteral("工作时长"));
    pModel->setSpan(0,16,3,1);

    pModel->setItem(0,17, QStringLiteral("柴油用量"));
    pModel->setSpan(0,17,3,1);

    pModel->setItem(0,18, QStringLiteral("材料费"));
    pModel->setSpan(0,18,3,1);

    pModel->setItem(0,19 ,QStringLiteral("修理费"));
    pModel->setSpan(0,19,3,1);

    pModel->setItem(0,20 ,QStringLiteral("备注"));
    pModel->setSpan(0,20,3,1);



    pHeadView->setModel(pModel);
    pHeadView->setAutoScroll(true) ;
    pTableView->setHorizontalHeader(pHeadView);
}


// 车辆管理
void  MainWindow::carsManage(bool var)
{
    CarsManageDialog *dlg = new CarsManageDialog(this) ;
    dlg->exec() ;
}


//  人口管理
void MainWindow::peopleManage(bool var)
{
    PeopleDialog *dlg = new PeopleDialog() ;
    dlg->exec() ;

}


//  车的类型
void MainWindow::carsClassManage(bool var)
{

    dlgCarsClass = new CarsClassDialog (this) ;
    dlgCarsClass->exec()  ;
}



// 刷新
void MainWindow::on_PB_refresh_clicked()
{

    reloadTableData()  ;
}



void MainWindow::resizeEvent(QResizeEvent *event)
{
//    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
//    auto gtable = ui->tableView->geometry(); ;
//    auto ghead = ui->tableView->horizontalHeader()->geometry() ;
//    auto tmp = pHeadView->geometry();

   // pHeadView2->setGeometry(ghead) ;


//    ghead.setWidth(gtable.width()) ;
//    ui->tableView->horizontalHeader()->setGeometry(ghead) ;
//    ui->tableView->horizontalHeader()->update() ;
}


void MainWindow::dohelp()
{
    DialogHelp help ;
    help.exec() ;
}


void MainWindow::clicked_rightMenu(const QPoint &pos)
{
    QModelIndex index = ui->tableWidget->indexAt(pos);
    if(nullptr == index.model()) {
        return ;
    }
    else {
         tableViewRightMenu->exec(QCursor::pos());
    }
}


void MainWindow::on_menu_del_clicked()
{
     QModelIndex index = ui->tableWidget->currentIndex()  ;

}


void MainWindow::on_menu_edit_clicked()
{
     auto row  = ui->tableWidget->currentIndex().row()  ;
     qlonglong editRowCarID  = mMapRowWithRID[ row] ;

     dlgAddDayWorkDlg = new AddDayWorkDialog (this, editRowCarID) ;
     if( QDialog::Accepted ==dlgAddDayWorkDlg->exec() )
     {

     }


}
// 添加每日工作
void MainWindow::addOneDayWork(bool var)
{
 //  https://blog.csdn.net/hebbely/article/details/54285855
 // 模式非模式对话框

    dlgAddDayWorkDlg = new AddDayWorkDialog () ;
    if(QDialog::Accepted  == dlgAddDayWorkDlg->exec() )
    {
         //model->select(); //选取整个表的所有行
    }
}
