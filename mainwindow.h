#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSqlTableModel>
#include <QTableView>
#include <QTableWidget>
#include <QMap>
#include <QMenu>

#include "carsclassdialog.h"
#include "adddayworkdialog.h"

#include "HTableview/HHeaderModel.h"
#include "HTableview/HHeaderView.h"


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
    void initHeadView(QTableWidget *pTableView)  ;
    void reloadTableData();
    void getCarNameTypeByID(quint32 carID ,QString& carType ,QString& carName)  ;
public slots:
    void carsClassManage(bool) ;
    void addOneDayWork(bool)  ;
    void carsManage(bool)  ;
    void peopleManage(bool)  ;
    void MonthJieSuan(bool)  ;

    void on_menu_edit_clicked();
    void on_menu_del_clicked();
    void clicked_rightMenu(const QPoint &pos);  //tableview 右键信号槽函数

    void dohelp() ;


protected:
    void resizeEvent(QResizeEvent *event);


private slots:
    void on_PB_refresh_clicked();


    void on_dateEdit_search_customContextMenuRequested(const QPoint &pos);

    void on_pushButton_3_clicked();

private:
    Ui::MainWindow *ui;

private:
    CarsClassDialog *dlgCarsClass  {nullptr} ;
    AddDayWorkDialog*  dlgAddDayWorkDlg  {nullptr} ;

    QSqlTableModel  *model{nullptr};
    QMap<int,qlonglong>   mMapRowWithRID ; // 行号 对应数据 行ID

    QMenu * tableViewRightMenu{nullptr}  ;
    HHeaderModel *m_pModel { nullptr} ;
    HHeaderView  *m_pHeadView {nullptr}  ;
};

#endif // MAINWINDOW_H
