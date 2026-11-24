#include <Arduino.h>
#include "controller.hpp"
#include "motori.hpp"
#include "robopropin.h"

constexpr float radice2_su2 = 0.70710678118654752440084436210485;
constexpr float pi = 3.14159265358979323846;
constexpr float quarantacinque_rad = 45 * pi / 180.0f;


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

void Controller_class::stop(){
        for (int i=0 ; i<4; i++) 
            Motori[i].stop();
    }


/* adottata convenzione  ROS vedi: https://control.ros.org/rolling/doc/ros2_controllers/doc/mobile_robot_kinematics.html#omnidirectional-wheeled-mobile-robots
                          ^  x
              alpha >0   =0    alpha<0
                          |
          mot_0    +      |      -    mot_3
                  /       |       \
                 -        |        +
     y                    |
    <---------------------+----------------        
                          |     
                          |        
          mot_1  +        |        -  mot_2
                  \       |       / 
                   -      |      +
*/

void Controller_class::trasla(float alfa, int velocita)
{   //TODO: ottimizzare 
    
    float alfa_rad = alfa * pi / 180.0f;

    float cosa = cos(alfa_rad + quarantacinque_rad);
    float sina = sin(alfa_rad + quarantacinque_rad);

    int vad = static_cast<int>(-velocita * radice2_su2 * sina);
    int vps = -vad;

    int vas = static_cast<int>(velocita * radice2_su2 * cosa);
    int vpd = -vas;

    Motore_AD.muovi(vad);
    Motore_PD.muovi(vpd);
    Motore_AS.muovi(vas);
    Motore_PS.muovi(vps);
}



/*            N
         NO   |   NE
            \   /
       O   --   --   E
            /   \
         SO   |   SE
              S  
*/

void Controller_class::trasla_nord(int pwm){
    Motore_AS.muovi(pwm);
    Motore_PS.muovi(pwm);
    Motore_PD.muovi(-pwm);
    Motore_AD.muovi(-pwm);
};

void Controller_class::trasla_nord_est(int pwm){
    Motore_AS.muovi(pwm);
    Motore_PS.muovi(0);
    Motore_PD.muovi(-pwm);
    Motore_AD.muovi(0);
};

void Controller_class::trasla_est(int pwm){
    Motore_AS.muovi(pwm);
    Motore_PS.muovi(-pwm);
    Motore_PD.muovi(-pwm);
    Motore_AD.muovi(pwm);  
};

void Controller_class::trasla_sud_est(int pwm){
    Motore_AS.stop();
    Motore_PS.muovi(-pwm);
    Motore_PD.stop();
    Motore_AD.muovi(pwm);  
};

void Controller_class::trasla_sud(int pwm)
{
    Motore_AS.muovi(-pwm);
    Motore_PS.muovi(-pwm);
    Motore_PD.muovi(pwm);
    Motore_AD.muovi(pwm);
};

void Controller_class::trasla_sud_ovest(int pwm)
{
    Motore_AS.muovi(-pwm);
    Motore_PS.muovi(0);
    Motore_PD.muovi(pwm);
    Motore_AD.muovi(0);
};

void Controller_class::trasla_ovest(int pwm)
{
    Motore_AS.muovi(-pwm);
    Motore_PS.muovi(pwm);
    Motore_PD.muovi(pwm);
    Motore_AD.muovi(-pwm);
};

void Controller_class::trasla_nord_ovest(int pwm){
    Motore_AS.stop();
    Motore_PS.muovi(pwm);
    Motore_PD.stop();
    Motore_AD.muovi(-pwm);  
};



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

void Controller_class::aggiorna_RPM_dei_quattro_motori()
{ // dura circa 7 -8  us (microsecondi) //TODO: verificare
    for (int i = 0; i < 4; i++)
    {
        Motori[i].aggiorna_lettura_rpm();
    }
}

Controller_class Controller;
