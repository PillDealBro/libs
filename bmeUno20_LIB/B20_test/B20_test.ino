#include <LiquidCrystal.h>
const int rs=12,en=11,d4=5,d5=4,d6=3,d7=1;
LiquidCrystal lcd(rs,en,d4,d5,d6,d7);
int crvena_dioda1=6;
int crvena_dioda2=7;
int zelena_dioda=2;
const int left_sensorPin=A0;
const int right_sensorPin=A1;
int left_sensorState;
int right_sensorState;
void setup() {
  lcd.begin(16,2);
  lcd.setCursor(0,1);
  pinMode(crvena_dioda1,OUTPUT);
  pinMode(crvena_dioda2,OUTPUT);
  pinMode(zelena_dioda,OUTPUT);
  pinMode(right_sensorPin,INPUT);
  pinMode(left_sensorPin,INPUT);
}

void loop() {
  digitalWrite(crvena_dioda1,HIGH);
  digitalWrite(crvena_dioda2,HIGH);
  digitalWrite(zelena_dioda,HIGH);
  bool linija=digitalRead(right_sensorPin);
  bool linija2=digitalRead(left_sensorPin);
  if(linija==1)
    lcd.print("Jeste iznad linije");
  if(linija==0)
    lcd.print("Nije iznad linije");
  delay(2000);
}
