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
    void clicked_rightMenu(const QPoint &pos);  //tableview 右键信号槽函数

    void on_pushButton_add_clicked();

    void on_pushButton_del_clicked();

    void on_pushButton_save_modify_clicked();

    void on_pushButton_cancle_modify_clicked();

private:
    Ui::CarsClassDialog *ui;

    QSqlTableModel  *model;
};

#endif // CARSCLASSDIALOG_H
