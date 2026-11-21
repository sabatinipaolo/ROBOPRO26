#include "motori.hpp"

void setup()
{
    Motore m(PIN_MOT_PD1, PIN_MOT_PD2, PIN_PWM_PD, PIN_ENC_PD1, PIN_ENC_PD2);
    m.muovi(255);  
}

void loop()
{
}
