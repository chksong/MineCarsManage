#include "carsmanagedialog.h"
#include "ui_carsmanagedialog.h"

CarsManageDialog::CarsManageDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CarsManageDialog)
{
    ui->setupUi(this);
    setAttribute (Qt::WA_DeleteOnClose);
}

CarsManageDialog::~CarsManageDialog()
{
    delete ui;
}

void CarsManageDialog::on_PB_ADD_clicked()
{

}

void CarsManageDialog::on_PB_DEL_clicked()
{

}

void CarsManageDialog::on_PB_SAVE_MODIY_clicked()
{

}

void CarsManageDialog::on_PB_CANCEL_MODIFY_clicked()
{

}
