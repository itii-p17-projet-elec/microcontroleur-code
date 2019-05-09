/* System includes */
#include <Arduino.h>

/* Libraries includes */

/* Project includes */
#include "hardware_defines.h"
#include "variables_globales.h"


/* ########################################################################## */
/* ########################################################################## */

static unsigned int s_interrupts_count  = 0U;

/* ########################################################################## */
/* ########################################################################## */
/**
 *  @brief  This function is called when an interrupt is generated by timer1.
 *
 *  @warning    NO PRINT IN INTERRUPT SERVICE ROUTINES !
 */
ISR(TIMER1_OVF_vect)        // interrupt service routine
{
    /* Immediately reset timer to limit drifts */
    TCNT1   = C_TIMER1_COUNTER_PRELOAD; // preload timer


    /* set the activity LED on */
    int lLEDPreviousState   = digitalRead(C_PIN_LED_ACTIVITY);
    digitalWrite(C_PIN_LED_ACTIVITY, HIGH);


    ++s_interrupts_count;


    /* set the activity LED off */
    digitalWrite(C_PIN_LED_ACTIVITY, lLEDPreviousState);
}

/* ########################################################################## */
/* ########################################################################## */
