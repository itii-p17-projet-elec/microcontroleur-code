##  @brief  This is just a common alias to remove all of generated items.
distclean: cleaner	#help: Same as 'make cleaner'.



##  @brief  Target to remove objects only.
clean:	#help: Target to remove objects only.
	@for lDir in $(DIRECTORIES_CLEAN) ; \
	do \
		echo -e "${lColorRM}    RM  $${lDir} ${CLREOL}$(FMT_STD)"; \
		if [ ! "$(TRACES)" -eq "0" ] ; \
		then \
			lCMD="$(RM) -rvf $${lDir}"; \
			echo "$${lCMD}"; \
		else \
			lCMD="$(RM) -rf $${lDir}" ; \
		fi; \
		$${lCMD} ; \
	done



##  @brief  Full Clean, Objects and Binaries.
cleaner: clean	#help: Full Clean, Objects and Binaries.
	@for lDir in $(DIRECTORIES_CLEANER); \
	do \
		echo -e "${lColorRM}    RM  $${lDir} ${CLREOL}$(FMT_STD)"; \
		if [ ! "$(TRACES)" -eq "0" ] ; \
		then \
			lCMD="$(RM) -rvf $${lDir}"; \
			echo "$${lCMD}"; \
		else \
			lCMD="$(RM) -rf $${lDir}" ; \
		fi; \
		$${lCMD} ; \
	done
