/* C++ 'references' header file: Objectivity/DB DDL Version: 11.1 */
/**************************************************************************
  		  Copyright (c) 1992-2002 Objectivity, Inc.
 	  		  All Rights Reserved

 	THIS IS UNPUBLISHED PROPRIETARY SOURCE CODE OF OBJECTIVITY, INC.

 	The copyright notice above does not evidence any
 	actual or intended publication of such source code.

*****************************************************************************/


#ifndef OO_INDEX_REF_H_TMP
#define OO_INDEX_REF_H_TMP

#ifndef OO_H
#include <oo.h>
#endif
#include <ooSchema_ref.h>
#if defined(_MSC_VER) && !defined(OO_DDL_TRANSLATION)
#pragma pack(push,8)
#endif
class ooIndexBase;


/////////////////////////////////////////////////////////////////////////////

ooTemplateSpecialization
class ooDeref(ooIndexBase) : public ooDerefBase {
	friend class ooRef(ooIndexBase);
  public:
    ~ooDerefStructor(ooIndexBase)();
    inline ooIndexBase *operator->() const;
#ifndef OO_BUGGY_TEMPLATES
  private:
#endif // !defined(OO_BUGGY_TEMPLATES)
    ooDerefStructor(ooIndexBase)(ooDeref(ooIndexBase)& deref);
    ooDerefStructor(ooIndexBase)(ooObj *  fromObject);
};


#ifdef OO_BUGGY_TEMPLATES

class ooHandle_superclass<ooIndexBase > : public ooHandle(ooSysIndex) {
 protected:
  ooHandle_superclass()
    {}
  ooHandle_superclass(const ooHandle(ooSysIndex) &  from) :
      ooHandle(ooSysIndex)(from)
    {}
  ooHandle_superclass(const ooRef(ooSysIndex) &  from) :
      ooHandle(ooSysIndex)(from)
    {}
  ooHandle_superclass(const ooSysIndex *  from) :
      ooHandle(ooSysIndex)(from)
    {}
  ~ooHandle_superclass()
    {}
};

class ooShortRef_superclass<ooIndexBase > : public ooShortRef(ooSysIndex) {
};

#endif // OO_BUGGY_TEMPLATES

ooTemplateSpecialization
class ooRef(ooIndexBase) : public ooRef(ooSysIndex) {
  public:
    ooRefStructor(ooIndexBase)()
      {}
    ooRefStructor(ooIndexBase)(const ooRef(ooIndexBase)& id) :
	  ooRef(ooSysIndex)(id)
      {}
    inline ooRefStructor(ooIndexBase)(const ooHandleSuper(ooIndexBase)& objH);
    inline ooRefStructor(ooIndexBase)(const ooIndexBase *  fromObject);
    inline ooRef(ooIndexBase)& operator=(const ooRef(ooIndexBase)& id);
    inline ooRef(ooIndexBase)& operator=(const ooShortRefSuper(ooIndexBase) &shortId);
    inline ooRef(ooIndexBase)& operator=(const ooHandleSuper(ooIndexBase)& objH);
    inline ooRef(ooIndexBase)& operator=(const ooIndexBase *  fromObject);
    ooStatus lookupObj(const ooHandle(ooObj)& scopeH,
		       const ooKey& key,
		       ooMode openMode = oocRead);
    ooStatus lookupObj(const ooHandle(ooObj)& scopeH,
		       const char* name,
		       ooMode openMode = oocRead);
#ifndef OO_BUGGY_TEMPLATES
    inline ooRef(ooIndexBase)& copy(const ooHandle(ooObj)& nearH,
		    ooRef(ooIndexBase)& newObjRef) const;
    inline ooHandle(ooIndexBase)& copy(const ooHandle(ooObj)& nearH,
			ooHandle(ooIndexBase)& result) const;
    inline ooHandle(ooIndexBase) copy(const ooHandle(ooObj)& nearH) const;
#endif // !defined(OO_BUGGY_TEMPLATES)
    inline ooIndexBase *pin(ooMode openMode = oocRead) const;
    ooDeref(ooIndexBase) operator->() const;
    /* Use pin() or use ooHandle "operator ooIndexBase *" instead of vm. */
    /* OBSOLETE */ inline ooIndexBase *vm(ooMode openMode = oocRead) const;
    // ODMG methods:
    ooRefStructor(ooIndexBase)(const d_Ref_Any &from);
    ooIndexBase *ptr() const;
};

ooTemplateSpecialization
class ooShortRef(ooIndexBase) :
#ifdef OO_BUGGY_TEMPLATES
			public ooShortRef_superclass<ooIndexBase >
#else // !defined(OO_BUGGY_TEMPLATES)
			public ooShortRef(ooSysIndex)
#endif // !defined(OO_BUGGY_TEMPLATES)
					            {
  public:
    ooShortRefStructor(ooIndexBase)();
    ooShortRefStructor(ooIndexBase)(const ooShortRef(ooIndexBase)& shortId);
    ooShortRefStructor(ooIndexBase)(const ooRef(ooIndexBase)& id);
    ooShortRefStructor(ooIndexBase)(const ooHandleSuper(ooIndexBase) &objH);
    ooShortRefStructor(ooIndexBase)(const ooIndexBase *  fromObject);
    ooShortRef(ooIndexBase)& operator=(const ooShortRef(ooIndexBase)& shortId);
    ooShortRef(ooIndexBase)& operator=(const ooRef(ooIndexBase)& id);
    ooShortRef(ooIndexBase)& operator=(const ooHandleSuper(ooIndexBase) &objH);
    ooShortRef(ooIndexBase)& operator=(const ooIndexBase *  fromObject);
};

ooTemplateSpecialization
class ooHandle(ooIndexBase) :
#ifdef OO_BUGGY_TEMPLATES
		      public ooHandle_superclass<ooIndexBase >
#else // !defined(OO_BUGGY_TEMPLATES)
		      public ooHandle(ooSysIndex)
#endif // !defined(OO_BUGGY_TEMPLATES)
                                                {
  public:
    inline ooHandleStructor(ooIndexBase)();
    inline ooHandleStructor(ooIndexBase)(const ooRef(ooIndexBase)& id);
    inline ooHandleStructor(ooIndexBase)(const ooHandle(ooIndexBase)& objH);
    inline ooHandleStructor(ooIndexBase)(const ooIndexBase *  fromObject);
    inline ooHandle(ooIndexBase)& operator=(const ooRef(ooIndexBase)& id);
    inline ooHandle(ooIndexBase)& operator=(const ooHandle(ooIndexBase)& objH);
    inline ooHandle(ooIndexBase)& operator=(const ooShortRef(ooIndexBase)& shortId);
    inline ooHandle(ooIndexBase)& operator=(const ooIndexBase *  fromObject);
    ooStatus lookupObj(const ooHandle(ooObj)& scopeH,
		       const ooKey& key,
		       ooMode openMode = oocRead);
    ooStatus lookupObj(const ooHandle(ooObj)& scopeH,
		       const char* name,
		       ooMode openMode = oocRead);
    ooHandle(ooIndexBase)& copy(const ooHandle(ooObj)& nearH,
		       ooHandle(ooIndexBase)& result) const;
    inline ooRef(ooIndexBase)& copy(const ooHandle(ooObj)& nearH,
		    ooRef(ooIndexBase)& result) const;
    ooHandle(ooIndexBase) copy(const ooHandle(ooObj)& nearH) const;
    inline ooIndexBase *pin(ooMode openMode = oocRead) const;
    inline ooIndexBase *operator->() const;
    inline ooIndexBase &operator*() const;
    inline operator ooIndexBase *() const;
    /* Use "operator ooIndexBase *" instead of vm. */
    /* OBSOLETE */ inline ooIndexBase *vm() const;
    // ODMG methods:
    ooHandleStructor(ooIndexBase)(const d_Ref_Any &from);
    ooIndexBase *ptr() const;
};

ooTemplateSpecialization
class ooItr(ooIndexBase) : public ooHandle(ooIndexBase),
		    public ooIteratorObjOrContObj {
  public:
    ooItrStructor(ooIndexBase)();
    ~ooItrStructor(ooIndexBase)();
  private:
    // Defined only to prevent implicit definition:
    ooItrStructor(ooIndexBase)(ooItr(ooIndexBase)&);
    ooItr(ooIndexBase)    operator=(ooItr(ooIndexBase)&);
};


/* methods on ooDeref(ooIndexBase) */
inline
ooDeref(ooIndexBase)::ooDerefStructor(ooIndexBase)(ooDeref(ooIndexBase) &  deref) :
    ooDerefBase(deref.vm())
{
  this->pinCompensate();
}
inline
ooDeref(ooIndexBase)::ooDerefStructor(ooIndexBase)(ooObj *  fromObject) :
    ooDerefBase(fromObject)
{
}
inline
ooDeref(ooIndexBase)::~ooDerefStructor(ooIndexBase)()
{
}
inline
ooIndexBase *
ooDeref(ooIndexBase)::operator->() const
{
  return ooReinterpretCast(ooIndexBase *, this->vm());
}


/* methods on ooRef(ooIndexBase) */
inline
ooRef(ooIndexBase)::ooRefStructor(ooIndexBase)(const ooHandleSuper(ooIndexBase)& objH) :
    ooRef(ooSysIndex)(objH)
{
}
inline
ooRef(ooIndexBase)::ooRefStructor(ooIndexBase)(const ooIndexBase *  fromObject) :
    ooRef(ooSysIndex)(ooReinterpretCast(const ooSysIndex *, fromObject))
{
}
inline
ooRef(ooIndexBase)&
ooRef(ooIndexBase)::operator=(const ooRef(ooIndexBase) &  id)
{
  this->ooId::operator=(id);
  return *this;
}
inline
ooRef(ooIndexBase)&
ooRef(ooIndexBase)::operator=(const ooShortRefSuper(ooIndexBase) &  shortId)
{
  this->ooRef(ooObj)::operator=(shortId);
  return *this;
}
inline
ooRef(ooIndexBase)&
ooRef(ooIndexBase)::operator=(const ooHandleSuper(ooIndexBase) &  objH)
{
  this->ooRef(ooObj)::operator=(objH);
  return *this;
}
inline
ooRef(ooIndexBase)&
ooRef(ooIndexBase)::operator=(const ooIndexBase *  fromObject)
{
  this->ooRef(ooObj)::operator=(ooReinterpretCast(const ooObj *, fromObject));
  return *this;
}
inline
ooIndexBase *
ooRef(ooIndexBase)::pin(ooMode  openMode) const
{
  return ooReinterpretCast(ooIndexBase *, this->pin_ref_internal(openMode));
}
inline
ooIndexBase *
ooRef(ooIndexBase)::vm(ooMode  openMode) const
{
  return this->pin(openMode);
}
#ifndef OO_BUGGY_TEMPLATES
inline
ooHandle(ooIndexBase) &
ooRef(ooIndexBase)::copy(const ooHandle(ooObj) &  nearH,
		ooHandle(ooIndexBase) &           result) const
{
  this->ooRef(ooObj)::copy(nearH, result);
  return result;
}
inline
ooRef(ooIndexBase) &
ooRef(ooIndexBase)::copy(const ooHandle(ooObj) &  nearH,
		ooRef(ooIndexBase) &              newObjRef) const
{
  this->ooRef(ooObj)::copy(nearH, newObjRef);
  return newObjRef;
}
inline
ooHandle(ooIndexBase)
ooRef(ooIndexBase)::copy(const ooHandle(ooObj) &  nearH) const
{
  ooHandle(ooIndexBase) result;
  this->ooRef(ooObj)::copy(nearH, result);
  return result;
}
#endif // !defined(OO_BUGGY_TEMPLATES)
inline
ooDeref(ooIndexBase)
ooRef(ooIndexBase)::operator->() const
{
  ooDeref(ooIndexBase) result(this->pin_ref_internal(oocRead));
  return result;
}


/* methods on ooShortRef(ooIndexBase) */
inline
ooShortRef(ooIndexBase) &
ooShortRef(ooIndexBase)::operator=(const ooShortRef(ooIndexBase) &  shortId)
{
  this->ooShortId::operator=(shortId);
  return *this;
}
inline
ooShortRef(ooIndexBase) &
ooShortRef(ooIndexBase)::operator=(const ooRef(ooIndexBase) &  id)
{
  this->ooShortId::operator=(id);
  return *this;
}
inline
ooShortRef(ooIndexBase) &
ooShortRef(ooIndexBase)::operator=(const ooHandleSuper(ooIndexBase) &  objH)
{
  this->ooShortId::operator=(objH);
  return *this;
}
inline
ooShortRef(ooIndexBase)&
ooShortRef(ooIndexBase)::operator=(const ooIndexBase *  fromObject)
{
  this->ooShortId::operator=(ooReinterpretCast(const ooObj *,fromObject));
  return *this;
}
inline
ooShortRef(ooIndexBase)::ooShortRefStructor(ooIndexBase)()
{
}
#ifdef OO_BUGGY_TEMPLATES
inline
ooShortRef(ooIndexBase)::ooShortRefStructor(ooIndexBase)(const ooShortRef(ooIndexBase) &  shortId)
{
  *this = shortId;
}
#else // !defined(OO_BUGGY_TEMPLATES)
inline
ooShortRef(ooIndexBase)::ooShortRefStructor(ooIndexBase)(const ooShortRef(ooIndexBase) &  shortId) :
    ooShortRef(ooSysIndex)(shortId)
{
}
#endif // !defined(OO_BUGGY_TEMPLATES)
#ifdef OO_BUGGY_TEMPLATES
inline
ooShortRef(ooIndexBase)::ooShortRefStructor(ooIndexBase)(const ooRef(ooIndexBase) &  id)
{
  *this = id;
}
#else // !defined(OO_BUGGY_TEMPLATES)
inline
ooShortRef(ooIndexBase)::ooShortRefStructor(ooIndexBase)(const ooRef(ooIndexBase) &  id) :
    ooShortRef(ooSysIndex)(id)
{
}
#endif // !defined(OO_BUGGY_TEMPLATES)
#ifdef OO_BUGGY_TEMPLATES
inline
ooShortRef(ooIndexBase)::ooShortRefStructor(ooIndexBase)(const ooHandleSuper(ooIndexBase) &  objH)
{
  *this = objH;
}
#else // !defined(OO_BUGGY_TEMPLATES)
inline
ooShortRef(ooIndexBase)::ooShortRefStructor(ooIndexBase)(const ooHandleSuper(ooIndexBase) &  objH) :
    ooShortRef(ooSysIndex)(objH)
{
}
#endif // !defined(OO_BUGGY_TEMPLATES)
#ifdef OO_BUGGY_TEMPLATES
inline
ooShortRef(ooIndexBase)::ooShortRefStructor(ooIndexBase)(const ooIndexBase *  fromObject)
{
  *this = fromObject;
}
#else // !defined(OO_BUGGY_TEMPLATES)
inline
ooShortRef(ooIndexBase)::ooShortRefStructor(ooIndexBase)(const ooIndexBase *  fromObject) :
    ooShortRef(ooSysIndex)(ooReinterpretCast(const ooSysIndex *,fromObject))
{
}
#endif // !defined(OO_BUGGY_TEMPLATES)


/* methods on ooHandle(ooIndexBase) */
inline
ooHandle(ooIndexBase)::ooHandleStructor(ooIndexBase)()
{
}
inline
ooHandle(ooIndexBase)::ooHandleStructor(ooIndexBase)(const ooHandle(ooIndexBase) &  objH) :
#ifdef OO_BUGGY_TEMPLATES
    ooHandle_superclass<ooIndexBase >(objH)
#else // !defined(OO_BUGGY_TEMPLATES)
    ooHandle(ooSysIndex)(objH)
#endif // !defined(OO_BUGGY_TEMPLATES)
{
}
inline
ooHandle(ooIndexBase)::ooHandleStructor(ooIndexBase)(const ooRef(ooIndexBase) &  id) :
#ifdef OO_BUGGY_TEMPLATES
    ooHandle_superclass<ooIndexBase >(id)
#else // !defined(OO_BUGGY_TEMPLATES)
    ooHandle(ooSysIndex)(id)
#endif // !defined(OO_BUGGY_TEMPLATES)
{
}
inline
ooHandle(ooIndexBase)::ooHandleStructor(ooIndexBase)(const ooIndexBase *  fromObject) :
#ifdef OO_BUGGY_TEMPLATES
    ooHandle_superclass<ooIndexBase >(ooReinterpretCast(const ooSysIndex *,fromObject))
#else // !defined(OO_BUGGY_TEMPLATES)
    ooHandle(ooSysIndex)(ooReinterpretCast(const ooSysIndex *,fromObject))
#endif // !defined(OO_BUGGY_TEMPLATES)
{
}
inline
ooHandle(ooIndexBase)&
ooHandle(ooIndexBase)::operator=(const ooRef(ooIndexBase) &  id)
{
  this->ooHandle(ooObj)::operator=(id);
  return *this;
}
inline
ooHandle(ooIndexBase)&
ooHandle(ooIndexBase)::operator=(const ooHandle(ooIndexBase) &  objH)
{
  this->ooHandle(ooObj)::operator=(objH);
  return *this;
}
inline
ooHandle(ooIndexBase)&
ooHandle(ooIndexBase)::operator=(const ooShortRef(ooIndexBase) &  shortId)
{
  this->ooHandle(ooObj)::operator=(shortId);
  return *this;
}
inline
ooHandle(ooIndexBase)&
ooHandle(ooIndexBase)::operator=(const ooIndexBase *  fromObject)
{
  this->ooHandle(ooObj)::operator=(ooReinterpretCast(const ooObj *,fromObject));
  return *this;
}
inline
ooIndexBase *
ooHandle(ooIndexBase)::pin(ooMode  openMode) const
{
  return ooReinterpretCast(ooIndexBase *, this->pin_obj_internal(openMode));
}
inline
ooIndexBase *
ooHandle(ooIndexBase)::operator->() const
{
  return this->vm();
}
inline
ooIndexBase &
ooHandle(ooIndexBase)::operator*() const
{
  return *(this->vm());
}
inline
ooHandle(ooIndexBase)::operator ooIndexBase *() const
{
  if ( _state == oocHandlePTR  )
    return ooReinterpretCast(ooIndexBase *, _ptr._obj);
  else return ooReinterpretCast(ooIndexBase *, this->get_vm());
}
inline
ooIndexBase *
ooHandle(ooIndexBase)::vm() const
{
  if ( _state == oocHandlePTR && _ptr._obj != NULL )
    return ooReinterpretCast(ooIndexBase *, _ptr._obj);
  else return ooReinterpretCast(ooIndexBase *, this->get_vm());
}
inline
ooRef(ooIndexBase) &
ooHandle(ooIndexBase)::copy(const ooHandle(ooObj) &  nearH,
		   ooRef(ooIndexBase) &              result) const
{
  this->ooHandle(ooObj)::copy(nearH, result);
  return result;
}


/* ODMG methods */
inline
ooIndexBase *
ooRef(ooIndexBase)::ptr() const
{
  return this->pin();
}
inline
ooIndexBase *
ooHandle(ooIndexBase)::ptr() const
{
  return this->operator ooIndexBase *();
}
class ooKeyedIndex;


/////////////////////////////////////////////////////////////////////////////

ooTemplateSpecialization
class ooDeref(ooKeyedIndex) : public ooDerefBase {
	friend class ooRef(ooKeyedIndex);
  public:
    ~ooDerefStructor(ooKeyedIndex)();
    inline ooKeyedIndex *operator->() const;
#ifndef OO_BUGGY_TEMPLATES
  private:
#endif // !defined(OO_BUGGY_TEMPLATES)
    ooDerefStructor(ooKeyedIndex)(ooDeref(ooKeyedIndex)& deref);
    ooDerefStructor(ooKeyedIndex)(ooObj *  fromObject);
};


#ifdef OO_BUGGY_TEMPLATES

class ooHandle_superclass<ooKeyedIndex > : public ooHandle(ooIndexBase) {
 protected:
  ooHandle_superclass()
    {}
  ooHandle_superclass(const ooHandle(ooIndexBase) &  from) :
      ooHandle(ooIndexBase)(from)
    {}
  ooHandle_superclass(const ooRef(ooIndexBase) &  from) :
      ooHandle(ooIndexBase)(from)
    {}
  ooHandle_superclass(const ooIndexBase *  from) :
      ooHandle(ooIndexBase)(from)
    {}
  ~ooHandle_superclass()
    {}
};

class ooShortRef_superclass<ooKeyedIndex > : public ooShortRef(ooIndexBase) {
};

#endif // OO_BUGGY_TEMPLATES

ooTemplateSpecialization
class ooRef(ooKeyedIndex) : public ooRef(ooIndexBase) {
  public:
    ooRefStructor(ooKeyedIndex)()
      {}
    ooRefStructor(ooKeyedIndex)(const ooRef(ooKeyedIndex)& id) :
	  ooRef(ooIndexBase)(id)
      {}
    inline ooRefStructor(ooKeyedIndex)(const ooHandleSuper(ooKeyedIndex)& objH);
    inline ooRefStructor(ooKeyedIndex)(const ooKeyedIndex *  fromObject);
    inline ooRef(ooKeyedIndex)& operator=(const ooRef(ooKeyedIndex)& id);
    inline ooRef(ooKeyedIndex)& operator=(const ooShortRefSuper(ooKeyedIndex) &shortId);
    inline ooRef(ooKeyedIndex)& operator=(const ooHandleSuper(ooKeyedIndex)& objH);
    inline ooRef(ooKeyedIndex)& operator=(const ooKeyedIndex *  fromObject);
    ooStatus lookupObj(const ooHandle(ooObj)& scopeH,
		       const ooKey& key,
		       ooMode openMode = oocRead);
    ooStatus lookupObj(const ooHandle(ooObj)& scopeH,
		       const char* name,
		       ooMode openMode = oocRead);
#ifndef OO_BUGGY_TEMPLATES
    inline ooRef(ooKeyedIndex)& copy(const ooHandle(ooObj)& nearH,
		    ooRef(ooKeyedIndex)& newObjRef) const;
    inline ooHandle(ooKeyedIndex)& copy(const ooHandle(ooObj)& nearH,
			ooHandle(ooKeyedIndex)& result) const;
    inline ooHandle(ooKeyedIndex) copy(const ooHandle(ooObj)& nearH) const;
#endif // !defined(OO_BUGGY_TEMPLATES)
    inline ooKeyedIndex *pin(ooMode openMode = oocRead) const;
    ooDeref(ooKeyedIndex) operator->() const;
    /* Use pin() or use ooHandle "operator ooKeyedIndex *" instead of vm. */
    /* OBSOLETE */ inline ooKeyedIndex *vm(ooMode openMode = oocRead) const;
    // ODMG methods:
    ooRefStructor(ooKeyedIndex)(const d_Ref_Any &from);
    ooKeyedIndex *ptr() const;
};

ooTemplateSpecialization
class ooShortRef(ooKeyedIndex) :
#ifdef OO_BUGGY_TEMPLATES
			public ooShortRef_superclass<ooKeyedIndex >
#else // !defined(OO_BUGGY_TEMPLATES)
			public ooShortRef(ooIndexBase)
#endif // !defined(OO_BUGGY_TEMPLATES)
					            {
  public:
    ooShortRefStructor(ooKeyedIndex)();
    ooShortRefStructor(ooKeyedIndex)(const ooShortRef(ooKeyedIndex)& shortId);
    ooShortRefStructor(ooKeyedIndex)(const ooRef(ooKeyedIndex)& id);
    ooShortRefStructor(ooKeyedIndex)(const ooHandleSuper(ooKeyedIndex) &objH);
    ooShortRefStructor(ooKeyedIndex)(const ooKeyedIndex *  fromObject);
    ooShortRef(ooKeyedIndex)& operator=(const ooShortRef(ooKeyedIndex)& shortId);
    ooShortRef(ooKeyedIndex)& operator=(const ooRef(ooKeyedIndex)& id);
    ooShortRef(ooKeyedIndex)& operator=(const ooHandleSuper(ooKeyedIndex) &objH);
    ooShortRef(ooKeyedIndex)& operator=(const ooKeyedIndex *  fromObject);
};

ooTemplateSpecialization
class ooHandle(ooKeyedIndex) :
#ifdef OO_BUGGY_TEMPLATES
		      public ooHandle_superclass<ooKeyedIndex >
#else // !defined(OO_BUGGY_TEMPLATES)
		      public ooHandle(ooIndexBase)
#endif // !defined(OO_BUGGY_TEMPLATES)
                                                {
  public:
    inline ooHandleStructor(ooKeyedIndex)();
    inline ooHandleStructor(ooKeyedIndex)(const ooRef(ooKeyedIndex)& id);
    inline ooHandleStructor(ooKeyedIndex)(const ooHandle(ooKeyedIndex)& objH);
    inline ooHandleStructor(ooKeyedIndex)(const ooKeyedIndex *  fromObject);
    inline ooHandle(ooKeyedIndex)& operator=(const ooRef(ooKeyedIndex)& id);
    inline ooHandle(ooKeyedIndex)& operator=(const ooHandle(ooKeyedIndex)& objH);
    inline ooHandle(ooKeyedIndex)& operator=(const ooShortRef(ooKeyedIndex)& shortId);
    inline ooHandle(ooKeyedIndex)& operator=(const ooKeyedIndex *  fromObject);
    ooStatus lookupObj(const ooHandle(ooObj)& scopeH,
		       const ooKey& key,
		       ooMode openMode = oocRead);
    ooStatus lookupObj(const ooHandle(ooObj)& scopeH,
		       const char* name,
		       ooMode openMode = oocRead);
    ooHandle(ooKeyedIndex)& copy(const ooHandle(ooObj)& nearH,
		       ooHandle(ooKeyedIndex)& result) const;
    inline ooRef(ooKeyedIndex)& copy(const ooHandle(ooObj)& nearH,
		    ooRef(ooKeyedIndex)& result) const;
    ooHandle(ooKeyedIndex) copy(const ooHandle(ooObj)& nearH) const;
    inline ooKeyedIndex *pin(ooMode openMode = oocRead) const;
    inline ooKeyedIndex *operator->() const;
    inline ooKeyedIndex &operator*() const;
    inline operator ooKeyedIndex *() const;
    /* Use "operator ooKeyedIndex *" instead of vm. */
    /* OBSOLETE */ inline ooKeyedIndex *vm() const;
    // ODMG methods:
    ooHandleStructor(ooKeyedIndex)(const d_Ref_Any &from);
    ooKeyedIndex *ptr() const;
};

ooTemplateSpecialization
class ooItr(ooKeyedIndex) : public ooHandle(ooKeyedIndex),
		    public ooIteratorObjOrContObj {
  public:
    ooItrStructor(ooKeyedIndex)();
    ~ooItrStructor(ooKeyedIndex)();
  private:
    // Defined only to prevent implicit definition:
    ooItrStructor(ooKeyedIndex)(ooItr(ooKeyedIndex)&);
    ooItr(ooKeyedIndex)    operator=(ooItr(ooKeyedIndex)&);
};


/* methods on ooDeref(ooKeyedIndex) */
inline
ooDeref(ooKeyedIndex)::ooDerefStructor(ooKeyedIndex)(ooDeref(ooKeyedIndex) &  deref) :
    ooDerefBase(deref.vm())
{
  this->pinCompensate();
}
inline
ooDeref(ooKeyedIndex)::ooDerefStructor(ooKeyedIndex)(ooObj *  fromObject) :
    ooDerefBase(fromObject)
{
}
inline
ooDeref(ooKeyedIndex)::~ooDerefStructor(ooKeyedIndex)()
{
}
inline
ooKeyedIndex *
ooDeref(ooKeyedIndex)::operator->() const
{
  return ooReinterpretCast(ooKeyedIndex *, this->vm());
}


/* methods on ooRef(ooKeyedIndex) */
inline
ooRef(ooKeyedIndex)::ooRefStructor(ooKeyedIndex)(const ooHandleSuper(ooKeyedIndex)& objH) :
    ooRef(ooIndexBase)(objH)
{
}
inline
ooRef(ooKeyedIndex)::ooRefStructor(ooKeyedIndex)(const ooKeyedIndex *  fromObject) :
    ooRef(ooIndexBase)(ooReinterpretCast(const ooIndexBase *, fromObject))
{
}
inline
ooRef(ooKeyedIndex)&
ooRef(ooKeyedIndex)::operator=(const ooRef(ooKeyedIndex) &  id)
{
  this->ooId::operator=(id);
  return *this;
}
inline
ooRef(ooKeyedIndex)&
ooRef(ooKeyedIndex)::operator=(const ooShortRefSuper(ooKeyedIndex) &  shortId)
{
  this->ooRef(ooObj)::operator=(shortId);
  return *this;
}
inline
ooRef(ooKeyedIndex)&
ooRef(ooKeyedIndex)::operator=(const ooHandleSuper(ooKeyedIndex) &  objH)
{
  this->ooRef(ooObj)::operator=(objH);
  return *this;
}
inline
ooRef(ooKeyedIndex)&
ooRef(ooKeyedIndex)::operator=(const ooKeyedIndex *  fromObject)
{
  this->ooRef(ooObj)::operator=(ooReinterpretCast(const ooObj *, fromObject));
  return *this;
}
inline
ooKeyedIndex *
ooRef(ooKeyedIndex)::pin(ooMode  openMode) const
{
  return ooReinterpretCast(ooKeyedIndex *, this->pin_ref_internal(openMode));
}
inline
ooKeyedIndex *
ooRef(ooKeyedIndex)::vm(ooMode  openMode) const
{
  return this->pin(openMode);
}
#ifndef OO_BUGGY_TEMPLATES
inline
ooHandle(ooKeyedIndex) &
ooRef(ooKeyedIndex)::copy(const ooHandle(ooObj) &  nearH,
		ooHandle(ooKeyedIndex) &           result) const
{
  this->ooRef(ooObj)::copy(nearH, result);
  return result;
}
inline
ooRef(ooKeyedIndex) &
ooRef(ooKeyedIndex)::copy(const ooHandle(ooObj) &  nearH,
		ooRef(ooKeyedIndex) &              newObjRef) const
{
  this->ooRef(ooObj)::copy(nearH, newObjRef);
  return newObjRef;
}
inline
ooHandle(ooKeyedIndex)
ooRef(ooKeyedIndex)::copy(const ooHandle(ooObj) &  nearH) const
{
  ooHandle(ooKeyedIndex) result;
  this->ooRef(ooObj)::copy(nearH, result);
  return result;
}
#endif // !defined(OO_BUGGY_TEMPLATES)
inline
ooDeref(ooKeyedIndex)
ooRef(ooKeyedIndex)::operator->() const
{
  ooDeref(ooKeyedIndex) result(this->pin_ref_internal(oocRead));
  return result;
}


/* methods on ooShortRef(ooKeyedIndex) */
inline
ooShortRef(ooKeyedIndex) &
ooShortRef(ooKeyedIndex)::operator=(const ooShortRef(ooKeyedIndex) &  shortId)
{
  this->ooShortId::operator=(shortId);
  return *this;
}
inline
ooShortRef(ooKeyedIndex) &
ooShortRef(ooKeyedIndex)::operator=(const ooRef(ooKeyedIndex) &  id)
{
  this->ooShortId::operator=(id);
  return *this;
}
inline
ooShortRef(ooKeyedIndex) &
ooShortRef(ooKeyedIndex)::operator=(const ooHandleSuper(ooKeyedIndex) &  objH)
{
  this->ooShortId::operator=(objH);
  return *this;
}
inline
ooShortRef(ooKeyedIndex)&
ooShortRef(ooKeyedIndex)::operator=(const ooKeyedIndex *  fromObject)
{
  this->ooShortId::operator=(ooReinterpretCast(const ooObj *,fromObject));
  return *this;
}
inline
ooShortRef(ooKeyedIndex)::ooShortRefStructor(ooKeyedIndex)()
{
}
#ifdef OO_BUGGY_TEMPLATES
inline
ooShortRef(ooKeyedIndex)::ooShortRefStructor(ooKeyedIndex)(const ooShortRef(ooKeyedIndex) &  shortId)
{
  *this = shortId;
}
#else // !defined(OO_BUGGY_TEMPLATES)
inline
ooShortRef(ooKeyedIndex)::ooShortRefStructor(ooKeyedIndex)(const ooShortRef(ooKeyedIndex) &  shortId) :
    ooShortRef(ooIndexBase)(shortId)
{
}
#endif // !defined(OO_BUGGY_TEMPLATES)
#ifdef OO_BUGGY_TEMPLATES
inline
ooShortRef(ooKeyedIndex)::ooShortRefStructor(ooKeyedIndex)(const ooRef(ooKeyedIndex) &  id)
{
  *this = id;
}
#else // !defined(OO_BUGGY_TEMPLATES)
inline
ooShortRef(ooKeyedIndex)::ooShortRefStructor(ooKeyedIndex)(const ooRef(ooKeyedIndex) &  id) :
    ooShortRef(ooIndexBase)(id)
{
}
#endif // !defined(OO_BUGGY_TEMPLATES)
#ifdef OO_BUGGY_TEMPLATES
inline
ooShortRef(ooKeyedIndex)::ooShortRefStructor(ooKeyedIndex)(const ooHandleSuper(ooKeyedIndex) &  objH)
{
  *this = objH;
}
#else // !defined(OO_BUGGY_TEMPLATES)
inline
ooShortRef(ooKeyedIndex)::ooShortRefStructor(ooKeyedIndex)(const ooHandleSuper(ooKeyedIndex) &  objH) :
    ooShortRef(ooIndexBase)(objH)
{
}
#endif // !defined(OO_BUGGY_TEMPLATES)
#ifdef OO_BUGGY_TEMPLATES
inline
ooShortRef(ooKeyedIndex)::ooShortRefStructor(ooKeyedIndex)(const ooKeyedIndex *  fromObject)
{
  *this = fromObject;
}
#else // !defined(OO_BUGGY_TEMPLATES)
inline
ooShortRef(ooKeyedIndex)::ooShortRefStructor(ooKeyedIndex)(const ooKeyedIndex *  fromObject) :
    ooShortRef(ooIndexBase)(ooReinterpretCast(const ooIndexBase *,fromObject))
{
}
#endif // !defined(OO_BUGGY_TEMPLATES)


/* methods on ooHandle(ooKeyedIndex) */
inline
ooHandle(ooKeyedIndex)::ooHandleStructor(ooKeyedIndex)()
{
}
inline
ooHandle(ooKeyedIndex)::ooHandleStructor(ooKeyedIndex)(const ooHandle(ooKeyedIndex) &  objH) :
#ifdef OO_BUGGY_TEMPLATES
    ooHandle_superclass<ooKeyedIndex >(objH)
#else // !defined(OO_BUGGY_TEMPLATES)
    ooHandle(ooIndexBase)(objH)
#endif // !defined(OO_BUGGY_TEMPLATES)
{
}
inline
ooHandle(ooKeyedIndex)::ooHandleStructor(ooKeyedIndex)(const ooRef(ooKeyedIndex) &  id) :
#ifdef OO_BUGGY_TEMPLATES
    ooHandle_superclass<ooKeyedIndex >(id)
#else // !defined(OO_BUGGY_TEMPLATES)
    ooHandle(ooIndexBase)(id)
#endif // !defined(OO_BUGGY_TEMPLATES)
{
}
inline
ooHandle(ooKeyedIndex)::ooHandleStructor(ooKeyedIndex)(const ooKeyedIndex *  fromObject) :
#ifdef OO_BUGGY_TEMPLATES
    ooHandle_superclass<ooKeyedIndex >(ooReinterpretCast(const ooIndexBase *,fromObject))
#else // !defined(OO_BUGGY_TEMPLATES)
    ooHandle(ooIndexBase)(ooReinterpretCast(const ooIndexBase *,fromObject))
#endif // !defined(OO_BUGGY_TEMPLATES)
{
}
inline
ooHandle(ooKeyedIndex)&
ooHandle(ooKeyedIndex)::operator=(const ooRef(ooKeyedIndex) &  id)
{
  this->ooHandle(ooObj)::operator=(id);
  return *this;
}
inline
ooHandle(ooKeyedIndex)&
ooHandle(ooKeyedIndex)::operator=(const ooHandle(ooKeyedIndex) &  objH)
{
  this->ooHandle(ooObj)::operator=(objH);
  return *this;
}
inline
ooHandle(ooKeyedIndex)&
ooHandle(ooKeyedIndex)::operator=(const ooShortRef(ooKeyedIndex) &  shortId)
{
  this->ooHandle(ooObj)::operator=(shortId);
  return *this;
}
inline
ooHandle(ooKeyedIndex)&
ooHandle(ooKeyedIndex)::operator=(const ooKeyedIndex *  fromObject)
{
  this->ooHandle(ooObj)::operator=(ooReinterpretCast(const ooObj *,fromObject));
  return *this;
}
inline
ooKeyedIndex *
ooHandle(ooKeyedIndex)::pin(ooMode  openMode) const
{
  return ooReinterpretCast(ooKeyedIndex *, this->pin_obj_internal(openMode));
}
inline
ooKeyedIndex *
ooHandle(ooKeyedIndex)::operator->() const
{
  return this->vm();
}
inline
ooKeyedIndex &
ooHandle(ooKeyedIndex)::operator*() const
{
  return *(this->vm());
}
inline
ooHandle(ooKeyedIndex)::operator ooKeyedIndex *() const
{
  if ( _state == oocHandlePTR  )
    return ooReinterpretCast(ooKeyedIndex *, _ptr._obj);
  else return ooReinterpretCast(ooKeyedIndex *, this->get_vm());
}
inline
ooKeyedIndex *
ooHandle(ooKeyedIndex)::vm() const
{
  if ( _state == oocHandlePTR && _ptr._obj != NULL )
    return ooReinterpretCast(ooKeyedIndex *, _ptr._obj);
  else return ooReinterpretCast(ooKeyedIndex *, this->get_vm());
}
inline
ooRef(ooKeyedIndex) &
ooHandle(ooKeyedIndex)::copy(const ooHandle(ooObj) &  nearH,
		   ooRef(ooKeyedIndex) &              result) const
{
  this->ooHandle(ooObj)::copy(nearH, result);
  return result;
}


/* ODMG methods */
inline
ooKeyedIndex *
ooRef(ooKeyedIndex)::ptr() const
{
  return this->pin();
}
inline
ooKeyedIndex *
ooHandle(ooKeyedIndex)::ptr() const
{
  return this->operator ooKeyedIndex *();
}
class ooKeyField;


/////////////////////////////////////////////////////////////////////////////

ooTemplateSpecialization
class ooDeref(ooKeyField) : public ooDerefBase {
	friend class ooRef(ooKeyField);
  public:
    ~ooDerefStructor(ooKeyField)();
    inline ooKeyField *operator->() const;
#ifndef OO_BUGGY_TEMPLATES
  private:
#endif // !defined(OO_BUGGY_TEMPLATES)
    ooDerefStructor(ooKeyField)(ooDeref(ooKeyField)& deref);
    ooDerefStructor(ooKeyField)(ooObj *  fromObject);
};


#ifdef OO_BUGGY_TEMPLATES

class ooHandle_superclass<ooKeyField > : public ooHandle(ooObj) {
 protected:
  ooHandle_superclass()
    {}
  ooHandle_superclass(const ooHandle(ooObj) &  from) :
      ooHandle(ooObj)(from)
    {}
  ooHandle_superclass(const ooRef(ooObj) &  from) :
      ooHandle(ooObj)(from)
    {}
  ooHandle_superclass(const ooObj *  from) :
      ooHandle(ooObj)(from)
    {}
  ~ooHandle_superclass()
    {}
};

class ooShortRef_superclass<ooKeyField > : public ooShortRef(ooObj) {
};

#endif // OO_BUGGY_TEMPLATES

ooTemplateSpecialization
class ooRef(ooKeyField) : public ooRef(ooObj) {
  public:
    ooRefStructor(ooKeyField)()
      {}
    ooRefStructor(ooKeyField)(const ooRef(ooKeyField)& id) :
	  ooRef(ooObj)(id)
      {}
    inline ooRefStructor(ooKeyField)(const ooHandleSuper(ooKeyField)& objH);
    inline ooRefStructor(ooKeyField)(const ooKeyField *  fromObject);
    inline ooRef(ooKeyField)& operator=(const ooRef(ooKeyField)& id);
    inline ooRef(ooKeyField)& operator=(const ooShortRefSuper(ooKeyField) &shortId);
    inline ooRef(ooKeyField)& operator=(const ooHandleSuper(ooKeyField)& objH);
    inline ooRef(ooKeyField)& operator=(const ooKeyField *  fromObject);
    ooStatus lookupObj(const ooHandle(ooObj)& scopeH,
		       const ooKey& key,
		       ooMode openMode = oocRead);
    ooStatus lookupObj(const ooHandle(ooObj)& scopeH,
		       const char* name,
		       ooMode openMode = oocRead);
#ifndef OO_BUGGY_TEMPLATES
    inline ooRef(ooKeyField)& copy(const ooHandle(ooObj)& nearH,
		    ooRef(ooKeyField)& newObjRef) const;
    inline ooHandle(ooKeyField)& copy(const ooHandle(ooObj)& nearH,
			ooHandle(ooKeyField)& result) const;
    inline ooHandle(ooKeyField) copy(const ooHandle(ooObj)& nearH) const;
#endif // !defined(OO_BUGGY_TEMPLATES)
    inline ooKeyField *pin(ooMode openMode = oocRead) const;
    ooDeref(ooKeyField) operator->() const;
    /* Use pin() or use ooHandle "operator ooKeyField *" instead of vm. */
    /* OBSOLETE */ inline ooKeyField *vm(ooMode openMode = oocRead) const;
    // ODMG methods:
    ooRefStructor(ooKeyField)(const d_Ref_Any &from);
    ooKeyField *ptr() const;
};

ooTemplateSpecialization
class ooShortRef(ooKeyField) :
#ifdef OO_BUGGY_TEMPLATES
			public ooShortRef_superclass<ooKeyField >
#else // !defined(OO_BUGGY_TEMPLATES)
			public ooShortRef(ooObj)
#endif // !defined(OO_BUGGY_TEMPLATES)
					            {
  public:
    ooShortRefStructor(ooKeyField)();
    ooShortRefStructor(ooKeyField)(const ooShortRef(ooKeyField)& shortId);
    ooShortRefStructor(ooKeyField)(const ooRef(ooKeyField)& id);
    ooShortRefStructor(ooKeyField)(const ooHandleSuper(ooKeyField) &objH);
    ooShortRefStructor(ooKeyField)(const ooKeyField *  fromObject);
    ooShortRef(ooKeyField)& operator=(const ooShortRef(ooKeyField)& shortId);
    ooShortRef(ooKeyField)& operator=(const ooRef(ooKeyField)& id);
    ooShortRef(ooKeyField)& operator=(const ooHandleSuper(ooKeyField) &objH);
    ooShortRef(ooKeyField)& operator=(const ooKeyField *  fromObject);
};

ooTemplateSpecialization
class ooHandle(ooKeyField) :
#ifdef OO_BUGGY_TEMPLATES
		      public ooHandle_superclass<ooKeyField >
#else // !defined(OO_BUGGY_TEMPLATES)
		      public ooHandle(ooObj)
#endif // !defined(OO_BUGGY_TEMPLATES)
                                                {
  public:
    inline ooHandleStructor(ooKeyField)();
    inline ooHandleStructor(ooKeyField)(const ooRef(ooKeyField)& id);
    inline ooHandleStructor(ooKeyField)(const ooHandle(ooKeyField)& objH);
    inline ooHandleStructor(ooKeyField)(const ooKeyField *  fromObject);
    inline ooHandle(ooKeyField)& operator=(const ooRef(ooKeyField)& id);
    inline ooHandle(ooKeyField)& operator=(const ooHandle(ooKeyField)& objH);
    inline ooHandle(ooKeyField)& operator=(const ooShortRef(ooKeyField)& shortId);
    inline ooHandle(ooKeyField)& operator=(const ooKeyField *  fromObject);
    ooStatus lookupObj(const ooHandle(ooObj)& scopeH,
		       const ooKey& key,
		       ooMode openMode = oocRead);
    ooStatus lookupObj(const ooHandle(ooObj)& scopeH,
		       const char* name,
		       ooMode openMode = oocRead);
    ooHandle(ooKeyField)& copy(const ooHandle(ooObj)& nearH,
		       ooHandle(ooKeyField)& result) const;
    inline ooRef(ooKeyField)& copy(const ooHandle(ooObj)& nearH,
		    ooRef(ooKeyField)& result) const;
    ooHandle(ooKeyField) copy(const ooHandle(ooObj)& nearH) const;
    inline ooKeyField *pin(ooMode openMode = oocRead) const;
    inline ooKeyField *operator->() const;
    inline ooKeyField &operator*() const;
    inline operator ooKeyField *() const;
    /* Use "operator ooKeyField *" instead of vm. */
    /* OBSOLETE */ inline ooKeyField *vm() const;
    // ODMG methods:
    ooHandleStructor(ooKeyField)(const d_Ref_Any &from);
    ooKeyField *ptr() const;
};

ooTemplateSpecialization
class ooItr(ooKeyField) : public ooHandle(ooKeyField),
		    public ooIteratorObjOrContObj {
  public:
    ooItrStructor(ooKeyField)();
    ~ooItrStructor(ooKeyField)();
  private:
    // Defined only to prevent implicit definition:
    ooItrStructor(ooKeyField)(ooItr(ooKeyField)&);
    ooItr(ooKeyField)    operator=(ooItr(ooKeyField)&);
};


/* methods on ooDeref(ooKeyField) */
inline
ooDeref(ooKeyField)::ooDerefStructor(ooKeyField)(ooDeref(ooKeyField) &  deref) :
    ooDerefBase(deref.vm())
{
  this->pinCompensate();
}
inline
ooDeref(ooKeyField)::ooDerefStructor(ooKeyField)(ooObj *  fromObject) :
    ooDerefBase(fromObject)
{
}
inline
ooDeref(ooKeyField)::~ooDerefStructor(ooKeyField)()
{
}
inline
ooKeyField *
ooDeref(ooKeyField)::operator->() const
{
  return ooReinterpretCast(ooKeyField *, this->vm());
}


/* methods on ooRef(ooKeyField) */
inline
ooRef(ooKeyField)::ooRefStructor(ooKeyField)(const ooHandleSuper(ooKeyField)& objH) :
    ooRef(ooObj)(objH)
{
}
inline
ooRef(ooKeyField)::ooRefStructor(ooKeyField)(const ooKeyField *  fromObject) :
    ooRef(ooObj)(ooReinterpretCast(const ooObj *, fromObject))
{
}
inline
ooRef(ooKeyField)&
ooRef(ooKeyField)::operator=(const ooRef(ooKeyField) &  id)
{
  this->ooId::operator=(id);
  return *this;
}
inline
ooRef(ooKeyField)&
ooRef(ooKeyField)::operator=(const ooShortRefSuper(ooKeyField) &  shortId)
{
  this->ooRef(ooObj)::operator=(shortId);
  return *this;
}
inline
ooRef(ooKeyField)&
ooRef(ooKeyField)::operator=(const ooHandleSuper(ooKeyField) &  objH)
{
  this->ooRef(ooObj)::operator=(objH);
  return *this;
}
inline
ooRef(ooKeyField)&
ooRef(ooKeyField)::operator=(const ooKeyField *  fromObject)
{
  this->ooRef(ooObj)::operator=(ooReinterpretCast(const ooObj *, fromObject));
  return *this;
}
inline
ooKeyField *
ooRef(ooKeyField)::pin(ooMode  openMode) const
{
  return ooReinterpretCast(ooKeyField *, this->pin_ref_internal(openMode));
}
inline
ooKeyField *
ooRef(ooKeyField)::vm(ooMode  openMode) const
{
  return this->pin(openMode);
}
#ifndef OO_BUGGY_TEMPLATES
inline
ooHandle(ooKeyField) &
ooRef(ooKeyField)::copy(const ooHandle(ooObj) &  nearH,
		ooHandle(ooKeyField) &           result) const
{
  this->ooRef(ooObj)::copy(nearH, result);
  return result;
}
inline
ooRef(ooKeyField) &
ooRef(ooKeyField)::copy(const ooHandle(ooObj) &  nearH,
		ooRef(ooKeyField) &              newObjRef) const
{
  this->ooRef(ooObj)::copy(nearH, newObjRef);
  return newObjRef;
}
inline
ooHandle(ooKeyField)
ooRef(ooKeyField)::copy(const ooHandle(ooObj) &  nearH) const
{
  ooHandle(ooKeyField) result;
  this->ooRef(ooObj)::copy(nearH, result);
  return result;
}
#endif // !defined(OO_BUGGY_TEMPLATES)
inline
ooDeref(ooKeyField)
ooRef(ooKeyField)::operator->() const
{
  ooDeref(ooKeyField) result(this->pin_ref_internal(oocRead));
  return result;
}


/* methods on ooShortRef(ooKeyField) */
inline
ooShortRef(ooKeyField) &
ooShortRef(ooKeyField)::operator=(const ooShortRef(ooKeyField) &  shortId)
{
  this->ooShortId::operator=(shortId);
  return *this;
}
inline
ooShortRef(ooKeyField) &
ooShortRef(ooKeyField)::operator=(const ooRef(ooKeyField) &  id)
{
  this->ooShortId::operator=(id);
  return *this;
}
inline
ooShortRef(ooKeyField) &
ooShortRef(ooKeyField)::operator=(const ooHandleSuper(ooKeyField) &  objH)
{
  this->ooShortId::operator=(objH);
  return *this;
}
inline
ooShortRef(ooKeyField)&
ooShortRef(ooKeyField)::operator=(const ooKeyField *  fromObject)
{
  this->ooShortId::operator=(ooReinterpretCast(const ooObj *,fromObject));
  return *this;
}
inline
ooShortRef(ooKeyField)::ooShortRefStructor(ooKeyField)()
{
}
#ifdef OO_BUGGY_TEMPLATES
inline
ooShortRef(ooKeyField)::ooShortRefStructor(ooKeyField)(const ooShortRef(ooKeyField) &  shortId)
{
  *this = shortId;
}
#else // !defined(OO_BUGGY_TEMPLATES)
inline
ooShortRef(ooKeyField)::ooShortRefStructor(ooKeyField)(const ooShortRef(ooKeyField) &  shortId) :
    ooShortRef(ooObj)(shortId)
{
}
#endif // !defined(OO_BUGGY_TEMPLATES)
#ifdef OO_BUGGY_TEMPLATES
inline
ooShortRef(ooKeyField)::ooShortRefStructor(ooKeyField)(const ooRef(ooKeyField) &  id)
{
  *this = id;
}
#else // !defined(OO_BUGGY_TEMPLATES)
inline
ooShortRef(ooKeyField)::ooShortRefStructor(ooKeyField)(const ooRef(ooKeyField) &  id) :
    ooShortRef(ooObj)(id)
{
}
#endif // !defined(OO_BUGGY_TEMPLATES)
#ifdef OO_BUGGY_TEMPLATES
inline
ooShortRef(ooKeyField)::ooShortRefStructor(ooKeyField)(const ooHandleSuper(ooKeyField) &  objH)
{
  *this = objH;
}
#else // !defined(OO_BUGGY_TEMPLATES)
inline
ooShortRef(ooKeyField)::ooShortRefStructor(ooKeyField)(const ooHandleSuper(ooKeyField) &  objH) :
    ooShortRef(ooObj)(objH)
{
}
#endif // !defined(OO_BUGGY_TEMPLATES)
#ifdef OO_BUGGY_TEMPLATES
inline
ooShortRef(ooKeyField)::ooShortRefStructor(ooKeyField)(const ooKeyField *  fromObject)
{
  *this = fromObject;
}
#else // !defined(OO_BUGGY_TEMPLATES)
inline
ooShortRef(ooKeyField)::ooShortRefStructor(ooKeyField)(const ooKeyField *  fromObject) :
    ooShortRef(ooObj)(ooReinterpretCast(const ooObj *,fromObject))
{
}
#endif // !defined(OO_BUGGY_TEMPLATES)


/* methods on ooHandle(ooKeyField) */
inline
ooHandle(ooKeyField)::ooHandleStructor(ooKeyField)()
{
}
inline
ooHandle(ooKeyField)::ooHandleStructor(ooKeyField)(const ooHandle(ooKeyField) &  objH) :
#ifdef OO_BUGGY_TEMPLATES
    ooHandle_superclass<ooKeyField >(objH)
#else // !defined(OO_BUGGY_TEMPLATES)
    ooHandle(ooObj)(objH)
#endif // !defined(OO_BUGGY_TEMPLATES)
{
}
inline
ooHandle(ooKeyField)::ooHandleStructor(ooKeyField)(const ooRef(ooKeyField) &  id) :
#ifdef OO_BUGGY_TEMPLATES
    ooHandle_superclass<ooKeyField >(id)
#else // !defined(OO_BUGGY_TEMPLATES)
    ooHandle(ooObj)(id)
#endif // !defined(OO_BUGGY_TEMPLATES)
{
}
inline
ooHandle(ooKeyField)::ooHandleStructor(ooKeyField)(const ooKeyField *  fromObject) :
#ifdef OO_BUGGY_TEMPLATES
    ooHandle_superclass<ooKeyField >(ooReinterpretCast(const ooObj *,fromObject))
#else // !defined(OO_BUGGY_TEMPLATES)
    ooHandle(ooObj)(ooReinterpretCast(const ooObj *,fromObject))
#endif // !defined(OO_BUGGY_TEMPLATES)
{
}
inline
ooHandle(ooKeyField)&
ooHandle(ooKeyField)::operator=(const ooRef(ooKeyField) &  id)
{
  this->ooHandle(ooObj)::operator=(id);
  return *this;
}
inline
ooHandle(ooKeyField)&
ooHandle(ooKeyField)::operator=(const ooHandle(ooKeyField) &  objH)
{
  this->ooHandle(ooObj)::operator=(objH);
  return *this;
}
inline
ooHandle(ooKeyField)&
ooHandle(ooKeyField)::operator=(const ooShortRef(ooKeyField) &  shortId)
{
  this->ooHandle(ooObj)::operator=(shortId);
  return *this;
}
inline
ooHandle(ooKeyField)&
ooHandle(ooKeyField)::operator=(const ooKeyField *  fromObject)
{
  this->ooHandle(ooObj)::operator=(ooReinterpretCast(const ooObj *,fromObject));
  return *this;
}
inline
ooKeyField *
ooHandle(ooKeyField)::pin(ooMode  openMode) const
{
  return ooReinterpretCast(ooKeyField *, this->pin_obj_internal(openMode));
}
inline
ooKeyField *
ooHandle(ooKeyField)::operator->() const
{
  return this->vm();
}
inline
ooKeyField &
ooHandle(ooKeyField)::operator*() const
{
  return *(this->vm());
}
inline
ooHandle(ooKeyField)::operator ooKeyField *() const
{
  if ( _state == oocHandlePTR  )
    return ooReinterpretCast(ooKeyField *, _ptr._obj);
  else return ooReinterpretCast(ooKeyField *, this->get_vm());
}
inline
ooKeyField *
ooHandle(ooKeyField)::vm() const
{
  if ( _state == oocHandlePTR && _ptr._obj != NULL )
    return ooReinterpretCast(ooKeyField *, _ptr._obj);
  else return ooReinterpretCast(ooKeyField *, this->get_vm());
}
inline
ooRef(ooKeyField) &
ooHandle(ooKeyField)::copy(const ooHandle(ooObj) &  nearH,
		   ooRef(ooKeyField) &              result) const
{
  this->ooHandle(ooObj)::copy(nearH, result);
  return result;
}


/* ODMG methods */
inline
ooKeyField *
ooRef(ooKeyField)::ptr() const
{
  return this->pin();
}
inline
ooKeyField *
ooHandle(ooKeyField)::ptr() const
{
  return this->operator ooKeyField *();
}
struct string_holder;


/////////////////////////////////////////////////////////////////////////////

ooTemplateSpecialization
class ooDeref(string_holder) : public ooDerefBase {
	friend class ooRef(string_holder);
  public:
    ~ooDerefStructor(string_holder)();
    inline string_holder *operator->() const;
#ifndef OO_BUGGY_TEMPLATES
  private:
#endif // !defined(OO_BUGGY_TEMPLATES)
    ooDerefStructor(string_holder)(ooDeref(string_holder)& deref);
    ooDerefStructor(string_holder)(ooObj *  fromObject);
};


#ifdef OO_BUGGY_TEMPLATES

class ooHandle_superclass<string_holder > : public ooHandle(ooObj) {
 protected:
  ooHandle_superclass()
    {}
  ooHandle_superclass(const ooHandle(ooObj) &  from) :
      ooHandle(ooObj)(from)
    {}
  ooHandle_superclass(const ooRef(ooObj) &  from) :
      ooHandle(ooObj)(from)
    {}
  ooHandle_superclass(const ooObj *  from) :
      ooHandle(ooObj)(from)
    {}
  ~ooHandle_superclass()
    {}
};

class ooShortRef_superclass<string_holder > : public ooShortRef(ooObj) {
};

#endif // OO_BUGGY_TEMPLATES

ooTemplateSpecialization
class ooRef(string_holder) : public ooRef(ooObj) {
  public:
    ooRefStructor(string_holder)()
      {}
    ooRefStructor(string_holder)(const ooRef(string_holder)& id) :
	  ooRef(ooObj)(id)
      {}
    inline ooRefStructor(string_holder)(const ooHandleSuper(string_holder)& objH);
    inline ooRefStructor(string_holder)(const string_holder *  fromObject);
    inline ooRef(string_holder)& operator=(const ooRef(string_holder)& id);
    inline ooRef(string_holder)& operator=(const ooShortRefSuper(string_holder) &shortId);
    inline ooRef(string_holder)& operator=(const ooHandleSuper(string_holder)& objH);
    inline ooRef(string_holder)& operator=(const string_holder *  fromObject);
    ooStatus lookupObj(const ooHandle(ooObj)& scopeH,
		       const ooKey& key,
		       ooMode openMode = oocRead);
    ooStatus lookupObj(const ooHandle(ooObj)& scopeH,
		       const char* name,
		       ooMode openMode = oocRead);
#ifndef OO_BUGGY_TEMPLATES
    inline ooRef(string_holder)& copy(const ooHandle(ooObj)& nearH,
		    ooRef(string_holder)& newObjRef) const;
    inline ooHandle(string_holder)& copy(const ooHandle(ooObj)& nearH,
			ooHandle(string_holder)& result) const;
    inline ooHandle(string_holder) copy(const ooHandle(ooObj)& nearH) const;
#endif // !defined(OO_BUGGY_TEMPLATES)
    inline string_holder *pin(ooMode openMode = oocRead) const;
    ooDeref(string_holder) operator->() const;
    /* Use pin() or use ooHandle "operator string_holder *" instead of vm. */
    /* OBSOLETE */ inline string_holder *vm(ooMode openMode = oocRead) const;
    // ODMG methods:
    ooRefStructor(string_holder)(const d_Ref_Any &from);
    string_holder *ptr() const;
};

ooTemplateSpecialization
class ooShortRef(string_holder) :
#ifdef OO_BUGGY_TEMPLATES
			public ooShortRef_superclass<string_holder >
#else // !defined(OO_BUGGY_TEMPLATES)
			public ooShortRef(ooObj)
#endif // !defined(OO_BUGGY_TEMPLATES)
					            {
  public:
    ooShortRefStructor(string_holder)();
    ooShortRefStructor(string_holder)(const ooShortRef(string_holder)& shortId);
    ooShortRefStructor(string_holder)(const ooRef(string_holder)& id);
    ooShortRefStructor(string_holder)(const ooHandleSuper(string_holder) &objH);
    ooShortRefStructor(string_holder)(const string_holder *  fromObject);
    ooShortRef(string_holder)& operator=(const ooShortRef(string_holder)& shortId);
    ooShortRef(string_holder)& operator=(const ooRef(string_holder)& id);
    ooShortRef(string_holder)& operator=(const ooHandleSuper(string_holder) &objH);
    ooShortRef(string_holder)& operator=(const string_holder *  fromObject);
};

ooTemplateSpecialization
class ooHandle(string_holder) :
#ifdef OO_BUGGY_TEMPLATES
		      public ooHandle_superclass<string_holder >
#else // !defined(OO_BUGGY_TEMPLATES)
		      public ooHandle(ooObj)
#endif // !defined(OO_BUGGY_TEMPLATES)
                                                {
  public:
    inline ooHandleStructor(string_holder)();
    inline ooHandleStructor(string_holder)(const ooRef(string_holder)& id);
    inline ooHandleStructor(string_holder)(const ooHandle(string_holder)& objH);
    inline ooHandleStructor(string_holder)(const string_holder *  fromObject);
    inline ooHandle(string_holder)& operator=(const ooRef(string_holder)& id);
    inline ooHandle(string_holder)& operator=(const ooHandle(string_holder)& objH);
    inline ooHandle(string_holder)& operator=(const ooShortRef(string_holder)& shortId);
    inline ooHandle(string_holder)& operator=(const string_holder *  fromObject);
    ooStatus lookupObj(const ooHandle(ooObj)& scopeH,
		       const ooKey& key,
		       ooMode openMode = oocRead);
    ooStatus lookupObj(const ooHandle(ooObj)& scopeH,
		       const char* name,
		       ooMode openMode = oocRead);
    ooHandle(string_holder)& copy(const ooHandle(ooObj)& nearH,
		       ooHandle(string_holder)& result) const;
    inline ooRef(string_holder)& copy(const ooHandle(ooObj)& nearH,
		    ooRef(string_holder)& result) const;
    ooHandle(string_holder) copy(const ooHandle(ooObj)& nearH) const;
    inline string_holder *pin(ooMode openMode = oocRead) const;
    inline string_holder *operator->() const;
    inline string_holder &operator*() const;
    inline operator string_holder *() const;
    /* Use "operator string_holder *" instead of vm. */
    /* OBSOLETE */ inline string_holder *vm() const;
    // ODMG methods:
    ooHandleStructor(string_holder)(const d_Ref_Any &from);
    string_holder *ptr() const;
};

ooTemplateSpecialization
class ooItr(string_holder) : public ooHandle(string_holder),
		    public ooIteratorObjOrContObj {
  public:
    ooItrStructor(string_holder)();
    ~ooItrStructor(string_holder)();
  private:
    // Defined only to prevent implicit definition:
    ooItrStructor(string_holder)(ooItr(string_holder)&);
    ooItr(string_holder)    operator=(ooItr(string_holder)&);
};


/* methods on ooDeref(string_holder) */
inline
ooDeref(string_holder)::ooDerefStructor(string_holder)(ooDeref(string_holder) &  deref) :
    ooDerefBase(deref.vm())
{
  this->pinCompensate();
}
inline
ooDeref(string_holder)::ooDerefStructor(string_holder)(ooObj *  fromObject) :
    ooDerefBase(fromObject)
{
}
inline
ooDeref(string_holder)::~ooDerefStructor(string_holder)()
{
}
inline
string_holder *
ooDeref(string_holder)::operator->() const
{
  return ooReinterpretCast(string_holder *, this->vm());
}


/* methods on ooRef(string_holder) */
inline
ooRef(string_holder)::ooRefStructor(string_holder)(const ooHandleSuper(string_holder)& objH) :
    ooRef(ooObj)(objH)
{
}
inline
ooRef(string_holder)::ooRefStructor(string_holder)(const string_holder *  fromObject) :
    ooRef(ooObj)(ooReinterpretCast(const ooObj *, fromObject))
{
}
inline
ooRef(string_holder)&
ooRef(string_holder)::operator=(const ooRef(string_holder) &  id)
{
  this->ooId::operator=(id);
  return *this;
}
inline
ooRef(string_holder)&
ooRef(string_holder)::operator=(const ooShortRefSuper(string_holder) &  shortId)
{
  this->ooRef(ooObj)::operator=(shortId);
  return *this;
}
inline
ooRef(string_holder)&
ooRef(string_holder)::operator=(const ooHandleSuper(string_holder) &  objH)
{
  this->ooRef(ooObj)::operator=(objH);
  return *this;
}
inline
ooRef(string_holder)&
ooRef(string_holder)::operator=(const string_holder *  fromObject)
{
  this->ooRef(ooObj)::operator=(ooReinterpretCast(const ooObj *, fromObject));
  return *this;
}
inline
string_holder *
ooRef(string_holder)::pin(ooMode  openMode) const
{
  return ooReinterpretCast(string_holder *, this->pin_ref_internal(openMode));
}
inline
string_holder *
ooRef(string_holder)::vm(ooMode  openMode) const
{
  return this->pin(openMode);
}
#ifndef OO_BUGGY_TEMPLATES
inline
ooHandle(string_holder) &
ooRef(string_holder)::copy(const ooHandle(ooObj) &  nearH,
		ooHandle(string_holder) &           result) const
{
  this->ooRef(ooObj)::copy(nearH, result);
  return result;
}
inline
ooRef(string_holder) &
ooRef(string_holder)::copy(const ooHandle(ooObj) &  nearH,
		ooRef(string_holder) &              newObjRef) const
{
  this->ooRef(ooObj)::copy(nearH, newObjRef);
  return newObjRef;
}
inline
ooHandle(string_holder)
ooRef(string_holder)::copy(const ooHandle(ooObj) &  nearH) const
{
  ooHandle(string_holder) result;
  this->ooRef(ooObj)::copy(nearH, result);
  return result;
}
#endif // !defined(OO_BUGGY_TEMPLATES)
inline
ooDeref(string_holder)
ooRef(string_holder)::operator->() const
{
  ooDeref(string_holder) result(this->pin_ref_internal(oocRead));
  return result;
}


/* methods on ooShortRef(string_holder) */
inline
ooShortRef(string_holder) &
ooShortRef(string_holder)::operator=(const ooShortRef(string_holder) &  shortId)
{
  this->ooShortId::operator=(shortId);
  return *this;
}
inline
ooShortRef(string_holder) &
ooShortRef(string_holder)::operator=(const ooRef(string_holder) &  id)
{
  this->ooShortId::operator=(id);
  return *this;
}
inline
ooShortRef(string_holder) &
ooShortRef(string_holder)::operator=(const ooHandleSuper(string_holder) &  objH)
{
  this->ooShortId::operator=(objH);
  return *this;
}
inline
ooShortRef(string_holder)&
ooShortRef(string_holder)::operator=(const string_holder *  fromObject)
{
  this->ooShortId::operator=(ooReinterpretCast(const ooObj *,fromObject));
  return *this;
}
inline
ooShortRef(string_holder)::ooShortRefStructor(string_holder)()
{
}
#ifdef OO_BUGGY_TEMPLATES
inline
ooShortRef(string_holder)::ooShortRefStructor(string_holder)(const ooShortRef(string_holder) &  shortId)
{
  *this = shortId;
}
#else // !defined(OO_BUGGY_TEMPLATES)
inline
ooShortRef(string_holder)::ooShortRefStructor(string_holder)(const ooShortRef(string_holder) &  shortId) :
    ooShortRef(ooObj)(shortId)
{
}
#endif // !defined(OO_BUGGY_TEMPLATES)
#ifdef OO_BUGGY_TEMPLATES
inline
ooShortRef(string_holder)::ooShortRefStructor(string_holder)(const ooRef(string_holder) &  id)
{
  *this = id;
}
#else // !defined(OO_BUGGY_TEMPLATES)
inline
ooShortRef(string_holder)::ooShortRefStructor(string_holder)(const ooRef(string_holder) &  id) :
    ooShortRef(ooObj)(id)
{
}
#endif // !defined(OO_BUGGY_TEMPLATES)
#ifdef OO_BUGGY_TEMPLATES
inline
ooShortRef(string_holder)::ooShortRefStructor(string_holder)(const ooHandleSuper(string_holder) &  objH)
{
  *this = objH;
}
#else // !defined(OO_BUGGY_TEMPLATES)
inline
ooShortRef(string_holder)::ooShortRefStructor(string_holder)(const ooHandleSuper(string_holder) &  objH) :
    ooShortRef(ooObj)(objH)
{
}
#endif // !defined(OO_BUGGY_TEMPLATES)
#ifdef OO_BUGGY_TEMPLATES
inline
ooShortRef(string_holder)::ooShortRefStructor(string_holder)(const string_holder *  fromObject)
{
  *this = fromObject;
}
#else // !defined(OO_BUGGY_TEMPLATES)
inline
ooShortRef(string_holder)::ooShortRefStructor(string_holder)(const string_holder *  fromObject) :
    ooShortRef(ooObj)(ooReinterpretCast(const ooObj *,fromObject))
{
}
#endif // !defined(OO_BUGGY_TEMPLATES)


/* methods on ooHandle(string_holder) */
inline
ooHandle(string_holder)::ooHandleStructor(string_holder)()
{
}
inline
ooHandle(string_holder)::ooHandleStructor(string_holder)(const ooHandle(string_holder) &  objH) :
#ifdef OO_BUGGY_TEMPLATES
    ooHandle_superclass<string_holder >(objH)
#else // !defined(OO_BUGGY_TEMPLATES)
    ooHandle(ooObj)(objH)
#endif // !defined(OO_BUGGY_TEMPLATES)
{
}
inline
ooHandle(string_holder)::ooHandleStructor(string_holder)(const ooRef(string_holder) &  id) :
#ifdef OO_BUGGY_TEMPLATES
    ooHandle_superclass<string_holder >(id)
#else // !defined(OO_BUGGY_TEMPLATES)
    ooHandle(ooObj)(id)
#endif // !defined(OO_BUGGY_TEMPLATES)
{
}
inline
ooHandle(string_holder)::ooHandleStructor(string_holder)(const string_holder *  fromObject) :
#ifdef OO_BUGGY_TEMPLATES
    ooHandle_superclass<string_holder >(ooReinterpretCast(const ooObj *,fromObject))
#else // !defined(OO_BUGGY_TEMPLATES)
    ooHandle(ooObj)(ooReinterpretCast(const ooObj *,fromObject))
#endif // !defined(OO_BUGGY_TEMPLATES)
{
}
inline
ooHandle(string_holder)&
ooHandle(string_holder)::operator=(const ooRef(string_holder) &  id)
{
  this->ooHandle(ooObj)::operator=(id);
  return *this;
}
inline
ooHandle(string_holder)&
ooHandle(string_holder)::operator=(const ooHandle(string_holder) &  objH)
{
  this->ooHandle(ooObj)::operator=(objH);
  return *this;
}
inline
ooHandle(string_holder)&
ooHandle(string_holder)::operator=(const ooShortRef(string_holder) &  shortId)
{
  this->ooHandle(ooObj)::operator=(shortId);
  return *this;
}
inline
ooHandle(string_holder)&
ooHandle(string_holder)::operator=(const string_holder *  fromObject)
{
  this->ooHandle(ooObj)::operator=(ooReinterpretCast(const ooObj *,fromObject));
  return *this;
}
inline
string_holder *
ooHandle(string_holder)::pin(ooMode  openMode) const
{
  return ooReinterpretCast(string_holder *, this->pin_obj_internal(openMode));
}
inline
string_holder *
ooHandle(string_holder)::operator->() const
{
  return this->vm();
}
inline
string_holder &
ooHandle(string_holder)::operator*() const
{
  return *(this->vm());
}
inline
ooHandle(string_holder)::operator string_holder *() const
{
  if ( _state == oocHandlePTR  )
    return ooReinterpretCast(string_holder *, _ptr._obj);
  else return ooReinterpretCast(string_holder *, this->get_vm());
}
inline
string_holder *
ooHandle(string_holder)::vm() const
{
  if ( _state == oocHandlePTR && _ptr._obj != NULL )
    return ooReinterpretCast(string_holder *, _ptr._obj);
  else return ooReinterpretCast(string_holder *, this->get_vm());
}
inline
ooRef(string_holder) &
ooHandle(string_holder)::copy(const ooHandle(ooObj) &  nearH,
		   ooRef(string_holder) &              result) const
{
  this->ooHandle(ooObj)::copy(nearH, result);
  return result;
}


/* ODMG methods */
inline
string_holder *
ooRef(string_holder)::ptr() const
{
  return this->pin();
}
inline
string_holder *
ooHandle(string_holder)::ptr() const
{
  return this->operator string_holder *();
}
class ooIndexDescBase;


/////////////////////////////////////////////////////////////////////////////

ooTemplateSpecialization
class ooDeref(ooIndexDescBase) : public ooDerefBase {
	friend class ooRef(ooIndexDescBase);
  public:
    ~ooDerefStructor(ooIndexDescBase)();
    inline ooIndexDescBase *operator->() const;
#ifndef OO_BUGGY_TEMPLATES
  private:
#endif // !defined(OO_BUGGY_TEMPLATES)
    ooDerefStructor(ooIndexDescBase)(ooDeref(ooIndexDescBase)& deref);
    ooDerefStructor(ooIndexDescBase)(ooObj *  fromObject);
};


#ifdef OO_BUGGY_TEMPLATES

class ooHandle_superclass<ooIndexDescBase > : public ooHandle(ooObj) {
 protected:
  ooHandle_superclass()
    {}
  ooHandle_superclass(const ooHandle(ooObj) &  from) :
      ooHandle(ooObj)(from)
    {}
  ooHandle_superclass(const ooRef(ooObj) &  from) :
      ooHandle(ooObj)(from)
    {}
  ooHandle_superclass(const ooObj *  from) :
      ooHandle(ooObj)(from)
    {}
  ~ooHandle_superclass()
    {}
};

class ooShortRef_superclass<ooIndexDescBase > : public ooShortRef(ooObj) {
};

#endif // OO_BUGGY_TEMPLATES

ooTemplateSpecialization
class ooRef(ooIndexDescBase) : public ooRef(ooObj) {
  public:
    ooRefStructor(ooIndexDescBase)()
      {}
    ooRefStructor(ooIndexDescBase)(const ooRef(ooIndexDescBase)& id) :
	  ooRef(ooObj)(id)
      {}
    inline ooRefStructor(ooIndexDescBase)(const ooHandleSuper(ooIndexDescBase)& objH);
    inline ooRefStructor(ooIndexDescBase)(const ooIndexDescBase *  fromObject);
    inline ooRef(ooIndexDescBase)& operator=(const ooRef(ooIndexDescBase)& id);
    inline ooRef(ooIndexDescBase)& operator=(const ooShortRefSuper(ooIndexDescBase) &shortId);
    inline ooRef(ooIndexDescBase)& operator=(const ooHandleSuper(ooIndexDescBase)& objH);
    inline ooRef(ooIndexDescBase)& operator=(const ooIndexDescBase *  fromObject);
    ooStatus lookupObj(const ooHandle(ooObj)& scopeH,
		       const ooKey& key,
		       ooMode openMode = oocRead);
    ooStatus lookupObj(const ooHandle(ooObj)& scopeH,
		       const char* name,
		       ooMode openMode = oocRead);
#ifndef OO_BUGGY_TEMPLATES
    inline ooRef(ooIndexDescBase)& copy(const ooHandle(ooObj)& nearH,
		    ooRef(ooIndexDescBase)& newObjRef) const;
    inline ooHandle(ooIndexDescBase)& copy(const ooHandle(ooObj)& nearH,
			ooHandle(ooIndexDescBase)& result) const;
    inline ooHandle(ooIndexDescBase) copy(const ooHandle(ooObj)& nearH) const;
#endif // !defined(OO_BUGGY_TEMPLATES)
    inline ooIndexDescBase *pin(ooMode openMode = oocRead) const;
    ooDeref(ooIndexDescBase) operator->() const;
    /* Use pin() or use ooHandle "operator ooIndexDescBase *" instead of vm. */
    /* OBSOLETE */ inline ooIndexDescBase *vm(ooMode openMode = oocRead) const;
    // ODMG methods:
    ooRefStructor(ooIndexDescBase)(const d_Ref_Any &from);
    ooIndexDescBase *ptr() const;
};

ooTemplateSpecialization
class ooShortRef(ooIndexDescBase) :
#ifdef OO_BUGGY_TEMPLATES
			public ooShortRef_superclass<ooIndexDescBase >
#else // !defined(OO_BUGGY_TEMPLATES)
			public ooShortRef(ooObj)
#endif // !defined(OO_BUGGY_TEMPLATES)
					            {
  public:
    ooShortRefStructor(ooIndexDescBase)();
    ooShortRefStructor(ooIndexDescBase)(const ooShortRef(ooIndexDescBase)& shortId);
    ooShortRefStructor(ooIndexDescBase)(const ooRef(ooIndexDescBase)& id);
    ooShortRefStructor(ooIndexDescBase)(const ooHandleSuper(ooIndexDescBase) &objH);
    ooShortRefStructor(ooIndexDescBase)(const ooIndexDescBase *  fromObject);
    ooShortRef(ooIndexDescBase)& operator=(const ooShortRef(ooIndexDescBase)& shortId);
    ooShortRef(ooIndexDescBase)& operator=(const ooRef(ooIndexDescBase)& id);
    ooShortRef(ooIndexDescBase)& operator=(const ooHandleSuper(ooIndexDescBase) &objH);
    ooShortRef(ooIndexDescBase)& operator=(const ooIndexDescBase *  fromObject);
};

ooTemplateSpecialization
class ooHandle(ooIndexDescBase) :
#ifdef OO_BUGGY_TEMPLATES
		      public ooHandle_superclass<ooIndexDescBase >
#else // !defined(OO_BUGGY_TEMPLATES)
		      public ooHandle(ooObj)
#endif // !defined(OO_BUGGY_TEMPLATES)
                                                {
  public:
    inline ooHandleStructor(ooIndexDescBase)();
    inline ooHandleStructor(ooIndexDescBase)(const ooRef(ooIndexDescBase)& id);
    inline ooHandleStructor(ooIndexDescBase)(const ooHandle(ooIndexDescBase)& objH);
    inline ooHandleStructor(ooIndexDescBase)(const ooIndexDescBase *  fromObject);
    inline ooHandle(ooIndexDescBase)& operator=(const ooRef(ooIndexDescBase)& id);
    inline ooHandle(ooIndexDescBase)& operator=(const ooHandle(ooIndexDescBase)& objH);
    inline ooHandle(ooIndexDescBase)& operator=(const ooShortRef(ooIndexDescBase)& shortId);
    inline ooHandle(ooIndexDescBase)& operator=(const ooIndexDescBase *  fromObject);
    ooStatus lookupObj(const ooHandle(ooObj)& scopeH,
		       const ooKey& key,
		       ooMode openMode = oocRead);
    ooStatus lookupObj(const ooHandle(ooObj)& scopeH,
		       const char* name,
		       ooMode openMode = oocRead);
    ooHandle(ooIndexDescBase)& copy(const ooHandle(ooObj)& nearH,
		       ooHandle(ooIndexDescBase)& result) const;
    inline ooRef(ooIndexDescBase)& copy(const ooHandle(ooObj)& nearH,
		    ooRef(ooIndexDescBase)& result) const;
    ooHandle(ooIndexDescBase) copy(const ooHandle(ooObj)& nearH) const;
    inline ooIndexDescBase *pin(ooMode openMode = oocRead) const;
    inline ooIndexDescBase *operator->() const;
    inline ooIndexDescBase &operator*() const;
    inline operator ooIndexDescBase *() const;
    /* Use "operator ooIndexDescBase *" instead of vm. */
    /* OBSOLETE */ inline ooIndexDescBase *vm() const;
    // ODMG methods:
    ooHandleStructor(ooIndexDescBase)(const d_Ref_Any &from);
    ooIndexDescBase *ptr() const;
};

ooTemplateSpecialization
class ooItr(ooIndexDescBase) : public ooHandle(ooIndexDescBase),
		    public ooIteratorObjOrContObj {
  public:
    ooItrStructor(ooIndexDescBase)();
    ~ooItrStructor(ooIndexDescBase)();
  private:
    // Defined only to prevent implicit definition:
    ooItrStructor(ooIndexDescBase)(ooItr(ooIndexDescBase)&);
    ooItr(ooIndexDescBase)    operator=(ooItr(ooIndexDescBase)&);
};


/* methods on ooDeref(ooIndexDescBase) */
inline
ooDeref(ooIndexDescBase)::ooDerefStructor(ooIndexDescBase)(ooDeref(ooIndexDescBase) &  deref) :
    ooDerefBase(deref.vm())
{
  this->pinCompensate();
}
inline
ooDeref(ooIndexDescBase)::ooDerefStructor(ooIndexDescBase)(ooObj *  fromObject) :
    ooDerefBase(fromObject)
{
}
inline
ooDeref(ooIndexDescBase)::~ooDerefStructor(ooIndexDescBase)()
{
}
inline
ooIndexDescBase *
ooDeref(ooIndexDescBase)::operator->() const
{
  return ooReinterpretCast(ooIndexDescBase *, this->vm());
}


/* methods on ooRef(ooIndexDescBase) */
inline
ooRef(ooIndexDescBase)::ooRefStructor(ooIndexDescBase)(const ooHandleSuper(ooIndexDescBase)& objH) :
    ooRef(ooObj)(objH)
{
}
inline
ooRef(ooIndexDescBase)::ooRefStructor(ooIndexDescBase)(const ooIndexDescBase *  fromObject) :
    ooRef(ooObj)(ooReinterpretCast(const ooObj *, fromObject))
{
}
inline
ooRef(ooIndexDescBase)&
ooRef(ooIndexDescBase)::operator=(const ooRef(ooIndexDescBase) &  id)
{
  this->ooId::operator=(id);
  return *this;
}
inline
ooRef(ooIndexDescBase)&
ooRef(ooIndexDescBase)::operator=(const ooShortRefSuper(ooIndexDescBase) &  shortId)
{
  this->ooRef(ooObj)::operator=(shortId);
  return *this;
}
inline
ooRef(ooIndexDescBase)&
ooRef(ooIndexDescBase)::operator=(const ooHandleSuper(ooIndexDescBase) &  objH)
{
  this->ooRef(ooObj)::operator=(objH);
  return *this;
}
inline
ooRef(ooIndexDescBase)&
ooRef(ooIndexDescBase)::operator=(const ooIndexDescBase *  fromObject)
{
  this->ooRef(ooObj)::operator=(ooReinterpretCast(const ooObj *, fromObject));
  return *this;
}
inline
ooIndexDescBase *
ooRef(ooIndexDescBase)::pin(ooMode  openMode) const
{
  return ooReinterpretCast(ooIndexDescBase *, this->pin_ref_internal(openMode));
}
inline
ooIndexDescBase *
ooRef(ooIndexDescBase)::vm(ooMode  openMode) const
{
  return this->pin(openMode);
}
#ifndef OO_BUGGY_TEMPLATES
inline
ooHandle(ooIndexDescBase) &
ooRef(ooIndexDescBase)::copy(const ooHandle(ooObj) &  nearH,
		ooHandle(ooIndexDescBase) &           result) const
{
  this->ooRef(ooObj)::copy(nearH, result);
  return result;
}
inline
ooRef(ooIndexDescBase) &
ooRef(ooIndexDescBase)::copy(const ooHandle(ooObj) &  nearH,
		ooRef(ooIndexDescBase) &              newObjRef) const
{
  this->ooRef(ooObj)::copy(nearH, newObjRef);
  return newObjRef;
}
inline
ooHandle(ooIndexDescBase)
ooRef(ooIndexDescBase)::copy(const ooHandle(ooObj) &  nearH) const
{
  ooHandle(ooIndexDescBase) result;
  this->ooRef(ooObj)::copy(nearH, result);
  return result;
}
#endif // !defined(OO_BUGGY_TEMPLATES)
inline
ooDeref(ooIndexDescBase)
ooRef(ooIndexDescBase)::operator->() const
{
  ooDeref(ooIndexDescBase) result(this->pin_ref_internal(oocRead));
  return result;
}


/* methods on ooShortRef(ooIndexDescBase) */
inline
ooShortRef(ooIndexDescBase) &
ooShortRef(ooIndexDescBase)::operator=(const ooShortRef(ooIndexDescBase) &  shortId)
{
  this->ooShortId::operator=(shortId);
  return *this;
}
inline
ooShortRef(ooIndexDescBase) &
ooShortRef(ooIndexDescBase)::operator=(const ooRef(ooIndexDescBase) &  id)
{
  this->ooShortId::operator=(id);
  return *this;
}
inline
ooShortRef(ooIndexDescBase) &
ooShortRef(ooIndexDescBase)::operator=(const ooHandleSuper(ooIndexDescBase) &  objH)
{
  this->ooShortId::operator=(objH);
  return *this;
}
inline
ooShortRef(ooIndexDescBase)&
ooShortRef(ooIndexDescBase)::operator=(const ooIndexDescBase *  fromObject)
{
  this->ooShortId::operator=(ooReinterpretCast(const ooObj *,fromObject));
  return *this;
}
inline
ooShortRef(ooIndexDescBase)::ooShortRefStructor(ooIndexDescBase)()
{
}
#ifdef OO_BUGGY_TEMPLATES
inline
ooShortRef(ooIndexDescBase)::ooShortRefStructor(ooIndexDescBase)(const ooShortRef(ooIndexDescBase) &  shortId)
{
  *this = shortId;
}
#else // !defined(OO_BUGGY_TEMPLATES)
inline
ooShortRef(ooIndexDescBase)::ooShortRefStructor(ooIndexDescBase)(const ooShortRef(ooIndexDescBase) &  shortId) :
    ooShortRef(ooObj)(shortId)
{
}
#endif // !defined(OO_BUGGY_TEMPLATES)
#ifdef OO_BUGGY_TEMPLATES
inline
ooShortRef(ooIndexDescBase)::ooShortRefStructor(ooIndexDescBase)(const ooRef(ooIndexDescBase) &  id)
{
  *this = id;
}
#else // !defined(OO_BUGGY_TEMPLATES)
inline
ooShortRef(ooIndexDescBase)::ooShortRefStructor(ooIndexDescBase)(const ooRef(ooIndexDescBase) &  id) :
    ooShortRef(ooObj)(id)
{
}
#endif // !defined(OO_BUGGY_TEMPLATES)
#ifdef OO_BUGGY_TEMPLATES
inline
ooShortRef(ooIndexDescBase)::ooShortRefStructor(ooIndexDescBase)(const ooHandleSuper(ooIndexDescBase) &  objH)
{
  *this = objH;
}
#else // !defined(OO_BUGGY_TEMPLATES)
inline
ooShortRef(ooIndexDescBase)::ooShortRefStructor(ooIndexDescBase)(const ooHandleSuper(ooIndexDescBase) &  objH) :
    ooShortRef(ooObj)(objH)
{
}
#endif // !defined(OO_BUGGY_TEMPLATES)
#ifdef OO_BUGGY_TEMPLATES
inline
ooShortRef(ooIndexDescBase)::ooShortRefStructor(ooIndexDescBase)(const ooIndexDescBase *  fromObject)
{
  *this = fromObject;
}
#else // !defined(OO_BUGGY_TEMPLATES)
inline
ooShortRef(ooIndexDescBase)::ooShortRefStructor(ooIndexDescBase)(const ooIndexDescBase *  fromObject) :
    ooShortRef(ooObj)(ooReinterpretCast(const ooObj *,fromObject))
{
}
#endif // !defined(OO_BUGGY_TEMPLATES)


/* methods on ooHandle(ooIndexDescBase) */
inline
ooHandle(ooIndexDescBase)::ooHandleStructor(ooIndexDescBase)()
{
}
inline
ooHandle(ooIndexDescBase)::ooHandleStructor(ooIndexDescBase)(const ooHandle(ooIndexDescBase) &  objH) :
#ifdef OO_BUGGY_TEMPLATES
    ooHandle_superclass<ooIndexDescBase >(objH)
#else // !defined(OO_BUGGY_TEMPLATES)
    ooHandle(ooObj)(objH)
#endif // !defined(OO_BUGGY_TEMPLATES)
{
}
inline
ooHandle(ooIndexDescBase)::ooHandleStructor(ooIndexDescBase)(const ooRef(ooIndexDescBase) &  id) :
#ifdef OO_BUGGY_TEMPLATES
    ooHandle_superclass<ooIndexDescBase >(id)
#else // !defined(OO_BUGGY_TEMPLATES)
    ooHandle(ooObj)(id)
#endif // !defined(OO_BUGGY_TEMPLATES)
{
}
inline
ooHandle(ooIndexDescBase)::ooHandleStructor(ooIndexDescBase)(const ooIndexDescBase *  fromObject) :
#ifdef OO_BUGGY_TEMPLATES
    ooHandle_superclass<ooIndexDescBase >(ooReinterpretCast(const ooObj *,fromObject))
#else // !defined(OO_BUGGY_TEMPLATES)
    ooHandle(ooObj)(ooReinterpretCast(const ooObj *,fromObject))
#endif // !defined(OO_BUGGY_TEMPLATES)
{
}
inline
ooHandle(ooIndexDescBase)&
ooHandle(ooIndexDescBase)::operator=(const ooRef(ooIndexDescBase) &  id)
{
  this->ooHandle(ooObj)::operator=(id);
  return *this;
}
inline
ooHandle(ooIndexDescBase)&
ooHandle(ooIndexDescBase)::operator=(const ooHandle(ooIndexDescBase) &  objH)
{
  this->ooHandle(ooObj)::operator=(objH);
  return *this;
}
inline
ooHandle(ooIndexDescBase)&
ooHandle(ooIndexDescBase)::operator=(const ooShortRef(ooIndexDescBase) &  shortId)
{
  this->ooHandle(ooObj)::operator=(shortId);
  return *this;
}
inline
ooHandle(ooIndexDescBase)&
ooHandle(ooIndexDescBase)::operator=(const ooIndexDescBase *  fromObject)
{
  this->ooHandle(ooObj)::operator=(ooReinterpretCast(const ooObj *,fromObject));
  return *this;
}
inline
ooIndexDescBase *
ooHandle(ooIndexDescBase)::pin(ooMode  openMode) const
{
  return ooReinterpretCast(ooIndexDescBase *, this->pin_obj_internal(openMode));
}
inline
ooIndexDescBase *
ooHandle(ooIndexDescBase)::operator->() const
{
  return this->vm();
}
inline
ooIndexDescBase &
ooHandle(ooIndexDescBase)::operator*() const
{
  return *(this->vm());
}
inline
ooHandle(ooIndexDescBase)::operator ooIndexDescBase *() const
{
  if ( _state == oocHandlePTR  )
    return ooReinterpretCast(ooIndexDescBase *, _ptr._obj);
  else return ooReinterpretCast(ooIndexDescBase *, this->get_vm());
}
inline
ooIndexDescBase *
ooHandle(ooIndexDescBase)::vm() const
{
  if ( _state == oocHandlePTR && _ptr._obj != NULL )
    return ooReinterpretCast(ooIndexDescBase *, _ptr._obj);
  else return ooReinterpretCast(ooIndexDescBase *, this->get_vm());
}
inline
ooRef(ooIndexDescBase) &
ooHandle(ooIndexDescBase)::copy(const ooHandle(ooObj) &  nearH,
		   ooRef(ooIndexDescBase) &              result) const
{
  this->ooHandle(ooObj)::copy(nearH, result);
  return result;
}


/* ODMG methods */
inline
ooIndexDescBase *
ooRef(ooIndexDescBase)::ptr() const
{
  return this->pin();
}
inline
ooIndexDescBase *
ooHandle(ooIndexDescBase)::ptr() const
{
  return this->operator ooIndexDescBase *();
}
class ooKeyDesc;


/////////////////////////////////////////////////////////////////////////////

ooTemplateSpecialization
class ooDeref(ooKeyDesc) : public ooDerefBase {
	friend class ooRef(ooKeyDesc);
  public:
    ~ooDerefStructor(ooKeyDesc)();
    inline ooKeyDesc *operator->() const;
#ifndef OO_BUGGY_TEMPLATES
  private:
#endif // !defined(OO_BUGGY_TEMPLATES)
    ooDerefStructor(ooKeyDesc)(ooDeref(ooKeyDesc)& deref);
    ooDerefStructor(ooKeyDesc)(ooObj *  fromObject);
};


#ifdef OO_BUGGY_TEMPLATES

class ooHandle_superclass<ooKeyDesc > : public ooHandle(ooIndexDescBase) {
 protected:
  ooHandle_superclass()
    {}
  ooHandle_superclass(const ooHandle(ooIndexDescBase) &  from) :
      ooHandle(ooIndexDescBase)(from)
    {}
  ooHandle_superclass(const ooRef(ooIndexDescBase) &  from) :
      ooHandle(ooIndexDescBase)(from)
    {}
  ooHandle_superclass(const ooIndexDescBase *  from) :
      ooHandle(ooIndexDescBase)(from)
    {}
  ~ooHandle_superclass()
    {}
};

class ooShortRef_superclass<ooKeyDesc > : public ooShortRef(ooIndexDescBase) {
};

#endif // OO_BUGGY_TEMPLATES

ooTemplateSpecialization
class ooRef(ooKeyDesc) : public ooRef(ooIndexDescBase) {
  public:
    ooRefStructor(ooKeyDesc)()
      {}
    ooRefStructor(ooKeyDesc)(const ooRef(ooKeyDesc)& id) :
	  ooRef(ooIndexDescBase)(id)
      {}
    inline ooRefStructor(ooKeyDesc)(const ooHandleSuper(ooKeyDesc)& objH);
    inline ooRefStructor(ooKeyDesc)(const ooKeyDesc *  fromObject);
    inline ooRef(ooKeyDesc)& operator=(const ooRef(ooKeyDesc)& id);
    inline ooRef(ooKeyDesc)& operator=(const ooShortRefSuper(ooKeyDesc) &shortId);
    inline ooRef(ooKeyDesc)& operator=(const ooHandleSuper(ooKeyDesc)& objH);
    inline ooRef(ooKeyDesc)& operator=(const ooKeyDesc *  fromObject);
    ooStatus lookupObj(const ooHandle(ooObj)& scopeH,
		       const ooKey& key,
		       ooMode openMode = oocRead);
    ooStatus lookupObj(const ooHandle(ooObj)& scopeH,
		       const char* name,
		       ooMode openMode = oocRead);
#ifndef OO_BUGGY_TEMPLATES
    inline ooRef(ooKeyDesc)& copy(const ooHandle(ooObj)& nearH,
		    ooRef(ooKeyDesc)& newObjRef) const;
    inline ooHandle(ooKeyDesc)& copy(const ooHandle(ooObj)& nearH,
			ooHandle(ooKeyDesc)& result) const;
    inline ooHandle(ooKeyDesc) copy(const ooHandle(ooObj)& nearH) const;
#endif // !defined(OO_BUGGY_TEMPLATES)
    inline ooKeyDesc *pin(ooMode openMode = oocRead) const;
    ooDeref(ooKeyDesc) operator->() const;
    /* Use pin() or use ooHandle "operator ooKeyDesc *" instead of vm. */
    /* OBSOLETE */ inline ooKeyDesc *vm(ooMode openMode = oocRead) const;
    // ODMG methods:
    ooRefStructor(ooKeyDesc)(const d_Ref_Any &from);
    ooKeyDesc *ptr() const;
};

ooTemplateSpecialization
class ooShortRef(ooKeyDesc) :
#ifdef OO_BUGGY_TEMPLATES
			public ooShortRef_superclass<ooKeyDesc >
#else // !defined(OO_BUGGY_TEMPLATES)
			public ooShortRef(ooIndexDescBase)
#endif // !defined(OO_BUGGY_TEMPLATES)
					            {
  public:
    ooShortRefStructor(ooKeyDesc)();
    ooShortRefStructor(ooKeyDesc)(const ooShortRef(ooKeyDesc)& shortId);
    ooShortRefStructor(ooKeyDesc)(const ooRef(ooKeyDesc)& id);
    ooShortRefStructor(ooKeyDesc)(const ooHandleSuper(ooKeyDesc) &objH);
    ooShortRefStructor(ooKeyDesc)(const ooKeyDesc *  fromObject);
    ooShortRef(ooKeyDesc)& operator=(const ooShortRef(ooKeyDesc)& shortId);
    ooShortRef(ooKeyDesc)& operator=(const ooRef(ooKeyDesc)& id);
    ooShortRef(ooKeyDesc)& operator=(const ooHandleSuper(ooKeyDesc) &objH);
    ooShortRef(ooKeyDesc)& operator=(const ooKeyDesc *  fromObject);
};

ooTemplateSpecialization
class ooHandle(ooKeyDesc) :
#ifdef OO_BUGGY_TEMPLATES
		      public ooHandle_superclass<ooKeyDesc >
#else // !defined(OO_BUGGY_TEMPLATES)
		      public ooHandle(ooIndexDescBase)
#endif // !defined(OO_BUGGY_TEMPLATES)
                                                {
  public:
    inline ooHandleStructor(ooKeyDesc)();
    inline ooHandleStructor(ooKeyDesc)(const ooRef(ooKeyDesc)& id);
    inline ooHandleStructor(ooKeyDesc)(const ooHandle(ooKeyDesc)& objH);
    inline ooHandleStructor(ooKeyDesc)(const ooKeyDesc *  fromObject);
    inline ooHandle(ooKeyDesc)& operator=(const ooRef(ooKeyDesc)& id);
    inline ooHandle(ooKeyDesc)& operator=(const ooHandle(ooKeyDesc)& objH);
    inline ooHandle(ooKeyDesc)& operator=(const ooShortRef(ooKeyDesc)& shortId);
    inline ooHandle(ooKeyDesc)& operator=(const ooKeyDesc *  fromObject);
    ooStatus lookupObj(const ooHandle(ooObj)& scopeH,
		       const ooKey& key,
		       ooMode openMode = oocRead);
    ooStatus lookupObj(const ooHandle(ooObj)& scopeH,
		       const char* name,
		       ooMode openMode = oocRead);
    ooHandle(ooKeyDesc)& copy(const ooHandle(ooObj)& nearH,
		       ooHandle(ooKeyDesc)& result) const;
    inline ooRef(ooKeyDesc)& copy(const ooHandle(ooObj)& nearH,
		    ooRef(ooKeyDesc)& result) const;
    ooHandle(ooKeyDesc) copy(const ooHandle(ooObj)& nearH) const;
    inline ooKeyDesc *pin(ooMode openMode = oocRead) const;
    inline ooKeyDesc *operator->() const;
    inline ooKeyDesc &operator*() const;
    inline operator ooKeyDesc *() const;
    /* Use "operator ooKeyDesc *" instead of vm. */
    /* OBSOLETE */ inline ooKeyDesc *vm() const;
    // ODMG methods:
    ooHandleStructor(ooKeyDesc)(const d_Ref_Any &from);
    ooKeyDesc *ptr() const;
};

ooTemplateSpecialization
class ooItr(ooKeyDesc) : public ooHandle(ooKeyDesc),
		    public ooIteratorObjOrContObj {
  public:
    ooItrStructor(ooKeyDesc)();
    ~ooItrStructor(ooKeyDesc)();
  private:
    // Defined only to prevent implicit definition:
    ooItrStructor(ooKeyDesc)(ooItr(ooKeyDesc)&);
    ooItr(ooKeyDesc)    operator=(ooItr(ooKeyDesc)&);
};


/* methods on ooDeref(ooKeyDesc) */
inline
ooDeref(ooKeyDesc)::ooDerefStructor(ooKeyDesc)(ooDeref(ooKeyDesc) &  deref) :
    ooDerefBase(deref.vm())
{
  this->pinCompensate();
}
inline
ooDeref(ooKeyDesc)::ooDerefStructor(ooKeyDesc)(ooObj *  fromObject) :
    ooDerefBase(fromObject)
{
}
inline
ooDeref(ooKeyDesc)::~ooDerefStructor(ooKeyDesc)()
{
}
inline
ooKeyDesc *
ooDeref(ooKeyDesc)::operator->() const
{
  return ooReinterpretCast(ooKeyDesc *, this->vm());
}


/* methods on ooRef(ooKeyDesc) */
inline
ooRef(ooKeyDesc)::ooRefStructor(ooKeyDesc)(const ooHandleSuper(ooKeyDesc)& objH) :
    ooRef(ooIndexDescBase)(objH)
{
}
inline
ooRef(ooKeyDesc)::ooRefStructor(ooKeyDesc)(const ooKeyDesc *  fromObject) :
    ooRef(ooIndexDescBase)(ooReinterpretCast(const ooIndexDescBase *, fromObject))
{
}
inline
ooRef(ooKeyDesc)&
ooRef(ooKeyDesc)::operator=(const ooRef(ooKeyDesc) &  id)
{
  this->ooId::operator=(id);
  return *this;
}
inline
ooRef(ooKeyDesc)&
ooRef(ooKeyDesc)::operator=(const ooShortRefSuper(ooKeyDesc) &  shortId)
{
  this->ooRef(ooObj)::operator=(shortId);
  return *this;
}
inline
ooRef(ooKeyDesc)&
ooRef(ooKeyDesc)::operator=(const ooHandleSuper(ooKeyDesc) &  objH)
{
  this->ooRef(ooObj)::operator=(objH);
  return *this;
}
inline
ooRef(ooKeyDesc)&
ooRef(ooKeyDesc)::operator=(const ooKeyDesc *  fromObject)
{
  this->ooRef(ooObj)::operator=(ooReinterpretCast(const ooObj *, fromObject));
  return *this;
}
inline
ooKeyDesc *
ooRef(ooKeyDesc)::pin(ooMode  openMode) const
{
  return ooReinterpretCast(ooKeyDesc *, this->pin_ref_internal(openMode));
}
inline
ooKeyDesc *
ooRef(ooKeyDesc)::vm(ooMode  openMode) const
{
  return this->pin(openMode);
}
#ifndef OO_BUGGY_TEMPLATES
inline
ooHandle(ooKeyDesc) &
ooRef(ooKeyDesc)::copy(const ooHandle(ooObj) &  nearH,
		ooHandle(ooKeyDesc) &           result) const
{
  this->ooRef(ooObj)::copy(nearH, result);
  return result;
}
inline
ooRef(ooKeyDesc) &
ooRef(ooKeyDesc)::copy(const ooHandle(ooObj) &  nearH,
		ooRef(ooKeyDesc) &              newObjRef) const
{
  this->ooRef(ooObj)::copy(nearH, newObjRef);
  return newObjRef;
}
inline
ooHandle(ooKeyDesc)
ooRef(ooKeyDesc)::copy(const ooHandle(ooObj) &  nearH) const
{
  ooHandle(ooKeyDesc) result;
  this->ooRef(ooObj)::copy(nearH, result);
  return result;
}
#endif // !defined(OO_BUGGY_TEMPLATES)
inline
ooDeref(ooKeyDesc)
ooRef(ooKeyDesc)::operator->() const
{
  ooDeref(ooKeyDesc) result(this->pin_ref_internal(oocRead));
  return result;
}


/* methods on ooShortRef(ooKeyDesc) */
inline
ooShortRef(ooKeyDesc) &
ooShortRef(ooKeyDesc)::operator=(const ooShortRef(ooKeyDesc) &  shortId)
{
  this->ooShortId::operator=(shortId);
  return *this;
}
inline
ooShortRef(ooKeyDesc) &
ooShortRef(ooKeyDesc)::operator=(const ooRef(ooKeyDesc) &  id)
{
  this->ooShortId::operator=(id);
  return *this;
}
inline
ooShortRef(ooKeyDesc) &
ooShortRef(ooKeyDesc)::operator=(const ooHandleSuper(ooKeyDesc) &  objH)
{
  this->ooShortId::operator=(objH);
  return *this;
}
inline
ooShortRef(ooKeyDesc)&
ooShortRef(ooKeyDesc)::operator=(const ooKeyDesc *  fromObject)
{
  this->ooShortId::operator=(ooReinterpretCast(const ooObj *,fromObject));
  return *this;
}
inline
ooShortRef(ooKeyDesc)::ooShortRefStructor(ooKeyDesc)()
{
}
#ifdef OO_BUGGY_TEMPLATES
inline
ooShortRef(ooKeyDesc)::ooShortRefStructor(ooKeyDesc)(const ooShortRef(ooKeyDesc) &  shortId)
{
  *this = shortId;
}
#else // !defined(OO_BUGGY_TEMPLATES)
inline
ooShortRef(ooKeyDesc)::ooShortRefStructor(ooKeyDesc)(const ooShortRef(ooKeyDesc) &  shortId) :
    ooShortRef(ooIndexDescBase)(shortId)
{
}
#endif // !defined(OO_BUGGY_TEMPLATES)
#ifdef OO_BUGGY_TEMPLATES
inline
ooShortRef(ooKeyDesc)::ooShortRefStructor(ooKeyDesc)(const ooRef(ooKeyDesc) &  id)
{
  *this = id;
}
#else // !defined(OO_BUGGY_TEMPLATES)
inline
ooShortRef(ooKeyDesc)::ooShortRefStructor(ooKeyDesc)(const ooRef(ooKeyDesc) &  id) :
    ooShortRef(ooIndexDescBase)(id)
{
}
#endif // !defined(OO_BUGGY_TEMPLATES)
#ifdef OO_BUGGY_TEMPLATES
inline
ooShortRef(ooKeyDesc)::ooShortRefStructor(ooKeyDesc)(const ooHandleSuper(ooKeyDesc) &  objH)
{
  *this = objH;
}
#else // !defined(OO_BUGGY_TEMPLATES)
inline
ooShortRef(ooKeyDesc)::ooShortRefStructor(ooKeyDesc)(const ooHandleSuper(ooKeyDesc) &  objH) :
    ooShortRef(ooIndexDescBase)(objH)
{
}
#endif // !defined(OO_BUGGY_TEMPLATES)
#ifdef OO_BUGGY_TEMPLATES
inline
ooShortRef(ooKeyDesc)::ooShortRefStructor(ooKeyDesc)(const ooKeyDesc *  fromObject)
{
  *this = fromObject;
}
#else // !defined(OO_BUGGY_TEMPLATES)
inline
ooShortRef(ooKeyDesc)::ooShortRefStructor(ooKeyDesc)(const ooKeyDesc *  fromObject) :
    ooShortRef(ooIndexDescBase)(ooReinterpretCast(const ooIndexDescBase *,fromObject))
{
}
#endif // !defined(OO_BUGGY_TEMPLATES)


/* methods on ooHandle(ooKeyDesc) */
inline
ooHandle(ooKeyDesc)::ooHandleStructor(ooKeyDesc)()
{
}
inline
ooHandle(ooKeyDesc)::ooHandleStructor(ooKeyDesc)(const ooHandle(ooKeyDesc) &  objH) :
#ifdef OO_BUGGY_TEMPLATES
    ooHandle_superclass<ooKeyDesc >(objH)
#else // !defined(OO_BUGGY_TEMPLATES)
    ooHandle(ooIndexDescBase)(objH)
#endif // !defined(OO_BUGGY_TEMPLATES)
{
}
inline
ooHandle(ooKeyDesc)::ooHandleStructor(ooKeyDesc)(const ooRef(ooKeyDesc) &  id) :
#ifdef OO_BUGGY_TEMPLATES
    ooHandle_superclass<ooKeyDesc >(id)
#else // !defined(OO_BUGGY_TEMPLATES)
    ooHandle(ooIndexDescBase)(id)
#endif // !defined(OO_BUGGY_TEMPLATES)
{
}
inline
ooHandle(ooKeyDesc)::ooHandleStructor(ooKeyDesc)(const ooKeyDesc *  fromObject) :
#ifdef OO_BUGGY_TEMPLATES
    ooHandle_superclass<ooKeyDesc >(ooReinterpretCast(const ooIndexDescBase *,fromObject))
#else // !defined(OO_BUGGY_TEMPLATES)
    ooHandle(ooIndexDescBase)(ooReinterpretCast(const ooIndexDescBase *,fromObject))
#endif // !defined(OO_BUGGY_TEMPLATES)
{
}
inline
ooHandle(ooKeyDesc)&
ooHandle(ooKeyDesc)::operator=(const ooRef(ooKeyDesc) &  id)
{
  this->ooHandle(ooObj)::operator=(id);
  return *this;
}
inline
ooHandle(ooKeyDesc)&
ooHandle(ooKeyDesc)::operator=(const ooHandle(ooKeyDesc) &  objH)
{
  this->ooHandle(ooObj)::operator=(objH);
  return *this;
}
inline
ooHandle(ooKeyDesc)&
ooHandle(ooKeyDesc)::operator=(const ooShortRef(ooKeyDesc) &  shortId)
{
  this->ooHandle(ooObj)::operator=(shortId);
  return *this;
}
inline
ooHandle(ooKeyDesc)&
ooHandle(ooKeyDesc)::operator=(const ooKeyDesc *  fromObject)
{
  this->ooHandle(ooObj)::operator=(ooReinterpretCast(const ooObj *,fromObject));
  return *this;
}
inline
ooKeyDesc *
ooHandle(ooKeyDesc)::pin(ooMode  openMode) const
{
  return ooReinterpretCast(ooKeyDesc *, this->pin_obj_internal(openMode));
}
inline
ooKeyDesc *
ooHandle(ooKeyDesc)::operator->() const
{
  return this->vm();
}
inline
ooKeyDesc &
ooHandle(ooKeyDesc)::operator*() const
{
  return *(this->vm());
}
inline
ooHandle(ooKeyDesc)::operator ooKeyDesc *() const
{
  if ( _state == oocHandlePTR  )
    return ooReinterpretCast(ooKeyDesc *, _ptr._obj);
  else return ooReinterpretCast(ooKeyDesc *, this->get_vm());
}
inline
ooKeyDesc *
ooHandle(ooKeyDesc)::vm() const
{
  if ( _state == oocHandlePTR && _ptr._obj != NULL )
    return ooReinterpretCast(ooKeyDesc *, _ptr._obj);
  else return ooReinterpretCast(ooKeyDesc *, this->get_vm());
}
inline
ooRef(ooKeyDesc) &
ooHandle(ooKeyDesc)::copy(const ooHandle(ooObj) &  nearH,
		   ooRef(ooKeyDesc) &              result) const
{
  this->ooHandle(ooObj)::copy(nearH, result);
  return result;
}


/* ODMG methods */
inline
ooKeyDesc *
ooRef(ooKeyDesc)::ptr() const
{
  return this->pin();
}
inline
ooKeyDesc *
ooHandle(ooKeyDesc)::ptr() const
{
  return this->operator ooKeyDesc *();
}
#if defined(_MSC_VER) && !defined(OO_DDL_TRANSLATION)
#pragma pack(pop)
#endif

#endif /* OO_INDEX_REF_H_TMP */

