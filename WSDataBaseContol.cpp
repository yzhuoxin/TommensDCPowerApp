#include "WSDataBaseContol.h"

#include "writecomlogs.h"
WSDataBaseContol::WSDataBaseContol()
{

}
bool WSDataBaseContol::open(QString databaseFileName)
{
  //  databasePath=MainWindow::databasePath+"\\DataBase\\MyDataBase.db";
    this->WSdatabase = QSqlDatabase::addDatabase("QSQLITE","ws");
    this->WSdatabase.setDatabaseName(databaseFileName);
    if (!this->WSdatabase.isOpen())
    {
       if  (!this->WSdatabase.open())
       {
           qCritical()<<"Error: Failed to connect database." << WSdatabase.lastError();
           return false;

       }else {
           return true;

       }

    }else {
        return true;

}
}
bool WSDataBaseContol::WriteSQLWSCollect(QString nMname, QString nChannel, float nVoltage, float nCurrent, float nPower, QDateTime nSampleTime, QString nPort, int nMddress)
{
    if (this->WSdatabase.isOpen())
    {
       this->dblock.lockForWrite();
          QSqlQuery WriteWSquery(this->WSdatabase);
          WriteWSquery.prepare("insert into  ElectValue (Mname,Channel,Voltage,Current,Power,SampTime,Port,MAddress)values \
                                     (:nMname,:nChannel,:nVoltage,:nCurrent,:nPower,:nSampTime,:nPort,:nMddress)");
          WriteWSquery.bindValue(":nMname",nMname);
          WriteWSquery.bindValue(":nChannel",nChannel);
          WriteWSquery.bindValue(":nVoltage",nVoltage);
          WriteWSquery.bindValue(":nCurrent",nCurrent);
          WriteWSquery.bindValue(":nPower",nPower);
          WriteWSquery.bindValue(":nSampTime",nSampleTime);
          WriteWSquery.bindValue(":nPort",nPort);
          WriteWSquery.bindValue(":nMddress",nMddress);
          WriteWSquery.exec();
         this->dblock.unlock();
         return true;

    }else {
        qCritical()<<"Error:open database before";
        return false;

}
}
bool WSDataBaseContol::GetMname(QList<QString> *nOutDevieNameList)
{
    if (this->WSdatabase.isOpen())
    {
        dblock.lockForRead();
        QSqlQuery getMnameQuery(WSdatabase);
        getMnameQuery.prepare("select distinct(Mname) from  ElectValue");
        getMnameQuery.executedQuery();
        while(getMnameQuery.next())
        {
           nOutDevieNameList->append(getMnameQuery.value("Mname").toString());
        }
        dblock.unlock();
        return true;

    }else {
        qCritical()<<"before open database please!";
        return  false;
}

}
bool WSDataBaseContol::GetChannelName(QString nDeviceDeviceName, QList<QString> *nOutDevieChannelList)
{
    if (WSdatabase.isOpen())
}
WSDataBaseContol::~WSDataBaseContol()
{
    if (WSdatabase.isOpen())
    {
        WSdatabase.close();
    }
}
