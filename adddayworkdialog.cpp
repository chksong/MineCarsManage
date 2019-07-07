#include "adddayworkdialog.h"
#include "ui_adddayworkdialog.h"


#include <QDebug>
#include <QDate>

#include <QDateTime>
#include <QMessageBox>


AddDayWorkDialog::AddDayWorkDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddDayWorkDialog)
{
    ui->setupUi(this);
    setAttribute (Qt::WA_DeleteOnClose);

    model = new QSqlTableModel(this);
    model->setTable("tb_carswork");
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);


    //时间控件初始化当前日期
    ui->dateEdit_add->setDate(QDateTime::currentDateTime().date()) ;

}

AddDayWorkDialog::~AddDayWorkDialog()
{
    delete ui;
}


void AddDayWorkDialog::on_PB_TEST_clicked()
{ 
	//测试时间输出
    //auto ret = ui->dateEdit->date().toString("yyyy-MM-dd  ddd") ;
    //auto ret2 = ui->dateTimeEdit->dateTime().toString("yyyy-MM-dd AP hh:mm:ss ddd") ;
    //auto ret3 = ui->calendarWidget->selectedDate().toString("yyyy-MM-dd ddd") ;


}


void AddDayWorkDialog::on_PB_CANCLE_clicked()
{
    reject() ;
}



void AddDayWorkDialog::on_PB_ADD_clicked()
{
    if(!checkValidCtrl()) {
        return;
    }


    QSqlTableModel *modelQuery = new QSqlTableModel(this);
    modelQuery->setTable("tb_carswork");

    QString strDateadd = ui->dateEdit_add->date().toString("yyyy-MM-dd") ;


   auto strSql = QString("date = '%1' and carid = '%2'").arg(strDateadd).arg(ui->lineEdit_cardid->text());
 // auto strSql = QString("name = '%1'").arg(strCarClass)  ;

    modelQuery->setFilter(strSql);
    modelQuery->select();
    auto curRows = modelQuery->rowCount();
    if (curRows) {
         QMessageBox::warning(this, QString::fromLocal8Bit("警告"), QString::fromLocal8Bit(
                "重复添加"),
                QMessageBox::Ok);
           return;
     }


    int rowNum = model->rowCount(); //获得表的行数
    model->insertRow(rowNum); //添加一行
    model->setData(model->index(rowNum,1), strDateadd);
    model->setData(model->index(rowNum,2), QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss")) ;
    model->setData(model->index(rowNum,3), ui->lineEdit_cardid->text());
    model->setData(model->index(rowNum,4), ui->comboBox_carclass->currentText());


    bool ret = model->submitAll()  ;
    if(!ret) {
        QMessageBox::critical(this, QString::fromLocal8Bit("错误"), QString::fromLocal8Bit(
               "添加失败"),
               QMessageBox::Ok);
          return;
    }


}





bool AddDayWorkDialog::checkValidCtrl()
{

    return  true ;
}


void AddDayWorkDialog::close()
{

}

