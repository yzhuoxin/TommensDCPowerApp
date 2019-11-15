#ifndef MODBUSCOMINFO_H
#define MODBUSCOMINFO_H
#include <qapplication.h>
#include "QSerialPort"
#include"QSerialPortInfo"
#include "QMutex"
#include "QReadWriteLock"

class ModBusComInfo:public QObject
{
public:
    ModBusComInfo();
    ~ModBusComInfo();

public:
     //延迟时间
    int DelayTime;
      //是否只记录变化 值
    bool recordChangeValue;
    //设备名称 自定议
    QString Mname;
    //端口名称
    QString portName;

    //采样频率
    int sampRate;
    //波特率
    int boudRate;
    //读超时时间
    int readTimeOut;
    //写超时时间
    int writeTimeOut;
    QSerialPort *m_serialPort;
   //
    QMutex sMutex;
  bool open();


};
class ModbusList:public QObject
{
public:
   static QReadWriteLock listReadWriteLock;
public:
    ModbusList();

    static QList <ModBusComInfo *> modBusList;
   // static ModBusComInfo * GetAndCreatePortByName(QString portName);
    static void addModbustoList(ModBusComInfo *newModbus);
    static bool SearchbyPortName(QString mPortname);
    static bool deleteAndFree(QString mPortName);
    static bool FreeAllModBus();

};

#endif // MODBUSCOMINFO_H
