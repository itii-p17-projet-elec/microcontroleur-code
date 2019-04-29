CC:=avr-g++
#CXX:=avr-g++
LD:=avr-g++


# ------------------------------------------------------------------------------
#   Build commands options
# Flags, Libraries and Includes
# ------------------------------------------------------------------------------
CFLAGS      := -MMD -mmcu=$(MCU) -DF_CPU=$(F_CPU) -Wall -ffunction-sections -fdata-sections -Os -fpermissive -fno-exceptions -std=gnu++11 -fno-threadsafe-statics -flto
LDFLAGS     := -mmcu=$(MCU) -Wl,--gc-section -Os -flto -fuse-linker-plugin
INC         := -I$(SRCDIR)
INC         += -I$(INCDIR)
INC         += -I$(ARDUINO_VARIANTS_PATH)
INC         += -I/usr/share/arduino/libraries
INC         += -I$(ARDUINO_PATH_SRC)
INC         += -I/usr/lib/avr/include/
INCDEP      := -I$(INCDIR)
LIBS	    := -lc
LIBS	    += -lm
