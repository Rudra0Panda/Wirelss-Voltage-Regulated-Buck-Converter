#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <ESPAsyncTCP.h>
#include <ESPAsyncWebServer.h>

const char* ssid  = "Airtel_Xtreme_2.4";
const char* password = "B3bnpaxg@612";

int changePWM(int pinNO, int Brightness){
  
  int scaledBrightNess = 0;

  if (Brightness > 0){
    scaledBrightNess = map(Brightness, 0, 100, 0, 1023);
  }

  analogWrite(pinNO, scaledBrightNess);
  return 0;
}

void setup() {

  Serial.begin(115200);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED){
    delay(500);
    Serial.print(".");
  }

  Serial.println("\nConnected");
  Serial.println(WiFi.localIP());

  pinMode(D1, OUTPUT);
}

void loop(){

  changePWM(D1, 50);   // 50% brightness
  delay(2000);

  changePWM(D1, 100);  // 100% brightness
  delay(2000);
}