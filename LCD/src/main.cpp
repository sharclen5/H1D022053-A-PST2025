#include <Arduino.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 26, 2);
int SDA_pin = D1;
int SCL_pin = D3;


void setup() {
  Wire.begin(SDA_pin, SCL_pin);
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Jasa Sedot WC");
  lcd.setCursor(0, 1);
  lcd.print("082313737136");

  Serial.begin(9600);
}

void loop() {

}