#include <SoftwareSerial.h>
SoftwareSerial rs485(6, 7);  // RX: 6, TX: 7

#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

int enablePin = 2;

Adafruit_SSD1306 display = Adafruit_SSD1306(128, 64, &Wire, -1);

void setup()
{
  rs485.begin(115200);
  Serial.begin(115200);
  pinMode(enablePin, OUTPUT);
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.display();
  delay(100);

  digitalWrite(enablePin, LOW);
  display.clearDisplay();
  display.display();
  display.setTextColor(WHITE);

}

void loop()

{
  while (rs485.available() || Serial.available())
  {
    digitalWrite(LED_BUILTIN, HIGH);

    display.clearDisplay();
    int adcSS = rs485.parseInt();
    int adcHS = Serial.parseInt();

    display.setCursor(20, 0);
    display.setTextSize(1);
    display.print("DATA DITERIMA");

    display.setCursor(20, 11);
    display.setTextSize(1);
    display.print("NILAI ADC =>");

    display.setCursor(0, 25);
    display.setTextSize(1);
    display.print("Software: ");
    display.setCursor(0, 40);
    display.setTextSize(2);
    display.print(adcSS);

    display.setCursor(65, 25);
    display.setTextSize(1);
    display.print("Hardware: ");
    display.setCursor(65, 40);
    display.setTextSize(2);
    display.print(adcHS);

    display.display();

  }
}
