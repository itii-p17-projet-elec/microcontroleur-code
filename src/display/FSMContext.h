#ifndef FSMCONTEXT_H
#define FSMCONTEXT_H

/* Inherited classes */
#include "common/TSingleton.hpp"

/* System includes */

/* Libraries includes */

/* Project includes */

namespace Display {

class FSMAbstractState;


/* ########################################################################## */
/* ########################################################################## */

class   FSMContext
        :   public TSingleton<FSMContext>
{
    friend class    TSingleton<FSMContext>;

public:

    void    changeState(FSMAbstractState* pFutureState);


    FSMAbstractState*   currentState(void) const;


    void    updateDisplay(void);



protected:
private:

    FSMContext(void);



public:
protected:
private:

    FSMAbstractState*   m_currentStatePtr;

};

/* ########################################################################## */
/* ########################################################################## */

}   /*< namespace Display */

#endif  /*< FSMCONTEXT_H */
