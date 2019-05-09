#ifndef KEYPAD_H
#define KEYPAD_H

/* Inherited classes */


/* System includes */
#include <stdint.h>

/* Libraries includes */

/* Project includes */

/* ########################################################################## */
/* ########################################################################## */

class   Keypad
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


    static const char*      buttonName(const TeButtonsID& pID);


    Keypad(void)    = delete;
    Keypad(uint8_t pAnalogPin);


    uint8_t         updateState(void);

    TeButtonsID     lastPressedButton(void) const;



protected:

    static TeButtonsID  readPressedButton(uint8_t pPinNbr);



private:



public:
protected:
private:

    /**
     *  @brief  Holds the ID of the analog pin to read keypad value from.
     */
    const uint8_t   c_pinNbr;


    /** @brief  Always holds the ID of the last pressed button. */
    TeButtonsID     m_buttonLastPressed;


    /** @brief  Holds the last known state (as a \ref TeButtonsID) of the analog
     *          input, this to detect state change. */
    TeButtonsID     m_buttonStatePrevious;

};

/* ########################################################################## */
/* ########################################################################## */

#endif  /*< KEYPAD_H */
