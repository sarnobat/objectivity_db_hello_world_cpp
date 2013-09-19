//***************************************************************************//
//                                                                           //
//                Copyright © 2000 Objectivity Inc, USA.                     //
//                                                                           //
//    All Rights Reserved. Unauthorized use, duplication or distribution     //
//         of this software, or any portion of it, is prohibited.            //
//                                                                           //
//***************************************************************************//

// "@(#)$Id$"

#ifndef ooStatistics_h
#define ooStatistics_h

#ifndef ooInternalStatistics_h
#include "ooInternalStatistics.h"
#endif

class ooLog;
class OO_STORAGE_SPECIFIER ooSession;

//-----------------------------------------------------------------------------
class OO_STORAGE_SPECIFIER ooStatistics
{
   public:

      ooStatistics();
      ooStatistics(const ooSession* session);

      // gets counts from Objectivity kernal 
      // call before using cumulative or delta results
      void update();

      // reports all counts between the last two calls to update()
      void addDeltaToLog(ooLog* log, const char* label) const;

      // reports all counts from beginning
      void addCumulativeToLog(ooLog* log, const char* label) const;

      // returns the cumulative statistics object
      const ooInternalStatistics& cumulative() const
      {return mcumulative;}

      // returns the delta statistics object
      const ooInternalStatistics& delta() const
      {return mDelta;}
      
   private:

      ooInternalStatistics mcumulative;
      ooInternalStatistics mDelta;
      ocmSession*  mKernelSession;

   public:  // the following are for internal use
      ooStatistics(ocmSession* cm_session);
      void update(ocmSession* cm_session);
};

#endif

