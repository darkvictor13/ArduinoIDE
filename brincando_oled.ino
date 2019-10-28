//#include <fonts/SystemFont5x7.h>
#include "SSD1306.h"
#include <Wire.h>

SSD1306  display(0x3c, 21, 22);

int i;

void setup() {
  display.init();
  display.clear();

}

void loop() {
  for (i = 0; i < 10; i++) {
    display.drawString(i, 64, "Fui para proxima linha");
    delay (2000);
  }
}
