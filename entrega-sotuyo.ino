#include "SSD1306.h"//biblioteca do Oled

//pinos usados no esp
#define pin_relay 13//5
#define pin_solo 15//36
#define scl 5//22
#define sda 18//21
#define umidade_solo_minima 20.1

float umidade_solo_porcentagem;
int erro;

SSD1306 display(0x3c, sda, scl);

void inicializacao () {
  display.setFont(ArialMT_Plain_24);
  display.drawRect(0, 0, 128, 64);
  display.drawString(2, 15, "  Iniciando");
  display.display();
  delay (1000);
  for (int i = 20; i <= 108; i++) {
    display.drawString(i, 32, ".");
    display.display();
    delay (25);
  }
}

void setup() {
  Serial.begin(9600);
  pinMode(pin_solo,INPUT);
  pinMode(pin_relay, OUTPUT);
  display.init();//inicia o display do oled
  display.setFont(ArialMT_Plain_24);
  display.drawRect(0, 0, 128, 64);
  display.drawString(8, 12, "Bienvenue\n");
  display.display();
  delay (3000);
  display.clear();
  inicializacao();
  display.clear();
  display.setFont(ArialMT_Plain_16);//define a fonte e o tamanho
}

void medeUmidadeDoSoloSalvaEmPorcentagem () {
  umidade_solo_porcentagem = map (analogRead (pin_solo),4095,1000,0,100);
}

void verificaErros () {
  if (umidade_solo_porcentagem <= umidade_solo_minima) {//valor de humidade do solo que a planta acha ruim
    erro = 1;
  }else {
    erro = 0;
  }
}

void MostraParaUsuario() {//faz exatamente oq o nome fala =)
  if (erro) {
    display.clear();
    display.setFont(ArialMT_Plain_24);
    display.drawRect(0, 0, 128, 64);
    display.drawString(2,10,"  Irrigando\n");
    display.display();
    delay (100);
    display.setFont(ArialMT_Plain_16);
    display.drawString(8,37," umidade baixa\n");
    display.display();//faz todos os comandos aparecerem no oled
  }else {
    display.clear();
    display.setFont(ArialMT_Plain_24);
    display.drawRect(0, 0, 128, 64);
    display.drawString(0,5,"  Aqumatic  \n  Saudável\n");
    display.display();
  }
}

void realizaAcoes () {
  if (erro) {
    digitalWrite(pin_relay, HIGH);
  }else {
    digitalWrite(pin_relay, LOW);
  }
}

void loop() {
  medeUmidadeDoSoloSalvaEmPorcentagem();
  verificaErros();
  realizaAcoes();
  MostraParaUsuario();
  delay(3000);
}
