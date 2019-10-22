#include "WSDataBaseContol.h"

#include "writecomlogs.h"
enum MaxVCP;
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
    {
        dblock.lockForRead();
        QSqlQuery getchQuery(WSdatabase);
        getchQuery.prepare("select distinct(Channel) from ElectValue where Mname=:Mname");
        getchQuery.bindValue(":Mname",nDeviceDeviceName);
        getchQuery.exec();
        while(getchQuery.next())
        {
            nOutDevieChannelList->append(getchQuery.value("Channal").toString());

        }
        dblock.unlock();
        return  true;
    }else {
        qCritical()<<"before open database please!";
        return  false;
}
}
bool WSDataBaseContol::GetAllDatabyDeviceName(QSqlQueryModel *outGetDataHistoryDataTable)
{
    if (WSdatabase.isOpen())
    {
        dblock.lockForRead();

        outGetDataHistoryDataTable->setQuery("select * from  ElectValue order by id desc  ",WSdatabase);
        while(outGetDataHistoryDataTable->canFetchMore())
        {
            outGetDataHistoryDataTable->fetchMore();
        }
        dblock.unlock();
        return  true;

    }
        else {
                qCritical()<<"before open database please!";
                return  false;
        }
    }

bool WSDataBaseContol::GetAllDatabyDeviceName(QString nMname, QSqlQueryModel *outGetDataHistoryDataTable)
{
    if (WSdatabase.isOpen())
    {
        dblock.lockForRead();
        QSqlQuery gethQuery(WSdatabase);
        gethQuery.prepare("select * from  ElectValue where Mname=:Mname  ");
        gethQuery.bindValue(":Mname",nMname);
        outGetDataHistoryDataTable->setQuery(gethQuery);

        while(outGetDataHistoryDataTable->canFetchMore())
        {
            outGetDataHistoryDataTable->fetchMore();
        }
        dblock.unlock();
        return true;
    }else {
        qCritical()<<"before open database please!";
        return  false;
}
}
bool WSDataBaseContol::GetAllDatabyDeviceName(QString nMname, QString nChannel, QSqlQueryModel *outGetDataHistoryDataTable)
{
    if (WSdatabase.isOpen())
    {
        dblock.lockForRead();
        QSqlQuery gethQuery(WSdatabase);
        gethQuery.prepare("select * from  ElectValue where Mname=:Mname and Channel=:NChannel ");
        gethQuery.bindValue(":Mname",nMname);
        gethQuery.bindValue(":NChannel",nChannel);
        outGetDataHistoryDataTable->setQuery(gethQuery);

        while(outGetDataHistoryDataTable->canFetchMore())
        {
            outGetDataHistoryDataTable->fetchMore();
        }
        dblock.unlock();
        return true;
    }else {
        qCritical()<<"before open database please!";
        return  false;
}
}


bool  WSDataBaseContol::GetDataHistoryByDeviceName(QSqlQueryModel *outGetDataHistoryDataTable)
{


    if (WSdatabase.isOpen())
    {
        dblock.lockForRead();

        outGetDataHistoryDataTable->setQuery("select * from  ElectValue order by id desc  ",WSdatabase);
        while(outGetDataHistoryDataTable->canFetchMore())
        {
            outGetDataHistoryDataTable->fetchMore();
        }
        dblock.unlock();
        return  true;

    }
        else {
                qCritical()<<"before open database please!";
                return  false;
        }
}

bool WSDataBaseContol::GetDataHistoryByDeviceName(QDateTime nBeginDate,  QString nMname, QSqlQueryModel *outGetDataHistoryDataTable)
{
    if (WSdatabase.isOpen())
    {
        dblock.lockForRead();
        QSqlQuery gethQuery(WSdatabase);
        gethQuery.prepare("select * from  ElectValue where Mname=:Mname  and SampTime>=:nBeginDate ");
        gethQuery.bindValue(":Mname",nMname);
        gethQuery.bindValue(":nBeginDate",nBeginDate);
        outGetDataHistoryDataTable->setQuery(gethQuery);

        while(outGetDataHistoryDataTable->canFetchMore())
        {
            outGetDataHistoryDataTable->fetchMore();
        }
        dblock.unlock();
        return true;
    }else {
        qCritical()<<"before open database please!";
        return  false;
}
}
bool WSDataBaseContol::GetDataHistoryByDeviceName(QDateTime nBeginDate, QDateTime nLastDate, QString nMname, QSqlQueryModel * outGetDataHistoryDataTable)
{
    if (WSdatabase.isOpen())
    {
        dblock.lockForRead();
        QSqlQuery gethQuery(WSdatabase);
        gethQuery.prepare("select * from  ElectValue where Mname=:Mname  and SampTime>=:nBeginDate and SampTime<=:nLastDate");
        gethQuery.bindValue(":Mname",nMname);
        gethQuery.bindValue(":nBeginDate",nBeginDate);
        gethQuery.bindValue(":nLastDate",nLastDate);
        outGetDataHistoryDataTable->setQuery(gethQuery);

        while(outGetDataHistoryDataTable->canFetchMore())
        {
            outGetDataHistoryDataTable->fetchMore();
        }
        dblock.unlock();
        return true;
    }else {
        qCritical()<<"before open database please!";
        return  false;
    }
}

bool  WSDataBaseContol::GetDataHistoryByDeviceName(QDateTime nBeginDate, QDateTime nLastDate, QString nMname,QString nChannel, QSqlQueryModel * outGetDataHistoryDataTable)
{
    if (WSdatabase.isOpen())
    {
        dblock.lockForRead();
        QSqlQuery gethQuery(WSdatabase);
        gethQuery.prepare("select * from  ElectValue where Mname=:Mname and Channel=:nChannel and SampTime>=:nBeginDate and SampTime<=:nLastDate");
        gethQuery.bindValue(":Mname",nMname);
        gethQuery.bindValue(":nBeginDate",nBeginDate);
        gethQuery.bindValue(":nLastDate",nLastDate);
         gethQuery.bindValue(":nChannel",nChannel);
        outGetDataHistoryDataTable->setQuery(gethQuery);

        while(outGetDataHistoryDataTable->canFetchMore())
        {
            outGetDataHistoryDataTable->fetchMore();
        }
        dblock.unlock();
        return true;
    }else {
        qCritical()<<"before open database please!";
        return  false;
    }
}
bool  WSDataBaseContol::GetDataHistoryByDeviceName(QDateTime nBeginDate, QDateTime nLastDate, QString nMname,MaxVCP nMaxVCP, QSqlQueryModel * outGetDataHistoryDataTable)
{
    if (WSdatabase.isOpen())
    {
        dblock.lockForRead();
        QSqlQuery gethQuery(WSdatabase);
        if (nMaxVCP==MaxVCP::MaxVoltage)
        {
            gethQuery.prepare("select * from  ElectValue where Mname=:Mname  and SampTime>=:nBeginDate and SampTime<=:nLastDate and Voltage=Max(Voltage)");

        }else if (nMaxVCP==MaxVCP::MaxCurrent)
        {
             gethQuery.prepare("select * from  ElectValue where Mname=:Mname  and SampTime>=:nBeginDate and SampTime<=:nLastDate and Current=Max(Current)");
        }else if (nMaxVCP==MaxVCP::MaxPower)
        {
            gethQuery.prepare("select * from  ElectValue where Mname=:Mname  and SampTime>=:nBeginDate and SampTime<=:nLastDate and Power=Max(Power)");
        }

        gethQuery.bindValue(":Mname",nMname);
        gethQuery.bindValue(":nBeginDate",nBeginDate);
        gethQuery.bindValue(":nLastDate",nLastDate);

        outGetDataHistoryDataTable->setQuery(gethQuery);

        while(outGetDataHistoryDataTable->canFetchMore())
        {
            outGetDataHistoryDataTable->fetchMore();
        }
        dblock.unlock();
        return true;
    }else {
        qCritical()<<"before open database please!";
        return  false;
    }
}
bool  WSDataBaseContol::GetDataHistoryByDeviceName(QDateTime nBeginDate, QDateTime nLastDate, QString nMname,QString nChannel, MaxVCP nMaxVCP, QSqlQueryModel * outGetDataHistoryDataTable)
{
    if (WSdatabase.isOpen())
    {
        dblock.lockForRead();
        QSqlQuery gethQuery(WSdatabase);
        if (nMaxVCP==MaxVCP::MaxVoltage)
        {
            gethQuery.prepare("select * from  ElectValue where Mname=:Mname and Channel=:nChannel and SampTime>=:nBeginDate and SampTime<=:nLastDate and Voltage=Max(Voltage)");

        }else if (nMaxVCP==MaxVCP::MaxCurrent)
        {
             gethQuery.prepare("select * from  ElectValue where Mname=:Mname and  Channel=:nChannel  and SampTime>=:nBeginDate and SampTime<=:nLastDate and Current=Max(Current)");
        }else if (nMaxVCP==MaxVCP::MaxPower)
        {
            gethQuery.prepare("select * from  ElectValue where Mname=:Mname and Channel=:nChannel  and SampTime>=:nBeginDate and SampTime<=:nLastDate and Power=Max(Power)");
        }

        gethQuery.bindValue(":Mname",nMname);
        gethQuery.bindValue(":nBeginDate",nBeginDate);
        gethQuery.bindValue(":nLastDate",nLastDate);
         gethQuery.bindValue(":nChannel",nChannel);
        outGetDataHistoryDataTable->setQuery(gethQuery);

        while(outGetDataHistoryDataTable->canFetchMore())
        {
            outGetDataHistoryDataTable->fetchMore();
        }
        dblock.unlock();
        return true;
    }else {
        qCritical()<<"before open database please!";
        return  false;
    }
}
bool WSDataBaseContol::GetDataHistoryByDeviceName(QString nMname, int lastNum, QSqlQueryModel * outGetDataHistoryDataTable)
{

    if (WSdatabase.isOpen())
    {
        dblock.lockForRead();
        QSqlQuery gethQuery(WSdatabase);
        gethQuery.prepare(" select *from  ElectValue where   Mname=@nMname  order by id  desc limit :nlastNum offset 0");
        gethQuery.bindValue(":Mname",nMname);
        gethQuery.bindValue(":nlastNum",lastNum);
        outGetDataHistoryDataTable->setQuery(gethQuery);

        while(outGetDataHistoryDataTable->canFetchMore())
        {
            outGetDataHistoryDataTable->fetchMore();
        }
        dblock.unlock();
        return true;
    }else {
        qCritical()<<"before open database please!";
        return  false;
    }

}

   //从bgein开始取几条数据
bool WSDataBaseContol::WSDataBaseContol::GetDataHistoryByDeviceName(QString nMname, QString nChannel, int lastNum, QSqlQueryModel * outGetDataHistoryDataTable)
{
    if (WSdatabase.isOpen())
    {
        dblock.lockForRead();
        QSqlQuery gethQuery(WSdatabase);
        gethQuery.prepare(" select *from  ElectValue where   Mname=@nMname  and Channel=:nChannel order by id  desc limit :nlastNum offset 0");
        gethQuery.bindValue(":Mname",nMname);
        gethQuery.bindValue(":nChannel",nChannel);
        gethQuery.bindValue(":nlastNum",lastNum);
        outGetDataHistoryDataTable->setQuery(gethQuery);

        while(outGetDataHistoryDataTable->canFetchMore())
        {
            outGetDataHistoryDataTable->fetchMore();
        }
        dblock.unlock();
        return true;
    }else {
        qCritical()<<"before open database please!";
        return  false;
    }

}

//
bool   WSDataBaseContol::GetDataHistoryByDeviceName(QDateTime nbegindate, QString nMname, int lastNum, QSqlQueryModel * outGetDataHistoryDataTable)
{
    if (WSdatabase.isOpen())
    {
        dblock.lockForRead();
        QSqlQuery gethQuery(WSdatabase);
        gethQuery.prepare(" select *from  ElectValue where   Mname=@nMname   and SampTime>:ngegindate order by id  desc limit :nlastNum offset 0");
        gethQuery.bindValue(":Mname",nMname);
        gethQuery.bindValue(":ngegindate",nbegindate);
        gethQuery.bindValue(":nlastNum",lastNum);
        outGetDataHistoryDataTable->setQuery(gethQuery);

        while(outGetDataHistoryDataTable->canFetchMore())
        {
            outGetDataHistoryDataTable->fetchMore();
        }
        dblock.unlock();
        return true;
    }else {
        qCritical()<<"before open database please!";
        return  false;
    }
}
bool  WSDataBaseContol::GetDataHistoryByDeviceName(QDateTime nbegindate, QString nMname, QString nChannel,int lastNum, QSqlQueryModel * outGetDataHistoryDataTable)
{
    if (WSdatabase.isOpen())
    {
        dblock.lockForRead();
        QSqlQuery gethQuery(WSdatabase);
        gethQuery.prepare(" select *from  ElectValue where   Mname=@nMname  and Channel=:nChannel  and SampTime>:ngegindate order by id  desc limit :nlastNum offset 0");
        gethQuery.bindValue(":Mname",nMname);
        gethQuery.bindValue(":nChannel",nChannel);
        gethQuery.bindValue(":ngegindate",nbegindate);
        gethQuery.bindValue(":nlastNum",lastNum);
        outGetDataHistoryDataTable->setQuery(gethQuery);

        while(outGetDataHistoryDataTable->canFetchMore())
        {
            outGetDataHistoryDataTable->fetchMore();
        }
        dblock.unlock();
        return true;
    }else {
        qCritical()<<"before open database please!";
        return  false;
    }
}

bool  WSDataBaseContol::GetLateData(QSqlQueryModel * outGetDataHistoryDataTable)
{

    if (WSdatabase.isOpen())
    {
        dblock.lockForRead();

        outGetDataHistoryDataTable->setQuery("select * from  ElectValue where id in (select MAX(id) FROM  ElectValue GROUP BY Mname)",WSdatabase);
        while(outGetDataHistoryDataTable->canFetchMore())
        {
            outGetDataHistoryDataTable->fetchMore();
        }
        dblock.unlock();
        return  true;

    }
        else {
                qCritical()<<"before open database please!";
                return  false;
        }
}
bool WSDataBaseContol::GetLateData(QString nMname, QSqlQueryModel * outGetDataHistoryDataTable)
{
    if (WSdatabase.isOpen())
    {
        dblock.lockForRead();

        QSqlQuery gethQuery(WSdatabase);
        gethQuery.prepare("select * from  ElectValue where id in (select MAX(id) FROM  ElectValue where Mname=:Mname GROUP BY Channel)");
        gethQuery.bindValue(":Mname",nMname);
        outGetDataHistoryDataTable->setQuery(gethQuery);
        while(outGetDataHistoryDataTable->canFetchMore())
        {
            outGetDataHistoryDataTable->fetchMore();
        }
        dblock.unlock();
        return  true;

    }
        else {
                qCritical()<<"before open database please!";
                return  false;
        }
}
bool  WSDataBaseContol::GetLateData(QString nMname,QString nChannel, QSqlQueryModel * outGetDataHistoryDataTable)
{
    if (WSdatabase.isOpen())
    {
        dblock.lockForRead();

        QSqlQuery gethQuery(WSdatabase);
        gethQuery.prepare("select * from  ElectValue where id in (select MAX(id) FROM  ElectValue where Mname=:Mname and Channel=:nChannel)");
        gethQuery.bindValue(":Mname",nMname);
        gethQuery.bindValue(":nChannel",nChannel);
        outGetDataHistoryDataTable->setQuery(gethQuery);
        while(outGetDataHistoryDataTable->canFetchMore())
        {
            outGetDataHistoryDataTable->fetchMore();
        }
        dblock.unlock();
        return  true;

    }
        else {
                qCritical()<<"before open database please!";
                return  false;
        }

}

bool WSDataBaseContol::DelDataHistory(QDateTime npreDate)
{
    if (WSdatabase.isOpen())
    {
        dblock.lockForRead();
        QSqlQuery getchQuery(WSdatabase);
        getchQuery.prepare("delete  from ElectValue where SimpleTime<:npreDate");
        getchQuery.bindValue(":npreDate",npreDate);
        getchQuery.exec();
        dblock.unlock();
        return  true;
    }else {
        qCritical()<<"before open database please!";
        return  false;
    }
}
bool  WSDataBaseContol::DelDataHistory(QDateTime nBeginDate, QDateTime nLastDate)
{
    if (WSdatabase.isOpen())
    {
        dblock.lockForRead();
        QSqlQuery getchQuery(WSdatabase);
        getchQuery.prepare("delete  from ElectValue where SimpleTime>:nBeginDate and  SimpleTime<:nLastDate");
        getchQuery.bindValue(":nBeginDate",nBeginDate);
        getchQuery.bindValue(":nLastDate",nLastDate);
        getchQuery.exec();
        dblock.unlock();
        return  true;
    }else {
        qCritical()<<"before open database please!";
        return  false;
    }
}

bool  WSDataBaseContol::DelDataHistory(QDateTime nBeginDate, QDateTime nLastDate, QString nMname)
{
    if (WSdatabase.isOpen())
    {
        dblock.lockForRead();
        QSqlQuery getchQuery(WSdatabase);
        getchQuery.prepare("delete  from ElectValue where SimpleTime>:nBeginDate and  SimpleTime<:nLastDate and Mname=:nMname");
        getchQuery.bindValue(":nBeginDate",nBeginDate);
        getchQuery.bindValue(":nLastDate",nLastDate);
        getchQuery.bindValue(":nMname",nMname);
        getchQuery.exec();
        dblock.unlock();
        return  true;
    }else {
        qCritical()<<"before open database please!";
        return  false;
    }
}
 bool WSDataBaseContol::DelDataHistory(QDateTime nBeginDate, QDateTime nLastDate, QString nMname,QString nChannel)
 {
     if (WSdatabase.isOpen())
     {
         dblock.lockForRead();
         QSqlQuery getchQuery(WSdatabase);
         getchQuery.prepare("delete  from ElectValue where SimpleTime>:nBeginDate and  SimpleTime<:nLastDate and Mname=:nMname and Channel=:nChannel");
         getchQuery.bindValue(":nBeginDate",nBeginDate);
         getchQuery.bindValue(":nLastDate",nLastDate);
         getchQuery.bindValue(":nMname",nMname);
         getchQuery.bindValue(":nChannel",nChannel);
         getchQuery.exec();
         dblock.unlock();
         return  true;
     }else {
         qCritical()<<"before open database please!";
         return  false;
     }
 }
 bool WSDataBaseContol::DelDataHistory(int nDelID)
 {
     if (WSdatabase.isOpen())
     {
         dblock.lockForRead();
         QSqlQuery getchQuery(WSdatabase);
         getchQuery.prepare("delete  from ElectValue where id=:NdelID");
         getchQuery.bindValue(":NdelID",nDelID);

         getchQuery.exec();
         dblock.unlock();
         return  true;
     }else {
         qCritical()<<"before open database please!";
         return  false;
     }
 }

 bool SelectdisDeviceName(QSqlQueryModel *OutGetDeviceNameAndChannel);




WSDataBaseContol::~WSDataBaseContol()
{
    if (WSdatabase.isOpen())
    {
        WSdatabase.close();
    }
}
