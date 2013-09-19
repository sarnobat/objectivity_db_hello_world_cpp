/**************************************************************************
		    Copyright (c) 1989-2000 Objectivity, Inc.
			  All Rights Reserved	

	THIS IS UNPUBLISHED PROPRIETARY SOURCE CODE OF OBJECTIVITY, INC.
	
	The copyright notice above does not evidence any	
	actual or intended publication of such source code.

*****************************************************************************/

#ifndef OO_ERROR_H
#define OO_ERROR_H "@(#)$Id$"


#if defined(_MSC_VER) && !defined(OO_DDL_TRANSLATION)
#pragma pack(push,8)
#endif

#ifndef OO_BASE_H
#include <ooBase.h>  /* for ooStatus and ooHandle */
#endif

/* Type declarations */

typedef enum ooErrorLevel {
    oocNoError = 0,
    oocWarning,
    oocUserError,
    oocSystemError,
    oocFatalError
} ooErrorLevel;

/* A pointer of type "oerError *" must be usable as type "ooError *". */
class OO_STORAGE_SPECIFIER ooError {
public:
    uint32	errorN;		/* error number */
    const char*	message;	/* error message */
};

#define OO_MAX_REPORTED_ERRORS 7
#define OEH_MSG_BUFFER_SIZE		1024

class OO_STORAGE_SPECIFIER ooErrorInfo {
public:
    uint32       errorN;
    char         message[OEH_MSG_BUFFER_SIZE];
    ooErrorLevel errorLevel;
    const char*  functionContext;
    ooId         objectContext;
};

typedef ooError*  ooErrorPtr;

typedef void	  (*ooMsgHandlerPtr) (char*);
typedef ooBoolean (*ooTwoMachineHandlerPtr)();

#ifndef _MSC_VER
typedef ooStatus (*ooErrorHandlerPtrInternal) (ooErrorLevel, ooError&, ooHandleBase*, char*);
#else
extern "C" {
typedef ooStatus (*ooErrorHandlerPtrInternal) (ooErrorLevel, ooError&, ooHandleBase*, char*);
}
#endif

OO_STORAGE_SPECIFIER extern ooError	   ooeAssert;

typedef struct oehSessionData oehSessionData;

oehSessionData *
oehSessionDataGetFunction();

/* These four are undocumented; no one should be using these. */
#define oovMsgHandler         ooGetMsgHandler()
#define oovLastMsgHandler     ooGetLastMsgHandler()

#define oovLastErrorLevel     ooGetLastErrorLevel()
#define oovLastError          ooGetLastError()
#define oovNError             ooGetNError()

OO_STORAGE_SPECIFIER ooErrorLevel & ooGetLastErrorLevel ();
OO_STORAGE_SPECIFIER ooErrorPtr & ooGetLastError ();
OO_STORAGE_SPECIFIER uint32 & ooGetNError ();

OO_STORAGE_SPECIFIER
ooTwoMachineHandlerPtr & ooGetTwoMachineHandler ();
OO_STORAGE_SPECIFIER
void ooRegTwoMachineHandler (ooTwoMachineHandlerPtr name);
#define ooTwoMachineHandler ooGetTwoMachineHandler()

/* Get message handler */
OO_STORAGE_SPECIFIER ooMsgHandlerPtr & ooGetMsgHandler ();
OO_STORAGE_SPECIFIER
ooMsgHandlerPtr & ooGetLastMsgHandler ();

ooErrorLevel oehGetLastErrorLevel ();
ooErrorPtr oehGetLastError ();
uint32 oehGetNError ();

/* Reset error flags */
OO_STORAGE_SPECIFIER void ooResetError ();

/* Set error context */
OO_STORAGE_SPECIFIER const char* ooSetErrorContext(const char* errorContext);
OO_STORAGE_SPECIFIER oehSessionData * oehSetErrorContext(const char* errorContext);

/* Reset error context */
OO_STORAGE_SPECIFIER void ooResetErrorContext ();

/* If top level, set error context and automatically reset at end of scope */
class OO_STORAGE_SPECIFIER ooWithErrorContext
{
private:
  const char** reset_loc;
public:
  ooWithErrorContext(const char* name);
  ~ooWithErrorContext() { *reset_loc = NULL; }
};

/* Function prototyping */

/* Register message handler */
OO_STORAGE_SPECIFIER ooMsgHandlerPtr
ooRegMsgHandler (ooMsgHandlerPtr nameOfMsgHandler);
OO_STORAGE_SPECIFIER ooErrorHandlerPtrInternal
ooRegErrorHandlerInternal(ooErrorHandlerPtrInternal errorHandler, oehSessionData* eh_ptr = 0);
OO_STORAGE_SPECIFIER ooStatus ooSignal (const ooErrorLevel	 errorLevel,
			  const ooError&	 errorId,
			  const ooHandleBase* pContextObj, ...);
OO_STORAGE_SPECIFIER ooStatus ooSignal (const ooErrorLevel	 errorLevel,
			  const ooError&	 errorId,
			  ooHandleBase pContextObj, ...);
ooStatus ooDefErrorHandler(ooErrorLevel errorLevel, ooError& errorId, ooHandleBase* pContextObj, char* pMessage);
OO_STORAGE_SPECIFIER ooStatus
ooNullErrorHandler (ooErrorLevel, ooError&, ooHandleBase*,char *);

OO_STORAGE_SPECIFIER ocmSession* ocmSessionCurrentGetFunction();

OO_STORAGE_SPECIFIER void ooThrowException(ocmSession* session);
OO_STORAGE_SPECIFIER void ooThrowException();

OO_STORAGE_SPECIFIER ooStatus ociSignal (ooErrorLevel	    errorLevel,
				   const ooError*	    errorId,
				   ooHandleBase*	    pContextObj,
				   ...);

OO_STORAGE_SPECIFIER
ooStatus ooSetErrorFile (const char* nameOfErrorFile);

/* Ignore the error message, no error message is printed */
void  OO_STORAGE_SPECIFIER ooNullMsgHandler (char*  message);

/* maximum line length for error message */
extern OO_STORAGE_SPECIFIER int oovErrorLineLength;
OO_STORAGE_SPECIFIER int ooErrorLineLength(int setValue = 0);

#if defined(_MSC_VER) && !defined(OO_DDL_TRANSLATION)
#pragma pack(pop)
#endif

#endif /* OO_ERROR_H */
