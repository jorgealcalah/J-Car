#include "Sound.h"
volatile bool claxonFlag = LOW;
void stopclaxon()
{
    claxonFlag = HIGH;
}

void resumeclaxon()
{
    claxonFlag = LOW;
}
void IRAM_ATTR checkclaxon()
{
    if (digitalRead(pinclaxon) == HIGH)
    {
        stopclaxon();
    }
    else
    {
        resumeclaxon();
    }
}
Sound::Sound()
{
}

Sound::~Sound()
{
}

void Sound::configureClaxon()
{
    pinMode(pinclaxon, INPUT);
    attachInterrupt(pinclaxon, checkclaxon, CHANGE);
}

void Sound::activateClaxon()
{
  if (claxonFlag == HIGH){
    tone(pinBuzzer,300);

  }
  else{
    noTone(pinBuzzer);
  }  
}