
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
enum MaxVCP
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
    QList<QString> * GetMname(QList<QString> * nOutDevieNameList );
    QList<QString> * GetChannelName(QString nDeviceDeviceName,QList<QString> *nOutDevieChannelList );
    bool  GetAllDatabyDeviceName( QSqlQueryModel * OutGetDataHistoryDataTable);
    bool  GetAllDatabyDeviceName(QString  nMname, QSqlQueryModel * nChartDataTable);
    bool  GetAllDatabyDeviceName(QString  nMname,QString nChannel, QSqlQueryModel * nChartDataTable);

    bool  GetDataHistoryByDeviceName(QSqlQueryModel *OutGetDataHistoryDataTable);

    bool  GetDataHistoryByDeviceName(QDateTime nBeginDate,  QString nWSname, QSqlQueryModel *OutGetDataHistoryDataTable);
    bool  GetDataHistoryByDeviceName(QDateTime nBeginDate, QDateTime nLastDate, QString nWSname, QSqlQueryModel * OutGetDataHistoryDataTable);
    bool  GetDataHistoryByDeviceName(QDateTime nBeginDate, QDateTime nLastDate, QString nWSname,QString nChannel, QSqlQueryModel * OutGetDataHistoryDataTable);
    bool  GetDataHistoryByDeviceName(QDateTime nBeginDate, QDateTime nLastDate, QString nWSname,MaxVCP nMaxVCP, QSqlQueryModel * OutGetDataHistoryDataTable);
    bool  GetDataHistoryByDeviceName(QDateTime nBeginDate, QDateTime nLastDate, QString nWSname,QString nChannel, MaxVCP nMaxVCP, QSqlQueryModel * OutGetDataHistoryDataTable);
    bool  GetDataHistoryByDeviceName(QString nWSname, int lastNum, QSqlQueryModel * outGetDataHistoryDataTable);
       //从bgein开始取几条数据
    bool  GetDataHistoryByDeviceName(QString nWSname, QString nChannel, int lastNum, QSqlQueryModel * outGetDataHistoryDataTable);
    //
    bool   GetDataHistoryByDeviceName(QDateTime nbegindate, QString nWSname, int lastNum, QSqlQueryModel * OutGetDataHistoryDataTable);
    bool   GetDataHistoryByDeviceName(QDateTime nbegindate, QString nWSname, QString nChannel,int lastNum, QSqlQueryModel * OutGetDataHistoryDataTable);

    bool  GetLateData(QSqlQueryModel * OutGetDataHistoryDataTable);
    bool  GetLateData(QString nWSname, QSqlQueryModel * OutGetDataHistoryDataTable);
    bool  GetLateData(QString nWSname,QString nChannel, QSqlQueryModel * OutGetDataHistoryDataTable);

    bool DelDataHistory(QDateTime npreDate);
    bool  DelDataHistory(QDateTime nBeginDate, QDateTime nLastDate);
    bool  DelDataHistory(QDateTime nBeginDate, QDateTime nLastDate, QString nWSname);
     bool DelDataHistory(QDateTime nBeginDate, QDateTime nLastDate, QString nWSname,QString nChannel);
     bool DelDataHistory(int nDelID);
     bool SelectdisDeviceName(QSqlQueryModel *OutGetDeviceNameAndChannel);


};

#endif // WSDATABASECONTOL_H
