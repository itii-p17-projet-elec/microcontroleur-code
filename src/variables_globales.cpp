/* Corresponding header inclusion */
#include "variables_globales.h"

/* System includes */

/* Libraries includes */

/* Project includes */
#include "hardware_defines.h"


/* ########################################################################## */
/* ########################################################################## */

/* 16MHz / 256 / 20Hz */
const int    C_TIMER1_COUNTER_PRELOAD   = 62411;


/**
 *  @brief  This flag shall be raised by ISR when an activity is detected on
 *          the keypad ; It is then reset by the main loop.
 */
//bool    g_flag_keypad   = false;


/**
 *  @brief  This flag is raised by an ISR every second to signal the main loop
 *          that some events shall be processed.
 */
bool    g_flag_processDelayedEvents_1s  = false;


/**
 *  @brief  This flag is raised by an ISR every 50 ms to signal the main loop
 *          that some events shall be processed.
 */
bool    g_flag_processDelayedEvents_50ms    = false;


/**
 *  @brief  This global object represents keypad's current state.
 */
Keypad  g_keypad( C_PIN_KEYPAD_SW );



/**
 *  @brief  This object represents the external temperature sensor.
 */
CSensors    g_sensors;

/* ########################################################################## */
/* ########################################################################## */

