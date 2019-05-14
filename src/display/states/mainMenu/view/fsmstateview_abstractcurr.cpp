/* Corresponding header inclusion */
#include "fsmstateview_abstractcurr.h"

/* Inherited classes */

/* System includes */

/* Libraries includes */

/* Project includes */
#include "display/FSMContext.h"


namespace Display
{

/* ########################################################################## */
/* ########################################################################## */

FSMStateView_AbstractCurr::FSMStateView_AbstractCurr(void)
    :   FSMAbstractState()
{
    return;
}

/* ########################################################################## */
/* ########################################################################## */

FSMStateView_AbstractCurr::~FSMStateView_AbstractCurr(void)
{
    return;
}

/* ########################################################################## */
/* ########################################################################## */

/* @brief returns 1 if it successfully displayed on the LCD, else 0
*/
int     FSMStateView_AbstractCurr::displayOnLCD(const char *data)
{
    Display::g_LCD.print(data);

    return 1;
}

/* ########################################################################## */
/* ########################################################################## */

/* @brief returns 1 if it successfully displayed on the LCD, else 0
*/
int     FSMStateView_AbstractCurr::displayOnLCD(const char* data, int posX, int posY)
{
    Display::g_LCD.setCursor(posX, posY);
    Display::g_LCD.print(data);

    return 1;
}

/* ########################################################################## */
/* ########################################################################## */

/* @brief returns 1 if it successfully displayed on the LCD, else 0
*/
int     FSMStateView_AbstractCurr::displayOnLCD(const char *data, int posX, int posY, int a)
{
    Display::g_LCD.setCursor(posX, posY);
    Display::g_LCD.print(data);

    return 1;
}

/* ########################################################################## */
/* ########################################################################## */

/* @brief returns 1 if it successfully displayed on the LCD, else 0
*/
int     FSMStateView_AbstractCurr::displayOnLCD(float data, int posX, int posY, int a)
{
    Display::g_LCD.setCursor(posX, posY);
    Display::g_LCD.print(data, a);

    return 1;
}

/* ########################################################################## */
/* ########################################################################## */

}   /*< namespace Display */
