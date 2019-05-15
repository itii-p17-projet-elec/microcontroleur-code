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
{

}

/* ########################################################################## */
/* ########################################################################## */

void ProtocolManager::sendMessage(const Messages::AbstractMessage *pMsgPtr)
{
    Serial.print( pMsgPtr->toString() );
}

/* ########################################################################## */
/* ########################################################################## */

} /*< namespace Comm */
