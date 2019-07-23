#ifndef ADDDAYWORKDIALOG_H
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
    explicit AddDayWorkDialog(QWidget *parent = nullptr);
    ~AddDayWorkDialog();

    bool checkValidCtrl() ;

    virtual void close() ;
private slots:
    void on_PB_TEST_clicked();

    void on_PB_CANCLE_clicked();

    void on_PB_ADD_clicked();

    void on_comboBox_cardid_currentTextChanged(const QString &arg1);

private:
    Ui::AddDayWorkDialog *ui;

    QSqlTableModel  *model{nullptr} ;
    QMap<QString ,int> mMapCars_ID ;
    QMap<QString ,int> mMapPeople_ID ;
};

#endif // ADDDAYWORKDIALOG_H
