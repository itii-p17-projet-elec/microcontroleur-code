#ifndef FSMSTATEMAINMENU_CONFIG_H
#define FSMSTATEMAINMENU_CONFIG_H

/* Inherited classes */
#include "common/TSingleton.hpp"
#include "../../FSMAbstractState.h"


namespace Display {


/* System includes */

/* Libraries includes */

/* Project includes */

/* ########################################################################## */
/* ########################################################################## */

class   FSMStateMainMenu_Config
        :   public  FSMAbstractState
        ,   public  TSingleton<FSMStateMainMenu_Config>
{
    friend class    TSingleton<FSMStateMainMenu_Config>;

public:

    virtual void    on_state_enter(void);
    virtual void    on_state_exit(void);


    virtual void    update_1s(void);

    virtual void    on_button_pressed(const Keypad::TeButtonsID& pButtonID);



protected:
private:

    FSMStateMainMenu_Config(void);



public:
protected:
private:

};

/* ########################################################################## */
/* ########################################################################## */

}   /*< namespace Display */

#endif  /*< FSMSTATEMAINMENU_CONFIG_H */
