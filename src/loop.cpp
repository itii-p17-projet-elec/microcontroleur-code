#include <Arduino.h>

/* Project includes */
#include "hardware_defines.h"
#include "variables_globales.h"

#include "PowerMgmt.h"
#include "display/FSMContext.h"


/* ########################################################################## */
/* ########################################################################## */

void loop()
{
    /* set the activity LED on */
    int lLEDPreviousState   = digitalRead(C_PIN_LED_ACTIVITY);
    digitalWrite(C_PIN_LED_ACTIVITY, HIGH);



    if( g_flag_keypad )
    {
        /* Reset the flag */
        g_flag_keypad   = false;

        /* Trigger events */
        Display::FSMContext::Instance()
                ->on_button_pressed( g_keypad.lastPressedButton() );
    }

    Display::FSMContext::Instance()->updateDisplay();

    /* set the activity LED off */
    digitalWrite(C_PIN_LED_ACTIVITY, lLEDPreviousState);

    /* Wait to be woken up */
    PowerMgmt::enterSleep();
}

/* ########################################################################## */
/* ########################################################################## */
