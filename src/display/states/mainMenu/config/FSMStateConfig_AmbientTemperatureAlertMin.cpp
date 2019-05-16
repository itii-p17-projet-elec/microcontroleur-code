/* Corresponding header inclusion */
#include "FSMStateConfig_AmbientTemperatureAlertMin.h"

/* System includes */

/* Libraries includes */
#include <Arduino.h>

/* Project includes */
#include "variables_globales.h"
#include "display/FSMContext.h"


#include "FSMStateConfig_AmbientTemperatureAlertMin_Edit.h"
#include "FSMStateConfig_Back.h"
#include "FSMStateConfig_EmissionDelay.h"


namespace Display {

/* ########################################################################## */
/* ########################################################################## */

FSMStateConfig_AmbientTemperatureAlertMin::FSMStateConfig_AmbientTemperatureAlertMin(void)
{

}

/* ########################################################################## */
/* ########################################################################## */

void    FSMStateConfig_AmbientTemperatureAlertMin::on_button_pressed(const Keypad::TeButtonsID &pButtonID)
{
    FSMAbstractState::on_button_pressed(pButtonID);

    Serial.print("FSMStateConfig_AmbientTemperatureAlertMin : Pressed button : ");
    Serial.println( Keypad::buttonName(pButtonID) );


    switch( pButtonID )
    {
        case    Keypad::BUTTON_LEFT:
            FSMContext::Instance()->changeState(
                        FSMStateConfig_EmissionDelay::Instance() );
            break;


        case    Keypad::BUTTON_RIGHT:
            FSMContext::Instance()->changeState(
                        FSMStateConfig_Back::Instance() );
            break;


        case    Keypad::BUTTON_SELECT:
            FSMContext::Instance()->changeState(
                        FSMStateConfig_AmbientTemperatureAlertMin_Edit::Instance() );
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

void    FSMStateConfig_AmbientTemperatureAlertMin::on_state_enter(void)
{
    Serial.println( "Entering FSMStateConfig_AmbientTemperatureAlertMin." );
    g_LCD.clear();

    g_LCD.setCursor(0,0);
    g_LCD.print( "< AMBTMP A. Min>" );

    g_LCD.setCursor(5,1);
    g_LCD.print( g_parameters.m_data.ambientTemperature_alertMin );
    g_LCD.print( " deg C          " );
}

/* ########################################################################## */
/* ########################################################################## */

void    FSMStateConfig_AmbientTemperatureAlertMin::on_state_exit(void)
{
    /* Nothing to do */
}

/* ########################################################################## */
/* ########################################################################## */

void    FSMStateConfig_AmbientTemperatureAlertMin::update_1s(void)
{
    /* Nothing to do */
}

/* ########################################################################## */
/* ########################################################################## */

} // namespace Display
