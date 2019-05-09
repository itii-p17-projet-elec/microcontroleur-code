#ifndef FSMSTATEDEFAULT_H
#define FSMSTATEDEFAULT_H

/* Inherited classes */
#include "common/TSingleton.hpp"
#include "../FSMAbstractState.h"


namespace Display {


/* System includes */

/* Libraries includes */

/* Project includes */

/* ########################################################################## */
/* ########################################################################## */

class   FSMStateDefault
        :   public  FSMAbstractState
        ,   public  TSingleton<FSMStateDefault>
{
    friend class    TSingleton<FSMStateDefault>;

public:

    virtual void    on_state_enter(void);
    virtual void    on_state_exit(void);


    virtual void    update_1s(void);

    virtual void    on_button_pressed(const Keypad::TeButtonsID& pButtonID);



protected:
private:

    FSMStateDefault(void);



public:
protected:
private:

    int     m_updatesCount;

};

/* ########################################################################## */
/* ########################################################################## */

}   /*< namespace Display */

#endif  /*< FSMSTATEDEFAULT_H */
