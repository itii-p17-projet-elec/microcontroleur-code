/* Corresponding header inclusion */
#include "CSensors.h"

/* System includes */
#include <math.h>

/* Libraries includes */
#include <Arduino.h>

/* Project includes */
#include "variables_globales.h"
#include "comm/protocol/ProtocolManager.h"
#include "comm/protocol/messages/AMBTMP.h"


#define C_SENSOR_DEFAULTVALUE_F         (-999.99)
#define C_SENSOR_ADS1015_1_CH_AMBTMP    (1)
#define C_SENSOR_ADS1015_1_CH_BATTMP    (0)
#define C_SENSOR_INA3321_CH_SOLARCELL   (1)
#define C_SENSOR_INA3321_CH_OUTPUT      (2)

/* ########################################################################## */
/* ########################################################################## */
/**
 *  @brief  Returns a temperature from the CTN voltage.
 *
 * @see this page for more details :
 * http://f4cvm.free.fr/arduino/shields/capteur/temperature/ctn/temperature_ctn.htm
 *
 *  @param  pVoltage_mv The measured voltage in milivolts, with full range being
 *                      5V.
 *
 * @return  The temperature value in celsius degrees.
 */
double  CTN_calculateTemperature(const double& pVoltage_mv)
{
#if 0
    //Calcul de la tension sur la borne analogique
//    double valeurAnalog = analogRead(PIN_NTC);
//    double V =  valeurAnalog / 1024 * V_IN;

    //Calcul de la résistance de la thermistance
    double Rth = (Rref * V ) / (V_IN - V);
    Serial.print("Rth = ");
    Serial.print(Rth);

    //Calcul de la température en kelvin( Steinhart and Hart)
    double kelvin = SteinhartHart(Rth);
    double celsius = kelvin - 273.15; //Conversion en celsius
    Serial.print("Ohm  -  T = ");
    Serial.print(celsius);
    Serial.print("C\n");
#else
    float R1 = 10000;
    float logR2, R2, T;
    const float c1 = 1.009249522e-03, c2 = 2.378405444e-04, c3 = 2.019202697e-07;

//    Vo = analogRead(ThermistorPin);
    R2 = R1 * ((5000.0 / (float)pVoltage_mv) - 1.0);
    logR2 = log(R2);
    T = (1.0 / (c1 + c2*logR2 + c3*logR2*logR2*logR2));
    T = T - 273.15;

    return T;
#endif
}

/* ########################################################################## */
/* ########################################################################## */

CSensors::CSensors(void)
    :   m_data_ambientTemperature_c(C_SENSOR_DEFAULTVALUE_F)
    ,   m_data_batteryInputCurrent_mA(C_SENSOR_DEFAULTVALUE_F)
    ,   m_data_batteryInputVoltage_V(C_SENSOR_DEFAULTVALUE_F)
    ,   m_data_batteryOutputCurrent_mA(C_SENSOR_DEFAULTVALUE_F)
    ,   m_data_batteryOutputVoltage_V(C_SENSOR_DEFAULTVALUE_F)
    ,   m_data_batteryTemperature_c(C_SENSOR_DEFAULTVALUE_F)
{

}

/* ########################################################################## */
/* ########################################################################## */
/**
 *  @brief  Accessor for the ambient temperature expressed in celsius degrees.
 */
float   CSensors::ambientTemperature_c(void) const
{
    return this->m_data_ambientTemperature_c;
}

/* ########################################################################## */
/* ########################################################################## */

float   CSensors::batteryInputCurrent_mA(void) const
{
    return this->m_data_batteryInputCurrent_mA;
}

/* ########################################################################## */
/* ########################################################################## */

float   CSensors::batteryInputVoltage_V(void) const
{
    return this->m_data_batteryInputVoltage_V;
}

/* ########################################################################## */
/* ########################################################################## */

float   CSensors::batteryOutputCurrent_mA(void) const
{
    return this->m_data_batteryOutputCurrent_mA;
}

/* ########################################################################## */
/* ########################################################################## */

float   CSensors::batteryOutputVoltage_V(void) const
{
    return this->m_data_batteryOutputVoltage_V;
}

/* ########################################################################## */
/* ########################################################################## */
/**
 *  @brief  Accessor for the battery temperature expressed in celsius degrees.
 */
float   CSensors::batteryTemperature_c() const
{
    return this->m_data_batteryTemperature_c;
}

/* ########################################################################## */
/* ########################################################################## */

void    CSensors::initialize(void)
{
    this->m_data_ambientTemperature_c   = C_SENSOR_DEFAULTVALUE_F;
    this->m_data_batteryInputCurrent_mA  = C_SENSOR_DEFAULTVALUE_F;
    this->m_data_batteryInputVoltage_V  = C_SENSOR_DEFAULTVALUE_F;
    this->m_data_batteryOutputCurrent_mA = C_SENSOR_DEFAULTVALUE_F;
    this->m_data_batteryOutputVoltage_V = C_SENSOR_DEFAULTVALUE_F;
    this->m_data_batteryTemperature_c   = C_SENSOR_DEFAULTVALUE_F;

    this->m_AM2320_ambient.begin();
    this->m_ADS1015_1.begin();
    this->m_INA3221.begin();
}

/* ########################################################################## */
/* ########################################################################## */

void    CSensors::update(void)
{
    if( this->m_AM2320_ambient.measure() != true )
    {
        Serial.print(__PRETTY_FUNCTION__);
        Serial.print(" :: WARN : An error occured while updating"
                       " AM2320 sensor data : ");

        switch (this->m_AM2320_ambient.getErrorCode())
        {
            case 1:
                Serial.println("Sensor is offline");
                break;


            case 2:
                Serial.println("CRC validation failed.");
                break;


            default:
                Serial.println("Unknown error!");
                break;
        }
    }


    this->m_data_ambientTemperature_c
            = CTN_calculateTemperature(
                  this->m_ADS1015_1.readADC_SingleEnded(
                      C_SENSOR_ADS1015_1_CH_AMBTMP)
                  * 3 );

    this->m_data_batteryTemperature_c
            = CTN_calculateTemperature(
                  this->m_ADS1015_1.readADC_SingleEnded(
                      C_SENSOR_ADS1015_1_CH_BATTMP)
                  * 3 );


    this->m_data_batteryInputCurrent_mA
            = -this->m_INA3221.getCurrent_mA(C_SENSOR_INA3321_CH_SOLARCELL);

    this->m_data_batteryInputVoltage_V
            = this->m_INA3221.getBusVoltage_V(C_SENSOR_INA3321_CH_SOLARCELL)
            + ( this->m_INA3221.getShuntVoltage_mV(
                    C_SENSOR_INA3321_CH_SOLARCELL) / 1000.0);


    this->m_data_batteryOutputCurrent_mA
            = -this->m_INA3221.getCurrent_mA(C_SENSOR_INA3321_CH_OUTPUT);

    this->m_data_batteryOutputVoltage_V
            = this->m_INA3221.getBusVoltage_V(C_SENSOR_INA3321_CH_OUTPUT)
            + ( this->m_INA3221.getShuntVoltage_mV(
                    C_SENSOR_INA3321_CH_OUTPUT) / 1000.0);


    /*
     *  Verify alert triggers
     */
    if(     (   this->ambientTemperature_c()
            <=  g_parameters.m_data.ambientTemperature_alertMin)
        ||  (   this->ambientTemperature_c()
            >=  g_parameters.m_data.ambientTemperature_alertMax) )
    {
        Comm::Messages::AMBTMP::Instance()->setAlert(true);
        Comm::ProtocolManager::Instance()
                ->sendMessage(Comm::Messages::AMBTMP::Instance());
    }
}

/* ########################################################################## */
/* ########################################################################## */
