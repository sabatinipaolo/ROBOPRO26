#include <Arduino.h>
#include "controller.hpp"
#include "motori.hpp"
#include "oled.hpp"
void setup()
{
    Oled.begin();

    //  Controller.trasla_nord(255);
    //  Controller.trasla_nord_est(255);
    //  Controller.trasla_est(255);
    //  Controller.trasla_sud_est(255);
    //  Controller.trasla_sud(255);
    //  Controller.trasla_sud_ovest(255);
    //  Controller.trasla_ovest(255);
      Controller.trasla_nord_ovest(255);
}

void loop()
{
    Oled.stampa4float(Motore_AS.get_RPM(),Motore_AD.get_RPM(),
                      Motore_PS.get_RPM(),Motore_PD.get_RPM());

    Controller.aggiorna_RPM_dei_quattro_motori();

    delay(11);
}

