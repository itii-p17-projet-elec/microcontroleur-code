#ifndef FSMSTATEVIEW_TEMPAMBIANTE_H
#define FSMSTATEVIEW_TEMPAMBIANTE_H

/* Inherited classes */
#include "fsmstateview_abstractt.h"
#include "common/TSingleton.hpp"
#include "../../../FSMAbstractState.h"

/* System includes */

/* Libraries includes */

/* Project includes */


class FSMStateView_TempAmbiante
        : public    FSMStateView_AbstractT
        , public    FSMAbstractState
        , public    TSingleton<FSMStateView_TempAmbiante>
{
    friend class    TSingleton<FSMStateView_TempAmbiante>;

public:
    virtual void    on_button_pressed(const Keypad::TeButtonsID& pButtonID);
    virtual void    on_state_enter(void);
    virtual void    on_state_exit(void);
    virtual void    update_1s(void);

protected:
private:
    FSMStateView_TempAmbiante(void);



public:
protected:
private:

};

#endif // FSMSTATEVIEW_TEMPAMBIANTE_H
