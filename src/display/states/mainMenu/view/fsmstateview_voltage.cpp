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

/* previous and next views */
#include "fsmstateview_currconsobatt.h"
#include "fsmstateview_percentageloadbatt.h"

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


        case    Keypad::BUTTON_UP:
            FSMContext::Instance()->changeState(
                        FSMStateMainMenu_View::Instance());


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

    displayOnLCD("< Voltage Batt >", 0, 0);

    this->update_1s();
}

/* ########################################################################## */
/* ########################################################################## */

void    FSMStateView_Voltage::on_state_exit(void)
{
    displayOnLCD((char*)"leaving state", 0, 0);
    displayOnLCD((char*)"Voltage Batt", 0, 1);
    return;
}

/* ########################################################################## */
/* ########################################################################## */

void    FSMStateView_Voltage::update_1s(void)
{
    Display::g_LCD(g_sensors.temperature.temperature_degC(), 0, 1, 2); ///////////// NEED g_sensors.voltage.getvoltageBatt_Volt(); /////////////
    displayOnLCD((char*)" C          ");
}

/* ########################################################################## */
/* ########################################################################## */

/* @brief returns 1 if it successfully displayed on the LCD, else 0
*/
int     FSMStateView_Voltage::displayOnLCD(char* data)
{
    try{
    Display::g_LCD.print(data);
    } catch(...) {
        return 0;
    }
    return 1;
}

/* ########################################################################## */
/* ########################################################################## */

/* @brief returns 1 if it successfully displayed on the LCD, else 0
*/
int     FSMStateView_Voltage::displayOnLCD(char* data, int posX, int posY)
{
    try{
    Display::g_LCD.setCursor(posX, posY);
    Display::g_LCD.print(data);
    } catch(...) {
        return 0;
    }
    return 1;
}

/* ########################################################################## */
/* ########################################################################## */

/* @brief returns 1 if it successfully displayed on the LCD, else 0
*/
int     FSMStateView_Voltage::displayOnLCD(char* data, int posX, int posY, int a)
{
    try{
    Display::g_LCD.setCursor(posX, posY);
    Display::g_LCD.print(data, a);
    } catch(...) {
        return 0;
    }
    return 1;
}

/* ########################################################################## */
/* ########################################################################## */
