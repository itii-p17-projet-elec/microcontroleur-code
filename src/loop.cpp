#include <Arduino.h>

/* Project includes */
#include "hardware_defines.h"
#include "variables_globales.h"

#include "PowerMgmt.h"
#include "comm/protocol/ProtocolManager.h"
#include "common/trace.h"
#include "display/FSMContext.h"


/* ########################################################################## */
/* ########################################################################## */

void    processDelayedEvents_1s(void)
{
    static uint16_t s_delayedEventsCount    = 0;


    g_sensors.update();

    Display::FSMContext::Instance()->update_1s();

    /*
     *  Trigger emission of data to data collection server
     */
    if(     (   s_delayedEventsCount
            %   g_parameters.m_data.sensors_periodicTransmissionDelay_s )
        ==  0 )
    {
        TRACE( __FUNCTION__ );
        TRACELN( " :: Sending data..." );


        Comm::ProtocolManager::Instance()->sendPeriodicMessages();

    }


    s_delayedEventsCount++;
}

/* ########################################################################## */
/* ########################################################################## */

void    processDelayedEvents_50ms(void)
{
    /* If a button has been pressed, raise flag to signal to main loop that
     * something has changed */
    if( g_keypad.updateState() != 0 )
    {
        Display::FSMContext::Instance()
                ->on_button_pressed( g_keypad.lastPressedButton() );
    }


    Display::FSMContext::Instance()->update_50ms();
}

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

        processDelayedEvents_50ms();

        if( g_flag_processDelayedEvents_50ms )
        {
            TRACELN( "WARNING"
                            " : Over-run on 50ms delayed events process !" );
        }
    }


    if( g_flag_processDelayedEvents_1s )
    {
        g_flag_processDelayedEvents_1s  = false;

        processDelayedEvents_1s();

        if( g_flag_processDelayedEvents_1s )
        {
            TRACELN( "WARNING"
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
