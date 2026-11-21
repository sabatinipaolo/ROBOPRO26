#include "motori.hpp"

void setup()
{
    Motore m_AS(PIN_MOT_AS1, PIN_MOT_AS2, PIN_PWM_AS, PIN_ENC_AS1, PIN_ENC_AS2);
    Motore m_PS(PIN_MOT_PS1, PIN_MOT_PS2, PIN_PWM_PS, PIN_ENC_PS1, PIN_ENC_PS2);
    Motore m_PD(PIN_MOT_PD1, PIN_MOT_PD2, PIN_PWM_PD, PIN_ENC_PD1, PIN_ENC_PD2);
    Motore m_AD(PIN_MOT_AD1, PIN_MOT_AD2, PIN_PWM_AD, PIN_ENC_AD1, PIN_ENC_AD2);

    m_AD.muovi(255);
    m_AS.muovi(255);
    m_PD.muovi(255);
    m_PS.muovi(255);
}

void loop()
{
}
