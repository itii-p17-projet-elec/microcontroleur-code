#ifndef BATVOU_H
#define BATVOU_H

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

class   BATVOU
        :   public  AbstractMessage
        ,   public  TSingleton<BATVOU>
{
    friend class    TSingleton<BATVOU>;

public:
protected:

    virtual String  generatePayload(void) const;



private:

    BATVOU(void);



public:
protected:
private:

};

/* ########################################################################## */
/* ########################################################################## */

}   /*< namespace Messages */
}   /*< namespace Comm */

#endif  /*< BATVOU_H */
