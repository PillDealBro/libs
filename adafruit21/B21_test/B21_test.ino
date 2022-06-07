#define temperatura A0
#define crvena_dioda 4
#define zelena_dioda 5

void setup() {
  pinMode(crvena_dioda,OUTPUT);
  pinMode(zelena_dioda,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int vrednostSenzora=analogRead(temperatura);
  float napon=vrednostSenzora*5/1023;
  Serial.print(napon);
  digitalWrite(crvena_dioda,HIGH);
  digitalWrite(zelena_dioda,LOW);
  delay(1000);
  digitalWrite(crvena_dioda,LOW);
  digitalWrite(zelena_dioda,HIGH);
  delay(1000);
  digitalWrite(crvena_dioda,LOW);
  digitalWrite(zelena_dioda,LOW);
}
