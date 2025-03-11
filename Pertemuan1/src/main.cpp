#include <Arduino.h>

// put function declarations here:
int myFunction(int, int);


int redLED = D0;
int yellowLED = D2;
int yellowLED2 = D4;

void setup() {
  // put your setup code here, to run once:
  pinMode(redLED, OUTPUT);
  pinMode(yellowLED, OUTPUT);
  pinMode(yellowLED2, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int led = random(3);
  if (led == 0) {
    digitalWrite(redLED, HIGH);
    delay(200);
    digitalWrite(redLED, LOW);
  } else if (led == 1) {
    digitalWrite(yellowLED, HIGH);
    delay(200);
    digitalWrite(yellowLED, LOW);
  } else if (led == 2) {
    digitalWrite(yellowLED2, HIGH);
    delay(200);
    digitalWrite(yellowLED2, LOW);
  }
}