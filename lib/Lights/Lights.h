#include <Arduino.h>
#define LuzDel 32 //pines de salida (LEDs)
#define LuzTras 33
#define LuzDir 25
#define LuzRev 23
#define botonDirec 22 //pines de entrada (botones)
#define delayTimeLight 150
class Lights
{
public:
    Lights();
    ~Lights();
    void ConfigureLights();
    void ActivateFrontLights();
    void ActivateBacklights();
    void ActivateReverseLights();
    void LeftBlinker();
    void RightBlinker();
    void checkCentralButton();
    void DisableLights();

private:
};