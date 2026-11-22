#include <Arduino.h>
#include "motori.hpp"

void setup()
{
    
    Motore_AS.muovi(-255);
    Motore_PS.muovi(-255);
    Motore_PD.muovi(-255);
    Motore_AD.muovi(-255);
}

void loop()
{
}
