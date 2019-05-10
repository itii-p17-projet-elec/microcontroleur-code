/* Corresponding header inclusion */
#include "FSMAbstractState.h"

/* System includes */

/* Libraries includes */

/* Project includes */
#include "FSMContext.h"


namespace Display {

/* ########################################################################## */
/* ########################################################################## */

FSMAbstractState::FSMAbstractState(void)
    :   _m_lcdBacklightDimmer( 0xFF )
{

}

/* ########################################################################## */
/* ########################################################################## */

void    FSMAbstractState::on_button_pressed(
                const Keypad::TeButtonsID &pButtonID)
{
    (void) pButtonID;

    _m_lcdBacklightDimmer   = 0xFF;
}

/* ########################################################################## */
/* ########################################################################## */

void    FSMAbstractState::update_50ms(void)
{
    if( _m_lcdBacklightDimmer > 128 )
    {
        _m_lcdBacklightDimmer   -= 2;
        g_LCD_backlightValue    = 0xFF;
    }
    else if( (_m_lcdBacklightDimmer - 2) >= 0 )
    {
        _m_lcdBacklightDimmer   -= 2;

        /* Multiply by 2 */
        g_LCD_backlightValue    = _m_lcdBacklightDimmer << 1;
    }
    /* If there's no activity, shut down display's backlight. */
    else
    {
        g_LCD_backlightValue    = 0;
    }
}

/* ########################################################################## */
/* ########################################################################## */

}   /*< namespace Display */
