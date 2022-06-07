#include <LiquidCrystal.h>

const int rs=12,en=11,d4=5,d5=4,d6=3,d7=1;
LiquidCrystal lcd(rs,en,d4,d5,d6,d7);
int cd1=6;
int cd2=7;
int zd=2;
int sensorLin1=8;
int sensorLin2=9;

void setup() {
  lcd.begin(16,2);
  pinMode(cd1,OUTPUT);
  pinMode(cd2,OUTPUT);
  pinMode(zd,OUTPUT);
  pinMode(sensorLin1,INPUT);
  pinMode(sensorLin2,INPUT);
  digitalWrite(cd1,LOW);
  digitalWrite(cd2,LOW);
  digitalWrite(zd,LOW);
}

void loop() {
  digitalRead(sensorLin1);
  digitalRead(sensorLin2);
  bool linija=digitalRead(sensorLin1);
  bool linija2=digitalRead(sensorLin2);
  if(linija==0 || linija2==0)
  {
    if(linija==1)
      digitalWrite(cd1,HIGH);
    else if(linija2==1)
      digitalWrite(cd2,HIGH);
    lcd.clear();
    lcd.print("Los pravac");
  }
  if(linija==0 && linija2==0)
  {
    lcd.clear();
    lcd.print("Dobar pravac");
    digitalWrite(zd,HIGH);
  }
  if(linija==1 && linija2==1)
  {
    lcd.clear();
    lcd.print("STOJ!");
    digitalWrite(cd1,HIGH);
    digitalWrite(cd2,HIGH);
  }
  delay(2000);
}
