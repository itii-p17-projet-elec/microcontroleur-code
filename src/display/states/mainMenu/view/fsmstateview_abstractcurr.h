#ifndef FSMSTATEVIEW_ABSTRACTCURR_H
#define FSMSTATEVIEW_ABSTRACTCURR_H

/* Inherited classes */
#include "../../../FSMAbstractState.h"

/* System includes */

/* Libraries includes */

/* Project includes */


namespace Display
{

class FSMStateView_AbstractCurr
        :   public    FSMAbstractState
{
public:
    FSMStateView_AbstractCurr(void);
    virtual ~FSMStateView_AbstractCurr(void);

protected:
    virtual int     displayOnLCD(const char* data);
    virtual int     displayOnLCD(const char *data, int posX, int posY);
    virtual int     displayOnLCD(const char* data, int posX, int posY, int a);
	    int	    displayOnLCD(float data, int posX, int posY, int a);

private:



public:
protected:
private:
};

}   /*< namespace Display */

#endif // FSMSTATEVIEW_ABSTRACTCURR_H
