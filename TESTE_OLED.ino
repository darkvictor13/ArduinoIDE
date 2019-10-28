#include "SSD1306.h"
#include <Wire.h>
//#include <fonts/SystemFont5x7.h>

SSD1306  display(0x3c, 21, 22);

int i,j;
char str [] = "1 linha",str_aux[3],aux;
 
void setup() {
  //oled.selectFont(Arial_Black_16);
  display.init();
  display.drawString(0, 0, "programa para Contagem \nde linhas\nVamos comecar???");
  display.display();
  delay (4000);
}
 
void loop() {
  display.init();
  /*display.drawString(0, 0, "Printa uma linha\n");
  display.display();
  delay (1000);
  display.drawString(0, 8, "Segunda linha\n");//8 pixels e ctz que uma letra nao encosta na outra 
  display.display();
  delay (1000);
  display.drawString(0, 16, "01234567890123456789012345678901234567890\n");
  display.display();
  delay (1000);*/
    display.drawString(0, i,"esta eh a");
    display.drawString(48, i,str);
    display.display();
    i += 8;
    str[0]++;
    delay (1000);
    if (i >= 56){
      display.init();
      display.drawString(0, 0, "Programa terminou ;-;\nRenicie em :\n5 segundos\n");
      display.display();
      delay (1000);
      for (i = 24,j = 0;j < 4 ; i += 8,j++) {
        aux = j;
        str_aux[0] = aux; 
        display.drawString(i, 0, str_aux);
        display.display();
        delay (1000);
      }
    }
      //https://www.filipeflop.com/blog/relogio-com-esp32-e-oled-com-servidor-ntp/
}
