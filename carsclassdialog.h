#ifndef CARSCLASSDIALOG_H
#define CARSCLASSDIALOG_H

#include <QDialog>


#include <QSqlTableModel>


namespace Ui {
class CarsClassDialog;
}

class CarsClassDialog : public QDialog
{
    Q_OBJECT

public:
    explicit CarsClassDialog(QWidget *parent = nullptr);
    ~CarsClassDialog();

private slots:
    void on_pushButton_clicked();

private:
    Ui::CarsClassDialog *ui;

    QSqlTableModel  *model;
};

#endif // CARSCLASSDIALOG_H
