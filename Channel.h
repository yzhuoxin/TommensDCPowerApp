#ifndef CHANNEL_H
#define CHANNEL_H
#include <qapplication.h>

class Channel: public QObject
{
public:
    Channel();
    //设备硬件地址有可能不存在
    int ChannelID;
    QString  alisName;
    unsigned char hostaddress;
    //
    unsigned short VoltageAddr=0x0010;//</VoltageAddr> <!-- 显示Voltage Address -->
    int VoltageBytes = 2;//</VoltageBytes> <!-- 显示Voltage Address长度 -->

   unsigned short CurrentAddr=0x0011;//</CurrentAddr><!-- 显示Current Address -->
    int CurrentBytes = 2;//</CurrentBytes><!-- 显示Current Address长度 -->

   unsigned short PowerAddr=0x0012;//</PowerAddr><!-- 显示Power Address -->
    int PowerBytes = 4;//</PowerBytes><!-- 显示Power Address长度 -->

   unsigned short PowerCalAddr=0x0014;//</PowerCalAddr><!-- 计算Power Address -->
    int PowerCalBytes = 4;//</PowerCalBytes><!-- 计算Power  Address长度 -->

    bool EnableProtect = false;
  unsigned  short ProtectVolAddr=0x0020;//</ProtectVolAddr><!--over voltage:保护 Address -->
    int ProtectVolBytes = 2;//</ProtectVolBytes><!--over voltage:保护 Address长度 -->

   unsigned short ProtectCurAddr=0x0021;//</ProtectCurAddr><!--over current:保护 Address -->
    int ProtectCurBytes = 2;//</ProtectCurBytes><!--over voltage:保护 Address长度 -->

   unsigned short ProtectPowAddr=0x0022;//</ProtectPowAddr><!--过Power保护 Address -->
    int ProtectPowBytes = 4;//</ProtectPowBytes><!--过Power保护 Address长度 -->
   //  <!-- ----------------程控Setting-------------------------------- -->
   unsigned short  SetVolAddr=0x0030;//</SetVolAddr><!--SettingVoltage Address -->
    int SetVolBytes = 2;//</SetVolBytes><!--SettingVoltage AddressByte数 -->

   unsigned short   SetCurAddr=0x0031;//</SetCurAddr><!--SettingCurrentAddress -->
    int SetCurBytes = 2;//</SetCurBytes><!--SettingCurrentAddressByte数 -->

   unsigned short  SetTimeSpanAddr=0x0032;//</TimeSpanAddr><!--Setting时间Address -->
    int SetTimeSpanBytes = 2;//</SetTimeSpanBytes><!--Setting时间AddressByte数 -->
};

#endif // CHANNEL_H
