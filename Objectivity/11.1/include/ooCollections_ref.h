/* C++ 'references' header file: Objectivity/DB DDL Version: 11.1 */


#ifndef OO_COLLECTIONS_REF_H
#define OO_COLLECTIONS_REF_H

#ifndef OO_H
#include <oo.h>
#endif
#include <ooSchema_ref.h>
#include "ooCollectionBase_ref.h"
#if defined(_MSC_VER) && !defined(OO_DDL_TRANSLATION)
#pragma pack(push,8)
#endif
class ooUnsortedArray;


/////////////////////////////////////////////////////////////////////////////

ooTemplateSpecialization
class CO_STORAGE_SPECIFIER ooDeref(ooUnsortedArray) : public ooDerefBase {
	friend class ooRef(ooUnsortedArray);
  public:
    ~ooDerefStructor(ooUnsortedArray)();
    inline ooUnsortedArray *operator->() const;
#ifndef OO_BUGGY_TEMPLATES
  private:
#endif // !defined(OO_BUGGY_TEMPLATES)
    ooDerefStructor(ooUnsortedArray)(ooDeref(ooUnsortedArray)& deref);
    ooDerefStructor(ooUnsortedArray)(ooObj *  fromObject);
};


#ifdef OO_BUGGY_TEMPLATES

class CO_STORAGE_SPECIFIER ooHandle_superclass<ooUnsortedArray > : public ooHandle(ooObj) {
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

class CO_STORAGE_SPECIFIER ooShortRef_superclass<ooUnsortedArray > : public ooShortRef(ooObj) {
};

#endif // OO_BUGGY_TEMPLATES

ooTemplateSpecialization
class CO_STORAGE_SPECIFIER ooRef(ooUnsortedArray) : public ooRef(ooObj) {
  public:
    ooRefStructor(ooUnsortedArray)()
      {}
    ooRefStructor(ooUnsortedArray)(const ooRef(ooUnsortedArray)& id) :
	  ooRef(ooObj)(id)
      {}
    inline ooRefStructor(ooUnsortedArray)(const ooHandleSuper(ooUnsortedArray)& objH);
    inline ooRefStructor(ooUnsortedArray)(const ooUnsortedArray *  fromObject);
    inline ooRef(ooUnsortedArray)& operator=(const ooRef(ooUnsortedArray)& id);
    inline ooRef(ooUnsortedArray)& operator=(const ooShortRefSuper(ooUnsortedArray) &shortId);
    inline ooRef(ooUnsortedArray)& operator=(const ooHandleSuper(ooUnsortedArray)& objH);
    inline ooRef(ooUnsortedArray)& operator=(const ooUnsortedArray *  fromObject);
    ooStatus lookupObj(const ooHandle(ooObj)& scopeH,
		       const ooKey& key,
		       ooMode openMode = oocRead);
    ooStatus lookupObj(const ooHandle(ooObj)& scopeH,
		       const char* name,
		       ooMode openMode = oocRead);
#ifndef OO_BUGGY_TEMPLATES
    inline ooRef(ooUnsortedArray)& copy(const ooHandle(ooObj)& nearH,
		    ooRef(ooUnsortedArray)& newObjRef) const;
    inline ooHandle(ooUnsortedArray)& copy(const ooHandle(ooObj)& nearH,
			ooHandle(ooUnsortedArray)& result) const;
    inline ooHandle(ooUnsortedArray) copy(const ooHandle(ooObj)& nearH) const;
#endif // !defined(OO_BUGGY_TEMPLATES)
    inline ooUnsortedArray *pin(ooMode openMode = oocRead) const;
    ooDeref(ooUnsortedArray) operator->() const;
    /* Use pin() or use ooHandle "operator ooUnsortedArray *" instead of vm. */
    /* OBSOLETE */ inline ooUnsortedArray *vm(ooMode openMode = oocRead) const;
    // ODMG methods:
    ooRefStructor(ooUnsortedArray)(const d_Ref_Any &from);
    ooUnsortedArray *ptr() const;
};

ooTemplateSpecialization
class CO_STORAGE_SPECIFIER ooShortRef(ooUnsortedArray) :
#ifdef OO_BUGGY_TEMPLATES
			public ooShortRef_superclass<ooUnsortedArray >
#else // !defined(OO_BUGGY_TEMPLATES)
			public ooShortRef(ooObj)
#endif // !defined(OO_BUGGY_TEMPLATES)
					            {
  public:
    ooShortRefStructor(ooUnsortedArray)();
    ooShortRefStructor(ooUnsortedArray)(const ooShortRef(ooUnsortedArray)& shortId);
    ooShortRefStructor(ooUnsortedArray)(const ooRef(ooUnsortedArray)& id);
    ooShortRefStructor(ooUnsortedArray)(const ooHandleSuper(ooUnsortedArray) &objH);
    ooShortRefStructor(ooUnsortedArray)(const ooUnsortedArray *  fromObject);
    ooShortRef(ooUnsortedArray)& operator=(const ooShortRef(ooUnsortedArray)& shortId);
    ooShortRef(ooUnsortedArray)& operator=(const ooRef(ooUnsortedArray)& id);
    ooShortRef(ooUnsortedArray)& operator=(const ooHandleSuper(ooUnsortedArray) &objH);
    ooShortRef(ooUnsortedArray)& operator=(const ooUnsortedArray *  fromObject);
};

ooTemplateSpecialization
class CO_STORAGE_SPECIFIER ooHandle(ooUnsortedArray) :
#ifdef OO_BUGGY_TEMPLATES
		      public ooHandle_superclass<ooUnsortedArray >
#else // !defined(OO_BUGGY_TEMPLATES)
		      public ooHandle(ooObj)
#endif // !defined(OO_BUGGY_TEMPLATES)
                                                {
  public:
    inline ooHandleStructor(ooUnsortedArray)();
    inline ooHandleStructor(ooUnsortedArray)(const ooRef(ooUnsortedArray)& id);
    inline ooHandleStructor(ooUnsortedArray)(const ooHandle(ooUnsortedArray)& objH);
    inline ooHandleStructor(ooUnsortedArray)(const ooUnsortedArray *  fromObject);
    inline ooHandle(ooUnsortedArray)& operator=(const ooRef(ooUnsortedArray)& id);
    inline ooHandle(ooUnsortedArray)& operator=(const ooHandle(ooUnsortedArray)& objH);
    inline ooHandle(ooUnsortedArray)& operator=(const ooShortRef(ooUnsortedArray)& shortId);
    inline ooHandle(ooUnsortedArray)& operator=(const ooUnsortedArray *  fromObject);
    ooStatus lookupObj(const ooHandle(ooObj)& scopeH,
		       const ooKey& key,
		       ooMode openMode = oocRead);
    ooStatus lookupObj(const ooHandle(ooObj)& scopeH,
		       const char* name,
		       ooMode openMode = oocRead);
    ooHandle(ooUnsortedArray)& copy(const ooHandle(ooObj)& nearH,
		       ooHandle(ooUnsortedArray)& result) const;
    inline ooRef(ooUnsortedArray)& copy(const ooHandle(ooObj)& nearH,
		    ooRef(ooUnsortedArray)& result) const;
    ooHandle(ooUnsortedArray) copy(const ooHandle(ooObj)& nearH) const;
    inline ooUnsortedArray *pin(ooMode openMode = oocRead) const;
    inline ooUnsortedArray *operator->() const;
    inline ooUnsortedArray &operator*() const;
    inline operator ooUnsortedArray *() const;
    /* Use "operator ooUnsortedArray *" instead of vm. */
    /* OBSOLETE */ inline ooUnsortedArray *vm() const;
    // ODMG methods:
    ooHandleStructor(ooUnsortedArray)(const d_Ref_Any &from);
    ooUnsortedArray *ptr() const;
};

ooTemplateSpecialization
class CO_STORAGE_SPECIFIER ooItr(ooUnsortedArray) : public ooHandle(ooUnsortedArray),
		    public ooIteratorObjOrContObj {
  public:
    ooItrStructor(ooUnsortedArray)();
    ~ooItrStructor(ooUnsortedArray)();
  private:
    // Defined only to prevent implicit definition:
    ooItrStructor(ooUnsortedArray)(ooItr(ooUnsortedArray)&);
    ooItr(ooUnsortedArray)    operator=(ooItr(ooUnsortedArray)&);
};


/* methods on ooDeref(ooUnsortedArray) */
inline
ooDeref(ooUnsortedArray)::ooDerefStructor(ooUnsortedArray)(ooDeref(ooUnsortedArray) &  deref) :
    ooDerefBase(deref.vm())
{
  this->pinCompensate();
}
inline
ooDeref(ooUnsortedArray)::ooDerefStructor(ooUnsortedArray)(ooObj *  fromObject) :
    ooDerefBase(fromObject)
{
}
inline
ooDeref(ooUnsortedArray)::~ooDerefStructor(ooUnsortedArray)()
{
}
inline
ooUnsortedArray *
ooDeref(ooUnsortedArray)::operator->() const
{
  return ooReinterpretCast(ooUnsortedArray *, this->vm());
}


/* methods on ooRef(ooUnsortedArray) */
inline
ooRef(ooUnsortedArray)::ooRefStructor(ooUnsortedArray)(const ooHandleSuper(ooUnsortedArray)& objH) :
    ooRef(ooObj)(objH)
{
}
inline
ooRef(ooUnsortedArray)::ooRefStructor(ooUnsortedArray)(const ooUnsortedArray *  fromObject) :
    ooRef(ooObj)(ooReinterpretCast(const ooObj *, fromObject))
{
}
inline
ooRef(ooUnsortedArray)&
ooRef(ooUnsortedArray)::operator=(const ooRef(ooUnsortedArray) &  id)
{
  this->ooId::operator=(id);
  return *this;
}
inline
ooRef(ooUnsortedArray)&
ooRef(ooUnsortedArray)::operator=(const ooShortRefSuper(ooUnsortedArray) &  shortId)
{
  this->ooRef(ooObj)::operator=(shortId);
  return *this;
}
inline
ooRef(ooUnsortedArray)&
ooRef(ooUnsortedArray)::operator=(const ooHandleSuper(ooUnsortedArray) &  objH)
{
  this->ooRef(ooObj)::operator=(objH);
  return *this;
}
inline
ooRef(ooUnsortedArray)&
ooRef(ooUnsortedArray)::operator=(const ooUnsortedArray *  fromObject)
{
  this->ooRef(ooObj)::operator=(ooReinterpretCast(const ooObj *, fromObject));
  return *this;
}
inline
ooUnsortedArray *
ooRef(ooUnsortedArray)::pin(ooMode  openMode) const
{
  return ooReinterpretCast(ooUnsortedArray *, this->pin_ref_internal(openMode));
}
inline
ooUnsortedArray *
ooRef(ooUnsortedArray)::vm(ooMode  openMode) const
{
  return this->pin(openMode);
}
#ifndef OO_BUGGY_TEMPLATES
inline
ooHandle(ooUnsortedArray) &
ooRef(ooUnsortedArray)::copy(const ooHandle(ooObj) &  nearH,
		ooHandle(ooUnsortedArray) &           result) const
{
  this->ooRef(ooObj)::copy(nearH, result);
  return result;
}
inline
ooRef(ooUnsortedArray) &
ooRef(ooUnsortedArray)::copy(const ooHandle(ooObj) &  nearH,
		ooRef(ooUnsortedArray) &              newObjRef) const
{
  this->ooRef(ooObj)::copy(nearH, newObjRef);
  return newObjRef;
}
inline
ooHandle(ooUnsortedArray)
ooRef(ooUnsortedArray)::copy(const ooHandle(ooObj) &  nearH) const
{
  ooHandle(ooUnsortedArray) result;
  this->ooRef(ooObj)::copy(nearH, result);
  return result;
}
#endif // !defined(OO_BUGGY_TEMPLATES)
inline
ooDeref(ooUnsortedArray)
ooRef(ooUnsortedArray)::operator->() const
{
  ooDeref(ooUnsortedArray) result(this->pin_ref_internal(oocRead));
  return result;
}


/* methods on ooShortRef(ooUnsortedArray) */
inline
ooShortRef(ooUnsortedArray) &
ooShortRef(ooUnsortedArray)::operator=(const ooShortRef(ooUnsortedArray) &  shortId)
{
  this->ooShortId::operator=(shortId);
  return *this;
}
inline
ooShortRef(ooUnsortedArray) &
ooShortRef(ooUnsortedArray)::operator=(const ooRef(ooUnsortedArray) &  id)
{
  this->ooShortId::operator=(id);
  return *this;
}
inline
ooShortRef(ooUnsortedArray) &
ooShortRef(ooUnsortedArray)::operator=(const ooHandleSuper(ooUnsortedArray) &  objH)
{
  this->ooShortId::operator=(objH);
  return *this;
}
inline
ooShortRef(ooUnsortedArray)&
ooShortRef(ooUnsortedArray)::operator=(const ooUnsortedArray *  fromObject)
{
  this->ooShortId::operator=(ooReinterpretCast(const ooObj *,fromObject));
  return *this;
}
inline
ooShortRef(ooUnsortedArray)::ooShortRefStructor(ooUnsortedArray)()
{
}
#ifdef OO_BUGGY_TEMPLATES
inline
ooShortRef(ooUnsortedArray)::ooShortRefStructor(ooUnsortedArray)(const ooShortRef(ooUnsortedArray) &  shortId)
{
  *this = shortId;
}
#else // !defined(OO_BUGGY_TEMPLATES)
inline
ooShortRef(ooUnsortedArray)::ooShortRefStructor(ooUnsortedArray)(const ooShortRef(ooUnsortedArray) &  shortId) :
    ooShortRef(ooObj)(shortId)
{
}
#endif // !defined(OO_BUGGY_TEMPLATES)
#ifdef OO_BUGGY_TEMPLATES
inline
ooShortRef(ooUnsortedArray)::ooShortRefStructor(ooUnsortedArray)(const ooRef(ooUnsortedArray) &  id)
{
  *this = id;
}
#else // !defined(OO_BUGGY_TEMPLATES)
inline
ooShortRef(ooUnsortedArray)::ooShortRefStructor(ooUnsortedArray)(const ooRef(ooUnsortedArray) &  id) :
    ooShortRef(ooObj)(id)
{
}
#endif // !defined(OO_BUGGY_TEMPLATES)
#ifdef OO_BUGGY_TEMPLATES
inline
ooShortRef(ooUnsortedArray)::ooShortRefStructor(ooUnsortedArray)(const ooHandleSuper(ooUnsortedArray) &  objH)
{
  *this = objH;
}
#else // !defined(OO_BUGGY_TEMPLATES)
inline
ooShortRef(ooUnsortedArray)::ooShortRefStructor(ooUnsortedArray)(const ooHandleSuper(ooUnsortedArray) &  objH) :
    ooShortRef(ooObj)(objH)
{
}
#endif // !defined(OO_BUGGY_TEMPLATES)
#ifdef OO_BUGGY_TEMPLATES
inline
ooShortRef(ooUnsortedArray)::ooShortRefStructor(ooUnsortedArray)(const ooUnsortedArray *  fromObject)
{
  *this = fromObject;
}
#else // !defined(OO_BUGGY_TEMPLATES)
inline
ooShortRef(ooUnsortedArray)::ooShortRefStructor(ooUnsortedArray)(const ooUnsortedArray *  fromObject) :
    ooShortRef(ooObj)(ooReinterpretCast(const ooObj *,fromObject))
{
}
#endif // !defined(OO_BUGGY_TEMPLATES)


/* methods on ooHandle(ooUnsortedArray) */
inline
ooHandle(ooUnsortedArray)::ooHandleStructor(ooUnsortedArray)()
{
}
inline
ooHandle(ooUnsortedArray)::ooHandleStructor(ooUnsortedArray)(const ooHandle(ooUnsortedArray) &  objH) :
#ifdef OO_BUGGY_TEMPLATES
    ooHandle_superclass<ooUnsortedArray >(objH)
#else // !defined(OO_BUGGY_TEMPLATES)
    ooHandle(ooObj)(objH)
#endif // !defined(OO_BUGGY_TEMPLATES)
{
}
inline
ooHandle(ooUnsortedArray)::ooHandleStructor(ooUnsortedArray)(const ooRef(ooUnsortedArray) &  id) :
#ifdef OO_BUGGY_TEMPLATES
    ooHandle_superclass<ooUnsortedArray >(id)
#else // !defined(OO_BUGGY_TEMPLATES)
    ooHandle(ooObj)(id)
#endif // !defined(OO_BUGGY_TEMPLATES)
{
}
inline
ooHandle(ooUnsortedArray)::ooHandleStructor(ooUnsortedArray)(const ooUnsortedArray *  fromObject) :
#ifdef OO_BUGGY_TEMPLATES
    ooHandle_superclass<ooUnsortedArray >(ooReinterpretCast(const ooObj *,fromObject))
#else // !defined(OO_BUGGY_TEMPLATES)
    ooHandle(ooObj)(ooReinterpretCast(const ooObj *,fromObject))
#endif // !defined(OO_BUGGY_TEMPLATES)
{
}
inline
ooHandle(ooUnsortedArray)&
ooHandle(ooUnsortedArray)::operator=(const ooRef(ooUnsortedArray) &  id)
{
  this->ooHandle(ooObj)::operator=(id);
  return *this;
}
inline
ooHandle(ooUnsortedArray)&
ooHandle(ooUnsortedArray)::operator=(const ooHandle(ooUnsortedArray) &  objH)
{
  this->ooHandle(ooObj)::operator=(objH);
  return *this;
}
inline
ooHandle(ooUnsortedArray)&
ooHandle(ooUnsortedArray)::operator=(const ooShortRef(ooUnsortedArray) &  shortId)
{
  this->ooHandle(ooObj)::operator=(shortId);
  return *this;
}
inline
ooHandle(ooUnsortedArray)&
ooHandle(ooUnsortedArray)::operator=(const ooUnsortedArray *  fromObject)
{
  this->ooHandle(ooObj)::operator=(ooReinterpretCast(const ooObj *,fromObject));
  return *this;
}
inline
ooUnsortedArray *
ooHandle(ooUnsortedArray)::pin(ooMode  openMode) const
{
  return ooReinterpretCast(ooUnsortedArray *, this->pin_obj_internal(openMode));
}
inline
ooUnsortedArray *
ooHandle(ooUnsortedArray)::operator->() const
{
  return this->vm();
}
inline
ooUnsortedArray &
ooHandle(ooUnsortedArray)::operator*() const
{
  return *(this->vm());
}
inline
ooHandle(ooUnsortedArray)::operator ooUnsortedArray *() const
{
  if ( _state == oocHandlePTR  )
    return ooReinterpretCast(ooUnsortedArray *, _ptr._obj);
  else return ooReinterpretCast(ooUnsortedArray *, this->get_vm());
}
inline
ooUnsortedArray *
ooHandle(ooUnsortedArray)::vm() const
{
  if ( _state == oocHandlePTR && _ptr._obj != NULL )
    return ooReinterpretCast(ooUnsortedArray *, _ptr._obj);
  else return ooReinterpretCast(ooUnsortedArray *, this->get_vm());
}
inline
ooRef(ooUnsortedArray) &
ooHandle(ooUnsortedArray)::copy(const ooHandle(ooObj) &  nearH,
		   ooRef(ooUnsortedArray) &              result) const
{
  this->ooHandle(ooObj)::copy(nearH, result);
  return result;
}


/* ODMG methods */
inline
ooUnsortedArray *
ooRef(ooUnsortedArray)::ptr() const
{
  return this->pin();
}
inline
ooUnsortedArray *
ooHandle(ooUnsortedArray)::ptr() const
{
  return this->operator ooUnsortedArray *();
}
class ooSortedArray;


/////////////////////////////////////////////////////////////////////////////

ooTemplateSpecialization
class CO_STORAGE_SPECIFIER ooDeref(ooSortedArray) : public ooDerefBase {
	friend class ooRef(ooSortedArray);
  public:
    ~ooDerefStructor(ooSortedArray)();
    inline ooSortedArray *operator->() const;
#ifndef OO_BUGGY_TEMPLATES
  private:
#endif // !defined(OO_BUGGY_TEMPLATES)
    ooDerefStructor(ooSortedArray)(ooDeref(ooSortedArray)& deref);
    ooDerefStructor(ooSortedArray)(ooObj *  fromObject);
};


#ifdef OO_BUGGY_TEMPLATES

class CO_STORAGE_SPECIFIER ooHandle_superclass<ooSortedArray > : public ooHandle(ooUnsortedArray) {
 protected:
  ooHandle_superclass()
    {}
  ooHandle_superclass(const ooHandle(ooUnsortedArray) &  from) :
      ooHandle(ooUnsortedArray)(from)
    {}
  ooHandle_superclass(const ooRef(ooUnsortedArray) &  from) :
      ooHandle(ooUnsortedArray)(from)
    {}
  ooHandle_superclass(const ooUnsortedArray *  from) :
      ooHandle(ooUnsortedArray)(from)
    {}
  ~ooHandle_superclass()
    {}
};

class CO_STORAGE_SPECIFIER ooShortRef_superclass<ooSortedArray > : public ooShortRef(ooUnsortedArray) {
};

#endif // OO_BUGGY_TEMPLATES

ooTemplateSpecialization
class CO_STORAGE_SPECIFIER ooRef(ooSortedArray) : public ooRef(ooUnsortedArray) {
  public:
    ooRefStructor(ooSortedArray)()
      {}
    ooRefStructor(ooSortedArray)(const ooRef(ooSortedArray)& id) :
	  ooRef(ooUnsortedArray)(id)
      {}
    inline ooRefStructor(ooSortedArray)(const ooHandleSuper(ooSortedArray)& objH);
    inline ooRefStructor(ooSortedArray)(const ooSortedArray *  fromObject);
    inline ooRef(ooSortedArray)& operator=(const ooRef(ooSortedArray)& id);
    inline ooRef(ooSortedArray)& operator=(const ooShortRefSuper(ooSortedArray) &shortId);
    inline ooRef(ooSortedArray)& operator=(const ooHandleSuper(ooSortedArray)& objH);
    inline ooRef(ooSortedArray)& operator=(const ooSortedArray *  fromObject);
    ooStatus lookupObj(const ooHandle(ooObj)& scopeH,
		       const ooKey& key,
		       ooMode openMode = oocRead);
    ooStatus lookupObj(const ooHandle(ooObj)& scopeH,
		       const char* name,
		       ooMode openMode = oocRead);
#ifndef OO_BUGGY_TEMPLATES
    inline ooRef(ooSortedArray)& copy(const ooHandle(ooObj)& nearH,
		    ooRef(ooSortedArray)& newObjRef) const;
    inline ooHandle(ooSortedArray)& copy(const ooHandle(ooObj)& nearH,
			ooHandle(ooSortedArray)& result) const;
    inline ooHandle(ooSortedArray) copy(const ooHandle(ooObj)& nearH) const;
#endif // !defined(OO_BUGGY_TEMPLATES)
    inline ooSortedArray *pin(ooMode openMode = oocRead) const;
    ooDeref(ooSortedArray) operator->() const;
    /* Use pin() or use ooHandle "operator ooSortedArray *" instead of vm. */
    /* OBSOLETE */ inline ooSortedArray *vm(ooMode openMode = oocRead) const;
    // ODMG methods:
    ooRefStructor(ooSortedArray)(const d_Ref_Any &from);
    ooSortedArray *ptr() const;
};

ooTemplateSpecialization
class CO_STORAGE_SPECIFIER ooShortRef(ooSortedArray) :
#ifdef OO_BUGGY_TEMPLATES
			public ooShortRef_superclass<ooSortedArray >
#else // !defined(OO_BUGGY_TEMPLATES)
			public ooShortRef(ooUnsortedArray)
#endif // !defined(OO_BUGGY_TEMPLATES)
					            {
  public:
    ooShortRefStructor(ooSortedArray)();
    ooShortRefStructor(ooSortedArray)(const ooShortRef(ooSortedArray)& shortId);
    ooShortRefStructor(ooSortedArray)(const ooRef(ooSortedArray)& id);
    ooShortRefStructor(ooSortedArray)(const ooHandleSuper(ooSortedArray) &objH);
    ooShortRefStructor(ooSortedArray)(const ooSortedArray *  fromObject);
    ooShortRef(ooSortedArray)& operator=(const ooShortRef(ooSortedArray)& shortId);
    ooShortRef(ooSortedArray)& operator=(const ooRef(ooSortedArray)& id);
    ooShortRef(ooSortedArray)& operator=(const ooHandleSuper(ooSortedArray) &objH);
    ooShortRef(ooSortedArray)& operator=(const ooSortedArray *  fromObject);
};

ooTemplateSpecialization
class CO_STORAGE_SPECIFIER ooHandle(ooSortedArray) :
#ifdef OO_BUGGY_TEMPLATES
		      public ooHandle_superclass<ooSortedArray >
#else // !defined(OO_BUGGY_TEMPLATES)
		      public ooHandle(ooUnsortedArray)
#endif // !defined(OO_BUGGY_TEMPLATES)
                                                {
  public:
    inline ooHandleStructor(ooSortedArray)();
    inline ooHandleStructor(ooSortedArray)(const ooRef(ooSortedArray)& id);
    inline ooHandleStructor(ooSortedArray)(const ooHandle(ooSortedArray)& objH);
    inline ooHandleStructor(ooSortedArray)(const ooSortedArray *  fromObject);
    inline ooHandle(ooSortedArray)& operator=(const ooRef(ooSortedArray)& id);
    inline ooHandle(ooSortedArray)& operator=(const ooHandle(ooSortedArray)& objH);
    inline ooHandle(ooSortedArray)& operator=(const ooShortRef(ooSortedArray)& shortId);
    inline ooHandle(ooSortedArray)& operator=(const ooSortedArray *  fromObject);
    ooStatus lookupObj(const ooHandle(ooObj)& scopeH,
		       const ooKey& key,
		       ooMode openMode = oocRead);
    ooStatus lookupObj(const ooHandle(ooObj)& scopeH,
		       const char* name,
		       ooMode openMode = oocRead);
    ooHandle(ooSortedArray)& copy(const ooHandle(ooObj)& nearH,
		       ooHandle(ooSortedArray)& result) const;
    inline ooRef(ooSortedArray)& copy(const ooHandle(ooObj)& nearH,
		    ooRef(ooSortedArray)& result) const;
    ooHandle(ooSortedArray) copy(const ooHandle(ooObj)& nearH) const;
    inline ooSortedArray *pin(ooMode openMode = oocRead) const;
    inline ooSortedArray *operator->() const;
    inline ooSortedArray &operator*() const;
    inline operator ooSortedArray *() const;
    /* Use "operator ooSortedArray *" instead of vm. */
    /* OBSOLETE */ inline ooSortedArray *vm() const;
    // ODMG methods:
    ooHandleStructor(ooSortedArray)(const d_Ref_Any &from);
    ooSortedArray *ptr() const;
};

ooTemplateSpecialization
class CO_STORAGE_SPECIFIER ooItr(ooSortedArray) : public ooHandle(ooSortedArray),
		    public ooIteratorObjOrContObj {
  public:
    ooItrStructor(ooSortedArray)();
    ~ooItrStructor(ooSortedArray)();
  private:
    // Defined only to prevent implicit definition:
    ooItrStructor(ooSortedArray)(ooItr(ooSortedArray)&);
    ooItr(ooSortedArray)    operator=(ooItr(ooSortedArray)&);
};


/* methods on ooDeref(ooSortedArray) */
inline
ooDeref(ooSortedArray)::ooDerefStructor(ooSortedArray)(ooDeref(ooSortedArray) &  deref) :
    ooDerefBase(deref.vm())
{
  this->pinCompensate();
}
inline
ooDeref(ooSortedArray)::ooDerefStructor(ooSortedArray)(ooObj *  fromObject) :
    ooDerefBase(fromObject)
{
}
inline
ooDeref(ooSortedArray)::~ooDerefStructor(ooSortedArray)()
{
}
inline
ooSortedArray *
ooDeref(ooSortedArray)::operator->() const
{
  return ooReinterpretCast(ooSortedArray *, this->vm());
}


/* methods on ooRef(ooSortedArray) */
inline
ooRef(ooSortedArray)::ooRefStructor(ooSortedArray)(const ooHandleSuper(ooSortedArray)& objH) :
    ooRef(ooUnsortedArray)(objH)
{
}
inline
ooRef(ooSortedArray)::ooRefStructor(ooSortedArray)(const ooSortedArray *  fromObject) :
    ooRef(ooUnsortedArray)(ooReinterpretCast(const ooUnsortedArray *, fromObject))
{
}
inline
ooRef(ooSortedArray)&
ooRef(ooSortedArray)::operator=(const ooRef(ooSortedArray) &  id)
{
  this->ooId::operator=(id);
  return *this;
}
inline
ooRef(ooSortedArray)&
ooRef(ooSortedArray)::operator=(const ooShortRefSuper(ooSortedArray) &  shortId)
{
  this->ooRef(ooObj)::operator=(shortId);
  return *this;
}
inline
ooRef(ooSortedArray)&
ooRef(ooSortedArray)::operator=(const ooHandleSuper(ooSortedArray) &  objH)
{
  this->ooRef(ooObj)::operator=(objH);
  return *this;
}
inline
ooRef(ooSortedArray)&
ooRef(ooSortedArray)::operator=(const ooSortedArray *  fromObject)
{
  this->ooRef(ooObj)::operator=(ooReinterpretCast(const ooObj *, fromObject));
  return *this;
}
inline
ooSortedArray *
ooRef(ooSortedArray)::pin(ooMode  openMode) const
{
  return ooReinterpretCast(ooSortedArray *, this->pin_ref_internal(openMode));
}
inline
ooSortedArray *
ooRef(ooSortedArray)::vm(ooMode  openMode) const
{
  return this->pin(openMode);
}
#ifndef OO_BUGGY_TEMPLATES
inline
ooHandle(ooSortedArray) &
ooRef(ooSortedArray)::copy(const ooHandle(ooObj) &  nearH,
		ooHandle(ooSortedArray) &           result) const
{
  this->ooRef(ooObj)::copy(nearH, result);
  return result;
}
inline
ooRef(ooSortedArray) &
ooRef(ooSortedArray)::copy(const ooHandle(ooObj) &  nearH,
		ooRef(ooSortedArray) &              newObjRef) const
{
  this->ooRef(ooObj)::copy(nearH, newObjRef);
  return newObjRef;
}
inline
ooHandle(ooSortedArray)
ooRef(ooSortedArray)::copy(const ooHandle(ooObj) &  nearH) const
{
  ooHandle(ooSortedArray) result;
  this->ooRef(ooObj)::copy(nearH, result);
  return result;
}
#endif // !defined(OO_BUGGY_TEMPLATES)
inline
ooDeref(ooSortedArray)
ooRef(ooSortedArray)::operator->() const
{
  ooDeref(ooSortedArray) result(this->pin_ref_internal(oocRead));
  return result;
}


/* methods on ooShortRef(ooSortedArray) */
inline
ooShortRef(ooSortedArray) &
ooShortRef(ooSortedArray)::operator=(const ooShortRef(ooSortedArray) &  shortId)
{
  this->ooShortId::operator=(shortId);
  return *this;
}
inline
ooShortRef(ooSortedArray) &
ooShortRef(ooSortedArray)::operator=(const ooRef(ooSortedArray) &  id)
{
  this->ooShortId::operator=(id);
  return *this;
}
inline
ooShortRef(ooSortedArray) &
ooShortRef(ooSortedArray)::operator=(const ooHandleSuper(ooSortedArray) &  objH)
{
  this->ooShortId::operator=(objH);
  return *this;
}
inline
ooShortRef(ooSortedArray)&
ooShortRef(ooSortedArray)::operator=(const ooSortedArray *  fromObject)
{
  this->ooShortId::operator=(ooReinterpretCast(const ooObj *,fromObject));
  return *this;
}
inline
ooShortRef(ooSortedArray)::ooShortRefStructor(ooSortedArray)()
{
}
#ifdef OO_BUGGY_TEMPLATES
inline
ooShortRef(ooSortedArray)::ooShortRefStructor(ooSortedArray)(const ooShortRef(ooSortedArray) &  shortId)
{
  *this = shortId;
}
#else // !defined(OO_BUGGY_TEMPLATES)
inline
ooShortRef(ooSortedArray)::ooShortRefStructor(ooSortedArray)(const ooShortRef(ooSortedArray) &  shortId) :
    ooShortRef(ooUnsortedArray)(shortId)
{
}
#endif // !defined(OO_BUGGY_TEMPLATES)
#ifdef OO_BUGGY_TEMPLATES
inline
ooShortRef(ooSortedArray)::ooShortRefStructor(ooSortedArray)(const ooRef(ooSortedArray) &  id)
{
  *this = id;
}
#else // !defined(OO_BUGGY_TEMPLATES)
inline
ooShortRef(ooSortedArray)::ooShortRefStructor(ooSortedArray)(const ooRef(ooSortedArray) &  id) :
    ooShortRef(ooUnsortedArray)(id)
{
}
#endif // !defined(OO_BUGGY_TEMPLATES)
#ifdef OO_BUGGY_TEMPLATES
inline
ooShortRef(ooSortedArray)::ooShortRefStructor(ooSortedArray)(const ooHandleSuper(ooSortedArray) &  objH)
{
  *this = objH;
}
#else // !defined(OO_BUGGY_TEMPLATES)
inline
ooShortRef(ooSortedArray)::ooShortRefStructor(ooSortedArray)(const ooHandleSuper(ooSortedArray) &  objH) :
    ooShortRef(ooUnsortedArray)(objH)
{
}
#endif // !defined(OO_BUGGY_TEMPLATES)
#ifdef OO_BUGGY_TEMPLATES
inline
ooShortRef(ooSortedArray)::ooShortRefStructor(ooSortedArray)(const ooSortedArray *  fromObject)
{
  *this = fromObject;
}
#else // !defined(OO_BUGGY_TEMPLATES)
inline
ooShortRef(ooSortedArray)::ooShortRefStructor(ooSortedArray)(const ooSortedArray *  fromObject) :
    ooShortRef(ooUnsortedArray)(ooReinterpretCast(const ooUnsortedArray *,fromObject))
{
}
#endif // !defined(OO_BUGGY_TEMPLATES)


/* methods on ooHandle(ooSortedArray) */
inline
ooHandle(ooSortedArray)::ooHandleStructor(ooSortedArray)()
{
}
inline
ooHandle(ooSortedArray)::ooHandleStructor(ooSortedArray)(const ooHandle(ooSortedArray) &  objH) :
#ifdef OO_BUGGY_TEMPLATES
    ooHandle_superclass<ooSortedArray >(objH)
#else // !defined(OO_BUGGY_TEMPLATES)
    ooHandle(ooUnsortedArray)(objH)
#endif // !defined(OO_BUGGY_TEMPLATES)
{
}
inline
ooHandle(ooSortedArray)::ooHandleStructor(ooSortedArray)(const ooRef(ooSortedArray) &  id) :
#ifdef OO_BUGGY_TEMPLATES
    ooHandle_superclass<ooSortedArray >(id)
#else // !defined(OO_BUGGY_TEMPLATES)
    ooHandle(ooUnsortedArray)(id)
#endif // !defined(OO_BUGGY_TEMPLATES)
{
}
inline
ooHandle(ooSortedArray)::ooHandleStructor(ooSortedArray)(const ooSortedArray *  fromObject) :
#ifdef OO_BUGGY_TEMPLATES
    ooHandle_superclass<ooSortedArray >(ooReinterpretCast(const ooUnsortedArray *,fromObject))
#else // !defined(OO_BUGGY_TEMPLATES)
    ooHandle(ooUnsortedArray)(ooReinterpretCast(const ooUnsortedArray *,fromObject))
#endif // !defined(OO_BUGGY_TEMPLATES)
{
}
inline
ooHandle(ooSortedArray)&
ooHandle(ooSortedArray)::operator=(const ooRef(ooSortedArray) &  id)
{
  this->ooHandle(ooObj)::operator=(id);
  return *this;
}
inline
ooHandle(ooSortedArray)&
ooHandle(ooSortedArray)::operator=(const ooHandle(ooSortedArray) &  objH)
{
  this->ooHandle(ooObj)::operator=(objH);
  return *this;
}
inline
ooHandle(ooSortedArray)&
ooHandle(ooSortedArray)::operator=(const ooShortRef(ooSortedArray) &  shortId)
{
  this->ooHandle(ooObj)::operator=(shortId);
  return *this;
}
inline
ooHandle(ooSortedArray)&
ooHandle(ooSortedArray)::operator=(const ooSortedArray *  fromObject)
{
  this->ooHandle(ooObj)::operator=(ooReinterpretCast(const ooObj *,fromObject));
  return *this;
}
inline
ooSortedArray *
ooHandle(ooSortedArray)::pin(ooMode  openMode) const
{
  return ooReinterpretCast(ooSortedArray *, this->pin_obj_internal(openMode));
}
inline
ooSortedArray *
ooHandle(ooSortedArray)::operator->() const
{
  return this->vm();
}
inline
ooSortedArray &
ooHandle(ooSortedArray)::operator*() const
{
  return *(this->vm());
}
inline
ooHandle(ooSortedArray)::operator ooSortedArray *() const
{
  if ( _state == oocHandlePTR  )
    return ooReinterpretCast(ooSortedArray *, _ptr._obj);
  else return ooReinterpretCast(ooSortedArray *, this->get_vm());
}
inline
ooSortedArray *
ooHandle(ooSortedArray)::vm() const
{
  if ( _state == oocHandlePTR && _ptr._obj != NULL )
    return ooReinterpretCast(ooSortedArray *, _ptr._obj);
  else return ooReinterpretCast(ooSortedArray *, this->get_vm());
}
inline
ooRef(ooSortedArray) &
ooHandle(ooSortedArray)::copy(const ooHandle(ooObj) &  nearH,
		   ooRef(ooSortedArray) &              result) const
{
  this->ooHandle(ooObj)::copy(nearH, result);
  return result;
}


/* ODMG methods */
inline
ooSortedArray *
ooRef(ooSortedArray)::ptr() const
{
  return this->pin();
}
inline
ooSortedArray *
ooHandle(ooSortedArray)::ptr() const
{
  return this->operator ooSortedArray *();
}
class ooBTree;


/////////////////////////////////////////////////////////////////////////////

ooTemplateSpecialization
class CO_STORAGE_SPECIFIER ooDeref(ooBTree) : public ooDerefBase {
	friend class ooRef(ooBTree);
  public:
    ~ooDerefStructor(ooBTree)();
    inline ooBTree *operator->() const;
#ifndef OO_BUGGY_TEMPLATES
  private:
#endif // !defined(OO_BUGGY_TEMPLATES)
    ooDerefStructor(ooBTree)(ooDeref(ooBTree)& deref);
    ooDerefStructor(ooBTree)(ooObj *  fromObject);
};


#ifdef OO_BUGGY_TEMPLATES

class CO_STORAGE_SPECIFIER ooHandle_superclass<ooBTree > : public ooHandle(ooCollection) {
 protected:
  ooHandle_superclass()
    {}
  ooHandle_superclass(const ooHandle(ooCollection) &  from) :
      ooHandle(ooCollection)(from)
    {}
  ooHandle_superclass(const ooRef(ooCollection) &  from) :
      ooHandle(ooCollection)(from)
    {}
  ooHandle_superclass(const ooCollection *  from) :
      ooHandle(ooCollection)(from)
    {}
  ~ooHandle_superclass()
    {}
};

class CO_STORAGE_SPECIFIER ooShortRef_superclass<ooBTree > : public ooShortRef(ooCollection) {
};

#endif // OO_BUGGY_TEMPLATES

ooTemplateSpecialization
class CO_STORAGE_SPECIFIER ooRef(ooBTree) : public ooRef(ooCollection) {
  public:
    ooRefStructor(ooBTree)()
      {}
    ooRefStructor(ooBTree)(const ooRef(ooBTree)& id) :
	  ooRef(ooCollection)(id)
      {}
    inline ooRefStructor(ooBTree)(const ooHandleSuper(ooBTree)& objH);
    inline ooRefStructor(ooBTree)(const ooBTree *  fromObject);
    inline ooRef(ooBTree)& operator=(const ooRef(ooBTree)& id);
    inline ooRef(ooBTree)& operator=(const ooShortRefSuper(ooBTree) &shortId);
    inline ooRef(ooBTree)& operator=(const ooHandleSuper(ooBTree)& objH);
    inline ooRef(ooBTree)& operator=(const ooBTree *  fromObject);
    ooStatus lookupObj(const ooHandle(ooObj)& scopeH,
		       const ooKey& key,
		       ooMode openMode = oocRead);
    ooStatus lookupObj(const ooHandle(ooObj)& scopeH,
		       const char* name,
		       ooMode openMode = oocRead);
#ifndef OO_BUGGY_TEMPLATES
    inline ooRef(ooBTree)& copy(const ooHandle(ooObj)& nearH,
		    ooRef(ooBTree)& newObjRef) const;
    inline ooHandle(ooBTree)& copy(const ooHandle(ooObj)& nearH,
			ooHandle(ooBTree)& result) const;
    inline ooHandle(ooBTree) copy(const ooHandle(ooObj)& nearH) const;
#endif // !defined(OO_BUGGY_TEMPLATES)
    inline ooBTree *pin(ooMode openMode = oocRead) const;
    ooDeref(ooBTree) operator->() const;
    /* Use pin() or use ooHandle "operator ooBTree *" instead of vm. */
    /* OBSOLETE */ inline ooBTree *vm(ooMode openMode = oocRead) const;
    // ODMG methods:
    ooRefStructor(ooBTree)(const d_Ref_Any &from);
    ooBTree *ptr() const;
};

ooTemplateSpecialization
class CO_STORAGE_SPECIFIER ooShortRef(ooBTree) :
#ifdef OO_BUGGY_TEMPLATES
			public ooShortRef_superclass<ooBTree >
#else // !defined(OO_BUGGY_TEMPLATES)
			public ooShortRef(ooCollection)
#endif // !defined(OO_BUGGY_TEMPLATES)
					            {
  public:
    ooShortRefStructor(ooBTree)();
    ooShortRefStructor(ooBTree)(const ooShortRef(ooBTree)& shortId);
    ooShortRefStructor(ooBTree)(const ooRef(ooBTree)& id);
    ooShortRefStructor(ooBTree)(const ooHandleSuper(ooBTree) &objH);
    ooShortRefStructor(ooBTree)(const ooBTree *  fromObject);
    ooShortRef(ooBTree)& operator=(const ooShortRef(ooBTree)& shortId);
    ooShortRef(ooBTree)& operator=(const ooRef(ooBTree)& id);
    ooShortRef(ooBTree)& operator=(const ooHandleSuper(ooBTree) &objH);
    ooShortRef(ooBTree)& operator=(const ooBTree *  fromObject);
};

ooTemplateSpecialization
class CO_STORAGE_SPECIFIER ooHandle(ooBTree) :
#ifdef OO_BUGGY_TEMPLATES
		      public ooHandle_superclass<ooBTree >
#else // !defined(OO_BUGGY_TEMPLATES)
		      public ooHandle(ooCollection)
#endif // !defined(OO_BUGGY_TEMPLATES)
                                                {
  public:
    inline ooHandleStructor(ooBTree)();
    inline ooHandleStructor(ooBTree)(const ooRef(ooBTree)& id);
    inline ooHandleStructor(ooBTree)(const ooHandle(ooBTree)& objH);
    inline ooHandleStructor(ooBTree)(const ooBTree *  fromObject);
    inline ooHandle(ooBTree)& operator=(const ooRef(ooBTree)& id);
    inline ooHandle(ooBTree)& operator=(const ooHandle(ooBTree)& objH);
    inline ooHandle(ooBTree)& operator=(const ooShortRef(ooBTree)& shortId);
    inline ooHandle(ooBTree)& operator=(const ooBTree *  fromObject);
    ooStatus lookupObj(const ooHandle(ooObj)& scopeH,
		       const ooKey& key,
		       ooMode openMode = oocRead);
    ooStatus lookupObj(const ooHandle(ooObj)& scopeH,
		       const char* name,
		       ooMode openMode = oocRead);
    ooHandle(ooBTree)& copy(const ooHandle(ooObj)& nearH,
		       ooHandle(ooBTree)& result) const;
    inline ooRef(ooBTree)& copy(const ooHandle(ooObj)& nearH,
		    ooRef(ooBTree)& result) const;
    ooHandle(ooBTree) copy(const ooHandle(ooObj)& nearH) const;
    inline ooBTree *pin(ooMode openMode = oocRead) const;
    inline ooBTree *operator->() const;
    inline ooBTree &operator*() const;
    inline operator ooBTree *() const;
    /* Use "operator ooBTree *" instead of vm. */
    /* OBSOLETE */ inline ooBTree *vm() const;
    // ODMG methods:
    ooHandleStructor(ooBTree)(const d_Ref_Any &from);
    ooBTree *ptr() const;
};

ooTemplateSpecialization
class CO_STORAGE_SPECIFIER ooItr(ooBTree) : public ooHandle(ooBTree),
		    public ooIteratorObjOrContObj {
  public:
    ooItrStructor(ooBTree)();
    ~ooItrStructor(ooBTree)();
  private:
    // Defined only to prevent implicit definition:
    ooItrStructor(ooBTree)(ooItr(ooBTree)&);
    ooItr(ooBTree)    operator=(ooItr(ooBTree)&);
};


/* methods on ooDeref(ooBTree) */
inline
ooDeref(ooBTree)::ooDerefStructor(ooBTree)(ooDeref(ooBTree) &  deref) :
    ooDerefBase(deref.vm())
{
  this->pinCompensate();
}
inline
ooDeref(ooBTree)::ooDerefStructor(ooBTree)(ooObj *  fromObject) :
    ooDerefBase(fromObject)
{
}
inline
ooDeref(ooBTree)::~ooDerefStructor(ooBTree)()
{
}
inline
ooBTree *
ooDeref(ooBTree)::operator->() const
{
  return ooReinterpretCast(ooBTree *, this->vm());
}


/* methods on ooRef(ooBTree) */
inline
ooRef(ooBTree)::ooRefStructor(ooBTree)(const ooHandleSuper(ooBTree)& objH) :
    ooRef(ooCollection)(objH)
{
}
inline
ooRef(ooBTree)::ooRefStructor(ooBTree)(const ooBTree *  fromObject) :
    ooRef(ooCollection)(ooReinterpretCast(const ooCollection *, fromObject))
{
}
inline
ooRef(ooBTree)&
ooRef(ooBTree)::operator=(const ooRef(ooBTree) &  id)
{
  this->ooId::operator=(id);
  return *this;
}
inline
ooRef(ooBTree)&
ooRef(ooBTree)::operator=(const ooShortRefSuper(ooBTree) &  shortId)
{
  this->ooRef(ooObj)::operator=(shortId);
  return *this;
}
inline
ooRef(ooBTree)&
ooRef(ooBTree)::operator=(const ooHandleSuper(ooBTree) &  objH)
{
  this->ooRef(ooObj)::operator=(objH);
  return *this;
}
inline
ooRef(ooBTree)&
ooRef(ooBTree)::operator=(const ooBTree *  fromObject)
{
  this->ooRef(ooObj)::operator=(ooReinterpretCast(const ooObj *, fromObject));
  return *this;
}
inline
ooBTree *
ooRef(ooBTree)::pin(ooMode  openMode) const
{
  return ooReinterpretCast(ooBTree *, this->pin_ref_internal(openMode));
}
inline
ooBTree *
ooRef(ooBTree)::vm(ooMode  openMode) const
{
  return this->pin(openMode);
}
#ifndef OO_BUGGY_TEMPLATES
inline
ooHandle(ooBTree) &
ooRef(ooBTree)::copy(const ooHandle(ooObj) &  nearH,
		ooHandle(ooBTree) &           result) const
{
  this->ooRef(ooObj)::copy(nearH, result);
  return result;
}
inline
ooRef(ooBTree) &
ooRef(ooBTree)::copy(const ooHandle(ooObj) &  nearH,
		ooRef(ooBTree) &              newObjRef) const
{
  this->ooRef(ooObj)::copy(nearH, newObjRef);
  return newObjRef;
}
inline
ooHandle(ooBTree)
ooRef(ooBTree)::copy(const ooHandle(ooObj) &  nearH) const
{
  ooHandle(ooBTree) result;
  this->ooRef(ooObj)::copy(nearH, result);
  return result;
}
#endif // !defined(OO_BUGGY_TEMPLATES)
inline
ooDeref(ooBTree)
ooRef(ooBTree)::operator->() const
{
  ooDeref(ooBTree) result(this->pin_ref_internal(oocRead));
  return result;
}


/* methods on ooShortRef(ooBTree) */
inline
ooShortRef(ooBTree) &
ooShortRef(ooBTree)::operator=(const ooShortRef(ooBTree) &  shortId)
{
  this->ooShortId::operator=(shortId);
  return *this;
}
inline
ooShortRef(ooBTree) &
ooShortRef(ooBTree)::operator=(const ooRef(ooBTree) &  id)
{
  this->ooShortId::operator=(id);
  return *this;
}
inline
ooShortRef(ooBTree) &
ooShortRef(ooBTree)::operator=(const ooHandleSuper(ooBTree) &  objH)
{
  this->ooShortId::operator=(objH);
  return *this;
}
inline
ooShortRef(ooBTree)&
ooShortRef(ooBTree)::operator=(const ooBTree *  fromObject)
{
  this->ooShortId::operator=(ooReinterpretCast(const ooObj *,fromObject));
  return *this;
}
inline
ooShortRef(ooBTree)::ooShortRefStructor(ooBTree)()
{
}
#ifdef OO_BUGGY_TEMPLATES
inline
ooShortRef(ooBTree)::ooShortRefStructor(ooBTree)(const ooShortRef(ooBTree) &  shortId)
{
  *this = shortId;
}
#else // !defined(OO_BUGGY_TEMPLATES)
inline
ooShortRef(ooBTree)::ooShortRefStructor(ooBTree)(const ooShortRef(ooBTree) &  shortId) :
    ooShortRef(ooCollection)(shortId)
{
}
#endif // !defined(OO_BUGGY_TEMPLATES)
#ifdef OO_BUGGY_TEMPLATES
inline
ooShortRef(ooBTree)::ooShortRefStructor(ooBTree)(const ooRef(ooBTree) &  id)
{
  *this = id;
}
#else // !defined(OO_BUGGY_TEMPLATES)
inline
ooShortRef(ooBTree)::ooShortRefStructor(ooBTree)(const ooRef(ooBTree) &  id) :
    ooShortRef(ooCollection)(id)
{
}
#endif // !defined(OO_BUGGY_TEMPLATES)
#ifdef OO_BUGGY_TEMPLATES
inline
ooShortRef(ooBTree)::ooShortRefStructor(ooBTree)(const ooHandleSuper(ooBTree) &  objH)
{
  *this = objH;
}
#else // !defined(OO_BUGGY_TEMPLATES)
inline
ooShortRef(ooBTree)::ooShortRefStructor(ooBTree)(const ooHandleSuper(ooBTree) &  objH) :
    ooShortRef(ooCollection)(objH)
{
}
#endif // !defined(OO_BUGGY_TEMPLATES)
#ifdef OO_BUGGY_TEMPLATES
inline
ooShortRef(ooBTree)::ooShortRefStructor(ooBTree)(const ooBTree *  fromObject)
{
  *this = fromObject;
}
#else // !defined(OO_BUGGY_TEMPLATES)
inline
ooShortRef(ooBTree)::ooShortRefStructor(ooBTree)(const ooBTree *  fromObject) :
    ooShortRef(ooCollection)(ooReinterpretCast(const ooCollection *,fromObject))
{
}
#endif // !defined(OO_BUGGY_TEMPLATES)


/* methods on ooHandle(ooBTree) */
inline
ooHandle(ooBTree)::ooHandleStructor(ooBTree)()
{
}
inline
ooHandle(ooBTree)::ooHandleStructor(ooBTree)(const ooHandle(ooBTree) &  objH) :
#ifdef OO_BUGGY_TEMPLATES
    ooHandle_superclass<ooBTree >(objH)
#else // !defined(OO_BUGGY_TEMPLATES)
    ooHandle(ooCollection)(objH)
#endif // !defined(OO_BUGGY_TEMPLATES)
{
}
inline
ooHandle(ooBTree)::ooHandleStructor(ooBTree)(const ooRef(ooBTree) &  id) :
#ifdef OO_BUGGY_TEMPLATES
    ooHandle_superclass<ooBTree >(id)
#else // !defined(OO_BUGGY_TEMPLATES)
    ooHandle(ooCollection)(id)
#endif // !defined(OO_BUGGY_TEMPLATES)
{
}
inline
ooHandle(ooBTree)::ooHandleStructor(ooBTree)(const ooBTree *  fromObject) :
#ifdef OO_BUGGY_TEMPLATES
    ooHandle_superclass<ooBTree >(ooReinterpretCast(const ooCollection *,fromObject))
#else // !defined(OO_BUGGY_TEMPLATES)
    ooHandle(ooCollection)(ooReinterpretCast(const ooCollection *,fromObject))
#endif // !defined(OO_BUGGY_TEMPLATES)
{
}
inline
ooHandle(ooBTree)&
ooHandle(ooBTree)::operator=(const ooRef(ooBTree) &  id)
{
  this->ooHandle(ooObj)::operator=(id);
  return *this;
}
inline
ooHandle(ooBTree)&
ooHandle(ooBTree)::operator=(const ooHandle(ooBTree) &  objH)
{
  this->ooHandle(ooObj)::operator=(objH);
  return *this;
}
inline
ooHandle(ooBTree)&
ooHandle(ooBTree)::operator=(const ooShortRef(ooBTree) &  shortId)
{
  this->ooHandle(ooObj)::operator=(shortId);
  return *this;
}
inline
ooHandle(ooBTree)&
ooHandle(ooBTree)::operator=(const ooBTree *  fromObject)
{
  this->ooHandle(ooObj)::operator=(ooReinterpretCast(const ooObj *,fromObject));
  return *this;
}
inline
ooBTree *
ooHandle(ooBTree)::pin(ooMode  openMode) const
{
  return ooReinterpretCast(ooBTree *, this->pin_obj_internal(openMode));
}
inline
ooBTree *
ooHandle(ooBTree)::operator->() const
{
  return this->vm();
}
inline
ooBTree &
ooHandle(ooBTree)::operator*() const
{
  return *(this->vm());
}
inline
ooHandle(ooBTree)::operator ooBTree *() const
{
  if ( _state == oocHandlePTR  )
    return ooReinterpretCast(ooBTree *, _ptr._obj);
  else return ooReinterpretCast(ooBTree *, this->get_vm());
}
inline
ooBTree *
ooHandle(ooBTree)::vm() const
{
  if ( _state == oocHandlePTR && _ptr._obj != NULL )
    return ooReinterpretCast(ooBTree *, _ptr._obj);
  else return ooReinterpretCast(ooBTree *, this->get_vm());
}
inline
ooRef(ooBTree) &
ooHandle(ooBTree)::copy(const ooHandle(ooObj) &  nearH,
		   ooRef(ooBTree) &              result) const
{
  this->ooHandle(ooObj)::copy(nearH, result);
  return result;
}


/* ODMG methods */
inline
ooBTree *
ooRef(ooBTree)::ptr() const
{
  return this->pin();
}
inline
ooBTree *
ooHandle(ooBTree)::ptr() const
{
  return this->operator ooBTree *();
}
class ooBTreeNode;


/////////////////////////////////////////////////////////////////////////////

ooTemplateSpecialization
class CO_STORAGE_SPECIFIER ooDeref(ooBTreeNode) : public ooDerefBase {
	friend class ooRef(ooBTreeNode);
  public:
    ~ooDerefStructor(ooBTreeNode)();
    inline ooBTreeNode *operator->() const;
#ifndef OO_BUGGY_TEMPLATES
  private:
#endif // !defined(OO_BUGGY_TEMPLATES)
    ooDerefStructor(ooBTreeNode)(ooDeref(ooBTreeNode)& deref);
    ooDerefStructor(ooBTreeNode)(ooObj *  fromObject);
};


#ifdef OO_BUGGY_TEMPLATES

class CO_STORAGE_SPECIFIER ooHandle_superclass<ooBTreeNode > : public ooHandle(ooBTree) {
 protected:
  ooHandle_superclass()
    {}
  ooHandle_superclass(const ooHandle(ooBTree) &  from) :
      ooHandle(ooBTree)(from)
    {}
  ooHandle_superclass(const ooRef(ooBTree) &  from) :
      ooHandle(ooBTree)(from)
    {}
  ooHandle_superclass(const ooBTree *  from) :
      ooHandle(ooBTree)(from)
    {}
  ~ooHandle_superclass()
    {}
};

class CO_STORAGE_SPECIFIER ooShortRef_superclass<ooBTreeNode > : public ooShortRef(ooBTree) {
};

#endif // OO_BUGGY_TEMPLATES

ooTemplateSpecialization
class CO_STORAGE_SPECIFIER ooRef(ooBTreeNode) : public ooRef(ooBTree) {
  public:
    ooRefStructor(ooBTreeNode)()
      {}
    ooRefStructor(ooBTreeNode)(const ooRef(ooBTreeNode)& id) :
	  ooRef(ooBTree)(id)
      {}
    inline ooRefStructor(ooBTreeNode)(const ooHandleSuper(ooBTreeNode)& objH);
    inline ooRefStructor(ooBTreeNode)(const ooBTreeNode *  fromObject);
    inline ooRef(ooBTreeNode)& operator=(const ooRef(ooBTreeNode)& id);
    inline ooRef(ooBTreeNode)& operator=(const ooShortRefSuper(ooBTreeNode) &shortId);
    inline ooRef(ooBTreeNode)& operator=(const ooHandleSuper(ooBTreeNode)& objH);
    inline ooRef(ooBTreeNode)& operator=(const ooBTreeNode *  fromObject);
    ooStatus lookupObj(const ooHandle(ooObj)& scopeH,
		       const ooKey& key,
		       ooMode openMode = oocRead);
    ooStatus lookupObj(const ooHandle(ooObj)& scopeH,
		       const char* name,
		       ooMode openMode = oocRead);
#ifndef OO_BUGGY_TEMPLATES
    inline ooRef(ooBTreeNode)& copy(const ooHandle(ooObj)& nearH,
		    ooRef(ooBTreeNode)& newObjRef) const;
    inline ooHandle(ooBTreeNode)& copy(const ooHandle(ooObj)& nearH,
			ooHandle(ooBTreeNode)& result) const;
    inline ooHandle(ooBTreeNode) copy(const ooHandle(ooObj)& nearH) const;
#endif // !defined(OO_BUGGY_TEMPLATES)
    inline ooBTreeNode *pin(ooMode openMode = oocRead) const;
    ooDeref(ooBTreeNode) operator->() const;
    /* Use pin() or use ooHandle "operator ooBTreeNode *" instead of vm. */
    /* OBSOLETE */ inline ooBTreeNode *vm(ooMode openMode = oocRead) const;
    // ODMG methods:
    ooRefStructor(ooBTreeNode)(const d_Ref_Any &from);
    ooBTreeNode *ptr() const;
};

ooTemplateSpecialization
class CO_STORAGE_SPECIFIER ooShortRef(ooBTreeNode) :
#ifdef OO_BUGGY_TEMPLATES
			public ooShortRef_superclass<ooBTreeNode >
#else // !defined(OO_BUGGY_TEMPLATES)
			public ooShortRef(ooBTree)
#endif // !defined(OO_BUGGY_TEMPLATES)
					            {
  public:
    ooShortRefStructor(ooBTreeNode)();
    ooShortRefStructor(ooBTreeNode)(const ooShortRef(ooBTreeNode)& shortId);
    ooShortRefStructor(ooBTreeNode)(const ooRef(ooBTreeNode)& id);
    ooShortRefStructor(ooBTreeNode)(const ooHandleSuper(ooBTreeNode) &objH);
    ooShortRefStructor(ooBTreeNode)(const ooBTreeNode *  fromObject);
    ooShortRef(ooBTreeNode)& operator=(const ooShortRef(ooBTreeNode)& shortId);
    ooShortRef(ooBTreeNode)& operator=(const ooRef(ooBTreeNode)& id);
    ooShortRef(ooBTreeNode)& operator=(const ooHandleSuper(ooBTreeNode) &objH);
    ooShortRef(ooBTreeNode)& operator=(const ooBTreeNode *  fromObject);
};

ooTemplateSpecialization
class CO_STORAGE_SPECIFIER ooHandle(ooBTreeNode) :
#ifdef OO_BUGGY_TEMPLATES
		      public ooHandle_superclass<ooBTreeNode >
#else // !defined(OO_BUGGY_TEMPLATES)
		      public ooHandle(ooBTree)
#endif // !defined(OO_BUGGY_TEMPLATES)
                                                {
  public:
    inline ooHandleStructor(ooBTreeNode)();
    inline ooHandleStructor(ooBTreeNode)(const ooRef(ooBTreeNode)& id);
    inline ooHandleStructor(ooBTreeNode)(const ooHandle(ooBTreeNode)& objH);
    inline ooHandleStructor(ooBTreeNode)(const ooBTreeNode *  fromObject);
    inline ooHandle(ooBTreeNode)& operator=(const ooRef(ooBTreeNode)& id);
    inline ooHandle(ooBTreeNode)& operator=(const ooHandle(ooBTreeNode)& objH);
    inline ooHandle(ooBTreeNode)& operator=(const ooShortRef(ooBTreeNode)& shortId);
    inline ooHandle(ooBTreeNode)& operator=(const ooBTreeNode *  fromObject);
    ooStatus lookupObj(const ooHandle(ooObj)& scopeH,
		       const ooKey& key,
		       ooMode openMode = oocRead);
    ooStatus lookupObj(const ooHandle(ooObj)& scopeH,
		       const char* name,
		       ooMode openMode = oocRead);
    ooHandle(ooBTreeNode)& copy(const ooHandle(ooObj)& nearH,
		       ooHandle(ooBTreeNode)& result) const;
    inline ooRef(ooBTreeNode)& copy(const ooHandle(ooObj)& nearH,
		    ooRef(ooBTreeNode)& result) const;
    ooHandle(ooBTreeNode) copy(const ooHandle(ooObj)& nearH) const;
    inline ooBTreeNode *pin(ooMode openMode = oocRead) const;
    inline ooBTreeNode *operator->() const;
    inline ooBTreeNode &operator*() const;
    inline operator ooBTreeNode *() const;
    /* Use "operator ooBTreeNode *" instead of vm. */
    /* OBSOLETE */ inline ooBTreeNode *vm() const;
    // ODMG methods:
    ooHandleStructor(ooBTreeNode)(const d_Ref_Any &from);
    ooBTreeNode *ptr() const;
};

ooTemplateSpecialization
class CO_STORAGE_SPECIFIER ooItr(ooBTreeNode) : public ooHandle(ooBTreeNode),
		    public ooIteratorObjOrContObj {
  public:
    ooItrStructor(ooBTreeNode)();
    ~ooItrStructor(ooBTreeNode)();
  private:
    // Defined only to prevent implicit definition:
    ooItrStructor(ooBTreeNode)(ooItr(ooBTreeNode)&);
    ooItr(ooBTreeNode)    operator=(ooItr(ooBTreeNode)&);
};


/* methods on ooDeref(ooBTreeNode) */
inline
ooDeref(ooBTreeNode)::ooDerefStructor(ooBTreeNode)(ooDeref(ooBTreeNode) &  deref) :
    ooDerefBase(deref.vm())
{
  this->pinCompensate();
}
inline
ooDeref(ooBTreeNode)::ooDerefStructor(ooBTreeNode)(ooObj *  fromObject) :
    ooDerefBase(fromObject)
{
}
inline
ooDeref(ooBTreeNode)::~ooDerefStructor(ooBTreeNode)()
{
}
inline
ooBTreeNode *
ooDeref(ooBTreeNode)::operator->() const
{
  return ooReinterpretCast(ooBTreeNode *, this->vm());
}


/* methods on ooRef(ooBTreeNode) */
inline
ooRef(ooBTreeNode)::ooRefStructor(ooBTreeNode)(const ooHandleSuper(ooBTreeNode)& objH) :
    ooRef(ooBTree)(objH)
{
}
inline
ooRef(ooBTreeNode)::ooRefStructor(ooBTreeNode)(const ooBTreeNode *  fromObject) :
    ooRef(ooBTree)(ooReinterpretCast(const ooBTree *, fromObject))
{
}
inline
ooRef(ooBTreeNode)&
ooRef(ooBTreeNode)::operator=(const ooRef(ooBTreeNode) &  id)
{
  this->ooId::operator=(id);
  return *this;
}
inline
ooRef(ooBTreeNode)&
ooRef(ooBTreeNode)::operator=(const ooShortRefSuper(ooBTreeNode) &  shortId)
{
  this->ooRef(ooObj)::operator=(shortId);
  return *this;
}
inline
ooRef(ooBTreeNode)&
ooRef(ooBTreeNode)::operator=(const ooHandleSuper(ooBTreeNode) &  objH)
{
  this->ooRef(ooObj)::operator=(objH);
  return *this;
}
inline
ooRef(ooBTreeNode)&
ooRef(ooBTreeNode)::operator=(const ooBTreeNode *  fromObject)
{
  this->ooRef(ooObj)::operator=(ooReinterpretCast(const ooObj *, fromObject));
  return *this;
}
inline
ooBTreeNode *
ooRef(ooBTreeNode)::pin(ooMode  openMode) const
{
  return ooReinterpretCast(ooBTreeNode *, this->pin_ref_internal(openMode));
}
inline
ooBTreeNode *
ooRef(ooBTreeNode)::vm(ooMode  openMode) const
{
  return this->pin(openMode);
}
#ifndef OO_BUGGY_TEMPLATES
inline
ooHandle(ooBTreeNode) &
ooRef(ooBTreeNode)::copy(const ooHandle(ooObj) &  nearH,
		ooHandle(ooBTreeNode) &           result) const
{
  this->ooRef(ooObj)::copy(nearH, result);
  return result;
}
inline
ooRef(ooBTreeNode) &
ooRef(ooBTreeNode)::copy(const ooHandle(ooObj) &  nearH,
		ooRef(ooBTreeNode) &              newObjRef) const
{
  this->ooRef(ooObj)::copy(nearH, newObjRef);
  return newObjRef;
}
inline
ooHandle(ooBTreeNode)
ooRef(ooBTreeNode)::copy(const ooHandle(ooObj) &  nearH) const
{
  ooHandle(ooBTreeNode) result;
  this->ooRef(ooObj)::copy(nearH, result);
  return result;
}
#endif // !defined(OO_BUGGY_TEMPLATES)
inline
ooDeref(ooBTreeNode)
ooRef(ooBTreeNode)::operator->() const
{
  ooDeref(ooBTreeNode) result(this->pin_ref_internal(oocRead));
  return result;
}


/* methods on ooShortRef(ooBTreeNode) */
inline
ooShortRef(ooBTreeNode) &
ooShortRef(ooBTreeNode)::operator=(const ooShortRef(ooBTreeNode) &  shortId)
{
  this->ooShortId::operator=(shortId);
  return *this;
}
inline
ooShortRef(ooBTreeNode) &
ooShortRef(ooBTreeNode)::operator=(const ooRef(ooBTreeNode) &  id)
{
  this->ooShortId::operator=(id);
  return *this;
}
inline
ooShortRef(ooBTreeNode) &
ooShortRef(ooBTreeNode)::operator=(const ooHandleSuper(ooBTreeNode) &  objH)
{
  this->ooShortId::operator=(objH);
  return *this;
}
inline
ooShortRef(ooBTreeNode)&
ooShortRef(ooBTreeNode)::operator=(const ooBTreeNode *  fromObject)
{
  this->ooShortId::operator=(ooReinterpretCast(const ooObj *,fromObject));
  return *this;
}
inline
ooShortRef(ooBTreeNode)::ooShortRefStructor(ooBTreeNode)()
{
}
#ifdef OO_BUGGY_TEMPLATES
inline
ooShortRef(ooBTreeNode)::ooShortRefStructor(ooBTreeNode)(const ooShortRef(ooBTreeNode) &  shortId)
{
  *this = shortId;
}
#else // !defined(OO_BUGGY_TEMPLATES)
inline
ooShortRef(ooBTreeNode)::ooShortRefStructor(ooBTreeNode)(const ooShortRef(ooBTreeNode) &  shortId) :
    ooShortRef(ooBTree)(shortId)
{
}
#endif // !defined(OO_BUGGY_TEMPLATES)
#ifdef OO_BUGGY_TEMPLATES
inline
ooShortRef(ooBTreeNode)::ooShortRefStructor(ooBTreeNode)(const ooRef(ooBTreeNode) &  id)
{
  *this = id;
}
#else // !defined(OO_BUGGY_TEMPLATES)
inline
ooShortRef(ooBTreeNode)::ooShortRefStructor(ooBTreeNode)(const ooRef(ooBTreeNode) &  id) :
    ooShortRef(ooBTree)(id)
{
}
#endif // !defined(OO_BUGGY_TEMPLATES)
#ifdef OO_BUGGY_TEMPLATES
inline
ooShortRef(ooBTreeNode)::ooShortRefStructor(ooBTreeNode)(const ooHandleSuper(ooBTreeNode) &  objH)
{
  *this = objH;
}
#else // !defined(OO_BUGGY_TEMPLATES)
inline
ooShortRef(ooBTreeNode)::ooShortRefStructor(ooBTreeNode)(const ooHandleSuper(ooBTreeNode) &  objH) :
    ooShortRef(ooBTree)(objH)
{
}
#endif // !defined(OO_BUGGY_TEMPLATES)
#ifdef OO_BUGGY_TEMPLATES
inline
ooShortRef(ooBTreeNode)::ooShortRefStructor(ooBTreeNode)(const ooBTreeNode *  fromObject)
{
  *this = fromObject;
}
#else // !defined(OO_BUGGY_TEMPLATES)
inline
ooShortRef(ooBTreeNode)::ooShortRefStructor(ooBTreeNode)(const ooBTreeNode *  fromObject) :
    ooShortRef(ooBTree)(ooReinterpretCast(const ooBTree *,fromObject))
{
}
#endif // !defined(OO_BUGGY_TEMPLATES)


/* methods on ooHandle(ooBTreeNode) */
inline
ooHandle(ooBTreeNode)::ooHandleStructor(ooBTreeNode)()
{
}
inline
ooHandle(ooBTreeNode)::ooHandleStructor(ooBTreeNode)(const ooHandle(ooBTreeNode) &  objH) :
#ifdef OO_BUGGY_TEMPLATES
    ooHandle_superclass<ooBTreeNode >(objH)
#else // !defined(OO_BUGGY_TEMPLATES)
    ooHandle(ooBTree)(objH)
#endif // !defined(OO_BUGGY_TEMPLATES)
{
}
inline
ooHandle(ooBTreeNode)::ooHandleStructor(ooBTreeNode)(const ooRef(ooBTreeNode) &  id) :
#ifdef OO_BUGGY_TEMPLATES
    ooHandle_superclass<ooBTreeNode >(id)
#else // !defined(OO_BUGGY_TEMPLATES)
    ooHandle(ooBTree)(id)
#endif // !defined(OO_BUGGY_TEMPLATES)
{
}
inline
ooHandle(ooBTreeNode)::ooHandleStructor(ooBTreeNode)(const ooBTreeNode *  fromObject) :
#ifdef OO_BUGGY_TEMPLATES
    ooHandle_superclass<ooBTreeNode >(ooReinterpretCast(const ooBTree *,fromObject))
#else // !defined(OO_BUGGY_TEMPLATES)
    ooHandle(ooBTree)(ooReinterpretCast(const ooBTree *,fromObject))
#endif // !defined(OO_BUGGY_TEMPLATES)
{
}
inline
ooHandle(ooBTreeNode)&
ooHandle(ooBTreeNode)::operator=(const ooRef(ooBTreeNode) &  id)
{
  this->ooHandle(ooObj)::operator=(id);
  return *this;
}
inline
ooHandle(ooBTreeNode)&
ooHandle(ooBTreeNode)::operator=(const ooHandle(ooBTreeNode) &  objH)
{
  this->ooHandle(ooObj)::operator=(objH);
  return *this;
}
inline
ooHandle(ooBTreeNode)&
ooHandle(ooBTreeNode)::operator=(const ooShortRef(ooBTreeNode) &  shortId)
{
  this->ooHandle(ooObj)::operator=(shortId);
  return *this;
}
inline
ooHandle(ooBTreeNode)&
ooHandle(ooBTreeNode)::operator=(const ooBTreeNode *  fromObject)
{
  this->ooHandle(ooObj)::operator=(ooReinterpretCast(const ooObj *,fromObject));
  return *this;
}
inline
ooBTreeNode *
ooHandle(ooBTreeNode)::pin(ooMode  openMode) const
{
  return ooReinterpretCast(ooBTreeNode *, this->pin_obj_internal(openMode));
}
inline
ooBTreeNode *
ooHandle(ooBTreeNode)::operator->() const
{
  return this->vm();
}
inline
ooBTreeNode &
ooHandle(ooBTreeNode)::operator*() const
{
  return *(this->vm());
}
inline
ooHandle(ooBTreeNode)::operator ooBTreeNode *() const
{
  if ( _state == oocHandlePTR  )
    return ooReinterpretCast(ooBTreeNode *, _ptr._obj);
  else return ooReinterpretCast(ooBTreeNode *, this->get_vm());
}
inline
ooBTreeNode *
ooHandle(ooBTreeNode)::vm() const
{
  if ( _state == oocHandlePTR && _ptr._obj != NULL )
    return ooReinterpretCast(ooBTreeNode *, _ptr._obj);
  else return ooReinterpretCast(ooBTreeNode *, this->get_vm());
}
inline
ooRef(ooBTreeNode) &
ooHandle(ooBTreeNode)::copy(const ooHandle(ooObj) &  nearH,
		   ooRef(ooBTreeNode) &              result) const
{
  this->ooHandle(ooObj)::copy(nearH, result);
  return result;
}


/* ODMG methods */
inline
ooBTreeNode *
ooRef(ooBTreeNode)::ptr() const
{
  return this->pin();
}
inline
ooBTreeNode *
ooHandle(ooBTreeNode)::ptr() const
{
  return this->operator ooBTreeNode *();
}
class ooTreeSet;


/////////////////////////////////////////////////////////////////////////////

ooTemplateSpecialization
class CO_STORAGE_SPECIFIER ooDeref(ooTreeSet) : public ooDerefBase {
	friend class ooRef(ooTreeSet);
  public:
    ~ooDerefStructor(ooTreeSet)();
    inline ooTreeSet *operator->() const;
#ifndef OO_BUGGY_TEMPLATES
  private:
#endif // !defined(OO_BUGGY_TEMPLATES)
    ooDerefStructor(ooTreeSet)(ooDeref(ooTreeSet)& deref);
    ooDerefStructor(ooTreeSet)(ooObj *  fromObject);
};


#ifdef OO_BUGGY_TEMPLATES

class CO_STORAGE_SPECIFIER ooHandle_superclass<ooTreeSet > : public ooHandle(ooBTree) {
 protected:
  ooHandle_superclass()
    {}
  ooHandle_superclass(const ooHandle(ooBTree) &  from) :
      ooHandle(ooBTree)(from)
    {}
  ooHandle_superclass(const ooRef(ooBTree) &  from) :
      ooHandle(ooBTree)(from)
    {}
  ooHandle_superclass(const ooBTree *  from) :
      ooHandle(ooBTree)(from)
    {}
  ~ooHandle_superclass()
    {}
};

class CO_STORAGE_SPECIFIER ooShortRef_superclass<ooTreeSet > : public ooShortRef(ooBTree) {
};

#endif // OO_BUGGY_TEMPLATES

ooTemplateSpecialization
class CO_STORAGE_SPECIFIER ooRef(ooTreeSet) : public ooRef(ooBTree) {
  public:
    ooRefStructor(ooTreeSet)()
      {}
    ooRefStructor(ooTreeSet)(const ooRef(ooTreeSet)& id) :
	  ooRef(ooBTree)(id)
      {}
    inline ooRefStructor(ooTreeSet)(const ooHandleSuper(ooTreeSet)& objH);
    inline ooRefStructor(ooTreeSet)(const ooTreeSet *  fromObject);
    inline ooRef(ooTreeSet)& operator=(const ooRef(ooTreeSet)& id);
    inline ooRef(ooTreeSet)& operator=(const ooShortRefSuper(ooTreeSet) &shortId);
    inline ooRef(ooTreeSet)& operator=(const ooHandleSuper(ooTreeSet)& objH);
    inline ooRef(ooTreeSet)& operator=(const ooTreeSet *  fromObject);
    ooStatus lookupObj(const ooHandle(ooObj)& scopeH,
		       const ooKey& key,
		       ooMode openMode = oocRead);
    ooStatus lookupObj(const ooHandle(ooObj)& scopeH,
		       const char* name,
		       ooMode openMode = oocRead);
#ifndef OO_BUGGY_TEMPLATES
    inline ooRef(ooTreeSet)& copy(const ooHandle(ooObj)& nearH,
		    ooRef(ooTreeSet)& newObjRef) const;
    inline ooHandle(ooTreeSet)& copy(const ooHandle(ooObj)& nearH,
			ooHandle(ooTreeSet)& result) const;
    inline ooHandle(ooTreeSet) copy(const ooHandle(ooObj)& nearH) const;
#endif // !defined(OO_BUGGY_TEMPLATES)
    inline ooTreeSet *pin(ooMode openMode = oocRead) const;
    ooDeref(ooTreeSet) operator->() const;
    /* Use pin() or use ooHandle "operator ooTreeSet *" instead of vm. */
    /* OBSOLETE */ inline ooTreeSet *vm(ooMode openMode = oocRead) const;
    // ODMG methods:
    ooRefStructor(ooTreeSet)(const d_Ref_Any &from);
    ooTreeSet *ptr() const;
};

ooTemplateSpecialization
class CO_STORAGE_SPECIFIER ooShortRef(ooTreeSet) :
#ifdef OO_BUGGY_TEMPLATES
			public ooShortRef_superclass<ooTreeSet >
#else // !defined(OO_BUGGY_TEMPLATES)
			public ooShortRef(ooBTree)
#endif // !defined(OO_BUGGY_TEMPLATES)
					            {
  public:
    ooShortRefStructor(ooTreeSet)();
    ooShortRefStructor(ooTreeSet)(const ooShortRef(ooTreeSet)& shortId);
    ooShortRefStructor(ooTreeSet)(const ooRef(ooTreeSet)& id);
    ooShortRefStructor(ooTreeSet)(const ooHandleSuper(ooTreeSet) &objH);
    ooShortRefStructor(ooTreeSet)(const ooTreeSet *  fromObject);
    ooShortRef(ooTreeSet)& operator=(const ooShortRef(ooTreeSet)& shortId);
    ooShortRef(ooTreeSet)& operator=(const ooRef(ooTreeSet)& id);
    ooShortRef(ooTreeSet)& operator=(const ooHandleSuper(ooTreeSet) &objH);
    ooShortRef(ooTreeSet)& operator=(const ooTreeSet *  fromObject);
};

ooTemplateSpecialization
class CO_STORAGE_SPECIFIER ooHandle(ooTreeSet) :
#ifdef OO_BUGGY_TEMPLATES
		      public ooHandle_superclass<ooTreeSet >
#else // !defined(OO_BUGGY_TEMPLATES)
		      public ooHandle(ooBTree)
#endif // !defined(OO_BUGGY_TEMPLATES)
                                                {
  public:
    inline ooHandleStructor(ooTreeSet)();
    inline ooHandleStructor(ooTreeSet)(const ooRef(ooTreeSet)& id);
    inline ooHandleStructor(ooTreeSet)(const ooHandle(ooTreeSet)& objH);
    inline ooHandleStructor(ooTreeSet)(const ooTreeSet *  fromObject);
    inline ooHandle(ooTreeSet)& operator=(const ooRef(ooTreeSet)& id);
    inline ooHandle(ooTreeSet)& operator=(const ooHandle(ooTreeSet)& objH);
    inline ooHandle(ooTreeSet)& operator=(const ooShortRef(ooTreeSet)& shortId);
    inline ooHandle(ooTreeSet)& operator=(const ooTreeSet *  fromObject);
    ooStatus lookupObj(const ooHandle(ooObj)& scopeH,
		       const ooKey& key,
		       ooMode openMode = oocRead);
    ooStatus lookupObj(const ooHandle(ooObj)& scopeH,
		       const char* name,
		       ooMode openMode = oocRead);
    ooHandle(ooTreeSet)& copy(const ooHandle(ooObj)& nearH,
		       ooHandle(ooTreeSet)& result) const;
    inline ooRef(ooTreeSet)& copy(const ooHandle(ooObj)& nearH,
		    ooRef(ooTreeSet)& result) const;
    ooHandle(ooTreeSet) copy(const ooHandle(ooObj)& nearH) const;
    inline ooTreeSet *pin(ooMode openMode = oocRead) const;
    inline ooTreeSet *operator->() const;
    inline ooTreeSet &operator*() const;
    inline operator ooTreeSet *() const;
    /* Use "operator ooTreeSet *" instead of vm. */
    /* OBSOLETE */ inline ooTreeSet *vm() const;
    // ODMG methods:
    ooHandleStructor(ooTreeSet)(const d_Ref_Any &from);
    ooTreeSet *ptr() const;
};

ooTemplateSpecialization
class CO_STORAGE_SPECIFIER ooItr(ooTreeSet) : public ooHandle(ooTreeSet),
		    public ooIteratorObjOrContObj {
  public:
    ooItrStructor(ooTreeSet)();
    ~ooItrStructor(ooTreeSet)();
  private:
    // Defined only to prevent implicit definition:
    ooItrStructor(ooTreeSet)(ooItr(ooTreeSet)&);
    ooItr(ooTreeSet)    operator=(ooItr(ooTreeSet)&);
};


/* methods on ooDeref(ooTreeSet) */
inline
ooDeref(ooTreeSet)::ooDerefStructor(ooTreeSet)(ooDeref(ooTreeSet) &  deref) :
    ooDerefBase(deref.vm())
{
  this->pinCompensate();
}
inline
ooDeref(ooTreeSet)::ooDerefStructor(ooTreeSet)(ooObj *  fromObject) :
    ooDerefBase(fromObject)
{
}
inline
ooDeref(ooTreeSet)::~ooDerefStructor(ooTreeSet)()
{
}
inline
ooTreeSet *
ooDeref(ooTreeSet)::operator->() const
{
  return ooReinterpretCast(ooTreeSet *, this->vm());
}


/* methods on ooRef(ooTreeSet) */
inline
ooRef(ooTreeSet)::ooRefStructor(ooTreeSet)(const ooHandleSuper(ooTreeSet)& objH) :
    ooRef(ooBTree)(objH)
{
}
inline
ooRef(ooTreeSet)::ooRefStructor(ooTreeSet)(const ooTreeSet *  fromObject) :
    ooRef(ooBTree)(ooReinterpretCast(const ooBTree *, fromObject))
{
}
inline
ooRef(ooTreeSet)&
ooRef(ooTreeSet)::operator=(const ooRef(ooTreeSet) &  id)
{
  this->ooId::operator=(id);
  return *this;
}
inline
ooRef(ooTreeSet)&
ooRef(ooTreeSet)::operator=(const ooShortRefSuper(ooTreeSet) &  shortId)
{
  this->ooRef(ooObj)::operator=(shortId);
  return *this;
}
inline
ooRef(ooTreeSet)&
ooRef(ooTreeSet)::operator=(const ooHandleSuper(ooTreeSet) &  objH)
{
  this->ooRef(ooObj)::operator=(objH);
  return *this;
}
inline
ooRef(ooTreeSet)&
ooRef(ooTreeSet)::operator=(const ooTreeSet *  fromObject)
{
  this->ooRef(ooObj)::operator=(ooReinterpretCast(const ooObj *, fromObject));
  return *this;
}
inline
ooTreeSet *
ooRef(ooTreeSet)::pin(ooMode  openMode) const
{
  return ooReinterpretCast(ooTreeSet *, this->pin_ref_internal(openMode));
}
inline
ooTreeSet *
ooRef(ooTreeSet)::vm(ooMode  openMode) const
{
  return this->pin(openMode);
}
#ifndef OO_BUGGY_TEMPLATES
inline
ooHandle(ooTreeSet) &
ooRef(ooTreeSet)::copy(const ooHandle(ooObj) &  nearH,
		ooHandle(ooTreeSet) &           result) const
{
  this->ooRef(ooObj)::copy(nearH, result);
  return result;
}
inline
ooRef(ooTreeSet) &
ooRef(ooTreeSet)::copy(const ooHandle(ooObj) &  nearH,
		ooRef(ooTreeSet) &              newObjRef) const
{
  this->ooRef(ooObj)::copy(nearH, newObjRef);
  return newObjRef;
}
inline
ooHandle(ooTreeSet)
ooRef(ooTreeSet)::copy(const ooHandle(ooObj) &  nearH) const
{
  ooHandle(ooTreeSet) result;
  this->ooRef(ooObj)::copy(nearH, result);
  return result;
}
#endif // !defined(OO_BUGGY_TEMPLATES)
inline
ooDeref(ooTreeSet)
ooRef(ooTreeSet)::operator->() const
{
  ooDeref(ooTreeSet) result(this->pin_ref_internal(oocRead));
  return result;
}


/* methods on ooShortRef(ooTreeSet) */
inline
ooShortRef(ooTreeSet) &
ooShortRef(ooTreeSet)::operator=(const ooShortRef(ooTreeSet) &  shortId)
{
  this->ooShortId::operator=(shortId);
  return *this;
}
inline
ooShortRef(ooTreeSet) &
ooShortRef(ooTreeSet)::operator=(const ooRef(ooTreeSet) &  id)
{
  this->ooShortId::operator=(id);
  return *this;
}
inline
ooShortRef(ooTreeSet) &
ooShortRef(ooTreeSet)::operator=(const ooHandleSuper(ooTreeSet) &  objH)
{
  this->ooShortId::operator=(objH);
  return *this;
}
inline
ooShortRef(ooTreeSet)&
ooShortRef(ooTreeSet)::operator=(const ooTreeSet *  fromObject)
{
  this->ooShortId::operator=(ooReinterpretCast(const ooObj *,fromObject));
  return *this;
}
inline
ooShortRef(ooTreeSet)::ooShortRefStructor(ooTreeSet)()
{
}
#ifdef OO_BUGGY_TEMPLATES
inline
ooShortRef(ooTreeSet)::ooShortRefStructor(ooTreeSet)(const ooShortRef(ooTreeSet) &  shortId)
{
  *this = shortId;
}
#else // !defined(OO_BUGGY_TEMPLATES)
inline
ooShortRef(ooTreeSet)::ooShortRefStructor(ooTreeSet)(const ooShortRef(ooTreeSet) &  shortId) :
    ooShortRef(ooBTree)(shortId)
{
}
#endif // !defined(OO_BUGGY_TEMPLATES)
#ifdef OO_BUGGY_TEMPLATES
inline
ooShortRef(ooTreeSet)::ooShortRefStructor(ooTreeSet)(const ooRef(ooTreeSet) &  id)
{
  *this = id;
}
#else // !defined(OO_BUGGY_TEMPLATES)
inline
ooShortRef(ooTreeSet)::ooShortRefStructor(ooTreeSet)(const ooRef(ooTreeSet) &  id) :
    ooShortRef(ooBTree)(id)
{
}
#endif // !defined(OO_BUGGY_TEMPLATES)
#ifdef OO_BUGGY_TEMPLATES
inline
ooShortRef(ooTreeSet)::ooShortRefStructor(ooTreeSet)(const ooHandleSuper(ooTreeSet) &  objH)
{
  *this = objH;
}
#else // !defined(OO_BUGGY_TEMPLATES)
inline
ooShortRef(ooTreeSet)::ooShortRefStructor(ooTreeSet)(const ooHandleSuper(ooTreeSet) &  objH) :
    ooShortRef(ooBTree)(objH)
{
}
#endif // !defined(OO_BUGGY_TEMPLATES)
#ifdef OO_BUGGY_TEMPLATES
inline
ooShortRef(ooTreeSet)::ooShortRefStructor(ooTreeSet)(const ooTreeSet *  fromObject)
{
  *this = fromObject;
}
#else // !defined(OO_BUGGY_TEMPLATES)
inline
ooShortRef(ooTreeSet)::ooShortRefStructor(ooTreeSet)(const ooTreeSet *  fromObject) :
    ooShortRef(ooBTree)(ooReinterpretCast(const ooBTree *,fromObject))
{
}
#endif // !defined(OO_BUGGY_TEMPLATES)


/* methods on ooHandle(ooTreeSet) */
inline
ooHandle(ooTreeSet)::ooHandleStructor(ooTreeSet)()
{
}
inline
ooHandle(ooTreeSet)::ooHandleStructor(ooTreeSet)(const ooHandle(ooTreeSet) &  objH) :
#ifdef OO_BUGGY_TEMPLATES
    ooHandle_superclass<ooTreeSet >(objH)
#else // !defined(OO_BUGGY_TEMPLATES)
    ooHandle(ooBTree)(objH)
#endif // !defined(OO_BUGGY_TEMPLATES)
{
}
inline
ooHandle(ooTreeSet)::ooHandleStructor(ooTreeSet)(const ooRef(ooTreeSet) &  id) :
#ifdef OO_BUGGY_TEMPLATES
    ooHandle_superclass<ooTreeSet >(id)
#else // !defined(OO_BUGGY_TEMPLATES)
    ooHandle(ooBTree)(id)
#endif // !defined(OO_BUGGY_TEMPLATES)
{
}
inline
ooHandle(ooTreeSet)::ooHandleStructor(ooTreeSet)(const ooTreeSet *  fromObject) :
#ifdef OO_BUGGY_TEMPLATES
    ooHandle_superclass<ooTreeSet >(ooReinterpretCast(const ooBTree *,fromObject))
#else // !defined(OO_BUGGY_TEMPLATES)
    ooHandle(ooBTree)(ooReinterpretCast(const ooBTree *,fromObject))
#endif // !defined(OO_BUGGY_TEMPLATES)
{
}
inline
ooHandle(ooTreeSet)&
ooHandle(ooTreeSet)::operator=(const ooRef(ooTreeSet) &  id)
{
  this->ooHandle(ooObj)::operator=(id);
  return *this;
}
inline
ooHandle(ooTreeSet)&
ooHandle(ooTreeSet)::operator=(const ooHandle(ooTreeSet) &  objH)
{
  this->ooHandle(ooObj)::operator=(objH);
  return *this;
}
inline
ooHandle(ooTreeSet)&
ooHandle(ooTreeSet)::operator=(const ooShortRef(ooTreeSet) &  shortId)
{
  this->ooHandle(ooObj)::operator=(shortId);
  return *this;
}
inline
ooHandle(ooTreeSet)&
ooHandle(ooTreeSet)::operator=(const ooTreeSet *  fromObject)
{
  this->ooHandle(ooObj)::operator=(ooReinterpretCast(const ooObj *,fromObject));
  return *this;
}
inline
ooTreeSet *
ooHandle(ooTreeSet)::pin(ooMode  openMode) const
{
  return ooReinterpretCast(ooTreeSet *, this->pin_obj_internal(openMode));
}
inline
ooTreeSet *
ooHandle(ooTreeSet)::operator->() const
{
  return this->vm();
}
inline
ooTreeSet &
ooHandle(ooTreeSet)::operator*() const
{
  return *(this->vm());
}
inline
ooHandle(ooTreeSet)::operator ooTreeSet *() const
{
  if ( _state == oocHandlePTR  )
    return ooReinterpretCast(ooTreeSet *, _ptr._obj);
  else return ooReinterpretCast(ooTreeSet *, this->get_vm());
}
inline
ooTreeSet *
ooHandle(ooTreeSet)::vm() const
{
  if ( _state == oocHandlePTR && _ptr._obj != NULL )
    return ooReinterpretCast(ooTreeSet *, _ptr._obj);
  else return ooReinterpretCast(ooTreeSet *, this->get_vm());
}
inline
ooRef(ooTreeSet) &
ooHandle(ooTreeSet)::copy(const ooHandle(ooObj) &  nearH,
		   ooRef(ooTreeSet) &              result) const
{
  this->ooHandle(ooObj)::copy(nearH, result);
  return result;
}


/* ODMG methods */
inline
ooTreeSet *
ooRef(ooTreeSet)::ptr() const
{
  return this->pin();
}
inline
ooTreeSet *
ooHandle(ooTreeSet)::ptr() const
{
  return this->operator ooTreeSet *();
}
class ooTreeList;


/////////////////////////////////////////////////////////////////////////////

ooTemplateSpecialization
class CO_STORAGE_SPECIFIER ooDeref(ooTreeList) : public ooDerefBase {
	friend class ooRef(ooTreeList);
  public:
    ~ooDerefStructor(ooTreeList)();
    inline ooTreeList *operator->() const;
#ifndef OO_BUGGY_TEMPLATES
  private:
#endif // !defined(OO_BUGGY_TEMPLATES)
    ooDerefStructor(ooTreeList)(ooDeref(ooTreeList)& deref);
    ooDerefStructor(ooTreeList)(ooObj *  fromObject);
};


#ifdef OO_BUGGY_TEMPLATES

class CO_STORAGE_SPECIFIER ooHandle_superclass<ooTreeList > : public ooHandle(ooBTree) {
 protected:
  ooHandle_superclass()
    {}
  ooHandle_superclass(const ooHandle(ooBTree) &  from) :
      ooHandle(ooBTree)(from)
    {}
  ooHandle_superclass(const ooRef(ooBTree) &  from) :
      ooHandle(ooBTree)(from)
    {}
  ooHandle_superclass(const ooBTree *  from) :
      ooHandle(ooBTree)(from)
    {}
  ~ooHandle_superclass()
    {}
};

class CO_STORAGE_SPECIFIER ooShortRef_superclass<ooTreeList > : public ooShortRef(ooBTree) {
};

#endif // OO_BUGGY_TEMPLATES

ooTemplateSpecialization
class CO_STORAGE_SPECIFIER ooRef(ooTreeList) : public ooRef(ooBTree) {
  public:
    ooRefStructor(ooTreeList)()
      {}
    ooRefStructor(ooTreeList)(const ooRef(ooTreeList)& id) :
	  ooRef(ooBTree)(id)
      {}
    inline ooRefStructor(ooTreeList)(const ooHandleSuper(ooTreeList)& objH);
    inline ooRefStructor(ooTreeList)(const ooTreeList *  fromObject);
    inline ooRef(ooTreeList)& operator=(const ooRef(ooTreeList)& id);
    inline ooRef(ooTreeList)& operator=(const ooShortRefSuper(ooTreeList) &shortId);
    inline ooRef(ooTreeList)& operator=(const ooHandleSuper(ooTreeList)& objH);
    inline ooRef(ooTreeList)& operator=(const ooTreeList *  fromObject);
    ooStatus lookupObj(const ooHandle(ooObj)& scopeH,
		       const ooKey& key,
		       ooMode openMode = oocRead);
    ooStatus lookupObj(const ooHandle(ooObj)& scopeH,
		       const char* name,
		       ooMode openMode = oocRead);
#ifndef OO_BUGGY_TEMPLATES
    inline ooRef(ooTreeList)& copy(const ooHandle(ooObj)& nearH,
		    ooRef(ooTreeList)& newObjRef) const;
    inline ooHandle(ooTreeList)& copy(const ooHandle(ooObj)& nearH,
			ooHandle(ooTreeList)& result) const;
    inline ooHandle(ooTreeList) copy(const ooHandle(ooObj)& nearH) const;
#endif // !defined(OO_BUGGY_TEMPLATES)
    inline ooTreeList *pin(ooMode openMode = oocRead) const;
    ooDeref(ooTreeList) operator->() const;
    /* Use pin() or use ooHandle "operator ooTreeList *" instead of vm. */
    /* OBSOLETE */ inline ooTreeList *vm(ooMode openMode = oocRead) const;
    // ODMG methods:
    ooRefStructor(ooTreeList)(const d_Ref_Any &from);
    ooTreeList *ptr() const;
};

ooTemplateSpecialization
class CO_STORAGE_SPECIFIER ooShortRef(ooTreeList) :
#ifdef OO_BUGGY_TEMPLATES
			public ooShortRef_superclass<ooTreeList >
#else // !defined(OO_BUGGY_TEMPLATES)
			public ooShortRef(ooBTree)
#endif // !defined(OO_BUGGY_TEMPLATES)
					            {
  public:
    ooShortRefStructor(ooTreeList)();
    ooShortRefStructor(ooTreeList)(const ooShortRef(ooTreeList)& shortId);
    ooShortRefStructor(ooTreeList)(const ooRef(ooTreeList)& id);
    ooShortRefStructor(ooTreeList)(const ooHandleSuper(ooTreeList) &objH);
    ooShortRefStructor(ooTreeList)(const ooTreeList *  fromObject);
    ooShortRef(ooTreeList)& operator=(const ooShortRef(ooTreeList)& shortId);
    ooShortRef(ooTreeList)& operator=(const ooRef(ooTreeList)& id);
    ooShortRef(ooTreeList)& operator=(const ooHandleSuper(ooTreeList) &objH);
    ooShortRef(ooTreeList)& operator=(const ooTreeList *  fromObject);
};

ooTemplateSpecialization
class CO_STORAGE_SPECIFIER ooHandle(ooTreeList) :
#ifdef OO_BUGGY_TEMPLATES
		      public ooHandle_superclass<ooTreeList >
#else // !defined(OO_BUGGY_TEMPLATES)
		      public ooHandle(ooBTree)
#endif // !defined(OO_BUGGY_TEMPLATES)
                                                {
  public:
    inline ooHandleStructor(ooTreeList)();
    inline ooHandleStructor(ooTreeList)(const ooRef(ooTreeList)& id);
    inline ooHandleStructor(ooTreeList)(const ooHandle(ooTreeList)& objH);
    inline ooHandleStructor(ooTreeList)(const ooTreeList *  fromObject);
    inline ooHandle(ooTreeList)& operator=(const ooRef(ooTreeList)& id);
    inline ooHandle(ooTreeList)& operator=(const ooHandle(ooTreeList)& objH);
    inline ooHandle(ooTreeList)& operator=(const ooShortRef(ooTreeList)& shortId);
    inline ooHandle(ooTreeList)& operator=(const ooTreeList *  fromObject);
    ooStatus lookupObj(const ooHandle(ooObj)& scopeH,
		       const ooKey& key,
		       ooMode openMode = oocRead);
    ooStatus lookupObj(const ooHandle(ooObj)& scopeH,
		       const char* name,
		       ooMode openMode = oocRead);
    ooHandle(ooTreeList)& copy(const ooHandle(ooObj)& nearH,
		       ooHandle(ooTreeList)& result) const;
    inline ooRef(ooTreeList)& copy(const ooHandle(ooObj)& nearH,
		    ooRef(ooTreeList)& result) const;
    ooHandle(ooTreeList) copy(const ooHandle(ooObj)& nearH) const;
    inline ooTreeList *pin(ooMode openMode = oocRead) const;
    inline ooTreeList *operator->() const;
    inline ooTreeList &operator*() const;
    inline operator ooTreeList *() const;
    /* Use "operator ooTreeList *" instead of vm. */
    /* OBSOLETE */ inline ooTreeList *vm() const;
    // ODMG methods:
    ooHandleStructor(ooTreeList)(const d_Ref_Any &from);
    ooTreeList *ptr() const;
};

ooTemplateSpecialization
class CO_STORAGE_SPECIFIER ooItr(ooTreeList) : public ooHandle(ooTreeList),
		    public ooIteratorObjOrContObj {
  public:
    ooItrStructor(ooTreeList)();
    ~ooItrStructor(ooTreeList)();
  private:
    // Defined only to prevent implicit definition:
    ooItrStructor(ooTreeList)(ooItr(ooTreeList)&);
    ooItr(ooTreeList)    operator=(ooItr(ooTreeList)&);
};


/* methods on ooDeref(ooTreeList) */
inline
ooDeref(ooTreeList)::ooDerefStructor(ooTreeList)(ooDeref(ooTreeList) &  deref) :
    ooDerefBase(deref.vm())
{
  this->pinCompensate();
}
inline
ooDeref(ooTreeList)::ooDerefStructor(ooTreeList)(ooObj *  fromObject) :
    ooDerefBase(fromObject)
{
}
inline
ooDeref(ooTreeList)::~ooDerefStructor(ooTreeList)()
{
}
inline
ooTreeList *
ooDeref(ooTreeList)::operator->() const
{
  return ooReinterpretCast(ooTreeList *, this->vm());
}


/* methods on ooRef(ooTreeList) */
inline
ooRef(ooTreeList)::ooRefStructor(ooTreeList)(const ooHandleSuper(ooTreeList)& objH) :
    ooRef(ooBTree)(objH)
{
}
inline
ooRef(ooTreeList)::ooRefStructor(ooTreeList)(const ooTreeList *  fromObject) :
    ooRef(ooBTree)(ooReinterpretCast(const ooBTree *, fromObject))
{
}
inline
ooRef(ooTreeList)&
ooRef(ooTreeList)::operator=(const ooRef(ooTreeList) &  id)
{
  this->ooId::operator=(id);
  return *this;
}
inline
ooRef(ooTreeList)&
ooRef(ooTreeList)::operator=(const ooShortRefSuper(ooTreeList) &  shortId)
{
  this->ooRef(ooObj)::operator=(shortId);
  return *this;
}
inline
ooRef(ooTreeList)&
ooRef(ooTreeList)::operator=(const ooHandleSuper(ooTreeList) &  objH)
{
  this->ooRef(ooObj)::operator=(objH);
  return *this;
}
inline
ooRef(ooTreeList)&
ooRef(ooTreeList)::operator=(const ooTreeList *  fromObject)
{
  this->ooRef(ooObj)::operator=(ooReinterpretCast(const ooObj *, fromObject));
  return *this;
}
inline
ooTreeList *
ooRef(ooTreeList)::pin(ooMode  openMode) const
{
  return ooReinterpretCast(ooTreeList *, this->pin_ref_internal(openMode));
}
inline
ooTreeList *
ooRef(ooTreeList)::vm(ooMode  openMode) const
{
  return this->pin(openMode);
}
#ifndef OO_BUGGY_TEMPLATES
inline
ooHandle(ooTreeList) &
ooRef(ooTreeList)::copy(const ooHandle(ooObj) &  nearH,
		ooHandle(ooTreeList) &           result) const
{
  this->ooRef(ooObj)::copy(nearH, result);
  return result;
}
inline
ooRef(ooTreeList) &
ooRef(ooTreeList)::copy(const ooHandle(ooObj) &  nearH,
		ooRef(ooTreeList) &              newObjRef) const
{
  this->ooRef(ooObj)::copy(nearH, newObjRef);
  return newObjRef;
}
inline
ooHandle(ooTreeList)
ooRef(ooTreeList)::copy(const ooHandle(ooObj) &  nearH) const
{
  ooHandle(ooTreeList) result;
  this->ooRef(ooObj)::copy(nearH, result);
  return result;
}
#endif // !defined(OO_BUGGY_TEMPLATES)
inline
ooDeref(ooTreeList)
ooRef(ooTreeList)::operator->() const
{
  ooDeref(ooTreeList) result(this->pin_ref_internal(oocRead));
  return result;
}


/* methods on ooShortRef(ooTreeList) */
inline
ooShortRef(ooTreeList) &
ooShortRef(ooTreeList)::operator=(const ooShortRef(ooTreeList) &  shortId)
{
  this->ooShortId::operator=(shortId);
  return *this;
}
inline
ooShortRef(ooTreeList) &
ooShortRef(ooTreeList)::operator=(const ooRef(ooTreeList) &  id)
{
  this->ooShortId::operator=(id);
  return *this;
}
inline
ooShortRef(ooTreeList) &
ooShortRef(ooTreeList)::operator=(const ooHandleSuper(ooTreeList) &  objH)
{
  this->ooShortId::operator=(objH);
  return *this;
}
inline
ooShortRef(ooTreeList)&
ooShortRef(ooTreeList)::operator=(const ooTreeList *  fromObject)
{
  this->ooShortId::operator=(ooReinterpretCast(const ooObj *,fromObject));
  return *this;
}
inline
ooShortRef(ooTreeList)::ooShortRefStructor(ooTreeList)()
{
}
#ifdef OO_BUGGY_TEMPLATES
inline
ooShortRef(ooTreeList)::ooShortRefStructor(ooTreeList)(const ooShortRef(ooTreeList) &  shortId)
{
  *this = shortId;
}
#else // !defined(OO_BUGGY_TEMPLATES)
inline
ooShortRef(ooTreeList)::ooShortRefStructor(ooTreeList)(const ooShortRef(ooTreeList) &  shortId) :
    ooShortRef(ooBTree)(shortId)
{
}
#endif // !defined(OO_BUGGY_TEMPLATES)
#ifdef OO_BUGGY_TEMPLATES
inline
ooShortRef(ooTreeList)::ooShortRefStructor(ooTreeList)(const ooRef(ooTreeList) &  id)
{
  *this = id;
}
#else // !defined(OO_BUGGY_TEMPLATES)
inline
ooShortRef(ooTreeList)::ooShortRefStructor(ooTreeList)(const ooRef(ooTreeList) &  id) :
    ooShortRef(ooBTree)(id)
{
}
#endif // !defined(OO_BUGGY_TEMPLATES)
#ifdef OO_BUGGY_TEMPLATES
inline
ooShortRef(ooTreeList)::ooShortRefStructor(ooTreeList)(const ooHandleSuper(ooTreeList) &  objH)
{
  *this = objH;
}
#else // !defined(OO_BUGGY_TEMPLATES)
inline
ooShortRef(ooTreeList)::ooShortRefStructor(ooTreeList)(const ooHandleSuper(ooTreeList) &  objH) :
    ooShortRef(ooBTree)(objH)
{
}
#endif // !defined(OO_BUGGY_TEMPLATES)
#ifdef OO_BUGGY_TEMPLATES
inline
ooShortRef(ooTreeList)::ooShortRefStructor(ooTreeList)(const ooTreeList *  fromObject)
{
  *this = fromObject;
}
#else // !defined(OO_BUGGY_TEMPLATES)
inline
ooShortRef(ooTreeList)::ooShortRefStructor(ooTreeList)(const ooTreeList *  fromObject) :
    ooShortRef(ooBTree)(ooReinterpretCast(const ooBTree *,fromObject))
{
}
#endif // !defined(OO_BUGGY_TEMPLATES)


/* methods on ooHandle(ooTreeList) */
inline
ooHandle(ooTreeList)::ooHandleStructor(ooTreeList)()
{
}
inline
ooHandle(ooTreeList)::ooHandleStructor(ooTreeList)(const ooHandle(ooTreeList) &  objH) :
#ifdef OO_BUGGY_TEMPLATES
    ooHandle_superclass<ooTreeList >(objH)
#else // !defined(OO_BUGGY_TEMPLATES)
    ooHandle(ooBTree)(objH)
#endif // !defined(OO_BUGGY_TEMPLATES)
{
}
inline
ooHandle(ooTreeList)::ooHandleStructor(ooTreeList)(const ooRef(ooTreeList) &  id) :
#ifdef OO_BUGGY_TEMPLATES
    ooHandle_superclass<ooTreeList >(id)
#else // !defined(OO_BUGGY_TEMPLATES)
    ooHandle(ooBTree)(id)
#endif // !defined(OO_BUGGY_TEMPLATES)
{
}
inline
ooHandle(ooTreeList)::ooHandleStructor(ooTreeList)(const ooTreeList *  fromObject) :
#ifdef OO_BUGGY_TEMPLATES
    ooHandle_superclass<ooTreeList >(ooReinterpretCast(const ooBTree *,fromObject))
#else // !defined(OO_BUGGY_TEMPLATES)
    ooHandle(ooBTree)(ooReinterpretCast(const ooBTree *,fromObject))
#endif // !defined(OO_BUGGY_TEMPLATES)
{
}
inline
ooHandle(ooTreeList)&
ooHandle(ooTreeList)::operator=(const ooRef(ooTreeList) &  id)
{
  this->ooHandle(ooObj)::operator=(id);
  return *this;
}
inline
ooHandle(ooTreeList)&
ooHandle(ooTreeList)::operator=(const ooHandle(ooTreeList) &  objH)
{
  this->ooHandle(ooObj)::operator=(objH);
  return *this;
}
inline
ooHandle(ooTreeList)&
ooHandle(ooTreeList)::operator=(const ooShortRef(ooTreeList) &  shortId)
{
  this->ooHandle(ooObj)::operator=(shortId);
  return *this;
}
inline
ooHandle(ooTreeList)&
ooHandle(ooTreeList)::operator=(const ooTreeList *  fromObject)
{
  this->ooHandle(ooObj)::operator=(ooReinterpretCast(const ooObj *,fromObject));
  return *this;
}
inline
ooTreeList *
ooHandle(ooTreeList)::pin(ooMode  openMode) const
{
  return ooReinterpretCast(ooTreeList *, this->pin_obj_internal(openMode));
}
inline
ooTreeList *
ooHandle(ooTreeList)::operator->() const
{
  return this->vm();
}
inline
ooTreeList &
ooHandle(ooTreeList)::operator*() const
{
  return *(this->vm());
}
inline
ooHandle(ooTreeList)::operator ooTreeList *() const
{
  if ( _state == oocHandlePTR  )
    return ooReinterpretCast(ooTreeList *, _ptr._obj);
  else return ooReinterpretCast(ooTreeList *, this->get_vm());
}
inline
ooTreeList *
ooHandle(ooTreeList)::vm() const
{
  if ( _state == oocHandlePTR && _ptr._obj != NULL )
    return ooReinterpretCast(ooTreeList *, _ptr._obj);
  else return ooReinterpretCast(ooTreeList *, this->get_vm());
}
inline
ooRef(ooTreeList) &
ooHandle(ooTreeList)::copy(const ooHandle(ooObj) &  nearH,
		   ooRef(ooTreeList) &              result) const
{
  this->ooHandle(ooObj)::copy(nearH, result);
  return result;
}


/* ODMG methods */
inline
ooTreeList *
ooRef(ooTreeList)::ptr() const
{
  return this->pin();
}
inline
ooTreeList *
ooHandle(ooTreeList)::ptr() const
{
  return this->operator ooTreeList *();
}
class ooTreeListNode;


/////////////////////////////////////////////////////////////////////////////

ooTemplateSpecialization
class CO_STORAGE_SPECIFIER ooDeref(ooTreeListNode) : public ooDerefBase {
	friend class ooRef(ooTreeListNode);
  public:
    ~ooDerefStructor(ooTreeListNode)();
    inline ooTreeListNode *operator->() const;
#ifndef OO_BUGGY_TEMPLATES
  private:
#endif // !defined(OO_BUGGY_TEMPLATES)
    ooDerefStructor(ooTreeListNode)(ooDeref(ooTreeListNode)& deref);
    ooDerefStructor(ooTreeListNode)(ooObj *  fromObject);
};


#ifdef OO_BUGGY_TEMPLATES

class CO_STORAGE_SPECIFIER ooHandle_superclass<ooTreeListNode > : public ooHandle(ooBTree) {
 protected:
  ooHandle_superclass()
    {}
  ooHandle_superclass(const ooHandle(ooBTree) &  from) :
      ooHandle(ooBTree)(from)
    {}
  ooHandle_superclass(const ooRef(ooBTree) &  from) :
      ooHandle(ooBTree)(from)
    {}
  ooHandle_superclass(const ooBTree *  from) :
      ooHandle(ooBTree)(from)
    {}
  ~ooHandle_superclass()
    {}
};

class CO_STORAGE_SPECIFIER ooShortRef_superclass<ooTreeListNode > : public ooShortRef(ooBTree) {
};

#endif // OO_BUGGY_TEMPLATES

ooTemplateSpecialization
class CO_STORAGE_SPECIFIER ooRef(ooTreeListNode) : public ooRef(ooBTree) {
  public:
    ooRefStructor(ooTreeListNode)()
      {}
    ooRefStructor(ooTreeListNode)(const ooRef(ooTreeListNode)& id) :
	  ooRef(ooBTree)(id)
      {}
    inline ooRefStructor(ooTreeListNode)(const ooHandleSuper(ooTreeListNode)& objH);
    inline ooRefStructor(ooTreeListNode)(const ooTreeListNode *  fromObject);
    inline ooRef(ooTreeListNode)& operator=(const ooRef(ooTreeListNode)& id);
    inline ooRef(ooTreeListNode)& operator=(const ooShortRefSuper(ooTreeListNode) &shortId);
    inline ooRef(ooTreeListNode)& operator=(const ooHandleSuper(ooTreeListNode)& objH);
    inline ooRef(ooTreeListNode)& operator=(const ooTreeListNode *  fromObject);
    ooStatus lookupObj(const ooHandle(ooObj)& scopeH,
		       const ooKey& key,
		       ooMode openMode = oocRead);
    ooStatus lookupObj(const ooHandle(ooObj)& scopeH,
		       const char* name,
		       ooMode openMode = oocRead);
#ifndef OO_BUGGY_TEMPLATES
    inline ooRef(ooTreeListNode)& copy(const ooHandle(ooObj)& nearH,
		    ooRef(ooTreeListNode)& newObjRef) const;
    inline ooHandle(ooTreeListNode)& copy(const ooHandle(ooObj)& nearH,
			ooHandle(ooTreeListNode)& result) const;
    inline ooHandle(ooTreeListNode) copy(const ooHandle(ooObj)& nearH) const;
#endif // !defined(OO_BUGGY_TEMPLATES)
    inline ooTreeListNode *pin(ooMode openMode = oocRead) const;
    ooDeref(ooTreeListNode) operator->() const;
    /* Use pin() or use ooHandle "operator ooTreeListNode *" instead of vm. */
    /* OBSOLETE */ inline ooTreeListNode *vm(ooMode openMode = oocRead) const;
    // ODMG methods:
    ooRefStructor(ooTreeListNode)(const d_Ref_Any &from);
    ooTreeListNode *ptr() const;
};

ooTemplateSpecialization
class CO_STORAGE_SPECIFIER ooShortRef(ooTreeListNode) :
#ifdef OO_BUGGY_TEMPLATES
			public ooShortRef_superclass<ooTreeListNode >
#else // !defined(OO_BUGGY_TEMPLATES)
			public ooShortRef(ooBTree)
#endif // !defined(OO_BUGGY_TEMPLATES)
					            {
  public:
    ooShortRefStructor(ooTreeListNode)();
    ooShortRefStructor(ooTreeListNode)(const ooShortRef(ooTreeListNode)& shortId);
    ooShortRefStructor(ooTreeListNode)(const ooRef(ooTreeListNode)& id);
    ooShortRefStructor(ooTreeListNode)(const ooHandleSuper(ooTreeListNode) &objH);
    ooShortRefStructor(ooTreeListNode)(const ooTreeListNode *  fromObject);
    ooShortRef(ooTreeListNode)& operator=(const ooShortRef(ooTreeListNode)& shortId);
    ooShortRef(ooTreeListNode)& operator=(const ooRef(ooTreeListNode)& id);
    ooShortRef(ooTreeListNode)& operator=(const ooHandleSuper(ooTreeListNode) &objH);
    ooShortRef(ooTreeListNode)& operator=(const ooTreeListNode *  fromObject);
};

ooTemplateSpecialization
class CO_STORAGE_SPECIFIER ooHandle(ooTreeListNode) :
#ifdef OO_BUGGY_TEMPLATES
		      public ooHandle_superclass<ooTreeListNode >
#else // !defined(OO_BUGGY_TEMPLATES)
		      public ooHandle(ooBTree)
#endif // !defined(OO_BUGGY_TEMPLATES)
                                                {
  public:
    inline ooHandleStructor(ooTreeListNode)();
    inline ooHandleStructor(ooTreeListNode)(const ooRef(ooTreeListNode)& id);
    inline ooHandleStructor(ooTreeListNode)(const ooHandle(ooTreeListNode)& objH);
    inline ooHandleStructor(ooTreeListNode)(const ooTreeListNode *  fromObject);
    inline ooHandle(ooTreeListNode)& operator=(const ooRef(ooTreeListNode)& id);
    inline ooHandle(ooTreeListNode)& operator=(const ooHandle(ooTreeListNode)& objH);
    inline ooHandle(ooTreeListNode)& operator=(const ooShortRef(ooTreeListNode)& shortId);
    inline ooHandle(ooTreeListNode)& operator=(const ooTreeListNode *  fromObject);
    ooStatus lookupObj(const ooHandle(ooObj)& scopeH,
		       const ooKey& key,
		       ooMode openMode = oocRead);
    ooStatus lookupObj(const ooHandle(ooObj)& scopeH,
		       const char* name,
		       ooMode openMode = oocRead);
    ooHandle(ooTreeListNode)& copy(const ooHandle(ooObj)& nearH,
		       ooHandle(ooTreeListNode)& result) const;
    inline ooRef(ooTreeListNode)& copy(const ooHandle(ooObj)& nearH,
		    ooRef(ooTreeListNode)& result) const;
    ooHandle(ooTreeListNode) copy(const ooHandle(ooObj)& nearH) const;
    inline ooTreeListNode *pin(ooMode openMode = oocRead) const;
    inline ooTreeListNode *operator->() const;
    inline ooTreeListNode &operator*() const;
    inline operator ooTreeListNode *() const;
    /* Use "operator ooTreeListNode *" instead of vm. */
    /* OBSOLETE */ inline ooTreeListNode *vm() const;
    // ODMG methods:
    ooHandleStructor(ooTreeListNode)(const d_Ref_Any &from);
    ooTreeListNode *ptr() const;
};

ooTemplateSpecialization
class CO_STORAGE_SPECIFIER ooItr(ooTreeListNode) : public ooHandle(ooTreeListNode),
		    public ooIteratorObjOrContObj {
  public:
    ooItrStructor(ooTreeListNode)();
    ~ooItrStructor(ooTreeListNode)();
  private:
    // Defined only to prevent implicit definition:
    ooItrStructor(ooTreeListNode)(ooItr(ooTreeListNode)&);
    ooItr(ooTreeListNode)    operator=(ooItr(ooTreeListNode)&);
};


/* methods on ooDeref(ooTreeListNode) */
inline
ooDeref(ooTreeListNode)::ooDerefStructor(ooTreeListNode)(ooDeref(ooTreeListNode) &  deref) :
    ooDerefBase(deref.vm())
{
  this->pinCompensate();
}
inline
ooDeref(ooTreeListNode)::ooDerefStructor(ooTreeListNode)(ooObj *  fromObject) :
    ooDerefBase(fromObject)
{
}
inline
ooDeref(ooTreeListNode)::~ooDerefStructor(ooTreeListNode)()
{
}
inline
ooTreeListNode *
ooDeref(ooTreeListNode)::operator->() const
{
  return ooReinterpretCast(ooTreeListNode *, this->vm());
}


/* methods on ooRef(ooTreeListNode) */
inline
ooRef(ooTreeListNode)::ooRefStructor(ooTreeListNode)(const ooHandleSuper(ooTreeListNode)& objH) :
    ooRef(ooBTree)(objH)
{
}
inline
ooRef(ooTreeListNode)::ooRefStructor(ooTreeListNode)(const ooTreeListNode *  fromObject) :
    ooRef(ooBTree)(ooReinterpretCast(const ooBTree *, fromObject))
{
}
inline
ooRef(ooTreeListNode)&
ooRef(ooTreeListNode)::operator=(const ooRef(ooTreeListNode) &  id)
{
  this->ooId::operator=(id);
  return *this;
}
inline
ooRef(ooTreeListNode)&
ooRef(ooTreeListNode)::operator=(const ooShortRefSuper(ooTreeListNode) &  shortId)
{
  this->ooRef(ooObj)::operator=(shortId);
  return *this;
}
inline
ooRef(ooTreeListNode)&
ooRef(ooTreeListNode)::operator=(const ooHandleSuper(ooTreeListNode) &  objH)
{
  this->ooRef(ooObj)::operator=(objH);
  return *this;
}
inline
ooRef(ooTreeListNode)&
ooRef(ooTreeListNode)::operator=(const ooTreeListNode *  fromObject)
{
  this->ooRef(ooObj)::operator=(ooReinterpretCast(const ooObj *, fromObject));
  return *this;
}
inline
ooTreeListNode *
ooRef(ooTreeListNode)::pin(ooMode  openMode) const
{
  return ooReinterpretCast(ooTreeListNode *, this->pin_ref_internal(openMode));
}
inline
ooTreeListNode *
ooRef(ooTreeListNode)::vm(ooMode  openMode) const
{
  return this->pin(openMode);
}
#ifndef OO_BUGGY_TEMPLATES
inline
ooHandle(ooTreeListNode) &
ooRef(ooTreeListNode)::copy(const ooHandle(ooObj) &  nearH,
		ooHandle(ooTreeListNode) &           result) const
{
  this->ooRef(ooObj)::copy(nearH, result);
  return result;
}
inline
ooRef(ooTreeListNode) &
ooRef(ooTreeListNode)::copy(const ooHandle(ooObj) &  nearH,
		ooRef(ooTreeListNode) &              newObjRef) const
{
  this->ooRef(ooObj)::copy(nearH, newObjRef);
  return newObjRef;
}
inline
ooHandle(ooTreeListNode)
ooRef(ooTreeListNode)::copy(const ooHandle(ooObj) &  nearH) const
{
  ooHandle(ooTreeListNode) result;
  this->ooRef(ooObj)::copy(nearH, result);
  return result;
}
#endif // !defined(OO_BUGGY_TEMPLATES)
inline
ooDeref(ooTreeListNode)
ooRef(ooTreeListNode)::operator->() const
{
  ooDeref(ooTreeListNode) result(this->pin_ref_internal(oocRead));
  return result;
}


/* methods on ooShortRef(ooTreeListNode) */
inline
ooShortRef(ooTreeListNode) &
ooShortRef(ooTreeListNode)::operator=(const ooShortRef(ooTreeListNode) &  shortId)
{
  this->ooShortId::operator=(shortId);
  return *this;
}
inline
ooShortRef(ooTreeListNode) &
ooShortRef(ooTreeListNode)::operator=(const ooRef(ooTreeListNode) &  id)
{
  this->ooShortId::operator=(id);
  return *this;
}
inline
ooShortRef(ooTreeListNode) &
ooShortRef(ooTreeListNode)::operator=(const ooHandleSuper(ooTreeListNode) &  objH)
{
  this->ooShortId::operator=(objH);
  return *this;
}
inline
ooShortRef(ooTreeListNode)&
ooShortRef(ooTreeListNode)::operator=(const ooTreeListNode *  fromObject)
{
  this->ooShortId::operator=(ooReinterpretCast(const ooObj *,fromObject));
  return *this;
}
inline
ooShortRef(ooTreeListNode)::ooShortRefStructor(ooTreeListNode)()
{
}
#ifdef OO_BUGGY_TEMPLATES
inline
ooShortRef(ooTreeListNode)::ooShortRefStructor(ooTreeListNode)(const ooShortRef(ooTreeListNode) &  shortId)
{
  *this = shortId;
}
#else // !defined(OO_BUGGY_TEMPLATES)
inline
ooShortRef(ooTreeListNode)::ooShortRefStructor(ooTreeListNode)(const ooShortRef(ooTreeListNode) &  shortId) :
    ooShortRef(ooBTree)(shortId)
{
}
#endif // !defined(OO_BUGGY_TEMPLATES)
#ifdef OO_BUGGY_TEMPLATES
inline
ooShortRef(ooTreeListNode)::ooShortRefStructor(ooTreeListNode)(const ooRef(ooTreeListNode) &  id)
{
  *this = id;
}
#else // !defined(OO_BUGGY_TEMPLATES)
inline
ooShortRef(ooTreeListNode)::ooShortRefStructor(ooTreeListNode)(const ooRef(ooTreeListNode) &  id) :
    ooShortRef(ooBTree)(id)
{
}
#endif // !defined(OO_BUGGY_TEMPLATES)
#ifdef OO_BUGGY_TEMPLATES
inline
ooShortRef(ooTreeListNode)::ooShortRefStructor(ooTreeListNode)(const ooHandleSuper(ooTreeListNode) &  objH)
{
  *this = objH;
}
#else // !defined(OO_BUGGY_TEMPLATES)
inline
ooShortRef(ooTreeListNode)::ooShortRefStructor(ooTreeListNode)(const ooHandleSuper(ooTreeListNode) &  objH) :
    ooShortRef(ooBTree)(objH)
{
}
#endif // !defined(OO_BUGGY_TEMPLATES)
#ifdef OO_BUGGY_TEMPLATES
inline
ooShortRef(ooTreeListNode)::ooShortRefStructor(ooTreeListNode)(const ooTreeListNode *  fromObject)
{
  *this = fromObject;
}
#else // !defined(OO_BUGGY_TEMPLATES)
inline
ooShortRef(ooTreeListNode)::ooShortRefStructor(ooTreeListNode)(const ooTreeListNode *  fromObject) :
    ooShortRef(ooBTree)(ooReinterpretCast(const ooBTree *,fromObject))
{
}
#endif // !defined(OO_BUGGY_TEMPLATES)


/* methods on ooHandle(ooTreeListNode) */
inline
ooHandle(ooTreeListNode)::ooHandleStructor(ooTreeListNode)()
{
}
inline
ooHandle(ooTreeListNode)::ooHandleStructor(ooTreeListNode)(const ooHandle(ooTreeListNode) &  objH) :
#ifdef OO_BUGGY_TEMPLATES
    ooHandle_superclass<ooTreeListNode >(objH)
#else // !defined(OO_BUGGY_TEMPLATES)
    ooHandle(ooBTree)(objH)
#endif // !defined(OO_BUGGY_TEMPLATES)
{
}
inline
ooHandle(ooTreeListNode)::ooHandleStructor(ooTreeListNode)(const ooRef(ooTreeListNode) &  id) :
#ifdef OO_BUGGY_TEMPLATES
    ooHandle_superclass<ooTreeListNode >(id)
#else // !defined(OO_BUGGY_TEMPLATES)
    ooHandle(ooBTree)(id)
#endif // !defined(OO_BUGGY_TEMPLATES)
{
}
inline
ooHandle(ooTreeListNode)::ooHandleStructor(ooTreeListNode)(const ooTreeListNode *  fromObject) :
#ifdef OO_BUGGY_TEMPLATES
    ooHandle_superclass<ooTreeListNode >(ooReinterpretCast(const ooBTree *,fromObject))
#else // !defined(OO_BUGGY_TEMPLATES)
    ooHandle(ooBTree)(ooReinterpretCast(const ooBTree *,fromObject))
#endif // !defined(OO_BUGGY_TEMPLATES)
{
}
inline
ooHandle(ooTreeListNode)&
ooHandle(ooTreeListNode)::operator=(const ooRef(ooTreeListNode) &  id)
{
  this->ooHandle(ooObj)::operator=(id);
  return *this;
}
inline
ooHandle(ooTreeListNode)&
ooHandle(ooTreeListNode)::operator=(const ooHandle(ooTreeListNode) &  objH)
{
  this->ooHandle(ooObj)::operator=(objH);
  return *this;
}
inline
ooHandle(ooTreeListNode)&
ooHandle(ooTreeListNode)::operator=(const ooShortRef(ooTreeListNode) &  shortId)
{
  this->ooHandle(ooObj)::operator=(shortId);
  return *this;
}
inline
ooHandle(ooTreeListNode)&
ooHandle(ooTreeListNode)::operator=(const ooTreeListNode *  fromObject)
{
  this->ooHandle(ooObj)::operator=(ooReinterpretCast(const ooObj *,fromObject));
  return *this;
}
inline
ooTreeListNode *
ooHandle(ooTreeListNode)::pin(ooMode  openMode) const
{
  return ooReinterpretCast(ooTreeListNode *, this->pin_obj_internal(openMode));
}
inline
ooTreeListNode *
ooHandle(ooTreeListNode)::operator->() const
{
  return this->vm();
}
inline
ooTreeListNode &
ooHandle(ooTreeListNode)::operator*() const
{
  return *(this->vm());
}
inline
ooHandle(ooTreeListNode)::operator ooTreeListNode *() const
{
  if ( _state == oocHandlePTR  )
    return ooReinterpretCast(ooTreeListNode *, _ptr._obj);
  else return ooReinterpretCast(ooTreeListNode *, this->get_vm());
}
inline
ooTreeListNode *
ooHandle(ooTreeListNode)::vm() const
{
  if ( _state == oocHandlePTR && _ptr._obj != NULL )
    return ooReinterpretCast(ooTreeListNode *, _ptr._obj);
  else return ooReinterpretCast(ooTreeListNode *, this->get_vm());
}
inline
ooRef(ooTreeListNode) &
ooHandle(ooTreeListNode)::copy(const ooHandle(ooObj) &  nearH,
		   ooRef(ooTreeListNode) &              result) const
{
  this->ooHandle(ooObj)::copy(nearH, result);
  return result;
}


/* ODMG methods */
inline
ooTreeListNode *
ooRef(ooTreeListNode)::ptr() const
{
  return this->pin();
}
inline
ooTreeListNode *
ooHandle(ooTreeListNode)::ptr() const
{
  return this->operator ooTreeListNode *();
}
class ooTreeMap;


/////////////////////////////////////////////////////////////////////////////

ooTemplateSpecialization
class CO_STORAGE_SPECIFIER ooDeref(ooTreeMap) : public ooDerefBase {
	friend class ooRef(ooTreeMap);
  public:
    ~ooDerefStructor(ooTreeMap)();
    inline ooTreeMap *operator->() const;
#ifndef OO_BUGGY_TEMPLATES
  private:
#endif // !defined(OO_BUGGY_TEMPLATES)
    ooDerefStructor(ooTreeMap)(ooDeref(ooTreeMap)& deref);
    ooDerefStructor(ooTreeMap)(ooObj *  fromObject);
};


#ifdef OO_BUGGY_TEMPLATES

class CO_STORAGE_SPECIFIER ooHandle_superclass<ooTreeMap > : public ooHandle(ooTreeSet) {
 protected:
  ooHandle_superclass()
    {}
  ooHandle_superclass(const ooHandle(ooTreeSet) &  from) :
      ooHandle(ooTreeSet)(from)
    {}
  ooHandle_superclass(const ooRef(ooTreeSet) &  from) :
      ooHandle(ooTreeSet)(from)
    {}
  ooHandle_superclass(const ooTreeSet *  from) :
      ooHandle(ooTreeSet)(from)
    {}
  ~ooHandle_superclass()
    {}
};

class CO_STORAGE_SPECIFIER ooShortRef_superclass<ooTreeMap > : public ooShortRef(ooTreeSet) {
};

#endif // OO_BUGGY_TEMPLATES

ooTemplateSpecialization
class CO_STORAGE_SPECIFIER ooRef(ooTreeMap) : public ooRef(ooTreeSet) {
  public:
    ooRefStructor(ooTreeMap)()
      {}
    ooRefStructor(ooTreeMap)(const ooRef(ooTreeMap)& id) :
	  ooRef(ooTreeSet)(id)
      {}
    inline ooRefStructor(ooTreeMap)(const ooHandleSuper(ooTreeMap)& objH);
    inline ooRefStructor(ooTreeMap)(const ooTreeMap *  fromObject);
    inline ooRef(ooTreeMap)& operator=(const ooRef(ooTreeMap)& id);
    inline ooRef(ooTreeMap)& operator=(const ooShortRefSuper(ooTreeMap) &shortId);
    inline ooRef(ooTreeMap)& operator=(const ooHandleSuper(ooTreeMap)& objH);
    inline ooRef(ooTreeMap)& operator=(const ooTreeMap *  fromObject);
    ooStatus lookupObj(const ooHandle(ooObj)& scopeH,
		       const ooKey& key,
		       ooMode openMode = oocRead);
    ooStatus lookupObj(const ooHandle(ooObj)& scopeH,
		       const char* name,
		       ooMode openMode = oocRead);
#ifndef OO_BUGGY_TEMPLATES
    inline ooRef(ooTreeMap)& copy(const ooHandle(ooObj)& nearH,
		    ooRef(ooTreeMap)& newObjRef) const;
    inline ooHandle(ooTreeMap)& copy(const ooHandle(ooObj)& nearH,
			ooHandle(ooTreeMap)& result) const;
    inline ooHandle(ooTreeMap) copy(const ooHandle(ooObj)& nearH) const;
#endif // !defined(OO_BUGGY_TEMPLATES)
    inline ooTreeMap *pin(ooMode openMode = oocRead) const;
    ooDeref(ooTreeMap) operator->() const;
    /* Use pin() or use ooHandle "operator ooTreeMap *" instead of vm. */
    /* OBSOLETE */ inline ooTreeMap *vm(ooMode openMode = oocRead) const;
    // ODMG methods:
    ooRefStructor(ooTreeMap)(const d_Ref_Any &from);
    ooTreeMap *ptr() const;
};

ooTemplateSpecialization
class CO_STORAGE_SPECIFIER ooShortRef(ooTreeMap) :
#ifdef OO_BUGGY_TEMPLATES
			public ooShortRef_superclass<ooTreeMap >
#else // !defined(OO_BUGGY_TEMPLATES)
			public ooShortRef(ooTreeSet)
#endif // !defined(OO_BUGGY_TEMPLATES)
					            {
  public:
    ooShortRefStructor(ooTreeMap)();
    ooShortRefStructor(ooTreeMap)(const ooShortRef(ooTreeMap)& shortId);
    ooShortRefStructor(ooTreeMap)(const ooRef(ooTreeMap)& id);
    ooShortRefStructor(ooTreeMap)(const ooHandleSuper(ooTreeMap) &objH);
    ooShortRefStructor(ooTreeMap)(const ooTreeMap *  fromObject);
    ooShortRef(ooTreeMap)& operator=(const ooShortRef(ooTreeMap)& shortId);
    ooShortRef(ooTreeMap)& operator=(const ooRef(ooTreeMap)& id);
    ooShortRef(ooTreeMap)& operator=(const ooHandleSuper(ooTreeMap) &objH);
    ooShortRef(ooTreeMap)& operator=(const ooTreeMap *  fromObject);
};

ooTemplateSpecialization
class CO_STORAGE_SPECIFIER ooHandle(ooTreeMap) :
#ifdef OO_BUGGY_TEMPLATES
		      public ooHandle_superclass<ooTreeMap >
#else // !defined(OO_BUGGY_TEMPLATES)
		      public ooHandle(ooTreeSet)
#endif // !defined(OO_BUGGY_TEMPLATES)
                                                {
  public:
    inline ooHandleStructor(ooTreeMap)();
    inline ooHandleStructor(ooTreeMap)(const ooRef(ooTreeMap)& id);
    inline ooHandleStructor(ooTreeMap)(const ooHandle(ooTreeMap)& objH);
    inline ooHandleStructor(ooTreeMap)(const ooTreeMap *  fromObject);
    inline ooHandle(ooTreeMap)& operator=(const ooRef(ooTreeMap)& id);
    inline ooHandle(ooTreeMap)& operator=(const ooHandle(ooTreeMap)& objH);
    inline ooHandle(ooTreeMap)& operator=(const ooShortRef(ooTreeMap)& shortId);
    inline ooHandle(ooTreeMap)& operator=(const ooTreeMap *  fromObject);
    ooStatus lookupObj(const ooHandle(ooObj)& scopeH,
		       const ooKey& key,
		       ooMode openMode = oocRead);
    ooStatus lookupObj(const ooHandle(ooObj)& scopeH,
		       const char* name,
		       ooMode openMode = oocRead);
    ooHandle(ooTreeMap)& copy(const ooHandle(ooObj)& nearH,
		       ooHandle(ooTreeMap)& result) const;
    inline ooRef(ooTreeMap)& copy(const ooHandle(ooObj)& nearH,
		    ooRef(ooTreeMap)& result) const;
    ooHandle(ooTreeMap) copy(const ooHandle(ooObj)& nearH) const;
    inline ooTreeMap *pin(ooMode openMode = oocRead) const;
    inline ooTreeMap *operator->() const;
    inline ooTreeMap &operator*() const;
    inline operator ooTreeMap *() const;
    /* Use "operator ooTreeMap *" instead of vm. */
    /* OBSOLETE */ inline ooTreeMap *vm() const;
    // ODMG methods:
    ooHandleStructor(ooTreeMap)(const d_Ref_Any &from);
    ooTreeMap *ptr() const;
};

ooTemplateSpecialization
class CO_STORAGE_SPECIFIER ooItr(ooTreeMap) : public ooHandle(ooTreeMap),
		    public ooIteratorObjOrContObj {
  public:
    ooItrStructor(ooTreeMap)();
    ~ooItrStructor(ooTreeMap)();
  private:
    // Defined only to prevent implicit definition:
    ooItrStructor(ooTreeMap)(ooItr(ooTreeMap)&);
    ooItr(ooTreeMap)    operator=(ooItr(ooTreeMap)&);
};


/* methods on ooDeref(ooTreeMap) */
inline
ooDeref(ooTreeMap)::ooDerefStructor(ooTreeMap)(ooDeref(ooTreeMap) &  deref) :
    ooDerefBase(deref.vm())
{
  this->pinCompensate();
}
inline
ooDeref(ooTreeMap)::ooDerefStructor(ooTreeMap)(ooObj *  fromObject) :
    ooDerefBase(fromObject)
{
}
inline
ooDeref(ooTreeMap)::~ooDerefStructor(ooTreeMap)()
{
}
inline
ooTreeMap *
ooDeref(ooTreeMap)::operator->() const
{
  return ooReinterpretCast(ooTreeMap *, this->vm());
}


/* methods on ooRef(ooTreeMap) */
inline
ooRef(ooTreeMap)::ooRefStructor(ooTreeMap)(const ooHandleSuper(ooTreeMap)& objH) :
    ooRef(ooTreeSet)(objH)
{
}
inline
ooRef(ooTreeMap)::ooRefStructor(ooTreeMap)(const ooTreeMap *  fromObject) :
    ooRef(ooTreeSet)(ooReinterpretCast(const ooTreeSet *, fromObject))
{
}
inline
ooRef(ooTreeMap)&
ooRef(ooTreeMap)::operator=(const ooRef(ooTreeMap) &  id)
{
  this->ooId::operator=(id);
  return *this;
}
inline
ooRef(ooTreeMap)&
ooRef(ooTreeMap)::operator=(const ooShortRefSuper(ooTreeMap) &  shortId)
{
  this->ooRef(ooObj)::operator=(shortId);
  return *this;
}
inline
ooRef(ooTreeMap)&
ooRef(ooTreeMap)::operator=(const ooHandleSuper(ooTreeMap) &  objH)
{
  this->ooRef(ooObj)::operator=(objH);
  return *this;
}
inline
ooRef(ooTreeMap)&
ooRef(ooTreeMap)::operator=(const ooTreeMap *  fromObject)
{
  this->ooRef(ooObj)::operator=(ooReinterpretCast(const ooObj *, fromObject));
  return *this;
}
inline
ooTreeMap *
ooRef(ooTreeMap)::pin(ooMode  openMode) const
{
  return ooReinterpretCast(ooTreeMap *, this->pin_ref_internal(openMode));
}
inline
ooTreeMap *
ooRef(ooTreeMap)::vm(ooMode  openMode) const
{
  return this->pin(openMode);
}
#ifndef OO_BUGGY_TEMPLATES
inline
ooHandle(ooTreeMap) &
ooRef(ooTreeMap)::copy(const ooHandle(ooObj) &  nearH,
		ooHandle(ooTreeMap) &           result) const
{
  this->ooRef(ooObj)::copy(nearH, result);
  return result;
}
inline
ooRef(ooTreeMap) &
ooRef(ooTreeMap)::copy(const ooHandle(ooObj) &  nearH,
		ooRef(ooTreeMap) &              newObjRef) const
{
  this->ooRef(ooObj)::copy(nearH, newObjRef);
  return newObjRef;
}
inline
ooHandle(ooTreeMap)
ooRef(ooTreeMap)::copy(const ooHandle(ooObj) &  nearH) const
{
  ooHandle(ooTreeMap) result;
  this->ooRef(ooObj)::copy(nearH, result);
  return result;
}
#endif // !defined(OO_BUGGY_TEMPLATES)
inline
ooDeref(ooTreeMap)
ooRef(ooTreeMap)::operator->() const
{
  ooDeref(ooTreeMap) result(this->pin_ref_internal(oocRead));
  return result;
}


/* methods on ooShortRef(ooTreeMap) */
inline
ooShortRef(ooTreeMap) &
ooShortRef(ooTreeMap)::operator=(const ooShortRef(ooTreeMap) &  shortId)
{
  this->ooShortId::operator=(shortId);
  return *this;
}
inline
ooShortRef(ooTreeMap) &
ooShortRef(ooTreeMap)::operator=(const ooRef(ooTreeMap) &  id)
{
  this->ooShortId::operator=(id);
  return *this;
}
inline
ooShortRef(ooTreeMap) &
ooShortRef(ooTreeMap)::operator=(const ooHandleSuper(ooTreeMap) &  objH)
{
  this->ooShortId::operator=(objH);
  return *this;
}
inline
ooShortRef(ooTreeMap)&
ooShortRef(ooTreeMap)::operator=(const ooTreeMap *  fromObject)
{
  this->ooShortId::operator=(ooReinterpretCast(const ooObj *,fromObject));
  return *this;
}
inline
ooShortRef(ooTreeMap)::ooShortRefStructor(ooTreeMap)()
{
}
#ifdef OO_BUGGY_TEMPLATES
inline
ooShortRef(ooTreeMap)::ooShortRefStructor(ooTreeMap)(const ooShortRef(ooTreeMap) &  shortId)
{
  *this = shortId;
}
#else // !defined(OO_BUGGY_TEMPLATES)
inline
ooShortRef(ooTreeMap)::ooShortRefStructor(ooTreeMap)(const ooShortRef(ooTreeMap) &  shortId) :
    ooShortRef(ooTreeSet)(shortId)
{
}
#endif // !defined(OO_BUGGY_TEMPLATES)
#ifdef OO_BUGGY_TEMPLATES
inline
ooShortRef(ooTreeMap)::ooShortRefStructor(ooTreeMap)(const ooRef(ooTreeMap) &  id)
{
  *this = id;
}
#else // !defined(OO_BUGGY_TEMPLATES)
inline
ooShortRef(ooTreeMap)::ooShortRefStructor(ooTreeMap)(const ooRef(ooTreeMap) &  id) :
    ooShortRef(ooTreeSet)(id)
{
}
#endif // !defined(OO_BUGGY_TEMPLATES)
#ifdef OO_BUGGY_TEMPLATES
inline
ooShortRef(ooTreeMap)::ooShortRefStructor(ooTreeMap)(const ooHandleSuper(ooTreeMap) &  objH)
{
  *this = objH;
}
#else // !defined(OO_BUGGY_TEMPLATES)
inline
ooShortRef(ooTreeMap)::ooShortRefStructor(ooTreeMap)(const ooHandleSuper(ooTreeMap) &  objH) :
    ooShortRef(ooTreeSet)(objH)
{
}
#endif // !defined(OO_BUGGY_TEMPLATES)
#ifdef OO_BUGGY_TEMPLATES
inline
ooShortRef(ooTreeMap)::ooShortRefStructor(ooTreeMap)(const ooTreeMap *  fromObject)
{
  *this = fromObject;
}
#else // !defined(OO_BUGGY_TEMPLATES)
inline
ooShortRef(ooTreeMap)::ooShortRefStructor(ooTreeMap)(const ooTreeMap *  fromObject) :
    ooShortRef(ooTreeSet)(ooReinterpretCast(const ooTreeSet *,fromObject))
{
}
#endif // !defined(OO_BUGGY_TEMPLATES)


/* methods on ooHandle(ooTreeMap) */
inline
ooHandle(ooTreeMap)::ooHandleStructor(ooTreeMap)()
{
}
inline
ooHandle(ooTreeMap)::ooHandleStructor(ooTreeMap)(const ooHandle(ooTreeMap) &  objH) :
#ifdef OO_BUGGY_TEMPLATES
    ooHandle_superclass<ooTreeMap >(objH)
#else // !defined(OO_BUGGY_TEMPLATES)
    ooHandle(ooTreeSet)(objH)
#endif // !defined(OO_BUGGY_TEMPLATES)
{
}
inline
ooHandle(ooTreeMap)::ooHandleStructor(ooTreeMap)(const ooRef(ooTreeMap) &  id) :
#ifdef OO_BUGGY_TEMPLATES
    ooHandle_superclass<ooTreeMap >(id)
#else // !defined(OO_BUGGY_TEMPLATES)
    ooHandle(ooTreeSet)(id)
#endif // !defined(OO_BUGGY_TEMPLATES)
{
}
inline
ooHandle(ooTreeMap)::ooHandleStructor(ooTreeMap)(const ooTreeMap *  fromObject) :
#ifdef OO_BUGGY_TEMPLATES
    ooHandle_superclass<ooTreeMap >(ooReinterpretCast(const ooTreeSet *,fromObject))
#else // !defined(OO_BUGGY_TEMPLATES)
    ooHandle(ooTreeSet)(ooReinterpretCast(const ooTreeSet *,fromObject))
#endif // !defined(OO_BUGGY_TEMPLATES)
{
}
inline
ooHandle(ooTreeMap)&
ooHandle(ooTreeMap)::operator=(const ooRef(ooTreeMap) &  id)
{
  this->ooHandle(ooObj)::operator=(id);
  return *this;
}
inline
ooHandle(ooTreeMap)&
ooHandle(ooTreeMap)::operator=(const ooHandle(ooTreeMap) &  objH)
{
  this->ooHandle(ooObj)::operator=(objH);
  return *this;
}
inline
ooHandle(ooTreeMap)&
ooHandle(ooTreeMap)::operator=(const ooShortRef(ooTreeMap) &  shortId)
{
  this->ooHandle(ooObj)::operator=(shortId);
  return *this;
}
inline
ooHandle(ooTreeMap)&
ooHandle(ooTreeMap)::operator=(const ooTreeMap *  fromObject)
{
  this->ooHandle(ooObj)::operator=(ooReinterpretCast(const ooObj *,fromObject));
  return *this;
}
inline
ooTreeMap *
ooHandle(ooTreeMap)::pin(ooMode  openMode) const
{
  return ooReinterpretCast(ooTreeMap *, this->pin_obj_internal(openMode));
}
inline
ooTreeMap *
ooHandle(ooTreeMap)::operator->() const
{
  return this->vm();
}
inline
ooTreeMap &
ooHandle(ooTreeMap)::operator*() const
{
  return *(this->vm());
}
inline
ooHandle(ooTreeMap)::operator ooTreeMap *() const
{
  if ( _state == oocHandlePTR  )
    return ooReinterpretCast(ooTreeMap *, _ptr._obj);
  else return ooReinterpretCast(ooTreeMap *, this->get_vm());
}
inline
ooTreeMap *
ooHandle(ooTreeMap)::vm() const
{
  if ( _state == oocHandlePTR && _ptr._obj != NULL )
    return ooReinterpretCast(ooTreeMap *, _ptr._obj);
  else return ooReinterpretCast(ooTreeMap *, this->get_vm());
}
inline
ooRef(ooTreeMap) &
ooHandle(ooTreeMap)::copy(const ooHandle(ooObj) &  nearH,
		   ooRef(ooTreeMap) &              result) const
{
  this->ooHandle(ooObj)::copy(nearH, result);
  return result;
}


/* ODMG methods */
inline
ooTreeMap *
ooRef(ooTreeMap)::ptr() const
{
  return this->pin();
}
inline
ooTreeMap *
ooHandle(ooTreeMap)::ptr() const
{
  return this->operator ooTreeMap *();
}
class ooTreeMapNode;


/////////////////////////////////////////////////////////////////////////////

ooTemplateSpecialization
class CO_STORAGE_SPECIFIER ooDeref(ooTreeMapNode) : public ooDerefBase {
	friend class ooRef(ooTreeMapNode);
  public:
    ~ooDerefStructor(ooTreeMapNode)();
    inline ooTreeMapNode *operator->() const;
#ifndef OO_BUGGY_TEMPLATES
  private:
#endif // !defined(OO_BUGGY_TEMPLATES)
    ooDerefStructor(ooTreeMapNode)(ooDeref(ooTreeMapNode)& deref);
    ooDerefStructor(ooTreeMapNode)(ooObj *  fromObject);
};


#ifdef OO_BUGGY_TEMPLATES

class CO_STORAGE_SPECIFIER ooHandle_superclass<ooTreeMapNode > : public ooHandle(ooBTree) {
 protected:
  ooHandle_superclass()
    {}
  ooHandle_superclass(const ooHandle(ooBTree) &  from) :
      ooHandle(ooBTree)(from)
    {}
  ooHandle_superclass(const ooRef(ooBTree) &  from) :
      ooHandle(ooBTree)(from)
    {}
  ooHandle_superclass(const ooBTree *  from) :
      ooHandle(ooBTree)(from)
    {}
  ~ooHandle_superclass()
    {}
};

class CO_STORAGE_SPECIFIER ooShortRef_superclass<ooTreeMapNode > : public ooShortRef(ooBTree) {
};

#endif // OO_BUGGY_TEMPLATES

ooTemplateSpecialization
class CO_STORAGE_SPECIFIER ooRef(ooTreeMapNode) : public ooRef(ooBTree) {
  public:
    ooRefStructor(ooTreeMapNode)()
      {}
    ooRefStructor(ooTreeMapNode)(const ooRef(ooTreeMapNode)& id) :
	  ooRef(ooBTree)(id)
      {}
    inline ooRefStructor(ooTreeMapNode)(const ooHandleSuper(ooTreeMapNode)& objH);
    inline ooRefStructor(ooTreeMapNode)(const ooTreeMapNode *  fromObject);
    inline ooRef(ooTreeMapNode)& operator=(const ooRef(ooTreeMapNode)& id);
    inline ooRef(ooTreeMapNode)& operator=(const ooShortRefSuper(ooTreeMapNode) &shortId);
    inline ooRef(ooTreeMapNode)& operator=(const ooHandleSuper(ooTreeMapNode)& objH);
    inline ooRef(ooTreeMapNode)& operator=(const ooTreeMapNode *  fromObject);
    ooStatus lookupObj(const ooHandle(ooObj)& scopeH,
		       const ooKey& key,
		       ooMode openMode = oocRead);
    ooStatus lookupObj(const ooHandle(ooObj)& scopeH,
		       const char* name,
		       ooMode openMode = oocRead);
#ifndef OO_BUGGY_TEMPLATES
    inline ooRef(ooTreeMapNode)& copy(const ooHandle(ooObj)& nearH,
		    ooRef(ooTreeMapNode)& newObjRef) const;
    inline ooHandle(ooTreeMapNode)& copy(const ooHandle(ooObj)& nearH,
			ooHandle(ooTreeMapNode)& result) const;
    inline ooHandle(ooTreeMapNode) copy(const ooHandle(ooObj)& nearH) const;
#endif // !defined(OO_BUGGY_TEMPLATES)
    inline ooTreeMapNode *pin(ooMode openMode = oocRead) const;
    ooDeref(ooTreeMapNode) operator->() const;
    /* Use pin() or use ooHandle "operator ooTreeMapNode *" instead of vm. */
    /* OBSOLETE */ inline ooTreeMapNode *vm(ooMode openMode = oocRead) const;
    // ODMG methods:
    ooRefStructor(ooTreeMapNode)(const d_Ref_Any &from);
    ooTreeMapNode *ptr() const;
};

ooTemplateSpecialization
class CO_STORAGE_SPECIFIER ooShortRef(ooTreeMapNode) :
#ifdef OO_BUGGY_TEMPLATES
			public ooShortRef_superclass<ooTreeMapNode >
#else // !defined(OO_BUGGY_TEMPLATES)
			public ooShortRef(ooBTree)
#endif // !defined(OO_BUGGY_TEMPLATES)
					            {
  public:
    ooShortRefStructor(ooTreeMapNode)();
    ooShortRefStructor(ooTreeMapNode)(const ooShortRef(ooTreeMapNode)& shortId);
    ooShortRefStructor(ooTreeMapNode)(const ooRef(ooTreeMapNode)& id);
    ooShortRefStructor(ooTreeMapNode)(const ooHandleSuper(ooTreeMapNode) &objH);
    ooShortRefStructor(ooTreeMapNode)(const ooTreeMapNode *  fromObject);
    ooShortRef(ooTreeMapNode)& operator=(const ooShortRef(ooTreeMapNode)& shortId);
    ooShortRef(ooTreeMapNode)& operator=(const ooRef(ooTreeMapNode)& id);
    ooShortRef(ooTreeMapNode)& operator=(const ooHandleSuper(ooTreeMapNode) &objH);
    ooShortRef(ooTreeMapNode)& operator=(const ooTreeMapNode *  fromObject);
};

ooTemplateSpecialization
class CO_STORAGE_SPECIFIER ooHandle(ooTreeMapNode) :
#ifdef OO_BUGGY_TEMPLATES
		      public ooHandle_superclass<ooTreeMapNode >
#else // !defined(OO_BUGGY_TEMPLATES)
		      public ooHandle(ooBTree)
#endif // !defined(OO_BUGGY_TEMPLATES)
                                                {
  public:
    inline ooHandleStructor(ooTreeMapNode)();
    inline ooHandleStructor(ooTreeMapNode)(const ooRef(ooTreeMapNode)& id);
    inline ooHandleStructor(ooTreeMapNode)(const ooHandle(ooTreeMapNode)& objH);
    inline ooHandleStructor(ooTreeMapNode)(const ooTreeMapNode *  fromObject);
    inline ooHandle(ooTreeMapNode)& operator=(const ooRef(ooTreeMapNode)& id);
    inline ooHandle(ooTreeMapNode)& operator=(const ooHandle(ooTreeMapNode)& objH);
    inline ooHandle(ooTreeMapNode)& operator=(const ooShortRef(ooTreeMapNode)& shortId);
    inline ooHandle(ooTreeMapNode)& operator=(const ooTreeMapNode *  fromObject);
    ooStatus lookupObj(const ooHandle(ooObj)& scopeH,
		       const ooKey& key,
		       ooMode openMode = oocRead);
    ooStatus lookupObj(const ooHandle(ooObj)& scopeH,
		       const char* name,
		       ooMode openMode = oocRead);
    ooHandle(ooTreeMapNode)& copy(const ooHandle(ooObj)& nearH,
		       ooHandle(ooTreeMapNode)& result) const;
    inline ooRef(ooTreeMapNode)& copy(const ooHandle(ooObj)& nearH,
		    ooRef(ooTreeMapNode)& result) const;
    ooHandle(ooTreeMapNode) copy(const ooHandle(ooObj)& nearH) const;
    inline ooTreeMapNode *pin(ooMode openMode = oocRead) const;
    inline ooTreeMapNode *operator->() const;
    inline ooTreeMapNode &operator*() const;
    inline operator ooTreeMapNode *() const;
    /* Use "operator ooTreeMapNode *" instead of vm. */
    /* OBSOLETE */ inline ooTreeMapNode *vm() const;
    // ODMG methods:
    ooHandleStructor(ooTreeMapNode)(const d_Ref_Any &from);
    ooTreeMapNode *ptr() const;
};

ooTemplateSpecialization
class CO_STORAGE_SPECIFIER ooItr(ooTreeMapNode) : public ooHandle(ooTreeMapNode),
		    public ooIteratorObjOrContObj {
  public:
    ooItrStructor(ooTreeMapNode)();
    ~ooItrStructor(ooTreeMapNode)();
  private:
    // Defined only to prevent implicit definition:
    ooItrStructor(ooTreeMapNode)(ooItr(ooTreeMapNode)&);
    ooItr(ooTreeMapNode)    operator=(ooItr(ooTreeMapNode)&);
};


/* methods on ooDeref(ooTreeMapNode) */
inline
ooDeref(ooTreeMapNode)::ooDerefStructor(ooTreeMapNode)(ooDeref(ooTreeMapNode) &  deref) :
    ooDerefBase(deref.vm())
{
  this->pinCompensate();
}
inline
ooDeref(ooTreeMapNode)::ooDerefStructor(ooTreeMapNode)(ooObj *  fromObject) :
    ooDerefBase(fromObject)
{
}
inline
ooDeref(ooTreeMapNode)::~ooDerefStructor(ooTreeMapNode)()
{
}
inline
ooTreeMapNode *
ooDeref(ooTreeMapNode)::operator->() const
{
  return ooReinterpretCast(ooTreeMapNode *, this->vm());
}


/* methods on ooRef(ooTreeMapNode) */
inline
ooRef(ooTreeMapNode)::ooRefStructor(ooTreeMapNode)(const ooHandleSuper(ooTreeMapNode)& objH) :
    ooRef(ooBTree)(objH)
{
}
inline
ooRef(ooTreeMapNode)::ooRefStructor(ooTreeMapNode)(const ooTreeMapNode *  fromObject) :
    ooRef(ooBTree)(ooReinterpretCast(const ooBTree *, fromObject))
{
}
inline
ooRef(ooTreeMapNode)&
ooRef(ooTreeMapNode)::operator=(const ooRef(ooTreeMapNode) &  id)
{
  this->ooId::operator=(id);
  return *this;
}
inline
ooRef(ooTreeMapNode)&
ooRef(ooTreeMapNode)::operator=(const ooShortRefSuper(ooTreeMapNode) &  shortId)
{
  this->ooRef(ooObj)::operator=(shortId);
  return *this;
}
inline
ooRef(ooTreeMapNode)&
ooRef(ooTreeMapNode)::operator=(const ooHandleSuper(ooTreeMapNode) &  objH)
{
  this->ooRef(ooObj)::operator=(objH);
  return *this;
}
inline
ooRef(ooTreeMapNode)&
ooRef(ooTreeMapNode)::operator=(const ooTreeMapNode *  fromObject)
{
  this->ooRef(ooObj)::operator=(ooReinterpretCast(const ooObj *, fromObject));
  return *this;
}
inline
ooTreeMapNode *
ooRef(ooTreeMapNode)::pin(ooMode  openMode) const
{
  return ooReinterpretCast(ooTreeMapNode *, this->pin_ref_internal(openMode));
}
inline
ooTreeMapNode *
ooRef(ooTreeMapNode)::vm(ooMode  openMode) const
{
  return this->pin(openMode);
}
#ifndef OO_BUGGY_TEMPLATES
inline
ooHandle(ooTreeMapNode) &
ooRef(ooTreeMapNode)::copy(const ooHandle(ooObj) &  nearH,
		ooHandle(ooTreeMapNode) &           result) const
{
  this->ooRef(ooObj)::copy(nearH, result);
  return result;
}
inline
ooRef(ooTreeMapNode) &
ooRef(ooTreeMapNode)::copy(const ooHandle(ooObj) &  nearH,
		ooRef(ooTreeMapNode) &              newObjRef) const
{
  this->ooRef(ooObj)::copy(nearH, newObjRef);
  return newObjRef;
}
inline
ooHandle(ooTreeMapNode)
ooRef(ooTreeMapNode)::copy(const ooHandle(ooObj) &  nearH) const
{
  ooHandle(ooTreeMapNode) result;
  this->ooRef(ooObj)::copy(nearH, result);
  return result;
}
#endif // !defined(OO_BUGGY_TEMPLATES)
inline
ooDeref(ooTreeMapNode)
ooRef(ooTreeMapNode)::operator->() const
{
  ooDeref(ooTreeMapNode) result(this->pin_ref_internal(oocRead));
  return result;
}


/* methods on ooShortRef(ooTreeMapNode) */
inline
ooShortRef(ooTreeMapNode) &
ooShortRef(ooTreeMapNode)::operator=(const ooShortRef(ooTreeMapNode) &  shortId)
{
  this->ooShortId::operator=(shortId);
  return *this;
}
inline
ooShortRef(ooTreeMapNode) &
ooShortRef(ooTreeMapNode)::operator=(const ooRef(ooTreeMapNode) &  id)
{
  this->ooShortId::operator=(id);
  return *this;
}
inline
ooShortRef(ooTreeMapNode) &
ooShortRef(ooTreeMapNode)::operator=(const ooHandleSuper(ooTreeMapNode) &  objH)
{
  this->ooShortId::operator=(objH);
  return *this;
}
inline
ooShortRef(ooTreeMapNode)&
ooShortRef(ooTreeMapNode)::operator=(const ooTreeMapNode *  fromObject)
{
  this->ooShortId::operator=(ooReinterpretCast(const ooObj *,fromObject));
  return *this;
}
inline
ooShortRef(ooTreeMapNode)::ooShortRefStructor(ooTreeMapNode)()
{
}
#ifdef OO_BUGGY_TEMPLATES
inline
ooShortRef(ooTreeMapNode)::ooShortRefStructor(ooTreeMapNode)(const ooShortRef(ooTreeMapNode) &  shortId)
{
  *this = shortId;
}
#else // !defined(OO_BUGGY_TEMPLATES)
inline
ooShortRef(ooTreeMapNode)::ooShortRefStructor(ooTreeMapNode)(const ooShortRef(ooTreeMapNode) &  shortId) :
    ooShortRef(ooBTree)(shortId)
{
}
#endif // !defined(OO_BUGGY_TEMPLATES)
#ifdef OO_BUGGY_TEMPLATES
inline
ooShortRef(ooTreeMapNode)::ooShortRefStructor(ooTreeMapNode)(const ooRef(ooTreeMapNode) &  id)
{
  *this = id;
}
#else // !defined(OO_BUGGY_TEMPLATES)
inline
ooShortRef(ooTreeMapNode)::ooShortRefStructor(ooTreeMapNode)(const ooRef(ooTreeMapNode) &  id) :
    ooShortRef(ooBTree)(id)
{
}
#endif // !defined(OO_BUGGY_TEMPLATES)
#ifdef OO_BUGGY_TEMPLATES
inline
ooShortRef(ooTreeMapNode)::ooShortRefStructor(ooTreeMapNode)(const ooHandleSuper(ooTreeMapNode) &  objH)
{
  *this = objH;
}
#else // !defined(OO_BUGGY_TEMPLATES)
inline
ooShortRef(ooTreeMapNode)::ooShortRefStructor(ooTreeMapNode)(const ooHandleSuper(ooTreeMapNode) &  objH) :
    ooShortRef(ooBTree)(objH)
{
}
#endif // !defined(OO_BUGGY_TEMPLATES)
#ifdef OO_BUGGY_TEMPLATES
inline
ooShortRef(ooTreeMapNode)::ooShortRefStructor(ooTreeMapNode)(const ooTreeMapNode *  fromObject)
{
  *this = fromObject;
}
#else // !defined(OO_BUGGY_TEMPLATES)
inline
ooShortRef(ooTreeMapNode)::ooShortRefStructor(ooTreeMapNode)(const ooTreeMapNode *  fromObject) :
    ooShortRef(ooBTree)(ooReinterpretCast(const ooBTree *,fromObject))
{
}
#endif // !defined(OO_BUGGY_TEMPLATES)


/* methods on ooHandle(ooTreeMapNode) */
inline
ooHandle(ooTreeMapNode)::ooHandleStructor(ooTreeMapNode)()
{
}
inline
ooHandle(ooTreeMapNode)::ooHandleStructor(ooTreeMapNode)(const ooHandle(ooTreeMapNode) &  objH) :
#ifdef OO_BUGGY_TEMPLATES
    ooHandle_superclass<ooTreeMapNode >(objH)
#else // !defined(OO_BUGGY_TEMPLATES)
    ooHandle(ooBTree)(objH)
#endif // !defined(OO_BUGGY_TEMPLATES)
{
}
inline
ooHandle(ooTreeMapNode)::ooHandleStructor(ooTreeMapNode)(const ooRef(ooTreeMapNode) &  id) :
#ifdef OO_BUGGY_TEMPLATES
    ooHandle_superclass<ooTreeMapNode >(id)
#else // !defined(OO_BUGGY_TEMPLATES)
    ooHandle(ooBTree)(id)
#endif // !defined(OO_BUGGY_TEMPLATES)
{
}
inline
ooHandle(ooTreeMapNode)::ooHandleStructor(ooTreeMapNode)(const ooTreeMapNode *  fromObject) :
#ifdef OO_BUGGY_TEMPLATES
    ooHandle_superclass<ooTreeMapNode >(ooReinterpretCast(const ooBTree *,fromObject))
#else // !defined(OO_BUGGY_TEMPLATES)
    ooHandle(ooBTree)(ooReinterpretCast(const ooBTree *,fromObject))
#endif // !defined(OO_BUGGY_TEMPLATES)
{
}
inline
ooHandle(ooTreeMapNode)&
ooHandle(ooTreeMapNode)::operator=(const ooRef(ooTreeMapNode) &  id)
{
  this->ooHandle(ooObj)::operator=(id);
  return *this;
}
inline
ooHandle(ooTreeMapNode)&
ooHandle(ooTreeMapNode)::operator=(const ooHandle(ooTreeMapNode) &  objH)
{
  this->ooHandle(ooObj)::operator=(objH);
  return *this;
}
inline
ooHandle(ooTreeMapNode)&
ooHandle(ooTreeMapNode)::operator=(const ooShortRef(ooTreeMapNode) &  shortId)
{
  this->ooHandle(ooObj)::operator=(shortId);
  return *this;
}
inline
ooHandle(ooTreeMapNode)&
ooHandle(ooTreeMapNode)::operator=(const ooTreeMapNode *  fromObject)
{
  this->ooHandle(ooObj)::operator=(ooReinterpretCast(const ooObj *,fromObject));
  return *this;
}
inline
ooTreeMapNode *
ooHandle(ooTreeMapNode)::pin(ooMode  openMode) const
{
  return ooReinterpretCast(ooTreeMapNode *, this->pin_obj_internal(openMode));
}
inline
ooTreeMapNode *
ooHandle(ooTreeMapNode)::operator->() const
{
  return this->vm();
}
inline
ooTreeMapNode &
ooHandle(ooTreeMapNode)::operator*() const
{
  return *(this->vm());
}
inline
ooHandle(ooTreeMapNode)::operator ooTreeMapNode *() const
{
  if ( _state == oocHandlePTR  )
    return ooReinterpretCast(ooTreeMapNode *, _ptr._obj);
  else return ooReinterpretCast(ooTreeMapNode *, this->get_vm());
}
inline
ooTreeMapNode *
ooHandle(ooTreeMapNode)::vm() const
{
  if ( _state == oocHandlePTR && _ptr._obj != NULL )
    return ooReinterpretCast(ooTreeMapNode *, _ptr._obj);
  else return ooReinterpretCast(ooTreeMapNode *, this->get_vm());
}
inline
ooRef(ooTreeMapNode) &
ooHandle(ooTreeMapNode)::copy(const ooHandle(ooObj) &  nearH,
		   ooRef(ooTreeMapNode) &              result) const
{
  this->ooHandle(ooObj)::copy(nearH, result);
  return result;
}


/* ODMG methods */
inline
ooTreeMapNode *
ooRef(ooTreeMapNode)::ptr() const
{
  return this->pin();
}
inline
ooTreeMapNode *
ooHandle(ooTreeMapNode)::ptr() const
{
  return this->operator ooTreeMapNode *();
}
class ooAdmin;


/////////////////////////////////////////////////////////////////////////////

ooTemplateSpecialization
class CO_STORAGE_SPECIFIER ooDeref(ooAdmin) : public ooDerefBase {
	friend class ooRef(ooAdmin);
  public:
    ~ooDerefStructor(ooAdmin)();
    inline ooAdmin *operator->() const;
#ifndef OO_BUGGY_TEMPLATES
  private:
#endif // !defined(OO_BUGGY_TEMPLATES)
    ooDerefStructor(ooAdmin)(ooDeref(ooAdmin)& deref);
    ooDerefStructor(ooAdmin)(ooObj *  fromObject);
};


#ifdef OO_BUGGY_TEMPLATES

class CO_STORAGE_SPECIFIER ooHandle_superclass<ooAdmin > : public ooHandle(ooObj) {
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

class CO_STORAGE_SPECIFIER ooShortRef_superclass<ooAdmin > : public ooShortRef(ooObj) {
};

#endif // OO_BUGGY_TEMPLATES

ooTemplateSpecialization
class CO_STORAGE_SPECIFIER ooRef(ooAdmin) : public ooRef(ooObj) {
  public:
    ooRefStructor(ooAdmin)()
      {}
    ooRefStructor(ooAdmin)(const ooRef(ooAdmin)& id) :
	  ooRef(ooObj)(id)
      {}
    inline ooRefStructor(ooAdmin)(const ooHandleSuper(ooAdmin)& objH);
    inline ooRefStructor(ooAdmin)(const ooAdmin *  fromObject);
    inline ooRef(ooAdmin)& operator=(const ooRef(ooAdmin)& id);
    inline ooRef(ooAdmin)& operator=(const ooShortRefSuper(ooAdmin) &shortId);
    inline ooRef(ooAdmin)& operator=(const ooHandleSuper(ooAdmin)& objH);
    inline ooRef(ooAdmin)& operator=(const ooAdmin *  fromObject);
    ooStatus lookupObj(const ooHandle(ooObj)& scopeH,
		       const ooKey& key,
		       ooMode openMode = oocRead);
    ooStatus lookupObj(const ooHandle(ooObj)& scopeH,
		       const char* name,
		       ooMode openMode = oocRead);
#ifndef OO_BUGGY_TEMPLATES
    inline ooRef(ooAdmin)& copy(const ooHandle(ooObj)& nearH,
		    ooRef(ooAdmin)& newObjRef) const;
    inline ooHandle(ooAdmin)& copy(const ooHandle(ooObj)& nearH,
			ooHandle(ooAdmin)& result) const;
    inline ooHandle(ooAdmin) copy(const ooHandle(ooObj)& nearH) const;
#endif // !defined(OO_BUGGY_TEMPLATES)
    inline ooAdmin *pin(ooMode openMode = oocRead) const;
    ooDeref(ooAdmin) operator->() const;
    /* Use pin() or use ooHandle "operator ooAdmin *" instead of vm. */
    /* OBSOLETE */ inline ooAdmin *vm(ooMode openMode = oocRead) const;
    // ODMG methods:
    ooRefStructor(ooAdmin)(const d_Ref_Any &from);
    ooAdmin *ptr() const;
};

ooTemplateSpecialization
class CO_STORAGE_SPECIFIER ooShortRef(ooAdmin) :
#ifdef OO_BUGGY_TEMPLATES
			public ooShortRef_superclass<ooAdmin >
#else // !defined(OO_BUGGY_TEMPLATES)
			public ooShortRef(ooObj)
#endif // !defined(OO_BUGGY_TEMPLATES)
					            {
  public:
    ooShortRefStructor(ooAdmin)();
    ooShortRefStructor(ooAdmin)(const ooShortRef(ooAdmin)& shortId);
    ooShortRefStructor(ooAdmin)(const ooRef(ooAdmin)& id);
    ooShortRefStructor(ooAdmin)(const ooHandleSuper(ooAdmin) &objH);
    ooShortRefStructor(ooAdmin)(const ooAdmin *  fromObject);
    ooShortRef(ooAdmin)& operator=(const ooShortRef(ooAdmin)& shortId);
    ooShortRef(ooAdmin)& operator=(const ooRef(ooAdmin)& id);
    ooShortRef(ooAdmin)& operator=(const ooHandleSuper(ooAdmin) &objH);
    ooShortRef(ooAdmin)& operator=(const ooAdmin *  fromObject);
};

ooTemplateSpecialization
class CO_STORAGE_SPECIFIER ooHandle(ooAdmin) :
#ifdef OO_BUGGY_TEMPLATES
		      public ooHandle_superclass<ooAdmin >
#else // !defined(OO_BUGGY_TEMPLATES)
		      public ooHandle(ooObj)
#endif // !defined(OO_BUGGY_TEMPLATES)
                                                {
  public:
    inline ooHandleStructor(ooAdmin)();
    inline ooHandleStructor(ooAdmin)(const ooRef(ooAdmin)& id);
    inline ooHandleStructor(ooAdmin)(const ooHandle(ooAdmin)& objH);
    inline ooHandleStructor(ooAdmin)(const ooAdmin *  fromObject);
    inline ooHandle(ooAdmin)& operator=(const ooRef(ooAdmin)& id);
    inline ooHandle(ooAdmin)& operator=(const ooHandle(ooAdmin)& objH);
    inline ooHandle(ooAdmin)& operator=(const ooShortRef(ooAdmin)& shortId);
    inline ooHandle(ooAdmin)& operator=(const ooAdmin *  fromObject);
    ooStatus lookupObj(const ooHandle(ooObj)& scopeH,
		       const ooKey& key,
		       ooMode openMode = oocRead);
    ooStatus lookupObj(const ooHandle(ooObj)& scopeH,
		       const char* name,
		       ooMode openMode = oocRead);
    ooHandle(ooAdmin)& copy(const ooHandle(ooObj)& nearH,
		       ooHandle(ooAdmin)& result) const;
    inline ooRef(ooAdmin)& copy(const ooHandle(ooObj)& nearH,
		    ooRef(ooAdmin)& result) const;
    ooHandle(ooAdmin) copy(const ooHandle(ooObj)& nearH) const;
    inline ooAdmin *pin(ooMode openMode = oocRead) const;
    inline ooAdmin *operator->() const;
    inline ooAdmin &operator*() const;
    inline operator ooAdmin *() const;
    /* Use "operator ooAdmin *" instead of vm. */
    /* OBSOLETE */ inline ooAdmin *vm() const;
    // ODMG methods:
    ooHandleStructor(ooAdmin)(const d_Ref_Any &from);
    ooAdmin *ptr() const;
};

ooTemplateSpecialization
class CO_STORAGE_SPECIFIER ooItr(ooAdmin) : public ooHandle(ooAdmin),
		    public ooIteratorObjOrContObj {
  public:
    ooItrStructor(ooAdmin)();
    ~ooItrStructor(ooAdmin)();
  private:
    // Defined only to prevent implicit definition:
    ooItrStructor(ooAdmin)(ooItr(ooAdmin)&);
    ooItr(ooAdmin)    operator=(ooItr(ooAdmin)&);
};


/* methods on ooDeref(ooAdmin) */
inline
ooDeref(ooAdmin)::ooDerefStructor(ooAdmin)(ooDeref(ooAdmin) &  deref) :
    ooDerefBase(deref.vm())
{
  this->pinCompensate();
}
inline
ooDeref(ooAdmin)::ooDerefStructor(ooAdmin)(ooObj *  fromObject) :
    ooDerefBase(fromObject)
{
}
inline
ooDeref(ooAdmin)::~ooDerefStructor(ooAdmin)()
{
}
inline
ooAdmin *
ooDeref(ooAdmin)::operator->() const
{
  return ooReinterpretCast(ooAdmin *, this->vm());
}


/* methods on ooRef(ooAdmin) */
inline
ooRef(ooAdmin)::ooRefStructor(ooAdmin)(const ooHandleSuper(ooAdmin)& objH) :
    ooRef(ooObj)(objH)
{
}
inline
ooRef(ooAdmin)::ooRefStructor(ooAdmin)(const ooAdmin *  fromObject) :
    ooRef(ooObj)(ooReinterpretCast(const ooObj *, fromObject))
{
}
inline
ooRef(ooAdmin)&
ooRef(ooAdmin)::operator=(const ooRef(ooAdmin) &  id)
{
  this->ooId::operator=(id);
  return *this;
}
inline
ooRef(ooAdmin)&
ooRef(ooAdmin)::operator=(const ooShortRefSuper(ooAdmin) &  shortId)
{
  this->ooRef(ooObj)::operator=(shortId);
  return *this;
}
inline
ooRef(ooAdmin)&
ooRef(ooAdmin)::operator=(const ooHandleSuper(ooAdmin) &  objH)
{
  this->ooRef(ooObj)::operator=(objH);
  return *this;
}
inline
ooRef(ooAdmin)&
ooRef(ooAdmin)::operator=(const ooAdmin *  fromObject)
{
  this->ooRef(ooObj)::operator=(ooReinterpretCast(const ooObj *, fromObject));
  return *this;
}
inline
ooAdmin *
ooRef(ooAdmin)::pin(ooMode  openMode) const
{
  return ooReinterpretCast(ooAdmin *, this->pin_ref_internal(openMode));
}
inline
ooAdmin *
ooRef(ooAdmin)::vm(ooMode  openMode) const
{
  return this->pin(openMode);
}
#ifndef OO_BUGGY_TEMPLATES
inline
ooHandle(ooAdmin) &
ooRef(ooAdmin)::copy(const ooHandle(ooObj) &  nearH,
		ooHandle(ooAdmin) &           result) const
{
  this->ooRef(ooObj)::copy(nearH, result);
  return result;
}
inline
ooRef(ooAdmin) &
ooRef(ooAdmin)::copy(const ooHandle(ooObj) &  nearH,
		ooRef(ooAdmin) &              newObjRef) const
{
  this->ooRef(ooObj)::copy(nearH, newObjRef);
  return newObjRef;
}
inline
ooHandle(ooAdmin)
ooRef(ooAdmin)::copy(const ooHandle(ooObj) &  nearH) const
{
  ooHandle(ooAdmin) result;
  this->ooRef(ooObj)::copy(nearH, result);
  return result;
}
#endif // !defined(OO_BUGGY_TEMPLATES)
inline
ooDeref(ooAdmin)
ooRef(ooAdmin)::operator->() const
{
  ooDeref(ooAdmin) result(this->pin_ref_internal(oocRead));
  return result;
}


/* methods on ooShortRef(ooAdmin) */
inline
ooShortRef(ooAdmin) &
ooShortRef(ooAdmin)::operator=(const ooShortRef(ooAdmin) &  shortId)
{
  this->ooShortId::operator=(shortId);
  return *this;
}
inline
ooShortRef(ooAdmin) &
ooShortRef(ooAdmin)::operator=(const ooRef(ooAdmin) &  id)
{
  this->ooShortId::operator=(id);
  return *this;
}
inline
ooShortRef(ooAdmin) &
ooShortRef(ooAdmin)::operator=(const ooHandleSuper(ooAdmin) &  objH)
{
  this->ooShortId::operator=(objH);
  return *this;
}
inline
ooShortRef(ooAdmin)&
ooShortRef(ooAdmin)::operator=(const ooAdmin *  fromObject)
{
  this->ooShortId::operator=(ooReinterpretCast(const ooObj *,fromObject));
  return *this;
}
inline
ooShortRef(ooAdmin)::ooShortRefStructor(ooAdmin)()
{
}
#ifdef OO_BUGGY_TEMPLATES
inline
ooShortRef(ooAdmin)::ooShortRefStructor(ooAdmin)(const ooShortRef(ooAdmin) &  shortId)
{
  *this = shortId;
}
#else // !defined(OO_BUGGY_TEMPLATES)
inline
ooShortRef(ooAdmin)::ooShortRefStructor(ooAdmin)(const ooShortRef(ooAdmin) &  shortId) :
    ooShortRef(ooObj)(shortId)
{
}
#endif // !defined(OO_BUGGY_TEMPLATES)
#ifdef OO_BUGGY_TEMPLATES
inline
ooShortRef(ooAdmin)::ooShortRefStructor(ooAdmin)(const ooRef(ooAdmin) &  id)
{
  *this = id;
}
#else // !defined(OO_BUGGY_TEMPLATES)
inline
ooShortRef(ooAdmin)::ooShortRefStructor(ooAdmin)(const ooRef(ooAdmin) &  id) :
    ooShortRef(ooObj)(id)
{
}
#endif // !defined(OO_BUGGY_TEMPLATES)
#ifdef OO_BUGGY_TEMPLATES
inline
ooShortRef(ooAdmin)::ooShortRefStructor(ooAdmin)(const ooHandleSuper(ooAdmin) &  objH)
{
  *this = objH;
}
#else // !defined(OO_BUGGY_TEMPLATES)
inline
ooShortRef(ooAdmin)::ooShortRefStructor(ooAdmin)(const ooHandleSuper(ooAdmin) &  objH) :
    ooShortRef(ooObj)(objH)
{
}
#endif // !defined(OO_BUGGY_TEMPLATES)
#ifdef OO_BUGGY_TEMPLATES
inline
ooShortRef(ooAdmin)::ooShortRefStructor(ooAdmin)(const ooAdmin *  fromObject)
{
  *this = fromObject;
}
#else // !defined(OO_BUGGY_TEMPLATES)
inline
ooShortRef(ooAdmin)::ooShortRefStructor(ooAdmin)(const ooAdmin *  fromObject) :
    ooShortRef(ooObj)(ooReinterpretCast(const ooObj *,fromObject))
{
}
#endif // !defined(OO_BUGGY_TEMPLATES)


/* methods on ooHandle(ooAdmin) */
inline
ooHandle(ooAdmin)::ooHandleStructor(ooAdmin)()
{
}
inline
ooHandle(ooAdmin)::ooHandleStructor(ooAdmin)(const ooHandle(ooAdmin) &  objH) :
#ifdef OO_BUGGY_TEMPLATES
    ooHandle_superclass<ooAdmin >(objH)
#else // !defined(OO_BUGGY_TEMPLATES)
    ooHandle(ooObj)(objH)
#endif // !defined(OO_BUGGY_TEMPLATES)
{
}
inline
ooHandle(ooAdmin)::ooHandleStructor(ooAdmin)(const ooRef(ooAdmin) &  id) :
#ifdef OO_BUGGY_TEMPLATES
    ooHandle_superclass<ooAdmin >(id)
#else // !defined(OO_BUGGY_TEMPLATES)
    ooHandle(ooObj)(id)
#endif // !defined(OO_BUGGY_TEMPLATES)
{
}
inline
ooHandle(ooAdmin)::ooHandleStructor(ooAdmin)(const ooAdmin *  fromObject) :
#ifdef OO_BUGGY_TEMPLATES
    ooHandle_superclass<ooAdmin >(ooReinterpretCast(const ooObj *,fromObject))
#else // !defined(OO_BUGGY_TEMPLATES)
    ooHandle(ooObj)(ooReinterpretCast(const ooObj *,fromObject))
#endif // !defined(OO_BUGGY_TEMPLATES)
{
}
inline
ooHandle(ooAdmin)&
ooHandle(ooAdmin)::operator=(const ooRef(ooAdmin) &  id)
{
  this->ooHandle(ooObj)::operator=(id);
  return *this;
}
inline
ooHandle(ooAdmin)&
ooHandle(ooAdmin)::operator=(const ooHandle(ooAdmin) &  objH)
{
  this->ooHandle(ooObj)::operator=(objH);
  return *this;
}
inline
ooHandle(ooAdmin)&
ooHandle(ooAdmin)::operator=(const ooShortRef(ooAdmin) &  shortId)
{
  this->ooHandle(ooObj)::operator=(shortId);
  return *this;
}
inline
ooHandle(ooAdmin)&
ooHandle(ooAdmin)::operator=(const ooAdmin *  fromObject)
{
  this->ooHandle(ooObj)::operator=(ooReinterpretCast(const ooObj *,fromObject));
  return *this;
}
inline
ooAdmin *
ooHandle(ooAdmin)::pin(ooMode  openMode) const
{
  return ooReinterpretCast(ooAdmin *, this->pin_obj_internal(openMode));
}
inline
ooAdmin *
ooHandle(ooAdmin)::operator->() const
{
  return this->vm();
}
inline
ooAdmin &
ooHandle(ooAdmin)::operator*() const
{
  return *(this->vm());
}
inline
ooHandle(ooAdmin)::operator ooAdmin *() const
{
  if ( _state == oocHandlePTR  )
    return ooReinterpretCast(ooAdmin *, _ptr._obj);
  else return ooReinterpretCast(ooAdmin *, this->get_vm());
}
inline
ooAdmin *
ooHandle(ooAdmin)::vm() const
{
  if ( _state == oocHandlePTR && _ptr._obj != NULL )
    return ooReinterpretCast(ooAdmin *, _ptr._obj);
  else return ooReinterpretCast(ooAdmin *, this->get_vm());
}
inline
ooRef(ooAdmin) &
ooHandle(ooAdmin)::copy(const ooHandle(ooObj) &  nearH,
		   ooRef(ooAdmin) &              result) const
{
  this->ooHandle(ooObj)::copy(nearH, result);
  return result;
}


/* ODMG methods */
inline
ooAdmin *
ooRef(ooAdmin)::ptr() const
{
  return this->pin();
}
inline
ooAdmin *
ooHandle(ooAdmin)::ptr() const
{
  return this->operator ooAdmin *();
}
class ooTreeAdmin;


/////////////////////////////////////////////////////////////////////////////

ooTemplateSpecialization
class CO_STORAGE_SPECIFIER ooDeref(ooTreeAdmin) : public ooDerefBase {
	friend class ooRef(ooTreeAdmin);
  public:
    ~ooDerefStructor(ooTreeAdmin)();
    inline ooTreeAdmin *operator->() const;
#ifndef OO_BUGGY_TEMPLATES
  private:
#endif // !defined(OO_BUGGY_TEMPLATES)
    ooDerefStructor(ooTreeAdmin)(ooDeref(ooTreeAdmin)& deref);
    ooDerefStructor(ooTreeAdmin)(ooObj *  fromObject);
};


#ifdef OO_BUGGY_TEMPLATES

class CO_STORAGE_SPECIFIER ooHandle_superclass<ooTreeAdmin > : public ooHandle(ooAdmin) {
 protected:
  ooHandle_superclass()
    {}
  ooHandle_superclass(const ooHandle(ooAdmin) &  from) :
      ooHandle(ooAdmin)(from)
    {}
  ooHandle_superclass(const ooRef(ooAdmin) &  from) :
      ooHandle(ooAdmin)(from)
    {}
  ooHandle_superclass(const ooAdmin *  from) :
      ooHandle(ooAdmin)(from)
    {}
  ~ooHandle_superclass()
    {}
};

class CO_STORAGE_SPECIFIER ooShortRef_superclass<ooTreeAdmin > : public ooShortRef(ooAdmin) {
};

#endif // OO_BUGGY_TEMPLATES

ooTemplateSpecialization
class CO_STORAGE_SPECIFIER ooRef(ooTreeAdmin) : public ooRef(ooAdmin) {
  public:
    ooRefStructor(ooTreeAdmin)()
      {}
    ooRefStructor(ooTreeAdmin)(const ooRef(ooTreeAdmin)& id) :
	  ooRef(ooAdmin)(id)
      {}
    inline ooRefStructor(ooTreeAdmin)(const ooHandleSuper(ooTreeAdmin)& objH);
    inline ooRefStructor(ooTreeAdmin)(const ooTreeAdmin *  fromObject);
    inline ooRef(ooTreeAdmin)& operator=(const ooRef(ooTreeAdmin)& id);
    inline ooRef(ooTreeAdmin)& operator=(const ooShortRefSuper(ooTreeAdmin) &shortId);
    inline ooRef(ooTreeAdmin)& operator=(const ooHandleSuper(ooTreeAdmin)& objH);
    inline ooRef(ooTreeAdmin)& operator=(const ooTreeAdmin *  fromObject);
    ooStatus lookupObj(const ooHandle(ooObj)& scopeH,
		       const ooKey& key,
		       ooMode openMode = oocRead);
    ooStatus lookupObj(const ooHandle(ooObj)& scopeH,
		       const char* name,
		       ooMode openMode = oocRead);
#ifndef OO_BUGGY_TEMPLATES
    inline ooRef(ooTreeAdmin)& copy(const ooHandle(ooObj)& nearH,
		    ooRef(ooTreeAdmin)& newObjRef) const;
    inline ooHandle(ooTreeAdmin)& copy(const ooHandle(ooObj)& nearH,
			ooHandle(ooTreeAdmin)& result) const;
    inline ooHandle(ooTreeAdmin) copy(const ooHandle(ooObj)& nearH) const;
#endif // !defined(OO_BUGGY_TEMPLATES)
    inline ooTreeAdmin *pin(ooMode openMode = oocRead) const;
    ooDeref(ooTreeAdmin) operator->() const;
    /* Use pin() or use ooHandle "operator ooTreeAdmin *" instead of vm. */
    /* OBSOLETE */ inline ooTreeAdmin *vm(ooMode openMode = oocRead) const;
    // ODMG methods:
    ooRefStructor(ooTreeAdmin)(const d_Ref_Any &from);
    ooTreeAdmin *ptr() const;
};

ooTemplateSpecialization
class CO_STORAGE_SPECIFIER ooShortRef(ooTreeAdmin) :
#ifdef OO_BUGGY_TEMPLATES
			public ooShortRef_superclass<ooTreeAdmin >
#else // !defined(OO_BUGGY_TEMPLATES)
			public ooShortRef(ooAdmin)
#endif // !defined(OO_BUGGY_TEMPLATES)
					            {
  public:
    ooShortRefStructor(ooTreeAdmin)();
    ooShortRefStructor(ooTreeAdmin)(const ooShortRef(ooTreeAdmin)& shortId);
    ooShortRefStructor(ooTreeAdmin)(const ooRef(ooTreeAdmin)& id);
    ooShortRefStructor(ooTreeAdmin)(const ooHandleSuper(ooTreeAdmin) &objH);
    ooShortRefStructor(ooTreeAdmin)(const ooTreeAdmin *  fromObject);
    ooShortRef(ooTreeAdmin)& operator=(const ooShortRef(ooTreeAdmin)& shortId);
    ooShortRef(ooTreeAdmin)& operator=(const ooRef(ooTreeAdmin)& id);
    ooShortRef(ooTreeAdmin)& operator=(const ooHandleSuper(ooTreeAdmin) &objH);
    ooShortRef(ooTreeAdmin)& operator=(const ooTreeAdmin *  fromObject);
};

ooTemplateSpecialization
class CO_STORAGE_SPECIFIER ooHandle(ooTreeAdmin) :
#ifdef OO_BUGGY_TEMPLATES
		      public ooHandle_superclass<ooTreeAdmin >
#else // !defined(OO_BUGGY_TEMPLATES)
		      public ooHandle(ooAdmin)
#endif // !defined(OO_BUGGY_TEMPLATES)
                                                {
  public:
    inline ooHandleStructor(ooTreeAdmin)();
    inline ooHandleStructor(ooTreeAdmin)(const ooRef(ooTreeAdmin)& id);
    inline ooHandleStructor(ooTreeAdmin)(const ooHandle(ooTreeAdmin)& objH);
    inline ooHandleStructor(ooTreeAdmin)(const ooTreeAdmin *  fromObject);
    inline ooHandle(ooTreeAdmin)& operator=(const ooRef(ooTreeAdmin)& id);
    inline ooHandle(ooTreeAdmin)& operator=(const ooHandle(ooTreeAdmin)& objH);
    inline ooHandle(ooTreeAdmin)& operator=(const ooShortRef(ooTreeAdmin)& shortId);
    inline ooHandle(ooTreeAdmin)& operator=(const ooTreeAdmin *  fromObject);
    ooStatus lookupObj(const ooHandle(ooObj)& scopeH,
		       const ooKey& key,
		       ooMode openMode = oocRead);
    ooStatus lookupObj(const ooHandle(ooObj)& scopeH,
		       const char* name,
		       ooMode openMode = oocRead);
    ooHandle(ooTreeAdmin)& copy(const ooHandle(ooObj)& nearH,
		       ooHandle(ooTreeAdmin)& result) const;
    inline ooRef(ooTreeAdmin)& copy(const ooHandle(ooObj)& nearH,
		    ooRef(ooTreeAdmin)& result) const;
    ooHandle(ooTreeAdmin) copy(const ooHandle(ooObj)& nearH) const;
    inline ooTreeAdmin *pin(ooMode openMode = oocRead) const;
    inline ooTreeAdmin *operator->() const;
    inline ooTreeAdmin &operator*() const;
    inline operator ooTreeAdmin *() const;
    /* Use "operator ooTreeAdmin *" instead of vm. */
    /* OBSOLETE */ inline ooTreeAdmin *vm() const;
    // ODMG methods:
    ooHandleStructor(ooTreeAdmin)(const d_Ref_Any &from);
    ooTreeAdmin *ptr() const;
};

ooTemplateSpecialization
class CO_STORAGE_SPECIFIER ooItr(ooTreeAdmin) : public ooHandle(ooTreeAdmin),
		    public ooIteratorObjOrContObj {
  public:
    ooItrStructor(ooTreeAdmin)();
    ~ooItrStructor(ooTreeAdmin)();
  private:
    // Defined only to prevent implicit definition:
    ooItrStructor(ooTreeAdmin)(ooItr(ooTreeAdmin)&);
    ooItr(ooTreeAdmin)    operator=(ooItr(ooTreeAdmin)&);
};


/* methods on ooDeref(ooTreeAdmin) */
inline
ooDeref(ooTreeAdmin)::ooDerefStructor(ooTreeAdmin)(ooDeref(ooTreeAdmin) &  deref) :
    ooDerefBase(deref.vm())
{
  this->pinCompensate();
}
inline
ooDeref(ooTreeAdmin)::ooDerefStructor(ooTreeAdmin)(ooObj *  fromObject) :
    ooDerefBase(fromObject)
{
}
inline
ooDeref(ooTreeAdmin)::~ooDerefStructor(ooTreeAdmin)()
{
}
inline
ooTreeAdmin *
ooDeref(ooTreeAdmin)::operator->() const
{
  return ooReinterpretCast(ooTreeAdmin *, this->vm());
}


/* methods on ooRef(ooTreeAdmin) */
inline
ooRef(ooTreeAdmin)::ooRefStructor(ooTreeAdmin)(const ooHandleSuper(ooTreeAdmin)& objH) :
    ooRef(ooAdmin)(objH)
{
}
inline
ooRef(ooTreeAdmin)::ooRefStructor(ooTreeAdmin)(const ooTreeAdmin *  fromObject) :
    ooRef(ooAdmin)(ooReinterpretCast(const ooAdmin *, fromObject))
{
}
inline
ooRef(ooTreeAdmin)&
ooRef(ooTreeAdmin)::operator=(const ooRef(ooTreeAdmin) &  id)
{
  this->ooId::operator=(id);
  return *this;
}
inline
ooRef(ooTreeAdmin)&
ooRef(ooTreeAdmin)::operator=(const ooShortRefSuper(ooTreeAdmin) &  shortId)
{
  this->ooRef(ooObj)::operator=(shortId);
  return *this;
}
inline
ooRef(ooTreeAdmin)&
ooRef(ooTreeAdmin)::operator=(const ooHandleSuper(ooTreeAdmin) &  objH)
{
  this->ooRef(ooObj)::operator=(objH);
  return *this;
}
inline
ooRef(ooTreeAdmin)&
ooRef(ooTreeAdmin)::operator=(const ooTreeAdmin *  fromObject)
{
  this->ooRef(ooObj)::operator=(ooReinterpretCast(const ooObj *, fromObject));
  return *this;
}
inline
ooTreeAdmin *
ooRef(ooTreeAdmin)::pin(ooMode  openMode) const
{
  return ooReinterpretCast(ooTreeAdmin *, this->pin_ref_internal(openMode));
}
inline
ooTreeAdmin *
ooRef(ooTreeAdmin)::vm(ooMode  openMode) const
{
  return this->pin(openMode);
}
#ifndef OO_BUGGY_TEMPLATES
inline
ooHandle(ooTreeAdmin) &
ooRef(ooTreeAdmin)::copy(const ooHandle(ooObj) &  nearH,
		ooHandle(ooTreeAdmin) &           result) const
{
  this->ooRef(ooObj)::copy(nearH, result);
  return result;
}
inline
ooRef(ooTreeAdmin) &
ooRef(ooTreeAdmin)::copy(const ooHandle(ooObj) &  nearH,
		ooRef(ooTreeAdmin) &              newObjRef) const
{
  this->ooRef(ooObj)::copy(nearH, newObjRef);
  return newObjRef;
}
inline
ooHandle(ooTreeAdmin)
ooRef(ooTreeAdmin)::copy(const ooHandle(ooObj) &  nearH) const
{
  ooHandle(ooTreeAdmin) result;
  this->ooRef(ooObj)::copy(nearH, result);
  return result;
}
#endif // !defined(OO_BUGGY_TEMPLATES)
inline
ooDeref(ooTreeAdmin)
ooRef(ooTreeAdmin)::operator->() const
{
  ooDeref(ooTreeAdmin) result(this->pin_ref_internal(oocRead));
  return result;
}


/* methods on ooShortRef(ooTreeAdmin) */
inline
ooShortRef(ooTreeAdmin) &
ooShortRef(ooTreeAdmin)::operator=(const ooShortRef(ooTreeAdmin) &  shortId)
{
  this->ooShortId::operator=(shortId);
  return *this;
}
inline
ooShortRef(ooTreeAdmin) &
ooShortRef(ooTreeAdmin)::operator=(const ooRef(ooTreeAdmin) &  id)
{
  this->ooShortId::operator=(id);
  return *this;
}
inline
ooShortRef(ooTreeAdmin) &
ooShortRef(ooTreeAdmin)::operator=(const ooHandleSuper(ooTreeAdmin) &  objH)
{
  this->ooShortId::operator=(objH);
  return *this;
}
inline
ooShortRef(ooTreeAdmin)&
ooShortRef(ooTreeAdmin)::operator=(const ooTreeAdmin *  fromObject)
{
  this->ooShortId::operator=(ooReinterpretCast(const ooObj *,fromObject));
  return *this;
}
inline
ooShortRef(ooTreeAdmin)::ooShortRefStructor(ooTreeAdmin)()
{
}
#ifdef OO_BUGGY_TEMPLATES
inline
ooShortRef(ooTreeAdmin)::ooShortRefStructor(ooTreeAdmin)(const ooShortRef(ooTreeAdmin) &  shortId)
{
  *this = shortId;
}
#else // !defined(OO_BUGGY_TEMPLATES)
inline
ooShortRef(ooTreeAdmin)::ooShortRefStructor(ooTreeAdmin)(const ooShortRef(ooTreeAdmin) &  shortId) :
    ooShortRef(ooAdmin)(shortId)
{
}
#endif // !defined(OO_BUGGY_TEMPLATES)
#ifdef OO_BUGGY_TEMPLATES
inline
ooShortRef(ooTreeAdmin)::ooShortRefStructor(ooTreeAdmin)(const ooRef(ooTreeAdmin) &  id)
{
  *this = id;
}
#else // !defined(OO_BUGGY_TEMPLATES)
inline
ooShortRef(ooTreeAdmin)::ooShortRefStructor(ooTreeAdmin)(const ooRef(ooTreeAdmin) &  id) :
    ooShortRef(ooAdmin)(id)
{
}
#endif // !defined(OO_BUGGY_TEMPLATES)
#ifdef OO_BUGGY_TEMPLATES
inline
ooShortRef(ooTreeAdmin)::ooShortRefStructor(ooTreeAdmin)(const ooHandleSuper(ooTreeAdmin) &  objH)
{
  *this = objH;
}
#else // !defined(OO_BUGGY_TEMPLATES)
inline
ooShortRef(ooTreeAdmin)::ooShortRefStructor(ooTreeAdmin)(const ooHandleSuper(ooTreeAdmin) &  objH) :
    ooShortRef(ooAdmin)(objH)
{
}
#endif // !defined(OO_BUGGY_TEMPLATES)
#ifdef OO_BUGGY_TEMPLATES
inline
ooShortRef(ooTreeAdmin)::ooShortRefStructor(ooTreeAdmin)(const ooTreeAdmin *  fromObject)
{
  *this = fromObject;
}
#else // !defined(OO_BUGGY_TEMPLATES)
inline
ooShortRef(ooTreeAdmin)::ooShortRefStructor(ooTreeAdmin)(const ooTreeAdmin *  fromObject) :
    ooShortRef(ooAdmin)(ooReinterpretCast(const ooAdmin *,fromObject))
{
}
#endif // !defined(OO_BUGGY_TEMPLATES)


/* methods on ooHandle(ooTreeAdmin) */
inline
ooHandle(ooTreeAdmin)::ooHandleStructor(ooTreeAdmin)()
{
}
inline
ooHandle(ooTreeAdmin)::ooHandleStructor(ooTreeAdmin)(const ooHandle(ooTreeAdmin) &  objH) :
#ifdef OO_BUGGY_TEMPLATES
    ooHandle_superclass<ooTreeAdmin >(objH)
#else // !defined(OO_BUGGY_TEMPLATES)
    ooHandle(ooAdmin)(objH)
#endif // !defined(OO_BUGGY_TEMPLATES)
{
}
inline
ooHandle(ooTreeAdmin)::ooHandleStructor(ooTreeAdmin)(const ooRef(ooTreeAdmin) &  id) :
#ifdef OO_BUGGY_TEMPLATES
    ooHandle_superclass<ooTreeAdmin >(id)
#else // !defined(OO_BUGGY_TEMPLATES)
    ooHandle(ooAdmin)(id)
#endif // !defined(OO_BUGGY_TEMPLATES)
{
}
inline
ooHandle(ooTreeAdmin)::ooHandleStructor(ooTreeAdmin)(const ooTreeAdmin *  fromObject) :
#ifdef OO_BUGGY_TEMPLATES
    ooHandle_superclass<ooTreeAdmin >(ooReinterpretCast(const ooAdmin *,fromObject))
#else // !defined(OO_BUGGY_TEMPLATES)
    ooHandle(ooAdmin)(ooReinterpretCast(const ooAdmin *,fromObject))
#endif // !defined(OO_BUGGY_TEMPLATES)
{
}
inline
ooHandle(ooTreeAdmin)&
ooHandle(ooTreeAdmin)::operator=(const ooRef(ooTreeAdmin) &  id)
{
  this->ooHandle(ooObj)::operator=(id);
  return *this;
}
inline
ooHandle(ooTreeAdmin)&
ooHandle(ooTreeAdmin)::operator=(const ooHandle(ooTreeAdmin) &  objH)
{
  this->ooHandle(ooObj)::operator=(objH);
  return *this;
}
inline
ooHandle(ooTreeAdmin)&
ooHandle(ooTreeAdmin)::operator=(const ooShortRef(ooTreeAdmin) &  shortId)
{
  this->ooHandle(ooObj)::operator=(shortId);
  return *this;
}
inline
ooHandle(ooTreeAdmin)&
ooHandle(ooTreeAdmin)::operator=(const ooTreeAdmin *  fromObject)
{
  this->ooHandle(ooObj)::operator=(ooReinterpretCast(const ooObj *,fromObject));
  return *this;
}
inline
ooTreeAdmin *
ooHandle(ooTreeAdmin)::pin(ooMode  openMode) const
{
  return ooReinterpretCast(ooTreeAdmin *, this->pin_obj_internal(openMode));
}
inline
ooTreeAdmin *
ooHandle(ooTreeAdmin)::operator->() const
{
  return this->vm();
}
inline
ooTreeAdmin &
ooHandle(ooTreeAdmin)::operator*() const
{
  return *(this->vm());
}
inline
ooHandle(ooTreeAdmin)::operator ooTreeAdmin *() const
{
  if ( _state == oocHandlePTR  )
    return ooReinterpretCast(ooTreeAdmin *, _ptr._obj);
  else return ooReinterpretCast(ooTreeAdmin *, this->get_vm());
}
inline
ooTreeAdmin *
ooHandle(ooTreeAdmin)::vm() const
{
  if ( _state == oocHandlePTR && _ptr._obj != NULL )
    return ooReinterpretCast(ooTreeAdmin *, _ptr._obj);
  else return ooReinterpretCast(ooTreeAdmin *, this->get_vm());
}
inline
ooRef(ooTreeAdmin) &
ooHandle(ooTreeAdmin)::copy(const ooHandle(ooObj) &  nearH,
		   ooRef(ooTreeAdmin) &              result) const
{
  this->ooHandle(ooObj)::copy(nearH, result);
  return result;
}


/* ODMG methods */
inline
ooTreeAdmin *
ooRef(ooTreeAdmin)::ptr() const
{
  return this->pin();
}
inline
ooTreeAdmin *
ooHandle(ooTreeAdmin)::ptr() const
{
  return this->operator ooTreeAdmin *();
}
class ooHashMapEntry;


/////////////////////////////////////////////////////////////////////////////

ooTemplateSpecialization
class CO_STORAGE_SPECIFIER ooDeref(ooHashMapEntry) : public ooDerefBase {
	friend class ooRef(ooHashMapEntry);
  public:
    ~ooDerefStructor(ooHashMapEntry)();
    inline ooHashMapEntry *operator->() const;
#ifndef OO_BUGGY_TEMPLATES
  private:
#endif // !defined(OO_BUGGY_TEMPLATES)
    ooDerefStructor(ooHashMapEntry)(ooDeref(ooHashMapEntry)& deref);
    ooDerefStructor(ooHashMapEntry)(ooObj *  fromObject);
};


#ifdef OO_BUGGY_TEMPLATES

class CO_STORAGE_SPECIFIER ooHandle_superclass<ooHashMapEntry > : public ooHandle(ooObj) {
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

class CO_STORAGE_SPECIFIER ooShortRef_superclass<ooHashMapEntry > : public ooShortRef(ooObj) {
};

#endif // OO_BUGGY_TEMPLATES

ooTemplateSpecialization
class CO_STORAGE_SPECIFIER ooRef(ooHashMapEntry) : public ooRef(ooObj) {
  public:
    ooRefStructor(ooHashMapEntry)()
      {}
    ooRefStructor(ooHashMapEntry)(const ooRef(ooHashMapEntry)& id) :
	  ooRef(ooObj)(id)
      {}
    inline ooRefStructor(ooHashMapEntry)(const ooHandleSuper(ooHashMapEntry)& objH);
    inline ooRefStructor(ooHashMapEntry)(const ooHashMapEntry *  fromObject);
    inline ooRef(ooHashMapEntry)& operator=(const ooRef(ooHashMapEntry)& id);
    inline ooRef(ooHashMapEntry)& operator=(const ooShortRefSuper(ooHashMapEntry) &shortId);
    inline ooRef(ooHashMapEntry)& operator=(const ooHandleSuper(ooHashMapEntry)& objH);
    inline ooRef(ooHashMapEntry)& operator=(const ooHashMapEntry *  fromObject);
    ooStatus lookupObj(const ooHandle(ooObj)& scopeH,
		       const ooKey& key,
		       ooMode openMode = oocRead);
    ooStatus lookupObj(const ooHandle(ooObj)& scopeH,
		       const char* name,
		       ooMode openMode = oocRead);
#ifndef OO_BUGGY_TEMPLATES
    inline ooRef(ooHashMapEntry)& copy(const ooHandle(ooObj)& nearH,
		    ooRef(ooHashMapEntry)& newObjRef) const;
    inline ooHandle(ooHashMapEntry)& copy(const ooHandle(ooObj)& nearH,
			ooHandle(ooHashMapEntry)& result) const;
    inline ooHandle(ooHashMapEntry) copy(const ooHandle(ooObj)& nearH) const;
#endif // !defined(OO_BUGGY_TEMPLATES)
    inline ooHashMapEntry *pin(ooMode openMode = oocRead) const;
    ooDeref(ooHashMapEntry) operator->() const;
    /* Use pin() or use ooHandle "operator ooHashMapEntry *" instead of vm. */
    /* OBSOLETE */ inline ooHashMapEntry *vm(ooMode openMode = oocRead) const;
    // ODMG methods:
    ooRefStructor(ooHashMapEntry)(const d_Ref_Any &from);
    ooHashMapEntry *ptr() const;
};

ooTemplateSpecialization
class CO_STORAGE_SPECIFIER ooShortRef(ooHashMapEntry) :
#ifdef OO_BUGGY_TEMPLATES
			public ooShortRef_superclass<ooHashMapEntry >
#else // !defined(OO_BUGGY_TEMPLATES)
			public ooShortRef(ooObj)
#endif // !defined(OO_BUGGY_TEMPLATES)
					            {
  public:
    ooShortRefStructor(ooHashMapEntry)();
    ooShortRefStructor(ooHashMapEntry)(const ooShortRef(ooHashMapEntry)& shortId);
    ooShortRefStructor(ooHashMapEntry)(const ooRef(ooHashMapEntry)& id);
    ooShortRefStructor(ooHashMapEntry)(const ooHandleSuper(ooHashMapEntry) &objH);
    ooShortRefStructor(ooHashMapEntry)(const ooHashMapEntry *  fromObject);
    ooShortRef(ooHashMapEntry)& operator=(const ooShortRef(ooHashMapEntry)& shortId);
    ooShortRef(ooHashMapEntry)& operator=(const ooRef(ooHashMapEntry)& id);
    ooShortRef(ooHashMapEntry)& operator=(const ooHandleSuper(ooHashMapEntry) &objH);
    ooShortRef(ooHashMapEntry)& operator=(const ooHashMapEntry *  fromObject);
};

ooTemplateSpecialization
class CO_STORAGE_SPECIFIER ooHandle(ooHashMapEntry) :
#ifdef OO_BUGGY_TEMPLATES
		      public ooHandle_superclass<ooHashMapEntry >
#else // !defined(OO_BUGGY_TEMPLATES)
		      public ooHandle(ooObj)
#endif // !defined(OO_BUGGY_TEMPLATES)
                                                {
  public:
    inline ooHandleStructor(ooHashMapEntry)();
    inline ooHandleStructor(ooHashMapEntry)(const ooRef(ooHashMapEntry)& id);
    inline ooHandleStructor(ooHashMapEntry)(const ooHandle(ooHashMapEntry)& objH);
    inline ooHandleStructor(ooHashMapEntry)(const ooHashMapEntry *  fromObject);
    inline ooHandle(ooHashMapEntry)& operator=(const ooRef(ooHashMapEntry)& id);
    inline ooHandle(ooHashMapEntry)& operator=(const ooHandle(ooHashMapEntry)& objH);
    inline ooHandle(ooHashMapEntry)& operator=(const ooShortRef(ooHashMapEntry)& shortId);
    inline ooHandle(ooHashMapEntry)& operator=(const ooHashMapEntry *  fromObject);
    ooStatus lookupObj(const ooHandle(ooObj)& scopeH,
		       const ooKey& key,
		       ooMode openMode = oocRead);
    ooStatus lookupObj(const ooHandle(ooObj)& scopeH,
		       const char* name,
		       ooMode openMode = oocRead);
    ooHandle(ooHashMapEntry)& copy(const ooHandle(ooObj)& nearH,
		       ooHandle(ooHashMapEntry)& result) const;
    inline ooRef(ooHashMapEntry)& copy(const ooHandle(ooObj)& nearH,
		    ooRef(ooHashMapEntry)& result) const;
    ooHandle(ooHashMapEntry) copy(const ooHandle(ooObj)& nearH) const;
    inline ooHashMapEntry *pin(ooMode openMode = oocRead) const;
    inline ooHashMapEntry *operator->() const;
    inline ooHashMapEntry &operator*() const;
    inline operator ooHashMapEntry *() const;
    /* Use "operator ooHashMapEntry *" instead of vm. */
    /* OBSOLETE */ inline ooHashMapEntry *vm() const;
    // ODMG methods:
    ooHandleStructor(ooHashMapEntry)(const d_Ref_Any &from);
    ooHashMapEntry *ptr() const;
};

ooTemplateSpecialization
class CO_STORAGE_SPECIFIER ooItr(ooHashMapEntry) : public ooHandle(ooHashMapEntry),
		    public ooIteratorObjOrContObj {
  public:
    ooItrStructor(ooHashMapEntry)();
    ~ooItrStructor(ooHashMapEntry)();
  private:
    // Defined only to prevent implicit definition:
    ooItrStructor(ooHashMapEntry)(ooItr(ooHashMapEntry)&);
    ooItr(ooHashMapEntry)    operator=(ooItr(ooHashMapEntry)&);
};


/* methods on ooDeref(ooHashMapEntry) */
inline
ooDeref(ooHashMapEntry)::ooDerefStructor(ooHashMapEntry)(ooDeref(ooHashMapEntry) &  deref) :
    ooDerefBase(deref.vm())
{
  this->pinCompensate();
}
inline
ooDeref(ooHashMapEntry)::ooDerefStructor(ooHashMapEntry)(ooObj *  fromObject) :
    ooDerefBase(fromObject)
{
}
inline
ooDeref(ooHashMapEntry)::~ooDerefStructor(ooHashMapEntry)()
{
}
inline
ooHashMapEntry *
ooDeref(ooHashMapEntry)::operator->() const
{
  return ooReinterpretCast(ooHashMapEntry *, this->vm());
}


/* methods on ooRef(ooHashMapEntry) */
inline
ooRef(ooHashMapEntry)::ooRefStructor(ooHashMapEntry)(const ooHandleSuper(ooHashMapEntry)& objH) :
    ooRef(ooObj)(objH)
{
}
inline
ooRef(ooHashMapEntry)::ooRefStructor(ooHashMapEntry)(const ooHashMapEntry *  fromObject) :
    ooRef(ooObj)(ooReinterpretCast(const ooObj *, fromObject))
{
}
inline
ooRef(ooHashMapEntry)&
ooRef(ooHashMapEntry)::operator=(const ooRef(ooHashMapEntry) &  id)
{
  this->ooId::operator=(id);
  return *this;
}
inline
ooRef(ooHashMapEntry)&
ooRef(ooHashMapEntry)::operator=(const ooShortRefSuper(ooHashMapEntry) &  shortId)
{
  this->ooRef(ooObj)::operator=(shortId);
  return *this;
}
inline
ooRef(ooHashMapEntry)&
ooRef(ooHashMapEntry)::operator=(const ooHandleSuper(ooHashMapEntry) &  objH)
{
  this->ooRef(ooObj)::operator=(objH);
  return *this;
}
inline
ooRef(ooHashMapEntry)&
ooRef(ooHashMapEntry)::operator=(const ooHashMapEntry *  fromObject)
{
  this->ooRef(ooObj)::operator=(ooReinterpretCast(const ooObj *, fromObject));
  return *this;
}
inline
ooHashMapEntry *
ooRef(ooHashMapEntry)::pin(ooMode  openMode) const
{
  return ooReinterpretCast(ooHashMapEntry *, this->pin_ref_internal(openMode));
}
inline
ooHashMapEntry *
ooRef(ooHashMapEntry)::vm(ooMode  openMode) const
{
  return this->pin(openMode);
}
#ifndef OO_BUGGY_TEMPLATES
inline
ooHandle(ooHashMapEntry) &
ooRef(ooHashMapEntry)::copy(const ooHandle(ooObj) &  nearH,
		ooHandle(ooHashMapEntry) &           result) const
{
  this->ooRef(ooObj)::copy(nearH, result);
  return result;
}
inline
ooRef(ooHashMapEntry) &
ooRef(ooHashMapEntry)::copy(const ooHandle(ooObj) &  nearH,
		ooRef(ooHashMapEntry) &              newObjRef) const
{
  this->ooRef(ooObj)::copy(nearH, newObjRef);
  return newObjRef;
}
inline
ooHandle(ooHashMapEntry)
ooRef(ooHashMapEntry)::copy(const ooHandle(ooObj) &  nearH) const
{
  ooHandle(ooHashMapEntry) result;
  this->ooRef(ooObj)::copy(nearH, result);
  return result;
}
#endif // !defined(OO_BUGGY_TEMPLATES)
inline
ooDeref(ooHashMapEntry)
ooRef(ooHashMapEntry)::operator->() const
{
  ooDeref(ooHashMapEntry) result(this->pin_ref_internal(oocRead));
  return result;
}


/* methods on ooShortRef(ooHashMapEntry) */
inline
ooShortRef(ooHashMapEntry) &
ooShortRef(ooHashMapEntry)::operator=(const ooShortRef(ooHashMapEntry) &  shortId)
{
  this->ooShortId::operator=(shortId);
  return *this;
}
inline
ooShortRef(ooHashMapEntry) &
ooShortRef(ooHashMapEntry)::operator=(const ooRef(ooHashMapEntry) &  id)
{
  this->ooShortId::operator=(id);
  return *this;
}
inline
ooShortRef(ooHashMapEntry) &
ooShortRef(ooHashMapEntry)::operator=(const ooHandleSuper(ooHashMapEntry) &  objH)
{
  this->ooShortId::operator=(objH);
  return *this;
}
inline
ooShortRef(ooHashMapEntry)&
ooShortRef(ooHashMapEntry)::operator=(const ooHashMapEntry *  fromObject)
{
  this->ooShortId::operator=(ooReinterpretCast(const ooObj *,fromObject));
  return *this;
}
inline
ooShortRef(ooHashMapEntry)::ooShortRefStructor(ooHashMapEntry)()
{
}
#ifdef OO_BUGGY_TEMPLATES
inline
ooShortRef(ooHashMapEntry)::ooShortRefStructor(ooHashMapEntry)(const ooShortRef(ooHashMapEntry) &  shortId)
{
  *this = shortId;
}
#else // !defined(OO_BUGGY_TEMPLATES)
inline
ooShortRef(ooHashMapEntry)::ooShortRefStructor(ooHashMapEntry)(const ooShortRef(ooHashMapEntry) &  shortId) :
    ooShortRef(ooObj)(shortId)
{
}
#endif // !defined(OO_BUGGY_TEMPLATES)
#ifdef OO_BUGGY_TEMPLATES
inline
ooShortRef(ooHashMapEntry)::ooShortRefStructor(ooHashMapEntry)(const ooRef(ooHashMapEntry) &  id)
{
  *this = id;
}
#else // !defined(OO_BUGGY_TEMPLATES)
inline
ooShortRef(ooHashMapEntry)::ooShortRefStructor(ooHashMapEntry)(const ooRef(ooHashMapEntry) &  id) :
    ooShortRef(ooObj)(id)
{
}
#endif // !defined(OO_BUGGY_TEMPLATES)
#ifdef OO_BUGGY_TEMPLATES
inline
ooShortRef(ooHashMapEntry)::ooShortRefStructor(ooHashMapEntry)(const ooHandleSuper(ooHashMapEntry) &  objH)
{
  *this = objH;
}
#else // !defined(OO_BUGGY_TEMPLATES)
inline
ooShortRef(ooHashMapEntry)::ooShortRefStructor(ooHashMapEntry)(const ooHandleSuper(ooHashMapEntry) &  objH) :
    ooShortRef(ooObj)(objH)
{
}
#endif // !defined(OO_BUGGY_TEMPLATES)
#ifdef OO_BUGGY_TEMPLATES
inline
ooShortRef(ooHashMapEntry)::ooShortRefStructor(ooHashMapEntry)(const ooHashMapEntry *  fromObject)
{
  *this = fromObject;
}
#else // !defined(OO_BUGGY_TEMPLATES)
inline
ooShortRef(ooHashMapEntry)::ooShortRefStructor(ooHashMapEntry)(const ooHashMapEntry *  fromObject) :
    ooShortRef(ooObj)(ooReinterpretCast(const ooObj *,fromObject))
{
}
#endif // !defined(OO_BUGGY_TEMPLATES)


/* methods on ooHandle(ooHashMapEntry) */
inline
ooHandle(ooHashMapEntry)::ooHandleStructor(ooHashMapEntry)()
{
}
inline
ooHandle(ooHashMapEntry)::ooHandleStructor(ooHashMapEntry)(const ooHandle(ooHashMapEntry) &  objH) :
#ifdef OO_BUGGY_TEMPLATES
    ooHandle_superclass<ooHashMapEntry >(objH)
#else // !defined(OO_BUGGY_TEMPLATES)
    ooHandle(ooObj)(objH)
#endif // !defined(OO_BUGGY_TEMPLATES)
{
}
inline
ooHandle(ooHashMapEntry)::ooHandleStructor(ooHashMapEntry)(const ooRef(ooHashMapEntry) &  id) :
#ifdef OO_BUGGY_TEMPLATES
    ooHandle_superclass<ooHashMapEntry >(id)
#else // !defined(OO_BUGGY_TEMPLATES)
    ooHandle(ooObj)(id)
#endif // !defined(OO_BUGGY_TEMPLATES)
{
}
inline
ooHandle(ooHashMapEntry)::ooHandleStructor(ooHashMapEntry)(const ooHashMapEntry *  fromObject) :
#ifdef OO_BUGGY_TEMPLATES
    ooHandle_superclass<ooHashMapEntry >(ooReinterpretCast(const ooObj *,fromObject))
#else // !defined(OO_BUGGY_TEMPLATES)
    ooHandle(ooObj)(ooReinterpretCast(const ooObj *,fromObject))
#endif // !defined(OO_BUGGY_TEMPLATES)
{
}
inline
ooHandle(ooHashMapEntry)&
ooHandle(ooHashMapEntry)::operator=(const ooRef(ooHashMapEntry) &  id)
{
  this->ooHandle(ooObj)::operator=(id);
  return *this;
}
inline
ooHandle(ooHashMapEntry)&
ooHandle(ooHashMapEntry)::operator=(const ooHandle(ooHashMapEntry) &  objH)
{
  this->ooHandle(ooObj)::operator=(objH);
  return *this;
}
inline
ooHandle(ooHashMapEntry)&
ooHandle(ooHashMapEntry)::operator=(const ooShortRef(ooHashMapEntry) &  shortId)
{
  this->ooHandle(ooObj)::operator=(shortId);
  return *this;
}
inline
ooHandle(ooHashMapEntry)&
ooHandle(ooHashMapEntry)::operator=(const ooHashMapEntry *  fromObject)
{
  this->ooHandle(ooObj)::operator=(ooReinterpretCast(const ooObj *,fromObject));
  return *this;
}
inline
ooHashMapEntry *
ooHandle(ooHashMapEntry)::pin(ooMode  openMode) const
{
  return ooReinterpretCast(ooHashMapEntry *, this->pin_obj_internal(openMode));
}
inline
ooHashMapEntry *
ooHandle(ooHashMapEntry)::operator->() const
{
  return this->vm();
}
inline
ooHashMapEntry &
ooHandle(ooHashMapEntry)::operator*() const
{
  return *(this->vm());
}
inline
ooHandle(ooHashMapEntry)::operator ooHashMapEntry *() const
{
  if ( _state == oocHandlePTR  )
    return ooReinterpretCast(ooHashMapEntry *, _ptr._obj);
  else return ooReinterpretCast(ooHashMapEntry *, this->get_vm());
}
inline
ooHashMapEntry *
ooHandle(ooHashMapEntry)::vm() const
{
  if ( _state == oocHandlePTR && _ptr._obj != NULL )
    return ooReinterpretCast(ooHashMapEntry *, _ptr._obj);
  else return ooReinterpretCast(ooHashMapEntry *, this->get_vm());
}
inline
ooRef(ooHashMapEntry) &
ooHandle(ooHashMapEntry)::copy(const ooHandle(ooObj) &  nearH,
		   ooRef(ooHashMapEntry) &              result) const
{
  this->ooHandle(ooObj)::copy(nearH, result);
  return result;
}


/* ODMG methods */
inline
ooHashMapEntry *
ooRef(ooHashMapEntry)::ptr() const
{
  return this->pin();
}
inline
ooHashMapEntry *
ooHandle(ooHashMapEntry)::ptr() const
{
  return this->operator ooHashMapEntry *();
}
class ooHashAdmin;


/////////////////////////////////////////////////////////////////////////////

ooTemplateSpecialization
class CO_STORAGE_SPECIFIER ooDeref(ooHashAdmin) : public ooDerefBase {
	friend class ooRef(ooHashAdmin);
  public:
    ~ooDerefStructor(ooHashAdmin)();
    inline ooHashAdmin *operator->() const;
#ifndef OO_BUGGY_TEMPLATES
  private:
#endif // !defined(OO_BUGGY_TEMPLATES)
    ooDerefStructor(ooHashAdmin)(ooDeref(ooHashAdmin)& deref);
    ooDerefStructor(ooHashAdmin)(ooObj *  fromObject);
};


#ifdef OO_BUGGY_TEMPLATES

class CO_STORAGE_SPECIFIER ooHandle_superclass<ooHashAdmin > : public ooHandle(ooAdmin) {
 protected:
  ooHandle_superclass()
    {}
  ooHandle_superclass(const ooHandle(ooAdmin) &  from) :
      ooHandle(ooAdmin)(from)
    {}
  ooHandle_superclass(const ooRef(ooAdmin) &  from) :
      ooHandle(ooAdmin)(from)
    {}
  ooHandle_superclass(const ooAdmin *  from) :
      ooHandle(ooAdmin)(from)
    {}
  ~ooHandle_superclass()
    {}
};

class CO_STORAGE_SPECIFIER ooShortRef_superclass<ooHashAdmin > : public ooShortRef(ooAdmin) {
};

#endif // OO_BUGGY_TEMPLATES

ooTemplateSpecialization
class CO_STORAGE_SPECIFIER ooRef(ooHashAdmin) : public ooRef(ooAdmin) {
  public:
    ooRefStructor(ooHashAdmin)()
      {}
    ooRefStructor(ooHashAdmin)(const ooRef(ooHashAdmin)& id) :
	  ooRef(ooAdmin)(id)
      {}
    inline ooRefStructor(ooHashAdmin)(const ooHandleSuper(ooHashAdmin)& objH);
    inline ooRefStructor(ooHashAdmin)(const ooHashAdmin *  fromObject);
    inline ooRef(ooHashAdmin)& operator=(const ooRef(ooHashAdmin)& id);
    inline ooRef(ooHashAdmin)& operator=(const ooShortRefSuper(ooHashAdmin) &shortId);
    inline ooRef(ooHashAdmin)& operator=(const ooHandleSuper(ooHashAdmin)& objH);
    inline ooRef(ooHashAdmin)& operator=(const ooHashAdmin *  fromObject);
    ooStatus lookupObj(const ooHandle(ooObj)& scopeH,
		       const ooKey& key,
		       ooMode openMode = oocRead);
    ooStatus lookupObj(const ooHandle(ooObj)& scopeH,
		       const char* name,
		       ooMode openMode = oocRead);
#ifndef OO_BUGGY_TEMPLATES
    inline ooRef(ooHashAdmin)& copy(const ooHandle(ooObj)& nearH,
		    ooRef(ooHashAdmin)& newObjRef) const;
    inline ooHandle(ooHashAdmin)& copy(const ooHandle(ooObj)& nearH,
			ooHandle(ooHashAdmin)& result) const;
    inline ooHandle(ooHashAdmin) copy(const ooHandle(ooObj)& nearH) const;
#endif // !defined(OO_BUGGY_TEMPLATES)
    inline ooHashAdmin *pin(ooMode openMode = oocRead) const;
    ooDeref(ooHashAdmin) operator->() const;
    /* Use pin() or use ooHandle "operator ooHashAdmin *" instead of vm. */
    /* OBSOLETE */ inline ooHashAdmin *vm(ooMode openMode = oocRead) const;
    // ODMG methods:
    ooRefStructor(ooHashAdmin)(const d_Ref_Any &from);
    ooHashAdmin *ptr() const;
};

ooTemplateSpecialization
class CO_STORAGE_SPECIFIER ooShortRef(ooHashAdmin) :
#ifdef OO_BUGGY_TEMPLATES
			public ooShortRef_superclass<ooHashAdmin >
#else // !defined(OO_BUGGY_TEMPLATES)
			public ooShortRef(ooAdmin)
#endif // !defined(OO_BUGGY_TEMPLATES)
					            {
  public:
    ooShortRefStructor(ooHashAdmin)();
    ooShortRefStructor(ooHashAdmin)(const ooShortRef(ooHashAdmin)& shortId);
    ooShortRefStructor(ooHashAdmin)(const ooRef(ooHashAdmin)& id);
    ooShortRefStructor(ooHashAdmin)(const ooHandleSuper(ooHashAdmin) &objH);
    ooShortRefStructor(ooHashAdmin)(const ooHashAdmin *  fromObject);
    ooShortRef(ooHashAdmin)& operator=(const ooShortRef(ooHashAdmin)& shortId);
    ooShortRef(ooHashAdmin)& operator=(const ooRef(ooHashAdmin)& id);
    ooShortRef(ooHashAdmin)& operator=(const ooHandleSuper(ooHashAdmin) &objH);
    ooShortRef(ooHashAdmin)& operator=(const ooHashAdmin *  fromObject);
};

ooTemplateSpecialization
class CO_STORAGE_SPECIFIER ooHandle(ooHashAdmin) :
#ifdef OO_BUGGY_TEMPLATES
		      public ooHandle_superclass<ooHashAdmin >
#else // !defined(OO_BUGGY_TEMPLATES)
		      public ooHandle(ooAdmin)
#endif // !defined(OO_BUGGY_TEMPLATES)
                                                {
  public:
    inline ooHandleStructor(ooHashAdmin)();
    inline ooHandleStructor(ooHashAdmin)(const ooRef(ooHashAdmin)& id);
    inline ooHandleStructor(ooHashAdmin)(const ooHandle(ooHashAdmin)& objH);
    inline ooHandleStructor(ooHashAdmin)(const ooHashAdmin *  fromObject);
    inline ooHandle(ooHashAdmin)& operator=(const ooRef(ooHashAdmin)& id);
    inline ooHandle(ooHashAdmin)& operator=(const ooHandle(ooHashAdmin)& objH);
    inline ooHandle(ooHashAdmin)& operator=(const ooShortRef(ooHashAdmin)& shortId);
    inline ooHandle(ooHashAdmin)& operator=(const ooHashAdmin *  fromObject);
    ooStatus lookupObj(const ooHandle(ooObj)& scopeH,
		       const ooKey& key,
		       ooMode openMode = oocRead);
    ooStatus lookupObj(const ooHandle(ooObj)& scopeH,
		       const char* name,
		       ooMode openMode = oocRead);
    ooHandle(ooHashAdmin)& copy(const ooHandle(ooObj)& nearH,
		       ooHandle(ooHashAdmin)& result) const;
    inline ooRef(ooHashAdmin)& copy(const ooHandle(ooObj)& nearH,
		    ooRef(ooHashAdmin)& result) const;
    ooHandle(ooHashAdmin) copy(const ooHandle(ooObj)& nearH) const;
    inline ooHashAdmin *pin(ooMode openMode = oocRead) const;
    inline ooHashAdmin *operator->() const;
    inline ooHashAdmin &operator*() const;
    inline operator ooHashAdmin *() const;
    /* Use "operator ooHashAdmin *" instead of vm. */
    /* OBSOLETE */ inline ooHashAdmin *vm() const;
    // ODMG methods:
    ooHandleStructor(ooHashAdmin)(const d_Ref_Any &from);
    ooHashAdmin *ptr() const;
};

ooTemplateSpecialization
class CO_STORAGE_SPECIFIER ooItr(ooHashAdmin) : public ooHandle(ooHashAdmin),
		    public ooIteratorObjOrContObj {
  public:
    ooItrStructor(ooHashAdmin)();
    ~ooItrStructor(ooHashAdmin)();
  private:
    // Defined only to prevent implicit definition:
    ooItrStructor(ooHashAdmin)(ooItr(ooHashAdmin)&);
    ooItr(ooHashAdmin)    operator=(ooItr(ooHashAdmin)&);
};


/* methods on ooDeref(ooHashAdmin) */
inline
ooDeref(ooHashAdmin)::ooDerefStructor(ooHashAdmin)(ooDeref(ooHashAdmin) &  deref) :
    ooDerefBase(deref.vm())
{
  this->pinCompensate();
}
inline
ooDeref(ooHashAdmin)::ooDerefStructor(ooHashAdmin)(ooObj *  fromObject) :
    ooDerefBase(fromObject)
{
}
inline
ooDeref(ooHashAdmin)::~ooDerefStructor(ooHashAdmin)()
{
}
inline
ooHashAdmin *
ooDeref(ooHashAdmin)::operator->() const
{
  return ooReinterpretCast(ooHashAdmin *, this->vm());
}


/* methods on ooRef(ooHashAdmin) */
inline
ooRef(ooHashAdmin)::ooRefStructor(ooHashAdmin)(const ooHandleSuper(ooHashAdmin)& objH) :
    ooRef(ooAdmin)(objH)
{
}
inline
ooRef(ooHashAdmin)::ooRefStructor(ooHashAdmin)(const ooHashAdmin *  fromObject) :
    ooRef(ooAdmin)(ooReinterpretCast(const ooAdmin *, fromObject))
{
}
inline
ooRef(ooHashAdmin)&
ooRef(ooHashAdmin)::operator=(const ooRef(ooHashAdmin) &  id)
{
  this->ooId::operator=(id);
  return *this;
}
inline
ooRef(ooHashAdmin)&
ooRef(ooHashAdmin)::operator=(const ooShortRefSuper(ooHashAdmin) &  shortId)
{
  this->ooRef(ooObj)::operator=(shortId);
  return *this;
}
inline
ooRef(ooHashAdmin)&
ooRef(ooHashAdmin)::operator=(const ooHandleSuper(ooHashAdmin) &  objH)
{
  this->ooRef(ooObj)::operator=(objH);
  return *this;
}
inline
ooRef(ooHashAdmin)&
ooRef(ooHashAdmin)::operator=(const ooHashAdmin *  fromObject)
{
  this->ooRef(ooObj)::operator=(ooReinterpretCast(const ooObj *, fromObject));
  return *this;
}
inline
ooHashAdmin *
ooRef(ooHashAdmin)::pin(ooMode  openMode) const
{
  return ooReinterpretCast(ooHashAdmin *, this->pin_ref_internal(openMode));
}
inline
ooHashAdmin *
ooRef(ooHashAdmin)::vm(ooMode  openMode) const
{
  return this->pin(openMode);
}
#ifndef OO_BUGGY_TEMPLATES
inline
ooHandle(ooHashAdmin) &
ooRef(ooHashAdmin)::copy(const ooHandle(ooObj) &  nearH,
		ooHandle(ooHashAdmin) &           result) const
{
  this->ooRef(ooObj)::copy(nearH, result);
  return result;
}
inline
ooRef(ooHashAdmin) &
ooRef(ooHashAdmin)::copy(const ooHandle(ooObj) &  nearH,
		ooRef(ooHashAdmin) &              newObjRef) const
{
  this->ooRef(ooObj)::copy(nearH, newObjRef);
  return newObjRef;
}
inline
ooHandle(ooHashAdmin)
ooRef(ooHashAdmin)::copy(const ooHandle(ooObj) &  nearH) const
{
  ooHandle(ooHashAdmin) result;
  this->ooRef(ooObj)::copy(nearH, result);
  return result;
}
#endif // !defined(OO_BUGGY_TEMPLATES)
inline
ooDeref(ooHashAdmin)
ooRef(ooHashAdmin)::operator->() const
{
  ooDeref(ooHashAdmin) result(this->pin_ref_internal(oocRead));
  return result;
}


/* methods on ooShortRef(ooHashAdmin) */
inline
ooShortRef(ooHashAdmin) &
ooShortRef(ooHashAdmin)::operator=(const ooShortRef(ooHashAdmin) &  shortId)
{
  this->ooShortId::operator=(shortId);
  return *this;
}
inline
ooShortRef(ooHashAdmin) &
ooShortRef(ooHashAdmin)::operator=(const ooRef(ooHashAdmin) &  id)
{
  this->ooShortId::operator=(id);
  return *this;
}
inline
ooShortRef(ooHashAdmin) &
ooShortRef(ooHashAdmin)::operator=(const ooHandleSuper(ooHashAdmin) &  objH)
{
  this->ooShortId::operator=(objH);
  return *this;
}
inline
ooShortRef(ooHashAdmin)&
ooShortRef(ooHashAdmin)::operator=(const ooHashAdmin *  fromObject)
{
  this->ooShortId::operator=(ooReinterpretCast(const ooObj *,fromObject));
  return *this;
}
inline
ooShortRef(ooHashAdmin)::ooShortRefStructor(ooHashAdmin)()
{
}
#ifdef OO_BUGGY_TEMPLATES
inline
ooShortRef(ooHashAdmin)::ooShortRefStructor(ooHashAdmin)(const ooShortRef(ooHashAdmin) &  shortId)
{
  *this = shortId;
}
#else // !defined(OO_BUGGY_TEMPLATES)
inline
ooShortRef(ooHashAdmin)::ooShortRefStructor(ooHashAdmin)(const ooShortRef(ooHashAdmin) &  shortId) :
    ooShortRef(ooAdmin)(shortId)
{
}
#endif // !defined(OO_BUGGY_TEMPLATES)
#ifdef OO_BUGGY_TEMPLATES
inline
ooShortRef(ooHashAdmin)::ooShortRefStructor(ooHashAdmin)(const ooRef(ooHashAdmin) &  id)
{
  *this = id;
}
#else // !defined(OO_BUGGY_TEMPLATES)
inline
ooShortRef(ooHashAdmin)::ooShortRefStructor(ooHashAdmin)(const ooRef(ooHashAdmin) &  id) :
    ooShortRef(ooAdmin)(id)
{
}
#endif // !defined(OO_BUGGY_TEMPLATES)
#ifdef OO_BUGGY_TEMPLATES
inline
ooShortRef(ooHashAdmin)::ooShortRefStructor(ooHashAdmin)(const ooHandleSuper(ooHashAdmin) &  objH)
{
  *this = objH;
}
#else // !defined(OO_BUGGY_TEMPLATES)
inline
ooShortRef(ooHashAdmin)::ooShortRefStructor(ooHashAdmin)(const ooHandleSuper(ooHashAdmin) &  objH) :
    ooShortRef(ooAdmin)(objH)
{
}
#endif // !defined(OO_BUGGY_TEMPLATES)
#ifdef OO_BUGGY_TEMPLATES
inline
ooShortRef(ooHashAdmin)::ooShortRefStructor(ooHashAdmin)(const ooHashAdmin *  fromObject)
{
  *this = fromObject;
}
#else // !defined(OO_BUGGY_TEMPLATES)
inline
ooShortRef(ooHashAdmin)::ooShortRefStructor(ooHashAdmin)(const ooHashAdmin *  fromObject) :
    ooShortRef(ooAdmin)(ooReinterpretCast(const ooAdmin *,fromObject))
{
}
#endif // !defined(OO_BUGGY_TEMPLATES)


/* methods on ooHandle(ooHashAdmin) */
inline
ooHandle(ooHashAdmin)::ooHandleStructor(ooHashAdmin)()
{
}
inline
ooHandle(ooHashAdmin)::ooHandleStructor(ooHashAdmin)(const ooHandle(ooHashAdmin) &  objH) :
#ifdef OO_BUGGY_TEMPLATES
    ooHandle_superclass<ooHashAdmin >(objH)
#else // !defined(OO_BUGGY_TEMPLATES)
    ooHandle(ooAdmin)(objH)
#endif // !defined(OO_BUGGY_TEMPLATES)
{
}
inline
ooHandle(ooHashAdmin)::ooHandleStructor(ooHashAdmin)(const ooRef(ooHashAdmin) &  id) :
#ifdef OO_BUGGY_TEMPLATES
    ooHandle_superclass<ooHashAdmin >(id)
#else // !defined(OO_BUGGY_TEMPLATES)
    ooHandle(ooAdmin)(id)
#endif // !defined(OO_BUGGY_TEMPLATES)
{
}
inline
ooHandle(ooHashAdmin)::ooHandleStructor(ooHashAdmin)(const ooHashAdmin *  fromObject) :
#ifdef OO_BUGGY_TEMPLATES
    ooHandle_superclass<ooHashAdmin >(ooReinterpretCast(const ooAdmin *,fromObject))
#else // !defined(OO_BUGGY_TEMPLATES)
    ooHandle(ooAdmin)(ooReinterpretCast(const ooAdmin *,fromObject))
#endif // !defined(OO_BUGGY_TEMPLATES)
{
}
inline
ooHandle(ooHashAdmin)&
ooHandle(ooHashAdmin)::operator=(const ooRef(ooHashAdmin) &  id)
{
  this->ooHandle(ooObj)::operator=(id);
  return *this;
}
inline
ooHandle(ooHashAdmin)&
ooHandle(ooHashAdmin)::operator=(const ooHandle(ooHashAdmin) &  objH)
{
  this->ooHandle(ooObj)::operator=(objH);
  return *this;
}
inline
ooHandle(ooHashAdmin)&
ooHandle(ooHashAdmin)::operator=(const ooShortRef(ooHashAdmin) &  shortId)
{
  this->ooHandle(ooObj)::operator=(shortId);
  return *this;
}
inline
ooHandle(ooHashAdmin)&
ooHandle(ooHashAdmin)::operator=(const ooHashAdmin *  fromObject)
{
  this->ooHandle(ooObj)::operator=(ooReinterpretCast(const ooObj *,fromObject));
  return *this;
}
inline
ooHashAdmin *
ooHandle(ooHashAdmin)::pin(ooMode  openMode) const
{
  return ooReinterpretCast(ooHashAdmin *, this->pin_obj_internal(openMode));
}
inline
ooHashAdmin *
ooHandle(ooHashAdmin)::operator->() const
{
  return this->vm();
}
inline
ooHashAdmin &
ooHandle(ooHashAdmin)::operator*() const
{
  return *(this->vm());
}
inline
ooHandle(ooHashAdmin)::operator ooHashAdmin *() const
{
  if ( _state == oocHandlePTR  )
    return ooReinterpretCast(ooHashAdmin *, _ptr._obj);
  else return ooReinterpretCast(ooHashAdmin *, this->get_vm());
}
inline
ooHashAdmin *
ooHandle(ooHashAdmin)::vm() const
{
  if ( _state == oocHandlePTR && _ptr._obj != NULL )
    return ooReinterpretCast(ooHashAdmin *, _ptr._obj);
  else return ooReinterpretCast(ooHashAdmin *, this->get_vm());
}
inline
ooRef(ooHashAdmin) &
ooHandle(ooHashAdmin)::copy(const ooHandle(ooObj) &  nearH,
		   ooRef(ooHashAdmin) &              result) const
{
  this->ooHandle(ooObj)::copy(nearH, result);
  return result;
}


/* ODMG methods */
inline
ooHashAdmin *
ooRef(ooHashAdmin)::ptr() const
{
  return this->pin();
}
inline
ooHashAdmin *
ooHandle(ooHashAdmin)::ptr() const
{
  return this->operator ooHashAdmin *();
}
class ooHashChain;


/////////////////////////////////////////////////////////////////////////////

ooTemplateSpecialization
class CO_STORAGE_SPECIFIER ooDeref(ooHashChain) : public ooDerefBase {
	friend class ooRef(ooHashChain);
  public:
    ~ooDerefStructor(ooHashChain)();
    inline ooHashChain *operator->() const;
#ifndef OO_BUGGY_TEMPLATES
  private:
#endif // !defined(OO_BUGGY_TEMPLATES)
    ooDerefStructor(ooHashChain)(ooDeref(ooHashChain)& deref);
    ooDerefStructor(ooHashChain)(ooObj *  fromObject);
};


#ifdef OO_BUGGY_TEMPLATES

class CO_STORAGE_SPECIFIER ooHandle_superclass<ooHashChain > : public ooHandle(ooObj) {
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

class CO_STORAGE_SPECIFIER ooShortRef_superclass<ooHashChain > : public ooShortRef(ooObj) {
};

#endif // OO_BUGGY_TEMPLATES

ooTemplateSpecialization
class CO_STORAGE_SPECIFIER ooRef(ooHashChain) : public ooRef(ooObj) {
  public:
    ooRefStructor(ooHashChain)()
      {}
    ooRefStructor(ooHashChain)(const ooRef(ooHashChain)& id) :
	  ooRef(ooObj)(id)
      {}
    inline ooRefStructor(ooHashChain)(const ooHandleSuper(ooHashChain)& objH);
    inline ooRefStructor(ooHashChain)(const ooHashChain *  fromObject);
    inline ooRef(ooHashChain)& operator=(const ooRef(ooHashChain)& id);
    inline ooRef(ooHashChain)& operator=(const ooShortRefSuper(ooHashChain) &shortId);
    inline ooRef(ooHashChain)& operator=(const ooHandleSuper(ooHashChain)& objH);
    inline ooRef(ooHashChain)& operator=(const ooHashChain *  fromObject);
    ooStatus lookupObj(const ooHandle(ooObj)& scopeH,
		       const ooKey& key,
		       ooMode openMode = oocRead);
    ooStatus lookupObj(const ooHandle(ooObj)& scopeH,
		       const char* name,
		       ooMode openMode = oocRead);
#ifndef OO_BUGGY_TEMPLATES
    inline ooRef(ooHashChain)& copy(const ooHandle(ooObj)& nearH,
		    ooRef(ooHashChain)& newObjRef) const;
    inline ooHandle(ooHashChain)& copy(const ooHandle(ooObj)& nearH,
			ooHandle(ooHashChain)& result) const;
    inline ooHandle(ooHashChain) copy(const ooHandle(ooObj)& nearH) const;
#endif // !defined(OO_BUGGY_TEMPLATES)
    inline ooHashChain *pin(ooMode openMode = oocRead) const;
    ooDeref(ooHashChain) operator->() const;
    /* Use pin() or use ooHandle "operator ooHashChain *" instead of vm. */
    /* OBSOLETE */ inline ooHashChain *vm(ooMode openMode = oocRead) const;
    // ODMG methods:
    ooRefStructor(ooHashChain)(const d_Ref_Any &from);
    ooHashChain *ptr() const;
};

ooTemplateSpecialization
class CO_STORAGE_SPECIFIER ooShortRef(ooHashChain) :
#ifdef OO_BUGGY_TEMPLATES
			public ooShortRef_superclass<ooHashChain >
#else // !defined(OO_BUGGY_TEMPLATES)
			public ooShortRef(ooObj)
#endif // !defined(OO_BUGGY_TEMPLATES)
					            {
  public:
    ooShortRefStructor(ooHashChain)();
    ooShortRefStructor(ooHashChain)(const ooShortRef(ooHashChain)& shortId);
    ooShortRefStructor(ooHashChain)(const ooRef(ooHashChain)& id);
    ooShortRefStructor(ooHashChain)(const ooHandleSuper(ooHashChain) &objH);
    ooShortRefStructor(ooHashChain)(const ooHashChain *  fromObject);
    ooShortRef(ooHashChain)& operator=(const ooShortRef(ooHashChain)& shortId);
    ooShortRef(ooHashChain)& operator=(const ooRef(ooHashChain)& id);
    ooShortRef(ooHashChain)& operator=(const ooHandleSuper(ooHashChain) &objH);
    ooShortRef(ooHashChain)& operator=(const ooHashChain *  fromObject);
};

ooTemplateSpecialization
class CO_STORAGE_SPECIFIER ooHandle(ooHashChain) :
#ifdef OO_BUGGY_TEMPLATES
		      public ooHandle_superclass<ooHashChain >
#else // !defined(OO_BUGGY_TEMPLATES)
		      public ooHandle(ooObj)
#endif // !defined(OO_BUGGY_TEMPLATES)
                                                {
  public:
    inline ooHandleStructor(ooHashChain)();
    inline ooHandleStructor(ooHashChain)(const ooRef(ooHashChain)& id);
    inline ooHandleStructor(ooHashChain)(const ooHandle(ooHashChain)& objH);
    inline ooHandleStructor(ooHashChain)(const ooHashChain *  fromObject);
    inline ooHandle(ooHashChain)& operator=(const ooRef(ooHashChain)& id);
    inline ooHandle(ooHashChain)& operator=(const ooHandle(ooHashChain)& objH);
    inline ooHandle(ooHashChain)& operator=(const ooShortRef(ooHashChain)& shortId);
    inline ooHandle(ooHashChain)& operator=(const ooHashChain *  fromObject);
    ooStatus lookupObj(const ooHandle(ooObj)& scopeH,
		       const ooKey& key,
		       ooMode openMode = oocRead);
    ooStatus lookupObj(const ooHandle(ooObj)& scopeH,
		       const char* name,
		       ooMode openMode = oocRead);
    ooHandle(ooHashChain)& copy(const ooHandle(ooObj)& nearH,
		       ooHandle(ooHashChain)& result) const;
    inline ooRef(ooHashChain)& copy(const ooHandle(ooObj)& nearH,
		    ooRef(ooHashChain)& result) const;
    ooHandle(ooHashChain) copy(const ooHandle(ooObj)& nearH) const;
    inline ooHashChain *pin(ooMode openMode = oocRead) const;
    inline ooHashChain *operator->() const;
    inline ooHashChain &operator*() const;
    inline operator ooHashChain *() const;
    /* Use "operator ooHashChain *" instead of vm. */
    /* OBSOLETE */ inline ooHashChain *vm() const;
    // ODMG methods:
    ooHandleStructor(ooHashChain)(const d_Ref_Any &from);
    ooHashChain *ptr() const;
};

ooTemplateSpecialization
class CO_STORAGE_SPECIFIER ooItr(ooHashChain) : public ooHandle(ooHashChain),
		    public ooIteratorObjOrContObj {
  public:
    ooItrStructor(ooHashChain)();
    ~ooItrStructor(ooHashChain)();
  private:
    // Defined only to prevent implicit definition:
    ooItrStructor(ooHashChain)(ooItr(ooHashChain)&);
    ooItr(ooHashChain)    operator=(ooItr(ooHashChain)&);
};


/* methods on ooDeref(ooHashChain) */
inline
ooDeref(ooHashChain)::ooDerefStructor(ooHashChain)(ooDeref(ooHashChain) &  deref) :
    ooDerefBase(deref.vm())
{
  this->pinCompensate();
}
inline
ooDeref(ooHashChain)::ooDerefStructor(ooHashChain)(ooObj *  fromObject) :
    ooDerefBase(fromObject)
{
}
inline
ooDeref(ooHashChain)::~ooDerefStructor(ooHashChain)()
{
}
inline
ooHashChain *
ooDeref(ooHashChain)::operator->() const
{
  return ooReinterpretCast(ooHashChain *, this->vm());
}


/* methods on ooRef(ooHashChain) */
inline
ooRef(ooHashChain)::ooRefStructor(ooHashChain)(const ooHandleSuper(ooHashChain)& objH) :
    ooRef(ooObj)(objH)
{
}
inline
ooRef(ooHashChain)::ooRefStructor(ooHashChain)(const ooHashChain *  fromObject) :
    ooRef(ooObj)(ooReinterpretCast(const ooObj *, fromObject))
{
}
inline
ooRef(ooHashChain)&
ooRef(ooHashChain)::operator=(const ooRef(ooHashChain) &  id)
{
  this->ooId::operator=(id);
  return *this;
}
inline
ooRef(ooHashChain)&
ooRef(ooHashChain)::operator=(const ooShortRefSuper(ooHashChain) &  shortId)
{
  this->ooRef(ooObj)::operator=(shortId);
  return *this;
}
inline
ooRef(ooHashChain)&
ooRef(ooHashChain)::operator=(const ooHandleSuper(ooHashChain) &  objH)
{
  this->ooRef(ooObj)::operator=(objH);
  return *this;
}
inline
ooRef(ooHashChain)&
ooRef(ooHashChain)::operator=(const ooHashChain *  fromObject)
{
  this->ooRef(ooObj)::operator=(ooReinterpretCast(const ooObj *, fromObject));
  return *this;
}
inline
ooHashChain *
ooRef(ooHashChain)::pin(ooMode  openMode) const
{
  return ooReinterpretCast(ooHashChain *, this->pin_ref_internal(openMode));
}
inline
ooHashChain *
ooRef(ooHashChain)::vm(ooMode  openMode) const
{
  return this->pin(openMode);
}
#ifndef OO_BUGGY_TEMPLATES
inline
ooHandle(ooHashChain) &
ooRef(ooHashChain)::copy(const ooHandle(ooObj) &  nearH,
		ooHandle(ooHashChain) &           result) const
{
  this->ooRef(ooObj)::copy(nearH, result);
  return result;
}
inline
ooRef(ooHashChain) &
ooRef(ooHashChain)::copy(const ooHandle(ooObj) &  nearH,
		ooRef(ooHashChain) &              newObjRef) const
{
  this->ooRef(ooObj)::copy(nearH, newObjRef);
  return newObjRef;
}
inline
ooHandle(ooHashChain)
ooRef(ooHashChain)::copy(const ooHandle(ooObj) &  nearH) const
{
  ooHandle(ooHashChain) result;
  this->ooRef(ooObj)::copy(nearH, result);
  return result;
}
#endif // !defined(OO_BUGGY_TEMPLATES)
inline
ooDeref(ooHashChain)
ooRef(ooHashChain)::operator->() const
{
  ooDeref(ooHashChain) result(this->pin_ref_internal(oocRead));
  return result;
}


/* methods on ooShortRef(ooHashChain) */
inline
ooShortRef(ooHashChain) &
ooShortRef(ooHashChain)::operator=(const ooShortRef(ooHashChain) &  shortId)
{
  this->ooShortId::operator=(shortId);
  return *this;
}
inline
ooShortRef(ooHashChain) &
ooShortRef(ooHashChain)::operator=(const ooRef(ooHashChain) &  id)
{
  this->ooShortId::operator=(id);
  return *this;
}
inline
ooShortRef(ooHashChain) &
ooShortRef(ooHashChain)::operator=(const ooHandleSuper(ooHashChain) &  objH)
{
  this->ooShortId::operator=(objH);
  return *this;
}
inline
ooShortRef(ooHashChain)&
ooShortRef(ooHashChain)::operator=(const ooHashChain *  fromObject)
{
  this->ooShortId::operator=(ooReinterpretCast(const ooObj *,fromObject));
  return *this;
}
inline
ooShortRef(ooHashChain)::ooShortRefStructor(ooHashChain)()
{
}
#ifdef OO_BUGGY_TEMPLATES
inline
ooShortRef(ooHashChain)::ooShortRefStructor(ooHashChain)(const ooShortRef(ooHashChain) &  shortId)
{
  *this = shortId;
}
#else // !defined(OO_BUGGY_TEMPLATES)
inline
ooShortRef(ooHashChain)::ooShortRefStructor(ooHashChain)(const ooShortRef(ooHashChain) &  shortId) :
    ooShortRef(ooObj)(shortId)
{
}
#endif // !defined(OO_BUGGY_TEMPLATES)
#ifdef OO_BUGGY_TEMPLATES
inline
ooShortRef(ooHashChain)::ooShortRefStructor(ooHashChain)(const ooRef(ooHashChain) &  id)
{
  *this = id;
}
#else // !defined(OO_BUGGY_TEMPLATES)
inline
ooShortRef(ooHashChain)::ooShortRefStructor(ooHashChain)(const ooRef(ooHashChain) &  id) :
    ooShortRef(ooObj)(id)
{
}
#endif // !defined(OO_BUGGY_TEMPLATES)
#ifdef OO_BUGGY_TEMPLATES
inline
ooShortRef(ooHashChain)::ooShortRefStructor(ooHashChain)(const ooHandleSuper(ooHashChain) &  objH)
{
  *this = objH;
}
#else // !defined(OO_BUGGY_TEMPLATES)
inline
ooShortRef(ooHashChain)::ooShortRefStructor(ooHashChain)(const ooHandleSuper(ooHashChain) &  objH) :
    ooShortRef(ooObj)(objH)
{
}
#endif // !defined(OO_BUGGY_TEMPLATES)
#ifdef OO_BUGGY_TEMPLATES
inline
ooShortRef(ooHashChain)::ooShortRefStructor(ooHashChain)(const ooHashChain *  fromObject)
{
  *this = fromObject;
}
#else // !defined(OO_BUGGY_TEMPLATES)
inline
ooShortRef(ooHashChain)::ooShortRefStructor(ooHashChain)(const ooHashChain *  fromObject) :
    ooShortRef(ooObj)(ooReinterpretCast(const ooObj *,fromObject))
{
}
#endif // !defined(OO_BUGGY_TEMPLATES)


/* methods on ooHandle(ooHashChain) */
inline
ooHandle(ooHashChain)::ooHandleStructor(ooHashChain)()
{
}
inline
ooHandle(ooHashChain)::ooHandleStructor(ooHashChain)(const ooHandle(ooHashChain) &  objH) :
#ifdef OO_BUGGY_TEMPLATES
    ooHandle_superclass<ooHashChain >(objH)
#else // !defined(OO_BUGGY_TEMPLATES)
    ooHandle(ooObj)(objH)
#endif // !defined(OO_BUGGY_TEMPLATES)
{
}
inline
ooHandle(ooHashChain)::ooHandleStructor(ooHashChain)(const ooRef(ooHashChain) &  id) :
#ifdef OO_BUGGY_TEMPLATES
    ooHandle_superclass<ooHashChain >(id)
#else // !defined(OO_BUGGY_TEMPLATES)
    ooHandle(ooObj)(id)
#endif // !defined(OO_BUGGY_TEMPLATES)
{
}
inline
ooHandle(ooHashChain)::ooHandleStructor(ooHashChain)(const ooHashChain *  fromObject) :
#ifdef OO_BUGGY_TEMPLATES
    ooHandle_superclass<ooHashChain >(ooReinterpretCast(const ooObj *,fromObject))
#else // !defined(OO_BUGGY_TEMPLATES)
    ooHandle(ooObj)(ooReinterpretCast(const ooObj *,fromObject))
#endif // !defined(OO_BUGGY_TEMPLATES)
{
}
inline
ooHandle(ooHashChain)&
ooHandle(ooHashChain)::operator=(const ooRef(ooHashChain) &  id)
{
  this->ooHandle(ooObj)::operator=(id);
  return *this;
}
inline
ooHandle(ooHashChain)&
ooHandle(ooHashChain)::operator=(const ooHandle(ooHashChain) &  objH)
{
  this->ooHandle(ooObj)::operator=(objH);
  return *this;
}
inline
ooHandle(ooHashChain)&
ooHandle(ooHashChain)::operator=(const ooShortRef(ooHashChain) &  shortId)
{
  this->ooHandle(ooObj)::operator=(shortId);
  return *this;
}
inline
ooHandle(ooHashChain)&
ooHandle(ooHashChain)::operator=(const ooHashChain *  fromObject)
{
  this->ooHandle(ooObj)::operator=(ooReinterpretCast(const ooObj *,fromObject));
  return *this;
}
inline
ooHashChain *
ooHandle(ooHashChain)::pin(ooMode  openMode) const
{
  return ooReinterpretCast(ooHashChain *, this->pin_obj_internal(openMode));
}
inline
ooHashChain *
ooHandle(ooHashChain)::operator->() const
{
  return this->vm();
}
inline
ooHashChain &
ooHandle(ooHashChain)::operator*() const
{
  return *(this->vm());
}
inline
ooHandle(ooHashChain)::operator ooHashChain *() const
{
  if ( _state == oocHandlePTR  )
    return ooReinterpretCast(ooHashChain *, _ptr._obj);
  else return ooReinterpretCast(ooHashChain *, this->get_vm());
}
inline
ooHashChain *
ooHandle(ooHashChain)::vm() const
{
  if ( _state == oocHandlePTR && _ptr._obj != NULL )
    return ooReinterpretCast(ooHashChain *, _ptr._obj);
  else return ooReinterpretCast(ooHashChain *, this->get_vm());
}
inline
ooRef(ooHashChain) &
ooHandle(ooHashChain)::copy(const ooHandle(ooObj) &  nearH,
		   ooRef(ooHashChain) &              result) const
{
  this->ooHandle(ooObj)::copy(nearH, result);
  return result;
}


/* ODMG methods */
inline
ooHashChain *
ooRef(ooHashChain)::ptr() const
{
  return this->pin();
}
inline
ooHashChain *
ooHandle(ooHashChain)::ptr() const
{
  return this->operator ooHashChain *();
}
class ooHashBucket;


/////////////////////////////////////////////////////////////////////////////

ooTemplateSpecialization
class CO_STORAGE_SPECIFIER ooDeref(ooHashBucket) : public ooDerefBase {
	friend class ooRef(ooHashBucket);
  public:
    ~ooDerefStructor(ooHashBucket)();
    inline ooHashBucket *operator->() const;
#ifndef OO_BUGGY_TEMPLATES
  private:
#endif // !defined(OO_BUGGY_TEMPLATES)
    ooDerefStructor(ooHashBucket)(ooDeref(ooHashBucket)& deref);
    ooDerefStructor(ooHashBucket)(ooObj *  fromObject);
};


#ifdef OO_BUGGY_TEMPLATES

class CO_STORAGE_SPECIFIER ooHandle_superclass<ooHashBucket > : public ooHandle(ooObj) {
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

class CO_STORAGE_SPECIFIER ooShortRef_superclass<ooHashBucket > : public ooShortRef(ooObj) {
};

#endif // OO_BUGGY_TEMPLATES

ooTemplateSpecialization
class CO_STORAGE_SPECIFIER ooRef(ooHashBucket) : public ooRef(ooObj) {
  public:
    ooRefStructor(ooHashBucket)()
      {}
    ooRefStructor(ooHashBucket)(const ooRef(ooHashBucket)& id) :
	  ooRef(ooObj)(id)
      {}
    inline ooRefStructor(ooHashBucket)(const ooHandleSuper(ooHashBucket)& objH);
    inline ooRefStructor(ooHashBucket)(const ooHashBucket *  fromObject);
    inline ooRef(ooHashBucket)& operator=(const ooRef(ooHashBucket)& id);
    inline ooRef(ooHashBucket)& operator=(const ooShortRefSuper(ooHashBucket) &shortId);
    inline ooRef(ooHashBucket)& operator=(const ooHandleSuper(ooHashBucket)& objH);
    inline ooRef(ooHashBucket)& operator=(const ooHashBucket *  fromObject);
    ooStatus lookupObj(const ooHandle(ooObj)& scopeH,
		       const ooKey& key,
		       ooMode openMode = oocRead);
    ooStatus lookupObj(const ooHandle(ooObj)& scopeH,
		       const char* name,
		       ooMode openMode = oocRead);
#ifndef OO_BUGGY_TEMPLATES
    inline ooRef(ooHashBucket)& copy(const ooHandle(ooObj)& nearH,
		    ooRef(ooHashBucket)& newObjRef) const;
    inline ooHandle(ooHashBucket)& copy(const ooHandle(ooObj)& nearH,
			ooHandle(ooHashBucket)& result) const;
    inline ooHandle(ooHashBucket) copy(const ooHandle(ooObj)& nearH) const;
#endif // !defined(OO_BUGGY_TEMPLATES)
    inline ooHashBucket *pin(ooMode openMode = oocRead) const;
    ooDeref(ooHashBucket) operator->() const;
    /* Use pin() or use ooHandle "operator ooHashBucket *" instead of vm. */
    /* OBSOLETE */ inline ooHashBucket *vm(ooMode openMode = oocRead) const;
    // ODMG methods:
    ooRefStructor(ooHashBucket)(const d_Ref_Any &from);
    ooHashBucket *ptr() const;
};

ooTemplateSpecialization
class CO_STORAGE_SPECIFIER ooShortRef(ooHashBucket) :
#ifdef OO_BUGGY_TEMPLATES
			public ooShortRef_superclass<ooHashBucket >
#else // !defined(OO_BUGGY_TEMPLATES)
			public ooShortRef(ooObj)
#endif // !defined(OO_BUGGY_TEMPLATES)
					            {
  public:
    ooShortRefStructor(ooHashBucket)();
    ooShortRefStructor(ooHashBucket)(const ooShortRef(ooHashBucket)& shortId);
    ooShortRefStructor(ooHashBucket)(const ooRef(ooHashBucket)& id);
    ooShortRefStructor(ooHashBucket)(const ooHandleSuper(ooHashBucket) &objH);
    ooShortRefStructor(ooHashBucket)(const ooHashBucket *  fromObject);
    ooShortRef(ooHashBucket)& operator=(const ooShortRef(ooHashBucket)& shortId);
    ooShortRef(ooHashBucket)& operator=(const ooRef(ooHashBucket)& id);
    ooShortRef(ooHashBucket)& operator=(const ooHandleSuper(ooHashBucket) &objH);
    ooShortRef(ooHashBucket)& operator=(const ooHashBucket *  fromObject);
};

ooTemplateSpecialization
class CO_STORAGE_SPECIFIER ooHandle(ooHashBucket) :
#ifdef OO_BUGGY_TEMPLATES
		      public ooHandle_superclass<ooHashBucket >
#else // !defined(OO_BUGGY_TEMPLATES)
		      public ooHandle(ooObj)
#endif // !defined(OO_BUGGY_TEMPLATES)
                                                {
  public:
    inline ooHandleStructor(ooHashBucket)();
    inline ooHandleStructor(ooHashBucket)(const ooRef(ooHashBucket)& id);
    inline ooHandleStructor(ooHashBucket)(const ooHandle(ooHashBucket)& objH);
    inline ooHandleStructor(ooHashBucket)(const ooHashBucket *  fromObject);
    inline ooHandle(ooHashBucket)& operator=(const ooRef(ooHashBucket)& id);
    inline ooHandle(ooHashBucket)& operator=(const ooHandle(ooHashBucket)& objH);
    inline ooHandle(ooHashBucket)& operator=(const ooShortRef(ooHashBucket)& shortId);
    inline ooHandle(ooHashBucket)& operator=(const ooHashBucket *  fromObject);
    ooStatus lookupObj(const ooHandle(ooObj)& scopeH,
		       const ooKey& key,
		       ooMode openMode = oocRead);
    ooStatus lookupObj(const ooHandle(ooObj)& scopeH,
		       const char* name,
		       ooMode openMode = oocRead);
    ooHandle(ooHashBucket)& copy(const ooHandle(ooObj)& nearH,
		       ooHandle(ooHashBucket)& result) const;
    inline ooRef(ooHashBucket)& copy(const ooHandle(ooObj)& nearH,
		    ooRef(ooHashBucket)& result) const;
    ooHandle(ooHashBucket) copy(const ooHandle(ooObj)& nearH) const;
    inline ooHashBucket *pin(ooMode openMode = oocRead) const;
    inline ooHashBucket *operator->() const;
    inline ooHashBucket &operator*() const;
    inline operator ooHashBucket *() const;
    /* Use "operator ooHashBucket *" instead of vm. */
    /* OBSOLETE */ inline ooHashBucket *vm() const;
    // ODMG methods:
    ooHandleStructor(ooHashBucket)(const d_Ref_Any &from);
    ooHashBucket *ptr() const;
};

ooTemplateSpecialization
class CO_STORAGE_SPECIFIER ooItr(ooHashBucket) : public ooHandle(ooHashBucket),
		    public ooIteratorObjOrContObj {
  public:
    ooItrStructor(ooHashBucket)();
    ~ooItrStructor(ooHashBucket)();
  private:
    // Defined only to prevent implicit definition:
    ooItrStructor(ooHashBucket)(ooItr(ooHashBucket)&);
    ooItr(ooHashBucket)    operator=(ooItr(ooHashBucket)&);
};


/* methods on ooDeref(ooHashBucket) */
inline
ooDeref(ooHashBucket)::ooDerefStructor(ooHashBucket)(ooDeref(ooHashBucket) &  deref) :
    ooDerefBase(deref.vm())
{
  this->pinCompensate();
}
inline
ooDeref(ooHashBucket)::ooDerefStructor(ooHashBucket)(ooObj *  fromObject) :
    ooDerefBase(fromObject)
{
}
inline
ooDeref(ooHashBucket)::~ooDerefStructor(ooHashBucket)()
{
}
inline
ooHashBucket *
ooDeref(ooHashBucket)::operator->() const
{
  return ooReinterpretCast(ooHashBucket *, this->vm());
}


/* methods on ooRef(ooHashBucket) */
inline
ooRef(ooHashBucket)::ooRefStructor(ooHashBucket)(const ooHandleSuper(ooHashBucket)& objH) :
    ooRef(ooObj)(objH)
{
}
inline
ooRef(ooHashBucket)::ooRefStructor(ooHashBucket)(const ooHashBucket *  fromObject) :
    ooRef(ooObj)(ooReinterpretCast(const ooObj *, fromObject))
{
}
inline
ooRef(ooHashBucket)&
ooRef(ooHashBucket)::operator=(const ooRef(ooHashBucket) &  id)
{
  this->ooId::operator=(id);
  return *this;
}
inline
ooRef(ooHashBucket)&
ooRef(ooHashBucket)::operator=(const ooShortRefSuper(ooHashBucket) &  shortId)
{
  this->ooRef(ooObj)::operator=(shortId);
  return *this;
}
inline
ooRef(ooHashBucket)&
ooRef(ooHashBucket)::operator=(const ooHandleSuper(ooHashBucket) &  objH)
{
  this->ooRef(ooObj)::operator=(objH);
  return *this;
}
inline
ooRef(ooHashBucket)&
ooRef(ooHashBucket)::operator=(const ooHashBucket *  fromObject)
{
  this->ooRef(ooObj)::operator=(ooReinterpretCast(const ooObj *, fromObject));
  return *this;
}
inline
ooHashBucket *
ooRef(ooHashBucket)::pin(ooMode  openMode) const
{
  return ooReinterpretCast(ooHashBucket *, this->pin_ref_internal(openMode));
}
inline
ooHashBucket *
ooRef(ooHashBucket)::vm(ooMode  openMode) const
{
  return this->pin(openMode);
}
#ifndef OO_BUGGY_TEMPLATES
inline
ooHandle(ooHashBucket) &
ooRef(ooHashBucket)::copy(const ooHandle(ooObj) &  nearH,
		ooHandle(ooHashBucket) &           result) const
{
  this->ooRef(ooObj)::copy(nearH, result);
  return result;
}
inline
ooRef(ooHashBucket) &
ooRef(ooHashBucket)::copy(const ooHandle(ooObj) &  nearH,
		ooRef(ooHashBucket) &              newObjRef) const
{
  this->ooRef(ooObj)::copy(nearH, newObjRef);
  return newObjRef;
}
inline
ooHandle(ooHashBucket)
ooRef(ooHashBucket)::copy(const ooHandle(ooObj) &  nearH) const
{
  ooHandle(ooHashBucket) result;
  this->ooRef(ooObj)::copy(nearH, result);
  return result;
}
#endif // !defined(OO_BUGGY_TEMPLATES)
inline
ooDeref(ooHashBucket)
ooRef(ooHashBucket)::operator->() const
{
  ooDeref(ooHashBucket) result(this->pin_ref_internal(oocRead));
  return result;
}


/* methods on ooShortRef(ooHashBucket) */
inline
ooShortRef(ooHashBucket) &
ooShortRef(ooHashBucket)::operator=(const ooShortRef(ooHashBucket) &  shortId)
{
  this->ooShortId::operator=(shortId);
  return *this;
}
inline
ooShortRef(ooHashBucket) &
ooShortRef(ooHashBucket)::operator=(const ooRef(ooHashBucket) &  id)
{
  this->ooShortId::operator=(id);
  return *this;
}
inline
ooShortRef(ooHashBucket) &
ooShortRef(ooHashBucket)::operator=(const ooHandleSuper(ooHashBucket) &  objH)
{
  this->ooShortId::operator=(objH);
  return *this;
}
inline
ooShortRef(ooHashBucket)&
ooShortRef(ooHashBucket)::operator=(const ooHashBucket *  fromObject)
{
  this->ooShortId::operator=(ooReinterpretCast(const ooObj *,fromObject));
  return *this;
}
inline
ooShortRef(ooHashBucket)::ooShortRefStructor(ooHashBucket)()
{
}
#ifdef OO_BUGGY_TEMPLATES
inline
ooShortRef(ooHashBucket)::ooShortRefStructor(ooHashBucket)(const ooShortRef(ooHashBucket) &  shortId)
{
  *this = shortId;
}
#else // !defined(OO_BUGGY_TEMPLATES)
inline
ooShortRef(ooHashBucket)::ooShortRefStructor(ooHashBucket)(const ooShortRef(ooHashBucket) &  shortId) :
    ooShortRef(ooObj)(shortId)
{
}
#endif // !defined(OO_BUGGY_TEMPLATES)
#ifdef OO_BUGGY_TEMPLATES
inline
ooShortRef(ooHashBucket)::ooShortRefStructor(ooHashBucket)(const ooRef(ooHashBucket) &  id)
{
  *this = id;
}
#else // !defined(OO_BUGGY_TEMPLATES)
inline
ooShortRef(ooHashBucket)::ooShortRefStructor(ooHashBucket)(const ooRef(ooHashBucket) &  id) :
    ooShortRef(ooObj)(id)
{
}
#endif // !defined(OO_BUGGY_TEMPLATES)
#ifdef OO_BUGGY_TEMPLATES
inline
ooShortRef(ooHashBucket)::ooShortRefStructor(ooHashBucket)(const ooHandleSuper(ooHashBucket) &  objH)
{
  *this = objH;
}
#else // !defined(OO_BUGGY_TEMPLATES)
inline
ooShortRef(ooHashBucket)::ooShortRefStructor(ooHashBucket)(const ooHandleSuper(ooHashBucket) &  objH) :
    ooShortRef(ooObj)(objH)
{
}
#endif // !defined(OO_BUGGY_TEMPLATES)
#ifdef OO_BUGGY_TEMPLATES
inline
ooShortRef(ooHashBucket)::ooShortRefStructor(ooHashBucket)(const ooHashBucket *  fromObject)
{
  *this = fromObject;
}
#else // !defined(OO_BUGGY_TEMPLATES)
inline
ooShortRef(ooHashBucket)::ooShortRefStructor(ooHashBucket)(const ooHashBucket *  fromObject) :
    ooShortRef(ooObj)(ooReinterpretCast(const ooObj *,fromObject))
{
}
#endif // !defined(OO_BUGGY_TEMPLATES)


/* methods on ooHandle(ooHashBucket) */
inline
ooHandle(ooHashBucket)::ooHandleStructor(ooHashBucket)()
{
}
inline
ooHandle(ooHashBucket)::ooHandleStructor(ooHashBucket)(const ooHandle(ooHashBucket) &  objH) :
#ifdef OO_BUGGY_TEMPLATES
    ooHandle_superclass<ooHashBucket >(objH)
#else // !defined(OO_BUGGY_TEMPLATES)
    ooHandle(ooObj)(objH)
#endif // !defined(OO_BUGGY_TEMPLATES)
{
}
inline
ooHandle(ooHashBucket)::ooHandleStructor(ooHashBucket)(const ooRef(ooHashBucket) &  id) :
#ifdef OO_BUGGY_TEMPLATES
    ooHandle_superclass<ooHashBucket >(id)
#else // !defined(OO_BUGGY_TEMPLATES)
    ooHandle(ooObj)(id)
#endif // !defined(OO_BUGGY_TEMPLATES)
{
}
inline
ooHandle(ooHashBucket)::ooHandleStructor(ooHashBucket)(const ooHashBucket *  fromObject) :
#ifdef OO_BUGGY_TEMPLATES
    ooHandle_superclass<ooHashBucket >(ooReinterpretCast(const ooObj *,fromObject))
#else // !defined(OO_BUGGY_TEMPLATES)
    ooHandle(ooObj)(ooReinterpretCast(const ooObj *,fromObject))
#endif // !defined(OO_BUGGY_TEMPLATES)
{
}
inline
ooHandle(ooHashBucket)&
ooHandle(ooHashBucket)::operator=(const ooRef(ooHashBucket) &  id)
{
  this->ooHandle(ooObj)::operator=(id);
  return *this;
}
inline
ooHandle(ooHashBucket)&
ooHandle(ooHashBucket)::operator=(const ooHandle(ooHashBucket) &  objH)
{
  this->ooHandle(ooObj)::operator=(objH);
  return *this;
}
inline
ooHandle(ooHashBucket)&
ooHandle(ooHashBucket)::operator=(const ooShortRef(ooHashBucket) &  shortId)
{
  this->ooHandle(ooObj)::operator=(shortId);
  return *this;
}
inline
ooHandle(ooHashBucket)&
ooHandle(ooHashBucket)::operator=(const ooHashBucket *  fromObject)
{
  this->ooHandle(ooObj)::operator=(ooReinterpretCast(const ooObj *,fromObject));
  return *this;
}
inline
ooHashBucket *
ooHandle(ooHashBucket)::pin(ooMode  openMode) const
{
  return ooReinterpretCast(ooHashBucket *, this->pin_obj_internal(openMode));
}
inline
ooHashBucket *
ooHandle(ooHashBucket)::operator->() const
{
  return this->vm();
}
inline
ooHashBucket &
ooHandle(ooHashBucket)::operator*() const
{
  return *(this->vm());
}
inline
ooHandle(ooHashBucket)::operator ooHashBucket *() const
{
  if ( _state == oocHandlePTR  )
    return ooReinterpretCast(ooHashBucket *, _ptr._obj);
  else return ooReinterpretCast(ooHashBucket *, this->get_vm());
}
inline
ooHashBucket *
ooHandle(ooHashBucket)::vm() const
{
  if ( _state == oocHandlePTR && _ptr._obj != NULL )
    return ooReinterpretCast(ooHashBucket *, _ptr._obj);
  else return ooReinterpretCast(ooHashBucket *, this->get_vm());
}
inline
ooRef(ooHashBucket) &
ooHandle(ooHashBucket)::copy(const ooHandle(ooObj) &  nearH,
		   ooRef(ooHashBucket) &              result) const
{
  this->ooHandle(ooObj)::copy(nearH, result);
  return result;
}


/* ODMG methods */
inline
ooHashBucket *
ooRef(ooHashBucket)::ptr() const
{
  return this->pin();
}
inline
ooHashBucket *
ooHandle(ooHashBucket)::ptr() const
{
  return this->operator ooHashBucket *();
}
class ooHashSet;


/////////////////////////////////////////////////////////////////////////////

ooTemplateSpecialization
class CO_STORAGE_SPECIFIER ooDeref(ooHashSet) : public ooDerefBase {
	friend class ooRef(ooHashSet);
  public:
    ~ooDerefStructor(ooHashSet)();
    inline ooHashSet *operator->() const;
#ifndef OO_BUGGY_TEMPLATES
  private:
#endif // !defined(OO_BUGGY_TEMPLATES)
    ooDerefStructor(ooHashSet)(ooDeref(ooHashSet)& deref);
    ooDerefStructor(ooHashSet)(ooObj *  fromObject);
};


#ifdef OO_BUGGY_TEMPLATES

class CO_STORAGE_SPECIFIER ooHandle_superclass<ooHashSet > : public ooHandle(ooCollection) {
 protected:
  ooHandle_superclass()
    {}
  ooHandle_superclass(const ooHandle(ooCollection) &  from) :
      ooHandle(ooCollection)(from)
    {}
  ooHandle_superclass(const ooRef(ooCollection) &  from) :
      ooHandle(ooCollection)(from)
    {}
  ooHandle_superclass(const ooCollection *  from) :
      ooHandle(ooCollection)(from)
    {}
  ~ooHandle_superclass()
    {}
};

class CO_STORAGE_SPECIFIER ooShortRef_superclass<ooHashSet > : public ooShortRef(ooCollection) {
};

#endif // OO_BUGGY_TEMPLATES

ooTemplateSpecialization
class CO_STORAGE_SPECIFIER ooRef(ooHashSet) : public ooRef(ooCollection) {
  public:
    ooRefStructor(ooHashSet)()
      {}
    ooRefStructor(ooHashSet)(const ooRef(ooHashSet)& id) :
	  ooRef(ooCollection)(id)
      {}
    inline ooRefStructor(ooHashSet)(const ooHandleSuper(ooHashSet)& objH);
    inline ooRefStructor(ooHashSet)(const ooHashSet *  fromObject);
    inline ooRef(ooHashSet)& operator=(const ooRef(ooHashSet)& id);
    inline ooRef(ooHashSet)& operator=(const ooShortRefSuper(ooHashSet) &shortId);
    inline ooRef(ooHashSet)& operator=(const ooHandleSuper(ooHashSet)& objH);
    inline ooRef(ooHashSet)& operator=(const ooHashSet *  fromObject);
    ooStatus lookupObj(const ooHandle(ooObj)& scopeH,
		       const ooKey& key,
		       ooMode openMode = oocRead);
    ooStatus lookupObj(const ooHandle(ooObj)& scopeH,
		       const char* name,
		       ooMode openMode = oocRead);
#ifndef OO_BUGGY_TEMPLATES
    inline ooRef(ooHashSet)& copy(const ooHandle(ooObj)& nearH,
		    ooRef(ooHashSet)& newObjRef) const;
    inline ooHandle(ooHashSet)& copy(const ooHandle(ooObj)& nearH,
			ooHandle(ooHashSet)& result) const;
    inline ooHandle(ooHashSet) copy(const ooHandle(ooObj)& nearH) const;
#endif // !defined(OO_BUGGY_TEMPLATES)
    inline ooHashSet *pin(ooMode openMode = oocRead) const;
    ooDeref(ooHashSet) operator->() const;
    /* Use pin() or use ooHandle "operator ooHashSet *" instead of vm. */
    /* OBSOLETE */ inline ooHashSet *vm(ooMode openMode = oocRead) const;
    // ODMG methods:
    ooRefStructor(ooHashSet)(const d_Ref_Any &from);
    ooHashSet *ptr() const;
};

ooTemplateSpecialization
class CO_STORAGE_SPECIFIER ooShortRef(ooHashSet) :
#ifdef OO_BUGGY_TEMPLATES
			public ooShortRef_superclass<ooHashSet >
#else // !defined(OO_BUGGY_TEMPLATES)
			public ooShortRef(ooCollection)
#endif // !defined(OO_BUGGY_TEMPLATES)
					            {
  public:
    ooShortRefStructor(ooHashSet)();
    ooShortRefStructor(ooHashSet)(const ooShortRef(ooHashSet)& shortId);
    ooShortRefStructor(ooHashSet)(const ooRef(ooHashSet)& id);
    ooShortRefStructor(ooHashSet)(const ooHandleSuper(ooHashSet) &objH);
    ooShortRefStructor(ooHashSet)(const ooHashSet *  fromObject);
    ooShortRef(ooHashSet)& operator=(const ooShortRef(ooHashSet)& shortId);
    ooShortRef(ooHashSet)& operator=(const ooRef(ooHashSet)& id);
    ooShortRef(ooHashSet)& operator=(const ooHandleSuper(ooHashSet) &objH);
    ooShortRef(ooHashSet)& operator=(const ooHashSet *  fromObject);
};

ooTemplateSpecialization
class CO_STORAGE_SPECIFIER ooHandle(ooHashSet) :
#ifdef OO_BUGGY_TEMPLATES
		      public ooHandle_superclass<ooHashSet >
#else // !defined(OO_BUGGY_TEMPLATES)
		      public ooHandle(ooCollection)
#endif // !defined(OO_BUGGY_TEMPLATES)
                                                {
  public:
    inline ooHandleStructor(ooHashSet)();
    inline ooHandleStructor(ooHashSet)(const ooRef(ooHashSet)& id);
    inline ooHandleStructor(ooHashSet)(const ooHandle(ooHashSet)& objH);
    inline ooHandleStructor(ooHashSet)(const ooHashSet *  fromObject);
    inline ooHandle(ooHashSet)& operator=(const ooRef(ooHashSet)& id);
    inline ooHandle(ooHashSet)& operator=(const ooHandle(ooHashSet)& objH);
    inline ooHandle(ooHashSet)& operator=(const ooShortRef(ooHashSet)& shortId);
    inline ooHandle(ooHashSet)& operator=(const ooHashSet *  fromObject);
    ooStatus lookupObj(const ooHandle(ooObj)& scopeH,
		       const ooKey& key,
		       ooMode openMode = oocRead);
    ooStatus lookupObj(const ooHandle(ooObj)& scopeH,
		       const char* name,
		       ooMode openMode = oocRead);
    ooHandle(ooHashSet)& copy(const ooHandle(ooObj)& nearH,
		       ooHandle(ooHashSet)& result) const;
    inline ooRef(ooHashSet)& copy(const ooHandle(ooObj)& nearH,
		    ooRef(ooHashSet)& result) const;
    ooHandle(ooHashSet) copy(const ooHandle(ooObj)& nearH) const;
    inline ooHashSet *pin(ooMode openMode = oocRead) const;
    inline ooHashSet *operator->() const;
    inline ooHashSet &operator*() const;
    inline operator ooHashSet *() const;
    /* Use "operator ooHashSet *" instead of vm. */
    /* OBSOLETE */ inline ooHashSet *vm() const;
    // ODMG methods:
    ooHandleStructor(ooHashSet)(const d_Ref_Any &from);
    ooHashSet *ptr() const;
};

ooTemplateSpecialization
class CO_STORAGE_SPECIFIER ooItr(ooHashSet) : public ooHandle(ooHashSet),
		    public ooIteratorObjOrContObj {
  public:
    ooItrStructor(ooHashSet)();
    ~ooItrStructor(ooHashSet)();
  private:
    // Defined only to prevent implicit definition:
    ooItrStructor(ooHashSet)(ooItr(ooHashSet)&);
    ooItr(ooHashSet)    operator=(ooItr(ooHashSet)&);
};


/* methods on ooDeref(ooHashSet) */
inline
ooDeref(ooHashSet)::ooDerefStructor(ooHashSet)(ooDeref(ooHashSet) &  deref) :
    ooDerefBase(deref.vm())
{
  this->pinCompensate();
}
inline
ooDeref(ooHashSet)::ooDerefStructor(ooHashSet)(ooObj *  fromObject) :
    ooDerefBase(fromObject)
{
}
inline
ooDeref(ooHashSet)::~ooDerefStructor(ooHashSet)()
{
}
inline
ooHashSet *
ooDeref(ooHashSet)::operator->() const
{
  return ooReinterpretCast(ooHashSet *, this->vm());
}


/* methods on ooRef(ooHashSet) */
inline
ooRef(ooHashSet)::ooRefStructor(ooHashSet)(const ooHandleSuper(ooHashSet)& objH) :
    ooRef(ooCollection)(objH)
{
}
inline
ooRef(ooHashSet)::ooRefStructor(ooHashSet)(const ooHashSet *  fromObject) :
    ooRef(ooCollection)(ooReinterpretCast(const ooCollection *, fromObject))
{
}
inline
ooRef(ooHashSet)&
ooRef(ooHashSet)::operator=(const ooRef(ooHashSet) &  id)
{
  this->ooId::operator=(id);
  return *this;
}
inline
ooRef(ooHashSet)&
ooRef(ooHashSet)::operator=(const ooShortRefSuper(ooHashSet) &  shortId)
{
  this->ooRef(ooObj)::operator=(shortId);
  return *this;
}
inline
ooRef(ooHashSet)&
ooRef(ooHashSet)::operator=(const ooHandleSuper(ooHashSet) &  objH)
{
  this->ooRef(ooObj)::operator=(objH);
  return *this;
}
inline
ooRef(ooHashSet)&
ooRef(ooHashSet)::operator=(const ooHashSet *  fromObject)
{
  this->ooRef(ooObj)::operator=(ooReinterpretCast(const ooObj *, fromObject));
  return *this;
}
inline
ooHashSet *
ooRef(ooHashSet)::pin(ooMode  openMode) const
{
  return ooReinterpretCast(ooHashSet *, this->pin_ref_internal(openMode));
}
inline
ooHashSet *
ooRef(ooHashSet)::vm(ooMode  openMode) const
{
  return this->pin(openMode);
}
#ifndef OO_BUGGY_TEMPLATES
inline
ooHandle(ooHashSet) &
ooRef(ooHashSet)::copy(const ooHandle(ooObj) &  nearH,
		ooHandle(ooHashSet) &           result) const
{
  this->ooRef(ooObj)::copy(nearH, result);
  return result;
}
inline
ooRef(ooHashSet) &
ooRef(ooHashSet)::copy(const ooHandle(ooObj) &  nearH,
		ooRef(ooHashSet) &              newObjRef) const
{
  this->ooRef(ooObj)::copy(nearH, newObjRef);
  return newObjRef;
}
inline
ooHandle(ooHashSet)
ooRef(ooHashSet)::copy(const ooHandle(ooObj) &  nearH) const
{
  ooHandle(ooHashSet) result;
  this->ooRef(ooObj)::copy(nearH, result);
  return result;
}
#endif // !defined(OO_BUGGY_TEMPLATES)
inline
ooDeref(ooHashSet)
ooRef(ooHashSet)::operator->() const
{
  ooDeref(ooHashSet) result(this->pin_ref_internal(oocRead));
  return result;
}


/* methods on ooShortRef(ooHashSet) */
inline
ooShortRef(ooHashSet) &
ooShortRef(ooHashSet)::operator=(const ooShortRef(ooHashSet) &  shortId)
{
  this->ooShortId::operator=(shortId);
  return *this;
}
inline
ooShortRef(ooHashSet) &
ooShortRef(ooHashSet)::operator=(const ooRef(ooHashSet) &  id)
{
  this->ooShortId::operator=(id);
  return *this;
}
inline
ooShortRef(ooHashSet) &
ooShortRef(ooHashSet)::operator=(const ooHandleSuper(ooHashSet) &  objH)
{
  this->ooShortId::operator=(objH);
  return *this;
}
inline
ooShortRef(ooHashSet)&
ooShortRef(ooHashSet)::operator=(const ooHashSet *  fromObject)
{
  this->ooShortId::operator=(ooReinterpretCast(const ooObj *,fromObject));
  return *this;
}
inline
ooShortRef(ooHashSet)::ooShortRefStructor(ooHashSet)()
{
}
#ifdef OO_BUGGY_TEMPLATES
inline
ooShortRef(ooHashSet)::ooShortRefStructor(ooHashSet)(const ooShortRef(ooHashSet) &  shortId)
{
  *this = shortId;
}
#else // !defined(OO_BUGGY_TEMPLATES)
inline
ooShortRef(ooHashSet)::ooShortRefStructor(ooHashSet)(const ooShortRef(ooHashSet) &  shortId) :
    ooShortRef(ooCollection)(shortId)
{
}
#endif // !defined(OO_BUGGY_TEMPLATES)
#ifdef OO_BUGGY_TEMPLATES
inline
ooShortRef(ooHashSet)::ooShortRefStructor(ooHashSet)(const ooRef(ooHashSet) &  id)
{
  *this = id;
}
#else // !defined(OO_BUGGY_TEMPLATES)
inline
ooShortRef(ooHashSet)::ooShortRefStructor(ooHashSet)(const ooRef(ooHashSet) &  id) :
    ooShortRef(ooCollection)(id)
{
}
#endif // !defined(OO_BUGGY_TEMPLATES)
#ifdef OO_BUGGY_TEMPLATES
inline
ooShortRef(ooHashSet)::ooShortRefStructor(ooHashSet)(const ooHandleSuper(ooHashSet) &  objH)
{
  *this = objH;
}
#else // !defined(OO_BUGGY_TEMPLATES)
inline
ooShortRef(ooHashSet)::ooShortRefStructor(ooHashSet)(const ooHandleSuper(ooHashSet) &  objH) :
    ooShortRef(ooCollection)(objH)
{
}
#endif // !defined(OO_BUGGY_TEMPLATES)
#ifdef OO_BUGGY_TEMPLATES
inline
ooShortRef(ooHashSet)::ooShortRefStructor(ooHashSet)(const ooHashSet *  fromObject)
{
  *this = fromObject;
}
#else // !defined(OO_BUGGY_TEMPLATES)
inline
ooShortRef(ooHashSet)::ooShortRefStructor(ooHashSet)(const ooHashSet *  fromObject) :
    ooShortRef(ooCollection)(ooReinterpretCast(const ooCollection *,fromObject))
{
}
#endif // !defined(OO_BUGGY_TEMPLATES)


/* methods on ooHandle(ooHashSet) */
inline
ooHandle(ooHashSet)::ooHandleStructor(ooHashSet)()
{
}
inline
ooHandle(ooHashSet)::ooHandleStructor(ooHashSet)(const ooHandle(ooHashSet) &  objH) :
#ifdef OO_BUGGY_TEMPLATES
    ooHandle_superclass<ooHashSet >(objH)
#else // !defined(OO_BUGGY_TEMPLATES)
    ooHandle(ooCollection)(objH)
#endif // !defined(OO_BUGGY_TEMPLATES)
{
}
inline
ooHandle(ooHashSet)::ooHandleStructor(ooHashSet)(const ooRef(ooHashSet) &  id) :
#ifdef OO_BUGGY_TEMPLATES
    ooHandle_superclass<ooHashSet >(id)
#else // !defined(OO_BUGGY_TEMPLATES)
    ooHandle(ooCollection)(id)
#endif // !defined(OO_BUGGY_TEMPLATES)
{
}
inline
ooHandle(ooHashSet)::ooHandleStructor(ooHashSet)(const ooHashSet *  fromObject) :
#ifdef OO_BUGGY_TEMPLATES
    ooHandle_superclass<ooHashSet >(ooReinterpretCast(const ooCollection *,fromObject))
#else // !defined(OO_BUGGY_TEMPLATES)
    ooHandle(ooCollection)(ooReinterpretCast(const ooCollection *,fromObject))
#endif // !defined(OO_BUGGY_TEMPLATES)
{
}
inline
ooHandle(ooHashSet)&
ooHandle(ooHashSet)::operator=(const ooRef(ooHashSet) &  id)
{
  this->ooHandle(ooObj)::operator=(id);
  return *this;
}
inline
ooHandle(ooHashSet)&
ooHandle(ooHashSet)::operator=(const ooHandle(ooHashSet) &  objH)
{
  this->ooHandle(ooObj)::operator=(objH);
  return *this;
}
inline
ooHandle(ooHashSet)&
ooHandle(ooHashSet)::operator=(const ooShortRef(ooHashSet) &  shortId)
{
  this->ooHandle(ooObj)::operator=(shortId);
  return *this;
}
inline
ooHandle(ooHashSet)&
ooHandle(ooHashSet)::operator=(const ooHashSet *  fromObject)
{
  this->ooHandle(ooObj)::operator=(ooReinterpretCast(const ooObj *,fromObject));
  return *this;
}
inline
ooHashSet *
ooHandle(ooHashSet)::pin(ooMode  openMode) const
{
  return ooReinterpretCast(ooHashSet *, this->pin_obj_internal(openMode));
}
inline
ooHashSet *
ooHandle(ooHashSet)::operator->() const
{
  return this->vm();
}
inline
ooHashSet &
ooHandle(ooHashSet)::operator*() const
{
  return *(this->vm());
}
inline
ooHandle(ooHashSet)::operator ooHashSet *() const
{
  if ( _state == oocHandlePTR  )
    return ooReinterpretCast(ooHashSet *, _ptr._obj);
  else return ooReinterpretCast(ooHashSet *, this->get_vm());
}
inline
ooHashSet *
ooHandle(ooHashSet)::vm() const
{
  if ( _state == oocHandlePTR && _ptr._obj != NULL )
    return ooReinterpretCast(ooHashSet *, _ptr._obj);
  else return ooReinterpretCast(ooHashSet *, this->get_vm());
}
inline
ooRef(ooHashSet) &
ooHandle(ooHashSet)::copy(const ooHandle(ooObj) &  nearH,
		   ooRef(ooHashSet) &              result) const
{
  this->ooHandle(ooObj)::copy(nearH, result);
  return result;
}


/* ODMG methods */
inline
ooHashSet *
ooRef(ooHashSet)::ptr() const
{
  return this->pin();
}
inline
ooHashSet *
ooHandle(ooHashSet)::ptr() const
{
  return this->operator ooHashSet *();
}
class ooHashMap;


/////////////////////////////////////////////////////////////////////////////

ooTemplateSpecialization
class CO_STORAGE_SPECIFIER ooDeref(ooHashMap) : public ooDerefBase {
	friend class ooRef(ooHashMap);
  public:
    ~ooDerefStructor(ooHashMap)();
    inline ooHashMap *operator->() const;
#ifndef OO_BUGGY_TEMPLATES
  private:
#endif // !defined(OO_BUGGY_TEMPLATES)
    ooDerefStructor(ooHashMap)(ooDeref(ooHashMap)& deref);
    ooDerefStructor(ooHashMap)(ooObj *  fromObject);
};


#ifdef OO_BUGGY_TEMPLATES

class CO_STORAGE_SPECIFIER ooHandle_superclass<ooHashMap > : public ooHandle(ooHashSet) {
 protected:
  ooHandle_superclass()
    {}
  ooHandle_superclass(const ooHandle(ooHashSet) &  from) :
      ooHandle(ooHashSet)(from)
    {}
  ooHandle_superclass(const ooRef(ooHashSet) &  from) :
      ooHandle(ooHashSet)(from)
    {}
  ooHandle_superclass(const ooHashSet *  from) :
      ooHandle(ooHashSet)(from)
    {}
  ~ooHandle_superclass()
    {}
};

class CO_STORAGE_SPECIFIER ooShortRef_superclass<ooHashMap > : public ooShortRef(ooHashSet) {
};

#endif // OO_BUGGY_TEMPLATES

ooTemplateSpecialization
class CO_STORAGE_SPECIFIER ooRef(ooHashMap) : public ooRef(ooHashSet) {
  public:
    ooRefStructor(ooHashMap)()
      {}
    ooRefStructor(ooHashMap)(const ooRef(ooHashMap)& id) :
	  ooRef(ooHashSet)(id)
      {}
    inline ooRefStructor(ooHashMap)(const ooHandleSuper(ooHashMap)& objH);
    inline ooRefStructor(ooHashMap)(const ooHashMap *  fromObject);
    inline ooRef(ooHashMap)& operator=(const ooRef(ooHashMap)& id);
    inline ooRef(ooHashMap)& operator=(const ooShortRefSuper(ooHashMap) &shortId);
    inline ooRef(ooHashMap)& operator=(const ooHandleSuper(ooHashMap)& objH);
    inline ooRef(ooHashMap)& operator=(const ooHashMap *  fromObject);
    ooStatus lookupObj(const ooHandle(ooObj)& scopeH,
		       const ooKey& key,
		       ooMode openMode = oocRead);
    ooStatus lookupObj(const ooHandle(ooObj)& scopeH,
		       const char* name,
		       ooMode openMode = oocRead);
#ifndef OO_BUGGY_TEMPLATES
    inline ooRef(ooHashMap)& copy(const ooHandle(ooObj)& nearH,
		    ooRef(ooHashMap)& newObjRef) const;
    inline ooHandle(ooHashMap)& copy(const ooHandle(ooObj)& nearH,
			ooHandle(ooHashMap)& result) const;
    inline ooHandle(ooHashMap) copy(const ooHandle(ooObj)& nearH) const;
#endif // !defined(OO_BUGGY_TEMPLATES)
    inline ooHashMap *pin(ooMode openMode = oocRead) const;
    ooDeref(ooHashMap) operator->() const;
    /* Use pin() or use ooHandle "operator ooHashMap *" instead of vm. */
    /* OBSOLETE */ inline ooHashMap *vm(ooMode openMode = oocRead) const;
    // ODMG methods:
    ooRefStructor(ooHashMap)(const d_Ref_Any &from);
    ooHashMap *ptr() const;
};

ooTemplateSpecialization
class CO_STORAGE_SPECIFIER ooShortRef(ooHashMap) :
#ifdef OO_BUGGY_TEMPLATES
			public ooShortRef_superclass<ooHashMap >
#else // !defined(OO_BUGGY_TEMPLATES)
			public ooShortRef(ooHashSet)
#endif // !defined(OO_BUGGY_TEMPLATES)
					            {
  public:
    ooShortRefStructor(ooHashMap)();
    ooShortRefStructor(ooHashMap)(const ooShortRef(ooHashMap)& shortId);
    ooShortRefStructor(ooHashMap)(const ooRef(ooHashMap)& id);
    ooShortRefStructor(ooHashMap)(const ooHandleSuper(ooHashMap) &objH);
    ooShortRefStructor(ooHashMap)(const ooHashMap *  fromObject);
    ooShortRef(ooHashMap)& operator=(const ooShortRef(ooHashMap)& shortId);
    ooShortRef(ooHashMap)& operator=(const ooRef(ooHashMap)& id);
    ooShortRef(ooHashMap)& operator=(const ooHandleSuper(ooHashMap) &objH);
    ooShortRef(ooHashMap)& operator=(const ooHashMap *  fromObject);
};

ooTemplateSpecialization
class CO_STORAGE_SPECIFIER ooHandle(ooHashMap) :
#ifdef OO_BUGGY_TEMPLATES
		      public ooHandle_superclass<ooHashMap >
#else // !defined(OO_BUGGY_TEMPLATES)
		      public ooHandle(ooHashSet)
#endif // !defined(OO_BUGGY_TEMPLATES)
                                                {
  public:
    inline ooHandleStructor(ooHashMap)();
    inline ooHandleStructor(ooHashMap)(const ooRef(ooHashMap)& id);
    inline ooHandleStructor(ooHashMap)(const ooHandle(ooHashMap)& objH);
    inline ooHandleStructor(ooHashMap)(const ooHashMap *  fromObject);
    inline ooHandle(ooHashMap)& operator=(const ooRef(ooHashMap)& id);
    inline ooHandle(ooHashMap)& operator=(const ooHandle(ooHashMap)& objH);
    inline ooHandle(ooHashMap)& operator=(const ooShortRef(ooHashMap)& shortId);
    inline ooHandle(ooHashMap)& operator=(const ooHashMap *  fromObject);
    ooStatus lookupObj(const ooHandle(ooObj)& scopeH,
		       const ooKey& key,
		       ooMode openMode = oocRead);
    ooStatus lookupObj(const ooHandle(ooObj)& scopeH,
		       const char* name,
		       ooMode openMode = oocRead);
    ooHandle(ooHashMap)& copy(const ooHandle(ooObj)& nearH,
		       ooHandle(ooHashMap)& result) const;
    inline ooRef(ooHashMap)& copy(const ooHandle(ooObj)& nearH,
		    ooRef(ooHashMap)& result) const;
    ooHandle(ooHashMap) copy(const ooHandle(ooObj)& nearH) const;
    inline ooHashMap *pin(ooMode openMode = oocRead) const;
    inline ooHashMap *operator->() const;
    inline ooHashMap &operator*() const;
    inline operator ooHashMap *() const;
    /* Use "operator ooHashMap *" instead of vm. */
    /* OBSOLETE */ inline ooHashMap *vm() const;
    // ODMG methods:
    ooHandleStructor(ooHashMap)(const d_Ref_Any &from);
    ooHashMap *ptr() const;
};

ooTemplateSpecialization
class CO_STORAGE_SPECIFIER ooItr(ooHashMap) : public ooHandle(ooHashMap),
		    public ooIteratorObjOrContObj {
  public:
    ooItrStructor(ooHashMap)();
    ~ooItrStructor(ooHashMap)();
  private:
    // Defined only to prevent implicit definition:
    ooItrStructor(ooHashMap)(ooItr(ooHashMap)&);
    ooItr(ooHashMap)    operator=(ooItr(ooHashMap)&);
};


/* methods on ooDeref(ooHashMap) */
inline
ooDeref(ooHashMap)::ooDerefStructor(ooHashMap)(ooDeref(ooHashMap) &  deref) :
    ooDerefBase(deref.vm())
{
  this->pinCompensate();
}
inline
ooDeref(ooHashMap)::ooDerefStructor(ooHashMap)(ooObj *  fromObject) :
    ooDerefBase(fromObject)
{
}
inline
ooDeref(ooHashMap)::~ooDerefStructor(ooHashMap)()
{
}
inline
ooHashMap *
ooDeref(ooHashMap)::operator->() const
{
  return ooReinterpretCast(ooHashMap *, this->vm());
}


/* methods on ooRef(ooHashMap) */
inline
ooRef(ooHashMap)::ooRefStructor(ooHashMap)(const ooHandleSuper(ooHashMap)& objH) :
    ooRef(ooHashSet)(objH)
{
}
inline
ooRef(ooHashMap)::ooRefStructor(ooHashMap)(const ooHashMap *  fromObject) :
    ooRef(ooHashSet)(ooReinterpretCast(const ooHashSet *, fromObject))
{
}
inline
ooRef(ooHashMap)&
ooRef(ooHashMap)::operator=(const ooRef(ooHashMap) &  id)
{
  this->ooId::operator=(id);
  return *this;
}
inline
ooRef(ooHashMap)&
ooRef(ooHashMap)::operator=(const ooShortRefSuper(ooHashMap) &  shortId)
{
  this->ooRef(ooObj)::operator=(shortId);
  return *this;
}
inline
ooRef(ooHashMap)&
ooRef(ooHashMap)::operator=(const ooHandleSuper(ooHashMap) &  objH)
{
  this->ooRef(ooObj)::operator=(objH);
  return *this;
}
inline
ooRef(ooHashMap)&
ooRef(ooHashMap)::operator=(const ooHashMap *  fromObject)
{
  this->ooRef(ooObj)::operator=(ooReinterpretCast(const ooObj *, fromObject));
  return *this;
}
inline
ooHashMap *
ooRef(ooHashMap)::pin(ooMode  openMode) const
{
  return ooReinterpretCast(ooHashMap *, this->pin_ref_internal(openMode));
}
inline
ooHashMap *
ooRef(ooHashMap)::vm(ooMode  openMode) const
{
  return this->pin(openMode);
}
#ifndef OO_BUGGY_TEMPLATES
inline
ooHandle(ooHashMap) &
ooRef(ooHashMap)::copy(const ooHandle(ooObj) &  nearH,
		ooHandle(ooHashMap) &           result) const
{
  this->ooRef(ooObj)::copy(nearH, result);
  return result;
}
inline
ooRef(ooHashMap) &
ooRef(ooHashMap)::copy(const ooHandle(ooObj) &  nearH,
		ooRef(ooHashMap) &              newObjRef) const
{
  this->ooRef(ooObj)::copy(nearH, newObjRef);
  return newObjRef;
}
inline
ooHandle(ooHashMap)
ooRef(ooHashMap)::copy(const ooHandle(ooObj) &  nearH) const
{
  ooHandle(ooHashMap) result;
  this->ooRef(ooObj)::copy(nearH, result);
  return result;
}
#endif // !defined(OO_BUGGY_TEMPLATES)
inline
ooDeref(ooHashMap)
ooRef(ooHashMap)::operator->() const
{
  ooDeref(ooHashMap) result(this->pin_ref_internal(oocRead));
  return result;
}


/* methods on ooShortRef(ooHashMap) */
inline
ooShortRef(ooHashMap) &
ooShortRef(ooHashMap)::operator=(const ooShortRef(ooHashMap) &  shortId)
{
  this->ooShortId::operator=(shortId);
  return *this;
}
inline
ooShortRef(ooHashMap) &
ooShortRef(ooHashMap)::operator=(const ooRef(ooHashMap) &  id)
{
  this->ooShortId::operator=(id);
  return *this;
}
inline
ooShortRef(ooHashMap) &
ooShortRef(ooHashMap)::operator=(const ooHandleSuper(ooHashMap) &  objH)
{
  this->ooShortId::operator=(objH);
  return *this;
}
inline
ooShortRef(ooHashMap)&
ooShortRef(ooHashMap)::operator=(const ooHashMap *  fromObject)
{
  this->ooShortId::operator=(ooReinterpretCast(const ooObj *,fromObject));
  return *this;
}
inline
ooShortRef(ooHashMap)::ooShortRefStructor(ooHashMap)()
{
}
#ifdef OO_BUGGY_TEMPLATES
inline
ooShortRef(ooHashMap)::ooShortRefStructor(ooHashMap)(const ooShortRef(ooHashMap) &  shortId)
{
  *this = shortId;
}
#else // !defined(OO_BUGGY_TEMPLATES)
inline
ooShortRef(ooHashMap)::ooShortRefStructor(ooHashMap)(const ooShortRef(ooHashMap) &  shortId) :
    ooShortRef(ooHashSet)(shortId)
{
}
#endif // !defined(OO_BUGGY_TEMPLATES)
#ifdef OO_BUGGY_TEMPLATES
inline
ooShortRef(ooHashMap)::ooShortRefStructor(ooHashMap)(const ooRef(ooHashMap) &  id)
{
  *this = id;
}
#else // !defined(OO_BUGGY_TEMPLATES)
inline
ooShortRef(ooHashMap)::ooShortRefStructor(ooHashMap)(const ooRef(ooHashMap) &  id) :
    ooShortRef(ooHashSet)(id)
{
}
#endif // !defined(OO_BUGGY_TEMPLATES)
#ifdef OO_BUGGY_TEMPLATES
inline
ooShortRef(ooHashMap)::ooShortRefStructor(ooHashMap)(const ooHandleSuper(ooHashMap) &  objH)
{
  *this = objH;
}
#else // !defined(OO_BUGGY_TEMPLATES)
inline
ooShortRef(ooHashMap)::ooShortRefStructor(ooHashMap)(const ooHandleSuper(ooHashMap) &  objH) :
    ooShortRef(ooHashSet)(objH)
{
}
#endif // !defined(OO_BUGGY_TEMPLATES)
#ifdef OO_BUGGY_TEMPLATES
inline
ooShortRef(ooHashMap)::ooShortRefStructor(ooHashMap)(const ooHashMap *  fromObject)
{
  *this = fromObject;
}
#else // !defined(OO_BUGGY_TEMPLATES)
inline
ooShortRef(ooHashMap)::ooShortRefStructor(ooHashMap)(const ooHashMap *  fromObject) :
    ooShortRef(ooHashSet)(ooReinterpretCast(const ooHashSet *,fromObject))
{
}
#endif // !defined(OO_BUGGY_TEMPLATES)


/* methods on ooHandle(ooHashMap) */
inline
ooHandle(ooHashMap)::ooHandleStructor(ooHashMap)()
{
}
inline
ooHandle(ooHashMap)::ooHandleStructor(ooHashMap)(const ooHandle(ooHashMap) &  objH) :
#ifdef OO_BUGGY_TEMPLATES
    ooHandle_superclass<ooHashMap >(objH)
#else // !defined(OO_BUGGY_TEMPLATES)
    ooHandle(ooHashSet)(objH)
#endif // !defined(OO_BUGGY_TEMPLATES)
{
}
inline
ooHandle(ooHashMap)::ooHandleStructor(ooHashMap)(const ooRef(ooHashMap) &  id) :
#ifdef OO_BUGGY_TEMPLATES
    ooHandle_superclass<ooHashMap >(id)
#else // !defined(OO_BUGGY_TEMPLATES)
    ooHandle(ooHashSet)(id)
#endif // !defined(OO_BUGGY_TEMPLATES)
{
}
inline
ooHandle(ooHashMap)::ooHandleStructor(ooHashMap)(const ooHashMap *  fromObject) :
#ifdef OO_BUGGY_TEMPLATES
    ooHandle_superclass<ooHashMap >(ooReinterpretCast(const ooHashSet *,fromObject))
#else // !defined(OO_BUGGY_TEMPLATES)
    ooHandle(ooHashSet)(ooReinterpretCast(const ooHashSet *,fromObject))
#endif // !defined(OO_BUGGY_TEMPLATES)
{
}
inline
ooHandle(ooHashMap)&
ooHandle(ooHashMap)::operator=(const ooRef(ooHashMap) &  id)
{
  this->ooHandle(ooObj)::operator=(id);
  return *this;
}
inline
ooHandle(ooHashMap)&
ooHandle(ooHashMap)::operator=(const ooHandle(ooHashMap) &  objH)
{
  this->ooHandle(ooObj)::operator=(objH);
  return *this;
}
inline
ooHandle(ooHashMap)&
ooHandle(ooHashMap)::operator=(const ooShortRef(ooHashMap) &  shortId)
{
  this->ooHandle(ooObj)::operator=(shortId);
  return *this;
}
inline
ooHandle(ooHashMap)&
ooHandle(ooHashMap)::operator=(const ooHashMap *  fromObject)
{
  this->ooHandle(ooObj)::operator=(ooReinterpretCast(const ooObj *,fromObject));
  return *this;
}
inline
ooHashMap *
ooHandle(ooHashMap)::pin(ooMode  openMode) const
{
  return ooReinterpretCast(ooHashMap *, this->pin_obj_internal(openMode));
}
inline
ooHashMap *
ooHandle(ooHashMap)::operator->() const
{
  return this->vm();
}
inline
ooHashMap &
ooHandle(ooHashMap)::operator*() const
{
  return *(this->vm());
}
inline
ooHandle(ooHashMap)::operator ooHashMap *() const
{
  if ( _state == oocHandlePTR  )
    return ooReinterpretCast(ooHashMap *, _ptr._obj);
  else return ooReinterpretCast(ooHashMap *, this->get_vm());
}
inline
ooHashMap *
ooHandle(ooHashMap)::vm() const
{
  if ( _state == oocHandlePTR && _ptr._obj != NULL )
    return ooReinterpretCast(ooHashMap *, _ptr._obj);
  else return ooReinterpretCast(ooHashMap *, this->get_vm());
}
inline
ooRef(ooHashMap) &
ooHandle(ooHashMap)::copy(const ooHandle(ooObj) &  nearH,
		   ooRef(ooHashMap) &              result) const
{
  this->ooHandle(ooObj)::copy(nearH, result);
  return result;
}


/* ODMG methods */
inline
ooHashMap *
ooRef(ooHashMap)::ptr() const
{
  return this->pin();
}
inline
ooHashMap *
ooHandle(ooHashMap)::ptr() const
{
  return this->operator ooHashMap *();
}
#if defined(_MSC_VER) && !defined(OO_DDL_TRANSLATION)
#pragma pack(pop)
#endif

#endif /* OO_COLLECTIONS_REF_H */

