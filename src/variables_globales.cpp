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
bool    g_flag_keypad   = false;


/**
 *  @brief  This global object represents keypad's current state.
 */
Keypad  g_keypad( C_PIN_KEYPAD_SW );

/* ########################################################################## */
/* ########################################################################## */
