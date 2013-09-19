//***************************************************************************//
//                                                                           //
//                Copyright © 2000, 2001 Objectivity Inc, USA.               //
//                                                                           //
//    All Rights Reserved. Unauthorized use, duplication or distribution     //
//         of this software, or any portion of it, is prohibited.            //
//                                                                           //
//***************************************************************************//

#ifndef ooConnection_h
#define ooConnection_h "@(#)$Id$"

#ifndef OO_H
#include "oo.h"
#endif

class OO_STORAGE_SPECIFIER ooSession;
class OO_STORAGE_SPECIFIER ooObjy;
class OO_STORAGE_SPECIFIER ooTuner;
class ooConnectionImp;

//-----------------------------------------------------------------------------
class OO_STORAGE_SPECIFIER ooConnection
{
   public:

      // create a ooSession pool with the specified parameters to be used 
      // by all pooled Sessions. 
      void createSessionPool(const char* sessionPoolName, 
	                     unsigned softLimit,
	                     unsigned hardLimit,
	                     uint32 cacheInitialPages = 200, 
	                     uint32 cacheMaxPages = 500, 
	                     uint32 largeObjectMemoryLimit = 0, // 0 => default
	                     ooBoolean hotMode = oocFalse, 
	                     int   lockWait = oocNoWait,
			     int   sessionWait = oocNoWait /* seconds */);

      // Test is a session pool with sessionPoolName already exists.
      bool haveSessionPool(const char* sessionPoolName);

      // create a ooSession with specified parameters
      ooSession* createSession(const char* name, 
	                       uint32 cacheInitialPages = 200, 
	                       uint32 cacheMaxPages = 500, 
	                       uint32 largeObjectMemoryLimit = 0,// 0=>default
	                       ooBoolean hotMode = oocFalse, 
	                       int32 lockWait = oocNoWait);

      // Returns an ooSession obtained from the specified pool.
      // If tag is non null and there is an available session with the 
      // specified tag value, then it will be returned, else the most 
      // recently used available session will be returned, else a session 
      // will be created and returned.
      // The returned session's tag value will be set to 'tag'.
      ooSession* getSessionFromPool(const char* sessionPoolName, 
	                            const char* tag = 0);

      // returns a session obtained from a pool back to that pool
      void returnSessionToPool(ooSession* session);
      
      // returns the connection's boot file path
      const char* bootFile() const;

      // start internal lock server
      void startInternalLS(void (*threadfn)() = 0);

      // stop internal lock server
      ooBoolean stopInternalLS(int wait = (int)(((unsigned)~0)>>1), // INT_MAX
			       ooBoolean force = oocFalse);

      // test whether this federation's lock server is running
      ooBoolean checkLS();

      // run without using a lock server (dangerous!)
      void noLock ();

      // specify the owning architecture for pages created
      void setObjectCreationDiskFormat(ooDiskFormat mach);

      // return the owning architecture for pages created
      ooDiskFormat getObjectCreationDiskFormat();

      // For internal use only:
      void doAutoRecover(ocmSession* kernelSession);

   private:

      ooConnectionImp* mConnectionImp;

      ooConnection(const char* bootFile, ooTuner* tuner, 
	           ooBoolean autoRecover);

      ~ooConnection();

      friend class ooObjy;

};

#endif

