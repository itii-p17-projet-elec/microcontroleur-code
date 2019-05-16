#ifndef BATIOU_H
#define BATIOU_H

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

class   BATIOU
        :   public  AbstractMessage
        ,   public  TSingleton<BATIOU>
{
    friend class    TSingleton<BATIOU>;

public:
protected:

    virtual String  generatePayload(void) const;



private:

    BATIOU(void);



public:
protected:
private:

};

/* ########################################################################## */
/* ########################################################################## */

}   /*< namespace Messages */
}   /*< namespace Comm */

#endif  /*< BATIOU_H */
