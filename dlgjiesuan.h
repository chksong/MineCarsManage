#ifndef DLGJIESUAN_H
#define DLGJIESUAN_H

#include <QDialog>
#include <QSqlRelationalTableModel>

namespace Ui {
class DlgJieSuan;
}

class DlgJieSuan : public QDialog
{
    Q_OBJECT

public:
    explicit DlgJieSuan(QWidget *parent = nullptr);
    ~DlgJieSuan();

    bool jieSuanMonth(int year, int month, int day) ;

    void reloadByMonth();
    
private slots:
    void on_PB_jieSuan_clicked();

private:
    Ui::DlgJieSuan *ui;
    QSqlRelationalTableModel  *model{nullptr} ;
};

#endif // DLGJIESUAN_H
