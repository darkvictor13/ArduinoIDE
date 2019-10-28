#include <HCAM2315.h>

#define I2CADD 0x5C

#define pino_sensor_solo 36

#define pin_controla_raley 5//digitalWrite(pin_controla_raley, HIGH); liga relay

HCAM2315 HCAM2315(I2CADD);

int temperatura,umidade,umidade_solo_porcentagem;

void setup() {
  Serial.begin(9600);
  pinMode (pino_sensor_solo,INPUT);
  pinMode(pin_controla_raley, OUTPUT);
  HCAM2315.init();
}

void faz_uma_medicao_do_solo_retorna_porcentagem (int *solo) {
  //int aux;
  //aux = analogRead (pino_sensor_solo);
  //*solo = map (aux1,1000,4095,0,100);
  *solo = map (analogRead (pino_sensor_solo),4095,1000,0,100);
}

void mede_temperatura_e_umidade_do_ar (int *temperatura,int *umidade) {
  if(HCAM2315.CheckCRC()){
    *temperatura = HCAM2315.Temp();
    *umidade =  HCAM2315.Hum(); 
  }else {
    Serial.println ("Deu errado essa medicao ae mano ;-;");
  }
}

void loop() {
  HCAM2315.Read();
  
  faz_uma_medicao_do_solo_retorna_porcentagem (&umidade_solo_porcentagem);
  
  mede_temperatura_e_umidade_do_ar (&temperatura,&umidade);
  
  if (umidade_solo_porcentagem <= 20) {
    digitalWrite(pin_controla_raley, HIGH);
  }else {
    digitalWrite(pin_controla_raley, LOW);
  }
  if(HCAM2315.CheckCRC()){
  Serial.print ("umidade solo = ");
  Serial.println (umidade_solo_porcentagem);
  Serial.print ("umidade ar = ");
  Serial.println (umidade);
  Serial.print("temperatura ar = ");
  Serial.println (temperatura);
  }
  delay (3000);
  
}
