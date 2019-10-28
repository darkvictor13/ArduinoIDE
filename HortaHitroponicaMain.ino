#include <WiFi.h>
#include <HCAM2315.h>
#include "SSD1306.h"

#define I2CADD 0x5C
#define pin_relay 5
#define pin_solo 36

const char* ssid  = "Horta IOT";
const char* password = "Iotehmtbom";

int temperatura,umidade,umidade_solo_porcentagem;

HCAM2315 HCAM2315(I2CADD);

WiFiServer server(80);

void setup() {
  Serial.begin(9600);
  pinMode(pin_solo,INPUT);
  pinMode(pin_relay, OUTPUT);
  WiFi.softAP(ssid, password);
  //IPAddress IP = WiFi.softAPIP();
  server.begin();
  HCAM2315.init();
}

void faz_uma_medicao_do_solo_retorna_porcentagem (int *solo) {
  *solo = map (analogRead (pino_sensor_solo),4095,1000,0,100);
}

void mede_temperatura_e_umidade_do_ar (int *temperatura,int *umidade) {
  if(HCAM2315.CheckCRC()){
    *temperatura = HCAM2315.Temp();
    *umidade =  HCAM2315.Hum(); 
  }else {
    Serial.println("Error");
  }
}

void loop() {
  
}
