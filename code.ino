#define BLYNK_PRINT Serial
#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>
char auth[]="";
char ssid[]="";
char pass[]="";
BLYNK_WRITE(V1)
{
  int pinValue = param.asInt();
  digitalWrite(2,pinValue);
  if(pinValue==1){
    Serial.println("ON");
  }
  if(pinValue==0)
  {
    Serial.println("OFF");
  }
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Blynk.begin(auth,ssid,pass);
  pinMode(2, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  Blynk.run();
}
