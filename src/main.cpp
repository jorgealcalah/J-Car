#include <I_D.h>

void setup()
{
  Serial.begin(9600);
  engine.initializeMotors();
  engine.enableBrake();
}

void loop()
{
  engine.throttleMotor();
  engine.brake();
}