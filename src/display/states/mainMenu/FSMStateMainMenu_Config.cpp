/* Corresponding header inclusion */
#include "FSMStateMainMenu_Config.h"

/* System includes */

/* Libraries includes */
#include <Arduino.h>

/* Project includes */
#include "../../FSMContext.h"
#include "FSMStateMainMenu_Back.h"
#include "FSMStateMainMenu_View.h"


namespace Display {

/* ########################################################################## */
/* ########################################################################## */

FSMStateMainMenu_Config::FSMStateMainMenu_Config(void)
    :   FSMAbstractState()
{

}

/* ########################################################################## */
/* ########################################################################## */

void    FSMStateMainMenu_Config::on_button_pressed(const Keypad::TeButtonsID &pButtonID)
{
    FSMAbstractState::on_button_pressed(pButtonID);

    Serial.print("FSMStateMainMenu_Config : Pressed button : ");
    Serial.println( Keypad::buttonName(pButtonID) );


    switch( pButtonID )
    {
        case    Keypad::BUTTON_LEFT:
            FSMContext::Instance()->changeState(
                        FSMStateMainMenu_View::Instance() );
            break;


        case    Keypad::BUTTON_RIGHT:
            FSMContext::Instance()->changeState(
                        FSMStateMainMenu_Back::Instance() );
            break;


        case    Keypad::BUTTON_SELECT:
            // TODO
            break;


        default:
            break;
    }
}

/* ########################################################################## */
/* ########################################################################## */

void    FSMStateMainMenu_Config::on_state_enter(void)
{
    Serial.println( "Entering FSMStateMainMenu_Config." );
    g_LCD.clear();

    g_LCD.setCursor(0,0);
    g_LCD.print( "Main menu" );

    g_LCD.setCursor(0,1);
    g_LCD.print( "<    CONFIG    >" );
}

/* ########################################################################## */
/* ########################################################################## */

void    FSMStateMainMenu_Config::on_state_exit(void)
{
    // TODO
}

/* ########################################################################## */
/* ########################################################################## */

void    FSMStateMainMenu_Config::update_1s(void)
{
    //TODO
}

/* ########################################################################## */
/* ########################################################################## */

}   /*< namespace Display */
