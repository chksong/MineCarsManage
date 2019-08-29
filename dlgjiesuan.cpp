#include "dlgjiesuan.h"
#include "ui_dlgjiesuan.h"
#include <QDebug>

#include <QSqlRelationalTableModel>
#include <QSqlQuery>

DlgJieSuan::DlgJieSuan(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DlgJieSuan)
{
    ui->setupUi(this);

    ui->dateEdit_JieSuanMonth->setDate(QDate::currentDate())  ;
    ui->dateEdit_JieSuanMonth->setCalendarPopup(true);

    //0  构造汽车管理的表格
    model = new QSqlRelationalTableModel(this);
    model->setTable("tb_JieSuan");
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
  //  model->setHeaderData(0, Qt::Horizontal, "ID");
    model->setHeaderData(1, Qt::Horizontal, QStringLiteral("车号"));
    model->setRelation(1,QSqlRelation("tb_cars","id","name")) ;

    model->setHeaderData(2, Qt::Horizontal, QStringLiteral("年"));
    model->setHeaderData(3, Qt::Horizontal, QStringLiteral("月"));
    model->setHeaderData(4, Qt::Horizontal, QStringLiteral("本月工时数"));
    model->setHeaderData(4, Qt::Horizontal, QStringLiteral("月初工时数"));


    QString strMonthYear = QString("%1-%2")
            .arg(ui->dateEdit_JieSuanMonth->date().year())
            .arg(ui->dateEdit_JieSuanMonth->date().month());

    QString strSql = QString("yearMonth = '%1'").arg(strMonthYear) ;

    model->setFilter(strSql);

    ui->tableView->setModel(model);
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers); //使其不可编辑
    ui->tableView->setColumnHidden(0, true);
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);

    model->select(); //选取整个表的所有行
}

DlgJieSuan::~DlgJieSuan()
{
    delete ui;
}

void DlgJieSuan::on_PB_jieSuan_clicked()
{
    auto strdate =  ui->dateEdit_JieSuanMonth->date().toString("yyyy-MM-25") ;

 //   qDebug() << strdate  ;
    auto  date = ui->dateEdit_JieSuanMonth->date() ;

    jieSuanMonth(date.year() ,date.month())  ;

}



bool DlgJieSuan::jieSuanMonth(int year, int month)
{
    QString strLastMonthDate, strThisMonthDate ;
    QString strLastMontYear ,strThisMonthYear ;

    strThisMonthDate = QString("%1-%2-25").arg(year).arg(month) ;
    strThisMonthYear = QString("%1-%2").arg(year).arg(month)  ;
    if (1 == month) {   //一月份，获得上一个年的12月份
        strLastMonthDate = QString("%1-%2-25").arg(year-1).arg(12) ;
        strLastMontYear = QString("%1-%2").arg(year-1).arg(12) ;
    }
    else {
        strLastMonthDate = QString("%1-%2-25").arg(year).arg(month-1) ;
        strLastMontYear = QString("%1-%2").arg(year).arg(month-1)  ;
    }


    // 统计出结果
    QString strQueryTJ = QString("SELECT carid, SUM(hoursofdays)  \
        FROM tb_carswork                \
        WHERE date > '%1' and date <= '%2' GROUP BY carid")
        .arg(strLastMonthDate).arg(strThisMonthDate) ;

    QSqlQuery  queryTJ ;
    queryTJ.exec(strQueryTJ) ;
    while (queryTJ.next()) {
        //上个月 hoursofBOM + 本月hoursofMonth = 本月hoursofBOM

        //上个月
        double lastMonthHoursofBOM = 0 ;
        QString strlastMonthYear =  QString("SELECT hoursofBOM FROM tb_JieSuan WHERE carid='%1' and yearMonth='%2'")
        .arg(queryTJ.value(0).toUInt()) //carid
        .arg(strLastMontYear);
        QSqlQuery  lastYMQuery  ;
        lastYMQuery.exec(strlastMonthYear)  ;
        if(lastYMQuery.next()) {
            lastMonthHoursofBOM = queryTJ.value(0).toDouble() ;
        }


        //2 检查是否存在
        QString strInsertUdate ;
        QString queryTJCheck =  QString("SELECT hoursofBOM FROM tb_JieSuan WHERE carid='%1' and yearMonth='%2'")
                .arg(queryTJ.value(0).toUInt()) //carid
                .arg(strThisMonthYear);
        QSqlQuery  tjCheck;
        tjCheck.exec(queryTJCheck)  ;
        if(tjCheck.next()) {   //存在
            strInsertUdate = QString("UPDATE tb_JieSuan hoursofMonth=%1 ,hoursofBOM=%2 \
                    WHERE carid='%3' and yearMonth='%4'")
                            .arg(queryTJ.value(1).toDouble())
                            .arg(queryTJ.value(1).toDouble()+ lastMonthHoursofBOM)
                            .arg(queryTJ.value(0).toUInt())
                            .arg(strThisMonthYear);
        }
        else {   //不存在
            strInsertUdate = QString("INSERT INTO tb_JieSuan (yearMonth,carid,hoursofMonth,hoursofBOM) VALUES ('%1',%2,%3,%4)")
                            .arg(strThisMonthYear)
                            .arg(queryTJ.value(0).toUInt())
                            .arg(queryTJ.value(1).toDouble())
                            .arg(queryTJ.value(1).toDouble()+ lastMonthHoursofBOM);
        }
        QSqlQuery  queryInsertUpdate ;
        auto bInsert = queryInsertUpdate.exec(strInsertUdate) ;
        qDebug() << bInsert << "**" << strInsertUdate ;
    }

    return true ;

    //"REPLACE INTO tb_JieSuan (yearMonth,carid,hoursofMonth) VALUES ('%1',%2,%3)
}
