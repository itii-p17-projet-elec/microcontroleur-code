#include <Arduino.h>

/* Project includes */
#include "hardware_defines.h"
#include "display/FSMContext.h"


/* ########################################################################## */
/* ########################################################################## */

void loop()
{
    /* set the activity LED on */
    int lLEDPreviousState   = digitalRead(C_PIN_LED_ACTIVITY);
    digitalWrite(C_PIN_LED_ACTIVITY, HIGH);

    Display::FSMContext::Instance()->updateDisplay();

    /* set the activity LED off */
    digitalWrite(C_PIN_LED_ACTIVITY, lLEDPreviousState);

    /* Wait to be woken up */
    delay(1000);
}

/* ########################################################################## */
/* ########################################################################## */
