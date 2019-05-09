/* System includes */

/* Libraries includes */
#include <Arduino.h>

/* Project includes */
#include "hardware_defines.h"
#include "variables_globales.h"
#include "display/FSMContext.h"


/* ########################################################################## */
/* ########################################################################## */
/*
 *  Forward declarations
 */
void    setup_pins(void);
void    setup_serial(void);
void    setup_timer1(void);

/* ########################################################################## */
/* ########################################################################## */

void    setup(void)
{
    setup_pins();

    setup_serial();


    /* Initialize the display by creating the FSM singleton instance */
    Display::FSMContext::Instance();


    /* This shall be done at last as it enables interrupts */
    setup_timer1();
}

/* ########################################################################## */
/* ########################################################################## */

void    setup_pins(void)
{
    pinMode(C_PIN_LED, OUTPUT);
}

/* ########################################################################## */
/* ########################################################################## */

void    setup_serial(void)
{
    //Initialize serial and wait for port to open:
    Serial.begin(9600);
    while (!Serial)
    {
        ; // wait for serial port to connect. Needed for Leonardo only
    }

    // prints title with ending line break
    Serial.println("\n~~~ Hello, World ! ~~~");
}

/* ########################################################################## */
/* ########################################################################## */

void    setup_timer1(void)
{
    // initialize timer1
    TCCR1A = 0;
    TCCR1B = 0;

    TCNT1   = C_TIMER1_COUNTER_PRELOAD;   // preload timer
    TCCR1B  |= (1 << CS12);    // 256 prescaler

    /* Enable timer 1 overflow interrupt */
    TIMSK1  |= (1 << TOIE1);   // enable timer overflow interrupt
}

/* ########################################################################## */
/* ########################################################################## */
