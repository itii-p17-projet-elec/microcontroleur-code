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
    if( this->temperature.measure() != 0 )
    {
        Serial.print(__PRETTY_FUNCTION__);
        Serial.print(" :: WARN : An error occured while updating"
                       " AM2320 sensor data : ");

        switch (this->temperature.getErrorCode())
        {
            case 1:
                Serial.println("Sensor is offline");
                break;


            case 2:
                Serial.println("CRC validation failed.");
                break;


            default:
                Serial.println("Unknown error!");
                break;
        }
    }
}

/* ########################################################################## */
/* ########################################################################## */
