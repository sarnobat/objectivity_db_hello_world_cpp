//***************************************************************************//
//                                                                           //
//                Copyright © 2000 Objectivity Inc, USA.                     //
//                                                                           //
//    All Rights Reserved. Unauthorized use, duplication or distribution     //
//         of this software, or any portion of it, is prohibited.            //
//                                                                           //
//***************************************************************************//

// "@(#)$Id$"

#ifndef ooEnvironmentBasedTuner_h
#define ooEnvironmentBasedTuner_h

#ifndef ooTuner_h
#include "ooTuner.h"
#endif

//-----------------------------------------------------------------------------
class OO_STORAGE_SPECIFIER ooEnvironmentBasedTuner : public ooTuner
{
   public:

      virtual uint32 numberOfFiles(uint32 current);
      virtual ooAMSUsage amsUsage(ooAMSUsage current);
      virtual ooBoolean useIndex(ooBoolean current);
      virtual ooIndexMode indexMode(ooIndexMode current);

      virtual uint32 cacheInitialPages(uint32 current);
      virtual uint32 cacheMaxPages(uint32 current);
      virtual uint32 largeObjectMemoryLimit(uint32 current);
      virtual ooBoolean hotMode(ooBoolean current);
      virtual int32 lockWait(int32 current);
 
      virtual ooBoolean appendLogs(ooBoolean current);
      virtual const char* logDirectory(const char* current);
      virtual int logOptions(int current);

      virtual unsigned sessionPoolSoftLimit(const char* contextPoolName, 
	                                    unsigned current);
      virtual uint32 poolSessionCacheInitialPages(const char* contextPoolName, 
	                                          uint32 current);
      virtual uint32 poolSessionCacheMaxPages(const char* contextPoolName, 
	                                      uint32 current);
      virtual uint32 poolSessionLargeObjectMemoryLimit
	 (const char* contextPoolName, uint32 current);
      virtual ooBoolean poolSessionHotMode(const char* contextPoolName, 
	                                   ooBoolean current);
      virtual int poolSessionLockWait(const char* contextPoolName, 
				      int current);
      virtual unsigned sessionPoolHardLimit(const char* sessionPoolName, 
	                                    unsigned current);
      virtual int sessionPoolWait(const char* sessionPoolName, 
				  int current);
};

#endif

