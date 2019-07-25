#include "TcTabelModel.h"
#include <QDebug>

TcTabelModel::TcTabelModel(QObject *parent) : QAbstractTableModel(parent)
{
    m_headerList<<"hahha"<<"bibibi"<<"cicic"<<"dididi"<<"eieiei"<<"fififi"  <<"hahha"<<"bibibi"<<"cicic"<<"dididi"<<"eieiei"<<"fififi" << "cicic"<<"dididi"<<"eieiei"<<"fififi";

    QStringList rowListOne,rowListTwo;
    rowListOne << "123" << "123" << "123" << "234" << "345" << "456" << "ddddddd" << "aaaa" << "bbb" << "eee"  << "fff" << "ggg" << "hhhhh" << "iiiiii" <<   "ggg" << "kkkk" << "llll";
    rowListTwo << "123" << "123" << "123" << "234" << "345" << "456" << "ddddddd" << "345" << "456" << "ddddddd"  << "ddddddd" << "345" << "456" << "ddddddd";
    m_data.insert("testOne",rowListOne);
    m_data.insert("testTwo",rowListTwo);
}

TcTabelModel::~TcTabelModel()
{
    m_headerList.clear();
    m_data.clear();
    qDebug()<<"[test]"<<"data clear";
}

int TcTabelModel::rowCount(const QModelIndex &parent) const
{
    return m_data.count();
}

int TcTabelModel::columnCount(const QModelIndex &) const
{
    return m_headerList.count();
}

QVariant TcTabelModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid() ||
            index.row() < 0 || index.row() >= m_data.count() ||
            index.column() < 0 || index.column() >= m_headerList.count())
    {
        return QVariant();
    }
    QString key = getKey(index.row());
    //qDebug()<<"[test]"<<key<<role;
    if (role == Qt::DisplayRole)
    {
        //qDebug()<<"[test]"<<key;
        return m_data.value(key).at(index.column());
    }
    else
    {
        //! 必须返回一个其他情况的值
        return QVariant();
    }
}
/**
 ** 应当保证本函数不会被调用
 ** 因为表头已经有自定义的了
*/
QVariant TcTabelModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role != Qt::DisplayRole)
        return QVariant();
    if (orientation == Qt::Horizontal)
    {
        return QVariant(m_headerList.at(section));
    }
    else if(orientation == Qt::Vertical)
    {
        return QVariant(section+1);
    }
    else
    {
        return QVariant();
    }
}

void TcTabelModel::print()
{
    QMap<QString,QStringList>::Iterator it = m_data.begin();
    while(it != m_data.end())
    {
        qDebug()<<"[test]"<<it.value();
        ++it;
    }
}

QString TcTabelModel::getKey(int nRow) const
{
    return (m_data.begin() + nRow).key();
}

