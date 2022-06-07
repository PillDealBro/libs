#include <ezButton.h>
#include<Stepper.h>
#define POT A0
#define stanje_OFF 0
#define stanje_ON 1


ezButton button(7);
int loopState = stanje_OFF;
int koraci = 32;
Stepper StepperM(koraci, 8, 10, 9, 11);
void setup() {
  Serial.begin(9600);

  button.setDebounceTime(100);
}

void loop() {
  button.loop();
 float napon = analogRead(POT) * (5.0 / 1023.0);
  if (button.isPressed()) {
    if (loopState == stanje_OFF)
      loopState = stanje_ON;
    else
      loopState = stanje_OFF;
  }
 

  if (loopState == stanje_ON) {
    Serial.println("Radi");
   
float procenti,vrednostPOT = analogRead(POT);
 
    //Serial.print(procenti);

           procenti = (vrednostPOT *100) / 1023;
         
          
           
           if(procenti == 0)
           {
            Serial.println("0%");
           }
           if(procenti == 20.0)
           {
            Serial.println("20%");
           }
          if(procenti == 100.0)
           {
            Serial.println("100%");
           }
             if ( procenti>20 && procenti<100){
              Serial.print(procenti);
              Serial.println("%");
           }

 
    StepperM.step(koraci);
    StepperM.setSpeed(analogRead(POT));
  //  Serial.println(analogRead(POT));
  
  }

}
