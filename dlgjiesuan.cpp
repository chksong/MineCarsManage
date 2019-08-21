#include "dlgjiesuan.h"
#include "ui_dlgjiesuan.h"

DlgJieSuan::DlgJieSuan(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DlgJieSuan)
{
    ui->setupUi(this);
}

DlgJieSuan::~DlgJieSuan()
{
    delete ui;
}
