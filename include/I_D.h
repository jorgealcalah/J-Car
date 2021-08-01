#include <Arduino.h>
#include <analogWrite.h>
#include <ESP32_PWM.h>


#define vx 15 //pines de joystick
#define vy 2  //pedal
#define m1a 27 //pines de control de motor
#define m1b 26
#define m2a 12
#define m2b 14
#define pwm1 18 //pines de PWM
#define pwm2 19

uint16_t velMot1;
uint16_t velMot2;
PWM pulse1;
PWM pulse2;
