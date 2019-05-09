/* Corresponding header inclusion */
#include "Keypad.h"

/* System includes */
#include <Arduino.h>
#include <avr/power.h>

/* Libraries includes */

/* Project includes */
#include "hardware_defines.h"


/* ########################################################################## */
/* ########################################################################## */
/**
 *  @brief  Constructor.
 *
 *  @param  pAnalogPin  The ID of the analog pin which we have to read the
 *                      buttons state value from.
 */
Keypad::Keypad(uint8_t pAnalogPin)
    :   c_pinNbr( pAnalogPin )
    ,   m_buttonLastPressed(BUTTON_NONE)
    ,   m_buttonStatePrevious(BUTTON_NONE)
{
}

/* ########################################################################## */
/* ########################################################################## */
/**
 *  @brief  This static method returns the corresponding name of a given \p pID
 *          TeButtonsID.
 *
 *  @param  pID The Keypad::TeButtonsID corresponding to the button we want the
 *              name.
 *
 *  @returns    A char pointer to the corresponding const string.
 */
const char*   Keypad::buttonName(const Keypad::TeButtonsID &pID)
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
/**
 *  @brief  Accessor to \ref Keypad::m_buttonLastPressed.
 */
Keypad::TeButtonsID Keypad::lastPressedButton(void) const
{
    return this->m_buttonLastPressed;
}

/* ########################################################################## */
/* ########################################################################## */
/**
 *  @brief  Reads the analog input as set by the \p pPinNbr parameter and
 *          converts it to a button ID.
 *
 *  @param  pPinNbr The ID of the analog pin to read.
 *
 *  @returns    A value from the Keypad::TeButtonsID enumerated type.
 */
Keypad::TeButtonsID Keypad::readPressedButton(uint8_t pPinNbr)
{
    TeButtonsID retval  = BUTTON_NONE;

    /* Lit l'état des boutons */
    power_adc_enable();
    int value = analogRead(pPinNbr);
    power_adc_disable();


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
/**
 *  @brief  Reads current state of keypad, then returns a non-null code if a
 *          button has been pressed.
 *
 *  Reads the value from the \ref Keypad::c_pinNbr analog pin.
 *
 * @return
 */
uint8_t Keypad::updateState(void)
{
    static TeButtonsID  s_buttonNew = BUTTON_NONE;

    uint8_t retval  = 0;


    /* Read current button state. */
    s_buttonNew = Keypad::readPressedButton(this->c_pinNbr);


    /* If a button is pressed and it is not the last known button, then set the
     * last known pressed button ID and change the returned value to non-zero */
    if(     s_buttonNew != Keypad::BUTTON_NONE
        &&  s_buttonNew != this->m_buttonStatePrevious )
    {
        this->m_buttonLastPressed = s_buttonNew;
        retval  = 1;
    }


    /* Update last known state */
    this->m_buttonStatePrevious = s_buttonNew;

    return retval;
}

/* ########################################################################## */
/* ########################################################################## */
