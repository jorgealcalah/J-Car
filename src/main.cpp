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