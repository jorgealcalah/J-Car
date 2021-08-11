#include "Lights.h"

Lights::Lights()
{
}

Lights::~Lights()
{
}

void Lights::ConfigureLights()
{
    pinMode(LuzDel, OUTPUT);
    pinMode(LuzDir, OUTPUT);
    pinMode(LuzTras, OUTPUT);
    pinMode(LuzRev,OUTPUT);
}
void Lights::ActivateFrontLights()
{
    digitalWrite(LuzDel,HIGH);
}

void Lights::ActivateBacklights()
{
    digitalWrite(LuzTras,HIGH);
}

void Lights::ActivateReverseLights()
{
    digitalWrite(LuzRev,HIGH);
}

void Lights::Intermitents()
{
    digitalWrite(LuzDir,HIGH);
    delay(500);
    digitalWrite(LuzDir,LOW);
    delay(500);
}

void Lights::LeftBlinker()
{
}

void Lights::RightBlinker()
{
}

void Lights::DisableLights()
{
}