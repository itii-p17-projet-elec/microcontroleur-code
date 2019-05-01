/**
 *  @file   demo_display-LCD_2_16_main.cpp
 *  @brief  This is a demo for usage of the "LCD Keypad Shield" from DFRobot.
 *
 *  @author GOM
 *  @note   This demo is based on this article :
 *          https://www.carnetdumaker.net/articles/utiliser-une-shield-lcd-de-dfrobots-avec-une-carte-arduino-genuino-et-la-bibliotheque-liquidcrystal/
 */

#include <Arduino.h>

#include <LiquidCrystal.h>

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
    C_PIN_LED                   = 13
};


/** Objet LiquidCrystal pour communication avec l'écran LCD */
LiquidCrystal lcd( C_PIN_LCD_RS,
                   C_PIN_LCD_EN,
                   C_PIN_LCD_D0,
                   C_PIN_LCD_D1,
                   C_PIN_LCD_D2,
                   C_PIN_LCD_D3 );

/* ########################################################################## */
/* ########################################################################## */

void setup()
{
    pinMode(C_PIN_LCD_BACKLIGHT, OUTPUT);
    pinMode(C_PIN_LED, OUTPUT);


    Serial.begin(9600);
    Serial.println("\n~~~ Hello, World ! ~~~");
    Serial.println("# Demo for DFRobot's \"LCD Keypad Shield\".\n");

    Serial.println("+-- Initialization...");
    lcd.begin(16, 2);
    lcd.print("Hello World !");
    Serial.println("    +-- Done.");
}

/* ########################################################################## */
/* ########################################################################## */

void loop()
{
    digitalWrite(C_PIN_LCD_BACKLIGHT, HIGH);
    digitalWrite(C_PIN_LED, HIGH);

    delay(500);

    digitalWrite(C_PIN_LCD_BACKLIGHT, LOW);
    digitalWrite(C_PIN_LED, LOW);

    delay(500);
}

/* ########################################################################## */
/* ########################################################################## */
