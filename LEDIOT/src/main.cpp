#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>

const char* ssid = "Maid of Orleans";
const char* password = "******";

ESP8266WebServer server(80);
String webpage;

void setup() {
  Serial.begin(9600);
  delay(10);

  pinMode(D0, OUTPUT);
  pinMode(D2, OUTPUT);
  pinMode(D3, OUTPUT);

  // Connect to Wi-Fi
  Serial.println();
  Serial.print("Configuring access point...");

  // Mengatur wifi
  WiFi.mode(WIFI_AP);
  WiFi.begin(ssid, password);

  //print status connect
  Serial.println("Connecting to ");
  Serial.println(WiFi.softAPIP());

  // Isi webpage
  webpage += "<html><body><h1>Suisei</h1>";
  webpage += "<p>LED 1 : ";
  webpage += "<a href=\"LED1ON\"\"><button>ON</button></a><a href=\"LED1OFF\"\"><button>OFF</button></a></p><br>";
  webpage += "<p>LED 2 : ";
  webpage += "<a href=\"LED0ON\"\"><button>ON</button></a><a href=\"LED2OFF\"\"><button>OFF</button></a></p><br>";
  webpage += "<p>LED 3 : ";
  webpage += "<a href=\"LED2ON\"\"><button>ON</button></a><a href=\"LED2OFF\"\"><button>OFF</button></a></p>";

  // membuat tampilan webpage
  server.on("/", []() {
    server.send(200, "text/html", webpage);
  });

  // Bagian ini untuk merespon perintah yang masuk
  server.on("/LED1ON", []() {
    server.send(200, "text/html", webpage);
    digitalWrite(D0, HIGH); // Turn LED on
    delay(1000);
  });
  server.on("/LED1OFF", []() {
    server.send(200, "text/html", webpage);
    digitalWrite(D0, LOW); // Turn LED off
    delay(1000);
  });
  server.on("/LED0ON", []() {
    server.send(200, "text/html", webpage);
    digitalWrite(D2, HIGH); // Turn LED on
    delay(1000);
  });
  server.on("/LED0OFF", []() {
    server.send(200, "text/html", webpage);
    digitalWrite(D2, LOW); // Turn LED off
    delay(1000);
  });
  server.on("/LED2ON", []() {
    server.send(200, "text/html", webpage);
    digitalWrite(D3, HIGH); // Turn LED on
    delay(1000);
  });
  server.on("/LED2OFF", []() {
    server.send(200, "text/html", webpage);
    digitalWrite(D3, LOW); // Turn LED off
    delay(1000);
  });

  // Start the server
  server.begin();
  Serial.println("Web server dijalankan");
}