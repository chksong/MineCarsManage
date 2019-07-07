#ifndef ADDDAYWORKDIALOG_H
#define ADDDAYWORKDIALOG_H




#include <QDialog>
#include <QSqlTableModel>



namespace Ui {
class AddDayWorkDialog;
}

class AddDayWorkDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddDayWorkDialog(QWidget *parent = nullptr);
    ~AddDayWorkDialog();

    bool checkValidCtrl() ;

    virtual void close() ;
private slots:
    void on_PB_TEST_clicked();

    void on_PB_CANCLE_clicked();

    void on_PB_ADD_clicked();

private:
    Ui::AddDayWorkDialog *ui;

    QSqlTableModel  *model{nullptr} ;
};

#endif // ADDDAYWORKDIALOG_H
