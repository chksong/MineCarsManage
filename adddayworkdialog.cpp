#include "adddayworkdialog.h"
#include "ui_adddayworkdialog.h"


#include <QDebug>



AddDayWorkDialog::AddDayWorkDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddDayWorkDialog)
{
    ui->setupUi(this);
}

AddDayWorkDialog::~AddDayWorkDialog()
{
    delete ui;
}


void AddDayWorkDialog::on_PB_TEST_clicked()
{ 
	//测试时间输出
    auto ret = ui->dateEdit->date().toString("yyyy-MM-dd  ddd") ;
    //auto ret2 = ui->dateTimeEdit->dateTime().toString("yyyy-MM-dd AP hh:mm:ss ddd") ;
    //auto ret3 = ui->calendarWidget->selectedDate().toString("yyyy-MM-dd ddd") ;
}
