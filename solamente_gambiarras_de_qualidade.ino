#include "SSD1306.h"
 
SSD1306 display(0x3c, 21, 22);

int i = 0;
char str [] = "Umidade = X%",aux = '1';

void setup() {
Serial.begin(115200);
display.init();
display.clear();
}
 
void loop() {
  //(x0, y0, x1, y1)
  display.drawRect(0, 0, 128, 64);
  display.setFont(ArialMT_Plain_16);

  for (; i < 9; i++,aux++) {

    str[10] = aux;
    display.drawString(5, 1, "Esp32 informa :");
    display.drawString(5, 17, str);
    display.display();
    delay (1000);
    display.clear();
    display.drawRect(0, 0, 128, 64);
    if(i == 9)break;
  }
  display.clear();
  display.setFont(ArialMT_Plain_24);
  display.drawString(0, 0, "Programa encerrado\n acho q funciona\n =)");
}
