#ifndef PEOPLEDIALOG_H
#define PEOPLEDIALOG_H

#include <QDialog>
#include <QSqlTableModel>
#include <QSqlRelationalTableModel>
#include <QMap>
#include <QModelIndex>


namespace Ui {
class PeopleDialog;
}

class PeopleDialog : public QDialog
{
    Q_OBJECT

public:
    explicit PeopleDialog(QWidget *parent = nullptr);
    ~PeopleDialog();

private slots:
    void on_PB_Add_clicked();

    void on_PB_Del_clicked();

    void on_PB_Save_Modify_clicked();

    void on_PB_Cancle_Modify_clicked();

    void clicked(QModelIndex modleIndex) ;
    void doubleClicked(QModelIndex modleIndex) ;

private:
    Ui::PeopleDialog *ui;

    QSqlRelationalTableModel  *model{nullptr} ;
    QMap<QString ,int> mMapCars_ID ;

    QModelIndex  lastModeIndex ; //上次点击的
};

#endif // PEOPLEDIALOG_H
