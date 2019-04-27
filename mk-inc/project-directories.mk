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
