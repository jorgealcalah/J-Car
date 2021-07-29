#include <Arduino.h>
#define vx 15
#define vy 2

void setup() {
  pinMode(vx,INPUT);
  pinMode(vy,INPUT);
  Serial.begin(9600);
  Serial.println("Hola");
}

void loop() {
  Serial.print("valor en x: ");
  Serial.print(analogRead(vx));
  Serial.print(" valor en y: ");
  Serial.println(analogRead(vy));
  
}