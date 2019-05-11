#ifndef AM2320_H
#define AM2320_H

/* Inherited classes */


/* System includes */
#include <stdint.h>

/* Libraries includes */

/* Project includes */

/* ########################################################################## */
/* ########################################################################## */
/**
 *  @brief The AM2320 class
 *
 *  @see    Datasheet : https://www.mouser.fr/datasheet/2/737/AM2320-1313931.pdf
 */
class   AM2320
{
public:

    AM2320(uint8_t pI2C_ADDR=I2C_ADDR);


    void    begin(void);


    int     readData(void);


    uint8_t i2cAddress(void) const;
    float   humidity_pc(void) const;
    float   temperature_degC(void) const;



protected:
private:



public:

    static const uint8_t    I2C_ADDR;



protected:
private:

    uint8_t     m_i2c_addr;
    float       m_humidity_pc;
    float       m_temperature_degC;

};

/* ########################################################################## */
/* ########################################################################## */

#endif  /*< AM2320_H */
