#ifndef FSMSTATECONFIG_EMISSIONDELAY_H
#define FSMSTATECONFIG_EMISSIONDELAY_H

/* Inherited classes */
#include "common/TSingleton.hpp"
#include "display/FSMAbstractState.h"


/* System includes */

/* Libraries includes */

/* Project includes */


namespace Display {

/* ########################################################################## */
/* ########################################################################## */

class   FSMStateConfig_EmissionDelay
        :   public  FSMAbstractState
        ,   public  TSingleton<FSMStateConfig_EmissionDelay>
{
    friend class    TSingleton<FSMStateConfig_EmissionDelay>;

public:

    virtual void    on_state_enter(void);
    virtual void    on_state_exit(void);


    virtual void    update_1s(void);

    virtual void    on_button_pressed(const Keypad::TeButtonsID& pButtonID);



protected:
private:

    FSMStateConfig_EmissionDelay(void);



public:
protected:
private:

};

/* ########################################################################## */
/* ########################################################################## */

}   /*< namespace Display */

#endif  /*< FSMSTATECONFIG_EMISSIONDELAY_H */
