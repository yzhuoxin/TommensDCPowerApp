#ifndef DEVICE_H
#define DEVICE_H
#include "ModBusComInfo.h"
#include "Channel.h"
#include "ShortCutKeyList.h"
#include "ModbusCRC.h"

class Device:public QObject
{
public:
    Device(  ModBusComInfo * mbsCom);
public:
    enum  DeviceStat
       {
           UnInit = 1,
           Initialized=2,
           Running=4,

           lineError=8,


       };
    Q_ENUM(DeviceStat)
    enum  StatON_OFF
    {
      ON=0x01,
      OFF=0x00,
      UnKnown=0x02,
    };
  Q_ENUM(StatON_OFF)
public:
  //机器对应的Modbus 端口指针
     ModBusComInfo * DevCom;
     //暂时保留
     QList<Channel *> channellist;
     //通道数
      ShortCutKeyList  shortCutList;
     int channelCount=1;
     //设备硬件地址
     unsigned char hostaddress;

      //     ShortCutKeyList WsShortCutKeyList=new ShortCutKeyList();
       //    AutoControlList WsAutoControlList=new AutoControlList();


           //设备字长16位 长度 2个Byte ，32位 4个Byte，默认16位。

          bool ifGetDeviceData = false;
          bool EnableProgram=false;
          QString  DeviceClassName="";
           //类型模版和快捷键模板 ID
          QString ShortCutKeyTID="";
          QString DeviceClassTID="";
          uint ShowBit = 3;
          uint AddressLength = 2;//Address字长
         unsigned short PowerSwitchAddr=0x0001; //<!-- 设备开关Address -->
          uint PowerSwitchBytes = 2;//<!-- 设备开关Address长度 -->

         unsigned short ProtectStatAddr=0x0002;//</ProtectStatAddr><!-- 保护状态Address -->
          uint ProtectStatBytes = 2;//</ProtectStatBytes>><!-- 保护状态Address长度 -->

         unsigned short  ModelAddr=0x0003;//</ModelAddr><!-- 规格型号Address -->
          uint ModelBytes = 2;//<!-- 规格型号Address长度 -->

         unsigned short  ClassDetialAddr=0x0004;//</ClassDetialAddr><!-- 分类尾缀Address -->
          uint ClassDetialBytes = 2;//</ClassDetialBytes><!-- 分类尾缀Address长度 -->

         unsigned short DecimalsAddr=0x0005;//</DecimalsAddr><!-- 小数点位数Address -->
          uint DecimalsBytes = 2;//</DecimalsBytes><!-- 小数点位数长度 -->

          unsigned short VoltageAddr=0x0010;//</VoltageAddr> <!-- 显示Voltage Address -->
          uint VoltageBytes = 2;//</VoltageBytes> <!-- 显示Voltage Address长度 -->

         unsigned short CurrentAddr=0x0011;//</CurrentAddr><!-- 显示Current Address -->
          uint CurrentBytes = 2;//</CurrentBytes><!-- 显示Current Address长度 -->

         unsigned short PowerAddr=0x0012;//</PowerAddr><!-- 显示Power Address -->
          uint PowerBytes = 4;//</PowerBytes><!-- 显示Power Address长度 -->

         unsigned short PowerCalAddr=0x0014;//</PowerCalAddr><!-- 计算Power Address -->
          uint PowerCalBytes = 4;//</PowerCalBytes><!-- 计算Power  Address长度 -->

          bool EnableProtect = false;
        unsigned  short ProtectVolAddr=0x0020;//</ProtectVolAddr><!--over voltage:保护 Address -->
          uint ProtectVolBytes = 2;//</ProtectVolBytes><!--over voltage:保护 Address长度 -->

         unsigned short ProtectCurAddr=0x0021;//</ProtectCurAddr><!--over current:保护 Address -->
          uint ProtectCurBytes = 2;//</ProtectCurBytes><!--over voltage:保护 Address长度 -->

         unsigned short ProtectPowAddr=0x0022;//</ProtectPowAddr><!--过Power保护 Address -->
          uint ProtectPowBytes = 4;//</ProtectPowBytes><!--过Power保护 Address长度 -->
         //  <!-- ----------------程控Setting-------------------------------- -->
         unsigned short  SetVolAddr=0x0030;//</SetVolAddr><!--SettingVoltage Address -->
          uint SetVolBytes = 2;//</SetVolBytes><!--SettingVoltage AddressByte数 -->

         unsigned short   SetCurAddr=0x0031;//</SetCurAddr><!--SettingCurrentAddress -->
          uint SetCurBytes = 2;//</SetCurBytes><!--SettingCurrentAddressByte数 -->

         unsigned short  SetTimeSpanAddr=0x0032;//</TimeSpanAddr><!--Setting时间Address -->
          uint SetTimeSpanBytes = 2;//</SetTimeSpanBytes><!--Setting时间AddressByte数 -->


   //<!-- ------------------------------------------------------------------------- -->

   //<!-- ------------------------------------------------------------------------- -->
          unsigned short PowerStatAddr=0x8801;//</PowerStatAddr><!-- 设备开机状态Address -->
          uint    PowerStatBytes = 2;//</PowerStatBytes><!-- 设备开关Address长度 -->

          unsigned short defaultShowAddr=0x8802;//</defaultShowAddr><!-- 预设值显示Address -->
          uint defaultShowBytes = 2;//</defaultShowBytes><!-- 预设值显示Address长度 -->

          unsigned short SCPAddr=0x8803;//</SCPAddr><!-- 短路Current保护Address -->
          uint    SCPBytes = 2;//</SCPBytes><!-- 短路Current保护Address长度 -->


          unsigned short BuzzerAddr=0x8804;//</BuzzerAddr><!-- 蜂鸣器Address -->
          uint BuzzerBytes = 2;//</BuzzerBytes><!-- 蜂鸣器Address长度 -->

          unsigned short DeviceAddr=0x9999;//</DeviceAddr><!-- 设备Address -->
          uint DeviceBytes = 2;//</DeviceBytes><!-- 设备Address长度 -->

          unsigned short SDTimeAddr=0xCCCC;//</SDTimeAddr><!-- SDTimeAddress -->
          uint SDTimeBytes = 2;//</SDTimeBytes><!-- SDTimeAddress长度 -->




          //----------------------------------------------------------------------------------缓冲
          uint WBuffHeadLength = 2;
          uint RBuffHeadLength = 3;
          uint CRCLength = 2;
          uint VCPDataCount = 4;
          uint OCPDataCount = 4;
          uint OneRegsiterLen = 1;

           uchar * GetVCPSendCommand;
           uchar * GetVCPRecviByte;

           uchar * GetOCPSendCommand;
           uchar * GetOCPRecviByte;

           uchar * sSetShortCutKeyCommand;
           uchar * ReadShortCutKeyCmd;
           uchar * SSetShortCutKeyRecviByte;
           uchar * ReadSCKVolRecviByte;
           uchar * ReadSCKCurrRecviByte;
           uchar * ReadSCKSpanTimeRecviByte;
           uchar * ReadSCKSpanEnableBytes;
          //写单个数据
           uchar * WriteSRegCommand;
           uchar * WriteSRegRecviByte;
          //读单个数据 缓冲
           uchar * ReadSRegCommand;
           uchar * ReadSRegRecviByte;
          //写单个数据
           uchar * WriteControlCommand;
           uchar * WriteControlRecviByte;
      //------------------------------------------------------------------------------------//
          bool iFWriteLog = true;//是否写日志,初始化 写日志

           int errorCount = 0;//连续读写错误次数,如果中间有一次对 ，清零
           int maxErrorCount = 5;//最大连续读写错误，超过这个数，重新关闭端口
           int totalErrorCount = 0;

           bool mlineError = false;//线路出错

           //
           bool tstop = false;//是否停止线程
           //暂时控制
           bool autoPause = false;
            bool  autoStop = false;
           //机器和线程状态
          // DeviceStat WSDeviceStat=DeviceStat.UnKnown;



           //接收到 型号
           QString rClassID;
           //型号尾缀
           QString rModelID;

           QString ClassTitle="";
           QString ModelTitle="";
           //十进制数放大 倍数，比如数据 位数是小数点两位，既要放大10*10=100，三位要放大10*10*10=1000
           int VolMultTen = 100;
           int CurrMultTen = 100;
           int PowMultTen = 100;
           //开关状态，初始化 未知
            short rDeviceStat =short(StatON_OFF::UnKnown);

           //接收到 Current，Voltage，Power
           float rVoltage=0;//Voltage
           float rCurrent=0;//Current
           float rPower=0;//Power
           //转化成 16位无符号数
            int32_t rUVoltage = 0;//Voltage
            int  rUCurrent = 0;//Current
           int  rUPower=0;//Power

           //最大 保护值
            float MaxVoltage = 0;
           float MaxCurrent = 0;
            float MaxPower = 0;
           //读到 over voltage:保护值
           float rOVPVoltage=0;
           float rOCPCurrent=0;
           float rOPPower=0;
private:
           void AddCRCToArrayLast(uchar *targetData);

           bool AllocateDevicePriBuff();
           bool AllocateDeviceBuff();

};

#endif // DEVICE_H
