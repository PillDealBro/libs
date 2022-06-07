#include <LiquidCrystal.h>
#include <Servo.h>

const int rs=12, en=11, d4=5, d5=4, d6=3, d7=2;
LiquidCrystal lcd(rs,en,d4,d5,d6,d7);
Servo myservo;
int sensorPin = A0;
int sensorValue;
int brojac=0;

void setup(){
  myservo.attach(9);
  lcd.begin(16, 2);
}
void loop(){
  sensorValue=analogRead(sensorPin);
  if(sensorValue<900)
  {
    lcd.clear();   
    lcd.print("MOKRA ZEMLJA");
    delay(5000);     
    brojac=0;
  }
  else
  {
    if(brojac==0)
    {   
    myservo.write(30);
    delay(1000);
    myservo.write(150);
    brojac++;
    }
    lcd.clear(); 
    lcd.print("SUVA ZEMLJA"); 
  }
  //Serial.begin(9600);
  //Serial.print(sensorValue);
}
