#include "qreadxmlcfg.h"

#include <QDomDocument>
#include <QDomProcessingInstruction>
#include <QFile>
#include <QTextStream>
#include <QDir>
#include <QCoreApplication>



////////////////////////////////////////////////
QReadXMLCfg* QReadXMLCfg::m_instance = nullptr ;
std::once_flag QReadXMLCfg::oc ;


///////////////////////////////
QReadXMLCfg* QReadXMLCfg::GetInstance()
{
    std::call_once(oc,[&](){m_instance =new QReadXMLCfg();});
    return m_instance;
}


QReadXMLCfg::QReadXMLCfg(QObject *parent) : QObject(parent)
{
}

/////////////////////////////////////////
void QReadXMLCfg::readCfg()
{
    //  https://blog.csdn.net/hpu11/article/details/80227093
    QString strFileAppConfig = QCoreApplication::applicationDirPath();
    strFileAppConfig.append("/MineCarsConfig.xml");

    //打开或创建文件
    QFile file(strFileAppConfig); //相对路径、绝对路径、资源路径都行
    if (!file.open(QFile::ReadOnly))
         return;

    QDomDocument doc;
    if (!doc.setContent(&file))
    {
        file.close();
        return;
    }

    QDomNodeList nodelist = doc.elementsByTagName("MySQL");
    if(nodelist.length())
    {
        QDomNode node = nodelist.at(0);
        strMysqlHost = node.toElement().attribute("host") ;
        mysqlPort    = node.toElement().attribute("port").toShort() ;
        strUser      =  node.toElement().attribute("user")  ;
        strPasswd   =  node.toElement().attribute("passwd") ;
    }

    file.close() ;
}







void QReadXMLCfg::CreateCfgItemToXML()
{
    //  https://blog.csdn.net/hpu11/article/details/80227093
    QString strFileAppConfig = QCoreApplication::applicationDirPath();
    strFileAppConfig.append("/MineCarsConfig.xml");


    QFile file(strFileAppConfig); //相对路径、绝对路径、资源路径都可以
    if (!file.open(QFile::WriteOnly | QFile::Truncate)) //可以用QIODevice，Truncate表示清空原来的内容
        return;

    QDomDocument doc;
    //写入xml头部
    QDomProcessingInstruction instruction; //添加处理命令
    instruction = doc.createProcessingInstruction("xml", "version=\"1.0\" encoding=\"UTF-8\"");
    doc.appendChild(instruction);

    QDomElement root = doc.createElement("MineCarsCfg");
    doc.appendChild(root);

 //   for (int i = 0; i < ballisticList.size(); ++i)
 //   {
        QDomElement item = doc.createElement("MySQL");

        QDomAttr host = doc.createAttribute("host"); //方式二：创建属性 值必须是字符串
        host.setValue(QString("127.0.0.1"));
        item.setAttributeNode(host);

        QDomAttr port = doc.createAttribute("port"); //方式二：创建属性 值必须是字符串
        port.setValue(QString("3306"));
        item.setAttributeNode(port);

        QDomAttr user = doc.createAttribute("user"); //方式二：创建属性 值必须是字符串
        user.setValue(QString("root"));
        item.setAttributeNode(user);

        QDomAttr passwd = doc.createAttribute("passwd"); //方式二：创建属性 值必须是字符串
        passwd.setValue(QString("123456"));
        item.setAttributeNode(passwd);

        QDomText text; //设置括号标签中间的值
        text = doc.createTextNode("Mysq Config Item");
        item.appendChild(text);
        root.appendChild(item);
 //   }

    //输出到文件
    QTextStream out_stream(&file);
    doc.save(out_stream, 4); //缩进4格
    file.close();
}

