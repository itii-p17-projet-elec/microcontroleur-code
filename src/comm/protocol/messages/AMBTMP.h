#ifndef AMBTMP_H
#define AMBTMP_H

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

class   AMBTMP
        :   public  AbstractMessage
        ,   public  TSingleton<AMBTMP>
{
    friend class    TSingleton<AMBTMP>;

public:



protected:

    virtual String  generatePayload(void) const;



private:

    AMBTMP(void);



public:
protected:
private:

};

/* ########################################################################## */
/* ########################################################################## */

} /*< namespace Messages */
} /*< namespace Comm */

#endif  /*< AMBTMP_H */
