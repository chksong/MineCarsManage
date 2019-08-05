#include "mainwindow.h"
#include <QApplication>


#include <QtSql/QSqlDatabase>
#include <QDebug>
#include <QCoreApplication>
#include <QString>


#include "mysqldbhelp.h"


#include <QtGlobal>
#include <QtDebug>
#include <QTextStream>
#include <QTextCodec>
#include <QLocale>
#include <QTime>
#include <QFile>
#include <QMessageBox>
#include <QSharedMemory>

#include "qreadxmlcfg.h"

////////////////////////////////////////////////////////////////
/// \brief  将输出到文件中
/// https://stackoverflow.com/questions/4954140/how-to-redirect-qdebug-qwarning-qcritical-etc-output
///
///
const QString logFilePath = "MineCarsApp.log";
bool logToFile = true;  // 开关

void customMessageOutput(QtMsgType type, const QMessageLogContext &context, const QString &msg)
{
    QHash<QtMsgType, QString> msgLevelHash({{QtDebugMsg, "Debug"}, {QtInfoMsg, "Info"}, {QtWarningMsg, "Warning"}, {QtCriticalMsg, "Critical"}, {QtFatalMsg, "Fatal"}});
    QByteArray localMsg = msg.toLocal8Bit();
    QTime time = QTime::currentTime();
    QString formattedTime = time.toString("hh:mm:ss.zzz");
    QByteArray formattedTimeMsg = formattedTime.toLocal8Bit();
    QString logLevelName = msgLevelHash[type];
    QByteArray logLevelMsg = logLevelName.toLocal8Bit();

    if (logToFile) {
        QString txt = QString("%1 %2: %3 (%4)").arg(formattedTime, logLevelName, msg,  context.file);
        QFile outFile(logFilePath);
        outFile.open(QIODevice::WriteOnly | QIODevice::Append);
        QTextStream ts(&outFile);
        ts << txt << endl;
        outFile.close();
    } else {
        fprintf(stderr, "%s %s: %s (%s:%u, %s)\n", formattedTimeMsg.constData(), logLevelMsg.constData(), localMsg.constData(), context.file, context.line, context.function);
        fflush(stderr);
    }

    if (type == QtFatalMsg)
        abort();
}



/////////////
//  初始化 数据库
bool initMySQLDB()
{
    MysqlDBHelp  help ;
    help.testMysqlAvailabe()  ;
    help.initTables()  ;
    return  true ;
}


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);


    a.processEvents();
     //---- Check for another instance code snippet ----
     //GUID : Generated once for your application
     // you could get one GUID here: http://www.guidgenerator.com/online-guid-generator.aspx

    //
     //https://www.cnblogs.com/techiel/p/8035263.html
     QSharedMemory shared("MineCarsApp");
     if(shared.attach())
     {
         // For a GUI application, replace this by :
          QMessageBox msgBox;
          msgBox.setText( QObject::tr("不能启动多个实例.") );
          msgBox.setIcon( QMessageBox::Critical );
          msgBox.exec();

         qWarning() << "Can't start more than one instance of the application.";
         return  0;
     }


    if( shared.create( 512, QSharedMemory::ReadWrite) ){

     }

    QReadXMLCfg::GetInstance()->CreateCfgItemToXML() ;
    QReadXMLCfg::GetInstance()->readCfg() ;

    initMySQLDB() ;




    MainWindow w;
    w.show();

    auto ret = a.exec();

    return ret  ;
}
