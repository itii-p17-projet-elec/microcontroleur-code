/* Corresponding header inclusion */
#include "FSMStateConfig_EmissionDelay_Edit.h"

/* System includes */

/* Libraries includes */
#include <Arduino.h>

/* Project includes */
#include "variables_globales.h"
#include "display/FSMContext.h"

#include "../FSMStateMainMenu_Config.h"
#include "FSMStateConfig_EmissionDelay.h"


namespace Display {

/* ########################################################################## */
/* ########################################################################## */

FSMStateConfig_EmissionDelay_Edit::FSMStateConfig_EmissionDelay_Edit(void)
    :   FSMAbstractState()
    ,   m_editedValue_s( -1 )
    ,   m_fastScroll(false)
{

}

/* ########################################################################## */
/* ########################################################################## */

void    FSMStateConfig_EmissionDelay_Edit::on_button_pressed(const Keypad::TeButtonsID &pButtonID)
{
    FSMAbstractState::on_button_pressed(pButtonID);

    Serial.print("FSMStateConfig_EmissionDelay_Edit : Pressed button : ");
    Serial.println( Keypad::buttonName(pButtonID) );


    switch( pButtonID )
    {
        case    Keypad::BUTTON_LEFT:
            break;


        case    Keypad::BUTTON_RIGHT:
            break;


        case    Keypad::BUTTON_SELECT:
            FSMContext::Instance()->changeState(
                        FSMStateConfig_EmissionDelay::Instance() );
            break;


        case Keypad::BUTTON_DOWN:
                this->m_editedValue_s   -= C_INCREMENT_SLOW_s;
                this->updateDisplay();
            break;


        case Keypad::BUTTON_UP:
                this->m_editedValue_s   += C_INCREMENT_SLOW_s;
                this->updateDisplay();
            break;


        default:
            break;
    }
}

/* ########################################################################## */
/* ########################################################################## */

void    FSMStateConfig_EmissionDelay_Edit::on_state_enter(void)
{
    Serial.println( "Entering FSMStateConfig_EmissionDelay_Edit." );
    g_LCD.clear();

    this->m_editedValue_s
            = g_parameters.m_data.sensors_periodicTransmissionDelay_s;

    g_LCD.setCursor(0,0);
    g_LCD.print( "  Emit. period  " );

    this->updateDisplay();
}

/* ########################################################################## */
/* ########################################################################## */

void    FSMStateConfig_EmissionDelay_Edit::on_state_exit(void)
{
    g_parameters.m_data.sensors_periodicTransmissionDelay_s
            = this->m_editedValue_s;
    g_EEPROM.saveData();
}

/* ########################################################################## */
/* ########################################################################## */

void    FSMStateConfig_EmissionDelay_Edit::update_1s(void)
{
    if(     g_keypad.lastPressedButton() != Keypad::BUTTON_NONE
        &&  g_keypad.currentlyPressedButton() == g_keypad.lastPressedButton() )
    {
        if( this->m_fastScroll == false )
        {
            this->m_fastScroll  = true;
        }
        else
        {
//            switch( g_keypad.lastPressedButton() )
//            {
//                case Keypad::BUTTON_DOWN:
//                    this->m_editedValue_s   -= C_INCREMENT_FAST_s;
//                    break;


//                case Keypad::BUTTON_UP:
//                    this->m_editedValue_s   += C_INCREMENT_FAST_s;
//                    break;


//                default:
//                    break;
//            }
        }


        this->_m_lcdBacklightDimmer = 0xFF;
    }
    else
    {
        this->m_fastScroll  = false;
    }


//    this->updateDisplay();
}

/* ########################################################################## */
/* ########################################################################## */

void    FSMStateConfig_EmissionDelay_Edit::update_50ms(void)
{
    if(     g_keypad.lastPressedButton() != Keypad::BUTTON_NONE
        &&  g_keypad.currentlyPressedButton() == g_keypad.lastPressedButton()
        &&  this->m_fastScroll == true )
    {
        switch( g_keypad.lastPressedButton() )
        {
            case Keypad::BUTTON_DOWN:
                this->m_editedValue_s   -= C_INCREMENT_SLOW_s;
                break;


            case Keypad::BUTTON_UP:
                this->m_editedValue_s   += C_INCREMENT_SLOW_s;
                break;


            default:
                break;
        }

        this->_m_lcdBacklightDimmer = 0xFF;
        this->updateDisplay();
    }
    else
    {
        this->m_fastScroll  = false;
    }
}

/* ########################################################################## */
/* ########################################################################## */

void    FSMStateConfig_EmissionDelay_Edit::updateDisplay(void)
{
    this->verifyValue();

    g_LCD.setCursor(5,1);
    g_LCD.print( this->m_editedValue_s );
    g_LCD.print( " s                 " );
}

/* ########################################################################## */
/* ########################################################################## */

void    FSMStateConfig_EmissionDelay_Edit::verifyValue(void)
{
    if(this->m_editedValue_s < C_VALUE_MIN)
    {
        this->m_editedValue_s   = C_VALUE_MIN;
    }
    else if(this->m_editedValue_s > C_VALUE_MAX)
    {
        this->m_editedValue_s   = C_VALUE_MIN;
    }
}

/* ########################################################################## */
/* ########################################################################## */

}   /*< namespace Display */
