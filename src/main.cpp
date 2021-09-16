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
#define delayPulse 10 //CAMBIAR - tiempo para sensor ultrasónico
unsigned long tiempoAnterior = 0;
bool ultrasonicState = LOW;

void setup()
{
  pinMode(BuzzerReverse, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(trig, OUTPUT);
}

void loop()
{
  unsigned long tiempoActual = micros();
  if (tiempoActual - tiempoAnterior >= delayPulse)
  {
    tiempoAnterior = tiempoActual;
    if (ultrasonicState == LOW)
    {
      ultrasonicState = HIGH;
    }
    else
    {
      ultrasonicState = LOW;
    }
    digitalWrite(trig, ultrasonicState);
  }

  uint16_t DURACION = pulseIn(echo, HIGH); // con funcion pulseIn se espera un pulso
                                           // alto en Echo
  uint16_t DISTANCIA = DURACION / 58.2;    // distancia medida en centimetros

  if (DISTANCIA <= 40 && DISTANCIA >= 0)
  {                           // si distancia entre 0 y 20 cms.
    tone(BuzzerReverse, 262); //un cuarto de la nota C4.
  }
  else
  {
    noTone(BuzzerReverse);
  }
}