#ifndef IFACESERIAL_H
#define IFACESERIAL_H

/* Inherited classes */
#include "AbstractInterface.h"
#include "common/TSingleton.hpp"

/* System includes */

/* Libraries includes */

/* Project includes */


namespace Comm {
namespace Interface {


/* ########################################################################## */
/* ########################################################################## */

class   IfaceSerial
        :   public  AbstractInterface
        ,   public  TSingleton<IfaceSerial>
{
    friend class    TSingleton<IfaceSerial>;

public:


    virtual void    initialize(void);
    virtual void    sendData(const String& pData);



protected:
private:

    IfaceSerial(void);



public:
protected:
private:

};

/* ########################################################################## */
/* ########################################################################## */

} // namespace Interface
} // namespace Comm

#endif  /*< IFACESERIAL_H */
