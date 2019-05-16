/* Corresponding header inclusion */
#include "CParameters.h"

/* System includes */

/* Libraries includes */

/* Project includes */

/* ########################################################################## */
/* ########################################################################## */



/* ########################################################################## */
/* ########################################################################## */

CParameters::CParameters(void)
{

}

/* ########################################################################## */
/* ########################################################################## */

void    CParameters::initialize()
{
    this->m_data.magic          = C_STRUCT_MAGIC;
    this->m_data.struct_version = C_STRUCT_VERSION;

    this->m_data.sensors_periodicTransmissionDelay_s    = 10;

    this->m_data.ambientTemperature_alertMin    = 10;
    this->m_data.ambientTemperature_alertMax    = 30;
}

/* ########################################################################## */
/* ########################################################################## */
