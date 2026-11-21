#include "motore.hpp"

void setup()
{
    Motore m(PIN_MOT_PS1, PIN_MOT_PS2, PIN_PWM_PS, PIN_ENC_PS1, PIN_ENC_PS2);
    m.muovi(255);  
}

void loop()
{
}
