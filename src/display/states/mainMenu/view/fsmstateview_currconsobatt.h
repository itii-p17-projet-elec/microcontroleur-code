#ifndef FSMSTATEVIEW_CURRCONSOBATT_H
#define FSMSTATEVIEW_CURRCONSOBATT_H

/* Inherited classes */
#include "fsmstateview_abstractcurr.h"
#include "common/TSingleton.hpp"
#include "../../../FSMAbstractState.h"

/* System includes */

/* Libraries includes */

/* Project includes */

namespace Display {

class FSMStateView_CurrConsoBatt
        : public    FSMStateView_AbstractCurr
        , public    TSingleton<FSMStateView_CurrConsoBatt>
{
    friend class    TSingleton<FSMStateView_CurrConsoBatt>;

public:
    virtual void    on_button_pressed(const Keypad::TeButtonsID& pButtonID);
    virtual void    on_state_enter(void);
    virtual void    on_state_exit(void);
    virtual void    update_1s(void);

protected:
private:
    FSMStateView_CurrConsoBatt(void);



public:
protected:
private:

};

}   /*< namespace Display */

#endif // FSMSTATEVIEW_CURRCONSOBATT_H
