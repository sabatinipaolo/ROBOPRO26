#include "motore.hpp"

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
}

