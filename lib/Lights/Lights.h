#include <Arduino.h>
#define LuzDel 32 //pines de salida (LEDs)
#define LuzTras 33
#define LuzDir 25
#define LuzRev 23 //CORREGIR!! ESTE PIN ES LA LECTURA DEL EJE X DE JOYSTICK
#define botonDirec 35 //pines de entrada (botones)
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
    void Intermitents();
    void DisableLights();

private:
};