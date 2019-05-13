
ARDUINO_LIB_EEPROM_PATH		:= $(ARDUINO_PATH)/libraries/EEPROM
ARDUINO_LIB_EEPROM_BUILDDIR	:=$(BUILDDIR)/arduino-lib-EEPROM



ARDUINO_LIB_EEPROM    := $(ARDUINO_LIB_EEPROM_BUILDDIR)/arduino_lib_EEPROM.a

ARDUINO_LIB_EEPROM_SOURCES	+= $(ARDUINO_LIB_EEPROM_PATH)/EEPROM.cpp

ARDUINO_LIB_EEPROM_OBJECTS	:= $(patsubst $(ARDUINO_LIB_EEPROM_PATH)/%,$(ARDUINO_LIB_EEPROM_BUILDDIR)/%,$(ARDUINO_LIB_EEPROM_SOURCES))
ARDUINO_LIB_EEPROM_OBJECTS	:= $(patsubst %.c,%.$(OBJEXT),$(ARDUINO_LIB_EEPROM_OBJECTS))
ARDUINO_LIB_EEPROM_OBJECTS	:= $(patsubst %.cpp,%.$(OBJEXT),$(ARDUINO_LIB_EEPROM_OBJECTS))


#Pull in dependency info for *existing* .o files
-include $(ARDUINO_LIB_EEPROM_OBJECTS:.$(OBJEXT)=.$(DEPEXT))



$(ARDUINO_LIB_EEPROM_BUILDDIR)/%.$(OBJEXT): $(ARDUINO_LIB_EEPROM_PATH)/%.c
	@echo -e "${lColorCC}    CC  $@ ${CLREOL}${FMT_STD}" $(TRACE_LOG)
	@$(eval lCMD:=$(CC) $(CFLAGS) $(INC) -o $@ $<)
	@mkdir -p $(dir $@) $(TRACE_REDIRECT)
	@if [ ! "$(TRACES)" -eq "0" ] ; then \
	        echo "$(lCMD)" $(TRACE_REDIRECT); \
	fi
	@$(lCMD) $(TRACE_REDIRECT)



$(ARDUINO_LIB_EEPROM_BUILDDIR)/%.$(OBJEXT): $(ARDUINO_LIB_EEPROM_PATH)/%.cpp
	@echo -e "${lColorCC}    CXX $@ ${CLREOL}${FMT_STD}" $(TRACE_LOG)
	@$(eval lCMD:=$(CXX) $(CXXFLAGS) $(INC) -o $@ $<)
	@mkdir -p $(dir $@) $(TRACE_REDIRECT)
	@if [ ! "$(TRACES)" -eq "0" ] ; then \
	        echo "$(lCMD)" $(TRACE_REDIRECT); \
	fi
	@$(lCMD) $(TRACE_REDIRECT)



##  @brief  Target to generate the library's archive
$(ARDUINO_LIB_EEPROM): $(ARDUINO_LIB_EEPROM_OBJECTS)
	@mkdir -p $(dir $@) $(TRACE_REDIRECT)
	@for lObj in $^ ; \
	do \
		echo -e "${lColorLD}    AR  $@ <- $${lObj} ${CLREOL}${FMT_STD}" $(TRACE_LOG); \
		lCMD="$(AR) rcs $@ $${lObj}"; \
		if [ ! "$(TRACES)" -eq "0" ] ; then \
		        echo "$(lCMD)" $(TRACE_REDIRECT); \
		fi; \
		$${lCMD} ; \
	done;




DIRECTORIES += $(ARDUINO_LIB_EEPROM_BUILDDIR)

INC	+= -I$(ARDUINO_LIB_EEPROM_PATH)

ARDUINO_SOURCES	+= $(ARDUINO_LIB_EEPROM_SOURCES)
ARDUINO_OBJECTS	+= $(ARDUINO_LIB_EEPROM_OBJECTS)

ARDUINO_LIBS	+= $(ARDUINO_LIB_EEPROM)
