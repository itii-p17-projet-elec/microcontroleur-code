#ifndef FSMSTATEVIEW_PERCENTAGELOADBATT_H
#define FSMSTATEVIEW_PERCENTAGELOADBATT_H


/* Inherited classes */
#include "common/TSingleton.hpp"
#include "../../../FSMAbstractState.h"

/* System includes */

/* Libraries includes */

/* Project includes */

namespace Display {

class FSMStateView_PercentageLoadBatt
        : public    FSMAbstractState
        , public    TSingleton<FSMStateView_PercentageLoadBatt>
{
    friend class    TSingleton<FSMStateView_PercentageLoadBatt>;

public:
    virtual void    on_button_pressed(const Keypad::TeButtonsID& pButtonID);
    virtual void    on_state_enter(void);
    virtual void    on_state_exit(void);
    virtual void    update_1s(void);

protected:
private:
    FSMStateView_PercentageLoadBatt(void);



public:
protected:
private:

};

}   /*< namespace Display */

#endif // FSMSTATEVIEW_PERCENTAGELOADBATT_H
