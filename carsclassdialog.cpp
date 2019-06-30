#include "carsclassdialog.h"
#include "ui_carsclassdialog.h"

CarsClassDialog::CarsClassDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CarsClassDialog)
{
    ui->setupUi(this);

}

CarsClassDialog::~CarsClassDialog()
{
    delete ui;
}
