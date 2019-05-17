//
//   SDL_Arduino_INA3221 Library Test Code
//   SDL_Arduino_INA3221.cpp Arduino code - runs in continuous mode
//   Version 1.1
//   SwitchDoc Labs   January 31, 2015
//
//
// This was designed for SunAirPlus - Solar Power Controller - www.switchdoc.com
//



#include <Wire.h>

#include "common/trace.h"

#include "INA3221.h"

INA3221 ina3221;

// the three channels of the INA3221 named for SunAirPlus Solar Power Controller channels (www.switchdoc.com)
#define LIPO_BATTERY_CHANNEL 1
#define SOLAR_CELL_CHANNEL 2
#define OUTPUT_CHANNEL 3

void setup(void)
{

    Serial.begin(115200);
    TRACELN("SDA_Arduino_INA3221_Test");

    TRACELN("Measuring voltage and current with ina3221 ...");
    ina3221.begin();
}

void loop(void)
{

    TRACELN("------------------------------");
    float shuntvoltage1 = 0;
    float busvoltage1 = 0;
    float current_mA1 = 0;
    float loadvoltage1 = 0;


    busvoltage1 = ina3221.getBusVoltage_V(LIPO_BATTERY_CHANNEL);
    shuntvoltage1 = ina3221.getShuntVoltage_mV(LIPO_BATTERY_CHANNEL);
    current_mA1 = -ina3221.getCurrent_mA(LIPO_BATTERY_CHANNEL);  // minus is to get the "sense" right.   - means the battery is charging, + that it is discharging
    loadvoltage1 = busvoltage1 + (shuntvoltage1 / 1000);

    TRACE("LIPO_Battery Bus Voltage:   "); TRACE(busvoltage1); TRACELN(" V");
    TRACE("LIPO_Battery Shunt Voltage: "); TRACE(shuntvoltage1); TRACELN(" mV");
    TRACE("LIPO_Battery Load Voltage:  "); TRACE(loadvoltage1); TRACELN(" V");
    TRACE("LIPO_Battery Current 1:       "); TRACE(current_mA1); TRACELN(" mA");
    TRACELN("");

    float shuntvoltage2 = 0;
    float busvoltage2 = 0;
    float current_mA2 = 0;
    float loadvoltage2 = 0;

    busvoltage2 = ina3221.getBusVoltage_V(SOLAR_CELL_CHANNEL);
    shuntvoltage2 = ina3221.getShuntVoltage_mV(SOLAR_CELL_CHANNEL);
    current_mA2 = -ina3221.getCurrent_mA(SOLAR_CELL_CHANNEL);
    loadvoltage2 = busvoltage2 + (shuntvoltage2 / 1000);

    TRACE("Solar Cell Bus Voltage 2:   "); TRACE(busvoltage2); TRACELN(" V");
    TRACE("Solar Cell Shunt Voltage 2: "); TRACE(shuntvoltage2); TRACELN(" mV");
    TRACE("Solar Cell Load Voltage 2:  "); TRACE(loadvoltage2); TRACELN(" V");
    TRACE("Solar Cell Current 2:       "); TRACE(current_mA2); TRACELN(" mA");
    TRACELN("");

    float shuntvoltage3 = 0;
    float busvoltage3 = 0;
    float current_mA3 = 0;
    float loadvoltage3 = 0;

    busvoltage3 = ina3221.getBusVoltage_V(OUTPUT_CHANNEL);
    shuntvoltage3 = ina3221.getShuntVoltage_mV(OUTPUT_CHANNEL);
    current_mA3 = ina3221.getCurrent_mA(OUTPUT_CHANNEL);
    loadvoltage3 = busvoltage3 + (shuntvoltage3 / 1000);

    TRACE("Output Bus Voltage 3:   "); TRACE(busvoltage3); TRACELN(" V");
    TRACE("Output Shunt Voltage 3: "); TRACE(shuntvoltage3); TRACELN(" mV");
    TRACE("Output Load Voltage 3:  "); TRACE(loadvoltage3); TRACELN(" V");
    TRACE("Output Current 3:       "); TRACE(current_mA3); TRACELN(" mA");
    TRACELN("");

    delay(2000);
}
