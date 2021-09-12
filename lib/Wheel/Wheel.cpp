#include "Wheel.h"

Wheel::Wheel()
{
}
Wheel::~Wheel()
{
}

void Wheel::initWheel(){
    servo1.attach(pinservo);
    pinMode(wheel,INPUT);

}

void Wheel::steerWheel(){
    joystickWheel = analogRead(wheel);
    wheelReading = map(joystickWheel,0,4095,0,180);
    servo1.write(wheelReading);
    Serial.println(wheelReading);
}