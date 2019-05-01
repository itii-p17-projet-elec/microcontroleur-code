#include <Arduino.h>

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
    Serial.println("\n~~~ Hello, World ! ~~~");
    Serial.println("# Demo for TI ADS1015 sensor.");

    Serial.println("Getting single-ended readings from AIN0..3");
    Serial.println("ADC Range: +/- 6.144V (1 bit = 3mV)");
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
    Serial.println("+-- New measure :");
    Serial.print("    +-- AIN0: "); Serial.print(adc0);Serial.print(" ( "); Serial.print(adc0 * 3);Serial.println(" mV )");
    Serial.print("    +-- AIN1: "); Serial.print(adc1);Serial.print(" ( "); Serial.print(adc1 * 3);Serial.println(" mV )");
    Serial.print("    +-- AIN2: "); Serial.print(adc2);Serial.print(" ( "); Serial.print(adc2 * 3);Serial.println(" mV )");
    Serial.print("    +-- AIN3: "); Serial.print(adc3);Serial.print(" ( "); Serial.print(adc3 * 3);Serial.println(" mV )");

    Serial.print("    +-- D01: ");
    Serial.print(adc_diff_0_1);
    Serial.print("(");
    Serial.print(adc_diff_0_1 * 3);
    Serial.println("mV)");

    Serial.print("    +-- D23: ");
    Serial.print(adc_diff_2_3);
    Serial.print("(");
    Serial.print(adc_diff_2_3 * 3);
    Serial.println("mV)");
    Serial.println("");

    delay(1000);
#else
    Serial.print("$");
    Serial.print(adc0);
    Serial.print(C_CHAR_SEP);
    Serial.print(adc1);
    Serial.print(C_CHAR_SEP);
    Serial.print(adc2);
    Serial.print(C_CHAR_SEP);
    Serial.print(adc3);
    Serial.print(C_CHAR_SEP);
    Serial.print(adc_diff_0_1);
    Serial.print(C_CHAR_SEP);
    Serial.print(adc_diff_2_3);
    Serial.print(C_CHAR_SEP);
    Serial.print("*\r\n");
    delay(100);
#endif

}

/* ########################################################################## */
/* ########################################################################## */
