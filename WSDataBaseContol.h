
#ifndef WSDATABASECONTOL_H
#define WSDATABASECONTOL_H
#include <qapplication.h>
#include <qdebug.h>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>

class WSDataBaseContol
{
public:
    WSDataBaseContol();
   ~WSDataBaseContol();
    QSqlDatabase WSdatabase;
    QString databasePath;
 public:
    bool open(QString databaseFileName);

};

#endif // WSDATABASECONTOL_H
