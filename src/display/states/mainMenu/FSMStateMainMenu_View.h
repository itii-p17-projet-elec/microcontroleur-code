#ifndef FSMSTATEMAINMENU_VIEW_H
#define FSMSTATEMAINMENU_VIEW_H

/* Inherited classes */
#include "common/TSingleton.hpp"
#include "../../FSMAbstractState.h"


namespace Display {


/* System includes */

/* Libraries includes */

/* Project includes */

/* ########################################################################## */
/* ########################################################################## */

class   FSMStateMainMenu_View
        :   public  FSMAbstractState
        ,   public  TSingleton<FSMStateMainMenu_View>
{
    friend class    TSingleton<FSMStateMainMenu_View>;

public:

    virtual void    on_state_enter(void);
    virtual void    on_state_exit(void);


    virtual void    update_1s(void);

    virtual void    on_button_pressed(const Keypad::TeButtonsID& pButtonID);



protected:
private:

    FSMStateMainMenu_View(void);



public:
protected:
private:

};

/* ########################################################################## */
/* ########################################################################## */

}   /*< namespace Display */

#endif  /*< FSMSTATEMAINMENU_VIEW_H */
