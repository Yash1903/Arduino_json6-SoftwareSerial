#include <ArduinoJson.h>
#include <SoftwareSerial.h>
SoftwareSerial swSer(14, 12, false, 256); //Rx,Tx


void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
swSer.begin(115200);
Serial.println("Arduiniojson 6 SoftwareSerial From Nano To ESP8266 & This is ESP8266 code.");
}

void loop() {
  if (swSer.available()) 
  {
    // Allocate the JSON document
    // This one must be bigger than for the sender because it must store the strings
    StaticJsonDocument<100> doc;

    // Read the JSON document from the "link" serial port
    DeserializationError err = deserializeJson(doc, swSer);

    if (err == DeserializationError::Ok) 
    {
      char buffer[100];
      serializeJson(doc, buffer);
      Serial.println(buffer);
}
  }
}
