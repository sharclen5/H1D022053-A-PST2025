#include <Arduino.h>

// deklarasi pin dalam variabel
int echoPin = D0;
int trigPin = D1;
int ledPin = D4;

// deklarasi variabel
long duration;
int distance;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(ledPin, OUTPUT);
  
  Serial.begin(9600);
}

void loop() {
  // Mengukur jarak
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Menerima sinyal ultrasonik
  duration = pulseIn(echoPin, HIGH);

  // Menghitung jarak
  distance = 0.034 * duration / 2;


  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  // Set Kondisi LED menyala
  if(distance <= 10) {
    digitalWrite(ledPin, HIGH);
  } else {
    digitalWrite(ledPin, LOW);
  }

  delay(1000);
}