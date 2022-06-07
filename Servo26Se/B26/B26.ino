#include <LiquidCrystal.h>


// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 1;

LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
int taster = 2;
byte brojevi[6][7] = { {0,0,0,1,0,0,0},
                       {1,0,0,0,0,1,0},
                       {0,1,0,1,0,0,1},
                       {1,1,0,0,0,1,1},
                       {1,1,0,1,0,1,1},
                       {1,1,1,0,1,1,1},
                      };
int rednibroj=0;

void setup() {
  lcd.begin(16, 2);
  lcd.print("Dobro dosli!");
  delay(200);
  for (int positionCounter = 0; positionCounter < 16; positionCounter++) {
    lcd.scrollDisplayRight();
    delay(300);
  }
  for (int positionCounter = 0; positionCounter < 29; positionCounter++) {
    lcd.scrollDisplayLeft();
    delay(300); 
  }
  lcd.clear();
  lcd.print("Baci kocku");
  pinMode(taster,INPUT);
  attachInterrupt(digitalPinToInterrupt(taster), bacanje, FALLING);  
}
void bacanje(){
  bool stop = digitalRead(taster);
  int broj = random(1,7);
  for(int pin=3; pin<=9; pin++)
  digitalWrite(pin, brojevi[broj-1][pin]);
  delay(300);
  lcd.clear();
  
  rednibroj++;
  
  lcd.print("Vas ");
  lcd.print(rednibroj);
  lcd.print(".broj je ");
  lcd.print(broj);
  if(broj == 6){
  lcd.setCursor(0,1);  
  lcd.print("ponovite bacanje");}
}
 void loop() {

}
