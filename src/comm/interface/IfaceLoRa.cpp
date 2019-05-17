/* Corresponding header inclusion */
#include "IfaceLoRa.h"

/* System includes */

/* Libraries includes */
#include <SPI.h>

/* Project includes */
#include "hardware_defines.h"
#include "drivers/comm/RH_RF95.h"
#include "common/trace.h"


namespace Comm {
namespace Interface {

// Change to 434.0 or other frequency, must match RX's freq!
#define RF95_FREQ 433.0

// Singleton instance of the radio driver
RH_RF95 rf95(C_PIN_RFM95_CS, C_PIN_RFM95_INT);

/* ########################################################################## */
/* ########################################################################## */

IfaceLoRa::IfaceLoRa(void)
    :   m_packetnum( 0 )
{

}

/* ########################################################################## */
/* ########################################################################## */

void    IfaceLoRa::initialize()
{
    pinMode(C_PIN_RFM95_RST, OUTPUT);
    digitalWrite(C_PIN_RFM95_RST, HIGH);

    // manual reset
    digitalWrite(C_PIN_RFM95_RST, LOW);
    delay(10);
    digitalWrite(C_PIN_RFM95_RST, HIGH);
    delay(10);

    while (!rf95.init()) {
        TRACELN("*** CRITICAL*** LoRa radio init failed !");
//        while (1);
    }
    TRACELN("LoRa radio init OK!");

    // Defaults after init are 434.0MHz, modulation GFSK_Rb250Fd250, +13dbM
    if (!rf95.setFrequency(RF95_FREQ)) {
        TRACELN("setFrequency failed");
//        while (1);
    }
    else
    {
        char    lBuff[16]   = {0};

        dtostre(RF95_FREQ, lBuff, 3, 0 );

        TRACE("Set Freq to: ");
        TRACELN(lBuff);
    }

    // set transmitter powers from 5 to 23 dBm:
    rf95.setTxPower(23, false);
}

/* ########################################################################## */
/* ########################################################################## */

void    IfaceLoRa::sendData(const String &pData)
{
    TRACE("Sending to rf95_server : ");
    TRACELN((String)pData);

    static char s_buffer[100]   = {0};

    pData.toCharArray(s_buffer, 100, 0);
    rf95.send((uint8_t *)s_buffer,
              pData.length());

    TRACELN("Waiting for packet to complete...");
    delay(10);
    rf95.waitPacketSent();
    delay(50);

    // Now wait for a reply
#if 0
    uint8_t buf[RH_RF95_MAX_MESSAGE_LEN];
    uint8_t len = sizeof(buf);

    TRACELN("Waiting for reply...");
    delay(10);

    if (rf95.waitAvailableTimeout(200)) /*< default was 1000 */
    {
        // Should be a reply message for us now
        if (rf95.recv(buf, &len))
        {
            TRACE("Got reply: ");
            TRACELN((char*)buf);
            TRACE("RSSI: ");
            TRACELN(rf95.lastRssi());
        }
        else
        {
            TRACELN("Receive failed");
        }
    }
    else
    {
        TRACELN("No reply, is there a listener around?");
    }
#endif
}

/* ########################################################################## */
/* ########################################################################## */

} // namespace Interface
} // namespace Comm
