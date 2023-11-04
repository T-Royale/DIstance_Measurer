#include <LiquidCrystal.h>

#define RS 29
#define ENABLE 30
#define D4 31
#define D5 32
#define D6 33
#define D7 34

#define trigger 41
#define echo 40
#define ConValue 58.2

LiquidCrystal lcd (RS, ENABLE, D4, D5, D6, D7);
int duracion;
int distancia;
int metros;
int cm;

void setup() {
  lcd.begin (16,2);
  pinMode(trigger, OUTPUT);
  pinMode(echo, INPUT);
  Serial.begin(9600);
}



void loop() {
  lcd.setCursor (0, 0);
  digitalWrite(trigger, HIGH);
  delay(1);
  digitalWrite(trigger, LOW);
  duracion = pulseIn(echo, HIGH);
  distancia = duracion / ConValue;
  Serial.println(distancia);
  metros = distancia/100;
  cm = distancia - (metros * 100);
  lcd.print (metros);
  lcd.print ("M");
  lcd.setCursor(0, 1);
  lcd.print (cm);
  lcd.print (" cm"); 
  delay (500);
}
