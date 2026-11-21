#include "motori.hpp"

Motore::Motore(int pin1, int pin2, int pinpwm, int pin_enc1, int pin_enc2)
    : pin1(pin1), pin2(pin2), pinpwm(pinpwm), pin_enc1(pin_enc1), pin_enc2(pin_enc2)
{
    pinMode(pin_enc1, INPUT_PULLUP);
    pinMode(pin_enc2, INPUT_PULLUP);
    pinMode(pin1, OUTPUT);
    pinMode(pin2, OUTPUT);
    pinMode(pinpwm, OUTPUT);

    stop();
};

void Motore::stop()
{
    digitalWrite(pin1, LOW);
    digitalWrite(pin2, LOW);
    analogWrite(pinpwm, LOW);
}

void Motore::muovi(int pwm)
{
    if (pwm == 0)
        stop();
    else if (pwm > 0)
    {

        digitalWrite(pin1, HIGH);
        digitalWrite(pin2, LOW);
        analogWrite(pinpwm, pwm);
    }
    else if (pwm < 0)
    {
        digitalWrite(pin1, LOW);
        digitalWrite(pin2, HIGH);
        analogWrite(pinpwm, -pwm);
    };
};

Motore Motori [] = {
    Motore(PIN_MOT_AS1, PIN_MOT_AS2, PIN_PWM_AS, PIN_ENC_AS1, PIN_ENC_AS2),
    Motore(PIN_MOT_PS1, PIN_MOT_PS2, PIN_PWM_PS, PIN_ENC_PS1, PIN_ENC_PS2),
    Motore(PIN_MOT_PD1, PIN_MOT_PD2, PIN_PWM_PD, PIN_ENC_PD1, PIN_ENC_PD2),
    Motore(PIN_MOT_AD1, PIN_MOT_AD2, PIN_PWM_AD, PIN_ENC_AD1, PIN_ENC_AD2)};

constexpr int ind_m_AS=0;
constexpr int ind_m_PS=1;
constexpr int ind_m_PD=2;
constexpr int ind_m_AD=3;

Motore & Motore_AS = Motori[ind_m_AS];
Motore & Motore_PS = Motori[ind_m_PS];
Motore & Motore_PD = Motori[ind_m_PD];
Motore & Motore_AD = Motori[ind_m_AD];





