#include <SigFox.h>
#include <ArduinoLowPower.h>
#include <DHT.h>

#define DEBUG         true             // Set DEBUG to false to disable serial prints
#define DHTPIN        6                // What digital pin we're connected to
#define DHTTYPE       DHT22
#define DEEPSLEEP     15 * 60 * 1000   // Set the delay to 15 minutes (15 min x 60 seconds x 1000 milliseconds)

// create an instance of the sensor
DHT dht(DHTPIN, DHTTYPE);

// define the message payload to send via Sigfox
typedef struct __attribute__ ((packed)) sigfox_message {
  int16_t moduleTemperature;
  int16_t dhtTemperature;
  uint16_t dhtHumidity;
  uint8_t lastMessageStatus;
} SigfoxMessage;

// Stub for message which will be sent
SigfoxMessage msg;

// include some helpers to handle Sigfox convertion, printing module info and sending the message
#include "sigfox_tools.h"

void setup() {

  pinMode(LED_BUILTIN, OUTPUT);
  
  if (DEBUG) {
    Serial.begin(9600);
    while (!Serial) {}
  }

  if (!SigFox.begin()) {
    if (DEBUG) {
      Serial.println("Shield error or not present! Try reboot");
    }
    reboot();
  }
  if (DEBUG) {
    printSigfoxInfo();
  }
  delay(100);
  //Send module to standby until we need to send a message
  SigFox.end();
  if (DEBUG) {
    // Enable DEBUG prints and LED indication if we are testing
    SigFox.debug();
  }
  dht.begin();
}

void loop() {
  if (DEBUG) {
    digitalWrite(LED_BUILTIN, HIGH);
    delay(500);
  }

  querySensor();
  sendSigfoxMessage();

  if (DEBUG) {
    digitalWrite(LED_BUILTIN, LOW);
    delay(DEEPSLEEP);
  } else {
    LowPower.sleep(DEEPSLEEP);
  }
}
void querySensor() {
  // Reading temperature or humidity takes about 250 milliseconds!
  // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
  float h = dht.readHumidity();
  // Read temperature as Celsius (the default)
  float t = dht.readTemperature();
  // Check if any reads failed and exit early (to try again).
  if (isnan(h) || isnan(t)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  msg.dhtTemperature = convertoFloatToInt16(t, 60, -60);
  msg.dhtHumidity = convertoFloatToUInt16(h, 110);

  if (DEBUG) {
    Serial.print("Humidity: ");
    Serial.print(h);
    Serial.print(" %\t");
    Serial.print("Temperature: ");
    Serial.print(t);
    Serial.print(" *C ");
  }

}

void reboot() {
  NVIC_SystemReset();
  while (1) ;
}
