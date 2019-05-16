/* Corresponding header inclusion */
#include "ProtocolManager.h"

/* System includes */

/* Libraries includes */
#include <Arduino.h>

/* Project includes */
#include "common/trace.h"


namespace Comm {

/* ########################################################################## */
/* ########################################################################## */

ProtocolManager::ProtocolManager(void)
    :   m_interfacePtr(nullptr)
    ,   m_periodicMessagesCount(0)
{

}

/* ########################################################################## */
/* ########################################################################## */

void    ProtocolManager::addPeriodicMessage(
                Messages::AbstractMessage*  pMsgPtr)
{
    if( this->m_periodicMessagesCount >= C_PERIODICMSG_MAXCOUNT )
    {
        TRACELN( "** CRITICAL ERROR ** :: Trying to add too many message"
                        " instances in periodic messages list !" );
    }
    else
    {
        this->m_periodicMessagesList[this->m_periodicMessagesCount++]
                = pMsgPtr;
    }
}

/* ########################################################################## */
/* ########################################################################## */

void    ProtocolManager::sendMessage(const Messages::AbstractMessage *pMsgPtr)
{
    if( this->m_interfacePtr == nullptr )
    {
        TRACE( "*** ERROR *** " );
        TRACE( __PRETTY_FUNCTION__ );
        TRACELN( " : Trying to send message whereas no interface has"
                        " been set !" );
    }
    else
    {
        this->m_interfacePtr->sendData( pMsgPtr->encode() );
    }
}

/* ########################################################################## */
/* ########################################################################## */

void    ProtocolManager::sendPeriodicMessages(void)
{
    for(uint8_t i = 0 ; i < this->m_periodicMessagesCount ; ++i)
    {
        this->m_periodicMessagesList[i]->setAlert(false);
        this->sendMessage( this->m_periodicMessagesList[i] );
    }
}

/* ########################################################################## */
/* ########################################################################## */

void    ProtocolManager::setInterface(
                Interface::AbstractInterface *pInterfacePtr)
{
    if(pInterfacePtr != nullptr)
    {
        this->m_interfacePtr    = pInterfacePtr;
        this->m_interfacePtr->initialize();
    }
}

/* ########################################################################## */
/* ########################################################################## */

} /*< namespace Comm */
