/* Corresponding header inclusion */
#include "fsmstateview_voltage.h"

/* System includes */

/* Libraries includes */
#include <Arduino.h>

/* Project includes */
#include "variables_globales.h"
#include "display/FSMContext.h"

#include "../FSMStateMainMenu_View.h"
#include "FSMStateView_Back.h"
#include "fsmstateview_currconsobatt.h"
#include "fsmstateview_percentageloadbatt.h"


namespace Display {

/* ########################################################################## */
/* ########################################################################## */

FSMStateView_Voltage::FSMStateView_Voltage(void)
    : Display::FSMAbstractState()
{
    return;
}

/* ########################################################################## */
/* ########################################################################## */

void    FSMStateView_Voltage::on_button_pressed(const Keypad::TeButtonsID &pButtonID)
{
    FSMAbstractState::on_button_pressed(pButtonID);

    Serial.print("FSMStateView_Voltage : Pressed button : ");
    Serial.println( Keypad::buttonName(pButtonID) );


    switch( pButtonID )
    {
        case    Keypad::BUTTON_LEFT:
            FSMContext::Instance()->changeState(
                        FSMStateView_CurrConsoBatt::Instance() );
            break;


        case    Keypad::BUTTON_RIGHT:
            FSMContext::Instance()->changeState(
                        FSMStateView_PercentageLoadBatt::Instance() );
            break;


//        case    Keypad::BUTTON_UP:
//            FSMContext::Instance()->changeState(
//                        FSMStateMainMenu_View::Instance());


        default:
            break;
    }
}

/* ########################################################################## */
/* ########################################################################## */

void    FSMStateView_Voltage::on_state_enter(void)
{
    Serial.println( "Entering FSMStateView_Voltage." );
    Display::g_LCD.clear();

    g_LCD.setCursor(0,0);
    g_LCD.print("< Voltage Batt >");

    this->update_1s();
}

/* ########################################################################## */
/* ########################################################################## */

void    FSMStateView_Voltage::on_state_exit(void)
{
    /* nothing to do */
}

/* ########################################################################## */
/* ########################################################################## */

void    FSMStateView_Voltage::update_1s(void)
{
    g_LCD.setCursor(5,1);
    g_LCD.print("?? C          ");
}

/* ########################################################################## */
/* ########################################################################## */

}   /*< namespace Display */
