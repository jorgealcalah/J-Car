#include <Arduino.h>
#define vx 15 //pines de joystick
#define vy 2  //pedal

#define m1a 27 //pines de control de motor
#define m1b 26
#define m2a 12
#define m2b 14

#define pwm1 18 //pines de PWM
#define pwm2 19

uint16_t velMot1;
uint16_t velMot2;
void setup()
{
  Serial.begin(9600);

  //pines de joystick
  pinMode(vx, INPUT);
  pinMode(vy, INPUT);

  //pines de control de motor
  pinMode(m1a, OUTPUT);
  pinMode(m1b, OUTPUT);
  pinMode(m2a, OUTPUT);
  pinMode(m2b, OUTPUT);

  /*
  digitalWrite(m1a,HIGH);
  digitalWrite(m1b,LOW);
  digitalWrite(m2a,LOW);
  digitalWrite(m2b,HIGH);
  */
}

void loop()
{
  uint16_t pedal = analogRead(vy);

  if (pedal < 1868) //joystick hacia adelante
  {
    digitalWrite(m1a, HIGH);
    digitalWrite(m1b, LOW);
    digitalWrite(m2a, LOW);
    digitalWrite(m2b, HIGH);
    velMot1 = map(pedal, 1868, 0, 0, 255);
    velMot2 = map(pedal, 1868, 0, 0, 255);
  }

  else if (pedal > 1880) //joystick hacia atrás
  {
    digitalWrite(m1a, LOW);
    digitalWrite(m1b, HIGH);
    digitalWrite(m2a, HIGH);
    digitalWrite(m2b, LOW);
    velMot1 = map(pedal, 1880, 4095, 0, 255);
    velMot2 = map(pedal, 1880, 4095, 0, 255);
  }
  /*Serial.print("valor en x: ");
  Serial.print(analogRead(vx));
  Serial.print(" valor en y: ");
  Serial.print(pedal);
  Serial.print(" la señal de pwm tiene un valor de: ");
  Serial.println(""); */
  /* 
  analogWrite(pwm1,velMot1);
  analogWrite(pwm2,velMot2);
  */
}