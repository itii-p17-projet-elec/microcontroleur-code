/**
 *  @file   demo_display-LCD_2_16_main.cpp
 *  @brief  This is a demo for usage of the "LCD Keypad Shield" from DFRobot.
 *
 *  @author GOM
 *  @note   This demo is based on this article :
 *          https://www.carnetdumaker.net/articles/utiliser-une-shield-lcd-de-dfrobots-avec-une-carte-arduino-genuino-et-la-bibliotheque-liquidcrystal/
 */

#include <Arduino.h>
#include <avr/power.h>
#include <avr/sleep.h>

#include <LiquidCrystal.h>

#include "common/trace.h"

#include "LCDKeypadShield.h"

/**
 *  @brief  The E_PIN_USAGE enum defines microcontroller's pins names & usage.
 */
enum    E_PIN_USAGE
{
    C_PIN_LCD_D0                = 4,
    C_PIN_LCD_D1                = 5,
    C_PIN_LCD_D2                = 6,
    C_PIN_LCD_D3                = 7,
    C_PIN_LCD_RS                = 8,
    C_PIN_LCD_EN                = 9,
    C_PIN_LCD_BACKLIGHT         = 10,

    /** Internal LED connected to digital pin 13 */
    C_PIN_LED                   = 13,

    C_PIN_KEYPAD_SW             = 54 /*< This is A0 on mega2560 */
};

/* ########################################################################## */
/* ########################################################################## */

/* 16MHz / 256 / 20Hz */
const int    C_TIMER1_COUNTER_PRELOAD   = 62411;


bool    flag_timer1    = false;


LCDKeypadShield::TeButtonsID    g_keypad_currentState
                                        = LCDKeypadShield::BUTTON_NONE;
LCDKeypadShield::TeButtonsID    g_keypad_lastState
                                        = LCDKeypadShield::BUTTON_NONE;

/** Objet LiquidCrystal pour communication avec l'écran LCD */
LiquidCrystal lcd( C_PIN_LCD_RS,
                   C_PIN_LCD_EN,
                   C_PIN_LCD_D0,
                   C_PIN_LCD_D1,
                   C_PIN_LCD_D2,
                   C_PIN_LCD_D3 );

/* ########################################################################## */
/* ########################################################################## */

ISR(TIMER1_OVF_vect)        // interrupt service routine
{
    /* Reset timer */
    TCNT1   = C_TIMER1_COUNTER_PRELOAD; // preload timer
    TRACELN("<INT>");


    digitalWrite(C_PIN_LED, HIGH);   // set the LED on


    /*
     *  Update outputs
     */
    /* Move cursor to the beginning of the second line */
    lcd.setCursor(0, 1);

    /* Display the name of the currently pressed button */
    lcd.print( LCDKeypadShield::buttonName( g_keypad_lastState ) );
    lcd.print( "        " ); /*< Add a few blanks to erase the display */

    /* Set the backlight luminosity using a PWM on backlight LED. */
    analogWrite( C_PIN_LCD_BACKLIGHT,
                 LCDKeypadShield::g_backlightValue > 255 ?
                        255
                    :   LCDKeypadShield::g_backlightValue );



    /*
     *  Update inputs
     */
    /* Get keypad buttons' current state */
    g_keypad_currentState
            = LCDKeypadShield::getPressedButton(C_PIN_KEYPAD_SW);

    flag_timer1 = true;
}

/* ########################################################################## */
/* ########################################################################## */

void setup()
{
    pinMode(C_PIN_KEYPAD_SW, INPUT);

    pinMode(C_PIN_LCD_BACKLIGHT, OUTPUT);
    pinMode(C_PIN_LED, OUTPUT);


    digitalWrite(C_PIN_LCD_BACKLIGHT, HIGH);


    Serial.begin(9600);
    TRACELN("\n~~~ Hello, World ! ~~~");
    TRACELN("# Demo for DFRobot's \"LCD Keypad Shield\".\n");

    TRACELN("+-- Initialization...");
    lcd.begin(16, 2);
    lcd.print("Hello World !");
    TRACELN("    +-- Done.");


    TRACELN("+-- Initialize Timer 1...");
    TCCR1A = 0;
    TCCR1B = 0;

    TCNT1   = C_TIMER1_COUNTER_PRELOAD; // preload timer
    TCCR1B |= (1 << CS12);    // 256 prescaler


    delay(1000);
    TRACELN("+-- Now starting main loop.");

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Switch:");

    /* Enable interrupts */
    TIMSK1 |= (1 << TOIE1);   // enable timer overflow interrupt
}

/* ########################################################################## */
/* ########################################################################## */

void    enterSleep(void)
{
  set_sleep_mode(SLEEP_MODE_IDLE);

  sleep_enable();


  /* Disable all of the unused peripherals. This will reduce power
   * consumption further and, more importantly, some of these
   * peripherals may generate interrupts that will wake our Arduino from
   * sleep!
   */
  power_adc_disable();
  power_spi_disable();
//  power_timer0_disable();
//  power_timer2_disable();
  power_twi_disable();

  /* Now enter sleep mode. */
  sleep_mode();

  /* The program will continue from here after the timer timeout*/
  sleep_disable(); /* First thing to do is disable sleep. */

  /* Re-enable the peripherals. */
  power_all_enable();
}

/* ########################################################################## */
/* ########################################################################## */

void loop()
{
    while( ! flag_timer1 )
    {
        delay(10);
    }

    flag_timer1 = false;



    /*
     *  Process
     */
    /* If a new button has been pressed, then reset backlight dimmer value. */
    if(     g_keypad_currentState != g_keypad_lastState
        &&  g_keypad_currentState != LCDKeypadShield::BUTTON_NONE )
    {
        LCDKeypadShield::g_backlightValue   = 0xFF;
    }
    /* If we still get a positive value, dim further the LCD backlight. */
    else if( (LCDKeypadShield::g_backlightValue - 5) >= 0 )
    {
        LCDKeypadShield::g_backlightValue   -= 5;
    }
    /* If there's no activity, shut down display's backlight. */
    else
    {
        LCDKeypadShield::g_backlightValue   = 0;
    }

    /* Update last known state value */
    g_keypad_lastState  = g_keypad_currentState;

    digitalWrite(C_PIN_LED, LOW);
    enterSleep();
}

/* ########################################################################## */
/* ########################################################################## */
