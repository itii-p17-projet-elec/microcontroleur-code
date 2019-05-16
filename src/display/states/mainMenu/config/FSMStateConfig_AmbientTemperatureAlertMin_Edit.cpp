/* Corresponding header inclusion */
#include "FSMStateConfig_AmbientTemperatureAlertMin_Edit.h"

/* System includes */

/* Libraries includes */

/* Project includes */
#include "variables_globales.h"
#include "display/FSMContext.h"

#include "FSMStateConfig_AmbientTemperatureAlertMin.h"


namespace Display {

/* ########################################################################## */
/* ########################################################################## */

FSMStateConfig_AmbientTemperatureAlertMin_Edit::FSMStateConfig_AmbientTemperatureAlertMin_Edit(void)
    :   FSMAbstractState()
    ,   m_editedValue_degC( -1 )
    ,   m_fastScroll(false)
{

}

/* ########################################################################## */
/* ########################################################################## */

void    FSMStateConfig_AmbientTemperatureAlertMin_Edit::on_button_pressed(const Keypad::TeButtonsID &pButtonID)
{
    FSMAbstractState::on_button_pressed(pButtonID);

    Serial.print("FSMStateConfig_AmbientTemperatureAlertMin_Edit : Pressed button : ");
    Serial.println( Keypad::buttonName(pButtonID) );


    switch( pButtonID )
    {
        case    Keypad::BUTTON_LEFT:
            break;


        case    Keypad::BUTTON_RIGHT:
            break;


        case    Keypad::BUTTON_SELECT:
            FSMContext::Instance()->changeState(
                        FSMStateConfig_AmbientTemperatureAlertMin::Instance() );
            break;


        case Keypad::BUTTON_DOWN:
                this->m_editedValue_degC   -= C_INCREMENT_degC;
                this->updateDisplay();
            break;


        case Keypad::BUTTON_UP:
                this->m_editedValue_degC   += C_INCREMENT_degC;
                this->updateDisplay();
            break;


        default:
            break;
    }
}

/* ########################################################################## */
/* ########################################################################## */

void    FSMStateConfig_AmbientTemperatureAlertMin_Edit::on_state_enter(void)
{
    Serial.println( "Entering FSMStateConfig_AmbientTemperatureAlertMin_Edit." );
    g_LCD.clear();

    this->m_editedValue_degC
            = g_parameters.m_data.ambientTemperature_alertMin;

    g_LCD.setCursor(0,0);
    g_LCD.print( "AMBTMP Alrt Min " );

    this->updateDisplay();
}

/* ########################################################################## */
/* ########################################################################## */

void    FSMStateConfig_AmbientTemperatureAlertMin_Edit::on_state_exit(void)
{
    g_parameters.m_data.ambientTemperature_alertMin
            = this->m_editedValue_degC;
    g_EEPROM.saveData();
}

/* ########################################################################## */
/* ########################################################################## */

void    FSMStateConfig_AmbientTemperatureAlertMin_Edit::update_1s(void)
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

void    FSMStateConfig_AmbientTemperatureAlertMin_Edit::update_50ms(void)
{
    if(     g_keypad.lastPressedButton() != Keypad::BUTTON_NONE
        &&  g_keypad.currentlyPressedButton() == g_keypad.lastPressedButton()
        &&  this->m_fastScroll == true )
    {
        switch( g_keypad.lastPressedButton() )
        {
            case Keypad::BUTTON_DOWN:
                this->m_editedValue_degC   -= C_INCREMENT_degC;
                break;


            case Keypad::BUTTON_UP:
                this->m_editedValue_degC   += C_INCREMENT_degC;
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

void    FSMStateConfig_AmbientTemperatureAlertMin_Edit::updateDisplay(void)
{
    this->verifyValue();

    g_LCD.setCursor(5,1);
    g_LCD.print( this->m_editedValue_degC );
    g_LCD.print( " deg C                 " );
}

/* ########################################################################## */
/* ########################################################################## */

void    FSMStateConfig_AmbientTemperatureAlertMin_Edit::verifyValue(void)
{
    if(this->m_editedValue_degC < C_VALUE_MIN)
    {
        this->m_editedValue_degC   = C_VALUE_MIN;
    }
    else if(this->m_editedValue_degC > C_VALUE_MAX)
    {
        this->m_editedValue_degC   = C_VALUE_MAX;
    }
}

/* ########################################################################## */
/* ########################################################################## */

}   /*< namespace Display */
