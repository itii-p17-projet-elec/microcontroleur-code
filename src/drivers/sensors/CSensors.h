#ifndef CSENSORS_H
#define CSENSORS_H

/* Inherited classes */


/* System includes */

/* Libraries includes */

/* Project includes */
#include "drivers/ADC/Adafruit_ADS1015.h"
#include "drivers/sensors/AM2320.h"
#include "drivers/sensors/INA3221.h"

/* ########################################################################## */
/* ########################################################################## */

class   CSensors
{
public:

    CSensors(void);


    void    initialize(void);

    void    update(void);


    float   ambientTemperature_c(void) const;
    float   batteryTemperature_c(void) const;

    float   batteryInputCurrent_mA(void) const;
    float   batteryInputVoltage_V(void) const;
    float   batteryOutputCurrent_mA(void) const;
    float   batteryOutputVoltage_V(void) const;



protected:
private:



public:



protected:
private:

    /**
     *  @brief  This object represents the external temperature sensor.
     */
    AM2320              m_AM2320_ambient;

    /** @brief  This object interacts with the ADC on the battery sub-system. */
    Adafruit_ADS1015    m_ADS1015_1;

    /** @brief  This object interacts with the battery monitoring IC. */
    INA3221             m_INA3221;


    float   m_data_ambientTemperature_c;
    float   m_data_batteryInputCurrent_mA;
    float   m_data_batteryInputVoltage_V;
    float   m_data_batteryOutputCurrent_mA;
    float   m_data_batteryOutputVoltage_V;
    float   m_data_batteryTemperature_c;

};

/* ########################################################################## */
/* ########################################################################## */

#endif  /*< CSENSORS_H */
