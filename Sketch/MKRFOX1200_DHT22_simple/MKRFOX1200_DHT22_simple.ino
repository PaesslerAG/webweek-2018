#include <SigFox.h>
 #include <SimpleDHT.h>
 #include <ArduinoLowPower.h>

 #define DHT22_PIN 6

 void setup() {
   Serial.begin(9600);
   pinMode(LED_BUILTIN, OUTPUT);
 }

 void blink(unsigned int count, unsigned long ms){
   for(int i=0; i<count; i++){
     digitalWrite(LED_BUILTIN, HIGH);
     delay(ms);
     digitalWrite(LED_BUILTIN, LOW);    
     delay(ms);
   }
 }

 void send_data(){
   // initialize sigfox module
   SigFox.begin();
   delay(100);

   // Enable debug led and disable automatic deep sleep
   SigFox.debug();

   // clears all pending interrupts
   SigFox.status();
   delay(1);

   // define sigfox payload data structure
   struct data{
     float temp;
     float hum;
   };

   // read temperature and humidity from DHT sensor connected at pin DHT11_PIN
   SimpleDHT11 dht22;
   byte temp, hum;
   dht22.read(DHT22_PIN, &temp, &hum, NULL);

   // NOTE! it is not quite efficient sending bytes as floats over the net, but this is just for illustrative purposes
   struct data reading;
   reading.temp = temp;
   reading.hum = hum;

   // send the structure to sigfox (8 bytes)
   Serial.println("Sending SigFox message!");

   // start a packet
   SigFox.beginPacket();

   // write our buffer
   SigFox.write((const char*)&reading, sizeof(reading));

   // send buffer to SIGFOX network
   int ret = SigFox.endPacket();  
   if (ret > 0) {
     Serial.println("No transmission");
     // 3 quick blink on error
     blink(3, 500);
   } else {
     Serial.println("Transmission ok");
     // 1 blink on success
     blink(1, 1000);
   }

   SigFox.end();
 }

 void loop() {
   send_data();
//   delay(10*60*1000);
   // you can deep sleep the device if you want
   LowPower.sleep(10*60*1000);
 }
