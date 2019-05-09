#ifndef FSMABSTRACTSTATE_H
#define FSMABSTRACTSTATE_H

/* Inherited classes */
#include "common/TSingleton.hpp"


/* System includes */

/* Libraries includes */

/* Project includes */
#include "drivers/Keypad.h"

namespace Display {

/* ########################################################################## */
/* ########################################################################## */

class   FSMAbstractState
//        :   public TSingleton<FSMAbstractState>
{
//    friend class    TSingleton<FSMAbstractState>;

public:

    /**
     *  @brief  This method is called when the FSM enters this state.
     */
    virtual void    on_state_enter(void)    = 0;

    /**
     *  @brief  This method is called when the FSM gets out of this state.
     */
    virtual void    on_state_exit(void)     = 0;


    /**
     *  @brief  This method shall be periodically called by the main thread to
     *          update displayed informations.
     */
    virtual void    update_1s(void) = 0;

    /**
     *  @brief  This method shall be periodically called by the main thread to
     *          update displayed informations.
     */
    virtual void    update_50ms(void);


    /**
     *  @brief  This method signals to the state that a button has been pressed.
     */
    virtual void    on_button_pressed(const Keypad::TeButtonsID& pButtonID);





protected:

    FSMAbstractState(void);



private:



public:
protected:
private:

    uint8_t _m_lcdBacklightDimmer;

};

/* ########################################################################## */
/* ########################################################################## */

}   /*< namespace Display */

#endif  /*< FSMABSTRACTSTATE_H */
