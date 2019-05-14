/* Corresponding header inclusion */
#include "fsmstateview_abstractt.h"

/* Inherited classes */

/* System includes */

/* Libraries includes */

/* Project includes */
#include "display/FSMContext.h"


namespace Display
{

/* ########################################################################## */
/* ########################################################################## */

FSMStateView_AbstractT::FSMStateView_AbstractT(void)
{
    return;
}

/* ########################################################################## */
/* ########################################################################## */

FSMStateView_AbstractT::~FSMStateView_AbstractT(void)
{
    return;
}

/* ########################################################################## */
/* ########################################################################## */

/* @brief returns 1 if it successfully displayed on the LCD, else 0
*/
int     FSMStateView_AbstractT::displayOnLCD(const char *data)
{
    Display::g_LCD.print(data);

    return 1;
}

/* ########################################################################## */
/* ########################################################################## */

/* @brief returns 1 if it successfully displayed on the LCD, else 0
*/
int     FSMStateView_AbstractT::displayOnLCD(const char* data, int posX, int posY)
{
    Display::g_LCD.setCursor(posX, posY);
    Display::g_LCD.print(data);

    return 1;
}

/* ########################################################################## */
/* ########################################################################## */

/* @brief returns 1 if it successfully displayed on the LCD, else 0
*/
int     FSMStateView_AbstractT::displayOnLCD(const char* data, int posX, int posY, int a)
{
    Display::g_LCD.setCursor(posX, posY);
    Display::g_LCD.print(data);

    return 1;
}

/* ########################################################################## */
/* ########################################################################## */

/* @brief returns 1 if it successfully displayed on the LCD, else 0
*/
int     FSMStateView_AbstractT::displayOnLCD(float data, int posX, int posY, int a)
{
    Display::g_LCD.setCursor(posX, posY);
    Display::g_LCD.print(data, a);

    return 1;
}

/* ########################################################################## */
/* ########################################################################## */

}   /*< namespace Display */
