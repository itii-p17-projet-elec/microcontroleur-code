
ARDUINO_AVRDUDE_CONFIG	:=$(ARDUINO_PATH)/hardware/tools/avrdude.conf



deploy: target # Deploy to target uC
	@echo -e "${lColorDP}    DP  $(TARGETDIR)/$(TARGET)${CLREOL}$(FMT_STD)" #$(TRACE_REDIRECT);
	avrdude -q -V -p $(MCU)			\
	        -C $(ARDUINO_AVRDUDE_CONFIG)	\
		-D				\
		-c $(UPLOAD_PROTOCOL)		\
		-b $(UPLOAD_SPEED)		\
		-P $(PORT)			\
		-U flash:w:$(TARGETDIR)/$(TARGET):i

# avrdude -p$(MCU) -P$(PORT) -carduino -b$(UPLOAD_SPEED) -U flash:w:$(TARGETDIR)/$(TARGET):i
