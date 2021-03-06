/* Corresponding header inclusion */
#include "fsmstateview_currcharge.h"

/* System includes */

/* Libraries includes */
#include <Arduino.h>

/* Project includes */
//#include "variables_globales.h"
#include "common/trace.h"
//#include "display/FSMContext.h"
#include "../../../../variables_globales.h"
#include "../../../../display/FSMContext.h"

#include "../../../FSMContext.h"
#include "../../FSMStateDefault.h"
//#include "../../../FSMAbstractState.h"

#include "../FSMStateMainMenu_View.h"
#include "FSMStateView_Back.h"

/* previous and next views */
#include "fsmstateview_tempbatt.h"
#include "fsmstateview_currdecharge.h"

namespace Display
{

/* ########################################################################## */
/* ########################################################################## */

FSMStateView_CurrCharge::FSMStateView_CurrCharge(void)
    : FSMStateView_AbstractCurr()
{
    return;
}


/* ########################################################################## */
/* ########################################################################## */

void    FSMStateView_CurrCharge::on_button_pressed(const Keypad::TeButtonsID &pButtonID)
{
    FSMAbstractState::on_button_pressed(pButtonID);

    TRACE("FSMStateView_CurrCharge : Pressed button : ");
    TRACELN( Keypad::buttonName(pButtonID) );


    switch( pButtonID )
    {
        case    Keypad::BUTTON_LEFT:
            FSMContext::Instance()->changeState(
                        FSMStateView_TempBatt::Instance() );
            break;


        case    Keypad::BUTTON_RIGHT:
            FSMContext::Instance()->changeState(
                        FSMStateView_CurrDecharge::Instance() );
            break;


//        case    Keypad::BUTTON_UP:
//            FSMContext::Instance()->changeState(
//                        FSMStateMainMenu_View::Instance() );


        default:
            break;
    }
}

/* ########################################################################## */
/* ########################################################################## */

void    FSMStateView_CurrCharge::on_state_enter(void)
{
    TRACELN( "Entering FSMStateView_CurrCharge." );
    Display::g_LCD.clear();

    displayOnLCD("< Curr Load >", 0, 0);

    this->update_1s();
}

/* ########################################################################## */
/* ########################################################################## */

void    FSMStateView_CurrCharge::on_state_exit(void)
{
    displayOnLCD((char*)"leaving state", 0, 0);
    displayOnLCD((char*)"Curr Charge", 0, 1);
    return;
}

/* ########################################################################## */
/* ########################################################################## */

void    FSMStateView_CurrCharge::update_1s(void)
{
    displayOnLCD(g_sensors.batteryInputCurrent_mA(), 0, 1, 2);
    displayOnLCD((char*)" mA          " );
}

/* ########################################################################## */
/* ########################################################################## */

}   /*< namespace Display */
