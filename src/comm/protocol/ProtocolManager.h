#ifndef PROTOCOLMANAGER_H
#define PROTOCOLMANAGER_H

/* Inherited classes */
#include "common/TSingleton.hpp"


/* System includes */

/* Libraries includes */

/* Project includes */
#include "comm/interface/AbstractInterface.h"
#include "messages/AbstractMessage.h"

namespace Comm {

/* ########################################################################## */
/* ########################################################################## */

class   ProtocolManager
        :   public  TSingleton<ProtocolManager>
{
    friend class TSingleton<ProtocolManager>;
public:


    void    setInterface(Comm::Interface::AbstractInterface* pInterfacePtr);


    void    addPeriodicMessage(Messages::AbstractMessage *pMsgPtr);

    void    sendMessage(const Messages::AbstractMessage *pMsgPtr);
    void    sendPeriodicMessages(void);



protected:
private:

    ProtocolManager(void);



public:
protected:
private:

    static const uint8_t    C_PERIODICMSG_MAXCOUNT  = 20;


    Comm::Interface::AbstractInterface* m_interfacePtr;

    Comm::Messages::AbstractMessage*    m_periodicMessagesList[C_PERIODICMSG_MAXCOUNT];
    uint8_t                             m_periodicMessagesCount;

};

/* ########################################################################## */
/* ########################################################################## */

}   /*< namespace Comm */

#endif  /*< PROTOCOLMANAGER_H */
