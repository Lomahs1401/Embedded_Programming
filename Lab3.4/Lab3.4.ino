#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include "DHT.h"
#include "OneButton.h"

LiquidCrystal_I2C lcd(0X27, 16, 2); //SCL A5 SDA A4

const int DHTPIN = 4;
const int DHTTYPE = DHT11;
DHT dht(DHTPIN, DHTTYPE);

OneButton Button1(A1, true);
int check = 0;

void setup()
{
  Serial.begin(9600);
  dht.begin();

  lcd.init();
  lcd.backlight();

  Button1.attachClick(click1);
  Button1.attachDoubleClick(click2);
}

void loop()
{
  if (check == 0) {
    lcd.backlight();
    float t = dht.readTemperature();
    lcd.setCursor(0, 0);
    lcd.print("Nhiet do ");
    lcd.print(t);
    lcd.print("oC");
  }
  else if (check == 1 ) {
    lcd.backlight();
    float t = dht.readTemperature(true);
    lcd.setCursor(0, 0);
    lcd.print("Nhiet do ");
    lcd.print(t);
    lcd.print("oF");
  }
  else {
    lcd.clear();
    lcd.noBacklight();
  }


  Button1.tick();
  delay(10);

}
void click1() {
  Serial.println("click");
  if (check == 0)
    check = 1;
  else
    check = 0;

}
void click2() {
  Serial.println(" double click");
  check = 3;
}
