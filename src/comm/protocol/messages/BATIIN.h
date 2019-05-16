#ifndef BATIIN_H
#define BATIIN_H

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

class   BATIIN
        :   public  AbstractMessage
        ,   public  TSingleton<BATIIN>
{
    friend class    TSingleton<BATIIN>;

public:



protected:

    virtual String  generatePayload(void) const;



private:

    BATIIN(void);



public:
protected:
private:

};

/* ########################################################################## */
/* ########################################################################## */

}   /*< namespace Messages */
}   /*< namespace Comm */

#endif  /*< BATIIN_H */
