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
lColorDP        :="${FMT_BLD}${COL_BLK}"
lColorLD        :="${COL_MAG}"
lColorRC        :="${COL_YLW}"
lColorRM        :="${COL_RED}"
lColorRun       :="${COL_CYN}"
lColorSrcList	:="${FMT_BLD}${FMT_UDL}"

