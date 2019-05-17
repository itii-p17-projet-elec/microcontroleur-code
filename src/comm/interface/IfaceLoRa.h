#ifndef IFACELORA_H
#define IFACELORA_H

/* Inherited classes */
#include "AbstractInterface.h"
#include "common/TSingleton.hpp"

/* System includes */

/* Libraries includes */

/* Project includes */


namespace Comm {
namespace Interface {


/* ########################################################################## */
/* ########################################################################## */

class   IfaceLoRa
        :   public  AbstractInterface
        ,   public  TSingleton<IfaceLoRa>
{
    friend class    TSingleton<IfaceLoRa>;

public:

    virtual void    initialize(void);
    virtual void    sendData(const String& pData);



protected:
private:

    IfaceLoRa(void);



public:
protected:
private:

    /** @brief  Packet counter, we increment per xmission */
    int16_t m_packetnum;

};

/* ########################################################################## */
/* ########################################################################## */

} // namespace Interface
} // namespace Comm

#endif  /*< IFACELORA_H */
