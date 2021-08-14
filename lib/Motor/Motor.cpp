#include "Motor.h"
//debounce button with polling:
//https://www.programmingelectronics.com/debouncing-a-button-with-arduino/
volatile bool brakeFlag = LOW; //bandera de freno
volatile bool turnFlag = LOW;  //bandera de luces intermitentes

void stop()
{
  brakeFlag = HIGH;
}

void resume()
{
  brakeFlag = LOW;
}
void IRAM_ATTR checkBrake() //check if button is pressed. https://forum.arduino.cc/t/rising-and-falling-interrupt-on-same-pin/144341/5
{
  if (digitalRead(freno) == HIGH)
  {
    stop();
  }
  else
  {
    resume();
  }
}

void Motor::enableBrake()
{
  pinMode(freno, INPUT);                      //https://microcontrollerslab.com/push-button-esp32-gpio-digital-input/
  attachInterrupt(freno, checkBrake, CHANGE); //se usan resistencias pull-down. https://programarfacil.com/blog/utilizar-pulsadores-en-arduino/
  //pinMode(botonDirec, INPUT);
  //attachInterrupt(botonDirec, toggleIntermitents, RISING);
}

Motor::Motor()
{
}

Motor::~Motor()
{
}

void Motor::initializeMotors()
{

  //pines de joystick
  pinMode(vx, INPUT);
  pinMode(vy, INPUT);

  //pines de control de motor
  pinMode(m1a, OUTPUT);
  pinMode(m1b, OUTPUT);
  pinMode(m2a, OUTPUT);
  pinMode(m2b, OUTPUT);
  pinMode(pwm1, OUTPUT);
  pinMode(pwm2, OUTPUT);
  pulse1.setup(pwm1, 1, 250);
  pulse2.setup(pwm2, 2, 250);
  light.ConfigureLights();
}

void Motor::throttleMotor()
{
  pedal = analogRead(vy);
  light.ActivateFrontLights();
  light.checkCentralButton();
  if (pedal > 1845 && pedal < 1880) // joystick no se está moviendo
  {
    digitalWrite(m1a, LOW);
    digitalWrite(m1b, LOW);
    digitalWrite(m2a, LOW);
    digitalWrite(m2b, LOW);
  }

  if (pedal < 1844) //joystick hacia adelante
  {
    digitalWrite(m1a, HIGH);
    digitalWrite(m1b, LOW);
    digitalWrite(m2a, LOW);
    digitalWrite(m2b, HIGH);
    velMot1 = map(pedal, 1844, 0, 0, 255);
    velMot2 = map(pedal, 1844, 0, 0, 255);
  }

  else if (pedal > 1890) //joystick hacia atrás (reversa)
  {
    digitalWrite(m1a, LOW);
    digitalWrite(m1b, HIGH);
    digitalWrite(m2a, HIGH);
    digitalWrite(m2b, LOW);
    velMot1 = map(pedal, 1890, 4095, 0, 255);
    velMot2 = map(pedal, 1890, 4095, 0, 255);
    //light.ActivateReverseLights();

  }

  pulse1.setDuty(velMot1);
  pulse2.setDuty(velMot2);
}

void Motor::brake()
{
  if (brakeFlag == HIGH)
  {
    digitalWrite(m1a, LOW);
    digitalWrite(m1b, LOW);
    digitalWrite(m2a, LOW);
    digitalWrite(m2b, LOW);
    light.ActivateBacklights();
  }
  else
  {
    digitalWrite(LuzTras, LOW);
  }
  Serial.println(brakeFlag);
}