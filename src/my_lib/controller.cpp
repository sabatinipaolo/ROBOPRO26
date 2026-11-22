#include <Arduino.h>
#include "controller.hpp"
#include "motori.hpp"
#include "robopropin.h"
Controller_class::Controller_class()
{
    init();
};

void Controller_class::init()
{
    for (int i = 0; i < 4; i++)
        Motori[i].stop();
    // TODO testare Motore_XX.pin_enc1 per eliminare PIN_ENC e include roboproppin.h
    attachInterrupt(digitalPinToInterrupt(PIN_ENC_AD1), ISR_encoder_Motore_AD, RISING);
    attachInterrupt(digitalPinToInterrupt(PIN_ENC_PD1), ISR_encoder_Motore_PD, RISING);
    attachInterrupt(digitalPinToInterrupt(PIN_ENC_PS1), ISR_encoder_Motore_PS, RISING);
    attachInterrupt(digitalPinToInterrupt(PIN_ENC_AS1), ISR_encoder_Motore_AS, RISING);
}

void Controller_class::ISR_encoder_Motore_AD()
{
    Motore_AD.ISR_encoder();
}

void Controller_class::ISR_encoder_Motore_PD()
{
    Motore_PD.ISR_encoder();
}

void Controller_class::ISR_encoder_Motore_PS()
{
    Motore_PS.ISR_encoder();
}

void Controller_class::ISR_encoder_Motore_AS()
{
    Motore_AS.ISR_encoder();
}

void Controller_class::aggiorna_RPM_dei_quattro_motori(int deltaTms)
{ // dura circa 7 -8  us (microsecondi)
    for (int i = 0; i < 4; i++)
    {
        Motori[i].aggiorna_lettura_rpm();
    }
}

Controller_class Controller;
