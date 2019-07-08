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
