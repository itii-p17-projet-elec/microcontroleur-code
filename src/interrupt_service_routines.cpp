/* System includes */
#include <Arduino.h>

/* Libraries includes */

/* Project includes */
#include "hardware_defines.h"
#include "variables_globales.h"


/* ########################################################################## */
/* ########################################################################## */

static unsigned int s_interrupts_count  = 0U;

ISR(TIMER1_OVF_vect)        // interrupt service routine
{
    /* Reset timer */
    TCNT1   = g_timer1_counterPreload;   // preload timer


    digitalWrite(C_PIN_LED, HIGH);   // set the LED on
    Serial.println( ++s_interrupts_count );


    // This delay is here just to let us see the LED blink - but it's bad habit!
    digitalWrite(C_PIN_LED, LOW);
}

/* ########################################################################## */
/* ########################################################################## */
