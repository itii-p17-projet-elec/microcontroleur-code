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


    if( g_flag_processDelayedEvents_50ms )
    {
        g_flag_processDelayedEvents_50ms    = false;


        /* If a button has been pressed, raise flag to signal to main loop that
         * something has changed */
        if( g_keypad.updateState() != 0 )
        {
            Display::FSMContext::Instance()
                    ->on_button_pressed( g_keypad.lastPressedButton() );
        }


        Display::FSMContext::Instance()->update_50ms();


        if( g_flag_processDelayedEvents_50ms )
        {
            Serial.println( "WARNING"
                            " : Over-run on 50ms delayed events process !" );
        }
    }


    if( g_flag_processDelayedEvents_1s )
    {
        g_flag_processDelayedEvents_1s  = false;

        Display::FSMContext::Instance()->update_1s();

        if( g_sensors.temperature.readData() != 0 )
        {
            Serial.println("WARN : An error occured while reading temperature"
                           " from AM2320 sensor.");
        }


        if( g_flag_processDelayedEvents_1s )
        {
            Serial.println( "WARNING"
                            " : Over-run on 1s delayed events process !" );
        }
    }



    /* set the activity LED off */
    digitalWrite(C_PIN_LED_ACTIVITY, lLEDPreviousState);

    /* Wait to be woken up */
    PowerMgmt::enterSleep();
}

/* ########################################################################## */
/* ########################################################################## */
