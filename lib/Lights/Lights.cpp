#include "Lights.h"
#define debounceTime 10
volatile bool intermitentFlag = LOW;
unsigned long previousTime = 0;
bool lightState = LOW;

Lights::Lights()
{
}

Lights::~Lights()
{
}

void Intermitents()
{
  digitalWrite(LuzDir, HIGH);
  delay(150);
  digitalWrite(LuzDir, LOW);
  delay(150);
}
void IRAM_ATTR inter()
{
  if (digitalRead(botonDirec) == LOW && intermitentFlag == LOW)
  {
    intermitentFlag = LOW;
  }
  else if (digitalRead(botonDirec) == HIGH && intermitentFlag == LOW)
  {
    intermitentFlag = HIGH;
  }
  else if (digitalRead(botonDirec) == HIGH && intermitentFlag == HIGH)
  {
    intermitentFlag = LOW;
  }
  else if (digitalRead(botonDirec) == LOW && intermitentFlag == HIGH)
  {
    intermitentFlag = HIGH;
  }
}

void Lights::ConfigureLights()
{
  pinMode(LuzDel, OUTPUT);
  pinMode(LuzDir, OUTPUT);
  pinMode(LuzTras, OUTPUT);
  pinMode(LuzRev, OUTPUT);
  pinMode(botonDirec, INPUT);
  attachInterrupt(botonDirec, inter, RISING);
}
void Lights::ActivateFrontLights()
{
  digitalWrite(LuzDel, HIGH);
}

void Lights::ActivateBacklights()
{
  digitalWrite(LuzTras, HIGH);
}

void Lights::ActivateReverseLights()
{
  digitalWrite(LuzRev, HIGH);
}

void Lights::checkCentralButton()
{
  if (intermitentFlag == HIGH)
  {
    unsigned long currentTime = millis();
    if (currentTime - previousTime >= delayTimeLight)
    {
      previousTime = currentTime;
      if (lightState == LOW)
      {
        lightState = HIGH;
      }
      else
      {
        lightState = LOW;
      }
      digitalWrite(LuzDir, lightState);
    }
  }
  else
  {
    digitalWrite(LuzDir, LOW);
  }
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