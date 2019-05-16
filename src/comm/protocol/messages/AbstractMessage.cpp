/* Corresponding header inclusion */
#include "AbstractMessage.h"

/* System includes */

/* Libraries includes */

/* Project includes */


namespace Comm {
namespace Messages {

const String    AbstractMessage::C_FRAME_END    = String("\r\n");

/* ########################################################################## */
/* ########################################################################## */

AbstractMessage::AbstractMessage(const String &pMsgID)
    :   m_alert(false)
    ,   m_identifier(pMsgID)
{

}

/* ########################################################################## */
/* ########################################################################## */

uint8_t AbstractMessage::calculateChecksum(const String &pPayloadStr)
{
    uint8_t retval  = 0x00;


    for(unsigned int i = 0 ; i < pPayloadStr.length() ; ++i)
    {
        retval  ^= pPayloadStr.charAt(i);
    }


    return retval;
}

/* ########################################################################## */
/* ########################################################################## */

bool    AbstractMessage::isAlert(void) const
{
    return this->m_alert;
}

/* ########################################################################## */
/* ########################################################################## */

void    AbstractMessage::setAlert(const bool &pAlert)
{
    this->m_alert   = pAlert;
}

/* ########################################################################## */
/* ########################################################################## */

String  AbstractMessage::toString() const
{
    String  retval;

    String lPayload = this->generatePayload();


    retval  += C_FRAME_BEGIN;
    retval  += lPayload;
    retval  += C_FRAME_CS_SEP;
    retval  += calculateChecksum(lPayload);
    retval  += C_FRAME_END;

    return retval;
}

/* ########################################################################## */
/* ########################################################################## */

}   /*< namespace Messages */
}   /*< namespace Comm */
