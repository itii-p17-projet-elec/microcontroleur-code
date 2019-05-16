#ifndef FSMSTATECONFIG_EMISSIONDELAY_EDIT_H
#define FSMSTATECONFIG_EMISSIONDELAY_EDIT_H

/* Inherited classes */
#include "common/TSingleton.hpp"
#include "display/FSMAbstractState.h"


/* System includes */

/* Libraries includes */

/* Project includes */


namespace Display {

/* ########################################################################## */
/* ########################################################################## */

class   FSMStateConfig_EmissionDelay_Edit
        :   public  FSMAbstractState
        ,   public  TSingleton<FSMStateConfig_EmissionDelay_Edit>
{
    friend class    TSingleton<FSMStateConfig_EmissionDelay_Edit>;

public:

    virtual void    on_state_enter(void);
    virtual void    on_state_exit(void);


    virtual void    update_50ms(void);
    virtual void    update_1s(void);

    virtual void    on_button_pressed(const Keypad::TeButtonsID& pButtonID);



protected:
private:

    FSMStateConfig_EmissionDelay_Edit(void);


    void    verifyValue(void);
    void    updateDisplay(void);



public:
protected:
private:

    static const int    C_INCREMENT_SLOW_s  = 5;
    static const int    C_INCREMENT_FAST_s  = 10;

    static const int    C_VALUE_MIN         = 10;
    static const int    C_VALUE_MAX         = 3600;

    uint16_t    m_editedValue_s;
    bool        m_fastScroll;

};

/* ########################################################################## */
/* ########################################################################## */

}   /*< namespace Display */

#endif  /*< FSMSTATECONFIG_EMISSIONDELAY_EDIT_H */
