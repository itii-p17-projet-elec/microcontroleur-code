#ifndef FSMSTATECONFIG_AMBIENTTEMPERATUREALERTMIN_H
#define FSMSTATECONFIG_AMBIENTTEMPERATUREALERTMIN_H

/* Inherited classes */
#include "common/TSingleton.hpp"
#include "display/FSMAbstractState.h"

/* System includes */

/* Libraries includes */

/* Project includes */


namespace Display {


/* ########################################################################## */
/* ########################################################################## */

class   FSMStateConfig_AmbientTemperatureAlertMin
        :   public  FSMAbstractState
        ,   public  TSingleton<FSMStateConfig_AmbientTemperatureAlertMin>
{
    friend class    TSingleton<FSMStateConfig_AmbientTemperatureAlertMin>;

public:

    virtual void    on_state_enter(void);
    virtual void    on_state_exit(void);


    virtual void    update_1s(void);

    virtual void    on_button_pressed(const Keypad::TeButtonsID& pButtonID);



protected:
private:

    FSMStateConfig_AmbientTemperatureAlertMin(void);



public:
protected:
private:

};

/* ########################################################################## */
/* ########################################################################## */

} // namespace Display

#endif  /*< FSMSTATECONFIG_AMBIENTTEMPERATUREALERTMIN_H */
