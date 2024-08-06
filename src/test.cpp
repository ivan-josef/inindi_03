#include <Arduino.h>
#include "InIndKit.h"


AsyncDelay_c delayPOT(100); // time mili second

void setup()
{
    InIndKit.setup("Wokwi-GUEST", "");
    Serial.begin(9600);
}

void loop()
{
    InIndKit.loop();
    if (delayPOT.isExpired())
    {
        delayPOT.repeat();
        const uint16_t pot_left = analogRead(def_pin_POT_LEFT);
        WSerial.println(pot_left);
    }
}