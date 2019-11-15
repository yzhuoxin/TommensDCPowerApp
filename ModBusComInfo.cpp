#include "ModBusComInfo.h"
#include <iterator>
 QReadWriteLock  ModbusList::listReadWriteLock;
 QList <ModBusComInfo *> ModbusList::modBusList;
ModBusComInfo::ModBusComInfo()
{

}
bool ModBusComInfo::open()
{
       m_serialPort=new QSerialPort();
       if (portName!=nullptr)
       {
       m_serialPort->setPortName(this->portName);
       }else {
           return false;
       }
       m_serialPort->setBaudRate(boudRate,QSerialPort::AllDirections);//设置波特率和读写方向
       m_serialPort->setDataBits(QSerialPort::Data8);		//数据位为8位
       m_serialPort->setFlowControl(QSerialPort::NoFlowControl);//无流控制
       m_serialPort->setParity(QSerialPort::NoParity);	//无校验位
       m_serialPort->setStopBits(QSerialPort::OneStop);
       if (!m_serialPort->isOpen())
       {
           m_serialPort->open(QIODevice::ReadWrite);
       }
       return  true;

}
ModBusComInfo::~ModBusComInfo()
{
    this->sMutex.lock();
    if ((m_serialPort!=nullptr)&&(m_serialPort->isOpen()))
    {
        m_serialPort->close();
     }
    this->sMutex.unlock();
}

 bool   ModbusList::SearchbyPortName(QString mPortname)
{
   listReadWriteLock.lockForRead();
 //  QList <ModBusComInfo *>::iterator moduIter;
   for(int mindex=0;mindex<modBusList.count();mindex++)
   {
       if (modBusList[mindex]->portName==mPortname)
       {
           listReadWriteLock.unlock();
           return  true;

       }

   }
   listReadWriteLock.unlock();
   return  false;

}
void ModbusList::addModbustoList(ModBusComInfo *newModbus)
{
    listReadWriteLock.lockForWrite();
    modBusList.append(newModbus);
    listReadWriteLock.unlock();
}
 bool ModbusList::deleteAndFree(QString mPortName)
 {
     listReadWriteLock.lockForWrite();
   //  QList <ModBusComInfo *>::iterator moduIter;
     for(int mindex=0;mindex<modBusList.count();mindex++)
     {
         if (modBusList[mindex]->portName==mPortName)
         {
             delete modBusList[mindex];
             modBusList.removeAt(mindex);
             listReadWriteLock.unlock();
             return  true;

         }

     }
     listReadWriteLock.unlock();
     return  false;

 }
 bool ModbusList:: FreeAllModBus()
 {
     listReadWriteLock.lockForWrite();
   //  QList <ModBusComInfo *>::iterator moduIter;
     for(int mindex=0;mindex<modBusList.count();mindex++)
     {
         if (modBusList[mindex]!=nullptr)
         {
             delete modBusList[mindex];
         }

     }
     modBusList.clear();
     listReadWriteLock.unlock();
     return  false;
 }

