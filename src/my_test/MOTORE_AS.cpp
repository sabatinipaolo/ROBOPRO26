#include <Arduino.h>
#include "motori.hpp"

void setup()
{
    Motore m(PIN_MOT_AS1, PIN_MOT_AS2, PIN_PWM_AS, PIN_ENC_AS1, PIN_ENC_AS2);
    m.muovi(255);  
}

void loop()
{
}
