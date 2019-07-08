#ifndef PEOPLEDIALOG_H
#define PEOPLEDIALOG_H

#include <QDialog>

namespace Ui {
class PeopleDialog;
}

class PeopleDialog : public QDialog
{
    Q_OBJECT

public:
    explicit PeopleDialog(QWidget *parent = nullptr);
    ~PeopleDialog();

private:
    Ui::PeopleDialog *ui;
};

#endif // PEOPLEDIALOG_H
