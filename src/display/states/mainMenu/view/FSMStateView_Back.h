#ifndef FSMSTATEVIEW_BACK_H
#define FSMSTATEVIEW_BACK_H

/* Inherited classes */
#include "common/TSingleton.hpp"
#include "display/FSMAbstractState.h"


/* System includes */

/* Libraries includes */

/* Project includes */


namespace Display {

/* ########################################################################## */
/* ########################################################################## */

class   FSMStateView_Back
        :   public  FSMAbstractState
        ,   public  TSingleton<FSMStateView_Back>
{
    friend class    TSingleton<FSMStateView_Back>;

public:

    virtual void    on_state_enter(void);
    virtual void    on_state_exit(void);


    virtual void    update_1s(void);

    virtual void    on_button_pressed(const Keypad::TeButtonsID& pButtonID);



protected:
private:

    FSMStateView_Back(void);



public:
protected:
private:

};

/* ########################################################################## */
/* ########################################################################## */

}   /*< namespace Display */

#endif  /*< FSMSTATEVIEW_BACK_H */
