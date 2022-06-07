#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>

Adafruit_BME280 bme;
#define CrvenaDioda 4
#define ZelenaDioda 5

void setup() {
  pinMode(CrvenaDioda,OUTPUT);
  pinMode(ZelenaDioda,OUTPUT);
  Serial.begin(9600);
   if (!bme.begin(0x76)) {
    Serial.println("Could not find a valid BME280 sensor, check wiring!");
    while (1);
  }
}
void loop() {
  int vrednostSenzora = analogRead(0x76);
  float napon = vrednostSenzora * (5.0 / 1023.0);
  Serial.println(napon);
  Serial.print("Temperature = ");
  Serial.print(bme.readTemperature());
  Serial.println("*C");
  Serial.println();
  delay(1000);
 if(bme.readTemperature()<20)
  {
    digitalWrite(CrvenaDioda,HIGH);
    digitalWrite(ZelenaDioda,LOW);
 }
  else if (bme.readTemperature()>25)
  {
     digitalWrite(CrvenaDioda,LOW);
     digitalWrite(ZelenaDioda,LOW);
  }  
  if(bme.readTemperature()<25)
  {
    digitalWrite(CrvenaDioda,LOW);
    digitalWrite(ZelenaDioda,LOW);
  }
  else if (bme.readTemperature()>30)
  {
    digitalWrite(CrvenaDioda,LOW);
     digitalWrite(ZelenaDioda,HIGH);
  }
}
