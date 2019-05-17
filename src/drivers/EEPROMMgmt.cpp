/* Corresponding header inclusion */
#include "EEPROMMgmt.h"

/* System includes */

/* Libraries includes */
#include <Arduino.h>
#include <EEPROM/EEPROM.h>

/* Project includes */
#include "variables_globales.h"
#include "common/trace.h"

/* ########################################################################## */
/* ########################################################################## */

EEPROMMgmt::EEPROMMgmt(void)
{

}

/* ########################################################################## */
/* ########################################################################## */

void    EEPROMMgmt::loadData(void)
{
    TRACELN( __PRETTY_FUNCTION__ );


    /*
     *  Read EEPROM memory
     */
//    EEPROM.get(0, g_parameters.m_data);
    int lBytePos    = 0;
    g_parameters.m_data.magic   =   (uint32_t)EEPROM.read(lBytePos++) << 24;
    g_parameters.m_data.magic   +=  (uint32_t)EEPROM.read(lBytePos++) << 16;
    g_parameters.m_data.magic   +=  (uint32_t)EEPROM.read(lBytePos++) << 8;
    g_parameters.m_data.magic   +=  (uint32_t)EEPROM.read(lBytePos++);

    g_parameters.m_data.struct_version  +=  EEPROM.read(lBytePos++);

    g_parameters.m_data.sensors_periodicTransmissionDelay_s
            =   EEPROM.read(lBytePos++) << 8;
    g_parameters.m_data.sensors_periodicTransmissionDelay_s
            +=  EEPROM.read(lBytePos++);


    // Détection d'une mémoire non initialisée
    bool    lEepromInitialized
            = g_parameters.m_data.magic == CParameters::C_STRUCT_MAGIC;

    if( ! lEepromInitialized )
    {
        TRACE( __FUNCTION__ );
        TRACE( "EEPROM is not initialized ! (" );
        TRACE(g_parameters.m_data.magic);
        TRACE(" vs ");
        TRACE(CParameters::C_STRUCT_MAGIC);
        TRACELN(")");

        g_parameters.initialize();
    }

    this->saveData();
}

/* ########################################################################## */
/* ########################################################################## */

void    EEPROMMgmt::saveData(void)
{
    int lBytePos    = 0;

    /* Write data to the EEPROM */
#if 0
    /* Only available on newer versions of Arduino */
    EEPROM.put(0, g_parameters.m_data);
#else
    this->write32(lBytePos, g_parameters.m_data.magic);
    lBytePos    += 4;

    this->write8(lBytePos,  g_parameters.m_data.struct_version);
    lBytePos    += 1;


    this->write16(lBytePos,
                  g_parameters.m_data.sensors_periodicTransmissionDelay_s);
    lBytePos    += 2;
#endif
}

/* ########################################################################## */
/* ########################################################################## */

uint8_t EEPROMMgmt::read8(int pAddr)
{
    return EEPROM.read(pAddr);
}

/* ########################################################################## */
/* ########################################################################## */

uint16_t    EEPROMMgmt::read16(int pAddr)
{
    uint16_t    retval  = 0;

    retval  += (EEPROM.read(pAddr++) << 8);
    retval  += (EEPROM.read(pAddr++));

    return retval;
}

/* ########################################################################## */
/* ########################################################################## */

uint32_t    EEPROMMgmt::read32(int pAddr)
{
    uint32_t    retval  = 0;

    retval  += ((uint32_t)EEPROM.read(pAddr++) << 24);
    retval  += ((uint32_t)EEPROM.read(pAddr++) << 16);
    retval  += (EEPROM.read(pAddr++) << 8);
    retval  += (EEPROM.read(pAddr++));

    return retval;
}

/* ########################################################################## */
/* ########################################################################## */

void    EEPROMMgmt::write8(int pAddr, const uint8_t &pData)
{
    TRACE( __FUNCTION__);
    TRACE( " :: Writing " );
    TRACE( pData );
    TRACE( " @ ");
    TRACELN( pAddr);


    EEPROM.write(pAddr, pData );
}

/* ########################################################################## */
/* ########################################################################## */

void    EEPROMMgmt::write16(int pAddr,    const uint16_t  &pData)
{
    this->write8( pAddr++,
                 (uint8_t)((pData & 0xFF00) >> 8) );
    this->write8( pAddr++,
                 (uint8_t)((pData & 0x00FF)) );
}

/* ########################################################################## */
/* ########################################################################## */

void    EEPROMMgmt::write32(int pAddr,  const uint32_t  &pData)
{
    this->write8( pAddr++,
                 (uint8_t)((pData & 0xFF000000) >> 24) );
    this->write8( pAddr++,
                 (uint8_t)((pData & 0x00FF0000) >> 16) );
    this->write8( pAddr++,
                 (uint8_t)((pData & 0x0000FF00) >> 8) );
    this->write8( pAddr++,
                 (uint8_t)((pData & 0x000000FF)) );
}

/* ########################################################################## */
/* ########################################################################## */
