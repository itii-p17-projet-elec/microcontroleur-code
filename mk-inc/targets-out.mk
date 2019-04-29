


$(BUILDDIR)/$(TARGET:%.hex=%.elf): $(ARDUINO_CORE_OBJECTS) $(OBJECTS)	#help: Main application's target.
	@echo -e "${lColorLD}    LD  $@${CLREOL}${FMT_STD}" $(TRACE_LOG)
	@if [ ! "$(TRACES)" -eq "0" ] ; then \
	        echo "$(LD) $(LDFLAGS) -o $@ $^" $(TRACE_REDIRECT); \
	fi
	@$(LD) $(LDFLAGS) -o $@ $^ $(LIBS) $(TRACE_REDIRECT)



$(TARGETDIR)/$(TARGET): $(BUILDDIR)/$(TARGET:%.hex=%.elf)
	@echo -e "${lColorLD}    HEX $@${CLREOL}${FMT_STD}" $(TRACE_LOG)
	avr-objcopy -O ihex -R .eeprom $< $@

