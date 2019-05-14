#ifndef FSMSTATEVIEW_ABSTRACTT_H
#define FSMSTATEVIEW_ABSTRACTT_H

/* Inherited classes */


/* System includes */

/* Libraries includes */

/* Project includes */


namespace Display
{


class FSMStateView_AbstractT
{
public:
    FSMStateView_AbstractT(void);
    virtual ~FSMStateView_AbstractT(void);

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

#endif // FSMSTATEVIEW_ABSTRACTT_H
