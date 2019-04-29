//#include <WProgram.h>
#include <Arduino.h>


const int   C_PIN_LED   =  13;    // LED connected to digital pin 13

char    g_char                  = '0';
int     g_timer1_counterPreload = 0;

/* ########################################################################## */
/* ########################################################################## */

ISR(TIMER1_OVF_vect)        // interrupt service routine
{
    /* Reset timer */
    TCNT1   = g_timer1_counterPreload;   // preload timer


    digitalWrite(C_PIN_LED, HIGH);   // set the LED on
    Serial.print( g_char );
    if( g_char == '9' )
    {
        g_char  = '0';
        Serial.println("");
    }
    else
    {
        g_char++;
    }

    // This delay is here just to let us see the LED blink - but it's bad habit!
    delay(100);
    digitalWrite(C_PIN_LED, LOW);
}

/* ########################################################################## */
/* ########################################################################## */

void setup()
{
    pinMode(C_PIN_LED, OUTPUT);

    //Initialize serial and wait for port to open:
    Serial.begin(9600);
    while (!Serial)
    {
        ; // wait for serial port to connect. Needed for Leonardo only
    }

    // prints title with ending line break
    Serial.println("\n~~~ Hello, World ! ~~~");


    // initialize timer1
    noInterrupts();           // disable all interrupts
    TCCR1A = 0;
    TCCR1B = 0;

    // Set timer1_counter to the correct value for our interrupt interval
    //timer1_counter = 64911;   // preload timer 65536-16MHz/256/100Hz
    //timer1_counter = 64286;   // preload timer 65536-16MHz/256/50Hz
//    timer1_counterPreload = 34286;   // preload timer 65536-16MHz/256/2Hz
    g_timer1_counterPreload = 49910;   // preload timer 65536-16MHz/256/2Hz

    TCNT1 = g_timer1_counterPreload;   // preload timer
//    TCCR1B |= (1 << CS12);    // 256 prescaler
    // 1024 prescaler
    TCCR1B |= (1 << CS12);    // 1024 prescaler
    TCCR1B |= (1 << CS10);    // 1024 prescaler
    TIMSK1 |= (1 << TOIE1);   // enable timer overflow interrupt
    interrupts();             // enable all interrupts
}

/* ########################################################################## */
/* ########################################################################## */

void loop()
{
    /* Nothing to do here for this software - everything is done during
     * interrupts ! */
}

/* ########################################################################## */
/* ########################################################################## */
# if 0
int main(void)
{
    init(); /*< From Arduino Framework */

    setup();


    /*
     *  Main loop
     */
    for (;;)
    {
       loop();
    }
}
#endif
/* ########################################################################## */
/* ########################################################################## */
