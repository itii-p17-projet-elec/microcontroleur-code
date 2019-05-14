#ifndef FSMSTATEVIEW_CURRDECHARGE_H
#define FSMSTATEVIEW_CURRDECHARGE_H

/* Inherited classes */
#include "fsmstateview_abstractcurr.h"
#include "common/TSingleton.hpp"


/* System includes */

/* Libraries includes */

/* Project includes */

namespace Display
{

class   FSMStateView_CurrDecharge
        : public    FSMStateView_AbstractCurr
        , public    TSingleton<FSMStateView_CurrDecharge>
{
    friend class    TSingleton<FSMStateView_CurrDecharge>;

public:
    virtual void    on_button_pressed(const Keypad::TeButtonsID& pButtonID);
    virtual void    on_state_enter(void);
    virtual void    on_state_exit(void);
    virtual void    update_1s(void);

protected:
private:
    FSMStateView_CurrDecharge(void);



public:
protected:
private:

};

}   /*< namespace Display */

#endif // FSMSTATEVIEW_CURRDECHARGE_H
