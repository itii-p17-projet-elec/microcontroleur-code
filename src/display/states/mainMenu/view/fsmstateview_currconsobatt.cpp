/* Corresponding header inclusion */
#include "fsmstateview_currconsobatt.h"

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

FSMStateView_CurrConsoBatt::FSMStateView_CurrConsoBatt(void)
    : FSMStateView_AbstractCurr()
    , FSMAbstractState()
{
    return;
}


/* ########################################################################## */
/* ########################################################################## */

void    FSMStateView_CurrConsoBatt::on_button_pressed(const Keypad::TeButtonsID &pButtonID)
{
    FSMAbstractState::on_button_pressed(pButtonID);

    Serial.print("FSMStateView_CurrConsoBatt : Pressed button : ");
    Serial.println( Keypad::buttonName(pButtonID) );


    switch( pButtonID )
    {
        case    Keypad::BUTTON_LEFT:
            FSMContext::Instance()->changeState(
                        FSMStateView_CurrDecharge::Instance() );
            break;


        case    Keypad::BUTTON_RIGHT:
            FSMContext::Instance()->changeState(
                        FSMStateView_Voltage::Instance() );
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

void    FSMStateView_CurrConsoBatt::on_state_enter(void)
{
    Serial.println( "Entering FSMStateView_CurrConsoBatt." );
    g_LCD.clear();

    displayOnLCD("< Curr Cons.Batt >", 0, 0);

    this->update_1s();
}

/* ########################################################################## */
/* ########################################################################## */

void    FSMStateView_CurrConsoBatt::on_state_exit(void)
{
    displayOnLCD((char*)"leaving state", 0, 0);
    displayOnLCD((char*)"Curr Conso", 0, 1);
    return;
}

/* ########################################################################## */
/* ########################################################################## */

void    FSMStateView_CurrConsoBatt::update_1s(void)
{
    displayOnLCD((char*)g_sensors.temperature.temperature_degC(), 0, 1, 2); ///////////// NEED g_sensors.current.getCurrentConsByBatt_Amp(); /////////////
    displayOnLCD((char*)" C          ");
}

/* ########################################################################## */
/* ########################################################################## */
