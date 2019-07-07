#include "carsclassdialog.h"
#include "ui_carsclassdialog.h"


#include <QSqlTableModel>
#include <QMessageBox>
#include <QAction>
#include <QMenu>

CarsClassDialog::CarsClassDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CarsClassDialog)
{
    ui->setupUi(this);
    setAttribute (Qt::WA_DeleteOnClose);


    // 初始化数据库的表格管理
    model = new QSqlTableModel(this);
    model->setTable("tb_carsclass");
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
  //  model->setHeaderData(0, Qt::Horizontal, "ID");
    model->setHeaderData(1, Qt::Horizontal, QStringLiteral("挖掘机型号"));
    model->select(); //选取整个表的所有行

    ui->tableView->setModel(model);
  //  ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers); //使其不可编辑
    ui->tableView->setColumnHidden(0, true);
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);


   // 添加右键
    ui->tableView->setContextMenuPolicy(Qt::CustomContextMenu);
    connect(ui->tableView, &QTableView::customContextMenuRequested,this,&CarsClassDialog::clicked_rightMenu)  ;
}

CarsClassDialog::~CarsClassDialog()
{
    delete ui;
}



// 添加设备型号
void CarsClassDialog::on_pushButton_clicked()
{
    QString  strCarClass = ui->lineEdit_CarClass->text() ;
    if(strCarClass.isEmpty())
        return  ;

    QSqlTableModel *modelQuery = new QSqlTableModel(this);
    modelQuery->setTable("tb_carsclass");

 // auto strSql = QString("name = '%1' and dev_ip = '%2'").arg(strDev).arg(strCOM);
    auto strSql = QString("name = '%1'").arg(strCarClass)  ;
    modelQuery->setFilter(strSql);
    modelQuery->select();
    auto curRows = modelQuery->rowCount();
    if (curRows) {
         QMessageBox::warning(this, QString::fromLocal8Bit("警告"), QString::fromLocal8Bit(
                "重复添加"),
                QMessageBox::Ok);
           return;
     }

    //添加设备型号
    int rowNum = model->rowCount(); //获得表的行数
    model->insertRow(rowNum); //添加一行
    model->setData(model->index(rowNum, 1), strCarClass);
    bool ret = model->submitAll()  ;
}


void CarsClassDialog::clicked_rightMenu(const QPoint &pos)
{

    QMenu *rightMenu = new QMenu() ;
    QAction* cutAction = new QAction(QStringLiteral("剪切"),this);
    QAction* copyAction = new QAction(QStringLiteral("复制"),this);
    QAction* pasteAction = new QAction(QStringLiteral("粘贴"),this);
    QAction* deleteAction = new QAction(QStringLiteral("删除"),this);

    rightMenu->addAction(cutAction);
    rightMenu->addAction(copyAction);
    rightMenu->addAction(pasteAction);
    rightMenu->addAction(deleteAction);
    rightMenu->exec(QCursor::pos());

}
