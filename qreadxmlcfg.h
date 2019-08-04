#ifndef QREADXMLCFG_H
#define QREADXMLCFG_H

#include <QObject>
#include <QString>


#include <mutex>


class QReadXMLCfg : public QObject
{
    Q_OBJECT
public:
     static QReadXMLCfg* GetInstance();


    void readCfg() ;
    void CreateCfgItemToXML()  ;


private:
    explicit QReadXMLCfg(QObject *parent = nullptr);
    static   QReadXMLCfg* m_instance ;
    static   std::once_flag oc;
public:
    QString strMysqlHost ;
    short  mysqlPort ;
    QString strUser ;
    QString strPasswd  ;



signals:

public slots:

};

#endif // QREADXMLCFG_H
