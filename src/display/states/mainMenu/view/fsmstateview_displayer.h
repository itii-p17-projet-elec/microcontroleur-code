#ifndef FSMSTATEVIEW_DISPLAYER_H
#define FSMSTATEVIEW_DISPLAYER_H

/* Inherited classes */

/* System includes */

/* Libraries includes */

/* Project includes */


class FSMStateView_Displayer
{
public:
    FSMStateView_Displayer(void);
    virtual ~FSMStateView_Displayer(void);

protected:
    virtual int     displayOnLCD(char* data) = 0;
    virtual int     displayOnLCD(char* data, int posX, int posY) = 0;
    virtual int     displayOnLCD(char* data, int posX, int posY, int a) = 0;

private:



public:
protected:
private:

};

#endif // FSMSTATEVIEW_DISPLAYER_H
