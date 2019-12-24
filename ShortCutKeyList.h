#ifndef SHORTCUTKEYLIST_H
#define SHORTCUTKEYLIST_H

#include <QObject>

class ShortCutKey
{
   public:
    ShortCutKey();
public:
    QString KeyName;
    QString keyID;
    quint16 VoltageAddr = 0x1000;//</VoltageAddr> <!-- ShortcutButtonVoltage Address -->

    float VoltageValue;

     quint16 CurrentAddr = 0x1001;//</CurrentAddr><!-- ShortcutButtonCurrent Address -->

    float  CurrentValue ;

     quint16 TimeSpanAddr = 0x1002;//</TimeSpanAddr><!-- ShortcutButton 时间  Address -->

      qint32 TimeSpanValue ;
      qint16 MaxTimeSpanValue = 9999;

      qint16 EnableAddr = 0x1003;//</EnableAddr><!-- ShortcutButtonEnable Address -->

      bool EnableValue ;

};

class ShortCutKeyList : public QObject
{
    Q_OBJECT
public:
    explicit ShortCutKeyList(QObject *parent = nullptr);
    ~ShortCutKeyList();
     QList<ShortCutKey*> mShortCutKeyList;
     QString ClassName;
     quint16 VoltageBytes=2;
     quint16 CurrentBytes = 2;
     quint16 TimeSpanBytes = 2;
     quint16 EnableBytes = 2;
     ShortCutKey * getShortCutByID(QString ScID);
     ShortCutKey * getShortCutByName(QString Scname);
    // bool searchShortCutByID(QString mscID);
   //  bool searchshortCutByName(QString sCname);
     void addShortCutToList(ShortCutKey *mshortCutKey);
     bool FreeAllShortCut();




signals:

public slots:
};

#endif // SHORTCUTKEYLIST_H
