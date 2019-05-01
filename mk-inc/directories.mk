# ------------------------------------------------------------------------------
#   Directories configuration
# The Directories, Source, Includes, Objects, Binary and Resources
# ------------------------------------------------------------------------------
SRCDIR	  := src
INCDIR	  := inc
BUILDDIRROOT    := build
BUILDDIR        := $(BUILDDIRROOT)/$(ARDUINO_BOARD)/$(MCU)
BUILDDIRSRC     := $(BUILDDIR)/src
BUILDDIRTST     := $(BUILDDIR)/tests
DIR_OUTPUT      := ./out
TARGETDIR       := $(DIR_OUTPUT)/bin
TARGETDIR_TST   :=$(TARGETDIR)/tests
RESDIR          := rsrc
TESTSDIR        := tests


DIRECTORIES	+= $(SRCDIR)
DIRECTORIES	+= $(INCDIR)
DIRECTORIES	+= $(BUILDDIRROOT)
DIRECTORIES	+= $(BUILDDIR)
DIRECTORIES	+= $(BUILDDIRSRC)
DIRECTORIES	+= $(BUILDDIRTST)
DIRECTORIES	+= $(DIR_OUTPUT)
DIRECTORIES	+= $(TARGETDIR)
DIRECTORIES	+= $(TARGETDIR_TST)
DIRECTORIES	+= $(RESDIR)
DIRECTORIES	+= $(TESTSDIR)



##  @brief Convenience target to make directories we'll need.
directories:	#help: Convenience target to make directories we'll need.
	@mkdir -p $(shell dirname $(FILE_TRACE))
	@for lDir in $(DIRECTORIES) ; do \
	        if [ ! -d "$${lDir}" ] ; \
		then \
		        echo -e "${lColorRC}    MKD $${lDir} ${CLREOL}${FMT_STD}" $(TRACE_LOG) ;\
			mkdir -p $${lDir} ; \
		fi; \
	done
