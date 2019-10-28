#include "SSD1306.h"
#include <Wire.h>

SSD1306  display(0x3c, 21, 22);

void setup() {
  display.init();
  display.drawString(0, 0, "Hello World");
  display.display();
}

void loop() {
  // put your main code here, to run repeatedly:

}
