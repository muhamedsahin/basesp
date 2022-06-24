#include <SoftwareSerial.h>
SoftwareSerial esp(9, 10);
String delimiter = "/9j/";
String asd = "";
String img = "";
void setup() {
  Serial.begin(9600);
  esp.begin(9600);
}

void loop() {
  if (asd.lastIndexOf(delimiter) > 1) {
    Serial.println(asd.substring(asd.indexOf(delimiter), asd.lastIndexOf(delimiter)));
    asd = asd.substring(asd.lastIndexOf(delimiter), asd.length());
  }
  while (esp.available() > 0) {
    char inByte = esp.read();
    Serial.write(inByte);
    asd += inByte;
  }
  
  for(int i = 0; i<18; i++)
  {
  Serial.println(String(Serial.read()));
  img = img+String(Serial.read());
  }
  Serial.println(img);
}
