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
  /*
  if (brakeFlag == HIGH)
  {
    brakeFlag = LOW;
    engine.brake();
  }
  Serial.println(brakeFlag);
  */
}