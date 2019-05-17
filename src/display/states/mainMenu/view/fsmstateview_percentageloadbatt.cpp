/* Corresponding header inclusion */
#include "fsmstateview_percentageloadbatt.h"

/* System includes */

/* Libraries includes */
#include <Arduino.h>

/* Project includes */
#include "variables_globales.h"
#include "common/trace.h"
#include "display/FSMContext.h"

#include "../../../FSMContext.h"
#include "../../FSMStateDefault.h"
//#include "../../../FSMAbstractState.h"

#include "../FSMStateMainMenu_View.h"
#include "FSMStateView_Back.h"
#include "fsmstateview_voltage.h"
#include "fsmstateview_tempambiante.h"


namespace Display {

/* previous and next views */
#include "fsmstateview_voltage.h"
#include "fsmstateview_tempambiante.h"

/* ########################################################################## */
/* ########################################################################## */

FSMStateView_PercentageLoadBatt::FSMStateView_PercentageLoadBatt(void)
    : Display::FSMAbstractState()
{
    return;
}

/* ########################################################################## */
/* ########################################################################## */

void    FSMStateView_PercentageLoadBatt::on_button_pressed(const Keypad::TeButtonsID &pButtonID)
{
    FSMAbstractState::on_button_pressed(pButtonID);

    TRACE("FSMStateView_PercentageLoadBatt : Pressed button : ");
    TRACELN( Keypad::buttonName(pButtonID) );


    switch( pButtonID )
    {
        case    Keypad::BUTTON_LEFT:
            FSMContext::Instance()->changeState(
                        FSMStateView_Voltage::Instance() );
            break;


        case    Keypad::BUTTON_RIGHT:
            FSMContext::Instance()->changeState(
                        FSMStateView_Back::Instance() );
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

void    FSMStateView_PercentageLoadBatt::on_state_enter(void)
{
    TRACELN( "Entering FSMStateView_PercentageLoadBatt." );
    Display::g_LCD.clear();

    g_LCD.setCursor(0, 0);
    g_LCD.print("< Batt load pc >");

    this->update_1s();
}

/* ########################################################################## */
/* ########################################################################## */

void    FSMStateView_PercentageLoadBatt::on_state_exit(void)
{
    /* Nothing to do */
}

/* ########################################################################## */
/* ########################################################################## */

void    FSMStateView_PercentageLoadBatt::update_1s(void)
{
    g_LCD.setCursor(5,1);
    g_LCD.print("?? C          ");
}

/* ########################################################################## */
/* ########################################################################## */

}   /*< namespace Display */
