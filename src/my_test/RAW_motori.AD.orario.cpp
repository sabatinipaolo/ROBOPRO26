#include <Arduino.h>
#include <robopropin.h>

void setup() {
  
    pinMode(PIN_MOT_AD1,OUTPUT);
    pinMode(PIN_MOT_AD2,OUTPUT);
    pinMode(PIN_PWM_AD,OUTPUT);

    analogWrite(PIN_PWM_AD,0);
    digitalWrite(PIN_MOT_AD1,0);
    digitalWrite(PIN_MOT_AD2,1);
    analogWrite(PIN_PWM_AD,255);
    
}

void loop() {

}


