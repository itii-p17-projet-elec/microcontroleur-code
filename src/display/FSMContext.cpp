/* Corresponding header inclusion */
#include "FSMContext.h"

/* System includes */
#include <Arduino.h>

/* Libraries includes */

/* Project includes */
#include "FSMAbstractState.h"
#include "hardware_defines.h"
#include "states/FSMStateDefault.h"


namespace Display {

/* ########################################################################## */
/* ########################################################################## */

LiquidCrystal   g_LCD( C_PIN_LCD_RS,
                       C_PIN_LCD_EN,
                       C_PIN_LCD_D0,
                       C_PIN_LCD_D1,
                       C_PIN_LCD_D2,
                       C_PIN_LCD_D3 );


/**
 *  @brief  This variable holds the current PWM value of the LCD backlight.
 */
uint8_t          g_LCD_backlightValue   = 0xFF;

/* ########################################################################## */
/* ########################################################################## */

FSMContext::FSMContext(void)
    :   m_currentStatePtr( nullptr )
{
    /* Initialize LCD */
    g_LCD.begin(16, 2);
    g_LCD.print("Polytech'Nice");
    g_LCD.setCursor(0,1);
    g_LCD.print("ITII-EII-P17");
    delay(1000);
    g_LCD.clear();
    g_LCD.home();


    /* Set the default state of the UI */
    FSMStateDefault::Instance();
    this->changeState( (FSMAbstractState*) FSMStateDefault::Instance() );
}

/* ########################################################################## */
/* ########################################################################## */

void    FSMContext::changeState(FSMAbstractState *pFutureState)
{
    Serial.println( "FSMContext : Entering changeState." );
    /*
     *  Verify pre-requisites
     */
    /* Refuse to go to a null state */
    if( pFutureState == 0 )
    {
        Serial.println( "ERR Future state is null !" );
        return;
    }


    /* Do not change state if it's the same as the current one */
    if( pFutureState == this->m_currentStatePtr )
    {
        Serial.println( "ERR Future state is current state !" );
        return;
    }


    /*
     *  Go to new state
     */
    if( this->m_currentStatePtr != 0 )
    {
        this->m_currentStatePtr->on_state_exit();
    }

    this->m_currentStatePtr = pFutureState;
    this->m_currentStatePtr->on_state_enter();
}

/* ########################################################################## */
/* ########################################################################## */

FSMAbstractState*   FSMContext::currentState(void) const
{
    return this->m_currentStatePtr;
}

/* ########################################################################## */
/* ########################################################################## */

void    FSMContext::on_button_pressed(const Keypad::TeButtonsID &pButtonID)
{
    if( this->currentState() != nullptr )
    {
        this->currentState()->on_button_pressed(pButtonID);
    }
}

/* ########################################################################## */
/* ########################################################################## */

void    FSMContext::update_1s()
{
    if( this->currentState() != nullptr )
    {
        this->currentState()->update_1s();
    }
}

/* ########################################################################## */
/* ########################################################################## */

void    FSMContext::update_50ms()
{
    if( this->currentState() != nullptr )
    {
        this->currentState()->update_50ms();
    }


    analogWrite( C_PIN_LCD_BACKLIGHT, g_LCD_backlightValue );
}

/* ########################################################################## */
/* ########################################################################## */

}   /*< namespace Display */
