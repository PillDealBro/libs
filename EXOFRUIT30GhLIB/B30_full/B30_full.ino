String Poslati_String;
int crvena_dioda=9;
int zelena_dioda=2;
int period[4]={500,1000,1500,2000};
int u=1;

void setup() {
  Serial.begin(9600);
  Serial.println("START");
}

void loop() {
  if(Serial.available()>0)
  {
    Poslati_String=Serial.readString();
    Serial.println(Poslati_String);
    if(Poslati_String=="#UVECAJ\n")
    {u=u+1;}
    if(Poslati_String=="#SMANJI\n")
    {u=u-1;}
    if(Poslati_String=="#CRVENA\n")
    {
      while(Serial.available()<=0)
      {
        digitalWrite(crvena_dioda,HIGH);
        digitalWrite(zelena_dioda,LOW);
        delay(period[u]);
        digitalWrite(crvena_dioda,LOW);
        delay(period[u]);
      }
    }
    if(Poslati_String=="#ZELENA\n")
    {
      while(Serial.available()<=0)
      {
        digitalWrite(crvena_dioda,LOW);
        digitalWrite(zelena_dioda,HIGH);
        delay(period[u]);
        digitalWrite(zelena_dioda,LOW);
        delay(period[u]);
      }
    }
  }
}
