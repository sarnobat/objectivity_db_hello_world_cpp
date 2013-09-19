//***************************************************************************//
//                                                                           //
//                Copyright © 2000 Objectivity Inc, USA.                     //
//                                                                           //
//    All Rights Reserved. Unauthorized use, duplication or distribution     //
//         of this software, or any portion of it, is prohibited.            //
//                                                                           //
//***************************************************************************//

// "@(#)$Id$"

#ifndef ooTuner_h
#define ooTuner_h

#ifndef OO_H
#include "oo.h"
#endif

//-----------------------------------------------------------------------------
class OO_STORAGE_SPECIFIER ooTuner
{
   public:

      virtual ~ooTuner() {}

      virtual uint32 numberOfFiles(uint32 current)
      {return current;}

      virtual ooAMSUsage amsUsage(ooAMSUsage current)
      {return current;}

      virtual ooBoolean useIndex(ooBoolean current)
      {return current;}
      
      virtual ooIndexMode indexMode(ooIndexMode current)
      {return current;}

      virtual uint32 cacheInitialPages(uint32 current)
      {return current;}

      virtual uint32 cacheMaxPages(uint32 current)
      {return current;}

      virtual uint32 largeObjectMemoryLimit(uint32 current)
      {return current;}

      virtual ooBoolean hotMode(ooBoolean current)
      {return current;}

      virtual int32 lockWait(int32 current)
      {return current;}

      virtual ooBoolean appendLogs(ooBoolean current)
      {return current;}

      virtual const char* logDirectory(const char* current)
      {return current;}

      virtual unsigned sessionPoolSoftLimit(const char* /* sessionPoolName */, 
	                                    unsigned current)
      {return current;}

      virtual uint32 poolSessionCacheInitialPages(const char* /* sessionPoolName */, 
	                                          uint32 current)
      {return current;}

      virtual uint32 poolSessionCacheMaxPages(const char* /* sessionPoolName */, 
	                                      uint32 current)
      {return current;}

      virtual uint32 poolSessionLargeObjectMemoryLimit
	 (const char* /* sessionPoolName */, uint32 current)
      {return current;}

      virtual ooBoolean poolSessionHotMode(const char* /* sessionPoolName */, 
	                                  ooBoolean current)
      {return current;}

      virtual int poolSessionLockWait(const char* /* sessionPoolName */, 
				      int current)
      {return current;}

      // Maximum number of sessions
      virtual unsigned sessionPoolHardLimit(const char* /* sessionPoolName */, 
	                                    unsigned current)
      {return current;}

      // Timeout, in seconds, when waiting for an available session when
      // the hard limit is reached, before ooTooManySessions is thrown.
      virtual int sessionPoolWait(const char* /* sessionPoolName */,
				  int current)
      {return current;}

      // Option bits for ooObjy::setLoggingOptions
      virtual int logOptions(int current) { return current; }

   protected:

      ooTuner() {}

};

#endif

