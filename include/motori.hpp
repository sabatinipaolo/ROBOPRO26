#ifndef MOTORI_HPP
#define MOTORI_HPP


class Motore
{

public:
    Motore(int pin1, int pin2, int pinpwm, int pin_enc1, int pin_enc2);

    Motore(const Motore &) = delete;            // impedisce copie di oggetti motori, Motore m(m2) (costruttore copia) genera errore
    Motore &operator=(const Motore &) = delete; // m1=m2 genera errore
                                                // vedi qui: https://www.stroustrup.com/C++11FAQ.html#default

    void muovi(int pwm);
    void stop();


private:
    int pin1;
    int pin2;
    int pinpwm;
    int pin_enc1;
    int pin_enc2;
};


extern Motore Motori[]; 
extern Motore & Motore_AS;
extern Motore & Motore_PS;
extern Motore & Motore_PD;
extern Motore & Motore_AD;

#endif // MOTORI_HPP
