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
    model->setData(model->index(rowNum,1), strDateadd);   // 工作日期
    model->setData(model->index(rowNum,2), QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss")) ;  //添加的日期
    model->setData(model->index(rowNum,3), ui->lineEdit_cardid->text());                // 车的ID
    model->setData(model->index(rowNum,4), ui->comboBox_carclass->currentText());       //车的类型

    model->setData(model->index(rowNum,5), ui->comboBox_people->currentText());         //员工信息
    model->setData(model->index(rowNum,6), ui->doubleSpinBox_hoursOfMonth->value());    //月初小时候数


    //日装
    model->setData(model->index(rowNum,7),  ui->comboBox_rz_where->currentText());       //日装工作地点
    model->setData(model->index(rowNum,8),  ui->comboBox_rz_type->currentText());        //日装工作地点

    model->setData(model->index(rowNum,9),  ui->spinBox_yk_carnums->value());           //原矿石车数
    model->setData(model->index(rowNum,10), ui->doubleSpinBox_yk_tons->value());        //原矿石吨数

    model->setData(model->index(rowNum,11), ui->spinBox_xk_carnums->value());           //细矿石车数
    model->setData(model->index(rowNum,12), ui->doubleSpinBox_xk_tons->value());        //细矿石吨数

    model->setData(model->index(rowNum,13), ui->spinBox_xk_carnums->value());           //尾矿石车数
    model->setData(model->index(rowNum,14), ui->doubleSpinBox_xk_tons->value());        //尾矿石吨数

    model->setData(model->index(rowNum,15), ui->spinBox_xk_carnums->value());           //剥岩石车数
    model->setData(model->index(rowNum,16), ui->doubleSpinBox_xk_tons->value());        //剥岩石吨数

    //日工工时
    model->setData(model->index(rowNum,17), ui->comboBox_rz_where->currentText());       //日装工作地点
    model->setData(model->index(rowNum,18), ui->comboBox_rz_type->currentText());        //日装工作地点
    model->setData(model->index(rowNum,19), ui->doubleSpinBox_rg_hours->value());        //日工工时数


    //总计信息
    model->setData(model->index(rowNum,20), ui->doubleSpinBox_hoursofday->value());      //本日工作时长
    model->setData(model->index(rowNum,21), ui->doubleSpinBox_oils->value());            //柴油用量
    model->setData(model->index(rowNum,22), ui->doubleSpinBox_materials->value());       //材料费
    model->setData(model->index(rowNum,23), ui->doubleSpinBox_repair->value());       //修理费
    model->setData(model->index(rowNum,24), ui->textEdit_comment->toPlainText());       //修理费




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

