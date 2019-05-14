#ifndef FSMSTATEVIEW_VOLTAGE_H
#define FSMSTATEVIEW_VOLTAGE_H


/* Inherited classes */
#include "fsmstateview_displayer.h"
#include "common/TSingleton.hpp"
#include "../../../FSMAbstractState.h"

/* System includes */

/* Libraries includes */

/* Project includes */


class FSMStateView_Voltage
        : public    FSMAbstractState
        , public    TSingleton<FSMStateView_Voltage>
{
    friend class    TSingleton<FSMStateView_Voltage>;

public:
    virtual void    on_button_pressed(const Keypad::TeButtonsID& pButtonID);
    virtual void    on_state_enter(void);
    virtual void    on_state_exit(void);
    virtual void    update_1s(void);

protected:
    virtual int     displayOnLCD(char* data);
    virtual int     displayOnLCD(char* data, int posX, int posY);
    virtual int     displayOnLCD(char* data, int posX, int posY, int a);

private:
    FSMStateView_Voltage(void);



public:
protected:
private:

};

#endif // FSMSTATEVIEW_VOLTAGE_H
