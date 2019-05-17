/* Corresponding header inclusion */
#include "fsmstateview_currdecharge.h"

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
/* previous and next views */
#include "fsmstateview_currcharge.h"
#include "fsmstateview_currconsobatt.h"

namespace Display
{

/* ########################################################################## */
/* ########################################################################## */

FSMStateView_CurrDecharge::FSMStateView_CurrDecharge(void)
    : FSMStateView_AbstractCurr()
{
    return;
}


/* ########################################################################## */
/* ########################################################################## */

void    FSMStateView_CurrDecharge::on_button_pressed(const Keypad::TeButtonsID &pButtonID)
{
    FSMAbstractState::on_button_pressed(pButtonID);

    TRACE("FSMStateView_CurrDecharge : Pressed button : ");
    TRACELN( Keypad::buttonName(pButtonID) );


    switch( pButtonID )
    {
        case    Keypad::BUTTON_LEFT:
            FSMContext::Instance()->changeState(
                        FSMStateView_CurrCharge::Instance() );
            break;


        case    Keypad::BUTTON_RIGHT:
            FSMContext::Instance()->changeState(
                        FSMStateView_CurrConsoBatt::Instance() );
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

void    FSMStateView_CurrDecharge::on_state_enter(void)
{
    TRACELN( "Entering FSMStateView_CurrDecharge." );
    Display::g_LCD.clear();

    displayOnLCD("< Curr Decharge >", 0, 0);

    this->update_1s();
}

/* ########################################################################## */
/* ########################################################################## */

void    FSMStateView_CurrDecharge::on_state_exit(void)
{
    /* Nothing to do */
}

/* ########################################################################## */
/* ########################################################################## */

void    FSMStateView_CurrDecharge::update_1s(void)
{
    displayOnLCD((char*)"?? C          ");
}

/* ########################################################################## */
/* ########################################################################## */

}   /*< namespace Display */
