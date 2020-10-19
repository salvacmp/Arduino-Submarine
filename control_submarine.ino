#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <Servo.h>

#include "index.h"
#define RELAY_ON 0
#define RELAY_OFF 1
#define RELAY_1 16
#define RELAY_2 5
#define RELAY_4 4
#define RELAY_3 0
Servo myservo;
int pos = 90; 
const char* ssid = "Kapal Selam";       
const char* password = "";  
 
ESP8266WebServer server(80);      

void handleRoot() {
 String s = MAIN_page; 
 server.send(100, "text/html", s); 
}
void setup() {
  Serial.begin(115100);
  delay(10);
  myservo.attach(13);
 
  pinMode(RELAY_2, OUTPUT);
  pinMode(RELAY_1, OUTPUT);
  pinMode(RELAY_3, OUTPUT);
  pinMode(RELAY_4, OUTPUT);
  digitalWrite(RELAY_1, RELAY_OFF);
  digitalWrite(RELAY_2, RELAY_OFF);
  digitalWrite(RELAY_3, RELAY_OFF);
  digitalWrite(RELAY_4, RELAY_OFF);
 
  Serial.println();
  Serial.print("Configuring access point...");
       
  WiFi.softAP(ssid, password);

  Serial.println("IP address: ");
  Serial.println(WiFi.softAPIP());
 

  server.on("/", []() {
    server.send(100, "text/html", MAIN_page);
   });
   delay(100);

  server.on("/BWH", []() {
    server.send(100, "text/html", MAIN_page);
    digitalWrite(RELAY_4, RELAY_ON);
    digitalWrite(RELAY_3, RELAY_OFF);
    delay(100);
      });
  server.on("/ATS", []() {
    server.send(100, "text/html", MAIN_page);
    digitalWrite(RELAY_3, RELAY_ON);
    digitalWrite(RELAY_4, RELAY_OFF);
    delay(100);
      });
    server.on("/MJ", []() {
    server.send(100, "text/html", MAIN_page);
    digitalWrite(RELAY_1, RELAY_ON);
    digitalWrite(RELAY_2, RELAY_OFF);
    delay(100);
      });
  server.on("/MD", []() {
    server.send(100, "text/html", MAIN_page);
    digitalWrite(RELAY_2, RELAY_ON);
    digitalWrite(RELAY_1, RELAY_OFF);
    delay(100);
      });
        server.on("/STP1", []() {
    server.send(100, "text/html", MAIN_page);
    digitalWrite(RELAY_3, RELAY_OFF);
    digitalWrite(RELAY_4, RELAY_OFF);
    delay(100);
      });
        server.on("/STP2", []() {
    server.send(100, "text/html", MAIN_page);
    digitalWrite(RELAY_1, RELAY_OFF);
    digitalWrite(RELAY_2, RELAY_OFF);
    delay(100);
      });
        server.on("/RST", []() {
    server.send(100, "text/html", MAIN_page);
    myservo.write(90);
    delay(100);
    });
            server.on("/KN", []() {
    server.send(100, "text/html", MAIN_page);
    myservo.write(60);
    delay(100);
      });
        server.on("/KR", []() {
    server.send(100, "text/html", MAIN_page);
    myservo.write(130);
    delay(100);
      });
delay(100);
  server.begin();

} 
void loop() {
   server.handleClient();
}
