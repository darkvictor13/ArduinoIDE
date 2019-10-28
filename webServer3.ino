#include <WiFi.h>
#include <WiFiServer.h>

WiFiServer servidor(80);
WiFiClient cliente;

String html;

void setup() {
  Serial.begin(9600);
  WiFi.mode(WIFI_STA);
  WiFi.begin("SmartPTI","SmartPT12017.");
  Serial.println(WiFi.localIP());
  servidor.begin();
  pinMode(2, OUTPUT);
}

void loop() {
  http();
}

void http()//Sub rotina que verifica novos clientes e se sim, envia o HTML.
{
   cliente = servidor.available();//Diz ao cliente que há um servidor disponivel.
 
   if (cliente == true)//Se houver clientes conectados, ira enviar o HTML.
   {
      String req = cliente.readStringUntil('\r');//Faz a leitura do Cliente.
      Serial.println(req);//Printa o pedido no Serial monitor.
 
      if (req.indexOf("/LED") > -1)//Caso o pedido houver led, inverter o seu estado.
      {
         digitalWrite(2, !digitalRead(2));//Inverte o estado do led.
      }
 
      html = "";//Reseta a string.
      html += "HTTP/1.1 Content-Type: text/html\n\n";//Identificaçao do HTML.
      html += "<!DOCTYPE html><html><head><title>ESP8266 WEB</title>";//Identificaçao e Titulo.
      html += "<meta name='viewport' content='user-scalable=no'>";//Desabilita o Zoom.
      html += "<style>h1{font-size:2vw;color:black;}</style></head>";//Cria uma nova fonte de tamanho e cor X.
      html += "<body bgcolor='ffffff'><center><h1>";//Cor do Background
 
      //Estas linhas acima sao parte essencial do codigo, só altere se souber o que esta fazendo!
 
      html += "<form action='/LED' method='get'>";//Cria um botao GET para o link /LED
      html += "<input type='submit' value='LED' id='frm1_submit'/></form>";
 
      html += "</h1></center></body></html>";//Termino e fechamento de TAG`s do HTML. Nao altere nada sem saber!
      cliente.print(html);//Finalmente, enviamos o HTML para o cliente.
      cliente.stop();//Encerra a conexao.
   }
}
