/* System includes */

/* Libraries includes */
#include <Arduino.h>

/* Project includes */
#include "hardware_defines.h"
#include "variables_globales.h"
#include "comm/protocol/ProtocolManager.h"
#include "comm/protocol/messages/AMBTMP.h"
#include "comm/protocol/messages/BATICH.h"
#include "comm/protocol/messages/BATTMP.h"
#include "display/FSMContext.h"


/* ########################################################################## */
/* ########################################################################## */
/*
 *  Forward declarations
 */
void    setup_commProtocol(void);
void    setup_parameters(void);
void    setup_pins(void);
void    setup_serial(void);
void    setup_timer1(void);

/* ########################################################################## */
/* ########################################################################## */

void    setup_commProtocol(void)
{
    Comm::ProtocolManager::Instance()->addPeriodicMessage(
                Comm::Messages::AMBTMP::Instance() );

    Comm::ProtocolManager::Instance()->addPeriodicMessage(
                Comm::Messages::BATICH::Instance() );

    Comm::ProtocolManager::Instance()->addPeriodicMessage(
                Comm::Messages::BATTMP::Instance() );
}

/* ########################################################################## */
/* ########################################################################## */

void    setup(void)
{
    setup_pins();

    setup_serial();

    setup_parameters();


    g_sensors.initialize();


    /* Initialize the display by creating the FSM singleton instance */
    Display::FSMContext::Instance();


    setup_commProtocol();


    /* This shall be done at last as it enables interrupts */
    setup_timer1();
    digitalWrite(C_PIN_LED_ACTIVITY, LOW);
}

/* ########################################################################## */
/* ########################################################################## */

void    setup_parameters(void)
{
    g_parameters.initialize();
    g_EEPROM.loadData();
}

/* ########################################################################## */
/* ########################################################################## */

void    setup_pins(void)
{
    pinMode(C_PIN_KEYPAD_SW, INPUT);

    pinMode(C_PIN_LCD_BACKLIGHT, OUTPUT);
    pinMode(C_PIN_LED_ACTIVITY, OUTPUT);


    digitalWrite(C_PIN_LCD_BACKLIGHT, HIGH);
}

/* ########################################################################## */
/* ########################################################################## */

void    setup_serial(void)
{
    //Initialize serial and wait for port to open:
    Serial.begin(115200);
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
