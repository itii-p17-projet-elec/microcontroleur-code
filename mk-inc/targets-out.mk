


$(BUILDDIR)/$(TARGET:%.hex=%.elf): $(OBJECTS) $(ARDUINO_LIBS)	#help: Main application's target.
	@echo -e "${lColorLD}    LD  $@${CLREOL}${FMT_STD}" $(TRACE_LOG)
	@$(eval lCMD:=$(LD) $(LDFLAGS) -o $@ $^ $(LIBS))
	@if [ ! "$(TRACES)" -eq "0" ] ; then \
	        echo "$(lCMD)"; \
	fi
	@$(lCMD)



$(TARGETDIR)/$(TARGET): $(BUILDDIR)/$(TARGET:%.hex=%.elf)
	@echo -e "${lColorLD}    HEX $@${CLREOL}${FMT_STD}" $(TRACE_LOG)
	@$(eval lCMD:=avr-objcopy -O ihex -R .eeprom $< $@)
	@if [ ! "$(TRACES)" -eq "0" ] ; then \
	        echo "$(lCMD)"; \
	fi
	@$(lCMD)

