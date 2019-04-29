
##  @brief  Target to generate object files from main sources.
$(BUILDDIRSRC)/%.$(OBJEXT): $(SRCDIR)/%.$(SRCEXT)
	@echo -e "${lColorCC}    CC  $@ ${CLREOL}${FMT_STD}" $(TRACE_LOG)
	@mkdir -p $(dir $@) $(TRACE_REDIRECT)
	@if [ ! "$(TRACES)" -eq "0" ] ; then \
	        echo "$(CC) -c $(CFLAGS) $(INC) -o $@ $<" $(TRACE_REDIRECT); \
	fi
	@$(CC) -c $(CFLAGS) $(INC) -o $@ $< $(TRACE_REDIRECT)

