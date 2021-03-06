#include <ESP32_PWM.h>
#include <Arduino.h>
#include <Lights.h>
#define pinpedal 2   //pedal
#define m1a 27 //pines de control de motor
#define m1b 26
#define m2a 12 //CAMBIAR
#define m2b 14 //CAMBIAR
#define pwm1 18 //pines de PWM CAMBIAR
#define pwm2 19
#define freno 4 //freno

class Motor
{
public:
    Motor();
    ~Motor();
    uint16_t pedal;
    uint16_t velMot1;
    uint16_t velMot2;
    PWM pulse1;
    PWM pulse2;
    Lights light;
    void stop();
    void resume();
    void initializeMotors();
    void throttleMotor();
    void enableBrake();
    void brake();

private:
};