#ifndef BATTMP_H
#define BATTMP_H

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

class   BATTMP
        :   public  AbstractMessage
        ,   public  TSingleton<BATTMP>
{
    friend class    TSingleton<BATTMP>;

public:
protected:

    virtual String  generatePayload(void) const;



private:

    BATTMP(void);



public:
protected:
private:

};

/* ########################################################################## */
/* ########################################################################## */

}   /*< namespace Messages */
}   /*< namespace Comm */

#endif  /*< BATTMP_H */
