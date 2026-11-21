#include <Arduino.h>
#include "motori.hpp"

void setup()
{
    for(int i=0; i<4; i++){
        Motori[i].muovi(255);
    }   
}

void loop()
{
}
