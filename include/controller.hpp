#ifndef CONTROLLER_HPP
#define CONTROLLER_HPP

class Controller_class
{
public:
    Controller_class();
    void init();

    void stop();

    void trasla_nord(int pwm);
    void trasla_nord_est(int pwm);
    void trasla_est(int pwm);
    void trasla_sud_est(int pwm);
    void trasla_sud(int pwm);
    void trasla_sud_ovest(int pwm );
    void trasla_ovest(int pwm);
    void trasla_nord_ovest(int pwm);
    
    // 4 ISR static
    static void ISR_encoder_Motore_AD();
    static void ISR_encoder_Motore_PD();
    static void ISR_encoder_Motore_PS();
    static void ISR_encoder_Motore_AS();

    static void aggiorna_RPM_dei_quattro_motori();

private:
};

extern Controller_class Controller;

#endif
