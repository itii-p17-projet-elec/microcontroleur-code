#ifndef PROTOCOLMANAGER_H
#define PROTOCOLMANAGER_H

/* Inherited classes */
#include "common/TSingleton.hpp"


/* System includes */

/* Libraries includes */

/* Project includes */
#include "messages/AbstractMessage.h"

namespace Comm {

/* ########################################################################## */
/* ########################################################################## */

class   ProtocolManager
        :   public  TSingleton<ProtocolManager>
{
    friend class TSingleton<ProtocolManager>;
public:


    void    sendMessage(const Messages::AbstractMessage *pMsgPtr);



protected:
private:

    ProtocolManager(void);



public:
protected:
private:

};

/* ########################################################################## */
/* ########################################################################## */

}   /*< namespace Comm */

#endif  /*< PROTOCOLMANAGER_H */
