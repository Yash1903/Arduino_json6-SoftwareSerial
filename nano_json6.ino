#include <ArduinoJson.h>
#include <SoftwareSerial.h>
SoftwareSerial mySerial(6, 7); // RX, TX


void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
mySerial.begin(115200);
Serial.println("Arduiniojson 6 SoftwareSerial From Nano To ESP8266 & This is Nano code.");
}

void loop() {
  // put your main code here, to run repeatedly:
 StaticJsonDocument<39> doc;
 doc["Gas_V"] = "228";
 doc["Distance_V"] = "220";

 char store[100];
 serializeJson(doc, store);
  serializeJson(doc, mySerial);
 Serial.println(store);
 delay(1000);
}
