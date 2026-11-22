#ifndef ROBOPROPIN_H
#define ROBOPROPIN_H
/*************************************************
 * MOTORI
 *************************************************/

// MOTORE ANTERIORE DESTRO
#define PIN_MOT_AD1 PB12
#define PIN_MOT_AD2 PB13
#define PIN_PWM_AD PA8 // TIM1_CH1

// Encoder AD
#define PIN_ENC_AD1 PA0 // EXTI0
#define PIN_ENC_AD2 PA1 // EXTI1

// MOTORE POSTERIORE DESTRO
#define PIN_MOT_PD1 PB14
#define PIN_MOT_PD2 PB15
#define PIN_PWM_PD PA9 // TIM1_CH2

// Encoder PD
#define PIN_ENC_PD1 PA5 // EXTI5
#define PIN_ENC_PD2 PA6 // EXTI6

// MOTORE POSTERIORE SINISTRO
#define PIN_MOT_PS1 PA15
#define PIN_MOT_PS2 PB0
#define PIN_PWM_PS PA10 // TIM1_CH3

// Encoder PS
#define PIN_ENC_PS1 PB8 // EXTI8
#define PIN_ENC_PS2 PB9 // EXTI9

// MOTORE ANTERIORE SINISTRO
#define PIN_MOT_AS1 PB1
#define PIN_MOT_AS2 PB2
#define PIN_PWM_AS PB4 // TIM4_CH1

// Encoder AS
#define PIN_ENC_AS1 PA7 // EXTI7
#define PIN_ENC_AS2 PB3 // EXTI3

#endif // ROBOPROPIN_H