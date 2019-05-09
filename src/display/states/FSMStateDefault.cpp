/* Corresponding header inclusion */
#include "FSMStateDefault.h"

/* System includes */

/* Libraries includes */
#include <Arduino.h>

/* Project includes */
#include "../FSMContext.h"


namespace Display {

/* ########################################################################## */
/* ########################################################################## */

FSMStateDefault::FSMStateDefault(void)
    :   m_updatesCount( 0 )
{

}

/* ########################################################################## */
/* ########################################################################## */

void    FSMStateDefault::on_button_pressed(const Keypad::TeButtonsID &pButtonID)
{
    Serial.print("StateDefault : Pressed button : ");
    Serial.println( Keypad::buttonName(pButtonID) );
}

/* ########################################################################## */
/* ########################################################################## */

void    FSMStateDefault::on_state_enter(void)
{
    Serial.println( "Entering state Default." );
    g_LCD.clear();

    g_LCD.setCursor(0,0);
    g_LCD.print( "FSMStateDefault" );

    g_LCD.setCursor(0,1);
    g_LCD.print( "Hello, World !" );
}

/* ########################################################################## */
/* ########################################################################## */

void    FSMStateDefault::on_state_exit(void)
{
    // TODO
}

/* ########################################################################## */
/* ########################################################################## */

void    FSMStateDefault::updateDisplay(void)
{

    g_LCD.setCursor(0,1);
    g_LCD.print( "Upd. cont: " );
    g_LCD.print( this->m_updatesCount++ );
}

/* ########################################################################## */
/* ########################################################################## */

}   /*< namespace Display */
