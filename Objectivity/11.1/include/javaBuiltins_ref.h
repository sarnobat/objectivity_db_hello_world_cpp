/* C++ 'references' header file: Objectivity/DB DDL Version: 11.1 */


#ifndef JAVA_BUILTINS_REF_H
#define JAVA_BUILTINS_REF_H

#ifndef OO_H
#include <oo.h>
#endif
#include <ooSchema_ref.h>
#if defined(_MSC_VER) && !defined(OO_DDL_TRANSLATION)
#pragma pack(push,8)
#endif
class oojString;


/////////////////////////////////////////////////////////////////////////////

ooTemplateSpecialization
class ooDeref(oojString) : public ooDerefBase {
	friend class ooRef(oojString);
  public:
    ~ooDerefStructor(oojString)();
    inline oojString *operator->() const;
#ifndef OO_BUGGY_TEMPLATES
  private:
#endif // !defined(OO_BUGGY_TEMPLATES)
    ooDerefStructor(oojString)(ooDeref(oojString)& deref);
    ooDerefStructor(oojString)(ooObj *  fromObject);
};


#ifdef OO_BUGGY_TEMPLATES

class ooHandle_superclass<oojString > : public ooHandle(ooObj) {
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

class ooShortRef_superclass<oojString > : public ooShortRef(ooObj) {
};

#endif // OO_BUGGY_TEMPLATES

ooTemplateSpecialization
class ooRef(oojString) : public ooRef(ooObj) {
  public:
    ooRefStructor(oojString)()
      {}
    ooRefStructor(oojString)(const ooRef(oojString)& id) :
	  ooRef(ooObj)(id)
      {}
    inline ooRefStructor(oojString)(const ooHandleSuper(oojString)& objH);
    inline ooRefStructor(oojString)(const oojString *  fromObject);
    inline ooRef(oojString)& operator=(const ooRef(oojString)& id);
    inline ooRef(oojString)& operator=(const ooShortRefSuper(oojString) &shortId);
    inline ooRef(oojString)& operator=(const ooHandleSuper(oojString)& objH);
    inline ooRef(oojString)& operator=(const oojString *  fromObject);
    ooStatus lookupObj(const ooHandle(ooObj)& scopeH,
		       const ooKey& key,
		       ooMode openMode = oocRead);
    ooStatus lookupObj(const ooHandle(ooObj)& scopeH,
		       const char* name,
		       ooMode openMode = oocRead);
#ifndef OO_BUGGY_TEMPLATES
    inline ooRef(oojString)& copy(const ooHandle(ooObj)& nearH,
		    ooRef(oojString)& newObjRef) const;
    inline ooHandle(oojString)& copy(const ooHandle(ooObj)& nearH,
			ooHandle(oojString)& result) const;
    inline ooHandle(oojString) copy(const ooHandle(ooObj)& nearH) const;
#endif // !defined(OO_BUGGY_TEMPLATES)
    inline oojString *pin(ooMode openMode = oocRead) const;
    ooDeref(oojString) operator->() const;
    /* Use pin() or use ooHandle "operator oojString *" instead of vm. */
    /* OBSOLETE */ inline oojString *vm(ooMode openMode = oocRead) const;
    // ODMG methods:
    ooRefStructor(oojString)(const d_Ref_Any &from);
    oojString *ptr() const;
};

ooTemplateSpecialization
class ooShortRef(oojString) :
#ifdef OO_BUGGY_TEMPLATES
			public ooShortRef_superclass<oojString >
#else // !defined(OO_BUGGY_TEMPLATES)
			public ooShortRef(ooObj)
#endif // !defined(OO_BUGGY_TEMPLATES)
					            {
  public:
    ooShortRefStructor(oojString)();
    ooShortRefStructor(oojString)(const ooShortRef(oojString)& shortId);
    ooShortRefStructor(oojString)(const ooRef(oojString)& id);
    ooShortRefStructor(oojString)(const ooHandleSuper(oojString) &objH);
    ooShortRefStructor(oojString)(const oojString *  fromObject);
    ooShortRef(oojString)& operator=(const ooShortRef(oojString)& shortId);
    ooShortRef(oojString)& operator=(const ooRef(oojString)& id);
    ooShortRef(oojString)& operator=(const ooHandleSuper(oojString) &objH);
    ooShortRef(oojString)& operator=(const oojString *  fromObject);
};

ooTemplateSpecialization
class ooHandle(oojString) :
#ifdef OO_BUGGY_TEMPLATES
		      public ooHandle_superclass<oojString >
#else // !defined(OO_BUGGY_TEMPLATES)
		      public ooHandle(ooObj)
#endif // !defined(OO_BUGGY_TEMPLATES)
                                                {
  public:
    inline ooHandleStructor(oojString)();
    inline ooHandleStructor(oojString)(const ooRef(oojString)& id);
    inline ooHandleStructor(oojString)(const ooHandle(oojString)& objH);
    inline ooHandleStructor(oojString)(const oojString *  fromObject);
    inline ooHandle(oojString)& operator=(const ooRef(oojString)& id);
    inline ooHandle(oojString)& operator=(const ooHandle(oojString)& objH);
    inline ooHandle(oojString)& operator=(const ooShortRef(oojString)& shortId);
    inline ooHandle(oojString)& operator=(const oojString *  fromObject);
    ooStatus lookupObj(const ooHandle(ooObj)& scopeH,
		       const ooKey& key,
		       ooMode openMode = oocRead);
    ooStatus lookupObj(const ooHandle(ooObj)& scopeH,
		       const char* name,
		       ooMode openMode = oocRead);
    ooHandle(oojString)& copy(const ooHandle(ooObj)& nearH,
		       ooHandle(oojString)& result) const;
    inline ooRef(oojString)& copy(const ooHandle(ooObj)& nearH,
		    ooRef(oojString)& result) const;
    ooHandle(oojString) copy(const ooHandle(ooObj)& nearH) const;
    inline oojString *pin(ooMode openMode = oocRead) const;
    inline oojString *operator->() const;
    inline oojString &operator*() const;
    inline operator oojString *() const;
    /* Use "operator oojString *" instead of vm. */
    /* OBSOLETE */ inline oojString *vm() const;
    // ODMG methods:
    ooHandleStructor(oojString)(const d_Ref_Any &from);
    oojString *ptr() const;
};

ooTemplateSpecialization
class ooItr(oojString) : public ooHandle(oojString),
		    public ooIteratorObjOrContObj {
  public:
    ooItrStructor(oojString)();
    ~ooItrStructor(oojString)();
  private:
    // Defined only to prevent implicit definition:
    ooItrStructor(oojString)(ooItr(oojString)&);
    ooItr(oojString)    operator=(ooItr(oojString)&);
};


/* methods on ooDeref(oojString) */
inline
ooDeref(oojString)::ooDerefStructor(oojString)(ooDeref(oojString) &  deref) :
    ooDerefBase(deref.vm())
{
  this->pinCompensate();
}
inline
ooDeref(oojString)::ooDerefStructor(oojString)(ooObj *  fromObject) :
    ooDerefBase(fromObject)
{
}
inline
ooDeref(oojString)::~ooDerefStructor(oojString)()
{
}
inline
oojString *
ooDeref(oojString)::operator->() const
{
  return ooReinterpretCast(oojString *, this->vm());
}


/* methods on ooRef(oojString) */
inline
ooRef(oojString)::ooRefStructor(oojString)(const ooHandleSuper(oojString)& objH) :
    ooRef(ooObj)(objH)
{
}
inline
ooRef(oojString)::ooRefStructor(oojString)(const oojString *  fromObject) :
    ooRef(ooObj)(ooReinterpretCast(const ooObj *, fromObject))
{
}
inline
ooRef(oojString)&
ooRef(oojString)::operator=(const ooRef(oojString) &  id)
{
  this->ooId::operator=(id);
  return *this;
}
inline
ooRef(oojString)&
ooRef(oojString)::operator=(const ooShortRefSuper(oojString) &  shortId)
{
  this->ooRef(ooObj)::operator=(shortId);
  return *this;
}
inline
ooRef(oojString)&
ooRef(oojString)::operator=(const ooHandleSuper(oojString) &  objH)
{
  this->ooRef(ooObj)::operator=(objH);
  return *this;
}
inline
ooRef(oojString)&
ooRef(oojString)::operator=(const oojString *  fromObject)
{
  this->ooRef(ooObj)::operator=(ooReinterpretCast(const ooObj *, fromObject));
  return *this;
}
inline
oojString *
ooRef(oojString)::pin(ooMode  openMode) const
{
  return ooReinterpretCast(oojString *, this->pin_ref_internal(openMode));
}
inline
oojString *
ooRef(oojString)::vm(ooMode  openMode) const
{
  return this->pin(openMode);
}
#ifndef OO_BUGGY_TEMPLATES
inline
ooHandle(oojString) &
ooRef(oojString)::copy(const ooHandle(ooObj) &  nearH,
		ooHandle(oojString) &           result) const
{
  this->ooRef(ooObj)::copy(nearH, result);
  return result;
}
inline
ooRef(oojString) &
ooRef(oojString)::copy(const ooHandle(ooObj) &  nearH,
		ooRef(oojString) &              newObjRef) const
{
  this->ooRef(ooObj)::copy(nearH, newObjRef);
  return newObjRef;
}
inline
ooHandle(oojString)
ooRef(oojString)::copy(const ooHandle(ooObj) &  nearH) const
{
  ooHandle(oojString) result;
  this->ooRef(ooObj)::copy(nearH, result);
  return result;
}
#endif // !defined(OO_BUGGY_TEMPLATES)
inline
ooDeref(oojString)
ooRef(oojString)::operator->() const
{
  ooDeref(oojString) result(this->pin_ref_internal(oocRead));
  return result;
}


/* methods on ooShortRef(oojString) */
inline
ooShortRef(oojString) &
ooShortRef(oojString)::operator=(const ooShortRef(oojString) &  shortId)
{
  this->ooShortId::operator=(shortId);
  return *this;
}
inline
ooShortRef(oojString) &
ooShortRef(oojString)::operator=(const ooRef(oojString) &  id)
{
  this->ooShortId::operator=(id);
  return *this;
}
inline
ooShortRef(oojString) &
ooShortRef(oojString)::operator=(const ooHandleSuper(oojString) &  objH)
{
  this->ooShortId::operator=(objH);
  return *this;
}
inline
ooShortRef(oojString)&
ooShortRef(oojString)::operator=(const oojString *  fromObject)
{
  this->ooShortId::operator=(ooReinterpretCast(const ooObj *,fromObject));
  return *this;
}
inline
ooShortRef(oojString)::ooShortRefStructor(oojString)()
{
}
#ifdef OO_BUGGY_TEMPLATES
inline
ooShortRef(oojString)::ooShortRefStructor(oojString)(const ooShortRef(oojString) &  shortId)
{
  *this = shortId;
}
#else // !defined(OO_BUGGY_TEMPLATES)
inline
ooShortRef(oojString)::ooShortRefStructor(oojString)(const ooShortRef(oojString) &  shortId) :
    ooShortRef(ooObj)(shortId)
{
}
#endif // !defined(OO_BUGGY_TEMPLATES)
#ifdef OO_BUGGY_TEMPLATES
inline
ooShortRef(oojString)::ooShortRefStructor(oojString)(const ooRef(oojString) &  id)
{
  *this = id;
}
#else // !defined(OO_BUGGY_TEMPLATES)
inline
ooShortRef(oojString)::ooShortRefStructor(oojString)(const ooRef(oojString) &  id) :
    ooShortRef(ooObj)(id)
{
}
#endif // !defined(OO_BUGGY_TEMPLATES)
#ifdef OO_BUGGY_TEMPLATES
inline
ooShortRef(oojString)::ooShortRefStructor(oojString)(const ooHandleSuper(oojString) &  objH)
{
  *this = objH;
}
#else // !defined(OO_BUGGY_TEMPLATES)
inline
ooShortRef(oojString)::ooShortRefStructor(oojString)(const ooHandleSuper(oojString) &  objH) :
    ooShortRef(ooObj)(objH)
{
}
#endif // !defined(OO_BUGGY_TEMPLATES)
#ifdef OO_BUGGY_TEMPLATES
inline
ooShortRef(oojString)::ooShortRefStructor(oojString)(const oojString *  fromObject)
{
  *this = fromObject;
}
#else // !defined(OO_BUGGY_TEMPLATES)
inline
ooShortRef(oojString)::ooShortRefStructor(oojString)(const oojString *  fromObject) :
    ooShortRef(ooObj)(ooReinterpretCast(const ooObj *,fromObject))
{
}
#endif // !defined(OO_BUGGY_TEMPLATES)


/* methods on ooHandle(oojString) */
inline
ooHandle(oojString)::ooHandleStructor(oojString)()
{
}
inline
ooHandle(oojString)::ooHandleStructor(oojString)(const ooHandle(oojString) &  objH) :
#ifdef OO_BUGGY_TEMPLATES
    ooHandle_superclass<oojString >(objH)
#else // !defined(OO_BUGGY_TEMPLATES)
    ooHandle(ooObj)(objH)
#endif // !defined(OO_BUGGY_TEMPLATES)
{
}
inline
ooHandle(oojString)::ooHandleStructor(oojString)(const ooRef(oojString) &  id) :
#ifdef OO_BUGGY_TEMPLATES
    ooHandle_superclass<oojString >(id)
#else // !defined(OO_BUGGY_TEMPLATES)
    ooHandle(ooObj)(id)
#endif // !defined(OO_BUGGY_TEMPLATES)
{
}
inline
ooHandle(oojString)::ooHandleStructor(oojString)(const oojString *  fromObject) :
#ifdef OO_BUGGY_TEMPLATES
    ooHandle_superclass<oojString >(ooReinterpretCast(const ooObj *,fromObject))
#else // !defined(OO_BUGGY_TEMPLATES)
    ooHandle(ooObj)(ooReinterpretCast(const ooObj *,fromObject))
#endif // !defined(OO_BUGGY_TEMPLATES)
{
}
inline
ooHandle(oojString)&
ooHandle(oojString)::operator=(const ooRef(oojString) &  id)
{
  this->ooHandle(ooObj)::operator=(id);
  return *this;
}
inline
ooHandle(oojString)&
ooHandle(oojString)::operator=(const ooHandle(oojString) &  objH)
{
  this->ooHandle(ooObj)::operator=(objH);
  return *this;
}
inline
ooHandle(oojString)&
ooHandle(oojString)::operator=(const ooShortRef(oojString) &  shortId)
{
  this->ooHandle(ooObj)::operator=(shortId);
  return *this;
}
inline
ooHandle(oojString)&
ooHandle(oojString)::operator=(const oojString *  fromObject)
{
  this->ooHandle(ooObj)::operator=(ooReinterpretCast(const ooObj *,fromObject));
  return *this;
}
inline
oojString *
ooHandle(oojString)::pin(ooMode  openMode) const
{
  return ooReinterpretCast(oojString *, this->pin_obj_internal(openMode));
}
inline
oojString *
ooHandle(oojString)::operator->() const
{
  return this->vm();
}
inline
oojString &
ooHandle(oojString)::operator*() const
{
  return *(this->vm());
}
inline
ooHandle(oojString)::operator oojString *() const
{
  if ( _state == oocHandlePTR  )
    return ooReinterpretCast(oojString *, _ptr._obj);
  else return ooReinterpretCast(oojString *, this->get_vm());
}
inline
oojString *
ooHandle(oojString)::vm() const
{
  if ( _state == oocHandlePTR && _ptr._obj != NULL )
    return ooReinterpretCast(oojString *, _ptr._obj);
  else return ooReinterpretCast(oojString *, this->get_vm());
}
inline
ooRef(oojString) &
ooHandle(oojString)::copy(const ooHandle(ooObj) &  nearH,
		   ooRef(oojString) &              result) const
{
  this->ooHandle(ooObj)::copy(nearH, result);
  return result;
}


/* ODMG methods */
inline
oojString *
ooRef(oojString)::ptr() const
{
  return this->pin();
}
inline
oojString *
ooHandle(oojString)::ptr() const
{
  return this->operator oojString *();
}
class oojDate;


/////////////////////////////////////////////////////////////////////////////

ooTemplateSpecialization
class ooDeref(oojDate) : public ooDerefBase {
	friend class ooRef(oojDate);
  public:
    ~ooDerefStructor(oojDate)();
    inline oojDate *operator->() const;
#ifndef OO_BUGGY_TEMPLATES
  private:
#endif // !defined(OO_BUGGY_TEMPLATES)
    ooDerefStructor(oojDate)(ooDeref(oojDate)& deref);
    ooDerefStructor(oojDate)(ooObj *  fromObject);
};


#ifdef OO_BUGGY_TEMPLATES

class ooHandle_superclass<oojDate > : public ooHandle(ooObj) {
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

class ooShortRef_superclass<oojDate > : public ooShortRef(ooObj) {
};

#endif // OO_BUGGY_TEMPLATES

ooTemplateSpecialization
class ooRef(oojDate) : public ooRef(ooObj) {
  public:
    ooRefStructor(oojDate)()
      {}
    ooRefStructor(oojDate)(const ooRef(oojDate)& id) :
	  ooRef(ooObj)(id)
      {}
    inline ooRefStructor(oojDate)(const ooHandleSuper(oojDate)& objH);
    inline ooRefStructor(oojDate)(const oojDate *  fromObject);
    inline ooRef(oojDate)& operator=(const ooRef(oojDate)& id);
    inline ooRef(oojDate)& operator=(const ooShortRefSuper(oojDate) &shortId);
    inline ooRef(oojDate)& operator=(const ooHandleSuper(oojDate)& objH);
    inline ooRef(oojDate)& operator=(const oojDate *  fromObject);
    ooStatus lookupObj(const ooHandle(ooObj)& scopeH,
		       const ooKey& key,
		       ooMode openMode = oocRead);
    ooStatus lookupObj(const ooHandle(ooObj)& scopeH,
		       const char* name,
		       ooMode openMode = oocRead);
#ifndef OO_BUGGY_TEMPLATES
    inline ooRef(oojDate)& copy(const ooHandle(ooObj)& nearH,
		    ooRef(oojDate)& newObjRef) const;
    inline ooHandle(oojDate)& copy(const ooHandle(ooObj)& nearH,
			ooHandle(oojDate)& result) const;
    inline ooHandle(oojDate) copy(const ooHandle(ooObj)& nearH) const;
#endif // !defined(OO_BUGGY_TEMPLATES)
    inline oojDate *pin(ooMode openMode = oocRead) const;
    ooDeref(oojDate) operator->() const;
    /* Use pin() or use ooHandle "operator oojDate *" instead of vm. */
    /* OBSOLETE */ inline oojDate *vm(ooMode openMode = oocRead) const;
    // ODMG methods:
    ooRefStructor(oojDate)(const d_Ref_Any &from);
    oojDate *ptr() const;
};

ooTemplateSpecialization
class ooShortRef(oojDate) :
#ifdef OO_BUGGY_TEMPLATES
			public ooShortRef_superclass<oojDate >
#else // !defined(OO_BUGGY_TEMPLATES)
			public ooShortRef(ooObj)
#endif // !defined(OO_BUGGY_TEMPLATES)
					            {
  public:
    ooShortRefStructor(oojDate)();
    ooShortRefStructor(oojDate)(const ooShortRef(oojDate)& shortId);
    ooShortRefStructor(oojDate)(const ooRef(oojDate)& id);
    ooShortRefStructor(oojDate)(const ooHandleSuper(oojDate) &objH);
    ooShortRefStructor(oojDate)(const oojDate *  fromObject);
    ooShortRef(oojDate)& operator=(const ooShortRef(oojDate)& shortId);
    ooShortRef(oojDate)& operator=(const ooRef(oojDate)& id);
    ooShortRef(oojDate)& operator=(const ooHandleSuper(oojDate) &objH);
    ooShortRef(oojDate)& operator=(const oojDate *  fromObject);
};

ooTemplateSpecialization
class ooHandle(oojDate) :
#ifdef OO_BUGGY_TEMPLATES
		      public ooHandle_superclass<oojDate >
#else // !defined(OO_BUGGY_TEMPLATES)
		      public ooHandle(ooObj)
#endif // !defined(OO_BUGGY_TEMPLATES)
                                                {
  public:
    inline ooHandleStructor(oojDate)();
    inline ooHandleStructor(oojDate)(const ooRef(oojDate)& id);
    inline ooHandleStructor(oojDate)(const ooHandle(oojDate)& objH);
    inline ooHandleStructor(oojDate)(const oojDate *  fromObject);
    inline ooHandle(oojDate)& operator=(const ooRef(oojDate)& id);
    inline ooHandle(oojDate)& operator=(const ooHandle(oojDate)& objH);
    inline ooHandle(oojDate)& operator=(const ooShortRef(oojDate)& shortId);
    inline ooHandle(oojDate)& operator=(const oojDate *  fromObject);
    ooStatus lookupObj(const ooHandle(ooObj)& scopeH,
		       const ooKey& key,
		       ooMode openMode = oocRead);
    ooStatus lookupObj(const ooHandle(ooObj)& scopeH,
		       const char* name,
		       ooMode openMode = oocRead);
    ooHandle(oojDate)& copy(const ooHandle(ooObj)& nearH,
		       ooHandle(oojDate)& result) const;
    inline ooRef(oojDate)& copy(const ooHandle(ooObj)& nearH,
		    ooRef(oojDate)& result) const;
    ooHandle(oojDate) copy(const ooHandle(ooObj)& nearH) const;
    inline oojDate *pin(ooMode openMode = oocRead) const;
    inline oojDate *operator->() const;
    inline oojDate &operator*() const;
    inline operator oojDate *() const;
    /* Use "operator oojDate *" instead of vm. */
    /* OBSOLETE */ inline oojDate *vm() const;
    // ODMG methods:
    ooHandleStructor(oojDate)(const d_Ref_Any &from);
    oojDate *ptr() const;
};

ooTemplateSpecialization
class ooItr(oojDate) : public ooHandle(oojDate),
		    public ooIteratorObjOrContObj {
  public:
    ooItrStructor(oojDate)();
    ~ooItrStructor(oojDate)();
  private:
    // Defined only to prevent implicit definition:
    ooItrStructor(oojDate)(ooItr(oojDate)&);
    ooItr(oojDate)    operator=(ooItr(oojDate)&);
};


/* methods on ooDeref(oojDate) */
inline
ooDeref(oojDate)::ooDerefStructor(oojDate)(ooDeref(oojDate) &  deref) :
    ooDerefBase(deref.vm())
{
  this->pinCompensate();
}
inline
ooDeref(oojDate)::ooDerefStructor(oojDate)(ooObj *  fromObject) :
    ooDerefBase(fromObject)
{
}
inline
ooDeref(oojDate)::~ooDerefStructor(oojDate)()
{
}
inline
oojDate *
ooDeref(oojDate)::operator->() const
{
  return ooReinterpretCast(oojDate *, this->vm());
}


/* methods on ooRef(oojDate) */
inline
ooRef(oojDate)::ooRefStructor(oojDate)(const ooHandleSuper(oojDate)& objH) :
    ooRef(ooObj)(objH)
{
}
inline
ooRef(oojDate)::ooRefStructor(oojDate)(const oojDate *  fromObject) :
    ooRef(ooObj)(ooReinterpretCast(const ooObj *, fromObject))
{
}
inline
ooRef(oojDate)&
ooRef(oojDate)::operator=(const ooRef(oojDate) &  id)
{
  this->ooId::operator=(id);
  return *this;
}
inline
ooRef(oojDate)&
ooRef(oojDate)::operator=(const ooShortRefSuper(oojDate) &  shortId)
{
  this->ooRef(ooObj)::operator=(shortId);
  return *this;
}
inline
ooRef(oojDate)&
ooRef(oojDate)::operator=(const ooHandleSuper(oojDate) &  objH)
{
  this->ooRef(ooObj)::operator=(objH);
  return *this;
}
inline
ooRef(oojDate)&
ooRef(oojDate)::operator=(const oojDate *  fromObject)
{
  this->ooRef(ooObj)::operator=(ooReinterpretCast(const ooObj *, fromObject));
  return *this;
}
inline
oojDate *
ooRef(oojDate)::pin(ooMode  openMode) const
{
  return ooReinterpretCast(oojDate *, this->pin_ref_internal(openMode));
}
inline
oojDate *
ooRef(oojDate)::vm(ooMode  openMode) const
{
  return this->pin(openMode);
}
#ifndef OO_BUGGY_TEMPLATES
inline
ooHandle(oojDate) &
ooRef(oojDate)::copy(const ooHandle(ooObj) &  nearH,
		ooHandle(oojDate) &           result) const
{
  this->ooRef(ooObj)::copy(nearH, result);
  return result;
}
inline
ooRef(oojDate) &
ooRef(oojDate)::copy(const ooHandle(ooObj) &  nearH,
		ooRef(oojDate) &              newObjRef) const
{
  this->ooRef(ooObj)::copy(nearH, newObjRef);
  return newObjRef;
}
inline
ooHandle(oojDate)
ooRef(oojDate)::copy(const ooHandle(ooObj) &  nearH) const
{
  ooHandle(oojDate) result;
  this->ooRef(ooObj)::copy(nearH, result);
  return result;
}
#endif // !defined(OO_BUGGY_TEMPLATES)
inline
ooDeref(oojDate)
ooRef(oojDate)::operator->() const
{
  ooDeref(oojDate) result(this->pin_ref_internal(oocRead));
  return result;
}


/* methods on ooShortRef(oojDate) */
inline
ooShortRef(oojDate) &
ooShortRef(oojDate)::operator=(const ooShortRef(oojDate) &  shortId)
{
  this->ooShortId::operator=(shortId);
  return *this;
}
inline
ooShortRef(oojDate) &
ooShortRef(oojDate)::operator=(const ooRef(oojDate) &  id)
{
  this->ooShortId::operator=(id);
  return *this;
}
inline
ooShortRef(oojDate) &
ooShortRef(oojDate)::operator=(const ooHandleSuper(oojDate) &  objH)
{
  this->ooShortId::operator=(objH);
  return *this;
}
inline
ooShortRef(oojDate)&
ooShortRef(oojDate)::operator=(const oojDate *  fromObject)
{
  this->ooShortId::operator=(ooReinterpretCast(const ooObj *,fromObject));
  return *this;
}
inline
ooShortRef(oojDate)::ooShortRefStructor(oojDate)()
{
}
#ifdef OO_BUGGY_TEMPLATES
inline
ooShortRef(oojDate)::ooShortRefStructor(oojDate)(const ooShortRef(oojDate) &  shortId)
{
  *this = shortId;
}
#else // !defined(OO_BUGGY_TEMPLATES)
inline
ooShortRef(oojDate)::ooShortRefStructor(oojDate)(const ooShortRef(oojDate) &  shortId) :
    ooShortRef(ooObj)(shortId)
{
}
#endif // !defined(OO_BUGGY_TEMPLATES)
#ifdef OO_BUGGY_TEMPLATES
inline
ooShortRef(oojDate)::ooShortRefStructor(oojDate)(const ooRef(oojDate) &  id)
{
  *this = id;
}
#else // !defined(OO_BUGGY_TEMPLATES)
inline
ooShortRef(oojDate)::ooShortRefStructor(oojDate)(const ooRef(oojDate) &  id) :
    ooShortRef(ooObj)(id)
{
}
#endif // !defined(OO_BUGGY_TEMPLATES)
#ifdef OO_BUGGY_TEMPLATES
inline
ooShortRef(oojDate)::ooShortRefStructor(oojDate)(const ooHandleSuper(oojDate) &  objH)
{
  *this = objH;
}
#else // !defined(OO_BUGGY_TEMPLATES)
inline
ooShortRef(oojDate)::ooShortRefStructor(oojDate)(const ooHandleSuper(oojDate) &  objH) :
    ooShortRef(ooObj)(objH)
{
}
#endif // !defined(OO_BUGGY_TEMPLATES)
#ifdef OO_BUGGY_TEMPLATES
inline
ooShortRef(oojDate)::ooShortRefStructor(oojDate)(const oojDate *  fromObject)
{
  *this = fromObject;
}
#else // !defined(OO_BUGGY_TEMPLATES)
inline
ooShortRef(oojDate)::ooShortRefStructor(oojDate)(const oojDate *  fromObject) :
    ooShortRef(ooObj)(ooReinterpretCast(const ooObj *,fromObject))
{
}
#endif // !defined(OO_BUGGY_TEMPLATES)


/* methods on ooHandle(oojDate) */
inline
ooHandle(oojDate)::ooHandleStructor(oojDate)()
{
}
inline
ooHandle(oojDate)::ooHandleStructor(oojDate)(const ooHandle(oojDate) &  objH) :
#ifdef OO_BUGGY_TEMPLATES
    ooHandle_superclass<oojDate >(objH)
#else // !defined(OO_BUGGY_TEMPLATES)
    ooHandle(ooObj)(objH)
#endif // !defined(OO_BUGGY_TEMPLATES)
{
}
inline
ooHandle(oojDate)::ooHandleStructor(oojDate)(const ooRef(oojDate) &  id) :
#ifdef OO_BUGGY_TEMPLATES
    ooHandle_superclass<oojDate >(id)
#else // !defined(OO_BUGGY_TEMPLATES)
    ooHandle(ooObj)(id)
#endif // !defined(OO_BUGGY_TEMPLATES)
{
}
inline
ooHandle(oojDate)::ooHandleStructor(oojDate)(const oojDate *  fromObject) :
#ifdef OO_BUGGY_TEMPLATES
    ooHandle_superclass<oojDate >(ooReinterpretCast(const ooObj *,fromObject))
#else // !defined(OO_BUGGY_TEMPLATES)
    ooHandle(ooObj)(ooReinterpretCast(const ooObj *,fromObject))
#endif // !defined(OO_BUGGY_TEMPLATES)
{
}
inline
ooHandle(oojDate)&
ooHandle(oojDate)::operator=(const ooRef(oojDate) &  id)
{
  this->ooHandle(ooObj)::operator=(id);
  return *this;
}
inline
ooHandle(oojDate)&
ooHandle(oojDate)::operator=(const ooHandle(oojDate) &  objH)
{
  this->ooHandle(ooObj)::operator=(objH);
  return *this;
}
inline
ooHandle(oojDate)&
ooHandle(oojDate)::operator=(const ooShortRef(oojDate) &  shortId)
{
  this->ooHandle(ooObj)::operator=(shortId);
  return *this;
}
inline
ooHandle(oojDate)&
ooHandle(oojDate)::operator=(const oojDate *  fromObject)
{
  this->ooHandle(ooObj)::operator=(ooReinterpretCast(const ooObj *,fromObject));
  return *this;
}
inline
oojDate *
ooHandle(oojDate)::pin(ooMode  openMode) const
{
  return ooReinterpretCast(oojDate *, this->pin_obj_internal(openMode));
}
inline
oojDate *
ooHandle(oojDate)::operator->() const
{
  return this->vm();
}
inline
oojDate &
ooHandle(oojDate)::operator*() const
{
  return *(this->vm());
}
inline
ooHandle(oojDate)::operator oojDate *() const
{
  if ( _state == oocHandlePTR  )
    return ooReinterpretCast(oojDate *, _ptr._obj);
  else return ooReinterpretCast(oojDate *, this->get_vm());
}
inline
oojDate *
ooHandle(oojDate)::vm() const
{
  if ( _state == oocHandlePTR && _ptr._obj != NULL )
    return ooReinterpretCast(oojDate *, _ptr._obj);
  else return ooReinterpretCast(oojDate *, this->get_vm());
}
inline
ooRef(oojDate) &
ooHandle(oojDate)::copy(const ooHandle(ooObj) &  nearH,
		   ooRef(oojDate) &              result) const
{
  this->ooHandle(ooObj)::copy(nearH, result);
  return result;
}


/* ODMG methods */
inline
oojDate *
ooRef(oojDate)::ptr() const
{
  return this->pin();
}
inline
oojDate *
ooHandle(oojDate)::ptr() const
{
  return this->operator oojDate *();
}
class oojTime;


/////////////////////////////////////////////////////////////////////////////

ooTemplateSpecialization
class ooDeref(oojTime) : public ooDerefBase {
	friend class ooRef(oojTime);
  public:
    ~ooDerefStructor(oojTime)();
    inline oojTime *operator->() const;
#ifndef OO_BUGGY_TEMPLATES
  private:
#endif // !defined(OO_BUGGY_TEMPLATES)
    ooDerefStructor(oojTime)(ooDeref(oojTime)& deref);
    ooDerefStructor(oojTime)(ooObj *  fromObject);
};


#ifdef OO_BUGGY_TEMPLATES

class ooHandle_superclass<oojTime > : public ooHandle(ooObj) {
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

class ooShortRef_superclass<oojTime > : public ooShortRef(ooObj) {
};

#endif // OO_BUGGY_TEMPLATES

ooTemplateSpecialization
class ooRef(oojTime) : public ooRef(ooObj) {
  public:
    ooRefStructor(oojTime)()
      {}
    ooRefStructor(oojTime)(const ooRef(oojTime)& id) :
	  ooRef(ooObj)(id)
      {}
    inline ooRefStructor(oojTime)(const ooHandleSuper(oojTime)& objH);
    inline ooRefStructor(oojTime)(const oojTime *  fromObject);
    inline ooRef(oojTime)& operator=(const ooRef(oojTime)& id);
    inline ooRef(oojTime)& operator=(const ooShortRefSuper(oojTime) &shortId);
    inline ooRef(oojTime)& operator=(const ooHandleSuper(oojTime)& objH);
    inline ooRef(oojTime)& operator=(const oojTime *  fromObject);
    ooStatus lookupObj(const ooHandle(ooObj)& scopeH,
		       const ooKey& key,
		       ooMode openMode = oocRead);
    ooStatus lookupObj(const ooHandle(ooObj)& scopeH,
		       const char* name,
		       ooMode openMode = oocRead);
#ifndef OO_BUGGY_TEMPLATES
    inline ooRef(oojTime)& copy(const ooHandle(ooObj)& nearH,
		    ooRef(oojTime)& newObjRef) const;
    inline ooHandle(oojTime)& copy(const ooHandle(ooObj)& nearH,
			ooHandle(oojTime)& result) const;
    inline ooHandle(oojTime) copy(const ooHandle(ooObj)& nearH) const;
#endif // !defined(OO_BUGGY_TEMPLATES)
    inline oojTime *pin(ooMode openMode = oocRead) const;
    ooDeref(oojTime) operator->() const;
    /* Use pin() or use ooHandle "operator oojTime *" instead of vm. */
    /* OBSOLETE */ inline oojTime *vm(ooMode openMode = oocRead) const;
    // ODMG methods:
    ooRefStructor(oojTime)(const d_Ref_Any &from);
    oojTime *ptr() const;
};

ooTemplateSpecialization
class ooShortRef(oojTime) :
#ifdef OO_BUGGY_TEMPLATES
			public ooShortRef_superclass<oojTime >
#else // !defined(OO_BUGGY_TEMPLATES)
			public ooShortRef(ooObj)
#endif // !defined(OO_BUGGY_TEMPLATES)
					            {
  public:
    ooShortRefStructor(oojTime)();
    ooShortRefStructor(oojTime)(const ooShortRef(oojTime)& shortId);
    ooShortRefStructor(oojTime)(const ooRef(oojTime)& id);
    ooShortRefStructor(oojTime)(const ooHandleSuper(oojTime) &objH);
    ooShortRefStructor(oojTime)(const oojTime *  fromObject);
    ooShortRef(oojTime)& operator=(const ooShortRef(oojTime)& shortId);
    ooShortRef(oojTime)& operator=(const ooRef(oojTime)& id);
    ooShortRef(oojTime)& operator=(const ooHandleSuper(oojTime) &objH);
    ooShortRef(oojTime)& operator=(const oojTime *  fromObject);
};

ooTemplateSpecialization
class ooHandle(oojTime) :
#ifdef OO_BUGGY_TEMPLATES
		      public ooHandle_superclass<oojTime >
#else // !defined(OO_BUGGY_TEMPLATES)
		      public ooHandle(ooObj)
#endif // !defined(OO_BUGGY_TEMPLATES)
                                                {
  public:
    inline ooHandleStructor(oojTime)();
    inline ooHandleStructor(oojTime)(const ooRef(oojTime)& id);
    inline ooHandleStructor(oojTime)(const ooHandle(oojTime)& objH);
    inline ooHandleStructor(oojTime)(const oojTime *  fromObject);
    inline ooHandle(oojTime)& operator=(const ooRef(oojTime)& id);
    inline ooHandle(oojTime)& operator=(const ooHandle(oojTime)& objH);
    inline ooHandle(oojTime)& operator=(const ooShortRef(oojTime)& shortId);
    inline ooHandle(oojTime)& operator=(const oojTime *  fromObject);
    ooStatus lookupObj(const ooHandle(ooObj)& scopeH,
		       const ooKey& key,
		       ooMode openMode = oocRead);
    ooStatus lookupObj(const ooHandle(ooObj)& scopeH,
		       const char* name,
		       ooMode openMode = oocRead);
    ooHandle(oojTime)& copy(const ooHandle(ooObj)& nearH,
		       ooHandle(oojTime)& result) const;
    inline ooRef(oojTime)& copy(const ooHandle(ooObj)& nearH,
		    ooRef(oojTime)& result) const;
    ooHandle(oojTime) copy(const ooHandle(ooObj)& nearH) const;
    inline oojTime *pin(ooMode openMode = oocRead) const;
    inline oojTime *operator->() const;
    inline oojTime &operator*() const;
    inline operator oojTime *() const;
    /* Use "operator oojTime *" instead of vm. */
    /* OBSOLETE */ inline oojTime *vm() const;
    // ODMG methods:
    ooHandleStructor(oojTime)(const d_Ref_Any &from);
    oojTime *ptr() const;
};

ooTemplateSpecialization
class ooItr(oojTime) : public ooHandle(oojTime),
		    public ooIteratorObjOrContObj {
  public:
    ooItrStructor(oojTime)();
    ~ooItrStructor(oojTime)();
  private:
    // Defined only to prevent implicit definition:
    ooItrStructor(oojTime)(ooItr(oojTime)&);
    ooItr(oojTime)    operator=(ooItr(oojTime)&);
};


/* methods on ooDeref(oojTime) */
inline
ooDeref(oojTime)::ooDerefStructor(oojTime)(ooDeref(oojTime) &  deref) :
    ooDerefBase(deref.vm())
{
  this->pinCompensate();
}
inline
ooDeref(oojTime)::ooDerefStructor(oojTime)(ooObj *  fromObject) :
    ooDerefBase(fromObject)
{
}
inline
ooDeref(oojTime)::~ooDerefStructor(oojTime)()
{
}
inline
oojTime *
ooDeref(oojTime)::operator->() const
{
  return ooReinterpretCast(oojTime *, this->vm());
}


/* methods on ooRef(oojTime) */
inline
ooRef(oojTime)::ooRefStructor(oojTime)(const ooHandleSuper(oojTime)& objH) :
    ooRef(ooObj)(objH)
{
}
inline
ooRef(oojTime)::ooRefStructor(oojTime)(const oojTime *  fromObject) :
    ooRef(ooObj)(ooReinterpretCast(const ooObj *, fromObject))
{
}
inline
ooRef(oojTime)&
ooRef(oojTime)::operator=(const ooRef(oojTime) &  id)
{
  this->ooId::operator=(id);
  return *this;
}
inline
ooRef(oojTime)&
ooRef(oojTime)::operator=(const ooShortRefSuper(oojTime) &  shortId)
{
  this->ooRef(ooObj)::operator=(shortId);
  return *this;
}
inline
ooRef(oojTime)&
ooRef(oojTime)::operator=(const ooHandleSuper(oojTime) &  objH)
{
  this->ooRef(ooObj)::operator=(objH);
  return *this;
}
inline
ooRef(oojTime)&
ooRef(oojTime)::operator=(const oojTime *  fromObject)
{
  this->ooRef(ooObj)::operator=(ooReinterpretCast(const ooObj *, fromObject));
  return *this;
}
inline
oojTime *
ooRef(oojTime)::pin(ooMode  openMode) const
{
  return ooReinterpretCast(oojTime *, this->pin_ref_internal(openMode));
}
inline
oojTime *
ooRef(oojTime)::vm(ooMode  openMode) const
{
  return this->pin(openMode);
}
#ifndef OO_BUGGY_TEMPLATES
inline
ooHandle(oojTime) &
ooRef(oojTime)::copy(const ooHandle(ooObj) &  nearH,
		ooHandle(oojTime) &           result) const
{
  this->ooRef(ooObj)::copy(nearH, result);
  return result;
}
inline
ooRef(oojTime) &
ooRef(oojTime)::copy(const ooHandle(ooObj) &  nearH,
		ooRef(oojTime) &              newObjRef) const
{
  this->ooRef(ooObj)::copy(nearH, newObjRef);
  return newObjRef;
}
inline
ooHandle(oojTime)
ooRef(oojTime)::copy(const ooHandle(ooObj) &  nearH) const
{
  ooHandle(oojTime) result;
  this->ooRef(ooObj)::copy(nearH, result);
  return result;
}
#endif // !defined(OO_BUGGY_TEMPLATES)
inline
ooDeref(oojTime)
ooRef(oojTime)::operator->() const
{
  ooDeref(oojTime) result(this->pin_ref_internal(oocRead));
  return result;
}


/* methods on ooShortRef(oojTime) */
inline
ooShortRef(oojTime) &
ooShortRef(oojTime)::operator=(const ooShortRef(oojTime) &  shortId)
{
  this->ooShortId::operator=(shortId);
  return *this;
}
inline
ooShortRef(oojTime) &
ooShortRef(oojTime)::operator=(const ooRef(oojTime) &  id)
{
  this->ooShortId::operator=(id);
  return *this;
}
inline
ooShortRef(oojTime) &
ooShortRef(oojTime)::operator=(const ooHandleSuper(oojTime) &  objH)
{
  this->ooShortId::operator=(objH);
  return *this;
}
inline
ooShortRef(oojTime)&
ooShortRef(oojTime)::operator=(const oojTime *  fromObject)
{
  this->ooShortId::operator=(ooReinterpretCast(const ooObj *,fromObject));
  return *this;
}
inline
ooShortRef(oojTime)::ooShortRefStructor(oojTime)()
{
}
#ifdef OO_BUGGY_TEMPLATES
inline
ooShortRef(oojTime)::ooShortRefStructor(oojTime)(const ooShortRef(oojTime) &  shortId)
{
  *this = shortId;
}
#else // !defined(OO_BUGGY_TEMPLATES)
inline
ooShortRef(oojTime)::ooShortRefStructor(oojTime)(const ooShortRef(oojTime) &  shortId) :
    ooShortRef(ooObj)(shortId)
{
}
#endif // !defined(OO_BUGGY_TEMPLATES)
#ifdef OO_BUGGY_TEMPLATES
inline
ooShortRef(oojTime)::ooShortRefStructor(oojTime)(const ooRef(oojTime) &  id)
{
  *this = id;
}
#else // !defined(OO_BUGGY_TEMPLATES)
inline
ooShortRef(oojTime)::ooShortRefStructor(oojTime)(const ooRef(oojTime) &  id) :
    ooShortRef(ooObj)(id)
{
}
#endif // !defined(OO_BUGGY_TEMPLATES)
#ifdef OO_BUGGY_TEMPLATES
inline
ooShortRef(oojTime)::ooShortRefStructor(oojTime)(const ooHandleSuper(oojTime) &  objH)
{
  *this = objH;
}
#else // !defined(OO_BUGGY_TEMPLATES)
inline
ooShortRef(oojTime)::ooShortRefStructor(oojTime)(const ooHandleSuper(oojTime) &  objH) :
    ooShortRef(ooObj)(objH)
{
}
#endif // !defined(OO_BUGGY_TEMPLATES)
#ifdef OO_BUGGY_TEMPLATES
inline
ooShortRef(oojTime)::ooShortRefStructor(oojTime)(const oojTime *  fromObject)
{
  *this = fromObject;
}
#else // !defined(OO_BUGGY_TEMPLATES)
inline
ooShortRef(oojTime)::ooShortRefStructor(oojTime)(const oojTime *  fromObject) :
    ooShortRef(ooObj)(ooReinterpretCast(const ooObj *,fromObject))
{
}
#endif // !defined(OO_BUGGY_TEMPLATES)


/* methods on ooHandle(oojTime) */
inline
ooHandle(oojTime)::ooHandleStructor(oojTime)()
{
}
inline
ooHandle(oojTime)::ooHandleStructor(oojTime)(const ooHandle(oojTime) &  objH) :
#ifdef OO_BUGGY_TEMPLATES
    ooHandle_superclass<oojTime >(objH)
#else // !defined(OO_BUGGY_TEMPLATES)
    ooHandle(ooObj)(objH)
#endif // !defined(OO_BUGGY_TEMPLATES)
{
}
inline
ooHandle(oojTime)::ooHandleStructor(oojTime)(const ooRef(oojTime) &  id) :
#ifdef OO_BUGGY_TEMPLATES
    ooHandle_superclass<oojTime >(id)
#else // !defined(OO_BUGGY_TEMPLATES)
    ooHandle(ooObj)(id)
#endif // !defined(OO_BUGGY_TEMPLATES)
{
}
inline
ooHandle(oojTime)::ooHandleStructor(oojTime)(const oojTime *  fromObject) :
#ifdef OO_BUGGY_TEMPLATES
    ooHandle_superclass<oojTime >(ooReinterpretCast(const ooObj *,fromObject))
#else // !defined(OO_BUGGY_TEMPLATES)
    ooHandle(ooObj)(ooReinterpretCast(const ooObj *,fromObject))
#endif // !defined(OO_BUGGY_TEMPLATES)
{
}
inline
ooHandle(oojTime)&
ooHandle(oojTime)::operator=(const ooRef(oojTime) &  id)
{
  this->ooHandle(ooObj)::operator=(id);
  return *this;
}
inline
ooHandle(oojTime)&
ooHandle(oojTime)::operator=(const ooHandle(oojTime) &  objH)
{
  this->ooHandle(ooObj)::operator=(objH);
  return *this;
}
inline
ooHandle(oojTime)&
ooHandle(oojTime)::operator=(const ooShortRef(oojTime) &  shortId)
{
  this->ooHandle(ooObj)::operator=(shortId);
  return *this;
}
inline
ooHandle(oojTime)&
ooHandle(oojTime)::operator=(const oojTime *  fromObject)
{
  this->ooHandle(ooObj)::operator=(ooReinterpretCast(const ooObj *,fromObject));
  return *this;
}
inline
oojTime *
ooHandle(oojTime)::pin(ooMode  openMode) const
{
  return ooReinterpretCast(oojTime *, this->pin_obj_internal(openMode));
}
inline
oojTime *
ooHandle(oojTime)::operator->() const
{
  return this->vm();
}
inline
oojTime &
ooHandle(oojTime)::operator*() const
{
  return *(this->vm());
}
inline
ooHandle(oojTime)::operator oojTime *() const
{
  if ( _state == oocHandlePTR  )
    return ooReinterpretCast(oojTime *, _ptr._obj);
  else return ooReinterpretCast(oojTime *, this->get_vm());
}
inline
oojTime *
ooHandle(oojTime)::vm() const
{
  if ( _state == oocHandlePTR && _ptr._obj != NULL )
    return ooReinterpretCast(oojTime *, _ptr._obj);
  else return ooReinterpretCast(oojTime *, this->get_vm());
}
inline
ooRef(oojTime) &
ooHandle(oojTime)::copy(const ooHandle(ooObj) &  nearH,
		   ooRef(oojTime) &              result) const
{
  this->ooHandle(ooObj)::copy(nearH, result);
  return result;
}


/* ODMG methods */
inline
oojTime *
ooRef(oojTime)::ptr() const
{
  return this->pin();
}
inline
oojTime *
ooHandle(oojTime)::ptr() const
{
  return this->operator oojTime *();
}
class oojTimestamp;


/////////////////////////////////////////////////////////////////////////////

ooTemplateSpecialization
class ooDeref(oojTimestamp) : public ooDerefBase {
	friend class ooRef(oojTimestamp);
  public:
    ~ooDerefStructor(oojTimestamp)();
    inline oojTimestamp *operator->() const;
#ifndef OO_BUGGY_TEMPLATES
  private:
#endif // !defined(OO_BUGGY_TEMPLATES)
    ooDerefStructor(oojTimestamp)(ooDeref(oojTimestamp)& deref);
    ooDerefStructor(oojTimestamp)(ooObj *  fromObject);
};


#ifdef OO_BUGGY_TEMPLATES

class ooHandle_superclass<oojTimestamp > : public ooHandle(ooObj) {
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

class ooShortRef_superclass<oojTimestamp > : public ooShortRef(ooObj) {
};

#endif // OO_BUGGY_TEMPLATES

ooTemplateSpecialization
class ooRef(oojTimestamp) : public ooRef(ooObj) {
  public:
    ooRefStructor(oojTimestamp)()
      {}
    ooRefStructor(oojTimestamp)(const ooRef(oojTimestamp)& id) :
	  ooRef(ooObj)(id)
      {}
    inline ooRefStructor(oojTimestamp)(const ooHandleSuper(oojTimestamp)& objH);
    inline ooRefStructor(oojTimestamp)(const oojTimestamp *  fromObject);
    inline ooRef(oojTimestamp)& operator=(const ooRef(oojTimestamp)& id);
    inline ooRef(oojTimestamp)& operator=(const ooShortRefSuper(oojTimestamp) &shortId);
    inline ooRef(oojTimestamp)& operator=(const ooHandleSuper(oojTimestamp)& objH);
    inline ooRef(oojTimestamp)& operator=(const oojTimestamp *  fromObject);
    ooStatus lookupObj(const ooHandle(ooObj)& scopeH,
		       const ooKey& key,
		       ooMode openMode = oocRead);
    ooStatus lookupObj(const ooHandle(ooObj)& scopeH,
		       const char* name,
		       ooMode openMode = oocRead);
#ifndef OO_BUGGY_TEMPLATES
    inline ooRef(oojTimestamp)& copy(const ooHandle(ooObj)& nearH,
		    ooRef(oojTimestamp)& newObjRef) const;
    inline ooHandle(oojTimestamp)& copy(const ooHandle(ooObj)& nearH,
			ooHandle(oojTimestamp)& result) const;
    inline ooHandle(oojTimestamp) copy(const ooHandle(ooObj)& nearH) const;
#endif // !defined(OO_BUGGY_TEMPLATES)
    inline oojTimestamp *pin(ooMode openMode = oocRead) const;
    ooDeref(oojTimestamp) operator->() const;
    /* Use pin() or use ooHandle "operator oojTimestamp *" instead of vm. */
    /* OBSOLETE */ inline oojTimestamp *vm(ooMode openMode = oocRead) const;
    // ODMG methods:
    ooRefStructor(oojTimestamp)(const d_Ref_Any &from);
    oojTimestamp *ptr() const;
};

ooTemplateSpecialization
class ooShortRef(oojTimestamp) :
#ifdef OO_BUGGY_TEMPLATES
			public ooShortRef_superclass<oojTimestamp >
#else // !defined(OO_BUGGY_TEMPLATES)
			public ooShortRef(ooObj)
#endif // !defined(OO_BUGGY_TEMPLATES)
					            {
  public:
    ooShortRefStructor(oojTimestamp)();
    ooShortRefStructor(oojTimestamp)(const ooShortRef(oojTimestamp)& shortId);
    ooShortRefStructor(oojTimestamp)(const ooRef(oojTimestamp)& id);
    ooShortRefStructor(oojTimestamp)(const ooHandleSuper(oojTimestamp) &objH);
    ooShortRefStructor(oojTimestamp)(const oojTimestamp *  fromObject);
    ooShortRef(oojTimestamp)& operator=(const ooShortRef(oojTimestamp)& shortId);
    ooShortRef(oojTimestamp)& operator=(const ooRef(oojTimestamp)& id);
    ooShortRef(oojTimestamp)& operator=(const ooHandleSuper(oojTimestamp) &objH);
    ooShortRef(oojTimestamp)& operator=(const oojTimestamp *  fromObject);
};

ooTemplateSpecialization
class ooHandle(oojTimestamp) :
#ifdef OO_BUGGY_TEMPLATES
		      public ooHandle_superclass<oojTimestamp >
#else // !defined(OO_BUGGY_TEMPLATES)
		      public ooHandle(ooObj)
#endif // !defined(OO_BUGGY_TEMPLATES)
                                                {
  public:
    inline ooHandleStructor(oojTimestamp)();
    inline ooHandleStructor(oojTimestamp)(const ooRef(oojTimestamp)& id);
    inline ooHandleStructor(oojTimestamp)(const ooHandle(oojTimestamp)& objH);
    inline ooHandleStructor(oojTimestamp)(const oojTimestamp *  fromObject);
    inline ooHandle(oojTimestamp)& operator=(const ooRef(oojTimestamp)& id);
    inline ooHandle(oojTimestamp)& operator=(const ooHandle(oojTimestamp)& objH);
    inline ooHandle(oojTimestamp)& operator=(const ooShortRef(oojTimestamp)& shortId);
    inline ooHandle(oojTimestamp)& operator=(const oojTimestamp *  fromObject);
    ooStatus lookupObj(const ooHandle(ooObj)& scopeH,
		       const ooKey& key,
		       ooMode openMode = oocRead);
    ooStatus lookupObj(const ooHandle(ooObj)& scopeH,
		       const char* name,
		       ooMode openMode = oocRead);
    ooHandle(oojTimestamp)& copy(const ooHandle(ooObj)& nearH,
		       ooHandle(oojTimestamp)& result) const;
    inline ooRef(oojTimestamp)& copy(const ooHandle(ooObj)& nearH,
		    ooRef(oojTimestamp)& result) const;
    ooHandle(oojTimestamp) copy(const ooHandle(ooObj)& nearH) const;
    inline oojTimestamp *pin(ooMode openMode = oocRead) const;
    inline oojTimestamp *operator->() const;
    inline oojTimestamp &operator*() const;
    inline operator oojTimestamp *() const;
    /* Use "operator oojTimestamp *" instead of vm. */
    /* OBSOLETE */ inline oojTimestamp *vm() const;
    // ODMG methods:
    ooHandleStructor(oojTimestamp)(const d_Ref_Any &from);
    oojTimestamp *ptr() const;
};

ooTemplateSpecialization
class ooItr(oojTimestamp) : public ooHandle(oojTimestamp),
		    public ooIteratorObjOrContObj {
  public:
    ooItrStructor(oojTimestamp)();
    ~ooItrStructor(oojTimestamp)();
  private:
    // Defined only to prevent implicit definition:
    ooItrStructor(oojTimestamp)(ooItr(oojTimestamp)&);
    ooItr(oojTimestamp)    operator=(ooItr(oojTimestamp)&);
};


/* methods on ooDeref(oojTimestamp) */
inline
ooDeref(oojTimestamp)::ooDerefStructor(oojTimestamp)(ooDeref(oojTimestamp) &  deref) :
    ooDerefBase(deref.vm())
{
  this->pinCompensate();
}
inline
ooDeref(oojTimestamp)::ooDerefStructor(oojTimestamp)(ooObj *  fromObject) :
    ooDerefBase(fromObject)
{
}
inline
ooDeref(oojTimestamp)::~ooDerefStructor(oojTimestamp)()
{
}
inline
oojTimestamp *
ooDeref(oojTimestamp)::operator->() const
{
  return ooReinterpretCast(oojTimestamp *, this->vm());
}


/* methods on ooRef(oojTimestamp) */
inline
ooRef(oojTimestamp)::ooRefStructor(oojTimestamp)(const ooHandleSuper(oojTimestamp)& objH) :
    ooRef(ooObj)(objH)
{
}
inline
ooRef(oojTimestamp)::ooRefStructor(oojTimestamp)(const oojTimestamp *  fromObject) :
    ooRef(ooObj)(ooReinterpretCast(const ooObj *, fromObject))
{
}
inline
ooRef(oojTimestamp)&
ooRef(oojTimestamp)::operator=(const ooRef(oojTimestamp) &  id)
{
  this->ooId::operator=(id);
  return *this;
}
inline
ooRef(oojTimestamp)&
ooRef(oojTimestamp)::operator=(const ooShortRefSuper(oojTimestamp) &  shortId)
{
  this->ooRef(ooObj)::operator=(shortId);
  return *this;
}
inline
ooRef(oojTimestamp)&
ooRef(oojTimestamp)::operator=(const ooHandleSuper(oojTimestamp) &  objH)
{
  this->ooRef(ooObj)::operator=(objH);
  return *this;
}
inline
ooRef(oojTimestamp)&
ooRef(oojTimestamp)::operator=(const oojTimestamp *  fromObject)
{
  this->ooRef(ooObj)::operator=(ooReinterpretCast(const ooObj *, fromObject));
  return *this;
}
inline
oojTimestamp *
ooRef(oojTimestamp)::pin(ooMode  openMode) const
{
  return ooReinterpretCast(oojTimestamp *, this->pin_ref_internal(openMode));
}
inline
oojTimestamp *
ooRef(oojTimestamp)::vm(ooMode  openMode) const
{
  return this->pin(openMode);
}
#ifndef OO_BUGGY_TEMPLATES
inline
ooHandle(oojTimestamp) &
ooRef(oojTimestamp)::copy(const ooHandle(ooObj) &  nearH,
		ooHandle(oojTimestamp) &           result) const
{
  this->ooRef(ooObj)::copy(nearH, result);
  return result;
}
inline
ooRef(oojTimestamp) &
ooRef(oojTimestamp)::copy(const ooHandle(ooObj) &  nearH,
		ooRef(oojTimestamp) &              newObjRef) const
{
  this->ooRef(ooObj)::copy(nearH, newObjRef);
  return newObjRef;
}
inline
ooHandle(oojTimestamp)
ooRef(oojTimestamp)::copy(const ooHandle(ooObj) &  nearH) const
{
  ooHandle(oojTimestamp) result;
  this->ooRef(ooObj)::copy(nearH, result);
  return result;
}
#endif // !defined(OO_BUGGY_TEMPLATES)
inline
ooDeref(oojTimestamp)
ooRef(oojTimestamp)::operator->() const
{
  ooDeref(oojTimestamp) result(this->pin_ref_internal(oocRead));
  return result;
}


/* methods on ooShortRef(oojTimestamp) */
inline
ooShortRef(oojTimestamp) &
ooShortRef(oojTimestamp)::operator=(const ooShortRef(oojTimestamp) &  shortId)
{
  this->ooShortId::operator=(shortId);
  return *this;
}
inline
ooShortRef(oojTimestamp) &
ooShortRef(oojTimestamp)::operator=(const ooRef(oojTimestamp) &  id)
{
  this->ooShortId::operator=(id);
  return *this;
}
inline
ooShortRef(oojTimestamp) &
ooShortRef(oojTimestamp)::operator=(const ooHandleSuper(oojTimestamp) &  objH)
{
  this->ooShortId::operator=(objH);
  return *this;
}
inline
ooShortRef(oojTimestamp)&
ooShortRef(oojTimestamp)::operator=(const oojTimestamp *  fromObject)
{
  this->ooShortId::operator=(ooReinterpretCast(const ooObj *,fromObject));
  return *this;
}
inline
ooShortRef(oojTimestamp)::ooShortRefStructor(oojTimestamp)()
{
}
#ifdef OO_BUGGY_TEMPLATES
inline
ooShortRef(oojTimestamp)::ooShortRefStructor(oojTimestamp)(const ooShortRef(oojTimestamp) &  shortId)
{
  *this = shortId;
}
#else // !defined(OO_BUGGY_TEMPLATES)
inline
ooShortRef(oojTimestamp)::ooShortRefStructor(oojTimestamp)(const ooShortRef(oojTimestamp) &  shortId) :
    ooShortRef(ooObj)(shortId)
{
}
#endif // !defined(OO_BUGGY_TEMPLATES)
#ifdef OO_BUGGY_TEMPLATES
inline
ooShortRef(oojTimestamp)::ooShortRefStructor(oojTimestamp)(const ooRef(oojTimestamp) &  id)
{
  *this = id;
}
#else // !defined(OO_BUGGY_TEMPLATES)
inline
ooShortRef(oojTimestamp)::ooShortRefStructor(oojTimestamp)(const ooRef(oojTimestamp) &  id) :
    ooShortRef(ooObj)(id)
{
}
#endif // !defined(OO_BUGGY_TEMPLATES)
#ifdef OO_BUGGY_TEMPLATES
inline
ooShortRef(oojTimestamp)::ooShortRefStructor(oojTimestamp)(const ooHandleSuper(oojTimestamp) &  objH)
{
  *this = objH;
}
#else // !defined(OO_BUGGY_TEMPLATES)
inline
ooShortRef(oojTimestamp)::ooShortRefStructor(oojTimestamp)(const ooHandleSuper(oojTimestamp) &  objH) :
    ooShortRef(ooObj)(objH)
{
}
#endif // !defined(OO_BUGGY_TEMPLATES)
#ifdef OO_BUGGY_TEMPLATES
inline
ooShortRef(oojTimestamp)::ooShortRefStructor(oojTimestamp)(const oojTimestamp *  fromObject)
{
  *this = fromObject;
}
#else // !defined(OO_BUGGY_TEMPLATES)
inline
ooShortRef(oojTimestamp)::ooShortRefStructor(oojTimestamp)(const oojTimestamp *  fromObject) :
    ooShortRef(ooObj)(ooReinterpretCast(const ooObj *,fromObject))
{
}
#endif // !defined(OO_BUGGY_TEMPLATES)


/* methods on ooHandle(oojTimestamp) */
inline
ooHandle(oojTimestamp)::ooHandleStructor(oojTimestamp)()
{
}
inline
ooHandle(oojTimestamp)::ooHandleStructor(oojTimestamp)(const ooHandle(oojTimestamp) &  objH) :
#ifdef OO_BUGGY_TEMPLATES
    ooHandle_superclass<oojTimestamp >(objH)
#else // !defined(OO_BUGGY_TEMPLATES)
    ooHandle(ooObj)(objH)
#endif // !defined(OO_BUGGY_TEMPLATES)
{
}
inline
ooHandle(oojTimestamp)::ooHandleStructor(oojTimestamp)(const ooRef(oojTimestamp) &  id) :
#ifdef OO_BUGGY_TEMPLATES
    ooHandle_superclass<oojTimestamp >(id)
#else // !defined(OO_BUGGY_TEMPLATES)
    ooHandle(ooObj)(id)
#endif // !defined(OO_BUGGY_TEMPLATES)
{
}
inline
ooHandle(oojTimestamp)::ooHandleStructor(oojTimestamp)(const oojTimestamp *  fromObject) :
#ifdef OO_BUGGY_TEMPLATES
    ooHandle_superclass<oojTimestamp >(ooReinterpretCast(const ooObj *,fromObject))
#else // !defined(OO_BUGGY_TEMPLATES)
    ooHandle(ooObj)(ooReinterpretCast(const ooObj *,fromObject))
#endif // !defined(OO_BUGGY_TEMPLATES)
{
}
inline
ooHandle(oojTimestamp)&
ooHandle(oojTimestamp)::operator=(const ooRef(oojTimestamp) &  id)
{
  this->ooHandle(ooObj)::operator=(id);
  return *this;
}
inline
ooHandle(oojTimestamp)&
ooHandle(oojTimestamp)::operator=(const ooHandle(oojTimestamp) &  objH)
{
  this->ooHandle(ooObj)::operator=(objH);
  return *this;
}
inline
ooHandle(oojTimestamp)&
ooHandle(oojTimestamp)::operator=(const ooShortRef(oojTimestamp) &  shortId)
{
  this->ooHandle(ooObj)::operator=(shortId);
  return *this;
}
inline
ooHandle(oojTimestamp)&
ooHandle(oojTimestamp)::operator=(const oojTimestamp *  fromObject)
{
  this->ooHandle(ooObj)::operator=(ooReinterpretCast(const ooObj *,fromObject));
  return *this;
}
inline
oojTimestamp *
ooHandle(oojTimestamp)::pin(ooMode  openMode) const
{
  return ooReinterpretCast(oojTimestamp *, this->pin_obj_internal(openMode));
}
inline
oojTimestamp *
ooHandle(oojTimestamp)::operator->() const
{
  return this->vm();
}
inline
oojTimestamp &
ooHandle(oojTimestamp)::operator*() const
{
  return *(this->vm());
}
inline
ooHandle(oojTimestamp)::operator oojTimestamp *() const
{
  if ( _state == oocHandlePTR  )
    return ooReinterpretCast(oojTimestamp *, _ptr._obj);
  else return ooReinterpretCast(oojTimestamp *, this->get_vm());
}
inline
oojTimestamp *
ooHandle(oojTimestamp)::vm() const
{
  if ( _state == oocHandlePTR && _ptr._obj != NULL )
    return ooReinterpretCast(oojTimestamp *, _ptr._obj);
  else return ooReinterpretCast(oojTimestamp *, this->get_vm());
}
inline
ooRef(oojTimestamp) &
ooHandle(oojTimestamp)::copy(const ooHandle(ooObj) &  nearH,
		   ooRef(oojTimestamp) &              result) const
{
  this->ooHandle(ooObj)::copy(nearH, result);
  return result;
}


/* ODMG methods */
inline
oojTimestamp *
ooRef(oojTimestamp)::ptr() const
{
  return this->pin();
}
inline
oojTimestamp *
ooHandle(oojTimestamp)::ptr() const
{
  return this->operator oojTimestamp *();
}
class oojArray;


/////////////////////////////////////////////////////////////////////////////

ooTemplateSpecialization
class ooDeref(oojArray) : public ooDerefBase {
	friend class ooRef(oojArray);
  public:
    ~ooDerefStructor(oojArray)();
    inline oojArray *operator->() const;
#ifndef OO_BUGGY_TEMPLATES
  private:
#endif // !defined(OO_BUGGY_TEMPLATES)
    ooDerefStructor(oojArray)(ooDeref(oojArray)& deref);
    ooDerefStructor(oojArray)(ooObj *  fromObject);
};


#ifdef OO_BUGGY_TEMPLATES

class ooHandle_superclass<oojArray > : public ooHandle(ooObj) {
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

class ooShortRef_superclass<oojArray > : public ooShortRef(ooObj) {
};

#endif // OO_BUGGY_TEMPLATES

ooTemplateSpecialization
class ooRef(oojArray) : public ooRef(ooObj) {
  public:
    ooRefStructor(oojArray)()
      {}
    ooRefStructor(oojArray)(const ooRef(oojArray)& id) :
	  ooRef(ooObj)(id)
      {}
    inline ooRefStructor(oojArray)(const ooHandleSuper(oojArray)& objH);
    inline ooRefStructor(oojArray)(const oojArray *  fromObject);
    inline ooRef(oojArray)& operator=(const ooRef(oojArray)& id);
    inline ooRef(oojArray)& operator=(const ooShortRefSuper(oojArray) &shortId);
    inline ooRef(oojArray)& operator=(const ooHandleSuper(oojArray)& objH);
    inline ooRef(oojArray)& operator=(const oojArray *  fromObject);
    ooStatus lookupObj(const ooHandle(ooObj)& scopeH,
		       const ooKey& key,
		       ooMode openMode = oocRead);
    ooStatus lookupObj(const ooHandle(ooObj)& scopeH,
		       const char* name,
		       ooMode openMode = oocRead);
#ifndef OO_BUGGY_TEMPLATES
    inline ooRef(oojArray)& copy(const ooHandle(ooObj)& nearH,
		    ooRef(oojArray)& newObjRef) const;
    inline ooHandle(oojArray)& copy(const ooHandle(ooObj)& nearH,
			ooHandle(oojArray)& result) const;
    inline ooHandle(oojArray) copy(const ooHandle(ooObj)& nearH) const;
#endif // !defined(OO_BUGGY_TEMPLATES)
    inline oojArray *pin(ooMode openMode = oocRead) const;
    ooDeref(oojArray) operator->() const;
    /* Use pin() or use ooHandle "operator oojArray *" instead of vm. */
    /* OBSOLETE */ inline oojArray *vm(ooMode openMode = oocRead) const;
    // ODMG methods:
    ooRefStructor(oojArray)(const d_Ref_Any &from);
    oojArray *ptr() const;
};

ooTemplateSpecialization
class ooShortRef(oojArray) :
#ifdef OO_BUGGY_TEMPLATES
			public ooShortRef_superclass<oojArray >
#else // !defined(OO_BUGGY_TEMPLATES)
			public ooShortRef(ooObj)
#endif // !defined(OO_BUGGY_TEMPLATES)
					            {
  public:
    ooShortRefStructor(oojArray)();
    ooShortRefStructor(oojArray)(const ooShortRef(oojArray)& shortId);
    ooShortRefStructor(oojArray)(const ooRef(oojArray)& id);
    ooShortRefStructor(oojArray)(const ooHandleSuper(oojArray) &objH);
    ooShortRefStructor(oojArray)(const oojArray *  fromObject);
    ooShortRef(oojArray)& operator=(const ooShortRef(oojArray)& shortId);
    ooShortRef(oojArray)& operator=(const ooRef(oojArray)& id);
    ooShortRef(oojArray)& operator=(const ooHandleSuper(oojArray) &objH);
    ooShortRef(oojArray)& operator=(const oojArray *  fromObject);
};

ooTemplateSpecialization
class ooHandle(oojArray) :
#ifdef OO_BUGGY_TEMPLATES
		      public ooHandle_superclass<oojArray >
#else // !defined(OO_BUGGY_TEMPLATES)
		      public ooHandle(ooObj)
#endif // !defined(OO_BUGGY_TEMPLATES)
                                                {
  public:
    inline ooHandleStructor(oojArray)();
    inline ooHandleStructor(oojArray)(const ooRef(oojArray)& id);
    inline ooHandleStructor(oojArray)(const ooHandle(oojArray)& objH);
    inline ooHandleStructor(oojArray)(const oojArray *  fromObject);
    inline ooHandle(oojArray)& operator=(const ooRef(oojArray)& id);
    inline ooHandle(oojArray)& operator=(const ooHandle(oojArray)& objH);
    inline ooHandle(oojArray)& operator=(const ooShortRef(oojArray)& shortId);
    inline ooHandle(oojArray)& operator=(const oojArray *  fromObject);
    ooStatus lookupObj(const ooHandle(ooObj)& scopeH,
		       const ooKey& key,
		       ooMode openMode = oocRead);
    ooStatus lookupObj(const ooHandle(ooObj)& scopeH,
		       const char* name,
		       ooMode openMode = oocRead);
    ooHandle(oojArray)& copy(const ooHandle(ooObj)& nearH,
		       ooHandle(oojArray)& result) const;
    inline ooRef(oojArray)& copy(const ooHandle(ooObj)& nearH,
		    ooRef(oojArray)& result) const;
    ooHandle(oojArray) copy(const ooHandle(ooObj)& nearH) const;
    inline oojArray *pin(ooMode openMode = oocRead) const;
    inline oojArray *operator->() const;
    inline oojArray &operator*() const;
    inline operator oojArray *() const;
    /* Use "operator oojArray *" instead of vm. */
    /* OBSOLETE */ inline oojArray *vm() const;
    // ODMG methods:
    ooHandleStructor(oojArray)(const d_Ref_Any &from);
    oojArray *ptr() const;
};

ooTemplateSpecialization
class ooItr(oojArray) : public ooHandle(oojArray),
		    public ooIteratorObjOrContObj {
  public:
    ooItrStructor(oojArray)();
    ~ooItrStructor(oojArray)();
  private:
    // Defined only to prevent implicit definition:
    ooItrStructor(oojArray)(ooItr(oojArray)&);
    ooItr(oojArray)    operator=(ooItr(oojArray)&);
};


/* methods on ooDeref(oojArray) */
inline
ooDeref(oojArray)::ooDerefStructor(oojArray)(ooDeref(oojArray) &  deref) :
    ooDerefBase(deref.vm())
{
  this->pinCompensate();
}
inline
ooDeref(oojArray)::ooDerefStructor(oojArray)(ooObj *  fromObject) :
    ooDerefBase(fromObject)
{
}
inline
ooDeref(oojArray)::~ooDerefStructor(oojArray)()
{
}
inline
oojArray *
ooDeref(oojArray)::operator->() const
{
  return ooReinterpretCast(oojArray *, this->vm());
}


/* methods on ooRef(oojArray) */
inline
ooRef(oojArray)::ooRefStructor(oojArray)(const ooHandleSuper(oojArray)& objH) :
    ooRef(ooObj)(objH)
{
}
inline
ooRef(oojArray)::ooRefStructor(oojArray)(const oojArray *  fromObject) :
    ooRef(ooObj)(ooReinterpretCast(const ooObj *, fromObject))
{
}
inline
ooRef(oojArray)&
ooRef(oojArray)::operator=(const ooRef(oojArray) &  id)
{
  this->ooId::operator=(id);
  return *this;
}
inline
ooRef(oojArray)&
ooRef(oojArray)::operator=(const ooShortRefSuper(oojArray) &  shortId)
{
  this->ooRef(ooObj)::operator=(shortId);
  return *this;
}
inline
ooRef(oojArray)&
ooRef(oojArray)::operator=(const ooHandleSuper(oojArray) &  objH)
{
  this->ooRef(ooObj)::operator=(objH);
  return *this;
}
inline
ooRef(oojArray)&
ooRef(oojArray)::operator=(const oojArray *  fromObject)
{
  this->ooRef(ooObj)::operator=(ooReinterpretCast(const ooObj *, fromObject));
  return *this;
}
inline
oojArray *
ooRef(oojArray)::pin(ooMode  openMode) const
{
  return ooReinterpretCast(oojArray *, this->pin_ref_internal(openMode));
}
inline
oojArray *
ooRef(oojArray)::vm(ooMode  openMode) const
{
  return this->pin(openMode);
}
#ifndef OO_BUGGY_TEMPLATES
inline
ooHandle(oojArray) &
ooRef(oojArray)::copy(const ooHandle(ooObj) &  nearH,
		ooHandle(oojArray) &           result) const
{
  this->ooRef(ooObj)::copy(nearH, result);
  return result;
}
inline
ooRef(oojArray) &
ooRef(oojArray)::copy(const ooHandle(ooObj) &  nearH,
		ooRef(oojArray) &              newObjRef) const
{
  this->ooRef(ooObj)::copy(nearH, newObjRef);
  return newObjRef;
}
inline
ooHandle(oojArray)
ooRef(oojArray)::copy(const ooHandle(ooObj) &  nearH) const
{
  ooHandle(oojArray) result;
  this->ooRef(ooObj)::copy(nearH, result);
  return result;
}
#endif // !defined(OO_BUGGY_TEMPLATES)
inline
ooDeref(oojArray)
ooRef(oojArray)::operator->() const
{
  ooDeref(oojArray) result(this->pin_ref_internal(oocRead));
  return result;
}


/* methods on ooShortRef(oojArray) */
inline
ooShortRef(oojArray) &
ooShortRef(oojArray)::operator=(const ooShortRef(oojArray) &  shortId)
{
  this->ooShortId::operator=(shortId);
  return *this;
}
inline
ooShortRef(oojArray) &
ooShortRef(oojArray)::operator=(const ooRef(oojArray) &  id)
{
  this->ooShortId::operator=(id);
  return *this;
}
inline
ooShortRef(oojArray) &
ooShortRef(oojArray)::operator=(const ooHandleSuper(oojArray) &  objH)
{
  this->ooShortId::operator=(objH);
  return *this;
}
inline
ooShortRef(oojArray)&
ooShortRef(oojArray)::operator=(const oojArray *  fromObject)
{
  this->ooShortId::operator=(ooReinterpretCast(const ooObj *,fromObject));
  return *this;
}
inline
ooShortRef(oojArray)::ooShortRefStructor(oojArray)()
{
}
#ifdef OO_BUGGY_TEMPLATES
inline
ooShortRef(oojArray)::ooShortRefStructor(oojArray)(const ooShortRef(oojArray) &  shortId)
{
  *this = shortId;
}
#else // !defined(OO_BUGGY_TEMPLATES)
inline
ooShortRef(oojArray)::ooShortRefStructor(oojArray)(const ooShortRef(oojArray) &  shortId) :
    ooShortRef(ooObj)(shortId)
{
}
#endif // !defined(OO_BUGGY_TEMPLATES)
#ifdef OO_BUGGY_TEMPLATES
inline
ooShortRef(oojArray)::ooShortRefStructor(oojArray)(const ooRef(oojArray) &  id)
{
  *this = id;
}
#else // !defined(OO_BUGGY_TEMPLATES)
inline
ooShortRef(oojArray)::ooShortRefStructor(oojArray)(const ooRef(oojArray) &  id) :
    ooShortRef(ooObj)(id)
{
}
#endif // !defined(OO_BUGGY_TEMPLATES)
#ifdef OO_BUGGY_TEMPLATES
inline
ooShortRef(oojArray)::ooShortRefStructor(oojArray)(const ooHandleSuper(oojArray) &  objH)
{
  *this = objH;
}
#else // !defined(OO_BUGGY_TEMPLATES)
inline
ooShortRef(oojArray)::ooShortRefStructor(oojArray)(const ooHandleSuper(oojArray) &  objH) :
    ooShortRef(ooObj)(objH)
{
}
#endif // !defined(OO_BUGGY_TEMPLATES)
#ifdef OO_BUGGY_TEMPLATES
inline
ooShortRef(oojArray)::ooShortRefStructor(oojArray)(const oojArray *  fromObject)
{
  *this = fromObject;
}
#else // !defined(OO_BUGGY_TEMPLATES)
inline
ooShortRef(oojArray)::ooShortRefStructor(oojArray)(const oojArray *  fromObject) :
    ooShortRef(ooObj)(ooReinterpretCast(const ooObj *,fromObject))
{
}
#endif // !defined(OO_BUGGY_TEMPLATES)


/* methods on ooHandle(oojArray) */
inline
ooHandle(oojArray)::ooHandleStructor(oojArray)()
{
}
inline
ooHandle(oojArray)::ooHandleStructor(oojArray)(const ooHandle(oojArray) &  objH) :
#ifdef OO_BUGGY_TEMPLATES
    ooHandle_superclass<oojArray >(objH)
#else // !defined(OO_BUGGY_TEMPLATES)
    ooHandle(ooObj)(objH)
#endif // !defined(OO_BUGGY_TEMPLATES)
{
}
inline
ooHandle(oojArray)::ooHandleStructor(oojArray)(const ooRef(oojArray) &  id) :
#ifdef OO_BUGGY_TEMPLATES
    ooHandle_superclass<oojArray >(id)
#else // !defined(OO_BUGGY_TEMPLATES)
    ooHandle(ooObj)(id)
#endif // !defined(OO_BUGGY_TEMPLATES)
{
}
inline
ooHandle(oojArray)::ooHandleStructor(oojArray)(const oojArray *  fromObject) :
#ifdef OO_BUGGY_TEMPLATES
    ooHandle_superclass<oojArray >(ooReinterpretCast(const ooObj *,fromObject))
#else // !defined(OO_BUGGY_TEMPLATES)
    ooHandle(ooObj)(ooReinterpretCast(const ooObj *,fromObject))
#endif // !defined(OO_BUGGY_TEMPLATES)
{
}
inline
ooHandle(oojArray)&
ooHandle(oojArray)::operator=(const ooRef(oojArray) &  id)
{
  this->ooHandle(ooObj)::operator=(id);
  return *this;
}
inline
ooHandle(oojArray)&
ooHandle(oojArray)::operator=(const ooHandle(oojArray) &  objH)
{
  this->ooHandle(ooObj)::operator=(objH);
  return *this;
}
inline
ooHandle(oojArray)&
ooHandle(oojArray)::operator=(const ooShortRef(oojArray) &  shortId)
{
  this->ooHandle(ooObj)::operator=(shortId);
  return *this;
}
inline
ooHandle(oojArray)&
ooHandle(oojArray)::operator=(const oojArray *  fromObject)
{
  this->ooHandle(ooObj)::operator=(ooReinterpretCast(const ooObj *,fromObject));
  return *this;
}
inline
oojArray *
ooHandle(oojArray)::pin(ooMode  openMode) const
{
  return ooReinterpretCast(oojArray *, this->pin_obj_internal(openMode));
}
inline
oojArray *
ooHandle(oojArray)::operator->() const
{
  return this->vm();
}
inline
oojArray &
ooHandle(oojArray)::operator*() const
{
  return *(this->vm());
}
inline
ooHandle(oojArray)::operator oojArray *() const
{
  if ( _state == oocHandlePTR  )
    return ooReinterpretCast(oojArray *, _ptr._obj);
  else return ooReinterpretCast(oojArray *, this->get_vm());
}
inline
oojArray *
ooHandle(oojArray)::vm() const
{
  if ( _state == oocHandlePTR && _ptr._obj != NULL )
    return ooReinterpretCast(oojArray *, _ptr._obj);
  else return ooReinterpretCast(oojArray *, this->get_vm());
}
inline
ooRef(oojArray) &
ooHandle(oojArray)::copy(const ooHandle(ooObj) &  nearH,
		   ooRef(oojArray) &              result) const
{
  this->ooHandle(ooObj)::copy(nearH, result);
  return result;
}


/* ODMG methods */
inline
oojArray *
ooRef(oojArray)::ptr() const
{
  return this->pin();
}
inline
oojArray *
ooHandle(oojArray)::ptr() const
{
  return this->operator oojArray *();
}
class oojArrayOfInt8;


/////////////////////////////////////////////////////////////////////////////

ooTemplateSpecialization
class ooDeref(oojArrayOfInt8) : public ooDerefBase {
	friend class ooRef(oojArrayOfInt8);
  public:
    ~ooDerefStructor(oojArrayOfInt8)();
    inline oojArrayOfInt8 *operator->() const;
#ifndef OO_BUGGY_TEMPLATES
  private:
#endif // !defined(OO_BUGGY_TEMPLATES)
    ooDerefStructor(oojArrayOfInt8)(ooDeref(oojArrayOfInt8)& deref);
    ooDerefStructor(oojArrayOfInt8)(ooObj *  fromObject);
};


#ifdef OO_BUGGY_TEMPLATES

class ooHandle_superclass<oojArrayOfInt8 > : public ooHandle(oojArray) {
 protected:
  ooHandle_superclass()
    {}
  ooHandle_superclass(const ooHandle(oojArray) &  from) :
      ooHandle(oojArray)(from)
    {}
  ooHandle_superclass(const ooRef(oojArray) &  from) :
      ooHandle(oojArray)(from)
    {}
  ooHandle_superclass(const oojArray *  from) :
      ooHandle(oojArray)(from)
    {}
  ~ooHandle_superclass()
    {}
};

class ooShortRef_superclass<oojArrayOfInt8 > : public ooShortRef(oojArray) {
};

#endif // OO_BUGGY_TEMPLATES

ooTemplateSpecialization
class ooRef(oojArrayOfInt8) : public ooRef(oojArray) {
  public:
    ooRefStructor(oojArrayOfInt8)()
      {}
    ooRefStructor(oojArrayOfInt8)(const ooRef(oojArrayOfInt8)& id) :
	  ooRef(oojArray)(id)
      {}
    inline ooRefStructor(oojArrayOfInt8)(const ooHandleSuper(oojArrayOfInt8)& objH);
    inline ooRefStructor(oojArrayOfInt8)(const oojArrayOfInt8 *  fromObject);
    inline ooRef(oojArrayOfInt8)& operator=(const ooRef(oojArrayOfInt8)& id);
    inline ooRef(oojArrayOfInt8)& operator=(const ooShortRefSuper(oojArrayOfInt8) &shortId);
    inline ooRef(oojArrayOfInt8)& operator=(const ooHandleSuper(oojArrayOfInt8)& objH);
    inline ooRef(oojArrayOfInt8)& operator=(const oojArrayOfInt8 *  fromObject);
    ooStatus lookupObj(const ooHandle(ooObj)& scopeH,
		       const ooKey& key,
		       ooMode openMode = oocRead);
    ooStatus lookupObj(const ooHandle(ooObj)& scopeH,
		       const char* name,
		       ooMode openMode = oocRead);
#ifndef OO_BUGGY_TEMPLATES
    inline ooRef(oojArrayOfInt8)& copy(const ooHandle(ooObj)& nearH,
		    ooRef(oojArrayOfInt8)& newObjRef) const;
    inline ooHandle(oojArrayOfInt8)& copy(const ooHandle(ooObj)& nearH,
			ooHandle(oojArrayOfInt8)& result) const;
    inline ooHandle(oojArrayOfInt8) copy(const ooHandle(ooObj)& nearH) const;
#endif // !defined(OO_BUGGY_TEMPLATES)
    inline oojArrayOfInt8 *pin(ooMode openMode = oocRead) const;
    ooDeref(oojArrayOfInt8) operator->() const;
    /* Use pin() or use ooHandle "operator oojArrayOfInt8 *" instead of vm. */
    /* OBSOLETE */ inline oojArrayOfInt8 *vm(ooMode openMode = oocRead) const;
    // ODMG methods:
    ooRefStructor(oojArrayOfInt8)(const d_Ref_Any &from);
    oojArrayOfInt8 *ptr() const;
};

ooTemplateSpecialization
class ooShortRef(oojArrayOfInt8) :
#ifdef OO_BUGGY_TEMPLATES
			public ooShortRef_superclass<oojArrayOfInt8 >
#else // !defined(OO_BUGGY_TEMPLATES)
			public ooShortRef(oojArray)
#endif // !defined(OO_BUGGY_TEMPLATES)
					            {
  public:
    ooShortRefStructor(oojArrayOfInt8)();
    ooShortRefStructor(oojArrayOfInt8)(const ooShortRef(oojArrayOfInt8)& shortId);
    ooShortRefStructor(oojArrayOfInt8)(const ooRef(oojArrayOfInt8)& id);
    ooShortRefStructor(oojArrayOfInt8)(const ooHandleSuper(oojArrayOfInt8) &objH);
    ooShortRefStructor(oojArrayOfInt8)(const oojArrayOfInt8 *  fromObject);
    ooShortRef(oojArrayOfInt8)& operator=(const ooShortRef(oojArrayOfInt8)& shortId);
    ooShortRef(oojArrayOfInt8)& operator=(const ooRef(oojArrayOfInt8)& id);
    ooShortRef(oojArrayOfInt8)& operator=(const ooHandleSuper(oojArrayOfInt8) &objH);
    ooShortRef(oojArrayOfInt8)& operator=(const oojArrayOfInt8 *  fromObject);
};

ooTemplateSpecialization
class ooHandle(oojArrayOfInt8) :
#ifdef OO_BUGGY_TEMPLATES
		      public ooHandle_superclass<oojArrayOfInt8 >
#else // !defined(OO_BUGGY_TEMPLATES)
		      public ooHandle(oojArray)
#endif // !defined(OO_BUGGY_TEMPLATES)
                                                {
  public:
    inline ooHandleStructor(oojArrayOfInt8)();
    inline ooHandleStructor(oojArrayOfInt8)(const ooRef(oojArrayOfInt8)& id);
    inline ooHandleStructor(oojArrayOfInt8)(const ooHandle(oojArrayOfInt8)& objH);
    inline ooHandleStructor(oojArrayOfInt8)(const oojArrayOfInt8 *  fromObject);
    inline ooHandle(oojArrayOfInt8)& operator=(const ooRef(oojArrayOfInt8)& id);
    inline ooHandle(oojArrayOfInt8)& operator=(const ooHandle(oojArrayOfInt8)& objH);
    inline ooHandle(oojArrayOfInt8)& operator=(const ooShortRef(oojArrayOfInt8)& shortId);
    inline ooHandle(oojArrayOfInt8)& operator=(const oojArrayOfInt8 *  fromObject);
    ooStatus lookupObj(const ooHandle(ooObj)& scopeH,
		       const ooKey& key,
		       ooMode openMode = oocRead);
    ooStatus lookupObj(const ooHandle(ooObj)& scopeH,
		       const char* name,
		       ooMode openMode = oocRead);
    ooHandle(oojArrayOfInt8)& copy(const ooHandle(ooObj)& nearH,
		       ooHandle(oojArrayOfInt8)& result) const;
    inline ooRef(oojArrayOfInt8)& copy(const ooHandle(ooObj)& nearH,
		    ooRef(oojArrayOfInt8)& result) const;
    ooHandle(oojArrayOfInt8) copy(const ooHandle(ooObj)& nearH) const;
    inline oojArrayOfInt8 *pin(ooMode openMode = oocRead) const;
    inline oojArrayOfInt8 *operator->() const;
    inline oojArrayOfInt8 &operator*() const;
    inline operator oojArrayOfInt8 *() const;
    /* Use "operator oojArrayOfInt8 *" instead of vm. */
    /* OBSOLETE */ inline oojArrayOfInt8 *vm() const;
    // ODMG methods:
    ooHandleStructor(oojArrayOfInt8)(const d_Ref_Any &from);
    oojArrayOfInt8 *ptr() const;
};

ooTemplateSpecialization
class ooItr(oojArrayOfInt8) : public ooHandle(oojArrayOfInt8),
		    public ooIteratorObjOrContObj {
  public:
    ooItrStructor(oojArrayOfInt8)();
    ~ooItrStructor(oojArrayOfInt8)();
  private:
    // Defined only to prevent implicit definition:
    ooItrStructor(oojArrayOfInt8)(ooItr(oojArrayOfInt8)&);
    ooItr(oojArrayOfInt8)    operator=(ooItr(oojArrayOfInt8)&);
};


/* methods on ooDeref(oojArrayOfInt8) */
inline
ooDeref(oojArrayOfInt8)::ooDerefStructor(oojArrayOfInt8)(ooDeref(oojArrayOfInt8) &  deref) :
    ooDerefBase(deref.vm())
{
  this->pinCompensate();
}
inline
ooDeref(oojArrayOfInt8)::ooDerefStructor(oojArrayOfInt8)(ooObj *  fromObject) :
    ooDerefBase(fromObject)
{
}
inline
ooDeref(oojArrayOfInt8)::~ooDerefStructor(oojArrayOfInt8)()
{
}
inline
oojArrayOfInt8 *
ooDeref(oojArrayOfInt8)::operator->() const
{
  return ooReinterpretCast(oojArrayOfInt8 *, this->vm());
}


/* methods on ooRef(oojArrayOfInt8) */
inline
ooRef(oojArrayOfInt8)::ooRefStructor(oojArrayOfInt8)(const ooHandleSuper(oojArrayOfInt8)& objH) :
    ooRef(oojArray)(objH)
{
}
inline
ooRef(oojArrayOfInt8)::ooRefStructor(oojArrayOfInt8)(const oojArrayOfInt8 *  fromObject) :
    ooRef(oojArray)(ooReinterpretCast(const oojArray *, fromObject))
{
}
inline
ooRef(oojArrayOfInt8)&
ooRef(oojArrayOfInt8)::operator=(const ooRef(oojArrayOfInt8) &  id)
{
  this->ooId::operator=(id);
  return *this;
}
inline
ooRef(oojArrayOfInt8)&
ooRef(oojArrayOfInt8)::operator=(const ooShortRefSuper(oojArrayOfInt8) &  shortId)
{
  this->ooRef(ooObj)::operator=(shortId);
  return *this;
}
inline
ooRef(oojArrayOfInt8)&
ooRef(oojArrayOfInt8)::operator=(const ooHandleSuper(oojArrayOfInt8) &  objH)
{
  this->ooRef(ooObj)::operator=(objH);
  return *this;
}
inline
ooRef(oojArrayOfInt8)&
ooRef(oojArrayOfInt8)::operator=(const oojArrayOfInt8 *  fromObject)
{
  this->ooRef(ooObj)::operator=(ooReinterpretCast(const ooObj *, fromObject));
  return *this;
}
inline
oojArrayOfInt8 *
ooRef(oojArrayOfInt8)::pin(ooMode  openMode) const
{
  return ooReinterpretCast(oojArrayOfInt8 *, this->pin_ref_internal(openMode));
}
inline
oojArrayOfInt8 *
ooRef(oojArrayOfInt8)::vm(ooMode  openMode) const
{
  return this->pin(openMode);
}
#ifndef OO_BUGGY_TEMPLATES
inline
ooHandle(oojArrayOfInt8) &
ooRef(oojArrayOfInt8)::copy(const ooHandle(ooObj) &  nearH,
		ooHandle(oojArrayOfInt8) &           result) const
{
  this->ooRef(ooObj)::copy(nearH, result);
  return result;
}
inline
ooRef(oojArrayOfInt8) &
ooRef(oojArrayOfInt8)::copy(const ooHandle(ooObj) &  nearH,
		ooRef(oojArrayOfInt8) &              newObjRef) const
{
  this->ooRef(ooObj)::copy(nearH, newObjRef);
  return newObjRef;
}
inline
ooHandle(oojArrayOfInt8)
ooRef(oojArrayOfInt8)::copy(const ooHandle(ooObj) &  nearH) const
{
  ooHandle(oojArrayOfInt8) result;
  this->ooRef(ooObj)::copy(nearH, result);
  return result;
}
#endif // !defined(OO_BUGGY_TEMPLATES)
inline
ooDeref(oojArrayOfInt8)
ooRef(oojArrayOfInt8)::operator->() const
{
  ooDeref(oojArrayOfInt8) result(this->pin_ref_internal(oocRead));
  return result;
}


/* methods on ooShortRef(oojArrayOfInt8) */
inline
ooShortRef(oojArrayOfInt8) &
ooShortRef(oojArrayOfInt8)::operator=(const ooShortRef(oojArrayOfInt8) &  shortId)
{
  this->ooShortId::operator=(shortId);
  return *this;
}
inline
ooShortRef(oojArrayOfInt8) &
ooShortRef(oojArrayOfInt8)::operator=(const ooRef(oojArrayOfInt8) &  id)
{
  this->ooShortId::operator=(id);
  return *this;
}
inline
ooShortRef(oojArrayOfInt8) &
ooShortRef(oojArrayOfInt8)::operator=(const ooHandleSuper(oojArrayOfInt8) &  objH)
{
  this->ooShortId::operator=(objH);
  return *this;
}
inline
ooShortRef(oojArrayOfInt8)&
ooShortRef(oojArrayOfInt8)::operator=(const oojArrayOfInt8 *  fromObject)
{
  this->ooShortId::operator=(ooReinterpretCast(const ooObj *,fromObject));
  return *this;
}
inline
ooShortRef(oojArrayOfInt8)::ooShortRefStructor(oojArrayOfInt8)()
{
}
#ifdef OO_BUGGY_TEMPLATES
inline
ooShortRef(oojArrayOfInt8)::ooShortRefStructor(oojArrayOfInt8)(const ooShortRef(oojArrayOfInt8) &  shortId)
{
  *this = shortId;
}
#else // !defined(OO_BUGGY_TEMPLATES)
inline
ooShortRef(oojArrayOfInt8)::ooShortRefStructor(oojArrayOfInt8)(const ooShortRef(oojArrayOfInt8) &  shortId) :
    ooShortRef(oojArray)(shortId)
{
}
#endif // !defined(OO_BUGGY_TEMPLATES)
#ifdef OO_BUGGY_TEMPLATES
inline
ooShortRef(oojArrayOfInt8)::ooShortRefStructor(oojArrayOfInt8)(const ooRef(oojArrayOfInt8) &  id)
{
  *this = id;
}
#else // !defined(OO_BUGGY_TEMPLATES)
inline
ooShortRef(oojArrayOfInt8)::ooShortRefStructor(oojArrayOfInt8)(const ooRef(oojArrayOfInt8) &  id) :
    ooShortRef(oojArray)(id)
{
}
#endif // !defined(OO_BUGGY_TEMPLATES)
#ifdef OO_BUGGY_TEMPLATES
inline
ooShortRef(oojArrayOfInt8)::ooShortRefStructor(oojArrayOfInt8)(const ooHandleSuper(oojArrayOfInt8) &  objH)
{
  *this = objH;
}
#else // !defined(OO_BUGGY_TEMPLATES)
inline
ooShortRef(oojArrayOfInt8)::ooShortRefStructor(oojArrayOfInt8)(const ooHandleSuper(oojArrayOfInt8) &  objH) :
    ooShortRef(oojArray)(objH)
{
}
#endif // !defined(OO_BUGGY_TEMPLATES)
#ifdef OO_BUGGY_TEMPLATES
inline
ooShortRef(oojArrayOfInt8)::ooShortRefStructor(oojArrayOfInt8)(const oojArrayOfInt8 *  fromObject)
{
  *this = fromObject;
}
#else // !defined(OO_BUGGY_TEMPLATES)
inline
ooShortRef(oojArrayOfInt8)::ooShortRefStructor(oojArrayOfInt8)(const oojArrayOfInt8 *  fromObject) :
    ooShortRef(oojArray)(ooReinterpretCast(const oojArray *,fromObject))
{
}
#endif // !defined(OO_BUGGY_TEMPLATES)


/* methods on ooHandle(oojArrayOfInt8) */
inline
ooHandle(oojArrayOfInt8)::ooHandleStructor(oojArrayOfInt8)()
{
}
inline
ooHandle(oojArrayOfInt8)::ooHandleStructor(oojArrayOfInt8)(const ooHandle(oojArrayOfInt8) &  objH) :
#ifdef OO_BUGGY_TEMPLATES
    ooHandle_superclass<oojArrayOfInt8 >(objH)
#else // !defined(OO_BUGGY_TEMPLATES)
    ooHandle(oojArray)(objH)
#endif // !defined(OO_BUGGY_TEMPLATES)
{
}
inline
ooHandle(oojArrayOfInt8)::ooHandleStructor(oojArrayOfInt8)(const ooRef(oojArrayOfInt8) &  id) :
#ifdef OO_BUGGY_TEMPLATES
    ooHandle_superclass<oojArrayOfInt8 >(id)
#else // !defined(OO_BUGGY_TEMPLATES)
    ooHandle(oojArray)(id)
#endif // !defined(OO_BUGGY_TEMPLATES)
{
}
inline
ooHandle(oojArrayOfInt8)::ooHandleStructor(oojArrayOfInt8)(const oojArrayOfInt8 *  fromObject) :
#ifdef OO_BUGGY_TEMPLATES
    ooHandle_superclass<oojArrayOfInt8 >(ooReinterpretCast(const oojArray *,fromObject))
#else // !defined(OO_BUGGY_TEMPLATES)
    ooHandle(oojArray)(ooReinterpretCast(const oojArray *,fromObject))
#endif // !defined(OO_BUGGY_TEMPLATES)
{
}
inline
ooHandle(oojArrayOfInt8)&
ooHandle(oojArrayOfInt8)::operator=(const ooRef(oojArrayOfInt8) &  id)
{
  this->ooHandle(ooObj)::operator=(id);
  return *this;
}
inline
ooHandle(oojArrayOfInt8)&
ooHandle(oojArrayOfInt8)::operator=(const ooHandle(oojArrayOfInt8) &  objH)
{
  this->ooHandle(ooObj)::operator=(objH);
  return *this;
}
inline
ooHandle(oojArrayOfInt8)&
ooHandle(oojArrayOfInt8)::operator=(const ooShortRef(oojArrayOfInt8) &  shortId)
{
  this->ooHandle(ooObj)::operator=(shortId);
  return *this;
}
inline
ooHandle(oojArrayOfInt8)&
ooHandle(oojArrayOfInt8)::operator=(const oojArrayOfInt8 *  fromObject)
{
  this->ooHandle(ooObj)::operator=(ooReinterpretCast(const ooObj *,fromObject));
  return *this;
}
inline
oojArrayOfInt8 *
ooHandle(oojArrayOfInt8)::pin(ooMode  openMode) const
{
  return ooReinterpretCast(oojArrayOfInt8 *, this->pin_obj_internal(openMode));
}
inline
oojArrayOfInt8 *
ooHandle(oojArrayOfInt8)::operator->() const
{
  return this->vm();
}
inline
oojArrayOfInt8 &
ooHandle(oojArrayOfInt8)::operator*() const
{
  return *(this->vm());
}
inline
ooHandle(oojArrayOfInt8)::operator oojArrayOfInt8 *() const
{
  if ( _state == oocHandlePTR  )
    return ooReinterpretCast(oojArrayOfInt8 *, _ptr._obj);
  else return ooReinterpretCast(oojArrayOfInt8 *, this->get_vm());
}
inline
oojArrayOfInt8 *
ooHandle(oojArrayOfInt8)::vm() const
{
  if ( _state == oocHandlePTR && _ptr._obj != NULL )
    return ooReinterpretCast(oojArrayOfInt8 *, _ptr._obj);
  else return ooReinterpretCast(oojArrayOfInt8 *, this->get_vm());
}
inline
ooRef(oojArrayOfInt8) &
ooHandle(oojArrayOfInt8)::copy(const ooHandle(ooObj) &  nearH,
		   ooRef(oojArrayOfInt8) &              result) const
{
  this->ooHandle(ooObj)::copy(nearH, result);
  return result;
}


/* ODMG methods */
inline
oojArrayOfInt8 *
ooRef(oojArrayOfInt8)::ptr() const
{
  return this->pin();
}
inline
oojArrayOfInt8 *
ooHandle(oojArrayOfInt8)::ptr() const
{
  return this->operator oojArrayOfInt8 *();
}
class oojArrayOfInt16;


/////////////////////////////////////////////////////////////////////////////

ooTemplateSpecialization
class ooDeref(oojArrayOfInt16) : public ooDerefBase {
	friend class ooRef(oojArrayOfInt16);
  public:
    ~ooDerefStructor(oojArrayOfInt16)();
    inline oojArrayOfInt16 *operator->() const;
#ifndef OO_BUGGY_TEMPLATES
  private:
#endif // !defined(OO_BUGGY_TEMPLATES)
    ooDerefStructor(oojArrayOfInt16)(ooDeref(oojArrayOfInt16)& deref);
    ooDerefStructor(oojArrayOfInt16)(ooObj *  fromObject);
};


#ifdef OO_BUGGY_TEMPLATES

class ooHandle_superclass<oojArrayOfInt16 > : public ooHandle(oojArray) {
 protected:
  ooHandle_superclass()
    {}
  ooHandle_superclass(const ooHandle(oojArray) &  from) :
      ooHandle(oojArray)(from)
    {}
  ooHandle_superclass(const ooRef(oojArray) &  from) :
      ooHandle(oojArray)(from)
    {}
  ooHandle_superclass(const oojArray *  from) :
      ooHandle(oojArray)(from)
    {}
  ~ooHandle_superclass()
    {}
};

class ooShortRef_superclass<oojArrayOfInt16 > : public ooShortRef(oojArray) {
};

#endif // OO_BUGGY_TEMPLATES

ooTemplateSpecialization
class ooRef(oojArrayOfInt16) : public ooRef(oojArray) {
  public:
    ooRefStructor(oojArrayOfInt16)()
      {}
    ooRefStructor(oojArrayOfInt16)(const ooRef(oojArrayOfInt16)& id) :
	  ooRef(oojArray)(id)
      {}
    inline ooRefStructor(oojArrayOfInt16)(const ooHandleSuper(oojArrayOfInt16)& objH);
    inline ooRefStructor(oojArrayOfInt16)(const oojArrayOfInt16 *  fromObject);
    inline ooRef(oojArrayOfInt16)& operator=(const ooRef(oojArrayOfInt16)& id);
    inline ooRef(oojArrayOfInt16)& operator=(const ooShortRefSuper(oojArrayOfInt16) &shortId);
    inline ooRef(oojArrayOfInt16)& operator=(const ooHandleSuper(oojArrayOfInt16)& objH);
    inline ooRef(oojArrayOfInt16)& operator=(const oojArrayOfInt16 *  fromObject);
    ooStatus lookupObj(const ooHandle(ooObj)& scopeH,
		       const ooKey& key,
		       ooMode openMode = oocRead);
    ooStatus lookupObj(const ooHandle(ooObj)& scopeH,
		       const char* name,
		       ooMode openMode = oocRead);
#ifndef OO_BUGGY_TEMPLATES
    inline ooRef(oojArrayOfInt16)& copy(const ooHandle(ooObj)& nearH,
		    ooRef(oojArrayOfInt16)& newObjRef) const;
    inline ooHandle(oojArrayOfInt16)& copy(const ooHandle(ooObj)& nearH,
			ooHandle(oojArrayOfInt16)& result) const;
    inline ooHandle(oojArrayOfInt16) copy(const ooHandle(ooObj)& nearH) const;
#endif // !defined(OO_BUGGY_TEMPLATES)
    inline oojArrayOfInt16 *pin(ooMode openMode = oocRead) const;
    ooDeref(oojArrayOfInt16) operator->() const;
    /* Use pin() or use ooHandle "operator oojArrayOfInt16 *" instead of vm. */
    /* OBSOLETE */ inline oojArrayOfInt16 *vm(ooMode openMode = oocRead) const;
    // ODMG methods:
    ooRefStructor(oojArrayOfInt16)(const d_Ref_Any &from);
    oojArrayOfInt16 *ptr() const;
};

ooTemplateSpecialization
class ooShortRef(oojArrayOfInt16) :
#ifdef OO_BUGGY_TEMPLATES
			public ooShortRef_superclass<oojArrayOfInt16 >
#else // !defined(OO_BUGGY_TEMPLATES)
			public ooShortRef(oojArray)
#endif // !defined(OO_BUGGY_TEMPLATES)
					            {
  public:
    ooShortRefStructor(oojArrayOfInt16)();
    ooShortRefStructor(oojArrayOfInt16)(const ooShortRef(oojArrayOfInt16)& shortId);
    ooShortRefStructor(oojArrayOfInt16)(const ooRef(oojArrayOfInt16)& id);
    ooShortRefStructor(oojArrayOfInt16)(const ooHandleSuper(oojArrayOfInt16) &objH);
    ooShortRefStructor(oojArrayOfInt16)(const oojArrayOfInt16 *  fromObject);
    ooShortRef(oojArrayOfInt16)& operator=(const ooShortRef(oojArrayOfInt16)& shortId);
    ooShortRef(oojArrayOfInt16)& operator=(const ooRef(oojArrayOfInt16)& id);
    ooShortRef(oojArrayOfInt16)& operator=(const ooHandleSuper(oojArrayOfInt16) &objH);
    ooShortRef(oojArrayOfInt16)& operator=(const oojArrayOfInt16 *  fromObject);
};

ooTemplateSpecialization
class ooHandle(oojArrayOfInt16) :
#ifdef OO_BUGGY_TEMPLATES
		      public ooHandle_superclass<oojArrayOfInt16 >
#else // !defined(OO_BUGGY_TEMPLATES)
		      public ooHandle(oojArray)
#endif // !defined(OO_BUGGY_TEMPLATES)
                                                {
  public:
    inline ooHandleStructor(oojArrayOfInt16)();
    inline ooHandleStructor(oojArrayOfInt16)(const ooRef(oojArrayOfInt16)& id);
    inline ooHandleStructor(oojArrayOfInt16)(const ooHandle(oojArrayOfInt16)& objH);
    inline ooHandleStructor(oojArrayOfInt16)(const oojArrayOfInt16 *  fromObject);
    inline ooHandle(oojArrayOfInt16)& operator=(const ooRef(oojArrayOfInt16)& id);
    inline ooHandle(oojArrayOfInt16)& operator=(const ooHandle(oojArrayOfInt16)& objH);
    inline ooHandle(oojArrayOfInt16)& operator=(const ooShortRef(oojArrayOfInt16)& shortId);
    inline ooHandle(oojArrayOfInt16)& operator=(const oojArrayOfInt16 *  fromObject);
    ooStatus lookupObj(const ooHandle(ooObj)& scopeH,
		       const ooKey& key,
		       ooMode openMode = oocRead);
    ooStatus lookupObj(const ooHandle(ooObj)& scopeH,
		       const char* name,
		       ooMode openMode = oocRead);
    ooHandle(oojArrayOfInt16)& copy(const ooHandle(ooObj)& nearH,
		       ooHandle(oojArrayOfInt16)& result) const;
    inline ooRef(oojArrayOfInt16)& copy(const ooHandle(ooObj)& nearH,
		    ooRef(oojArrayOfInt16)& result) const;
    ooHandle(oojArrayOfInt16) copy(const ooHandle(ooObj)& nearH) const;
    inline oojArrayOfInt16 *pin(ooMode openMode = oocRead) const;
    inline oojArrayOfInt16 *operator->() const;
    inline oojArrayOfInt16 &operator*() const;
    inline operator oojArrayOfInt16 *() const;
    /* Use "operator oojArrayOfInt16 *" instead of vm. */
    /* OBSOLETE */ inline oojArrayOfInt16 *vm() const;
    // ODMG methods:
    ooHandleStructor(oojArrayOfInt16)(const d_Ref_Any &from);
    oojArrayOfInt16 *ptr() const;
};

ooTemplateSpecialization
class ooItr(oojArrayOfInt16) : public ooHandle(oojArrayOfInt16),
		    public ooIteratorObjOrContObj {
  public:
    ooItrStructor(oojArrayOfInt16)();
    ~ooItrStructor(oojArrayOfInt16)();
  private:
    // Defined only to prevent implicit definition:
    ooItrStructor(oojArrayOfInt16)(ooItr(oojArrayOfInt16)&);
    ooItr(oojArrayOfInt16)    operator=(ooItr(oojArrayOfInt16)&);
};


/* methods on ooDeref(oojArrayOfInt16) */
inline
ooDeref(oojArrayOfInt16)::ooDerefStructor(oojArrayOfInt16)(ooDeref(oojArrayOfInt16) &  deref) :
    ooDerefBase(deref.vm())
{
  this->pinCompensate();
}
inline
ooDeref(oojArrayOfInt16)::ooDerefStructor(oojArrayOfInt16)(ooObj *  fromObject) :
    ooDerefBase(fromObject)
{
}
inline
ooDeref(oojArrayOfInt16)::~ooDerefStructor(oojArrayOfInt16)()
{
}
inline
oojArrayOfInt16 *
ooDeref(oojArrayOfInt16)::operator->() const
{
  return ooReinterpretCast(oojArrayOfInt16 *, this->vm());
}


/* methods on ooRef(oojArrayOfInt16) */
inline
ooRef(oojArrayOfInt16)::ooRefStructor(oojArrayOfInt16)(const ooHandleSuper(oojArrayOfInt16)& objH) :
    ooRef(oojArray)(objH)
{
}
inline
ooRef(oojArrayOfInt16)::ooRefStructor(oojArrayOfInt16)(const oojArrayOfInt16 *  fromObject) :
    ooRef(oojArray)(ooReinterpretCast(const oojArray *, fromObject))
{
}
inline
ooRef(oojArrayOfInt16)&
ooRef(oojArrayOfInt16)::operator=(const ooRef(oojArrayOfInt16) &  id)
{
  this->ooId::operator=(id);
  return *this;
}
inline
ooRef(oojArrayOfInt16)&
ooRef(oojArrayOfInt16)::operator=(const ooShortRefSuper(oojArrayOfInt16) &  shortId)
{
  this->ooRef(ooObj)::operator=(shortId);
  return *this;
}
inline
ooRef(oojArrayOfInt16)&
ooRef(oojArrayOfInt16)::operator=(const ooHandleSuper(oojArrayOfInt16) &  objH)
{
  this->ooRef(ooObj)::operator=(objH);
  return *this;
}
inline
ooRef(oojArrayOfInt16)&
ooRef(oojArrayOfInt16)::operator=(const oojArrayOfInt16 *  fromObject)
{
  this->ooRef(ooObj)::operator=(ooReinterpretCast(const ooObj *, fromObject));
  return *this;
}
inline
oojArrayOfInt16 *
ooRef(oojArrayOfInt16)::pin(ooMode  openMode) const
{
  return ooReinterpretCast(oojArrayOfInt16 *, this->pin_ref_internal(openMode));
}
inline
oojArrayOfInt16 *
ooRef(oojArrayOfInt16)::vm(ooMode  openMode) const
{
  return this->pin(openMode);
}
#ifndef OO_BUGGY_TEMPLATES
inline
ooHandle(oojArrayOfInt16) &
ooRef(oojArrayOfInt16)::copy(const ooHandle(ooObj) &  nearH,
		ooHandle(oojArrayOfInt16) &           result) const
{
  this->ooRef(ooObj)::copy(nearH, result);
  return result;
}
inline
ooRef(oojArrayOfInt16) &
ooRef(oojArrayOfInt16)::copy(const ooHandle(ooObj) &  nearH,
		ooRef(oojArrayOfInt16) &              newObjRef) const
{
  this->ooRef(ooObj)::copy(nearH, newObjRef);
  return newObjRef;
}
inline
ooHandle(oojArrayOfInt16)
ooRef(oojArrayOfInt16)::copy(const ooHandle(ooObj) &  nearH) const
{
  ooHandle(oojArrayOfInt16) result;
  this->ooRef(ooObj)::copy(nearH, result);
  return result;
}
#endif // !defined(OO_BUGGY_TEMPLATES)
inline
ooDeref(oojArrayOfInt16)
ooRef(oojArrayOfInt16)::operator->() const
{
  ooDeref(oojArrayOfInt16) result(this->pin_ref_internal(oocRead));
  return result;
}


/* methods on ooShortRef(oojArrayOfInt16) */
inline
ooShortRef(oojArrayOfInt16) &
ooShortRef(oojArrayOfInt16)::operator=(const ooShortRef(oojArrayOfInt16) &  shortId)
{
  this->ooShortId::operator=(shortId);
  return *this;
}
inline
ooShortRef(oojArrayOfInt16) &
ooShortRef(oojArrayOfInt16)::operator=(const ooRef(oojArrayOfInt16) &  id)
{
  this->ooShortId::operator=(id);
  return *this;
}
inline
ooShortRef(oojArrayOfInt16) &
ooShortRef(oojArrayOfInt16)::operator=(const ooHandleSuper(oojArrayOfInt16) &  objH)
{
  this->ooShortId::operator=(objH);
  return *this;
}
inline
ooShortRef(oojArrayOfInt16)&
ooShortRef(oojArrayOfInt16)::operator=(const oojArrayOfInt16 *  fromObject)
{
  this->ooShortId::operator=(ooReinterpretCast(const ooObj *,fromObject));
  return *this;
}
inline
ooShortRef(oojArrayOfInt16)::ooShortRefStructor(oojArrayOfInt16)()
{
}
#ifdef OO_BUGGY_TEMPLATES
inline
ooShortRef(oojArrayOfInt16)::ooShortRefStructor(oojArrayOfInt16)(const ooShortRef(oojArrayOfInt16) &  shortId)
{
  *this = shortId;
}
#else // !defined(OO_BUGGY_TEMPLATES)
inline
ooShortRef(oojArrayOfInt16)::ooShortRefStructor(oojArrayOfInt16)(const ooShortRef(oojArrayOfInt16) &  shortId) :
    ooShortRef(oojArray)(shortId)
{
}
#endif // !defined(OO_BUGGY_TEMPLATES)
#ifdef OO_BUGGY_TEMPLATES
inline
ooShortRef(oojArrayOfInt16)::ooShortRefStructor(oojArrayOfInt16)(const ooRef(oojArrayOfInt16) &  id)
{
  *this = id;
}
#else // !defined(OO_BUGGY_TEMPLATES)
inline
ooShortRef(oojArrayOfInt16)::ooShortRefStructor(oojArrayOfInt16)(const ooRef(oojArrayOfInt16) &  id) :
    ooShortRef(oojArray)(id)
{
}
#endif // !defined(OO_BUGGY_TEMPLATES)
#ifdef OO_BUGGY_TEMPLATES
inline
ooShortRef(oojArrayOfInt16)::ooShortRefStructor(oojArrayOfInt16)(const ooHandleSuper(oojArrayOfInt16) &  objH)
{
  *this = objH;
}
#else // !defined(OO_BUGGY_TEMPLATES)
inline
ooShortRef(oojArrayOfInt16)::ooShortRefStructor(oojArrayOfInt16)(const ooHandleSuper(oojArrayOfInt16) &  objH) :
    ooShortRef(oojArray)(objH)
{
}
#endif // !defined(OO_BUGGY_TEMPLATES)
#ifdef OO_BUGGY_TEMPLATES
inline
ooShortRef(oojArrayOfInt16)::ooShortRefStructor(oojArrayOfInt16)(const oojArrayOfInt16 *  fromObject)
{
  *this = fromObject;
}
#else // !defined(OO_BUGGY_TEMPLATES)
inline
ooShortRef(oojArrayOfInt16)::ooShortRefStructor(oojArrayOfInt16)(const oojArrayOfInt16 *  fromObject) :
    ooShortRef(oojArray)(ooReinterpretCast(const oojArray *,fromObject))
{
}
#endif // !defined(OO_BUGGY_TEMPLATES)


/* methods on ooHandle(oojArrayOfInt16) */
inline
ooHandle(oojArrayOfInt16)::ooHandleStructor(oojArrayOfInt16)()
{
}
inline
ooHandle(oojArrayOfInt16)::ooHandleStructor(oojArrayOfInt16)(const ooHandle(oojArrayOfInt16) &  objH) :
#ifdef OO_BUGGY_TEMPLATES
    ooHandle_superclass<oojArrayOfInt16 >(objH)
#else // !defined(OO_BUGGY_TEMPLATES)
    ooHandle(oojArray)(objH)
#endif // !defined(OO_BUGGY_TEMPLATES)
{
}
inline
ooHandle(oojArrayOfInt16)::ooHandleStructor(oojArrayOfInt16)(const ooRef(oojArrayOfInt16) &  id) :
#ifdef OO_BUGGY_TEMPLATES
    ooHandle_superclass<oojArrayOfInt16 >(id)
#else // !defined(OO_BUGGY_TEMPLATES)
    ooHandle(oojArray)(id)
#endif // !defined(OO_BUGGY_TEMPLATES)
{
}
inline
ooHandle(oojArrayOfInt16)::ooHandleStructor(oojArrayOfInt16)(const oojArrayOfInt16 *  fromObject) :
#ifdef OO_BUGGY_TEMPLATES
    ooHandle_superclass<oojArrayOfInt16 >(ooReinterpretCast(const oojArray *,fromObject))
#else // !defined(OO_BUGGY_TEMPLATES)
    ooHandle(oojArray)(ooReinterpretCast(const oojArray *,fromObject))
#endif // !defined(OO_BUGGY_TEMPLATES)
{
}
inline
ooHandle(oojArrayOfInt16)&
ooHandle(oojArrayOfInt16)::operator=(const ooRef(oojArrayOfInt16) &  id)
{
  this->ooHandle(ooObj)::operator=(id);
  return *this;
}
inline
ooHandle(oojArrayOfInt16)&
ooHandle(oojArrayOfInt16)::operator=(const ooHandle(oojArrayOfInt16) &  objH)
{
  this->ooHandle(ooObj)::operator=(objH);
  return *this;
}
inline
ooHandle(oojArrayOfInt16)&
ooHandle(oojArrayOfInt16)::operator=(const ooShortRef(oojArrayOfInt16) &  shortId)
{
  this->ooHandle(ooObj)::operator=(shortId);
  return *this;
}
inline
ooHandle(oojArrayOfInt16)&
ooHandle(oojArrayOfInt16)::operator=(const oojArrayOfInt16 *  fromObject)
{
  this->ooHandle(ooObj)::operator=(ooReinterpretCast(const ooObj *,fromObject));
  return *this;
}
inline
oojArrayOfInt16 *
ooHandle(oojArrayOfInt16)::pin(ooMode  openMode) const
{
  return ooReinterpretCast(oojArrayOfInt16 *, this->pin_obj_internal(openMode));
}
inline
oojArrayOfInt16 *
ooHandle(oojArrayOfInt16)::operator->() const
{
  return this->vm();
}
inline
oojArrayOfInt16 &
ooHandle(oojArrayOfInt16)::operator*() const
{
  return *(this->vm());
}
inline
ooHandle(oojArrayOfInt16)::operator oojArrayOfInt16 *() const
{
  if ( _state == oocHandlePTR  )
    return ooReinterpretCast(oojArrayOfInt16 *, _ptr._obj);
  else return ooReinterpretCast(oojArrayOfInt16 *, this->get_vm());
}
inline
oojArrayOfInt16 *
ooHandle(oojArrayOfInt16)::vm() const
{
  if ( _state == oocHandlePTR && _ptr._obj != NULL )
    return ooReinterpretCast(oojArrayOfInt16 *, _ptr._obj);
  else return ooReinterpretCast(oojArrayOfInt16 *, this->get_vm());
}
inline
ooRef(oojArrayOfInt16) &
ooHandle(oojArrayOfInt16)::copy(const ooHandle(ooObj) &  nearH,
		   ooRef(oojArrayOfInt16) &              result) const
{
  this->ooHandle(ooObj)::copy(nearH, result);
  return result;
}


/* ODMG methods */
inline
oojArrayOfInt16 *
ooRef(oojArrayOfInt16)::ptr() const
{
  return this->pin();
}
inline
oojArrayOfInt16 *
ooHandle(oojArrayOfInt16)::ptr() const
{
  return this->operator oojArrayOfInt16 *();
}
class oojArrayOfInt32;


/////////////////////////////////////////////////////////////////////////////

ooTemplateSpecialization
class ooDeref(oojArrayOfInt32) : public ooDerefBase {
	friend class ooRef(oojArrayOfInt32);
  public:
    ~ooDerefStructor(oojArrayOfInt32)();
    inline oojArrayOfInt32 *operator->() const;
#ifndef OO_BUGGY_TEMPLATES
  private:
#endif // !defined(OO_BUGGY_TEMPLATES)
    ooDerefStructor(oojArrayOfInt32)(ooDeref(oojArrayOfInt32)& deref);
    ooDerefStructor(oojArrayOfInt32)(ooObj *  fromObject);
};


#ifdef OO_BUGGY_TEMPLATES

class ooHandle_superclass<oojArrayOfInt32 > : public ooHandle(oojArray) {
 protected:
  ooHandle_superclass()
    {}
  ooHandle_superclass(const ooHandle(oojArray) &  from) :
      ooHandle(oojArray)(from)
    {}
  ooHandle_superclass(const ooRef(oojArray) &  from) :
      ooHandle(oojArray)(from)
    {}
  ooHandle_superclass(const oojArray *  from) :
      ooHandle(oojArray)(from)
    {}
  ~ooHandle_superclass()
    {}
};

class ooShortRef_superclass<oojArrayOfInt32 > : public ooShortRef(oojArray) {
};

#endif // OO_BUGGY_TEMPLATES

ooTemplateSpecialization
class ooRef(oojArrayOfInt32) : public ooRef(oojArray) {
  public:
    ooRefStructor(oojArrayOfInt32)()
      {}
    ooRefStructor(oojArrayOfInt32)(const ooRef(oojArrayOfInt32)& id) :
	  ooRef(oojArray)(id)
      {}
    inline ooRefStructor(oojArrayOfInt32)(const ooHandleSuper(oojArrayOfInt32)& objH);
    inline ooRefStructor(oojArrayOfInt32)(const oojArrayOfInt32 *  fromObject);
    inline ooRef(oojArrayOfInt32)& operator=(const ooRef(oojArrayOfInt32)& id);
    inline ooRef(oojArrayOfInt32)& operator=(const ooShortRefSuper(oojArrayOfInt32) &shortId);
    inline ooRef(oojArrayOfInt32)& operator=(const ooHandleSuper(oojArrayOfInt32)& objH);
    inline ooRef(oojArrayOfInt32)& operator=(const oojArrayOfInt32 *  fromObject);
    ooStatus lookupObj(const ooHandle(ooObj)& scopeH,
		       const ooKey& key,
		       ooMode openMode = oocRead);
    ooStatus lookupObj(const ooHandle(ooObj)& scopeH,
		       const char* name,
		       ooMode openMode = oocRead);
#ifndef OO_BUGGY_TEMPLATES
    inline ooRef(oojArrayOfInt32)& copy(const ooHandle(ooObj)& nearH,
		    ooRef(oojArrayOfInt32)& newObjRef) const;
    inline ooHandle(oojArrayOfInt32)& copy(const ooHandle(ooObj)& nearH,
			ooHandle(oojArrayOfInt32)& result) const;
    inline ooHandle(oojArrayOfInt32) copy(const ooHandle(ooObj)& nearH) const;
#endif // !defined(OO_BUGGY_TEMPLATES)
    inline oojArrayOfInt32 *pin(ooMode openMode = oocRead) const;
    ooDeref(oojArrayOfInt32) operator->() const;
    /* Use pin() or use ooHandle "operator oojArrayOfInt32 *" instead of vm. */
    /* OBSOLETE */ inline oojArrayOfInt32 *vm(ooMode openMode = oocRead) const;
    // ODMG methods:
    ooRefStructor(oojArrayOfInt32)(const d_Ref_Any &from);
    oojArrayOfInt32 *ptr() const;
};

ooTemplateSpecialization
class ooShortRef(oojArrayOfInt32) :
#ifdef OO_BUGGY_TEMPLATES
			public ooShortRef_superclass<oojArrayOfInt32 >
#else // !defined(OO_BUGGY_TEMPLATES)
			public ooShortRef(oojArray)
#endif // !defined(OO_BUGGY_TEMPLATES)
					            {
  public:
    ooShortRefStructor(oojArrayOfInt32)();
    ooShortRefStructor(oojArrayOfInt32)(const ooShortRef(oojArrayOfInt32)& shortId);
    ooShortRefStructor(oojArrayOfInt32)(const ooRef(oojArrayOfInt32)& id);
    ooShortRefStructor(oojArrayOfInt32)(const ooHandleSuper(oojArrayOfInt32) &objH);
    ooShortRefStructor(oojArrayOfInt32)(const oojArrayOfInt32 *  fromObject);
    ooShortRef(oojArrayOfInt32)& operator=(const ooShortRef(oojArrayOfInt32)& shortId);
    ooShortRef(oojArrayOfInt32)& operator=(const ooRef(oojArrayOfInt32)& id);
    ooShortRef(oojArrayOfInt32)& operator=(const ooHandleSuper(oojArrayOfInt32) &objH);
    ooShortRef(oojArrayOfInt32)& operator=(const oojArrayOfInt32 *  fromObject);
};

ooTemplateSpecialization
class ooHandle(oojArrayOfInt32) :
#ifdef OO_BUGGY_TEMPLATES
		      public ooHandle_superclass<oojArrayOfInt32 >
#else // !defined(OO_BUGGY_TEMPLATES)
		      public ooHandle(oojArray)
#endif // !defined(OO_BUGGY_TEMPLATES)
                                                {
  public:
    inline ooHandleStructor(oojArrayOfInt32)();
    inline ooHandleStructor(oojArrayOfInt32)(const ooRef(oojArrayOfInt32)& id);
    inline ooHandleStructor(oojArrayOfInt32)(const ooHandle(oojArrayOfInt32)& objH);
    inline ooHandleStructor(oojArrayOfInt32)(const oojArrayOfInt32 *  fromObject);
    inline ooHandle(oojArrayOfInt32)& operator=(const ooRef(oojArrayOfInt32)& id);
    inline ooHandle(oojArrayOfInt32)& operator=(const ooHandle(oojArrayOfInt32)& objH);
    inline ooHandle(oojArrayOfInt32)& operator=(const ooShortRef(oojArrayOfInt32)& shortId);
    inline ooHandle(oojArrayOfInt32)& operator=(const oojArrayOfInt32 *  fromObject);
    ooStatus lookupObj(const ooHandle(ooObj)& scopeH,
		       const ooKey& key,
		       ooMode openMode = oocRead);
    ooStatus lookupObj(const ooHandle(ooObj)& scopeH,
		       const char* name,
		       ooMode openMode = oocRead);
    ooHandle(oojArrayOfInt32)& copy(const ooHandle(ooObj)& nearH,
		       ooHandle(oojArrayOfInt32)& result) const;
    inline ooRef(oojArrayOfInt32)& copy(const ooHandle(ooObj)& nearH,
		    ooRef(oojArrayOfInt32)& result) const;
    ooHandle(oojArrayOfInt32) copy(const ooHandle(ooObj)& nearH) const;
    inline oojArrayOfInt32 *pin(ooMode openMode = oocRead) const;
    inline oojArrayOfInt32 *operator->() const;
    inline oojArrayOfInt32 &operator*() const;
    inline operator oojArrayOfInt32 *() const;
    /* Use "operator oojArrayOfInt32 *" instead of vm. */
    /* OBSOLETE */ inline oojArrayOfInt32 *vm() const;
    // ODMG methods:
    ooHandleStructor(oojArrayOfInt32)(const d_Ref_Any &from);
    oojArrayOfInt32 *ptr() const;
};

ooTemplateSpecialization
class ooItr(oojArrayOfInt32) : public ooHandle(oojArrayOfInt32),
		    public ooIteratorObjOrContObj {
  public:
    ooItrStructor(oojArrayOfInt32)();
    ~ooItrStructor(oojArrayOfInt32)();
  private:
    // Defined only to prevent implicit definition:
    ooItrStructor(oojArrayOfInt32)(ooItr(oojArrayOfInt32)&);
    ooItr(oojArrayOfInt32)    operator=(ooItr(oojArrayOfInt32)&);
};


/* methods on ooDeref(oojArrayOfInt32) */
inline
ooDeref(oojArrayOfInt32)::ooDerefStructor(oojArrayOfInt32)(ooDeref(oojArrayOfInt32) &  deref) :
    ooDerefBase(deref.vm())
{
  this->pinCompensate();
}
inline
ooDeref(oojArrayOfInt32)::ooDerefStructor(oojArrayOfInt32)(ooObj *  fromObject) :
    ooDerefBase(fromObject)
{
}
inline
ooDeref(oojArrayOfInt32)::~ooDerefStructor(oojArrayOfInt32)()
{
}
inline
oojArrayOfInt32 *
ooDeref(oojArrayOfInt32)::operator->() const
{
  return ooReinterpretCast(oojArrayOfInt32 *, this->vm());
}


/* methods on ooRef(oojArrayOfInt32) */
inline
ooRef(oojArrayOfInt32)::ooRefStructor(oojArrayOfInt32)(const ooHandleSuper(oojArrayOfInt32)& objH) :
    ooRef(oojArray)(objH)
{
}
inline
ooRef(oojArrayOfInt32)::ooRefStructor(oojArrayOfInt32)(const oojArrayOfInt32 *  fromObject) :
    ooRef(oojArray)(ooReinterpretCast(const oojArray *, fromObject))
{
}
inline
ooRef(oojArrayOfInt32)&
ooRef(oojArrayOfInt32)::operator=(const ooRef(oojArrayOfInt32) &  id)
{
  this->ooId::operator=(id);
  return *this;
}
inline
ooRef(oojArrayOfInt32)&
ooRef(oojArrayOfInt32)::operator=(const ooShortRefSuper(oojArrayOfInt32) &  shortId)
{
  this->ooRef(ooObj)::operator=(shortId);
  return *this;
}
inline
ooRef(oojArrayOfInt32)&
ooRef(oojArrayOfInt32)::operator=(const ooHandleSuper(oojArrayOfInt32) &  objH)
{
  this->ooRef(ooObj)::operator=(objH);
  return *this;
}
inline
ooRef(oojArrayOfInt32)&
ooRef(oojArrayOfInt32)::operator=(const oojArrayOfInt32 *  fromObject)
{
  this->ooRef(ooObj)::operator=(ooReinterpretCast(const ooObj *, fromObject));
  return *this;
}
inline
oojArrayOfInt32 *
ooRef(oojArrayOfInt32)::pin(ooMode  openMode) const
{
  return ooReinterpretCast(oojArrayOfInt32 *, this->pin_ref_internal(openMode));
}
inline
oojArrayOfInt32 *
ooRef(oojArrayOfInt32)::vm(ooMode  openMode) const
{
  return this->pin(openMode);
}
#ifndef OO_BUGGY_TEMPLATES
inline
ooHandle(oojArrayOfInt32) &
ooRef(oojArrayOfInt32)::copy(const ooHandle(ooObj) &  nearH,
		ooHandle(oojArrayOfInt32) &           result) const
{
  this->ooRef(ooObj)::copy(nearH, result);
  return result;
}
inline
ooRef(oojArrayOfInt32) &
ooRef(oojArrayOfInt32)::copy(const ooHandle(ooObj) &  nearH,
		ooRef(oojArrayOfInt32) &              newObjRef) const
{
  this->ooRef(ooObj)::copy(nearH, newObjRef);
  return newObjRef;
}
inline
ooHandle(oojArrayOfInt32)
ooRef(oojArrayOfInt32)::copy(const ooHandle(ooObj) &  nearH) const
{
  ooHandle(oojArrayOfInt32) result;
  this->ooRef(ooObj)::copy(nearH, result);
  return result;
}
#endif // !defined(OO_BUGGY_TEMPLATES)
inline
ooDeref(oojArrayOfInt32)
ooRef(oojArrayOfInt32)::operator->() const
{
  ooDeref(oojArrayOfInt32) result(this->pin_ref_internal(oocRead));
  return result;
}


/* methods on ooShortRef(oojArrayOfInt32) */
inline
ooShortRef(oojArrayOfInt32) &
ooShortRef(oojArrayOfInt32)::operator=(const ooShortRef(oojArrayOfInt32) &  shortId)
{
  this->ooShortId::operator=(shortId);
  return *this;
}
inline
ooShortRef(oojArrayOfInt32) &
ooShortRef(oojArrayOfInt32)::operator=(const ooRef(oojArrayOfInt32) &  id)
{
  this->ooShortId::operator=(id);
  return *this;
}
inline
ooShortRef(oojArrayOfInt32) &
ooShortRef(oojArrayOfInt32)::operator=(const ooHandleSuper(oojArrayOfInt32) &  objH)
{
  this->ooShortId::operator=(objH);
  return *this;
}
inline
ooShortRef(oojArrayOfInt32)&
ooShortRef(oojArrayOfInt32)::operator=(const oojArrayOfInt32 *  fromObject)
{
  this->ooShortId::operator=(ooReinterpretCast(const ooObj *,fromObject));
  return *this;
}
inline
ooShortRef(oojArrayOfInt32)::ooShortRefStructor(oojArrayOfInt32)()
{
}
#ifdef OO_BUGGY_TEMPLATES
inline
ooShortRef(oojArrayOfInt32)::ooShortRefStructor(oojArrayOfInt32)(const ooShortRef(oojArrayOfInt32) &  shortId)
{
  *this = shortId;
}
#else // !defined(OO_BUGGY_TEMPLATES)
inline
ooShortRef(oojArrayOfInt32)::ooShortRefStructor(oojArrayOfInt32)(const ooShortRef(oojArrayOfInt32) &  shortId) :
    ooShortRef(oojArray)(shortId)
{
}
#endif // !defined(OO_BUGGY_TEMPLATES)
#ifdef OO_BUGGY_TEMPLATES
inline
ooShortRef(oojArrayOfInt32)::ooShortRefStructor(oojArrayOfInt32)(const ooRef(oojArrayOfInt32) &  id)
{
  *this = id;
}
#else // !defined(OO_BUGGY_TEMPLATES)
inline
ooShortRef(oojArrayOfInt32)::ooShortRefStructor(oojArrayOfInt32)(const ooRef(oojArrayOfInt32) &  id) :
    ooShortRef(oojArray)(id)
{
}
#endif // !defined(OO_BUGGY_TEMPLATES)
#ifdef OO_BUGGY_TEMPLATES
inline
ooShortRef(oojArrayOfInt32)::ooShortRefStructor(oojArrayOfInt32)(const ooHandleSuper(oojArrayOfInt32) &  objH)
{
  *this = objH;
}
#else // !defined(OO_BUGGY_TEMPLATES)
inline
ooShortRef(oojArrayOfInt32)::ooShortRefStructor(oojArrayOfInt32)(const ooHandleSuper(oojArrayOfInt32) &  objH) :
    ooShortRef(oojArray)(objH)
{
}
#endif // !defined(OO_BUGGY_TEMPLATES)
#ifdef OO_BUGGY_TEMPLATES
inline
ooShortRef(oojArrayOfInt32)::ooShortRefStructor(oojArrayOfInt32)(const oojArrayOfInt32 *  fromObject)
{
  *this = fromObject;
}
#else // !defined(OO_BUGGY_TEMPLATES)
inline
ooShortRef(oojArrayOfInt32)::ooShortRefStructor(oojArrayOfInt32)(const oojArrayOfInt32 *  fromObject) :
    ooShortRef(oojArray)(ooReinterpretCast(const oojArray *,fromObject))
{
}
#endif // !defined(OO_BUGGY_TEMPLATES)


/* methods on ooHandle(oojArrayOfInt32) */
inline
ooHandle(oojArrayOfInt32)::ooHandleStructor(oojArrayOfInt32)()
{
}
inline
ooHandle(oojArrayOfInt32)::ooHandleStructor(oojArrayOfInt32)(const ooHandle(oojArrayOfInt32) &  objH) :
#ifdef OO_BUGGY_TEMPLATES
    ooHandle_superclass<oojArrayOfInt32 >(objH)
#else // !defined(OO_BUGGY_TEMPLATES)
    ooHandle(oojArray)(objH)
#endif // !defined(OO_BUGGY_TEMPLATES)
{
}
inline
ooHandle(oojArrayOfInt32)::ooHandleStructor(oojArrayOfInt32)(const ooRef(oojArrayOfInt32) &  id) :
#ifdef OO_BUGGY_TEMPLATES
    ooHandle_superclass<oojArrayOfInt32 >(id)
#else // !defined(OO_BUGGY_TEMPLATES)
    ooHandle(oojArray)(id)
#endif // !defined(OO_BUGGY_TEMPLATES)
{
}
inline
ooHandle(oojArrayOfInt32)::ooHandleStructor(oojArrayOfInt32)(const oojArrayOfInt32 *  fromObject) :
#ifdef OO_BUGGY_TEMPLATES
    ooHandle_superclass<oojArrayOfInt32 >(ooReinterpretCast(const oojArray *,fromObject))
#else // !defined(OO_BUGGY_TEMPLATES)
    ooHandle(oojArray)(ooReinterpretCast(const oojArray *,fromObject))
#endif // !defined(OO_BUGGY_TEMPLATES)
{
}
inline
ooHandle(oojArrayOfInt32)&
ooHandle(oojArrayOfInt32)::operator=(const ooRef(oojArrayOfInt32) &  id)
{
  this->ooHandle(ooObj)::operator=(id);
  return *this;
}
inline
ooHandle(oojArrayOfInt32)&
ooHandle(oojArrayOfInt32)::operator=(const ooHandle(oojArrayOfInt32) &  objH)
{
  this->ooHandle(ooObj)::operator=(objH);
  return *this;
}
inline
ooHandle(oojArrayOfInt32)&
ooHandle(oojArrayOfInt32)::operator=(const ooShortRef(oojArrayOfInt32) &  shortId)
{
  this->ooHandle(ooObj)::operator=(shortId);
  return *this;
}
inline
ooHandle(oojArrayOfInt32)&
ooHandle(oojArrayOfInt32)::operator=(const oojArrayOfInt32 *  fromObject)
{
  this->ooHandle(ooObj)::operator=(ooReinterpretCast(const ooObj *,fromObject));
  return *this;
}
inline
oojArrayOfInt32 *
ooHandle(oojArrayOfInt32)::pin(ooMode  openMode) const
{
  return ooReinterpretCast(oojArrayOfInt32 *, this->pin_obj_internal(openMode));
}
inline
oojArrayOfInt32 *
ooHandle(oojArrayOfInt32)::operator->() const
{
  return this->vm();
}
inline
oojArrayOfInt32 &
ooHandle(oojArrayOfInt32)::operator*() const
{
  return *(this->vm());
}
inline
ooHandle(oojArrayOfInt32)::operator oojArrayOfInt32 *() const
{
  if ( _state == oocHandlePTR  )
    return ooReinterpretCast(oojArrayOfInt32 *, _ptr._obj);
  else return ooReinterpretCast(oojArrayOfInt32 *, this->get_vm());
}
inline
oojArrayOfInt32 *
ooHandle(oojArrayOfInt32)::vm() const
{
  if ( _state == oocHandlePTR && _ptr._obj != NULL )
    return ooReinterpretCast(oojArrayOfInt32 *, _ptr._obj);
  else return ooReinterpretCast(oojArrayOfInt32 *, this->get_vm());
}
inline
ooRef(oojArrayOfInt32) &
ooHandle(oojArrayOfInt32)::copy(const ooHandle(ooObj) &  nearH,
		   ooRef(oojArrayOfInt32) &              result) const
{
  this->ooHandle(ooObj)::copy(nearH, result);
  return result;
}


/* ODMG methods */
inline
oojArrayOfInt32 *
ooRef(oojArrayOfInt32)::ptr() const
{
  return this->pin();
}
inline
oojArrayOfInt32 *
ooHandle(oojArrayOfInt32)::ptr() const
{
  return this->operator oojArrayOfInt32 *();
}
class oojArrayOfInt64;


/////////////////////////////////////////////////////////////////////////////

ooTemplateSpecialization
class ooDeref(oojArrayOfInt64) : public ooDerefBase {
	friend class ooRef(oojArrayOfInt64);
  public:
    ~ooDerefStructor(oojArrayOfInt64)();
    inline oojArrayOfInt64 *operator->() const;
#ifndef OO_BUGGY_TEMPLATES
  private:
#endif // !defined(OO_BUGGY_TEMPLATES)
    ooDerefStructor(oojArrayOfInt64)(ooDeref(oojArrayOfInt64)& deref);
    ooDerefStructor(oojArrayOfInt64)(ooObj *  fromObject);
};


#ifdef OO_BUGGY_TEMPLATES

class ooHandle_superclass<oojArrayOfInt64 > : public ooHandle(oojArray) {
 protected:
  ooHandle_superclass()
    {}
  ooHandle_superclass(const ooHandle(oojArray) &  from) :
      ooHandle(oojArray)(from)
    {}
  ooHandle_superclass(const ooRef(oojArray) &  from) :
      ooHandle(oojArray)(from)
    {}
  ooHandle_superclass(const oojArray *  from) :
      ooHandle(oojArray)(from)
    {}
  ~ooHandle_superclass()
    {}
};

class ooShortRef_superclass<oojArrayOfInt64 > : public ooShortRef(oojArray) {
};

#endif // OO_BUGGY_TEMPLATES

ooTemplateSpecialization
class ooRef(oojArrayOfInt64) : public ooRef(oojArray) {
  public:
    ooRefStructor(oojArrayOfInt64)()
      {}
    ooRefStructor(oojArrayOfInt64)(const ooRef(oojArrayOfInt64)& id) :
	  ooRef(oojArray)(id)
      {}
    inline ooRefStructor(oojArrayOfInt64)(const ooHandleSuper(oojArrayOfInt64)& objH);
    inline ooRefStructor(oojArrayOfInt64)(const oojArrayOfInt64 *  fromObject);
    inline ooRef(oojArrayOfInt64)& operator=(const ooRef(oojArrayOfInt64)& id);
    inline ooRef(oojArrayOfInt64)& operator=(const ooShortRefSuper(oojArrayOfInt64) &shortId);
    inline ooRef(oojArrayOfInt64)& operator=(const ooHandleSuper(oojArrayOfInt64)& objH);
    inline ooRef(oojArrayOfInt64)& operator=(const oojArrayOfInt64 *  fromObject);
    ooStatus lookupObj(const ooHandle(ooObj)& scopeH,
		       const ooKey& key,
		       ooMode openMode = oocRead);
    ooStatus lookupObj(const ooHandle(ooObj)& scopeH,
		       const char* name,
		       ooMode openMode = oocRead);
#ifndef OO_BUGGY_TEMPLATES
    inline ooRef(oojArrayOfInt64)& copy(const ooHandle(ooObj)& nearH,
		    ooRef(oojArrayOfInt64)& newObjRef) const;
    inline ooHandle(oojArrayOfInt64)& copy(const ooHandle(ooObj)& nearH,
			ooHandle(oojArrayOfInt64)& result) const;
    inline ooHandle(oojArrayOfInt64) copy(const ooHandle(ooObj)& nearH) const;
#endif // !defined(OO_BUGGY_TEMPLATES)
    inline oojArrayOfInt64 *pin(ooMode openMode = oocRead) const;
    ooDeref(oojArrayOfInt64) operator->() const;
    /* Use pin() or use ooHandle "operator oojArrayOfInt64 *" instead of vm. */
    /* OBSOLETE */ inline oojArrayOfInt64 *vm(ooMode openMode = oocRead) const;
    // ODMG methods:
    ooRefStructor(oojArrayOfInt64)(const d_Ref_Any &from);
    oojArrayOfInt64 *ptr() const;
};

ooTemplateSpecialization
class ooShortRef(oojArrayOfInt64) :
#ifdef OO_BUGGY_TEMPLATES
			public ooShortRef_superclass<oojArrayOfInt64 >
#else // !defined(OO_BUGGY_TEMPLATES)
			public ooShortRef(oojArray)
#endif // !defined(OO_BUGGY_TEMPLATES)
					            {
  public:
    ooShortRefStructor(oojArrayOfInt64)();
    ooShortRefStructor(oojArrayOfInt64)(const ooShortRef(oojArrayOfInt64)& shortId);
    ooShortRefStructor(oojArrayOfInt64)(const ooRef(oojArrayOfInt64)& id);
    ooShortRefStructor(oojArrayOfInt64)(const ooHandleSuper(oojArrayOfInt64) &objH);
    ooShortRefStructor(oojArrayOfInt64)(const oojArrayOfInt64 *  fromObject);
    ooShortRef(oojArrayOfInt64)& operator=(const ooShortRef(oojArrayOfInt64)& shortId);
    ooShortRef(oojArrayOfInt64)& operator=(const ooRef(oojArrayOfInt64)& id);
    ooShortRef(oojArrayOfInt64)& operator=(const ooHandleSuper(oojArrayOfInt64) &objH);
    ooShortRef(oojArrayOfInt64)& operator=(const oojArrayOfInt64 *  fromObject);
};

ooTemplateSpecialization
class ooHandle(oojArrayOfInt64) :
#ifdef OO_BUGGY_TEMPLATES
		      public ooHandle_superclass<oojArrayOfInt64 >
#else // !defined(OO_BUGGY_TEMPLATES)
		      public ooHandle(oojArray)
#endif // !defined(OO_BUGGY_TEMPLATES)
                                                {
  public:
    inline ooHandleStructor(oojArrayOfInt64)();
    inline ooHandleStructor(oojArrayOfInt64)(const ooRef(oojArrayOfInt64)& id);
    inline ooHandleStructor(oojArrayOfInt64)(const ooHandle(oojArrayOfInt64)& objH);
    inline ooHandleStructor(oojArrayOfInt64)(const oojArrayOfInt64 *  fromObject);
    inline ooHandle(oojArrayOfInt64)& operator=(const ooRef(oojArrayOfInt64)& id);
    inline ooHandle(oojArrayOfInt64)& operator=(const ooHandle(oojArrayOfInt64)& objH);
    inline ooHandle(oojArrayOfInt64)& operator=(const ooShortRef(oojArrayOfInt64)& shortId);
    inline ooHandle(oojArrayOfInt64)& operator=(const oojArrayOfInt64 *  fromObject);
    ooStatus lookupObj(const ooHandle(ooObj)& scopeH,
		       const ooKey& key,
		       ooMode openMode = oocRead);
    ooStatus lookupObj(const ooHandle(ooObj)& scopeH,
		       const char* name,
		       ooMode openMode = oocRead);
    ooHandle(oojArrayOfInt64)& copy(const ooHandle(ooObj)& nearH,
		       ooHandle(oojArrayOfInt64)& result) const;
    inline ooRef(oojArrayOfInt64)& copy(const ooHandle(ooObj)& nearH,
		    ooRef(oojArrayOfInt64)& result) const;
    ooHandle(oojArrayOfInt64) copy(const ooHandle(ooObj)& nearH) const;
    inline oojArrayOfInt64 *pin(ooMode openMode = oocRead) const;
    inline oojArrayOfInt64 *operator->() const;
    inline oojArrayOfInt64 &operator*() const;
    inline operator oojArrayOfInt64 *() const;
    /* Use "operator oojArrayOfInt64 *" instead of vm. */
    /* OBSOLETE */ inline oojArrayOfInt64 *vm() const;
    // ODMG methods:
    ooHandleStructor(oojArrayOfInt64)(const d_Ref_Any &from);
    oojArrayOfInt64 *ptr() const;
};

ooTemplateSpecialization
class ooItr(oojArrayOfInt64) : public ooHandle(oojArrayOfInt64),
		    public ooIteratorObjOrContObj {
  public:
    ooItrStructor(oojArrayOfInt64)();
    ~ooItrStructor(oojArrayOfInt64)();
  private:
    // Defined only to prevent implicit definition:
    ooItrStructor(oojArrayOfInt64)(ooItr(oojArrayOfInt64)&);
    ooItr(oojArrayOfInt64)    operator=(ooItr(oojArrayOfInt64)&);
};


/* methods on ooDeref(oojArrayOfInt64) */
inline
ooDeref(oojArrayOfInt64)::ooDerefStructor(oojArrayOfInt64)(ooDeref(oojArrayOfInt64) &  deref) :
    ooDerefBase(deref.vm())
{
  this->pinCompensate();
}
inline
ooDeref(oojArrayOfInt64)::ooDerefStructor(oojArrayOfInt64)(ooObj *  fromObject) :
    ooDerefBase(fromObject)
{
}
inline
ooDeref(oojArrayOfInt64)::~ooDerefStructor(oojArrayOfInt64)()
{
}
inline
oojArrayOfInt64 *
ooDeref(oojArrayOfInt64)::operator->() const
{
  return ooReinterpretCast(oojArrayOfInt64 *, this->vm());
}


/* methods on ooRef(oojArrayOfInt64) */
inline
ooRef(oojArrayOfInt64)::ooRefStructor(oojArrayOfInt64)(const ooHandleSuper(oojArrayOfInt64)& objH) :
    ooRef(oojArray)(objH)
{
}
inline
ooRef(oojArrayOfInt64)::ooRefStructor(oojArrayOfInt64)(const oojArrayOfInt64 *  fromObject) :
    ooRef(oojArray)(ooReinterpretCast(const oojArray *, fromObject))
{
}
inline
ooRef(oojArrayOfInt64)&
ooRef(oojArrayOfInt64)::operator=(const ooRef(oojArrayOfInt64) &  id)
{
  this->ooId::operator=(id);
  return *this;
}
inline
ooRef(oojArrayOfInt64)&
ooRef(oojArrayOfInt64)::operator=(const ooShortRefSuper(oojArrayOfInt64) &  shortId)
{
  this->ooRef(ooObj)::operator=(shortId);
  return *this;
}
inline
ooRef(oojArrayOfInt64)&
ooRef(oojArrayOfInt64)::operator=(const ooHandleSuper(oojArrayOfInt64) &  objH)
{
  this->ooRef(ooObj)::operator=(objH);
  return *this;
}
inline
ooRef(oojArrayOfInt64)&
ooRef(oojArrayOfInt64)::operator=(const oojArrayOfInt64 *  fromObject)
{
  this->ooRef(ooObj)::operator=(ooReinterpretCast(const ooObj *, fromObject));
  return *this;
}
inline
oojArrayOfInt64 *
ooRef(oojArrayOfInt64)::pin(ooMode  openMode) const
{
  return ooReinterpretCast(oojArrayOfInt64 *, this->pin_ref_internal(openMode));
}
inline
oojArrayOfInt64 *
ooRef(oojArrayOfInt64)::vm(ooMode  openMode) const
{
  return this->pin(openMode);
}
#ifndef OO_BUGGY_TEMPLATES
inline
ooHandle(oojArrayOfInt64) &
ooRef(oojArrayOfInt64)::copy(const ooHandle(ooObj) &  nearH,
		ooHandle(oojArrayOfInt64) &           result) const
{
  this->ooRef(ooObj)::copy(nearH, result);
  return result;
}
inline
ooRef(oojArrayOfInt64) &
ooRef(oojArrayOfInt64)::copy(const ooHandle(ooObj) &  nearH,
		ooRef(oojArrayOfInt64) &              newObjRef) const
{
  this->ooRef(ooObj)::copy(nearH, newObjRef);
  return newObjRef;
}
inline
ooHandle(oojArrayOfInt64)
ooRef(oojArrayOfInt64)::copy(const ooHandle(ooObj) &  nearH) const
{
  ooHandle(oojArrayOfInt64) result;
  this->ooRef(ooObj)::copy(nearH, result);
  return result;
}
#endif // !defined(OO_BUGGY_TEMPLATES)
inline
ooDeref(oojArrayOfInt64)
ooRef(oojArrayOfInt64)::operator->() const
{
  ooDeref(oojArrayOfInt64) result(this->pin_ref_internal(oocRead));
  return result;
}


/* methods on ooShortRef(oojArrayOfInt64) */
inline
ooShortRef(oojArrayOfInt64) &
ooShortRef(oojArrayOfInt64)::operator=(const ooShortRef(oojArrayOfInt64) &  shortId)
{
  this->ooShortId::operator=(shortId);
  return *this;
}
inline
ooShortRef(oojArrayOfInt64) &
ooShortRef(oojArrayOfInt64)::operator=(const ooRef(oojArrayOfInt64) &  id)
{
  this->ooShortId::operator=(id);
  return *this;
}
inline
ooShortRef(oojArrayOfInt64) &
ooShortRef(oojArrayOfInt64)::operator=(const ooHandleSuper(oojArrayOfInt64) &  objH)
{
  this->ooShortId::operator=(objH);
  return *this;
}
inline
ooShortRef(oojArrayOfInt64)&
ooShortRef(oojArrayOfInt64)::operator=(const oojArrayOfInt64 *  fromObject)
{
  this->ooShortId::operator=(ooReinterpretCast(const ooObj *,fromObject));
  return *this;
}
inline
ooShortRef(oojArrayOfInt64)::ooShortRefStructor(oojArrayOfInt64)()
{
}
#ifdef OO_BUGGY_TEMPLATES
inline
ooShortRef(oojArrayOfInt64)::ooShortRefStructor(oojArrayOfInt64)(const ooShortRef(oojArrayOfInt64) &  shortId)
{
  *this = shortId;
}
#else // !defined(OO_BUGGY_TEMPLATES)
inline
ooShortRef(oojArrayOfInt64)::ooShortRefStructor(oojArrayOfInt64)(const ooShortRef(oojArrayOfInt64) &  shortId) :
    ooShortRef(oojArray)(shortId)
{
}
#endif // !defined(OO_BUGGY_TEMPLATES)
#ifdef OO_BUGGY_TEMPLATES
inline
ooShortRef(oojArrayOfInt64)::ooShortRefStructor(oojArrayOfInt64)(const ooRef(oojArrayOfInt64) &  id)
{
  *this = id;
}
#else // !defined(OO_BUGGY_TEMPLATES)
inline
ooShortRef(oojArrayOfInt64)::ooShortRefStructor(oojArrayOfInt64)(const ooRef(oojArrayOfInt64) &  id) :
    ooShortRef(oojArray)(id)
{
}
#endif // !defined(OO_BUGGY_TEMPLATES)
#ifdef OO_BUGGY_TEMPLATES
inline
ooShortRef(oojArrayOfInt64)::ooShortRefStructor(oojArrayOfInt64)(const ooHandleSuper(oojArrayOfInt64) &  objH)
{
  *this = objH;
}
#else // !defined(OO_BUGGY_TEMPLATES)
inline
ooShortRef(oojArrayOfInt64)::ooShortRefStructor(oojArrayOfInt64)(const ooHandleSuper(oojArrayOfInt64) &  objH) :
    ooShortRef(oojArray)(objH)
{
}
#endif // !defined(OO_BUGGY_TEMPLATES)
#ifdef OO_BUGGY_TEMPLATES
inline
ooShortRef(oojArrayOfInt64)::ooShortRefStructor(oojArrayOfInt64)(const oojArrayOfInt64 *  fromObject)
{
  *this = fromObject;
}
#else // !defined(OO_BUGGY_TEMPLATES)
inline
ooShortRef(oojArrayOfInt64)::ooShortRefStructor(oojArrayOfInt64)(const oojArrayOfInt64 *  fromObject) :
    ooShortRef(oojArray)(ooReinterpretCast(const oojArray *,fromObject))
{
}
#endif // !defined(OO_BUGGY_TEMPLATES)


/* methods on ooHandle(oojArrayOfInt64) */
inline
ooHandle(oojArrayOfInt64)::ooHandleStructor(oojArrayOfInt64)()
{
}
inline
ooHandle(oojArrayOfInt64)::ooHandleStructor(oojArrayOfInt64)(const ooHandle(oojArrayOfInt64) &  objH) :
#ifdef OO_BUGGY_TEMPLATES
    ooHandle_superclass<oojArrayOfInt64 >(objH)
#else // !defined(OO_BUGGY_TEMPLATES)
    ooHandle(oojArray)(objH)
#endif // !defined(OO_BUGGY_TEMPLATES)
{
}
inline
ooHandle(oojArrayOfInt64)::ooHandleStructor(oojArrayOfInt64)(const ooRef(oojArrayOfInt64) &  id) :
#ifdef OO_BUGGY_TEMPLATES
    ooHandle_superclass<oojArrayOfInt64 >(id)
#else // !defined(OO_BUGGY_TEMPLATES)
    ooHandle(oojArray)(id)
#endif // !defined(OO_BUGGY_TEMPLATES)
{
}
inline
ooHandle(oojArrayOfInt64)::ooHandleStructor(oojArrayOfInt64)(const oojArrayOfInt64 *  fromObject) :
#ifdef OO_BUGGY_TEMPLATES
    ooHandle_superclass<oojArrayOfInt64 >(ooReinterpretCast(const oojArray *,fromObject))
#else // !defined(OO_BUGGY_TEMPLATES)
    ooHandle(oojArray)(ooReinterpretCast(const oojArray *,fromObject))
#endif // !defined(OO_BUGGY_TEMPLATES)
{
}
inline
ooHandle(oojArrayOfInt64)&
ooHandle(oojArrayOfInt64)::operator=(const ooRef(oojArrayOfInt64) &  id)
{
  this->ooHandle(ooObj)::operator=(id);
  return *this;
}
inline
ooHandle(oojArrayOfInt64)&
ooHandle(oojArrayOfInt64)::operator=(const ooHandle(oojArrayOfInt64) &  objH)
{
  this->ooHandle(ooObj)::operator=(objH);
  return *this;
}
inline
ooHandle(oojArrayOfInt64)&
ooHandle(oojArrayOfInt64)::operator=(const ooShortRef(oojArrayOfInt64) &  shortId)
{
  this->ooHandle(ooObj)::operator=(shortId);
  return *this;
}
inline
ooHandle(oojArrayOfInt64)&
ooHandle(oojArrayOfInt64)::operator=(const oojArrayOfInt64 *  fromObject)
{
  this->ooHandle(ooObj)::operator=(ooReinterpretCast(const ooObj *,fromObject));
  return *this;
}
inline
oojArrayOfInt64 *
ooHandle(oojArrayOfInt64)::pin(ooMode  openMode) const
{
  return ooReinterpretCast(oojArrayOfInt64 *, this->pin_obj_internal(openMode));
}
inline
oojArrayOfInt64 *
ooHandle(oojArrayOfInt64)::operator->() const
{
  return this->vm();
}
inline
oojArrayOfInt64 &
ooHandle(oojArrayOfInt64)::operator*() const
{
  return *(this->vm());
}
inline
ooHandle(oojArrayOfInt64)::operator oojArrayOfInt64 *() const
{
  if ( _state == oocHandlePTR  )
    return ooReinterpretCast(oojArrayOfInt64 *, _ptr._obj);
  else return ooReinterpretCast(oojArrayOfInt64 *, this->get_vm());
}
inline
oojArrayOfInt64 *
ooHandle(oojArrayOfInt64)::vm() const
{
  if ( _state == oocHandlePTR && _ptr._obj != NULL )
    return ooReinterpretCast(oojArrayOfInt64 *, _ptr._obj);
  else return ooReinterpretCast(oojArrayOfInt64 *, this->get_vm());
}
inline
ooRef(oojArrayOfInt64) &
ooHandle(oojArrayOfInt64)::copy(const ooHandle(ooObj) &  nearH,
		   ooRef(oojArrayOfInt64) &              result) const
{
  this->ooHandle(ooObj)::copy(nearH, result);
  return result;
}


/* ODMG methods */
inline
oojArrayOfInt64 *
ooRef(oojArrayOfInt64)::ptr() const
{
  return this->pin();
}
inline
oojArrayOfInt64 *
ooHandle(oojArrayOfInt64)::ptr() const
{
  return this->operator oojArrayOfInt64 *();
}
class oojArrayOfCharacter;


/////////////////////////////////////////////////////////////////////////////

ooTemplateSpecialization
class ooDeref(oojArrayOfCharacter) : public ooDerefBase {
	friend class ooRef(oojArrayOfCharacter);
  public:
    ~ooDerefStructor(oojArrayOfCharacter)();
    inline oojArrayOfCharacter *operator->() const;
#ifndef OO_BUGGY_TEMPLATES
  private:
#endif // !defined(OO_BUGGY_TEMPLATES)
    ooDerefStructor(oojArrayOfCharacter)(ooDeref(oojArrayOfCharacter)& deref);
    ooDerefStructor(oojArrayOfCharacter)(ooObj *  fromObject);
};


#ifdef OO_BUGGY_TEMPLATES

class ooHandle_superclass<oojArrayOfCharacter > : public ooHandle(oojArray) {
 protected:
  ooHandle_superclass()
    {}
  ooHandle_superclass(const ooHandle(oojArray) &  from) :
      ooHandle(oojArray)(from)
    {}
  ooHandle_superclass(const ooRef(oojArray) &  from) :
      ooHandle(oojArray)(from)
    {}
  ooHandle_superclass(const oojArray *  from) :
      ooHandle(oojArray)(from)
    {}
  ~ooHandle_superclass()
    {}
};

class ooShortRef_superclass<oojArrayOfCharacter > : public ooShortRef(oojArray) {
};

#endif // OO_BUGGY_TEMPLATES

ooTemplateSpecialization
class ooRef(oojArrayOfCharacter) : public ooRef(oojArray) {
  public:
    ooRefStructor(oojArrayOfCharacter)()
      {}
    ooRefStructor(oojArrayOfCharacter)(const ooRef(oojArrayOfCharacter)& id) :
	  ooRef(oojArray)(id)
      {}
    inline ooRefStructor(oojArrayOfCharacter)(const ooHandleSuper(oojArrayOfCharacter)& objH);
    inline ooRefStructor(oojArrayOfCharacter)(const oojArrayOfCharacter *  fromObject);
    inline ooRef(oojArrayOfCharacter)& operator=(const ooRef(oojArrayOfCharacter)& id);
    inline ooRef(oojArrayOfCharacter)& operator=(const ooShortRefSuper(oojArrayOfCharacter) &shortId);
    inline ooRef(oojArrayOfCharacter)& operator=(const ooHandleSuper(oojArrayOfCharacter)& objH);
    inline ooRef(oojArrayOfCharacter)& operator=(const oojArrayOfCharacter *  fromObject);
    ooStatus lookupObj(const ooHandle(ooObj)& scopeH,
		       const ooKey& key,
		       ooMode openMode = oocRead);
    ooStatus lookupObj(const ooHandle(ooObj)& scopeH,
		       const char* name,
		       ooMode openMode = oocRead);
#ifndef OO_BUGGY_TEMPLATES
    inline ooRef(oojArrayOfCharacter)& copy(const ooHandle(ooObj)& nearH,
		    ooRef(oojArrayOfCharacter)& newObjRef) const;
    inline ooHandle(oojArrayOfCharacter)& copy(const ooHandle(ooObj)& nearH,
			ooHandle(oojArrayOfCharacter)& result) const;
    inline ooHandle(oojArrayOfCharacter) copy(const ooHandle(ooObj)& nearH) const;
#endif // !defined(OO_BUGGY_TEMPLATES)
    inline oojArrayOfCharacter *pin(ooMode openMode = oocRead) const;
    ooDeref(oojArrayOfCharacter) operator->() const;
    /* Use pin() or use ooHandle "operator oojArrayOfCharacter *" instead of vm. */
    /* OBSOLETE */ inline oojArrayOfCharacter *vm(ooMode openMode = oocRead) const;
    // ODMG methods:
    ooRefStructor(oojArrayOfCharacter)(const d_Ref_Any &from);
    oojArrayOfCharacter *ptr() const;
};

ooTemplateSpecialization
class ooShortRef(oojArrayOfCharacter) :
#ifdef OO_BUGGY_TEMPLATES
			public ooShortRef_superclass<oojArrayOfCharacter >
#else // !defined(OO_BUGGY_TEMPLATES)
			public ooShortRef(oojArray)
#endif // !defined(OO_BUGGY_TEMPLATES)
					            {
  public:
    ooShortRefStructor(oojArrayOfCharacter)();
    ooShortRefStructor(oojArrayOfCharacter)(const ooShortRef(oojArrayOfCharacter)& shortId);
    ooShortRefStructor(oojArrayOfCharacter)(const ooRef(oojArrayOfCharacter)& id);
    ooShortRefStructor(oojArrayOfCharacter)(const ooHandleSuper(oojArrayOfCharacter) &objH);
    ooShortRefStructor(oojArrayOfCharacter)(const oojArrayOfCharacter *  fromObject);
    ooShortRef(oojArrayOfCharacter)& operator=(const ooShortRef(oojArrayOfCharacter)& shortId);
    ooShortRef(oojArrayOfCharacter)& operator=(const ooRef(oojArrayOfCharacter)& id);
    ooShortRef(oojArrayOfCharacter)& operator=(const ooHandleSuper(oojArrayOfCharacter) &objH);
    ooShortRef(oojArrayOfCharacter)& operator=(const oojArrayOfCharacter *  fromObject);
};

ooTemplateSpecialization
class ooHandle(oojArrayOfCharacter) :
#ifdef OO_BUGGY_TEMPLATES
		      public ooHandle_superclass<oojArrayOfCharacter >
#else // !defined(OO_BUGGY_TEMPLATES)
		      public ooHandle(oojArray)
#endif // !defined(OO_BUGGY_TEMPLATES)
                                                {
  public:
    inline ooHandleStructor(oojArrayOfCharacter)();
    inline ooHandleStructor(oojArrayOfCharacter)(const ooRef(oojArrayOfCharacter)& id);
    inline ooHandleStructor(oojArrayOfCharacter)(const ooHandle(oojArrayOfCharacter)& objH);
    inline ooHandleStructor(oojArrayOfCharacter)(const oojArrayOfCharacter *  fromObject);
    inline ooHandle(oojArrayOfCharacter)& operator=(const ooRef(oojArrayOfCharacter)& id);
    inline ooHandle(oojArrayOfCharacter)& operator=(const ooHandle(oojArrayOfCharacter)& objH);
    inline ooHandle(oojArrayOfCharacter)& operator=(const ooShortRef(oojArrayOfCharacter)& shortId);
    inline ooHandle(oojArrayOfCharacter)& operator=(const oojArrayOfCharacter *  fromObject);
    ooStatus lookupObj(const ooHandle(ooObj)& scopeH,
		       const ooKey& key,
		       ooMode openMode = oocRead);
    ooStatus lookupObj(const ooHandle(ooObj)& scopeH,
		       const char* name,
		       ooMode openMode = oocRead);
    ooHandle(oojArrayOfCharacter)& copy(const ooHandle(ooObj)& nearH,
		       ooHandle(oojArrayOfCharacter)& result) const;
    inline ooRef(oojArrayOfCharacter)& copy(const ooHandle(ooObj)& nearH,
		    ooRef(oojArrayOfCharacter)& result) const;
    ooHandle(oojArrayOfCharacter) copy(const ooHandle(ooObj)& nearH) const;
    inline oojArrayOfCharacter *pin(ooMode openMode = oocRead) const;
    inline oojArrayOfCharacter *operator->() const;
    inline oojArrayOfCharacter &operator*() const;
    inline operator oojArrayOfCharacter *() const;
    /* Use "operator oojArrayOfCharacter *" instead of vm. */
    /* OBSOLETE */ inline oojArrayOfCharacter *vm() const;
    // ODMG methods:
    ooHandleStructor(oojArrayOfCharacter)(const d_Ref_Any &from);
    oojArrayOfCharacter *ptr() const;
};

ooTemplateSpecialization
class ooItr(oojArrayOfCharacter) : public ooHandle(oojArrayOfCharacter),
		    public ooIteratorObjOrContObj {
  public:
    ooItrStructor(oojArrayOfCharacter)();
    ~ooItrStructor(oojArrayOfCharacter)();
  private:
    // Defined only to prevent implicit definition:
    ooItrStructor(oojArrayOfCharacter)(ooItr(oojArrayOfCharacter)&);
    ooItr(oojArrayOfCharacter)    operator=(ooItr(oojArrayOfCharacter)&);
};


/* methods on ooDeref(oojArrayOfCharacter) */
inline
ooDeref(oojArrayOfCharacter)::ooDerefStructor(oojArrayOfCharacter)(ooDeref(oojArrayOfCharacter) &  deref) :
    ooDerefBase(deref.vm())
{
  this->pinCompensate();
}
inline
ooDeref(oojArrayOfCharacter)::ooDerefStructor(oojArrayOfCharacter)(ooObj *  fromObject) :
    ooDerefBase(fromObject)
{
}
inline
ooDeref(oojArrayOfCharacter)::~ooDerefStructor(oojArrayOfCharacter)()
{
}
inline
oojArrayOfCharacter *
ooDeref(oojArrayOfCharacter)::operator->() const
{
  return ooReinterpretCast(oojArrayOfCharacter *, this->vm());
}


/* methods on ooRef(oojArrayOfCharacter) */
inline
ooRef(oojArrayOfCharacter)::ooRefStructor(oojArrayOfCharacter)(const ooHandleSuper(oojArrayOfCharacter)& objH) :
    ooRef(oojArray)(objH)
{
}
inline
ooRef(oojArrayOfCharacter)::ooRefStructor(oojArrayOfCharacter)(const oojArrayOfCharacter *  fromObject) :
    ooRef(oojArray)(ooReinterpretCast(const oojArray *, fromObject))
{
}
inline
ooRef(oojArrayOfCharacter)&
ooRef(oojArrayOfCharacter)::operator=(const ooRef(oojArrayOfCharacter) &  id)
{
  this->ooId::operator=(id);
  return *this;
}
inline
ooRef(oojArrayOfCharacter)&
ooRef(oojArrayOfCharacter)::operator=(const ooShortRefSuper(oojArrayOfCharacter) &  shortId)
{
  this->ooRef(ooObj)::operator=(shortId);
  return *this;
}
inline
ooRef(oojArrayOfCharacter)&
ooRef(oojArrayOfCharacter)::operator=(const ooHandleSuper(oojArrayOfCharacter) &  objH)
{
  this->ooRef(ooObj)::operator=(objH);
  return *this;
}
inline
ooRef(oojArrayOfCharacter)&
ooRef(oojArrayOfCharacter)::operator=(const oojArrayOfCharacter *  fromObject)
{
  this->ooRef(ooObj)::operator=(ooReinterpretCast(const ooObj *, fromObject));
  return *this;
}
inline
oojArrayOfCharacter *
ooRef(oojArrayOfCharacter)::pin(ooMode  openMode) const
{
  return ooReinterpretCast(oojArrayOfCharacter *, this->pin_ref_internal(openMode));
}
inline
oojArrayOfCharacter *
ooRef(oojArrayOfCharacter)::vm(ooMode  openMode) const
{
  return this->pin(openMode);
}
#ifndef OO_BUGGY_TEMPLATES
inline
ooHandle(oojArrayOfCharacter) &
ooRef(oojArrayOfCharacter)::copy(const ooHandle(ooObj) &  nearH,
		ooHandle(oojArrayOfCharacter) &           result) const
{
  this->ooRef(ooObj)::copy(nearH, result);
  return result;
}
inline
ooRef(oojArrayOfCharacter) &
ooRef(oojArrayOfCharacter)::copy(const ooHandle(ooObj) &  nearH,
		ooRef(oojArrayOfCharacter) &              newObjRef) const
{
  this->ooRef(ooObj)::copy(nearH, newObjRef);
  return newObjRef;
}
inline
ooHandle(oojArrayOfCharacter)
ooRef(oojArrayOfCharacter)::copy(const ooHandle(ooObj) &  nearH) const
{
  ooHandle(oojArrayOfCharacter) result;
  this->ooRef(ooObj)::copy(nearH, result);
  return result;
}
#endif // !defined(OO_BUGGY_TEMPLATES)
inline
ooDeref(oojArrayOfCharacter)
ooRef(oojArrayOfCharacter)::operator->() const
{
  ooDeref(oojArrayOfCharacter) result(this->pin_ref_internal(oocRead));
  return result;
}


/* methods on ooShortRef(oojArrayOfCharacter) */
inline
ooShortRef(oojArrayOfCharacter) &
ooShortRef(oojArrayOfCharacter)::operator=(const ooShortRef(oojArrayOfCharacter) &  shortId)
{
  this->ooShortId::operator=(shortId);
  return *this;
}
inline
ooShortRef(oojArrayOfCharacter) &
ooShortRef(oojArrayOfCharacter)::operator=(const ooRef(oojArrayOfCharacter) &  id)
{
  this->ooShortId::operator=(id);
  return *this;
}
inline
ooShortRef(oojArrayOfCharacter) &
ooShortRef(oojArrayOfCharacter)::operator=(const ooHandleSuper(oojArrayOfCharacter) &  objH)
{
  this->ooShortId::operator=(objH);
  return *this;
}
inline
ooShortRef(oojArrayOfCharacter)&
ooShortRef(oojArrayOfCharacter)::operator=(const oojArrayOfCharacter *  fromObject)
{
  this->ooShortId::operator=(ooReinterpretCast(const ooObj *,fromObject));
  return *this;
}
inline
ooShortRef(oojArrayOfCharacter)::ooShortRefStructor(oojArrayOfCharacter)()
{
}
#ifdef OO_BUGGY_TEMPLATES
inline
ooShortRef(oojArrayOfCharacter)::ooShortRefStructor(oojArrayOfCharacter)(const ooShortRef(oojArrayOfCharacter) &  shortId)
{
  *this = shortId;
}
#else // !defined(OO_BUGGY_TEMPLATES)
inline
ooShortRef(oojArrayOfCharacter)::ooShortRefStructor(oojArrayOfCharacter)(const ooShortRef(oojArrayOfCharacter) &  shortId) :
    ooShortRef(oojArray)(shortId)
{
}
#endif // !defined(OO_BUGGY_TEMPLATES)
#ifdef OO_BUGGY_TEMPLATES
inline
ooShortRef(oojArrayOfCharacter)::ooShortRefStructor(oojArrayOfCharacter)(const ooRef(oojArrayOfCharacter) &  id)
{
  *this = id;
}
#else // !defined(OO_BUGGY_TEMPLATES)
inline
ooShortRef(oojArrayOfCharacter)::ooShortRefStructor(oojArrayOfCharacter)(const ooRef(oojArrayOfCharacter) &  id) :
    ooShortRef(oojArray)(id)
{
}
#endif // !defined(OO_BUGGY_TEMPLATES)
#ifdef OO_BUGGY_TEMPLATES
inline
ooShortRef(oojArrayOfCharacter)::ooShortRefStructor(oojArrayOfCharacter)(const ooHandleSuper(oojArrayOfCharacter) &  objH)
{
  *this = objH;
}
#else // !defined(OO_BUGGY_TEMPLATES)
inline
ooShortRef(oojArrayOfCharacter)::ooShortRefStructor(oojArrayOfCharacter)(const ooHandleSuper(oojArrayOfCharacter) &  objH) :
    ooShortRef(oojArray)(objH)
{
}
#endif // !defined(OO_BUGGY_TEMPLATES)
#ifdef OO_BUGGY_TEMPLATES
inline
ooShortRef(oojArrayOfCharacter)::ooShortRefStructor(oojArrayOfCharacter)(const oojArrayOfCharacter *  fromObject)
{
  *this = fromObject;
}
#else // !defined(OO_BUGGY_TEMPLATES)
inline
ooShortRef(oojArrayOfCharacter)::ooShortRefStructor(oojArrayOfCharacter)(const oojArrayOfCharacter *  fromObject) :
    ooShortRef(oojArray)(ooReinterpretCast(const oojArray *,fromObject))
{
}
#endif // !defined(OO_BUGGY_TEMPLATES)


/* methods on ooHandle(oojArrayOfCharacter) */
inline
ooHandle(oojArrayOfCharacter)::ooHandleStructor(oojArrayOfCharacter)()
{
}
inline
ooHandle(oojArrayOfCharacter)::ooHandleStructor(oojArrayOfCharacter)(const ooHandle(oojArrayOfCharacter) &  objH) :
#ifdef OO_BUGGY_TEMPLATES
    ooHandle_superclass<oojArrayOfCharacter >(objH)
#else // !defined(OO_BUGGY_TEMPLATES)
    ooHandle(oojArray)(objH)
#endif // !defined(OO_BUGGY_TEMPLATES)
{
}
inline
ooHandle(oojArrayOfCharacter)::ooHandleStructor(oojArrayOfCharacter)(const ooRef(oojArrayOfCharacter) &  id) :
#ifdef OO_BUGGY_TEMPLATES
    ooHandle_superclass<oojArrayOfCharacter >(id)
#else // !defined(OO_BUGGY_TEMPLATES)
    ooHandle(oojArray)(id)
#endif // !defined(OO_BUGGY_TEMPLATES)
{
}
inline
ooHandle(oojArrayOfCharacter)::ooHandleStructor(oojArrayOfCharacter)(const oojArrayOfCharacter *  fromObject) :
#ifdef OO_BUGGY_TEMPLATES
    ooHandle_superclass<oojArrayOfCharacter >(ooReinterpretCast(const oojArray *,fromObject))
#else // !defined(OO_BUGGY_TEMPLATES)
    ooHandle(oojArray)(ooReinterpretCast(const oojArray *,fromObject))
#endif // !defined(OO_BUGGY_TEMPLATES)
{
}
inline
ooHandle(oojArrayOfCharacter)&
ooHandle(oojArrayOfCharacter)::operator=(const ooRef(oojArrayOfCharacter) &  id)
{
  this->ooHandle(ooObj)::operator=(id);
  return *this;
}
inline
ooHandle(oojArrayOfCharacter)&
ooHandle(oojArrayOfCharacter)::operator=(const ooHandle(oojArrayOfCharacter) &  objH)
{
  this->ooHandle(ooObj)::operator=(objH);
  return *this;
}
inline
ooHandle(oojArrayOfCharacter)&
ooHandle(oojArrayOfCharacter)::operator=(const ooShortRef(oojArrayOfCharacter) &  shortId)
{
  this->ooHandle(ooObj)::operator=(shortId);
  return *this;
}
inline
ooHandle(oojArrayOfCharacter)&
ooHandle(oojArrayOfCharacter)::operator=(const oojArrayOfCharacter *  fromObject)
{
  this->ooHandle(ooObj)::operator=(ooReinterpretCast(const ooObj *,fromObject));
  return *this;
}
inline
oojArrayOfCharacter *
ooHandle(oojArrayOfCharacter)::pin(ooMode  openMode) const
{
  return ooReinterpretCast(oojArrayOfCharacter *, this->pin_obj_internal(openMode));
}
inline
oojArrayOfCharacter *
ooHandle(oojArrayOfCharacter)::operator->() const
{
  return this->vm();
}
inline
oojArrayOfCharacter &
ooHandle(oojArrayOfCharacter)::operator*() const
{
  return *(this->vm());
}
inline
ooHandle(oojArrayOfCharacter)::operator oojArrayOfCharacter *() const
{
  if ( _state == oocHandlePTR  )
    return ooReinterpretCast(oojArrayOfCharacter *, _ptr._obj);
  else return ooReinterpretCast(oojArrayOfCharacter *, this->get_vm());
}
inline
oojArrayOfCharacter *
ooHandle(oojArrayOfCharacter)::vm() const
{
  if ( _state == oocHandlePTR && _ptr._obj != NULL )
    return ooReinterpretCast(oojArrayOfCharacter *, _ptr._obj);
  else return ooReinterpretCast(oojArrayOfCharacter *, this->get_vm());
}
inline
ooRef(oojArrayOfCharacter) &
ooHandle(oojArrayOfCharacter)::copy(const ooHandle(ooObj) &  nearH,
		   ooRef(oojArrayOfCharacter) &              result) const
{
  this->ooHandle(ooObj)::copy(nearH, result);
  return result;
}


/* ODMG methods */
inline
oojArrayOfCharacter *
ooRef(oojArrayOfCharacter)::ptr() const
{
  return this->pin();
}
inline
oojArrayOfCharacter *
ooHandle(oojArrayOfCharacter)::ptr() const
{
  return this->operator oojArrayOfCharacter *();
}
class oojArrayOfBoolean;


/////////////////////////////////////////////////////////////////////////////

ooTemplateSpecialization
class ooDeref(oojArrayOfBoolean) : public ooDerefBase {
	friend class ooRef(oojArrayOfBoolean);
  public:
    ~ooDerefStructor(oojArrayOfBoolean)();
    inline oojArrayOfBoolean *operator->() const;
#ifndef OO_BUGGY_TEMPLATES
  private:
#endif // !defined(OO_BUGGY_TEMPLATES)
    ooDerefStructor(oojArrayOfBoolean)(ooDeref(oojArrayOfBoolean)& deref);
    ooDerefStructor(oojArrayOfBoolean)(ooObj *  fromObject);
};


#ifdef OO_BUGGY_TEMPLATES

class ooHandle_superclass<oojArrayOfBoolean > : public ooHandle(oojArray) {
 protected:
  ooHandle_superclass()
    {}
  ooHandle_superclass(const ooHandle(oojArray) &  from) :
      ooHandle(oojArray)(from)
    {}
  ooHandle_superclass(const ooRef(oojArray) &  from) :
      ooHandle(oojArray)(from)
    {}
  ooHandle_superclass(const oojArray *  from) :
      ooHandle(oojArray)(from)
    {}
  ~ooHandle_superclass()
    {}
};

class ooShortRef_superclass<oojArrayOfBoolean > : public ooShortRef(oojArray) {
};

#endif // OO_BUGGY_TEMPLATES

ooTemplateSpecialization
class ooRef(oojArrayOfBoolean) : public ooRef(oojArray) {
  public:
    ooRefStructor(oojArrayOfBoolean)()
      {}
    ooRefStructor(oojArrayOfBoolean)(const ooRef(oojArrayOfBoolean)& id) :
	  ooRef(oojArray)(id)
      {}
    inline ooRefStructor(oojArrayOfBoolean)(const ooHandleSuper(oojArrayOfBoolean)& objH);
    inline ooRefStructor(oojArrayOfBoolean)(const oojArrayOfBoolean *  fromObject);
    inline ooRef(oojArrayOfBoolean)& operator=(const ooRef(oojArrayOfBoolean)& id);
    inline ooRef(oojArrayOfBoolean)& operator=(const ooShortRefSuper(oojArrayOfBoolean) &shortId);
    inline ooRef(oojArrayOfBoolean)& operator=(const ooHandleSuper(oojArrayOfBoolean)& objH);
    inline ooRef(oojArrayOfBoolean)& operator=(const oojArrayOfBoolean *  fromObject);
    ooStatus lookupObj(const ooHandle(ooObj)& scopeH,
		       const ooKey& key,
		       ooMode openMode = oocRead);
    ooStatus lookupObj(const ooHandle(ooObj)& scopeH,
		       const char* name,
		       ooMode openMode = oocRead);
#ifndef OO_BUGGY_TEMPLATES
    inline ooRef(oojArrayOfBoolean)& copy(const ooHandle(ooObj)& nearH,
		    ooRef(oojArrayOfBoolean)& newObjRef) const;
    inline ooHandle(oojArrayOfBoolean)& copy(const ooHandle(ooObj)& nearH,
			ooHandle(oojArrayOfBoolean)& result) const;
    inline ooHandle(oojArrayOfBoolean) copy(const ooHandle(ooObj)& nearH) const;
#endif // !defined(OO_BUGGY_TEMPLATES)
    inline oojArrayOfBoolean *pin(ooMode openMode = oocRead) const;
    ooDeref(oojArrayOfBoolean) operator->() const;
    /* Use pin() or use ooHandle "operator oojArrayOfBoolean *" instead of vm. */
    /* OBSOLETE */ inline oojArrayOfBoolean *vm(ooMode openMode = oocRead) const;
    // ODMG methods:
    ooRefStructor(oojArrayOfBoolean)(const d_Ref_Any &from);
    oojArrayOfBoolean *ptr() const;
};

ooTemplateSpecialization
class ooShortRef(oojArrayOfBoolean) :
#ifdef OO_BUGGY_TEMPLATES
			public ooShortRef_superclass<oojArrayOfBoolean >
#else // !defined(OO_BUGGY_TEMPLATES)
			public ooShortRef(oojArray)
#endif // !defined(OO_BUGGY_TEMPLATES)
					            {
  public:
    ooShortRefStructor(oojArrayOfBoolean)();
    ooShortRefStructor(oojArrayOfBoolean)(const ooShortRef(oojArrayOfBoolean)& shortId);
    ooShortRefStructor(oojArrayOfBoolean)(const ooRef(oojArrayOfBoolean)& id);
    ooShortRefStructor(oojArrayOfBoolean)(const ooHandleSuper(oojArrayOfBoolean) &objH);
    ooShortRefStructor(oojArrayOfBoolean)(const oojArrayOfBoolean *  fromObject);
    ooShortRef(oojArrayOfBoolean)& operator=(const ooShortRef(oojArrayOfBoolean)& shortId);
    ooShortRef(oojArrayOfBoolean)& operator=(const ooRef(oojArrayOfBoolean)& id);
    ooShortRef(oojArrayOfBoolean)& operator=(const ooHandleSuper(oojArrayOfBoolean) &objH);
    ooShortRef(oojArrayOfBoolean)& operator=(const oojArrayOfBoolean *  fromObject);
};

ooTemplateSpecialization
class ooHandle(oojArrayOfBoolean) :
#ifdef OO_BUGGY_TEMPLATES
		      public ooHandle_superclass<oojArrayOfBoolean >
#else // !defined(OO_BUGGY_TEMPLATES)
		      public ooHandle(oojArray)
#endif // !defined(OO_BUGGY_TEMPLATES)
                                                {
  public:
    inline ooHandleStructor(oojArrayOfBoolean)();
    inline ooHandleStructor(oojArrayOfBoolean)(const ooRef(oojArrayOfBoolean)& id);
    inline ooHandleStructor(oojArrayOfBoolean)(const ooHandle(oojArrayOfBoolean)& objH);
    inline ooHandleStructor(oojArrayOfBoolean)(const oojArrayOfBoolean *  fromObject);
    inline ooHandle(oojArrayOfBoolean)& operator=(const ooRef(oojArrayOfBoolean)& id);
    inline ooHandle(oojArrayOfBoolean)& operator=(const ooHandle(oojArrayOfBoolean)& objH);
    inline ooHandle(oojArrayOfBoolean)& operator=(const ooShortRef(oojArrayOfBoolean)& shortId);
    inline ooHandle(oojArrayOfBoolean)& operator=(const oojArrayOfBoolean *  fromObject);
    ooStatus lookupObj(const ooHandle(ooObj)& scopeH,
		       const ooKey& key,
		       ooMode openMode = oocRead);
    ooStatus lookupObj(const ooHandle(ooObj)& scopeH,
		       const char* name,
		       ooMode openMode = oocRead);
    ooHandle(oojArrayOfBoolean)& copy(const ooHandle(ooObj)& nearH,
		       ooHandle(oojArrayOfBoolean)& result) const;
    inline ooRef(oojArrayOfBoolean)& copy(const ooHandle(ooObj)& nearH,
		    ooRef(oojArrayOfBoolean)& result) const;
    ooHandle(oojArrayOfBoolean) copy(const ooHandle(ooObj)& nearH) const;
    inline oojArrayOfBoolean *pin(ooMode openMode = oocRead) const;
    inline oojArrayOfBoolean *operator->() const;
    inline oojArrayOfBoolean &operator*() const;
    inline operator oojArrayOfBoolean *() const;
    /* Use "operator oojArrayOfBoolean *" instead of vm. */
    /* OBSOLETE */ inline oojArrayOfBoolean *vm() const;
    // ODMG methods:
    ooHandleStructor(oojArrayOfBoolean)(const d_Ref_Any &from);
    oojArrayOfBoolean *ptr() const;
};

ooTemplateSpecialization
class ooItr(oojArrayOfBoolean) : public ooHandle(oojArrayOfBoolean),
		    public ooIteratorObjOrContObj {
  public:
    ooItrStructor(oojArrayOfBoolean)();
    ~ooItrStructor(oojArrayOfBoolean)();
  private:
    // Defined only to prevent implicit definition:
    ooItrStructor(oojArrayOfBoolean)(ooItr(oojArrayOfBoolean)&);
    ooItr(oojArrayOfBoolean)    operator=(ooItr(oojArrayOfBoolean)&);
};


/* methods on ooDeref(oojArrayOfBoolean) */
inline
ooDeref(oojArrayOfBoolean)::ooDerefStructor(oojArrayOfBoolean)(ooDeref(oojArrayOfBoolean) &  deref) :
    ooDerefBase(deref.vm())
{
  this->pinCompensate();
}
inline
ooDeref(oojArrayOfBoolean)::ooDerefStructor(oojArrayOfBoolean)(ooObj *  fromObject) :
    ooDerefBase(fromObject)
{
}
inline
ooDeref(oojArrayOfBoolean)::~ooDerefStructor(oojArrayOfBoolean)()
{
}
inline
oojArrayOfBoolean *
ooDeref(oojArrayOfBoolean)::operator->() const
{
  return ooReinterpretCast(oojArrayOfBoolean *, this->vm());
}


/* methods on ooRef(oojArrayOfBoolean) */
inline
ooRef(oojArrayOfBoolean)::ooRefStructor(oojArrayOfBoolean)(const ooHandleSuper(oojArrayOfBoolean)& objH) :
    ooRef(oojArray)(objH)
{
}
inline
ooRef(oojArrayOfBoolean)::ooRefStructor(oojArrayOfBoolean)(const oojArrayOfBoolean *  fromObject) :
    ooRef(oojArray)(ooReinterpretCast(const oojArray *, fromObject))
{
}
inline
ooRef(oojArrayOfBoolean)&
ooRef(oojArrayOfBoolean)::operator=(const ooRef(oojArrayOfBoolean) &  id)
{
  this->ooId::operator=(id);
  return *this;
}
inline
ooRef(oojArrayOfBoolean)&
ooRef(oojArrayOfBoolean)::operator=(const ooShortRefSuper(oojArrayOfBoolean) &  shortId)
{
  this->ooRef(ooObj)::operator=(shortId);
  return *this;
}
inline
ooRef(oojArrayOfBoolean)&
ooRef(oojArrayOfBoolean)::operator=(const ooHandleSuper(oojArrayOfBoolean) &  objH)
{
  this->ooRef(ooObj)::operator=(objH);
  return *this;
}
inline
ooRef(oojArrayOfBoolean)&
ooRef(oojArrayOfBoolean)::operator=(const oojArrayOfBoolean *  fromObject)
{
  this->ooRef(ooObj)::operator=(ooReinterpretCast(const ooObj *, fromObject));
  return *this;
}
inline
oojArrayOfBoolean *
ooRef(oojArrayOfBoolean)::pin(ooMode  openMode) const
{
  return ooReinterpretCast(oojArrayOfBoolean *, this->pin_ref_internal(openMode));
}
inline
oojArrayOfBoolean *
ooRef(oojArrayOfBoolean)::vm(ooMode  openMode) const
{
  return this->pin(openMode);
}
#ifndef OO_BUGGY_TEMPLATES
inline
ooHandle(oojArrayOfBoolean) &
ooRef(oojArrayOfBoolean)::copy(const ooHandle(ooObj) &  nearH,
		ooHandle(oojArrayOfBoolean) &           result) const
{
  this->ooRef(ooObj)::copy(nearH, result);
  return result;
}
inline
ooRef(oojArrayOfBoolean) &
ooRef(oojArrayOfBoolean)::copy(const ooHandle(ooObj) &  nearH,
		ooRef(oojArrayOfBoolean) &              newObjRef) const
{
  this->ooRef(ooObj)::copy(nearH, newObjRef);
  return newObjRef;
}
inline
ooHandle(oojArrayOfBoolean)
ooRef(oojArrayOfBoolean)::copy(const ooHandle(ooObj) &  nearH) const
{
  ooHandle(oojArrayOfBoolean) result;
  this->ooRef(ooObj)::copy(nearH, result);
  return result;
}
#endif // !defined(OO_BUGGY_TEMPLATES)
inline
ooDeref(oojArrayOfBoolean)
ooRef(oojArrayOfBoolean)::operator->() const
{
  ooDeref(oojArrayOfBoolean) result(this->pin_ref_internal(oocRead));
  return result;
}


/* methods on ooShortRef(oojArrayOfBoolean) */
inline
ooShortRef(oojArrayOfBoolean) &
ooShortRef(oojArrayOfBoolean)::operator=(const ooShortRef(oojArrayOfBoolean) &  shortId)
{
  this->ooShortId::operator=(shortId);
  return *this;
}
inline
ooShortRef(oojArrayOfBoolean) &
ooShortRef(oojArrayOfBoolean)::operator=(const ooRef(oojArrayOfBoolean) &  id)
{
  this->ooShortId::operator=(id);
  return *this;
}
inline
ooShortRef(oojArrayOfBoolean) &
ooShortRef(oojArrayOfBoolean)::operator=(const ooHandleSuper(oojArrayOfBoolean) &  objH)
{
  this->ooShortId::operator=(objH);
  return *this;
}
inline
ooShortRef(oojArrayOfBoolean)&
ooShortRef(oojArrayOfBoolean)::operator=(const oojArrayOfBoolean *  fromObject)
{
  this->ooShortId::operator=(ooReinterpretCast(const ooObj *,fromObject));
  return *this;
}
inline
ooShortRef(oojArrayOfBoolean)::ooShortRefStructor(oojArrayOfBoolean)()
{
}
#ifdef OO_BUGGY_TEMPLATES
inline
ooShortRef(oojArrayOfBoolean)::ooShortRefStructor(oojArrayOfBoolean)(const ooShortRef(oojArrayOfBoolean) &  shortId)
{
  *this = shortId;
}
#else // !defined(OO_BUGGY_TEMPLATES)
inline
ooShortRef(oojArrayOfBoolean)::ooShortRefStructor(oojArrayOfBoolean)(const ooShortRef(oojArrayOfBoolean) &  shortId) :
    ooShortRef(oojArray)(shortId)
{
}
#endif // !defined(OO_BUGGY_TEMPLATES)
#ifdef OO_BUGGY_TEMPLATES
inline
ooShortRef(oojArrayOfBoolean)::ooShortRefStructor(oojArrayOfBoolean)(const ooRef(oojArrayOfBoolean) &  id)
{
  *this = id;
}
#else // !defined(OO_BUGGY_TEMPLATES)
inline
ooShortRef(oojArrayOfBoolean)::ooShortRefStructor(oojArrayOfBoolean)(const ooRef(oojArrayOfBoolean) &  id) :
    ooShortRef(oojArray)(id)
{
}
#endif // !defined(OO_BUGGY_TEMPLATES)
#ifdef OO_BUGGY_TEMPLATES
inline
ooShortRef(oojArrayOfBoolean)::ooShortRefStructor(oojArrayOfBoolean)(const ooHandleSuper(oojArrayOfBoolean) &  objH)
{
  *this = objH;
}
#else // !defined(OO_BUGGY_TEMPLATES)
inline
ooShortRef(oojArrayOfBoolean)::ooShortRefStructor(oojArrayOfBoolean)(const ooHandleSuper(oojArrayOfBoolean) &  objH) :
    ooShortRef(oojArray)(objH)
{
}
#endif // !defined(OO_BUGGY_TEMPLATES)
#ifdef OO_BUGGY_TEMPLATES
inline
ooShortRef(oojArrayOfBoolean)::ooShortRefStructor(oojArrayOfBoolean)(const oojArrayOfBoolean *  fromObject)
{
  *this = fromObject;
}
#else // !defined(OO_BUGGY_TEMPLATES)
inline
ooShortRef(oojArrayOfBoolean)::ooShortRefStructor(oojArrayOfBoolean)(const oojArrayOfBoolean *  fromObject) :
    ooShortRef(oojArray)(ooReinterpretCast(const oojArray *,fromObject))
{
}
#endif // !defined(OO_BUGGY_TEMPLATES)


/* methods on ooHandle(oojArrayOfBoolean) */
inline
ooHandle(oojArrayOfBoolean)::ooHandleStructor(oojArrayOfBoolean)()
{
}
inline
ooHandle(oojArrayOfBoolean)::ooHandleStructor(oojArrayOfBoolean)(const ooHandle(oojArrayOfBoolean) &  objH) :
#ifdef OO_BUGGY_TEMPLATES
    ooHandle_superclass<oojArrayOfBoolean >(objH)
#else // !defined(OO_BUGGY_TEMPLATES)
    ooHandle(oojArray)(objH)
#endif // !defined(OO_BUGGY_TEMPLATES)
{
}
inline
ooHandle(oojArrayOfBoolean)::ooHandleStructor(oojArrayOfBoolean)(const ooRef(oojArrayOfBoolean) &  id) :
#ifdef OO_BUGGY_TEMPLATES
    ooHandle_superclass<oojArrayOfBoolean >(id)
#else // !defined(OO_BUGGY_TEMPLATES)
    ooHandle(oojArray)(id)
#endif // !defined(OO_BUGGY_TEMPLATES)
{
}
inline
ooHandle(oojArrayOfBoolean)::ooHandleStructor(oojArrayOfBoolean)(const oojArrayOfBoolean *  fromObject) :
#ifdef OO_BUGGY_TEMPLATES
    ooHandle_superclass<oojArrayOfBoolean >(ooReinterpretCast(const oojArray *,fromObject))
#else // !defined(OO_BUGGY_TEMPLATES)
    ooHandle(oojArray)(ooReinterpretCast(const oojArray *,fromObject))
#endif // !defined(OO_BUGGY_TEMPLATES)
{
}
inline
ooHandle(oojArrayOfBoolean)&
ooHandle(oojArrayOfBoolean)::operator=(const ooRef(oojArrayOfBoolean) &  id)
{
  this->ooHandle(ooObj)::operator=(id);
  return *this;
}
inline
ooHandle(oojArrayOfBoolean)&
ooHandle(oojArrayOfBoolean)::operator=(const ooHandle(oojArrayOfBoolean) &  objH)
{
  this->ooHandle(ooObj)::operator=(objH);
  return *this;
}
inline
ooHandle(oojArrayOfBoolean)&
ooHandle(oojArrayOfBoolean)::operator=(const ooShortRef(oojArrayOfBoolean) &  shortId)
{
  this->ooHandle(ooObj)::operator=(shortId);
  return *this;
}
inline
ooHandle(oojArrayOfBoolean)&
ooHandle(oojArrayOfBoolean)::operator=(const oojArrayOfBoolean *  fromObject)
{
  this->ooHandle(ooObj)::operator=(ooReinterpretCast(const ooObj *,fromObject));
  return *this;
}
inline
oojArrayOfBoolean *
ooHandle(oojArrayOfBoolean)::pin(ooMode  openMode) const
{
  return ooReinterpretCast(oojArrayOfBoolean *, this->pin_obj_internal(openMode));
}
inline
oojArrayOfBoolean *
ooHandle(oojArrayOfBoolean)::operator->() const
{
  return this->vm();
}
inline
oojArrayOfBoolean &
ooHandle(oojArrayOfBoolean)::operator*() const
{
  return *(this->vm());
}
inline
ooHandle(oojArrayOfBoolean)::operator oojArrayOfBoolean *() const
{
  if ( _state == oocHandlePTR  )
    return ooReinterpretCast(oojArrayOfBoolean *, _ptr._obj);
  else return ooReinterpretCast(oojArrayOfBoolean *, this->get_vm());
}
inline
oojArrayOfBoolean *
ooHandle(oojArrayOfBoolean)::vm() const
{
  if ( _state == oocHandlePTR && _ptr._obj != NULL )
    return ooReinterpretCast(oojArrayOfBoolean *, _ptr._obj);
  else return ooReinterpretCast(oojArrayOfBoolean *, this->get_vm());
}
inline
ooRef(oojArrayOfBoolean) &
ooHandle(oojArrayOfBoolean)::copy(const ooHandle(ooObj) &  nearH,
		   ooRef(oojArrayOfBoolean) &              result) const
{
  this->ooHandle(ooObj)::copy(nearH, result);
  return result;
}


/* ODMG methods */
inline
oojArrayOfBoolean *
ooRef(oojArrayOfBoolean)::ptr() const
{
  return this->pin();
}
inline
oojArrayOfBoolean *
ooHandle(oojArrayOfBoolean)::ptr() const
{
  return this->operator oojArrayOfBoolean *();
}
class oojArrayOfFloat;


/////////////////////////////////////////////////////////////////////////////

ooTemplateSpecialization
class ooDeref(oojArrayOfFloat) : public ooDerefBase {
	friend class ooRef(oojArrayOfFloat);
  public:
    ~ooDerefStructor(oojArrayOfFloat)();
    inline oojArrayOfFloat *operator->() const;
#ifndef OO_BUGGY_TEMPLATES
  private:
#endif // !defined(OO_BUGGY_TEMPLATES)
    ooDerefStructor(oojArrayOfFloat)(ooDeref(oojArrayOfFloat)& deref);
    ooDerefStructor(oojArrayOfFloat)(ooObj *  fromObject);
};


#ifdef OO_BUGGY_TEMPLATES

class ooHandle_superclass<oojArrayOfFloat > : public ooHandle(oojArray) {
 protected:
  ooHandle_superclass()
    {}
  ooHandle_superclass(const ooHandle(oojArray) &  from) :
      ooHandle(oojArray)(from)
    {}
  ooHandle_superclass(const ooRef(oojArray) &  from) :
      ooHandle(oojArray)(from)
    {}
  ooHandle_superclass(const oojArray *  from) :
      ooHandle(oojArray)(from)
    {}
  ~ooHandle_superclass()
    {}
};

class ooShortRef_superclass<oojArrayOfFloat > : public ooShortRef(oojArray) {
};

#endif // OO_BUGGY_TEMPLATES

ooTemplateSpecialization
class ooRef(oojArrayOfFloat) : public ooRef(oojArray) {
  public:
    ooRefStructor(oojArrayOfFloat)()
      {}
    ooRefStructor(oojArrayOfFloat)(const ooRef(oojArrayOfFloat)& id) :
	  ooRef(oojArray)(id)
      {}
    inline ooRefStructor(oojArrayOfFloat)(const ooHandleSuper(oojArrayOfFloat)& objH);
    inline ooRefStructor(oojArrayOfFloat)(const oojArrayOfFloat *  fromObject);
    inline ooRef(oojArrayOfFloat)& operator=(const ooRef(oojArrayOfFloat)& id);
    inline ooRef(oojArrayOfFloat)& operator=(const ooShortRefSuper(oojArrayOfFloat) &shortId);
    inline ooRef(oojArrayOfFloat)& operator=(const ooHandleSuper(oojArrayOfFloat)& objH);
    inline ooRef(oojArrayOfFloat)& operator=(const oojArrayOfFloat *  fromObject);
    ooStatus lookupObj(const ooHandle(ooObj)& scopeH,
		       const ooKey& key,
		       ooMode openMode = oocRead);
    ooStatus lookupObj(const ooHandle(ooObj)& scopeH,
		       const char* name,
		       ooMode openMode = oocRead);
#ifndef OO_BUGGY_TEMPLATES
    inline ooRef(oojArrayOfFloat)& copy(const ooHandle(ooObj)& nearH,
		    ooRef(oojArrayOfFloat)& newObjRef) const;
    inline ooHandle(oojArrayOfFloat)& copy(const ooHandle(ooObj)& nearH,
			ooHandle(oojArrayOfFloat)& result) const;
    inline ooHandle(oojArrayOfFloat) copy(const ooHandle(ooObj)& nearH) const;
#endif // !defined(OO_BUGGY_TEMPLATES)
    inline oojArrayOfFloat *pin(ooMode openMode = oocRead) const;
    ooDeref(oojArrayOfFloat) operator->() const;
    /* Use pin() or use ooHandle "operator oojArrayOfFloat *" instead of vm. */
    /* OBSOLETE */ inline oojArrayOfFloat *vm(ooMode openMode = oocRead) const;
    // ODMG methods:
    ooRefStructor(oojArrayOfFloat)(const d_Ref_Any &from);
    oojArrayOfFloat *ptr() const;
};

ooTemplateSpecialization
class ooShortRef(oojArrayOfFloat) :
#ifdef OO_BUGGY_TEMPLATES
			public ooShortRef_superclass<oojArrayOfFloat >
#else // !defined(OO_BUGGY_TEMPLATES)
			public ooShortRef(oojArray)
#endif // !defined(OO_BUGGY_TEMPLATES)
					            {
  public:
    ooShortRefStructor(oojArrayOfFloat)();
    ooShortRefStructor(oojArrayOfFloat)(const ooShortRef(oojArrayOfFloat)& shortId);
    ooShortRefStructor(oojArrayOfFloat)(const ooRef(oojArrayOfFloat)& id);
    ooShortRefStructor(oojArrayOfFloat)(const ooHandleSuper(oojArrayOfFloat) &objH);
    ooShortRefStructor(oojArrayOfFloat)(const oojArrayOfFloat *  fromObject);
    ooShortRef(oojArrayOfFloat)& operator=(const ooShortRef(oojArrayOfFloat)& shortId);
    ooShortRef(oojArrayOfFloat)& operator=(const ooRef(oojArrayOfFloat)& id);
    ooShortRef(oojArrayOfFloat)& operator=(const ooHandleSuper(oojArrayOfFloat) &objH);
    ooShortRef(oojArrayOfFloat)& operator=(const oojArrayOfFloat *  fromObject);
};

ooTemplateSpecialization
class ooHandle(oojArrayOfFloat) :
#ifdef OO_BUGGY_TEMPLATES
		      public ooHandle_superclass<oojArrayOfFloat >
#else // !defined(OO_BUGGY_TEMPLATES)
		      public ooHandle(oojArray)
#endif // !defined(OO_BUGGY_TEMPLATES)
                                                {
  public:
    inline ooHandleStructor(oojArrayOfFloat)();
    inline ooHandleStructor(oojArrayOfFloat)(const ooRef(oojArrayOfFloat)& id);
    inline ooHandleStructor(oojArrayOfFloat)(const ooHandle(oojArrayOfFloat)& objH);
    inline ooHandleStructor(oojArrayOfFloat)(const oojArrayOfFloat *  fromObject);
    inline ooHandle(oojArrayOfFloat)& operator=(const ooRef(oojArrayOfFloat)& id);
    inline ooHandle(oojArrayOfFloat)& operator=(const ooHandle(oojArrayOfFloat)& objH);
    inline ooHandle(oojArrayOfFloat)& operator=(const ooShortRef(oojArrayOfFloat)& shortId);
    inline ooHandle(oojArrayOfFloat)& operator=(const oojArrayOfFloat *  fromObject);
    ooStatus lookupObj(const ooHandle(ooObj)& scopeH,
		       const ooKey& key,
		       ooMode openMode = oocRead);
    ooStatus lookupObj(const ooHandle(ooObj)& scopeH,
		       const char* name,
		       ooMode openMode = oocRead);
    ooHandle(oojArrayOfFloat)& copy(const ooHandle(ooObj)& nearH,
		       ooHandle(oojArrayOfFloat)& result) const;
    inline ooRef(oojArrayOfFloat)& copy(const ooHandle(ooObj)& nearH,
		    ooRef(oojArrayOfFloat)& result) const;
    ooHandle(oojArrayOfFloat) copy(const ooHandle(ooObj)& nearH) const;
    inline oojArrayOfFloat *pin(ooMode openMode = oocRead) const;
    inline oojArrayOfFloat *operator->() const;
    inline oojArrayOfFloat &operator*() const;
    inline operator oojArrayOfFloat *() const;
    /* Use "operator oojArrayOfFloat *" instead of vm. */
    /* OBSOLETE */ inline oojArrayOfFloat *vm() const;
    // ODMG methods:
    ooHandleStructor(oojArrayOfFloat)(const d_Ref_Any &from);
    oojArrayOfFloat *ptr() const;
};

ooTemplateSpecialization
class ooItr(oojArrayOfFloat) : public ooHandle(oojArrayOfFloat),
		    public ooIteratorObjOrContObj {
  public:
    ooItrStructor(oojArrayOfFloat)();
    ~ooItrStructor(oojArrayOfFloat)();
  private:
    // Defined only to prevent implicit definition:
    ooItrStructor(oojArrayOfFloat)(ooItr(oojArrayOfFloat)&);
    ooItr(oojArrayOfFloat)    operator=(ooItr(oojArrayOfFloat)&);
};


/* methods on ooDeref(oojArrayOfFloat) */
inline
ooDeref(oojArrayOfFloat)::ooDerefStructor(oojArrayOfFloat)(ooDeref(oojArrayOfFloat) &  deref) :
    ooDerefBase(deref.vm())
{
  this->pinCompensate();
}
inline
ooDeref(oojArrayOfFloat)::ooDerefStructor(oojArrayOfFloat)(ooObj *  fromObject) :
    ooDerefBase(fromObject)
{
}
inline
ooDeref(oojArrayOfFloat)::~ooDerefStructor(oojArrayOfFloat)()
{
}
inline
oojArrayOfFloat *
ooDeref(oojArrayOfFloat)::operator->() const
{
  return ooReinterpretCast(oojArrayOfFloat *, this->vm());
}


/* methods on ooRef(oojArrayOfFloat) */
inline
ooRef(oojArrayOfFloat)::ooRefStructor(oojArrayOfFloat)(const ooHandleSuper(oojArrayOfFloat)& objH) :
    ooRef(oojArray)(objH)
{
}
inline
ooRef(oojArrayOfFloat)::ooRefStructor(oojArrayOfFloat)(const oojArrayOfFloat *  fromObject) :
    ooRef(oojArray)(ooReinterpretCast(const oojArray *, fromObject))
{
}
inline
ooRef(oojArrayOfFloat)&
ooRef(oojArrayOfFloat)::operator=(const ooRef(oojArrayOfFloat) &  id)
{
  this->ooId::operator=(id);
  return *this;
}
inline
ooRef(oojArrayOfFloat)&
ooRef(oojArrayOfFloat)::operator=(const ooShortRefSuper(oojArrayOfFloat) &  shortId)
{
  this->ooRef(ooObj)::operator=(shortId);
  return *this;
}
inline
ooRef(oojArrayOfFloat)&
ooRef(oojArrayOfFloat)::operator=(const ooHandleSuper(oojArrayOfFloat) &  objH)
{
  this->ooRef(ooObj)::operator=(objH);
  return *this;
}
inline
ooRef(oojArrayOfFloat)&
ooRef(oojArrayOfFloat)::operator=(const oojArrayOfFloat *  fromObject)
{
  this->ooRef(ooObj)::operator=(ooReinterpretCast(const ooObj *, fromObject));
  return *this;
}
inline
oojArrayOfFloat *
ooRef(oojArrayOfFloat)::pin(ooMode  openMode) const
{
  return ooReinterpretCast(oojArrayOfFloat *, this->pin_ref_internal(openMode));
}
inline
oojArrayOfFloat *
ooRef(oojArrayOfFloat)::vm(ooMode  openMode) const
{
  return this->pin(openMode);
}
#ifndef OO_BUGGY_TEMPLATES
inline
ooHandle(oojArrayOfFloat) &
ooRef(oojArrayOfFloat)::copy(const ooHandle(ooObj) &  nearH,
		ooHandle(oojArrayOfFloat) &           result) const
{
  this->ooRef(ooObj)::copy(nearH, result);
  return result;
}
inline
ooRef(oojArrayOfFloat) &
ooRef(oojArrayOfFloat)::copy(const ooHandle(ooObj) &  nearH,
		ooRef(oojArrayOfFloat) &              newObjRef) const
{
  this->ooRef(ooObj)::copy(nearH, newObjRef);
  return newObjRef;
}
inline
ooHandle(oojArrayOfFloat)
ooRef(oojArrayOfFloat)::copy(const ooHandle(ooObj) &  nearH) const
{
  ooHandle(oojArrayOfFloat) result;
  this->ooRef(ooObj)::copy(nearH, result);
  return result;
}
#endif // !defined(OO_BUGGY_TEMPLATES)
inline
ooDeref(oojArrayOfFloat)
ooRef(oojArrayOfFloat)::operator->() const
{
  ooDeref(oojArrayOfFloat) result(this->pin_ref_internal(oocRead));
  return result;
}


/* methods on ooShortRef(oojArrayOfFloat) */
inline
ooShortRef(oojArrayOfFloat) &
ooShortRef(oojArrayOfFloat)::operator=(const ooShortRef(oojArrayOfFloat) &  shortId)
{
  this->ooShortId::operator=(shortId);
  return *this;
}
inline
ooShortRef(oojArrayOfFloat) &
ooShortRef(oojArrayOfFloat)::operator=(const ooRef(oojArrayOfFloat) &  id)
{
  this->ooShortId::operator=(id);
  return *this;
}
inline
ooShortRef(oojArrayOfFloat) &
ooShortRef(oojArrayOfFloat)::operator=(const ooHandleSuper(oojArrayOfFloat) &  objH)
{
  this->ooShortId::operator=(objH);
  return *this;
}
inline
ooShortRef(oojArrayOfFloat)&
ooShortRef(oojArrayOfFloat)::operator=(const oojArrayOfFloat *  fromObject)
{
  this->ooShortId::operator=(ooReinterpretCast(const ooObj *,fromObject));
  return *this;
}
inline
ooShortRef(oojArrayOfFloat)::ooShortRefStructor(oojArrayOfFloat)()
{
}
#ifdef OO_BUGGY_TEMPLATES
inline
ooShortRef(oojArrayOfFloat)::ooShortRefStructor(oojArrayOfFloat)(const ooShortRef(oojArrayOfFloat) &  shortId)
{
  *this = shortId;
}
#else // !defined(OO_BUGGY_TEMPLATES)
inline
ooShortRef(oojArrayOfFloat)::ooShortRefStructor(oojArrayOfFloat)(const ooShortRef(oojArrayOfFloat) &  shortId) :
    ooShortRef(oojArray)(shortId)
{
}
#endif // !defined(OO_BUGGY_TEMPLATES)
#ifdef OO_BUGGY_TEMPLATES
inline
ooShortRef(oojArrayOfFloat)::ooShortRefStructor(oojArrayOfFloat)(const ooRef(oojArrayOfFloat) &  id)
{
  *this = id;
}
#else // !defined(OO_BUGGY_TEMPLATES)
inline
ooShortRef(oojArrayOfFloat)::ooShortRefStructor(oojArrayOfFloat)(const ooRef(oojArrayOfFloat) &  id) :
    ooShortRef(oojArray)(id)
{
}
#endif // !defined(OO_BUGGY_TEMPLATES)
#ifdef OO_BUGGY_TEMPLATES
inline
ooShortRef(oojArrayOfFloat)::ooShortRefStructor(oojArrayOfFloat)(const ooHandleSuper(oojArrayOfFloat) &  objH)
{
  *this = objH;
}
#else // !defined(OO_BUGGY_TEMPLATES)
inline
ooShortRef(oojArrayOfFloat)::ooShortRefStructor(oojArrayOfFloat)(const ooHandleSuper(oojArrayOfFloat) &  objH) :
    ooShortRef(oojArray)(objH)
{
}
#endif // !defined(OO_BUGGY_TEMPLATES)
#ifdef OO_BUGGY_TEMPLATES
inline
ooShortRef(oojArrayOfFloat)::ooShortRefStructor(oojArrayOfFloat)(const oojArrayOfFloat *  fromObject)
{
  *this = fromObject;
}
#else // !defined(OO_BUGGY_TEMPLATES)
inline
ooShortRef(oojArrayOfFloat)::ooShortRefStructor(oojArrayOfFloat)(const oojArrayOfFloat *  fromObject) :
    ooShortRef(oojArray)(ooReinterpretCast(const oojArray *,fromObject))
{
}
#endif // !defined(OO_BUGGY_TEMPLATES)


/* methods on ooHandle(oojArrayOfFloat) */
inline
ooHandle(oojArrayOfFloat)::ooHandleStructor(oojArrayOfFloat)()
{
}
inline
ooHandle(oojArrayOfFloat)::ooHandleStructor(oojArrayOfFloat)(const ooHandle(oojArrayOfFloat) &  objH) :
#ifdef OO_BUGGY_TEMPLATES
    ooHandle_superclass<oojArrayOfFloat >(objH)
#else // !defined(OO_BUGGY_TEMPLATES)
    ooHandle(oojArray)(objH)
#endif // !defined(OO_BUGGY_TEMPLATES)
{
}
inline
ooHandle(oojArrayOfFloat)::ooHandleStructor(oojArrayOfFloat)(const ooRef(oojArrayOfFloat) &  id) :
#ifdef OO_BUGGY_TEMPLATES
    ooHandle_superclass<oojArrayOfFloat >(id)
#else // !defined(OO_BUGGY_TEMPLATES)
    ooHandle(oojArray)(id)
#endif // !defined(OO_BUGGY_TEMPLATES)
{
}
inline
ooHandle(oojArrayOfFloat)::ooHandleStructor(oojArrayOfFloat)(const oojArrayOfFloat *  fromObject) :
#ifdef OO_BUGGY_TEMPLATES
    ooHandle_superclass<oojArrayOfFloat >(ooReinterpretCast(const oojArray *,fromObject))
#else // !defined(OO_BUGGY_TEMPLATES)
    ooHandle(oojArray)(ooReinterpretCast(const oojArray *,fromObject))
#endif // !defined(OO_BUGGY_TEMPLATES)
{
}
inline
ooHandle(oojArrayOfFloat)&
ooHandle(oojArrayOfFloat)::operator=(const ooRef(oojArrayOfFloat) &  id)
{
  this->ooHandle(ooObj)::operator=(id);
  return *this;
}
inline
ooHandle(oojArrayOfFloat)&
ooHandle(oojArrayOfFloat)::operator=(const ooHandle(oojArrayOfFloat) &  objH)
{
  this->ooHandle(ooObj)::operator=(objH);
  return *this;
}
inline
ooHandle(oojArrayOfFloat)&
ooHandle(oojArrayOfFloat)::operator=(const ooShortRef(oojArrayOfFloat) &  shortId)
{
  this->ooHandle(ooObj)::operator=(shortId);
  return *this;
}
inline
ooHandle(oojArrayOfFloat)&
ooHandle(oojArrayOfFloat)::operator=(const oojArrayOfFloat *  fromObject)
{
  this->ooHandle(ooObj)::operator=(ooReinterpretCast(const ooObj *,fromObject));
  return *this;
}
inline
oojArrayOfFloat *
ooHandle(oojArrayOfFloat)::pin(ooMode  openMode) const
{
  return ooReinterpretCast(oojArrayOfFloat *, this->pin_obj_internal(openMode));
}
inline
oojArrayOfFloat *
ooHandle(oojArrayOfFloat)::operator->() const
{
  return this->vm();
}
inline
oojArrayOfFloat &
ooHandle(oojArrayOfFloat)::operator*() const
{
  return *(this->vm());
}
inline
ooHandle(oojArrayOfFloat)::operator oojArrayOfFloat *() const
{
  if ( _state == oocHandlePTR  )
    return ooReinterpretCast(oojArrayOfFloat *, _ptr._obj);
  else return ooReinterpretCast(oojArrayOfFloat *, this->get_vm());
}
inline
oojArrayOfFloat *
ooHandle(oojArrayOfFloat)::vm() const
{
  if ( _state == oocHandlePTR && _ptr._obj != NULL )
    return ooReinterpretCast(oojArrayOfFloat *, _ptr._obj);
  else return ooReinterpretCast(oojArrayOfFloat *, this->get_vm());
}
inline
ooRef(oojArrayOfFloat) &
ooHandle(oojArrayOfFloat)::copy(const ooHandle(ooObj) &  nearH,
		   ooRef(oojArrayOfFloat) &              result) const
{
  this->ooHandle(ooObj)::copy(nearH, result);
  return result;
}


/* ODMG methods */
inline
oojArrayOfFloat *
ooRef(oojArrayOfFloat)::ptr() const
{
  return this->pin();
}
inline
oojArrayOfFloat *
ooHandle(oojArrayOfFloat)::ptr() const
{
  return this->operator oojArrayOfFloat *();
}
class oojArrayOfDouble;


/////////////////////////////////////////////////////////////////////////////

ooTemplateSpecialization
class ooDeref(oojArrayOfDouble) : public ooDerefBase {
	friend class ooRef(oojArrayOfDouble);
  public:
    ~ooDerefStructor(oojArrayOfDouble)();
    inline oojArrayOfDouble *operator->() const;
#ifndef OO_BUGGY_TEMPLATES
  private:
#endif // !defined(OO_BUGGY_TEMPLATES)
    ooDerefStructor(oojArrayOfDouble)(ooDeref(oojArrayOfDouble)& deref);
    ooDerefStructor(oojArrayOfDouble)(ooObj *  fromObject);
};


#ifdef OO_BUGGY_TEMPLATES

class ooHandle_superclass<oojArrayOfDouble > : public ooHandle(oojArray) {
 protected:
  ooHandle_superclass()
    {}
  ooHandle_superclass(const ooHandle(oojArray) &  from) :
      ooHandle(oojArray)(from)
    {}
  ooHandle_superclass(const ooRef(oojArray) &  from) :
      ooHandle(oojArray)(from)
    {}
  ooHandle_superclass(const oojArray *  from) :
      ooHandle(oojArray)(from)
    {}
  ~ooHandle_superclass()
    {}
};

class ooShortRef_superclass<oojArrayOfDouble > : public ooShortRef(oojArray) {
};

#endif // OO_BUGGY_TEMPLATES

ooTemplateSpecialization
class ooRef(oojArrayOfDouble) : public ooRef(oojArray) {
  public:
    ooRefStructor(oojArrayOfDouble)()
      {}
    ooRefStructor(oojArrayOfDouble)(const ooRef(oojArrayOfDouble)& id) :
	  ooRef(oojArray)(id)
      {}
    inline ooRefStructor(oojArrayOfDouble)(const ooHandleSuper(oojArrayOfDouble)& objH);
    inline ooRefStructor(oojArrayOfDouble)(const oojArrayOfDouble *  fromObject);
    inline ooRef(oojArrayOfDouble)& operator=(const ooRef(oojArrayOfDouble)& id);
    inline ooRef(oojArrayOfDouble)& operator=(const ooShortRefSuper(oojArrayOfDouble) &shortId);
    inline ooRef(oojArrayOfDouble)& operator=(const ooHandleSuper(oojArrayOfDouble)& objH);
    inline ooRef(oojArrayOfDouble)& operator=(const oojArrayOfDouble *  fromObject);
    ooStatus lookupObj(const ooHandle(ooObj)& scopeH,
		       const ooKey& key,
		       ooMode openMode = oocRead);
    ooStatus lookupObj(const ooHandle(ooObj)& scopeH,
		       const char* name,
		       ooMode openMode = oocRead);
#ifndef OO_BUGGY_TEMPLATES
    inline ooRef(oojArrayOfDouble)& copy(const ooHandle(ooObj)& nearH,
		    ooRef(oojArrayOfDouble)& newObjRef) const;
    inline ooHandle(oojArrayOfDouble)& copy(const ooHandle(ooObj)& nearH,
			ooHandle(oojArrayOfDouble)& result) const;
    inline ooHandle(oojArrayOfDouble) copy(const ooHandle(ooObj)& nearH) const;
#endif // !defined(OO_BUGGY_TEMPLATES)
    inline oojArrayOfDouble *pin(ooMode openMode = oocRead) const;
    ooDeref(oojArrayOfDouble) operator->() const;
    /* Use pin() or use ooHandle "operator oojArrayOfDouble *" instead of vm. */
    /* OBSOLETE */ inline oojArrayOfDouble *vm(ooMode openMode = oocRead) const;
    // ODMG methods:
    ooRefStructor(oojArrayOfDouble)(const d_Ref_Any &from);
    oojArrayOfDouble *ptr() const;
};

ooTemplateSpecialization
class ooShortRef(oojArrayOfDouble) :
#ifdef OO_BUGGY_TEMPLATES
			public ooShortRef_superclass<oojArrayOfDouble >
#else // !defined(OO_BUGGY_TEMPLATES)
			public ooShortRef(oojArray)
#endif // !defined(OO_BUGGY_TEMPLATES)
					            {
  public:
    ooShortRefStructor(oojArrayOfDouble)();
    ooShortRefStructor(oojArrayOfDouble)(const ooShortRef(oojArrayOfDouble)& shortId);
    ooShortRefStructor(oojArrayOfDouble)(const ooRef(oojArrayOfDouble)& id);
    ooShortRefStructor(oojArrayOfDouble)(const ooHandleSuper(oojArrayOfDouble) &objH);
    ooShortRefStructor(oojArrayOfDouble)(const oojArrayOfDouble *  fromObject);
    ooShortRef(oojArrayOfDouble)& operator=(const ooShortRef(oojArrayOfDouble)& shortId);
    ooShortRef(oojArrayOfDouble)& operator=(const ooRef(oojArrayOfDouble)& id);
    ooShortRef(oojArrayOfDouble)& operator=(const ooHandleSuper(oojArrayOfDouble) &objH);
    ooShortRef(oojArrayOfDouble)& operator=(const oojArrayOfDouble *  fromObject);
};

ooTemplateSpecialization
class ooHandle(oojArrayOfDouble) :
#ifdef OO_BUGGY_TEMPLATES
		      public ooHandle_superclass<oojArrayOfDouble >
#else // !defined(OO_BUGGY_TEMPLATES)
		      public ooHandle(oojArray)
#endif // !defined(OO_BUGGY_TEMPLATES)
                                                {
  public:
    inline ooHandleStructor(oojArrayOfDouble)();
    inline ooHandleStructor(oojArrayOfDouble)(const ooRef(oojArrayOfDouble)& id);
    inline ooHandleStructor(oojArrayOfDouble)(const ooHandle(oojArrayOfDouble)& objH);
    inline ooHandleStructor(oojArrayOfDouble)(const oojArrayOfDouble *  fromObject);
    inline ooHandle(oojArrayOfDouble)& operator=(const ooRef(oojArrayOfDouble)& id);
    inline ooHandle(oojArrayOfDouble)& operator=(const ooHandle(oojArrayOfDouble)& objH);
    inline ooHandle(oojArrayOfDouble)& operator=(const ooShortRef(oojArrayOfDouble)& shortId);
    inline ooHandle(oojArrayOfDouble)& operator=(const oojArrayOfDouble *  fromObject);
    ooStatus lookupObj(const ooHandle(ooObj)& scopeH,
		       const ooKey& key,
		       ooMode openMode = oocRead);
    ooStatus lookupObj(const ooHandle(ooObj)& scopeH,
		       const char* name,
		       ooMode openMode = oocRead);
    ooHandle(oojArrayOfDouble)& copy(const ooHandle(ooObj)& nearH,
		       ooHandle(oojArrayOfDouble)& result) const;
    inline ooRef(oojArrayOfDouble)& copy(const ooHandle(ooObj)& nearH,
		    ooRef(oojArrayOfDouble)& result) const;
    ooHandle(oojArrayOfDouble) copy(const ooHandle(ooObj)& nearH) const;
    inline oojArrayOfDouble *pin(ooMode openMode = oocRead) const;
    inline oojArrayOfDouble *operator->() const;
    inline oojArrayOfDouble &operator*() const;
    inline operator oojArrayOfDouble *() const;
    /* Use "operator oojArrayOfDouble *" instead of vm. */
    /* OBSOLETE */ inline oojArrayOfDouble *vm() const;
    // ODMG methods:
    ooHandleStructor(oojArrayOfDouble)(const d_Ref_Any &from);
    oojArrayOfDouble *ptr() const;
};

ooTemplateSpecialization
class ooItr(oojArrayOfDouble) : public ooHandle(oojArrayOfDouble),
		    public ooIteratorObjOrContObj {
  public:
    ooItrStructor(oojArrayOfDouble)();
    ~ooItrStructor(oojArrayOfDouble)();
  private:
    // Defined only to prevent implicit definition:
    ooItrStructor(oojArrayOfDouble)(ooItr(oojArrayOfDouble)&);
    ooItr(oojArrayOfDouble)    operator=(ooItr(oojArrayOfDouble)&);
};


/* methods on ooDeref(oojArrayOfDouble) */
inline
ooDeref(oojArrayOfDouble)::ooDerefStructor(oojArrayOfDouble)(ooDeref(oojArrayOfDouble) &  deref) :
    ooDerefBase(deref.vm())
{
  this->pinCompensate();
}
inline
ooDeref(oojArrayOfDouble)::ooDerefStructor(oojArrayOfDouble)(ooObj *  fromObject) :
    ooDerefBase(fromObject)
{
}
inline
ooDeref(oojArrayOfDouble)::~ooDerefStructor(oojArrayOfDouble)()
{
}
inline
oojArrayOfDouble *
ooDeref(oojArrayOfDouble)::operator->() const
{
  return ooReinterpretCast(oojArrayOfDouble *, this->vm());
}


/* methods on ooRef(oojArrayOfDouble) */
inline
ooRef(oojArrayOfDouble)::ooRefStructor(oojArrayOfDouble)(const ooHandleSuper(oojArrayOfDouble)& objH) :
    ooRef(oojArray)(objH)
{
}
inline
ooRef(oojArrayOfDouble)::ooRefStructor(oojArrayOfDouble)(const oojArrayOfDouble *  fromObject) :
    ooRef(oojArray)(ooReinterpretCast(const oojArray *, fromObject))
{
}
inline
ooRef(oojArrayOfDouble)&
ooRef(oojArrayOfDouble)::operator=(const ooRef(oojArrayOfDouble) &  id)
{
  this->ooId::operator=(id);
  return *this;
}
inline
ooRef(oojArrayOfDouble)&
ooRef(oojArrayOfDouble)::operator=(const ooShortRefSuper(oojArrayOfDouble) &  shortId)
{
  this->ooRef(ooObj)::operator=(shortId);
  return *this;
}
inline
ooRef(oojArrayOfDouble)&
ooRef(oojArrayOfDouble)::operator=(const ooHandleSuper(oojArrayOfDouble) &  objH)
{
  this->ooRef(ooObj)::operator=(objH);
  return *this;
}
inline
ooRef(oojArrayOfDouble)&
ooRef(oojArrayOfDouble)::operator=(const oojArrayOfDouble *  fromObject)
{
  this->ooRef(ooObj)::operator=(ooReinterpretCast(const ooObj *, fromObject));
  return *this;
}
inline
oojArrayOfDouble *
ooRef(oojArrayOfDouble)::pin(ooMode  openMode) const
{
  return ooReinterpretCast(oojArrayOfDouble *, this->pin_ref_internal(openMode));
}
inline
oojArrayOfDouble *
ooRef(oojArrayOfDouble)::vm(ooMode  openMode) const
{
  return this->pin(openMode);
}
#ifndef OO_BUGGY_TEMPLATES
inline
ooHandle(oojArrayOfDouble) &
ooRef(oojArrayOfDouble)::copy(const ooHandle(ooObj) &  nearH,
		ooHandle(oojArrayOfDouble) &           result) const
{
  this->ooRef(ooObj)::copy(nearH, result);
  return result;
}
inline
ooRef(oojArrayOfDouble) &
ooRef(oojArrayOfDouble)::copy(const ooHandle(ooObj) &  nearH,
		ooRef(oojArrayOfDouble) &              newObjRef) const
{
  this->ooRef(ooObj)::copy(nearH, newObjRef);
  return newObjRef;
}
inline
ooHandle(oojArrayOfDouble)
ooRef(oojArrayOfDouble)::copy(const ooHandle(ooObj) &  nearH) const
{
  ooHandle(oojArrayOfDouble) result;
  this->ooRef(ooObj)::copy(nearH, result);
  return result;
}
#endif // !defined(OO_BUGGY_TEMPLATES)
inline
ooDeref(oojArrayOfDouble)
ooRef(oojArrayOfDouble)::operator->() const
{
  ooDeref(oojArrayOfDouble) result(this->pin_ref_internal(oocRead));
  return result;
}


/* methods on ooShortRef(oojArrayOfDouble) */
inline
ooShortRef(oojArrayOfDouble) &
ooShortRef(oojArrayOfDouble)::operator=(const ooShortRef(oojArrayOfDouble) &  shortId)
{
  this->ooShortId::operator=(shortId);
  return *this;
}
inline
ooShortRef(oojArrayOfDouble) &
ooShortRef(oojArrayOfDouble)::operator=(const ooRef(oojArrayOfDouble) &  id)
{
  this->ooShortId::operator=(id);
  return *this;
}
inline
ooShortRef(oojArrayOfDouble) &
ooShortRef(oojArrayOfDouble)::operator=(const ooHandleSuper(oojArrayOfDouble) &  objH)
{
  this->ooShortId::operator=(objH);
  return *this;
}
inline
ooShortRef(oojArrayOfDouble)&
ooShortRef(oojArrayOfDouble)::operator=(const oojArrayOfDouble *  fromObject)
{
  this->ooShortId::operator=(ooReinterpretCast(const ooObj *,fromObject));
  return *this;
}
inline
ooShortRef(oojArrayOfDouble)::ooShortRefStructor(oojArrayOfDouble)()
{
}
#ifdef OO_BUGGY_TEMPLATES
inline
ooShortRef(oojArrayOfDouble)::ooShortRefStructor(oojArrayOfDouble)(const ooShortRef(oojArrayOfDouble) &  shortId)
{
  *this = shortId;
}
#else // !defined(OO_BUGGY_TEMPLATES)
inline
ooShortRef(oojArrayOfDouble)::ooShortRefStructor(oojArrayOfDouble)(const ooShortRef(oojArrayOfDouble) &  shortId) :
    ooShortRef(oojArray)(shortId)
{
}
#endif // !defined(OO_BUGGY_TEMPLATES)
#ifdef OO_BUGGY_TEMPLATES
inline
ooShortRef(oojArrayOfDouble)::ooShortRefStructor(oojArrayOfDouble)(const ooRef(oojArrayOfDouble) &  id)
{
  *this = id;
}
#else // !defined(OO_BUGGY_TEMPLATES)
inline
ooShortRef(oojArrayOfDouble)::ooShortRefStructor(oojArrayOfDouble)(const ooRef(oojArrayOfDouble) &  id) :
    ooShortRef(oojArray)(id)
{
}
#endif // !defined(OO_BUGGY_TEMPLATES)
#ifdef OO_BUGGY_TEMPLATES
inline
ooShortRef(oojArrayOfDouble)::ooShortRefStructor(oojArrayOfDouble)(const ooHandleSuper(oojArrayOfDouble) &  objH)
{
  *this = objH;
}
#else // !defined(OO_BUGGY_TEMPLATES)
inline
ooShortRef(oojArrayOfDouble)::ooShortRefStructor(oojArrayOfDouble)(const ooHandleSuper(oojArrayOfDouble) &  objH) :
    ooShortRef(oojArray)(objH)
{
}
#endif // !defined(OO_BUGGY_TEMPLATES)
#ifdef OO_BUGGY_TEMPLATES
inline
ooShortRef(oojArrayOfDouble)::ooShortRefStructor(oojArrayOfDouble)(const oojArrayOfDouble *  fromObject)
{
  *this = fromObject;
}
#else // !defined(OO_BUGGY_TEMPLATES)
inline
ooShortRef(oojArrayOfDouble)::ooShortRefStructor(oojArrayOfDouble)(const oojArrayOfDouble *  fromObject) :
    ooShortRef(oojArray)(ooReinterpretCast(const oojArray *,fromObject))
{
}
#endif // !defined(OO_BUGGY_TEMPLATES)


/* methods on ooHandle(oojArrayOfDouble) */
inline
ooHandle(oojArrayOfDouble)::ooHandleStructor(oojArrayOfDouble)()
{
}
inline
ooHandle(oojArrayOfDouble)::ooHandleStructor(oojArrayOfDouble)(const ooHandle(oojArrayOfDouble) &  objH) :
#ifdef OO_BUGGY_TEMPLATES
    ooHandle_superclass<oojArrayOfDouble >(objH)
#else // !defined(OO_BUGGY_TEMPLATES)
    ooHandle(oojArray)(objH)
#endif // !defined(OO_BUGGY_TEMPLATES)
{
}
inline
ooHandle(oojArrayOfDouble)::ooHandleStructor(oojArrayOfDouble)(const ooRef(oojArrayOfDouble) &  id) :
#ifdef OO_BUGGY_TEMPLATES
    ooHandle_superclass<oojArrayOfDouble >(id)
#else // !defined(OO_BUGGY_TEMPLATES)
    ooHandle(oojArray)(id)
#endif // !defined(OO_BUGGY_TEMPLATES)
{
}
inline
ooHandle(oojArrayOfDouble)::ooHandleStructor(oojArrayOfDouble)(const oojArrayOfDouble *  fromObject) :
#ifdef OO_BUGGY_TEMPLATES
    ooHandle_superclass<oojArrayOfDouble >(ooReinterpretCast(const oojArray *,fromObject))
#else // !defined(OO_BUGGY_TEMPLATES)
    ooHandle(oojArray)(ooReinterpretCast(const oojArray *,fromObject))
#endif // !defined(OO_BUGGY_TEMPLATES)
{
}
inline
ooHandle(oojArrayOfDouble)&
ooHandle(oojArrayOfDouble)::operator=(const ooRef(oojArrayOfDouble) &  id)
{
  this->ooHandle(ooObj)::operator=(id);
  return *this;
}
inline
ooHandle(oojArrayOfDouble)&
ooHandle(oojArrayOfDouble)::operator=(const ooHandle(oojArrayOfDouble) &  objH)
{
  this->ooHandle(ooObj)::operator=(objH);
  return *this;
}
inline
ooHandle(oojArrayOfDouble)&
ooHandle(oojArrayOfDouble)::operator=(const ooShortRef(oojArrayOfDouble) &  shortId)
{
  this->ooHandle(ooObj)::operator=(shortId);
  return *this;
}
inline
ooHandle(oojArrayOfDouble)&
ooHandle(oojArrayOfDouble)::operator=(const oojArrayOfDouble *  fromObject)
{
  this->ooHandle(ooObj)::operator=(ooReinterpretCast(const ooObj *,fromObject));
  return *this;
}
inline
oojArrayOfDouble *
ooHandle(oojArrayOfDouble)::pin(ooMode  openMode) const
{
  return ooReinterpretCast(oojArrayOfDouble *, this->pin_obj_internal(openMode));
}
inline
oojArrayOfDouble *
ooHandle(oojArrayOfDouble)::operator->() const
{
  return this->vm();
}
inline
oojArrayOfDouble &
ooHandle(oojArrayOfDouble)::operator*() const
{
  return *(this->vm());
}
inline
ooHandle(oojArrayOfDouble)::operator oojArrayOfDouble *() const
{
  if ( _state == oocHandlePTR  )
    return ooReinterpretCast(oojArrayOfDouble *, _ptr._obj);
  else return ooReinterpretCast(oojArrayOfDouble *, this->get_vm());
}
inline
oojArrayOfDouble *
ooHandle(oojArrayOfDouble)::vm() const
{
  if ( _state == oocHandlePTR && _ptr._obj != NULL )
    return ooReinterpretCast(oojArrayOfDouble *, _ptr._obj);
  else return ooReinterpretCast(oojArrayOfDouble *, this->get_vm());
}
inline
ooRef(oojArrayOfDouble) &
ooHandle(oojArrayOfDouble)::copy(const ooHandle(ooObj) &  nearH,
		   ooRef(oojArrayOfDouble) &              result) const
{
  this->ooHandle(ooObj)::copy(nearH, result);
  return result;
}


/* ODMG methods */
inline
oojArrayOfDouble *
ooRef(oojArrayOfDouble)::ptr() const
{
  return this->pin();
}
inline
oojArrayOfDouble *
ooHandle(oojArrayOfDouble)::ptr() const
{
  return this->operator oojArrayOfDouble *();
}
class oojArrayOfObject;


/////////////////////////////////////////////////////////////////////////////

ooTemplateSpecialization
class ooDeref(oojArrayOfObject) : public ooDerefBase {
	friend class ooRef(oojArrayOfObject);
  public:
    ~ooDerefStructor(oojArrayOfObject)();
    inline oojArrayOfObject *operator->() const;
#ifndef OO_BUGGY_TEMPLATES
  private:
#endif // !defined(OO_BUGGY_TEMPLATES)
    ooDerefStructor(oojArrayOfObject)(ooDeref(oojArrayOfObject)& deref);
    ooDerefStructor(oojArrayOfObject)(ooObj *  fromObject);
};


#ifdef OO_BUGGY_TEMPLATES

class ooHandle_superclass<oojArrayOfObject > : public ooHandle(oojArray) {
 protected:
  ooHandle_superclass()
    {}
  ooHandle_superclass(const ooHandle(oojArray) &  from) :
      ooHandle(oojArray)(from)
    {}
  ooHandle_superclass(const ooRef(oojArray) &  from) :
      ooHandle(oojArray)(from)
    {}
  ooHandle_superclass(const oojArray *  from) :
      ooHandle(oojArray)(from)
    {}
  ~ooHandle_superclass()
    {}
};

class ooShortRef_superclass<oojArrayOfObject > : public ooShortRef(oojArray) {
};

#endif // OO_BUGGY_TEMPLATES

ooTemplateSpecialization
class ooRef(oojArrayOfObject) : public ooRef(oojArray) {
  public:
    ooRefStructor(oojArrayOfObject)()
      {}
    ooRefStructor(oojArrayOfObject)(const ooRef(oojArrayOfObject)& id) :
	  ooRef(oojArray)(id)
      {}
    inline ooRefStructor(oojArrayOfObject)(const ooHandleSuper(oojArrayOfObject)& objH);
    inline ooRefStructor(oojArrayOfObject)(const oojArrayOfObject *  fromObject);
    inline ooRef(oojArrayOfObject)& operator=(const ooRef(oojArrayOfObject)& id);
    inline ooRef(oojArrayOfObject)& operator=(const ooShortRefSuper(oojArrayOfObject) &shortId);
    inline ooRef(oojArrayOfObject)& operator=(const ooHandleSuper(oojArrayOfObject)& objH);
    inline ooRef(oojArrayOfObject)& operator=(const oojArrayOfObject *  fromObject);
    ooStatus lookupObj(const ooHandle(ooObj)& scopeH,
		       const ooKey& key,
		       ooMode openMode = oocRead);
    ooStatus lookupObj(const ooHandle(ooObj)& scopeH,
		       const char* name,
		       ooMode openMode = oocRead);
#ifndef OO_BUGGY_TEMPLATES
    inline ooRef(oojArrayOfObject)& copy(const ooHandle(ooObj)& nearH,
		    ooRef(oojArrayOfObject)& newObjRef) const;
    inline ooHandle(oojArrayOfObject)& copy(const ooHandle(ooObj)& nearH,
			ooHandle(oojArrayOfObject)& result) const;
    inline ooHandle(oojArrayOfObject) copy(const ooHandle(ooObj)& nearH) const;
#endif // !defined(OO_BUGGY_TEMPLATES)
    inline oojArrayOfObject *pin(ooMode openMode = oocRead) const;
    ooDeref(oojArrayOfObject) operator->() const;
    /* Use pin() or use ooHandle "operator oojArrayOfObject *" instead of vm. */
    /* OBSOLETE */ inline oojArrayOfObject *vm(ooMode openMode = oocRead) const;
    // ODMG methods:
    ooRefStructor(oojArrayOfObject)(const d_Ref_Any &from);
    oojArrayOfObject *ptr() const;
};

ooTemplateSpecialization
class ooShortRef(oojArrayOfObject) :
#ifdef OO_BUGGY_TEMPLATES
			public ooShortRef_superclass<oojArrayOfObject >
#else // !defined(OO_BUGGY_TEMPLATES)
			public ooShortRef(oojArray)
#endif // !defined(OO_BUGGY_TEMPLATES)
					            {
  public:
    ooShortRefStructor(oojArrayOfObject)();
    ooShortRefStructor(oojArrayOfObject)(const ooShortRef(oojArrayOfObject)& shortId);
    ooShortRefStructor(oojArrayOfObject)(const ooRef(oojArrayOfObject)& id);
    ooShortRefStructor(oojArrayOfObject)(const ooHandleSuper(oojArrayOfObject) &objH);
    ooShortRefStructor(oojArrayOfObject)(const oojArrayOfObject *  fromObject);
    ooShortRef(oojArrayOfObject)& operator=(const ooShortRef(oojArrayOfObject)& shortId);
    ooShortRef(oojArrayOfObject)& operator=(const ooRef(oojArrayOfObject)& id);
    ooShortRef(oojArrayOfObject)& operator=(const ooHandleSuper(oojArrayOfObject) &objH);
    ooShortRef(oojArrayOfObject)& operator=(const oojArrayOfObject *  fromObject);
};

ooTemplateSpecialization
class ooHandle(oojArrayOfObject) :
#ifdef OO_BUGGY_TEMPLATES
		      public ooHandle_superclass<oojArrayOfObject >
#else // !defined(OO_BUGGY_TEMPLATES)
		      public ooHandle(oojArray)
#endif // !defined(OO_BUGGY_TEMPLATES)
                                                {
  public:
    inline ooHandleStructor(oojArrayOfObject)();
    inline ooHandleStructor(oojArrayOfObject)(const ooRef(oojArrayOfObject)& id);
    inline ooHandleStructor(oojArrayOfObject)(const ooHandle(oojArrayOfObject)& objH);
    inline ooHandleStructor(oojArrayOfObject)(const oojArrayOfObject *  fromObject);
    inline ooHandle(oojArrayOfObject)& operator=(const ooRef(oojArrayOfObject)& id);
    inline ooHandle(oojArrayOfObject)& operator=(const ooHandle(oojArrayOfObject)& objH);
    inline ooHandle(oojArrayOfObject)& operator=(const ooShortRef(oojArrayOfObject)& shortId);
    inline ooHandle(oojArrayOfObject)& operator=(const oojArrayOfObject *  fromObject);
    ooStatus lookupObj(const ooHandle(ooObj)& scopeH,
		       const ooKey& key,
		       ooMode openMode = oocRead);
    ooStatus lookupObj(const ooHandle(ooObj)& scopeH,
		       const char* name,
		       ooMode openMode = oocRead);
    ooHandle(oojArrayOfObject)& copy(const ooHandle(ooObj)& nearH,
		       ooHandle(oojArrayOfObject)& result) const;
    inline ooRef(oojArrayOfObject)& copy(const ooHandle(ooObj)& nearH,
		    ooRef(oojArrayOfObject)& result) const;
    ooHandle(oojArrayOfObject) copy(const ooHandle(ooObj)& nearH) const;
    inline oojArrayOfObject *pin(ooMode openMode = oocRead) const;
    inline oojArrayOfObject *operator->() const;
    inline oojArrayOfObject &operator*() const;
    inline operator oojArrayOfObject *() const;
    /* Use "operator oojArrayOfObject *" instead of vm. */
    /* OBSOLETE */ inline oojArrayOfObject *vm() const;
    // ODMG methods:
    ooHandleStructor(oojArrayOfObject)(const d_Ref_Any &from);
    oojArrayOfObject *ptr() const;
};

ooTemplateSpecialization
class ooItr(oojArrayOfObject) : public ooHandle(oojArrayOfObject),
		    public ooIteratorObjOrContObj {
  public:
    ooItrStructor(oojArrayOfObject)();
    ~ooItrStructor(oojArrayOfObject)();
  private:
    // Defined only to prevent implicit definition:
    ooItrStructor(oojArrayOfObject)(ooItr(oojArrayOfObject)&);
    ooItr(oojArrayOfObject)    operator=(ooItr(oojArrayOfObject)&);
};


/* methods on ooDeref(oojArrayOfObject) */
inline
ooDeref(oojArrayOfObject)::ooDerefStructor(oojArrayOfObject)(ooDeref(oojArrayOfObject) &  deref) :
    ooDerefBase(deref.vm())
{
  this->pinCompensate();
}
inline
ooDeref(oojArrayOfObject)::ooDerefStructor(oojArrayOfObject)(ooObj *  fromObject) :
    ooDerefBase(fromObject)
{
}
inline
ooDeref(oojArrayOfObject)::~ooDerefStructor(oojArrayOfObject)()
{
}
inline
oojArrayOfObject *
ooDeref(oojArrayOfObject)::operator->() const
{
  return ooReinterpretCast(oojArrayOfObject *, this->vm());
}


/* methods on ooRef(oojArrayOfObject) */
inline
ooRef(oojArrayOfObject)::ooRefStructor(oojArrayOfObject)(const ooHandleSuper(oojArrayOfObject)& objH) :
    ooRef(oojArray)(objH)
{
}
inline
ooRef(oojArrayOfObject)::ooRefStructor(oojArrayOfObject)(const oojArrayOfObject *  fromObject) :
    ooRef(oojArray)(ooReinterpretCast(const oojArray *, fromObject))
{
}
inline
ooRef(oojArrayOfObject)&
ooRef(oojArrayOfObject)::operator=(const ooRef(oojArrayOfObject) &  id)
{
  this->ooId::operator=(id);
  return *this;
}
inline
ooRef(oojArrayOfObject)&
ooRef(oojArrayOfObject)::operator=(const ooShortRefSuper(oojArrayOfObject) &  shortId)
{
  this->ooRef(ooObj)::operator=(shortId);
  return *this;
}
inline
ooRef(oojArrayOfObject)&
ooRef(oojArrayOfObject)::operator=(const ooHandleSuper(oojArrayOfObject) &  objH)
{
  this->ooRef(ooObj)::operator=(objH);
  return *this;
}
inline
ooRef(oojArrayOfObject)&
ooRef(oojArrayOfObject)::operator=(const oojArrayOfObject *  fromObject)
{
  this->ooRef(ooObj)::operator=(ooReinterpretCast(const ooObj *, fromObject));
  return *this;
}
inline
oojArrayOfObject *
ooRef(oojArrayOfObject)::pin(ooMode  openMode) const
{
  return ooReinterpretCast(oojArrayOfObject *, this->pin_ref_internal(openMode));
}
inline
oojArrayOfObject *
ooRef(oojArrayOfObject)::vm(ooMode  openMode) const
{
  return this->pin(openMode);
}
#ifndef OO_BUGGY_TEMPLATES
inline
ooHandle(oojArrayOfObject) &
ooRef(oojArrayOfObject)::copy(const ooHandle(ooObj) &  nearH,
		ooHandle(oojArrayOfObject) &           result) const
{
  this->ooRef(ooObj)::copy(nearH, result);
  return result;
}
inline
ooRef(oojArrayOfObject) &
ooRef(oojArrayOfObject)::copy(const ooHandle(ooObj) &  nearH,
		ooRef(oojArrayOfObject) &              newObjRef) const
{
  this->ooRef(ooObj)::copy(nearH, newObjRef);
  return newObjRef;
}
inline
ooHandle(oojArrayOfObject)
ooRef(oojArrayOfObject)::copy(const ooHandle(ooObj) &  nearH) const
{
  ooHandle(oojArrayOfObject) result;
  this->ooRef(ooObj)::copy(nearH, result);
  return result;
}
#endif // !defined(OO_BUGGY_TEMPLATES)
inline
ooDeref(oojArrayOfObject)
ooRef(oojArrayOfObject)::operator->() const
{
  ooDeref(oojArrayOfObject) result(this->pin_ref_internal(oocRead));
  return result;
}


/* methods on ooShortRef(oojArrayOfObject) */
inline
ooShortRef(oojArrayOfObject) &
ooShortRef(oojArrayOfObject)::operator=(const ooShortRef(oojArrayOfObject) &  shortId)
{
  this->ooShortId::operator=(shortId);
  return *this;
}
inline
ooShortRef(oojArrayOfObject) &
ooShortRef(oojArrayOfObject)::operator=(const ooRef(oojArrayOfObject) &  id)
{
  this->ooShortId::operator=(id);
  return *this;
}
inline
ooShortRef(oojArrayOfObject) &
ooShortRef(oojArrayOfObject)::operator=(const ooHandleSuper(oojArrayOfObject) &  objH)
{
  this->ooShortId::operator=(objH);
  return *this;
}
inline
ooShortRef(oojArrayOfObject)&
ooShortRef(oojArrayOfObject)::operator=(const oojArrayOfObject *  fromObject)
{
  this->ooShortId::operator=(ooReinterpretCast(const ooObj *,fromObject));
  return *this;
}
inline
ooShortRef(oojArrayOfObject)::ooShortRefStructor(oojArrayOfObject)()
{
}
#ifdef OO_BUGGY_TEMPLATES
inline
ooShortRef(oojArrayOfObject)::ooShortRefStructor(oojArrayOfObject)(const ooShortRef(oojArrayOfObject) &  shortId)
{
  *this = shortId;
}
#else // !defined(OO_BUGGY_TEMPLATES)
inline
ooShortRef(oojArrayOfObject)::ooShortRefStructor(oojArrayOfObject)(const ooShortRef(oojArrayOfObject) &  shortId) :
    ooShortRef(oojArray)(shortId)
{
}
#endif // !defined(OO_BUGGY_TEMPLATES)
#ifdef OO_BUGGY_TEMPLATES
inline
ooShortRef(oojArrayOfObject)::ooShortRefStructor(oojArrayOfObject)(const ooRef(oojArrayOfObject) &  id)
{
  *this = id;
}
#else // !defined(OO_BUGGY_TEMPLATES)
inline
ooShortRef(oojArrayOfObject)::ooShortRefStructor(oojArrayOfObject)(const ooRef(oojArrayOfObject) &  id) :
    ooShortRef(oojArray)(id)
{
}
#endif // !defined(OO_BUGGY_TEMPLATES)
#ifdef OO_BUGGY_TEMPLATES
inline
ooShortRef(oojArrayOfObject)::ooShortRefStructor(oojArrayOfObject)(const ooHandleSuper(oojArrayOfObject) &  objH)
{
  *this = objH;
}
#else // !defined(OO_BUGGY_TEMPLATES)
inline
ooShortRef(oojArrayOfObject)::ooShortRefStructor(oojArrayOfObject)(const ooHandleSuper(oojArrayOfObject) &  objH) :
    ooShortRef(oojArray)(objH)
{
}
#endif // !defined(OO_BUGGY_TEMPLATES)
#ifdef OO_BUGGY_TEMPLATES
inline
ooShortRef(oojArrayOfObject)::ooShortRefStructor(oojArrayOfObject)(const oojArrayOfObject *  fromObject)
{
  *this = fromObject;
}
#else // !defined(OO_BUGGY_TEMPLATES)
inline
ooShortRef(oojArrayOfObject)::ooShortRefStructor(oojArrayOfObject)(const oojArrayOfObject *  fromObject) :
    ooShortRef(oojArray)(ooReinterpretCast(const oojArray *,fromObject))
{
}
#endif // !defined(OO_BUGGY_TEMPLATES)


/* methods on ooHandle(oojArrayOfObject) */
inline
ooHandle(oojArrayOfObject)::ooHandleStructor(oojArrayOfObject)()
{
}
inline
ooHandle(oojArrayOfObject)::ooHandleStructor(oojArrayOfObject)(const ooHandle(oojArrayOfObject) &  objH) :
#ifdef OO_BUGGY_TEMPLATES
    ooHandle_superclass<oojArrayOfObject >(objH)
#else // !defined(OO_BUGGY_TEMPLATES)
    ooHandle(oojArray)(objH)
#endif // !defined(OO_BUGGY_TEMPLATES)
{
}
inline
ooHandle(oojArrayOfObject)::ooHandleStructor(oojArrayOfObject)(const ooRef(oojArrayOfObject) &  id) :
#ifdef OO_BUGGY_TEMPLATES
    ooHandle_superclass<oojArrayOfObject >(id)
#else // !defined(OO_BUGGY_TEMPLATES)
    ooHandle(oojArray)(id)
#endif // !defined(OO_BUGGY_TEMPLATES)
{
}
inline
ooHandle(oojArrayOfObject)::ooHandleStructor(oojArrayOfObject)(const oojArrayOfObject *  fromObject) :
#ifdef OO_BUGGY_TEMPLATES
    ooHandle_superclass<oojArrayOfObject >(ooReinterpretCast(const oojArray *,fromObject))
#else // !defined(OO_BUGGY_TEMPLATES)
    ooHandle(oojArray)(ooReinterpretCast(const oojArray *,fromObject))
#endif // !defined(OO_BUGGY_TEMPLATES)
{
}
inline
ooHandle(oojArrayOfObject)&
ooHandle(oojArrayOfObject)::operator=(const ooRef(oojArrayOfObject) &  id)
{
  this->ooHandle(ooObj)::operator=(id);
  return *this;
}
inline
ooHandle(oojArrayOfObject)&
ooHandle(oojArrayOfObject)::operator=(const ooHandle(oojArrayOfObject) &  objH)
{
  this->ooHandle(ooObj)::operator=(objH);
  return *this;
}
inline
ooHandle(oojArrayOfObject)&
ooHandle(oojArrayOfObject)::operator=(const ooShortRef(oojArrayOfObject) &  shortId)
{
  this->ooHandle(ooObj)::operator=(shortId);
  return *this;
}
inline
ooHandle(oojArrayOfObject)&
ooHandle(oojArrayOfObject)::operator=(const oojArrayOfObject *  fromObject)
{
  this->ooHandle(ooObj)::operator=(ooReinterpretCast(const ooObj *,fromObject));
  return *this;
}
inline
oojArrayOfObject *
ooHandle(oojArrayOfObject)::pin(ooMode  openMode) const
{
  return ooReinterpretCast(oojArrayOfObject *, this->pin_obj_internal(openMode));
}
inline
oojArrayOfObject *
ooHandle(oojArrayOfObject)::operator->() const
{
  return this->vm();
}
inline
oojArrayOfObject &
ooHandle(oojArrayOfObject)::operator*() const
{
  return *(this->vm());
}
inline
ooHandle(oojArrayOfObject)::operator oojArrayOfObject *() const
{
  if ( _state == oocHandlePTR  )
    return ooReinterpretCast(oojArrayOfObject *, _ptr._obj);
  else return ooReinterpretCast(oojArrayOfObject *, this->get_vm());
}
inline
oojArrayOfObject *
ooHandle(oojArrayOfObject)::vm() const
{
  if ( _state == oocHandlePTR && _ptr._obj != NULL )
    return ooReinterpretCast(oojArrayOfObject *, _ptr._obj);
  else return ooReinterpretCast(oojArrayOfObject *, this->get_vm());
}
inline
ooRef(oojArrayOfObject) &
ooHandle(oojArrayOfObject)::copy(const ooHandle(ooObj) &  nearH,
		   ooRef(oojArrayOfObject) &              result) const
{
  this->ooHandle(ooObj)::copy(nearH, result);
  return result;
}


/* ODMG methods */
inline
oojArrayOfObject *
ooRef(oojArrayOfObject)::ptr() const
{
  return this->pin();
}
inline
oojArrayOfObject *
ooHandle(oojArrayOfObject)::ptr() const
{
  return this->operator oojArrayOfObject *();
}
#if defined(_MSC_VER) && !defined(OO_DDL_TRANSLATION)
#pragma pack(pop)
#endif

#endif /* JAVA_BUILTINS_REF_H */

