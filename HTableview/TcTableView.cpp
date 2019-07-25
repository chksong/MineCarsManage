#include "TcTableView.h"
#include <QDebug>
#include "HHeaderView.h"
#include "HHeaderModel.h"
#include <QMessageBox>

TcTableView::TcTableView(QWidget *parent) : QTableView(parent)
{
}

TcTableView::~TcTableView()
{
    QAbstractItemModel *pModel = model();
    delete pModel;
    pModel = NULL;
}

void TcTableView::initHeaderView()
{
   //! 初始化表格，这个表格我只自定义横向表头，纵向不管
   HHeaderView *pHeadView = new HHeaderView(Qt::Horizontal);
   HHeaderModel *pHeadModel = new HHeaderModel();

   pHeadView->initHeaderView(pHeadModel);
   pHeadView->setModel(pHeadModel);
   setHorizontalHeader(pHeadView);
}
//! 下面是添加表头的右键行为，及其响应方法
void TcTableView::initAction()
{
    horizontalHeader()->setContextMenuPolicy(Qt::CustomContextMenu);
    verticalHeader()->setContextMenuPolicy(Qt::CustomContextMenu);

    m_popMenu = new QMenu(this);
    m_popMenu->setStyleSheet("QMenu{background-color:rgb(255,255,255);color:rgb(0, 0, 0);font:10pt ""宋体"";}"
                             "QMenu::item:selected{background-color:#CCDAE7;}");

    m_actionDel = new QAction(tr("删除"),this);
    m_actionMod = new QAction(tr("修改"),this);
    m_actionCreate = new QAction(tr("新建"),this);


    connect(m_actionDel,SIGNAL(triggered()),this,SLOT(onDeleteVariable()));
    connect(m_actionMod,SIGNAL(triggered()),this,SLOT(onModifyVariable()));
    connect(m_actionCreate,SIGNAL(triggered()),this,SLOT(onCreateVariable()));

    //! 选中一列
    connect(horizontalHeader(),SIGNAL(sectionClicked(int)),this,SLOT(onColumnClicked(int)));

    //! 选中一行
    connect(verticalHeader(),SIGNAL(sectionClicked(int)),this,SLOT(onRowClicked(int)));
    connect(horizontalHeader(),SIGNAL(customContextMenuRequested(QPoint)),this, SLOT(onMenuHorizontalHeaderRequested(QPoint)));
    connect(verticalHeader(),SIGNAL(customContextMenuRequested(QPoint)),this, SLOT(onMenuVerticalHeaderRequested(QPoint)));

}

void TcTableView::onMenuHorizontalHeaderRequested(QPoint pos)
{
    Q_UNUSED(pos)
    qDebug()<<"[test]"<<"横向表头右键";
    m_popMenu->clear();
    m_popMenu->addAction(m_actionCreate);
    m_popMenu->addAction(m_actionMod);
    m_popMenu->addAction(m_actionDel);
    m_popMenu->exec(QCursor::pos());
}

void TcTableView::onMenuVerticalHeaderRequested(QPoint pos)
{
    Q_UNUSED(pos)
    qDebug()<<"[test]"<<"纵向表头右键";
    m_popMenu->clear();
    m_popMenu->addAction(m_actionCreate);
    m_popMenu->addAction(m_actionMod);
    m_popMenu->addAction(m_actionDel);
    m_popMenu->exec(QCursor::pos());
}

void TcTableView::onColumnClicked(int nIndex)
{
    setSelectionBehavior(QAbstractItemView::SelectColumns);
    QMessageBox msgBox;
    msgBox.setText("Column Clicked.");
    msgBox.setInformativeText(QString::number(nIndex));
    msgBox.setStandardButtons(QMessageBox::Ok|QMessageBox::Cancel);
    msgBox.setDefaultButton(QMessageBox::Ok);
    int ret = msgBox.exec();
}

void TcTableView::onRowClicked(int nIndex)
{
    setSelectionBehavior(QAbstractItemView::SelectRows);
    QMessageBox msgBox;
    msgBox.setText("Row Clicked.");
    msgBox.setInformativeText(QString::number(nIndex));
    msgBox.setStandardButtons(QMessageBox::Ok|QMessageBox::Cancel);
    msgBox.setDefaultButton(QMessageBox::Ok);
    int ret = msgBox.exec();
}
//! 支持重载
void TcTableView::onCreateVariable()
{
    QMessageBox msgBox;
    msgBox.setText("Create.");
    msgBox.setInformativeText("creater?");
    msgBox.setStandardButtons(QMessageBox::Ok|QMessageBox::Cancel);
    msgBox.setDefaultButton(QMessageBox::Ok);
    int ret = msgBox.exec();
}

void TcTableView::onDeleteVariable()
{
    QMessageBox msgBox;
    msgBox.setText("Delete.");
    msgBox.setInformativeText("delete?");
    msgBox.setStandardButtons(QMessageBox::Ok|QMessageBox::Cancel);
    msgBox.setDefaultButton(QMessageBox::Ok);
    int ret = msgBox.exec();
}

void TcTableView::onModifyVariable()
{
    QMessageBox msgBox;
    msgBox.setText("modify.");
    msgBox.setInformativeText("modify?");
    msgBox.setStandardButtons(QMessageBox::Ok|QMessageBox::Cancel);
    msgBox.setDefaultButton(QMessageBox::Ok);
    int ret = msgBox.exec();
}








