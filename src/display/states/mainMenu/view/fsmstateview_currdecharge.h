#ifndef FSMSTATEVIEW_CURRDECHARGE_H
#define FSMSTATEVIEW_CURRDECHARGE_H

/* Inherited classes */
#include "fsmstateview_abstractcurr.h"
#include "common/TSingleton.hpp"
#include "../../../FSMAbstractState.h"

/* System includes */

/* Libraries includes */

/* Project includes */


class FSMStateView_CurrDecharge
        : public    FSMStateView_AbstractCurr
        , public    FSMAbstractState
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

#endif // FSMSTATEVIEW_CURRDECHARGE_H
