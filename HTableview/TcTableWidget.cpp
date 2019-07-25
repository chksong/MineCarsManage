#include "TcTableWidget.h"
#include "ui_TcTableWidget.h"
#include "TcTableView.h"
#include "TcTabelModel.h"
#include <QDebug>
#include <QTableWidget>

TcTableWidget::TcTableWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TcTableWidget),m_nTableCount(0)
{
    ui->setupUi(this);
    resize(1024,550);
    ui->tabWidget->clear();
}

TcTableWidget::~TcTableWidget()
{
    delete ui;
}

//! 关闭一个tab
void TcTableWidget::on_tabWidget_tabCloseRequested(int index)
{
    QWidget *pWidget = ui->tabWidget->widget(index);
    TcTableView *pTable = dynamic_cast<TcTableView*>(pWidget);
    if(!pTable)
    {
        qDebug()<<"[test]"<<"table not exists";
        return;
    }
    delete pTable;
    pTable = NULL;
    m_nTableCount--;

    qDebug()<<"[test]"<<"table delete complete";
}
//! 创建表格
void TcTableWidget::on_pushButton_clicked()
{
    TcTableView *pTable = new TcTableView();
    TcTabelModel *pModel = new TcTabelModel();
    //! 为表格内部(不是表头)设置数据的model
    pTable->setModel(pModel);
    pTable->initHeaderView();
    pTable->initAction();

    m_allDataModel.insert("testone"+QString::number(m_nTableCount),pModel);

    ui->tabWidget->addTab(pTable,"新建"+QString::number(m_nTableCount));
    m_nTableCount++;
    //qDebug()<<"[test]"<<"start a new table";
}
//! 打印model
void TcTableWidget::on_pushButton_2_clicked()
{
    qDebug()<<"[test]"<<m_allDataModel.count();
    if(m_allDataModel.isEmpty())
    {
        qDebug()<<"[test]"<<"all data model is empty";
        return;
    }
    QMap<QString,TcTabelModel*>::Iterator it = m_allDataModel.begin();
    while(it != m_allDataModel.end())
    {
        (*it)->print();
        qDebug()<<"[test]"<<it.key();
        it++;
    }
}
