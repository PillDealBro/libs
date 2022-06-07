int led=13;
int senzor=3;
const int buzzer=13;
int stanje=LOW;
int val=0;

void setup() {
  pinMode(led,OUTPUT);
  pinMode(senzor,INPUT);
  pinMode(buzzer,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  val=digitalRead(senzor);
  if(val==HIGH)
  {
    digitalWrite(buzzer,HIGH);
    delay(1000);
    digitalWrite(led,HIGH);
  }
}
