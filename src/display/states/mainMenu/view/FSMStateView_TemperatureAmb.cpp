/* Corresponding header inclusion */
#include "FSMStateView_TemperatureAmb.h"

/* System includes */

/* Libraries includes */
#include <Arduino.h>

/* Project includes */
#include "variables_globales.h"
#include "display/FSMContext.h"

#include "../FSMStateMainMenu_View.h"
#include "FSMStateView_Back.h"


namespace Display {

/* ########################################################################## */
/* ########################################################################## */

FSMStateView_TemperatureAmb::FSMStateView_TemperatureAmb(void)
    :   FSMAbstractState()
{

}

/* ########################################################################## */
/* ########################################################################## */

void    FSMStateView_TemperatureAmb::on_button_pressed(const Keypad::TeButtonsID &pButtonID)
{
    FSMAbstractState::on_button_pressed(pButtonID);

    Serial.print("FSMStateView_TemperatureAmb : Pressed button : ");
    Serial.println( Keypad::buttonName(pButtonID) );


    switch( pButtonID )
    {
        case    Keypad::BUTTON_LEFT:
            FSMContext::Instance()->changeState(
                        FSMStateView_Back::Instance() );
            break;


        case    Keypad::BUTTON_RIGHT:
            FSMContext::Instance()->changeState(
                        FSMStateView_Back::Instance() );
            break;


        default:
            break;
    }
}

/* ########################################################################## */
/* ########################################################################## */

void    FSMStateView_TemperatureAmb::on_state_enter(void)
{
    Serial.println( "Entering FSMStateView_TemperatureAmb." );
    g_LCD.clear();

    g_LCD.setCursor(0,0);
    g_LCD.print( "< Ambient temp >" );

    this->update_1s();
}

/* ########################################################################## */
/* ########################################################################## */

void    FSMStateView_TemperatureAmb::on_state_exit(void)
{
    // TODO
}

/* ########################################################################## */
/* ########################################################################## */

void    FSMStateView_TemperatureAmb::update_1s(void)
{
    g_LCD.setCursor(0,1);
    g_LCD.print( g_sensors.temperature.temperature_degC(), 2 );
    g_LCD.print( " C          " );
}

/* ########################################################################## */
/* ########################################################################## */

}   /*< namespace Display */
