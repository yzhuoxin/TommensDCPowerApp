#ifndef MODBUSCOMINFO_H
#define MODBUSCOMINFO_H
#include <qapplication.h>
#include "QSerialPort"
#include"QSerialPortInfo"

class ModBusComInfo
{
public:
    ModBusComInfo();
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
QSerialPort *serial;




};

#endif // MODBUSCOMINFO_H
