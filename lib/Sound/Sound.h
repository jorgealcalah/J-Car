#include <Arduino.h>
#include <ESP32Tone.h>
#define pinBuzzer 17
#define pinclaxon 16
class Sound
{
public:
    Sound();
    ~Sound();
    void configureClaxon();
    void activateClaxon();
private:
};