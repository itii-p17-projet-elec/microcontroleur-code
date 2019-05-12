#ifndef FSMSTATEVIEW_ABSTRACTT_H
#define FSMSTATEVIEW_ABSTRACTT_H

/* Inherited classes */
#include "fsmstateview_displayer.h"

/* System includes */

/* Libraries includes */

/* Project includes */


class FSMStateView_AbstractT
        : public    FSMStateView_Displayer
{
public:
    FSMStateView_AbstractT(void);
    virtual ~FSMStateView_AbstractT(void);

protected:
    virtual int     displayOnLCD(char* data);
    virtual int     displayOnLCD(char* data, int posX, int posY);
    virtual int     displayOnLCD(char* data, int posX, int posY, int a);

private:



public:
protected:
private:

};

#endif // FSMSTATEVIEW_ABSTRACTT_H
