
#include <Arduino.h>

class M5Stack_UNIT_LoRaWAN
{
private:
    //HardwareSerial *_serial;
    Stream* deviceSerial;
public:
    //void Init(HardwareSerial *serial = &Serial2, uint8_t RX = 16, uint8_t TX = 17);
    void Init(Stream &serial);
    String waitMsg(unsigned long time);
    bool checkDeviceConnect();
    bool checkJoinStatus();
    void writeCMD(String command);
    void configOTTA(String device_eui, 
                    String app_eui, 
                    String app_key,
                    String ul_dl_mode);
    void configABP(String device_addr, 
                    String app_skey,
                    String net_skey,
                    String ul_dl_mode);
    void setClass(String mode);
    void setRxWindow(String freq);
    void setFreqMask(String mask);
    void startJoin();
    void sendMsg(uint8_t confirm, uint8_t nbtrials, size_t length, String data);
    String receiveMsg();
};
