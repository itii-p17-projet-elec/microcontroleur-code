/* Corresponding header inclusion */
#include "BATIOU.h"

/* System includes */

/* Libraries includes */

/* Project includes */
#include "variables_globales.h"


namespace Comm {
namespace Messages {

/* ########################################################################## */
/* ########################################################################## */

BATIOU::BATIOU(void)
    :   AbstractMessage("BATIOU")
{

}

/* ########################################################################## */
/* ########################################################################## */

String  BATIOU::generatePayload(void) const
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
#if 1
    char    lBuffer[16] = {0};
    dtostrf(g_sensors.batteryOutputCurrent_mA(),
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
