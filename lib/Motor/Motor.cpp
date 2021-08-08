#include "Motor.h"
volatile bool brakeFlag = LOW; //bandera de freno

void IRAM_ATTR stop()
{
  brakeFlag = HIGH;
}
void Motor::enableBrake()
{
  pinMode(freno, INPUT);
  attachInterrupt(freno, stop, RISING);
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
}

void Motor::throttleMotor()
{
  pedal = analogRead(vy);

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

  else if (pedal > 1890) //joystick hacia atrás
  {
    digitalWrite(m1a, LOW);
    digitalWrite(m1b, HIGH);
    digitalWrite(m2a, HIGH);
    digitalWrite(m2b, LOW);
    velMot1 = map(pedal, 1890, 4095, 0, 255);
    velMot2 = map(pedal, 1890, 4095, 0, 255);
  }

  pulse1.setDuty(velMot1);
  pulse2.setDuty(velMot2);
}

void Motor::brake()
{
  digitalWrite(m1a, LOW);
  digitalWrite(m1b, LOW);
  digitalWrite(m2a, LOW);
  digitalWrite(m2b, LOW);
}