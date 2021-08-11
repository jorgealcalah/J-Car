#include <I_D.h>
//pines banneados temporalmente STRAPPING: 14, 15, 10, 13, 16
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