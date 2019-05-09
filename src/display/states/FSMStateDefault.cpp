/* Corresponding header inclusion */
#include "FSMStateDefault.h"

/* System includes */

/* Libraries includes */
#include <Arduino.h>

/* Project includes */
#include "../FSMContext.h"
#include "mainMenu/FSMStateMainMenu_View.h"


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
    FSMAbstractState::on_button_pressed(pButtonID);

    Serial.print("StateDefault : Pressed button : ");
    Serial.println( Keypad::buttonName(pButtonID) );


    switch( pButtonID )
    {
        case    Keypad::BUTTON_SELECT:
            FSMContext::Instance()->changeState(
                        FSMStateMainMenu_View::Instance() );
            break;


        default:
            break;
    }
}

/* ########################################################################## */
/* ########################################################################## */

void    FSMStateDefault::on_state_enter(void)
{
    Serial.println( "Entering FSMStateDefault." );
    g_LCD_backlightValue    = 0xFF;
    g_LCD.clear();

    g_LCD.setCursor(0,0);
    g_LCD.print( "FSMStateDefault" );

    g_LCD.setCursor(0,1);
//    g_LCD.print( "Hello, World !" );
}

/* ########################################################################## */
/* ########################################################################## */

void    FSMStateDefault::on_state_exit(void)
{
    g_LCD_backlightValue    = 0xFF;
}

/* ########################################################################## */
/* ########################################################################## */

void    FSMStateDefault::update_1s(void)
{

    g_LCD.setCursor(0,1);
    g_LCD.print( "Upd. cont: " );
    g_LCD.print( this->m_updatesCount++ );
}

/* ########################################################################## */
/* ########################################################################## */

}   /*< namespace Display */
