/**************************************************************************
		Copyright (c) 1989-2000 Objectivity, Inc.
			  All Rights Reserved


	THIS IS UNPUBLISHED PROPRIETARY SOURCE CODE OF OBJECTIVITY, INC.


	The copyright notice above does not evidence any
	actual or intended publication of such source code.


*****************************************************************************/

// This file must match files builtin.ddl, ooSchema.h, and opiBuiltin.C.


#ifndef OO_SCHEMA_REF_H
#define OO_SCHEMA_REF_H "@(#)$Id$"


#if defined(_MSC_VER) && !defined(OO_DDL_TRANSLATION)
#pragma pack(push,8)
#endif

#ifndef OO_H
#include <oo.h>
#endif

// Note that file ooDecl.h is included in the middle of this file.

#if defined(OO_SPARC_CXX50) || defined(OO_HP_CXX) || (defined(OO_GNU_CXX) && OO_GNU_CXX >= 4)
// Use this to suppress compiler warnings about using a string
// literal as a non-const value.  In the next major Objectivity release,
// the affected functions should be changed to return a `const char*'
// so that this cast will not be needed.
#define OO_CHAR_PTR(x) const_cast<char*>(x)
#else
#define OO_CHAR_PTR(x) x
#endif

class OO_STORAGE_SPECIFIER ooObj;
class OO_STORAGE_SPECIFIER ooFDObj;
class OO_STORAGE_SPECIFIER ooAPObj;
class OO_STORAGE_SPECIFIER ooDBObj;
class OO_STORAGE_SPECIFIER ooContObj;
class OO_STORAGE_SPECIFIER ooLookupKey;
class OO_STORAGE_SPECIFIER ooAsObj;

///////////////////////////////////////////////////////////////////////////////

ooTemplateSpecialization
class OO_STORAGE_SPECIFIER ooDeref(ooObj) : public ooDerefBase
{
 public:
  ~ooDerefStructor(ooObj)();
  inline ooObj * operator->() const;
 private:
  friend class ooRef(ooObj);
  ooDerefStructor(ooObj)(ooDeref(ooObj)& deref);
  ooDerefStructor(ooObj)(ooObj * pObject);
};

ooTemplateSpecialization
OO_CLI_PUBLIC
class OO_STORAGE_SPECIFIER ooRef(ooObj) : public ooId
{
  public:
    ooRefStructor(ooObj)() {}
    ooRefStructor(ooObj)(const ooId& id) : ooId(id) {}
    inline
        ooRefStructor(ooObj)(const ooHandleBase &objH) {
	  *this = objH;
	}
    ooRefStructor(ooObj)(const ooObj* pObject);
    ooRef(ooObj)& operator=(const ooId& id);
    ooRef(ooObj)& operator=(const ooShortId& shortId);
    ooRef(ooObj)& operator=(const ooHandleBase& objH);
    ooRef(ooObj)& operator=(const ooObj* pObject);
    inline ooRef(ooObj) &
        operator=(const ooRef(ooObj) &  from) {
	  ooId *thisId = this;
	  *thisId = from;
	  return *this;
	}
    ooBoolean operator==(const ooHandleBase& objH) const;
    ooBoolean operator!=(const ooHandleBase& objH) const;
    ooBoolean operator==(const ooId& id) const;
    ooBoolean operator!=(const ooId& id) const;
    ooBoolean operator==(const ooShortId& shortId) const;
    ooBoolean operator!=(const ooShortId& shortId) const;
    ooBoolean operator==(const ooObj* pObject) const;
    ooBoolean operator!=(const ooObj* pObject) const;

#if OO_LONG_REF
    ooRefStructor(ooObj)(const ooLongId& id);
    ooRef(ooObj)& operator=(const ooLongId& id);
    ooBoolean operator==(const ooLongId& id) const;
    ooBoolean operator!=(const ooLongId& id) const;
#endif

    ooStatus set_container(const ooId& id);
    ooStatus open(ooMode openMode = oocRead) const;
    ooStatus update() const;	/* corrects ooId proto */
    ooStatus close() const;
    ooMode openMode() const;
    ooStatus lookupObj(const ooHandleBase& scopeH, const ooKey& key,
		       ooMode openMode = oocRead);
    ooStatus lookupObj(const ooKey& key, ooMode openMode = oocRead);
    ooStatus lookupObj(const ooHandleBase& scopeH, const char* name,
		       ooMode openMode = oocRead);
    ooStatus nameObj(const ooHandleBase& scopeH, const char* name) const;
    char* getObjName(const ooHandleBase& scopeH) const;
    ooStatus unnameObj(const ooHandleBase& scopeH,
		       const char* name = 0) const;
    ooStatus getNameScope(ooItr(ooObj) &objItr) const;
    ooStatus getNameObj(ooItr(ooObj) &objItr) const;
    ooStatus lock(ooLockMode lockMode) const;
    ooStatus lockNoProp(ooLockMode lockMode) const;
    ooStatus releaseReadLock();
    ooVersMode getVersStatus() const;
    ooStatus setVersStatus(const ooVersMode versMode) const;
    ooStatus getDefaultVers(ooRef(ooObj)& defId) const;
    ooStatus getDefaultVers(ooHandleBase& defH) const;
    ooStatus setDefaultVers() const;
    ooStatus getNextVers(ooHandleBase& nextVersItrH,
			 ooMode openMode = oocNoOpen) const;
    ooStatus getPrevVers(ooRef(ooObj)& prevId) const;
    ooStatus getPrevVers(ooHandleBase& prevH) const;
    ooTypeNumber typeN() const;
    const char* typeName() const;
    ooHandle(ooContObj)	 containedIn() const;
    ooHandle(ooContObj)& containedIn(ooHandle(ooContObj)&) const;
    ooRef(ooContObj)& containedIn(ooRef(ooContObj)&) const;
    ooHandle(ooObj)& copy(const ooHandle(ooObj)& nearH,
			  ooHandle(ooObj)& newObjH) const;
    ooRef(ooObj)& copy(const ooHandle(ooObj)& nearH,
		       ooRef(ooObj)& newObjId) const;
    ooHandle(ooObj) copy(const ooHandle(ooObj)& nearH) const;
    ooStatus move(const ooHandleBase& targetContH);
    ooObj * pin(ooMode openMode = oocRead) const;
    void unpin() const;
    ooDeref(ooObj) operator->() const;
    operator int() const;
    ooBoolean isValid() const;
    void print(FILE* fp = stdout) const;
    char* sprint(char* buf = 0) const;
    // ODMG methods:
    ooRefStructor(ooObj)(const d_Ref_Any &from);
    operator d_Ref_Any() const;
    ooObj *ptr() const;
    int is_null() const;
    void delete_object();
    ooBoolean isNull() const;
    ooBoolean isTransient() const; // SPR 20580
    /********************************************************************
     *									*
     * Note: The following methods are only for internal system usage.	*
     *	     It is subject to change in any future release.		*
     *	     You are not allowed to use it.				*
     *									*
     ********************************************************************/
    /* Use operator=(0) instead */
    /* OBSOLETE */ void nullify();
    /* ooHandle compatibility only -- use operator ooId& cast instead */
    /* OBSOLETE */ const ooId& oid() const { return *this; }
    /* size no longer supported - use sizeof(type) for known type */
    /* OBSOLETE */ uint32 size() const;
    void clear() { ooId::nullify(); } /* ooHandle compatibility only */
    // Special forms to resolve ambiguities for various C++ translators
    ooBoolean operator==(int  zero) const;
    ooBoolean operator!=(int  zero) const;
    ooBoolean operator==(short  zero) const;
    ooBoolean operator!=(short  zero) const;
    ooBoolean operator==(long  zero) const;
    ooBoolean operator!=(long  zero) const;
    ooBoolean operator==(unsigned int  zero) const;
    ooBoolean operator!=(unsigned int  zero) const;
    ooBoolean operator==(unsigned short  zero) const;
    ooBoolean operator!=(unsigned short  zero) const;
    ooBoolean operator==(unsigned long  zero) const;
    ooBoolean operator!=(unsigned long  zero) const;
    ooBoolean isContainerUpdated() const;
    ooStatus refreshOpenContainer(ooMode openMode, ooBoolean *pIsUpdated, 
	 ooBoolean closeHandles = oocFalse, ooBoolean errorIfOpenOoRef = 
#ifdef __SUNPRO_CC   
		oocFalse // SPR 17132
#else
		oocTrue
#endif
    ) const;
 protected:
    ooObj * pin_ref_internal(ooMode openMode = oocRead) const;
};

ooTemplateSpecialization
class OO_STORAGE_SPECIFIER ooShortRef(ooObj) : public ooShortId
{
  public:
    ooShortRefStructor(ooObj)();
    ooShortRefStructor(ooObj)(const ooShortId& shortId);
    ooShortRefStructor(ooObj)(const ooId& id);
    ooShortRefStructor(ooObj)(const ooHandleBase& objH);
    ooShortRefStructor(ooObj)(const ooObj* pObject);
    ooShortRef(ooObj)& operator=(const ooShortId& shortId);
    ooShortRef(ooObj)& operator=(const ooId& id);
    ooShortRef(ooObj)& operator=(const ooHandleBase& objH);
    ooShortRef(ooObj)& operator=(const ooObj* pObject);
    ooBoolean operator==(const ooShortId& shortId) const;
    ooBoolean operator!=(const ooShortId& shortId) const;
    ooBoolean operator==(const ooId& id) const;
    ooBoolean operator!=(const ooId& id) const;
    ooBoolean operator==(const ooHandleBase& objH) const;
    ooBoolean operator!=(const ooHandleBase& objH) const;
    ooBoolean operator==(const ooObj* pObject) const;
    ooBoolean operator!=(const ooObj* pObject) const;
    operator int() const;
    void print(FILE* fp = stdout) const;
    char* sprint(char* buf = 0) const;
    ooBoolean isNull() const;
    /********************************************************************
     *									*
     * Note: The following methods are only for internal system usage.	*
     *	     It is subject to change in any future release.		*
     *	     You are not allowed to use it.				*
     *									*
     ********************************************************************/
    /* Use operator=(0) instead */
    /* OBSOLETE */ void nullify();
    // Special forms to resolve ambiguities for various C++ translators
    ooBoolean operator==(int  zero) const;
    ooBoolean operator!=(int  zero) const;
    ooBoolean operator==(short  zero) const;
    ooBoolean operator!=(short  zero) const;
    ooBoolean operator==(long  zero) const;
    ooBoolean operator!=(long  zero) const;
    ooBoolean operator==(unsigned int  zero) const;
    ooBoolean operator!=(unsigned int  zero) const;
    ooBoolean operator==(unsigned short  zero) const;
    ooBoolean operator!=(unsigned short  zero) const;
    ooBoolean operator==(unsigned long  zero) const;
    ooBoolean operator!=(unsigned long  zero) const;
};


#if OO_LONG_REF
ooTemplateSpecialization
class OO_STORAGE_SPECIFIER ooLongRef(ooObj) : public ooLongId
{
  public:
    ooLongRefStructor(ooObj)() : ooLongId() {}
    ooLongRefStructor(ooObj)(const ooLongId& id) : ooLongId(id) {}
    ooLongRefStructor(ooObj)(const ooHandleBase &objH);
    ooLongRefStructor(ooObj)(const ooObj * pObject);
    ooLongRefStructor(ooObj)(const ooHandle(ooFDObj)&, const ooRef(ooObj)&);
    ooLongRef(ooObj)& operator=(const ooLongId& id)
      { ooLongId::operator=(id); return *this; }
    ooLongRef(ooObj)& operator=(const ooShortId& shortId);
    ooLongRef(ooObj)& operator=(const ooHandleBase& objH)
      { ooLongId::operator=(objH); return *this; }
    ooLongRef(ooObj)& operator=(const ooObj * pObject);
    inline ooLongRef(ooObj) &
        operator=(const ooLongRef(ooObj) & from)
	  {
	    ooLongId *thisId = this;
	    *thisId = from;
	    return *this;
	  }
    ooBoolean operator==(const ooHandleBase& objH) const;
    ooBoolean operator!=(const ooHandleBase& objH) const;
    ooBoolean operator==(const ooLongId& id) const;
    ooBoolean operator!=(const ooLongId& id) const;
    ooBoolean operator==(const ooShortId& shortId) const;
    ooBoolean operator!=(const ooShortId& shortId) const;
    ooBoolean operator==(const ooObj * pObject) const;
    ooBoolean operator!=(const ooObj * pObject) const;
    ooStatus set_container(const ooLongId& id);
    ooStatus open(ooMode openMode = oocRead) const;
    ooStatus close() const;
    ooMode openMode() const;
    ooStatus lookupObj(const ooHandleBase& scopeH, const ooKey& key,
		       ooMode openMode = oocRead);
    ooStatus lookupObj(const ooKey& key, ooMode openMode = oocRead);
    ooStatus lookupObj(const ooHandleBase& scopeH, const char* name,
		       ooMode openMode = oocRead);
    ooStatus nameObj(const ooHandleBase& scopeH, const char* name) const;
    char* getObjName(const ooHandleBase& scopeH) const;
    ooStatus unnameObj(const ooHandleBase& scopeH,
		       const char* name = 0) const;
    ooStatus getNameScope(ooItr(ooObj) &objItr) const;
    ooStatus getNameObj(ooItr(ooObj) &objItr) const;
    ooStatus lock(ooLockMode lockMode) const;
    ooStatus lockNoProp(ooLockMode lockMode) const;
    ooVersMode getVersStatus() const;
    ooStatus setVersStatus(const ooVersMode versMode) const;
    ooStatus getDefaultVers(ooLongRef(ooObj)& defId) const;
    ooStatus getDefaultVers(ooHandleBase& defH) const;
    ooStatus setDefaultVers() const;
    ooStatus getNextVers(ooHandleBase& nextVersItrH,
			 ooMode openMode = oocNoOpen) const;
    ooStatus getPrevVers(ooLongRef(ooObj)& prevId) const;
    ooStatus getPrevVers(ooHandleBase& prevH) const;
    ooTypeNumber typeN() const;
    const char* typeName() const;
    uint32 size() const;
    ooStatus update() const;
    ooHandle(ooContObj)	 containedIn() const;
    ooHandle(ooContObj)& containedIn(ooHandle(ooContObj)&) const;
    ooLongRef(ooContObj)& containedIn(ooLongRef(ooContObj)&) const;
    ooHandle(ooObj)& copy(const ooHandle(ooObj)& nearH,
			  ooHandle(ooObj)& newObjH) const;
    ooLongRef(ooObj)& copy(const ooHandle(ooObj)& nearH,
		       ooLongRef(ooObj)& newObjId) const;
    ooHandle(ooObj) copy(const ooHandle(ooObj)& nearH) const;
    ooStatus move(const ooHandle(ooObj) & targetContH);
    operator int() const;
    ooBoolean isValid() const;

    // ODMG methods:
    ooLongRefStructor(ooObj)(const d_Ref_Any &from);
    operator d_Ref_Any() const;
    ooObj *ptr() const;
    int is_null() const;
    void delete_object();
    // NOT YET - ooBoolean isTransient() const;

    // Special forms to resolve ambiguities for various C++ translators
    ooBoolean operator==(int  zero) const;
    ooBoolean operator!=(int  zero) const;
    ooBoolean operator==(short  zero) const;
    ooBoolean operator!=(short  zero) const;
    ooBoolean operator==(long  zero) const;
    ooBoolean operator!=(long  zero) const;
    ooBoolean operator==(unsigned int  zero) const;
    ooBoolean operator!=(unsigned int  zero) const;
    ooBoolean operator==(unsigned short  zero) const;
    ooBoolean operator!=(unsigned short  zero) const;
    ooBoolean operator==(unsigned long  zero) const;
    ooBoolean operator!=(unsigned long  zero) const;

 protected:
    ooObj * pin(ooMode openMode = oocRead) const;
    void unpin() const;
};

inline
int 
ooLongRef(ooObj)::is_null() const
{
  return ((int) (this->isNull()));

}
#endif /* OO_LONG_REF */


ooTemplateSpecialization
OO_CLI_PUBLIC
class OO_STORAGE_SPECIFIER ooHandle(ooObj) : public ooHandleBase
{
public:
  ooHandleStructor(ooObj)();
  ooHandleStructor(ooObj)(const ooId& id);
  ooHandleStructor(ooObj)(const ooHandle(ooObj)& objH);
  ooHandleStructor(ooObj)(const ooObj* pObject);
  ~ooHandleStructor(ooObj)();
  ooHandle(ooObj)& operator=(const ooId& id);
  ooHandle(ooObj)& operator=(const ooShortId& shortId);
  ooHandle(ooObj)& operator=(const ooHandle(ooObj)& objH);
  ooHandle(ooObj)& operator=(const ooObj* pObject);
  ooBoolean operator==(const ooHandle(ooObj)& objH) const;
  ooBoolean operator!=(const ooHandle(ooObj)& objH) const;
  ooBoolean operator==(const ooId& id) const;
  ooBoolean operator!=(const ooId& id) const;
  ooBoolean operator==(const ooShortId& shortId) const;
  ooBoolean operator!=(const ooShortId& shortId) const;
  ooBoolean operator==(const ooObj* pObject) const;
  ooBoolean operator!=(const ooObj* pObject) const;

#if OO_LONG_REF
  ooHandleStructor(ooObj)(const ooLongId& id);
  ooHandle(ooObj)& operator=(const ooLongId& id);
  ooBoolean operator==(const ooLongId& id) const;
  ooBoolean operator!=(const ooLongId& id) const;
#endif

  ooStatus set_container(const ooHandle(ooObj)& objH);
  ooStatus setId(unsigned dbNum, unsigned contNum, unsigned pageNum, unsigned slotNum);
  // ocmSession parameter is Objectivity internal only
  ooStatus open(ooMode openMode = oocRead, ocmSession* session = 0) const;
  ooStatus update() const;
  ooStatus close() const;
  ooMode openMode() const;
  ooStatus lookupObj(const ooHandle(ooObj)& scopeH,
    const ooKey& key, ooMode openMode = oocRead);
  ooStatus lookupObj(const ooKey& key, ooMode openMode = oocRead);
  ooStatus lookupObj(const ooHandle(ooObj)& scopeH,
    const char* name, ooMode openMode = oocRead);
  ooStatus nameObj(const ooHandle(ooObj)& scopeH, const char* name) const;
  char* getObjName(const ooHandle(ooObj)& scopeH) const;
  ooStatus unnameObj(const ooHandle(ooObj)& scopeH,
    const char* name = 0) const;
  ooStatus getNameScope(ooItr(ooObj)& objItr,
    ooBoolean returnNameObject = oocFalse) const;
  ooStatus getNameObj(ooItr(ooObj)& objItr) const;
  ooStatus lock(ooLockMode lockMode) const;
  ooStatus lockNoProp(ooLockMode lockMode) const;
  ooStatus releaseReadLock();
  ooVersMode getVersStatus() const;
  ooStatus setVersStatus(const ooVersMode versMode) const;
  ooStatus getDefaultVers(ooHandle(ooObj)& defH) const;
  ooStatus getDefaultVers(ooRef(ooObj)& defId) const;
  ooStatus setDefaultVers() const;
  ooStatus getNextVers(ooHandle(ooObj)& nextVersItrH,
    ooMode openMode = oocNoOpen) const;
  ooStatus getPrevVers(ooHandle(ooObj)& prevH) const;
  ooStatus getPrevVers(ooRef(ooObj)& prevId) const;
  ooTypeNumber typeN() const;
  const char* typeName() const;
  ooHandle(ooContObj)	 containedIn() const;
  ooHandle(ooContObj)& containedIn(ooHandle(ooContObj)&) const;
  ooRef(ooContObj)& containedIn(ooRef(ooContObj)&) const;
  ooHandle(ooObj)& copy(const ooHandle(ooObj)& nearH,
    ooHandle(ooObj)& newObjH) const;
  ooRef(ooObj)& copy(const ooHandle(ooObj)& nearH,
    ooRef(ooObj)& newObjId) const;
  ooHandle(ooObj) copy(const ooHandle(ooObj)& nearH) const;
  void fixOoMapRefs() const;
  ooStatus move(const ooHandle(ooObj)& targetContH);
  ooObj * pin(ooMode openMode = oocRead) const;
  void unpin() const;
  ooObj * operator->() const;
  ooObj& operator*() const;
  operator ooObj *() const;
  // The result of the following conversion is not tagged `const' for
  // compatibility reasons, but it must not be modified anyway.
  operator ooId&() const { return *(ooId*)&_id; }
  ooBoolean isValid(ooMode openMode = oocNoOpen) const;
  unsigned getPageFreeSpace() const;
  void print(FILE* fp = stdout) const;
  char* sprint(char* buf = 0) const;
  char* sprintl(char* buf = 0) const;
  // ODMG methods:
  ooHandleStructor(ooObj)(const d_Ref_Any &from);
  operator d_Ref_Any() const;
  ooObj *ptr() const;
  int is_null() const;
  void delete_object();
  ooBoolean isTransient() const; // SPR 20580
  /********************************************************************
  *									*
  * Note: The following methods are only for internal system usage.	*
  *	     It is subject to change in any future release.		*
  *	     You are not allowed to use it.				*
  *									*
  ********************************************************************/
  /* Use operator ooObj *() instead */
  /* OBSOLETE */ ooObj * vm() const;
  /* Use operator=(0) instead */
  /* OBSOLETE */ void nullify();
  /* Use operator ooId&() cast instead */
  /* OBSOLETE */ const ooId& oid() const;
  /* size no longer supported - use sizeof(type) for known type */
  /* OBSOLETE */ uint32 size() const;
  void clear() { nullifyHandleBase(); }

  // Special forms to resolve ambiguities for various C++ translators
  ooBoolean operator==(int  zero) const;
  ooBoolean operator!=(int  zero) const;
  ooBoolean operator==(short  zero) const;
  ooBoolean operator!=(short  zero) const;
  ooBoolean operator==(long  zero) const;
  ooBoolean operator!=(long  zero) const;
  ooBoolean operator==(unsigned int  zero) const;
  ooBoolean operator!=(unsigned int  zero) const;
  ooBoolean operator==(unsigned short  zero) const;
  ooBoolean operator!=(unsigned short  zero) const;
  ooBoolean operator==(unsigned long  zero) const;
  ooBoolean operator!=(unsigned long  zero) const;
  ooHandle(ooObj)* self()	  { return this; }
  ooHandle(ooObj)& get_handle() { return *this; }
  // Warning: get_id is unsafe; for internal use only. 
  // (Assign handle to ooId variable instead.)
  const ooRef(ooObj) &get_id() const {
    return *((ooRef(ooObj) *) (&_id));
  }
  ooBoolean isOID() const { return _state == oocHandleOID; }
  ooBoolean isPTR() const { return _state == oocHandlePTR; }
  ooBoolean isGoodOID() const;
  OO_FORCE_INLINE ooBoolean isOK() const
  {
    return isGoodPTR() || isGoodOID();
  }
  void  print1(FILE* fp = stdout) const;
  void  print2(FILE* fp = stdout) const;
  ooObj *  get_vm() const;
  const   ooId& get_oid() const { return *(ooId*)&_id; }
  uint16  get_region() const { return _region; }
  ooMode  get_openMode() const;
  uint8   get_state() const	 { return _state; }
  ooObj *  get_fast_vm() const	{ return (ooObj*) _ptr._obj; }
  ooOCB*  get_ocb() const	 { return _ptr._ocb; }
  ooHandle(ooObj)* get_next()	 { return ((ooHandle(ooObj) *) (_next)); }
  ooHandle(ooObj)* get_prev()	 { return ((ooHandle(ooObj) *) (_prev)); }
  void  set_state(const uint8 state)	  { _state = state; }
  void  set_id(const ooId& id)	  { _id = id; }
  void  set_vm(ooObj * const vm)	 { _ptr._obj = (char*) vm; }
  void  set_ocb(ooOCB* const ocb)	  { _ptr._ocb = ocb; }
  void  set_next(ooHandle(ooObj)* next) { _next = next; }
  void  set_prev(ooHandle(ooObj)* prev) { _prev = prev; }
  ooStatus link(ocmSession* session);
  void unlink()
  {
    if (_prev)
    {
      ((ooHandle(ooObj) *)_prev)->set_next((ooHandle(ooObj) *)_next);
      ((ooHandle(ooObj) *)_next)->set_prev((ooHandle(ooObj) *)_prev);
      _prev = NULL;
      _next = NULL;
    }
  }
  ooBoolean isContainerUpdated() const;
  ooStatus refreshOpenContainer(ooMode openMode, ooBoolean *pIsUpdated, 
	 ooBoolean closeHandles = oocFalse, ooBoolean errorIfOpenOoRef = 
#ifdef __SUNPRO_CC   
		oocFalse // SPR 17132
#else
		oocTrue
#endif
    ) const;
protected:
  ooObj * pin_obj_internal(ooMode openMode = oocRead) const;
};

ooTemplateSpecialization
OO_CLI_PUBLIC
class OO_STORAGE_SPECIFIER ooItr(ooObj) : public ooHandle(ooObj),
		     public ooIteratorObjOrContObj
{
  public:
    ooItrStructor(ooObj)();
    ~ooItrStructor(ooObj)();
  private:
    // Declared only to prevent implicit definition:
    ooItrStructor(ooObj)(const ooItr(ooObj) &);
    ooItr(ooObj) &    operator=(const ooItr(ooObj) &);
};


///////////////////////////////////////////////////////////////////////////////

ooTemplateSpecialization
class OO_STORAGE_SPECIFIER ooRef(ooAPObj) : public ooRef(ooObj)
{
  public:
    ooRefStructor(ooAPObj)() {}
    ooRefStructor(ooAPObj)(const ooRef(ooAPObj)& id) : ooRef(ooObj)(id) {}
    ooRefStructor(ooAPObj)(const ooHandle(ooAPObj) &objH);
    ooRefStructor(ooAPObj)(const ooAPObj* pObject);
    ooRef(ooAPObj)& operator=(const ooRef(ooAPObj)& id);
    ooRef(ooAPObj)& operator=(const ooHandle(ooAPObj) &objH);
    ooRef(ooAPObj)& operator=(const ooAPObj* pObject);
    ooBoolean exist(const ooHandle(ooFDObj) &containingFdH,
		    const char *apSystemName,
		    ooMode openMode = oocNoOpen);
    ooStatus open(const ooHandle(ooFDObj)& containingFdH,
		  const char* apSystemName,
		  ooMode openMode = oocRead);
    ooStatus open(ooMode openMode = oocRead) const;
    ooStatus update() const;
    ooStatus close() const;
    ooMode openMode() const;
    char* name() const;
    unsigned number() const { return get_DB(); }
    char* lockServerHost() const;
    char* sysDBFileHost() const;
    char* sysDBFilePath() const;
    char* bootFileHost() const;
    char* bootFilePath() const;
    char* jnlDirHost() const;
    char* jnlDirPath() const;
    unsigned int getPartitionWeight() const;
    ooStatus setPartitionWeight(unsigned int weight);

    ooHandle(ooFDObj) containedIn() const;
    ooHandle(ooFDObj)& containedIn(ooHandle(ooFDObj)& containingFd) const;
    ooRef(ooFDObj)& containedIn(ooRef(ooFDObj)& containingFdId) const;
    ooStatus imagesContainedIn(ooItr(ooDBObj) &controlledDbs,
			       ooMode openMode = oocNoOpen) const;
    ooStatus containersControlledBy(ooItr(ooContObj) &directlyControlledConts,
				    ooMode openMode = oocNoOpen) const;
    ooStatus returnAll() const;
    ooTypeNumber typeN() const;
    const char* typeName() const;
    ooBoolean isValid() const;
    void print(FILE* fp = stdout) const;
    char* sprint(char* buf = 0) const;
    ooStatus change(const char* newLockServerHost = 0,
	const char* newSysDBFileHost = 0, const char* newSysDBFilePath = 0,
	const char* newBootFileHost = 0, const char* newBootFilePath = 0,
	const char* newJnlDirHost = 0, const char* newJnlDirPath = 0,
	ooBoolean catalogOnly = oocFalse) const;
    ooStatus markOffline() const;
    ooStatus markOnline() const;
    ooBoolean isOffline() const;
    ooBoolean isAccessible();
    ooBoolean isAvailable() const;
    ooStatus  ensureAllImagesInQuorums();
    uint32 getLockServerTime() const; 
  private:
    void delete_object() {;}
    void lookupObj(const ooHandle(ooObj)&, const ooKey&, ooMode);
    void lookupObj(const ooKey&, ooMode);
    void lookupObj(const ooHandle(ooObj)&, const char*, ooMode);
    void nameObj(const ooHandle(ooObj)&, const char*) const;
    void getObjName(ooHandle(ooObj)&) const;
    void unnameObj(const ooHandle(ooObj)&, const char*) const;
    void getNameScope(ooItr(ooObj)&) const;
    void lockNoProp(ooLockMode) const;
    void releaseReadLock();
    void unlockNoProp() const;
    void getVersStatus() const;
    void setVersStatus(const ooVersMode) const;
    void getDefaultVers(ooHandle(ooObj)&) const;
    void getDefaultVers(ooRef(ooObj)&) const;
    void setDefaultVers() const;
    void getNextVers(ooHandle(ooObj)&, ooMode) const;
    void getPrevVers(ooHandle(ooObj)&) const;
    void getPrevVers(ooRef(ooObj)&) const;
    void copy(const ooHandle(ooObj)&) const;
    void copy(const ooHandle(ooObj)&, ooHandleBase&) const;
    void copy(const ooHandle(ooObj)&, ooRef(ooAPObj)&) const;
    void move(const ooHandle(ooObj)&);
    ooAPObj* pin(ooMode = oocRead) const;
    ooStatus unpin() const;
    ooAPObj* operator->() const;
};

ooTemplateSpecialization
class OO_STORAGE_SPECIFIER ooHandle(ooAPObj) : public ooHandle(ooObj)
{
  public:
    ooHandleStructor(ooAPObj)();
    ooHandleStructor(ooAPObj)(const ooHandle(ooAPObj)& objH);
    ooHandleStructor(ooAPObj)(const ooRef(ooAPObj)& id);
    ooHandleStructor(ooAPObj)(const ooAPObj* pObject);
    ooHandle(ooAPObj)& operator=(const ooHandle(ooAPObj)& objH);
    ooHandle(ooAPObj)& operator=(const ooRef(ooAPObj)& id);
    ooHandle(ooAPObj)& operator=(const ooAPObj* pObject);
    ooBoolean exist(const ooHandle(ooFDObj) &containingFdH,
		    const char* apSystemName,
		    ooMode openMode = oocNoOpen);
    ooStatus open(const ooHandle(ooFDObj) &containingFdH,
		  const char* apSystemName,
		  ooMode openMode = oocRead);
    ooStatus open(ooMode openMode = oocRead) const;
    ooStatus update() const;
    ooStatus close() const;
    ooMode openMode() const;
    char* name() const;
    unsigned number() const { return get_APID(); }
    char* lockServerHost() const;
    char* sysDBFileHost() const;
    char* sysDBFilePath() const;
    char* bootFileHost() const;
    char* bootFilePath() const;
    char* jnlDirHost() const;
    char* jnlDirPath() const;
    unsigned int getPartitionWeight() const;
    ooStatus setPartitionWeight(unsigned int weight);
    ooHandle(ooFDObj) containedIn() const;
    ooHandle(ooFDObj)& containedIn(ooHandle(ooFDObj)& containingFd) const;
    ooRef(ooFDObj)& containedIn(ooRef(ooFDObj)& containingFdId) const;
    ooStatus imagesContainedIn(ooItr(ooDBObj) &controlledDbs,
			       ooMode openMode = oocNoOpen);
    ooStatus containersControlledBy(ooItr(ooContObj) &directlyControlledConts,
				    ooMode openMode = oocNoOpen);
    ooStatus returnAll();
    ooTypeNumber typeN() const;
    const char* typeName() const;
    ooBoolean isValid() const;
    void print(FILE* fp = stdout) const;
    char* sprint(char* buf = 0) const;
    ooStatus change(const char* newLockServerHost = 0,
		    const char* newSysDBFileHost = 0,
		    const char* newSysDBFilePath = 0,
		    const char* newBootFileHost = 0,
		    const char* newBootFilePath = 0,
		    const char* newJnlDirHost = 0,
		    const char* newJnlDirPath = 0,
        ooBoolean catalogOnly = oocFalse) const;
    ooStatus markOffline();
    ooStatus markOnline();
    ooBoolean isOffline();
    ooBoolean isAccessible();
    ooBoolean isAvailable() const;
    ooStatus  ensureAllImagesInQuorums();
    uint32 getLockServerTime() const; 
    /********************************************************************
     *									*
     * Note: The following methods are only for internal system use.	*
     *	     They are subject to change in any future release.		*
     *	     Please do not use them.					*
     *									*
     ********************************************************************/
    /* Use operator=(0) instead */
    /* OBSOLETE */ void nullify();
    ooBoolean isAP() const { return get_state() == oocHandleAP; }
    ooBoolean isGoodAP() const
	{ return isAP() && get_id().get_DB() != 0 && get_id().get_OC() == 0 &&
		 get_id().get_page() == 0 && get_id().get_slot() == 0; }
    uint16 get_APID() const
	{ return get_id().get_DB(); }
    void set_APID(uint16 apId);
    void set_APID(uint16 apId, uint16 region);
  private:
    void delete_object() {;}
    void set_container(const ooHandle(ooObj)&);
    void lookupObj(const ooHandle(ooObj)&, const ooKey&, ooMode);
    void lookupObj(const ooKey&, ooMode);
    void lookupObj(const ooHandle(ooObj)&, const char*, ooMode);
    void nameObj(const ooHandle(ooObj)&, const char*) const;
    void getObjName(const ooHandle(ooObj)&) const;
    void unnameObj(const ooHandle(ooObj)&, const char*) const;
    void getNameScope(ooItr(ooObj)&) const;
    void lockNoProp(ooLockMode);
    void unlockNoProp();
    void releaseReadLock();
    void getVersStatus() const;
    void setVersStatus(const ooVersMode) const;
    void getDefaultVers(ooHandle(ooObj)&) const;
    void getDefaultVers(ooRef(ooObj)&) const;
    void setDefaultVers() const;
    void getNextVers(ooHandle(ooObj)&, ooMode) const;
    void getPrevVers(ooHandle(ooObj)&) const;
    void getPrevVers(ooRef(ooObj)&) const;
    void copy(const ooHandle(ooObj)&, ooHandle(ooAPObj)&) const;
    void copy(const ooHandle(ooObj)&, ooRef(ooAPObj)&) const;
    void copy(const ooHandle(ooObj)&) const;
    void move(const ooHandle(ooObj)&);
    void operator*() const;
    ooAPObj* vm() const;
    ooAPObj* pin(ooMode = oocRead) const;
    ooStatus unpin() const;
    ooAPObj* operator->() const;
};

ooTemplateSpecialization
class OO_STORAGE_SPECIFIER ooItr(ooAPObj) : public ooHandle(ooAPObj)
{
 public:
  opiItr(): dbId(0), inAp(0) , nextInAp(0) {}
  ~opiItr() { if (inAp) delete [] inAp; }
  ooStatus scan(const ooHandle(ooFDObj)& FDhandle, ooMode mode = oocNoOpen);
  ooStatus end();
  ooStatus next();
  void reset() { apItr.reset(); nextInAp = 0; }

 private:
  uint16* inAp; // new catalogs use this
  uint16 dbId; // Objectivity internal use only
  uint16 nextInAp;
  ooMode openWithMode;
  oomAPIterator apItr;
  friend class ooHandle(ooDBObj); // for partitionsContainingImage
  friend class ooHandle(ooFDObj); // for contains
};


ooTemplateSpecialization
class OO_STORAGE_SPECIFIER ooRef(ooFDObj) :
					    public ooRef(ooObj)
{
  public:
    ooRefStructor(ooFDObj)() : ooRef(ooObj)(0) 
      {}
    ooRefStructor(ooFDObj)(const ooHandle(ooFDObj) &objH);
    ooRefStructor(ooFDObj)(const ooFDObj* pObject);
    ooRef(ooFDObj) &
        operator=(const ooRef(ooFDObj)& id)
          {
	    this->ooId::operator=(id);
	    return *this;
	  }
    ooRef(ooFDObj)& operator=(const ooHandle(ooFDObj) &objH);
    ooRef(ooFDObj)& operator=(const ooFDObj* pObject);
    ooBoolean exist(const char* bootFilePath = 0,
		    ooMode openMode = oocNoOpen);
    ooStatus open(const char* bootFilePath = 0,
		  ooMode openMode = oocRead,
		  ooBoolean recover = oocFalse,
		  ooGlobalTransStatusFunc statusFunc = 0);
    ooStatus close() const;
    ooStatus convertObjects (ooBoolean purge_schema = oocFalse);
    ooStatus upgradeObjects (ooBoolean purge_schema = oocFalse) ;
    ooStatus setConversion (const char *class_name,
			    ooConvertFunction conversion_func) const ;
    ooStatus update() const;
    ooMode openMode() const;
    char* name() const;
    ooStatus lock(ooLockMode lockMode) const;
    ooStatus unlock() const;
    ooStatus contains(ooItr(ooDBObj) &dbItr,
		      ooMode mode = oocNoOpen,
		      ooBoolean visitForeign = oocFalse) const;
    ooStatus contains(ooItr(ooAPObj)& containedAPs,
		      ooMode openMode = oocNoOpen) const;
    ooHandle(ooAPObj) bootAP() const;
    ooHandle(ooAPObj)& bootAP(ooHandle(ooAPObj)& bootAP) const;
    ooRef(ooAPObj)& bootAP(ooRef(ooAPObj)& bootAP) const;
    ooTypeNumber typeN() const;
    const char* typeName() const;
    ooBoolean isValid() const;
    void print(FILE* fp = stdout) const;
    char* sprint(char* buf = 0) const;
    ooStatus dumpCatalog(FILE* outputFile = stdout,
			 ooFileNameFormat format = oocHostLocal,
			 ooBoolean printLabels = oocTrue) const;
    ooStatus dumpCatalog(FILE* outputFile,
			 ooFileNameFormat format,
			 FILE* reportFile) const;
    ooStatus change(const char* name = 0, const char* lockServerName = 0,
		    uint32 number = 0, FILE* fp = stdout) const;
    char* lockServerName() const;
    uint32 number() const;
    uint32 pageSize() const;
    ooStatus tidy(FILE* fp = stdout, const char* hostName = 0,
		  const char* pathName = 0) const;
    unsigned newQueryAgent(const char* DBname, 
                  const char* hostName,
                  const char* queryAgent, const char* parameters = NULL,
                  unsigned userDBID = 0, unsigned pageSize = 0);
  private:
    void delete_object() {;}
    void lookupObj(const ooHandle(ooObj)&, const ooKey&, ooMode);
    void lookupObj(const ooKey&, ooMode);
    void lookupObj(const ooHandle(ooObj)&, const char*, ooMode);
    void nameObj(const ooHandle(ooObj)&, const char*) const;
    void getObjName(const ooHandle(ooObj)&) const;
    void unnameObj(const ooHandle(ooObj)&, const char*) const;
    void getNameScope(ooItr(ooObj)&) const;
    void lockNoProp(ooLockMode) const;
    void unlockNoProp() const;
    void releaseReadLock();
    void getVersStatus() const;
    void setVersStatus(const ooVersMode) const;
    void getDefaultVers(ooHandle(ooObj)&) const;
    void setDefaultVers() const;
    void getNextVers(ooHandle(ooObj)&, ooMode) const;
    void getPrevVers(ooRef(ooObj)&) const;
    void getPrevVers(ooHandle(ooObj)&) const;
    void containedIn() const;
    void containedIn(ooHandle(ooObj)&) const;
    void containedIn(ooRef(ooObj)&) const;
    void copy(const ooHandle(ooObj)&, ooHandleBase&) const;
    void copy(const ooHandle(ooObj)&, ooRef(ooFDObj)&) const;
    void copy(const ooHandle(ooObj)&) const;
    void move(const ooHandle(ooObj)&);
    ooFDObj* pin(ooMode = oocRead) const;
    ooStatus unpin() const;
    ooFDObj* operator->() const;
};

ooTemplateSpecialization
class OO_STORAGE_SPECIFIER ooHandle(ooFDObj) :
					     public ooHandle(ooObj)
{
  public:
    ooHandleStructor(ooFDObj)();
    ooHandleStructor(ooFDObj)(const ooRef(ooFDObj)& id);
    ooHandleStructor(ooFDObj)(const ooHandle(ooFDObj)& objH);
    void backup(const char* toDirectory = 0, const char* toHost = 0, bool deleteReplacedPages = false, bool systemDbOnly = false, const char* backupName = "backup");
    ooStatus convertObjects (ooBoolean purge_schema = oocFalse);
    ooStatus upgradeObjects (ooBoolean purge_schema = oocFalse) ;
    ooHandleStructor(ooFDObj)(const ooFDObj* pObject);
    ooHandle(ooFDObj)& operator=(const ooRef(ooFDObj)& id);
    ooHandle(ooFDObj)& operator=(const ooHandle(ooFDObj)& objH);
    ooHandle(ooFDObj)& operator=(const ooFDObj* pObject);
    ooBoolean exist(const char* bootFilePath = 0,
		    ooMode openMode = oocNoOpen);
    ooStatus open(const char* bootFilePath = 0,
		  ooMode openMode = oocRead,
		  ooBoolean recover = oocFalse,
		  ooGlobalTransStatusFunc statusFunc = 0);
    ooStatus update() const;
    ooStatus close() const;
    ooStatus setConversion (const char *class_name,
			    ooConvertFunction conversion_func) const ;
    ooMode openMode() const;
    char* name() const;
    ooStatus lock(ooLockMode lockMode) const;
    ooStatus unlock() const;
    ooStatus contains(ooItr(ooDBObj) &dbItr,
		      ooMode mode = oocNoOpen,
		      ooBoolean visitForeign = oocFalse) const;
    ooStatus contains(ooItr(ooAPObj)& containedAPs,
		      ooMode openMode = oocNoOpen) const;
    ooHandle(ooAPObj) bootAP();
    ooHandle(ooAPObj)& bootAP(ooHandle(ooAPObj)& bootAP);
    ooRef(ooAPObj)& bootAP(ooRef(ooAPObj)& bootAPId);
    ooHandle(ooDBObj) hasDb(unsigned dbId, ooMode openMode = oocNoOpen);
    ooTypeNumber typeN() const;
    const char* typeName() const;
    ooBoolean isValid() const;
    void print(FILE* fp = stdout) const;
    char* sprint(char* buf = 0) const;
    ooStatus dumpCatalog(FILE* outputFile = stdout,
			 ooFileNameFormat format = oocHostLocal,
			 ooBoolean printLabels = oocTrue,
       uint16 apId = 0,
       ooBoolean apFileInfo = oocFalse) const;
    ooStatus dumpCatalog(FILE* outputFile,
			 ooFileNameFormat format,
			 FILE* reportFile) const;
    ooStatus change(const char* bootFilePath = 0,
		    const char* lockServerName = 0,
		    uint32 number = 0, FILE* fp = stdout) const;
    char* lockServerName() const;
    uint32 number() const;
    uint32 pageSize() const;
    ooStatus tidy(FILE* fp = stdout, const char* hostName = 0,
		  const char* pathName = 0) const;
    char* sprintl(char* buf = 0) const;
    ooBoolean isR9catalog() const; // new catalog format?
    /********************************************************************
     *									*
     * Note: The following methods are only for internal system usage.	*
     *	     It is subject to change in any future release.		*
     *	     You are not allowed to use it.				*
     *									*
     ********************************************************************/
    /* Use operator=(0) instead */
    /* OBSOLETE */ void nullify();
    ooBoolean isFD() const { return get_state() == oocHandleFD; }
    ooBoolean isGoodFD() const
	{ return isFD() && get_id().get_DB() != 0   &&
		 get_id().get_OC() == 0 &&
		 get_id().get_page() == 0 && get_id().get_slot() == 0; }
    uint32 get_fdnum() const { return (uint32) get_id().get_DB(); }
    unsigned newQueryAgent(const char* DBname, 
                  const char* hostName,
                  const char* queryAgent, const char* parameters = NULL,
                  unsigned userDBID = 0, unsigned pageSize = 0);

  private:
    void delete_object() {;}
    void set_container(const ooHandle(ooObj)&);
    void lookupObj(const ooHandle(ooObj)&, const ooKey&, ooMode);
    void lookupObj(const ooKey&, ooMode);
    void lookupObj(const ooHandle(ooObj)&, const char*, ooMode);
    void nameObj(const ooHandle(ooObj)&, const char*) const;
    void getObjName(const ooHandle(ooObj)&) const;
    void unnameObj(const ooHandle(ooObj)&, const char*) const;
    void getNameScope(ooItr(ooObj)&) const;
    void lockNoProp(ooLockMode);
    void unlockNoProp();
    void releaseReadLock();
    void getVersStatus() const;
    void setVersStatus(const ooVersMode) const;
    void getDefaultVers(ooHandle(ooObj)&) const;
    void setDefaultVers() const;
    void getNextVers(ooHandle(ooObj)&, ooMode) const;
    void getPrevVers(ooHandle(ooObj)&) const;
    void containedIn() const;
    void containedIn(ooHandle(ooObj)&) const;
    void copy(const ooHandle(ooObj)&, ooHandle(ooFDObj)&) const;
    void copy(const ooHandle(ooObj)&, ooRef(ooFDObj)&) const;
    void copy(const ooHandle(ooObj)&) const;
    void move(const ooHandle(ooObj)&);
    void operator*() const;
    ooFDObj* vm() const;
    ooFDObj* pin(ooMode = oocRead) const;
    ooStatus unpin() const;
    ooFDObj* operator->() const;
};

ooTemplateSpecialization
class OO_STORAGE_SPECIFIER ooRef(ooDBObj) : public ooRef(ooObj)
{
  public:
    ooRefStructor(ooDBObj)() {}
    ooRefStructor(ooDBObj)(const ooRef(ooDBObj)& id) : ooRef(ooObj)(id) {}
    ooStatus convertObjects () ;
    ooRefStructor(ooDBObj)(const ooHandle(ooDBObj)& objH);
    ooRefStructor(ooDBObj)(const ooDBObj* pObject);
    ooRef(ooDBObj)& operator=(const ooRef(ooDBObj)& id);
    ooRef(ooDBObj)& operator=(const ooHandle(ooDBObj)& objH);
    ooRef(ooDBObj)& operator=(const ooDBObj* pObject);
    ooBoolean exist(const ooHandle(ooFDObj)& FDhandle,
		    const char* DBname, ooMode openMode = oocNoOpen);
    ooBoolean isReadOnly();
    ooStatus setReadOnly(ooBoolean readOnly, ooBoolean forceLockOverride = oocFalse);
    ooStatus open(const ooHandle(ooFDObj)& FDhandle,
		  const char* DBname, ooMode openMode = oocRead);
    ooStatus open(ooMode openMode = oocRead) const;
    ooStatus close() const;
    ooStatus update() const;
    ooMode openMode() const;
    ooStatus deleteDb(bool catalogOnly = false); // delete database
    char* name() const;
    unsigned number() const { return get_DB(); }
    char* hostName() const;
    char* pathName() const;
    char* fileName() const;
    uint32 pageSize() const;
    ooStatus lock(ooLockMode lockMode) const;
    ooStatus unlock() const;
    ooStatus contains(ooItr(ooContObj) &contItr,
		      ooMode mode= oocNoOpen,
		      ooContainsFilter whichConts = oocAllObjs) const;
    ooHandle(ooFDObj)  containedIn() const;
    ooHandle(ooFDObj)& containedIn(ooHandle(ooFDObj)&) const;
    ooRef(ooFDObj)&    containedIn(ooRef(ooFDObj)&) const;
    ooStatus changePartition(const ooHandle(ooAPObj)& newControllingAP) const;
    ooHandle(ooContObj)	getDefaultContObj(ooMode mode = oocNoOpen) const;
    ooHandle(ooContObj) &getDefaultContObj(ooHandle(ooContObj)& contHandle,
					   ooMode mode= oocNoOpen) const;
    ooRef(ooContObj) &getDefaultContObj(ooRef(ooContObj)& contHandle,
					ooMode mode = oocNoOpen) const;
    ooTypeNumber typeN() const;
    const char* typeName() const;
    ooBoolean isValid() const;
    ooStatus change(const char* name = 0, const char* hostName = 0,
		    const char* pathName = 0, FILE* fp = stdout,
           ooBoolean catalogOnly = oocFalse) const;
    ooStatus tidy(FILE* fp = stdout, const char* hostName = 0,
		  const char* pathName = 0) const;
    unsigned long numContObjs() const;
    ooBoolean isReplicated() const;
    ooBoolean hasImageIn(const ooHandle(ooAPObj) &) const;
    unsigned int numImages() const;
    ooAvailability availability() const;
    ooBoolean isImageAccessible(const ooHandle(ooAPObj)&) const;
    ooStatus  ensureImageInQuorum(const ooHandle(ooAPObj)&);
    ooBoolean isAvailable() const;
    ooBoolean isImageAvailable(const ooHandle(ooAPObj) &) const;
    ooStatus  getReadImage(ooHandle(ooAPObj)&) const;
    ooStatus  setReadImage(const ooHandle(ooAPObj) &);
    ooStatus replicate(const ooHandle(ooAPObj) &,
		       const char * hostName = 0,
		       const char * pathName = 0,
		       uint32 weight = 1) const;
    ooStatus deleteImage(const ooHandle(ooAPObj) &,
			 ooBoolean deleteDBifLast = oocFalse,
			 ooBoolean catalogOnly = oocFalse) const;
    ooStatus partitionsContainingImage(ooItr(ooAPObj) & iterator) const;
    uint32 getImageWeight(const ooHandle(ooAPObj) &) const;
    ooStatus setImageWeight(const ooHandle(ooAPObj) &,
			    uint32 weight) const;
    const char * getImageFileName(const ooHandle(ooAPObj) &) const;
    const char * getImagePathName(const ooHandle(ooAPObj) &) const;
    const char * getImageHostName(const ooHandle(ooAPObj) &) const;
    ooHandle(ooAPObj) getTieBreaker() const;
    ooStatus setTieBreaker(const ooHandle(ooAPObj) &, unsigned weight=1) const;
    ooHandle(ooAPObj) containingPartition() const;
    ooHandle(ooAPObj) & containingPartition(ooHandle(ooAPObj) & result) const;
    ooRef(ooAPObj) & containingPartition(ooRef(ooAPObj) & result) const;
    ooStatus setAllowNonQuorumRead(ooBoolean value = oocTrue) const;
    ooBoolean getAllowNonQuorumRead() const;
    ooBoolean isNonQuorumRead() const;
    ooStatus negotiateQuorum(ooMode openMode);
    ooBoolean isExternalSearchAgent() const; // ESA pseudo database?
    ooBoolean getESAinfo(char* SOname, unsigned int SOnameLen, // Fetch ESA info
                         char* parameters, unsigned int parametersLen) const;
    ooBoolean parseESAstring(const char* namePlusParam, 
                             char* SOname, unsigned int SOnameLen, 
                             char* parameters, unsigned int parametersLen) const;
  private:
    void delete_object() {;}
    void lookupObj(const ooHandle(ooObj)&, const ooKey&, ooMode);
    void lookupObj(const ooKey&, ooMode);
    void lookupObj(const ooHandle(ooObj)&, const char*, ooMode);
    void nameObj(const ooHandle(ooObj)&, const char*) const;
    void getObjName(ooHandle(ooObj)&) const;
    void unnameObj(const ooHandle(ooObj)&, const char*) const;
    void getNameScope(ooItr(ooObj)&) const;
    void lockNoProp(ooLockMode) const;
    void unlockNoProp() const;
    void releaseReadLock();
    void getVersStatus() const;
    void setVersStatus(const ooVersMode) const;
    void getDefaultVers(ooHandle(ooObj)&) const;
    void getDefaultVers(ooRef(ooObj)&) const;
    void setDefaultVers() const;
    void getNextVers(ooHandle(ooObj)&, ooMode) const;
    void getPrevVers(ooHandle(ooObj)&) const;
    void getPrevVers(ooRef(ooObj)&) const;
    void copy(const ooHandle(ooObj)&) const;
    void copy(const ooHandle(ooObj)&, ooHandleBase&) const;
    void copy(const ooHandle(ooObj)&, ooRef(ooDBObj)&) const;
    void move(const ooHandle(ooObj)&);
    ooDBObj* pin(ooMode = oocRead) const;
    ooStatus unpin() const;
    ooDBObj* operator->() const;
};

ooTemplateSpecialization
class OO_STORAGE_SPECIFIER ooHandle(ooDBObj) :
					     public ooHandle(ooObj)
{
  public:
    ooHandleStructor(ooDBObj)();
    ooHandleStructor(ooDBObj)(const ooRef(ooDBObj)& id);
    ooHandleStructor(ooDBObj)(unsigned dbId);
    ooHandleStructor(ooDBObj)(int dbId);
    ooHandleStructor(ooDBObj)(const ooHandle(ooDBObj)& objH);
    ooHandleStructor(ooDBObj)(const ooDBObj* pObject);
    ooStatus convertObjects () ;
    ooHandle(ooDBObj)& operator=(unsigned dbId)
    {
      _id._DB = (uint16) dbId;
      return *this;
    }
    ooHandle(ooDBObj)& operator=(int dbId)
    {
      _id._DB = (uint16) dbId;
      return *this;
    }
    ooHandle(ooDBObj)& operator=(const ooRef(ooDBObj)& id);
    ooHandle(ooDBObj)& operator=(const ooHandle(ooDBObj)& objH);
    ooHandle(ooDBObj)& operator=(const ooDBObj* pObject);
    ooHandle(ooContObj) hasContainer(unsigned contId, ooMode openMode = oocRead);
    ooBoolean exist(const ooHandle(ooFDObj)& FDhandle,
		    const char* DBname, ooMode openMode = oocNoOpen);
    ooStatus open(const ooHandle(ooFDObj)& FDhandle,
		  const char* DBname, ooMode openMode = oocRead);
    ooStatus open(ooMode openMode = oocRead) const;
    ooBoolean isReadOnly();
    ooStatus setReadOnly(ooBoolean readOnly,
			 ooBoolean forceLockOverride = oocFalse);
    ooStatus update() const;
    ooStatus close() const;
    ooMode openMode() const;
    ooStatus deleteDb(bool catalogOnly = false); // delete database
    char* name() const;
    unsigned number() const { return get_id().get_DB(); }
    void setDbId(unsigned number) { _id._DB = (uint16)number; }
    char* hostName() const;
    char* pathName() const;
    char* fileName() const;
    uint32 pageSize() const;
    ooStatus lock(ooLockMode lockMode) const;
    ooStatus unlock() const;
    ooStatus contains(ooItr(ooContObj) &contItr,
		      ooMode mode = oocNoOpen,
		      ooContainsFilter whichConts = oocAllObjs) const;
    ooHandle(ooFDObj)  containedIn() const;
    ooHandle(ooFDObj)& containedIn(ooHandle(ooFDObj)&) const;
    ooRef(ooFDObj)&    containedIn(ooRef(ooFDObj)&) const;
    ooStatus changePartition(const ooHandle(ooAPObj)& newControllingAP);
    ooHandle(ooContObj) getDefaultContObj(ooMode mode = oocNoOpen) const;
    ooHandle(ooContObj)& getDefaultContObj(
				ooHandle(ooContObj)& contHandle,
				ooMode mode = oocNoOpen) const;
    ooRef(ooContObj)& getDefaultContObj(ooRef(ooContObj)& contHandle,
					ooMode mode = oocNoOpen) const;
    unsigned numberOfContainerFiles() const;
    ooTypeNumber typeN() const;
    const char* typeName() const;
    ooBoolean isValid() const;
    ooStatus change(const char* name = 0, const char* hostName = 0,
		    const char* pathName = 0, FILE* fp = stdout,
		    ooBoolean catalogOnly = oocFalse) const;
    ooStatus tidy(FILE* fp = stdout, const char* hostName = 0,
		  const char* pathName = 0) const;
    ooBoolean isR9catalog() const; // new catalog format?
    ooBoolean isExternalSearchAgent() const; // ESA pseudo database?
    ooBoolean getESAinfo(char* SOname, unsigned int SOnameLen, // Fetch ESA info
                         char* parameters, unsigned int parametersLen) const;
    ooBoolean parseESAstring(const char* namePlusParam, 
                             char* SOname, unsigned int SOnameLen, 
                             char* parameters, unsigned int parametersLen) const;
    /********************************************************************
     *									*
     * Note: The following methods are only for internal system usage.	*
     *	     It is subject to change in any future release.		*
     *	     You are not allowed to use it.				*
     *									*
     ********************************************************************/
    /* Use operator=(0) instead */
    /* OBSOLETE */ void nullify();
    ooBoolean isDB() const { return get_state() == oocHandleDB; }
    ooBoolean isGoodDB() const
	{ return isDB() && get_id().get_DB() != 0   &&
		 get_id().get_OC() == 0 &&
		 get_id().get_page() == 0 && get_id().get_slot() == 0; }
    unsigned long numContObjs() const;
    ooBoolean isReplicated() const;
    ooBoolean hasImageIn(const ooHandle(ooAPObj) &) const;
    unsigned int numImages() const;
    ooAvailability availability() const;
    ooBoolean isImageAccessible(const ooHandle(ooAPObj)&) const;
    ooStatus  ensureImageInQuorum(const ooHandle(ooAPObj)&);
    ooBoolean isAvailable() const;
    ooBoolean isImageAvailable(const ooHandle(ooAPObj) &) const;
    ooStatus  getReadImage(ooHandle(ooAPObj)&) const;
    ooStatus  setReadImage(const ooHandle(ooAPObj) &);
    ooStatus replicate(const ooHandle(ooAPObj) &,
		       const char * hostName = 0,
		       const char * pathName = 0,
		       uint32 weight = 1,
           ooBoolean catalogOnly = oocFalse) const;
    ooStatus deleteImage(const ooHandle(ooAPObj) &,
			 ooBoolean deleteDBifLast = oocFalse, ooBoolean catalogOnly = oocFalse) const;
    ooStatus partitionsContainingImage(ooItr(ooAPObj) & iterator) const;
    uint32 getImageWeight(const ooHandle(ooAPObj) &) const;
    ooStatus setImageWeight(const ooHandle(ooAPObj) &,
			uint32 weight) const;
    const char * getImageFileName(const ooHandle(ooAPObj) &) const;
    const char * getImagePathName(const ooHandle(ooAPObj) &) const;
    const char * getImageHostName(const ooHandle(ooAPObj) &) const;
    ooHandle(ooAPObj) getTieBreaker() const;
    ooStatus setTieBreaker(const ooHandle(ooAPObj) &, unsigned weight=1) const;
    ooHandle(ooAPObj) containingPartition() const;
    ooHandle(ooAPObj) & containingPartition(ooHandle(ooAPObj) & result) const;
    ooRef(ooAPObj) & containingPartition(ooRef(ooAPObj) & result) const;
    ooStatus setAllowNonQuorumRead(ooBoolean value = oocTrue) const;
    ooBoolean getAllowNonQuorumRead() const;
    ooBoolean isNonQuorumRead() const;
    ooStatus negotiateQuorum(ooMode openMode);
  private:
    void delete_object() {;}
    void set_container(const ooHandle(ooObj)&);
    void lookupObj(const ooHandle(ooObj)&, const ooKey&, ooMode);
    void lookupObj(const ooKey&, ooMode);
    void lookupObj(const ooHandle(ooObj)&, const char*, ooMode);
    void nameObj(const ooHandle(ooObj)&, const char*) const;
    void getObjName(const ooHandle(ooObj)&) const;
    void unnameObj(const ooHandle(ooObj)&, const char*) const;
    void getNameScope(ooItr(ooObj)&) const;
    void lockNoProp(ooLockMode);
    void unlockNoProp();
    void releaseReadLock();
    void getVersStatus() const;
    void setVersStatus(const ooVersMode) const;
    void getDefaultVers(ooHandle(ooObj)&) const;
    void getDefaultVers(ooRef(ooObj)&) const;
    void setDefaultVers() const;
    void getNextVers(ooHandle(ooObj)&, ooMode) const;
    void getPrevVers(ooHandle(ooObj)&) const;
    void getPrevVers(ooRef(ooObj)&) const;
    void copy(const ooHandle(ooObj)&, ooHandle(ooDBObj)&) const;
    void copy(const ooHandle(ooObj)&, ooRef(ooDBObj)&) const;
    void copy(const ooHandle(ooObj)&) const;
    void move(const ooHandle(ooObj)&);
    void operator*() const;
    ooDBObj* vm() const;
    ooDBObj* pin(ooMode = oocRead) const;
    ooStatus unpin() const;
    ooDBObj* operator->() const;
};

ooTemplateSpecialization
class OO_STORAGE_SPECIFIER ooItr(ooDBObj) :
					    public ooHandle(ooDBObj),
					    public ooIterator
{
  public:
    ooItrStructor(ooDBObj)();
    ~ooItrStructor(ooDBObj)();
    ooBoolean next();
    ooStatus scan(const ooHandle(ooFDObj)& FDhandle,ooMode mode = oocNoOpen,ooBoolean visitForeign=oocFalse);
    uint16 apId; // used by new catalogs when iterating over all DB's contained in a certain ap
    bool visitForeign;
  private:
    // Declared only to prevent implicit definition:
    ooItrStructor(ooDBObj)(const ooItr(ooDBObj) &);
    ooItr(ooDBObj) &    operator=(const ooItr(ooDBObj) &);
};


///////////////////////////////////////////////////////////////////////////////

ooTemplateSpecialization
class OO_STORAGE_SPECIFIER ooDeref(ooContObj) : public ooDerefBase
{
public:
    ~ooDerefStructor(ooContObj)();
    inline ooContObj * operator->() const;
 private:
    //friend class ooRef(ooObj); VisualC++ 6.0 (sp4): error C2908: explicit specialization; 'opiRef<class ooObj>' has already been instantiated from the primary template
    friend class ooRef(ooContObj);
    ooDerefStructor(ooContObj)(ooDeref(ooContObj)& deref);
    ooDerefStructor(ooContObj)(ooObj * pObject);
};

ooTemplateSpecialization
class OO_STORAGE_SPECIFIER ooRef(ooContObj) :
					      public ooRef(ooObj)
{
  public:
    ooRefStructor(ooContObj)() {}
    ooRefStructor(ooContObj)(const ooRef(ooContObj)& id):ooRef(ooObj)(0)
      { *this = id; }
    ooStatus convertObjects () ;
    ooRefStructor(ooContObj)(const ooHandle(ooContObj) &objH);
    ooRefStructor(ooContObj)(const ooContObj* pObject);
    inline ooRef(ooContObj)& operator=(const ooRef(ooContObj)& id);
    inline ooRef(ooContObj)& operator=(const ooShortRef(ooContObj) &shortId);
    inline ooRef(ooContObj)& operator=(const ooHandle(ooContObj) &objH);
    inline ooRef(ooContObj)& operator=(const ooContObj* pObject);
    ooBoolean exist(const ooHandle(ooDBObj)& DBhandle, const char* contName,
		    ooMode openMode = oocNoOpen);
    ooStatus open(ooMode openMode = oocRead) const;
    ooStatus open(const ooHandle(ooDBObj)& DBhandle, const char* contName,
		  ooMode openMode = oocRead);
    ooStatus close(const ooCloseMode closeMode = oocCloseOnly) const;
    char* name() const;
    unsigned number() const { return get_OC(); }
    ooMode openMode() const;
    ooBoolean isUpdated() const;
    ooStatus refreshOpen(ooMode openMode,
			 ooBoolean *pIsUpdated,
			 ooBoolean closeHandles = oocFalse) const;
    ooStatus lockNoProp(ooLockMode lockMode) const;
    unsigned maxPagesForSmallPageMap() const;
    ooStatus unlockNoProp() const;
    ooStatus contains(ooItr(ooObj)& objItr,
		      ooMode mode = oocNoOpen) const;
    ooHandle(ooDBObj)  containedIn() const;
    ooHandle(ooDBObj)& containedIn(ooHandle(ooDBObj)&) const;
    ooRef(ooDBObj)& containedIn(ooRef(ooDBObj)&) const;
    ooHandle(ooAPObj) controlledBy() const;
    ooHandle(ooAPObj)& controlledBy(ooHandle(ooAPObj)& controllingAP) const;
    ooRef(ooAPObj)& controlledBy(ooRef(ooAPObj)& controllingAPId) const;
    ooStatus transferControl(const ooHandle(ooAPObj)& newControllingAP) const;
    ooStatus returnControl() const;
    ooContObj * pin(ooMode openMode = oocRead) const;
    ooDeref(ooContObj) operator->() const;
    ooStatus lookupObj(const ooHandle(ooObj)& scopeH,
		       const char* name,
		       ooMode openMode = oocRead);
    int32  hash() const;
    uint32 nPage() const;
    uint32 percentGrow() const;
    uint32 numLogicalPages() const;   // largest logical page number used
    uint32 countLogicalPages() const; // count allocated logical pages
    // ODMG methods:
    ooRefStructor(ooContObj)(const d_Ref_Any &from);
    ooContObj *ptr() const;
  private:
    void lookupObj(ooHandle(ooObj)&, const ooKey&, ooMode);
    void lookupObj(const ooKey&, ooMode);
    void getVersStatus() const;
    void setVersStatus(const ooVersMode) const;
    void getDefaultVers(ooHandle(ooObj)&) const;
    void getDefaultVers(ooRef(ooObj)&) const;
    void setDefaultVers() const;
    void getNextVers(ooHandle(ooObj)&, ooMode) const;
    void getPrevVers(ooHandle(ooObj)&) const;
    void getPrevVers(ooRef(ooObj)&) const;
    void copy(const ooHandle(ooObj)&, ooHandleBase&) const;
    void copy(const ooHandle(ooObj)&, ooRef(ooContObj)&) const;
    void copy(const ooHandle(ooObj)&) const;
    void move(const ooHandle(ooObj)&);
 protected:
    ooObj * pin_ref_internal(ooMode openMode = oocRead) const;
};

ooTemplateSpecialization
class OO_STORAGE_SPECIFIER ooShortRef(ooContObj) : public ooShortRef(ooObj)
{
  public:
    ooShortRefStructor(ooContObj)();
    ooShortRefStructor(ooContObj)(const ooShortRef(ooContObj)& shortId);
    ooShortRefStructor(ooContObj)(const ooRef(ooContObj)& id);
    ooShortRefStructor(ooContObj)(const ooHandle(ooContObj) &objH);
    ooShortRefStructor(ooContObj)(const ooContObj* pObject);
    ooShortRef(ooContObj)& operator=(const ooShortRef(ooContObj)& shortId);
    ooShortRef(ooContObj)& operator=(const ooRef(ooContObj)& id);
    ooShortRef(ooContObj)& operator=(const ooHandle(ooContObj) &objH);
    ooShortRef(ooContObj)& operator=(const ooContObj* pObject);
};

ooTemplateSpecialization
class OO_STORAGE_SPECIFIER ooHandle(ooContObj) : public ooHandle(ooObj)
{
  public:
    ooHandleStructor(ooContObj)();
    inline ooHandleStructor(ooContObj)(const ooHandle(ooContObj)& objH);
    inline ooHandleStructor(ooContObj)(const ooRef(ooContObj)& id);
    ooStatus convertObjects () ;
    ooHandleStructor(ooContObj)(const ooContObj* pObject);
    ooHandleStructor(ooContObj)(const ooId& id);
    ooHandle(ooContObj)& operator=(const ooRef(ooContObj)& id);
    ooHandle(ooContObj)& operator=(const ooHandle(ooContObj)& objH);
    ooHandle(ooContObj)& operator=(const ooShortRef(ooContObj)& shortId);
    ooHandle(ooContObj)& operator=(const ooContObj* pObject);
    ooStatus change(const char* name = 0, const char* hostName = 0, const char* pathName = 0, ooBoolean catalogOnly = oocFalse) const;
    ooBoolean exist(const ooHandle(ooDBObj)& DBhandle, const char* contName, ooMode openMode = oocNoOpen);
    const char* fileName() const;
    const char* hostName() const;
    const char* pathName() const;
    unsigned maxPagesForSmallPageMap() const;
    uint32 pageSize() const;
    ooStatus open(ooMode openMode = oocRead) const;
    ooStatus open(const ooHandle(ooDBObj)& DBhandle, const char* contName, ooMode openMode = oocRead);
    ooStatus close(const ooCloseMode closeMode = oocCloseOnly) const;
    ooBoolean hasName() const;
    char* name() const;
    unsigned number() const;
    ooMode openMode() const;
    ooBoolean isUpdated() const;
    ooStatus refreshOpen(ooMode openMode, ooBoolean *pIsUpdated, 
	 ooBoolean closeHandles = oocFalse, ooBoolean errorIfOpenOoRef = 
#ifdef __SUNPRO_CC   
		oocFalse // SPR 17132
#else
		oocTrue
#endif
	 ) const;
    ooStatus lockNoProp(ooLockMode lockMode) const;
    ooStatus unlockNoProp() const;
    ooStatus contains(ooItr(ooObj)& objItr, ooMode mode = oocNoOpen) const;
    ooHandle(ooDBObj)  containedIn() const;
    ooHandle(ooDBObj)& containedIn(ooHandle(ooDBObj)&) const;
    ooRef(ooDBObj)& containedIn(ooRef(ooDBObj)&) const;
    ooHandle(ooAPObj) controlledBy();
    ooHandle(ooAPObj)& controlledBy(ooHandle(ooAPObj)& controllingAP);
    ooRef(ooAPObj)& controlledBy(ooRef(ooAPObj)& controllingAPId);
    ooStatus transferControl(const ooHandle(ooAPObj)& newControllingAP);
    ooStatus returnControl();
    ooContObj * pin(ooMode openMode = oocRead) const;
    ooContObj * operator->() const;
    ooContObj& operator*() const;
    operator ooContObj *() const;
    ooStatus lookupObj(const ooHandle(ooObj)& scopeH, const char* name, ooMode openMode = oocRead);
    int32 hash();
    uint32 nPage();
    uint32 percentGrow();    
    ooStatus changePercentGrowth(const uint32 growth); // SPR 18954; % growth from 0 to 100
    uint32 numLogicalPages();   // largest logical page number used
    uint32 countLogicalPages(); // count allocated logical pages
    // ODMG methods:
    ooHandleStructor(ooContObj)(const d_Ref_Any &from);
    ooContObj *ptr() const;
    /********************************************************************
     *									*
     * Note: The following methods are only for internal system usage.	*
     *	     It is subject to change in any future release.		*
     *	     You are not allowed to use it.				*
     *									*
     ********************************************************************/
    /* Use operator ooContObj *() instead */
    /* OBSOLETE */ ooContObj * vm() const;
    ooRef(ooObj) nameCollection();
  protected:
    ooContObj * get_vm() const;
    ooContObj * pin_obj_internal(ooMode openMode = oocRead) const;
  private:
    void lookupObj(ooHandle(ooObj)&, const ooKey&, ooMode);
    void lookupObj(const ooKey&, ooMode);
    void getVersStatus() const;
    void setVersStatus(const ooVersMode) const;
    void getDefaultVers(ooHandle(ooObj)&) const;
    void getDefaultVers(ooRef(ooObj)&) const;
    void setDefaultVers() const;
    void getNextVers(ooHandle(ooObj)&, ooMode) const;
    void getPrevVers(ooHandle(ooObj)&) const;
    void getPrevVers(ooRef(ooObj)&) const;
    void copy(const ooHandle(ooObj)&, ooHandle(ooContObj)&) const;
    void copy(const ooHandle(ooObj)&, ooRef(ooContObj)&) const;
    void copy(const ooHandle(ooObj)&) const;
    void move(const ooHandle(ooObj)&);
};

ooTemplateSpecialization
class OO_STORAGE_SPECIFIER ooItr(ooContObj) :
					     public ooHandle(ooContObj),
					     public ooIteratorObjOrContObj
{
  public:
    ooItrStructor(ooContObj)();
    ~ooItrStructor(ooContObj)();
  private:
    // Declared only to prevent implicit definition:
    ooItrStructor(ooContObj)(const ooItr(ooContObj) &);
    ooItr(ooContObj) &    operator=(const ooItr(ooContObj) &);
};


///////////////////////////////////////////////////////////////////////////////

#include <ooDecl.h>


///////////////////////////////////////////////////////////////////////////////

/* Methods on ooDeref(ooObj) */
inline
ooDeref(ooObj)::ooDerefStructor(ooObj)(ooDeref(ooObj) &  from) :
    ooDerefBase(from.vm())
{
  this->pinCompensate();
}
inline
ooDeref(ooObj)::ooDerefStructor(ooObj)(ooObj *  fromObject) :
    ooDerefBase(fromObject)
{
}
inline
ooDeref(ooObj)::~ooDerefStructor(ooObj)()
{
}
inline
ooObj *
ooDeref(ooObj)::operator->() const
{
  return (ooObj *) (this->vm());
}


/* Methods on ooRef(ooObj) */
inline
ooRef(ooObj)&
ooRef(ooObj)::operator=(const ooId& id)
{
  this->ooId::operator=(id);
  return *this;
}
inline
ooRef(ooObj)&
ooRef(ooObj)::operator=(const ooShortId& shortId)
{
  this->ooId::operator=(shortId);
  return *this;
}
inline
ooRef(ooObj)&
ooRef(ooObj)::operator=(const ooObj* pObject)
{
  this->ooId::operator=(pObject);
  return *this;
}
inline
ooBoolean
ooRef(ooObj)::operator==(const ooHandleBase& objH) const
{
  return this->ooId::operator==(objH);
}
inline
ooBoolean
ooRef(ooObj)::operator!=(const ooHandleBase& objH) const
{
  return this->ooId::operator!=(objH);
}
inline
ooBoolean
ooRef(ooObj)::operator==(const ooId& id) const
{
  return this->ooId::operator==(id);
}
inline
ooBoolean
ooRef(ooObj)::operator!=(const ooId& id) const
{
  return this->ooId::operator!=(id);
}
inline
ooBoolean
ooRef(ooObj)::operator==(const ooShortId& shortId) const
{
  return this->ooId::operator==(shortId);
}
inline
ooBoolean
ooRef(ooObj)::operator!=(const ooShortId& shortId) const
{
  return this->ooId::operator!=(shortId);
}
inline
ooBoolean
ooRef(ooObj)::operator==(const ooObj* pObject) const
{
  return this->ooId::operator==(pObject);
}
inline
ooBoolean
ooRef(ooObj)::operator!=(const ooObj* pObject) const
{
  return this->ooId::operator!=(pObject);
}
inline
ooBoolean
ooRef(ooObj)::operator==(int  zero) const
{
  return this->ooId::operator==(zero);
}
inline
ooBoolean
ooRef(ooObj)::operator!=(int  zero) const
{
  return this->ooId::operator!=(zero);
}
inline
ooBoolean
ooRef(ooObj)::operator==(short  zero) const
{
  return this->ooId::operator==(zero);
}
inline
ooBoolean
ooRef(ooObj)::operator!=(short  zero) const
{
  return this->ooId::operator!=(zero);
}
inline
ooBoolean
ooRef(ooObj)::operator==(long  zero) const
{
  return this->ooId::operator==(zero);
}
inline
ooBoolean
ooRef(ooObj)::operator!=(long  zero) const
{
  return this->ooId::operator!=(zero);
}
inline
ooBoolean
ooRef(ooObj)::operator==(unsigned int  zero) const
{
  return this->ooId::operator==(zero);
}
inline
ooBoolean
ooRef(ooObj)::operator!=(unsigned int  zero) const
{
  return this->ooId::operator!=(zero);
}
inline
ooBoolean
ooRef(ooObj)::operator==(unsigned short  zero) const
{
  return this->ooId::operator==(zero);
}
inline
ooBoolean
ooRef(ooObj)::operator!=(unsigned short  zero) const
{
  return this->ooId::operator!=(zero);
}
inline
ooBoolean
ooRef(ooObj)::operator==(unsigned long  zero) const
{
  return this->ooId::operator==(zero);
}
inline
ooBoolean
ooRef(ooObj)::operator!=(unsigned long  zero) const
{
  return this->ooId::operator!=(zero);
}
inline
ooStatus
ooRef(ooObj)::set_container(const ooId& id)
{
  this->set_DB(id.get_DB());
  this->set_OC(id.get_OC());
  this->set_page(0);
  this->set_slot(0);
  return oocSuccess;
}
inline
ooStatus
ooRef(ooObj)::open(ooMode openMode) const
{
  ooHandle(ooObj) thisH = *this;
  return thisH.open(openMode);
}
inline
ooStatus
ooRef(ooObj)::close() const
{
  ooHandle(ooObj) thisH = *this;
  return thisH.close();
}
inline
ooMode
ooRef(ooObj)::openMode() const
{
  ooHandle(ooObj) thisH = *this;
  return thisH.openMode();
}
inline
ooStatus
ooRef(ooObj)::nameObj(const ooHandleBase &  scopeHBase,
		      const char *          name) const
{
  const ooHandle(ooObj) &scopeH = ((const ooHandle(ooObj) &) (scopeHBase));
  ooHandle(ooObj) thisH = *this;
  return thisH.nameObj(scopeH, name);
}
inline
char*
ooRef(ooObj)::getObjName(const ooHandleBase& scopeHBase) const
{
  const ooHandle(ooObj) &scopeH = ((const ooHandle(ooObj) &) (scopeHBase));
  ooHandle(ooObj) thisH = *this;
  return thisH.getObjName(scopeH);
}
inline
ooStatus
ooRef(ooObj)::unnameObj(const ooHandleBase &  scopeHBase,
			const char *          name) const
{
  const ooHandle(ooObj) &scopeH = ((const ooHandle(ooObj) &) (scopeHBase));
  ooHandle(ooObj) thisH = *this;
  return thisH.unnameObj(scopeH, name);
}
inline
ooStatus
ooRef(ooObj)::getNameScope(ooItr(ooObj) &  objItr) const
{
  ooHandle(ooObj) thisH = *this;
  return thisH.getNameScope(objItr);
}

inline
ooStatus
ooRef(ooObj)::getNameObj(ooItr(ooObj) &  objItr) const
{
  ooHandle(ooObj) thisH = *this;
  return thisH.getNameObj(objItr);
}
inline
ooStatus
ooRef(ooObj)::lock(ooLockMode lockMode) const
{
  ooHandle(ooObj) thisH = *this;
  return thisH.lock(lockMode);
}
inline
ooStatus
ooRef(ooObj)::lockNoProp(ooLockMode lockMode) const
{
  ooHandle(ooObj) thisH = *this;
  return thisH.lockNoProp(lockMode);
}

inline
ooVersMode
ooRef(ooObj)::getVersStatus() const
{
  ooHandle(ooObj) thisH = *this;
  return thisH.getVersStatus();
}
inline
ooStatus
ooRef(ooObj)::setVersStatus(const ooVersMode versMode) const
{
  ooHandle(ooObj) thisH = *this;
  return thisH.setVersStatus(versMode);
}
inline
ooStatus
ooRef(ooObj)::getDefaultVers(ooHandleBase& defHBase) const
{
  ooHandle(ooObj) &defH = ((ooHandle(ooObj) &) (defHBase));
  ooHandle(ooObj) thisH = *this;
  return thisH.getDefaultVers(defH);
}
inline
ooStatus
ooRef(ooObj)::getDefaultVers(ooRef(ooObj) & defId) const
{
  ooHandle(ooObj) defH;
  ooStatus result = this->getDefaultVers(defH);
  defId = defH;
  return result;
}
inline
ooStatus
ooRef(ooObj)::setDefaultVers() const
{
  ooHandle(ooObj) thisH = *this;
  return thisH.setDefaultVers();
}
inline
ooStatus
ooRef(ooObj)::getNextVers(ooHandleBase& nextVersItrHBase,
			  ooMode openMode) const
{
  ooHandle(ooObj) &nextVersItrH = ((ooHandle(ooObj) &) (nextVersItrHBase));
  ooHandle(ooObj) thisH = *this;
  return thisH.getNextVers(nextVersItrH, openMode);
}
inline
ooStatus
ooRef(ooObj)::getPrevVers(ooHandleBase& prevHBase) const
{
  ooHandle(ooObj) &prevH = ((ooHandle(ooObj) &) (prevHBase));
  ooHandle(ooObj) thisH = *this;
  return thisH.getPrevVers(prevH);
}
inline
ooStatus
ooRef(ooObj)::getPrevVers(ooRef(ooObj)& prevId) const
{
  ooHandle(ooObj) prevH;
  ooStatus result = getPrevVers(prevH);
  prevId = prevH;
  return result;
}
inline
ooTypeNumber
ooRef(ooObj)::typeN() const
{
  ooHandle(ooObj) thisH = *this;
  return thisH.typeN();
}
inline
const char*
ooRef(ooObj)::typeName() const
{
  ooHandle(ooObj) thisH = *this;
  return thisH.typeName();
}
inline
uint32
ooRef(ooObj)::size() const
{
  ooHandle(ooObj) thisH = *this;
  return thisH.size();
}
inline
ooStatus
ooRef(ooObj)::move(const ooHandleBase& targetContHBase)
{
  const ooHandle(ooObj) &targetContH =
      ((const ooHandle(ooObj) &) (targetContHBase));
  ooHandle(ooObj) thisH = *this;
  ooStatus result = thisH.move(targetContH);
  *this = thisH;
  return result;
}
inline
ooStatus
ooRef(ooObj)::update() const
{
  ooId tempId = *this;
  return tempId.update();
}
inline
ooObj *
ooRef(ooObj)::pin(ooMode openMode) const
{
  return ((ooObj *) (opiRefPin(this, openMode)));
}
inline
ooObj *
ooRef(ooObj)::pin_ref_internal(ooMode openMode) const
{
  return ((ooObj *) (opiRefPin(this, openMode)));
}
inline
void
ooRef(ooObj)::unpin() const
{
  ooHandle(ooObj) thisH = *this;
  thisH.unpin();
}
inline
ooDeref(ooObj)
ooRef(ooObj)::operator->() const
{
  ooDeref(ooObj) deref(opiRefPin(this, oocRead));
  return deref;
}
inline
ooBoolean
ooRef(ooObj)::isValid() const
{
  return ooId::isValid();
}
inline
ooBoolean
ooRef(ooObj)::isNull() const
{
  return ooId::isNull();
}
inline
void
ooRef(ooObj)::nullify()
{
  ooId::nullify();
}
// SPR 20580
inline
ooBoolean
ooRef(ooObj)::isTransient() const
{
  ooHandle(ooObj) thisH = *this;
  return thisH.isTransient();
}
inline
ooRef(ooObj)::operator int() const
{
  return ooId::operator int();
}
inline
void
ooRef(ooObj)::print(FILE* fp) const
{
  ooId::print(fp);
}
inline
char*
ooRef(ooObj)::sprint(char* buf) const
{
  return ooId::sprint(buf);
}
// ODMG methods:
inline
ooRef(ooObj)::ooRefStructor(ooObj)(const d_Ref_Any &from)
{
  *this = *ooReinterpretCast(const ooId *, &from);
}
inline
ooRef(ooObj)::operator d_Ref_Any() const
{
  return *ooReinterpretCast(const d_Ref_Any *, this);
}
inline
ooObj *
ooRef(ooObj)::ptr() const
{
  return this->pin_ref_internal(oocUpdate);
}
inline
int 
ooRef(ooObj)::is_null() const
{
  return ((int) (this->isNull()));
}


/*  methods on ooShortRef(ooObj) */
inline
ooShortRef(ooObj)&
ooShortRef(ooObj)::operator=(const ooShortId& shortId)
{
  ooShortId::operator=(shortId);
  return *this;
}
inline
ooShortRef(ooObj)&
ooShortRef(ooObj)::operator=(const ooId& id)
{
  ooShortId::operator=(id);
  return *this;
}
inline
ooShortRef(ooObj)&
ooShortRef(ooObj)::operator=(const ooObj *  pObject)
{
  this->ooShortId::operator=(pObject);
  return *this;
}
inline
ooShortRef(ooObj)::ooShortRefStructor(ooObj)(const ooShortId& shortId)
{
  ooShortId::operator=(shortId);
}
inline
ooShortRef(ooObj)::ooShortRefStructor(ooObj)(const ooId& id)
{
  ooShortId::operator=(id);
}
inline
ooShortRef(ooObj)::ooShortRefStructor(ooObj)(const ooHandleBase &  objH)
{
  *this = objH;
}
inline
ooBoolean
ooShortRef(ooObj)::operator==(const ooHandleBase &objH) const
{
  return ooShortId::operator==(objH);
}
inline
ooBoolean
ooShortRef(ooObj)::operator!=(const ooHandleBase &objH) const
{
  return ooShortId::operator!=(objH);
}
inline
ooBoolean
ooShortRef(ooObj)::operator==(const ooId& id) const
{
  return ooShortId::operator==(id);
}
inline
ooBoolean
ooShortRef(ooObj)::operator!=(const ooId& id) const
{
  return ooShortId::operator!=(id);
}
inline
ooBoolean
ooShortRef(ooObj)::operator==(const ooShortId& shortId) const
{
  return ooShortId::operator==(shortId);
}
inline
ooBoolean
ooShortRef(ooObj)::operator!=(const ooShortId& shortId) const
{
  return ooShortId::operator!=(shortId);
}
inline
ooBoolean
ooShortRef(ooObj)::operator==(const ooObj* pObject) const
{
  return ooShortId::operator==(pObject);
}
inline
ooBoolean
ooShortRef(ooObj)::operator!=(const ooObj* pObject) const
{
  return ooShortId::operator!=(pObject);
}
inline
ooBoolean
ooShortRef(ooObj)::operator==(int  zero) const
{
  return ooShortId::operator==(zero);
}
inline
ooBoolean
ooShortRef(ooObj)::operator!=(int  zero) const
{
  return ooShortId::operator!=(zero);
}
inline
ooBoolean
ooShortRef(ooObj)::operator==(short  zero) const
{
  return ooShortId::operator==(zero);
}
inline
ooBoolean
ooShortRef(ooObj)::operator!=(short  zero) const
{
  return ooShortId::operator!=(zero);
}
inline
ooBoolean
ooShortRef(ooObj)::operator==(long  zero) const
{
  return ooShortId::operator==(zero);
}
inline
ooBoolean
ooShortRef(ooObj)::operator!=(long  zero) const
{
  return ooShortId::operator!=(zero);
}
inline
ooBoolean
ooShortRef(ooObj)::operator==(unsigned int  zero) const
{
  return ooShortId::operator==(zero);
}
inline
ooBoolean
ooShortRef(ooObj)::operator!=(unsigned int  zero) const
{
  return ooShortId::operator!=(zero);
}
inline
ooBoolean
ooShortRef(ooObj)::operator==(unsigned short  zero) const
{
  return ooShortId::operator==(zero);
}
inline
ooBoolean
ooShortRef(ooObj)::operator!=(unsigned short  zero) const
{
  return ooShortId::operator!=(zero);
}
inline
ooBoolean
ooShortRef(ooObj)::operator==(unsigned long  zero) const
{
  return ooShortId::operator==(zero);
}
inline
ooBoolean
ooShortRef(ooObj)::operator!=(unsigned long  zero) const
{
  return ooShortId::operator!=(zero);
}
inline
void
ooShortRef(ooObj)::nullify()
{
 ooShortId::nullify();
 }
inline
ooBoolean
ooShortRef(ooObj)::isNull() const
{
  return ooShortId::isNull();
}
inline
ooShortRef(ooObj)::operator int() const
{
  return ooShortId::operator int();
}
inline
void
ooShortRef(ooObj)::print(FILE* fp) const
{
  ooShortId::print(fp);
}
inline
char*
ooShortRef(ooObj)::sprint(char* buf) const
{
  return ooShortId::sprint(buf);
}


/* Methods on ooHandle(ooObj) */
inline
ooBoolean
ooHandle(ooObj)::isGoodOID() const
{
  return _state == oocHandleOID && get_id().isOK();
}

inline
ooBoolean
ooHandle(ooObj)::operator!=(const ooHandle(ooObj)& objH) const
{
  return ! operator==(objH);
}
// isNull() is now defined on ooHandleBase
inline
ooBoolean
ooHandle(ooObj)::operator==(const ooId& id) const
{
  return (id == *this);
}
inline
ooBoolean
ooHandle(ooObj)::operator!=(const ooId& id) const
{
  return (id != *this);
}
inline
ooBoolean
ooHandle(ooObj)::operator==(const ooShortId& shortId) const
{
  return (shortId == *this);
}
inline
ooBoolean
ooHandle(ooObj)::operator!=(const ooShortId& shortId) const
{
  return (shortId != *this);
}
inline
ooBoolean
ooHandle(ooObj)::operator!=(const ooObj* pObject) const
{
  return ! operator==(pObject);
}
inline
ooBoolean
ooHandle(ooObj)::operator==(int  zero) const
{
  return (zero) ? ! isNull(): isNull();
}
inline
ooBoolean
ooHandle(ooObj)::operator!=(int  zero) const
{
  return ! operator==(zero);
}
inline
ooBoolean
ooHandle(ooObj)::operator==(short  zero) const
{
  return (zero) ? ! isNull(): isNull();
}
inline
ooBoolean
ooHandle(ooObj)::operator!=(short  zero) const
{
  return ! operator==(zero);
}
inline
ooBoolean
ooHandle(ooObj)::operator==(long  zero) const
{
  return (zero) ? ! isNull(): isNull();
}
inline
ooBoolean
ooHandle(ooObj)::operator!=(long  zero) const
{
  return ! operator==(zero);
}
inline
ooBoolean
ooHandle(ooObj)::operator==(unsigned int  zero) const
{
  return (zero) ? ! isNull(): isNull();
}
inline
ooBoolean
ooHandle(ooObj)::operator!=(unsigned int  zero) const
{
  return ! operator==(zero);
}
inline
ooBoolean
ooHandle(ooObj)::operator==(unsigned short  zero) const
{
  return (zero) ? ! isNull(): isNull();
}
inline
ooBoolean
ooHandle(ooObj)::operator!=(unsigned short  zero) const
{
  return ! operator==(zero);
}
inline
ooBoolean
ooHandle(ooObj)::operator==(unsigned long  zero) const
{
  return (zero) ? ! isNull(): isNull();
}
inline
ooBoolean
ooHandle(ooObj)::operator!=(unsigned long  zero) const
{
  return ! operator==(zero);
}
inline
ooStatus
ooHandle(ooObj)::update() const
{
  return this->open(oocUpdate);
}
inline
ooStatus
ooHandle(ooObj)::getDefaultVers(ooRef(ooObj)& defId) const
{
  ooHandle(ooObj) defH;
  ooStatus result = getDefaultVers(defH);
  defId = defH;
  return result;
}
inline
ooStatus
ooHandle(ooObj)::getPrevVers(ooRef(ooObj)& prevId) const
{
  ooHandle(ooObj) prevH;
  ooStatus result = getPrevVers(prevH);
  prevId = prevH;
  return result;
}
inline
ooObj *
ooHandle(ooObj)::vm() const
{	// throws exception if handle is null or invalid
  if ( _state == oocHandlePTR && _ptr._obj != NULL )
    return ooReinterpretCast(ooObj*, _ptr._obj);
  else return this->get_vm();
}
inline
ooObj *
ooHandle(ooObj)::operator->() const
{
  return this->vm();
}
inline
ooHandle(ooObj)::operator ooObj *() const
{	// allows null as a valid return value
  if ( _state == oocHandlePTR )
    return ooReinterpretCast(ooObj*, _ptr._obj);
  else return this->get_vm();
}
inline
const ooId&
ooHandle(ooObj)::oid() const
{
  return this->get_oid();
}
inline
ooObj *
ooHandle(ooObj)::pin_obj_internal(ooMode openMode) const
{
  return this->pin(openMode);
}

// ODMG methods:
inline
ooHandle(ooObj)::operator d_Ref_Any() const
{
  ooRef(ooObj) result = *this;
  return *ooReinterpretCast(const d_Ref_Any *, &result);
}
inline
ooObj *
ooHandle(ooObj)::ptr() const
{
  return this->operator ooObj *();
}
inline
int 
ooHandle(ooObj)::is_null() const
{
  return ((int) (this->isNull()));
}


///////////////////////////////////////////////////////////////////////////////

inline
ooRef(ooContObj)&
ooRef(ooContObj)::operator=(const ooRef(ooContObj)& id)
{
 this->ooId::operator=(id);
 return *this;
}

/* Methods on ooDeref(ooContObj) */
inline
ooDeref(ooContObj)::ooDerefStructor(ooContObj)(ooDeref(ooContObj) &  from) :
    ooDerefBase(from.vm())
{
  this->pinCompensate();
}
inline
ooDeref(ooContObj)::ooDerefStructor(ooContObj)(ooObj *  fromObject) :
    ooDerefBase(fromObject)
{
}
inline
ooDeref(ooContObj)::~ooDerefStructor(ooContObj)()
{
}
inline
ooContObj *
ooDeref(ooContObj)::operator->() const
{
  return ooReinterpretCast(ooContObj *, this->vm());
}


/* Methods on ooRef(ooContObj) */
inline
ooRef(ooContObj)::ooRefStructor(ooContObj)(const ooHandle(ooContObj) &  objH) :
    ooRef(ooObj)(objH)
{
}
inline
ooRef(ooContObj)::ooRefStructor(ooContObj)(const ooContObj *  pObject) :
    ooRef(ooObj)(ooReinterpretCast(const ooObj *, pObject))
{
}
inline
ooRef(ooContObj) &
ooRef(ooContObj)::operator=(const ooHandle(ooContObj) &objH)
{
  this->ooRef(ooObj)::operator=(objH);
  return *this;
}

inline
ooRef(ooContObj)&
ooRef(ooContObj)::operator=(const ooShortRef(ooContObj) &shortId)
{
  this->ooRef(ooObj)::operator=(shortId);
  return *this;
}

inline
ooRef(ooContObj) &
ooRef(ooContObj)::operator=(const ooContObj *  fromObject)
{
  this->ooRef(ooObj)::operator=(ooReinterpretCast(const ooObj *, fromObject));
  return *this;
}
inline
ooBoolean
ooRef(ooContObj)::exist(const ooHandle(ooDBObj)& DBhandle,
			const char* contName,
			ooMode openMode)
{
  ooHandle(ooContObj) thisH;
  ooBoolean result = thisH.exist(DBhandle, contName, openMode);
  *this = thisH;
  return result;
}
inline
ooStatus
ooRef(ooContObj)::open(ooMode openMode) const
{
  const ooRef(ooObj) *ooObjRefPtr = this;
  return ooObjRefPtr->open(openMode);
}
inline
ooStatus
ooRef(ooContObj)::open(const ooHandle(ooDBObj) &  DBhandle,
		       const char *               contName,
		       ooMode               openMode)
{
  ooHandle(ooContObj) thisH;
  ooStatus result = thisH.open(DBhandle, contName, openMode);
  *this = thisH;
  return result;
}
inline
ooStatus
ooRef(ooContObj)::close(const ooCloseMode closeMode) const
{
  ooHandle(ooContObj) thisH = *this;
  return thisH.close(closeMode);
}
inline
char*
ooRef(ooContObj)::name() const
{
  ooHandle(ooContObj) thisH = *this;
  return thisH.name();
}
inline
ooMode
ooRef(ooContObj)::openMode() const
{
  ooHandle(ooContObj) thisH = *this;
  return thisH.openMode();
}
inline
ooBoolean
ooRef(ooContObj)::isUpdated() const
{
  ooHandle(ooContObj) thisH = *this;
  return thisH.isUpdated();
}
inline
ooStatus
ooRef(ooContObj)::refreshOpen(ooMode openMode,
			      ooBoolean *pIsUpdated,
			      ooBoolean closeHandles) const
{
  ooHandle(ooContObj) thisH = *this;
  return thisH.refreshOpen(openMode, pIsUpdated, closeHandles);
}
inline
ooStatus
ooRef(ooContObj)::lockNoProp(ooLockMode lockMode) const
{
  ooHandle(ooContObj) thisH = *this;
  return thisH.lockNoProp(lockMode);
}
inline
ooStatus
ooRef(ooContObj)::unlockNoProp() const
{
  ooHandle(ooContObj) thisH = *this;
  return thisH.unlockNoProp();
}
inline
ooStatus
ooRef(ooContObj)::contains(ooItr(ooObj) &  objItr,
			   ooMode           mode) const
{
  ooHandle(ooContObj) thisH = *this;
  return thisH.contains(objItr, mode);
}
inline
ooStatus
ooRef(ooContObj)::transferControl(
			      const ooHandle(ooAPObj) &newControllingAP) const
{
  ooHandle(ooContObj) thisH = *this;
  return thisH.transferControl(newControllingAP);
}
inline
ooStatus
ooRef(ooContObj)::returnControl() const
{
  ooHandle(ooContObj) thisH = *this;
  return thisH.returnControl();
}
inline
ooContObj *
ooRef(ooContObj)::pin(ooMode openMode) const
{
  return ooReinterpretCast(ooContObj *, this->pin_ref_internal(openMode));
}
inline
ooDeref(ooContObj)
ooRef(ooContObj)::operator->() const
{
  ooObj* p = ooReinterpretCast(ooObj*, this->pin_ref_internal(oocRead));
  ooDeref(ooContObj) deref(p);
  return deref;
}
inline
int32
ooRef(ooContObj)::hash()  const
{
  ooHandle(ooContObj) thisH = *this;
  return thisH.hash();
}
inline
uint32
ooRef(ooContObj)::nPage()  const
{
  ooHandle(ooContObj) thisH = *this;
  return thisH.nPage();
}
inline
uint32
ooRef(ooContObj)::percentGrow()	 const
{
  ooHandle(ooContObj) thisH = *this;
  return thisH.percentGrow();
}
inline
uint32
ooRef(ooContObj)::numLogicalPages()  const
{
  ooHandle(ooContObj) thisH = *this;
  return thisH.numLogicalPages();
}
inline
uint32
ooRef(ooContObj)::countLogicalPages() const
{
  ooHandle(ooContObj) thisH = *this;
  return thisH.countLogicalPages();
}
// ODMG methods:
inline
ooContObj *
ooRef(ooContObj)::ptr() const
{
  return ooReinterpretCast(ooContObj *, this->pin_ref_internal(oocUpdate));
}


/* Methods on ooShortRef(ooContObj) */
inline
ooShortRef(ooContObj)::ooShortRefStructor(ooContObj)(const ooShortRef(ooContObj) &shortId): ooShortRef(ooObj)(0)
{
  ooShortId::operator=(shortId);
}

inline
ooShortRef(ooContObj)::ooShortRefStructor(ooContObj)(const ooRef(ooContObj)& id)
{
  ooShortId::operator=(id);
}

inline
ooShortRef(ooContObj)::ooShortRefStructor(ooContObj)(
						  const ooContObj *  pObject) :
    ooShortRef(ooObj)(ooReinterpretCast(const ooObj *, pObject))
{
}
inline
ooShortRef(ooContObj)::ooShortRefStructor(ooContObj)(
					   const ooHandle(ooContObj) &  objH) :
    ooShortRef(ooObj)(objH)
{
}

inline
ooShortRef(ooContObj) &
ooShortRef(ooContObj)::operator=(const ooHandle(ooContObj) &objH)
{
  this->ooShortRef(ooObj)::operator=(objH);
  return *this;
}

inline
ooShortRef(ooContObj)&
ooShortRef(ooContObj)::operator=(const ooShortRef(ooContObj)& shortId)
{
  ooShortId::operator=(shortId);
  return *this;
}
inline
ooShortRef(ooContObj)&
ooShortRef(ooContObj)::operator=(const ooRef(ooContObj)& id)
{
  ooShortId::operator=(id);
  return *this;
}
inline
ooShortRef(ooContObj)&
ooShortRef(ooContObj)::operator=(const ooContObj * pObject)
{
  this->ooShortRef(ooObj)::operator=(ooReinterpretCast(const ooObj *,
						       pObject));
  return *this;
}


/* Methods on ooHandle(ooContObj) */
inline
ooHandle(ooContObj)::ooHandleStructor(ooContObj)(
					   const ooHandle(ooContObj) &  objH) :
    ooHandle(ooObj)(objH)
{
}
inline
ooHandle(ooContObj)::ooHandleStructor(ooContObj)(const ooRef(ooContObj)& id) :
    ooHandle(ooObj)(id)
{
}

inline
ooHandle(ooContObj)::ooHandleStructor(ooContObj)(
					       const ooContObj *  fromObject) :
    ooHandle(ooObj)(ooReinterpretCast(const ooObj *, fromObject))
{
}

inline
ooHandle(ooContObj)::ooHandleStructor(ooContObj)(const ooId& id) :
    ooHandle(ooObj)(id)
{
}

inline
ooHandle(ooContObj)&
ooHandle(ooContObj)::operator=(const ooHandle(ooContObj)& objH)
{
  this->ooHandle(ooObj)::operator=(objH);
  return *this;
}
inline
ooHandle(ooContObj)&
ooHandle(ooContObj)::operator=(const ooRef(ooContObj)& id)
{
  this->ooHandle(ooObj)::operator=(id);
  return *this;
}
inline
ooHandle(ooContObj)&
ooHandle(ooContObj)::operator=(const ooShortRef(ooContObj)& shortId)
{
  this->ooHandle(ooObj)::operator=(shortId);
  return *this;
}

inline
ooHandle(ooContObj)&
ooHandle(ooContObj)::operator=(const ooContObj *  pObject)
{
  this->ooHandle(ooObj)::operator=(ooReinterpretCast(const ooObj *, pObject));
  return *this;
}

inline
ooContObj *
ooHandle(ooContObj)::pin(ooMode openMode) const
{
  return this->pin_obj_internal(openMode);
}

inline
ooContObj *
ooHandle(ooContObj)::vm() const
{
  return this->get_vm();
}

inline
ooContObj *
ooHandle(ooContObj)::operator->() const
{
  return this->get_vm();
}
inline
ooHandle(ooContObj)::operator ooContObj *() const
{
  if ( _state == oocHandlePTR )
    return ooReinterpretCast(ooContObj*, _ptr._obj);
  else return this->get_vm();
}


///////////////////////////////////////////////////////////////////////////////

/* Methods on ooRef(ooFDObj) */
inline
ooRef(ooFDObj) &
ooRef(ooFDObj)::operator=(const ooHandle(ooFDObj) &  objH)
{
  this->ooRef(ooObj)::operator=(objH);
  return *this;
}

inline
ooRef(ooFDObj)::ooRefStructor(ooFDObj)(const ooHandle(ooFDObj) &  objH)
{
  *this = objH;
}

inline
ooBoolean
ooRef(ooFDObj)::exist(const char* bootFilePath, ooMode openMode)
{
  ooHandle(ooFDObj) thisH;
  ooBoolean result = thisH.exist(bootFilePath, openMode);
  *this = thisH;
  return result;
}
inline
ooStatus
ooRef(ooFDObj)::open(const char* bootFilePath,
		     ooMode openMode,
		     ooBoolean recover,
		     ooGlobalTransStatusFunc statusFunc)
{
  ooHandle(ooFDObj) thisH;
  ooStatus result = thisH.open(bootFilePath, openMode, recover, statusFunc);
  *this = thisH;
  return result;
}
inline
ooStatus
ooRef(ooFDObj)::close()	 const
{
  ooHandle(ooFDObj) thisH = *this;
  return thisH.close();
}
inline
ooStatus
ooRef(ooFDObj)::update() const
{
  ooHandle(ooFDObj) thisH = *this;
  return thisH.update();
}
inline
ooMode
ooRef(ooFDObj)::openMode() const
{
  ooHandle(ooFDObj) thisH = *this;
  return thisH.openMode();
}
inline
char*
ooRef(ooFDObj)::name() const
{
  ooHandle(ooFDObj) thisH = *this;
  return thisH.name();
}
inline
ooStatus
ooRef(ooFDObj)::lock(ooLockMode lockMode) const
{
  ooHandle(ooFDObj) thisH = *this;
  return thisH.lock(lockMode);
}
inline
ooStatus
ooRef(ooFDObj)::unlock()  const
{
  ooHandle(ooFDObj) thisH = *this;
  return thisH.unlock();
}
inline
ooStatus
ooRef(ooFDObj)::contains(ooItr(ooDBObj) &dbItr,
			 ooMode mode, ooBoolean visitForeign) const
{
  ooHandle(ooFDObj) thisH = *this;
  return thisH.contains(dbItr, mode, visitForeign);
}

inline
ooStatus
ooRef(ooFDObj)::contains(ooItr(ooAPObj)& containedAPs,
			 ooMode openMode) const
{
  ooHandle(ooFDObj) thisH = *this;
  return thisH.contains(containedAPs, openMode );
}
inline
const char*
ooRef(ooFDObj)::typeName() const
{
  return "ooFDObj";
}
inline
ooStatus
ooRef(ooFDObj)::dumpCatalog(FILE* outputFile,
			    ooFileNameFormat format,
			    ooBoolean printLabels) const
{
  ooHandle(ooFDObj) thisH = *this;
      return thisH.dumpCatalog(outputFile, format, printLabels);
}
inline
ooStatus
ooRef(ooFDObj)::dumpCatalog(FILE* outputFile,
			    ooFileNameFormat format,
			    FILE* reportFile) const
{
  
 ooHandle(ooFDObj) thisH = *this;
 return thisH.dumpCatalog(outputFile, format, reportFile);

}
inline
ooStatus
ooRef(ooFDObj)::change(const char *  bootFilePath,
		       const char *  lockServerName,
		       uint32        number,
		       FILE *        fp) const
{
  ooHandle(ooFDObj) thisH = *this;
  return thisH.change(bootFilePath, lockServerName, number, fp);
}
inline
char*
ooRef(ooFDObj)::lockServerName() const
{
  ooHandle(ooFDObj) thisH = *this;
  return thisH.lockServerName();
}
inline
uint32
ooRef(ooFDObj)::number() const
{
  ooHandle(ooFDObj) thisH = *this;
  return thisH.number();
}
inline
uint32
ooRef(ooFDObj)::pageSize() const
{
  ooHandle(ooFDObj) thisH = *this;
  return thisH.pageSize();
}
inline
ooStatus
ooRef(ooFDObj)::tidy(FILE *        fp,
		     const char *  hostName,
		     const char *  pathName) const
{
  ooHandle(ooFDObj) thisH = *this;
  return thisH.tidy(fp, hostName, pathName);
}


inline
const char*
ooHandle(ooFDObj)::typeName() const
{
  return "ooFDObj";
}
inline
ooBoolean
ooRef(ooFDObj)::isValid() const
{
  ooHandle(ooFDObj) thisH = *this;
  return thisH.isValid();
}

inline
unsigned
ooRef(ooFDObj)::newQueryAgent(const char* DBname, 
                  const char* hostName,
                  const char* queryAgent, const char* parameters,
                  unsigned userDBID, unsigned pageSize)
{
  ooHandle(ooFDObj) thisH = *this;
  return thisH.newQueryAgent(DBname, hostName, queryAgent, parameters, userDBID, pageSize);
}


///////////////////////////////////////////////////////////////////////////////

/* Methods on ooRef(ooAPObj) */
inline
ooRef(ooAPObj)::ooRefStructor(ooAPObj)(const ooHandle(ooAPObj) &  objH) :
    ooRef(ooObj)(objH)
{
}

inline
ooRef(ooAPObj)&
ooRef(ooAPObj)::operator=(const ooRef(ooAPObj) &  fromRef)
{
 this->ooId::operator=(fromRef);
 return *this;
}

inline
ooRef(ooAPObj) &
ooRef(ooAPObj)::operator=(const ooHandle(ooAPObj) &  fromHandle)
{
  this->ooRef(ooObj)::operator=(fromHandle);
  return *this;
}

inline
ooBoolean
ooRef(ooAPObj)::exist(const ooHandle(ooFDObj) &containingFdH,
		      const char *apSystemName,
		      ooMode openMode)
{
  ooHandle(ooAPObj) thisH;
  ooBoolean result = thisH.exist(containingFdH, apSystemName, openMode);
  *this = thisH;
  return result;
}

inline
ooStatus
ooRef(ooAPObj)::open(const ooHandle(ooFDObj)& containingFdH,
		     const char* apSystemName,
		     ooMode openMode)
{
  ooHandle(ooAPObj) thisH;
  ooStatus result = thisH.open(containingFdH, apSystemName, openMode);
  *this = thisH;
  return result;
}

inline
ooStatus
ooRef(ooAPObj)::open(ooMode openMode) const
{
  ooHandle(ooAPObj) thisH = *this;
  return thisH.open(openMode);
}

inline
ooStatus
ooRef(ooAPObj)::update() const
{
  ooHandle(ooAPObj) thisH = *this;
  return thisH.update();
}

inline
ooStatus
ooRef(ooAPObj)::close() const
{
  ooHandle(ooAPObj) thisH = *this;
  return thisH.close();
}
inline
ooMode
ooRef(ooAPObj)::openMode() const
{
  ooHandle(ooAPObj) thisH = *this;
  return thisH.openMode();
}
inline
char*
ooRef(ooAPObj)::name() const
{
  ooHandle(ooAPObj) thisH = *this;
  return thisH.name();
}
inline
char*
ooRef(ooAPObj)::lockServerHost() const
{
  ooHandle(ooAPObj) thisH = *this;
  return thisH.lockServerHost();
}
inline
char*
ooRef(ooAPObj)::sysDBFileHost() const
{
  ooHandle(ooAPObj) thisH = *this;
  return thisH.sysDBFileHost();
}
inline
char*
ooRef(ooAPObj)::sysDBFilePath() const
{
  ooHandle(ooAPObj) thisH = *this;
  return thisH.sysDBFilePath();
}
inline
char*
ooRef(ooAPObj)::bootFileHost() const
{
  ooHandle(ooAPObj) thisH = *this;
  return thisH.bootFileHost();
}
inline
char*
ooRef(ooAPObj)::bootFilePath() const
{
  ooHandle(ooAPObj) thisH = *this;
  return thisH.bootFilePath();
}
inline
char*
ooRef(ooAPObj)::jnlDirHost() const
{
  ooHandle(ooAPObj) thisH = *this;
  return thisH.jnlDirHost();
}
inline
char*
ooRef(ooAPObj)::jnlDirPath() const
{
  ooHandle(ooAPObj) thisH = *this;
  return thisH.jnlDirPath();
}
inline
ooStatus
ooRef(ooAPObj)::imagesContainedIn(ooItr(ooDBObj) &controlledDbs,
				  ooMode openMode) const
{
  ooHandle(ooAPObj) thisH = *this;
  return thisH.imagesContainedIn(controlledDbs, openMode);
}

inline
ooStatus
ooRef(ooAPObj)::containersControlledBy(
				ooItr(ooContObj) &directlyControlledConts,
				ooMode openMode) const
{
  ooHandle(ooAPObj) thisH = *this;
  return thisH.containersControlledBy(directlyControlledConts, openMode);
}

inline
ooStatus
ooRef(ooAPObj)::returnAll() const
{
  ooHandle(ooAPObj) thisH = *this;
  return thisH.returnAll();
}
inline
const char*
ooRef(ooAPObj)::typeName() const
{
  return "ooAPObj";
}
inline
ooBoolean
ooRef(ooAPObj)::isValid() const
{
  ooHandle(ooAPObj) thisH = *this;
  return thisH.isValid();
}
inline
ooStatus
ooRef(ooAPObj)::change(const char* newLockServerHost,
		       const char* newSysDBFileHost,
		       const char* newSysDBFilePath,
		       const char* newBootFileHost,
		       const char* newBootFilePath,
		       const char* newJnlDirHost,
		       const char* newJnlDirPath,
		       ooBoolean catalogOnly) const
{
  ooHandle(ooAPObj) thisH = *this;
  return thisH.change(newLockServerHost,
		      newSysDBFileHost,
		      newSysDBFilePath,
		      newBootFileHost,
		      newBootFilePath,
		      newJnlDirHost,
		      newJnlDirPath,
		      catalogOnly);
}
inline
ooStatus
ooRef(ooAPObj)::markOffline() const
{
  ooHandle(ooAPObj) thisH = *this;
  return thisH.markOffline();
}
inline
ooStatus
ooRef(ooAPObj)::markOnline() const
{
  ooHandle(ooAPObj) thisH = *this;
  return thisH.markOnline();
}
inline
ooBoolean
ooRef(ooAPObj)::isOffline() const
{
  ooHandle(ooAPObj) thisH = *this;
  return thisH.isOffline();
}
inline
ooBoolean
ooRef(ooAPObj)::isAvailable() const
{
  ooHandle(ooAPObj) thisH = *this;
  return thisH.isAvailable();
}


/* Methods on ooHandle(ooAPObj) */
inline
const char*
ooHandle(ooAPObj)::typeName() const
{
  return "ooAPObj";
}


///////////////////////////////////////////////////////////////////////////////

/* Methods on ooRef(ooDBObj) */
inline
ooRef(ooDBObj)::ooRefStructor(ooDBObj)(const ooHandle(ooDBObj) &  objH) :
    ooRef(ooObj)(objH)
{
}

inline
ooRef(ooDBObj)&
ooRef(ooDBObj)::operator=(const ooRef(ooDBObj)& id)
{
  this->ooId::operator=(id);
  return *this;
}
inline
ooRef(ooDBObj) &
ooRef(ooDBObj)::operator=(const ooHandle(ooDBObj) &  objH)
{
  this->ooRef(ooObj)::operator=(objH);
  return *this;
}
inline
ooBoolean
ooRef(ooDBObj)::exist(const ooHandle(ooFDObj)& FDhandle, const char* DBname,
     ooMode openMode)
{
  ooHandle(ooDBObj) thisH;
  ooBoolean result = thisH.exist(FDhandle, DBname, openMode);
  *this = thisH;
  return result;
}
inline
ooStatus
ooRef(ooDBObj)::open(const ooHandle(ooFDObj) &  FDhandle,
		     const char *               DBname,
		     ooMode               openMode)
{
  ooHandle(ooDBObj) thisH = *this;
  ooStatus result = thisH.open(FDhandle, DBname, openMode);
  *this = thisH;
  return result;
}
inline
ooStatus
ooRef(ooDBObj)::open(ooMode openMode) const
{
  ooHandle(ooDBObj) thisH = *this;
  return thisH.open(openMode);
}
inline
ooStatus
ooRef(ooDBObj)::close() const
{
  ooHandle(ooDBObj) thisH = *this;
  return thisH.close();
}
inline
ooStatus
ooRef(ooDBObj)::update() const
{
  ooHandle(ooDBObj) thisH = *this;
  return thisH.update();
}
inline
ooMode
ooRef(ooDBObj)::openMode() const
{
  ooHandle(ooDBObj) thisH = *this;
  return thisH.openMode();
}
inline
char*
ooRef(ooDBObj)::name() const
{
  ooHandle(ooDBObj) thisH = *this;
  return thisH.name();
}
inline
char*
ooRef(ooDBObj)::hostName() const
{
  ooHandle(ooDBObj) thisH = *this;
  return thisH.hostName();
}
inline
char*
ooRef(ooDBObj)::pathName() const
{
  ooHandle(ooDBObj) thisH = *this;
  return thisH.pathName();
}
inline
char*
ooRef(ooDBObj)::fileName() const
{
  ooHandle(ooDBObj) thisH = *this;
  return thisH.fileName();
}
inline
ooStatus
ooRef(ooDBObj)::lock(ooLockMode lockMode) const
{
  ooHandle(ooDBObj) thisH = *this;
  return thisH.lock(lockMode);
}
inline
ooStatus
ooRef(ooDBObj)::unlock() const
{
  ooHandle(ooDBObj) thisH = *this;
  return thisH.unlock();
}
inline
ooStatus
ooRef(ooDBObj)::contains(ooItr(ooContObj) &contItr,
			 ooMode mode,
			 ooContainsFilter whichConts) const
{
  ooHandle(ooDBObj) thisH = *this;
  return thisH.contains(contItr, mode, whichConts);
}

inline
ooStatus
ooRef(ooDBObj)::changePartition(
			      const ooHandle(ooAPObj)& newControllingAP) const
{
  ooHandle(ooDBObj) thisH = *this;
  return thisH.changePartition(newControllingAP);
}
inline
const char*
ooRef(ooDBObj)::typeName() const
{
  return "ooDBObj";
}
inline
ooStatus
ooRef(ooDBObj)::change(const char *  name,
		       const char*  hostName,
		       const char*  pathName,
		       FILE* fp,
           ooBoolean catalogOnly) const
{
  ooHandle(ooDBObj) thisH = *this;
  return thisH.change(name, hostName, pathName, fp, catalogOnly);
}
inline
ooStatus
ooRef(ooDBObj)::tidy(FILE* fp, const char* hostName,
		     const char* pathName) const
{
  ooHandle(ooDBObj) thisH = *this;
  return thisH.tidy(fp, hostName, pathName);
}
inline
ooStatus
ooRef(ooDBObj)::deleteImage(const ooHandle(ooAPObj) &  partition,
			    ooBoolean                  deleteDBifLast,
			    ooBoolean                  catalogOnly) const
{
  ooHandle(ooDBObj) thisH = *this;
  return thisH.deleteImage(partition, deleteDBifLast, catalogOnly);
}


/* Methods on ooHandle(ooDBObj) */
inline
const char *
ooHandle(ooDBObj)::typeName() const
{
  return "ooDBObj";
}
inline
ooBoolean
ooRef(ooDBObj)::isValid() const
{
  ooHandle(ooDBObj) thisH = *this;
  return thisH.isValid();
}


/* Methods on ooItr(ooDBObj) */
inline
ooStatus
ooItr(ooDBObj)::scan(const ooHandle(ooFDObj) &  FDhandle,
		     ooMode                     mode,
		     ooBoolean			visitForeignFlag)
{
  return FDhandle.contains(*this, mode, visitForeignFlag);
}

// ODMG methods:
inline
ooContObj *
ooHandle(ooContObj)::ptr() const
{
  return this->operator->();
}

ooTemplateSpecialization
class OO_STORAGE_SPECIFIER ooRef(ooAsObj) : public ooRef(ooObj)
{
};

///////////////////////////////////////////////////////////////////////////////

#if defined(_MSC_VER) && !defined(OO_DDL_TRANSLATION)
#pragma pack(pop)
#endif

#endif /* OO_SCHEMA_H */
