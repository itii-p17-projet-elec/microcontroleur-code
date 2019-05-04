ARDUINO_PATH=/usr/share/arduino

ARDUINO_BOARD=mega2560
#ARDUINO_BOARD=nano328



ifeq ($(ARDUINO_BOARD),mega2560)
    MCU=atmega2560
    F_CPU=16000000
    DEFINES += -D_BOARD_MEGA2560_
    INC += -I$(ARDUINO_PATH)/hardware/arduino/variants/mega

    PORT=/dev/ttyACM0
    UPLOAD_PROTOCOL=wiring
    UPLOAD_SPEED=115200
else ifeq ($(ARDUINO_BOARD),nano328)
    MCU=atmega328p
    F_CPU=16000000
    PORT=/dev/ttyUSB0
    UPLOAD_PROTOCOL=arduino
    UPLOAD_SPEED=57600
else
    $(error Unknown Arduino board name !)
endif



ARDUINO_VARIANTS_PATH=$(ARDUINO_PATH)/hardware/arduino/variants/standard

TARGET  = $(TARGETNAME)-$(ARDUINO_BOARD)-$(MCU).hex
