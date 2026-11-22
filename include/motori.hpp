#ifndef MOTORI_HPP
#define MOTORI_HPP

static constexpr unsigned long DELTA_T = 10;
static constexpr int IMPULSI_PER_GIRO = (30 * 7.0f);

class Motore
{

public:
    Motore(int pin1, int pin2, int pinpwm, int pin_enc1, int pin_enc2);

    Motore(const Motore &) = delete;            // impedisce copie di oggetti motori, Motore m(m2) (costruttore copia) genera errore
    Motore &operator=(const Motore &) = delete; // m1=m2 genera errore
                                                // vedi qui: https://www.stroustrup.com/C++11FAQ.html#default

    void muovi(int pwm);
    void stop();

    float get_RPM() { return rpm };
    void ISR_encoder();
    void aggiorna_lettura_rpm();

    const int pin1;
    const int pin2;
    const int pinpwm;
    const int pin_enc1;
    const int pin_enc2;

private:
    float rpm = 0;

    // variabili per calcolo RPM
    volatile unsigned long conta_impulsi_encoder = 0; // dovremmo aver un overflof ogni 600 ore circa ..
    volatile unsigned long ultimo_conteggio_impulsi = 0;
    volatile unsigned long tempo_ultimo_aggiornamento_rpm = 0;
};

extern Motore Motori[]; 
extern Motore & Motore_AS;
extern Motore & Motore_PS;
extern Motore & Motore_PD;
extern Motore & Motore_AD;

#endif // MOTORI_HPP
