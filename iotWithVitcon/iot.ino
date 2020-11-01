#include <U8g2lib.h>
#include "DHT.h"

U8G2_SH1106_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, U8X8_PIN_NONE);
#define DHTPIN A1
#define DHTTYPE DHT22

DHT dht(DHTPIN, DHTTYPE);

#include "VitconMQTTComm.h"

using namespace vitcon;

/* A set of definition for MQTT items */
#define ITEMCOUNT 4

MQTTItem Analog0("A0");
MQTTItem Analog1("A1");
MQTTItem Analog2("A2");
MQTTItem Analog3("A3");

MQTTItem *Items[ITEMCOUNT] = { &Analog0, &Analog1, &Analog2, &Analog3 };
/* A set of definition for MQTT items */

//MQTT communication manager
MQTTComm comm(&Serial, Items, ITEMCOUNT);

//Subscribe callback function
void Subscribe(const char* topic, const char* data)
{
  String gettopic = String(topic);
  String getdata = String(data);
  
  if (gettopic.indexOf("/D2") != -1)
  {
    int num = getdata.toInt();
    if (num == 1 ) digitalWrite(2, HIGH);
    else if ( num == 0 )digitalWrite(2, LOW);
  }
  else if (gettopic.indexOf("/D3") != -1)
  {
    int num = getdata.toInt();
    if (num == 1 ) digitalWrite(3, HIGH);
    else if ( num == 0 )digitalWrite(3, LOW);
  }
  else if (gettopic.indexOf("/D4") != -1)
  {
    int num = getdata.toInt();
    if (num == 1 ) digitalWrite(4, HIGH);
    else if ( num == 0 )digitalWrite(4, LOW);
  }
  else if (gettopic.indexOf("/D5") != -1)
  {
    int num = getdata.toInt();
    if (num == 1 ) digitalWrite(5, HIGH);
    else if ( num == 0 )digitalWrite(5, LOW);
  }
  else if (gettopic.indexOf("/D6") != -1)
  {
    int num = getdata.toInt();
    if (num == 1 ) digitalWrite(6, HIGH);
    else if ( num == 0 )digitalWrite(6, LOW);
  }
  else if (gettopic.indexOf("/D7") != -1)
  {
    int num = getdata.toInt();
    if (num == 1 ) digitalWrite(7, HIGH);
    else if ( num == 0 )digitalWrite(7, LOW);
  }
  else if (gettopic.indexOf("/D8") != -1)
  {
    int num = getdata.toInt();
    if (num == 1 ) digitalWrite(8, HIGH);
    else if ( num == 0 )digitalWrite(8, LOW);
  }
  else if (gettopic.indexOf("/D9") != -1)
  {
    int num = getdata.toInt();
    if (num == 1 ) digitalWrite(9, HIGH);
    else if ( num == 0 )digitalWrite(9, LOW);
  }
}

void setup() {
  dht.begin();
  u8g2.begin();
  
  comm.Init();
  comm.SetSubscribe(Subscribe);

  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
}

void loop() {
  action();
  OLEDdraw();
}

void action(){
  delay(2000);
  Analog0.Set(analogRead(A0));
  Analog1.Set(analogRead(A1));
  int a3 = analogRead(A3);
  int a4 = analogRead(A4);

  if ( a3 > 500 ) Analog2.Set("HIGH");
  else if (a3 < 500) Analog2.Set("LOW");
  if ( a4 > 500 ) Analog3.Set("HIGH");
  else if (a4 < 500) Analog3.Set("LOW");

  comm.Run();  
}

void OLEDdraw(){
  u8g2.clearBuffer();

  u8g2.setFont(u8g2_font_ncenB08_te);
  u8g2.drawStr(1,15, "SMART FRAM");
  u8g2.drawStr(15,46, " - JAMES FLUTTER");
  u8g2.sendBuffer();
}
