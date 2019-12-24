#include "Device.h"


Device::Device(  ModBusComInfo * mbsCom)
{
   DevCom=mbsCom;
}
/// <summary>
        // 分配缓冲------------------------------------------------------------------------------------------
/// </summary>
///
bool Device::AllocateDevicePriBuff()
        {
            if (WriteSRegCommand == nullptr)
                WriteSRegCommand = new uchar[WBuffHeadLength + AddressLength + AddressLength + CRCLength];
            if (WriteSRegRecviByte == nullptr)
                WriteSRegRecviByte = new uchar[_msize(WriteSRegCommand)];
            // { WsModbusComInfo.HostAddress, (byte)DeviceRWFunction.WriteSReg, beginAddrsByte[1], beginAddrsByte[0], wDataByte[1], wDataByte[0] };
            if (ReadSRegCommand == nullptr)
                ReadSRegCommand = new uchar[WBuffHeadLength + AddressLength + AddressLength + CRCLength];
            if (ReadSRegRecviByte == nullptr)
                ReadSRegRecviByte = new uchar[RBuffHeadLength + AddressLength + CRCLength];
            ///控制VoltageCurrent线程专用
            return true;
        }
  bool Device::AllocateDeviceBuff()
        {

           //监控数据缓冲
            if (GetVCPSendCommand==nullptr)
                GetVCPSendCommand = new uchar[WBuffHeadLength + AddressLength +AddressLength + CRCLength];

            if (GetVCPRecviByte==nullptr)
                GetVCPRecviByte = new uchar[RBuffHeadLength + ProtectVolBytes + ProtectCurBytes + ProtectPowBytes + CRCLength];
          //over current:over voltage:过Power缓冲
            if (GetOCPSendCommand==nullptr)
                GetOCPSendCommand = new uchar[WBuffHeadLength + AddressLength + AddressLength + CRCLength];
            if (GetOCPRecviByte == nullptr)
                GetOCPRecviByte = new uchar[RBuffHeadLength +ProtectVolBytes +ProtectCurBytes + ProtectPowBytes + CRCLength];
             //   { WsModbusComInfo.HostAddress, (byte)DeviceRWFunction.ReadMReg, getaddreHbyte((int)RegAddress.Voltage), getaddreLbyte((int)RegAddress.Voltage), 0x00, 0x04 };

            if (WriteControlCommand == nullptr)
               WriteControlCommand = new uchar[WBuffHeadLength + AddressLength + AddressLength + CRCLength];
            if (WriteControlRecviByte == nullptr)
               WriteControlRecviByte = new uchar[_msize(WriteSRegCommand)];
           // if (SetShortCutKeyCommand==null)
          //      SetShortCutKeyCommand=new byte[WBuffHeadLength + AddressLength + AddressLength + CRCLength];
          //  if (SetShortCutKeyRecviByte==null)
         //       SetShortCutKeyRecviByte = new byte[RBuffHeadLength + VoltageBytes + CRCLength];//
            if (ReadSCKVolRecviByte == nullptr)
                ReadSCKVolRecviByte = new uchar[RBuffHeadLength + shortCutList.VoltageBytes + CRCLength];//;
            if (ReadSCKCurrRecviByte == nullptr)
            {
                ReadSCKCurrRecviByte = new uchar[RBuffHeadLength + shortCutList.CurrentBytes + CRCLength];
            }
            if (ReadSCKSpanTimeRecviByte==nullptr)
            {
                ReadSCKSpanTimeRecviByte = new uchar[RBuffHeadLength + shortCutList.TimeSpanBytes + CRCLength];
            }
            if (ReadSCKSpanEnableBytes == nullptr)
            {
                ReadSCKSpanEnableBytes = new uchar[RBuffHeadLength + shortCutList.EnableBytes + CRCLength];
            }
            return true;
        }
        //修改Address后要重新Setting采集发送数据
void Device::AddCRCToArrayLast(uchar *targetData)
{
    uchar sHCRCBit;
    uchar sLCRCbit;
    ModbusCRC::CRC16Calc(targetData,_msize(targetData)-2,sHCRCBit,sLCRCbit);

}
