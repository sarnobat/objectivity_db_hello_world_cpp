//***************************************************************************//
//                                                                           //
//                Copyright © 2000 Objectivity Inc, USA.                     //
//                                                                           //
//    All Rights Reserved. Unauthorized use, duplication or distribution     //
//         of this software, or any portion of it, is prohibited.            //
//                                                                           //
//***************************************************************************//

#ifndef ooObjy_h
#define ooObjy_h "@(#)$Id$"

#ifndef OO_H
#include <oo.h>
#endif

#ifndef ooTuner_h
#include "ooTuner.h"
#endif

#ifndef ooSessionException_h
#include "ooSessionException.h"
#endif

#ifndef ooLogListener_h
#include "ooLogListener.h"
#endif

#ifndef ooSession_h
#include "ooSession.h"
#endif

#ifndef ooConnection_h
#include "ooConnection.h"
#endif

#ifndef ooStatistics_h
#include "ooStatistics.h"
#endif

class ooTaskAssigner;
class ooPerformanceAnalyzer;

// or-able logging options. 
enum ooLogOptions {
      oocLogNone = 0,
      oocLogMain = 1,
      oocLogSession = 2,
      oocLogTransactionStatistics = 4,
      oocLogTransactionTiming = 8,
      oocLogOther = 16,
      oocLogAll = 31};

//-----------------------------------------------------------------------------
class OO_STORAGE_SPECIFIER ooObjy
{
   public:

      // starts the connection
      static void startup(uint32 numberOfFiles = oocDefaultMaxOpenFiles,
	                  ooAMSUsage amsUsage = oocAMSPreferred,
	                  ooBoolean installSigHandler = oocTrue);

      // shuts down the connection
      static void shutdown();

      // sets up the current thread to use Objectivity resources
      static void initializeThread();

      // deinitializes Objectivity resources for the current thread
      static void terminateThread();

      // returns the connection for the specified bootfile,
      // creates it if necessary
      static ooConnection* getConnection(const char* bootFile,  
	                                 ooBoolean autoRecover = 
	                                    defaultAutoRecover());

      // sets the default autorecover policy (initially oocTrue)
      static void setDefaultAutoRecover(ooBoolean autoRecover)
      {smDefaultAutoRecover = autoRecover;}

      // returns the currently set default autorecover policy
      static ooBoolean defaultAutoRecover()
      {return smDefaultAutoRecover;}

      // sets the ooTuner that is given a chance to override all performance 
      // related variables.
      // ooObjy takes ownership of the passed in ooTuner and will delete 
      // it at shutdown.
      // you must set the ooTuner before making any other ooObjy calls.
      static void setTuner(ooTuner* tuner);
      // no argument indicates the use of the default environment based tuner
      static void setTuner();

      // returns the currently set tuner
      static ooTuner* tuner()
      {return smTuner;}

      // sets the main log's listener
      static void setMainLogListener(ooLogListener* listener);

      // add a logItem to the end of the main log with given label and text
      static void addToMainLog(const char* label = 0, const char* text = 0);

      // sets the logging options
      static void setLoggingOptions(uint32 options, 
	                            ooBoolean logToFiles, 
	                            ooBoolean appendLogFiles = oocFalse, 
	                            const char* logDirPath = "",
				    const char* mainLogFileName="MainLog.txt");

      // test whether lock server is running on host (defaults to current)
      static ooBoolean checkLS(const char* host = 0);

      // enable checking for missing v-tables
      static void checkVTablePointer (ooBoolean checkVptr = oocTrue)
	  { ooCheckVTablePointer(checkVptr); }

      // return the architecture of the running application
      static ooDiskFormat getClientHostArch();

      // return the disk format corresponding to an installation name string
      static ooDiskFormat diskFormatFromString(const char *str);

      // return the installation name string corresponding to a disk format
      static const char *stringFromDiskFormat(ooDiskFormat mach);

      // return the size in bits of a memory address using the given disk format
      static size_t diskFormatAddressSize(ooDiskFormat mach);

      // parallel query support for custom task assigner
      static void setTaskAssigner(ooTaskAssigner* assigner);
      static ooTaskAssigner* getTaskAssigner();
      static ooBoolean checkQueryServer(const char * hostName);
      static void startInternalQueryServer(unsigned numThreads = 0);

      //internal use for C#
      static ooBoolean isStartupCalled() {return smIsStarted;}

      // Configuration support
      static void enableConfiguration(bool allowMachineConfig, 
                    const char* applicationConfig = 0,
                    unsigned argc = 0,
                    const char* const argv[] = 0);

      friend class ooPerformanceAnalyzer;

   private:

      static void Reset();

      static ooTuner* smTuner;
      static ooContext* smMainContext;

      static ooBoolean smLogOther;
      static ooBoolean smLoggingOptionsSet;
      static ooBoolean smIsStarted;
      static ooBoolean smIsShutdown;
      static ooBoolean smDefaultAutoRecover;

      static void addToLogInternal(const char* label, const char* text,
				   ocmSession* cm_session);
      static ooStatus errorHandler(ooErrorLevel errorLevel, ooError& error,
	                           ooHandle(ooObj)* contextObj,
				   char* errorMsg);

#ifdef OOST_H /* internal */
      static ost_retval 
      delete_connection_entry (char* key, ooConnection* conn, void* arg);
#endif

      ooObjy() {}

#ifndef OO_GNU_CXX /* avoid warning from Gnu compiler */
      ~ooObjy() {}
#endif
};

//-----------------------------------------------------------------------------
class OO_STORAGE_SPECIFIER ooLocalThread
{
   public:
       
      ooLocalThread()
      {
	 ooObjy::initializeThread();
      }
       
     ~ooLocalThread(); // calls ooObjy::terminateThread()
};


#endif

