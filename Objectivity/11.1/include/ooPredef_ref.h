/* C++ 'references' header file: Objectivity/DB DDL Version: 11.1 */
/**************************************************************************
  		  Copyright (c) 1992-2002 Objectivity, Inc.
 	  		  All Rights Reserved

 	THIS IS UNPUBLISHED PROPRIETARY SOURCE CODE OF OBJECTIVITY, INC.

 	The copyright notice above does not evidence any
 	actual or intended publication of such source code.

*****************************************************************************/


#ifndef OO_PREDEFINED_REF_H
#define OO_PREDEFINED_REF_H

#ifndef OO_H
#include <oo.h>
#endif
#include <ooSchema_ref.h>
#if defined(_MSC_VER) && !defined(OO_DDL_TRANSLATION)
#pragma pack(push,8)
#endif
class ooDefaultContObj;


/////////////////////////////////////////////////////////////////////////////

ooTemplateSpecialization
class ooDeref(ooDefaultContObj) : public ooDerefBase {
	friend class ooRef(ooDefaultContObj);
  public:
    ~ooDerefStructor(ooDefaultContObj)();
    inline ooDefaultContObj *operator->() const;
#ifndef OO_BUGGY_TEMPLATES
  private:
#endif // !defined(OO_BUGGY_TEMPLATES)
    ooDerefStructor(ooDefaultContObj)(ooDeref(ooDefaultContObj)& deref);
    ooDerefStructor(ooDefaultContObj)(ooObj *  fromObject);
};


#ifdef OO_BUGGY_TEMPLATES

class ooHandle_superclass<ooDefaultContObj > : public ooHandle(ooContObj) {
 protected:
  ooHandle_superclass()
    {}
  ooHandle_superclass(const ooHandle(ooContObj) &  from) :
      ooHandle(ooContObj)(from)
    {}
  ooHandle_superclass(const ooRef(ooContObj) &  from) :
      ooHandle(ooContObj)(from)
    {}
  ooHandle_superclass(const ooContObj *  from) :
      ooHandle(ooContObj)(from)
    {}
  ~ooHandle_superclass()
    {}
};

class ooShortRef_superclass<ooDefaultContObj > : public ooShortRef(ooContObj) {
};

#endif // OO_BUGGY_TEMPLATES

ooTemplateSpecialization
class ooRef(ooDefaultContObj) : public ooRef(ooContObj) {
  public:
    ooRefStructor(ooDefaultContObj)()
      {}
    ooRefStructor(ooDefaultContObj)(const ooRef(ooDefaultContObj)& id) :
	  ooRef(ooContObj)(id)
      {}
    inline ooRefStructor(ooDefaultContObj)(const ooHandleSuper(ooDefaultContObj)& objH);
    inline ooRefStructor(ooDefaultContObj)(const ooDefaultContObj *  fromObject);
    inline ooRef(ooDefaultContObj)& operator=(const ooRef(ooDefaultContObj)& id);
    inline ooRef(ooDefaultContObj)& operator=(const ooShortRefSuper(ooDefaultContObj) &shortId);
    inline ooRef(ooDefaultContObj)& operator=(const ooHandleSuper(ooDefaultContObj)& objH);
    inline ooRef(ooDefaultContObj)& operator=(const ooDefaultContObj *  fromObject);
    ooStatus lookupObj(const ooHandle(ooObj)& scopeH,
		       const ooKey& key,
		       ooMode openMode = oocRead);
    ooStatus lookupObj(const ooHandle(ooObj)& scopeH,
		       const char* name,
		       ooMode openMode = oocRead);
#ifndef OO_BUGGY_TEMPLATES
    inline ooRef(ooDefaultContObj)& copy(const ooHandle(ooObj)& nearH,
		    ooRef(ooDefaultContObj)& newObjRef) const;
    inline ooHandle(ooDefaultContObj)& copy(const ooHandle(ooObj)& nearH,
			ooHandle(ooDefaultContObj)& result) const;
    inline ooHandle(ooDefaultContObj) copy(const ooHandle(ooObj)& nearH) const;
#endif // !defined(OO_BUGGY_TEMPLATES)
    inline ooDefaultContObj *pin(ooMode openMode = oocRead) const;
    ooDeref(ooDefaultContObj) operator->() const;
    /* Use pin() or use ooHandle "operator ooDefaultContObj *" instead of vm. */
    /* OBSOLETE */ inline ooDefaultContObj *vm(ooMode openMode = oocRead) const;
    // ODMG methods:
    ooRefStructor(ooDefaultContObj)(const d_Ref_Any &from);
    ooDefaultContObj *ptr() const;
};

ooTemplateSpecialization
class ooShortRef(ooDefaultContObj) :
#ifdef OO_BUGGY_TEMPLATES
			public ooShortRef_superclass<ooDefaultContObj >
#else // !defined(OO_BUGGY_TEMPLATES)
			public ooShortRef(ooContObj)
#endif // !defined(OO_BUGGY_TEMPLATES)
					            {
  public:
    ooShortRefStructor(ooDefaultContObj)();
    ooShortRefStructor(ooDefaultContObj)(const ooShortRef(ooDefaultContObj)& shortId);
    ooShortRefStructor(ooDefaultContObj)(const ooRef(ooDefaultContObj)& id);
    ooShortRefStructor(ooDefaultContObj)(const ooHandleSuper(ooDefaultContObj) &objH);
    ooShortRefStructor(ooDefaultContObj)(const ooDefaultContObj *  fromObject);
    ooShortRef(ooDefaultContObj)& operator=(const ooShortRef(ooDefaultContObj)& shortId);
    ooShortRef(ooDefaultContObj)& operator=(const ooRef(ooDefaultContObj)& id);
    ooShortRef(ooDefaultContObj)& operator=(const ooHandleSuper(ooDefaultContObj) &objH);
    ooShortRef(ooDefaultContObj)& operator=(const ooDefaultContObj *  fromObject);
};

ooTemplateSpecialization
class ooHandle(ooDefaultContObj) :
#ifdef OO_BUGGY_TEMPLATES
		      public ooHandle_superclass<ooDefaultContObj >
#else // !defined(OO_BUGGY_TEMPLATES)
		      public ooHandle(ooContObj)
#endif // !defined(OO_BUGGY_TEMPLATES)
                                                {
  public:
    inline ooHandleStructor(ooDefaultContObj)();
    inline ooHandleStructor(ooDefaultContObj)(const ooRef(ooDefaultContObj)& id);
    inline ooHandleStructor(ooDefaultContObj)(const ooHandle(ooDefaultContObj)& objH);
    inline ooHandleStructor(ooDefaultContObj)(const ooDefaultContObj *  fromObject);
    inline ooHandle(ooDefaultContObj)& operator=(const ooRef(ooDefaultContObj)& id);
    inline ooHandle(ooDefaultContObj)& operator=(const ooHandle(ooDefaultContObj)& objH);
    inline ooHandle(ooDefaultContObj)& operator=(const ooShortRef(ooDefaultContObj)& shortId);
    inline ooHandle(ooDefaultContObj)& operator=(const ooDefaultContObj *  fromObject);
    ooStatus lookupObj(const ooHandle(ooObj)& scopeH,
		       const ooKey& key,
		       ooMode openMode = oocRead);
    ooStatus lookupObj(const ooHandle(ooObj)& scopeH,
		       const char* name,
		       ooMode openMode = oocRead);
    ooHandle(ooDefaultContObj)& copy(const ooHandle(ooObj)& nearH,
		       ooHandle(ooDefaultContObj)& result) const;
    inline ooRef(ooDefaultContObj)& copy(const ooHandle(ooObj)& nearH,
		    ooRef(ooDefaultContObj)& result) const;
    ooHandle(ooDefaultContObj) copy(const ooHandle(ooObj)& nearH) const;
    inline ooDefaultContObj *pin(ooMode openMode = oocRead) const;
    inline ooDefaultContObj *operator->() const;
    inline ooDefaultContObj &operator*() const;
    inline operator ooDefaultContObj *() const;
    /* Use "operator ooDefaultContObj *" instead of vm. */
    /* OBSOLETE */ inline ooDefaultContObj *vm() const;
    // ODMG methods:
    ooHandleStructor(ooDefaultContObj)(const d_Ref_Any &from);
    ooDefaultContObj *ptr() const;
};

ooTemplateSpecialization
class ooItr(ooDefaultContObj) : public ooHandle(ooDefaultContObj),
		    public ooIteratorObjOrContObj {
  public:
    ooItrStructor(ooDefaultContObj)();
    ~ooItrStructor(ooDefaultContObj)();
  private:
    // Defined only to prevent implicit definition:
    ooItrStructor(ooDefaultContObj)(ooItr(ooDefaultContObj)&);
    ooItr(ooDefaultContObj)    operator=(ooItr(ooDefaultContObj)&);
};


/* methods on ooDeref(ooDefaultContObj) */
inline
ooDeref(ooDefaultContObj)::ooDerefStructor(ooDefaultContObj)(ooDeref(ooDefaultContObj) &  deref) :
    ooDerefBase(deref.vm())
{
  this->pinCompensate();
}
inline
ooDeref(ooDefaultContObj)::ooDerefStructor(ooDefaultContObj)(ooObj *  fromObject) :
    ooDerefBase(fromObject)
{
}
inline
ooDeref(ooDefaultContObj)::~ooDerefStructor(ooDefaultContObj)()
{
}
inline
ooDefaultContObj *
ooDeref(ooDefaultContObj)::operator->() const
{
  return ooReinterpretCast(ooDefaultContObj *, this->vm());
}


/* methods on ooRef(ooDefaultContObj) */
inline
ooRef(ooDefaultContObj)::ooRefStructor(ooDefaultContObj)(const ooHandleSuper(ooDefaultContObj)& objH) :
    ooRef(ooContObj)(objH)
{
}
inline
ooRef(ooDefaultContObj)::ooRefStructor(ooDefaultContObj)(const ooDefaultContObj *  fromObject) :
    ooRef(ooContObj)(ooReinterpretCast(const ooContObj *, fromObject))
{
}
inline
ooRef(ooDefaultContObj)&
ooRef(ooDefaultContObj)::operator=(const ooRef(ooDefaultContObj) &  id)
{
  this->ooId::operator=(id);
  return *this;
}
inline
ooRef(ooDefaultContObj)&
ooRef(ooDefaultContObj)::operator=(const ooShortRefSuper(ooDefaultContObj) &  shortId)
{
  this->ooRef(ooObj)::operator=(shortId);
  return *this;
}
inline
ooRef(ooDefaultContObj)&
ooRef(ooDefaultContObj)::operator=(const ooHandleSuper(ooDefaultContObj) &  objH)
{
  this->ooRef(ooObj)::operator=(objH);
  return *this;
}
inline
ooRef(ooDefaultContObj)&
ooRef(ooDefaultContObj)::operator=(const ooDefaultContObj *  fromObject)
{
  this->ooRef(ooObj)::operator=(ooReinterpretCast(const ooObj *, fromObject));
  return *this;
}
inline
ooDefaultContObj *
ooRef(ooDefaultContObj)::pin(ooMode  openMode) const
{
  return ooReinterpretCast(ooDefaultContObj *, this->pin_ref_internal(openMode));
}
inline
ooDefaultContObj *
ooRef(ooDefaultContObj)::vm(ooMode  openMode) const
{
  return this->pin(openMode);
}
#ifndef OO_BUGGY_TEMPLATES
inline
ooHandle(ooDefaultContObj) &
ooRef(ooDefaultContObj)::copy(const ooHandle(ooObj) &  nearH,
		ooHandle(ooDefaultContObj) &           result) const
{
  this->ooRef(ooObj)::copy(nearH, result);
  return result;
}
inline
ooRef(ooDefaultContObj) &
ooRef(ooDefaultContObj)::copy(const ooHandle(ooObj) &  nearH,
		ooRef(ooDefaultContObj) &              newObjRef) const
{
  this->ooRef(ooObj)::copy(nearH, newObjRef);
  return newObjRef;
}
inline
ooHandle(ooDefaultContObj)
ooRef(ooDefaultContObj)::copy(const ooHandle(ooObj) &  nearH) const
{
  ooHandle(ooDefaultContObj) result;
  this->ooRef(ooObj)::copy(nearH, result);
  return result;
}
#endif // !defined(OO_BUGGY_TEMPLATES)
inline
ooDeref(ooDefaultContObj)
ooRef(ooDefaultContObj)::operator->() const
{
  ooDeref(ooDefaultContObj) result(this->pin_ref_internal(oocRead));
  return result;
}


/* methods on ooShortRef(ooDefaultContObj) */
inline
ooShortRef(ooDefaultContObj) &
ooShortRef(ooDefaultContObj)::operator=(const ooShortRef(ooDefaultContObj) &  shortId)
{
  this->ooShortId::operator=(shortId);
  return *this;
}
inline
ooShortRef(ooDefaultContObj) &
ooShortRef(ooDefaultContObj)::operator=(const ooRef(ooDefaultContObj) &  id)
{
  this->ooShortId::operator=(id);
  return *this;
}
inline
ooShortRef(ooDefaultContObj) &
ooShortRef(ooDefaultContObj)::operator=(const ooHandleSuper(ooDefaultContObj) &  objH)
{
  this->ooShortId::operator=(objH);
  return *this;
}
inline
ooShortRef(ooDefaultContObj)&
ooShortRef(ooDefaultContObj)::operator=(const ooDefaultContObj *  fromObject)
{
  this->ooShortId::operator=(ooReinterpretCast(const ooObj *,fromObject));
  return *this;
}
inline
ooShortRef(ooDefaultContObj)::ooShortRefStructor(ooDefaultContObj)()
{
}
#ifdef OO_BUGGY_TEMPLATES
inline
ooShortRef(ooDefaultContObj)::ooShortRefStructor(ooDefaultContObj)(const ooShortRef(ooDefaultContObj) &  shortId)
{
  *this = shortId;
}
#else // !defined(OO_BUGGY_TEMPLATES)
inline
ooShortRef(ooDefaultContObj)::ooShortRefStructor(ooDefaultContObj)(const ooShortRef(ooDefaultContObj) &  shortId) :
    ooShortRef(ooContObj)(shortId)
{
}
#endif // !defined(OO_BUGGY_TEMPLATES)
#ifdef OO_BUGGY_TEMPLATES
inline
ooShortRef(ooDefaultContObj)::ooShortRefStructor(ooDefaultContObj)(const ooRef(ooDefaultContObj) &  id)
{
  *this = id;
}
#else // !defined(OO_BUGGY_TEMPLATES)
inline
ooShortRef(ooDefaultContObj)::ooShortRefStructor(ooDefaultContObj)(const ooRef(ooDefaultContObj) &  id) :
    ooShortRef(ooContObj)(id)
{
}
#endif // !defined(OO_BUGGY_TEMPLATES)
#ifdef OO_BUGGY_TEMPLATES
inline
ooShortRef(ooDefaultContObj)::ooShortRefStructor(ooDefaultContObj)(const ooHandleSuper(ooDefaultContObj) &  objH)
{
  *this = objH;
}
#else // !defined(OO_BUGGY_TEMPLATES)
inline
ooShortRef(ooDefaultContObj)::ooShortRefStructor(ooDefaultContObj)(const ooHandleSuper(ooDefaultContObj) &  objH) :
    ooShortRef(ooContObj)(objH)
{
}
#endif // !defined(OO_BUGGY_TEMPLATES)
#ifdef OO_BUGGY_TEMPLATES
inline
ooShortRef(ooDefaultContObj)::ooShortRefStructor(ooDefaultContObj)(const ooDefaultContObj *  fromObject)
{
  *this = fromObject;
}
#else // !defined(OO_BUGGY_TEMPLATES)
inline
ooShortRef(ooDefaultContObj)::ooShortRefStructor(ooDefaultContObj)(const ooDefaultContObj *  fromObject) :
    ooShortRef(ooContObj)(ooReinterpretCast(const ooContObj *,fromObject))
{
}
#endif // !defined(OO_BUGGY_TEMPLATES)


/* methods on ooHandle(ooDefaultContObj) */
inline
ooHandle(ooDefaultContObj)::ooHandleStructor(ooDefaultContObj)()
{
}
inline
ooHandle(ooDefaultContObj)::ooHandleStructor(ooDefaultContObj)(const ooHandle(ooDefaultContObj) &  objH) :
#ifdef OO_BUGGY_TEMPLATES
    ooHandle_superclass<ooDefaultContObj >(objH)
#else // !defined(OO_BUGGY_TEMPLATES)
    ooHandle(ooContObj)(objH)
#endif // !defined(OO_BUGGY_TEMPLATES)
{
}
inline
ooHandle(ooDefaultContObj)::ooHandleStructor(ooDefaultContObj)(const ooRef(ooDefaultContObj) &  id) :
#ifdef OO_BUGGY_TEMPLATES
    ooHandle_superclass<ooDefaultContObj >(id)
#else // !defined(OO_BUGGY_TEMPLATES)
    ooHandle(ooContObj)(id)
#endif // !defined(OO_BUGGY_TEMPLATES)
{
}
inline
ooHandle(ooDefaultContObj)::ooHandleStructor(ooDefaultContObj)(const ooDefaultContObj *  fromObject) :
#ifdef OO_BUGGY_TEMPLATES
    ooHandle_superclass<ooDefaultContObj >(ooReinterpretCast(const ooContObj *,fromObject))
#else // !defined(OO_BUGGY_TEMPLATES)
    ooHandle(ooContObj)(ooReinterpretCast(const ooContObj *,fromObject))
#endif // !defined(OO_BUGGY_TEMPLATES)
{
}
inline
ooHandle(ooDefaultContObj)&
ooHandle(ooDefaultContObj)::operator=(const ooRef(ooDefaultContObj) &  id)
{
  this->ooHandle(ooObj)::operator=(id);
  return *this;
}
inline
ooHandle(ooDefaultContObj)&
ooHandle(ooDefaultContObj)::operator=(const ooHandle(ooDefaultContObj) &  objH)
{
  this->ooHandle(ooObj)::operator=(objH);
  return *this;
}
inline
ooHandle(ooDefaultContObj)&
ooHandle(ooDefaultContObj)::operator=(const ooShortRef(ooDefaultContObj) &  shortId)
{
  this->ooHandle(ooObj)::operator=(shortId);
  return *this;
}
inline
ooHandle(ooDefaultContObj)&
ooHandle(ooDefaultContObj)::operator=(const ooDefaultContObj *  fromObject)
{
  this->ooHandle(ooObj)::operator=(ooReinterpretCast(const ooObj *,fromObject));
  return *this;
}
inline
ooDefaultContObj *
ooHandle(ooDefaultContObj)::pin(ooMode  openMode) const
{
  return ooReinterpretCast(ooDefaultContObj *, this->pin_obj_internal(openMode));
}
inline
ooDefaultContObj *
ooHandle(ooDefaultContObj)::operator->() const
{
  return this->vm();
}
inline
ooDefaultContObj &
ooHandle(ooDefaultContObj)::operator*() const
{
  return *(this->vm());
}
inline
ooHandle(ooDefaultContObj)::operator ooDefaultContObj *() const
{
  if ( _state == oocHandlePTR  )
    return ooReinterpretCast(ooDefaultContObj *, _ptr._obj);
  else return ooReinterpretCast(ooDefaultContObj *, this->get_vm());
}
inline
ooDefaultContObj *
ooHandle(ooDefaultContObj)::vm() const
{
  if ( _state == oocHandlePTR && _ptr._obj != NULL )
    return ooReinterpretCast(ooDefaultContObj *, _ptr._obj);
  else return ooReinterpretCast(ooDefaultContObj *, this->get_vm());
}
inline
ooRef(ooDefaultContObj) &
ooHandle(ooDefaultContObj)::copy(const ooHandle(ooObj) &  nearH,
		   ooRef(ooDefaultContObj) &              result) const
{
  this->ooHandle(ooObj)::copy(nearH, result);
  return result;
}


/* ODMG methods */
inline
ooDefaultContObj *
ooRef(ooDefaultContObj)::ptr() const
{
  return this->pin();
}
inline
ooDefaultContObj *
ooHandle(ooDefaultContObj)::ptr() const
{
  return this->operator ooDefaultContObj *();
}
class ooGCContObj;


/////////////////////////////////////////////////////////////////////////////

ooTemplateSpecialization
class ooDeref(ooGCContObj) : public ooDerefBase {
	friend class ooRef(ooGCContObj);
  public:
    ~ooDerefStructor(ooGCContObj)();
    inline ooGCContObj *operator->() const;
#ifndef OO_BUGGY_TEMPLATES
  private:
#endif // !defined(OO_BUGGY_TEMPLATES)
    ooDerefStructor(ooGCContObj)(ooDeref(ooGCContObj)& deref);
    ooDerefStructor(ooGCContObj)(ooObj *  fromObject);
};


#ifdef OO_BUGGY_TEMPLATES

class ooHandle_superclass<ooGCContObj > : public ooHandle(ooContObj) {
 protected:
  ooHandle_superclass()
    {}
  ooHandle_superclass(const ooHandle(ooContObj) &  from) :
      ooHandle(ooContObj)(from)
    {}
  ooHandle_superclass(const ooRef(ooContObj) &  from) :
      ooHandle(ooContObj)(from)
    {}
  ooHandle_superclass(const ooContObj *  from) :
      ooHandle(ooContObj)(from)
    {}
  ~ooHandle_superclass()
    {}
};

class ooShortRef_superclass<ooGCContObj > : public ooShortRef(ooContObj) {
};

#endif // OO_BUGGY_TEMPLATES

ooTemplateSpecialization
class ooRef(ooGCContObj) : public ooRef(ooContObj) {
  public:
    ooRefStructor(ooGCContObj)()
      {}
    ooRefStructor(ooGCContObj)(const ooRef(ooGCContObj)& id) :
	  ooRef(ooContObj)(id)
      {}
    inline ooRefStructor(ooGCContObj)(const ooHandleSuper(ooGCContObj)& objH);
    inline ooRefStructor(ooGCContObj)(const ooGCContObj *  fromObject);
    inline ooRef(ooGCContObj)& operator=(const ooRef(ooGCContObj)& id);
    inline ooRef(ooGCContObj)& operator=(const ooShortRefSuper(ooGCContObj) &shortId);
    inline ooRef(ooGCContObj)& operator=(const ooHandleSuper(ooGCContObj)& objH);
    inline ooRef(ooGCContObj)& operator=(const ooGCContObj *  fromObject);
    ooStatus lookupObj(const ooHandle(ooObj)& scopeH,
		       const ooKey& key,
		       ooMode openMode = oocRead);
    ooStatus lookupObj(const ooHandle(ooObj)& scopeH,
		       const char* name,
		       ooMode openMode = oocRead);
#ifndef OO_BUGGY_TEMPLATES
    inline ooRef(ooGCContObj)& copy(const ooHandle(ooObj)& nearH,
		    ooRef(ooGCContObj)& newObjRef) const;
    inline ooHandle(ooGCContObj)& copy(const ooHandle(ooObj)& nearH,
			ooHandle(ooGCContObj)& result) const;
    inline ooHandle(ooGCContObj) copy(const ooHandle(ooObj)& nearH) const;
#endif // !defined(OO_BUGGY_TEMPLATES)
    inline ooGCContObj *pin(ooMode openMode = oocRead) const;
    ooDeref(ooGCContObj) operator->() const;
    /* Use pin() or use ooHandle "operator ooGCContObj *" instead of vm. */
    /* OBSOLETE */ inline ooGCContObj *vm(ooMode openMode = oocRead) const;
    // ODMG methods:
    ooRefStructor(ooGCContObj)(const d_Ref_Any &from);
    ooGCContObj *ptr() const;
};

ooTemplateSpecialization
class ooShortRef(ooGCContObj) :
#ifdef OO_BUGGY_TEMPLATES
			public ooShortRef_superclass<ooGCContObj >
#else // !defined(OO_BUGGY_TEMPLATES)
			public ooShortRef(ooContObj)
#endif // !defined(OO_BUGGY_TEMPLATES)
					            {
  public:
    ooShortRefStructor(ooGCContObj)();
    ooShortRefStructor(ooGCContObj)(const ooShortRef(ooGCContObj)& shortId);
    ooShortRefStructor(ooGCContObj)(const ooRef(ooGCContObj)& id);
    ooShortRefStructor(ooGCContObj)(const ooHandleSuper(ooGCContObj) &objH);
    ooShortRefStructor(ooGCContObj)(const ooGCContObj *  fromObject);
    ooShortRef(ooGCContObj)& operator=(const ooShortRef(ooGCContObj)& shortId);
    ooShortRef(ooGCContObj)& operator=(const ooRef(ooGCContObj)& id);
    ooShortRef(ooGCContObj)& operator=(const ooHandleSuper(ooGCContObj) &objH);
    ooShortRef(ooGCContObj)& operator=(const ooGCContObj *  fromObject);
};

ooTemplateSpecialization
class ooHandle(ooGCContObj) :
#ifdef OO_BUGGY_TEMPLATES
		      public ooHandle_superclass<ooGCContObj >
#else // !defined(OO_BUGGY_TEMPLATES)
		      public ooHandle(ooContObj)
#endif // !defined(OO_BUGGY_TEMPLATES)
                                                {
  public:
    inline ooHandleStructor(ooGCContObj)();
    inline ooHandleStructor(ooGCContObj)(const ooRef(ooGCContObj)& id);
    inline ooHandleStructor(ooGCContObj)(const ooHandle(ooGCContObj)& objH);
    inline ooHandleStructor(ooGCContObj)(const ooGCContObj *  fromObject);
    inline ooHandle(ooGCContObj)& operator=(const ooRef(ooGCContObj)& id);
    inline ooHandle(ooGCContObj)& operator=(const ooHandle(ooGCContObj)& objH);
    inline ooHandle(ooGCContObj)& operator=(const ooShortRef(ooGCContObj)& shortId);
    inline ooHandle(ooGCContObj)& operator=(const ooGCContObj *  fromObject);
    ooStatus lookupObj(const ooHandle(ooObj)& scopeH,
		       const ooKey& key,
		       ooMode openMode = oocRead);
    ooStatus lookupObj(const ooHandle(ooObj)& scopeH,
		       const char* name,
		       ooMode openMode = oocRead);
    ooHandle(ooGCContObj)& copy(const ooHandle(ooObj)& nearH,
		       ooHandle(ooGCContObj)& result) const;
    inline ooRef(ooGCContObj)& copy(const ooHandle(ooObj)& nearH,
		    ooRef(ooGCContObj)& result) const;
    ooHandle(ooGCContObj) copy(const ooHandle(ooObj)& nearH) const;
    inline ooGCContObj *pin(ooMode openMode = oocRead) const;
    inline ooGCContObj *operator->() const;
    inline ooGCContObj &operator*() const;
    inline operator ooGCContObj *() const;
    /* Use "operator ooGCContObj *" instead of vm. */
    /* OBSOLETE */ inline ooGCContObj *vm() const;
    // ODMG methods:
    ooHandleStructor(ooGCContObj)(const d_Ref_Any &from);
    ooGCContObj *ptr() const;
};

ooTemplateSpecialization
class ooItr(ooGCContObj) : public ooHandle(ooGCContObj),
		    public ooIteratorObjOrContObj {
  public:
    ooItrStructor(ooGCContObj)();
    ~ooItrStructor(ooGCContObj)();
  private:
    // Defined only to prevent implicit definition:
    ooItrStructor(ooGCContObj)(ooItr(ooGCContObj)&);
    ooItr(ooGCContObj)    operator=(ooItr(ooGCContObj)&);
};


/* methods on ooDeref(ooGCContObj) */
inline
ooDeref(ooGCContObj)::ooDerefStructor(ooGCContObj)(ooDeref(ooGCContObj) &  deref) :
    ooDerefBase(deref.vm())
{
  this->pinCompensate();
}
inline
ooDeref(ooGCContObj)::ooDerefStructor(ooGCContObj)(ooObj *  fromObject) :
    ooDerefBase(fromObject)
{
}
inline
ooDeref(ooGCContObj)::~ooDerefStructor(ooGCContObj)()
{
}
inline
ooGCContObj *
ooDeref(ooGCContObj)::operator->() const
{
  return ooReinterpretCast(ooGCContObj *, this->vm());
}


/* methods on ooRef(ooGCContObj) */
inline
ooRef(ooGCContObj)::ooRefStructor(ooGCContObj)(const ooHandleSuper(ooGCContObj)& objH) :
    ooRef(ooContObj)(objH)
{
}
inline
ooRef(ooGCContObj)::ooRefStructor(ooGCContObj)(const ooGCContObj *  fromObject) :
    ooRef(ooContObj)(ooReinterpretCast(const ooContObj *, fromObject))
{
}
inline
ooRef(ooGCContObj)&
ooRef(ooGCContObj)::operator=(const ooRef(ooGCContObj) &  id)
{
  this->ooId::operator=(id);
  return *this;
}
inline
ooRef(ooGCContObj)&
ooRef(ooGCContObj)::operator=(const ooShortRefSuper(ooGCContObj) &  shortId)
{
  this->ooRef(ooObj)::operator=(shortId);
  return *this;
}
inline
ooRef(ooGCContObj)&
ooRef(ooGCContObj)::operator=(const ooHandleSuper(ooGCContObj) &  objH)
{
  this->ooRef(ooObj)::operator=(objH);
  return *this;
}
inline
ooRef(ooGCContObj)&
ooRef(ooGCContObj)::operator=(const ooGCContObj *  fromObject)
{
  this->ooRef(ooObj)::operator=(ooReinterpretCast(const ooObj *, fromObject));
  return *this;
}
inline
ooGCContObj *
ooRef(ooGCContObj)::pin(ooMode  openMode) const
{
  return ooReinterpretCast(ooGCContObj *, this->pin_ref_internal(openMode));
}
inline
ooGCContObj *
ooRef(ooGCContObj)::vm(ooMode  openMode) const
{
  return this->pin(openMode);
}
#ifndef OO_BUGGY_TEMPLATES
inline
ooHandle(ooGCContObj) &
ooRef(ooGCContObj)::copy(const ooHandle(ooObj) &  nearH,
		ooHandle(ooGCContObj) &           result) const
{
  this->ooRef(ooObj)::copy(nearH, result);
  return result;
}
inline
ooRef(ooGCContObj) &
ooRef(ooGCContObj)::copy(const ooHandle(ooObj) &  nearH,
		ooRef(ooGCContObj) &              newObjRef) const
{
  this->ooRef(ooObj)::copy(nearH, newObjRef);
  return newObjRef;
}
inline
ooHandle(ooGCContObj)
ooRef(ooGCContObj)::copy(const ooHandle(ooObj) &  nearH) const
{
  ooHandle(ooGCContObj) result;
  this->ooRef(ooObj)::copy(nearH, result);
  return result;
}
#endif // !defined(OO_BUGGY_TEMPLATES)
inline
ooDeref(ooGCContObj)
ooRef(ooGCContObj)::operator->() const
{
  ooDeref(ooGCContObj) result(this->pin_ref_internal(oocRead));
  return result;
}


/* methods on ooShortRef(ooGCContObj) */
inline
ooShortRef(ooGCContObj) &
ooShortRef(ooGCContObj)::operator=(const ooShortRef(ooGCContObj) &  shortId)
{
  this->ooShortId::operator=(shortId);
  return *this;
}
inline
ooShortRef(ooGCContObj) &
ooShortRef(ooGCContObj)::operator=(const ooRef(ooGCContObj) &  id)
{
  this->ooShortId::operator=(id);
  return *this;
}
inline
ooShortRef(ooGCContObj) &
ooShortRef(ooGCContObj)::operator=(const ooHandleSuper(ooGCContObj) &  objH)
{
  this->ooShortId::operator=(objH);
  return *this;
}
inline
ooShortRef(ooGCContObj)&
ooShortRef(ooGCContObj)::operator=(const ooGCContObj *  fromObject)
{
  this->ooShortId::operator=(ooReinterpretCast(const ooObj *,fromObject));
  return *this;
}
inline
ooShortRef(ooGCContObj)::ooShortRefStructor(ooGCContObj)()
{
}
#ifdef OO_BUGGY_TEMPLATES
inline
ooShortRef(ooGCContObj)::ooShortRefStructor(ooGCContObj)(const ooShortRef(ooGCContObj) &  shortId)
{
  *this = shortId;
}
#else // !defined(OO_BUGGY_TEMPLATES)
inline
ooShortRef(ooGCContObj)::ooShortRefStructor(ooGCContObj)(const ooShortRef(ooGCContObj) &  shortId) :
    ooShortRef(ooContObj)(shortId)
{
}
#endif // !defined(OO_BUGGY_TEMPLATES)
#ifdef OO_BUGGY_TEMPLATES
inline
ooShortRef(ooGCContObj)::ooShortRefStructor(ooGCContObj)(const ooRef(ooGCContObj) &  id)
{
  *this = id;
}
#else // !defined(OO_BUGGY_TEMPLATES)
inline
ooShortRef(ooGCContObj)::ooShortRefStructor(ooGCContObj)(const ooRef(ooGCContObj) &  id) :
    ooShortRef(ooContObj)(id)
{
}
#endif // !defined(OO_BUGGY_TEMPLATES)
#ifdef OO_BUGGY_TEMPLATES
inline
ooShortRef(ooGCContObj)::ooShortRefStructor(ooGCContObj)(const ooHandleSuper(ooGCContObj) &  objH)
{
  *this = objH;
}
#else // !defined(OO_BUGGY_TEMPLATES)
inline
ooShortRef(ooGCContObj)::ooShortRefStructor(ooGCContObj)(const ooHandleSuper(ooGCContObj) &  objH) :
    ooShortRef(ooContObj)(objH)
{
}
#endif // !defined(OO_BUGGY_TEMPLATES)
#ifdef OO_BUGGY_TEMPLATES
inline
ooShortRef(ooGCContObj)::ooShortRefStructor(ooGCContObj)(const ooGCContObj *  fromObject)
{
  *this = fromObject;
}
#else // !defined(OO_BUGGY_TEMPLATES)
inline
ooShortRef(ooGCContObj)::ooShortRefStructor(ooGCContObj)(const ooGCContObj *  fromObject) :
    ooShortRef(ooContObj)(ooReinterpretCast(const ooContObj *,fromObject))
{
}
#endif // !defined(OO_BUGGY_TEMPLATES)


/* methods on ooHandle(ooGCContObj) */
inline
ooHandle(ooGCContObj)::ooHandleStructor(ooGCContObj)()
{
}
inline
ooHandle(ooGCContObj)::ooHandleStructor(ooGCContObj)(const ooHandle(ooGCContObj) &  objH) :
#ifdef OO_BUGGY_TEMPLATES
    ooHandle_superclass<ooGCContObj >(objH)
#else // !defined(OO_BUGGY_TEMPLATES)
    ooHandle(ooContObj)(objH)
#endif // !defined(OO_BUGGY_TEMPLATES)
{
}
inline
ooHandle(ooGCContObj)::ooHandleStructor(ooGCContObj)(const ooRef(ooGCContObj) &  id) :
#ifdef OO_BUGGY_TEMPLATES
    ooHandle_superclass<ooGCContObj >(id)
#else // !defined(OO_BUGGY_TEMPLATES)
    ooHandle(ooContObj)(id)
#endif // !defined(OO_BUGGY_TEMPLATES)
{
}
inline
ooHandle(ooGCContObj)::ooHandleStructor(ooGCContObj)(const ooGCContObj *  fromObject) :
#ifdef OO_BUGGY_TEMPLATES
    ooHandle_superclass<ooGCContObj >(ooReinterpretCast(const ooContObj *,fromObject))
#else // !defined(OO_BUGGY_TEMPLATES)
    ooHandle(ooContObj)(ooReinterpretCast(const ooContObj *,fromObject))
#endif // !defined(OO_BUGGY_TEMPLATES)
{
}
inline
ooHandle(ooGCContObj)&
ooHandle(ooGCContObj)::operator=(const ooRef(ooGCContObj) &  id)
{
  this->ooHandle(ooObj)::operator=(id);
  return *this;
}
inline
ooHandle(ooGCContObj)&
ooHandle(ooGCContObj)::operator=(const ooHandle(ooGCContObj) &  objH)
{
  this->ooHandle(ooObj)::operator=(objH);
  return *this;
}
inline
ooHandle(ooGCContObj)&
ooHandle(ooGCContObj)::operator=(const ooShortRef(ooGCContObj) &  shortId)
{
  this->ooHandle(ooObj)::operator=(shortId);
  return *this;
}
inline
ooHandle(ooGCContObj)&
ooHandle(ooGCContObj)::operator=(const ooGCContObj *  fromObject)
{
  this->ooHandle(ooObj)::operator=(ooReinterpretCast(const ooObj *,fromObject));
  return *this;
}
inline
ooGCContObj *
ooHandle(ooGCContObj)::pin(ooMode  openMode) const
{
  return ooReinterpretCast(ooGCContObj *, this->pin_obj_internal(openMode));
}
inline
ooGCContObj *
ooHandle(ooGCContObj)::operator->() const
{
  return this->vm();
}
inline
ooGCContObj &
ooHandle(ooGCContObj)::operator*() const
{
  return *(this->vm());
}
inline
ooHandle(ooGCContObj)::operator ooGCContObj *() const
{
  if ( _state == oocHandlePTR  )
    return ooReinterpretCast(ooGCContObj *, _ptr._obj);
  else return ooReinterpretCast(ooGCContObj *, this->get_vm());
}
inline
ooGCContObj *
ooHandle(ooGCContObj)::vm() const
{
  if ( _state == oocHandlePTR && _ptr._obj != NULL )
    return ooReinterpretCast(ooGCContObj *, _ptr._obj);
  else return ooReinterpretCast(ooGCContObj *, this->get_vm());
}
inline
ooRef(ooGCContObj) &
ooHandle(ooGCContObj)::copy(const ooHandle(ooObj) &  nearH,
		   ooRef(ooGCContObj) &              result) const
{
  this->ooHandle(ooObj)::copy(nearH, result);
  return result;
}


/* ODMG methods */
inline
ooGCContObj *
ooRef(ooGCContObj)::ptr() const
{
  return this->pin();
}
inline
ooGCContObj *
ooHandle(ooGCContObj)::ptr() const
{
  return this->operator ooGCContObj *();
}
class ooGCRootsCont;


/////////////////////////////////////////////////////////////////////////////

ooTemplateSpecialization
class ooDeref(ooGCRootsCont) : public ooDerefBase {
	friend class ooRef(ooGCRootsCont);
  public:
    ~ooDerefStructor(ooGCRootsCont)();
    inline ooGCRootsCont *operator->() const;
#ifndef OO_BUGGY_TEMPLATES
  private:
#endif // !defined(OO_BUGGY_TEMPLATES)
    ooDerefStructor(ooGCRootsCont)(ooDeref(ooGCRootsCont)& deref);
    ooDerefStructor(ooGCRootsCont)(ooObj *  fromObject);
};


#ifdef OO_BUGGY_TEMPLATES

class ooHandle_superclass<ooGCRootsCont > : public ooHandle(ooGCContObj) {
 protected:
  ooHandle_superclass()
    {}
  ooHandle_superclass(const ooHandle(ooGCContObj) &  from) :
      ooHandle(ooGCContObj)(from)
    {}
  ooHandle_superclass(const ooRef(ooGCContObj) &  from) :
      ooHandle(ooGCContObj)(from)
    {}
  ooHandle_superclass(const ooGCContObj *  from) :
      ooHandle(ooGCContObj)(from)
    {}
  ~ooHandle_superclass()
    {}
};

class ooShortRef_superclass<ooGCRootsCont > : public ooShortRef(ooGCContObj) {
};

#endif // OO_BUGGY_TEMPLATES

ooTemplateSpecialization
class ooRef(ooGCRootsCont) : public ooRef(ooGCContObj) {
  public:
    ooRefStructor(ooGCRootsCont)()
      {}
    ooRefStructor(ooGCRootsCont)(const ooRef(ooGCRootsCont)& id) :
	  ooRef(ooGCContObj)(id)
      {}
    inline ooRefStructor(ooGCRootsCont)(const ooHandleSuper(ooGCRootsCont)& objH);
    inline ooRefStructor(ooGCRootsCont)(const ooGCRootsCont *  fromObject);
    inline ooRef(ooGCRootsCont)& operator=(const ooRef(ooGCRootsCont)& id);
    inline ooRef(ooGCRootsCont)& operator=(const ooShortRefSuper(ooGCRootsCont) &shortId);
    inline ooRef(ooGCRootsCont)& operator=(const ooHandleSuper(ooGCRootsCont)& objH);
    inline ooRef(ooGCRootsCont)& operator=(const ooGCRootsCont *  fromObject);
    ooStatus lookupObj(const ooHandle(ooObj)& scopeH,
		       const ooKey& key,
		       ooMode openMode = oocRead);
    ooStatus lookupObj(const ooHandle(ooObj)& scopeH,
		       const char* name,
		       ooMode openMode = oocRead);
#ifndef OO_BUGGY_TEMPLATES
    inline ooRef(ooGCRootsCont)& copy(const ooHandle(ooObj)& nearH,
		    ooRef(ooGCRootsCont)& newObjRef) const;
    inline ooHandle(ooGCRootsCont)& copy(const ooHandle(ooObj)& nearH,
			ooHandle(ooGCRootsCont)& result) const;
    inline ooHandle(ooGCRootsCont) copy(const ooHandle(ooObj)& nearH) const;
#endif // !defined(OO_BUGGY_TEMPLATES)
    inline ooGCRootsCont *pin(ooMode openMode = oocRead) const;
    ooDeref(ooGCRootsCont) operator->() const;
    /* Use pin() or use ooHandle "operator ooGCRootsCont *" instead of vm. */
    /* OBSOLETE */ inline ooGCRootsCont *vm(ooMode openMode = oocRead) const;
    // ODMG methods:
    ooRefStructor(ooGCRootsCont)(const d_Ref_Any &from);
    ooGCRootsCont *ptr() const;
};

ooTemplateSpecialization
class ooShortRef(ooGCRootsCont) :
#ifdef OO_BUGGY_TEMPLATES
			public ooShortRef_superclass<ooGCRootsCont >
#else // !defined(OO_BUGGY_TEMPLATES)
			public ooShortRef(ooGCContObj)
#endif // !defined(OO_BUGGY_TEMPLATES)
					            {
  public:
    ooShortRefStructor(ooGCRootsCont)();
    ooShortRefStructor(ooGCRootsCont)(const ooShortRef(ooGCRootsCont)& shortId);
    ooShortRefStructor(ooGCRootsCont)(const ooRef(ooGCRootsCont)& id);
    ooShortRefStructor(ooGCRootsCont)(const ooHandleSuper(ooGCRootsCont) &objH);
    ooShortRefStructor(ooGCRootsCont)(const ooGCRootsCont *  fromObject);
    ooShortRef(ooGCRootsCont)& operator=(const ooShortRef(ooGCRootsCont)& shortId);
    ooShortRef(ooGCRootsCont)& operator=(const ooRef(ooGCRootsCont)& id);
    ooShortRef(ooGCRootsCont)& operator=(const ooHandleSuper(ooGCRootsCont) &objH);
    ooShortRef(ooGCRootsCont)& operator=(const ooGCRootsCont *  fromObject);
};

ooTemplateSpecialization
class ooHandle(ooGCRootsCont) :
#ifdef OO_BUGGY_TEMPLATES
		      public ooHandle_superclass<ooGCRootsCont >
#else // !defined(OO_BUGGY_TEMPLATES)
		      public ooHandle(ooGCContObj)
#endif // !defined(OO_BUGGY_TEMPLATES)
                                                {
  public:
    inline ooHandleStructor(ooGCRootsCont)();
    inline ooHandleStructor(ooGCRootsCont)(const ooRef(ooGCRootsCont)& id);
    inline ooHandleStructor(ooGCRootsCont)(const ooHandle(ooGCRootsCont)& objH);
    inline ooHandleStructor(ooGCRootsCont)(const ooGCRootsCont *  fromObject);
    inline ooHandle(ooGCRootsCont)& operator=(const ooRef(ooGCRootsCont)& id);
    inline ooHandle(ooGCRootsCont)& operator=(const ooHandle(ooGCRootsCont)& objH);
    inline ooHandle(ooGCRootsCont)& operator=(const ooShortRef(ooGCRootsCont)& shortId);
    inline ooHandle(ooGCRootsCont)& operator=(const ooGCRootsCont *  fromObject);
    ooStatus lookupObj(const ooHandle(ooObj)& scopeH,
		       const ooKey& key,
		       ooMode openMode = oocRead);
    ooStatus lookupObj(const ooHandle(ooObj)& scopeH,
		       const char* name,
		       ooMode openMode = oocRead);
    ooHandle(ooGCRootsCont)& copy(const ooHandle(ooObj)& nearH,
		       ooHandle(ooGCRootsCont)& result) const;
    inline ooRef(ooGCRootsCont)& copy(const ooHandle(ooObj)& nearH,
		    ooRef(ooGCRootsCont)& result) const;
    ooHandle(ooGCRootsCont) copy(const ooHandle(ooObj)& nearH) const;
    inline ooGCRootsCont *pin(ooMode openMode = oocRead) const;
    inline ooGCRootsCont *operator->() const;
    inline ooGCRootsCont &operator*() const;
    inline operator ooGCRootsCont *() const;
    /* Use "operator ooGCRootsCont *" instead of vm. */
    /* OBSOLETE */ inline ooGCRootsCont *vm() const;
    // ODMG methods:
    ooHandleStructor(ooGCRootsCont)(const d_Ref_Any &from);
    ooGCRootsCont *ptr() const;
};

ooTemplateSpecialization
class ooItr(ooGCRootsCont) : public ooHandle(ooGCRootsCont),
		    public ooIteratorObjOrContObj {
  public:
    ooItrStructor(ooGCRootsCont)();
    ~ooItrStructor(ooGCRootsCont)();
  private:
    // Defined only to prevent implicit definition:
    ooItrStructor(ooGCRootsCont)(ooItr(ooGCRootsCont)&);
    ooItr(ooGCRootsCont)    operator=(ooItr(ooGCRootsCont)&);
};


/* methods on ooDeref(ooGCRootsCont) */
inline
ooDeref(ooGCRootsCont)::ooDerefStructor(ooGCRootsCont)(ooDeref(ooGCRootsCont) &  deref) :
    ooDerefBase(deref.vm())
{
  this->pinCompensate();
}
inline
ooDeref(ooGCRootsCont)::ooDerefStructor(ooGCRootsCont)(ooObj *  fromObject) :
    ooDerefBase(fromObject)
{
}
inline
ooDeref(ooGCRootsCont)::~ooDerefStructor(ooGCRootsCont)()
{
}
inline
ooGCRootsCont *
ooDeref(ooGCRootsCont)::operator->() const
{
  return ooReinterpretCast(ooGCRootsCont *, this->vm());
}


/* methods on ooRef(ooGCRootsCont) */
inline
ooRef(ooGCRootsCont)::ooRefStructor(ooGCRootsCont)(const ooHandleSuper(ooGCRootsCont)& objH) :
    ooRef(ooGCContObj)(objH)
{
}
inline
ooRef(ooGCRootsCont)::ooRefStructor(ooGCRootsCont)(const ooGCRootsCont *  fromObject) :
    ooRef(ooGCContObj)(ooReinterpretCast(const ooGCContObj *, fromObject))
{
}
inline
ooRef(ooGCRootsCont)&
ooRef(ooGCRootsCont)::operator=(const ooRef(ooGCRootsCont) &  id)
{
  this->ooId::operator=(id);
  return *this;
}
inline
ooRef(ooGCRootsCont)&
ooRef(ooGCRootsCont)::operator=(const ooShortRefSuper(ooGCRootsCont) &  shortId)
{
  this->ooRef(ooObj)::operator=(shortId);
  return *this;
}
inline
ooRef(ooGCRootsCont)&
ooRef(ooGCRootsCont)::operator=(const ooHandleSuper(ooGCRootsCont) &  objH)
{
  this->ooRef(ooObj)::operator=(objH);
  return *this;
}
inline
ooRef(ooGCRootsCont)&
ooRef(ooGCRootsCont)::operator=(const ooGCRootsCont *  fromObject)
{
  this->ooRef(ooObj)::operator=(ooReinterpretCast(const ooObj *, fromObject));
  return *this;
}
inline
ooGCRootsCont *
ooRef(ooGCRootsCont)::pin(ooMode  openMode) const
{
  return ooReinterpretCast(ooGCRootsCont *, this->pin_ref_internal(openMode));
}
inline
ooGCRootsCont *
ooRef(ooGCRootsCont)::vm(ooMode  openMode) const
{
  return this->pin(openMode);
}
#ifndef OO_BUGGY_TEMPLATES
inline
ooHandle(ooGCRootsCont) &
ooRef(ooGCRootsCont)::copy(const ooHandle(ooObj) &  nearH,
		ooHandle(ooGCRootsCont) &           result) const
{
  this->ooRef(ooObj)::copy(nearH, result);
  return result;
}
inline
ooRef(ooGCRootsCont) &
ooRef(ooGCRootsCont)::copy(const ooHandle(ooObj) &  nearH,
		ooRef(ooGCRootsCont) &              newObjRef) const
{
  this->ooRef(ooObj)::copy(nearH, newObjRef);
  return newObjRef;
}
inline
ooHandle(ooGCRootsCont)
ooRef(ooGCRootsCont)::copy(const ooHandle(ooObj) &  nearH) const
{
  ooHandle(ooGCRootsCont) result;
  this->ooRef(ooObj)::copy(nearH, result);
  return result;
}
#endif // !defined(OO_BUGGY_TEMPLATES)
inline
ooDeref(ooGCRootsCont)
ooRef(ooGCRootsCont)::operator->() const
{
  ooDeref(ooGCRootsCont) result(this->pin_ref_internal(oocRead));
  return result;
}


/* methods on ooShortRef(ooGCRootsCont) */
inline
ooShortRef(ooGCRootsCont) &
ooShortRef(ooGCRootsCont)::operator=(const ooShortRef(ooGCRootsCont) &  shortId)
{
  this->ooShortId::operator=(shortId);
  return *this;
}
inline
ooShortRef(ooGCRootsCont) &
ooShortRef(ooGCRootsCont)::operator=(const ooRef(ooGCRootsCont) &  id)
{
  this->ooShortId::operator=(id);
  return *this;
}
inline
ooShortRef(ooGCRootsCont) &
ooShortRef(ooGCRootsCont)::operator=(const ooHandleSuper(ooGCRootsCont) &  objH)
{
  this->ooShortId::operator=(objH);
  return *this;
}
inline
ooShortRef(ooGCRootsCont)&
ooShortRef(ooGCRootsCont)::operator=(const ooGCRootsCont *  fromObject)
{
  this->ooShortId::operator=(ooReinterpretCast(const ooObj *,fromObject));
  return *this;
}
inline
ooShortRef(ooGCRootsCont)::ooShortRefStructor(ooGCRootsCont)()
{
}
#ifdef OO_BUGGY_TEMPLATES
inline
ooShortRef(ooGCRootsCont)::ooShortRefStructor(ooGCRootsCont)(const ooShortRef(ooGCRootsCont) &  shortId)
{
  *this = shortId;
}
#else // !defined(OO_BUGGY_TEMPLATES)
inline
ooShortRef(ooGCRootsCont)::ooShortRefStructor(ooGCRootsCont)(const ooShortRef(ooGCRootsCont) &  shortId) :
    ooShortRef(ooGCContObj)(shortId)
{
}
#endif // !defined(OO_BUGGY_TEMPLATES)
#ifdef OO_BUGGY_TEMPLATES
inline
ooShortRef(ooGCRootsCont)::ooShortRefStructor(ooGCRootsCont)(const ooRef(ooGCRootsCont) &  id)
{
  *this = id;
}
#else // !defined(OO_BUGGY_TEMPLATES)
inline
ooShortRef(ooGCRootsCont)::ooShortRefStructor(ooGCRootsCont)(const ooRef(ooGCRootsCont) &  id) :
    ooShortRef(ooGCContObj)(id)
{
}
#endif // !defined(OO_BUGGY_TEMPLATES)
#ifdef OO_BUGGY_TEMPLATES
inline
ooShortRef(ooGCRootsCont)::ooShortRefStructor(ooGCRootsCont)(const ooHandleSuper(ooGCRootsCont) &  objH)
{
  *this = objH;
}
#else // !defined(OO_BUGGY_TEMPLATES)
inline
ooShortRef(ooGCRootsCont)::ooShortRefStructor(ooGCRootsCont)(const ooHandleSuper(ooGCRootsCont) &  objH) :
    ooShortRef(ooGCContObj)(objH)
{
}
#endif // !defined(OO_BUGGY_TEMPLATES)
#ifdef OO_BUGGY_TEMPLATES
inline
ooShortRef(ooGCRootsCont)::ooShortRefStructor(ooGCRootsCont)(const ooGCRootsCont *  fromObject)
{
  *this = fromObject;
}
#else // !defined(OO_BUGGY_TEMPLATES)
inline
ooShortRef(ooGCRootsCont)::ooShortRefStructor(ooGCRootsCont)(const ooGCRootsCont *  fromObject) :
    ooShortRef(ooGCContObj)(ooReinterpretCast(const ooGCContObj *,fromObject))
{
}
#endif // !defined(OO_BUGGY_TEMPLATES)


/* methods on ooHandle(ooGCRootsCont) */
inline
ooHandle(ooGCRootsCont)::ooHandleStructor(ooGCRootsCont)()
{
}
inline
ooHandle(ooGCRootsCont)::ooHandleStructor(ooGCRootsCont)(const ooHandle(ooGCRootsCont) &  objH) :
#ifdef OO_BUGGY_TEMPLATES
    ooHandle_superclass<ooGCRootsCont >(objH)
#else // !defined(OO_BUGGY_TEMPLATES)
    ooHandle(ooGCContObj)(objH)
#endif // !defined(OO_BUGGY_TEMPLATES)
{
}
inline
ooHandle(ooGCRootsCont)::ooHandleStructor(ooGCRootsCont)(const ooRef(ooGCRootsCont) &  id) :
#ifdef OO_BUGGY_TEMPLATES
    ooHandle_superclass<ooGCRootsCont >(id)
#else // !defined(OO_BUGGY_TEMPLATES)
    ooHandle(ooGCContObj)(id)
#endif // !defined(OO_BUGGY_TEMPLATES)
{
}
inline
ooHandle(ooGCRootsCont)::ooHandleStructor(ooGCRootsCont)(const ooGCRootsCont *  fromObject) :
#ifdef OO_BUGGY_TEMPLATES
    ooHandle_superclass<ooGCRootsCont >(ooReinterpretCast(const ooGCContObj *,fromObject))
#else // !defined(OO_BUGGY_TEMPLATES)
    ooHandle(ooGCContObj)(ooReinterpretCast(const ooGCContObj *,fromObject))
#endif // !defined(OO_BUGGY_TEMPLATES)
{
}
inline
ooHandle(ooGCRootsCont)&
ooHandle(ooGCRootsCont)::operator=(const ooRef(ooGCRootsCont) &  id)
{
  this->ooHandle(ooObj)::operator=(id);
  return *this;
}
inline
ooHandle(ooGCRootsCont)&
ooHandle(ooGCRootsCont)::operator=(const ooHandle(ooGCRootsCont) &  objH)
{
  this->ooHandle(ooObj)::operator=(objH);
  return *this;
}
inline
ooHandle(ooGCRootsCont)&
ooHandle(ooGCRootsCont)::operator=(const ooShortRef(ooGCRootsCont) &  shortId)
{
  this->ooHandle(ooObj)::operator=(shortId);
  return *this;
}
inline
ooHandle(ooGCRootsCont)&
ooHandle(ooGCRootsCont)::operator=(const ooGCRootsCont *  fromObject)
{
  this->ooHandle(ooObj)::operator=(ooReinterpretCast(const ooObj *,fromObject));
  return *this;
}
inline
ooGCRootsCont *
ooHandle(ooGCRootsCont)::pin(ooMode  openMode) const
{
  return ooReinterpretCast(ooGCRootsCont *, this->pin_obj_internal(openMode));
}
inline
ooGCRootsCont *
ooHandle(ooGCRootsCont)::operator->() const
{
  return this->vm();
}
inline
ooGCRootsCont &
ooHandle(ooGCRootsCont)::operator*() const
{
  return *(this->vm());
}
inline
ooHandle(ooGCRootsCont)::operator ooGCRootsCont *() const
{
  if ( _state == oocHandlePTR  )
    return ooReinterpretCast(ooGCRootsCont *, _ptr._obj);
  else return ooReinterpretCast(ooGCRootsCont *, this->get_vm());
}
inline
ooGCRootsCont *
ooHandle(ooGCRootsCont)::vm() const
{
  if ( _state == oocHandlePTR && _ptr._obj != NULL )
    return ooReinterpretCast(ooGCRootsCont *, _ptr._obj);
  else return ooReinterpretCast(ooGCRootsCont *, this->get_vm());
}
inline
ooRef(ooGCRootsCont) &
ooHandle(ooGCRootsCont)::copy(const ooHandle(ooObj) &  nearH,
		   ooRef(ooGCRootsCont) &              result) const
{
  this->ooHandle(ooObj)::copy(nearH, result);
  return result;
}


/* ODMG methods */
inline
ooGCRootsCont *
ooRef(ooGCRootsCont)::ptr() const
{
  return this->pin();
}
inline
ooGCRootsCont *
ooHandle(ooGCRootsCont)::ptr() const
{
  return this->operator ooGCRootsCont *();
}
class ooCheckOutInfoObj;


/////////////////////////////////////////////////////////////////////////////

ooTemplateSpecialization
class ooDeref(ooCheckOutInfoObj) : public ooDerefBase {
	friend class ooRef(ooCheckOutInfoObj);
  public:
    ~ooDerefStructor(ooCheckOutInfoObj)();
    inline ooCheckOutInfoObj *operator->() const;
#ifndef OO_BUGGY_TEMPLATES
  private:
#endif // !defined(OO_BUGGY_TEMPLATES)
    ooDerefStructor(ooCheckOutInfoObj)(ooDeref(ooCheckOutInfoObj)& deref);
    ooDerefStructor(ooCheckOutInfoObj)(ooObj *  fromObject);
};


#ifdef OO_BUGGY_TEMPLATES

class ooHandle_superclass<ooCheckOutInfoObj > : public ooHandle(ooObj) {
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

class ooShortRef_superclass<ooCheckOutInfoObj > : public ooShortRef(ooObj) {
};

#endif // OO_BUGGY_TEMPLATES

ooTemplateSpecialization
class ooRef(ooCheckOutInfoObj) : public ooRef(ooObj) {
  public:
    ooRefStructor(ooCheckOutInfoObj)()
      {}
    ooRefStructor(ooCheckOutInfoObj)(const ooRef(ooCheckOutInfoObj)& id) :
	  ooRef(ooObj)(id)
      {}
    inline ooRefStructor(ooCheckOutInfoObj)(const ooHandleSuper(ooCheckOutInfoObj)& objH);
    inline ooRefStructor(ooCheckOutInfoObj)(const ooCheckOutInfoObj *  fromObject);
    inline ooRef(ooCheckOutInfoObj)& operator=(const ooRef(ooCheckOutInfoObj)& id);
    inline ooRef(ooCheckOutInfoObj)& operator=(const ooShortRefSuper(ooCheckOutInfoObj) &shortId);
    inline ooRef(ooCheckOutInfoObj)& operator=(const ooHandleSuper(ooCheckOutInfoObj)& objH);
    inline ooRef(ooCheckOutInfoObj)& operator=(const ooCheckOutInfoObj *  fromObject);
    ooStatus lookupObj(const ooHandle(ooObj)& scopeH,
		       const ooKey& key,
		       ooMode openMode = oocRead);
    ooStatus lookupObj(const ooHandle(ooObj)& scopeH,
		       const char* name,
		       ooMode openMode = oocRead);
#ifndef OO_BUGGY_TEMPLATES
    inline ooRef(ooCheckOutInfoObj)& copy(const ooHandle(ooObj)& nearH,
		    ooRef(ooCheckOutInfoObj)& newObjRef) const;
    inline ooHandle(ooCheckOutInfoObj)& copy(const ooHandle(ooObj)& nearH,
			ooHandle(ooCheckOutInfoObj)& result) const;
    inline ooHandle(ooCheckOutInfoObj) copy(const ooHandle(ooObj)& nearH) const;
#endif // !defined(OO_BUGGY_TEMPLATES)
    inline ooCheckOutInfoObj *pin(ooMode openMode = oocRead) const;
    ooDeref(ooCheckOutInfoObj) operator->() const;
    /* Use pin() or use ooHandle "operator ooCheckOutInfoObj *" instead of vm. */
    /* OBSOLETE */ inline ooCheckOutInfoObj *vm(ooMode openMode = oocRead) const;
    // ODMG methods:
    ooRefStructor(ooCheckOutInfoObj)(const d_Ref_Any &from);
    ooCheckOutInfoObj *ptr() const;
};

ooTemplateSpecialization
class ooShortRef(ooCheckOutInfoObj) :
#ifdef OO_BUGGY_TEMPLATES
			public ooShortRef_superclass<ooCheckOutInfoObj >
#else // !defined(OO_BUGGY_TEMPLATES)
			public ooShortRef(ooObj)
#endif // !defined(OO_BUGGY_TEMPLATES)
					            {
  public:
    ooShortRefStructor(ooCheckOutInfoObj)();
    ooShortRefStructor(ooCheckOutInfoObj)(const ooShortRef(ooCheckOutInfoObj)& shortId);
    ooShortRefStructor(ooCheckOutInfoObj)(const ooRef(ooCheckOutInfoObj)& id);
    ooShortRefStructor(ooCheckOutInfoObj)(const ooHandleSuper(ooCheckOutInfoObj) &objH);
    ooShortRefStructor(ooCheckOutInfoObj)(const ooCheckOutInfoObj *  fromObject);
    ooShortRef(ooCheckOutInfoObj)& operator=(const ooShortRef(ooCheckOutInfoObj)& shortId);
    ooShortRef(ooCheckOutInfoObj)& operator=(const ooRef(ooCheckOutInfoObj)& id);
    ooShortRef(ooCheckOutInfoObj)& operator=(const ooHandleSuper(ooCheckOutInfoObj) &objH);
    ooShortRef(ooCheckOutInfoObj)& operator=(const ooCheckOutInfoObj *  fromObject);
};

ooTemplateSpecialization
class ooHandle(ooCheckOutInfoObj) :
#ifdef OO_BUGGY_TEMPLATES
		      public ooHandle_superclass<ooCheckOutInfoObj >
#else // !defined(OO_BUGGY_TEMPLATES)
		      public ooHandle(ooObj)
#endif // !defined(OO_BUGGY_TEMPLATES)
                                                {
  public:
    inline ooHandleStructor(ooCheckOutInfoObj)();
    inline ooHandleStructor(ooCheckOutInfoObj)(const ooRef(ooCheckOutInfoObj)& id);
    inline ooHandleStructor(ooCheckOutInfoObj)(const ooHandle(ooCheckOutInfoObj)& objH);
    inline ooHandleStructor(ooCheckOutInfoObj)(const ooCheckOutInfoObj *  fromObject);
    inline ooHandle(ooCheckOutInfoObj)& operator=(const ooRef(ooCheckOutInfoObj)& id);
    inline ooHandle(ooCheckOutInfoObj)& operator=(const ooHandle(ooCheckOutInfoObj)& objH);
    inline ooHandle(ooCheckOutInfoObj)& operator=(const ooShortRef(ooCheckOutInfoObj)& shortId);
    inline ooHandle(ooCheckOutInfoObj)& operator=(const ooCheckOutInfoObj *  fromObject);
    ooStatus lookupObj(const ooHandle(ooObj)& scopeH,
		       const ooKey& key,
		       ooMode openMode = oocRead);
    ooStatus lookupObj(const ooHandle(ooObj)& scopeH,
		       const char* name,
		       ooMode openMode = oocRead);
    ooHandle(ooCheckOutInfoObj)& copy(const ooHandle(ooObj)& nearH,
		       ooHandle(ooCheckOutInfoObj)& result) const;
    inline ooRef(ooCheckOutInfoObj)& copy(const ooHandle(ooObj)& nearH,
		    ooRef(ooCheckOutInfoObj)& result) const;
    ooHandle(ooCheckOutInfoObj) copy(const ooHandle(ooObj)& nearH) const;
    inline ooCheckOutInfoObj *pin(ooMode openMode = oocRead) const;
    inline ooCheckOutInfoObj *operator->() const;
    inline ooCheckOutInfoObj &operator*() const;
    inline operator ooCheckOutInfoObj *() const;
    /* Use "operator ooCheckOutInfoObj *" instead of vm. */
    /* OBSOLETE */ inline ooCheckOutInfoObj *vm() const;
    // ODMG methods:
    ooHandleStructor(ooCheckOutInfoObj)(const d_Ref_Any &from);
    ooCheckOutInfoObj *ptr() const;
};

ooTemplateSpecialization
class ooItr(ooCheckOutInfoObj) : public ooHandle(ooCheckOutInfoObj),
		    public ooIteratorObjOrContObj {
  public:
    ooItrStructor(ooCheckOutInfoObj)();
    ~ooItrStructor(ooCheckOutInfoObj)();
  private:
    // Defined only to prevent implicit definition:
    ooItrStructor(ooCheckOutInfoObj)(ooItr(ooCheckOutInfoObj)&);
    ooItr(ooCheckOutInfoObj)    operator=(ooItr(ooCheckOutInfoObj)&);
};


/* methods on ooDeref(ooCheckOutInfoObj) */
inline
ooDeref(ooCheckOutInfoObj)::ooDerefStructor(ooCheckOutInfoObj)(ooDeref(ooCheckOutInfoObj) &  deref) :
    ooDerefBase(deref.vm())
{
  this->pinCompensate();
}
inline
ooDeref(ooCheckOutInfoObj)::ooDerefStructor(ooCheckOutInfoObj)(ooObj *  fromObject) :
    ooDerefBase(fromObject)
{
}
inline
ooDeref(ooCheckOutInfoObj)::~ooDerefStructor(ooCheckOutInfoObj)()
{
}
inline
ooCheckOutInfoObj *
ooDeref(ooCheckOutInfoObj)::operator->() const
{
  return ooReinterpretCast(ooCheckOutInfoObj *, this->vm());
}


/* methods on ooRef(ooCheckOutInfoObj) */
inline
ooRef(ooCheckOutInfoObj)::ooRefStructor(ooCheckOutInfoObj)(const ooHandleSuper(ooCheckOutInfoObj)& objH) :
    ooRef(ooObj)(objH)
{
}
inline
ooRef(ooCheckOutInfoObj)::ooRefStructor(ooCheckOutInfoObj)(const ooCheckOutInfoObj *  fromObject) :
    ooRef(ooObj)(ooReinterpretCast(const ooObj *, fromObject))
{
}
inline
ooRef(ooCheckOutInfoObj)&
ooRef(ooCheckOutInfoObj)::operator=(const ooRef(ooCheckOutInfoObj) &  id)
{
  this->ooId::operator=(id);
  return *this;
}
inline
ooRef(ooCheckOutInfoObj)&
ooRef(ooCheckOutInfoObj)::operator=(const ooShortRefSuper(ooCheckOutInfoObj) &  shortId)
{
  this->ooRef(ooObj)::operator=(shortId);
  return *this;
}
inline
ooRef(ooCheckOutInfoObj)&
ooRef(ooCheckOutInfoObj)::operator=(const ooHandleSuper(ooCheckOutInfoObj) &  objH)
{
  this->ooRef(ooObj)::operator=(objH);
  return *this;
}
inline
ooRef(ooCheckOutInfoObj)&
ooRef(ooCheckOutInfoObj)::operator=(const ooCheckOutInfoObj *  fromObject)
{
  this->ooRef(ooObj)::operator=(ooReinterpretCast(const ooObj *, fromObject));
  return *this;
}
inline
ooCheckOutInfoObj *
ooRef(ooCheckOutInfoObj)::pin(ooMode  openMode) const
{
  return ooReinterpretCast(ooCheckOutInfoObj *, this->pin_ref_internal(openMode));
}
inline
ooCheckOutInfoObj *
ooRef(ooCheckOutInfoObj)::vm(ooMode  openMode) const
{
  return this->pin(openMode);
}
#ifndef OO_BUGGY_TEMPLATES
inline
ooHandle(ooCheckOutInfoObj) &
ooRef(ooCheckOutInfoObj)::copy(const ooHandle(ooObj) &  nearH,
		ooHandle(ooCheckOutInfoObj) &           result) const
{
  this->ooRef(ooObj)::copy(nearH, result);
  return result;
}
inline
ooRef(ooCheckOutInfoObj) &
ooRef(ooCheckOutInfoObj)::copy(const ooHandle(ooObj) &  nearH,
		ooRef(ooCheckOutInfoObj) &              newObjRef) const
{
  this->ooRef(ooObj)::copy(nearH, newObjRef);
  return newObjRef;
}
inline
ooHandle(ooCheckOutInfoObj)
ooRef(ooCheckOutInfoObj)::copy(const ooHandle(ooObj) &  nearH) const
{
  ooHandle(ooCheckOutInfoObj) result;
  this->ooRef(ooObj)::copy(nearH, result);
  return result;
}
#endif // !defined(OO_BUGGY_TEMPLATES)
inline
ooDeref(ooCheckOutInfoObj)
ooRef(ooCheckOutInfoObj)::operator->() const
{
  ooDeref(ooCheckOutInfoObj) result(this->pin_ref_internal(oocRead));
  return result;
}


/* methods on ooShortRef(ooCheckOutInfoObj) */
inline
ooShortRef(ooCheckOutInfoObj) &
ooShortRef(ooCheckOutInfoObj)::operator=(const ooShortRef(ooCheckOutInfoObj) &  shortId)
{
  this->ooShortId::operator=(shortId);
  return *this;
}
inline
ooShortRef(ooCheckOutInfoObj) &
ooShortRef(ooCheckOutInfoObj)::operator=(const ooRef(ooCheckOutInfoObj) &  id)
{
  this->ooShortId::operator=(id);
  return *this;
}
inline
ooShortRef(ooCheckOutInfoObj) &
ooShortRef(ooCheckOutInfoObj)::operator=(const ooHandleSuper(ooCheckOutInfoObj) &  objH)
{
  this->ooShortId::operator=(objH);
  return *this;
}
inline
ooShortRef(ooCheckOutInfoObj)&
ooShortRef(ooCheckOutInfoObj)::operator=(const ooCheckOutInfoObj *  fromObject)
{
  this->ooShortId::operator=(ooReinterpretCast(const ooObj *,fromObject));
  return *this;
}
inline
ooShortRef(ooCheckOutInfoObj)::ooShortRefStructor(ooCheckOutInfoObj)()
{
}
#ifdef OO_BUGGY_TEMPLATES
inline
ooShortRef(ooCheckOutInfoObj)::ooShortRefStructor(ooCheckOutInfoObj)(const ooShortRef(ooCheckOutInfoObj) &  shortId)
{
  *this = shortId;
}
#else // !defined(OO_BUGGY_TEMPLATES)
inline
ooShortRef(ooCheckOutInfoObj)::ooShortRefStructor(ooCheckOutInfoObj)(const ooShortRef(ooCheckOutInfoObj) &  shortId) :
    ooShortRef(ooObj)(shortId)
{
}
#endif // !defined(OO_BUGGY_TEMPLATES)
#ifdef OO_BUGGY_TEMPLATES
inline
ooShortRef(ooCheckOutInfoObj)::ooShortRefStructor(ooCheckOutInfoObj)(const ooRef(ooCheckOutInfoObj) &  id)
{
  *this = id;
}
#else // !defined(OO_BUGGY_TEMPLATES)
inline
ooShortRef(ooCheckOutInfoObj)::ooShortRefStructor(ooCheckOutInfoObj)(const ooRef(ooCheckOutInfoObj) &  id) :
    ooShortRef(ooObj)(id)
{
}
#endif // !defined(OO_BUGGY_TEMPLATES)
#ifdef OO_BUGGY_TEMPLATES
inline
ooShortRef(ooCheckOutInfoObj)::ooShortRefStructor(ooCheckOutInfoObj)(const ooHandleSuper(ooCheckOutInfoObj) &  objH)
{
  *this = objH;
}
#else // !defined(OO_BUGGY_TEMPLATES)
inline
ooShortRef(ooCheckOutInfoObj)::ooShortRefStructor(ooCheckOutInfoObj)(const ooHandleSuper(ooCheckOutInfoObj) &  objH) :
    ooShortRef(ooObj)(objH)
{
}
#endif // !defined(OO_BUGGY_TEMPLATES)
#ifdef OO_BUGGY_TEMPLATES
inline
ooShortRef(ooCheckOutInfoObj)::ooShortRefStructor(ooCheckOutInfoObj)(const ooCheckOutInfoObj *  fromObject)
{
  *this = fromObject;
}
#else // !defined(OO_BUGGY_TEMPLATES)
inline
ooShortRef(ooCheckOutInfoObj)::ooShortRefStructor(ooCheckOutInfoObj)(const ooCheckOutInfoObj *  fromObject) :
    ooShortRef(ooObj)(ooReinterpretCast(const ooObj *,fromObject))
{
}
#endif // !defined(OO_BUGGY_TEMPLATES)


/* methods on ooHandle(ooCheckOutInfoObj) */
inline
ooHandle(ooCheckOutInfoObj)::ooHandleStructor(ooCheckOutInfoObj)()
{
}
inline
ooHandle(ooCheckOutInfoObj)::ooHandleStructor(ooCheckOutInfoObj)(const ooHandle(ooCheckOutInfoObj) &  objH) :
#ifdef OO_BUGGY_TEMPLATES
    ooHandle_superclass<ooCheckOutInfoObj >(objH)
#else // !defined(OO_BUGGY_TEMPLATES)
    ooHandle(ooObj)(objH)
#endif // !defined(OO_BUGGY_TEMPLATES)
{
}
inline
ooHandle(ooCheckOutInfoObj)::ooHandleStructor(ooCheckOutInfoObj)(const ooRef(ooCheckOutInfoObj) &  id) :
#ifdef OO_BUGGY_TEMPLATES
    ooHandle_superclass<ooCheckOutInfoObj >(id)
#else // !defined(OO_BUGGY_TEMPLATES)
    ooHandle(ooObj)(id)
#endif // !defined(OO_BUGGY_TEMPLATES)
{
}
inline
ooHandle(ooCheckOutInfoObj)::ooHandleStructor(ooCheckOutInfoObj)(const ooCheckOutInfoObj *  fromObject) :
#ifdef OO_BUGGY_TEMPLATES
    ooHandle_superclass<ooCheckOutInfoObj >(ooReinterpretCast(const ooObj *,fromObject))
#else // !defined(OO_BUGGY_TEMPLATES)
    ooHandle(ooObj)(ooReinterpretCast(const ooObj *,fromObject))
#endif // !defined(OO_BUGGY_TEMPLATES)
{
}
inline
ooHandle(ooCheckOutInfoObj)&
ooHandle(ooCheckOutInfoObj)::operator=(const ooRef(ooCheckOutInfoObj) &  id)
{
  this->ooHandle(ooObj)::operator=(id);
  return *this;
}
inline
ooHandle(ooCheckOutInfoObj)&
ooHandle(ooCheckOutInfoObj)::operator=(const ooHandle(ooCheckOutInfoObj) &  objH)
{
  this->ooHandle(ooObj)::operator=(objH);
  return *this;
}
inline
ooHandle(ooCheckOutInfoObj)&
ooHandle(ooCheckOutInfoObj)::operator=(const ooShortRef(ooCheckOutInfoObj) &  shortId)
{
  this->ooHandle(ooObj)::operator=(shortId);
  return *this;
}
inline
ooHandle(ooCheckOutInfoObj)&
ooHandle(ooCheckOutInfoObj)::operator=(const ooCheckOutInfoObj *  fromObject)
{
  this->ooHandle(ooObj)::operator=(ooReinterpretCast(const ooObj *,fromObject));
  return *this;
}
inline
ooCheckOutInfoObj *
ooHandle(ooCheckOutInfoObj)::pin(ooMode  openMode) const
{
  return ooReinterpretCast(ooCheckOutInfoObj *, this->pin_obj_internal(openMode));
}
inline
ooCheckOutInfoObj *
ooHandle(ooCheckOutInfoObj)::operator->() const
{
  return this->vm();
}
inline
ooCheckOutInfoObj &
ooHandle(ooCheckOutInfoObj)::operator*() const
{
  return *(this->vm());
}
inline
ooHandle(ooCheckOutInfoObj)::operator ooCheckOutInfoObj *() const
{
  if ( _state == oocHandlePTR  )
    return ooReinterpretCast(ooCheckOutInfoObj *, _ptr._obj);
  else return ooReinterpretCast(ooCheckOutInfoObj *, this->get_vm());
}
inline
ooCheckOutInfoObj *
ooHandle(ooCheckOutInfoObj)::vm() const
{
  if ( _state == oocHandlePTR && _ptr._obj != NULL )
    return ooReinterpretCast(ooCheckOutInfoObj *, _ptr._obj);
  else return ooReinterpretCast(ooCheckOutInfoObj *, this->get_vm());
}
inline
ooRef(ooCheckOutInfoObj) &
ooHandle(ooCheckOutInfoObj)::copy(const ooHandle(ooObj) &  nearH,
		   ooRef(ooCheckOutInfoObj) &              result) const
{
  this->ooHandle(ooObj)::copy(nearH, result);
  return result;
}


/* ODMG methods */
inline
ooCheckOutInfoObj *
ooRef(ooCheckOutInfoObj)::ptr() const
{
  return this->pin();
}
inline
ooCheckOutInfoObj *
ooHandle(ooCheckOutInfoObj)::ptr() const
{
  return this->operator ooCheckOutInfoObj *();
}
class ooGeneObj;


/////////////////////////////////////////////////////////////////////////////

ooTemplateSpecialization
class ooDeref(ooGeneObj) : public ooDerefBase {
	friend class ooRef(ooGeneObj);
  public:
    ~ooDerefStructor(ooGeneObj)();
    inline ooGeneObj *operator->() const;
#ifndef OO_BUGGY_TEMPLATES
  private:
#endif // !defined(OO_BUGGY_TEMPLATES)
    ooDerefStructor(ooGeneObj)(ooDeref(ooGeneObj)& deref);
    ooDerefStructor(ooGeneObj)(ooObj *  fromObject);
};


#ifdef OO_BUGGY_TEMPLATES

class ooHandle_superclass<ooGeneObj > : public ooHandle(ooObj) {
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

class ooShortRef_superclass<ooGeneObj > : public ooShortRef(ooObj) {
};

#endif // OO_BUGGY_TEMPLATES

ooTemplateSpecialization
class ooRef(ooGeneObj) : public ooRef(ooObj) {
  public:
    ooRefStructor(ooGeneObj)()
      {}
    ooRefStructor(ooGeneObj)(const ooRef(ooGeneObj)& id) :
	  ooRef(ooObj)(id)
      {}
    inline ooRefStructor(ooGeneObj)(const ooHandleSuper(ooGeneObj)& objH);
    inline ooRefStructor(ooGeneObj)(const ooGeneObj *  fromObject);
    inline ooRef(ooGeneObj)& operator=(const ooRef(ooGeneObj)& id);
    inline ooRef(ooGeneObj)& operator=(const ooShortRefSuper(ooGeneObj) &shortId);
    inline ooRef(ooGeneObj)& operator=(const ooHandleSuper(ooGeneObj)& objH);
    inline ooRef(ooGeneObj)& operator=(const ooGeneObj *  fromObject);
    ooStatus lookupObj(const ooHandle(ooObj)& scopeH,
		       const ooKey& key,
		       ooMode openMode = oocRead);
    ooStatus lookupObj(const ooHandle(ooObj)& scopeH,
		       const char* name,
		       ooMode openMode = oocRead);
#ifndef OO_BUGGY_TEMPLATES
    inline ooRef(ooGeneObj)& copy(const ooHandle(ooObj)& nearH,
		    ooRef(ooGeneObj)& newObjRef) const;
    inline ooHandle(ooGeneObj)& copy(const ooHandle(ooObj)& nearH,
			ooHandle(ooGeneObj)& result) const;
    inline ooHandle(ooGeneObj) copy(const ooHandle(ooObj)& nearH) const;
#endif // !defined(OO_BUGGY_TEMPLATES)
    inline ooGeneObj *pin(ooMode openMode = oocRead) const;
    ooDeref(ooGeneObj) operator->() const;
    /* Use pin() or use ooHandle "operator ooGeneObj *" instead of vm. */
    /* OBSOLETE */ inline ooGeneObj *vm(ooMode openMode = oocRead) const;
    // ODMG methods:
    ooRefStructor(ooGeneObj)(const d_Ref_Any &from);
    ooGeneObj *ptr() const;
};

ooTemplateSpecialization
class ooShortRef(ooGeneObj) :
#ifdef OO_BUGGY_TEMPLATES
			public ooShortRef_superclass<ooGeneObj >
#else // !defined(OO_BUGGY_TEMPLATES)
			public ooShortRef(ooObj)
#endif // !defined(OO_BUGGY_TEMPLATES)
					            {
  public:
    ooShortRefStructor(ooGeneObj)();
    ooShortRefStructor(ooGeneObj)(const ooShortRef(ooGeneObj)& shortId);
    ooShortRefStructor(ooGeneObj)(const ooRef(ooGeneObj)& id);
    ooShortRefStructor(ooGeneObj)(const ooHandleSuper(ooGeneObj) &objH);
    ooShortRefStructor(ooGeneObj)(const ooGeneObj *  fromObject);
    ooShortRef(ooGeneObj)& operator=(const ooShortRef(ooGeneObj)& shortId);
    ooShortRef(ooGeneObj)& operator=(const ooRef(ooGeneObj)& id);
    ooShortRef(ooGeneObj)& operator=(const ooHandleSuper(ooGeneObj) &objH);
    ooShortRef(ooGeneObj)& operator=(const ooGeneObj *  fromObject);
};

ooTemplateSpecialization
class ooHandle(ooGeneObj) :
#ifdef OO_BUGGY_TEMPLATES
		      public ooHandle_superclass<ooGeneObj >
#else // !defined(OO_BUGGY_TEMPLATES)
		      public ooHandle(ooObj)
#endif // !defined(OO_BUGGY_TEMPLATES)
                                                {
  public:
    inline ooHandleStructor(ooGeneObj)();
    inline ooHandleStructor(ooGeneObj)(const ooRef(ooGeneObj)& id);
    inline ooHandleStructor(ooGeneObj)(const ooHandle(ooGeneObj)& objH);
    inline ooHandleStructor(ooGeneObj)(const ooGeneObj *  fromObject);
    inline ooHandle(ooGeneObj)& operator=(const ooRef(ooGeneObj)& id);
    inline ooHandle(ooGeneObj)& operator=(const ooHandle(ooGeneObj)& objH);
    inline ooHandle(ooGeneObj)& operator=(const ooShortRef(ooGeneObj)& shortId);
    inline ooHandle(ooGeneObj)& operator=(const ooGeneObj *  fromObject);
    ooStatus lookupObj(const ooHandle(ooObj)& scopeH,
		       const ooKey& key,
		       ooMode openMode = oocRead);
    ooStatus lookupObj(const ooHandle(ooObj)& scopeH,
		       const char* name,
		       ooMode openMode = oocRead);
    ooHandle(ooGeneObj)& copy(const ooHandle(ooObj)& nearH,
		       ooHandle(ooGeneObj)& result) const;
    inline ooRef(ooGeneObj)& copy(const ooHandle(ooObj)& nearH,
		    ooRef(ooGeneObj)& result) const;
    ooHandle(ooGeneObj) copy(const ooHandle(ooObj)& nearH) const;
    inline ooGeneObj *pin(ooMode openMode = oocRead) const;
    inline ooGeneObj *operator->() const;
    inline ooGeneObj &operator*() const;
    inline operator ooGeneObj *() const;
    /* Use "operator ooGeneObj *" instead of vm. */
    /* OBSOLETE */ inline ooGeneObj *vm() const;
    // ODMG methods:
    ooHandleStructor(ooGeneObj)(const d_Ref_Any &from);
    ooGeneObj *ptr() const;
};

ooTemplateSpecialization
class ooItr(ooGeneObj) : public ooHandle(ooGeneObj),
		    public ooIteratorObjOrContObj {
  public:
    ooItrStructor(ooGeneObj)();
    ~ooItrStructor(ooGeneObj)();
  private:
    // Defined only to prevent implicit definition:
    ooItrStructor(ooGeneObj)(ooItr(ooGeneObj)&);
    ooItr(ooGeneObj)    operator=(ooItr(ooGeneObj)&);
};


/* methods on ooDeref(ooGeneObj) */
inline
ooDeref(ooGeneObj)::ooDerefStructor(ooGeneObj)(ooDeref(ooGeneObj) &  deref) :
    ooDerefBase(deref.vm())
{
  this->pinCompensate();
}
inline
ooDeref(ooGeneObj)::ooDerefStructor(ooGeneObj)(ooObj *  fromObject) :
    ooDerefBase(fromObject)
{
}
inline
ooDeref(ooGeneObj)::~ooDerefStructor(ooGeneObj)()
{
}
inline
ooGeneObj *
ooDeref(ooGeneObj)::operator->() const
{
  return ooReinterpretCast(ooGeneObj *, this->vm());
}


/* methods on ooRef(ooGeneObj) */
inline
ooRef(ooGeneObj)::ooRefStructor(ooGeneObj)(const ooHandleSuper(ooGeneObj)& objH) :
    ooRef(ooObj)(objH)
{
}
inline
ooRef(ooGeneObj)::ooRefStructor(ooGeneObj)(const ooGeneObj *  fromObject) :
    ooRef(ooObj)(ooReinterpretCast(const ooObj *, fromObject))
{
}
inline
ooRef(ooGeneObj)&
ooRef(ooGeneObj)::operator=(const ooRef(ooGeneObj) &  id)
{
  this->ooId::operator=(id);
  return *this;
}
inline
ooRef(ooGeneObj)&
ooRef(ooGeneObj)::operator=(const ooShortRefSuper(ooGeneObj) &  shortId)
{
  this->ooRef(ooObj)::operator=(shortId);
  return *this;
}
inline
ooRef(ooGeneObj)&
ooRef(ooGeneObj)::operator=(const ooHandleSuper(ooGeneObj) &  objH)
{
  this->ooRef(ooObj)::operator=(objH);
  return *this;
}
inline
ooRef(ooGeneObj)&
ooRef(ooGeneObj)::operator=(const ooGeneObj *  fromObject)
{
  this->ooRef(ooObj)::operator=(ooReinterpretCast(const ooObj *, fromObject));
  return *this;
}
inline
ooGeneObj *
ooRef(ooGeneObj)::pin(ooMode  openMode) const
{
  return ooReinterpretCast(ooGeneObj *, this->pin_ref_internal(openMode));
}
inline
ooGeneObj *
ooRef(ooGeneObj)::vm(ooMode  openMode) const
{
  return this->pin(openMode);
}
#ifndef OO_BUGGY_TEMPLATES
inline
ooHandle(ooGeneObj) &
ooRef(ooGeneObj)::copy(const ooHandle(ooObj) &  nearH,
		ooHandle(ooGeneObj) &           result) const
{
  this->ooRef(ooObj)::copy(nearH, result);
  return result;
}
inline
ooRef(ooGeneObj) &
ooRef(ooGeneObj)::copy(const ooHandle(ooObj) &  nearH,
		ooRef(ooGeneObj) &              newObjRef) const
{
  this->ooRef(ooObj)::copy(nearH, newObjRef);
  return newObjRef;
}
inline
ooHandle(ooGeneObj)
ooRef(ooGeneObj)::copy(const ooHandle(ooObj) &  nearH) const
{
  ooHandle(ooGeneObj) result;
  this->ooRef(ooObj)::copy(nearH, result);
  return result;
}
#endif // !defined(OO_BUGGY_TEMPLATES)
inline
ooDeref(ooGeneObj)
ooRef(ooGeneObj)::operator->() const
{
  ooDeref(ooGeneObj) result(this->pin_ref_internal(oocRead));
  return result;
}


/* methods on ooShortRef(ooGeneObj) */
inline
ooShortRef(ooGeneObj) &
ooShortRef(ooGeneObj)::operator=(const ooShortRef(ooGeneObj) &  shortId)
{
  this->ooShortId::operator=(shortId);
  return *this;
}
inline
ooShortRef(ooGeneObj) &
ooShortRef(ooGeneObj)::operator=(const ooRef(ooGeneObj) &  id)
{
  this->ooShortId::operator=(id);
  return *this;
}
inline
ooShortRef(ooGeneObj) &
ooShortRef(ooGeneObj)::operator=(const ooHandleSuper(ooGeneObj) &  objH)
{
  this->ooShortId::operator=(objH);
  return *this;
}
inline
ooShortRef(ooGeneObj)&
ooShortRef(ooGeneObj)::operator=(const ooGeneObj *  fromObject)
{
  this->ooShortId::operator=(ooReinterpretCast(const ooObj *,fromObject));
  return *this;
}
inline
ooShortRef(ooGeneObj)::ooShortRefStructor(ooGeneObj)()
{
}
#ifdef OO_BUGGY_TEMPLATES
inline
ooShortRef(ooGeneObj)::ooShortRefStructor(ooGeneObj)(const ooShortRef(ooGeneObj) &  shortId)
{
  *this = shortId;
}
#else // !defined(OO_BUGGY_TEMPLATES)
inline
ooShortRef(ooGeneObj)::ooShortRefStructor(ooGeneObj)(const ooShortRef(ooGeneObj) &  shortId) :
    ooShortRef(ooObj)(shortId)
{
}
#endif // !defined(OO_BUGGY_TEMPLATES)
#ifdef OO_BUGGY_TEMPLATES
inline
ooShortRef(ooGeneObj)::ooShortRefStructor(ooGeneObj)(const ooRef(ooGeneObj) &  id)
{
  *this = id;
}
#else // !defined(OO_BUGGY_TEMPLATES)
inline
ooShortRef(ooGeneObj)::ooShortRefStructor(ooGeneObj)(const ooRef(ooGeneObj) &  id) :
    ooShortRef(ooObj)(id)
{
}
#endif // !defined(OO_BUGGY_TEMPLATES)
#ifdef OO_BUGGY_TEMPLATES
inline
ooShortRef(ooGeneObj)::ooShortRefStructor(ooGeneObj)(const ooHandleSuper(ooGeneObj) &  objH)
{
  *this = objH;
}
#else // !defined(OO_BUGGY_TEMPLATES)
inline
ooShortRef(ooGeneObj)::ooShortRefStructor(ooGeneObj)(const ooHandleSuper(ooGeneObj) &  objH) :
    ooShortRef(ooObj)(objH)
{
}
#endif // !defined(OO_BUGGY_TEMPLATES)
#ifdef OO_BUGGY_TEMPLATES
inline
ooShortRef(ooGeneObj)::ooShortRefStructor(ooGeneObj)(const ooGeneObj *  fromObject)
{
  *this = fromObject;
}
#else // !defined(OO_BUGGY_TEMPLATES)
inline
ooShortRef(ooGeneObj)::ooShortRefStructor(ooGeneObj)(const ooGeneObj *  fromObject) :
    ooShortRef(ooObj)(ooReinterpretCast(const ooObj *,fromObject))
{
}
#endif // !defined(OO_BUGGY_TEMPLATES)


/* methods on ooHandle(ooGeneObj) */
inline
ooHandle(ooGeneObj)::ooHandleStructor(ooGeneObj)()
{
}
inline
ooHandle(ooGeneObj)::ooHandleStructor(ooGeneObj)(const ooHandle(ooGeneObj) &  objH) :
#ifdef OO_BUGGY_TEMPLATES
    ooHandle_superclass<ooGeneObj >(objH)
#else // !defined(OO_BUGGY_TEMPLATES)
    ooHandle(ooObj)(objH)
#endif // !defined(OO_BUGGY_TEMPLATES)
{
}
inline
ooHandle(ooGeneObj)::ooHandleStructor(ooGeneObj)(const ooRef(ooGeneObj) &  id) :
#ifdef OO_BUGGY_TEMPLATES
    ooHandle_superclass<ooGeneObj >(id)
#else // !defined(OO_BUGGY_TEMPLATES)
    ooHandle(ooObj)(id)
#endif // !defined(OO_BUGGY_TEMPLATES)
{
}
inline
ooHandle(ooGeneObj)::ooHandleStructor(ooGeneObj)(const ooGeneObj *  fromObject) :
#ifdef OO_BUGGY_TEMPLATES
    ooHandle_superclass<ooGeneObj >(ooReinterpretCast(const ooObj *,fromObject))
#else // !defined(OO_BUGGY_TEMPLATES)
    ooHandle(ooObj)(ooReinterpretCast(const ooObj *,fromObject))
#endif // !defined(OO_BUGGY_TEMPLATES)
{
}
inline
ooHandle(ooGeneObj)&
ooHandle(ooGeneObj)::operator=(const ooRef(ooGeneObj) &  id)
{
  this->ooHandle(ooObj)::operator=(id);
  return *this;
}
inline
ooHandle(ooGeneObj)&
ooHandle(ooGeneObj)::operator=(const ooHandle(ooGeneObj) &  objH)
{
  this->ooHandle(ooObj)::operator=(objH);
  return *this;
}
inline
ooHandle(ooGeneObj)&
ooHandle(ooGeneObj)::operator=(const ooShortRef(ooGeneObj) &  shortId)
{
  this->ooHandle(ooObj)::operator=(shortId);
  return *this;
}
inline
ooHandle(ooGeneObj)&
ooHandle(ooGeneObj)::operator=(const ooGeneObj *  fromObject)
{
  this->ooHandle(ooObj)::operator=(ooReinterpretCast(const ooObj *,fromObject));
  return *this;
}
inline
ooGeneObj *
ooHandle(ooGeneObj)::pin(ooMode  openMode) const
{
  return ooReinterpretCast(ooGeneObj *, this->pin_obj_internal(openMode));
}
inline
ooGeneObj *
ooHandle(ooGeneObj)::operator->() const
{
  return this->vm();
}
inline
ooGeneObj &
ooHandle(ooGeneObj)::operator*() const
{
  return *(this->vm());
}
inline
ooHandle(ooGeneObj)::operator ooGeneObj *() const
{
  if ( _state == oocHandlePTR  )
    return ooReinterpretCast(ooGeneObj *, _ptr._obj);
  else return ooReinterpretCast(ooGeneObj *, this->get_vm());
}
inline
ooGeneObj *
ooHandle(ooGeneObj)::vm() const
{
  if ( _state == oocHandlePTR && _ptr._obj != NULL )
    return ooReinterpretCast(ooGeneObj *, _ptr._obj);
  else return ooReinterpretCast(ooGeneObj *, this->get_vm());
}
inline
ooRef(ooGeneObj) &
ooHandle(ooGeneObj)::copy(const ooHandle(ooObj) &  nearH,
		   ooRef(ooGeneObj) &              result) const
{
  this->ooHandle(ooObj)::copy(nearH, result);
  return result;
}


/* ODMG methods */
inline
ooGeneObj *
ooRef(ooGeneObj)::ptr() const
{
  return this->pin();
}
inline
ooGeneObj *
ooHandle(ooGeneObj)::ptr() const
{
  return this->operator ooGeneObj *();
}
class ooSysIndex;


/////////////////////////////////////////////////////////////////////////////

ooTemplateSpecialization
class ooDeref(ooSysIndex) : public ooDerefBase {
	friend class ooRef(ooSysIndex);
  public:
    ~ooDerefStructor(ooSysIndex)();
    inline ooSysIndex *operator->() const;
#ifndef OO_BUGGY_TEMPLATES
  private:
#endif // !defined(OO_BUGGY_TEMPLATES)
    ooDerefStructor(ooSysIndex)(ooDeref(ooSysIndex)& deref);
    ooDerefStructor(ooSysIndex)(ooObj *  fromObject);
};


#ifdef OO_BUGGY_TEMPLATES

class ooHandle_superclass<ooSysIndex > : public ooHandle(ooObj) {
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

class ooShortRef_superclass<ooSysIndex > : public ooShortRef(ooObj) {
};

#endif // OO_BUGGY_TEMPLATES

ooTemplateSpecialization
class ooRef(ooSysIndex) : public ooRef(ooObj) {
  public:
    ooRefStructor(ooSysIndex)()
      {}
    ooRefStructor(ooSysIndex)(const ooRef(ooSysIndex)& id) :
	  ooRef(ooObj)(id)
      {}
    inline ooRefStructor(ooSysIndex)(const ooHandleSuper(ooSysIndex)& objH);
    inline ooRefStructor(ooSysIndex)(const ooSysIndex *  fromObject);
    inline ooRef(ooSysIndex)& operator=(const ooRef(ooSysIndex)& id);
    inline ooRef(ooSysIndex)& operator=(const ooShortRefSuper(ooSysIndex) &shortId);
    inline ooRef(ooSysIndex)& operator=(const ooHandleSuper(ooSysIndex)& objH);
    inline ooRef(ooSysIndex)& operator=(const ooSysIndex *  fromObject);
    ooStatus lookupObj(const ooHandle(ooObj)& scopeH,
		       const ooKey& key,
		       ooMode openMode = oocRead);
    ooStatus lookupObj(const ooHandle(ooObj)& scopeH,
		       const char* name,
		       ooMode openMode = oocRead);
#ifndef OO_BUGGY_TEMPLATES
    inline ooRef(ooSysIndex)& copy(const ooHandle(ooObj)& nearH,
		    ooRef(ooSysIndex)& newObjRef) const;
    inline ooHandle(ooSysIndex)& copy(const ooHandle(ooObj)& nearH,
			ooHandle(ooSysIndex)& result) const;
    inline ooHandle(ooSysIndex) copy(const ooHandle(ooObj)& nearH) const;
#endif // !defined(OO_BUGGY_TEMPLATES)
    inline ooSysIndex *pin(ooMode openMode = oocRead) const;
    ooDeref(ooSysIndex) operator->() const;
    /* Use pin() or use ooHandle "operator ooSysIndex *" instead of vm. */
    /* OBSOLETE */ inline ooSysIndex *vm(ooMode openMode = oocRead) const;
    // ODMG methods:
    ooRefStructor(ooSysIndex)(const d_Ref_Any &from);
    ooSysIndex *ptr() const;
};

ooTemplateSpecialization
class ooShortRef(ooSysIndex) :
#ifdef OO_BUGGY_TEMPLATES
			public ooShortRef_superclass<ooSysIndex >
#else // !defined(OO_BUGGY_TEMPLATES)
			public ooShortRef(ooObj)
#endif // !defined(OO_BUGGY_TEMPLATES)
					            {
  public:
    ooShortRefStructor(ooSysIndex)();
    ooShortRefStructor(ooSysIndex)(const ooShortRef(ooSysIndex)& shortId);
    ooShortRefStructor(ooSysIndex)(const ooRef(ooSysIndex)& id);
    ooShortRefStructor(ooSysIndex)(const ooHandleSuper(ooSysIndex) &objH);
    ooShortRefStructor(ooSysIndex)(const ooSysIndex *  fromObject);
    ooShortRef(ooSysIndex)& operator=(const ooShortRef(ooSysIndex)& shortId);
    ooShortRef(ooSysIndex)& operator=(const ooRef(ooSysIndex)& id);
    ooShortRef(ooSysIndex)& operator=(const ooHandleSuper(ooSysIndex) &objH);
    ooShortRef(ooSysIndex)& operator=(const ooSysIndex *  fromObject);
};

ooTemplateSpecialization
class ooHandle(ooSysIndex) :
#ifdef OO_BUGGY_TEMPLATES
		      public ooHandle_superclass<ooSysIndex >
#else // !defined(OO_BUGGY_TEMPLATES)
		      public ooHandle(ooObj)
#endif // !defined(OO_BUGGY_TEMPLATES)
                                                {
  public:
    inline ooHandleStructor(ooSysIndex)();
    inline ooHandleStructor(ooSysIndex)(const ooRef(ooSysIndex)& id);
    inline ooHandleStructor(ooSysIndex)(const ooHandle(ooSysIndex)& objH);
    inline ooHandleStructor(ooSysIndex)(const ooSysIndex *  fromObject);
    inline ooHandle(ooSysIndex)& operator=(const ooRef(ooSysIndex)& id);
    inline ooHandle(ooSysIndex)& operator=(const ooHandle(ooSysIndex)& objH);
    inline ooHandle(ooSysIndex)& operator=(const ooShortRef(ooSysIndex)& shortId);
    inline ooHandle(ooSysIndex)& operator=(const ooSysIndex *  fromObject);
    ooStatus lookupObj(const ooHandle(ooObj)& scopeH,
		       const ooKey& key,
		       ooMode openMode = oocRead);
    ooStatus lookupObj(const ooHandle(ooObj)& scopeH,
		       const char* name,
		       ooMode openMode = oocRead);
    ooHandle(ooSysIndex)& copy(const ooHandle(ooObj)& nearH,
		       ooHandle(ooSysIndex)& result) const;
    inline ooRef(ooSysIndex)& copy(const ooHandle(ooObj)& nearH,
		    ooRef(ooSysIndex)& result) const;
    ooHandle(ooSysIndex) copy(const ooHandle(ooObj)& nearH) const;
    inline ooSysIndex *pin(ooMode openMode = oocRead) const;
    inline ooSysIndex *operator->() const;
    inline ooSysIndex &operator*() const;
    inline operator ooSysIndex *() const;
    /* Use "operator ooSysIndex *" instead of vm. */
    /* OBSOLETE */ inline ooSysIndex *vm() const;
    // ODMG methods:
    ooHandleStructor(ooSysIndex)(const d_Ref_Any &from);
    ooSysIndex *ptr() const;
};

ooTemplateSpecialization
class ooItr(ooSysIndex) : public ooHandle(ooSysIndex),
		    public ooIteratorObjOrContObj {
  public:
    ooItrStructor(ooSysIndex)();
    ~ooItrStructor(ooSysIndex)();
  private:
    // Defined only to prevent implicit definition:
    ooItrStructor(ooSysIndex)(ooItr(ooSysIndex)&);
    ooItr(ooSysIndex)    operator=(ooItr(ooSysIndex)&);
};


/* methods on ooDeref(ooSysIndex) */
inline
ooDeref(ooSysIndex)::ooDerefStructor(ooSysIndex)(ooDeref(ooSysIndex) &  deref) :
    ooDerefBase(deref.vm())
{
  this->pinCompensate();
}
inline
ooDeref(ooSysIndex)::ooDerefStructor(ooSysIndex)(ooObj *  fromObject) :
    ooDerefBase(fromObject)
{
}
inline
ooDeref(ooSysIndex)::~ooDerefStructor(ooSysIndex)()
{
}
inline
ooSysIndex *
ooDeref(ooSysIndex)::operator->() const
{
  return ooReinterpretCast(ooSysIndex *, this->vm());
}


/* methods on ooRef(ooSysIndex) */
inline
ooRef(ooSysIndex)::ooRefStructor(ooSysIndex)(const ooHandleSuper(ooSysIndex)& objH) :
    ooRef(ooObj)(objH)
{
}
inline
ooRef(ooSysIndex)::ooRefStructor(ooSysIndex)(const ooSysIndex *  fromObject) :
    ooRef(ooObj)(ooReinterpretCast(const ooObj *, fromObject))
{
}
inline
ooRef(ooSysIndex)&
ooRef(ooSysIndex)::operator=(const ooRef(ooSysIndex) &  id)
{
  this->ooId::operator=(id);
  return *this;
}
inline
ooRef(ooSysIndex)&
ooRef(ooSysIndex)::operator=(const ooShortRefSuper(ooSysIndex) &  shortId)
{
  this->ooRef(ooObj)::operator=(shortId);
  return *this;
}
inline
ooRef(ooSysIndex)&
ooRef(ooSysIndex)::operator=(const ooHandleSuper(ooSysIndex) &  objH)
{
  this->ooRef(ooObj)::operator=(objH);
  return *this;
}
inline
ooRef(ooSysIndex)&
ooRef(ooSysIndex)::operator=(const ooSysIndex *  fromObject)
{
  this->ooRef(ooObj)::operator=(ooReinterpretCast(const ooObj *, fromObject));
  return *this;
}
inline
ooSysIndex *
ooRef(ooSysIndex)::pin(ooMode  openMode) const
{
  return ooReinterpretCast(ooSysIndex *, this->pin_ref_internal(openMode));
}
inline
ooSysIndex *
ooRef(ooSysIndex)::vm(ooMode  openMode) const
{
  return this->pin(openMode);
}
#ifndef OO_BUGGY_TEMPLATES
inline
ooHandle(ooSysIndex) &
ooRef(ooSysIndex)::copy(const ooHandle(ooObj) &  nearH,
		ooHandle(ooSysIndex) &           result) const
{
  this->ooRef(ooObj)::copy(nearH, result);
  return result;
}
inline
ooRef(ooSysIndex) &
ooRef(ooSysIndex)::copy(const ooHandle(ooObj) &  nearH,
		ooRef(ooSysIndex) &              newObjRef) const
{
  this->ooRef(ooObj)::copy(nearH, newObjRef);
  return newObjRef;
}
inline
ooHandle(ooSysIndex)
ooRef(ooSysIndex)::copy(const ooHandle(ooObj) &  nearH) const
{
  ooHandle(ooSysIndex) result;
  this->ooRef(ooObj)::copy(nearH, result);
  return result;
}
#endif // !defined(OO_BUGGY_TEMPLATES)
inline
ooDeref(ooSysIndex)
ooRef(ooSysIndex)::operator->() const
{
  ooDeref(ooSysIndex) result(this->pin_ref_internal(oocRead));
  return result;
}


/* methods on ooShortRef(ooSysIndex) */
inline
ooShortRef(ooSysIndex) &
ooShortRef(ooSysIndex)::operator=(const ooShortRef(ooSysIndex) &  shortId)
{
  this->ooShortId::operator=(shortId);
  return *this;
}
inline
ooShortRef(ooSysIndex) &
ooShortRef(ooSysIndex)::operator=(const ooRef(ooSysIndex) &  id)
{
  this->ooShortId::operator=(id);
  return *this;
}
inline
ooShortRef(ooSysIndex) &
ooShortRef(ooSysIndex)::operator=(const ooHandleSuper(ooSysIndex) &  objH)
{
  this->ooShortId::operator=(objH);
  return *this;
}
inline
ooShortRef(ooSysIndex)&
ooShortRef(ooSysIndex)::operator=(const ooSysIndex *  fromObject)
{
  this->ooShortId::operator=(ooReinterpretCast(const ooObj *,fromObject));
  return *this;
}
inline
ooShortRef(ooSysIndex)::ooShortRefStructor(ooSysIndex)()
{
}
#ifdef OO_BUGGY_TEMPLATES
inline
ooShortRef(ooSysIndex)::ooShortRefStructor(ooSysIndex)(const ooShortRef(ooSysIndex) &  shortId)
{
  *this = shortId;
}
#else // !defined(OO_BUGGY_TEMPLATES)
inline
ooShortRef(ooSysIndex)::ooShortRefStructor(ooSysIndex)(const ooShortRef(ooSysIndex) &  shortId) :
    ooShortRef(ooObj)(shortId)
{
}
#endif // !defined(OO_BUGGY_TEMPLATES)
#ifdef OO_BUGGY_TEMPLATES
inline
ooShortRef(ooSysIndex)::ooShortRefStructor(ooSysIndex)(const ooRef(ooSysIndex) &  id)
{
  *this = id;
}
#else // !defined(OO_BUGGY_TEMPLATES)
inline
ooShortRef(ooSysIndex)::ooShortRefStructor(ooSysIndex)(const ooRef(ooSysIndex) &  id) :
    ooShortRef(ooObj)(id)
{
}
#endif // !defined(OO_BUGGY_TEMPLATES)
#ifdef OO_BUGGY_TEMPLATES
inline
ooShortRef(ooSysIndex)::ooShortRefStructor(ooSysIndex)(const ooHandleSuper(ooSysIndex) &  objH)
{
  *this = objH;
}
#else // !defined(OO_BUGGY_TEMPLATES)
inline
ooShortRef(ooSysIndex)::ooShortRefStructor(ooSysIndex)(const ooHandleSuper(ooSysIndex) &  objH) :
    ooShortRef(ooObj)(objH)
{
}
#endif // !defined(OO_BUGGY_TEMPLATES)
#ifdef OO_BUGGY_TEMPLATES
inline
ooShortRef(ooSysIndex)::ooShortRefStructor(ooSysIndex)(const ooSysIndex *  fromObject)
{
  *this = fromObject;
}
#else // !defined(OO_BUGGY_TEMPLATES)
inline
ooShortRef(ooSysIndex)::ooShortRefStructor(ooSysIndex)(const ooSysIndex *  fromObject) :
    ooShortRef(ooObj)(ooReinterpretCast(const ooObj *,fromObject))
{
}
#endif // !defined(OO_BUGGY_TEMPLATES)


/* methods on ooHandle(ooSysIndex) */
inline
ooHandle(ooSysIndex)::ooHandleStructor(ooSysIndex)()
{
}
inline
ooHandle(ooSysIndex)::ooHandleStructor(ooSysIndex)(const ooHandle(ooSysIndex) &  objH) :
#ifdef OO_BUGGY_TEMPLATES
    ooHandle_superclass<ooSysIndex >(objH)
#else // !defined(OO_BUGGY_TEMPLATES)
    ooHandle(ooObj)(objH)
#endif // !defined(OO_BUGGY_TEMPLATES)
{
}
inline
ooHandle(ooSysIndex)::ooHandleStructor(ooSysIndex)(const ooRef(ooSysIndex) &  id) :
#ifdef OO_BUGGY_TEMPLATES
    ooHandle_superclass<ooSysIndex >(id)
#else // !defined(OO_BUGGY_TEMPLATES)
    ooHandle(ooObj)(id)
#endif // !defined(OO_BUGGY_TEMPLATES)
{
}
inline
ooHandle(ooSysIndex)::ooHandleStructor(ooSysIndex)(const ooSysIndex *  fromObject) :
#ifdef OO_BUGGY_TEMPLATES
    ooHandle_superclass<ooSysIndex >(ooReinterpretCast(const ooObj *,fromObject))
#else // !defined(OO_BUGGY_TEMPLATES)
    ooHandle(ooObj)(ooReinterpretCast(const ooObj *,fromObject))
#endif // !defined(OO_BUGGY_TEMPLATES)
{
}
inline
ooHandle(ooSysIndex)&
ooHandle(ooSysIndex)::operator=(const ooRef(ooSysIndex) &  id)
{
  this->ooHandle(ooObj)::operator=(id);
  return *this;
}
inline
ooHandle(ooSysIndex)&
ooHandle(ooSysIndex)::operator=(const ooHandle(ooSysIndex) &  objH)
{
  this->ooHandle(ooObj)::operator=(objH);
  return *this;
}
inline
ooHandle(ooSysIndex)&
ooHandle(ooSysIndex)::operator=(const ooShortRef(ooSysIndex) &  shortId)
{
  this->ooHandle(ooObj)::operator=(shortId);
  return *this;
}
inline
ooHandle(ooSysIndex)&
ooHandle(ooSysIndex)::operator=(const ooSysIndex *  fromObject)
{
  this->ooHandle(ooObj)::operator=(ooReinterpretCast(const ooObj *,fromObject));
  return *this;
}
inline
ooSysIndex *
ooHandle(ooSysIndex)::pin(ooMode  openMode) const
{
  return ooReinterpretCast(ooSysIndex *, this->pin_obj_internal(openMode));
}
inline
ooSysIndex *
ooHandle(ooSysIndex)::operator->() const
{
  return this->vm();
}
inline
ooSysIndex &
ooHandle(ooSysIndex)::operator*() const
{
  return *(this->vm());
}
inline
ooHandle(ooSysIndex)::operator ooSysIndex *() const
{
  if ( _state == oocHandlePTR  )
    return ooReinterpretCast(ooSysIndex *, _ptr._obj);
  else return ooReinterpretCast(ooSysIndex *, this->get_vm());
}
inline
ooSysIndex *
ooHandle(ooSysIndex)::vm() const
{
  if ( _state == oocHandlePTR && _ptr._obj != NULL )
    return ooReinterpretCast(ooSysIndex *, _ptr._obj);
  else return ooReinterpretCast(ooSysIndex *, this->get_vm());
}
inline
ooRef(ooSysIndex) &
ooHandle(ooSysIndex)::copy(const ooHandle(ooObj) &  nearH,
		   ooRef(ooSysIndex) &              result) const
{
  this->ooHandle(ooObj)::copy(nearH, result);
  return result;
}


/* ODMG methods */
inline
ooSysIndex *
ooRef(ooSysIndex)::ptr() const
{
  return this->pin();
}
inline
ooSysIndex *
ooHandle(ooSysIndex)::ptr() const
{
  return this->operator ooSysIndex *();
}
class ooVStringHolder;


/////////////////////////////////////////////////////////////////////////////

ooTemplateSpecialization
class ooDeref(ooVStringHolder) : public ooDerefBase {
	friend class ooRef(ooVStringHolder);
  public:
    ~ooDerefStructor(ooVStringHolder)();
    inline ooVStringHolder *operator->() const;
#ifndef OO_BUGGY_TEMPLATES
  private:
#endif // !defined(OO_BUGGY_TEMPLATES)
    ooDerefStructor(ooVStringHolder)(ooDeref(ooVStringHolder)& deref);
    ooDerefStructor(ooVStringHolder)(ooObj *  fromObject);
};


#ifdef OO_BUGGY_TEMPLATES

class ooHandle_superclass<ooVStringHolder > : public ooHandle(ooObj) {
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

class ooShortRef_superclass<ooVStringHolder > : public ooShortRef(ooObj) {
};

#endif // OO_BUGGY_TEMPLATES

ooTemplateSpecialization
class ooRef(ooVStringHolder) : public ooRef(ooObj) {
  public:
    ooRefStructor(ooVStringHolder)()
      {}
    ooRefStructor(ooVStringHolder)(const ooRef(ooVStringHolder)& id) :
	  ooRef(ooObj)(id)
      {}
    inline ooRefStructor(ooVStringHolder)(const ooHandleSuper(ooVStringHolder)& objH);
    inline ooRefStructor(ooVStringHolder)(const ooVStringHolder *  fromObject);
    inline ooRef(ooVStringHolder)& operator=(const ooRef(ooVStringHolder)& id);
    inline ooRef(ooVStringHolder)& operator=(const ooShortRefSuper(ooVStringHolder) &shortId);
    inline ooRef(ooVStringHolder)& operator=(const ooHandleSuper(ooVStringHolder)& objH);
    inline ooRef(ooVStringHolder)& operator=(const ooVStringHolder *  fromObject);
    ooStatus lookupObj(const ooHandle(ooObj)& scopeH,
		       const ooKey& key,
		       ooMode openMode = oocRead);
    ooStatus lookupObj(const ooHandle(ooObj)& scopeH,
		       const char* name,
		       ooMode openMode = oocRead);
#ifndef OO_BUGGY_TEMPLATES
    inline ooRef(ooVStringHolder)& copy(const ooHandle(ooObj)& nearH,
		    ooRef(ooVStringHolder)& newObjRef) const;
    inline ooHandle(ooVStringHolder)& copy(const ooHandle(ooObj)& nearH,
			ooHandle(ooVStringHolder)& result) const;
    inline ooHandle(ooVStringHolder) copy(const ooHandle(ooObj)& nearH) const;
#endif // !defined(OO_BUGGY_TEMPLATES)
    inline ooVStringHolder *pin(ooMode openMode = oocRead) const;
    ooDeref(ooVStringHolder) operator->() const;
    /* Use pin() or use ooHandle "operator ooVStringHolder *" instead of vm. */
    /* OBSOLETE */ inline ooVStringHolder *vm(ooMode openMode = oocRead) const;
    // ODMG methods:
    ooRefStructor(ooVStringHolder)(const d_Ref_Any &from);
    ooVStringHolder *ptr() const;
};

ooTemplateSpecialization
class ooShortRef(ooVStringHolder) :
#ifdef OO_BUGGY_TEMPLATES
			public ooShortRef_superclass<ooVStringHolder >
#else // !defined(OO_BUGGY_TEMPLATES)
			public ooShortRef(ooObj)
#endif // !defined(OO_BUGGY_TEMPLATES)
					            {
  public:
    ooShortRefStructor(ooVStringHolder)();
    ooShortRefStructor(ooVStringHolder)(const ooShortRef(ooVStringHolder)& shortId);
    ooShortRefStructor(ooVStringHolder)(const ooRef(ooVStringHolder)& id);
    ooShortRefStructor(ooVStringHolder)(const ooHandleSuper(ooVStringHolder) &objH);
    ooShortRefStructor(ooVStringHolder)(const ooVStringHolder *  fromObject);
    ooShortRef(ooVStringHolder)& operator=(const ooShortRef(ooVStringHolder)& shortId);
    ooShortRef(ooVStringHolder)& operator=(const ooRef(ooVStringHolder)& id);
    ooShortRef(ooVStringHolder)& operator=(const ooHandleSuper(ooVStringHolder) &objH);
    ooShortRef(ooVStringHolder)& operator=(const ooVStringHolder *  fromObject);
};

ooTemplateSpecialization
class ooHandle(ooVStringHolder) :
#ifdef OO_BUGGY_TEMPLATES
		      public ooHandle_superclass<ooVStringHolder >
#else // !defined(OO_BUGGY_TEMPLATES)
		      public ooHandle(ooObj)
#endif // !defined(OO_BUGGY_TEMPLATES)
                                                {
  public:
    inline ooHandleStructor(ooVStringHolder)();
    inline ooHandleStructor(ooVStringHolder)(const ooRef(ooVStringHolder)& id);
    inline ooHandleStructor(ooVStringHolder)(const ooHandle(ooVStringHolder)& objH);
    inline ooHandleStructor(ooVStringHolder)(const ooVStringHolder *  fromObject);
    inline ooHandle(ooVStringHolder)& operator=(const ooRef(ooVStringHolder)& id);
    inline ooHandle(ooVStringHolder)& operator=(const ooHandle(ooVStringHolder)& objH);
    inline ooHandle(ooVStringHolder)& operator=(const ooShortRef(ooVStringHolder)& shortId);
    inline ooHandle(ooVStringHolder)& operator=(const ooVStringHolder *  fromObject);
    ooStatus lookupObj(const ooHandle(ooObj)& scopeH,
		       const ooKey& key,
		       ooMode openMode = oocRead);
    ooStatus lookupObj(const ooHandle(ooObj)& scopeH,
		       const char* name,
		       ooMode openMode = oocRead);
    ooHandle(ooVStringHolder)& copy(const ooHandle(ooObj)& nearH,
		       ooHandle(ooVStringHolder)& result) const;
    inline ooRef(ooVStringHolder)& copy(const ooHandle(ooObj)& nearH,
		    ooRef(ooVStringHolder)& result) const;
    ooHandle(ooVStringHolder) copy(const ooHandle(ooObj)& nearH) const;
    inline ooVStringHolder *pin(ooMode openMode = oocRead) const;
    inline ooVStringHolder *operator->() const;
    inline ooVStringHolder &operator*() const;
    inline operator ooVStringHolder *() const;
    /* Use "operator ooVStringHolder *" instead of vm. */
    /* OBSOLETE */ inline ooVStringHolder *vm() const;
    // ODMG methods:
    ooHandleStructor(ooVStringHolder)(const d_Ref_Any &from);
    ooVStringHolder *ptr() const;
};

ooTemplateSpecialization
class ooItr(ooVStringHolder) : public ooHandle(ooVStringHolder),
		    public ooIteratorObjOrContObj {
  public:
    ooItrStructor(ooVStringHolder)();
    ~ooItrStructor(ooVStringHolder)();
  private:
    // Defined only to prevent implicit definition:
    ooItrStructor(ooVStringHolder)(ooItr(ooVStringHolder)&);
    ooItr(ooVStringHolder)    operator=(ooItr(ooVStringHolder)&);
};


/* methods on ooDeref(ooVStringHolder) */
inline
ooDeref(ooVStringHolder)::ooDerefStructor(ooVStringHolder)(ooDeref(ooVStringHolder) &  deref) :
    ooDerefBase(deref.vm())
{
  this->pinCompensate();
}
inline
ooDeref(ooVStringHolder)::ooDerefStructor(ooVStringHolder)(ooObj *  fromObject) :
    ooDerefBase(fromObject)
{
}
inline
ooDeref(ooVStringHolder)::~ooDerefStructor(ooVStringHolder)()
{
}
inline
ooVStringHolder *
ooDeref(ooVStringHolder)::operator->() const
{
  return ooReinterpretCast(ooVStringHolder *, this->vm());
}


/* methods on ooRef(ooVStringHolder) */
inline
ooRef(ooVStringHolder)::ooRefStructor(ooVStringHolder)(const ooHandleSuper(ooVStringHolder)& objH) :
    ooRef(ooObj)(objH)
{
}
inline
ooRef(ooVStringHolder)::ooRefStructor(ooVStringHolder)(const ooVStringHolder *  fromObject) :
    ooRef(ooObj)(ooReinterpretCast(const ooObj *, fromObject))
{
}
inline
ooRef(ooVStringHolder)&
ooRef(ooVStringHolder)::operator=(const ooRef(ooVStringHolder) &  id)
{
  this->ooId::operator=(id);
  return *this;
}
inline
ooRef(ooVStringHolder)&
ooRef(ooVStringHolder)::operator=(const ooShortRefSuper(ooVStringHolder) &  shortId)
{
  this->ooRef(ooObj)::operator=(shortId);
  return *this;
}
inline
ooRef(ooVStringHolder)&
ooRef(ooVStringHolder)::operator=(const ooHandleSuper(ooVStringHolder) &  objH)
{
  this->ooRef(ooObj)::operator=(objH);
  return *this;
}
inline
ooRef(ooVStringHolder)&
ooRef(ooVStringHolder)::operator=(const ooVStringHolder *  fromObject)
{
  this->ooRef(ooObj)::operator=(ooReinterpretCast(const ooObj *, fromObject));
  return *this;
}
inline
ooVStringHolder *
ooRef(ooVStringHolder)::pin(ooMode  openMode) const
{
  return ooReinterpretCast(ooVStringHolder *, this->pin_ref_internal(openMode));
}
inline
ooVStringHolder *
ooRef(ooVStringHolder)::vm(ooMode  openMode) const
{
  return this->pin(openMode);
}
#ifndef OO_BUGGY_TEMPLATES
inline
ooHandle(ooVStringHolder) &
ooRef(ooVStringHolder)::copy(const ooHandle(ooObj) &  nearH,
		ooHandle(ooVStringHolder) &           result) const
{
  this->ooRef(ooObj)::copy(nearH, result);
  return result;
}
inline
ooRef(ooVStringHolder) &
ooRef(ooVStringHolder)::copy(const ooHandle(ooObj) &  nearH,
		ooRef(ooVStringHolder) &              newObjRef) const
{
  this->ooRef(ooObj)::copy(nearH, newObjRef);
  return newObjRef;
}
inline
ooHandle(ooVStringHolder)
ooRef(ooVStringHolder)::copy(const ooHandle(ooObj) &  nearH) const
{
  ooHandle(ooVStringHolder) result;
  this->ooRef(ooObj)::copy(nearH, result);
  return result;
}
#endif // !defined(OO_BUGGY_TEMPLATES)
inline
ooDeref(ooVStringHolder)
ooRef(ooVStringHolder)::operator->() const
{
  ooDeref(ooVStringHolder) result(this->pin_ref_internal(oocRead));
  return result;
}


/* methods on ooShortRef(ooVStringHolder) */
inline
ooShortRef(ooVStringHolder) &
ooShortRef(ooVStringHolder)::operator=(const ooShortRef(ooVStringHolder) &  shortId)
{
  this->ooShortId::operator=(shortId);
  return *this;
}
inline
ooShortRef(ooVStringHolder) &
ooShortRef(ooVStringHolder)::operator=(const ooRef(ooVStringHolder) &  id)
{
  this->ooShortId::operator=(id);
  return *this;
}
inline
ooShortRef(ooVStringHolder) &
ooShortRef(ooVStringHolder)::operator=(const ooHandleSuper(ooVStringHolder) &  objH)
{
  this->ooShortId::operator=(objH);
  return *this;
}
inline
ooShortRef(ooVStringHolder)&
ooShortRef(ooVStringHolder)::operator=(const ooVStringHolder *  fromObject)
{
  this->ooShortId::operator=(ooReinterpretCast(const ooObj *,fromObject));
  return *this;
}
inline
ooShortRef(ooVStringHolder)::ooShortRefStructor(ooVStringHolder)()
{
}
#ifdef OO_BUGGY_TEMPLATES
inline
ooShortRef(ooVStringHolder)::ooShortRefStructor(ooVStringHolder)(const ooShortRef(ooVStringHolder) &  shortId)
{
  *this = shortId;
}
#else // !defined(OO_BUGGY_TEMPLATES)
inline
ooShortRef(ooVStringHolder)::ooShortRefStructor(ooVStringHolder)(const ooShortRef(ooVStringHolder) &  shortId) :
    ooShortRef(ooObj)(shortId)
{
}
#endif // !defined(OO_BUGGY_TEMPLATES)
#ifdef OO_BUGGY_TEMPLATES
inline
ooShortRef(ooVStringHolder)::ooShortRefStructor(ooVStringHolder)(const ooRef(ooVStringHolder) &  id)
{
  *this = id;
}
#else // !defined(OO_BUGGY_TEMPLATES)
inline
ooShortRef(ooVStringHolder)::ooShortRefStructor(ooVStringHolder)(const ooRef(ooVStringHolder) &  id) :
    ooShortRef(ooObj)(id)
{
}
#endif // !defined(OO_BUGGY_TEMPLATES)
#ifdef OO_BUGGY_TEMPLATES
inline
ooShortRef(ooVStringHolder)::ooShortRefStructor(ooVStringHolder)(const ooHandleSuper(ooVStringHolder) &  objH)
{
  *this = objH;
}
#else // !defined(OO_BUGGY_TEMPLATES)
inline
ooShortRef(ooVStringHolder)::ooShortRefStructor(ooVStringHolder)(const ooHandleSuper(ooVStringHolder) &  objH) :
    ooShortRef(ooObj)(objH)
{
}
#endif // !defined(OO_BUGGY_TEMPLATES)
#ifdef OO_BUGGY_TEMPLATES
inline
ooShortRef(ooVStringHolder)::ooShortRefStructor(ooVStringHolder)(const ooVStringHolder *  fromObject)
{
  *this = fromObject;
}
#else // !defined(OO_BUGGY_TEMPLATES)
inline
ooShortRef(ooVStringHolder)::ooShortRefStructor(ooVStringHolder)(const ooVStringHolder *  fromObject) :
    ooShortRef(ooObj)(ooReinterpretCast(const ooObj *,fromObject))
{
}
#endif // !defined(OO_BUGGY_TEMPLATES)


/* methods on ooHandle(ooVStringHolder) */
inline
ooHandle(ooVStringHolder)::ooHandleStructor(ooVStringHolder)()
{
}
inline
ooHandle(ooVStringHolder)::ooHandleStructor(ooVStringHolder)(const ooHandle(ooVStringHolder) &  objH) :
#ifdef OO_BUGGY_TEMPLATES
    ooHandle_superclass<ooVStringHolder >(objH)
#else // !defined(OO_BUGGY_TEMPLATES)
    ooHandle(ooObj)(objH)
#endif // !defined(OO_BUGGY_TEMPLATES)
{
}
inline
ooHandle(ooVStringHolder)::ooHandleStructor(ooVStringHolder)(const ooRef(ooVStringHolder) &  id) :
#ifdef OO_BUGGY_TEMPLATES
    ooHandle_superclass<ooVStringHolder >(id)
#else // !defined(OO_BUGGY_TEMPLATES)
    ooHandle(ooObj)(id)
#endif // !defined(OO_BUGGY_TEMPLATES)
{
}
inline
ooHandle(ooVStringHolder)::ooHandleStructor(ooVStringHolder)(const ooVStringHolder *  fromObject) :
#ifdef OO_BUGGY_TEMPLATES
    ooHandle_superclass<ooVStringHolder >(ooReinterpretCast(const ooObj *,fromObject))
#else // !defined(OO_BUGGY_TEMPLATES)
    ooHandle(ooObj)(ooReinterpretCast(const ooObj *,fromObject))
#endif // !defined(OO_BUGGY_TEMPLATES)
{
}
inline
ooHandle(ooVStringHolder)&
ooHandle(ooVStringHolder)::operator=(const ooRef(ooVStringHolder) &  id)
{
  this->ooHandle(ooObj)::operator=(id);
  return *this;
}
inline
ooHandle(ooVStringHolder)&
ooHandle(ooVStringHolder)::operator=(const ooHandle(ooVStringHolder) &  objH)
{
  this->ooHandle(ooObj)::operator=(objH);
  return *this;
}
inline
ooHandle(ooVStringHolder)&
ooHandle(ooVStringHolder)::operator=(const ooShortRef(ooVStringHolder) &  shortId)
{
  this->ooHandle(ooObj)::operator=(shortId);
  return *this;
}
inline
ooHandle(ooVStringHolder)&
ooHandle(ooVStringHolder)::operator=(const ooVStringHolder *  fromObject)
{
  this->ooHandle(ooObj)::operator=(ooReinterpretCast(const ooObj *,fromObject));
  return *this;
}
inline
ooVStringHolder *
ooHandle(ooVStringHolder)::pin(ooMode  openMode) const
{
  return ooReinterpretCast(ooVStringHolder *, this->pin_obj_internal(openMode));
}
inline
ooVStringHolder *
ooHandle(ooVStringHolder)::operator->() const
{
  return this->vm();
}
inline
ooVStringHolder &
ooHandle(ooVStringHolder)::operator*() const
{
  return *(this->vm());
}
inline
ooHandle(ooVStringHolder)::operator ooVStringHolder *() const
{
  if ( _state == oocHandlePTR  )
    return ooReinterpretCast(ooVStringHolder *, _ptr._obj);
  else return ooReinterpretCast(ooVStringHolder *, this->get_vm());
}
inline
ooVStringHolder *
ooHandle(ooVStringHolder)::vm() const
{
  if ( _state == oocHandlePTR && _ptr._obj != NULL )
    return ooReinterpretCast(ooVStringHolder *, _ptr._obj);
  else return ooReinterpretCast(ooVStringHolder *, this->get_vm());
}
inline
ooRef(ooVStringHolder) &
ooHandle(ooVStringHolder)::copy(const ooHandle(ooObj) &  nearH,
		   ooRef(ooVStringHolder) &              result) const
{
  this->ooHandle(ooObj)::copy(nearH, result);
  return result;
}


/* ODMG methods */
inline
ooVStringHolder *
ooRef(ooVStringHolder)::ptr() const
{
  return this->pin();
}
inline
ooVStringHolder *
ooHandle(ooVStringHolder)::ptr() const
{
  return this->operator ooVStringHolder *();
}
class ooUtf8StringHolder;


/////////////////////////////////////////////////////////////////////////////

ooTemplateSpecialization
class ooDeref(ooUtf8StringHolder) : public ooDerefBase {
	friend class ooRef(ooUtf8StringHolder);
  public:
    ~ooDerefStructor(ooUtf8StringHolder)();
    inline ooUtf8StringHolder *operator->() const;
#ifndef OO_BUGGY_TEMPLATES
  private:
#endif // !defined(OO_BUGGY_TEMPLATES)
    ooDerefStructor(ooUtf8StringHolder)(ooDeref(ooUtf8StringHolder)& deref);
    ooDerefStructor(ooUtf8StringHolder)(ooObj *  fromObject);
};


#ifdef OO_BUGGY_TEMPLATES

class ooHandle_superclass<ooUtf8StringHolder > : public ooHandle(ooObj) {
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

class ooShortRef_superclass<ooUtf8StringHolder > : public ooShortRef(ooObj) {
};

#endif // OO_BUGGY_TEMPLATES

ooTemplateSpecialization
class ooRef(ooUtf8StringHolder) : public ooRef(ooObj) {
  public:
    ooRefStructor(ooUtf8StringHolder)()
      {}
    ooRefStructor(ooUtf8StringHolder)(const ooRef(ooUtf8StringHolder)& id) :
	  ooRef(ooObj)(id)
      {}
    inline ooRefStructor(ooUtf8StringHolder)(const ooHandleSuper(ooUtf8StringHolder)& objH);
    inline ooRefStructor(ooUtf8StringHolder)(const ooUtf8StringHolder *  fromObject);
    inline ooRef(ooUtf8StringHolder)& operator=(const ooRef(ooUtf8StringHolder)& id);
    inline ooRef(ooUtf8StringHolder)& operator=(const ooShortRefSuper(ooUtf8StringHolder) &shortId);
    inline ooRef(ooUtf8StringHolder)& operator=(const ooHandleSuper(ooUtf8StringHolder)& objH);
    inline ooRef(ooUtf8StringHolder)& operator=(const ooUtf8StringHolder *  fromObject);
    ooStatus lookupObj(const ooHandle(ooObj)& scopeH,
		       const ooKey& key,
		       ooMode openMode = oocRead);
    ooStatus lookupObj(const ooHandle(ooObj)& scopeH,
		       const char* name,
		       ooMode openMode = oocRead);
#ifndef OO_BUGGY_TEMPLATES
    inline ooRef(ooUtf8StringHolder)& copy(const ooHandle(ooObj)& nearH,
		    ooRef(ooUtf8StringHolder)& newObjRef) const;
    inline ooHandle(ooUtf8StringHolder)& copy(const ooHandle(ooObj)& nearH,
			ooHandle(ooUtf8StringHolder)& result) const;
    inline ooHandle(ooUtf8StringHolder) copy(const ooHandle(ooObj)& nearH) const;
#endif // !defined(OO_BUGGY_TEMPLATES)
    inline ooUtf8StringHolder *pin(ooMode openMode = oocRead) const;
    ooDeref(ooUtf8StringHolder) operator->() const;
    /* Use pin() or use ooHandle "operator ooUtf8StringHolder *" instead of vm. */
    /* OBSOLETE */ inline ooUtf8StringHolder *vm(ooMode openMode = oocRead) const;
    // ODMG methods:
    ooRefStructor(ooUtf8StringHolder)(const d_Ref_Any &from);
    ooUtf8StringHolder *ptr() const;
};

ooTemplateSpecialization
class ooShortRef(ooUtf8StringHolder) :
#ifdef OO_BUGGY_TEMPLATES
			public ooShortRef_superclass<ooUtf8StringHolder >
#else // !defined(OO_BUGGY_TEMPLATES)
			public ooShortRef(ooObj)
#endif // !defined(OO_BUGGY_TEMPLATES)
					            {
  public:
    ooShortRefStructor(ooUtf8StringHolder)();
    ooShortRefStructor(ooUtf8StringHolder)(const ooShortRef(ooUtf8StringHolder)& shortId);
    ooShortRefStructor(ooUtf8StringHolder)(const ooRef(ooUtf8StringHolder)& id);
    ooShortRefStructor(ooUtf8StringHolder)(const ooHandleSuper(ooUtf8StringHolder) &objH);
    ooShortRefStructor(ooUtf8StringHolder)(const ooUtf8StringHolder *  fromObject);
    ooShortRef(ooUtf8StringHolder)& operator=(const ooShortRef(ooUtf8StringHolder)& shortId);
    ooShortRef(ooUtf8StringHolder)& operator=(const ooRef(ooUtf8StringHolder)& id);
    ooShortRef(ooUtf8StringHolder)& operator=(const ooHandleSuper(ooUtf8StringHolder) &objH);
    ooShortRef(ooUtf8StringHolder)& operator=(const ooUtf8StringHolder *  fromObject);
};

ooTemplateSpecialization
class ooHandle(ooUtf8StringHolder) :
#ifdef OO_BUGGY_TEMPLATES
		      public ooHandle_superclass<ooUtf8StringHolder >
#else // !defined(OO_BUGGY_TEMPLATES)
		      public ooHandle(ooObj)
#endif // !defined(OO_BUGGY_TEMPLATES)
                                                {
  public:
    inline ooHandleStructor(ooUtf8StringHolder)();
    inline ooHandleStructor(ooUtf8StringHolder)(const ooRef(ooUtf8StringHolder)& id);
    inline ooHandleStructor(ooUtf8StringHolder)(const ooHandle(ooUtf8StringHolder)& objH);
    inline ooHandleStructor(ooUtf8StringHolder)(const ooUtf8StringHolder *  fromObject);
    inline ooHandle(ooUtf8StringHolder)& operator=(const ooRef(ooUtf8StringHolder)& id);
    inline ooHandle(ooUtf8StringHolder)& operator=(const ooHandle(ooUtf8StringHolder)& objH);
    inline ooHandle(ooUtf8StringHolder)& operator=(const ooShortRef(ooUtf8StringHolder)& shortId);
    inline ooHandle(ooUtf8StringHolder)& operator=(const ooUtf8StringHolder *  fromObject);
    ooStatus lookupObj(const ooHandle(ooObj)& scopeH,
		       const ooKey& key,
		       ooMode openMode = oocRead);
    ooStatus lookupObj(const ooHandle(ooObj)& scopeH,
		       const char* name,
		       ooMode openMode = oocRead);
    ooHandle(ooUtf8StringHolder)& copy(const ooHandle(ooObj)& nearH,
		       ooHandle(ooUtf8StringHolder)& result) const;
    inline ooRef(ooUtf8StringHolder)& copy(const ooHandle(ooObj)& nearH,
		    ooRef(ooUtf8StringHolder)& result) const;
    ooHandle(ooUtf8StringHolder) copy(const ooHandle(ooObj)& nearH) const;
    inline ooUtf8StringHolder *pin(ooMode openMode = oocRead) const;
    inline ooUtf8StringHolder *operator->() const;
    inline ooUtf8StringHolder &operator*() const;
    inline operator ooUtf8StringHolder *() const;
    /* Use "operator ooUtf8StringHolder *" instead of vm. */
    /* OBSOLETE */ inline ooUtf8StringHolder *vm() const;
    // ODMG methods:
    ooHandleStructor(ooUtf8StringHolder)(const d_Ref_Any &from);
    ooUtf8StringHolder *ptr() const;
};

ooTemplateSpecialization
class ooItr(ooUtf8StringHolder) : public ooHandle(ooUtf8StringHolder),
		    public ooIteratorObjOrContObj {
  public:
    ooItrStructor(ooUtf8StringHolder)();
    ~ooItrStructor(ooUtf8StringHolder)();
  private:
    // Defined only to prevent implicit definition:
    ooItrStructor(ooUtf8StringHolder)(ooItr(ooUtf8StringHolder)&);
    ooItr(ooUtf8StringHolder)    operator=(ooItr(ooUtf8StringHolder)&);
};


/* methods on ooDeref(ooUtf8StringHolder) */
inline
ooDeref(ooUtf8StringHolder)::ooDerefStructor(ooUtf8StringHolder)(ooDeref(ooUtf8StringHolder) &  deref) :
    ooDerefBase(deref.vm())
{
  this->pinCompensate();
}
inline
ooDeref(ooUtf8StringHolder)::ooDerefStructor(ooUtf8StringHolder)(ooObj *  fromObject) :
    ooDerefBase(fromObject)
{
}
inline
ooDeref(ooUtf8StringHolder)::~ooDerefStructor(ooUtf8StringHolder)()
{
}
inline
ooUtf8StringHolder *
ooDeref(ooUtf8StringHolder)::operator->() const
{
  return ooReinterpretCast(ooUtf8StringHolder *, this->vm());
}


/* methods on ooRef(ooUtf8StringHolder) */
inline
ooRef(ooUtf8StringHolder)::ooRefStructor(ooUtf8StringHolder)(const ooHandleSuper(ooUtf8StringHolder)& objH) :
    ooRef(ooObj)(objH)
{
}
inline
ooRef(ooUtf8StringHolder)::ooRefStructor(ooUtf8StringHolder)(const ooUtf8StringHolder *  fromObject) :
    ooRef(ooObj)(ooReinterpretCast(const ooObj *, fromObject))
{
}
inline
ooRef(ooUtf8StringHolder)&
ooRef(ooUtf8StringHolder)::operator=(const ooRef(ooUtf8StringHolder) &  id)
{
  this->ooId::operator=(id);
  return *this;
}
inline
ooRef(ooUtf8StringHolder)&
ooRef(ooUtf8StringHolder)::operator=(const ooShortRefSuper(ooUtf8StringHolder) &  shortId)
{
  this->ooRef(ooObj)::operator=(shortId);
  return *this;
}
inline
ooRef(ooUtf8StringHolder)&
ooRef(ooUtf8StringHolder)::operator=(const ooHandleSuper(ooUtf8StringHolder) &  objH)
{
  this->ooRef(ooObj)::operator=(objH);
  return *this;
}
inline
ooRef(ooUtf8StringHolder)&
ooRef(ooUtf8StringHolder)::operator=(const ooUtf8StringHolder *  fromObject)
{
  this->ooRef(ooObj)::operator=(ooReinterpretCast(const ooObj *, fromObject));
  return *this;
}
inline
ooUtf8StringHolder *
ooRef(ooUtf8StringHolder)::pin(ooMode  openMode) const
{
  return ooReinterpretCast(ooUtf8StringHolder *, this->pin_ref_internal(openMode));
}
inline
ooUtf8StringHolder *
ooRef(ooUtf8StringHolder)::vm(ooMode  openMode) const
{
  return this->pin(openMode);
}
#ifndef OO_BUGGY_TEMPLATES
inline
ooHandle(ooUtf8StringHolder) &
ooRef(ooUtf8StringHolder)::copy(const ooHandle(ooObj) &  nearH,
		ooHandle(ooUtf8StringHolder) &           result) const
{
  this->ooRef(ooObj)::copy(nearH, result);
  return result;
}
inline
ooRef(ooUtf8StringHolder) &
ooRef(ooUtf8StringHolder)::copy(const ooHandle(ooObj) &  nearH,
		ooRef(ooUtf8StringHolder) &              newObjRef) const
{
  this->ooRef(ooObj)::copy(nearH, newObjRef);
  return newObjRef;
}
inline
ooHandle(ooUtf8StringHolder)
ooRef(ooUtf8StringHolder)::copy(const ooHandle(ooObj) &  nearH) const
{
  ooHandle(ooUtf8StringHolder) result;
  this->ooRef(ooObj)::copy(nearH, result);
  return result;
}
#endif // !defined(OO_BUGGY_TEMPLATES)
inline
ooDeref(ooUtf8StringHolder)
ooRef(ooUtf8StringHolder)::operator->() const
{
  ooDeref(ooUtf8StringHolder) result(this->pin_ref_internal(oocRead));
  return result;
}


/* methods on ooShortRef(ooUtf8StringHolder) */
inline
ooShortRef(ooUtf8StringHolder) &
ooShortRef(ooUtf8StringHolder)::operator=(const ooShortRef(ooUtf8StringHolder) &  shortId)
{
  this->ooShortId::operator=(shortId);
  return *this;
}
inline
ooShortRef(ooUtf8StringHolder) &
ooShortRef(ooUtf8StringHolder)::operator=(const ooRef(ooUtf8StringHolder) &  id)
{
  this->ooShortId::operator=(id);
  return *this;
}
inline
ooShortRef(ooUtf8StringHolder) &
ooShortRef(ooUtf8StringHolder)::operator=(const ooHandleSuper(ooUtf8StringHolder) &  objH)
{
  this->ooShortId::operator=(objH);
  return *this;
}
inline
ooShortRef(ooUtf8StringHolder)&
ooShortRef(ooUtf8StringHolder)::operator=(const ooUtf8StringHolder *  fromObject)
{
  this->ooShortId::operator=(ooReinterpretCast(const ooObj *,fromObject));
  return *this;
}
inline
ooShortRef(ooUtf8StringHolder)::ooShortRefStructor(ooUtf8StringHolder)()
{
}
#ifdef OO_BUGGY_TEMPLATES
inline
ooShortRef(ooUtf8StringHolder)::ooShortRefStructor(ooUtf8StringHolder)(const ooShortRef(ooUtf8StringHolder) &  shortId)
{
  *this = shortId;
}
#else // !defined(OO_BUGGY_TEMPLATES)
inline
ooShortRef(ooUtf8StringHolder)::ooShortRefStructor(ooUtf8StringHolder)(const ooShortRef(ooUtf8StringHolder) &  shortId) :
    ooShortRef(ooObj)(shortId)
{
}
#endif // !defined(OO_BUGGY_TEMPLATES)
#ifdef OO_BUGGY_TEMPLATES
inline
ooShortRef(ooUtf8StringHolder)::ooShortRefStructor(ooUtf8StringHolder)(const ooRef(ooUtf8StringHolder) &  id)
{
  *this = id;
}
#else // !defined(OO_BUGGY_TEMPLATES)
inline
ooShortRef(ooUtf8StringHolder)::ooShortRefStructor(ooUtf8StringHolder)(const ooRef(ooUtf8StringHolder) &  id) :
    ooShortRef(ooObj)(id)
{
}
#endif // !defined(OO_BUGGY_TEMPLATES)
#ifdef OO_BUGGY_TEMPLATES
inline
ooShortRef(ooUtf8StringHolder)::ooShortRefStructor(ooUtf8StringHolder)(const ooHandleSuper(ooUtf8StringHolder) &  objH)
{
  *this = objH;
}
#else // !defined(OO_BUGGY_TEMPLATES)
inline
ooShortRef(ooUtf8StringHolder)::ooShortRefStructor(ooUtf8StringHolder)(const ooHandleSuper(ooUtf8StringHolder) &  objH) :
    ooShortRef(ooObj)(objH)
{
}
#endif // !defined(OO_BUGGY_TEMPLATES)
#ifdef OO_BUGGY_TEMPLATES
inline
ooShortRef(ooUtf8StringHolder)::ooShortRefStructor(ooUtf8StringHolder)(const ooUtf8StringHolder *  fromObject)
{
  *this = fromObject;
}
#else // !defined(OO_BUGGY_TEMPLATES)
inline
ooShortRef(ooUtf8StringHolder)::ooShortRefStructor(ooUtf8StringHolder)(const ooUtf8StringHolder *  fromObject) :
    ooShortRef(ooObj)(ooReinterpretCast(const ooObj *,fromObject))
{
}
#endif // !defined(OO_BUGGY_TEMPLATES)


/* methods on ooHandle(ooUtf8StringHolder) */
inline
ooHandle(ooUtf8StringHolder)::ooHandleStructor(ooUtf8StringHolder)()
{
}
inline
ooHandle(ooUtf8StringHolder)::ooHandleStructor(ooUtf8StringHolder)(const ooHandle(ooUtf8StringHolder) &  objH) :
#ifdef OO_BUGGY_TEMPLATES
    ooHandle_superclass<ooUtf8StringHolder >(objH)
#else // !defined(OO_BUGGY_TEMPLATES)
    ooHandle(ooObj)(objH)
#endif // !defined(OO_BUGGY_TEMPLATES)
{
}
inline
ooHandle(ooUtf8StringHolder)::ooHandleStructor(ooUtf8StringHolder)(const ooRef(ooUtf8StringHolder) &  id) :
#ifdef OO_BUGGY_TEMPLATES
    ooHandle_superclass<ooUtf8StringHolder >(id)
#else // !defined(OO_BUGGY_TEMPLATES)
    ooHandle(ooObj)(id)
#endif // !defined(OO_BUGGY_TEMPLATES)
{
}
inline
ooHandle(ooUtf8StringHolder)::ooHandleStructor(ooUtf8StringHolder)(const ooUtf8StringHolder *  fromObject) :
#ifdef OO_BUGGY_TEMPLATES
    ooHandle_superclass<ooUtf8StringHolder >(ooReinterpretCast(const ooObj *,fromObject))
#else // !defined(OO_BUGGY_TEMPLATES)
    ooHandle(ooObj)(ooReinterpretCast(const ooObj *,fromObject))
#endif // !defined(OO_BUGGY_TEMPLATES)
{
}
inline
ooHandle(ooUtf8StringHolder)&
ooHandle(ooUtf8StringHolder)::operator=(const ooRef(ooUtf8StringHolder) &  id)
{
  this->ooHandle(ooObj)::operator=(id);
  return *this;
}
inline
ooHandle(ooUtf8StringHolder)&
ooHandle(ooUtf8StringHolder)::operator=(const ooHandle(ooUtf8StringHolder) &  objH)
{
  this->ooHandle(ooObj)::operator=(objH);
  return *this;
}
inline
ooHandle(ooUtf8StringHolder)&
ooHandle(ooUtf8StringHolder)::operator=(const ooShortRef(ooUtf8StringHolder) &  shortId)
{
  this->ooHandle(ooObj)::operator=(shortId);
  return *this;
}
inline
ooHandle(ooUtf8StringHolder)&
ooHandle(ooUtf8StringHolder)::operator=(const ooUtf8StringHolder *  fromObject)
{
  this->ooHandle(ooObj)::operator=(ooReinterpretCast(const ooObj *,fromObject));
  return *this;
}
inline
ooUtf8StringHolder *
ooHandle(ooUtf8StringHolder)::pin(ooMode  openMode) const
{
  return ooReinterpretCast(ooUtf8StringHolder *, this->pin_obj_internal(openMode));
}
inline
ooUtf8StringHolder *
ooHandle(ooUtf8StringHolder)::operator->() const
{
  return this->vm();
}
inline
ooUtf8StringHolder &
ooHandle(ooUtf8StringHolder)::operator*() const
{
  return *(this->vm());
}
inline
ooHandle(ooUtf8StringHolder)::operator ooUtf8StringHolder *() const
{
  if ( _state == oocHandlePTR  )
    return ooReinterpretCast(ooUtf8StringHolder *, _ptr._obj);
  else return ooReinterpretCast(ooUtf8StringHolder *, this->get_vm());
}
inline
ooUtf8StringHolder *
ooHandle(ooUtf8StringHolder)::vm() const
{
  if ( _state == oocHandlePTR && _ptr._obj != NULL )
    return ooReinterpretCast(ooUtf8StringHolder *, _ptr._obj);
  else return ooReinterpretCast(ooUtf8StringHolder *, this->get_vm());
}
inline
ooRef(ooUtf8StringHolder) &
ooHandle(ooUtf8StringHolder)::copy(const ooHandle(ooObj) &  nearH,
		   ooRef(ooUtf8StringHolder) &              result) const
{
  this->ooHandle(ooObj)::copy(nearH, result);
  return result;
}


/* ODMG methods */
inline
ooUtf8StringHolder *
ooRef(ooUtf8StringHolder)::ptr() const
{
  return this->pin();
}
inline
ooUtf8StringHolder *
ooHandle(ooUtf8StringHolder)::ptr() const
{
  return this->operator ooUtf8StringHolder *();
}
class ooUtf16StringHolder;


/////////////////////////////////////////////////////////////////////////////

ooTemplateSpecialization
class ooDeref(ooUtf16StringHolder) : public ooDerefBase {
	friend class ooRef(ooUtf16StringHolder);
  public:
    ~ooDerefStructor(ooUtf16StringHolder)();
    inline ooUtf16StringHolder *operator->() const;
#ifndef OO_BUGGY_TEMPLATES
  private:
#endif // !defined(OO_BUGGY_TEMPLATES)
    ooDerefStructor(ooUtf16StringHolder)(ooDeref(ooUtf16StringHolder)& deref);
    ooDerefStructor(ooUtf16StringHolder)(ooObj *  fromObject);
};


#ifdef OO_BUGGY_TEMPLATES

class ooHandle_superclass<ooUtf16StringHolder > : public ooHandle(ooObj) {
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

class ooShortRef_superclass<ooUtf16StringHolder > : public ooShortRef(ooObj) {
};

#endif // OO_BUGGY_TEMPLATES

ooTemplateSpecialization
class ooRef(ooUtf16StringHolder) : public ooRef(ooObj) {
  public:
    ooRefStructor(ooUtf16StringHolder)()
      {}
    ooRefStructor(ooUtf16StringHolder)(const ooRef(ooUtf16StringHolder)& id) :
	  ooRef(ooObj)(id)
      {}
    inline ooRefStructor(ooUtf16StringHolder)(const ooHandleSuper(ooUtf16StringHolder)& objH);
    inline ooRefStructor(ooUtf16StringHolder)(const ooUtf16StringHolder *  fromObject);
    inline ooRef(ooUtf16StringHolder)& operator=(const ooRef(ooUtf16StringHolder)& id);
    inline ooRef(ooUtf16StringHolder)& operator=(const ooShortRefSuper(ooUtf16StringHolder) &shortId);
    inline ooRef(ooUtf16StringHolder)& operator=(const ooHandleSuper(ooUtf16StringHolder)& objH);
    inline ooRef(ooUtf16StringHolder)& operator=(const ooUtf16StringHolder *  fromObject);
    ooStatus lookupObj(const ooHandle(ooObj)& scopeH,
		       const ooKey& key,
		       ooMode openMode = oocRead);
    ooStatus lookupObj(const ooHandle(ooObj)& scopeH,
		       const char* name,
		       ooMode openMode = oocRead);
#ifndef OO_BUGGY_TEMPLATES
    inline ooRef(ooUtf16StringHolder)& copy(const ooHandle(ooObj)& nearH,
		    ooRef(ooUtf16StringHolder)& newObjRef) const;
    inline ooHandle(ooUtf16StringHolder)& copy(const ooHandle(ooObj)& nearH,
			ooHandle(ooUtf16StringHolder)& result) const;
    inline ooHandle(ooUtf16StringHolder) copy(const ooHandle(ooObj)& nearH) const;
#endif // !defined(OO_BUGGY_TEMPLATES)
    inline ooUtf16StringHolder *pin(ooMode openMode = oocRead) const;
    ooDeref(ooUtf16StringHolder) operator->() const;
    /* Use pin() or use ooHandle "operator ooUtf16StringHolder *" instead of vm. */
    /* OBSOLETE */ inline ooUtf16StringHolder *vm(ooMode openMode = oocRead) const;
    // ODMG methods:
    ooRefStructor(ooUtf16StringHolder)(const d_Ref_Any &from);
    ooUtf16StringHolder *ptr() const;
};

ooTemplateSpecialization
class ooShortRef(ooUtf16StringHolder) :
#ifdef OO_BUGGY_TEMPLATES
			public ooShortRef_superclass<ooUtf16StringHolder >
#else // !defined(OO_BUGGY_TEMPLATES)
			public ooShortRef(ooObj)
#endif // !defined(OO_BUGGY_TEMPLATES)
					            {
  public:
    ooShortRefStructor(ooUtf16StringHolder)();
    ooShortRefStructor(ooUtf16StringHolder)(const ooShortRef(ooUtf16StringHolder)& shortId);
    ooShortRefStructor(ooUtf16StringHolder)(const ooRef(ooUtf16StringHolder)& id);
    ooShortRefStructor(ooUtf16StringHolder)(const ooHandleSuper(ooUtf16StringHolder) &objH);
    ooShortRefStructor(ooUtf16StringHolder)(const ooUtf16StringHolder *  fromObject);
    ooShortRef(ooUtf16StringHolder)& operator=(const ooShortRef(ooUtf16StringHolder)& shortId);
    ooShortRef(ooUtf16StringHolder)& operator=(const ooRef(ooUtf16StringHolder)& id);
    ooShortRef(ooUtf16StringHolder)& operator=(const ooHandleSuper(ooUtf16StringHolder) &objH);
    ooShortRef(ooUtf16StringHolder)& operator=(const ooUtf16StringHolder *  fromObject);
};

ooTemplateSpecialization
class ooHandle(ooUtf16StringHolder) :
#ifdef OO_BUGGY_TEMPLATES
		      public ooHandle_superclass<ooUtf16StringHolder >
#else // !defined(OO_BUGGY_TEMPLATES)
		      public ooHandle(ooObj)
#endif // !defined(OO_BUGGY_TEMPLATES)
                                                {
  public:
    inline ooHandleStructor(ooUtf16StringHolder)();
    inline ooHandleStructor(ooUtf16StringHolder)(const ooRef(ooUtf16StringHolder)& id);
    inline ooHandleStructor(ooUtf16StringHolder)(const ooHandle(ooUtf16StringHolder)& objH);
    inline ooHandleStructor(ooUtf16StringHolder)(const ooUtf16StringHolder *  fromObject);
    inline ooHandle(ooUtf16StringHolder)& operator=(const ooRef(ooUtf16StringHolder)& id);
    inline ooHandle(ooUtf16StringHolder)& operator=(const ooHandle(ooUtf16StringHolder)& objH);
    inline ooHandle(ooUtf16StringHolder)& operator=(const ooShortRef(ooUtf16StringHolder)& shortId);
    inline ooHandle(ooUtf16StringHolder)& operator=(const ooUtf16StringHolder *  fromObject);
    ooStatus lookupObj(const ooHandle(ooObj)& scopeH,
		       const ooKey& key,
		       ooMode openMode = oocRead);
    ooStatus lookupObj(const ooHandle(ooObj)& scopeH,
		       const char* name,
		       ooMode openMode = oocRead);
    ooHandle(ooUtf16StringHolder)& copy(const ooHandle(ooObj)& nearH,
		       ooHandle(ooUtf16StringHolder)& result) const;
    inline ooRef(ooUtf16StringHolder)& copy(const ooHandle(ooObj)& nearH,
		    ooRef(ooUtf16StringHolder)& result) const;
    ooHandle(ooUtf16StringHolder) copy(const ooHandle(ooObj)& nearH) const;
    inline ooUtf16StringHolder *pin(ooMode openMode = oocRead) const;
    inline ooUtf16StringHolder *operator->() const;
    inline ooUtf16StringHolder &operator*() const;
    inline operator ooUtf16StringHolder *() const;
    /* Use "operator ooUtf16StringHolder *" instead of vm. */
    /* OBSOLETE */ inline ooUtf16StringHolder *vm() const;
    // ODMG methods:
    ooHandleStructor(ooUtf16StringHolder)(const d_Ref_Any &from);
    ooUtf16StringHolder *ptr() const;
};

ooTemplateSpecialization
class ooItr(ooUtf16StringHolder) : public ooHandle(ooUtf16StringHolder),
		    public ooIteratorObjOrContObj {
  public:
    ooItrStructor(ooUtf16StringHolder)();
    ~ooItrStructor(ooUtf16StringHolder)();
  private:
    // Defined only to prevent implicit definition:
    ooItrStructor(ooUtf16StringHolder)(ooItr(ooUtf16StringHolder)&);
    ooItr(ooUtf16StringHolder)    operator=(ooItr(ooUtf16StringHolder)&);
};


/* methods on ooDeref(ooUtf16StringHolder) */
inline
ooDeref(ooUtf16StringHolder)::ooDerefStructor(ooUtf16StringHolder)(ooDeref(ooUtf16StringHolder) &  deref) :
    ooDerefBase(deref.vm())
{
  this->pinCompensate();
}
inline
ooDeref(ooUtf16StringHolder)::ooDerefStructor(ooUtf16StringHolder)(ooObj *  fromObject) :
    ooDerefBase(fromObject)
{
}
inline
ooDeref(ooUtf16StringHolder)::~ooDerefStructor(ooUtf16StringHolder)()
{
}
inline
ooUtf16StringHolder *
ooDeref(ooUtf16StringHolder)::operator->() const
{
  return ooReinterpretCast(ooUtf16StringHolder *, this->vm());
}


/* methods on ooRef(ooUtf16StringHolder) */
inline
ooRef(ooUtf16StringHolder)::ooRefStructor(ooUtf16StringHolder)(const ooHandleSuper(ooUtf16StringHolder)& objH) :
    ooRef(ooObj)(objH)
{
}
inline
ooRef(ooUtf16StringHolder)::ooRefStructor(ooUtf16StringHolder)(const ooUtf16StringHolder *  fromObject) :
    ooRef(ooObj)(ooReinterpretCast(const ooObj *, fromObject))
{
}
inline
ooRef(ooUtf16StringHolder)&
ooRef(ooUtf16StringHolder)::operator=(const ooRef(ooUtf16StringHolder) &  id)
{
  this->ooId::operator=(id);
  return *this;
}
inline
ooRef(ooUtf16StringHolder)&
ooRef(ooUtf16StringHolder)::operator=(const ooShortRefSuper(ooUtf16StringHolder) &  shortId)
{
  this->ooRef(ooObj)::operator=(shortId);
  return *this;
}
inline
ooRef(ooUtf16StringHolder)&
ooRef(ooUtf16StringHolder)::operator=(const ooHandleSuper(ooUtf16StringHolder) &  objH)
{
  this->ooRef(ooObj)::operator=(objH);
  return *this;
}
inline
ooRef(ooUtf16StringHolder)&
ooRef(ooUtf16StringHolder)::operator=(const ooUtf16StringHolder *  fromObject)
{
  this->ooRef(ooObj)::operator=(ooReinterpretCast(const ooObj *, fromObject));
  return *this;
}
inline
ooUtf16StringHolder *
ooRef(ooUtf16StringHolder)::pin(ooMode  openMode) const
{
  return ooReinterpretCast(ooUtf16StringHolder *, this->pin_ref_internal(openMode));
}
inline
ooUtf16StringHolder *
ooRef(ooUtf16StringHolder)::vm(ooMode  openMode) const
{
  return this->pin(openMode);
}
#ifndef OO_BUGGY_TEMPLATES
inline
ooHandle(ooUtf16StringHolder) &
ooRef(ooUtf16StringHolder)::copy(const ooHandle(ooObj) &  nearH,
		ooHandle(ooUtf16StringHolder) &           result) const
{
  this->ooRef(ooObj)::copy(nearH, result);
  return result;
}
inline
ooRef(ooUtf16StringHolder) &
ooRef(ooUtf16StringHolder)::copy(const ooHandle(ooObj) &  nearH,
		ooRef(ooUtf16StringHolder) &              newObjRef) const
{
  this->ooRef(ooObj)::copy(nearH, newObjRef);
  return newObjRef;
}
inline
ooHandle(ooUtf16StringHolder)
ooRef(ooUtf16StringHolder)::copy(const ooHandle(ooObj) &  nearH) const
{
  ooHandle(ooUtf16StringHolder) result;
  this->ooRef(ooObj)::copy(nearH, result);
  return result;
}
#endif // !defined(OO_BUGGY_TEMPLATES)
inline
ooDeref(ooUtf16StringHolder)
ooRef(ooUtf16StringHolder)::operator->() const
{
  ooDeref(ooUtf16StringHolder) result(this->pin_ref_internal(oocRead));
  return result;
}


/* methods on ooShortRef(ooUtf16StringHolder) */
inline
ooShortRef(ooUtf16StringHolder) &
ooShortRef(ooUtf16StringHolder)::operator=(const ooShortRef(ooUtf16StringHolder) &  shortId)
{
  this->ooShortId::operator=(shortId);
  return *this;
}
inline
ooShortRef(ooUtf16StringHolder) &
ooShortRef(ooUtf16StringHolder)::operator=(const ooRef(ooUtf16StringHolder) &  id)
{
  this->ooShortId::operator=(id);
  return *this;
}
inline
ooShortRef(ooUtf16StringHolder) &
ooShortRef(ooUtf16StringHolder)::operator=(const ooHandleSuper(ooUtf16StringHolder) &  objH)
{
  this->ooShortId::operator=(objH);
  return *this;
}
inline
ooShortRef(ooUtf16StringHolder)&
ooShortRef(ooUtf16StringHolder)::operator=(const ooUtf16StringHolder *  fromObject)
{
  this->ooShortId::operator=(ooReinterpretCast(const ooObj *,fromObject));
  return *this;
}
inline
ooShortRef(ooUtf16StringHolder)::ooShortRefStructor(ooUtf16StringHolder)()
{
}
#ifdef OO_BUGGY_TEMPLATES
inline
ooShortRef(ooUtf16StringHolder)::ooShortRefStructor(ooUtf16StringHolder)(const ooShortRef(ooUtf16StringHolder) &  shortId)
{
  *this = shortId;
}
#else // !defined(OO_BUGGY_TEMPLATES)
inline
ooShortRef(ooUtf16StringHolder)::ooShortRefStructor(ooUtf16StringHolder)(const ooShortRef(ooUtf16StringHolder) &  shortId) :
    ooShortRef(ooObj)(shortId)
{
}
#endif // !defined(OO_BUGGY_TEMPLATES)
#ifdef OO_BUGGY_TEMPLATES
inline
ooShortRef(ooUtf16StringHolder)::ooShortRefStructor(ooUtf16StringHolder)(const ooRef(ooUtf16StringHolder) &  id)
{
  *this = id;
}
#else // !defined(OO_BUGGY_TEMPLATES)
inline
ooShortRef(ooUtf16StringHolder)::ooShortRefStructor(ooUtf16StringHolder)(const ooRef(ooUtf16StringHolder) &  id) :
    ooShortRef(ooObj)(id)
{
}
#endif // !defined(OO_BUGGY_TEMPLATES)
#ifdef OO_BUGGY_TEMPLATES
inline
ooShortRef(ooUtf16StringHolder)::ooShortRefStructor(ooUtf16StringHolder)(const ooHandleSuper(ooUtf16StringHolder) &  objH)
{
  *this = objH;
}
#else // !defined(OO_BUGGY_TEMPLATES)
inline
ooShortRef(ooUtf16StringHolder)::ooShortRefStructor(ooUtf16StringHolder)(const ooHandleSuper(ooUtf16StringHolder) &  objH) :
    ooShortRef(ooObj)(objH)
{
}
#endif // !defined(OO_BUGGY_TEMPLATES)
#ifdef OO_BUGGY_TEMPLATES
inline
ooShortRef(ooUtf16StringHolder)::ooShortRefStructor(ooUtf16StringHolder)(const ooUtf16StringHolder *  fromObject)
{
  *this = fromObject;
}
#else // !defined(OO_BUGGY_TEMPLATES)
inline
ooShortRef(ooUtf16StringHolder)::ooShortRefStructor(ooUtf16StringHolder)(const ooUtf16StringHolder *  fromObject) :
    ooShortRef(ooObj)(ooReinterpretCast(const ooObj *,fromObject))
{
}
#endif // !defined(OO_BUGGY_TEMPLATES)


/* methods on ooHandle(ooUtf16StringHolder) */
inline
ooHandle(ooUtf16StringHolder)::ooHandleStructor(ooUtf16StringHolder)()
{
}
inline
ooHandle(ooUtf16StringHolder)::ooHandleStructor(ooUtf16StringHolder)(const ooHandle(ooUtf16StringHolder) &  objH) :
#ifdef OO_BUGGY_TEMPLATES
    ooHandle_superclass<ooUtf16StringHolder >(objH)
#else // !defined(OO_BUGGY_TEMPLATES)
    ooHandle(ooObj)(objH)
#endif // !defined(OO_BUGGY_TEMPLATES)
{
}
inline
ooHandle(ooUtf16StringHolder)::ooHandleStructor(ooUtf16StringHolder)(const ooRef(ooUtf16StringHolder) &  id) :
#ifdef OO_BUGGY_TEMPLATES
    ooHandle_superclass<ooUtf16StringHolder >(id)
#else // !defined(OO_BUGGY_TEMPLATES)
    ooHandle(ooObj)(id)
#endif // !defined(OO_BUGGY_TEMPLATES)
{
}
inline
ooHandle(ooUtf16StringHolder)::ooHandleStructor(ooUtf16StringHolder)(const ooUtf16StringHolder *  fromObject) :
#ifdef OO_BUGGY_TEMPLATES
    ooHandle_superclass<ooUtf16StringHolder >(ooReinterpretCast(const ooObj *,fromObject))
#else // !defined(OO_BUGGY_TEMPLATES)
    ooHandle(ooObj)(ooReinterpretCast(const ooObj *,fromObject))
#endif // !defined(OO_BUGGY_TEMPLATES)
{
}
inline
ooHandle(ooUtf16StringHolder)&
ooHandle(ooUtf16StringHolder)::operator=(const ooRef(ooUtf16StringHolder) &  id)
{
  this->ooHandle(ooObj)::operator=(id);
  return *this;
}
inline
ooHandle(ooUtf16StringHolder)&
ooHandle(ooUtf16StringHolder)::operator=(const ooHandle(ooUtf16StringHolder) &  objH)
{
  this->ooHandle(ooObj)::operator=(objH);
  return *this;
}
inline
ooHandle(ooUtf16StringHolder)&
ooHandle(ooUtf16StringHolder)::operator=(const ooShortRef(ooUtf16StringHolder) &  shortId)
{
  this->ooHandle(ooObj)::operator=(shortId);
  return *this;
}
inline
ooHandle(ooUtf16StringHolder)&
ooHandle(ooUtf16StringHolder)::operator=(const ooUtf16StringHolder *  fromObject)
{
  this->ooHandle(ooObj)::operator=(ooReinterpretCast(const ooObj *,fromObject));
  return *this;
}
inline
ooUtf16StringHolder *
ooHandle(ooUtf16StringHolder)::pin(ooMode  openMode) const
{
  return ooReinterpretCast(ooUtf16StringHolder *, this->pin_obj_internal(openMode));
}
inline
ooUtf16StringHolder *
ooHandle(ooUtf16StringHolder)::operator->() const
{
  return this->vm();
}
inline
ooUtf16StringHolder &
ooHandle(ooUtf16StringHolder)::operator*() const
{
  return *(this->vm());
}
inline
ooHandle(ooUtf16StringHolder)::operator ooUtf16StringHolder *() const
{
  if ( _state == oocHandlePTR  )
    return ooReinterpretCast(ooUtf16StringHolder *, _ptr._obj);
  else return ooReinterpretCast(ooUtf16StringHolder *, this->get_vm());
}
inline
ooUtf16StringHolder *
ooHandle(ooUtf16StringHolder)::vm() const
{
  if ( _state == oocHandlePTR && _ptr._obj != NULL )
    return ooReinterpretCast(ooUtf16StringHolder *, _ptr._obj);
  else return ooReinterpretCast(ooUtf16StringHolder *, this->get_vm());
}
inline
ooRef(ooUtf16StringHolder) &
ooHandle(ooUtf16StringHolder)::copy(const ooHandle(ooObj) &  nearH,
		   ooRef(ooUtf16StringHolder) &              result) const
{
  this->ooHandle(ooObj)::copy(nearH, result);
  return result;
}


/* ODMG methods */
inline
ooUtf16StringHolder *
ooRef(ooUtf16StringHolder)::ptr() const
{
  return this->pin();
}
inline
ooUtf16StringHolder *
ooHandle(ooUtf16StringHolder)::ptr() const
{
  return this->operator ooUtf16StringHolder *();
}
class ooUtf32StringHolder;


/////////////////////////////////////////////////////////////////////////////

ooTemplateSpecialization
class ooDeref(ooUtf32StringHolder) : public ooDerefBase {
	friend class ooRef(ooUtf32StringHolder);
  public:
    ~ooDerefStructor(ooUtf32StringHolder)();
    inline ooUtf32StringHolder *operator->() const;
#ifndef OO_BUGGY_TEMPLATES
  private:
#endif // !defined(OO_BUGGY_TEMPLATES)
    ooDerefStructor(ooUtf32StringHolder)(ooDeref(ooUtf32StringHolder)& deref);
    ooDerefStructor(ooUtf32StringHolder)(ooObj *  fromObject);
};


#ifdef OO_BUGGY_TEMPLATES

class ooHandle_superclass<ooUtf32StringHolder > : public ooHandle(ooObj) {
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

class ooShortRef_superclass<ooUtf32StringHolder > : public ooShortRef(ooObj) {
};

#endif // OO_BUGGY_TEMPLATES

ooTemplateSpecialization
class ooRef(ooUtf32StringHolder) : public ooRef(ooObj) {
  public:
    ooRefStructor(ooUtf32StringHolder)()
      {}
    ooRefStructor(ooUtf32StringHolder)(const ooRef(ooUtf32StringHolder)& id) :
	  ooRef(ooObj)(id)
      {}
    inline ooRefStructor(ooUtf32StringHolder)(const ooHandleSuper(ooUtf32StringHolder)& objH);
    inline ooRefStructor(ooUtf32StringHolder)(const ooUtf32StringHolder *  fromObject);
    inline ooRef(ooUtf32StringHolder)& operator=(const ooRef(ooUtf32StringHolder)& id);
    inline ooRef(ooUtf32StringHolder)& operator=(const ooShortRefSuper(ooUtf32StringHolder) &shortId);
    inline ooRef(ooUtf32StringHolder)& operator=(const ooHandleSuper(ooUtf32StringHolder)& objH);
    inline ooRef(ooUtf32StringHolder)& operator=(const ooUtf32StringHolder *  fromObject);
    ooStatus lookupObj(const ooHandle(ooObj)& scopeH,
		       const ooKey& key,
		       ooMode openMode = oocRead);
    ooStatus lookupObj(const ooHandle(ooObj)& scopeH,
		       const char* name,
		       ooMode openMode = oocRead);
#ifndef OO_BUGGY_TEMPLATES
    inline ooRef(ooUtf32StringHolder)& copy(const ooHandle(ooObj)& nearH,
		    ooRef(ooUtf32StringHolder)& newObjRef) const;
    inline ooHandle(ooUtf32StringHolder)& copy(const ooHandle(ooObj)& nearH,
			ooHandle(ooUtf32StringHolder)& result) const;
    inline ooHandle(ooUtf32StringHolder) copy(const ooHandle(ooObj)& nearH) const;
#endif // !defined(OO_BUGGY_TEMPLATES)
    inline ooUtf32StringHolder *pin(ooMode openMode = oocRead) const;
    ooDeref(ooUtf32StringHolder) operator->() const;
    /* Use pin() or use ooHandle "operator ooUtf32StringHolder *" instead of vm. */
    /* OBSOLETE */ inline ooUtf32StringHolder *vm(ooMode openMode = oocRead) const;
    // ODMG methods:
    ooRefStructor(ooUtf32StringHolder)(const d_Ref_Any &from);
    ooUtf32StringHolder *ptr() const;
};

ooTemplateSpecialization
class ooShortRef(ooUtf32StringHolder) :
#ifdef OO_BUGGY_TEMPLATES
			public ooShortRef_superclass<ooUtf32StringHolder >
#else // !defined(OO_BUGGY_TEMPLATES)
			public ooShortRef(ooObj)
#endif // !defined(OO_BUGGY_TEMPLATES)
					            {
  public:
    ooShortRefStructor(ooUtf32StringHolder)();
    ooShortRefStructor(ooUtf32StringHolder)(const ooShortRef(ooUtf32StringHolder)& shortId);
    ooShortRefStructor(ooUtf32StringHolder)(const ooRef(ooUtf32StringHolder)& id);
    ooShortRefStructor(ooUtf32StringHolder)(const ooHandleSuper(ooUtf32StringHolder) &objH);
    ooShortRefStructor(ooUtf32StringHolder)(const ooUtf32StringHolder *  fromObject);
    ooShortRef(ooUtf32StringHolder)& operator=(const ooShortRef(ooUtf32StringHolder)& shortId);
    ooShortRef(ooUtf32StringHolder)& operator=(const ooRef(ooUtf32StringHolder)& id);
    ooShortRef(ooUtf32StringHolder)& operator=(const ooHandleSuper(ooUtf32StringHolder) &objH);
    ooShortRef(ooUtf32StringHolder)& operator=(const ooUtf32StringHolder *  fromObject);
};

ooTemplateSpecialization
class ooHandle(ooUtf32StringHolder) :
#ifdef OO_BUGGY_TEMPLATES
		      public ooHandle_superclass<ooUtf32StringHolder >
#else // !defined(OO_BUGGY_TEMPLATES)
		      public ooHandle(ooObj)
#endif // !defined(OO_BUGGY_TEMPLATES)
                                                {
  public:
    inline ooHandleStructor(ooUtf32StringHolder)();
    inline ooHandleStructor(ooUtf32StringHolder)(const ooRef(ooUtf32StringHolder)& id);
    inline ooHandleStructor(ooUtf32StringHolder)(const ooHandle(ooUtf32StringHolder)& objH);
    inline ooHandleStructor(ooUtf32StringHolder)(const ooUtf32StringHolder *  fromObject);
    inline ooHandle(ooUtf32StringHolder)& operator=(const ooRef(ooUtf32StringHolder)& id);
    inline ooHandle(ooUtf32StringHolder)& operator=(const ooHandle(ooUtf32StringHolder)& objH);
    inline ooHandle(ooUtf32StringHolder)& operator=(const ooShortRef(ooUtf32StringHolder)& shortId);
    inline ooHandle(ooUtf32StringHolder)& operator=(const ooUtf32StringHolder *  fromObject);
    ooStatus lookupObj(const ooHandle(ooObj)& scopeH,
		       const ooKey& key,
		       ooMode openMode = oocRead);
    ooStatus lookupObj(const ooHandle(ooObj)& scopeH,
		       const char* name,
		       ooMode openMode = oocRead);
    ooHandle(ooUtf32StringHolder)& copy(const ooHandle(ooObj)& nearH,
		       ooHandle(ooUtf32StringHolder)& result) const;
    inline ooRef(ooUtf32StringHolder)& copy(const ooHandle(ooObj)& nearH,
		    ooRef(ooUtf32StringHolder)& result) const;
    ooHandle(ooUtf32StringHolder) copy(const ooHandle(ooObj)& nearH) const;
    inline ooUtf32StringHolder *pin(ooMode openMode = oocRead) const;
    inline ooUtf32StringHolder *operator->() const;
    inline ooUtf32StringHolder &operator*() const;
    inline operator ooUtf32StringHolder *() const;
    /* Use "operator ooUtf32StringHolder *" instead of vm. */
    /* OBSOLETE */ inline ooUtf32StringHolder *vm() const;
    // ODMG methods:
    ooHandleStructor(ooUtf32StringHolder)(const d_Ref_Any &from);
    ooUtf32StringHolder *ptr() const;
};

ooTemplateSpecialization
class ooItr(ooUtf32StringHolder) : public ooHandle(ooUtf32StringHolder),
		    public ooIteratorObjOrContObj {
  public:
    ooItrStructor(ooUtf32StringHolder)();
    ~ooItrStructor(ooUtf32StringHolder)();
  private:
    // Defined only to prevent implicit definition:
    ooItrStructor(ooUtf32StringHolder)(ooItr(ooUtf32StringHolder)&);
    ooItr(ooUtf32StringHolder)    operator=(ooItr(ooUtf32StringHolder)&);
};


/* methods on ooDeref(ooUtf32StringHolder) */
inline
ooDeref(ooUtf32StringHolder)::ooDerefStructor(ooUtf32StringHolder)(ooDeref(ooUtf32StringHolder) &  deref) :
    ooDerefBase(deref.vm())
{
  this->pinCompensate();
}
inline
ooDeref(ooUtf32StringHolder)::ooDerefStructor(ooUtf32StringHolder)(ooObj *  fromObject) :
    ooDerefBase(fromObject)
{
}
inline
ooDeref(ooUtf32StringHolder)::~ooDerefStructor(ooUtf32StringHolder)()
{
}
inline
ooUtf32StringHolder *
ooDeref(ooUtf32StringHolder)::operator->() const
{
  return ooReinterpretCast(ooUtf32StringHolder *, this->vm());
}


/* methods on ooRef(ooUtf32StringHolder) */
inline
ooRef(ooUtf32StringHolder)::ooRefStructor(ooUtf32StringHolder)(const ooHandleSuper(ooUtf32StringHolder)& objH) :
    ooRef(ooObj)(objH)
{
}
inline
ooRef(ooUtf32StringHolder)::ooRefStructor(ooUtf32StringHolder)(const ooUtf32StringHolder *  fromObject) :
    ooRef(ooObj)(ooReinterpretCast(const ooObj *, fromObject))
{
}
inline
ooRef(ooUtf32StringHolder)&
ooRef(ooUtf32StringHolder)::operator=(const ooRef(ooUtf32StringHolder) &  id)
{
  this->ooId::operator=(id);
  return *this;
}
inline
ooRef(ooUtf32StringHolder)&
ooRef(ooUtf32StringHolder)::operator=(const ooShortRefSuper(ooUtf32StringHolder) &  shortId)
{
  this->ooRef(ooObj)::operator=(shortId);
  return *this;
}
inline
ooRef(ooUtf32StringHolder)&
ooRef(ooUtf32StringHolder)::operator=(const ooHandleSuper(ooUtf32StringHolder) &  objH)
{
  this->ooRef(ooObj)::operator=(objH);
  return *this;
}
inline
ooRef(ooUtf32StringHolder)&
ooRef(ooUtf32StringHolder)::operator=(const ooUtf32StringHolder *  fromObject)
{
  this->ooRef(ooObj)::operator=(ooReinterpretCast(const ooObj *, fromObject));
  return *this;
}
inline
ooUtf32StringHolder *
ooRef(ooUtf32StringHolder)::pin(ooMode  openMode) const
{
  return ooReinterpretCast(ooUtf32StringHolder *, this->pin_ref_internal(openMode));
}
inline
ooUtf32StringHolder *
ooRef(ooUtf32StringHolder)::vm(ooMode  openMode) const
{
  return this->pin(openMode);
}
#ifndef OO_BUGGY_TEMPLATES
inline
ooHandle(ooUtf32StringHolder) &
ooRef(ooUtf32StringHolder)::copy(const ooHandle(ooObj) &  nearH,
		ooHandle(ooUtf32StringHolder) &           result) const
{
  this->ooRef(ooObj)::copy(nearH, result);
  return result;
}
inline
ooRef(ooUtf32StringHolder) &
ooRef(ooUtf32StringHolder)::copy(const ooHandle(ooObj) &  nearH,
		ooRef(ooUtf32StringHolder) &              newObjRef) const
{
  this->ooRef(ooObj)::copy(nearH, newObjRef);
  return newObjRef;
}
inline
ooHandle(ooUtf32StringHolder)
ooRef(ooUtf32StringHolder)::copy(const ooHandle(ooObj) &  nearH) const
{
  ooHandle(ooUtf32StringHolder) result;
  this->ooRef(ooObj)::copy(nearH, result);
  return result;
}
#endif // !defined(OO_BUGGY_TEMPLATES)
inline
ooDeref(ooUtf32StringHolder)
ooRef(ooUtf32StringHolder)::operator->() const
{
  ooDeref(ooUtf32StringHolder) result(this->pin_ref_internal(oocRead));
  return result;
}


/* methods on ooShortRef(ooUtf32StringHolder) */
inline
ooShortRef(ooUtf32StringHolder) &
ooShortRef(ooUtf32StringHolder)::operator=(const ooShortRef(ooUtf32StringHolder) &  shortId)
{
  this->ooShortId::operator=(shortId);
  return *this;
}
inline
ooShortRef(ooUtf32StringHolder) &
ooShortRef(ooUtf32StringHolder)::operator=(const ooRef(ooUtf32StringHolder) &  id)
{
  this->ooShortId::operator=(id);
  return *this;
}
inline
ooShortRef(ooUtf32StringHolder) &
ooShortRef(ooUtf32StringHolder)::operator=(const ooHandleSuper(ooUtf32StringHolder) &  objH)
{
  this->ooShortId::operator=(objH);
  return *this;
}
inline
ooShortRef(ooUtf32StringHolder)&
ooShortRef(ooUtf32StringHolder)::operator=(const ooUtf32StringHolder *  fromObject)
{
  this->ooShortId::operator=(ooReinterpretCast(const ooObj *,fromObject));
  return *this;
}
inline
ooShortRef(ooUtf32StringHolder)::ooShortRefStructor(ooUtf32StringHolder)()
{
}
#ifdef OO_BUGGY_TEMPLATES
inline
ooShortRef(ooUtf32StringHolder)::ooShortRefStructor(ooUtf32StringHolder)(const ooShortRef(ooUtf32StringHolder) &  shortId)
{
  *this = shortId;
}
#else // !defined(OO_BUGGY_TEMPLATES)
inline
ooShortRef(ooUtf32StringHolder)::ooShortRefStructor(ooUtf32StringHolder)(const ooShortRef(ooUtf32StringHolder) &  shortId) :
    ooShortRef(ooObj)(shortId)
{
}
#endif // !defined(OO_BUGGY_TEMPLATES)
#ifdef OO_BUGGY_TEMPLATES
inline
ooShortRef(ooUtf32StringHolder)::ooShortRefStructor(ooUtf32StringHolder)(const ooRef(ooUtf32StringHolder) &  id)
{
  *this = id;
}
#else // !defined(OO_BUGGY_TEMPLATES)
inline
ooShortRef(ooUtf32StringHolder)::ooShortRefStructor(ooUtf32StringHolder)(const ooRef(ooUtf32StringHolder) &  id) :
    ooShortRef(ooObj)(id)
{
}
#endif // !defined(OO_BUGGY_TEMPLATES)
#ifdef OO_BUGGY_TEMPLATES
inline
ooShortRef(ooUtf32StringHolder)::ooShortRefStructor(ooUtf32StringHolder)(const ooHandleSuper(ooUtf32StringHolder) &  objH)
{
  *this = objH;
}
#else // !defined(OO_BUGGY_TEMPLATES)
inline
ooShortRef(ooUtf32StringHolder)::ooShortRefStructor(ooUtf32StringHolder)(const ooHandleSuper(ooUtf32StringHolder) &  objH) :
    ooShortRef(ooObj)(objH)
{
}
#endif // !defined(OO_BUGGY_TEMPLATES)
#ifdef OO_BUGGY_TEMPLATES
inline
ooShortRef(ooUtf32StringHolder)::ooShortRefStructor(ooUtf32StringHolder)(const ooUtf32StringHolder *  fromObject)
{
  *this = fromObject;
}
#else // !defined(OO_BUGGY_TEMPLATES)
inline
ooShortRef(ooUtf32StringHolder)::ooShortRefStructor(ooUtf32StringHolder)(const ooUtf32StringHolder *  fromObject) :
    ooShortRef(ooObj)(ooReinterpretCast(const ooObj *,fromObject))
{
}
#endif // !defined(OO_BUGGY_TEMPLATES)


/* methods on ooHandle(ooUtf32StringHolder) */
inline
ooHandle(ooUtf32StringHolder)::ooHandleStructor(ooUtf32StringHolder)()
{
}
inline
ooHandle(ooUtf32StringHolder)::ooHandleStructor(ooUtf32StringHolder)(const ooHandle(ooUtf32StringHolder) &  objH) :
#ifdef OO_BUGGY_TEMPLATES
    ooHandle_superclass<ooUtf32StringHolder >(objH)
#else // !defined(OO_BUGGY_TEMPLATES)
    ooHandle(ooObj)(objH)
#endif // !defined(OO_BUGGY_TEMPLATES)
{
}
inline
ooHandle(ooUtf32StringHolder)::ooHandleStructor(ooUtf32StringHolder)(const ooRef(ooUtf32StringHolder) &  id) :
#ifdef OO_BUGGY_TEMPLATES
    ooHandle_superclass<ooUtf32StringHolder >(id)
#else // !defined(OO_BUGGY_TEMPLATES)
    ooHandle(ooObj)(id)
#endif // !defined(OO_BUGGY_TEMPLATES)
{
}
inline
ooHandle(ooUtf32StringHolder)::ooHandleStructor(ooUtf32StringHolder)(const ooUtf32StringHolder *  fromObject) :
#ifdef OO_BUGGY_TEMPLATES
    ooHandle_superclass<ooUtf32StringHolder >(ooReinterpretCast(const ooObj *,fromObject))
#else // !defined(OO_BUGGY_TEMPLATES)
    ooHandle(ooObj)(ooReinterpretCast(const ooObj *,fromObject))
#endif // !defined(OO_BUGGY_TEMPLATES)
{
}
inline
ooHandle(ooUtf32StringHolder)&
ooHandle(ooUtf32StringHolder)::operator=(const ooRef(ooUtf32StringHolder) &  id)
{
  this->ooHandle(ooObj)::operator=(id);
  return *this;
}
inline
ooHandle(ooUtf32StringHolder)&
ooHandle(ooUtf32StringHolder)::operator=(const ooHandle(ooUtf32StringHolder) &  objH)
{
  this->ooHandle(ooObj)::operator=(objH);
  return *this;
}
inline
ooHandle(ooUtf32StringHolder)&
ooHandle(ooUtf32StringHolder)::operator=(const ooShortRef(ooUtf32StringHolder) &  shortId)
{
  this->ooHandle(ooObj)::operator=(shortId);
  return *this;
}
inline
ooHandle(ooUtf32StringHolder)&
ooHandle(ooUtf32StringHolder)::operator=(const ooUtf32StringHolder *  fromObject)
{
  this->ooHandle(ooObj)::operator=(ooReinterpretCast(const ooObj *,fromObject));
  return *this;
}
inline
ooUtf32StringHolder *
ooHandle(ooUtf32StringHolder)::pin(ooMode  openMode) const
{
  return ooReinterpretCast(ooUtf32StringHolder *, this->pin_obj_internal(openMode));
}
inline
ooUtf32StringHolder *
ooHandle(ooUtf32StringHolder)::operator->() const
{
  return this->vm();
}
inline
ooUtf32StringHolder &
ooHandle(ooUtf32StringHolder)::operator*() const
{
  return *(this->vm());
}
inline
ooHandle(ooUtf32StringHolder)::operator ooUtf32StringHolder *() const
{
  if ( _state == oocHandlePTR  )
    return ooReinterpretCast(ooUtf32StringHolder *, _ptr._obj);
  else return ooReinterpretCast(ooUtf32StringHolder *, this->get_vm());
}
inline
ooUtf32StringHolder *
ooHandle(ooUtf32StringHolder)::vm() const
{
  if ( _state == oocHandlePTR && _ptr._obj != NULL )
    return ooReinterpretCast(ooUtf32StringHolder *, _ptr._obj);
  else return ooReinterpretCast(ooUtf32StringHolder *, this->get_vm());
}
inline
ooRef(ooUtf32StringHolder) &
ooHandle(ooUtf32StringHolder)::copy(const ooHandle(ooObj) &  nearH,
		   ooRef(ooUtf32StringHolder) &              result) const
{
  this->ooHandle(ooObj)::copy(nearH, result);
  return result;
}


/* ODMG methods */
inline
ooUtf32StringHolder *
ooRef(ooUtf32StringHolder)::ptr() const
{
  return this->pin();
}
inline
ooUtf32StringHolder *
ooHandle(ooUtf32StringHolder)::ptr() const
{
  return this->operator ooUtf32StringHolder *();
}
#if defined(_MSC_VER) && !defined(OO_DDL_TRANSLATION)
#pragma pack(pop)
#endif

#endif /* OO_PREDEFINED_REF_H */

