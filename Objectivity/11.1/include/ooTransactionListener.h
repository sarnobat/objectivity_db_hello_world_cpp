//***************************************************************************//
//                                                                           //
//                Copyright © 2000 Objectivity Inc, USA.                     //
//                                                                           //
//    All Rights Reserved. Unauthorized use, duplication or distribution     //
//         of this software, or any portion of it, is prohibited.            //
//                                                                           //
//***************************************************************************//

// "@(#)$Id$"

#ifndef ooTransactionListener_h
#define ooTransactionListener_h

#ifndef OO_H
#include <oo.h>
#endif

//-----------------------------------------------------------------------------
class OO_STORAGE_SPECIFIER ooTransactionListener
{
   public:

      // called when ooSession::begin is called 
      virtual void onTransactionBegin(uint32 /* nestCount */,
				      ooMode /* openMode */, 
				      ooMode /* mrowMode */,
				      ooIndexMode /* indexMode */) {}

      // called when the transaction has actually begun
      virtual void onTransactionBegun(ooTransId /* transactionId */) {}

      // called when open mode upgrade is requested
      virtual void onOpenModeUpgrade(uint32 /* nestCount */, 
				     ooBoolean /* activeTransaction */) {}

      // called when open mode has been upgraded from oocRead to oocUpdate
      virtual void onOpenModeUpgraded() {}

      // called when ooSession::checkpoint is called
      virtual void onTransactionCheckpoint(uint32 /* nestCount */, 
	                                   ooBoolean /* activeTransaction */,
	                                   ooDowngradeMode /* downgradeMode */)
		{}

      // called when the transaction has actually been checkpointed
      virtual void onTransactionCheckpointed() {}

      // called when ooSession::commit is called
      virtual void onTransactionCommit(uint32 /* nestCount */,
	                               ooBoolean /* activeTransaction */) {}

      // called when the transaction has actually been committed
      virtual void onTransactionCommitted() {}

      // called when ooSession::abort is called
      virtual void onTransactionAbort(uint32 /* nestCount */,  
	                              ooBoolean /* activeTransaction */, 
	                              ooHandleMode /* mode */) {}

      // called when the transaction has actually been aborted
      virtual void onTransactionAborted() {}

      // called whenever the transaction has been committed, checkpointed
      // or aborted
      virtual void onTransactionFinished(ooBoolean /* commited */) {}

      // returns this listener's priority
      unsigned priority() const
      {return mPriority;}

   protected:

      // priority (highest == 0) determines order of notification; 
      // higher priority listeners are notified before lower.
      ooTransactionListener(uint32 priority) 
	 : mPriority(priority) { mNext = NULL; }

   private:

      uint32 mPriority;

      ooTransactionListener* mNext;
	            
   friend class ooTransactionListenerRegistry;
};

#endif

