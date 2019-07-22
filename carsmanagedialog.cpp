#include "carsmanagedialog.h"
#include "ui_carsmanagedialog.h"


#include <QSqlQuery>
#include <QMessageBox>
#include <QSqlError>
#include <QMessageBox>
#include <QMap>
#include <QSqlRelation>

//   sql 简单用法
//   https://www.cnblogs.com/coolcpp/p/qt-sql.html

//  外键的使用
// https://www.kancloud.cn/kancloud/qt-study-road-2/99497


CarsManageDialog::CarsManageDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CarsManageDialog)
{
    ui->setupUi(this);
    setAttribute (Qt::WA_DeleteOnClose);

    //关联双击
    connect(ui->tableView,&QTableView::doubleClicked, this,&CarsManageDialog::doubleClicked)  ;
    connect(ui->tableView,&QTableView::clicked, this,&CarsManageDialog::clicked)  ;

    //0  构造汽车管理的表格
    model = new QSqlRelationalTableModel(this);
    model->setTable("tb_cars");
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
  //  model->setHeaderData(0, Qt::Horizontal, "ID");
    model->setHeaderData(1, Qt::Horizontal, QStringLiteral("车号"));
    model->setHeaderData(2, Qt::Horizontal, QStringLiteral("品牌型号"));
    model->setRelation(2,QSqlRelation("tb_carsclass","id","name")) ;
    model->select(); //选取整个表的所有行


    ui->tableView->setModel(model);
 //   ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers); //使其不可编辑
    ui->tableView->setColumnHidden(0, true);
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);


   // ui->tableView->resizeColumnsToContents();


    //1 加载车的型号
    QSqlQuery  query ;
    query.exec("select name,id from tb_carsclass") ;
    while (query.next()) {
     //   query.value(0)
        mMapCarCalss_ID.insert(query.value(0).toString(),query.value(1).toInt());

        ui->comboBox_CarClassList->addItem(query.value(0).toString()) ;
    }
}

CarsManageDialog::~CarsManageDialog()
{
    delete ui;
}

void CarsManageDialog::on_PB_ADD_clicked()
{

    if(ui->lineEdit_CarID->text().isEmpty()
            || ui->comboBox_CarClassList->currentText().isEmpty())
    {
        QMessageBox::warning(this, QString::fromLocal8Bit("警告"),
                             QString::fromLocal8Bit("车号或者品牌类型为空"),
               QMessageBox::Ok);
         return  ;
    }


    QSqlTableModel *modelQuery = new QSqlTableModel(this);
    modelQuery->setTable("tb_cars");

    auto strSql = QString("name = '%1' and carsclassid = '%2'")
           .arg(ui->lineEdit_CarID->text())
           .arg(mMapCarCalss_ID[ui->comboBox_CarClassList->currentText()]);

    modelQuery->setFilter(strSql);
    modelQuery->select();
    auto curRows = modelQuery->rowCount();
    if (curRows) {
         QMessageBox::warning(this, QString::fromLocal8Bit("警告"), QString::fromLocal8Bit(
                "车辆重复添加"),
                QMessageBox::Ok);
           return;
     }

    //添加设备
    int rowNum = model->rowCount(); //获得表的行数
    model->insertRow(rowNum); //添加一行
    model->setData(model->index(rowNum, 1), ui->lineEdit_CarID->text());
    model->setData(model->index(rowNum,2),  mMapCarCalss_ID[ui->comboBox_CarClassList->currentText()]);
    bool ret = model->submitAll()  ;

}

void CarsManageDialog::on_PB_DEL_clicked()
{
    //获取选中的行
     int curRow = ui->tableView->currentIndex().row();


     int ok = QMessageBox::warning(this, QString::fromLocal8Bit("删除当前行!"), QString::fromLocal8Bit("你确定"
             "删除当前行吗？"),
             QMessageBox::Yes, QMessageBox::No);
         if (ok == QMessageBox::No)
         {
             model->revertAll(); //如果不删除，则撤销
             return;
         }
         else  {
             //删除该行
             model->removeRow(curRow);
             model->submitAll(); //否则提交，在数据库中删除该行
         }
}

void CarsManageDialog::on_PB_SAVE_MODIY_clicked()
{

    // 删除旧有modleIndex 的控件
    if( ui->tableView->indexWidget(lastModeIndex))   {
        QComboBox *comboBox = (QComboBox*)ui->tableView->indexWidget(lastModeIndex) ;
        model->setData(lastModeIndex, mMapCarCalss_ID[comboBox->currentText()]);
        ui->tableView->setIndexWidget(lastModeIndex,nullptr) ;
        delete  comboBox ;
    }


    model->database().transaction(); //开始事务操作
    if (model->submitAll()) {
        model->database().commit(); //提交
    }
    else {
        model->database().rollback(); //回滚
        QMessageBox::warning(this, tr("保存修改"),
                tr("数据库错误: %1")
                .arg(model->lastError().text()));
     }

}

void CarsManageDialog::on_PB_CANCEL_MODIFY_clicked()
{
    // 删除旧有modleIndex 的控件
    if( ui->tableView->indexWidget(lastModeIndex))   {
        QWidget *comboBox = ui->tableView->indexWidget(lastModeIndex) ;
        ui->tableView->setIndexWidget(lastModeIndex,nullptr) ;
        delete  comboBox ;
    }

    model->revertAll();
}


void  CarsManageDialog::doubleClicked(QModelIndex modleIndex)
{
    // 删除旧有modleIndex 的控件
    if(lastModeIndex != modleIndex && ui->tableView->indexWidget(lastModeIndex))   {
        QWidget *comboBox = ui->tableView->indexWidget(lastModeIndex) ;
        ui->tableView->setIndexWidget(lastModeIndex,nullptr) ;
        delete  comboBox ;
    }

    if(2 != modleIndex.column())
        return ;

    //添加新的控件
    QComboBox *comboBox  = new QComboBox(this) ;
    ui->tableView->setIndexWidget(modleIndex,comboBox) ;

   int carclassID  = model->data(modleIndex).toInt() ;
    QMap<QString, int>::iterator iter = mMapCarCalss_ID.begin();
    while (iter != mMapCarCalss_ID.end()) {
        comboBox->addItem(iter.key()) ;

        if(carclassID == iter.value()) {
            comboBox->setCurrentText(iter.key())  ;
        }
        ++iter ;
    }

    lastModeIndex = modleIndex ;
}


void CarsManageDialog::clicked(QModelIndex modleIndex)
{
    // 删除旧有modleIndex 的控件
    if(lastModeIndex != modleIndex && ui->tableView->indexWidget(lastModeIndex))   {
        QWidget *comboBox = ui->tableView->indexWidget(lastModeIndex) ;
        ui->tableView->setIndexWidget(lastModeIndex,nullptr) ;
        delete  comboBox ;
    }

}
