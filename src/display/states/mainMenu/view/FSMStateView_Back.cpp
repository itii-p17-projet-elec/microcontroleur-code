/* Corresponding header inclusion */
#include "FSMStateView_Back.h"

/* System includes */

/* Libraries includes */
#include <Arduino.h>

/* Project includes */
#include "variables_globales.h"
#include "common/trace.h"
#include "display/FSMContext.h"

#include "../FSMStateMainMenu_View.h"
#include "fsmstateview_percentageloadbatt.h"
#include "fsmstateview_tempambiante.h"


namespace Display {

/* ########################################################################## */
/* ########################################################################## */

FSMStateView_Back::FSMStateView_Back(void)
    :   FSMAbstractState()
{

}

/* ########################################################################## */
/* ########################################################################## */

void    FSMStateView_Back::on_button_pressed(const Keypad::TeButtonsID &pButtonID)
{
    FSMAbstractState::on_button_pressed(pButtonID);

    TRACE("FSMStateView_Back : Pressed button : ");
    TRACELN( Keypad::buttonName(pButtonID) );


    switch( pButtonID )
    {
        case    Keypad::BUTTON_LEFT:
            FSMContext::Instance()->changeState(
                        FSMStateView_PercentageLoadBatt::Instance() );
            break;


        case    Keypad::BUTTON_RIGHT:
            FSMContext::Instance()->changeState(
                        FSMStateView_TempAmbiante::Instance() );
            break;


        case    Keypad::BUTTON_SELECT:
            FSMContext::Instance()->changeState(
                        FSMStateMainMenu_View::Instance() );
            break;


        default:
            break;
    }
}

/* ########################################################################## */
/* ########################################################################## */

void    FSMStateView_Back::on_state_enter(void)
{
    TRACELN( "Entering FSMStateView_Back." );
    g_LCD.clear();

    g_LCD.setCursor(0,0);
    g_LCD.print( "<   Back to    >" );
    g_LCD.setCursor(0,1);
    g_LCD.print( "   Main menu    " );

    this->update_1s();
}

/* ########################################################################## */
/* ########################################################################## */

void    FSMStateView_Back::on_state_exit(void)
{
    // TODO
}

/* ########################################################################## */
/* ########################################################################## */

void    FSMStateView_Back::update_1s(void)
{
}

/* ########################################################################## */
/* ########################################################################## */

}   /*< namespace Display */
