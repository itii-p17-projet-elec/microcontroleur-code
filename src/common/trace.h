#ifndef TRACE_H
#define TRACE_H

#include "comm/interface/IfaceSerial.h"

/* ########################################################################## */
/* ########################################################################## */

#ifdef  TRACES

#define TRACE(arg)  Comm::Interface::IfaceSerial::Instance()->sendData(#arg);
#define TRACELN(arg)    \
        Comm::Interface::IfaceSerial::Instance()->sendData(#arg); \
        Comm::Interface::IfaceSerial::Instance()->sendData("\n");

#else   /* no TRACES defined */

#define TRACE(arg)
#define TRACELN(arg)

#endif

/* ########################################################################## */
/* ########################################################################## */

#endif  /*< TRACE_H */
