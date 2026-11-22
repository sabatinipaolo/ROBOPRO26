#ifndef OLED_HPP
#define OLED_HPP

#include <Adafruit_SSD1306.h>
#include <Wire.h>

#define OLED_I2C_ADDR 0x3C

class Oled_class : public Adafruit_SSD1306
{

public:
    static constexpr int OLED_RESET = -1;
    Oled_class() : Adafruit_SSD1306(128, 32, &Wire, OLED_RESET) {};
    bool begin();
    void stampa4float(float f1, float f2, float f3, float f4);

private:
};

extern Oled_class Oled;

#endif