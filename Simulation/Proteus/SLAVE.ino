#include <LiquidCrystal.h>
const int rs = 11, en = 10, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

//int enablePin = 8;
int ledpin = 12;
const byte pot = A0;

void setup() {
  lcd.begin(16, 2);
  Serial.begin(9600);    
                
  pinMode(ledpin, OUTPUT);
  //pinMode(enablePin, OUTPUT);
  pinMode(pot, INPUT);
  delay(10);

  //digitalWrite(enablePin, LOW);        
}
void loop() {
  int nilaiPot = analogRead(pot);
  
  while (Serial.available()) {
    nilaiPot = Serial.parseInt();           
    int pwm = map(nilaiPot, 0, 1023, 0, 255); 
    analogWrite(ledpin, pwm);              
    
    lcd.setCursor(1, 0);
    lcd.print("NILAI ADC POT:");
    lcd.setCursor(5, 1);
    lcd.print(nilaiPot);                   
  }
}
