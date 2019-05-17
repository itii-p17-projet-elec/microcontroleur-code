/* System includes */

/* Libraries includes */
#include <Arduino.h>

/* Project includes */
#include "hardware_defines.h"
#include "variables_globales.h"
#include "comm/interface/IfaceLoRa.h"
#include "comm/protocol/ProtocolManager.h"
#include "comm/protocol/messages/AMBTMP.h"
#include "comm/protocol/messages/BATIIN.h"
#include "comm/protocol/messages/BATIOU.h"
#include "comm/protocol/messages/BATTMP.h"
#include "comm/protocol/messages/BATVIN.h"
#include "comm/protocol/messages/BATVOU.h"
#include "common/trace.h"
#include "display/FSMContext.h"


/* ########################################################################## */
/* ########################################################################## */
/*
 *  Forward declarations
 */
void    setup_commInterfaces(void);
void    setup_commProtocol(void);
void    setup_parameters(void);
void    setup_pins(void);
void    setup_timer1(void);

/* ########################################################################## */
/* ########################################################################## */

void    setup(void)
{
    setup_pins();

    setup_commInterfaces();

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

void    setup_commInterfaces(void)
{
    Comm::Interface::IfaceSerial::Instance()->initialize();

    // prints title with ending line break
    TRACELN("\n~~~ Hello, World ! ~~~");
}

/* ########################################################################## */
/* ########################################################################## */

void    setup_commProtocol(void)
{
    /*
     *  Define the communication interface on which to send messages
     */
    Comm::ProtocolManager::Instance()->setInterface(
                Comm::Interface::IfaceLoRa::Instance() );


    /*
     *  Declare all periodic message factories
     */
    Comm::ProtocolManager::Instance()->addPeriodicMessage(
                Comm::Messages::AMBTMP::Instance() );

    Comm::ProtocolManager::Instance()->addPeriodicMessage(
                Comm::Messages::BATIIN::Instance() );

    Comm::ProtocolManager::Instance()->addPeriodicMessage(
                Comm::Messages::BATIOU::Instance() );

    Comm::ProtocolManager::Instance()->addPeriodicMessage(
                Comm::Messages::BATTMP::Instance() );

    Comm::ProtocolManager::Instance()->addPeriodicMessage(
                Comm::Messages::BATVIN::Instance() );

    Comm::ProtocolManager::Instance()->addPeriodicMessage(
                Comm::Messages::BATVOU::Instance() );
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
