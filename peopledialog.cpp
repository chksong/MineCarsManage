#include "peopledialog.h"
#include "ui_peopledialog.h"



#include <QSqlQuery>
#include <QMessageBox>
#include <QSqlError>
#include <QMessageBox>
#include <QMap>
#include <QSqlRelation>



PeopleDialog::PeopleDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PeopleDialog)
{
    ui->setupUi(this);
    setAttribute (Qt::WA_DeleteOnClose);

    //关联双击
    connect(ui->tableView,&QTableView::doubleClicked, this,&PeopleDialog::doubleClicked)  ;
    connect(ui->tableView,&QTableView::clicked, this,&PeopleDialog::clicked)  ;


    //0  构造员工管理的表格
    model = new QSqlRelationalTableModel(this);
    model->setTable("tb_people");
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    model->setHeaderData(1, Qt::Horizontal, QStringLiteral("姓名"));
    model->setHeaderData(2, Qt::Horizontal, QStringLiteral("车号"));
    model->setRelation(2,QSqlRelation("tb_cars","id","name")) ;
    model->select(); //选取整个表的所有行


    ui->tableView->setModel(model);
 //   ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers); //使其不可编辑
    ui->tableView->setColumnHidden(0, true);
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);


    //1 加载车的型号
    QSqlQuery  query ;
    query.exec("select name,id from tb_cars") ;
    while (query.next()) {
     //   query.value(0)
        mMapCars_ID.insert(query.value(0).toString(),query.value(1).toInt());

        ui->comboBox_CarIDList->addItem(query.value(0).toString()) ;
    }

}

PeopleDialog::~PeopleDialog()
{
    delete ui;
}

// 添加
void PeopleDialog::on_PB_Add_clicked()
{
    //1 检查控件
    if(ui->lineEdit_Name->text().isEmpty()
            || ui->comboBox_CarIDList->currentText().isEmpty())
    {
        QMessageBox::warning(this, "警告",
                             "姓名或者车号为空",
               QMessageBox::Ok);
         return  ;
    }

    //检查是否重复加入
    QSqlTableModel *modelQuery = new QSqlTableModel(this);
    modelQuery->setTable("tb_people");

    auto strSql = QString("name = '%1' and carid = '%2'")
           .arg(ui->lineEdit_Name->text())
           .arg(mMapCars_ID[ui->comboBox_CarIDList->currentText()]);

    modelQuery->setFilter(strSql);
    modelQuery->select();
    auto curRows = modelQuery->rowCount();
    if (curRows) {
         QMessageBox::warning(this, QString::fromLocal8Bit("警告"), QString::fromLocal8Bit(
                "员工和车号重复加入"),
                QMessageBox::Ok);
           return;
     }

    //添加员工姓名和车的绑定
    int rowNum = model->rowCount(); //获得表的行数
    model->insertRow(rowNum); //添加一行
    model->setData(model->index(rowNum, 1), ui->lineEdit_Name->text());
    model->setData(model->index(rowNum,2),  mMapCars_ID[ui->comboBox_CarIDList->currentText()]);
    bool ret = model->submitAll()  ;

}

void PeopleDialog::on_PB_Del_clicked()
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

void PeopleDialog::on_PB_Save_Modify_clicked()
{
    // 删除旧有modleIndex 的控件
    if( ui->tableView->indexWidget(lastModeIndex))   {
        QComboBox *comboBox = (QComboBox*)ui->tableView->indexWidget(lastModeIndex) ;
        model->setData(lastModeIndex, mMapCars_ID[comboBox->currentText()]);
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

void PeopleDialog::on_PB_Cancle_Modify_clicked()
{
    // 删除旧有modleIndex 的控件
    if( ui->tableView->indexWidget(lastModeIndex))   {
        QWidget *comboBox = ui->tableView->indexWidget(lastModeIndex) ;
        ui->tableView->setIndexWidget(lastModeIndex,nullptr) ;
        delete  comboBox ;
    }

    model->revertAll();

}




void  PeopleDialog::doubleClicked(QModelIndex modleIndex)
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

   int carID  = model->data(modleIndex).toInt() ;
    QMap<QString, int>::iterator iter = mMapCars_ID.begin();
    while (iter != mMapCars_ID.end()) {
        comboBox->addItem(iter.key()) ;

        if(carID == iter.value()) {
            comboBox->setCurrentText(iter.key())  ;
        }
        ++iter ;
    }

    lastModeIndex = modleIndex ;
}


void PeopleDialog::clicked(QModelIndex modleIndex)
{
    // 删除旧有modleIndex 的控件
    if(lastModeIndex != modleIndex && ui->tableView->indexWidget(lastModeIndex))   {
        QWidget *comboBox = ui->tableView->indexWidget(lastModeIndex) ;
        ui->tableView->setIndexWidget(lastModeIndex,nullptr) ;
        delete  comboBox ;
    }

}


void PeopleDialog::keyPressEvent(QKeyEvent *event)
{
    switch(event->key())
      {
        case Qt::Key_Escape:
            {
                QWidget *comboBox = ui->tableView->indexWidget(lastModeIndex) ;
                if( nullptr != comboBox)
                {
                    ui->tableView->setIndexWidget(lastModeIndex,nullptr) ;
                    delete  comboBox ;
                }
            }
          break;
       default:
          QWidget::keyPressEvent(event);
      }

}
