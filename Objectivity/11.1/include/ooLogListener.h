//***************************************************************************//
//                                                                           //
//                Copyright © 2000 Objectivity Inc, USA.                     //
//                                                                           //
//    All Rights Reserved. Unauthorized use, duplication or distribution     //
//         of this software, or any portion of it, is prohibited.            //
//                                                                           //
//***************************************************************************//

// "@(#)$Id$"

#ifndef ooLogListener_h
#define ooLogListener_h

#include <ooConfig.h> // for OO_STORAGE_SPECIFIER

//-----------------------------------------------------------------------------

class ooLogBase;
class ooLog;

//-----------------------------------------------------------------------------
class OO_STORAGE_SPECIFIER ooLogListener
{
   public:

      // called whenever a log item is added to registered with log
      virtual void onLogItem(long timeStamp, const char* label, 
	                     const char* text) = 0;

      virtual ~ooLogListener();

   protected:

      ooLogListener();

   private:

      ooLogBase* mLog;

      void setLog(ooLogBase* log);

      friend class ooLog;
};

#endif

