#ifndef FSMSTATECONFIG_AMBIENTTEMPERATUREALERTMIN_EDIT_H
#define FSMSTATECONFIG_AMBIENTTEMPERATUREALERTMIN_EDIT_H

/* Inherited classes */
#include "common/TSingleton.hpp"
#include "display/FSMAbstractState.h"


/* System includes */

/* Libraries includes */

/* Project includes */


namespace Display {


/* ########################################################################## */
/* ########################################################################## */

class   FSMStateConfig_AmbientTemperatureAlertMin_Edit
        :   public  FSMAbstractState
        ,   public  TSingleton<FSMStateConfig_AmbientTemperatureAlertMin_Edit>
{
    friend class    TSingleton<FSMStateConfig_AmbientTemperatureAlertMin_Edit>;

public:

    virtual void    on_state_enter(void);
    virtual void    on_state_exit(void);


    virtual void    update_50ms(void);
    virtual void    update_1s(void);

    virtual void    on_button_pressed(const Keypad::TeButtonsID& pButtonID);



protected:
private:

    FSMStateConfig_AmbientTemperatureAlertMin_Edit(void);


    void    verifyValue(void);
    void    updateDisplay(void);



public:
protected:
private:

    static const int    C_INCREMENT_degC    = 1;

    static const int    C_VALUE_MIN         = -10;
    static const int    C_VALUE_MAX         = 50;

    int8_t      m_editedValue_degC;
    bool        m_fastScroll;

};

/* ########################################################################## */
/* ########################################################################## */

} // namespace Display

#endif  /*< FSMSTATECONFIG_AMBIENTTEMPERATUREALERTMIN_EDIT_H */
