/* System includes */

/* Libraries includes */
#include <Arduino.h>

/* Project includes */
#include "hardware_defines.h"
#include "variables_globales.h"


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
    noInterrupts();           // disable all interrupts
    TCCR1A = 0;
    TCCR1B = 0;

    // Set timer1_counter to the correct value for our interrupt interval
    //timer1_counter = 64911;   // preload timer 65536-16MHz/256/100Hz
    //timer1_counter = 64286;   // preload timer 65536-16MHz/256/50Hz
//    timer1_counterPreload = 34286;   // preload timer 65536-16MHz/256/2Hz
    g_timer1_counterPreload = 49910;   // preload timer 65536-16MHz/256/2Hz

    TCNT1 = g_timer1_counterPreload;   // preload timer
//    TCCR1B |= (1 << CS12);    // 256 prescaler
    // 1024 prescaler
    TCCR1B |= (1 << CS12);    // 1024 prescaler
    TCCR1B |= (1 << CS10);    // 1024 prescaler
    TIMSK1 |= (1 << TOIE1);   // enable timer overflow interrupt
    interrupts();             // enable all interrupts
}

/* ########################################################################## */
/* ########################################################################## */
