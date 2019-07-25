#ifndef TCTABELMODEL_H
#define TCTABELMODEL_H

#include <QObject>
#include <QAbstractTableModel>

class TcTabelModel : public QAbstractTableModel
{
    Q_OBJECT
public:
    explicit TcTabelModel(QObject *parent = 0);
    ~TcTabelModel();
    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    int columnCount(const QModelIndex &) const;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const;
    void print();

signals:

public slots:
private:
    QString getKey(int nRow) const;
private:
    QStringList m_headerList;
    QMap<QString,QStringList> m_data;
};

#endif // TCTABELMODEL_H
