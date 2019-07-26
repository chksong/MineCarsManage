#include "dialoghelp.h"
#include "ui_dialoghelp.h"

#include "HTableview/HHeaderModel.h"
#include "HTableview/HHeaderView.h"
#include "HTableview/TcTabelModel.h"


DialogHelp::DialogHelp(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogHelp)
{
    ui->setupUi(this);

  //  QTableView *pTable = new QTableView() ;

    HHeaderView *pHeadView = new HHeaderView(Qt::Horizontal);
    HHeaderModel *pHeadModel = new HHeaderModel();
    pHeadView->initHeaderView(pHeadModel);
    pHeadView->setModel(pHeadModel);
    ui->tableView->setHorizontalHeader(pHeadView);

}

DialogHelp::~DialogHelp()
{
    delete ui;
}
