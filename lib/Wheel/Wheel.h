#include <Arduino.h>
#include <ESP32Servo.h>
#define wheel 39
#define pinservo 34
class Wheel
{
public:
    Servo servo1;
    uint16_t joystickWheel;
    uint16_t wheelReading;
    Wheel();
    ~Wheel();
    void initWheel();
    void steerWheel();

private:
};