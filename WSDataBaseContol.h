
#ifndef WSDATABASECONTOL_H
#define WSDATABASECONTOL_H
#include <qapplication.h>
#include <qdebug.h>
#include <QSqlDatabase>
#include <QSqlQueryModel>
#include <QSqlError>
#include <QSqlQuery>
#include <QReadWriteLock>
#include <qdatetime.h>
enum class MaxVCP
{
   MaxVoltage = 0,
   MaxCurrent = 1,
   MaxPower = 2,
};
class WSDataBaseContol
{
private:
    QReadWriteLock dblock;
public:
    WSDataBaseContol();
   ~WSDataBaseContol();
    QSqlDatabase WSdatabase;
    QString databasePath;
 public:
    bool open(QString databaseFileName);
    bool WriteSQLWSCollect(QString nMname,QString nChannel,float nVoltage,float nCurrent ,float nPower,QDateTime  nSampleTime,QString nPort ,int nMddress );
    bool GetMname(QList<QString> * nOutDevieNameList );
    bool  GetChannelName(QString nDeviceDeviceName,QList<QString> *nOutDevieChannelList );
    bool  GetAllDatabyDeviceName( QSqlQueryModel * outGetDataHistoryDataTable);
    bool  GetAllDatabyDeviceName(QString  nMname, QSqlQueryModel * outGetDataHistoryDataTable);
    bool  GetAllDatabyDeviceName(QString  nMname,QString nChannel, QSqlQueryModel * outGetDataHistoryDataTable);

    bool  GetDataHistoryByDeviceName(QSqlQueryModel *outGetDataHistoryDataTable);

    bool  GetDataHistoryByDeviceName(QDateTime nBeginDate,  QString nMname, QSqlQueryModel *outGetDataHistoryDataTable);
    bool  GetDataHistoryByDeviceName(QDateTime nBeginDate, QDateTime nLastDate, QString nMname, QSqlQueryModel * outGetDataHistoryDataTable);
    bool  GetDataHistoryByDeviceName(QDateTime nBeginDate, QDateTime nLastDate, QString nMname,QString nChannel, QSqlQueryModel * outGetDataHistoryDataTable);
    bool  GetDataHistoryByDeviceName(QDateTime nBeginDate, QDateTime nLastDate, QString nMname,MaxVCP nMaxVCP, QSqlQueryModel * outGetDataHistoryDataTable);
    bool  GetDataHistoryByDeviceName(QDateTime nBeginDate, QDateTime nLastDate, QString nMname,QString nChannel, MaxVCP nMaxVCP, QSqlQueryModel * outGetDataHistoryDataTable);
    bool  GetDataHistoryByDeviceName(QString nMname, int lastNum, QSqlQueryModel * outGetDataHistoryDataTable);
       //从bgein开始取几条数据
    bool  GetDataHistoryByDeviceName(QString nMname, QString nChannel, int lastNum, QSqlQueryModel * outGetDataHistoryDataTable);
    //
    bool   GetDataHistoryByDeviceName(QDateTime nbegindate, QString nMname, int lastNum, QSqlQueryModel * outGetDataHistoryDataTable);
    bool   GetDataHistoryByDeviceName(QDateTime nbegindate, QString nMname, QString nChannel,int lastNum, QSqlQueryModel * outGetDataHistoryDataTable);

    bool  GetLateData(QSqlQueryModel * outGetDataHistoryDataTable);
    bool  GetLateData(QString nMname, QSqlQueryModel * outGetDataHistoryDataTable);
    bool  GetLateData(QString nMname,QString nChannel, QSqlQueryModel * outGetDataHistoryDataTable);

    bool DelDataHistory(QDateTime npreDate);
    bool  DelDataHistory(QDateTime nBeginDate, QDateTime nLastDate);
    bool  DelDataHistory(QDateTime nBeginDate, QDateTime nLastDate, QString nMname);
     bool DelDataHistory(QDateTime nBeginDate, QDateTime nLastDate, QString nMname,QString nChannel);
     bool DelDataHistory(int nDelID);
     bool SelectdisDeviceName(QSqlQueryModel *OutGetDeviceNameAndChannel);


};

#endif // WSDATABASECONTOL_H
