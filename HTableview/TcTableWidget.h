#ifndef TCTABLEWIDGET_H
#define TCTABLEWIDGET_H

#include <QWidget>
#include <QTableView>
#include <QMap>

namespace Ui {
class TcTableWidget;
}

class HHeaderModel;
class TcTabelModel;
class TcTableWidget : public QWidget
{
    Q_OBJECT

public:
    explicit TcTableWidget(QWidget *parent = 0);
    ~TcTableWidget();

private slots:
    void on_tabWidget_tabCloseRequested(int index);

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::TcTableWidget *ui;
    int m_nTableCount;
    QMap<QString,TcTabelModel*> m_allDataModel;

};

#endif // TCTABLEWIDGET_H
