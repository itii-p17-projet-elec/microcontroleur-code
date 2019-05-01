
##  @brief  Target to generate object files from main sources.
$(BUILDDIRSRC)/%.$(OBJEXT): $(SRCDIR)/%.cpp
	@echo -e "${lColorCC}    CXX $@ ${CLREOL}${FMT_STD}" $(TRACE_LOG)
	@$(eval lCMD:=$(CXX) $(CXXFLAGS) $(INC) -o $@ $<)
	@mkdir -p $(dir $@) $(TRACE_REDIRECT)
	@if [ ! "$(TRACES)" -eq "0" ] ; then \
	        echo "$(lCMD)" $(TRACE_REDIRECT); \
	fi
	@$(lCMD) $(TRACE_REDIRECT)

