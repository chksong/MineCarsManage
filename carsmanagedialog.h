#ifndef CARSMANAGEDIALOG_H
#define CARSMANAGEDIALOG_H

#include <QDialog>

namespace Ui {
class CarsManageDialog;
}

class CarsManageDialog : public QDialog
{
    Q_OBJECT

public:
    explicit CarsManageDialog(QWidget *parent = nullptr);
    ~CarsManageDialog();

private:
    Ui::CarsManageDialog *ui;
};

#endif // CARSMANAGEDIALOG_H
