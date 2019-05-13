/* Corresponding header inclusion */
#include "fsmstateview_tempambiante.h"

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

FSMStateView_TempAmbiante::FSMStateView_TempAmbiante(void)
    : FSMStateView_AbstractT()
    , FSMAbstractState()
{
    return;
}

/* ########################################################################## */
/* ########################################################################## */

void    FSMStateView_TempAmbiante::on_button_pressed(const Keypad::TeButtonsID &pButtonID)
{
    FSMAbstractState::on_button_pressed(pButtonID);

    Serial.print("FSMStateView_TempAmbiante : Pressed button : ");
    Serial.println( Keypad::buttonName(pButtonID) );


    switch( pButtonID )
    {
        case    Keypad::BUTTON_LEFT:
            FSMContext::Instance()->changeState(
                        FSMStateView_PercentageLoadBatt::Instance() );
            break;


        case    Keypad::BUTTON_RIGHT:
            FSMContext::Instance()->changeState(
                        FSMStateView_TempBatt::Instance() );
            break;



        case    Keypad::BUTTON_UP:
            FSMContext::Instance()->changeState(
                        FSMStateMainMenu_View::Instance());


        default:
            break;
    }
}

/* ########################################################################## */
/* ########################################################################## */

void    FSMStateView_TempAmbiante::on_state_enter(void)
{
    Serial.println( "Entering FSMStateView_TempAmbiante." );
    g_LCD.clear();

    displayOnLCD("< Ambient temp >", 0, 0);

    this->update_1s();
}

/* ########################################################################## */
/* ########################################################################## */

void    FSMStateView_TempAmbiante::on_state_exit(void)
{
    displayOnLCD((char*)"leaving state", 0, 0);
    displayOnLCD((char*)"TempAmb", 0, 1);
    return;
}

/* ########################################################################## */
/* ########################################################################## */

void    FSMStateView_TempAmbiante::update_1s(void)
{
    displayOnLCD(g_sensors.temperature.temperature_degC(), 0, 1, 2);
    displayOnLCD((char*)" C          " );
}



/* ########################################################################## */
/* ########################################################################## */
