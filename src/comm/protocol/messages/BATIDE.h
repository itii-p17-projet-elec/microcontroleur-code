#ifndef BATIDE_H
#define BATIDE_H

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

class   BATIDE
        :   public  AbstractMessage
        ,   public  TSingleton<BATIDE>
{
    friend class    TSingleton<BATIDE>;

public:
protected:

    virtual String  generatePayload(void) const;



private:

    BATIDE(void);



public:
protected:
private:

};

/* ########################################################################## */
/* ########################################################################## */

}   /*< namespace Messages */
}   /*< namespace Comm */

#endif  /*< BATIDE_H */
