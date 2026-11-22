#include <Arduino.h>
#include "oled.hpp"

void setup()
{
    Serial.begin(9600);

    Oled.begin();
}

void loop()
{
    Serial.print("OLED TEST ");
    Oled.stampa4float(2.0, 3.0, 4.0, 5.0);
    delay(2000);
    Oled.clearDisplay();
    Oled.display();
    delay(2000);
}
