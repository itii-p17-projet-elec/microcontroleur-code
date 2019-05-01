
ARDUINO_AVRDUDE_CONFIG	:=$(ARDUINO_PATH)/hardware/tools/avrdude.conf



deploy: target # Deploy to target uC
	@echo -e "${lColorDP}    DP  $(TARGETDIR)/$(TARGET)${CLREOL}$(FMT_STD)" #$(TRACE_REDIRECT);
	@$(eval lCMD:=avrdude	-q				\
	                        -V				\
				-p $(MCU)			\
				-C $(ARDUINO_AVRDUDE_CONFIG)	\
				-D				\
				-c $(UPLOAD_PROTOCOL)		\
				-b $(UPLOAD_SPEED)		\
				-P $(PORT)			\
				-U flash:w:$(TARGETDIR)/$(TARGET):i)
	@if [ ! "$(TRACES)" -eq "0" ] ; then \
	        echo "$(lCMD)"; \
	fi
	@$(lCMD)

