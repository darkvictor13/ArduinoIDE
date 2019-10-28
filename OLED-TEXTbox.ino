#include <FTOLED.h>

OLED oled(pin_cs, pin_dc, pin_reset);

OLED_TextBox text(oled);

void setup() {
  Serial.begin(115200);
  oled.begin();
}

void loop() {
  text.println("Something here");
  delay(1000);
  text.clear();
  text.println("Replaced with this");
}
