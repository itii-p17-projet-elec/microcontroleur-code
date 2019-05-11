#ifndef CSENSORS_H
#define CSENSORS_H

/* Inherited classes */


/* System includes */

/* Libraries includes */

/* Project includes */
#include "drivers/sensors/AM2320.h"

/* ########################################################################## */
/* ########################################################################## */

class   CSensors
{
public:

    CSensors(void);


    void    initialize(void);



protected:
private:



public:

    /**
     *  @brief  This object represents the external temperature sensor.
     */
    AM2320  temperature;



protected:
private:

};

/* ########################################################################## */
/* ########################################################################## */

#endif  /*< CSENSORS_H */
