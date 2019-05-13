/* Corresponding header inclusion */
#include "FSMStateConfig_EmissionDelay.h"

/* System includes */

/* Libraries includes */
#include <Arduino.h>

/* Project includes */
#include "variables_globales.h"
#include "display/FSMContext.h"

#include "../FSMStateMainMenu_Config.h"
#include "FSMStateConfig_Back.h"
#include "FSMStateConfig_EmissionDelay_Edit.h"


namespace Display {

/* ########################################################################## */
/* ########################################################################## */

FSMStateConfig_EmissionDelay::FSMStateConfig_EmissionDelay(void)
    :   FSMAbstractState()
{

}

/* ########################################################################## */
/* ########################################################################## */

void    FSMStateConfig_EmissionDelay::on_button_pressed(const Keypad::TeButtonsID &pButtonID)
{
    FSMAbstractState::on_button_pressed(pButtonID);

    Serial.print("FSMStateConfig_EmissionDelay : Pressed button : ");
    Serial.println( Keypad::buttonName(pButtonID) );


    switch( pButtonID )
    {
        case    Keypad::BUTTON_LEFT:
            FSMContext::Instance()->changeState(
                        FSMStateConfig_Back::Instance() );
            break;


        case    Keypad::BUTTON_RIGHT:
            FSMContext::Instance()->changeState(
                        FSMStateConfig_Back::Instance() );
            break;


        case    Keypad::BUTTON_SELECT:
            FSMContext::Instance()->changeState(
                        FSMStateConfig_EmissionDelay_Edit::Instance() );
            break;


        case Keypad::BUTTON_DOWN:
            break;


        case Keypad::BUTTON_UP:
            break;


        default:
            break;
    }
}

/* ########################################################################## */
/* ########################################################################## */

void    FSMStateConfig_EmissionDelay::on_state_enter(void)
{
    Serial.println( "Entering FSMStateConfig_EmissionDelay." );
    g_LCD.clear();

    g_LCD.setCursor(0,0);
    g_LCD.print( "< Emit. period >" );

    g_LCD.setCursor(5,1);
    g_LCD.print( g_parameters.m_data.sensors_periodicTransmissionDelay_s );
    g_LCD.print( " s          " );
}

/* ########################################################################## */
/* ########################################################################## */

void    FSMStateConfig_EmissionDelay::on_state_exit(void)
{
    /* Nothing to do */
}

/* ########################################################################## */
/* ########################################################################## */

void    FSMStateConfig_EmissionDelay::update_1s(void)
{
    /* Nothing to do */
}

/* ########################################################################## */
/* ########################################################################## */

}   /*< namespace Display */
