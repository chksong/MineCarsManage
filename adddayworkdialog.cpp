#include "adddayworkdialog.h"
#include "ui_adddayworkdialog.h"


#include <QDebug>
#include <QDate>

#include <QDateTime>
#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QStringLiteral>


//重建Map与ID的映射表  员工ID，MAP
void AddDayWorkDialog::reloadNameIDSMapByCarName(const QString &strCar )
{
    int carid = mMapCars_ID[strCar] ;
    mMapPeople_ID.clear() ;
    ui->comboBox_people->clear() ;
    ui->comboBox_people->clearEditText() ;

    QString strSql = QString("select name,id from tb_people where carid='%1'")
            .arg(carid) ;

    QSqlQuery  query ;
    query.exec(strSql) ;
    while (query.next()) {
        mMapPeople_ID.insert(query.value(0).toString(),  query.value(1).toInt());

        ui->comboBox_people->addItem(query.value(0).toString()) ;
    }
}

//加载 车map    员工map
void AddDayWorkDialog::reloadAllMapIDS()
{
    QSqlQuery  query ;
    mMapCars_ID.clear() ;
    query.exec("select name,id from tb_cars") ;
    while (query.next()) {
        mMapCars_ID.insert(query.value(0).toString(),  query.value(1).toInt());
        ui->comboBox_cardid->addItem(query.value(0).toString()) ;
    }

    if(mMapCars_ID.size() >0) {
         reloadNameIDSMapByCarName(mMapCars_ID.firstKey());
    }
}


// 构造函数
AddDayWorkDialog::AddDayWorkDialog(QWidget *parent,qlonglong work_id):
    QDialog(parent), ui(new Ui::AddDayWorkDialog), edit_tb_carwork_id(work_id)
{
    ui->setupUi(this);
    setAttribute (Qt::WA_DeleteOnClose);


    if ( edit_tb_carwork_id < 0) {  // 正常添加模式
        model = new QSqlTableModel(this);
        model->setTable("tb_carswork");
        model->setEditStrategy(QSqlTableModel::OnManualSubmit);
        //时间控件初始化当前日期
        ui->dateEdit_add->setDate(QDateTime::currentDateTime().date()) ;
        //添加车的ID
        reloadAllMapIDS();
    }
    else {
        // 更改界面的提示
        // 对话框 提示可能要修改
        ui->PB_ADD->setText(QStringLiteral("保存修改")) ;
        ui->PB_CANCLE->setText(QStringLiteral("取消修改")) ;
        setWindowTitle("更新工作记录") ;


        //加载
        reloadAllMapIDS();

        EditTableWithID()  ;  // 编辑表格可能 修改
    }
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
    // 检验失败
    if(false == checkValidCtrl()) {
        return;
    }

    // 当前页面是修改的保存
    if(-1 != edit_tb_carwork_id ) {
        SaveEditItemByID() ;
        return  ;
    }


    QSqlTableModel *modelQuery = new QSqlTableModel(this);
    modelQuery->setTable("tb_carswork");
    QString strDateadd = ui->dateEdit_add->date().toString("yyyy-MM-dd") ;

   //同一天，同一车，同一个人只能有一次
   auto strSql = QString("date = '%1' and carid = '%2' and peopleid = '%3'")
           .arg(strDateadd)
           .arg(mMapCars_ID[ui->comboBox_cardid->currentText()])
           .arg(mMapPeople_ID[ui->comboBox_people->currentText()]) ;

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
    model->setData(model->index(rowNum,2),
                   QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss")) ;  //添加的日期
    QString  strCar =  ui->comboBox_cardid->currentText();
    int carID = mMapCars_ID[strCar];
    model->setData(model->index(rowNum,3), carID);     // 车的ID

    QString  strpeople = ui->comboBox_people->currentText();
    int peopleID = mMapPeople_ID[strpeople];
    model->setData(model->index(rowNum,4), peopleID);   //  peopleID

    //日装
    model->setData(model->index(rowNum,5),  ui->comboBox_rz_where->currentText());       //日装工作地点
    model->setData(model->index(rowNum,6),  ui->comboBox_rz_type->currentText());        //日装工作地点

    model->setData(model->index(rowNum,7),  ui->spinBox_yk_carnums->value());           //原矿石车数
    model->setData(model->index(rowNum,8),  ui->doubleSpinBox_yk_tons->value());         //原矿石吨数

    model->setData(model->index(rowNum,9),  ui->spinBox_xk_carnums->value());            //细矿石车数
    model->setData(model->index(rowNum,10), ui->doubleSpinBox_xk_tons->value());        //细矿石吨数

    model->setData(model->index(rowNum,11), ui->spinBox_wk_carnums->value());           //尾矿石车数
    model->setData(model->index(rowNum,12), ui->doubleSpinBox_wk_tons->value());        //尾矿石吨数

    model->setData(model->index(rowNum,13), ui->spinBox_by_carnums->value());           //剥岩石车数
    model->setData(model->index(rowNum,14), ui->doubleSpinBox_by_tons->value());        //剥岩石吨数

    //日工工时
    model->setData(model->index(rowNum,15), ui->comboBox_rg_where->currentText());       //日装工作地点
    model->setData(model->index(rowNum,16), ui->comboBox_rg_type->currentText());        //日装工作地点
    model->setData(model->index(rowNum,17), ui->doubleSpinBox_rg_hours->value());        //日工工时数


    //总计信息
    model->setData(model->index(rowNum,18), ui->doubleSpinBox_hoursofday->value());      //本日工作时长
    model->setData(model->index(rowNum,19), ui->doubleSpinBox_oils->value());            //柴油用量
    model->setData(model->index(rowNum,20), ui->doubleSpinBox_materials->value());       //材料费
    model->setData(model->index(rowNum,21), ui->doubleSpinBox_repair->value());          //修理费
    model->setData(model->index(rowNum,22), ui->textEdit_comment->toPlainText());        //备注


    bool ret = model->submitAll()  ;
    if(!ret) {
        QMessageBox::critical(this, QString::fromLocal8Bit("错误"), QString::fromLocal8Bit(
               "添加失败"),
               QMessageBox::Ok);
          return;
    } else {
        QMessageBox::information(this, QString::fromLocal8Bit("成功"), QString::fromLocal8Bit(
               "添加成功"),
               QMessageBox::Ok);
        return;
    }
}




//检验 输入的车号，以及员工号的ID 不能为空
bool AddDayWorkDialog::checkValidCtrl()
{
    if( ui->comboBox_cardid->currentText().length() == 0
            || ui->comboBox_people->currentText() == 0 )
    {
        QMessageBox::warning(this, QString::fromLocal8Bit("警告"), QString::fromLocal8Bit(
               "车号或者员工为空"),
               QMessageBox::Ok);
        return false   ;
    }
    else {
        return  true ;
    }
}


void AddDayWorkDialog::close()
{

}


void AddDayWorkDialog::on_comboBox_cardid_currentTextChanged(const QString &arg1)
{
    mMapPeople_ID.clear() ;
    ui->comboBox_people->clear();

    reloadNameIDSMapByCarName(arg1) ;
}


//编辑
void AddDayWorkDialog::EditTableWithID()
{
    if(-1 == edit_tb_carwork_id ) {
        return  ;
    }

    QSqlTableModel *modelQuery = new QSqlTableModel(this);
    modelQuery->setTable("tb_carswork") ;
    auto strSql = QString("id = '%1'")
           .arg(edit_tb_carwork_id) ;

    modelQuery->setFilter(strSql);
    modelQuery->select();
    auto curRows = modelQuery->rowCount();
    if (1 != curRows ) {
         QMessageBox::warning(this, QString::fromLocal8Bit("警告"), QString::fromLocal8Bit(
                "不存在该条记录"),
                QMessageBox::Ok);
           return;
    }

    //0
    ui->dateEdit_add->setDate( modelQuery->record(0).value(1).toDate()) ;  //添加的日期  ;

    //1车的ID-->车名
    {
        int cardid = modelQuery->record(0).value(3).toInt()  ;
        QMap<QString, int>::iterator iter_carid = mMapCars_ID.begin();
        while (iter_carid != mMapCars_ID.end()) {
             if(cardid == iter_carid.value())  {
                 QString strCarName = iter_carid.key() ;
                 ui->comboBox_cardid->setCurrentText(strCarName)  ;
                 break ;
             }
             else {
                 ++iter_carid ;
             }
        }
    }

    //2姓名
    {
        int peopleid = modelQuery->record(0).value(4).toInt() ;
        QMap<QString, int>::iterator iter_people = mMapPeople_ID.begin();
        while (iter_people != mMapPeople_ID.end()) {
             if(peopleid == iter_people.value())  {
                 QString strCarName = iter_people.key() ;
                 ui->comboBox_people->setCurrentText(strCarName)  ;
                 break ;
             }
             else {
                 ++iter_people ;
             }
        }
    }

    //3
    ui->comboBox_rz_where->setCurrentText(modelQuery->record(0).value(5).toString() ); //日装工作地点
    ui->comboBox_rz_type->setCurrentText(modelQuery->record(0).value(6).toString() ) ; //日装工作地点
    ui->spinBox_yk_carnums->setValue(modelQuery->record(0).value(7).toInt() )        ;  //原矿石车数
    ui->doubleSpinBox_yk_tons->setValue(modelQuery->record(0).value(8).toDouble() )  ;  //原矿石吨数

    ui->spinBox_xk_carnums->setValue(modelQuery->record(0).value(9).toInt())  ;         //细矿石车数
    ui->doubleSpinBox_xk_tons->setValue(modelQuery->record(0).value(10).toDouble()) ;   //细矿石吨数

    ui->spinBox_wk_carnums->setValue(modelQuery->record(0).value(11).toInt() ) ;        //尾矿石车数
    ui->doubleSpinBox_wk_tons->setValue(modelQuery->record(0).value(12).toDouble());    //尾矿石吨数

    ui->spinBox_by_carnums->setValue(modelQuery->record(0).value(13).toInt() ) ;       //剥岩石车数
    ui->doubleSpinBox_by_tons->setValue(modelQuery->record(0).value(14).toDouble());   //剥岩石吨数

    //日工工时
    ui->comboBox_rg_where->setCurrentText(modelQuery->record(0).value(15).toString() );   //日装工作地点
    ui->comboBox_rg_type->setCurrentText(modelQuery->record(0).value(16).toString() );    //日装工作地点
    ui->doubleSpinBox_rg_hours->setValue(modelQuery->record(0).value(17).toDouble());     //日工工时数

    //总计信息
    ui->doubleSpinBox_hoursofday->setValue(modelQuery->record(0).value(18).toDouble());   //本日工作时长
    ui->doubleSpinBox_oils->setValue(modelQuery->record(0).value(19).toDouble());         //柴油用量
    ui->doubleSpinBox_materials->setValue(modelQuery->record(0).value(20).toDouble());    //材料费
    ui->doubleSpinBox_repair->setValue(modelQuery->record(0).value(21).toDouble());      //修理费
    ui->textEdit_comment->setText(modelQuery->record(0).value(22).toString()) ;   // 备注

}


//保存修改的记录
void AddDayWorkDialog::SaveEditItemByID()
{
    if(-1 == edit_tb_carwork_id ) {
        return  ;
    }

    QSqlTableModel *modelQuery = new QSqlTableModel(this);
    modelQuery->setTable("tb_carswork") ;
    auto strSql = QString("id = '%1'")
           .arg(edit_tb_carwork_id) ;

    modelQuery->setFilter(strSql);
    modelQuery->select();
    auto curRows = modelQuery->rowCount();
    if (1 != curRows ) {
         QMessageBox::warning(this, QString::fromLocal8Bit("警告"), QString::fromLocal8Bit(
                "不存在该条记录"),
                QMessageBox::Ok);
           return;
    }

    QSqlRecord record = modelQuery->record(0);
    record.setValue(2, QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss")) ; //修改时间

    QString  strCar =  ui->comboBox_cardid->currentText();
    int carID = mMapCars_ID[strCar];
    record.setValue(3, carID);     // 车的ID

    QString  strpeople = ui->comboBox_people->currentText();
    int peopleID = mMapPeople_ID[strpeople];
    record.setValue(4, peopleID);   //  peopleID

    //日装
    record.setValue(5,  ui->comboBox_rz_where->currentText());       //日装工作地点
    record.setValue(6,  ui->comboBox_rz_type->currentText());        //日装工作地点

    record.setValue(7,   ui->spinBox_yk_carnums->value());           //原矿石车数
    record.setValue(8,  ui->doubleSpinBox_yk_tons->value());         //原矿石吨数

    record.setValue(9,   ui->spinBox_xk_carnums->value());            //细矿石车数
    record.setValue(10,  ui->doubleSpinBox_xk_tons->value());        //细矿石吨数

    record.setValue(11, ui->spinBox_wk_carnums->value());           //尾矿石车数
    record.setValue(12, ui->doubleSpinBox_wk_tons->value());        //尾矿石吨数

    record.setValue(13, ui->spinBox_by_carnums->value());           //剥岩石车数
    record.setValue(14, ui->doubleSpinBox_by_tons->value());        //剥岩石吨数

    //日工工时
    record.setValue(15, ui->comboBox_rg_where->currentText());       //日装工作地点
    record.setValue(16, ui->comboBox_rg_type->currentText());        //日装工作地点
    record.setValue(17, ui->doubleSpinBox_rg_hours->value());        //日工工时数

    //总计信息
    record.setValue(18, ui->doubleSpinBox_hoursofday->value());      //本日工作时长
    record.setValue(19, ui->doubleSpinBox_oils->value());            //柴油用量
    record.setValue(20, ui->doubleSpinBox_materials->value());       //材料费
    record.setValue(21, ui->doubleSpinBox_repair->value());          //修理费
    record.setValue(22, ui->textEdit_comment->toPlainText());        //备注

    modelQuery->setRecord(0,record);
    bool ret = modelQuery->submitAll()  ;
    if(!ret) {
        QMessageBox::critical(this, QString::fromLocal8Bit("错误"), QString::fromLocal8Bit(
               "修改失败"),
               QMessageBox::Ok);
          return;
    }
    else {
        QMessageBox::information(this, QString::fromLocal8Bit("成功"), QString::fromLocal8Bit(
               "修改成功"),
               QMessageBox::Ok);
          return;
    }
}
