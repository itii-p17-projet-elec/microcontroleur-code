#ifndef FSMSTATEVIEW_TEMPERATUREAMB_H
#define FSMSTATEVIEW_TEMPERATUREAMB_H

/* Inherited classes */
#include "common/TSingleton.hpp"
#include "display/FSMAbstractState.h"


/* System includes */

/* Libraries includes */

/* Project includes */


namespace Display {

/* ########################################################################## */
/* ########################################################################## */

class   FSMStateView_TemperatureAmb
        :   public  FSMAbstractState
        ,   public  TSingleton<FSMStateView_TemperatureAmb>
{
    friend class    TSingleton<FSMStateView_TemperatureAmb>;

public:

    virtual void    on_state_enter(void);
    virtual void    on_state_exit(void);


    virtual void    update_1s(void);

    virtual void    on_button_pressed(const Keypad::TeButtonsID& pButtonID);



protected:
private:

    FSMStateView_TemperatureAmb(void);



public:
protected:
private:

};

/* ########################################################################## */
/* ########################################################################## */

}   /*< namespace Display */

#endif  /*< FSMSTATEVIEW_TEMPERATUREAMB_H */
