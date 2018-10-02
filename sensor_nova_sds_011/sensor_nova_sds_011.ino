
#include <SigFox.h>
#include <ArduinoLowPower.h>
#include <sds011_mkrfox.h>
#include "convert.h"

int debug = true;
int sdsWarmup = 15 * 1000;
int deepSleep = 15 * 60 * 1000;
 
SdsDustSensor sds(Serial1);
typedef struct __attribute__ ((packed)) sigfox_message {
  uint8_t status;
  int16_t moduleTemperature;
  uint16_t pm25;
  uint16_t pm10;
} SigfoxMessage;
SigfoxMessage msg;
 
void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  LowPower.attachInterruptWakeup(RTC_ALARM_WAKEUP, onWakeup, CHANGE);
 
  if (debug == true) {
    Serial.begin(9600);
    while (!Serial) {}
  }
 
  if (!SigFox.begin()) {
    if (debug == true) {
      Serial.println("Shield error or not present! Try reboot");
    }
    reboot();
  }
  if (debug == true) {
    printSigfoxInfo();
  }
  delay(100);
  //Send module to standby until we need to send a message
  SigFox.end();
 
  if (debug == true) {
    // Enable debug prints and LED indication if we are testing
    SigFox.debug();
  }
 
  sds.begin(); // this line will begin Serial1 with given baud rate (9600 by default)
  if (debug == true) {
    printSensorInfo();
  }
}
void loop() {
 
  if (debug == true) {
    digitalWrite(LED_BUILTIN, HIGH);
    delay(500);
  }
 
  querySensor();
  sendSigfox();
 
  if (debug == true) {
    digitalWrite(LED_BUILTIN, LOW);
    delay(deepSleep - sdsWarmup);
  } else {
    LowPower.sleep(deepSleep - sdsWarmup);
  }
}
void reboot() {
  NVIC_SystemReset();
  while (1);
}
 
void onWakeup() {
 
}
void sendSigfox() {
  SigFox.begin();
  delay(100);
 
  float temperature = SigFox.internalTemperature();
  msg.moduleTemperature = convertoFloatToInt16(temperature, 60, -60);
 
  SigFox.status();
  delay(1);
 
  SigFox.beginPacket();
  SigFox.write((uint8_t*)&msg, 6);
 
  int ret = SigFox.endPacket();
  SigFox.end();
 
  if (debug == true) {
    Serial.println("Temperature: " + String(temperature));
 
    if (ret > 0) {
      Serial.println("Transmisson failed: " + String(ret));
    } else {
      Serial.println("Transmission: OKay");
    }
  }
}
 
void querySensor() {
  msg.status = 0;
  msg.pm25 = convertoFloatToInt16(0, 1000, 0);
  msg.pm10 = convertoFloatToInt16(0, 1000, 0);
 
  sds.wakeup();
  delay(sdsWarmup); // working for some seconds
  PmResult pm = sds.queryPm();
  msg.status |= pm.rawStatus;
  if (pm.isOk()) {
    msg.pm25 = convertoFloatToInt16(pm.pm25, 1000, 0);
    msg.pm10 = convertoFloatToInt16(pm.pm10, 1000, 0);
 
    if (debug == true) {
      Serial.print(pm.pm25);
      Serial.print(" PM2.5, ");
      Serial.print(pm.pm10);
      Serial.println(" PM10");
    }
  } else {
    Serial.print("Could not read values from sensor, reason: ");
    Serial.print(pm.statusToString());
  }
 
  WorkingStateResult state = sds.sleep();
  if (state.isWorking()) {
    Serial.println(" Problem with sleeping the sensor.");
  } else {
    Serial.println(" Sensor is sleeping");
  }
}
 
void printSigfoxInfo() {
  String version = SigFox.SigVersion();
  String ID = SigFox.ID();
  String PAC = SigFox.PAC();
 
  // Display module informations
  Serial.println("MKRFox1200 Sigfox first configuration");
  Serial.println("SigFox FW version " + version);
  Serial.println("ID  = " + ID);
  Serial.println("PAC = " + PAC);
 
  Serial.println("");
 
  Serial.print("Module temperature: ");
  Serial.println(SigFox.internalTemperature());
 
  Serial.println("Register your board on https://backend.sigfox.com/activate with provided ID and PAC");
 
}
void printSensorInfo() {
  Serial.println();
  Serial.println("SDS011:");
  Serial.println(sds.queryFirmwareVersion().toString()); // prints firmware version
  Serial.println(sds.setQueryReportingMode().toString()); // ensures sensor is in 'query' reporting mode
  Serial.print("SDS011 warm up:");
  Serial.print(sdsWarmup);
  Serial.println(" mSec");
  Serial.print("Sending every: ");
  Serial.print(deepSleep);
  Serial.println(" mSec");
}
