#ifndef CPARAMETERS_H
#define CPARAMETERS_H

/* Inherited classes */


/* System includes */
#include <stdint.h>

/* Libraries includes */

/* Project includes */

/* ########################################################################## */
/* ########################################################################## */

class   CParameters
{
public:

    CParameters(void);


    void    initialize(void);



protected:
private:



public:

    /** The "magic number" for the \ref CParameters::StrData data struct */
    static const uint32_t   C_STRUCT_MAGIC      = 123456788;

    /** Current version number of the data struct \ref CParameters::StrData */
    static const uint8_t    C_STRUCT_VERSION    = 1;

    /**
     *  @brief This struct represents user parameters as saved in the EEPROM.
     */
    struct  StrData
    {
        uint32_t    magic;
        uint8_t     struct_version;


        /**
         *  @brief  This variable contains the delay between each periodic
         *          sensors data emission, expressed in seconds.
         */
        uint16_t    sensors_periodicTransmissionDelay_s;

    }   m_data;



protected:
private:

};

/* ########################################################################## */
/* ########################################################################## */

#endif  /*< CPARAMETERS_H */
