CC:=/usr/share/arduino/hardware/tools/avr/bin/avr-gcc
CXX:=/usr/share/arduino/hardware/tools/avr/bin/avr-g++
AR:=/usr/share/arduino/hardware/tools/avr/bin/avr-ar
LD:=/usr/share/arduino/hardware/tools/avr/bin/avr-gcc


# ------------------------------------------------------------------------------
#   Build commands options
# Flags, Libraries and Includes
# ------------------------------------------------------------------------------
INC         += -I$(SRCDIR)
INC         += -I$(INCDIR)
INC         += -I/usr/share/arduino/libraries
INC         += -I/usr/lib/avr/include/

INCDEP      := -I$(INCDIR)

LIBS	    += -lc
LIBS	    += -lm


STD:=c++11


CFLAGS:=
CFLAGS+= -c
CFLAGS+= -g
CFLAGS+= -Os
CFLAGS+= -Wall
CFLAGS+= -ffunction-sections
CFLAGS+= -fdata-sections
CFLAGS+= -mmcu=$(MCU)
CFLAGS+= -DF_CPU=$(F_CPU)
CFLAGS+= -MMD
CFLAGS+= -DUSB_VID=null
CFLAGS+= -DUSB_PID=null
CFLAGS+= -DARDUINO=105
CFLAGS+= -D__PROG_TYPES_COMPAT__
CFLAGS+= $(DEFINES)



CXXFLAGS:=
CXXFLAGS+= -c
CXXFLAGS+= -g
CXXFLAGS+= -Os
CXXFLAGS+= -Wall
CXXFLAGS+= -std=$(STD)
CXXFLAGS+= -fno-exceptions
CXXFLAGS+= -ffunction-sections
CXXFLAGS+= -fdata-sections
CXXFLAGS+= -mmcu=$(MCU)
CXXFLAGS+= -DF_CPU=$(F_CPU)
CXXFLAGS+= -MMD
CXXFLAGS+= -DUSB_VID=null
CXXFLAGS+= -DUSB_PID=null
CXXFLAGS+= -DARDUINO=105
CXXFLAGS+= -D__PROG_TYPES_COMPAT__
CXXFLAGS+= $(DEFINES)



LDFLAGS:=
LDFLAGS+=-Os
LDFLAGS+=-Wl,--gc-sections,--relax
LDFLAGS+= -mmcu=$(MCU)
