#include "peopledialog.h"
#include "ui_peopledialog.h"

PeopleDialog::PeopleDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PeopleDialog)
{
    ui->setupUi(this);
}

PeopleDialog::~PeopleDialog()
{
    delete ui;
}
