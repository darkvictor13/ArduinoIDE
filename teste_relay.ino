int in1 = 5;
void setup() {
  pinMode(in1, OUTPUT);
  digitalWrite(in1, HIGH);
}
void loop() {
  digitalWrite(in1, LOW);
  delay(3000);
  digitalWrite(in1, HIGH);
  delay(3000);
}

/*int porta = 7,d5 = 18;

void setup() {
  pinMode (d5,OUTPUT);
}

void loop() {
  digitalWrite (d5,LOW);
  Serial.println ("cheguei");
  delay (1000);
  digitalWrite (d5,HIGH);
  Serial.println ("cheguei2");
}*/
