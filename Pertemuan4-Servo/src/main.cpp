#include <Arduino.h>
#include <servo.h>

Servo myservo;

void setup() {

  myservo.attach(D0);
  Serial.begin(9600);
}

void loop() {

//   for(int pos = 0; pos <= 180; pos ++) {
//     myservo.write(pos);
//     delay(10)
//   }

//   for(int pos = 180; pos >= 0; pos --) {
//     myservo.write(pos);
//     delay(10)
//   }

// }

  myservo.write(90);
  delay(2000)
  myservo.write(0);
  delay(2000)
  myservo.write(90);
  delay(2000)
}