#include <Arduino.h>

#include "common/trace.h"
#include "drivers/ADC/Adafruit_ADS1015.h"

const int   C_PIN_LED   =  13;    // LED connected to digital pin 13

Adafruit_ADS1015 ads1015;
int16_t adc0, adc1, adc2, adc3;
int16_t adc_diff_0_1    = 0;
int16_t adc_diff_2_3    = 0;

static const char   C_CHAR_SEP  = ',';

/* ########################################################################## */
/* ########################################################################## */

void setup()
{
    pinMode(C_PIN_LED, OUTPUT);


    Serial.begin(9600);
    TRACELN("\n~~~ Hello, World ! ~~~");
    TRACELN("# Demo for TI ADS1015 sensor.");

    TRACELN("Getting single-ended readings from AIN0..3");
    TRACELN("ADC Range: +/- 6.144V (1 bit = 3mV)");
    ads1015.begin();
}

/* ########################################################################## */
/* ########################################################################## */

void loop()
{
    digitalWrite(C_PIN_LED, HIGH);

    adc0 = ads1015.readADC_SingleEnded(0);
    adc1 = ads1015.readADC_SingleEnded(1);
    adc2 = ads1015.readADC_SingleEnded(2);
    adc3 = ads1015.readADC_SingleEnded(3);
    adc_diff_0_1 = ads1015.readADC_Differential_0_1();
    adc_diff_2_3 = ads1015.readADC_Differential_2_3();

    digitalWrite(C_PIN_LED, LOW);

#if 1
    TRACELN("+-- New measure :");
    TRACE("    +-- AIN0: "); TRACE(adc0);TRACE(" ( "); TRACE(adc0 * 3);TRACELN(" mV )");
    TRACE("    +-- AIN1: "); TRACE(adc1);TRACE(" ( "); TRACE(adc1 * 3);TRACELN(" mV )");
    TRACE("    +-- AIN2: "); TRACE(adc2);TRACE(" ( "); TRACE(adc2 * 3);TRACELN(" mV )");
    TRACE("    +-- AIN3: "); TRACE(adc3);TRACE(" ( "); TRACE(adc3 * 3);TRACELN(" mV )");

    TRACE("    +-- D01: ");
    TRACE(adc_diff_0_1);
    TRACE("(");
    TRACE(adc_diff_0_1 * 3);
    TRACELN("mV)");

    TRACE("    +-- D23: ");
    TRACE(adc_diff_2_3);
    TRACE("(");
    TRACE(adc_diff_2_3 * 3);
    TRACELN("mV)");
    TRACELN("");

    delay(1000);
#else
    TRACE("$");
    TRACE(adc0);
    TRACE(C_CHAR_SEP);
    TRACE(adc1);
    TRACE(C_CHAR_SEP);
    TRACE(adc2);
    TRACE(C_CHAR_SEP);
    TRACE(adc3);
    TRACE(C_CHAR_SEP);
    TRACE(adc_diff_0_1);
    TRACE(C_CHAR_SEP);
    TRACE(adc_diff_2_3);
    TRACE(C_CHAR_SEP);
    TRACE("*\r\n");
    delay(100);
#endif

}

/* ########################################################################## */
/* ########################################################################## */
