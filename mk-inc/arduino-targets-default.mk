


$(BUILDDIR_ARDUINO_CORE)/%.$(OBJEXT): $(ARDUINO_PATH_SRC)/%.c
	@echo -e "${lColorCC}    CC  $@ ${CLREOL}${FMT_STD}" $(TRACE_LOG)
	@mkdir -p $(dir $@) $(TRACE_REDIRECT)
	@if [ ! "$(TRACES)" -eq "0" ] ; then \
		echo "$(CC) $(CFLAGS) $(INC) -c -o $@ $<" $(TRACE_REDIRECT); \
	fi
	@$(CC) $(CFLAGS) $(INC) -c -o $@ $< $(TRACE_REDIRECT)



##  @brief  Target to generate object files from main sources.
$(BUILDDIR_ARDUINO_CORE)/%.$(OBJEXT): $(ARDUINO_PATH_SRC)/%.cpp
	@echo -e "${lColorCC}    CXX $@ ${CLREOL}${FMT_STD}" $(TRACE_LOG)
	@mkdir -p $(dir $@) $(TRACE_REDIRECT)
	@if [ ! "$(TRACES)" -eq "0" ] ; then \
		echo "$(CC) $(CFLAGS) $(INC) -c -o $@ $<" $(TRACE_REDIRECT); \
	fi
	@$(CC) $(CFLAGS) $(INC) -c -o $@ $< $(TRACE_REDIRECT)



##  @brief  Target to generate object files from main sources.
$(BUILDDIR)/usr_share_arduino_libraries/%.$(OBJEXT): /usr/share/arduino/libraries/%.cpp
	@echo -e "${lColorCC}    CXX $@ ${CLREOL}${FMT_STD}" $(TRACE_LOG)
	@mkdir -p $(dir $@) $(TRACE_REDIRECT)
	@if [ ! "$(TRACES)" -eq "0" ] ; then \
		echo "$(CC) $(CFLAGS) $(INC) -c -o $@ $<" $(TRACE_REDIRECT); \
	fi
	@$(CC) $(CFLAGS) $(INC) -c -o $@ $< $(TRACE_REDIRECT)
