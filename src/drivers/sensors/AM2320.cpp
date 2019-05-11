/* Corresponding header inclusion */
#include "AM2320.h"

/* System includes */

/* Libraries includes */
#include <Arduino.h>
#include <Wire.h>

/* Project includes */


#define AM2320_FUNCCODE_READ            (0x03)
#define AM2320_FUNCCODE_WRITE           (0x10)

#define AM2320_REGADDR_HUMIDITY_MSB     (0x00)
#define AM2320_REGADDR_HUMIDITY_LSB     (0x01)
#define AM2320_REGADDR_TEMPERATURE_MSB  (0x02)
#define AM2320_REGADDR_TEMPERATURE_LSB  (0x03)
/* 0x04 to 0x07 : Retention. */
#define AM2320_REGADDR_MODEL_H          (0x08)
#define AM2320_REGADDR_MODEL_L          (0x09)
#define AM2320_REGADDR_VERSION          (0x0A)
#define AM2320_REGADDR_DEVICEID1        (0x0B)
#define AM2320_REGADDR_DEVICEID2        (0x0C)
#define AM2320_REGADDR_DEVICEID3        (0x0D)
#define AM2320_REGADDR_DEVICEID4        (0x0E)
#define AM2320_REGADDR_STATUS           (0x0F)
#define AM2320_REGADDR_USERREG1_H       (0x10)
#define AM2320_REGADDR_USERREG1_L       (0x11)
#define AM2320_REGADDR_USERREG2_H       (0x12)
#define AM2320_REGADDR_USERREG2_L       (0x13)
/* 0x14  to 0x1F : Retention. */

/** @brief  Default I2C address of the AM2320 sensor. */
const uint8_t   AM2320::I2C_ADDR    = 0x5C;

/* ########################################################################## */
/* ########################################################################## */
/**
 *  @brief  CRC function from datasheet.
 *
 *  @param  ptr
 *  @param  length
 *  @return
 */
uint16_t    CRC16(uint8_t *ptr, uint8_t length)
{
    uint16_t    crc = 0xFFFF;
    uint8_t     s   = 0x00;


    while(length--)
    {
        crc ^= *ptr++;
        for(s = 0; s < 8; s++)
        {
            if((crc & 0x01) != 0)
            {
                crc >>= 1;
                crc ^= 0xA001;
            }
            else
            {
                crc >>= 1;
            }
        }
    }


    return crc;
}

/* ########################################################################## */
/* ########################################################################## */
/**
 *  @brief  Constructor.
 *
 *  @param  pI2C_ADDR   The I2C address of the sensor.
 */
AM2320::AM2320(uint8_t pI2C_ADDR)
    :   m_i2c_addr(pI2C_ADDR)
    ,   m_humidity_pc(-9999.99)
    ,   m_temperature_degC(-9999.99)
{

}

/* ########################################################################## */
/* ########################################################################## */

void    AM2320::begin(void)
{
    Wire.begin();
}

/* ########################################################################## */
/* ########################################################################## */
/**
 *  @brief  Accessor for humidity value, expressed in percents.
 *
 *  @returns    The value of the \ref AM2320::m_humidity_pc member.
 */
float   AM2320::humidity_pc(void) const
{
    return this->m_humidity_pc;
}

/* ########################################################################## */
/* ########################################################################## */
/**
 *  @brief  Accessor for sensor's I2C address.
 *
 *  @returns    The value of the \ref AM2320::m_i2c_addr member.
 */
uint8_t AM2320::i2cAddress(void) const
{
    return this->m_i2c_addr;
}

/* ########################################################################## */
/* ########################################################################## */
/**
 *  @brief  Reads data from sensor and updates local variables.
 *
 *  @retval 1   If sensor is not accessible ;
 *  @retval 2   If a CRC error has been detected in sensor's answer ;
 *  @retval 0   Otherwise.
 */
int AM2320::readData(void)
{
    uint8_t buf[8];
    for(int s = 0; s < 8; s++) buf[s] = 0x00;

    Wire.beginTransmission(this->i2cAddress());
    Wire.endTransmission();


    Wire.beginTransmission(this->i2cAddress()); /*< Sensor address */
    Wire.write(AM2320_FUNCCODE_READ);           /*< Function code */
    Wire.write(AM2320_REGADDR_HUMIDITY_MSB);    /*< Register start address */
    Wire.write(0x04);                           /*< Registers count to read */
    if(Wire.endTransmission(1) != 0)
    {
        return 1;
    }


    delayMicroseconds(1600); //>1.5ms

    // Lecture des resultats
    Wire.requestFrom(this->i2cAddress(), (uint8_t)0x08);
    for(int i = 0; i < 0x08; i++)
    {
        buf[i] = Wire.read();
    }

    // CRC check
    uint8_t Rcrc = buf[7] << 8;
    Rcrc += buf[6];
    if (Rcrc != CRC16(buf, 6))
    {
        return 2;
    }


    unsigned int temperature = ((buf[4] & 0x7F) << 8) + buf[5];
    m_temperature_degC = temperature / 10.0;
    m_temperature_degC
            =   ((buf[4] & 0x80) >> 7) == 1
                ?   m_temperature_degC * (-1)
                :   m_temperature_degC;

    unsigned int humidity = (buf[2] << 8) + buf[3];
    m_humidity_pc = humidity / 10.0;


    return 0;
}

/* ########################################################################## */
/* ########################################################################## */
/**
 *  @brief  Accessor for temperature value, expressed in celsius degrees.
 *
 *  @returns    The value of the \ref AM2320::m_temperature_degC member.
 */
float   AM2320::temperature_degC(void) const
{
    return this->m_temperature_degC;
}

/* ########################################################################## */
/* ########################################################################## */
