#ifndef FSMSTATEVIEW_ABSTRACTCURR_H
#define FSMSTATEVIEW_ABSTRACTCURR_H

/* Inherited classes */
#include "fsmstateview_displayer.h"

/* System includes */

/* Libraries includes */

/* Project includes */


class FSMStateView_AbstractCurr
        : public    FSMStateView_Displayer
{
public:
    FSMStateView_AbstractCurr(void);
    virtual ~FSMStateView_AbstractCurr(void);

protected:
    virtual int     displayOnLCD(char* data);
    virtual int     displayOnLCD(char* data, int posX, int posY);
    virtual int     displayOnLCD(char* data, int posX, int posY, int a);
	    int	    displayOnLCD(float data, int posX, int posY, int a);

private:



public:
protected:
private:
};

#endif // FSMSTATEVIEW_ABSTRACTCURR_H
