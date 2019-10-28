#include <WiFi.h>

const char* ssid  = "Victor-Esp-32";
const char* password = "IotEhDaora";

WiFiServer server(80);

String header;

void setup() {
  Serial.begin(115200);
  Serial.print("Setting AP (Access Point)…");
  WiFi.softAP(ssid, password);
  IPAddress IP = WiFi.softAPIP();
  Serial.print("AP IP address: ");
  Serial.println(IP);

  server.begin();
}

void loop() {}
