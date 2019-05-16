/* Corresponding header inclusion */
#include "BATIDE.h"

/* System includes */

/* Libraries includes */

/* Project includes */


namespace Comm {
namespace Messages {

/* ########################################################################## */
/* ########################################################################## */

BATIDE::BATIDE(void)
    :   AbstractMessage("BATIDE")
{

}

/* ########################################################################## */
/* ########################################################################## */

String  BATIDE::generatePayload(void) const
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
#if 0
    char    lBuffer[16] = {0};
    dtostrf(g_sensors.battery_intensity_decharge,
            4,2,
            lBuffer);


    retval  += lBuffer;
#else
    retval  += "<-- TODO -->";
#endif

    return retval;
}

/* ########################################################################## */
/* ########################################################################## */

}   /*< namespace Messages */
}   /*< namespace Comm */
