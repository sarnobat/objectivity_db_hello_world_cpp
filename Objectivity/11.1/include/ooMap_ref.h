/* C++ 'references' header file: Objectivity/DB DDL Version: 11.1 */
/**************************************************************************
  		  Copyright (c) 1992-2002 Objectivity, Inc.
 	  		  All Rights Reserved

 	THIS IS UNPUBLISHED PROPRIETARY SOURCE CODE OF OBJECTIVITY, INC.

 	The copyright notice above does not evidence any
 	actual or intended publication of such source code.

*****************************************************************************/


#ifndef OO_MAP_REF_H_TMP
#define OO_MAP_REF_H_TMP

#ifndef OO_H
#include <oo.h>
#endif
#include <ooSchema_ref.h>
#if defined(_MSC_VER) && !defined(OO_DDL_TRANSLATION)
#pragma pack(push,8)
#endif
class ooMapElem;


/////////////////////////////////////////////////////////////////////////////

ooTemplateSpecialization
class ooDeref(ooMapElem) : public ooDerefBase {
	friend class ooRef(ooMapElem);
  public:
    ~ooDerefStructor(ooMapElem)();
    inline ooMapElem *operator->() const;
#ifndef OO_BUGGY_TEMPLATES
  private:
#endif // !defined(OO_BUGGY_TEMPLATES)
    ooDerefStructor(ooMapElem)(ooDeref(ooMapElem)& deref);
    ooDerefStructor(ooMapElem)(ooObj *  fromObject);
};


#ifdef OO_BUGGY_TEMPLATES

class ooHandle_superclass<ooMapElem > : public ooHandle(ooObj) {
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

class ooShortRef_superclass<ooMapElem > : public ooShortRef(ooObj) {
};

#endif // OO_BUGGY_TEMPLATES

ooTemplateSpecialization
class ooRef(ooMapElem) : public ooRef(ooObj) {
  public:
    ooRefStructor(ooMapElem)()
      {}
    ooRefStructor(ooMapElem)(const ooRef(ooMapElem)& id) :
	  ooRef(ooObj)(id)
      {}
    inline ooRefStructor(ooMapElem)(const ooHandleSuper(ooMapElem)& objH);
    inline ooRefStructor(ooMapElem)(const ooMapElem *  fromObject);
    inline ooRef(ooMapElem)& operator=(const ooRef(ooMapElem)& id);
    inline ooRef(ooMapElem)& operator=(const ooShortRefSuper(ooMapElem) &shortId);
    inline ooRef(ooMapElem)& operator=(const ooHandleSuper(ooMapElem)& objH);
    inline ooRef(ooMapElem)& operator=(const ooMapElem *  fromObject);
    ooStatus lookupObj(const ooHandle(ooObj)& scopeH,
		       const ooKey& key,
		       ooMode openMode = oocRead);
    ooStatus lookupObj(const ooHandle(ooObj)& scopeH,
		       const char* name,
		       ooMode openMode = oocRead);
#ifndef OO_BUGGY_TEMPLATES
    inline ooRef(ooMapElem)& copy(const ooHandle(ooObj)& nearH,
		    ooRef(ooMapElem)& newObjRef) const;
    inline ooHandle(ooMapElem)& copy(const ooHandle(ooObj)& nearH,
			ooHandle(ooMapElem)& result) const;
    inline ooHandle(ooMapElem) copy(const ooHandle(ooObj)& nearH) const;
#endif // !defined(OO_BUGGY_TEMPLATES)
    inline ooMapElem *pin(ooMode openMode = oocRead) const;
    ooDeref(ooMapElem) operator->() const;
    /* Use pin() or use ooHandle "operator ooMapElem *" instead of vm. */
    /* OBSOLETE */ inline ooMapElem *vm(ooMode openMode = oocRead) const;
    // ODMG methods:
    ooRefStructor(ooMapElem)(const d_Ref_Any &from);
    ooMapElem *ptr() const;
};

ooTemplateSpecialization
class ooShortRef(ooMapElem) :
#ifdef OO_BUGGY_TEMPLATES
			public ooShortRef_superclass<ooMapElem >
#else // !defined(OO_BUGGY_TEMPLATES)
			public ooShortRef(ooObj)
#endif // !defined(OO_BUGGY_TEMPLATES)
					            {
  public:
    ooShortRefStructor(ooMapElem)();
    ooShortRefStructor(ooMapElem)(const ooShortRef(ooMapElem)& shortId);
    ooShortRefStructor(ooMapElem)(const ooRef(ooMapElem)& id);
    ooShortRefStructor(ooMapElem)(const ooHandleSuper(ooMapElem) &objH);
    ooShortRefStructor(ooMapElem)(const ooMapElem *  fromObject);
    ooShortRef(ooMapElem)& operator=(const ooShortRef(ooMapElem)& shortId);
    ooShortRef(ooMapElem)& operator=(const ooRef(ooMapElem)& id);
    ooShortRef(ooMapElem)& operator=(const ooHandleSuper(ooMapElem) &objH);
    ooShortRef(ooMapElem)& operator=(const ooMapElem *  fromObject);
};

ooTemplateSpecialization
class ooHandle(ooMapElem) :
#ifdef OO_BUGGY_TEMPLATES
		      public ooHandle_superclass<ooMapElem >
#else // !defined(OO_BUGGY_TEMPLATES)
		      public ooHandle(ooObj)
#endif // !defined(OO_BUGGY_TEMPLATES)
                                                {
  public:
    inline ooHandleStructor(ooMapElem)();
    inline ooHandleStructor(ooMapElem)(const ooRef(ooMapElem)& id);
    inline ooHandleStructor(ooMapElem)(const ooHandle(ooMapElem)& objH);
    inline ooHandleStructor(ooMapElem)(const ooMapElem *  fromObject);
    inline ooHandle(ooMapElem)& operator=(const ooRef(ooMapElem)& id);
    inline ooHandle(ooMapElem)& operator=(const ooHandle(ooMapElem)& objH);
    inline ooHandle(ooMapElem)& operator=(const ooShortRef(ooMapElem)& shortId);
    inline ooHandle(ooMapElem)& operator=(const ooMapElem *  fromObject);
    ooStatus lookupObj(const ooHandle(ooObj)& scopeH,
		       const ooKey& key,
		       ooMode openMode = oocRead);
    ooStatus lookupObj(const ooHandle(ooObj)& scopeH,
		       const char* name,
		       ooMode openMode = oocRead);
    ooHandle(ooMapElem)& copy(const ooHandle(ooObj)& nearH,
		       ooHandle(ooMapElem)& result) const;
    inline ooRef(ooMapElem)& copy(const ooHandle(ooObj)& nearH,
		    ooRef(ooMapElem)& result) const;
    ooHandle(ooMapElem) copy(const ooHandle(ooObj)& nearH) const;
    inline ooMapElem *pin(ooMode openMode = oocRead) const;
    inline ooMapElem *operator->() const;
    inline ooMapElem &operator*() const;
    inline operator ooMapElem *() const;
    /* Use "operator ooMapElem *" instead of vm. */
    /* OBSOLETE */ inline ooMapElem *vm() const;
    // ODMG methods:
    ooHandleStructor(ooMapElem)(const d_Ref_Any &from);
    ooMapElem *ptr() const;
};

ooTemplateSpecialization
class ooItr(ooMapElem) : public ooHandle(ooMapElem),
		    public ooIteratorObjOrContObj {
  public:
    ooItrStructor(ooMapElem)();
    ~ooItrStructor(ooMapElem)();
  private:
    // Defined only to prevent implicit definition:
    ooItrStructor(ooMapElem)(ooItr(ooMapElem)&);
    ooItr(ooMapElem)    operator=(ooItr(ooMapElem)&);
};


/* methods on ooDeref(ooMapElem) */
inline
ooDeref(ooMapElem)::ooDerefStructor(ooMapElem)(ooDeref(ooMapElem) &  deref) :
    ooDerefBase(deref.vm())
{
  this->pinCompensate();
}
inline
ooDeref(ooMapElem)::ooDerefStructor(ooMapElem)(ooObj *  fromObject) :
    ooDerefBase(fromObject)
{
}
inline
ooDeref(ooMapElem)::~ooDerefStructor(ooMapElem)()
{
}
inline
ooMapElem *
ooDeref(ooMapElem)::operator->() const
{
  return ooReinterpretCast(ooMapElem *, this->vm());
}


/* methods on ooRef(ooMapElem) */
inline
ooRef(ooMapElem)::ooRefStructor(ooMapElem)(const ooHandleSuper(ooMapElem)& objH) :
    ooRef(ooObj)(objH)
{
}
inline
ooRef(ooMapElem)::ooRefStructor(ooMapElem)(const ooMapElem *  fromObject) :
    ooRef(ooObj)(ooReinterpretCast(const ooObj *, fromObject))
{
}
inline
ooRef(ooMapElem)&
ooRef(ooMapElem)::operator=(const ooRef(ooMapElem) &  id)
{
  this->ooId::operator=(id);
  return *this;
}
inline
ooRef(ooMapElem)&
ooRef(ooMapElem)::operator=(const ooShortRefSuper(ooMapElem) &  shortId)
{
  this->ooRef(ooObj)::operator=(shortId);
  return *this;
}
inline
ooRef(ooMapElem)&
ooRef(ooMapElem)::operator=(const ooHandleSuper(ooMapElem) &  objH)
{
  this->ooRef(ooObj)::operator=(objH);
  return *this;
}
inline
ooRef(ooMapElem)&
ooRef(ooMapElem)::operator=(const ooMapElem *  fromObject)
{
  this->ooRef(ooObj)::operator=(ooReinterpretCast(const ooObj *, fromObject));
  return *this;
}
inline
ooMapElem *
ooRef(ooMapElem)::pin(ooMode  openMode) const
{
  return ooReinterpretCast(ooMapElem *, this->pin_ref_internal(openMode));
}
inline
ooMapElem *
ooRef(ooMapElem)::vm(ooMode  openMode) const
{
  return this->pin(openMode);
}
#ifndef OO_BUGGY_TEMPLATES
inline
ooHandle(ooMapElem) &
ooRef(ooMapElem)::copy(const ooHandle(ooObj) &  nearH,
		ooHandle(ooMapElem) &           result) const
{
  this->ooRef(ooObj)::copy(nearH, result);
  return result;
}
inline
ooRef(ooMapElem) &
ooRef(ooMapElem)::copy(const ooHandle(ooObj) &  nearH,
		ooRef(ooMapElem) &              newObjRef) const
{
  this->ooRef(ooObj)::copy(nearH, newObjRef);
  return newObjRef;
}
inline
ooHandle(ooMapElem)
ooRef(ooMapElem)::copy(const ooHandle(ooObj) &  nearH) const
{
  ooHandle(ooMapElem) result;
  this->ooRef(ooObj)::copy(nearH, result);
  return result;
}
#endif // !defined(OO_BUGGY_TEMPLATES)
inline
ooDeref(ooMapElem)
ooRef(ooMapElem)::operator->() const
{
  ooDeref(ooMapElem) result(this->pin_ref_internal(oocRead));
  return result;
}


/* methods on ooShortRef(ooMapElem) */
inline
ooShortRef(ooMapElem) &
ooShortRef(ooMapElem)::operator=(const ooShortRef(ooMapElem) &  shortId)
{
  this->ooShortId::operator=(shortId);
  return *this;
}
inline
ooShortRef(ooMapElem) &
ooShortRef(ooMapElem)::operator=(const ooRef(ooMapElem) &  id)
{
  this->ooShortId::operator=(id);
  return *this;
}
inline
ooShortRef(ooMapElem) &
ooShortRef(ooMapElem)::operator=(const ooHandleSuper(ooMapElem) &  objH)
{
  this->ooShortId::operator=(objH);
  return *this;
}
inline
ooShortRef(ooMapElem)&
ooShortRef(ooMapElem)::operator=(const ooMapElem *  fromObject)
{
  this->ooShortId::operator=(ooReinterpretCast(const ooObj *,fromObject));
  return *this;
}
inline
ooShortRef(ooMapElem)::ooShortRefStructor(ooMapElem)()
{
}
#ifdef OO_BUGGY_TEMPLATES
inline
ooShortRef(ooMapElem)::ooShortRefStructor(ooMapElem)(const ooShortRef(ooMapElem) &  shortId)
{
  *this = shortId;
}
#else // !defined(OO_BUGGY_TEMPLATES)
inline
ooShortRef(ooMapElem)::ooShortRefStructor(ooMapElem)(const ooShortRef(ooMapElem) &  shortId) :
    ooShortRef(ooObj)(shortId)
{
}
#endif // !defined(OO_BUGGY_TEMPLATES)
#ifdef OO_BUGGY_TEMPLATES
inline
ooShortRef(ooMapElem)::ooShortRefStructor(ooMapElem)(const ooRef(ooMapElem) &  id)
{
  *this = id;
}
#else // !defined(OO_BUGGY_TEMPLATES)
inline
ooShortRef(ooMapElem)::ooShortRefStructor(ooMapElem)(const ooRef(ooMapElem) &  id) :
    ooShortRef(ooObj)(id)
{
}
#endif // !defined(OO_BUGGY_TEMPLATES)
#ifdef OO_BUGGY_TEMPLATES
inline
ooShortRef(ooMapElem)::ooShortRefStructor(ooMapElem)(const ooHandleSuper(ooMapElem) &  objH)
{
  *this = objH;
}
#else // !defined(OO_BUGGY_TEMPLATES)
inline
ooShortRef(ooMapElem)::ooShortRefStructor(ooMapElem)(const ooHandleSuper(ooMapElem) &  objH) :
    ooShortRef(ooObj)(objH)
{
}
#endif // !defined(OO_BUGGY_TEMPLATES)
#ifdef OO_BUGGY_TEMPLATES
inline
ooShortRef(ooMapElem)::ooShortRefStructor(ooMapElem)(const ooMapElem *  fromObject)
{
  *this = fromObject;
}
#else // !defined(OO_BUGGY_TEMPLATES)
inline
ooShortRef(ooMapElem)::ooShortRefStructor(ooMapElem)(const ooMapElem *  fromObject) :
    ooShortRef(ooObj)(ooReinterpretCast(const ooObj *,fromObject))
{
}
#endif // !defined(OO_BUGGY_TEMPLATES)


/* methods on ooHandle(ooMapElem) */
inline
ooHandle(ooMapElem)::ooHandleStructor(ooMapElem)()
{
}
inline
ooHandle(ooMapElem)::ooHandleStructor(ooMapElem)(const ooHandle(ooMapElem) &  objH) :
#ifdef OO_BUGGY_TEMPLATES
    ooHandle_superclass<ooMapElem >(objH)
#else // !defined(OO_BUGGY_TEMPLATES)
    ooHandle(ooObj)(objH)
#endif // !defined(OO_BUGGY_TEMPLATES)
{
}
inline
ooHandle(ooMapElem)::ooHandleStructor(ooMapElem)(const ooRef(ooMapElem) &  id) :
#ifdef OO_BUGGY_TEMPLATES
    ooHandle_superclass<ooMapElem >(id)
#else // !defined(OO_BUGGY_TEMPLATES)
    ooHandle(ooObj)(id)
#endif // !defined(OO_BUGGY_TEMPLATES)
{
}
inline
ooHandle(ooMapElem)::ooHandleStructor(ooMapElem)(const ooMapElem *  fromObject) :
#ifdef OO_BUGGY_TEMPLATES
    ooHandle_superclass<ooMapElem >(ooReinterpretCast(const ooObj *,fromObject))
#else // !defined(OO_BUGGY_TEMPLATES)
    ooHandle(ooObj)(ooReinterpretCast(const ooObj *,fromObject))
#endif // !defined(OO_BUGGY_TEMPLATES)
{
}
inline
ooHandle(ooMapElem)&
ooHandle(ooMapElem)::operator=(const ooRef(ooMapElem) &  id)
{
  this->ooHandle(ooObj)::operator=(id);
  return *this;
}
inline
ooHandle(ooMapElem)&
ooHandle(ooMapElem)::operator=(const ooHandle(ooMapElem) &  objH)
{
  this->ooHandle(ooObj)::operator=(objH);
  return *this;
}
inline
ooHandle(ooMapElem)&
ooHandle(ooMapElem)::operator=(const ooShortRef(ooMapElem) &  shortId)
{
  this->ooHandle(ooObj)::operator=(shortId);
  return *this;
}
inline
ooHandle(ooMapElem)&
ooHandle(ooMapElem)::operator=(const ooMapElem *  fromObject)
{
  this->ooHandle(ooObj)::operator=(ooReinterpretCast(const ooObj *,fromObject));
  return *this;
}
inline
ooMapElem *
ooHandle(ooMapElem)::pin(ooMode  openMode) const
{
  return ooReinterpretCast(ooMapElem *, this->pin_obj_internal(openMode));
}
inline
ooMapElem *
ooHandle(ooMapElem)::operator->() const
{
  return this->vm();
}
inline
ooMapElem &
ooHandle(ooMapElem)::operator*() const
{
  return *(this->vm());
}
inline
ooHandle(ooMapElem)::operator ooMapElem *() const
{
  if ( _state == oocHandlePTR  )
    return ooReinterpretCast(ooMapElem *, _ptr._obj);
  else return ooReinterpretCast(ooMapElem *, this->get_vm());
}
inline
ooMapElem *
ooHandle(ooMapElem)::vm() const
{
  if ( _state == oocHandlePTR && _ptr._obj != NULL )
    return ooReinterpretCast(ooMapElem *, _ptr._obj);
  else return ooReinterpretCast(ooMapElem *, this->get_vm());
}
inline
ooRef(ooMapElem) &
ooHandle(ooMapElem)::copy(const ooHandle(ooObj) &  nearH,
		   ooRef(ooMapElem) &              result) const
{
  this->ooHandle(ooObj)::copy(nearH, result);
  return result;
}


/* ODMG methods */
inline
ooMapElem *
ooRef(ooMapElem)::ptr() const
{
  return this->pin();
}
inline
ooMapElem *
ooHandle(ooMapElem)::ptr() const
{
  return this->operator ooMapElem *();
}
class ooMap;


/////////////////////////////////////////////////////////////////////////////

ooTemplateSpecialization
class ooDeref(ooMap) : public ooDerefBase {
	friend class ooRef(ooMap);
  public:
    ~ooDerefStructor(ooMap)();
    inline ooMap *operator->() const;
#ifndef OO_BUGGY_TEMPLATES
  private:
#endif // !defined(OO_BUGGY_TEMPLATES)
    ooDerefStructor(ooMap)(ooDeref(ooMap)& deref);
    ooDerefStructor(ooMap)(ooObj *  fromObject);
};


#ifdef OO_BUGGY_TEMPLATES

class ooHandle_superclass<ooMap > : public ooHandle(ooObj) {
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

class ooShortRef_superclass<ooMap > : public ooShortRef(ooObj) {
};

#endif // OO_BUGGY_TEMPLATES

ooTemplateSpecialization
class ooRef(ooMap) : public ooRef(ooObj) {
  public:
    ooRefStructor(ooMap)()
      {}
    ooRefStructor(ooMap)(const ooRef(ooMap)& id) :
	  ooRef(ooObj)(id)
      {}
    inline ooRefStructor(ooMap)(const ooHandleSuper(ooMap)& objH);
    inline ooRefStructor(ooMap)(const ooMap *  fromObject);
    inline ooRef(ooMap)& operator=(const ooRef(ooMap)& id);
    inline ooRef(ooMap)& operator=(const ooShortRefSuper(ooMap) &shortId);
    inline ooRef(ooMap)& operator=(const ooHandleSuper(ooMap)& objH);
    inline ooRef(ooMap)& operator=(const ooMap *  fromObject);
    ooStatus lookupObj(const ooHandle(ooObj)& scopeH,
		       const ooKey& key,
		       ooMode openMode = oocRead);
    ooStatus lookupObj(const ooHandle(ooObj)& scopeH,
		       const char* name,
		       ooMode openMode = oocRead);
#ifndef OO_BUGGY_TEMPLATES
    inline ooRef(ooMap)& copy(const ooHandle(ooObj)& nearH,
		    ooRef(ooMap)& newObjRef) const;
    inline ooHandle(ooMap)& copy(const ooHandle(ooObj)& nearH,
			ooHandle(ooMap)& result) const;
    inline ooHandle(ooMap) copy(const ooHandle(ooObj)& nearH) const;
#endif // !defined(OO_BUGGY_TEMPLATES)
    inline ooMap *pin(ooMode openMode = oocRead) const;
    ooDeref(ooMap) operator->() const;
    /* Use pin() or use ooHandle "operator ooMap *" instead of vm. */
    /* OBSOLETE */ inline ooMap *vm(ooMode openMode = oocRead) const;
    // ODMG methods:
    ooRefStructor(ooMap)(const d_Ref_Any &from);
    ooMap *ptr() const;
};

ooTemplateSpecialization
class ooShortRef(ooMap) :
#ifdef OO_BUGGY_TEMPLATES
			public ooShortRef_superclass<ooMap >
#else // !defined(OO_BUGGY_TEMPLATES)
			public ooShortRef(ooObj)
#endif // !defined(OO_BUGGY_TEMPLATES)
					            {
  public:
    ooShortRefStructor(ooMap)();
    ooShortRefStructor(ooMap)(const ooShortRef(ooMap)& shortId);
    ooShortRefStructor(ooMap)(const ooRef(ooMap)& id);
    ooShortRefStructor(ooMap)(const ooHandleSuper(ooMap) &objH);
    ooShortRefStructor(ooMap)(const ooMap *  fromObject);
    ooShortRef(ooMap)& operator=(const ooShortRef(ooMap)& shortId);
    ooShortRef(ooMap)& operator=(const ooRef(ooMap)& id);
    ooShortRef(ooMap)& operator=(const ooHandleSuper(ooMap) &objH);
    ooShortRef(ooMap)& operator=(const ooMap *  fromObject);
};

ooTemplateSpecialization
class ooHandle(ooMap) :
#ifdef OO_BUGGY_TEMPLATES
		      public ooHandle_superclass<ooMap >
#else // !defined(OO_BUGGY_TEMPLATES)
		      public ooHandle(ooObj)
#endif // !defined(OO_BUGGY_TEMPLATES)
                                                {
  public:
    inline ooHandleStructor(ooMap)();
    inline ooHandleStructor(ooMap)(const ooRef(ooMap)& id);
    inline ooHandleStructor(ooMap)(const ooHandle(ooMap)& objH);
    inline ooHandleStructor(ooMap)(const ooMap *  fromObject);
    inline ooHandle(ooMap)& operator=(const ooRef(ooMap)& id);
    inline ooHandle(ooMap)& operator=(const ooHandle(ooMap)& objH);
    inline ooHandle(ooMap)& operator=(const ooShortRef(ooMap)& shortId);
    inline ooHandle(ooMap)& operator=(const ooMap *  fromObject);
    ooStatus lookupObj(const ooHandle(ooObj)& scopeH,
		       const ooKey& key,
		       ooMode openMode = oocRead);
    ooStatus lookupObj(const ooHandle(ooObj)& scopeH,
		       const char* name,
		       ooMode openMode = oocRead);
    ooHandle(ooMap)& copy(const ooHandle(ooObj)& nearH,
		       ooHandle(ooMap)& result) const;
    inline ooRef(ooMap)& copy(const ooHandle(ooObj)& nearH,
		    ooRef(ooMap)& result) const;
    ooHandle(ooMap) copy(const ooHandle(ooObj)& nearH) const;
    inline ooMap *pin(ooMode openMode = oocRead) const;
    inline ooMap *operator->() const;
    inline ooMap &operator*() const;
    inline operator ooMap *() const;
    /* Use "operator ooMap *" instead of vm. */
    /* OBSOLETE */ inline ooMap *vm() const;
    // ODMG methods:
    ooHandleStructor(ooMap)(const d_Ref_Any &from);
    ooMap *ptr() const;
};

ooTemplateSpecialization
class ooItr(ooMap) : public ooHandle(ooMap),
		    public ooIteratorObjOrContObj {
  public:
    ooItrStructor(ooMap)();
    ~ooItrStructor(ooMap)();
  private:
    // Defined only to prevent implicit definition:
    ooItrStructor(ooMap)(ooItr(ooMap)&);
    ooItr(ooMap)    operator=(ooItr(ooMap)&);
};


/* methods on ooDeref(ooMap) */
inline
ooDeref(ooMap)::ooDerefStructor(ooMap)(ooDeref(ooMap) &  deref) :
    ooDerefBase(deref.vm())
{
  this->pinCompensate();
}
inline
ooDeref(ooMap)::ooDerefStructor(ooMap)(ooObj *  fromObject) :
    ooDerefBase(fromObject)
{
}
inline
ooDeref(ooMap)::~ooDerefStructor(ooMap)()
{
}
inline
ooMap *
ooDeref(ooMap)::operator->() const
{
  return ooReinterpretCast(ooMap *, this->vm());
}


/* methods on ooRef(ooMap) */
inline
ooRef(ooMap)::ooRefStructor(ooMap)(const ooHandleSuper(ooMap)& objH) :
    ooRef(ooObj)(objH)
{
}
inline
ooRef(ooMap)::ooRefStructor(ooMap)(const ooMap *  fromObject) :
    ooRef(ooObj)(ooReinterpretCast(const ooObj *, fromObject))
{
}
inline
ooRef(ooMap)&
ooRef(ooMap)::operator=(const ooRef(ooMap) &  id)
{
  this->ooId::operator=(id);
  return *this;
}
inline
ooRef(ooMap)&
ooRef(ooMap)::operator=(const ooShortRefSuper(ooMap) &  shortId)
{
  this->ooRef(ooObj)::operator=(shortId);
  return *this;
}
inline
ooRef(ooMap)&
ooRef(ooMap)::operator=(const ooHandleSuper(ooMap) &  objH)
{
  this->ooRef(ooObj)::operator=(objH);
  return *this;
}
inline
ooRef(ooMap)&
ooRef(ooMap)::operator=(const ooMap *  fromObject)
{
  this->ooRef(ooObj)::operator=(ooReinterpretCast(const ooObj *, fromObject));
  return *this;
}
inline
ooMap *
ooRef(ooMap)::pin(ooMode  openMode) const
{
  return ooReinterpretCast(ooMap *, this->pin_ref_internal(openMode));
}
inline
ooMap *
ooRef(ooMap)::vm(ooMode  openMode) const
{
  return this->pin(openMode);
}
#ifndef OO_BUGGY_TEMPLATES
inline
ooHandle(ooMap) &
ooRef(ooMap)::copy(const ooHandle(ooObj) &  nearH,
		ooHandle(ooMap) &           result) const
{
  this->ooRef(ooObj)::copy(nearH, result);
  return result;
}
inline
ooRef(ooMap) &
ooRef(ooMap)::copy(const ooHandle(ooObj) &  nearH,
		ooRef(ooMap) &              newObjRef) const
{
  this->ooRef(ooObj)::copy(nearH, newObjRef);
  return newObjRef;
}
inline
ooHandle(ooMap)
ooRef(ooMap)::copy(const ooHandle(ooObj) &  nearH) const
{
  ooHandle(ooMap) result;
  this->ooRef(ooObj)::copy(nearH, result);
  return result;
}
#endif // !defined(OO_BUGGY_TEMPLATES)
inline
ooDeref(ooMap)
ooRef(ooMap)::operator->() const
{
  ooDeref(ooMap) result(this->pin_ref_internal(oocRead));
  return result;
}


/* methods on ooShortRef(ooMap) */
inline
ooShortRef(ooMap) &
ooShortRef(ooMap)::operator=(const ooShortRef(ooMap) &  shortId)
{
  this->ooShortId::operator=(shortId);
  return *this;
}
inline
ooShortRef(ooMap) &
ooShortRef(ooMap)::operator=(const ooRef(ooMap) &  id)
{
  this->ooShortId::operator=(id);
  return *this;
}
inline
ooShortRef(ooMap) &
ooShortRef(ooMap)::operator=(const ooHandleSuper(ooMap) &  objH)
{
  this->ooShortId::operator=(objH);
  return *this;
}
inline
ooShortRef(ooMap)&
ooShortRef(ooMap)::operator=(const ooMap *  fromObject)
{
  this->ooShortId::operator=(ooReinterpretCast(const ooObj *,fromObject));
  return *this;
}
inline
ooShortRef(ooMap)::ooShortRefStructor(ooMap)()
{
}
#ifdef OO_BUGGY_TEMPLATES
inline
ooShortRef(ooMap)::ooShortRefStructor(ooMap)(const ooShortRef(ooMap) &  shortId)
{
  *this = shortId;
}
#else // !defined(OO_BUGGY_TEMPLATES)
inline
ooShortRef(ooMap)::ooShortRefStructor(ooMap)(const ooShortRef(ooMap) &  shortId) :
    ooShortRef(ooObj)(shortId)
{
}
#endif // !defined(OO_BUGGY_TEMPLATES)
#ifdef OO_BUGGY_TEMPLATES
inline
ooShortRef(ooMap)::ooShortRefStructor(ooMap)(const ooRef(ooMap) &  id)
{
  *this = id;
}
#else // !defined(OO_BUGGY_TEMPLATES)
inline
ooShortRef(ooMap)::ooShortRefStructor(ooMap)(const ooRef(ooMap) &  id) :
    ooShortRef(ooObj)(id)
{
}
#endif // !defined(OO_BUGGY_TEMPLATES)
#ifdef OO_BUGGY_TEMPLATES
inline
ooShortRef(ooMap)::ooShortRefStructor(ooMap)(const ooHandleSuper(ooMap) &  objH)
{
  *this = objH;
}
#else // !defined(OO_BUGGY_TEMPLATES)
inline
ooShortRef(ooMap)::ooShortRefStructor(ooMap)(const ooHandleSuper(ooMap) &  objH) :
    ooShortRef(ooObj)(objH)
{
}
#endif // !defined(OO_BUGGY_TEMPLATES)
#ifdef OO_BUGGY_TEMPLATES
inline
ooShortRef(ooMap)::ooShortRefStructor(ooMap)(const ooMap *  fromObject)
{
  *this = fromObject;
}
#else // !defined(OO_BUGGY_TEMPLATES)
inline
ooShortRef(ooMap)::ooShortRefStructor(ooMap)(const ooMap *  fromObject) :
    ooShortRef(ooObj)(ooReinterpretCast(const ooObj *,fromObject))
{
}
#endif // !defined(OO_BUGGY_TEMPLATES)


/* methods on ooHandle(ooMap) */
inline
ooHandle(ooMap)::ooHandleStructor(ooMap)()
{
}
inline
ooHandle(ooMap)::ooHandleStructor(ooMap)(const ooHandle(ooMap) &  objH) :
#ifdef OO_BUGGY_TEMPLATES
    ooHandle_superclass<ooMap >(objH)
#else // !defined(OO_BUGGY_TEMPLATES)
    ooHandle(ooObj)(objH)
#endif // !defined(OO_BUGGY_TEMPLATES)
{
}
inline
ooHandle(ooMap)::ooHandleStructor(ooMap)(const ooRef(ooMap) &  id) :
#ifdef OO_BUGGY_TEMPLATES
    ooHandle_superclass<ooMap >(id)
#else // !defined(OO_BUGGY_TEMPLATES)
    ooHandle(ooObj)(id)
#endif // !defined(OO_BUGGY_TEMPLATES)
{
}
inline
ooHandle(ooMap)::ooHandleStructor(ooMap)(const ooMap *  fromObject) :
#ifdef OO_BUGGY_TEMPLATES
    ooHandle_superclass<ooMap >(ooReinterpretCast(const ooObj *,fromObject))
#else // !defined(OO_BUGGY_TEMPLATES)
    ooHandle(ooObj)(ooReinterpretCast(const ooObj *,fromObject))
#endif // !defined(OO_BUGGY_TEMPLATES)
{
}
inline
ooHandle(ooMap)&
ooHandle(ooMap)::operator=(const ooRef(ooMap) &  id)
{
  this->ooHandle(ooObj)::operator=(id);
  return *this;
}
inline
ooHandle(ooMap)&
ooHandle(ooMap)::operator=(const ooHandle(ooMap) &  objH)
{
  this->ooHandle(ooObj)::operator=(objH);
  return *this;
}
inline
ooHandle(ooMap)&
ooHandle(ooMap)::operator=(const ooShortRef(ooMap) &  shortId)
{
  this->ooHandle(ooObj)::operator=(shortId);
  return *this;
}
inline
ooHandle(ooMap)&
ooHandle(ooMap)::operator=(const ooMap *  fromObject)
{
  this->ooHandle(ooObj)::operator=(ooReinterpretCast(const ooObj *,fromObject));
  return *this;
}
inline
ooMap *
ooHandle(ooMap)::pin(ooMode  openMode) const
{
  return ooReinterpretCast(ooMap *, this->pin_obj_internal(openMode));
}
inline
ooMap *
ooHandle(ooMap)::operator->() const
{
  return this->vm();
}
inline
ooMap &
ooHandle(ooMap)::operator*() const
{
  return *(this->vm());
}
inline
ooHandle(ooMap)::operator ooMap *() const
{
  if ( _state == oocHandlePTR  )
    return ooReinterpretCast(ooMap *, _ptr._obj);
  else return ooReinterpretCast(ooMap *, this->get_vm());
}
inline
ooMap *
ooHandle(ooMap)::vm() const
{
  if ( _state == oocHandlePTR && _ptr._obj != NULL )
    return ooReinterpretCast(ooMap *, _ptr._obj);
  else return ooReinterpretCast(ooMap *, this->get_vm());
}
inline
ooRef(ooMap) &
ooHandle(ooMap)::copy(const ooHandle(ooObj) &  nearH,
		   ooRef(ooMap) &              result) const
{
  this->ooHandle(ooObj)::copy(nearH, result);
  return result;
}


/* ODMG methods */
inline
ooMap *
ooRef(ooMap)::ptr() const
{
  return this->pin();
}
inline
ooMap *
ooHandle(ooMap)::ptr() const
{
  return this->operator ooMap *();
}
#if defined(_MSC_VER) && !defined(OO_DDL_TRANSLATION)
#pragma pack(pop)
#endif

#endif /* OO_MAP_REF_H_TMP */

