#include <ESP32_PWM.h>
#include <Arduino.h>
class Motor
{
public:
    Motor();
    ~Motor();
    uint16_t velMot1;
    uint16_t velMot2;
    PWM pulse1;
    PWM pulse2;

    void initializeMotors();
    void throttleMotor();

private:
};