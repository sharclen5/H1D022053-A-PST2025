#include <Arduino.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>


LiquidCrystal_I2C lcd(0x27, 16, 2);
int echoPin = D1;
int trigPin = D0;
int SDA_pin = D3;
int SCL_pin = D4;
long duration;
int distance;

void setup() {
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);
    Wire.begin(SDA_pin, SCL_pin);
    lcd.init();
    lcd.backlight();  
    Serial.begin(9600);
}

void loop() {
    digitalWrite(trigPin, LOW);
    delayMicroseconds(5);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);

    duration = pulseIn(echoPin, HIGH);

    distance = 0.034 * duration / 2;

    lcd.clear(); 
    if (distance <= 100) {
        lcd.setCursor(0, 0);
        lcd.print("AREA");
        lcd.setCursor(0, 1);
        lcd.print("BERBAHAYA");
    } else {
        lcd.setCursor(0, 0);
        lcd.print("AREA");
        lcd.setCursor(0, 1);
        lcd.print("AMAN");
    }

    Serial.print("Jarak: ");
    Serial.print(distance);
    Serial.println(" cm");

    delay(1000); 
}
