#define pino_sensor 36

int valor,valor_porcentagem;

void setup() {
  Serial.begin(9600);
  pinMode (pino_sensor,INPUT);
}

void loop() {
  valor = analogRead (pino_sensor);
  valor_porcentagem = map (valor,4095,1000,0,100);
  Serial.print("Umidade = ");
  Serial.println(valor_porcentagem);
  delay (1000);
}
