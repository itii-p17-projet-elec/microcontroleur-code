#ifndef BATICH_H
#define BATICH_H

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

class   BATICH
        :   public  AbstractMessage
        ,   public  TSingleton<BATICH>
{
    friend class    TSingleton<BATICH>;

public:



protected:

    virtual String  generatePayload(void) const;



private:

    BATICH(void);



public:
protected:
private:

};

/* ########################################################################## */
/* ########################################################################## */

}   /*< namespace Messages */
}   /*< namespace Comm */

#endif  /*< BATICH_H */
