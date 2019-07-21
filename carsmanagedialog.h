#ifndef CARSMANAGEDIALOG_H
#define CARSMANAGEDIALOG_H

#include <QDialog>
#include <QSqlTableModel>
#include <QSqlRelationalTableModel>
#include <QMap>


namespace Ui {
class CarsManageDialog;
}

class CarsManageDialog : public QDialog
{
    Q_OBJECT

public:
    explicit CarsManageDialog(QWidget *parent = nullptr);
    ~CarsManageDialog();

private slots:
    void on_PB_ADD_clicked();

    void on_PB_DEL_clicked();

    void on_PB_SAVE_MODIY_clicked();

    void on_PB_CANCEL_MODIFY_clicked();

private:
    Ui::CarsManageDialog *ui;

 //   QSqlTableModel  *model{nullptr} ;
    QSqlRelationalTableModel  *model{nullptr} ;
    QMap<QString ,int> mMapCarCalss_ID ;
};

#endif // CARSMANAGEDIALOG_H
