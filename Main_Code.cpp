#include <LiquidCrystal.h>

#define RS 4
#define ENABLE 5
#define D4 6
#define D5 7
#define D6 8
#define D7 9

#define trigger 3
#define echo 2
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
