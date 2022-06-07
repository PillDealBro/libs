#include <ezButton.h>
#include <Stepper.h>
#define POT A0
#define stanje_OFF 0
#define stanje_ON 1

ezButton button(7);
int loopState=stanje_OFF;
int koraci=32;
Stepper StepperM(koraci,8,9,10,11);

void setup()
{
  Serial.begin(9600);
  button.setDebounceTime(100);
}
void loop()
{
  float napon=analogRead(POT)*5/1023;
  if(button.isPressed())
  {
    if(loopState==stanje_OFF)
      loopState=stanje_ON;
    else
      loopState=stanje_OFF;
  }
  if(loopState==stanje_ON)
  {
    Serial.println("Radi");
    int procenti=napon*100;
    Serial.print(procenti);
    Serial.println("%");
    StepperM.step(koraci);
    StepperM.setSpeed(analogRead(POT));
    Serial.print(analogRead(POT));
  }
}
