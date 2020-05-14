#include <Arduino.h>
#include <WiFi.h>

char ssid[]="ChEM1234";
char password[]="738Rus4888";
char servername[]="google.com";
int status=WL_IDLE_STATUS;
WiFiClient client;

void setup() {
 Serial.begin(9600);
 Serial.print("Tryin' to connect");
 while (status != WL_CONNECTED){
   status=WiFi.begin(ssid, password);
   delay(10000);
 }
 Serial.println("Connected");
 if (client.connect(servername, 80)){
   Serial.println("connected to site");
 }
}

void loop() {
  // put your main code here, to run repeatedly:
}
