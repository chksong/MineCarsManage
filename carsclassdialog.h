#ifndef CARSCLASSDIALOG_H
#define CARSCLASSDIALOG_H

#include <QDialog>

namespace Ui {
class CarsClassDialog;
}

class CarsClassDialog : public QDialog
{
    Q_OBJECT

public:
    explicit CarsClassDialog(QWidget *parent = nullptr);
    ~CarsClassDialog();

private:
    Ui::CarsClassDialog *ui;
};

#endif // CARSCLASSDIALOG_H
