#ifndef ABSTRACTINTERFACE_H
#define ABSTRACTINTERFACE_H

/* Inherited classes */

/* System includes */

/* Libraries includes */
#include <Arduino.h>

/* Project includes */


namespace Comm {
namespace Interface {


/* ########################################################################## */
/* ########################################################################## */

class   AbstractInterface
{
public:

    AbstractInterface(void);


    virtual void    initialize(void)    {}
    virtual void    sendData(const String& pData)   = 0;



protected:
private:



public:
protected:
private:

};

/* ########################################################################## */
/* ########################################################################## */

} // namespace Interface
} // namespace Comm

#endif  /*< ABSTRACTINTERFACE_H */
