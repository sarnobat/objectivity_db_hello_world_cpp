/**************************************************************************
		    Copyright (c) 1989-2000 Objectivity, Inc.
			  All Rights Reserved	

	THIS IS UNPUBLISHED PROPRIETARY SOURCE CODE OF OBJECTIVITY, INC.
	
	The copyright notice above does not evidence any	
	actual or intended publication of such source code.

*****************************************************************************/

#ifndef OO_EXCEPTION_H
#define OO_EXCEPTION_H "@(#)$Id$"

#if defined(__cplusplus) && !defined(OO_BASE_H) && !defined(OOSRCID)
// Allow users to include this file before oo.h without getting errors.
// Internal files should include ooBase.h first if oo.h isn't wanted.
#include <oo.h>
#endif
#include <ooError.h>

#ifdef OO_DEC_CXX
 // Changing the name of this before including <exception> so that we can
 // define it ourselves to work around an incompatibility between Compaq
 // version 4 and 5 C++ libraries without getting multiple definitions
 // in links. (ref SPR 15693).
 #define __rw_stdexcept_NoNamedException OO_NO_NAMED_EXCEPTION_HACK
#endif

#if defined(OO_SOLARIS) || defined(OO_AIX) || defined(OO_LYNXOS) || defined(OO_ALTIX)
 // Only for old compilers which don't support <exception>
 #define OO_EXCEPTION_BASE
 #define ooBaseException ooException
#elif defined(OO_NO_EXCEPTION_BASE)
 // For applications using an incompatible implementation of std::exception.
 // This hack was done in 2001 and is most likely never needed now.
 #include <exception>
 class replacingStdException {
     virtual void ____method() {;}
#if defined(OO_NT)
     // NT adds physical members
     char ____mem[sizeof(std::exception) - sizeof(void *)];
#endif
 };
 #define OO_EXCEPTION_BASE : replacingStdException
 #define ooBaseException ooException
#else
 // This is the normal case used on all currently supported platforms.
 #include <exception>
 #define OO_EXCEPTION_BASE : public std::exception
 typedef std::exception ooBaseException;
#endif

#if defined(OO_SOLARIS) || defined(OO_AIX)
 #define OO_WHAT_THROW_NONE
#else
 #define OO_WHAT_THROW_NONE throw()
#endif

#ifdef __cplusplus

OO_STORAGE_SPECIFIER int oehExceptionHack(int); // internal use only

class OO_STORAGE_SPECIFIER ooKernelException;

OO_CLI_PUBLIC
class OO_STORAGE_SPECIFIER ooException OO_EXCEPTION_BASE
{
 private:
  static ooBoolean _enabled;
 public:
  virtual const char* what() const OO_WHAT_THROW_NONE = 0;
  virtual operator const char *() const{ return what(); }
  virtual int get_kind() const { return -1; }  // ODMG compatibility
  virtual void reportErrors(const char* context = 0) const throw();
  virtual const ooKernelException* asKernelException() const throw()
    { return NULL; }
  static void enable();
  static ooBoolean enabled();
  static ooBoolean enabled(ocmSession*);
  static void setEnabled(ocmSession*, bool);

  friend OO_STORAGE_SPECIFIER int oehExceptionHack(int); // internal use only
};

typedef ooException d_Error; // ODMG compatibility

OO_CLI_PUBLIC
class OO_STORAGE_SPECIFIER ooSimpleException : public ooException
{
  const char* _what;
 public:
  ooSimpleException(const char* what=0): _what(what) {}
  const char* what() const OO_WHAT_THROW_NONE { return _what; }
};

OO_CLI_PUBLIC
class OO_STORAGE_SPECIFIER ooKernelException : public ooException
{
 protected:
  uint32 _sessionId;
// private:
//  ooKernelException& operator=(const ooKernelException&); // alternate approach to avoid warning C4512 (Windows)
 public:
  ooKernelException(ocmSession* session, int index);
  int noOfErrors; // max OO_MAX_REPORTED_ERRORS will be reported
  int exceptionErrorIndex; //  remove "const" to avoid warning C4512 (Windows)
  const ooErrorInfo* errorInfo() const;
  const char* what() const OO_WHAT_THROW_NONE;
  int get_kind() const; // ODMG compatibility
  void reportErrors(const char* context = 0) const throw();
  const ooKernelException* asKernelException() const throw() { return this; }
  const ooErrorInfo* errorInfo(int index) const;
  const ooId* contextOID() const; // OID associated with operation
  const ooId* errorOID() const;   // OID associated with error
};

class OO_STORAGE_SPECIFIER ooNetworkException : public ooKernelException
{
 public:
  ooNetworkException(ocmSession* session, int index) : ooKernelException(session, index) {}
};

class OO_STORAGE_SPECIFIER ooNoQuorumException : public ooNetworkException
{
 public:
  ooNoQuorumException(ocmSession* session, int index) : ooNetworkException(session, index) {}
};

// Lock Conflict Information
enum ooResourceType {
    oocFederation = 0,
    oocDatabase   = 1,
    oocContainer  = 2
};

struct ooLockStatEntry {
    char            *hostName;
    ooUInt32        userID;
    ooInt32         processID;
    ooTransId       transactionID;
    ooResourceType  resourceType;
    ooId            oid;          // object identifier
    ooLockMode      mode;         // lock mode
};

struct ooConflictInfo {
    ooUInt32        federationID;
    ooId            oid;          // object identifier
    ooMode          mode;         // open mode
    unsigned int    count;        // number of enteries in ooLockStatEntry
    ooLockStatEntry *pLsEntry;    // pointer to ooLockStatEntry structure
};

class OO_STORAGE_SPECIFIER ooLockConflictException : public ooKernelException
{
 private:
  static ooBoolean _enabled; // Default oocTrue -- exception will be thrown.
 public:
  static void disable() { _enabled = oocFalse; }
  static ooBoolean enabled() { return _enabled; }
  ooLockConflictException(ocmSession* session, int index) : ooKernelException(session, index) {}
  static void enableConflictInfo(ooBoolean mode);	// enable/disable lock conflict info
  ooConflictInfo *getConflictInfo () const; // get lock conflict information
};

class OO_STORAGE_SPECIFIER ooCannotUpgradeLockException : public ooLockConflictException
{
 public:
  ooCannotUpgradeLockException(ocmSession* session, int index) : ooLockConflictException(session, index) {}
};

class OO_STORAGE_SPECIFIER ooDeadlockException : public ooLockConflictException
{
 public:
  ooDeadlockException(ocmSession* session, int index): ooLockConflictException(session, index) {}
};

class OO_STORAGE_SPECIFIER ooOutOfException : public ooKernelException
{
 public:
  ooOutOfException(ocmSession* session, int index): ooKernelException(session, index) {}
};

class OO_STORAGE_SPECIFIER ooOutOfContainerIDsException : public ooOutOfException
{
 public:
  ooOutOfContainerIDsException(ocmSession* session, int index): ooOutOfException(session, index) {}
};

class OO_STORAGE_SPECIFIER ooOutOfDiskSpaceException : public ooOutOfException
{
 public:
  ooOutOfDiskSpaceException(ocmSession* session, int index): ooOutOfException(session, index) {}
};

class OO_STORAGE_SPECIFIER ooOutOfContainerPagesException : public ooOutOfException
{
 public:
  ooOutOfContainerPagesException(ocmSession* session, int index): ooOutOfException(session, index) {}
};

class OO_STORAGE_SPECIFIER ooOutOfDbIDsException : public ooOutOfException
{
 public:
  ooOutOfDbIDsException(ocmSession* session, int index): ooOutOfException(session, index) {}
};

class OO_STORAGE_SPECIFIER ooAttemptToAccessOfflinePartitionException : public ooKernelException
{
 public:
  ooAttemptToAccessOfflinePartitionException(ocmSession* session, int index): ooKernelException(session, index) {}
};

class OO_STORAGE_SPECIFIER ooObjectNameNotUniqueException : public ooKernelException
{
 public:
  ooObjectNameNotUniqueException(ocmSession* session, int index): ooKernelException(session, index) {}
};

class OO_STORAGE_SPECIFIER ooObjectPlacementFailedException : public ooKernelException
{
 public:
  ooObjectPlacementFailedException(ocmSession* session, int index): ooKernelException(session, index) {}
};

class OO_STORAGE_SPECIFIER ooCacheFullException : public ooOutOfException
{
 public:
  ooCacheFullException(ocmSession* session, int index): ooOutOfException(session, index) {}
};

class OO_STORAGE_SPECIFIER ooOutOfMemoryException : public ooOutOfException
{
 public:
  ooOutOfMemoryException(ocmSession* session, int index): ooOutOfException(session, index) {}
};

//class OO_STORAGE_SPECIFIER ooFileOverflowException : public ooOutOfException
//{
// public:
// ooFileOverflowException(ocmSession* session, int index): ooOutOfException(session, index) {}
//};

class OO_STORAGE_SPECIFIER ooCommitFailedException : public ooKernelException
{
 public:
  ooCommitFailedException(ocmSession* session, int index): ooKernelException(session, index) {}
};

class OO_STORAGE_SPECIFIER ooNotFoundException : public ooKernelException
{
 public:
  ooNotFoundException(ocmSession* session, int index): ooKernelException(session, index) {}
};

class OO_STORAGE_SPECIFIER ooDatabaseNotFoundException : public ooNotFoundException
{
 public:
  ooDatabaseNotFoundException(ocmSession* session, int index): ooNotFoundException(session, index) {}
};

class OO_STORAGE_SPECIFIER ooContainerNotFoundException : public ooNotFoundException
{
 public:
  ooContainerNotFoundException(ocmSession* session, int index): ooNotFoundException(session, index) {}
};

class OO_STORAGE_SPECIFIER ooAlreadyExistException : public ooKernelException
{
 public:
  ooAlreadyExistException(ocmSession* session, int index): ooKernelException(session, index) {}
};

class OO_STORAGE_SPECIFIER ooAuthorizationException : public ooKernelException
{
 public:
  ooAuthorizationException(ocmSession* session, int index): ooKernelException(session, index) {}
};

// Implementation class for an exception with a formatted message;
// there would be no reason to catch this specific class.
class OO_STORAGE_SPECIFIER ooFormattedException : public ooException
{
 private:
  char* _what;
 public:
  ooFormattedException(const char* format, ...);
  const char* what() const OO_WHAT_THROW_NONE { return _what; }
  ~ooFormattedException() OO_WHAT_THROW_NONE;
 protected:
  ooFormattedException() : _what(NULL) { }
  void setMessage(const char* message);
#if defined(OO_H) || defined(OOOS_H) // if stdarg.h has been included
  void setMessage(const char* format, va_list ap);
#endif
};

// An exception that represents a method argument that is out of range.
class OO_STORAGE_SPECIFIER ooArgumentOutOfRangeException
   : public ooFormattedException
{
 public:
  ooArgumentOutOfRangeException(const char* format, ...);
  virtual int get_kind() const { return -401; }
};

// An exception that represents an overflow.
class OO_STORAGE_SPECIFIER ooOverflowException : public ooFormattedException
{
 public:
  ooOverflowException(const char* format, ...);
  virtual int get_kind() const { return -402; }
};

#endif /* __cplusplus */
#endif /* OO_EXCEPTION_H */
