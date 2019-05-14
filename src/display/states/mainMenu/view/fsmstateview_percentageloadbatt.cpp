/* Corresponding header inclusion */
#include "fsmstateview_percentageloadbatt.h"

/* System includes */

/* Libraries includes */
#include <Arduino.h>

/* Project includes */
#include "variables_globales.h"
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

    Serial.print("FSMStateView_PercentageLoadBatt : Pressed button : ");
    Serial.println( Keypad::buttonName(pButtonID) );


    switch( pButtonID )
    {
        case    Keypad::BUTTON_LEFT:
            FSMContext::Instance()->changeState(
                        FSMStateView_Voltage::Instance() );
            break;


        case    Keypad::BUTTON_RIGHT:
            FSMContext::Instance()->changeState(
                        FSMStateView_TempAmbiante::Instance() );
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

void    FSMStateView_PercentageLoadBatt::on_state_enter(void)
{
    Serial.println( "Entering FSMStateView_PercentageLoadBatt." );
    Display::g_LCD.clear();

    displayOnLCD("< Voltage Batt >", 0, 0);

    this->update_1s();
}

/* ########################################################################## */
/* ########################################################################## */

void    FSMStateView_PercentageLoadBatt::on_state_exit(void)
{
    displayOnLCD((char*)"leaving state", 0, 0);
    displayOnLCD((char*)"Percent LoadBatt", 0, 1);
    return;
}

/* ########################################################################## */
/* ########################################################################## */

void    FSMStateView_PercentageLoadBatt::update_1s(void)
{
    displayOnLCD(" ??? C          ");
}

/* ########################################################################## */
/* ########################################################################## */

/* @brief returns 1 if it successfully displayed on the LCD, else 0
*/
int     FSMStateView_PercentageLoadBatt::displayOnLCD(const char* data)
{
    Display::g_LCD.print(data);
    return 1;
}

/* ########################################################################## */
/* ########################################################################## */

/* @brief returns 1 if it successfully displayed on the LCD, else 0
*/
int     FSMStateView_PercentageLoadBatt::displayOnLCD(const char* data, int posX, int posY)
{
    Display::g_LCD.setCursor(posX, posY);
    Display::g_LCD.print(data);

    return 1;
}

/* ########################################################################## */
/* ########################################################################## */

/* @brief returns 1 if it successfully displayed on the LCD, else 0
*/
int     FSMStateView_PercentageLoadBatt::displayOnLCD(const char* data, int posX, int posY, int a)
{
    Display::g_LCD.setCursor(posX, posY);
    Display::g_LCD.print(data);

    return 1;
}

/* ########################################################################## */
/* ########################################################################## */

}   /*< namespace Display */
