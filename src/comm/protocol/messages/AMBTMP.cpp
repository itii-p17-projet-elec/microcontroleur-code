/* Corresponding header inclusion */
#include "AMBTMP.h"

/* System includes */

/* Libraries includes */

/* Project includes */
#include "variables_globales.h"


namespace Comm {
namespace Messages {

/* ########################################################################## */
/* ########################################################################## */

AMBTMP::AMBTMP(void)
    :   AbstractMessage("AMBTMP")
{

}

/* ########################################################################## */
/* ########################################################################## */

String  AMBTMP::generatePayload(void) const
{
    String  retval(this->m_identifier);

    /*
     *  Add "alert" field
     */
    retval  += C_FRAME_SEP;

    if(this->isAlert())
    {
        retval  += "1";
    }
    else
    {
        retval  += "0";
    }


    /*
     *  Add "value" field
     */
    retval  += C_FRAME_SEP;

    char    lBuffer[16] = {0};
    dtostrf(g_sensors.temperature.getTemperature(),
            4,2,
            lBuffer);


    retval  += lBuffer;


    return retval;
}

/* ########################################################################## */
/* ########################################################################## */

} /*< namespace Messages */
} /*< namespace Comm */
