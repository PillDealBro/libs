String Poslati_String;
int crvena_dioda=9;
int zelena_dioda=2;

void setup() {
  Serial.begin(9600);
  Serial.println("START");
}

void loop() {
  if(Serial.available()>0)
  {
    Poslati_String=Serial.readString();
    Serial.println(Poslati_String);
    if(Poslati_String=="#TEST\n")
    {
      while(Serial.available()<=0)
      {
        digitalWrite(crvena_dioda,HIGH);
        digitalWrite(zelena_dioda,HIGH);
        delay(1000);
        digitalWrite(crvena_dioda,LOW);
        digitalWrite(zelena_dioda,LOW);
        delay(1000);
        Serial.println(Poslati_String);
      }
    }
    delay(1000);
  }
}
