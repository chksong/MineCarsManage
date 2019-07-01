#include "carsclassdialog.h"
#include "ui_carsclassdialog.h"


#include <QSqlTableModel>
#include <QMessageBox>


CarsClassDialog::CarsClassDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CarsClassDialog)
{
    ui->setupUi(this);


    // 初始化数据库的表格管理
    model = new QSqlTableModel(this);
    model->setTable("tb_carsclass");
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
  //  model->setHeaderData(0, Qt::Horizontal, "ID");
    model->setHeaderData(1, Qt::Horizontal, QStringLiteral("挖掘机型号"));
    model->select(); //选取整个表的所有行

    ui->tableView->setModel(model);
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers); //使其不可编辑
    ui->tableView->setColumnHidden(0, true);
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);

}

CarsClassDialog::~CarsClassDialog()
{
    delete ui;
}



// 添加设备型号
void CarsClassDialog::on_pushButton_clicked()
{
    QString  strCarClass = ui->lineEdit_CarClass->text() ;
    if(strCarClass.isEmpty())
        return  ;

    QSqlTableModel *modelQuery = new QSqlTableModel(this);
    modelQuery->setTable("tb_carsclass");

 // auto strSql = QString("name = '%1' and dev_ip = '%2'").arg(strDev).arg(strCOM);
    auto strSql = QString("name = '%1'").arg(strCarClass)  ;
    modelQuery->setFilter(strSql);
    modelQuery->select();
    auto curRows = modelQuery->rowCount();
    if (curRows) {
         QMessageBox::warning(this, QString::fromLocal8Bit("警告"), QString::fromLocal8Bit(
                "重复添加"),
                QMessageBox::Ok);
           return;
     }

    //添加设备型号
    int rowNum = model->rowCount(); //获得表的行数
    model->insertRow(rowNum); //添加一行
    model->setData(model->index(rowNum, 1), strCarClass);
  //  model->setData(model->index(rowNum,0),rowNum);
    bool ret = model->submitAll() ;

}
