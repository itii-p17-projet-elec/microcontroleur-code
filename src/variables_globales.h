#ifndef VARIABLES_GLOBALES_H
#define VARIABLES_GLOBALES_H

/* Inherited classes */


/* System includes */

/* Libraries includes */

/* Project includes */
#include "data/CParameters.h"
#include "drivers/Keypad.h"
#include "drivers/sensors/CSensors.h"

/* ########################################################################## */
/* ########################################################################## */

extern const int    C_TIMER1_COUNTER_PRELOAD;

//extern bool     g_flag_keypad;

extern bool     g_flag_processDelayedEvents_1s;
extern bool     g_flag_processDelayedEvents_50ms;

extern Keypad   g_keypad;

extern CSensors g_sensors;

extern CParameters  g_parameters;

/* ########################################################################## */
/* ########################################################################## */

#endif  /*< VARIABLES_GLOBALES_H */
