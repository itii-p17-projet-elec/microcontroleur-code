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


    virtual void    updateDisplay(void);

    virtual void    on_button_pressed(void);



protected:
private:

    FSMStateDefault(void);



public:
protected:
private:

};

/* ########################################################################## */
/* ########################################################################## */

}   /*< namespace Display */

#endif  /*< FSMSTATEDEFAULT_H */
