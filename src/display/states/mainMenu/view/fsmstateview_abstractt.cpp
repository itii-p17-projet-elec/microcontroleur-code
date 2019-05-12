/* Corresponding header inclusion */
#include "fsmstateview_abstractt.h"

/* Inherited classes */

/* System includes */

/* Libraries includes */

/* Project includes */

/* ########################################################################## */
/* ########################################################################## */

FSMStateView_AbstractT::FSMStateView_AbstractT(void)
    : FSMStateView_Displayer()
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
int     FSMStateView_AbstractT::displayOnLCD(char* data)
{
    try{
    g_LCD.print(data);
    } catch(...) {
        return 0;
    }
    return 1;
}

/* ########################################################################## */
/* ########################################################################## */

/* @brief returns 1 if it successfully displayed on the LCD, else 0
*/
int     FSMStateView_AbstractT::displayOnLCD(char* data, int posX, int posY)
{
    try{
    g_LCD.setCursor(posX, posY);
    g_LCD.print(data);
    } catch(...) {
        return 0;
    }
    return 1;
}

/* ########################################################################## */
/* ########################################################################## */

/* @brief returns 1 if it successfully displayed on the LCD, else 0
*/
int     FSMStateView_AbstractT::displayOnLCD(char* data, int posX, int posY, int a)
{
    try{
    g_LCD.setCursor(posX, posY);
    g_LCD.print(data, a);
    } catch(...) {
        return 0;
    }
    return 1;
}

/* ########################################################################## */
/* ########################################################################## */
