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


    QString strSql = QString("year = '%1' and month = '%2'")
           .arg(ui->dateEdit_JieSuanMonth->date().year())
           .arg(ui->dateEdit_JieSuanMonth->date().month());

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
    strThisMonthDate = QString("%1-%2-25").arg(year).arg(month) ;

    if (1 == month) {   //一月份，获得上一个年的12月份
        strLastMonthDate = QString("%1-%2-25").arg(year-1).arg(12) ;
    }
    else {
        strLastMonthDate = QString("%1-%2-25").arg(year).arg(month-1) ;
    }

    // 统计出结果
    QString strQuery = QString("SELECT carid, SUM(hoursofdays)  \
        FROM tb_carswork                \
        WHERE date > '%1' and date <= '%2' GROUP BY carid")
        .arg(strLastMonthDate).arg(strThisMonthDate) ;

    QSqlQuery  query ;
    query.exec(strQuery) ;
    while (query.next()) {





    }

  //  QString strInsert = QString("INSERT INTO tb_JieSuan (yearMonth,carid,hoursofMonth) VALUES (1,13,3)  \
  //                  ON DUPLICATE KEY UPDATE hoursofMonth=hoursofMonth+1") ;

    QString strInsert = QString("REPLACE INTO tb_JieSuan (yearMonth,carid,hoursofMonth) VALUES (1,13,3)");
    query.exec(strInsert) ;
}
