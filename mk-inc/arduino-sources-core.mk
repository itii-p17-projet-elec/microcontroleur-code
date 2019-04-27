
ARDUINO_PATH_SRC    =$(ARDUINO_PATH)/hardware/arduino/cores/arduino

#ARDUINO_CORE_SOURCES=\
#	$(ARDUINO_PATH_SRC)/wiring.c\
#	$(ARDUINO_PATH_SRC)/wiring_analog.c\
#	$(ARDUINO_PATH_SRC)/wiring_digital.c\
#	$(ARDUINO_PATH_SRC)/wiring_pulse.c\
#	$(ARDUINO_PATH_SRC)/wiring_shift.c\
#	$(ARDUINO_PATH_SRC)/WInterrupts.c\
#	$(ARDUINO_PATH_SRC)/HardwareSerial.cpp\
#	$(ARDUINO_PATH_SRC)/WMath.cpp\
#	$(ARDUINO_PATH_SRC)/WString.cpp\
#	$(ARDUINO_PATH_SRC)/Print.cpp

ARDUINO_CORE_SOURCES		:= $(shell find $(ARDUINO_PATH_SRC) -type f -iname *.c -o -iname *.cpp)
ARDUINO_CORE_SOURCES		+= $(shell find $(ARDUINO_PATH)/libraries/SPI -type f -iname *.c -o -iname *.cpp)

BUILDDIR_ARDUINO_CORE   :=$(BUILDDIR)/arduino-core
#ARDUINO_CORE_OBJECTS	:= $(patsubst $(ARDUINO_PATH_SRC)/%,$(BUILDDIR_ARDUINO_CORE)/%,$(ARDUINO_CORE_SOURCES:=.$(OBJEXT)))
ARDUINO_CORE_OBJECTS	:= $(patsubst $(ARDUINO_PATH_SRC)/%,$(BUILDDIR_ARDUINO_CORE)/%,$(ARDUINO_CORE_SOURCES))
ARDUINO_CORE_OBJECTS	:= $(patsubst /usr/share/arduino/libraries/%,$(BUILDDIR)/usr_share_arduino_libraries/%,$(ARDUINO_CORE_OBJECTS))
ARDUINO_CORE_OBJECTS	:= $(patsubst %.c,%.$(OBJEXT),$(ARDUINO_CORE_OBJECTS))
ARDUINO_CORE_OBJECTS	:= $(patsubst %.cpp,%.$(OBJEXT),$(ARDUINO_CORE_OBJECTS))


#Pull in dependency info for *existing* .o files
-include $(ARDUINO_CORE_OBJECTS:.$(OBJEXT)=.$(DEPEXT))
