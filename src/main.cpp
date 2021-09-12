/*
#include <I_D.h>
//pines banneados temporalmente STRAPPING: 14, 15, 10, 13, 16

void setup()
{
  engine.initializeMotors();
  engine.enableBrake();
  volante.initWheel();
  claxon.configureClaxon();
  Serial.begin(9600);
}

void loop()
{
  engine.throttleMotor();
  engine.brake();
  volante.steerWheel();
  claxon.activateClaxon();
  //Serial.println(analogRead(39)); 
}

*/
#include <Arduino.h>
#include <ESP32Tone.h>
#define BuzzerReverse 43
#define echo 23
#define trig 45

void setup()
{
  pinMode(BuzzerReverse,OUTPUT);
  pinMode(echo,INPUT);
  pinMode(trig,OUTPUT);
}

void loop()
{
  digitalWrite(trig, HIGH);     // generacion del pulso a enviar
  delay(1);       // al pin conectado al trigger
  digitalWrite(trig, LOW);    // del sensor
  
  uint16_t DURACION = pulseIn(echo, HIGH);  // con funcion pulseIn se espera un pulso
            // alto en Echo
  uint16_t DISTANCIA = DURACION / 58.2;    // distancia medida en centimetros
  Serial.println(DISTANCIA);    // envio de valor de distancia por monitor serial
  delay(200);       // demora entre datos

  if (DISTANCIA <= 40 && DISTANCIA >= 0){ // si distancia entre 0 y 20 cms.
    tone(BuzzerReverse, 262); //un cuarto de la nota C4.      // enciende LED
    delay(DISTANCIA * 10);      // demora proporcional a la distancia
    digitalWrite(BuzzerReverse, LOW);     // apaga LED
    }
}