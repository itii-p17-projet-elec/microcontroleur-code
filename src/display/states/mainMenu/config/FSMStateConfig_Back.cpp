/* Corresponding header inclusion */
#include "FSMStateConfig_Back.h"

/* System includes */

/* Libraries includes */
#include <Arduino.h>

/* Project includes */
#include "variables_globales.h"
#include "display/FSMContext.h"

#include "../FSMStateMainMenu_Config.h"
#include "FSMStateConfig_EmissionDelay.h"


namespace Display {

/* ########################################################################## */
/* ########################################################################## */

FSMStateConfig_Back::FSMStateConfig_Back(void)
    :   FSMAbstractState()
{

}

/* ########################################################################## */
/* ########################################################################## */

void    FSMStateConfig_Back::on_button_pressed(const Keypad::TeButtonsID &pButtonID)
{
    FSMAbstractState::on_button_pressed(pButtonID);

    Serial.print("FSMStateConfig_Back : Pressed button : ");
    Serial.println( Keypad::buttonName(pButtonID) );


    switch( pButtonID )
    {
        case    Keypad::BUTTON_LEFT:
            FSMContext::Instance()->changeState(
                        FSMStateConfig_EmissionDelay::Instance() );
            break;


        case    Keypad::BUTTON_RIGHT:
            FSMContext::Instance()->changeState(
                        FSMStateConfig_EmissionDelay::Instance() );
            break;


        case    Keypad::BUTTON_SELECT:
            FSMContext::Instance()->changeState(
                        FSMStateMainMenu_Config::Instance() );
            break;


        default:
            break;
    }
}

/* ########################################################################## */
/* ########################################################################## */

void    FSMStateConfig_Back::on_state_enter(void)
{
    Serial.println( "Entering FSMStateConfig_Back." );
    g_LCD.clear();

    g_LCD.setCursor(0,0);
    g_LCD.print( "<   Back to    >" );
    g_LCD.setCursor(0,1);
    g_LCD.print( "   Main menu    " );

    this->update_1s();
}

/* ########################################################################## */
/* ########################################################################## */

void    FSMStateConfig_Back::on_state_exit(void)
{
    // TODO
}

/* ########################################################################## */
/* ########################################################################## */

void    FSMStateConfig_Back::update_1s(void)
{
}

/* ########################################################################## */
/* ########################################################################## */

}   /*< namespace Display */
