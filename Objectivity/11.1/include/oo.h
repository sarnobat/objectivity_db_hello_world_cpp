
/**************************************************************************
		    Copyright (c) 1989-2002 Objectivity, Inc.
			  All Rights Reserved	

	THIS IS UNPUBLISHED PROPRIETARY SOURCE CODE OF OBJECTIVITY, INC.
	
	The copyright notice above does not evidence any	
	actual or intended publication of such source code.

*****************************************************************************/

#ifndef OO_H
#define OO_H "@(#)$Id$"

/* Note that several files are included in the middle of this file. */

#include <ooConfig.h>

#if defined(_MSC_VER) && !defined(OO_DDL_TRANSLATION)
#pragma pack(push,8)
#endif

#if defined(OO_MSC_VISUAL_CXX) && !defined(OO_BUILD) /*{*/
#if !defined(OO_OO_COMPILE_STATIC) && !defined(OO_DDL_TRANSLATION)
#ifndef _MT
#error You must compile Objectivity C++ files with \
                    [Debug] Multithreaded DLL Code Generation 
#endif

#ifndef _DLL
#error You must compile Objectivity C++ files with \
                    [Debug] Multithreaded DLL Code Generation 
#endif 
#endif

#if defined(OO_OO_DLL) || (defined(_DLL) && !defined(OO_OO_NO_DLL)) /*{*/
#ifdef _DEBUG
/* Dynamic debug link */
#pragma comment(lib, "oodbid.lib")
#else
/* Dynamic non-debug link */
#pragma comment(lib, "oodbi.lib")
#endif
#endif /*!(defined(OO_OO_DLL)||(defined(_DLL)&&!defined(OO_OO_NO_DLL)))*//*}*/

#pragma comment(lib, "ws2_32.lib")
#pragma comment(lib, "advapi32.lib")
#pragma comment(lib, "user32.lib")

#endif /*(defined(OO_MSC_VISUAL_CXX) && !defined(OO_BUILD))*//*}*/

#if defined(OO_GNU_CXX) && (((__GNUC__ * 100) + __GNUC_MINOR__) >= 406)
// If diagnostic pragma push and pop are supported (gcc 4.6 or later),
// locally suppress some non-helpful warnings. (OBJY-16115)
#define OO_GCC_POP
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Weffc++"
#pragma GCC diagnostic ignored "-Wnon-virtual-dtor"
#endif

#include <stddef.h>
#include <stdarg.h>
#if defined(OO_GNU_CXX) || defined(OO_INTEL_CXX)
#include <new>
#else
#include <new.h>
#endif
#include <ooBase.h>


/* The Objectivity version is 11.1.0 (major.minor.revision). */
#define OO_VERSION_MAJOR 11
#define OO_VERSION_MINOR 1
#define OO_VERSION_REVISION 0

// Library version as a string:
OO_STORAGE_SPECIFIER const char* ooVersionString();

// Forward declarations
class OO_STORAGE_SPECIFIER ooFDObj;
class OO_STORAGE_SPECIFIER ooAPObj;
class OO_STORAGE_SPECIFIER ooDBObj;
class OO_STORAGE_SPECIFIER ooContObj;
class OO_STORAGE_SPECIFIER ooDerefBase;
class OO_STORAGE_SPECIFIER ooDerefUtil;
class OO_STORAGE_SPECIFIER ooTrans;
class OO_STORAGE_SPECIFIER ooConvertInObject ;
class OO_STORAGE_SPECIFIER ooConvertInOutObject ;
class OO_STORAGE_SPECIFIER otiMemberInfo;
class OO_STORAGE_SPECIFIER d_Ref_Any;
class OO_STORAGE_SPECIFIER d_Database;
class OO_STORAGE_SPECIFIER ooLookupKey;
class OO_STORAGE_SPECIFIER ooCollectionIterator;

OO_STORAGE_SPECIFIER void opiHandleFromAny(ooTypeNumber, ooHandleBase *, const d_Ref_Any *);
OO_STORAGE_SPECIFIER void opiRefFromAny(ooTypeNumber, ooId *, const d_Ref_Any *);
OO_STORAGE_SPECIFIER void* opiODMGDatabaseNew(size_t, ooTypeNumber, const d_Database *);
OO_STORAGE_SPECIFIER void opiConversionWrap (ooIdBase*, ooVoidFuncPtr , void* , void*, void*, void*);

#ifdef OO_DDL_TRANSLATION // Do some stuff for ooddl
#pragma ooschema *  // Use the default schema for the builtin types.
#endif

// Define the ooRef macros, and related stuff.
/*
Define the ooRef and related macros to use templates.  Also declare the
templates the macros produce.  The " "s before the final ">"s in the macros
are needed when "T" is a template type, and the " " after the final ">"s in
the macros are needed when the macro is a template parameter.
*/

#define ooRef(T) opiRef<T > 
#define ooRefStructor(T) opiRef
template<class T>
class opiRef;

#define ooShortRef(T) opiShortRef<T > 
#define ooShortRefStructor(T) opiShortRef
template<class T>
class opiShortRef;

#define ooLongRef(T) opiLongRef<T > 
#define ooLongRefStructor(T) opiLongRef
template<class T>
class opiLongRef;

#define ooHandle(T) opiHandle<T >
#define ooHandleStructor(T) opiHandle
template<class T>
class opiHandle;

#define ooItr(T) opiItr<T > 
#define ooItrStructor(T) opiItr
template<class T>
class opiItr;

#define ooDeref(T) opiDeref<T > 
#define ooDerefStructor(T) opiDeref
template<class T>
class opiDeref;

#define ooString(N) opiString<N > 
template<int N>
class opiString;

#define ooShortRefSuper(T) opiShortRef<T >
#define ooHandleSuper(T) opiHandle<T >

// ooTypeN and ooAssocN
#define ooTypeN(T) T::opiTypeN
OO_STORAGE_SPECIFIER const char* ooTypeName(ooTypeNumber typeN);
#define ooAssocN(T,A) T::ooConcat2(A,_ooAssocN)

// Some ODMG names
// (ODMG version 1.1 uses Persistent_Object; 1.2 and later use d_Object)
#define d_Persistent_Object ooObj
#define d_Object ooObj
#define d_Ref opiRef
#define d_Transaction ooTrans
#define d_String ooVString
#define d_Char ooChar
#define d_Short int16
#define d_UShort uint16
#define d_ULong uint32
#define d_Long int32
#define d_Boolean ooBoolean
#define d_Octet ooChar
#define d_Float float32
#define d_Double float64

#ifndef d_True
#define d_True  oocTrue
#define d_False oocFalse
#endif

// Do not use realloc or free as identifier names under some conditions.
#ifdef _CRTDBG_MAP_ALLOC
#define opiFreeName opiFreeMethod
#define opiReallocName opiReallocMethod
#else
#define opiFreeName free
#define opiReallocName realloc
#endif


// A couple of function types.
typedef void (*ooDeleteFuncPtr)(void*);
typedef void (*ooConvertFunction)(const ooConvertInObject&, 
				  ooConvertInOutObject&);


#if defined(OO_GNU_CXX)
#define ooGetMemberPtr(className,identifier) (&this->identifier)
#else
#define ooGetMemberPtr(className,identifier)	\
    ((char*)this + (unsigned long)(&(((className *) 0)->identifier)))
#endif


// This macro is sometimes needed to combine templates and macros
#define OO_COMMA ,

// Internal function declarations

OO_STORAGE_SPECIFIER ooBoolean opiIsStorePers(const void* pObject);

OO_STORAGE_SPECIFIER ooObj *
opiRefPin(const ooId *id,
	  ooMode mode);

OO_STORAGE_SPECIFIER void opiSessionTerm();
OO_STORAGE_SPECIFIER void opiProcessInit();
ooExternC OO_STORAGE_SPECIFIER void ocmProcessTermAll();

///////////////////////////////////////////////////////////////////////////////
// This class and variable arranges for the opiProcessInitTermClass constructor
// to be called before any static initialization that uses Objy in any
// compilation unit that includes <oo.h>, and similarly for the
// opiProcessInitTermClass destructor to be called after all other static
// destruction that uses Objy.  The constructor performs some crucial
// pre-initialization of Objy and the destructor shuts Objy down.
class opiProcessInitTermClass {
 public:
  opiProcessInitTermClass()
  {
    opiProcessInit();
  }
// all platforms except Windows accomplish this cleanup by using atexit(ocmProcessTermAll()) instead
#if defined(OO_NT) && !defined(OO_SKIP_AUTO_CLEANUP_AT_EXIT) && !defined(_USRDLL) && !defined(_AFXDLL)
  ~opiProcessInitTermClass()
  {
    ocmProcessTermAll();
  }
#endif
};
static opiProcessInitTermClass opiProcessInitTermVariable;

///////////////////////////////////////////////////////////////////////////////
// The default varray type

// The old ooddl parser cannot tolerate a definition of this built-in type.
struct ooDefaultVArray {
    void* _data;
};

class OO_STORAGE_SPECIFIER ooDerefBase {
	friend class ooDerefUtil;
 public:
  static ooDerefBase *    createDerefStackDummyHead();
  // Fields:
  ooObj	*        _ptr;
  ooDerefBase *  _prev;
  ooDerefBase *  _next;
  inline ooObj * vm() const {
	  return this->_ptr;
  }
  void close();
 protected:
  // Structors:
  ooDerefBase(ooObj *  fromObject);
  ~ooDerefBase();
  // Methods:
  void    pinCompensate();
 private:
  // Declared only to avoid implicit definition:
  ooDerefBase(const ooDerefBase &);
};

inline
ooId &
ooId::operator=(const ooShortId& shortId)
{
  _page = shortId.get_page();
  _slot = shortId.get_slot();
  return *this;
}

inline
ooBoolean
ooId::operator==(const ooShortId& shortId) const
{
  return _slot == shortId.get_slot() && _page == shortId.get_page();
}

inline
ooBoolean
ooId::operator!=(const ooShortId& shortId) const
{
  return ! operator==(shortId);
}

///////////////////////////////////////////////////////////////////////////////
// Class ooIterator and related types

typedef uint32 ooItrMode;
typedef ooAssocNumber ooAssocTypeN;

class ooItrStateBase;

// Generic iterator classes.  Use only the first external methods.
class OO_STORAGE_SPECIFIER ooIterator {
  public:
    ooStatus end();
    ooBoolean	next();
    // This method works only for non-indexed scans of objects in a container:
    ooStatus goTo (const ooHandle(ooObj)& current);
    // The rest of these public methods are for internal use only.
    ooIterator& get_itr(){ return *this; }
    ooItrMode get_mode() const { return _mode; }
    ooTypeNumber get_typeN() const { return _typeN; }
    ooItrStateBase* getState() const { return itrState; }
    void set_mode(const ooItrMode mode) { _mode = mode; }
    void set_typeN(const ooTypeNumber typeN) { _typeN = typeN; }
    void setState(ooItrStateBase* state) { itrState = state; }
    void optimizeScanOrder(ooBoolean state) 
         { physicalPageOrder = state; }
    ooBoolean getOptimizeScanOrder() const
         { return physicalPageOrder; }
    void setObjectTypeFilter(ooObjectTypeFilter* filter);
    ooBoolean usedIndexes();
    ocmSession* session() const;
    ooCollectionIterator* coItr;
    ooId scope;
    ooId scopeId;	// For ooEventListener reporting
    ooMode openWithMode;
  protected:
    ooIterator(ooTypeNumber typeN):_mode(0), _typeN(typeN), itrState(0), 
               physicalPageOrder(oocFalse), coItr(0), openWithMode(oocNoOpen) {}
    ~ooIterator();

  private:
    ooItrMode _mode;
    ooTypeNumber _typeN;
    ooItrStateBase* itrState;
    ooBoolean physicalPageOrder;
};

class OO_STORAGE_SPECIFIER ooQuerySplitter;
class OO_STORAGE_SPECIFIER oqrQueryProxy;

namespace objy { namespace query {
  class ObjectQualifier;
}}

namespace objy { namespace placement {
  class QueryPlanBase;
  class QueryPlanStateBase;
  class Conditions;
}}

// EOQ integration: added scans/parallelScans taking wide predicate and ObjectQualifier

// Regular and container object iterator classes. Use only the scan methods.
class OO_STORAGE_SPECIFIER ooIteratorObjOrContObj : public ooIterator
{
 public:
  ooIteratorObjOrContObj(ooTypeNumber typeN) 
    : ooIterator(typeN) {}
  ~ooIteratorObjOrContObj() {}

  // implemented in opiItr.cxx
  ooStatus scan(const ooHandle(ooObj)& objH, ooMode mode = oocNoOpen);
  ooStatus scan(const ooId&  objId, ooMode mode = oocNoOpen);

  // implemented in opiQuery.cxx
  ooStatus scan(const ooHandle(ooObj)&  objH, const char* predicate);
  ooStatus scan(const ooHandle(ooObj)&  objH, const wchar_t* predicate);
  ooStatus scan(const ooHandle(ooObj)&  objH, 
    const objy::query::ObjectQualifier& objQualifier);

  ooStatus scan(const ooId& objId, const char* predicate);
  ooStatus scan(const ooId& objId, const wchar_t* predicate);
  ooStatus scan(const ooId& objId, 
    const objy::query::ObjectQualifier& objQualifier);

  ooStatus scan(const ooId& objId, ooMode mode, 
    ooAccessMode access, const char* predicate);
  ooStatus scan(const ooId& objId, ooMode mode, 
    ooAccessMode access, const wchar_t* predicate);
  ooStatus scan(const ooId& objId, ooMode mode, 
    ooAccessMode access, const objy::query::ObjectQualifier& objQualifier);

  ooStatus scan(const ooHandle(ooObj)& objH, ooMode mode, 
    ooAccessMode access, const char* predicate);
  ooStatus scan(const ooHandle(ooObj)& objH, ooMode mode, 
    ooAccessMode access, const wchar_t* predicate);
  ooStatus scan(const ooHandle(ooObj)& objH, ooMode mode, ooAccessMode access, 
    const objy::query::ObjectQualifier& objQualifier);

  ooStatus scan(const ooHandle(ooObj)& objH, const ooLookupKey& lookupKey, ooMode mode = oocNoOpen);
  ooStatus scan(const ooId& objId, const ooLookupKey& lookupKey, ooMode mode = oocNoOpen);

  ooStatus parallelScan(const ooHandle(ooObj)& objH, ooMode mode, 
			const char* predicate, ooQuerySplitter* splitter = 0,
			const char* filterName = 0,
			const void* filterData = 0, int filterDataLength = 0);
  ooStatus parallelScan(const ooHandle(ooObj)& objH, ooMode mode, 
			const wchar_t* predicate, ooQuerySplitter* splitter = 0,
			const char* filterName = 0,
			const void* filterData = 0, int filterDataLength = 0);
  ooStatus parallelScan(const ooHandle(ooObj)& objH, ooMode mode, 
			const objy::query::ObjectQualifier& objQualifier, 
         ooQuerySplitter* splitter = 0,
			const char* filterName = 0,
			const void* filterData = 0, int filterDataLength = 0);

  ooStatus parallelScan(const ooRef(ooFDObj)& objR, ooMode mode, 
			const char* predicate, ooQuerySplitter* splitter = 0,
			const char* filterName = 0,
			const void* filterData = 0, int filterDataLength = 0);
  ooStatus parallelScan(const ooRef(ooFDObj)& objR, ooMode mode, 
			const wchar_t* predicate, ooQuerySplitter* splitter = 0,
			const char* filterName = 0,
			const void* filterData = 0, int filterDataLength = 0);
  ooStatus parallelScan(const ooRef(ooFDObj)& objR, ooMode mode, 
			const objy::query::ObjectQualifier& objQualifier, 
         ooQuerySplitter* splitter = 0,
			const char* filterName = 0,
			const void* filterData = 0, int filterDataLength = 0);

  ooStatus parallelScan(const ooRef(ooDBObj)& objR, ooMode mode, 
			const char* predicate, ooQuerySplitter* splitter = 0,
			const char* filterName = 0,
			const void* filterData = 0, int filterDataLength = 0);
  ooStatus parallelScan(const ooRef(ooDBObj)& objR, ooMode mode, 
			const wchar_t* predicate, ooQuerySplitter* splitter = 0,
			const char* filterName = 0,
			const void* filterData = 0, int filterDataLength = 0);
  ooStatus parallelScan(const ooRef(ooDBObj)& objR, ooMode mode, 
			const objy::query::ObjectQualifier& objQualifier, 
         ooQuerySplitter* splitter = 0,
			const char* filterName = 0,
			const void* filterData = 0, int filterDataLength = 0);

  ooStatus scan(ooHandle(ooContObj)&  container,
                ooRef(ooObj) index,
                ooMode mode, 
                uint32 targetTypeN,
                const ooLookupKey* lookupKey,
                ooObjectTypeFilter* filter);

  ooStatus scan(objy::placement::QueryPlanBase* queryPlan,
                objy::placement::QueryPlanStateBase* queryPlanState);

 protected:
  // implemented in opiItr.cxx
  ooStatus scan(const ooHandle(ooObj)& objH, ooMode mode, ooBoolean usePredicate, 
                const ooLookupKey* lookupKey);

 private:
  ooStatus scan(const ooHandle(ooObj)&  objHandle, ooMode mode, ooAccessMode access, oqrQueryProxy* query);

  friend class ooItrPlacementManagedPredState;
};

class OO_STORAGE_SPECIFIER ooTrans 
{
  public:
    ooTrans() :
        _transId(0),
        _state(0),
        _globalControl(oocFalse),
	_session(0)
      {}
    ~ooTrans();
    ooStatus start(ooMode mode = oocNoMROW,
		   int32 waitOption = oocTransNoWait,
		   ooIndexMode indexMode = oocInsensitive);
    ooStatus abort(const ooHandleMode mode = oocHandleToNull);
    ooStatus commit();
    ooStatus commitAndHold(ooDowngradeMode mode = oocNoDowngrade);
    ooStatus upgrade() ;
    ooBoolean isActive() const;

    // ODMG methods:
    void begin()
      {
	this->start();
      }
    void checkpoint()
      {
	this->commitAndHold();
      }
    ooTransId  getID() const;

    /********************************************************************
     *									*
     * Note: The following methods are only for internal system usage.	*
     *	     It is subject to change in any future release.		*
     *	     You are not allowed to use it.				*
     *									*
     ********************************************************************/

    ooTransId  get_transId() const	       { return _transId; }
    uint8      get_state()   const	       { return _state; }

  private:
    void  set_transId(const ooTransId transId) { _transId = transId; }
    void  set_state(const uint8 state)	       { _state = state; }
    ooStatus abandon();
    void  clear_transaction(ocmSession* current);

  public:
    ooStatus prepare(ooExternalTransId *globalTransId);
    ooBoolean is_global() const { return _globalControl; }
    friend struct opiXAstate;
    friend OO_STORAGE_SPECIFIER void opiSessionTerm();

  private:
    ooTransId  _transId;
    uint8      _state;
    ooBoolean  _globalControl; // controlled by external Transaction Manager?
    ocmSession* _session;
    void*       _reserve; // space reserved for future use

    // These methods are declared only to avoid implicit definition:
    ooTrans(const ooTrans &);
    ooTrans &    operator=(const ooTrans &);
};

class OO_STORAGE_SPECIFIER ooContext {
  friend OO_STORAGE_SPECIFIER void opiProcessInit();
  friend OO_STORAGE_SPECIFIER void ooTermThread();
  friend OO_STORAGE_SPECIFIER void opiSessionTerm();
 public:
  // Structors:
  ooContext(uint32  numPages = 200,
	    uint32  maxPages = 500);
  ~ooContext();
  // Context:
  static ooContext* current(const ooHandle(ooObj)* objH = 0);
  static void setCurrent(ooContext *  context);
  static void setCurrentShared(ooContext *  context);
  unsigned int get_region() const;
  ooStatus lockEnable(); // SPR 18900
  ocmSession *  kernelSession; // for Objectivity internal use only
 protected:
  // Data:
  // Bootstrap constructor:
  enum internalConstructorType { internalConstructor };
  ooContext(/*ooContext::*/internalConstructorType,
	    ocmSession *                        theKernelSession);
 private:
  // Declared only to avoid implicit definition:
  ooContext(const ooContext &);
  ooContext &    operator=(const ooContext &);
};

class OO_STORAGE_SPECIFIER d_Ref_Any {
 public:
  d_Ref_Any()
    {}
  d_Ref_Any(const d_Ref_Any &  from) :
      data(from.data)
    {}
  d_Ref_Any(const d_Persistent_Object *  from)
    {
      this->data = from;
    }
  ~d_Ref_Any()
    {}
  d_Ref_Any& operator=(const d_Ref_Any &  from)
  {
	  this->data = from.data;
	  return *this;
	}
 inline d_Ref_Any&  operator=(const ooHandle(ooObj)& from);
 inline d_Ref_Any&  operator=(const ooRef(ooObj)& from);
// This method confuses some compilers, but luckily is an optimization.
#if !(defined(OO_IBM_CXXSET) || defined(OO_SGI_CXXN32))
  d_Ref_Any &
      operator=(const d_Persistent_Object *  from)
        {
	  this->data = from;
	  return *this;
	}
#endif
  void
      clear()
        {
	  this->data.nullify();
	}
  inline void delete_object();
  // boolean predicates checking to see if value is null or not
  operator const void *() const
    {
      return ((const void *) (!(this->data.isNull())));
    }
  int
      operator!() const
        {
	  return this->data.isNull();
	}
  int
      is_null() const
        {
	  return this->data.isNull();
	}
#ifdef OO_ENABLE_REF_ANY_COMPARISON
friend int    operator==(const d_Ref_Any &, const d_Ref_Any &);
friend int    operator==(const d_Ref_Any &, const d_Persistent_Object *);
friend int    operator==(const d_Persistent_Object *, const d_Ref_Any &);
friend int    operator!=(const d_Ref_Any &, const d_Ref_Any &);
friend int    operator!=(const d_Ref_Any &, const d_Persistent_Object *);
friend int    operator!=(const d_Persistent_Object *, const d_Ref_Any &);
#endif
 protected:
  ooId data;
};


///////////////////////////////////////////////////////////////////////////////
// class d_Database

class d_Database {
 public:
  enum access_status {
    not_open = oocNoOpen,
    read_write = oocUpdate,
    read_only = oocRead,
    exclusive = oocXUpdate
  };
  void    open(const char *   database_name,
	       access_status  status = read_write);
  void    close();
  void    set_object_name(const d_Ref_Any &  the_object,
			  const char *       the_name);
  const char *    get_object_name(const d_Ref_Any &  the_object) const;
  void    rename_object(const char *  old_name,
			const char *  new_name);
  d_Ref_Any    lookup_object(const char *  the_name) const;
  static d_Database *    const transient_memory;
};

struct ooInternalObj {
    char dummy;
    ooInternalObj() { dummy = 0; }
};

class OO_STORAGE_SPECIFIER ooConvertInObject {
private:
    ooStatus getEmbeddedMember (const char *member_name,
				ooConvertInObject &old_value,
				otiMemberInfo **member_info) const;
public:
    ooStatus getInt8 (const char *member_name, int8 &value) const;
    ooStatus getInt16 (const char *member_name, int16 &value) const;
    ooStatus getInt32 (const char *member_name, int32 &value) const;
    ooStatus getInt64 (const char *member_name, int64 &value) const;
    ooStatus getUInt8 (const char *member_name, uint8 &value) const;
    ooStatus getUInt16 (const char *member_name, uint16 &value) const;
    ooStatus getUInt32 (const char *member_name, uint32 &value) const;
    ooStatus getUInt64 (const char *member_name, uint64 &value) const;
    ooStatus getFloat32 (const char *member_name, float32 &value) const;
    ooStatus getFloat64 (const char *member_name, float64 &value) const;
    ooStatus getChar (const char *member_name, char &value) const;
    ooStatus getChar16 (const char *member_name, ooChar16 &value) const;
    ooStatus getChar32 (const char *member_name, ooChar32 &value) const;
    ooStatus getBoolean (const char *member_name, ooBoolean &value) const;
    ooStatus getOldDataMember (const char *member_name, 
			       	       ooConvertInObject &old_value) const;
    ooStatus getOldBaseClass (const char *base_class_path, 
			              ooConvertInObject &old_value) const;
    virtual ~ooConvertInObject () ;
    ooConvertInObject () {_state = NULL ;}  ;
protected:
    void *_state ;

friend OO_STORAGE_SPECIFIER void opiConversionWrap (ooIdBase*, ooVoidFuncPtr user_function, 
			       void* new_obj, void* old_obj, 
			       void* new_shape, void* old_shape) ;
friend class OO_STORAGE_SPECIFIER ooConvertInOutObject ;
} ;

class OO_STORAGE_SPECIFIER ooConvertInOutObject : public ooConvertInObject {
public:
    ooConvertInOutObject()
      {
	this->_state = NULL;
      }
    ooStatus setInt8 (const char *member_name, int8 value) ;
    ooStatus setInt16 (const char *member_name, int16 value) ;
    ooStatus setInt32 (const char *member_name, int32 value) ;
    ooStatus setInt64 (const char *member_name, int64 value) ;
    ooStatus setUInt8 (const char *member_name, uint8 value) ;
    ooStatus setUInt16 (const char *member_name, uint16 value) ;
    ooStatus setUInt32 (const char *member_name, uint32 value) ;
    ooStatus setUInt64 (const char *member_name, uint64 value) ;
    ooStatus setFloat32 (const char *member_name, float32 value) ;
    ooStatus setFloat64 (const char *member_name, float64 value) ;
    ooStatus setChar (const char *member_name, char value) ;
    ooStatus setChar16 (const char *member_name, ooChar16 value) ;
    ooStatus setChar32 (const char *member_name, ooChar32 value) ;
    ooStatus setBoolean (const char *member_name, ooBoolean value) ;
    ooStatus getNewDataMember (const char *member_name, 
			       ooConvertInOutObject &new_value) ;
    ooStatus getNewBaseClass (const char *base_class_path, 
			      ooConvertInOutObject &new_value) ;
    virtual ~ooConvertInOutObject () ;

friend OO_STORAGE_SPECIFIER void opiConversionWrap (ooIdBase* pOid, ooVoidFuncPtr user_function, 
			       void* new_obj, void* old_obj, 
			       void* new_shape, void* old_shape) ;

} ;

///////////////////////////////////////////////////////////////////////////////
// opiRef and related dummy template definitions

#if defined(OO_DDL_TRANSLATION) // {

/*
Define dummy classes used to produce error messages when ooRef and related
class definitions are not #included before they are used.
*/

template<class T>
class Ignore_the_compilers_error_message_The_real_error_is_Missing_definition_of_ooRef;

template<class T>
class Ignore_the_compilers_error_message_The_real_error_is_Missing_definition_of_ooShortRef;

template<class T>
class Ignore_the_compilers_error_message_The_real_error_is_Missing_definition_of_ooHandle;


/* Define the templates produced by the ooRef and related macros. */

template<class T>
class opiRef : private ooId {
  Ignore_the_compilers_error_message_The_real_error_is_Missing_definition_of_ooRef<T> dummy;
};

template<class T>
class opiShortRef : private ooShortId {
  Ignore_the_compilers_error_message_The_real_error_is_Missing_definition_of_ooShortRef<T> dummy;
};

template<class T>
class opiHandle : private ooHandleBase {
  Ignore_the_compilers_error_message_The_real_error_is_Missing_definition_of_ooHandle<T> dummy;
};

template<class T>
class opiItr : private opiHandle<T>,
  	       private ooIterator {
};

template<class T>
class opiDeref : private ooDerefBase {
};


#endif // defined(OO_DDL_TRANSLATION)  }

///////////////////////////////////////////////////////////////////////////////

// Note that file ooSchema.h #includes file file ooSchema_ref.h, which in turn
// #includes file ooDecl.h.
#include <ooClusterStrategy.h>
#include <ooSchema.h>
#ifndef OO_PREDEFINED_H
#include <ooPredef.h>
#endif
#include <ooError.h>
#include <ooVArray.h>
#include <ooString.h>
//#include <ooUserOper.h>
#include <ooException.h>

#if defined(_MSC_VER) && _MSC_VER > 1300
ooExplicitTemplateInstantiation OO_STORAGE_SPECIFIER ooVArray(int8);
ooExplicitTemplateInstantiation OO_STORAGE_SPECIFIER ooVArray(int16);
ooExplicitTemplateInstantiation OO_STORAGE_SPECIFIER ooVArray(int32);
ooExplicitTemplateInstantiation OO_STORAGE_SPECIFIER ooVArray(float32);
ooExplicitTemplateInstantiation OO_STORAGE_SPECIFIER ooVArray(float64);
ooExplicitTemplateInstantiation OO_STORAGE_SPECIFIER ooVArray(int64);
ooExplicitTemplateInstantiation OO_STORAGE_SPECIFIER ooVArray(uint32);
ooExplicitTemplateInstantiation OO_STORAGE_SPECIFIER ooVArray(uint16);
ooExplicitTemplateInstantiation OO_STORAGE_SPECIFIER ooVArray(uint8);
ooExplicitTemplateInstantiation OO_STORAGE_SPECIFIER ooVArray(ooRef(ooObj));
#endif

// each element of the default association array
struct ooAssocElement {
  ooAssocNumber association_type_number; // ooAssocN(class,association)
  ooRef(ooObj)  ref;  // reference to the associated object
};

// the default association array
class OO_STORAGE_SPECIFIER ooDefaultAssocArray : private oomVCB
{
public:
  int size ();
  int capacity ();
  ooStatus setCapacity ( int new_capacity );
  const ooAssocElement& operator[](int index);
};

// Use the following macro to access an inline association.
// The result value is of type ooInlineVArray or ooShortInlineVArray.
#define ooInlineAssociation(object,association_name) \
		((object)-> ooConcat2(_oo,association_name))

// inline association array of ooRef
class OO_STORAGE_SPECIFIER ooInlineVArray
{
public:
    int size ();
    int capacity ();
    ooStatus setCapacity ( int new_capacity );
    const ooRef(ooObj)& operator[](int index);

    void *	 _data;
    operator void *() const { return _data; }
    /* do not copy ooInlineVArrays - they are identity dependent */
    ooInlineVArray()
	{}
    ooInlineVArray(const ooInlineVArray &)
	{}
    ooInlineVArray &operator=(const ooInlineVArray &)
	{
	    return (*this);
	}
};

// inline association array of ooShortRef
class OO_STORAGE_SPECIFIER ooShortInlineVArray
{
public:
    int size ();
    int capacity ();
    ooStatus setCapacity ( int new_capacity );
    const ooShortRef(ooObj)& operator[](int index);

    void *	 _data;
    operator void *() const { return _data; }
    /* do not copy ooShortInlineVArrays - they are identity dependent */
    ooShortInlineVArray()
	{}
    ooShortInlineVArray(const ooShortInlineVArray &)
	{}
    ooShortInlineVArray &operator=(const ooShortInlineVArray &)
	{
	    return (*this);
	}
};

// Various functions
OO_STORAGE_SPECIFIER ooStatus
ooInit(uint32 nFiles = oocDefaultMaxOpenFiles,
       uint32 nPages = 200,
       uint32 nMaxPages = 500,
       ooBoolean installSigHandler = oocTrue);

OO_STORAGE_SPECIFIER void
ooSetBufferSpace( unsigned page_size, size_t initial_page_space,
		  size_t maximum_page_space,
		  unsigned initial_large_objects,
		  unsigned maximum_large_objects );

// Max time to wait for container/db catalog lock, page map lock, file lock (page allocation from file)
// If a higher value is set for ooSetLockWait then that value is also used for catalog lock wait
OO_STORAGE_SPECIFIER void ooSetCatalogLockWait(int32 seconds = 35);
OO_STORAGE_SPECIFIER void ooSetLockWait(int32 waitOption = oocNoWait);
OO_STORAGE_SPECIFIER int32 ooGetLockWait();
OO_STORAGE_SPECIFIER ooStatus ooNoLock();
OO_STORAGE_SPECIFIER void ooNoJournal();
OO_STORAGE_SPECIFIER void ooCheckVTablePointer(ooBoolean checkVptr = oocTrue);
OO_STORAGE_SPECIFIER void ooSetHotMode(ooBoolean hotMode = oocTrue);
OO_STORAGE_SPECIFIER void ooSetRpcTimeout(int sec = 25);
OO_STORAGE_SPECIFIER int ooGetRpcTimeout();
OO_STORAGE_SPECIFIER void ooSetConnectRetries(unsigned int retries);
OO_STORAGE_SPECIFIER void ooUseIndex(ooBoolean useIndex = oocTrue);
OO_STORAGE_SPECIFIER void ooRunStatus();
OO_STORAGE_SPECIFIER ooStatus ooSetOfflineMode(ooOfflineMode offlineMode);
OO_STORAGE_SPECIFIER ooOfflineMode ooGetOfflineMode();
OO_STORAGE_SPECIFIER ooStatus ooPurgeAps(char ** appNames, int numOfAps);
OO_STORAGE_SPECIFIER void ooAllowNonQuorumReadAll();
OO_STORAGE_SPECIFIER void ooExitCleanup();
OO_STORAGE_SPECIFIER ooStatus ooResetFD();
OO_STORAGE_SPECIFIER ooStatus ooUpdateIndexes(const ooHandle(ooObj)&, ooIndexOp = oocIOpUpdate);

OO_STORAGE_SPECIFIER void ooInitThread(ooContext*  context);
OO_STORAGE_SPECIFIER void ooInitThread();

OO_STORAGE_SPECIFIER void ooTermThread();
OO_STORAGE_SPECIFIER void opiPrintHList(uint32 level, uint32 number = 0);
OO_STORAGE_SPECIFIER void ooSetAMSUsage(ooAMSUsage ams_usage = oocAMSPreferred);
OO_STORAGE_SPECIFIER ooAMSUsage ooGetAMSUsage();
OO_STORAGE_SPECIFIER void ooSetLargeObjectMemoryLimit(uint32);
OO_STORAGE_SPECIFIER ooStatus ooRegAtStartFunc(ooVoidFuncPtr);
OO_STORAGE_SPECIFIER ooStatus ooRegOnExitFunc(ooVoidFuncPtr);
OO_STORAGE_SPECIFIER void ooSetCheckHLoop();
OO_STORAGE_SPECIFIER void ooSetContObjHashPercent(uint32);
OO_STORAGE_SPECIFIER ooDiskFormat ooGetObjectCreationDiskFormat();
OO_STORAGE_SPECIFIER void ooSetObjectCreationDiskFormat(ooDiskFormat);
  
OO_STORAGE_SPECIFIER ooStatus
ooOpenContainers (const ooVArray(ooRef(ooObj)) & objects,
		  ooMode openMode = oocRead);

OO_STORAGE_SPECIFIER ooStatus
ooLockAny(/* in: */ const ooIdBase* oid_array, int oid_array_length,
		    ooLockMode lockMode, ocmSession* session,
	  /* out: */ ooIdBase* locked_oid, bool signal = true);

OO_STORAGE_SPECIFIER unsigned 
ooNewQueryAgent(const char *DBname,  const char *hostName,  
                const char *queryAgent,  const char *parameters = 0,  
                unsigned userDBID = 0,  unsigned pageSize = 0);

///////////////////////////////////////////////////////////////////////////////
// d_Ref_Any inline methods and operators

inline
d_Ref_Any &
d_Ref_Any::operator=(const ooHandle(ooObj) &  from)
{
  this->data = from;
  return *this;
}

inline
d_Ref_Any &
d_Ref_Any::operator=(const ooRef(ooObj) &  from)
{
  this->data = from;
  return *this;
}

inline
void
d_Ref_Any::delete_object()
{
  ooReinterpretCast(ooRef(ooObj) *,this)->delete_object();
}

#ifdef OO_ENABLE_REF_ANY_COMPARISON

inline
int
operator==(const d_Ref_Any &  left,
	   const d_Ref_Any &  right)
{
  return (*((ooRef(ooObj) *) (&left)) == *((ooRef(ooObj) *) (&right)));
}

inline
int
operator==(const d_Ref_Any &  left,
	   const d_Persistent_Object *  right)
{
  return (*((ooRef(ooObj) *) (&left)) == right);
}

inline
int
operator==(const d_Persistent_Object *  left,
	   const d_Ref_Any &  right)
{
  return (right == left);
}

inline
int
operator!=(const d_Ref_Any &  left,
	   const d_Ref_Any &  right)
{
  return !(left == right);
}

inline
int
operator!=(const d_Ref_Any &  left,
	   const d_Persistent_Object *  right)
{
  return !(left == right);
}

inline
int
operator!=(const d_Persistent_Object *  left,
	   const d_Ref_Any &  right)
{
  return !(left == right);
}

template<class T>
inline
int
operator==(const d_Ref_Any &  left,
	   const opiHandle<T> &  right)
{
  return (*((ooRef(ooObj) *) (&left)) == *((ooHandle(ooObj) *) (&right)));
}

template<class T>
inline
int
operator==(const opiHandle<T> &  left,
	   const d_Ref_Any &  right)
{
  return (right == left);
}

template<class T>
inline
int
operator==(const d_Ref_Any &  left,
	   const opiRef<T> &  right)
{
  return (*((ooRef(ooObj) *) (&left)) == *((ooRef(ooObj) *) (&right)));
}

template<class T>
inline
int
operator==(const opiRef<T> &  left,
	   const d_Ref_Any &  right)
{
  return (right == left);
}

template<class T>
inline
int
operator!=(const d_Ref_Any &  left,
	   const opiHandle<T> &  right)
{
  return (*((ooRef(ooObj) *) (&left)) != *((ooHandle(ooObj) *) (&right)));
}

template<class T>
inline
int
operator!=(const opiHandle<T> &  left,
	   const d_Ref_Any &  right)
{
  return (right != left);
}

template<class T>
inline
int
operator!=(const d_Ref_Any &  left,
	   const opiRef<T> &  right)
{
  return (*((ooRef(ooObj) *) (&left)) != *((ooRef(ooObj) *) (&right)));
}

template<class T>
inline
int
operator!=(const opiRef<T> &  left,
	   const d_Ref_Any &  right)
{
  return (right != left);
}

#endif // defined(OO_ENABLE_REF_ANY_COMPARISON)


///////////////////////////////////////////////////////////////////////////////
// Persistent-capable object new/delete operations

enum opiPlacementNewType { opiPlacementNewValue };

inline
void *
operator new(size_t               ,
	     opiPlacementNewType  ,
	     void *               result)
{
  return result;
}

#if defined(_MSC_VER) || (defined(OO_HP_CXX) && (__HP_aCC >= 60000))
// This is just to suppress warning C4291 from VC++ 6.0.
// Or warning #2830-D from the HP compiler.
inline
void
operator delete(void*, opiPlacementNewType, void*) { }
#endif

// ooNewConts() - create a batch of containers
//   - number is the number of containers to be created
//   - hash, initPages, and percentGrow, are parameters for container
//   - openP is a Boolean flag for open/close of containers after creation
//   - pHandle is a pointer to an array of oohandle or ooref
// NOTE: Before making changes to this macro, please consider making same changes in 
// Java_com_objy_pm_ExternalInterface_jooContObj_1ooNewConts() in jooContObj.cpp
// where the ooNewConts functionality is reproduced for Java.
#define ooNewConts(objType,number,clusteringHint,hash,initPages,percentGrow,openP,pHandle) \
  {                                                                           \
    unsigned int ___base = opiNewContSForMacro(ooTypeN(objType),              \
					    number,                           \
					    clusteringHint,                   \
					    hash,                             \
					    initPages,                        \
					    percentGrow);                     \
    if (___base) {                                                            \
      for (unsigned ___i = 0; ___i < number; ___i++) {                        \
	void *___storage = opiNewContObjObj(ooTypeN(objType),                 \
					   pHandle[___i],                     \
					   ___base + ___i,                    \
					   clusteringHint);                   \
	if (___storage) {                                                     \
	  ::new(opiPlacementNewValue, ___storage)  objType();                 \
	} else {                                                              \
	  pHandle->clear();                                                   \
	  break;                                                              \
	}                                                                     \
	if (!openP && !(pHandle[___i].close())) {                             \
	  pHandle->clear();                                                   \
	  break;                                                              \
	}                                                                     \
      } /*for*/                                                               \
    }                                                                         \
  }

OO_STORAGE_SPECIFIER ooStatus 
opiReplaceDbPrep (ooTypeNumber typeN, const ooHandle(ooFDObj) & fdH);
OO_STORAGE_SPECIFIER ooDBObj* 
opiReplaceDb (const char *DBname, uint32 initPages = 0,
	      uint32 percentGrow = 0, const char *hostName =  0,
	      const char *pathName =  0, uint32 weight = 1,
	      uint16 userDBID = 0, unsigned pageSize = 0);

// ooReplace() is for DB objects, only.    Deprecated.
#define ooReplace(objType, initializer, clusteringHint)         \
      (opiReplaceDbPrep(ooTypeN(objType), (clusteringHint)) ?   \
	(opiReplaceDb initializer) : (ooDBObj*)0)

OO_STORAGE_SPECIFIER ooStatus ooDelete(ooHandle(ooObj) &);

inline
ooStatus	// added to fix 17055 - ooDelete() fails when passed an ooRef(ooAPObj).
ooDelete(const ooRef(ooAPObj) &objR)
{
   ooHandle(ooAPObj) objH(objR);
   return ooDelete(objH);
}

inline
ooStatus
ooDelete(const ooRef(ooObj) &objR)
{
   ooHandle(ooObj) objH(objR);
   return ooDelete(objH);
}

OO_STORAGE_SPECIFIER ooStatus ooDeleteNoProp(ooHandle(ooObj) &);

inline
ooStatus
ooDeleteNoProp(const ooRef(ooObj) &objR)
{
	ooHandle(ooObj) objH(objR);
	return ooDeleteNoProp(objH);
}

#if !defined(OO_BUILD) && defined(OO_MSC_VISUAL_CXX) && defined(_DEBUG)
extern "C" void DB_STORAGE ooprint(ooHandle(ooObj) *h_obj_ptr);
#endif

#ifdef OO_DDL_TRANSLATION
// Restore the original schema.
#pragma ooschema
#endif

#if defined(_MSC_VER) && !defined(OO_DDL_TRANSLATION)
#pragma pack(pop)
#endif

#ifndef _MSC_VER
typedef ooStatus (*ooErrorHandlerPtr) (ooErrorLevel, ooError&, ooHandle(ooObj)*, char*);
#else
extern "C" {
typedef ooStatus (*ooErrorHandlerPtr) (ooErrorLevel, ooError&, ooHandle(ooObj)*, char*);
}
#endif

inline ooErrorHandlerPtr ooRegErrorHandler(ooErrorHandlerPtr errorHandler)
{
	return (ooErrorHandlerPtr) ooRegErrorHandlerInternal((ooErrorHandlerPtrInternal) errorHandler);
}

OO_STORAGE_SPECIFIER ooErrorHandlerPtr& ooGetErrorHandler();
OO_STORAGE_SPECIFIER ooErrorHandlerPtr& ooGetLastErrorHandler();

// objy internal only
OO_STORAGE_SPECIFIER ooHandle(ooContObj) opiCreateDefaultContObj(ooRef(ooContObj)& contR);
OO_STORAGE_SPECIFIER ooRef(ooObj)& ooNullObjRef();
// snapshot API
#ifndef OO_DDL_TRANSLATION
//SPR19728 - renamed infoFormat to ooInfoFormat and sortOrder to ooSortOrder
OO_STORAGE_SPECIFIER ooStatus
 ooSnapShot(unsigned info = oocAllInfo,
           ooInfoFormat format = oocReadable,
           FILE *filePtr = stdout,
           ooBoolean onException = oocTrue,
           ooSortOrder sort = oocAscending,
           const ooId& scope = oocNullId);
#endif

// class definition for ooQuery, moved from qr/ooUserOper.h
class oqrQueryProxy;

class OO_STORAGE_SPECIFIER ooQuery {

    oqrQueryProxy* query;

public:
    ooQuery();
    ~ooQuery();

    ooStatus  setup(const char* predicate, ooTypeNumber typeN);
    ooStatus  setup(const wchar_t* predicate, ooTypeNumber typeN);
    ooBoolean evaluate(ooHandle(ooObj)& obj);
};

#ifdef OO_GCC_POP
#pragma GCC diagnostic pop
#endif

#endif /* OO_H */
