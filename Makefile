# ##############################################################################
##  @file
##  @brief  Generic Makefile for basic C++ projects.
##
##  @see Reference makefile from : https://stackoverflow.com/a/27794283
##
##  This makefile is an adaptation of the version we can find on StackOverflow.
##  It's basically the same but with colors and documentation support.
##
##
##  @par "Basic targets"
##
##
##  @par    "Subdirectories description"
##
##  This makefiles relies on a specific directories tree as shown below :
##
##  . [Main directory]
##  ├── doc/
##  │   └── doxygen/
##  │       └── doxygen.conf
##  ├── inc/
##  │   └── test/
##  │       └── catch.hpp
##  ├── Makefile
##  ├── out
##  ├── rsrc
##  ├── src
##  │   ├── main.cpp
##  │   └── [project sources]
##  └── tests
##      └── auto
##          ├── ["catch" framework test sources]
##          └── tests-auto.cpp
##
##
##  - **doc/**:         This directory groups documentation elements related
##                      to the project.
##
##  - **doc/doxygen/**: Doxygen-related files. This directory contains the conf
##                      file for doxygen (`doxygen.conf`). You can also put some
##                      doxygen pages in there.
##
##  - **inc/**:         This directory contains external headers.
##
##  - **inc/test/**:    Contains headers related to tests (like the `catch`
##                      framework).
##
##  - **Makefile**:     This file.
##
##  - **out/**:         Destination directory (auto-generated).
##
##  - **rsrc/**:        Not used yet. To put "other files" needed by the
##                      application.
##
##  - **src/**:         Main target's sources. They can be in subdirectories.
##
##  - **src/main.cpp**: Main target's entry point. It won't be used when editing
##                      links for test executable.
##
##  - **tests/auto/**:  This directory contains sources for automated tests.
##
##
##  @author Aloike
##  @date   2019-01-21  Creation.
##
# ##############################################################################


##  @brief  The Target Binary Program's name
TARGETNAME		:= HelloArduino

##  @brief  The test target's name
TARGET_TESTS_AUTO	:= tests-auto



#ARDUINO_BOARD=mega2560
ARDUINO_BOARD=nano328

ifeq ($(ARDUINO_BOARD),mega2560)
    MCU=atmega2560
    F_CPU=16000000
    PORT=/dev/ttyACM0
    UPLOAD_SPEED=115200
else ifeq ($(ARDUINO_BOARD),nano328)
    MCU=atmega328p
    F_CPU=16000000
    PORT=/dev/ttyUSB0
    UPLOAD_SPEED=57600
else
    $(error Unknown Arduino board name !)
endif

TARGET  = $(TARGETNAME)-$(ARDUINO_BOARD)-$(MCU).hex



# ------------------------------------------------------------------------------
#   Directories configuration
# The Directories, Source, Includes, Objects, Binary and Resources
# ------------------------------------------------------------------------------
SRCDIR          := src
INCDIR          := inc
BUILDDIRROOT    := build
BUILDDIR        := $(BUILDDIRROOT)/$(ARDUINO_BOARD)/$(MCU)
BUILDDIRSRC     := $(BUILDDIR)/src/
BUILDDIRTST     := $(BUILDDIR)/tests/
DIR_OUTPUT      := ./out/
TARGETDIR       := $(DIR_OUTPUT)/bin
TARGETDIR_TST   :=$(TARGETDIR)/tests/
RESDIR          := rsrc
TESTSDIR        := tests
DIR_DOC         := doc
DIR_DOC_OUT     :=$(DIR_OUTPUT)/doc/

SRCEXT      := cpp
DEPEXT      := d
OBJEXT      := o


# ------------------------------------------------------------------------------
#   Arduino-related declarations
# ------------------------------------------------------------------------------

ARDUINO_PATH=/usr/share/arduino/hardware/arduino/cores/arduino
VARIANTS_PATH=/usr/share/arduino/hardware/arduino/variants/standard

#ARDUINO_CORE_SOURCES=\
#	$(ARDUINO_PATH)/wiring.c\
#	$(ARDUINO_PATH)/wiring_analog.c\
#	$(ARDUINO_PATH)/wiring_digital.c\
#	$(ARDUINO_PATH)/wiring_pulse.c\
#	$(ARDUINO_PATH)/wiring_shift.c\
#	$(ARDUINO_PATH)/WInterrupts.c\
#	$(ARDUINO_PATH)/HardwareSerial.cpp\
#	$(ARDUINO_PATH)/WMath.cpp\
#	$(ARDUINO_PATH)/WString.cpp\
#	$(ARDUINO_PATH)/Print.cpp

ARDUINO_CORE_SOURCES		:= $(shell find $(ARDUINO_PATH) -type f -iname *.c -o -iname *.cpp)

BUILDDIR_ARDUINO_CORE   :=$(BUILDDIR)/arduino-core
#ARDUINO_CORE_OBJECTS	:= $(patsubst $(ARDUINO_PATH)/%,$(BUILDDIR_ARDUINO_CORE)/%,$(ARDUINO_CORE_SOURCES:=.$(OBJEXT)))
ARDUINO_CORE_OBJECTS	:= $(patsubst $(ARDUINO_PATH)/%,$(BUILDDIR_ARDUINO_CORE)/%,$(ARDUINO_CORE_SOURCES))
ARDUINO_CORE_OBJECTS	:= $(patsubst %.c,%.$(OBJEXT),$(ARDUINO_CORE_OBJECTS))
ARDUINO_CORE_OBJECTS	:= $(patsubst %.cpp,%.$(OBJEXT),$(ARDUINO_CORE_OBJECTS))



# ------------------------------------------------------------------------------
BIN_DOXYGEN     := doxygen
CC:=avr-g++
#CXX:=avr-g++
LD:=avr-g++


# ------------------------------------------------------------------------------
#   Build commands options
# Flags, Libraries and Includes
# ------------------------------------------------------------------------------
CFLAGS      := -MMD -mmcu=$(MCU) -DF_CPU=$(F_CPU) -Wall -ffunction-sections -fdata-sections -Os -fpermissive -fno-exceptions -std=gnu++11 -fno-threadsafe-statics -flto
LDFLAGS     := -mmcu=$(MCU) -Wl,--gc-section -Os -flto -fuse-linker-plugin
INC         := -I$(SRCDIR) -I$(INCDIR) -I$(ARDUINO_PATH) -I$(VARIANTS_PATH)
INCDEP      := -I$(INCDIR)
LIBS	    := -lc -lm



# ##############################################################################
#   DO NOT EDIT BELOW THIS LINE
# ##############################################################################
SHELL:=/bin/bash


# ------------------------------------------------------------------------------
#   Bash control chars definitions
# ------------------------------------------------------------------------------

# From https://stackoverflow.com/a/12099167
ifeq ($(OS),Windows_NT)
	echo "Windows not supported !"
	exit 1
else
    UNAME_S := $(shell uname -s)
    ifeq ($(UNAME_S),Linux)
	ESC_CHAR:="\\e"
    endif
    ifeq ($(UNAME_S),Darwin)
	ESC_CHAR:="\\033"
    endif
endif


# Bash format definitions
FMT_STD:="${ESC_CHAR}[0m"
FMT_BLD:="${ESC_CHAR}[1m"
FMT_UDL:="${ESC_CHAR}[4m"

# Bash colors list
COL_BLK:="${ESC_CHAR}[40m"
COL_BLU:="${ESC_CHAR}[44m"
COL_CYN:="${ESC_CHAR}[30;46m"
COL_GRE:="${ESC_CHAR}[47m"
COL_GRN:="${ESC_CHAR}[30;42m"
COL_ORG:="${ESC_CHAR}[30;43m"
COL_MAG:="${ESC_CHAR}[30;45m"
COL_RED:="${ESC_CHAR}[41m"
COL_YLW:="${ESC_CHAR}[30;103m"

# Control char to fill a line
CLREOL:="${ESC_CHAR}[K"


# Aliases to define which color to use for this makefile's traces
lColorCC        :="${COL_ORG}"
lColorDoc       :="${COL_GRN}"
lColorLD        :="${COL_MAG}"
lColorRC        :="${COL_YLW}"
lColorRM        :="${COL_RED}"
lColorRun       :="${COL_CYN}"
lColorSrcList	:="${FMT_BLD}${FMT_UDL}"



# ------------------------------------------------------------------------------
#   Makefile log management
# ------------------------------------------------------------------------------

# To manage traces activation through command line call
ifndef TRACES
TRACES:=0
else
TRACES:=1
endif


##  @brief  This variable defines the log file path
FILE_TRACE:=$(BUILDDIR)/trace_$(shell date +%Y-%m-%d_%H-%M-%S).log


# Here we define some aliases to manage traces redirections
ifeq ($(TRACES),0)
TRACE_REDIRECT:=1>/dev/null
TRACE_LOG:=
else
TRACE_REDIRECT:=2>&1|tee -a $(FILE_TRACE)
TRACE_LOG:=$(TRACE_REDIRECT)
endif



# ------------------------------------------------------------------------------
#   Auto-generated variables
# ------------------------------------------------------------------------------

# The following macros will basically produce lists of files (sources and objs)
# from what they found in src/ and tests/ directories.
SOURCES		:= $(shell find $(SRCDIR) -type f -name *.$(SRCEXT))
SOURCES_TST	:= $(shell find $(TESTSDIR) -type f -name *.$(SRCEXT))
OBJECTS		:= $(patsubst $(SRCDIR)/%,$(BUILDDIRSRC)/%,$(SOURCES:.$(SRCEXT)=.$(OBJEXT)))
OBJECTS_TST	:= $(patsubst $(TESTSDIR)/%,$(BUILDDIRTST)/%,$(SOURCES_TST:.$(SRCEXT)=.$(OBJEXT)))



# ------------------------------------------------------------------------------
#   Target aliases
# ------------------------------------------------------------------------------

##  @brief  Default Make target.
default: target


##  @brief  Target to build the main target.
target: show_sources resources $(TARGETDIR)/$(TARGET)


##  @brief  Target to build everything.
all: default show_sources_tests $(TARGET_TESTS_AUTO) doc


##  @brief  Target to re-build everything
remake: cleaner all	#help: Same as 'make cleaner all'


##  @brief  This is just a common alias to remove all of generated items.
distclean: cleaner	#help: Same as 'make cleaner'.


##  @brief  Target to build development documentation.
doc: doxygen	#help: build development documentation.


##  @brief  Target to build all test executables.
tests: show_sources_tests resources $(TARGET_TESTS_AUTO) #help: Builds all test executables.



# ------------------------------------------------------------------------------
#   Non-File Targets
# ------------------------------------------------------------------------------

##  @brief  To force Make to always proceed these target receipes.
.PHONY: all remake clean cleaner resources doxygen


##  @brief  Target to display detected source files.
show_sources: directories	#help: Displays detected source files.
	@echo -e "\n${lColorSrcList}List of auto-detected sources :${FMT_STD}\n" $(TRACE_LOG)
	@for file in $(ARDUINO_CORE_SOURCES) $(SOURCES); do \
		echo "+-- $${file}" $(TRACE_LOG); \
	done
	@echo ""


##  @brief  Target to display detected test source files.
show_sources_tests: directories	#help: Displays detected test source files.
	@echo -e "\n${lColorSrcList}List of auto-detected test sources :${FMT_STD}\n" $(TRACE_LOG)
	@for file in $(SOURCES_TST) ; do \
		echo "+-- $${file}" $(TRACE_LOG); \
	done
	@echo ""


##  @brief  Target to display detected source files.
show_objects: directories	#help: Displays detected source files.
	@echo -e "\n${lColorSrcList}List of objects :${FMT_STD}\n" $(TRACE_LOG)
	@for file in $(ARDUINO_CORE_OBJECTS); do \
		echo "+-- $${file}" $(TRACE_LOG); \
	done
	@echo ""




# To be updated : #Copy Resources from Resources Directory to Target Directory
# To be updated : resources: directories	#help: Copy Resources from Resources Directory to Target Directory.
# To be updated : 	@for file in `find $(RESDIR) -type f`; \
# To be updated : 	do \
# To be updated : 		lDestFile=$$(echo $$file |sed -e "s@$(RESDIR)@$(TARGETDIR)@"); \
# To be updated : 		if [ ! -d $$(dirname "$$lDestFile") ] ; \
# To be updated : 		then \
# To be updated : 			echo -e "${lColorRC}    RCD $$(dirname "$$lDestFile") ${CLREOL}${FMT_STD}" $(TRACE_LOG) ;\
# To be updated : 			mkdir -p $$(dirname "$$lDestFile"); \
# To be updated : 		fi; \
# To be updated : 		\
# To be updated : 		lRsync_test=$$(rsync -aEim --dry-run "$$file" "$$lDestFile"); \
# To be updated : 		if [ -n "$$lRsync_test" ] ; \
# To be updated : 		then \
# To be updated : 			echo -e "${lColorRC}    RC  $$lDestFile ${CLREOL}${FMT_STD}" $(TRACE_LOG) ;\
# To be updated : 			rsync -aEim "$$file" "$$lDestFile" $(TRACE_REDIRECT); \
# To be updated : 		fi; \
# To be updated : 	done #cp $(RESDIR)/* $(TARGETDIR)/


##  @brief Convenience target to make directories we'll need.
directories:	#help: Convenience target to make directories we'll need.
	@mkdir -p $(shell dirname $(FILE_TRACE))
	@mkdir -p $(RESDIR)		    $(TRACE_REDIRECT)
	@mkdir -p $(TARGETDIR)		    $(TRACE_REDIRECT)
	@mkdir -p $(TARGETDIR_TST)	    $(TRACE_REDIRECT)
	@mkdir -p $(BUILDDIRSRC)	    $(TRACE_REDIRECT)
	@mkdir -p $(BUILDDIRTST)	    $(TRACE_REDIRECT)
	@mkdir -p $(DIR_DOC_OUT)	    $(TRACE_REDIRECT)
	@mkdir -p $(BUILDDIR_ARDUINO_CORE)  $(TRACE_REDIRECT)


#Pull in dependency info for *existing* .o files
-include $(OBJECTS:.$(OBJEXT)=.$(DEPEXT))



# ------------------------------------------------------------------------------
#   Compilation targets
# To produce object files.
# ------------------------------------------------------------------------------

##  @brief  Target to generate object files from main sources.
$(BUILDDIRSRC)/%.$(OBJEXT): $(SRCDIR)/%.$(SRCEXT)
	@echo -e "${lColorCC}    CC $@ ${CLREOL}${FMT_STD}" $(TRACE_LOG)
	@mkdir -p $(dir $@) $(TRACE_REDIRECT)
	@if [ ! "$(TRACES)" -eq "0" ] ; then \
	        echo "$(CC) -c $(CFLAGS) $(INC) -o $@ $<" $(TRACE_REDIRECT); \
	fi
	@$(CC) -c $(CFLAGS) $(INC) -o $@ $< $(TRACE_REDIRECT)


$(BUILDDIR_ARDUINO_CORE)/%.$(OBJEXT): $(ARDUINO_PATH)/%.c
	@echo -e "${lColorCC}    CC  $@ ${CLREOL}${FMT_STD}" $(TRACE_LOG)
	@mkdir -p $(dir $@) $(TRACE_REDIRECT)
	@if [ ! "$(TRACES)" -eq "0" ] ; then \
		echo "$(CC) $(CFLAGS) $(INC) -c -o $@ $<" $(TRACE_REDIRECT); \
	fi
	@$(CC) $(CFLAGS) $(INC) -c -o $@ $< $(TRACE_REDIRECT)


##  @brief  Target to generate object files from main sources.
$(BUILDDIR_ARDUINO_CORE)/%.$(OBJEXT): $(ARDUINO_PATH)/%.cpp
	@echo -e "${lColorCC}    CXX $@ ${CLREOL}${FMT_STD}" $(TRACE_LOG)
	@mkdir -p $(dir $@) $(TRACE_REDIRECT)
	@if [ ! "$(TRACES)" -eq "0" ] ; then \
		echo "$(CC) $(CFLAGS) $(INC) -c -o $@ $<" $(TRACE_REDIRECT); \
	fi
	@$(CC) $(CFLAGS) $(INC) -c -o $@ $< $(TRACE_REDIRECT)


# To be updated : ##  @brief  Target to generate object files from test sources.
# To be updated : $(BUILDDIRTST)/%.$(OBJEXT): $(TESTSDIR)/%.$(SRCEXT)
# To be updated : 	@echo -e "${lColorCC}    CC $@${CLREOL}${FMT_STD}" $(TRACE_LOG)
# To be updated : 	@mkdir -p $(dir $@)
# To be updated : 	@if [ ! "$(TRACES)" -eq "0" ] ; then \
# To be updated : 		echo "$(CC) $(CFLAGS) $(INC) -c -o $@ $<" $(TRACE_REDIRECT); \
# To be updated : 	fi
# To be updated : 	@$(CC) $(CFLAGS) $(INC) -c -o $@ $< $(TRACE_REDIRECT)



# ------------------------------------------------------------------------------
#   Link targets
# To produce executables.
# ------------------------------------------------------------------------------

$(BUILDDIR)/$(TARGET:%.hex=%.elf): $(ARDUINO_CORE_OBJECTS) $(OBJECTS)	#help: Main application's target.
	@echo -e "${lColorLD}    LD  $@${CLREOL}${FMT_STD}" $(TRACE_LOG)
	@if [ ! "$(TRACES)" -eq "0" ] ; then \
	        echo "$(LD) $(LDFLAGS) -o $@ $^" $(TRACE_REDIRECT); \
	fi
	@$(LD) $(LDFLAGS) -o $@ $^ $(LIBS) $(TRACE_REDIRECT)


$(TARGETDIR)/$(TARGET): $(BUILDDIR)/$(TARGET:%.hex=%.elf)
	@echo -e "${lColorLD}    HEX $@${CLREOL}${FMT_STD}" $(TRACE_LOG)
	avr-objcopy -O ihex -R .eeprom $< $@

## To be updated : ##  @brief  Automated tests target.
## To be updated : $(TARGET_TESTS_AUTO): $(OBJECTS_TST) $(filter-out $(BUILDDIRSRC)/main.$(OBJEXT), $(OBJECTS))	#help: Automated tests target.
## To be updated : 	@echo -e "${lColorLD}    LD  $@${CLREOL}${FMT_STD}" $(TRACE_LOG)
## To be updated : 	@if [ ! "$(TRACES)" -eq "0" ] ; then \
## To be updated : 		echo "$(CC) -o $(TARGETDIR_TST)/$(TARGET_TESTS_AUTO) $^ $(LIB)" $(TRACE_REDIRECT); \
## To be updated : 	fi
## To be updated : 	@$(CC) -o $(TARGETDIR_TST)/$(TARGET_TESTS_AUTO) $^ $(LIB) $(TRACE_REDIRECT)



# ------------------------------------------------------------------------------
#   Cleaning targets
# ------------------------------------------------------------------------------

##  @brief  Target to remove objects only.
clean:	#help: Target to remove objects only.
	@echo -e "${lColorRM}    RM  ./$(BUILDDIRROOT)/ ${CLREOL}$(FMT_STD)" #$(TRACE_REDIRECT);
	@$(RM) -rvf ./$(BUILDDIRROOT)/ #$(TRACE_REDIRECT)


##  @brief  Target to remove documentation only.
clean-doc:	#help: Target to remove documentation only.
	@echo -e "${lColorRM}    RM  ./$(DIR_DOC_OUT)/ ${CLREOL}$(FMT_STD)" #$(TRACE_REDIRECT);
	@$(RM) -rvf ./$(DIR_DOC_OUT)/ #$(TRACE_REDIRECT)


##  @brief  Full Clean, Objects and Binaries.
cleaner: clean clean-doc	#help: Full Clean, Objects and Binaries.
	@echo -e "${lColorRM}    RM  ./$(TARGETDIR)/ ${CLREOL}$(FMT_STD)"
	@$(RM) -rvf $(TARGETDIR)
	@echo -e "${lColorRM}    RM  ./$(DIR_OUTPUT)/ ${CLREOL}$(FMT_STD)"
	@$(RM) -rvf $(DIR_OUTPUT)



# ------------------------------------------------------------------------------
#   "run" targets
# ------------------------------------------------------------------------------

# To be updated : run-target: target	#help: Run the target.
# To be updated : 	@echo -e "${lColorRun}    RUN $(TARGETDIR)/$(TARGET)${CLREOL}$(FMT_STD)"
# To be updated : 	$(TARGETDIR)/$(TARGET) $(TRACE_LOG)
# To be updated : 
# To be updated : 
# To be updated : run-tests-auto: tests	#help: Run executable for automated tests.
# To be updated : 	@echo -e "${lColorRun}    RUN $(TARGETDIR_TST)/$(TARGET_TESTS_AUTO)${CLREOL}$(FMT_STD)"
# To be updated : 	@pushd $(TARGETDIR_TST) 1>/dev/null; \
# To be updated : 		echo "[Repertoire '$$(pwd)']"; \
# To be updated : 		./$(TARGET_TESTS_AUTO) -d no $(TRACE_LOG);\
# To be updated : 	popd;



# ------------------------------------------------------------------------------
#   "analysis" targets
# ------------------------------------------------------------------------------
# To be updated : run-target-analysis-valgrind: target	#help: Run the target with callgrind analysis.
# To be updated : 	@echo -e "${lColorRun}    RUN VALGRIND $(TARGETDIR)/$(TARGET)${CLREOL}$(FMT_STD)"
# To be updated : 	valkyrie $(TARGETDIR)/$(TARGET) $(TRACE_LOG)
# To be updated : 
# To be updated : 
# To be updated : run-tests-auto-analysis-valgrind: tests	#help: Run the tests with callgrind analysis.
# To be updated : 	@echo -e "${lColorRun}    RUN VALGRIND $(TARGETDIR_TST)/$(TARGET_TESTS_AUTO)${CLREOL}$(FMT_STD)"
# To be updated : 	@pushd $(TARGETDIR_TST) 1>/dev/null; \
# To be updated : 		echo "[Repertoire '$$(pwd)']"; \
# To be updated : 		valkyrie ./$(TARGET_TESTS_AUTO) -d no $(TRACE_LOG);\
# To be updated : 	popd;



# ------------------------------------------------------------------------------
#   Other targets
# ------------------------------------------------------------------------------

##  @brief  Calls a script to create a zip archive from the current project.
archive:	#help: Creates an archive of the current project.
	@./scripts/generate-archive.sh


##  @brief  Target to generate Doxygen documentation.
doxygen: directories	#help: Target to generate Doxygen documentation.
	@echo -e "${lColorDoc}    DOC $@${CLREOL}${FMT_STD}" $(TRACE_LOG)
	@if [ ! "$(TRACES)" -eq "0" ] ; then \
		echo "$(BIN_DOXYGEN) $(DIR_DOC)/doxygen/doxygen.conf" $(TRACE_REDIRECT); \
	fi
	@$(BIN_DOXYGEN) $(DIR_DOC)/doxygen/doxygen.conf $(TRACE_REDIRECT)


ide-qtcreator-files:	#help: Creates/Updates files for the QtCreator IDE.
	./scripts/generate-qtcreator-files.sh


##  @brief  Convenience target to open the documentation main page.
open-docdev:	#help: Convenience target to open the documentation main page.
	@xdg-open $(DIR_DOC_OUT)/html/index.html


help: #help: Print this help.
	@sed -ne '/@sed/!s/:.*#help: /: \t/p' $(MAKEFILE_LIST)


deploy: target # Deploy to target uC
	@echo -e "${lColorRM}    DP  $(TARGETDIR)/$(TARGET)${CLREOL}$(FMT_STD)" #$(TRACE_REDIRECT);
	avrdude -p$(MCU) -P$(PORT) -carduino -b$(UPLOAD_SPEED) -U flash:w:$(TARGETDIR)/$(TARGET):i
