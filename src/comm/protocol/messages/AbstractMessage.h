#ifndef ABSTRACTMESSAGE_H
#define ABSTRACTMESSAGE_H

/* Inherited classes */


/* System includes */

/* Libraries includes */
#include <Arduino.h>

/* Project includes */

namespace Comm {
namespace Messages {

/* ########################################################################## */
/* ########################################################################## */

class   AbstractMessage
{
public:

    AbstractMessage(const String& pMsgID);


    bool    isAlert(void) const;
    void    setAlert(const bool& pAlert);


    String  encode(void) const;



protected:
private:

    static uint8_t calculateChecksum(const String& pPayloadStr);


    virtual String  generatePayload(void) const = 0;



public:

    static const char   C_FRAME_BEGIN   = '$';
    static const char   C_FRAME_CS_SEP  = '*';
    static const String C_FRAME_END;
    static const char   C_FRAME_SEP  = ',';



protected:

    bool        m_alert;
    String      m_identifier;



private:

};

/* ########################################################################## */
/* ########################################################################## */

}   /*< namespace Messages */
}   /*< namespace Comm */

#endif  /*< ABSTRACTMESSAGE_H */
