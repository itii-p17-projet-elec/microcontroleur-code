/* Corresponding header inclusion */
#include "CSensors.h"

/* System includes */

/* Libraries includes */
#include <Arduino.h>

/* Project includes */


/* ########################################################################## */
/* ########################################################################## */

CSensors::CSensors(void)
{

}

/* ########################################################################## */
/* ########################################################################## */

void    CSensors::initialize(void)
{
    this->temperature.begin();
}

/* ########################################################################## */
/* ########################################################################## */

void    CSensors::update(void)
{
    if( this->temperature.readData() != 0 )
    {
        Serial.print(__PRETTY_FUNCTION__);
        Serial.println(" :: WARN : An error occured while updating"
                       " AM2320 sensor data.");
    }
}

/* ########################################################################## */
/* ########################################################################## */
