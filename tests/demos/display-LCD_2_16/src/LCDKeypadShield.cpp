#include "LCDKeypadShield.h"

#include <Arduino.h>
#include <avr/power.h>

/* ########################################################################## */
/* ########################################################################## */

uint8_t     LCDKeypadShield::g_backlightValue   = 0xFF;

/* ########################################################################## */
/* ########################################################################## */

LCDKeypadShield::LCDKeypadShield()
{

}

/* ########################################################################## */
/* ########################################################################## */

char *LCDKeypadShield::buttonName(const LCDKeypadShield::TeButtonsID &pID)
{
    char*   retval  = NULL;


    switch(pID)
    {
        case BUTTON_DOWN:
            retval  = (char*)"DOWN";
            break;


        case BUTTON_LEFT:
            retval  = (char*)"LEFT";
            break;


        case BUTTON_RIGHT:
            retval  = (char*)"RIGHT";
            break;


        case BUTTON_SELECT:
            retval  = (char*)"SELECT";
            break;


        case BUTTON_UP:
            retval  = (char*)"UP";
            break;


        case BUTTON_NONE:
        default:
            retval  = (char*)"NONE";
            break;
    }


    return retval;
}

/* ########################################################################## */
/* ########################################################################## */

LCDKeypadShield::TeButtonsID LCDKeypadShield::getPressedButton(uint8_t pPinNbr)
{
    TeButtonsID retval  = BUTTON_NONE;

    /* Lit l'état des boutons */
    power_adc_enable();
    int value = analogRead(pPinNbr);
    power_adc_disable();
    Serial.print( "Value = " );
    Serial.println( value );


    /* Calcul de l'état des boutons */
    if (value < 50)
    {
        retval  = BUTTON_RIGHT;
    }
    else if (value < 250)
    {
        retval  = BUTTON_UP;
    }
    else if (value < 450)
    {
        retval  = BUTTON_DOWN;
    }
    else if (value < 650)
    {
        retval  = BUTTON_LEFT;
    }
    else if (value < 850)
    {
        retval  = BUTTON_SELECT;
    }
    else
    {
        retval  = BUTTON_NONE;
    }


    return retval;
}

/* ########################################################################## */
/* ########################################################################## */
