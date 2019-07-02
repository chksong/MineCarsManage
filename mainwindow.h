#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>


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

public slots:
    void carsClassManage(bool) ;
    void addOneDayWork(bool)  ;

private:
    Ui::MainWindow *ui;

private:
    CarsClassDialog *dlgCarsClass  {nullptr} ;
    AddDayWorkDialog*  dlgAddDayWorkDlg  {nullptr} ;

};

#endif // MAINWINDOW_H
