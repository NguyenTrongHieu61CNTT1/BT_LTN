#include <LiquidCrystal.h>
LiquidCrystal lcd(9, 8, 7, 6, 5, 4);
const int trig = 3;
const int echo = 2;

void setup() {
  Serial.begin(9600);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  lcd.begin(16,2);
}

void loop() {
  float duration; //Thời gian
  float distance; //Khoảng cách
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, HIGH);
  duration = pulseIn(echo, HIGH, 30000);
  distance = (duration*0.034/2);
  lcd.setCursor(0,0);
  lcd.print("DISTANCE");
  lcd.setCursor(0,1);
  lcd.print(distance);
  lcd.print("cm");
  delay(1000);
  lcd.clear();
}
