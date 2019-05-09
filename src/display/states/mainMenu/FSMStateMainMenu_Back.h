#ifndef FSMSTATEMAINMENU_BACK_H
#define FSMSTATEMAINMENU_BACK_H

/* Inherited classes */
#include "common/TSingleton.hpp"
#include "../../FSMAbstractState.h"


namespace Display {


/* System includes */

/* Libraries includes */

/* Project includes */

/* ########################################################################## */
/* ########################################################################## */

class   FSMStateMainMenu_Back
        :   public  FSMAbstractState
        ,   public  TSingleton<FSMStateMainMenu_Back>
{
    friend class    TSingleton<FSMStateMainMenu_Back>;

public:

    virtual void    on_state_enter(void);
    virtual void    on_state_exit(void);


    virtual void    update_1s(void);

    virtual void    on_button_pressed(const Keypad::TeButtonsID& pButtonID);



protected:
private:

    FSMStateMainMenu_Back(void);



public:
protected:
private:

};

/* ########################################################################## */
/* ########################################################################## */

}   /*< namespace Display */

#endif  /*< FSMSTATEMAINMENU_BACK_H */
