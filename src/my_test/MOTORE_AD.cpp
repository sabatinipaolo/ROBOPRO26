#include <Arduino.h>
#include "motori.hpp"

void setup()
{
    Motore m(PIN_MOT_AD1, PIN_MOT_AD2, PIN_PWM_AD, PIN_ENC_AD1, PIN_ENC_AD2);
    m.muovi(255);  
}

void loop()
{
}
