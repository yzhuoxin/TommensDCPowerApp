#ifndef MODBUSCRC_H
#define MODBUSCRC_H
#include <QObject>

class ModbusCRC
{
public:
    ModbusCRC();
    static unsigned char _auchCRCHi[];
    static unsigned char _auchCRCLo[];
    static  quint16 CRC16(unsigned char buffer[],int Sset,int ESet);
    static void CRC16(unsigned char buffer[], int Sset, int Eset,  unsigned char  &hiCRCBit,unsigned char &loCRCBit);
    static ushort CRC16Calc(unsigned char databuff[],uint datalen);
    static void CRC16Calc(uchar databuff[],uint datalen,uchar &hiCRCBit,uchar &loCRCBit);
};

#endif // MODBUSCRC_H
