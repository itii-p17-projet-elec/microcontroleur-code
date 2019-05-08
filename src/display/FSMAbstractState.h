#ifndef FSMABSTRACTSTATE_H
#define FSMABSTRACTSTATE_H

/* Inherited classes */
#include "common/TSingleton.hpp"

namespace Display {


/* System includes */

/* Libraries includes */

/* Project includes */

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
    virtual void    updateDisplay(void) = 0;





protected:

    FSMAbstractState(void);



private:



public:
protected:
private:

};

/* ########################################################################## */
/* ########################################################################## */

}   /*< namespace Display */

#endif  /*< FSMABSTRACTSTATE_H */
