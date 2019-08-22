#include "dlgjiesuan.h"
#include "ui_dlgjiesuan.h"
#include <QDebug>

DlgJieSuan::DlgJieSuan(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DlgJieSuan)
{
    ui->setupUi(this);

    ui->dateEdit_JieSuanMonth->setDate(QDate::currentDate())  ;
    ui->dateEdit_JieSuanMonth->setCalendarPopup(true);

}

DlgJieSuan::~DlgJieSuan()
{
    delete ui;
}

void DlgJieSuan::on_PB_jieSuan_clicked()
{
    auto date =  ui->dateEdit_JieSuanMonth->date().toString("yyyy-MM-25") ;

    qDebug() << date  ;

    return ;
}
