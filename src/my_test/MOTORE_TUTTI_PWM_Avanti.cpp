#include <Arduino.h>
#include "motori.hpp"
#include "oled.hpp"

void setup()
{
    Oled.begin();

    
    Motore_AS.muovi(255);
    Motore_AD.muovi(-255);
    Motore_PS.muovi(255);
    Motore_PD.muovi(-255);
        
}

void loop()
{
     for (int i = 0; i < 4; i++)
         Motori[i].aggiorna_lettura_rpm();

        
    Oled.stampa4float(Motore_AS.get_RPM(),
                      Motore_AD.get_RPM(),
                      Motore_PS.get_RPM(),
                      Motore_PD.get_RPM());

    delay(5);
}
