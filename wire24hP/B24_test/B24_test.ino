#include <LiquidCrystal.h>
#include <Servo.h>

const int rs=12, en=11, d4=5, d5=4, d6=3, d7=2;
LiquidCrystal lcd(rs,en,d4,d5,d6,d7);
Servo myservo;
int sensorPin = A0;
int sensorValue;

void write_angle_lcd(int pos){
  lcd.setCursor(0, 1);
  lcd.print(pos);
}

void setup(){
  myservo.attach(9);
  lcd.begin(16, 2);
  lcd.println("Analog Value : "); 
}
void loop(){  
  int pos;
  sensorValue = analogRead(sensorPin);
  lcd.setCursor(0, 1);
  lcd.print(sensorValue); 
  for(pos = 0; pos <= 180; pos += 1){
  myservo.write(pos);//u levo  
  delay(50);
  } 
  delay(1000);
  for(pos = 180; pos >= 0; pos -= 1){                       
  myservo.write(pos);//u desno
  delay(50);
  }
   
}
