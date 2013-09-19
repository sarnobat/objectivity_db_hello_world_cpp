//***************************************************************************//
//                                                                           //
//                Copyright © 2000 Objectivity Inc, USA.                     //
//                                                                           //
//    All Rights Reserved. Unauthorized use, duplication or distribution     //
//         of this software, or any portion of it, is prohibited.            //
//                                                                           //
//***************************************************************************//

// "@(#)$Id$"

#ifndef ooSessionData_h
#define ooSessionData_h

class OO_STORAGE_SPECIFIER ooSessionImp;

//-----------------------------------------------------------------------------
class OO_STORAGE_SPECIFIER ooSessionData
{
   public:

      virtual ~ooSessionData();
    
      ooBoolean isSessionOwned() const
      {return mIsSessionOwned;} 
   
   protected:

      ooSessionData(ooBoolean isSessionOwned = oocTrue);

   private:

      friend class ooSessionImp;

      void setSession(ooSessionImp * session);

      ooBoolean mIsSessionOwned;
      ooSessionImp * mSession;

 };

#endif

