/* Corresponding header inclusion */
#include "FSMStateMainMenu_View.h"

/* System includes */

/* Libraries includes */
#include <Arduino.h>

/* Project includes */
#include "../../FSMContext.h"
#include "../FSMStateDefault.h"
#include "FSMStateMainMenu_Back.h"
#include "FSMStateMainMenu_Config.h"
#include "view/FSMStateView_TemperatureAmb.h"


namespace Display {

/* ########################################################################## */
/* ########################################################################## */

FSMStateMainMenu_View::FSMStateMainMenu_View(void)
    :   FSMAbstractState()
{

}

/* ########################################################################## */
/* ########################################################################## */

void    FSMStateMainMenu_View::on_button_pressed(const Keypad::TeButtonsID &pButtonID)
{
    FSMAbstractState::on_button_pressed(pButtonID);

    Serial.print("FSMStateMainMenu_View : Pressed button : ");
    Serial.println( Keypad::buttonName(pButtonID) );


    switch( pButtonID )
    {
        case    Keypad::BUTTON_LEFT:
            FSMContext::Instance()->changeState(
                        FSMStateMainMenu_Back::Instance() );
            break;


        case    Keypad::BUTTON_RIGHT:
            FSMContext::Instance()->changeState(
                        FSMStateMainMenu_Config::Instance() );
            break;


        case    Keypad::BUTTON_SELECT:
            FSMContext::Instance()->changeState(
                        FSMStateView_TempAmbiante::Instance() );
            break;


        default:
            break;
    }
}

/* ########################################################################## */
/* ########################################################################## */

void    FSMStateMainMenu_View::on_state_enter(void)
{
    Serial.println( "Entering FSMStateMainMenu_View." );
    g_LCD.clear();

    g_LCD.setCursor(0,0);
    g_LCD.print( "Main menu" );

    g_LCD.setCursor(0,1);
    g_LCD.print( "<     VIEW     >" );
}

/* ########################################################################## */
/* ########################################################################## */

void    FSMStateMainMenu_View::on_state_exit(void)
{
    // TODO
}

/* ########################################################################## */
/* ########################################################################## */

void    FSMStateMainMenu_View::update_1s(void)
{
    //TODO
}

/* ########################################################################## */
/* ########################################################################## */

}   /*< namespace Display */
