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

/* ########################################################################## */
/* ########################################################################## */

FSMContext::FSMContext(void)
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
    this->m_currentStatePtr = FSMStateDefault::Instance();
}

/* ########################################################################## */
/* ########################################################################## */

void    FSMContext::changeState(FSMAbstractState *pFutureState)
{
    this->m_currentStatePtr->on_state_exit();

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

void FSMContext::updateDisplay()
{
    this->currentState()->updateDisplay();
}

/* ########################################################################## */
/* ########################################################################## */

}   /*< namespace Display */
