#include "writecomlogs.h"
 #include <qapplication.h>
#include "mainwindow.h"

#include <QDateTime>
#include <QIODevice>
#include <QFile>
#include <QTextStream>

bool WriteCOMlogs::log_enable=true;
QMutex WriteCOMlogs::mutex;
WriteCOMlogs::WriteCOMlogs()
{
}
void WriteCOMlogs::startLog()
{
     qInstallMessageHandler(outputMessage);
}
void WriteCOMlogs::setEnable(bool logenable)
{
    log_enable=logenable;
}
void WriteCOMlogs::outputMessage(QtMsgType type, const QMessageLogContext &context, const QString &msg)
{
    if (log_enable==false)
        return;

    QString text;
    switch(type)
    {
    case QtDebugMsg:
        text = QString("Debug:");
        break;

    case QtWarningMsg:
        text = QString("Warning:");
        break;

    case QtCriticalMsg:
        text = QString("Critical:");
        break;

    case QtFatalMsg:
        text = QString("Fatal:");
        break;

    case QtInfoMsg:
        text=QString("Info:");
        break;
    }

    QString context_info = QString("File:(%1) Line:(%2)").arg(QString(context.file)).arg(context.line);
    QString current_date_time = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss ddd");
    QString current_date = QString("(%1)").arg(current_date_time);
    QString message = QString("%1 %2 %3 %4").arg(text).arg(context_info).arg(msg).arg(current_date);

    QString logfileName=MainWindow::logfilepath+(QDateTime::currentDateTime().toString("yyyy-MM-dd"))+(".txt");
    QFile file(logfileName);
    mutex.lock();
    file.open(QIODevice::WriteOnly | QIODevice::Append);
    QTextStream text_stream(&file);
    text_stream << message << "\r\n";
    file.flush();
    file.close();

    mutex.unlock();
}
