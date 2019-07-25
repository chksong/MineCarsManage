#ifndef TCTABLEVIEW_H
#define TCTABLEVIEW_H

#include <QWidget>
#include <QTableView>
#include <QMenu>
#include <QAction>

class TcTableView : public QTableView
{
    Q_OBJECT
public:
    explicit TcTableView(QWidget *parent = 0);
    ~TcTableView();

    void initHeaderView();
    void initAction();

signals:
public slots:

    virtual void onMenuHorizontalHeaderRequested(QPoint pos);
    virtual void onMenuVerticalHeaderRequested(QPoint pos);

    virtual void onColumnClicked(int nIndex);
    virtual void onRowClicked(int nIndex);

    virtual void onCreateVariable();
    virtual void onDeleteVariable();
    virtual void onModifyVariable();

private:
    QMenu       *m_popMenu;        // 菜单指针
    QAction     *m_actionDel;      // 菜单中删除(动作)action的指针
    QAction     *m_actionMod;      // 菜单中修改(动作)action的指针
    QAction     *m_actionCreate;   // 菜单中新建(动作)action的指针

};

#endif // TCTABLEVIEW_H
