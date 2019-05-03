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
    C_PIN_LED                   = 13,

    C_PIN_KEYPAD_SW             = 54 /*< This is A0 on mega2560 */
};

/* ########################################################################## */
/* ########################################################################## */

/** Objet LiquidCrystal pour communication avec l'écran LCD */
LiquidCrystal lcd( C_PIN_LCD_RS,
                   C_PIN_LCD_EN,
                   C_PIN_LCD_D0,
                   C_PIN_LCD_D1,
                   C_PIN_LCD_D2,
                   C_PIN_LCD_D3 );

/* ########################################################################## */
/* ########################################################################## */

namespace   LCDKeypadShield
{
    typedef enum    EButtonsID
    {
        BUTTON_NONE     = 0x00, /*!< Pas de bouton appuyé */
        BUTTON_UP       = 0x01, /*!< Bouton UP (haut) */
        BUTTON_DOWN     = 0x02, /*!< Bouton DOWN (bas) */
        BUTTON_LEFT     = 0x04, /*!< Bouton LEFT (gauche) */
        BUTTON_RIGHT    = 0x08, /*!< Bouton RIGHT (droite) */
        BUTTON_SELECT   = 0x10  /*!< Bouton SELECT */
    }   TeButtonsID;



    uint8_t     g_backlightValue    = 0xFF;



    TeButtonsID getPressedButton(void)
    {
        TeButtonsID retval  = BUTTON_NONE;

        /* Lit l'état des boutons */
        int value = analogRead(C_PIN_KEYPAD_SW);
        Serial.print( "Value = " );
        Serial.println( value );


        /* Calcul de l'état des boutons */
        if (value < 50)
        {
            retval  = BUTTON_RIGHT;
        }
        else if (value < 250)
        {
            retval  = BUTTON_UP;
        }
        else if (value < 450)
        {
            retval  = BUTTON_DOWN;
        }
        else if (value < 650)
        {
            retval  = BUTTON_LEFT;
        }
        else if (value < 850)
        {
            retval  = BUTTON_SELECT;
        }
        else
        {
            retval  = BUTTON_NONE;
        }


        return retval;
    }



    static char*    buttonName(const TeButtonsID& pID)
    {
        char*   retval  = NULL;


        switch(pID)
        {
            case BUTTON_DOWN:
                retval  = (char*)"DOWN";
                break;


            case BUTTON_LEFT:
                retval  = (char*)"LEFT";
                break;


            case BUTTON_RIGHT:
                retval  = (char*)"RIGHT";
                break;


            case BUTTON_SELECT:
                retval  = (char*)"SELECT";
                break;


            case BUTTON_UP:
                retval  = (char*)"UP";
                break;


            case BUTTON_NONE:
            default:
                retval  = (char*)"NONE";
                break;
        }


        return retval;
    }
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
    Serial.println("\n~~~ Hello, World ! ~~~");
    Serial.println("# Demo for DFRobot's \"LCD Keypad Shield\".\n");

    Serial.println("+-- Initialization...");
    lcd.begin(16, 2);
    lcd.print("Hello World !");
    Serial.println("    +-- Done.");

    delay(1000);
    Serial.println("+-- Now starting main loop.");

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Switch:");
}

/* ########################################################################## */
/* ########################################################################## */

LCDKeypadShield::TeButtonsID    g_keypad_lastState
                                        = LCDKeypadShield::BUTTON_NONE;

void loop()
{
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
    static LCDKeypadShield::TeButtonsID s_Keypad_currentState
            = LCDKeypadShield::BUTTON_NONE;

    /* Get keypad buttons' current state */
    s_Keypad_currentState   = LCDKeypadShield::getPressedButton();



    /*
     *  Process
     */
    /* If a new button has been pressed, then reset backlight dimmer value. */
    if(     s_Keypad_currentState != g_keypad_lastState
        &&  s_Keypad_currentState != LCDKeypadShield::BUTTON_NONE )
    {
        LCDKeypadShield::g_backlightValue   = 0xFF;

        Serial.print( "New keypad state : " );
        Serial.println( LCDKeypadShield::buttonName( s_Keypad_currentState ) );
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
    g_keypad_lastState  = s_Keypad_currentState;

    /* Loop delay... */
    delay(50);
}

/* ########################################################################## */
/* ########################################################################## */
