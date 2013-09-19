/*                                     Appendix A
 Include file for Lock Server Performance Monitoring API 
 */

/*  oolspm.h
 */
/**************************************************************************
                    Copyright (c) 2000 Objectivity, Inc.
                          All Rights Reserved

        THIS IS UNPUBLISHED PROPRIETARY SOURCE CODE OF OBJECTIVITY, INC.

        The copyright notice above does not evidence any
        actual or intended publication of such source code.

*****************************************************************************/



#ifndef ___OOLSPM_H___
// {
#define ___OOLSPM_H___ "@(#)$Id$"


#include <stdio.h>
#include <string.h>
#include <time.h>

#define LSPM_PROTOCOL_VERSION 2
typedef unsigned int YN;
const YN yes = 0xFFFFFFFF;
const YN no = 0;

#define MAXHOSTNAMELENGTH 256

#define MAX_EXCEPTION_MSG_BUFFER_SIZE 256

#ifndef LSPM_STORAGE_SPECIFIER // {
#if defined(_MSC_VER) && defined(_DLL) // {
#ifdef OO_BUILD  // while bulding library
#define LSPM_STORAGE_SPECIFIER  __declspec(dllimport)
#else
#define LSPM_STORAGE_SPECIFIER  //__declspec(dllexport)
#ifdef _DEBUG
/* Dynamic debug link */
#pragma comment(lib, "oolspmid.lib")
#else
/* Dynamic non-debug link */
#pragma comment(lib, "oolspmi.lib")
#endif
#endif
#else
// }{ 	//unix
#define LSPM_STORAGE_SPECIFIER
// }
#endif
#endif

// Sun C++ 4.2, HPUX and IBM does not support <exception>
#if defined(OO_SOLARIS) || defined(OO_AIX) || defined(OO_HPUX)
class LSPM_STORAGE_SPECIFIER oolspmException 
#else
#include <exception>
class LSPM_STORAGE_SPECIFIER oolspmException : public std::exception 
#endif
{
protected:
	char exceptionMsg[MAX_EXCEPTION_MSG_BUFFER_SIZE];

public:
	
#if defined(OO_SOLARIS) || defined(OO_AIX)
        virtual const char* what() const { return (const char*) exceptionMsg; }
#else
        virtual const char* what() const throw() { return (const char*) exceptionMsg; }
#endif

};	//oolspmException

class LSPM_STORAGE_SPECIFIER oolspmCantConnectToLockServerException : public oolspmException
{
public:
	oolspmCantConnectToLockServerException(const char *ls);
};	//oolspmCantConnectToLockServerException

class LSPM_STORAGE_SPECIFIER oolspmLockServerNotAvailableException : public oolspmException
{
public:
	oolspmLockServerNotAvailableException(const char *ls);
};	//oolspmLockServerNotAvailableException

class LSPM_STORAGE_SPECIFIER oolspmLockServerMonitoringAlreadyStartedException : public oolspmException
{
public:
	oolspmLockServerMonitoringAlreadyStartedException(const char *ls);
};	//oolspmLockServerMonitoringAlreadyStartedException

class LSPM_STORAGE_SPECIFIER oolspmLockServerMonitorNotRunningException : public oolspmException
{
public:
	oolspmLockServerMonitorNotRunningException(const char *ls);
};	//oolspmLockServerMonitorNotRunningException

class LSPM_STORAGE_SPECIFIER oolspmIncompatibleLockserverVersionException : public oolspmException
{
public:
	oolspmIncompatibleLockserverVersionException(const char *ls);
};	//oolspmIncompatibleLockserverVersionException

class LSPM_STORAGE_SPECIFIER oolspmLockServerConnectionClosedException : public oolspmException
{
public:
	oolspmLockServerConnectionClosedException(const char *ls);
};	//oolspmLockServerConnectionClosedException

class LSPM_STORAGE_SPECIFIER oolspmUnknownException : public oolspmException
{
public:
	oolspmUnknownException(const char *ls);
};	//oolspmUnknownException



#ifdef OO_NT
#include <winsock2.h> // need for SOCKET definition
typedef SOCKET oolsSocket;
#else /* !OO_NT */
typedef int oolsSocket;
#endif

/* classes */
class LSPM_STORAGE_SPECIFIER oolsEventsMonitorMessage;
class onmAmsSocketDefault;

class  LSPM_STORAGE_SPECIFIER oolsEventsMonitor
{
	/* oolsEventsMonitor is the main class, which is used to
	   affect monitoring. An interested analyst would create
	   an instance of this class and  invoke its methods as needed.
	   The analyst also creates an instance of the companion class
	   oolsEventsMonitorMessage, which will be filled with "raw" messages
	   receieved from the lock server.  This object should be sent to
	   getNextMessage().
	 */

public:

	/* This class will have the following public methods
	 */
	oolsEventsMonitor(const char *ls);
	/* Taking a lock server host name as the parameter, 
	   the constructor will establish a connection to that 
	   lock server.  

	 Throws: oolspmLockServerNotAvailableException
		 oolspmLockServerConnectionClosedException
	 */
         
    // SPR 19839 - Incomplete Type Compiler Warning
    // moved destructer implementation to oolspm.cxx
    ~oolsEventsMonitor();

	void startMonitoring();
	/* Invoking this method will establish a connection 
	   with the lock server, identifies the current process
	   as the one to which event monitoring messages would be sent.

	 Throws: oolspmLockServerNotAvailableException,
		 oolspmLockServerConnectionClosedException
	         oolspmCantConnectToLockServerException
	         oolspmLockServerMonitoringAlreadyStartedException
	 */

	void stopMonitoring ();
	/* This method will cause the lock server to do
	   equivalent of unmonitorEvent(ooclsMonitorAll), and
 	   disconnects itself from the initiating process.

	 Throws: oolspmLockServerNotAvailableException,
		 oolspmLockServerConnectionClosedException
	         oolspmLockServerMonitorNotRunningException
 	 */

	void monitorLocks (YN yn = yes);
	/* This method causes the lock events to be added to  
	   or removed from the list of events being monitored.

	 Throws: oolspmLockServerNotAvailableException,
		 oolspmLockServerConnectionClosedException
	         oolspmUnknownException
	 */

	void monitorQueues (YN yn = yes);
	/* This method causes the queue events to be added to  
	   or removed from the list of events being monitored.

	 Throws: oolspmLockServerNotAvailableException,
		 oolspmLockServerConnectionClosedException
	         oolspmUnknownException
	 */

	void monitorTransactions (YN yn = yes);
	/* This method causes the transaction events to be added to  
	   or removed from the list of events being monitored.

	 Throws: oolspmLockServerNotAvailableException,
		 oolspmLockServerConnectionClosedException
	         oolspmUnknownException
	 */

	void monitorConnects (YN yn = yes);
	/* This method causes the connect events to be added to  
	   or removed from the list of events being monitored.

	 Throws: oolspmLockServerNotAvailableException,
		 oolspmLockServerConnectionClosedException
	         oolspmUnknownException
	 */

	void monitorDeadlocks (YN yn = yes);
	/* This method causes the deadlock events to be added to  
	   or removed from the list of events being monitored.

	 Throws: oolspmLockServerNotAvailableException,
		 oolspmLockServerConnectionClosedException
	         oolspmUnknownException
	 */

	YN isMonitoringLocks(void);
	YN isMonitoringQueues(void);
	YN isMonitoringTransactions(void);
	YN isMonitoringConnects(void);
	YN isMonitoringDeadlocks(void);
	/* These methods enquire the lock server if the
	   events of the respective type are being monitored
	   at this time.

	 Throws: oolspmLockServerNotAvailableException,
		 oolspmLockServerConnectionClosedException
	         oolspmUnknownException
	 */

	YN isMonitoringActive(void);
	/* This method enquires the lock server if there is
	   a process which is actively monitoring at this time.

	 Throws: oolspmLockServerNotAvailableException,
		 oolspmLockServerConnectionClosedException
	         oolspmUnknownException
	 */

	//TODO: should 2nd param be int32 for platform independency?
	int getNextMessage(oolsEventsMonitorMessage  *msg, int msecWaitTime = 0);
	/* This method receives the next message sent by the lock server.
	   msg will have the "raw" message.
	   If next message is not received in msecWaitTime milliseconds, 
	   the call will return with error.
	   Return value of 1 means there is message, 0 means no message within
	   time limit set.
	   Upon receiving lspmStoppedMessageType message, lock server 
	   will be disconnected, don't issue any more getNextMessage().

	 */
  private:
    //SPR 18801 make this an instance variable rather than a static
    //since on linux the order of static initializer execution is different
    onmAmsSocketDefault* myListenSocket;
};



typedef int oolsMessageType;
typedef int oolsStopCause;
typedef int oolsLockResult;
typedef int oolsResult;
typedef int oolsLockType;
typedef int oolsTransEndType;
typedef int oolsResourceType;

// oolsMessageType 
//{
const int noMessageType = 0; 
const int lockMessageType = 1; 
const int unlockMessageType = 2; 
const int beginTransactionMessageType = 3; 
const int endTransactionMessageType = 4; 
const int downgradeMessageType = 5; 
const int waitFailedMessageType = 6; 
const int waitSucceededMessageType = 7; 
const int deadlockFirstMessageType = 8; 
const int deadlockMessageType = 9; 
const int deadlockLastMessageType = 10; 
const int connectMessageType = 11; 
const int disconnectMessageType = 12;
const int lspmStoppedMessageType = 13;
//};
// oolsStopCause 
//{
const int lsKilled = 0;  // 'K'
const int userStop = 1;	// 'U'
//}

// oolsLockResult 
//{
const int lkerror=0; // 'E'
const int granted=1; // 'G'
const int upgraded=2; // 'U'
const int queued=3;  // 'Q'
const int deadlock=4; // 'D'
const int rejected=5; // 'R'
const int probeSucceeded=6; // 'S'
const int probeFailed=7; // 'F'
//}

// oolsResult
//{
const int error=0; // 'E'
const int succeeded=1; // 'S'
//}

// oolsLockType
//{
const int noLock=0;
const int IS=1;
const int IC=2;
const int IX=6;
const int S=3;
const int R=4;
const int C=5;
const int X=7;
//}

// oolsTransEndType
//{
const int abortTran = 0; // 'A'
const int commitTran = 1; // 'C'
const int releaseLatchesTran = 2; // 'R'
const int downgradeTran = 3; // 'D'
//}

// oolsResourceType  
//{
const int   FDB=0;
const int   DB=1;
const int   OC=2;
//}

class LSPM_STORAGE_SPECIFIER oolsClientId
{
public:
	int uid;
	int pid;
	char host[MAXHOSTNAMELENGTH];

	void save(FILE *msgFile) ;
};


typedef long oolsTimestamp;	//time_t ==> long to avoid platform dependency

struct LSPM_STORAGE_SPECIFIER oolsTimeval {
    ooUInt32 tv_sec;
    ooUInt32 tv_msec;
};

typedef unsigned int oolsTransId;


class LSPM_STORAGE_SPECIFIER oolsResourceId
{
public:
	oolsResourceType resource;
	unsigned int apid;
	unsigned int fdid;
	unsigned int dbid;
	unsigned int ocid;
	unsigned int versn;

	void save(FILE *msgFile) ;
};

class LSPM_STORAGE_SPECIFIER oolsLockMessage
{
public:
	oolsTimeval ts;
	oolsTransId tid;
	oolsResourceId resrc;
	oolsLockType mode;
	oolsClientId client;
	oolsLockResult result;

	void save(FILE *msgFile) ;
};

class LSPM_STORAGE_SPECIFIER oolsUnlockMessage
{
public:
	oolsTimeval ts;
	oolsTransId tid;
	oolsResourceId resrc;
	oolsResult result;

	void save(FILE *msgFile) ;
};
const int MAXFDNAME = 1024;    // ==olmMAXFDNAME ==OO_MAX_PATH_LEN
class LSPM_STORAGE_SPECIFIER oolsBeginTransactionMessage 
{
public:
	oolsTimeval ts;
	oolsTransId tid; /* will be 0 in case of error */
	unsigned int apid;
	unsigned int fdid;
	char fdName[MAXFDNAME];
	oolsClientId client;
	oolsResult result;

	void save(FILE *msgFile) ;
};

class LSPM_STORAGE_SPECIFIER oolsEndTransactionMessage 
{
public:
	oolsTimeval ts;
	oolsTransId tid;
	unsigned int apid;
	oolsTransEndType type;
	oolsResult result;

	void save(FILE *msgFile) ;
};

class LSPM_STORAGE_SPECIFIER oolsDowngradeMessage
{
public:
	oolsTimeval ts;
	oolsTransId tid;
	oolsResult result;

	void save(FILE *msgFile) ;
};

class LSPM_STORAGE_SPECIFIER oolsWaitFailedMessage
{
public:
	oolsTimeval ts;
	oolsTransId tid;
	oolsResourceId resrc;
	oolsLockType mode;
	int uid;
    unsigned int timeInQ;

	void save(FILE *msgFile) ;
};

class LSPM_STORAGE_SPECIFIER oolsWaitSucceededMessage 
{
public:
	oolsTimeval ts;
	oolsTransId tid;
	oolsResourceId resrc;
	oolsLockType mode;
	oolsClientId client;

	unsigned int timeInQ;

	void save(FILE *msgFile) ;
};

/* signals start of deadlock chain */
class LSPM_STORAGE_SPECIFIER oolsDeadlockFirstMessage
{ 
public:
	oolsTimeval ts;
	oolsTransId tid;

	void save(FILE *msgFile) ;
};

class LSPM_STORAGE_SPECIFIER oolsDeadlockMessage
{
public:
	oolsTransId tid;

	void save(FILE *msgFile) ;
};

class LSPM_STORAGE_SPECIFIER oolsDeadlockLastMessage
{ /* signals end of deadlock chain  - currently unused */
public:
	oolsTransId tid;

	void save(FILE *msgFile) ;
}; 

class LSPM_STORAGE_SPECIFIER oolsConnectMessage
{
public:
	oolsTimeval ts;
	oolsClientId client;
	oolsSocket sock;
	oolsResult result;


	void save(FILE *msgFile); 
};

class LSPM_STORAGE_SPECIFIER oolsDisconnectMessage
{
public:
	oolsTimeval ts;
	oolsSocket sock;

	void save(FILE *msgFile); 
};

class LSPM_STORAGE_SPECIFIER oolsLspmStoppedMessage
{
public:
	oolsTimeval ts;
	oolsStopCause cause;

	void save(FILE *msgFile); 
};

class LSPM_STORAGE_SPECIFIER oolsEventsMonitorMessage
{
public:
	unsigned int msgNumber;
	oolsMessageType msgType;
	union
	{
		oolsLockMessage lockMsg;
		oolsUnlockMessage unlockMsg;
		oolsBeginTransactionMessage btMsg;
		oolsEndTransactionMessage etMsg;
		oolsDowngradeMessage downgradeMsg;
		oolsWaitFailedMessage waitFailedMsg;
		oolsWaitSucceededMessage waitSucceededMsg;
		oolsDeadlockFirstMessage deadlockFirstMsg;
		oolsDeadlockMessage deadlockMsg;
		oolsDeadlockLastMessage deadlockLastMsg; 
		oolsConnectMessage connectMsg;
		oolsDisconnectMessage disconnectMsg;
		oolsLspmStoppedMessage lspmStoppedMsg;
	} msg;
	/* constructor */
	oolsEventsMonitorMessage() : msgNumber(0), msgType(noMessageType)
		{ }

	/* destructor must destroy proper type; compiler should
	   do that as long as we don't have pointers.
	 */

	void save(FILE *msgFile) ;
};

// }
#endif //___OOLSPM_H___
