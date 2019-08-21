#ifndef DLGJIESUAN_H
#define DLGJIESUAN_H

#include <QDialog>

namespace Ui {
class DlgJieSuan;
}

class DlgJieSuan : public QDialog
{
    Q_OBJECT

public:
    explicit DlgJieSuan(QWidget *parent = nullptr);
    ~DlgJieSuan();

private:
    Ui::DlgJieSuan *ui;
};

#endif // DLGJIESUAN_H
