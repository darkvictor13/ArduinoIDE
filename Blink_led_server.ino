#include <WiFi.h>
#include <WiFiClient.h> 
#include <WebServer.h>

#define LED 2 //Saida para o lED

String command;             //String que guarda o comando

const char* ssid = "Esp32DevKitV1"; //Nome da rede

WiFiServer server(80);

void setup() {
 
  Serial.begin(9600);
  
// Connecting WiFi

  WiFi.mode(WIFI_AP);
  WiFi.softAP(ssid);

  IPAddress myIP = WiFi.softAPIP();
  Serial.print("AP IP address: ");//Imprime no serial o ip do servidor - Entrar nesse ip pelo navegador
  Serial.println(myIP);
 
 // Starting WEB-server 
     server.on ( "/", HTTP_handleRoot );
     server.onNotFound ( HTTP_handleRoot );
     server.begin();  


   //PReparando as portas para Usar com o led
   pinMode(LED_BUILTIN, OUTPUT);
   pinMode(LED_BUILTIN, LOW);
   pinMode(LED, OUTPUT);
   digitalWrite(LED, LOW); 
}


void loop() {
    server.handleClient();
    
      command = server.arg("LED1");
      if (command == "L") 
        digitalWrite(LED, HIGH); 
      if (command == "D")
        digitalWrite(LED, LOW);
}

void HTTP_handleRoot(void) {
  
if( server.hasArg("LED1") ){
       Serial.println(server.arg("LED1"));
  }
  server.send ( 200, "text/html",  "<html> <form align=\"center\" method=\"SET\"> <input type=\"radio\" name=\"LED1\" value=\"L\"> Ligar LED <br> <input type=\"radio\" name=\"LED1\" value=\"D\"> Desligar LED<br>    <input type=\"submit\" value=\"Submit\" /> </form> </html>"  );
  delay(1);
}
