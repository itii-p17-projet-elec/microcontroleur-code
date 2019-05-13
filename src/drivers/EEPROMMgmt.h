#ifndef EEPROMMGMT_H
#define EEPROMMGMT_H

/* Inherited classes */


/* System includes */
#include <stdint.h>

/* Libraries includes */

/* Project includes */

/* ########################################################################## */
/* ########################################################################## */

class   EEPROMMgmt
{
public:

    EEPROMMgmt(void);


    void    loadData(void);
    void    saveData(void);



protected:
private:

    uint8_t     read8(int pAddr);
    uint16_t    read16(int pAddr);
    uint32_t    read32(int pAddr);

    void        write8(int pAddr,   const uint8_t&  pData );
    void        write16(int pAddr,  const uint16_t& pData );
    void        write32(int pAddr,  const uint32_t& pData );



public:
protected:
private:

};

/* ########################################################################## */
/* ########################################################################## */

#endif  /*< EEPROMMGMT_H */
