/* C++ 'references' header file: Objectivity/DB DDL Version: 11.1 */


#ifndef _HELLO_OBJECT_REF_H
#define _HELLO_OBJECT_REF_H

#ifndef OO_H
#include <oo.h>
#endif
#include <ooSchema_ref.h>
#if defined(_MSC_VER) && !defined(OO_DDL_TRANSLATION)
#pragma pack(push,8)
#endif
class HelloObject;


/////////////////////////////////////////////////////////////////////////////

ooTemplateSpecialization
class ooDeref(HelloObject) : public ooDerefBase {
	friend class ooRef(HelloObject);
  public:
    ~ooDerefStructor(HelloObject)();
    inline HelloObject *operator->() const;
#ifndef OO_BUGGY_TEMPLATES
  private:
#endif // !defined(OO_BUGGY_TEMPLATES)
    ooDerefStructor(HelloObject)(ooDeref(HelloObject)& deref);
    ooDerefStructor(HelloObject)(ooObj *  fromObject);
};


#ifdef OO_BUGGY_TEMPLATES

class ooHandle_superclass<HelloObject > : public ooHandle(ooObj) {
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

class ooShortRef_superclass<HelloObject > : public ooShortRef(ooObj) {
};

#endif // OO_BUGGY_TEMPLATES

ooTemplateSpecialization
class ooRef(HelloObject) : public ooRef(ooObj) {
  public:
    ooRefStructor(HelloObject)()
      {}
    ooRefStructor(HelloObject)(const ooRef(HelloObject)& id) :
	  ooRef(ooObj)(id)
      {}
    inline ooRefStructor(HelloObject)(const ooHandleSuper(HelloObject)& objH);
    inline ooRefStructor(HelloObject)(const HelloObject *  fromObject);
    inline ooRef(HelloObject)& operator=(const ooRef(HelloObject)& id);
    inline ooRef(HelloObject)& operator=(const ooShortRefSuper(HelloObject) &shortId);
    inline ooRef(HelloObject)& operator=(const ooHandleSuper(HelloObject)& objH);
    inline ooRef(HelloObject)& operator=(const HelloObject *  fromObject);
    ooStatus lookupObj(const ooHandle(ooObj)& scopeH,
		       const ooKey& key,
		       ooMode openMode = oocRead);
    ooStatus lookupObj(const ooHandle(ooObj)& scopeH,
		       const char* name,
		       ooMode openMode = oocRead);
#ifndef OO_BUGGY_TEMPLATES
    inline ooRef(HelloObject)& copy(const ooHandle(ooObj)& nearH,
		    ooRef(HelloObject)& newObjRef) const;
    inline ooHandle(HelloObject)& copy(const ooHandle(ooObj)& nearH,
			ooHandle(HelloObject)& result) const;
    inline ooHandle(HelloObject) copy(const ooHandle(ooObj)& nearH) const;
#endif // !defined(OO_BUGGY_TEMPLATES)
    inline HelloObject *pin(ooMode openMode = oocRead) const;
    ooDeref(HelloObject) operator->() const;
    /* Use pin() or use ooHandle "operator HelloObject *" instead of vm. */
    /* OBSOLETE */ inline HelloObject *vm(ooMode openMode = oocRead) const;
    // ODMG methods:
    ooRefStructor(HelloObject)(const d_Ref_Any &from);
    HelloObject *ptr() const;
};

ooTemplateSpecialization
class ooShortRef(HelloObject) :
#ifdef OO_BUGGY_TEMPLATES
			public ooShortRef_superclass<HelloObject >
#else // !defined(OO_BUGGY_TEMPLATES)
			public ooShortRef(ooObj)
#endif // !defined(OO_BUGGY_TEMPLATES)
					            {
  public:
    ooShortRefStructor(HelloObject)();
    ooShortRefStructor(HelloObject)(const ooShortRef(HelloObject)& shortId);
    ooShortRefStructor(HelloObject)(const ooRef(HelloObject)& id);
    ooShortRefStructor(HelloObject)(const ooHandleSuper(HelloObject) &objH);
    ooShortRefStructor(HelloObject)(const HelloObject *  fromObject);
    ooShortRef(HelloObject)& operator=(const ooShortRef(HelloObject)& shortId);
    ooShortRef(HelloObject)& operator=(const ooRef(HelloObject)& id);
    ooShortRef(HelloObject)& operator=(const ooHandleSuper(HelloObject) &objH);
    ooShortRef(HelloObject)& operator=(const HelloObject *  fromObject);
};

ooTemplateSpecialization
class ooHandle(HelloObject) :
#ifdef OO_BUGGY_TEMPLATES
		      public ooHandle_superclass<HelloObject >
#else // !defined(OO_BUGGY_TEMPLATES)
		      public ooHandle(ooObj)
#endif // !defined(OO_BUGGY_TEMPLATES)
                                                {
  public:
    inline ooHandleStructor(HelloObject)();
    inline ooHandleStructor(HelloObject)(const ooRef(HelloObject)& id);
    inline ooHandleStructor(HelloObject)(const ooHandle(HelloObject)& objH);
    inline ooHandleStructor(HelloObject)(const HelloObject *  fromObject);
    inline ooHandle(HelloObject)& operator=(const ooRef(HelloObject)& id);
    inline ooHandle(HelloObject)& operator=(const ooHandle(HelloObject)& objH);
    inline ooHandle(HelloObject)& operator=(const ooShortRef(HelloObject)& shortId);
    inline ooHandle(HelloObject)& operator=(const HelloObject *  fromObject);
    ooStatus lookupObj(const ooHandle(ooObj)& scopeH,
		       const ooKey& key,
		       ooMode openMode = oocRead);
    ooStatus lookupObj(const ooHandle(ooObj)& scopeH,
		       const char* name,
		       ooMode openMode = oocRead);
    ooHandle(HelloObject)& copy(const ooHandle(ooObj)& nearH,
		       ooHandle(HelloObject)& result) const;
    inline ooRef(HelloObject)& copy(const ooHandle(ooObj)& nearH,
		    ooRef(HelloObject)& result) const;
    ooHandle(HelloObject) copy(const ooHandle(ooObj)& nearH) const;
    inline HelloObject *pin(ooMode openMode = oocRead) const;
    inline HelloObject *operator->() const;
    inline HelloObject &operator*() const;
    inline operator HelloObject *() const;
    /* Use "operator HelloObject *" instead of vm. */
    /* OBSOLETE */ inline HelloObject *vm() const;
    // ODMG methods:
    ooHandleStructor(HelloObject)(const d_Ref_Any &from);
    HelloObject *ptr() const;
};

ooTemplateSpecialization
class ooItr(HelloObject) : public ooHandle(HelloObject),
		    public ooIteratorObjOrContObj {
  public:
    ooItrStructor(HelloObject)();
    ~ooItrStructor(HelloObject)();
  private:
    // Defined only to prevent implicit definition:
    ooItrStructor(HelloObject)(ooItr(HelloObject)&);
    ooItr(HelloObject)    operator=(ooItr(HelloObject)&);
};


/* methods on ooDeref(HelloObject) */
inline
ooDeref(HelloObject)::ooDerefStructor(HelloObject)(ooDeref(HelloObject) &  deref) :
    ooDerefBase(deref.vm())
{
  this->pinCompensate();
}
inline
ooDeref(HelloObject)::ooDerefStructor(HelloObject)(ooObj *  fromObject) :
    ooDerefBase(fromObject)
{
}
inline
ooDeref(HelloObject)::~ooDerefStructor(HelloObject)()
{
}
inline
HelloObject *
ooDeref(HelloObject)::operator->() const
{
  return ooReinterpretCast(HelloObject *, this->vm());
}


/* methods on ooRef(HelloObject) */
inline
ooRef(HelloObject)::ooRefStructor(HelloObject)(const ooHandleSuper(HelloObject)& objH) :
    ooRef(ooObj)(objH)
{
}
inline
ooRef(HelloObject)::ooRefStructor(HelloObject)(const HelloObject *  fromObject) :
    ooRef(ooObj)(ooReinterpretCast(const ooObj *, fromObject))
{
}
inline
ooRef(HelloObject)&
ooRef(HelloObject)::operator=(const ooRef(HelloObject) &  id)
{
  this->ooId::operator=(id);
  return *this;
}
inline
ooRef(HelloObject)&
ooRef(HelloObject)::operator=(const ooShortRefSuper(HelloObject) &  shortId)
{
  this->ooRef(ooObj)::operator=(shortId);
  return *this;
}
inline
ooRef(HelloObject)&
ooRef(HelloObject)::operator=(const ooHandleSuper(HelloObject) &  objH)
{
  this->ooRef(ooObj)::operator=(objH);
  return *this;
}
inline
ooRef(HelloObject)&
ooRef(HelloObject)::operator=(const HelloObject *  fromObject)
{
  this->ooRef(ooObj)::operator=(ooReinterpretCast(const ooObj *, fromObject));
  return *this;
}
inline
HelloObject *
ooRef(HelloObject)::pin(ooMode  openMode) const
{
  return ooReinterpretCast(HelloObject *, this->pin_ref_internal(openMode));
}
inline
HelloObject *
ooRef(HelloObject)::vm(ooMode  openMode) const
{
  return this->pin(openMode);
}
#ifndef OO_BUGGY_TEMPLATES
inline
ooHandle(HelloObject) &
ooRef(HelloObject)::copy(const ooHandle(ooObj) &  nearH,
		ooHandle(HelloObject) &           result) const
{
  this->ooRef(ooObj)::copy(nearH, result);
  return result;
}
inline
ooRef(HelloObject) &
ooRef(HelloObject)::copy(const ooHandle(ooObj) &  nearH,
		ooRef(HelloObject) &              newObjRef) const
{
  this->ooRef(ooObj)::copy(nearH, newObjRef);
  return newObjRef;
}
inline
ooHandle(HelloObject)
ooRef(HelloObject)::copy(const ooHandle(ooObj) &  nearH) const
{
  ooHandle(HelloObject) result;
  this->ooRef(ooObj)::copy(nearH, result);
  return result;
}
#endif // !defined(OO_BUGGY_TEMPLATES)
inline
ooDeref(HelloObject)
ooRef(HelloObject)::operator->() const
{
  ooDeref(HelloObject) result(this->pin_ref_internal(oocRead));
  return result;
}


/* methods on ooShortRef(HelloObject) */
inline
ooShortRef(HelloObject) &
ooShortRef(HelloObject)::operator=(const ooShortRef(HelloObject) &  shortId)
{
  this->ooShortId::operator=(shortId);
  return *this;
}
inline
ooShortRef(HelloObject) &
ooShortRef(HelloObject)::operator=(const ooRef(HelloObject) &  id)
{
  this->ooShortId::operator=(id);
  return *this;
}
inline
ooShortRef(HelloObject) &
ooShortRef(HelloObject)::operator=(const ooHandleSuper(HelloObject) &  objH)
{
  this->ooShortId::operator=(objH);
  return *this;
}
inline
ooShortRef(HelloObject)&
ooShortRef(HelloObject)::operator=(const HelloObject *  fromObject)
{
  this->ooShortId::operator=(ooReinterpretCast(const ooObj *,fromObject));
  return *this;
}
inline
ooShortRef(HelloObject)::ooShortRefStructor(HelloObject)()
{
}
#ifdef OO_BUGGY_TEMPLATES
inline
ooShortRef(HelloObject)::ooShortRefStructor(HelloObject)(const ooShortRef(HelloObject) &  shortId)
{
  *this = shortId;
}
#else // !defined(OO_BUGGY_TEMPLATES)
inline
ooShortRef(HelloObject)::ooShortRefStructor(HelloObject)(const ooShortRef(HelloObject) &  shortId) :
    ooShortRef(ooObj)(shortId)
{
}
#endif // !defined(OO_BUGGY_TEMPLATES)
#ifdef OO_BUGGY_TEMPLATES
inline
ooShortRef(HelloObject)::ooShortRefStructor(HelloObject)(const ooRef(HelloObject) &  id)
{
  *this = id;
}
#else // !defined(OO_BUGGY_TEMPLATES)
inline
ooShortRef(HelloObject)::ooShortRefStructor(HelloObject)(const ooRef(HelloObject) &  id) :
    ooShortRef(ooObj)(id)
{
}
#endif // !defined(OO_BUGGY_TEMPLATES)
#ifdef OO_BUGGY_TEMPLATES
inline
ooShortRef(HelloObject)::ooShortRefStructor(HelloObject)(const ooHandleSuper(HelloObject) &  objH)
{
  *this = objH;
}
#else // !defined(OO_BUGGY_TEMPLATES)
inline
ooShortRef(HelloObject)::ooShortRefStructor(HelloObject)(const ooHandleSuper(HelloObject) &  objH) :
    ooShortRef(ooObj)(objH)
{
}
#endif // !defined(OO_BUGGY_TEMPLATES)
#ifdef OO_BUGGY_TEMPLATES
inline
ooShortRef(HelloObject)::ooShortRefStructor(HelloObject)(const HelloObject *  fromObject)
{
  *this = fromObject;
}
#else // !defined(OO_BUGGY_TEMPLATES)
inline
ooShortRef(HelloObject)::ooShortRefStructor(HelloObject)(const HelloObject *  fromObject) :
    ooShortRef(ooObj)(ooReinterpretCast(const ooObj *,fromObject))
{
}
#endif // !defined(OO_BUGGY_TEMPLATES)


/* methods on ooHandle(HelloObject) */
inline
ooHandle(HelloObject)::ooHandleStructor(HelloObject)()
{
}
inline
ooHandle(HelloObject)::ooHandleStructor(HelloObject)(const ooHandle(HelloObject) &  objH) :
#ifdef OO_BUGGY_TEMPLATES
    ooHandle_superclass<HelloObject >(objH)
#else // !defined(OO_BUGGY_TEMPLATES)
    ooHandle(ooObj)(objH)
#endif // !defined(OO_BUGGY_TEMPLATES)
{
}
inline
ooHandle(HelloObject)::ooHandleStructor(HelloObject)(const ooRef(HelloObject) &  id) :
#ifdef OO_BUGGY_TEMPLATES
    ooHandle_superclass<HelloObject >(id)
#else // !defined(OO_BUGGY_TEMPLATES)
    ooHandle(ooObj)(id)
#endif // !defined(OO_BUGGY_TEMPLATES)
{
}
inline
ooHandle(HelloObject)::ooHandleStructor(HelloObject)(const HelloObject *  fromObject) :
#ifdef OO_BUGGY_TEMPLATES
    ooHandle_superclass<HelloObject >(ooReinterpretCast(const ooObj *,fromObject))
#else // !defined(OO_BUGGY_TEMPLATES)
    ooHandle(ooObj)(ooReinterpretCast(const ooObj *,fromObject))
#endif // !defined(OO_BUGGY_TEMPLATES)
{
}
inline
ooHandle(HelloObject)&
ooHandle(HelloObject)::operator=(const ooRef(HelloObject) &  id)
{
  this->ooHandle(ooObj)::operator=(id);
  return *this;
}
inline
ooHandle(HelloObject)&
ooHandle(HelloObject)::operator=(const ooHandle(HelloObject) &  objH)
{
  this->ooHandle(ooObj)::operator=(objH);
  return *this;
}
inline
ooHandle(HelloObject)&
ooHandle(HelloObject)::operator=(const ooShortRef(HelloObject) &  shortId)
{
  this->ooHandle(ooObj)::operator=(shortId);
  return *this;
}
inline
ooHandle(HelloObject)&
ooHandle(HelloObject)::operator=(const HelloObject *  fromObject)
{
  this->ooHandle(ooObj)::operator=(ooReinterpretCast(const ooObj *,fromObject));
  return *this;
}
inline
HelloObject *
ooHandle(HelloObject)::pin(ooMode  openMode) const
{
  return ooReinterpretCast(HelloObject *, this->pin_obj_internal(openMode));
}
inline
HelloObject *
ooHandle(HelloObject)::operator->() const
{
  return this->vm();
}
inline
HelloObject &
ooHandle(HelloObject)::operator*() const
{
  return *(this->vm());
}
inline
ooHandle(HelloObject)::operator HelloObject *() const
{
  if ( _state == oocHandlePTR  )
    return ooReinterpretCast(HelloObject *, _ptr._obj);
  else return ooReinterpretCast(HelloObject *, this->get_vm());
}
inline
HelloObject *
ooHandle(HelloObject)::vm() const
{
  if ( _state == oocHandlePTR && _ptr._obj != NULL )
    return ooReinterpretCast(HelloObject *, _ptr._obj);
  else return ooReinterpretCast(HelloObject *, this->get_vm());
}
inline
ooRef(HelloObject) &
ooHandle(HelloObject)::copy(const ooHandle(ooObj) &  nearH,
		   ooRef(HelloObject) &              result) const
{
  this->ooHandle(ooObj)::copy(nearH, result);
  return result;
}


/* ODMG methods */
inline
HelloObject *
ooRef(HelloObject)::ptr() const
{
  return this->pin();
}
inline
HelloObject *
ooHandle(HelloObject)::ptr() const
{
  return this->operator HelloObject *();
}
#if defined(_MSC_VER) && !defined(OO_DDL_TRANSLATION)
#pragma pack(pop)
#endif

#endif /* _HELLO_OBJECT_REF_H */

