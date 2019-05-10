/* Corresponding header inclusion */
#include "PowerMgmt.h"

/* System includes */
#include <avr/power.h>
#include <avr/sleep.h>

/* Libraries includes */

/* Project includes */


/* ########################################################################## */
/* ########################################################################## */

void    PowerMgmt::enterSleep(void)
{
    set_sleep_mode(SLEEP_MODE_IDLE);
    sleep_enable();


    /* Disable all of the unused peripherals. This will reduce power
     * consumption further and, more importantly, some of these
     * peripherals may generate interrupts that will wake our MCU from
     * sleep!
     */
    power_adc_disable();
    power_spi_disable();
//    power_timer0_disable();
//    power_timer2_disable();
    power_twi_disable();

    /* Now enter sleep mode. */
    sleep_mode();

    /* The program will continue from here when woken up */
    sleep_disable(); /* First thing to do is disable sleep. */

    /* Re-enable the peripherals. */
    power_all_enable();
}

/* ########################################################################## */
/* ########################################################################## */
