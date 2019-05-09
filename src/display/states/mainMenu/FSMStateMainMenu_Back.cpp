/* Corresponding header inclusion */
#include "FSMStateMainMenu_Back.h"

/* System includes */

/* Libraries includes */
#include <Arduino.h>

/* Project includes */
#include "../../FSMContext.h"
#include "FSMStateMainMenu_Config.h"
#include "FSMStateMainMenu_View.h"
#include "../FSMStateDefault.h"


namespace Display {

/* ########################################################################## */
/* ########################################################################## */

FSMStateMainMenu_Back::FSMStateMainMenu_Back(void)
    :   FSMAbstractState()
{

}

/* ########################################################################## */
/* ########################################################################## */

void    FSMStateMainMenu_Back::on_button_pressed(const Keypad::TeButtonsID &pButtonID)
{
    FSMAbstractState::on_button_pressed(pButtonID);

    Serial.print("FSMStateMainMenu_Back : Pressed button : ");
    Serial.println( Keypad::buttonName(pButtonID) );


    switch( pButtonID )
    {
        case    Keypad::BUTTON_LEFT:
            FSMContext::Instance()->changeState(
                        FSMStateMainMenu_Config::Instance() );
            break;


        case    Keypad::BUTTON_RIGHT:
            FSMContext::Instance()->changeState(
                        FSMStateMainMenu_View::Instance() );
            break;


        case    Keypad::BUTTON_SELECT:
            FSMContext::Instance()->changeState(
                        FSMStateDefault::Instance() );
            break;


        default:
            break;
    }
}

/* ########################################################################## */
/* ########################################################################## */

void    FSMStateMainMenu_Back::on_state_enter(void)
{
    Serial.println( "Entering FSMStateMainMenu_Back." );
    g_LCD.clear();

    g_LCD.setCursor(0,0);
    g_LCD.print( "Main menu" );

    g_LCD.setCursor(0,1);
    g_LCD.print( "<     Back     >" );
}

/* ########################################################################## */
/* ########################################################################## */

void    FSMStateMainMenu_Back::on_state_exit(void)
{
    // TODO
}

/* ########################################################################## */
/* ########################################################################## */

void    FSMStateMainMenu_Back::update_1s(void)
{
    //TODO
}

/* ########################################################################## */
/* ########################################################################## */

}   /*< namespace Display */
