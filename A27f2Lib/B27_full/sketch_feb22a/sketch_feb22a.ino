// Definisanje konekcionih pinova
#define buzzerPin 8
#define pirPin 3
#define ledPin 13
// Kreiranje promjenljivih
int val = 0;
bool motionState = false; // Startuje se bey detekctovanog pokreta.
void setup() {
// Konfigurisanje pinova
pinMode(buzzerPin, OUTPUT);
pinMode(ledPin, OUTPUT);
pinMode(pirPin, INPUT);
// Iniciranje serijske komunikacije
Serial.begin(9600);
}
// Funkcija za generisanje tona
void alarm(long duration, int freq) {
tone(buzzerPin, freq);
delay(duration);
noTone(buzzerPin);
}
void loop() {
// Očitavanje stanja pirPin-a
val = digitalRead(pirPin);
// Ako je pokret detektovan (pirPin = HIGH), radi sljedeće:
if (val == HIGH) {
digitalWrite(ledPin, HIGH); // Uključi LED na ploči.
alarm(1000, 100); // Uklhuči alarm (duration, frequency).
// Promijeni stanje promjenljive motionState
if (motionState == false) {
Serial.println("Upozorenje!");
motionState = true;
}
}
// If no motion is detected (pirPin = LOW), do the following:
else {
digitalWrite(ledPin, LOW); // Iskluči LED na ploči.
noTone(buzzerPin); // isključi alarm
delay(150);
// Promijeni stanje promjenljive motionState
if (motionState == true) {
Serial.println("Bezbedno!");
motionState = false;
}
}
}
