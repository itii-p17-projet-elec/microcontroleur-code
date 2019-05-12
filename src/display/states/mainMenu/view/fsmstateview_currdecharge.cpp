/* Corresponding header inclusion */
#include "fsmstateview_currdecharge.h"

/* System includes */

/* Libraries includes */
#include <Arduino.h>

/* Project includes */
#include "variables_globales.h"
#include "display/FSMContext.h"

#include "../FSMStateMainMenu_View.h"
#include "FSMStateView_Back.h"

/* ########################################################################## */
/* ########################################################################## */

FSMStateView_CurrDecharge::FSMStateView_CurrDecharge(void)
    : FSMStateView_AbstractCurr()
    , FSMAbstractState()
{
    return;
}


/* ########################################################################## */
/* ########################################################################## */

void    FSMStateView_CurrDecharge::on_button_pressed(const Keypad::TeButtonsID &pButtonID)
{
    FSMAbstractState::on_button_pressed(pButtonID);

    Serial.print("FSMStateView_CurrDecharge : Pressed button : ");
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

void    FSMStateView_CurrDecharge::on_state_enter(void)
{
    Serial.println( "Entering FSMStateView_CurrDecharge." );
    g_LCD.clear();

    displayOnLCD("< Curr Decharge >", 0, 0);

    this->update_1s();
}

/* ########################################################################## */
/* ########################################################################## */

void    FSMStateView_CurrDecharge::on_state_exit(void)
{
    displayOnLCD((char*)"leaving state", 0, 0);
    displayOnLCD((char*)"Curr Decharge", 0, 1);
    return;
}

/* ########################################################################## */
/* ########################################################################## */

void    FSMStateView_CurrDecharge::update_1s(void)
{
    displayOnLCD((char*)g_sensors.temperature.temperature_degC(), 0, 1, 2); ///////////// NEED g_sensors.current.getCurrentDeload_Amp(); /////////////
    displayOnLCD((char*)" C          ");
}

/* ########################################################################## */
/* ########################################################################## */
