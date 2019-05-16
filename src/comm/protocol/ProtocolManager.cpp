/* Corresponding header inclusion */
#include "ProtocolManager.h"

/* System includes */

/* Libraries includes */
#include <Arduino.h>

/* Project includes */


namespace Comm {

/* ########################################################################## */
/* ########################################################################## */

ProtocolManager::ProtocolManager(void)
    :   m_periodicMessagesCount(0)
{

}

/* ########################################################################## */
/* ########################################################################## */

void    ProtocolManager::addPeriodicMessage(
                Messages::AbstractMessage*  pMsgPtr)
{
    if( this->m_periodicMessagesCount >= C_PERIODICMSG_MAXCOUNT )
    {
        Serial.println( "** CRITICAL ERROR ** :: Trying to add too many message"
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
    Serial.print( pMsgPtr->toString() );
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

} /*< namespace Comm */
