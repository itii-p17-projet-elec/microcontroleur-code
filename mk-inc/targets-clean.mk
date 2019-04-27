##  @brief  This is just a common alias to remove all of generated items.
distclean: cleaner	#help: Same as 'make cleaner'.



##  @brief  Target to remove objects only.
clean:	#help: Target to remove objects only.
	@echo -e "${lColorRM}    RM  ./$(BUILDDIRROOT)/ ${CLREOL}$(FMT_STD)" #$(TRACE_REDIRECT);
	@$(RM) -rvf ./$(BUILDDIRROOT)/ #$(TRACE_REDIRECT)



##  @brief  Full Clean, Objects and Binaries.
cleaner: clean clean-doc	#help: Full Clean, Objects and Binaries.
	@echo -e "${lColorRM}    RM  ./$(TARGETDIR)/ ${CLREOL}$(FMT_STD)"
	@$(RM) -rvf $(TARGETDIR)
	@echo -e "${lColorRM}    RM  ./$(DIR_OUTPUT)/ ${CLREOL}$(FMT_STD)"
	@$(RM) -rvf $(DIR_OUTPUT)
