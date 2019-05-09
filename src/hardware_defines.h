#ifndef HARDWARE_DEFINES_H
#define HARDWARE_DEFINES_H

#ifdef  _BOARD_MEGA2560_
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
    C_PIN_LED_ACTIVITY          = 13,

    C_PIN_KEYPAD_SW             = 54 /*< This is A0 on mega2560 */
};
#endif

#endif  /*< HARDWARE_DEFINES_H */
