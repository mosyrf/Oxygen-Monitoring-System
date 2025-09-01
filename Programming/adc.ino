#include <LiquidCrystal.h>
const int rs = 11, en = 10, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
const byte pot = A0;

void setup() {
  lcd.begin(16, 2);
  Serial.begin(9600);
  pinMode(pot, INPUT);

}
void loop() {
  int nilaiPot = analogRead(pot);
  float tegangan = nilaiPot * (5.0 / 1023.0);

  Serial.print("NILAI ADC POT:");
  Serial.println(nilaiPot);
  Serial.println("");

  Serial.print("NILAI TEG POT:");
  Serial.println(tegangan);
  Serial.println("");

  lcd.setCursor(1, 0);
  lcd.print("NILAI ADC POT:");
  lcd.setCursor(0, 1);
  lcd.print(nilaiPot);
  lcd.setCursor(8, 1);
  lcd.print(tegangan);
}
