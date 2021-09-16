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
#define BuzzerReverse 13
#define echo 34
#define trig 1
#define delayPulseTrig 0.010
unsigned long tiempoAnteriorTrig = 0;
unsigned long previousTimeUltSen = 0;
bool ultrasonicState = LOW;

void setup()
{
  pinMode(BuzzerReverse, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(trig, OUTPUT);
  //Serial.begin(9600);
}

void loop()
{
  unsigned long tiempoActualTrig = millis();
  if (tiempoActualTrig - tiempoAnteriorTrig >= delayPulseTrig)
  {
    tiempoAnteriorTrig = tiempoActualTrig;
    if (ultrasonicState == LOW)
    {
      ultrasonicState = HIGH;
    }
    else
    {
      ultrasonicState = LOW;
    }
    digitalWrite(trig, ultrasonicState); //envía un pulso de 10us a trigger
  }

  unsigned long DURACION = pulseIn(echo, HIGH); // con funcion pulseIn se espera un pulso
  uint16_t DISTANCIA = DURACION * 0.034 / 2;    // distancia en cm

  if (DISTANCIA <= 40 && DISTANCIA >= 0)
  {
    uint8_t datoDelay = map(DISTANCIA, 40, 0, 10, 0); //corregir
    unsigned long tiempoActualSensor = millis();
    tone(BuzzerReverse, 262);
  }
  else
  {
    noTone(BuzzerReverse);
  }
}