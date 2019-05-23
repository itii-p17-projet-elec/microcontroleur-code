#include <Arduino.h>

#include "hardware_defines.h"



void setup()
{
  pinMode(C_PIN_LED_ACTIVITY,   OUTPUT);

  while (!Serial);
  Serial.begin(115200);
  delay(100);

  Serial.println("Arduino LEDs fade demo");
}

void loop()
{
    static uint8_t  s_val = 0;

    Serial.println("Starting loop...");

    s_val   = 0;
    while( s_val < 250U )
    {
        analogWrite(C_PIN_LED_ACTIVITY, s_val );
        delay(1);

        ++s_val;
    }


    s_val   = 250U;
    while(s_val > 0)
    {
        analogWrite(C_PIN_LED_ACTIVITY, s_val );
        delay(1);

        --s_val;
    }
}
