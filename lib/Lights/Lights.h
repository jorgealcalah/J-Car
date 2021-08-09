#define LuzDel 1
#define LuzTras 1
#define LuzDir 1
class Lights
{
public:
    Lights();
    ~Lights();
    void ActivateFrontLights();
    void ActivateBacklights();
    void ActivateReverseLights();
    void LeftBlinker();
    void RightBlinker();
    void Intermitents();
    void DisableLights();
private:
};