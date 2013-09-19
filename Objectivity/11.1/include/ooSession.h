//***************************************************************************//
//                                                                           //
//                Copyright © 2000 Objectivity Inc, USA.                     //
//                                                                           //
//    All Rights Reserved. Unauthorized use, duplication or distribution     //
//         of this software, or any portion of it, is prohibited.            //
//                                                                           //
//***************************************************************************//

#ifndef ooSession_h
#define ooSession_h "@(#)$Id$"

#ifndef OO_H
#include "oo.h"
#endif

#ifndef ooSessionData_h
#include "ooSessionData.h"
#endif

#ifndef ooLogListener_h
#include "ooLogListener.h"
#endif

#ifndef ooTransactionListener_h
#include "ooTransactionListener.h"
#endif

#ifndef OO_BASE_H
#include "ooBase.h"
#endif

class OO_STORAGE_SPECIFIER ooConnection;
class ooConnectionImp;
class ooSessionPoolBase;
class OO_STORAGE_SPECIFIER ooObjy;
class OO_STORAGE_SPECIFIER ooSessionImp;
class ooLog;

extern OO_STORAGE_SPECIFIER ooGlobalTransStatusFunc NETglobalTransStatusFunc;

//-----------------------------------------------------------------------------
class OO_STORAGE_SPECIFIER ooSession
{
   public:

      ~ooSession();

      // returns a handle to the federated database
      ooHandle(ooFDObj)& fd();

      // returns the session's transaction
      ooTrans& trans();

      // starts a transaction with given parameters if not a nested call, 
      // else increases nest count
      void begin(ooMode openMode, 
	         ooMode mrowMode = defaultMrowMode(), 
	         ooIndexMode indexMode = defaultIndexMode());

      // checkpoints the transaction
      void checkpoint(ooDowngradeMode downgradeMode = defaultDowngradeMode());
      
      // commits the transaction if not a nested call, 
      // else decreases nest count
      void commit();

      // aborts the transaction if active
      void abort(ooHandleMode mode = defaultAbortMode());

      // upgrades the current open mode to oocUpdate
      void upgradeOpenMode();

      // Force recovery of transactions from crashed clients;
      // use this only when not in a transaction.
      void recover(ooGlobalTransStatusFunc statusFunc = 0);

      // returns the current nest count
      // (0 => no transaction, 1 => top-level trans., >1 => nested trans.)
      uint32 nestCount() const;

      // returns true if a transaction is active
      ooBoolean haveActiveTransaction() const;

      // returns the current transaction ID number
      ooTransId getTransactionID() const;

      // sets the lock wait value for this session (seconds or oocWait)
      void setLockWait(int32 lockWait);

      // gets the lock wait value set for this session
      int32 getLockWait() const;
      
      // returns the current open mode
      ooMode currentOpenMode() const;

      // returns the current MROW mode
      ooMode currentMrowMode() const;

      // sets page buffer parameters
      void setBufferSpace( unsigned page_size, size_t initial_page_space,
			   size_t maximum_page_space,
			   unsigned initial_large_objects,
			   unsigned maximum_large_objects );

      // enables non-quorum read for all databases
      void setAllowNonQuorumRead();

      // sets the log's listener
      void setLogListener(ooLogListener* listener);

      // add a logItem to the end of the log with given label and text
      void addToLog(const char* label = 0, const char* text= 0);

      // adds Listener to be notified of transaction events
      void addTransactionListener(ooTransactionListener* listener);

      // removes Listener from the transaction subscriber list
      void removeTransactionListener(ooTransactionListener* listener);

      // set data as the user defined data for the current ooSession
      void setSessionData(const char* name, ooSessionData* sessionData);

      // get the user defined data for the current ooSession
      ooSessionData* getSessionData(const char* name) const;

      // starts the general purpose timer
      // adds a log item indicating its start into the log
      void startTimer();

      // stops the general purpose timer
      // adds a log item indicating its value into the log
      void stopTimer();

      // gets counts from Objectivity kernel
      // adds start indication to the log
      void startStatistics();

      // add a log item representing delta statistics from start to the log
      void stopStatistics();

      // attach the ooSession to the current thread
      void attach();

      // detach the ooSession from the current thread
      void detach();

      // attach the session to the current thread. add to log if enabled
      void attach(ooBoolean addToLog);

      // detach the session from the current thread. add to log if enabled
      void detach(ooBoolean addToLog);

      // returns true if some thread is attached to this session.
      ooBoolean isAttached() const;

      // Allow multiple threads to share the same current session.
      // (Dangerous; don't use this unless you know what you're doing.)
      void join();
      void leave();

      // returns the connection that created this session
      ooConnection* getConnection() const;

      // returns the name given this ooSession
      const char* name() const;

      // returns true if this session was originally obtained from a pool
      ooBoolean obtainedFromSessionPool() const;

      // returns the name of the pool this ooSession belongs to 
      // or "" if it is not pooled
      const char* poolName() const;

      // returns the session back to its pool    
      void returnSessionToPool();
      
      // returns the bootfile
      const char* bootFile() const;

      // returns the ooSession for the current thread
      static ooSession* getCurrent();

      // if true, then scan will use indexes when available
      void setUseIndex(ooBoolean useIndex);

      // sets the timeout value used when communicating with the 
      // AMS or lock servers
      void setServerTimeout(int seconds);

      // gets server timeout value in seconds
      int  getServerTimeout() const;

      // returns the region number of the federation being accessed.
      unsigned int get_region() const;

      // get or change the default cluster strategy
      ooClusterStrategy* clusterStrategy() const;
      ooClusterStrategy* setClusterStrategy(ooClusterStrategy* strategy);

      // get or change the function for handling warning messages
      ooMsgHandlerPtr & getMsgHandler () const;
      ooMsgHandlerPtr regMsgHandler (ooMsgHandlerPtr nameOfMsgHandler);

      // set pathname for the warning message file of the default handler
      void setErrorFile (const char* nameOfErrorFile);

      // register handler function for two-machine fail-over
      void regTwoMachineHandler (ooTwoMachineHandlerPtr funct);

      // get or change the offline enforcement status
      void setOfflineMode (ooOfflineMode offlineMode);
      ooOfflineMode getOfflineMode () const;

      // set number of retries for network connection failure
      void setConnectRetries (unsigned int retries);

      // initialize for a schema upgrade transaction
      void setSchemaUpgradeMode ();


      // sets the default MROW mode (initially oocNoMROW)
      static void setDefaultMrowMode(ooMode defaultMrowMode)
      {smDefaultMrowMode = defaultMrowMode;}

      // returns the default MROW mode 
      static ooMode defaultMrowMode()
      {return smDefaultMrowMode;}

      // sets the default Index mode (initially oocInsensitive)
      static void setDefaultIndexMode(ooIndexMode defaultIndexMode)
      {smDefaultIndexMode = defaultIndexMode;}

      // returns the default Index mode 
      static ooIndexMode defaultIndexMode()
      {return smDefaultIndexMode;}

      // sets the default Downgrade mode (initially oocNoDowngrade) 
      static void setDefaultDowngradeMode(ooDowngradeMode defaultDowngradeMode)
      {smDefaultDowngradeMode = defaultDowngradeMode;}

      // returns the default Downgrade mode 
      static ooDowngradeMode defaultDowngradeMode()
      {return smDefaultDowngradeMode;}

      // sets the default Abort mode (initially oocHandleToNull)
      static void setDefaultAbortMode(ooHandleMode defaultAbortMode)
      {smDefaultAbortMode = defaultAbortMode;}

      // returns the default Abort mode
      static ooHandleMode defaultAbortMode()
      {return smDefaultAbortMode;}

      // sets the default use index mode (initially oocFalse)
      static void setDefaultUseIndex(ooBoolean defaultUseIndex);

      // returns the default use index mode
      static ooBoolean defaultUseIndex();

      // sets the default server timeout value (initially 25)
      static void setDefaultServerTimeout(int seconds);

      // returns the default server timeout value
      static int defaultServerTimeout();

      // registers the event listener
      void setEventListener(ooEventListener *);

     // close physical files for databases no longer open
     void releaseFiles();

      ooStatus snapShot(unsigned info = oocAllInfo,
        ooInfoFormat format = oocReadable,
        FILE *filePtr = stdout,
        ooBoolean onException = oocTrue,
        ooSortOrder sort = oocAscending,
        const ooId& scope = oocNullId);

     int joinCount() const;     

      // sets/gets the sessions file sync policy allowing the
      //   user to suppress fsync on both db and jnl files
      void setNoSync(ooBoolean noSync);
      ooBoolean getNoSync();

   private:
      static void reset(); 
      static ooMode smDefaultMrowMode;
      static ooIndexMode smDefaultIndexMode;
      static ooDowngradeMode smDefaultDowngradeMode;
      static ooHandleMode smDefaultAbortMode;

      ooSessionImp* mSessionImp;
   
	   ooSession(ooConnection* connection, const char* bootfile, 
	        const char* name, ooSessionPoolBase* sessionPool, 
	        uint32 cacheInitialPages, uint32 cacheMaxPages, 
	        uint32 largeObjectMemoryLimit, ooBoolean hotMode, 
	        int32 lockWait);

      // returns the tag value given to support biased pool retrieval
      const char* tag() const;
      
      // sets the tag value used to support biased pool retrieval
      void setTag(const char* value);

      ooLog* log() const;

      friend class ooSessionPool;
      friend class ooConnectionImp;
      friend class ooObjy;
      friend class ooSessionImp;
 
   public:
      ocmSession* getKernelSession() const; // for internal use

#ifdef __cplusplus_cli
    friend  class ooNETSessionFriend;
#endif        
};

//-----------------------------------------------------------------------------
class OO_STORAGE_SPECIFIER ooLocalSessionUse
{
   public:
      
      ooLocalSessionUse(ooSession* session);     
      ~ooLocalSessionUse();

   private:

      ooSession* mSession;
      ocmSession* mOuterSession;
      ocmSession* mInnerSession;
};


#endif

