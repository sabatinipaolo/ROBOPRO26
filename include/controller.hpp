#ifndef CONTROLLER_HPP
#define CONTROLLER_HPP

class Controller_class
{
public:
    Controller_class();
    void init();

    // 4 ISR static
    static void ISR_encoder_Motore_AD();
    static void ISR_encoder_Motore_PD();
    static void ISR_encoder_Motore_PS();
    static void ISR_encoder_Motore_AS();

    static void aggiorna_RPM_dei_quattro_motori(int deltaTms);

private:
};

extern Controller_class Controller;

#endif
