//***************************************************************************//
//                                                                           //
//                Copyright © 2005 Objectivity Inc, USA.                     //
//                                                                           //
//    All Rights Reserved. Unauthorized use, duplication or distribution     //
//         of this software, or any portion of it, is prohibited.            //
//                                                                           //
//***************************************************************************//

#ifndef ReferenceCounted_h
#define ReferenceCounted_h

#include "ObjectQualificationSS.h"

namespace objy {namespace query
{

//-----------------------------------------------------------------------------
class OQ_STORAGE_SPECIFIER ReferenceCounted
{
   public:

      // Constructor
      ReferenceCounted();

      // Destructor
      virtual ~ReferenceCounted();

      // Adds a reference.
      // If this is the first ref added then firstRefAdded is called.
      int16 addRef();

      // Removes a reference.
      // If this is the last ref, then release is called.
      int16 removeRef();

      // Returns true if there is more than one reference; false otherwise.
      bool isShared() const;

      // Returns the current number of user counts
      int16 getUserCount() const
      { return mUserCount; }

   protected:

      // Called when ther last ref has been removed.
      virtual void release();

   private:
      volatile int16 mUserCount;

      // TODO: consider using a light weight thread safety library, like the interlock
      // provided on Windows
	    //CCriticalSection mReferenceCountedMutex;

};

//-----------------------------------------------------------------------------
template <class T> class ReferenceCountedHandle
{
  public:

    ReferenceCountedHandle()
      : mReferenceCounted(0)
    {
    }

    ReferenceCountedHandle(T* referenceCounted)
      : mReferenceCounted(referenceCounted)
    {
      if (mReferenceCounted)
      {
        mReferenceCounted->addRef();
      }
    }

    ReferenceCountedHandle(const ReferenceCountedHandle& other)
      : mReferenceCounted(other.mReferenceCounted)
    {
      if (mReferenceCounted)
      {
        mReferenceCounted->addRef();
      }
    }

    ~ReferenceCountedHandle()
    {
      if (mReferenceCounted)
      {
        mReferenceCounted->removeRef();
      }
    }

    ReferenceCountedHandle& operator=(const ReferenceCountedHandle& other)
    {
      if (&other != this) 
      {
        if (mReferenceCounted)
        {
          mReferenceCounted->removeRef();
        }
        mReferenceCounted = other.mReferenceCounted;
        if (mReferenceCounted)
        {
          mReferenceCounted->addRef();
        }
      }
      return *this;
    }

    ReferenceCountedHandle& operator=(T* referenceCounted)
    {
      if (mReferenceCounted != referenceCounted)
      {
        if (mReferenceCounted)
        {
          mReferenceCounted->removeRef();
        }
        mReferenceCounted = referenceCounted;
        if (mReferenceCounted)
        {
          mReferenceCounted->addRef();
        }
      }
      return *this;
    }

    operator const T*() const
    {return mReferenceCounted;}

    operator T*()
    {return mReferenceCounted;}

    T* operator->()
    {return mReferenceCounted;}

    const T* operator->() const
    {return mReferenceCounted;}

    bool isNull() const
    {return mReferenceCounted == 0;}

    bool operator == (const ReferenceCountedHandle& other) const
    {return mReferenceCounted == other.mReferenceCounted;}

  private:

    T* mReferenceCounted;
};

}/* end query namespace */} /* end objy namespace */

#endif
