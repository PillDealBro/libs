#include <LiquidCrystal.h>

const int rs=12,en=11,d4=5,d5=4,d6=3,d7=1;
LiquidCrystal lcd(rs,en,d4,d5,d6,d7);
int taster=2;
void setup()
{
  lcd.begin(16,2);
  lcd.print("Dobar dan");
  pinMode(taster,INPUT);
  attachInterrupt(digitalPinToInterrupt(2),tekst,FALLING);
}
void tekst()
{
  lcd.clear();
  lcd.print("Zdravo");
}
void loop()
{
  
}
