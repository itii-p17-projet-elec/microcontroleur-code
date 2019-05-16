#ifndef BATVIN_H
#define BATVIN_H

/* Inherited classes */
#include "AbstractMessage.h"
#include "common/TSingleton.hpp"

/* System includes */

/* Libraries includes */

/* Project includes */


namespace Comm {
namespace Messages {


/* ########################################################################## */
/* ########################################################################## */

class   BATVIN
        :   public  AbstractMessage
        ,   public  TSingleton<BATVIN>
{
    friend class    TSingleton<BATVIN>;

public:
protected:

    virtual String  generatePayload(void) const;



private:

    BATVIN(void);



public:
protected:
private:

};

/* ########################################################################## */
/* ########################################################################## */

}   /*< namespace Messages */
}   /*< namespace Comm */

#endif  /*< BATVIN_H */
