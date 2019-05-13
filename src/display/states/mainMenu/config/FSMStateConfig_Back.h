#ifndef FSMSTATECONFIG_BACK_H
#define FSMSTATECONFIG_BACK_H

/* Inherited classes */
#include "common/TSingleton.hpp"
#include "display/FSMAbstractState.h"


/* System includes */

/* Libraries includes */

/* Project includes */


namespace Display {

/* ########################################################################## */
/* ########################################################################## */

class   FSMStateConfig_Back
        :   public  FSMAbstractState
        ,   public  TSingleton<FSMStateConfig_Back>
{
    friend class    TSingleton<FSMStateConfig_Back>;

public:

    virtual void    on_state_enter(void);
    virtual void    on_state_exit(void);


    virtual void    update_1s(void);

    virtual void    on_button_pressed(const Keypad::TeButtonsID& pButtonID);



protected:
private:

    FSMStateConfig_Back(void);



public:
protected:
private:

};

/* ########################################################################## */
/* ########################################################################## */

}   /*< namespace Display */

#endif  /*< FSMSTATECONFIG_BACK_H */
