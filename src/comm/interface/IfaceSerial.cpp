/* Corresponding header inclusion */
#include "IfaceSerial.h"

/* System includes */

/* Libraries includes */
#include <Arduino.h>

/* Project includes */


namespace Comm {
namespace Interface {

/* ########################################################################## */
/* ########################################################################## */

IfaceSerial::IfaceSerial(void)
{

}

/* ########################################################################## */
/* ########################################################################## */

void    IfaceSerial::initialize()
{
    Serial.begin(115200);
    while (!Serial)
    {
        ; // wait for serial port to connect. Needed for Leonardo only
    }
}

/* ########################################################################## */
/* ########################################################################## */

void    IfaceSerial::sendData(const String &pData)
{
    Serial.print( pData );
}

/* ########################################################################## */
/* ########################################################################## */

} // namespace Interface
} // namespace Comm
