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
SHELL:=/bin/bash

MK_INCDIR   := ../../../mk-inc



##  @brief  Default Make target.
default: target



include $(MK_INCDIR)/project-config.mk

# Override this variable (declared in project-config)
TARGETNAME	:= demo-ADS1015


include $(MK_INCDIR)/arduino-config.mk

include $(MK_INCDIR)/directories.mk



# ------------------------------------------------------------------------------
#   Arduino-related declarations
# ------------------------------------------------------------------------------

include $(MK_INCDIR)/arduino-lib-core.mk
include $(MK_INCDIR)/arduino-lib-wire.mk



# ------------------------------------------------------------------------------
include $(MK_INCDIR)/build-options.mk
INC+= -I$(MK_INCDIR)/../src/



# ##############################################################################
#   DO NOT EDIT BELOW THIS LINE
# ##############################################################################

include $(MK_INCDIR)/colors.mk
include $(MK_INCDIR)/traces.mk
include $(MK_INCDIR)/sources.mk



# ------------------------------------------------------------------------------
#   Target aliases
# ------------------------------------------------------------------------------

##  @brief  Target to build the main target.
target: show_sources resources $(TARGETDIR)/$(TARGET)


##  @brief  Target to build everything.
all: default show_sources_tests $(TARGET_TESTS_AUTO) doc


##  @brief  Target to re-build everything
remake: cleaner all	#help: Same as 'make cleaner all'


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
	@for file in $(ARDUINO_SOURCES) $(SOURCES); do \
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
	@for file in $(ARDUINO_OBJECTS) $(OBJECTS); do \
		echo "+-- $${file}" $(TRACE_LOG); \
	done
	@echo ""



# ------------------------------------------------------------------------------
#   Compilation targets
# To produce object files.
# ------------------------------------------------------------------------------

include $(MK_INCDIR)/targets-default.mk



# ------------------------------------------------------------------------------
#   Link targets
# To produce executables.
# ------------------------------------------------------------------------------

include $(MK_INCDIR)/targets-out.mk



# ------------------------------------------------------------------------------
#   Cleaning targets
# ------------------------------------------------------------------------------

include $(MK_INCDIR)/targets-clean.mk



# ------------------------------------------------------------------------------
#   Other targets
# ------------------------------------------------------------------------------

include $(MK_INCDIR)/targets-doc.mk
include $(MK_INCDIR)/arduino-target-deploy.mk

##  @brief  Calls a script to create a zip archive from the current project.
archive:	#help: Creates an archive of the current project.
	@./scripts/generate-archive.sh



ide-qtcreator-files:	#help: Creates/Updates files for the QtCreator IDE.
	./scripts/generate-qtcreator-files.sh



help: #help: Print this help.
	@sed -ne '/@sed/!s/:.*#help: /: \t/p' $(MAKEFILE_LIST)



