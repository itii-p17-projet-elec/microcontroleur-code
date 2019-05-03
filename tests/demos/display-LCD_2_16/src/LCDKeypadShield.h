#ifndef LCDKEYPADSHIELD_H
#define LCDKEYPADSHIELD_H

#include <stdint.h>


class   LCDKeypadShield
{
public:
    typedef enum    EButtonsID
    {
        BUTTON_NONE     = 0x00, /*!< Pas de bouton appuyé */
        BUTTON_UP       = 0x01, /*!< Bouton UP (haut) */
        BUTTON_DOWN     = 0x02, /*!< Bouton DOWN (bas) */
        BUTTON_LEFT     = 0x04, /*!< Bouton LEFT (gauche) */
        BUTTON_RIGHT    = 0x08, /*!< Bouton RIGHT (droite) */
        BUTTON_SELECT   = 0x10  /*!< Bouton SELECT */
    }   TeButtonsID;


    static char*    buttonName(const TeButtonsID& pID);


    static TeButtonsID  getPressedButton(uint8_t pPinNbr);




protected:
private:

    LCDKeypadShield();



public:

    static uint8_t     g_backlightValue;



protected:
private:



};

#endif  /*< LCDKEYPADSHIELD_H */
