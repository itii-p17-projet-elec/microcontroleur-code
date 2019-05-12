#ifndef FSMSTATEVIEW_TEMPBATT_H
#define FSMSTATEVIEW_TEMPBATT_H

/* Inherited classes */
#include "fsmstateview_abstractt.h"
#include "common/TSingleton.hpp"
#include "display/FSMAbstractState.h"

/* System includes */

/* Libraries includes */

/* Project includes */


class FSMStateView_TempBatt
        : public    FSMStateView_AbstractT
        , public    FSMAbstractState
        , public    TSingleton<FSMStateView_TempBatt>
{
    friend class    TSingleton<FSMStateView_TempBatt>;

public:
    virtual void    on_button_pressed(const Keypad::TeButtonsID& pButtonID);
    virtual void    on_state_enter(void);
    virtual void    on_state_exit(void);
    virtual void    update_1s(void);

protected:
private:
    FSMStateView_TempBatt(void);



public:
protected:
private:

};

#endif // FSMSTATEVIEW_TEMPBATT_H
