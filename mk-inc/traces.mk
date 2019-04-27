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
