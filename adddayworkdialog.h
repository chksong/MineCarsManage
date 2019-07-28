﻿#ifndef ADDDAYWORKDIALOG_H
#define ADDDAYWORKDIALOG_H




#include <QDialog>
#include <QSqlTableModel>
#include <QMap>



namespace Ui {
class AddDayWorkDialog;
}

class AddDayWorkDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddDayWorkDialog(QWidget *parent = nullptr, qlonglong work_id = -1);
    ~AddDayWorkDialog();

    bool checkValidCtrl() ;

    virtual void close() ;

    //重建Map与ID的映射表
    void reloadAllMapIDS();

    void reloadNameIDSMapByCarName(const QString &strCar);

    void EditTableWithID()  ;
    void SaveEditItemByID()  ;

private slots:
    void on_PB_TEST_clicked();

    void on_PB_CANCLE_clicked();

    void on_PB_ADD_clicked();

    void on_comboBox_cardid_currentTextChanged(const QString &arg1);

private:
    Ui::AddDayWorkDialog *ui;

    QSqlTableModel  *model{nullptr} ;

    QMap<QString ,int> mMapCars_ID ;     //车ID和Name的映射表
    QMap<QString ,int> mMapPeople_ID ;   //员工ID和Name的映射表

    qlonglong  edit_tb_carwork_id = {-1};  // 标准ID ；
};

#endif // ADDDAYWORKDIALOG_H
