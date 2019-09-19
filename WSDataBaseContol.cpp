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
           qDebug()<< "Error: Failed to connect database." << WSdatabase.lastError();
           return false;

       }else {
           return true;

       }

    }else {
        return true;

}
}
WSDataBaseContol::~WSDataBaseContol()
{
    if (WSdatabase.isOpen())
    {
        WSdatabase.close();
    }
}
