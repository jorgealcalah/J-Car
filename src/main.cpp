#include <Arduino.h>
#define vx 15
#define vy 2
#define m1a 27
#define m1b 26
#define m2a 12
#define m2b 14

void setup() {
  pinMode(vx,INPUT);
  pinMode(vy,INPUT);
  pinMode(m1a,OUTPUT);
  pinMode(m1b,OUTPUT);
  pinMode(m2a,OUTPUT);
  pinMode(m2b,OUTPUT);
  Serial.begin(115200);
}

void loop() {
  Serial.print("valor en x: ");
  Serial.print(analogRead(vx));
  Serial.print(" valor en y: ");
  Serial.println(analogRead(vy));
  digitalWrite(m1a,HIGH);
  digitalWrite(m1b,LOW);
  digitalWrite(m2a,HIGH);
  digitalWrite(m2b,LOW);

}