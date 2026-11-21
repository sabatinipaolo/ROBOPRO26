#ifndef ROBOPROPIN_H
#define ROBOPROPIN_H
/*************************************************
 * MOTORI – PWM + DIR (TIM1)
 *************************************************/

// ANTERIORE DESTRO
#define PIN_MOT_AD1       PB12
#define PIN_MOT_AD2       PB13
#define PIN_PWM_AD        PA8    // TIM1_CH1

// POSTERIORE DESTRO
#define PIN_MOT_PD1       PB14
#define PIN_MOT_PD2       PB15
#define PIN_PWM_PD        PA9    // TIM1_CH2

// POSTERIORE SINISTRO
#define PIN_MOT_PS1       PA15
#define PIN_MOT_PS2       PB0
#define PIN_PWM_PS        PA10   // TIM1_CH3

// ANTERIORE SINISTRO
#define PIN_MOT_AS1       PB1
#define PIN_MOT_AS2       PB2
#define PIN_PWM_AS        PB4    // TIM4_CH1


#endif // ROBOPROPIN_H