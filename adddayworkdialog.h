#ifndef ADDDAYWORKDIALOG_H
#define ADDDAYWORKDIALOG_H

#include <QDialog>

namespace Ui {
class AddDayWorkDialog;
}

class AddDayWorkDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddDayWorkDialog(QWidget *parent = nullptr);
    ~AddDayWorkDialog();

private slots:
    void on_PB_TEST_clicked();

private:
    Ui::AddDayWorkDialog *ui;
};

#endif // ADDDAYWORKDIALOG_H
