#include <SoftwareSerial.h>
SoftwareSerial rs485(6, 7);  // RX: 6, TX: 7

int AnalogHS = A0;
int AnalogSS = A1;
int adcHS = 0;
int adcSS = 0;
int enablePin = 2;

void setup()
{
  rs485.begin(115200);
  Serial.begin(115200);
  pinMode(AnalogHS, INPUT);
  pinMode(AnalogSS, INPUT);
  pinMode(enablePin, OUTPUT);
  delay(10);

  digitalWrite(enablePin, HIGH);
}
void loop()
{
  int adcHS = analogRead(AnalogHS);
  int adcSS = analogRead(AnalogSS);

  rs485.println(adcSS);
  Serial.println(adcHS);
}
