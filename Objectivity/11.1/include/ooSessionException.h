//***************************************************************************//
//                                                                           //
//                Copyright © 2000 Objectivity Inc, USA.                     //
//                                                                           //
//    All Rights Reserved. Unauthorized use, duplication or distribution     //
//         of this software, or any portion of it, is prohibited.            //
//                                                                           //
//***************************************************************************//

// "@(#)$Id$"

#ifndef ooSessionException_h
#define ooSessionException_h

#include <ooException.h>

//The following error numbers are used (-100 to -111)

//-----------------------------------------------------------------------------

class OO_STORAGE_SPECIFIER ooSessionException : public ooException
{
   protected:

      ooSessionException() {}

   public:
      virtual int get_kind() const { return -100; }
};

//-----------------------------------------------------------------------------
class OO_STORAGE_SPECIFIER ooObjyAlreadyStarted : public ooSessionException
{
   public:

      ooObjyAlreadyStarted();

      virtual const char* what() const OO_WHAT_THROW_NONE;
      virtual int get_kind() const { return -111; }
};

//-----------------------------------------------------------------------------
class OO_STORAGE_SPECIFIER ooObjyNotStarted : public ooSessionException
{
   public:

      ooObjyNotStarted();

      virtual const char* what() const OO_WHAT_THROW_NONE;
};

//-----------------------------------------------------------------------------
class OO_STORAGE_SPECIFIER ooObjyStarted : public ooSessionException
{
   public:

      ooObjyStarted();

      virtual const char* what() const OO_WHAT_THROW_NONE;
};

//-----------------------------------------------------------------------------
class OO_STORAGE_SPECIFIER ooObjyShutdown : public ooSessionException
{
   public:

      ooObjyShutdown();

      virtual const char* what() const OO_WHAT_THROW_NONE;
};

//-----------------------------------------------------------------------------
class OO_STORAGE_SPECIFIER ooTunerNotSetFirst : public ooSessionException
{
   public:

      ooTunerNotSetFirst();

      virtual const char* what() const OO_WHAT_THROW_NONE;
};

//-----------------------------------------------------------------------------
class OO_STORAGE_SPECIFIER ooDuplicateSessionPoolName : public ooSessionException
{
   public:

      ooDuplicateSessionPoolName();

      virtual const char* what() const OO_WHAT_THROW_NONE;
      virtual int get_kind() const { return -103; }
};

//-----------------------------------------------------------------------------
class OO_STORAGE_SPECIFIER ooSessionPoolNotFound : public ooSessionException
{
   public:

      ooSessionPoolNotFound();

      virtual const char* what() const OO_WHAT_THROW_NONE;
      virtual int get_kind() const { return -104; }
};

//-----------------------------------------------------------------------------
class OO_STORAGE_SPECIFIER ooReturningActiveSessionToPool : public ooSessionException
{
   public:

      ooReturningActiveSessionToPool();

      virtual const char* what() const OO_WHAT_THROW_NONE;
      virtual int get_kind() const { return -105; }
};

//-----------------------------------------------------------------------------
class OO_STORAGE_SPECIFIER ooTooManySessions : public ooSessionException
{
   public:

      ooTooManySessions();

      virtual const char* what() const OO_WHAT_THROW_NONE;
      virtual int get_kind() const { return -106; }
};

//-----------------------------------------------------------------------------
class OO_STORAGE_SPECIFIER ooSessionDataNotFound : public ooSessionException
{
   public:

      virtual const char* what() const OO_WHAT_THROW_NONE;
      virtual int get_kind() const { return -102; }
};

//-----------------------------------------------------------------------------
class OO_STORAGE_SPECIFIER ooThreadAlreadyHasASession : public ooSessionException
{
   public:

      virtual const char* what() const OO_WHAT_THROW_NONE;
      virtual int get_kind() const { return -107; }
};

//-----------------------------------------------------------------------------
class OO_STORAGE_SPECIFIER ooSessionAlreadyAttached : public ooSessionException
{
   public:

      virtual const char* what() const OO_WHAT_THROW_NONE;
      virtual int get_kind() const { return -108; }
};

//-----------------------------------------------------------------------------
class OO_STORAGE_SPECIFIER ooSessionAlreadyDetached : public ooSessionException
{
   public:

      virtual const char* what() const OO_WHAT_THROW_NONE;
      virtual int get_kind() const { return -109; }
};

//-----------------------------------------------------------------------------
class OO_STORAGE_SPECIFIER ooSessionAttachedToOtherThread : public ooSessionException
{
   public:

      virtual const char* what() const OO_WHAT_THROW_NONE;
      virtual int get_kind() const { return -110; }
};

//-----------------------------------------------------------------------------
class OO_STORAGE_SPECIFIER ooTransactionListenerNotFound : public ooSessionException
{
   public:

      virtual const char* what() const OO_WHAT_THROW_NONE;
};

//-----------------------------------------------------------------------------
class OO_STORAGE_SPECIFIER ooLogOpenFailed : public ooSessionException
{
   private:
      char message [300];
   public:
      // forLogFile flag will allow using this exception for
      // issues with the log dir path. - SPR 18843
      ooLogOpenFailed(const char* path, int error, bool forLogFile=true);
      virtual const char* what() const OO_WHAT_THROW_NONE;
      virtual int get_kind() const { return -101; }
};

#endif

