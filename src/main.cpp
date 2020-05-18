#include <Arduino.h>
#include <WiFi.h>

char ssid[]="urssid";
char password[]="urpassword";
char servername[]="p4.zmail.in.net";
int status=WL_IDLE_STATUS;
WiFiClient client;

void setup() {
 Serial.begin(9600);
 Serial.println("Tryin' to connect");
 while (status != WL_CONNECTED){
   status=WiFi.begin(ssid, password);
   delay(10000);
 }
 Serial.println("Connected to WiFi");
 if (client.connect(servername, 80)){
   Serial.println("connected to site");
 };
 client.println("GET /v1/x4.html?device=3&event=2&status=1");
}

void loop() {
  // Если от сервера поступили данные, то
  // считываем их и выводим:
  if (client.available()) {
    char c = client.read();
    Serial.print(c);
  }

  // если соединение с сервером разорвано, то останавливаем клиент:
  if (!client.connected()) {
    Serial.println();
    Serial.println("disconnecting.");
    client.stop();

    // больше ничего не делаем:
    for(;;)
      ;
  }
}
