#ifndef WRITECOMLOGS_H
#define WRITECOMLOGS_H

#include <qapplication.h>
#include <stdio.h>
#include <stdlib.h>
#include <QMutex>
class WriteCOMlogs
{
public:
    WriteCOMlogs();
    static void startLog();
    static void outputMessage(QtMsgType type, const QMessageLogContext &context, const QString &msg);
    static void setEnable(bool logenable);
    static  QString logfileName;
private:
    static bool log_enable;
    static QMutex mutex;
};

#endif // WRITECOMLOGS_H
