#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSqlTableModel>



#include "carsclassdialog.h"
#include "adddayworkdialog.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void initTable() ;

public slots:
    void carsClassManage(bool) ;
    void addOneDayWork(bool)  ;
    void carsManage(bool)  ;
    void peopleManage(bool)  ;




private slots:
    void on_PB_refresh_clicked();

private:
    Ui::MainWindow *ui;

private:
    CarsClassDialog *dlgCarsClass  {nullptr} ;
    AddDayWorkDialog*  dlgAddDayWorkDlg  {nullptr} ;

    QSqlTableModel  *model{nullptr};

};

#endif // MAINWINDOW_H
