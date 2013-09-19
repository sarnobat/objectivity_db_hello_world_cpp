/* C++ 'references' header file: Objectivity/DB DDL Version: 11.1 */


#ifndef OO_COLLECTION_BASE_REF_H
#define OO_COLLECTION_BASE_REF_H

#ifndef OO_H
#include <oo.h>
#endif
#include <ooSchema_ref.h>
#if defined(_MSC_VER) && !defined(OO_DDL_TRANSLATION)
#pragma pack(push,8)
#endif
class ooCompare;


/////////////////////////////////////////////////////////////////////////////

ooTemplateSpecialization
class ooDeref(ooCompare) : public ooDerefBase {
	friend class ooRef(ooCompare);
  public:
    ~ooDerefStructor(ooCompare)();
    inline ooCompare *operator->() const;
#ifndef OO_BUGGY_TEMPLATES
  private:
#endif // !defined(OO_BUGGY_TEMPLATES)
    ooDerefStructor(ooCompare)(ooDeref(ooCompare)& deref);
    ooDerefStructor(ooCompare)(ooObj *  fromObject);
};


#ifdef OO_BUGGY_TEMPLATES

class ooHandle_superclass<ooCompare > : public ooHandle(ooObj) {
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

class ooShortRef_superclass<ooCompare > : public ooShortRef(ooObj) {
};

#endif // OO_BUGGY_TEMPLATES

ooTemplateSpecialization
class ooRef(ooCompare) : public ooRef(ooObj) {
  public:
    ooRefStructor(ooCompare)()
      {}
    ooRefStructor(ooCompare)(const ooRef(ooCompare)& id) :
	  ooRef(ooObj)(id)
      {}
    inline ooRefStructor(ooCompare)(const ooHandleSuper(ooCompare)& objH);
    inline ooRefStructor(ooCompare)(const ooCompare *  fromObject);
    inline ooRef(ooCompare)& operator=(const ooRef(ooCompare)& id);
    inline ooRef(ooCompare)& operator=(const ooShortRefSuper(ooCompare) &shortId);
    inline ooRef(ooCompare)& operator=(const ooHandleSuper(ooCompare)& objH);
    inline ooRef(ooCompare)& operator=(const ooCompare *  fromObject);
    ooStatus lookupObj(const ooHandle(ooObj)& scopeH,
		       const ooKey& key,
		       ooMode openMode = oocRead);
    ooStatus lookupObj(const ooHandle(ooObj)& scopeH,
		       const char* name,
		       ooMode openMode = oocRead);
#ifndef OO_BUGGY_TEMPLATES
    inline ooRef(ooCompare)& copy(const ooHandle(ooObj)& nearH,
		    ooRef(ooCompare)& newObjRef) const;
    inline ooHandle(ooCompare)& copy(const ooHandle(ooObj)& nearH,
			ooHandle(ooCompare)& result) const;
    inline ooHandle(ooCompare) copy(const ooHandle(ooObj)& nearH) const;
#endif // !defined(OO_BUGGY_TEMPLATES)
    inline ooCompare *pin(ooMode openMode = oocRead) const;
    ooDeref(ooCompare) operator->() const;
    /* Use pin() or use ooHandle "operator ooCompare *" instead of vm. */
    /* OBSOLETE */ inline ooCompare *vm(ooMode openMode = oocRead) const;
    // ODMG methods:
    ooRefStructor(ooCompare)(const d_Ref_Any &from);
    ooCompare *ptr() const;
};

ooTemplateSpecialization
class ooShortRef(ooCompare) :
#ifdef OO_BUGGY_TEMPLATES
			public ooShortRef_superclass<ooCompare >
#else // !defined(OO_BUGGY_TEMPLATES)
			public ooShortRef(ooObj)
#endif // !defined(OO_BUGGY_TEMPLATES)
					            {
  public:
    ooShortRefStructor(ooCompare)();
    ooShortRefStructor(ooCompare)(const ooShortRef(ooCompare)& shortId);
    ooShortRefStructor(ooCompare)(const ooRef(ooCompare)& id);
    ooShortRefStructor(ooCompare)(const ooHandleSuper(ooCompare) &objH);
    ooShortRefStructor(ooCompare)(const ooCompare *  fromObject);
    ooShortRef(ooCompare)& operator=(const ooShortRef(ooCompare)& shortId);
    ooShortRef(ooCompare)& operator=(const ooRef(ooCompare)& id);
    ooShortRef(ooCompare)& operator=(const ooHandleSuper(ooCompare) &objH);
    ooShortRef(ooCompare)& operator=(const ooCompare *  fromObject);
};

ooTemplateSpecialization
class ooHandle(ooCompare) :
#ifdef OO_BUGGY_TEMPLATES
		      public ooHandle_superclass<ooCompare >
#else // !defined(OO_BUGGY_TEMPLATES)
		      public ooHandle(ooObj)
#endif // !defined(OO_BUGGY_TEMPLATES)
                                                {
  public:
    inline ooHandleStructor(ooCompare)();
    inline ooHandleStructor(ooCompare)(const ooRef(ooCompare)& id);
    inline ooHandleStructor(ooCompare)(const ooHandle(ooCompare)& objH);
    inline ooHandleStructor(ooCompare)(const ooCompare *  fromObject);
    inline ooHandle(ooCompare)& operator=(const ooRef(ooCompare)& id);
    inline ooHandle(ooCompare)& operator=(const ooHandle(ooCompare)& objH);
    inline ooHandle(ooCompare)& operator=(const ooShortRef(ooCompare)& shortId);
    inline ooHandle(ooCompare)& operator=(const ooCompare *  fromObject);
    ooStatus lookupObj(const ooHandle(ooObj)& scopeH,
		       const ooKey& key,
		       ooMode openMode = oocRead);
    ooStatus lookupObj(const ooHandle(ooObj)& scopeH,
		       const char* name,
		       ooMode openMode = oocRead);
    ooHandle(ooCompare)& copy(const ooHandle(ooObj)& nearH,
		       ooHandle(ooCompare)& result) const;
    inline ooRef(ooCompare)& copy(const ooHandle(ooObj)& nearH,
		    ooRef(ooCompare)& result) const;
    ooHandle(ooCompare) copy(const ooHandle(ooObj)& nearH) const;
    inline ooCompare *pin(ooMode openMode = oocRead) const;
    inline ooCompare *operator->() const;
    inline ooCompare &operator*() const;
    inline operator ooCompare *() const;
    /* Use "operator ooCompare *" instead of vm. */
    /* OBSOLETE */ inline ooCompare *vm() const;
    // ODMG methods:
    ooHandleStructor(ooCompare)(const d_Ref_Any &from);
    ooCompare *ptr() const;
};

ooTemplateSpecialization
class ooItr(ooCompare) : public ooHandle(ooCompare),
		    public ooIteratorObjOrContObj {
  public:
    ooItrStructor(ooCompare)();
    ~ooItrStructor(ooCompare)();
  private:
    // Defined only to prevent implicit definition:
    ooItrStructor(ooCompare)(ooItr(ooCompare)&);
    ooItr(ooCompare)    operator=(ooItr(ooCompare)&);
};


/* methods on ooDeref(ooCompare) */
inline
ooDeref(ooCompare)::ooDerefStructor(ooCompare)(ooDeref(ooCompare) &  deref) :
    ooDerefBase(deref.vm())
{
  this->pinCompensate();
}
inline
ooDeref(ooCompare)::ooDerefStructor(ooCompare)(ooObj *  fromObject) :
    ooDerefBase(fromObject)
{
}
inline
ooDeref(ooCompare)::~ooDerefStructor(ooCompare)()
{
}
inline
ooCompare *
ooDeref(ooCompare)::operator->() const
{
  return ooReinterpretCast(ooCompare *, this->vm());
}


/* methods on ooRef(ooCompare) */
inline
ooRef(ooCompare)::ooRefStructor(ooCompare)(const ooHandleSuper(ooCompare)& objH) :
    ooRef(ooObj)(objH)
{
}
inline
ooRef(ooCompare)::ooRefStructor(ooCompare)(const ooCompare *  fromObject) :
    ooRef(ooObj)(ooReinterpretCast(const ooObj *, fromObject))
{
}
inline
ooRef(ooCompare)&
ooRef(ooCompare)::operator=(const ooRef(ooCompare) &  id)
{
  this->ooId::operator=(id);
  return *this;
}
inline
ooRef(ooCompare)&
ooRef(ooCompare)::operator=(const ooShortRefSuper(ooCompare) &  shortId)
{
  this->ooRef(ooObj)::operator=(shortId);
  return *this;
}
inline
ooRef(ooCompare)&
ooRef(ooCompare)::operator=(const ooHandleSuper(ooCompare) &  objH)
{
  this->ooRef(ooObj)::operator=(objH);
  return *this;
}
inline
ooRef(ooCompare)&
ooRef(ooCompare)::operator=(const ooCompare *  fromObject)
{
  this->ooRef(ooObj)::operator=(ooReinterpretCast(const ooObj *, fromObject));
  return *this;
}
inline
ooCompare *
ooRef(ooCompare)::pin(ooMode  openMode) const
{
  return ooReinterpretCast(ooCompare *, this->pin_ref_internal(openMode));
}
inline
ooCompare *
ooRef(ooCompare)::vm(ooMode  openMode) const
{
  return this->pin(openMode);
}
#ifndef OO_BUGGY_TEMPLATES
inline
ooHandle(ooCompare) &
ooRef(ooCompare)::copy(const ooHandle(ooObj) &  nearH,
		ooHandle(ooCompare) &           result) const
{
  this->ooRef(ooObj)::copy(nearH, result);
  return result;
}
inline
ooRef(ooCompare) &
ooRef(ooCompare)::copy(const ooHandle(ooObj) &  nearH,
		ooRef(ooCompare) &              newObjRef) const
{
  this->ooRef(ooObj)::copy(nearH, newObjRef);
  return newObjRef;
}
inline
ooHandle(ooCompare)
ooRef(ooCompare)::copy(const ooHandle(ooObj) &  nearH) const
{
  ooHandle(ooCompare) result;
  this->ooRef(ooObj)::copy(nearH, result);
  return result;
}
#endif // !defined(OO_BUGGY_TEMPLATES)
inline
ooDeref(ooCompare)
ooRef(ooCompare)::operator->() const
{
  ooDeref(ooCompare) result(this->pin_ref_internal(oocRead));
  return result;
}


/* methods on ooShortRef(ooCompare) */
inline
ooShortRef(ooCompare) &
ooShortRef(ooCompare)::operator=(const ooShortRef(ooCompare) &  shortId)
{
  this->ooShortId::operator=(shortId);
  return *this;
}
inline
ooShortRef(ooCompare) &
ooShortRef(ooCompare)::operator=(const ooRef(ooCompare) &  id)
{
  this->ooShortId::operator=(id);
  return *this;
}
inline
ooShortRef(ooCompare) &
ooShortRef(ooCompare)::operator=(const ooHandleSuper(ooCompare) &  objH)
{
  this->ooShortId::operator=(objH);
  return *this;
}
inline
ooShortRef(ooCompare)&
ooShortRef(ooCompare)::operator=(const ooCompare *  fromObject)
{
  this->ooShortId::operator=(ooReinterpretCast(const ooObj *,fromObject));
  return *this;
}
inline
ooShortRef(ooCompare)::ooShortRefStructor(ooCompare)()
{
}
#ifdef OO_BUGGY_TEMPLATES
inline
ooShortRef(ooCompare)::ooShortRefStructor(ooCompare)(const ooShortRef(ooCompare) &  shortId)
{
  *this = shortId;
}
#else // !defined(OO_BUGGY_TEMPLATES)
inline
ooShortRef(ooCompare)::ooShortRefStructor(ooCompare)(const ooShortRef(ooCompare) &  shortId) :
    ooShortRef(ooObj)(shortId)
{
}
#endif // !defined(OO_BUGGY_TEMPLATES)
#ifdef OO_BUGGY_TEMPLATES
inline
ooShortRef(ooCompare)::ooShortRefStructor(ooCompare)(const ooRef(ooCompare) &  id)
{
  *this = id;
}
#else // !defined(OO_BUGGY_TEMPLATES)
inline
ooShortRef(ooCompare)::ooShortRefStructor(ooCompare)(const ooRef(ooCompare) &  id) :
    ooShortRef(ooObj)(id)
{
}
#endif // !defined(OO_BUGGY_TEMPLATES)
#ifdef OO_BUGGY_TEMPLATES
inline
ooShortRef(ooCompare)::ooShortRefStructor(ooCompare)(const ooHandleSuper(ooCompare) &  objH)
{
  *this = objH;
}
#else // !defined(OO_BUGGY_TEMPLATES)
inline
ooShortRef(ooCompare)::ooShortRefStructor(ooCompare)(const ooHandleSuper(ooCompare) &  objH) :
    ooShortRef(ooObj)(objH)
{
}
#endif // !defined(OO_BUGGY_TEMPLATES)
#ifdef OO_BUGGY_TEMPLATES
inline
ooShortRef(ooCompare)::ooShortRefStructor(ooCompare)(const ooCompare *  fromObject)
{
  *this = fromObject;
}
#else // !defined(OO_BUGGY_TEMPLATES)
inline
ooShortRef(ooCompare)::ooShortRefStructor(ooCompare)(const ooCompare *  fromObject) :
    ooShortRef(ooObj)(ooReinterpretCast(const ooObj *,fromObject))
{
}
#endif // !defined(OO_BUGGY_TEMPLATES)


/* methods on ooHandle(ooCompare) */
inline
ooHandle(ooCompare)::ooHandleStructor(ooCompare)()
{
}
inline
ooHandle(ooCompare)::ooHandleStructor(ooCompare)(const ooHandle(ooCompare) &  objH) :
#ifdef OO_BUGGY_TEMPLATES
    ooHandle_superclass<ooCompare >(objH)
#else // !defined(OO_BUGGY_TEMPLATES)
    ooHandle(ooObj)(objH)
#endif // !defined(OO_BUGGY_TEMPLATES)
{
}
inline
ooHandle(ooCompare)::ooHandleStructor(ooCompare)(const ooRef(ooCompare) &  id) :
#ifdef OO_BUGGY_TEMPLATES
    ooHandle_superclass<ooCompare >(id)
#else // !defined(OO_BUGGY_TEMPLATES)
    ooHandle(ooObj)(id)
#endif // !defined(OO_BUGGY_TEMPLATES)
{
}
inline
ooHandle(ooCompare)::ooHandleStructor(ooCompare)(const ooCompare *  fromObject) :
#ifdef OO_BUGGY_TEMPLATES
    ooHandle_superclass<ooCompare >(ooReinterpretCast(const ooObj *,fromObject))
#else // !defined(OO_BUGGY_TEMPLATES)
    ooHandle(ooObj)(ooReinterpretCast(const ooObj *,fromObject))
#endif // !defined(OO_BUGGY_TEMPLATES)
{
}
inline
ooHandle(ooCompare)&
ooHandle(ooCompare)::operator=(const ooRef(ooCompare) &  id)
{
  this->ooHandle(ooObj)::operator=(id);
  return *this;
}
inline
ooHandle(ooCompare)&
ooHandle(ooCompare)::operator=(const ooHandle(ooCompare) &  objH)
{
  this->ooHandle(ooObj)::operator=(objH);
  return *this;
}
inline
ooHandle(ooCompare)&
ooHandle(ooCompare)::operator=(const ooShortRef(ooCompare) &  shortId)
{
  this->ooHandle(ooObj)::operator=(shortId);
  return *this;
}
inline
ooHandle(ooCompare)&
ooHandle(ooCompare)::operator=(const ooCompare *  fromObject)
{
  this->ooHandle(ooObj)::operator=(ooReinterpretCast(const ooObj *,fromObject));
  return *this;
}
inline
ooCompare *
ooHandle(ooCompare)::pin(ooMode  openMode) const
{
  return ooReinterpretCast(ooCompare *, this->pin_obj_internal(openMode));
}
inline
ooCompare *
ooHandle(ooCompare)::operator->() const
{
  return this->vm();
}
inline
ooCompare &
ooHandle(ooCompare)::operator*() const
{
  return *(this->vm());
}
inline
ooHandle(ooCompare)::operator ooCompare *() const
{
  if ( _state == oocHandlePTR  )
    return ooReinterpretCast(ooCompare *, _ptr._obj);
  else return ooReinterpretCast(ooCompare *, this->get_vm());
}
inline
ooCompare *
ooHandle(ooCompare)::vm() const
{
  if ( _state == oocHandlePTR && _ptr._obj != NULL )
    return ooReinterpretCast(ooCompare *, _ptr._obj);
  else return ooReinterpretCast(ooCompare *, this->get_vm());
}
inline
ooRef(ooCompare) &
ooHandle(ooCompare)::copy(const ooHandle(ooObj) &  nearH,
		   ooRef(ooCompare) &              result) const
{
  this->ooHandle(ooObj)::copy(nearH, result);
  return result;
}


/* ODMG methods */
inline
ooCompare *
ooRef(ooCompare)::ptr() const
{
  return this->pin();
}
inline
ooCompare *
ooHandle(ooCompare)::ptr() const
{
  return this->operator ooCompare *();
}
class ooCollection;


/////////////////////////////////////////////////////////////////////////////

ooTemplateSpecialization
class ooDeref(ooCollection) : public ooDerefBase {
	friend class ooRef(ooCollection);
  public:
    ~ooDerefStructor(ooCollection)();
    inline ooCollection *operator->() const;
#ifndef OO_BUGGY_TEMPLATES
  private:
#endif // !defined(OO_BUGGY_TEMPLATES)
    ooDerefStructor(ooCollection)(ooDeref(ooCollection)& deref);
    ooDerefStructor(ooCollection)(ooObj *  fromObject);
};


#ifdef OO_BUGGY_TEMPLATES

class ooHandle_superclass<ooCollection > : public ooHandle(ooObj) {
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

class ooShortRef_superclass<ooCollection > : public ooShortRef(ooObj) {
};

#endif // OO_BUGGY_TEMPLATES

ooTemplateSpecialization
class ooRef(ooCollection) : public ooRef(ooObj) {
  public:
    ooRefStructor(ooCollection)()
      {}
    ooRefStructor(ooCollection)(const ooRef(ooCollection)& id) :
	  ooRef(ooObj)(id)
      {}
    inline ooRefStructor(ooCollection)(const ooHandleSuper(ooCollection)& objH);
    inline ooRefStructor(ooCollection)(const ooCollection *  fromObject);
    inline ooRef(ooCollection)& operator=(const ooRef(ooCollection)& id);
    inline ooRef(ooCollection)& operator=(const ooShortRefSuper(ooCollection) &shortId);
    inline ooRef(ooCollection)& operator=(const ooHandleSuper(ooCollection)& objH);
    inline ooRef(ooCollection)& operator=(const ooCollection *  fromObject);
    ooStatus lookupObj(const ooHandle(ooObj)& scopeH,
		       const ooKey& key,
		       ooMode openMode = oocRead);
    ooStatus lookupObj(const ooHandle(ooObj)& scopeH,
		       const char* name,
		       ooMode openMode = oocRead);
#ifndef OO_BUGGY_TEMPLATES
    inline ooRef(ooCollection)& copy(const ooHandle(ooObj)& nearH,
		    ooRef(ooCollection)& newObjRef) const;
    inline ooHandle(ooCollection)& copy(const ooHandle(ooObj)& nearH,
			ooHandle(ooCollection)& result) const;
    inline ooHandle(ooCollection) copy(const ooHandle(ooObj)& nearH) const;
#endif // !defined(OO_BUGGY_TEMPLATES)
    inline ooCollection *pin(ooMode openMode = oocRead) const;
    ooDeref(ooCollection) operator->() const;
    /* Use pin() or use ooHandle "operator ooCollection *" instead of vm. */
    /* OBSOLETE */ inline ooCollection *vm(ooMode openMode = oocRead) const;
    // ODMG methods:
    ooRefStructor(ooCollection)(const d_Ref_Any &from);
    ooCollection *ptr() const;
};

ooTemplateSpecialization
class ooShortRef(ooCollection) :
#ifdef OO_BUGGY_TEMPLATES
			public ooShortRef_superclass<ooCollection >
#else // !defined(OO_BUGGY_TEMPLATES)
			public ooShortRef(ooObj)
#endif // !defined(OO_BUGGY_TEMPLATES)
					            {
  public:
    ooShortRefStructor(ooCollection)();
    ooShortRefStructor(ooCollection)(const ooShortRef(ooCollection)& shortId);
    ooShortRefStructor(ooCollection)(const ooRef(ooCollection)& id);
    ooShortRefStructor(ooCollection)(const ooHandleSuper(ooCollection) &objH);
    ooShortRefStructor(ooCollection)(const ooCollection *  fromObject);
    ooShortRef(ooCollection)& operator=(const ooShortRef(ooCollection)& shortId);
    ooShortRef(ooCollection)& operator=(const ooRef(ooCollection)& id);
    ooShortRef(ooCollection)& operator=(const ooHandleSuper(ooCollection) &objH);
    ooShortRef(ooCollection)& operator=(const ooCollection *  fromObject);
};

ooTemplateSpecialization
class ooHandle(ooCollection) :
#ifdef OO_BUGGY_TEMPLATES
		      public ooHandle_superclass<ooCollection >
#else // !defined(OO_BUGGY_TEMPLATES)
		      public ooHandle(ooObj)
#endif // !defined(OO_BUGGY_TEMPLATES)
                                                {
  public:
    inline ooHandleStructor(ooCollection)();
    inline ooHandleStructor(ooCollection)(const ooRef(ooCollection)& id);
    inline ooHandleStructor(ooCollection)(const ooHandle(ooCollection)& objH);
    inline ooHandleStructor(ooCollection)(const ooCollection *  fromObject);
    inline ooHandle(ooCollection)& operator=(const ooRef(ooCollection)& id);
    inline ooHandle(ooCollection)& operator=(const ooHandle(ooCollection)& objH);
    inline ooHandle(ooCollection)& operator=(const ooShortRef(ooCollection)& shortId);
    inline ooHandle(ooCollection)& operator=(const ooCollection *  fromObject);
    ooStatus lookupObj(const ooHandle(ooObj)& scopeH,
		       const ooKey& key,
		       ooMode openMode = oocRead);
    ooStatus lookupObj(const ooHandle(ooObj)& scopeH,
		       const char* name,
		       ooMode openMode = oocRead);
    ooHandle(ooCollection)& copy(const ooHandle(ooObj)& nearH,
		       ooHandle(ooCollection)& result) const;
    inline ooRef(ooCollection)& copy(const ooHandle(ooObj)& nearH,
		    ooRef(ooCollection)& result) const;
    ooHandle(ooCollection) copy(const ooHandle(ooObj)& nearH) const;
    inline ooCollection *pin(ooMode openMode = oocRead) const;
    inline ooCollection *operator->() const;
    inline ooCollection &operator*() const;
    inline operator ooCollection *() const;
    /* Use "operator ooCollection *" instead of vm. */
    /* OBSOLETE */ inline ooCollection *vm() const;
    // ODMG methods:
    ooHandleStructor(ooCollection)(const d_Ref_Any &from);
    ooCollection *ptr() const;
};

ooTemplateSpecialization
class ooItr(ooCollection) : public ooHandle(ooCollection),
		    public ooIteratorObjOrContObj {
  public:
    ooItrStructor(ooCollection)();
    ~ooItrStructor(ooCollection)();
  private:
    // Defined only to prevent implicit definition:
    ooItrStructor(ooCollection)(ooItr(ooCollection)&);
    ooItr(ooCollection)    operator=(ooItr(ooCollection)&);
};


/* methods on ooDeref(ooCollection) */
inline
ooDeref(ooCollection)::ooDerefStructor(ooCollection)(ooDeref(ooCollection) &  deref) :
    ooDerefBase(deref.vm())
{
  this->pinCompensate();
}
inline
ooDeref(ooCollection)::ooDerefStructor(ooCollection)(ooObj *  fromObject) :
    ooDerefBase(fromObject)
{
}
inline
ooDeref(ooCollection)::~ooDerefStructor(ooCollection)()
{
}
inline
ooCollection *
ooDeref(ooCollection)::operator->() const
{
  return ooReinterpretCast(ooCollection *, this->vm());
}


/* methods on ooRef(ooCollection) */
inline
ooRef(ooCollection)::ooRefStructor(ooCollection)(const ooHandleSuper(ooCollection)& objH) :
    ooRef(ooObj)(objH)
{
}
inline
ooRef(ooCollection)::ooRefStructor(ooCollection)(const ooCollection *  fromObject) :
    ooRef(ooObj)(ooReinterpretCast(const ooObj *, fromObject))
{
}
inline
ooRef(ooCollection)&
ooRef(ooCollection)::operator=(const ooRef(ooCollection) &  id)
{
  this->ooId::operator=(id);
  return *this;
}
inline
ooRef(ooCollection)&
ooRef(ooCollection)::operator=(const ooShortRefSuper(ooCollection) &  shortId)
{
  this->ooRef(ooObj)::operator=(shortId);
  return *this;
}
inline
ooRef(ooCollection)&
ooRef(ooCollection)::operator=(const ooHandleSuper(ooCollection) &  objH)
{
  this->ooRef(ooObj)::operator=(objH);
  return *this;
}
inline
ooRef(ooCollection)&
ooRef(ooCollection)::operator=(const ooCollection *  fromObject)
{
  this->ooRef(ooObj)::operator=(ooReinterpretCast(const ooObj *, fromObject));
  return *this;
}
inline
ooCollection *
ooRef(ooCollection)::pin(ooMode  openMode) const
{
  return ooReinterpretCast(ooCollection *, this->pin_ref_internal(openMode));
}
inline
ooCollection *
ooRef(ooCollection)::vm(ooMode  openMode) const
{
  return this->pin(openMode);
}
#ifndef OO_BUGGY_TEMPLATES
inline
ooHandle(ooCollection) &
ooRef(ooCollection)::copy(const ooHandle(ooObj) &  nearH,
		ooHandle(ooCollection) &           result) const
{
  this->ooRef(ooObj)::copy(nearH, result);
  return result;
}
inline
ooRef(ooCollection) &
ooRef(ooCollection)::copy(const ooHandle(ooObj) &  nearH,
		ooRef(ooCollection) &              newObjRef) const
{
  this->ooRef(ooObj)::copy(nearH, newObjRef);
  return newObjRef;
}
inline
ooHandle(ooCollection)
ooRef(ooCollection)::copy(const ooHandle(ooObj) &  nearH) const
{
  ooHandle(ooCollection) result;
  this->ooRef(ooObj)::copy(nearH, result);
  return result;
}
#endif // !defined(OO_BUGGY_TEMPLATES)
inline
ooDeref(ooCollection)
ooRef(ooCollection)::operator->() const
{
  ooDeref(ooCollection) result(this->pin_ref_internal(oocRead));
  return result;
}


/* methods on ooShortRef(ooCollection) */
inline
ooShortRef(ooCollection) &
ooShortRef(ooCollection)::operator=(const ooShortRef(ooCollection) &  shortId)
{
  this->ooShortId::operator=(shortId);
  return *this;
}
inline
ooShortRef(ooCollection) &
ooShortRef(ooCollection)::operator=(const ooRef(ooCollection) &  id)
{
  this->ooShortId::operator=(id);
  return *this;
}
inline
ooShortRef(ooCollection) &
ooShortRef(ooCollection)::operator=(const ooHandleSuper(ooCollection) &  objH)
{
  this->ooShortId::operator=(objH);
  return *this;
}
inline
ooShortRef(ooCollection)&
ooShortRef(ooCollection)::operator=(const ooCollection *  fromObject)
{
  this->ooShortId::operator=(ooReinterpretCast(const ooObj *,fromObject));
  return *this;
}
inline
ooShortRef(ooCollection)::ooShortRefStructor(ooCollection)()
{
}
#ifdef OO_BUGGY_TEMPLATES
inline
ooShortRef(ooCollection)::ooShortRefStructor(ooCollection)(const ooShortRef(ooCollection) &  shortId)
{
  *this = shortId;
}
#else // !defined(OO_BUGGY_TEMPLATES)
inline
ooShortRef(ooCollection)::ooShortRefStructor(ooCollection)(const ooShortRef(ooCollection) &  shortId) :
    ooShortRef(ooObj)(shortId)
{
}
#endif // !defined(OO_BUGGY_TEMPLATES)
#ifdef OO_BUGGY_TEMPLATES
inline
ooShortRef(ooCollection)::ooShortRefStructor(ooCollection)(const ooRef(ooCollection) &  id)
{
  *this = id;
}
#else // !defined(OO_BUGGY_TEMPLATES)
inline
ooShortRef(ooCollection)::ooShortRefStructor(ooCollection)(const ooRef(ooCollection) &  id) :
    ooShortRef(ooObj)(id)
{
}
#endif // !defined(OO_BUGGY_TEMPLATES)
#ifdef OO_BUGGY_TEMPLATES
inline
ooShortRef(ooCollection)::ooShortRefStructor(ooCollection)(const ooHandleSuper(ooCollection) &  objH)
{
  *this = objH;
}
#else // !defined(OO_BUGGY_TEMPLATES)
inline
ooShortRef(ooCollection)::ooShortRefStructor(ooCollection)(const ooHandleSuper(ooCollection) &  objH) :
    ooShortRef(ooObj)(objH)
{
}
#endif // !defined(OO_BUGGY_TEMPLATES)
#ifdef OO_BUGGY_TEMPLATES
inline
ooShortRef(ooCollection)::ooShortRefStructor(ooCollection)(const ooCollection *  fromObject)
{
  *this = fromObject;
}
#else // !defined(OO_BUGGY_TEMPLATES)
inline
ooShortRef(ooCollection)::ooShortRefStructor(ooCollection)(const ooCollection *  fromObject) :
    ooShortRef(ooObj)(ooReinterpretCast(const ooObj *,fromObject))
{
}
#endif // !defined(OO_BUGGY_TEMPLATES)


/* methods on ooHandle(ooCollection) */
inline
ooHandle(ooCollection)::ooHandleStructor(ooCollection)()
{
}
inline
ooHandle(ooCollection)::ooHandleStructor(ooCollection)(const ooHandle(ooCollection) &  objH) :
#ifdef OO_BUGGY_TEMPLATES
    ooHandle_superclass<ooCollection >(objH)
#else // !defined(OO_BUGGY_TEMPLATES)
    ooHandle(ooObj)(objH)
#endif // !defined(OO_BUGGY_TEMPLATES)
{
}
inline
ooHandle(ooCollection)::ooHandleStructor(ooCollection)(const ooRef(ooCollection) &  id) :
#ifdef OO_BUGGY_TEMPLATES
    ooHandle_superclass<ooCollection >(id)
#else // !defined(OO_BUGGY_TEMPLATES)
    ooHandle(ooObj)(id)
#endif // !defined(OO_BUGGY_TEMPLATES)
{
}
inline
ooHandle(ooCollection)::ooHandleStructor(ooCollection)(const ooCollection *  fromObject) :
#ifdef OO_BUGGY_TEMPLATES
    ooHandle_superclass<ooCollection >(ooReinterpretCast(const ooObj *,fromObject))
#else // !defined(OO_BUGGY_TEMPLATES)
    ooHandle(ooObj)(ooReinterpretCast(const ooObj *,fromObject))
#endif // !defined(OO_BUGGY_TEMPLATES)
{
}
inline
ooHandle(ooCollection)&
ooHandle(ooCollection)::operator=(const ooRef(ooCollection) &  id)
{
  this->ooHandle(ooObj)::operator=(id);
  return *this;
}
inline
ooHandle(ooCollection)&
ooHandle(ooCollection)::operator=(const ooHandle(ooCollection) &  objH)
{
  this->ooHandle(ooObj)::operator=(objH);
  return *this;
}
inline
ooHandle(ooCollection)&
ooHandle(ooCollection)::operator=(const ooShortRef(ooCollection) &  shortId)
{
  this->ooHandle(ooObj)::operator=(shortId);
  return *this;
}
inline
ooHandle(ooCollection)&
ooHandle(ooCollection)::operator=(const ooCollection *  fromObject)
{
  this->ooHandle(ooObj)::operator=(ooReinterpretCast(const ooObj *,fromObject));
  return *this;
}
inline
ooCollection *
ooHandle(ooCollection)::pin(ooMode  openMode) const
{
  return ooReinterpretCast(ooCollection *, this->pin_obj_internal(openMode));
}
inline
ooCollection *
ooHandle(ooCollection)::operator->() const
{
  return this->vm();
}
inline
ooCollection &
ooHandle(ooCollection)::operator*() const
{
  return *(this->vm());
}
inline
ooHandle(ooCollection)::operator ooCollection *() const
{
  if ( _state == oocHandlePTR  )
    return ooReinterpretCast(ooCollection *, _ptr._obj);
  else return ooReinterpretCast(ooCollection *, this->get_vm());
}
inline
ooCollection *
ooHandle(ooCollection)::vm() const
{
  if ( _state == oocHandlePTR && _ptr._obj != NULL )
    return ooReinterpretCast(ooCollection *, _ptr._obj);
  else return ooReinterpretCast(ooCollection *, this->get_vm());
}
inline
ooRef(ooCollection) &
ooHandle(ooCollection)::copy(const ooHandle(ooObj) &  nearH,
		   ooRef(ooCollection) &              result) const
{
  this->ooHandle(ooObj)::copy(nearH, result);
  return result;
}


/* ODMG methods */
inline
ooCollection *
ooRef(ooCollection)::ptr() const
{
  return this->pin();
}
inline
ooCollection *
ooHandle(ooCollection)::ptr() const
{
  return this->operator ooCollection *();
}
class ooCompareShortRef;


/////////////////////////////////////////////////////////////////////////////

ooTemplateSpecialization
class ooDeref(ooCompareShortRef) : public ooDerefBase {
	friend class ooRef(ooCompareShortRef);
  public:
    ~ooDerefStructor(ooCompareShortRef)();
    inline ooCompareShortRef *operator->() const;
#ifndef OO_BUGGY_TEMPLATES
  private:
#endif // !defined(OO_BUGGY_TEMPLATES)
    ooDerefStructor(ooCompareShortRef)(ooDeref(ooCompareShortRef)& deref);
    ooDerefStructor(ooCompareShortRef)(ooObj *  fromObject);
};


#ifdef OO_BUGGY_TEMPLATES

class ooHandle_superclass<ooCompareShortRef > : public ooHandle(ooCompare) {
 protected:
  ooHandle_superclass()
    {}
  ooHandle_superclass(const ooHandle(ooCompare) &  from) :
      ooHandle(ooCompare)(from)
    {}
  ooHandle_superclass(const ooRef(ooCompare) &  from) :
      ooHandle(ooCompare)(from)
    {}
  ooHandle_superclass(const ooCompare *  from) :
      ooHandle(ooCompare)(from)
    {}
  ~ooHandle_superclass()
    {}
};

class ooShortRef_superclass<ooCompareShortRef > : public ooShortRef(ooCompare) {
};

#endif // OO_BUGGY_TEMPLATES

ooTemplateSpecialization
class ooRef(ooCompareShortRef) : public ooRef(ooCompare) {
  public:
    ooRefStructor(ooCompareShortRef)()
      {}
    ooRefStructor(ooCompareShortRef)(const ooRef(ooCompareShortRef)& id) :
	  ooRef(ooCompare)(id)
      {}
    inline ooRefStructor(ooCompareShortRef)(const ooHandleSuper(ooCompareShortRef)& objH);
    inline ooRefStructor(ooCompareShortRef)(const ooCompareShortRef *  fromObject);
    inline ooRef(ooCompareShortRef)& operator=(const ooRef(ooCompareShortRef)& id);
    inline ooRef(ooCompareShortRef)& operator=(const ooShortRefSuper(ooCompareShortRef) &shortId);
    inline ooRef(ooCompareShortRef)& operator=(const ooHandleSuper(ooCompareShortRef)& objH);
    inline ooRef(ooCompareShortRef)& operator=(const ooCompareShortRef *  fromObject);
    ooStatus lookupObj(const ooHandle(ooObj)& scopeH,
		       const ooKey& key,
		       ooMode openMode = oocRead);
    ooStatus lookupObj(const ooHandle(ooObj)& scopeH,
		       const char* name,
		       ooMode openMode = oocRead);
#ifndef OO_BUGGY_TEMPLATES
    inline ooRef(ooCompareShortRef)& copy(const ooHandle(ooObj)& nearH,
		    ooRef(ooCompareShortRef)& newObjRef) const;
    inline ooHandle(ooCompareShortRef)& copy(const ooHandle(ooObj)& nearH,
			ooHandle(ooCompareShortRef)& result) const;
    inline ooHandle(ooCompareShortRef) copy(const ooHandle(ooObj)& nearH) const;
#endif // !defined(OO_BUGGY_TEMPLATES)
    inline ooCompareShortRef *pin(ooMode openMode = oocRead) const;
    ooDeref(ooCompareShortRef) operator->() const;
    /* Use pin() or use ooHandle "operator ooCompareShortRef *" instead of vm. */
    /* OBSOLETE */ inline ooCompareShortRef *vm(ooMode openMode = oocRead) const;
    // ODMG methods:
    ooRefStructor(ooCompareShortRef)(const d_Ref_Any &from);
    ooCompareShortRef *ptr() const;
};

ooTemplateSpecialization
class ooShortRef(ooCompareShortRef) :
#ifdef OO_BUGGY_TEMPLATES
			public ooShortRef_superclass<ooCompareShortRef >
#else // !defined(OO_BUGGY_TEMPLATES)
			public ooShortRef(ooCompare)
#endif // !defined(OO_BUGGY_TEMPLATES)
					            {
  public:
    ooShortRefStructor(ooCompareShortRef)();
    ooShortRefStructor(ooCompareShortRef)(const ooShortRef(ooCompareShortRef)& shortId);
    ooShortRefStructor(ooCompareShortRef)(const ooRef(ooCompareShortRef)& id);
    ooShortRefStructor(ooCompareShortRef)(const ooHandleSuper(ooCompareShortRef) &objH);
    ooShortRefStructor(ooCompareShortRef)(const ooCompareShortRef *  fromObject);
    ooShortRef(ooCompareShortRef)& operator=(const ooShortRef(ooCompareShortRef)& shortId);
    ooShortRef(ooCompareShortRef)& operator=(const ooRef(ooCompareShortRef)& id);
    ooShortRef(ooCompareShortRef)& operator=(const ooHandleSuper(ooCompareShortRef) &objH);
    ooShortRef(ooCompareShortRef)& operator=(const ooCompareShortRef *  fromObject);
};

ooTemplateSpecialization
class ooHandle(ooCompareShortRef) :
#ifdef OO_BUGGY_TEMPLATES
		      public ooHandle_superclass<ooCompareShortRef >
#else // !defined(OO_BUGGY_TEMPLATES)
		      public ooHandle(ooCompare)
#endif // !defined(OO_BUGGY_TEMPLATES)
                                                {
  public:
    inline ooHandleStructor(ooCompareShortRef)();
    inline ooHandleStructor(ooCompareShortRef)(const ooRef(ooCompareShortRef)& id);
    inline ooHandleStructor(ooCompareShortRef)(const ooHandle(ooCompareShortRef)& objH);
    inline ooHandleStructor(ooCompareShortRef)(const ooCompareShortRef *  fromObject);
    inline ooHandle(ooCompareShortRef)& operator=(const ooRef(ooCompareShortRef)& id);
    inline ooHandle(ooCompareShortRef)& operator=(const ooHandle(ooCompareShortRef)& objH);
    inline ooHandle(ooCompareShortRef)& operator=(const ooShortRef(ooCompareShortRef)& shortId);
    inline ooHandle(ooCompareShortRef)& operator=(const ooCompareShortRef *  fromObject);
    ooStatus lookupObj(const ooHandle(ooObj)& scopeH,
		       const ooKey& key,
		       ooMode openMode = oocRead);
    ooStatus lookupObj(const ooHandle(ooObj)& scopeH,
		       const char* name,
		       ooMode openMode = oocRead);
    ooHandle(ooCompareShortRef)& copy(const ooHandle(ooObj)& nearH,
		       ooHandle(ooCompareShortRef)& result) const;
    inline ooRef(ooCompareShortRef)& copy(const ooHandle(ooObj)& nearH,
		    ooRef(ooCompareShortRef)& result) const;
    ooHandle(ooCompareShortRef) copy(const ooHandle(ooObj)& nearH) const;
    inline ooCompareShortRef *pin(ooMode openMode = oocRead) const;
    inline ooCompareShortRef *operator->() const;
    inline ooCompareShortRef &operator*() const;
    inline operator ooCompareShortRef *() const;
    /* Use "operator ooCompareShortRef *" instead of vm. */
    /* OBSOLETE */ inline ooCompareShortRef *vm() const;
    // ODMG methods:
    ooHandleStructor(ooCompareShortRef)(const d_Ref_Any &from);
    ooCompareShortRef *ptr() const;
};

ooTemplateSpecialization
class ooItr(ooCompareShortRef) : public ooHandle(ooCompareShortRef),
		    public ooIteratorObjOrContObj {
  public:
    ooItrStructor(ooCompareShortRef)();
    ~ooItrStructor(ooCompareShortRef)();
  private:
    // Defined only to prevent implicit definition:
    ooItrStructor(ooCompareShortRef)(ooItr(ooCompareShortRef)&);
    ooItr(ooCompareShortRef)    operator=(ooItr(ooCompareShortRef)&);
};


/* methods on ooDeref(ooCompareShortRef) */
inline
ooDeref(ooCompareShortRef)::ooDerefStructor(ooCompareShortRef)(ooDeref(ooCompareShortRef) &  deref) :
    ooDerefBase(deref.vm())
{
  this->pinCompensate();
}
inline
ooDeref(ooCompareShortRef)::ooDerefStructor(ooCompareShortRef)(ooObj *  fromObject) :
    ooDerefBase(fromObject)
{
}
inline
ooDeref(ooCompareShortRef)::~ooDerefStructor(ooCompareShortRef)()
{
}
inline
ooCompareShortRef *
ooDeref(ooCompareShortRef)::operator->() const
{
  return ooReinterpretCast(ooCompareShortRef *, this->vm());
}


/* methods on ooRef(ooCompareShortRef) */
inline
ooRef(ooCompareShortRef)::ooRefStructor(ooCompareShortRef)(const ooHandleSuper(ooCompareShortRef)& objH) :
    ooRef(ooCompare)(objH)
{
}
inline
ooRef(ooCompareShortRef)::ooRefStructor(ooCompareShortRef)(const ooCompareShortRef *  fromObject) :
    ooRef(ooCompare)(ooReinterpretCast(const ooCompare *, fromObject))
{
}
inline
ooRef(ooCompareShortRef)&
ooRef(ooCompareShortRef)::operator=(const ooRef(ooCompareShortRef) &  id)
{
  this->ooId::operator=(id);
  return *this;
}
inline
ooRef(ooCompareShortRef)&
ooRef(ooCompareShortRef)::operator=(const ooShortRefSuper(ooCompareShortRef) &  shortId)
{
  this->ooRef(ooObj)::operator=(shortId);
  return *this;
}
inline
ooRef(ooCompareShortRef)&
ooRef(ooCompareShortRef)::operator=(const ooHandleSuper(ooCompareShortRef) &  objH)
{
  this->ooRef(ooObj)::operator=(objH);
  return *this;
}
inline
ooRef(ooCompareShortRef)&
ooRef(ooCompareShortRef)::operator=(const ooCompareShortRef *  fromObject)
{
  this->ooRef(ooObj)::operator=(ooReinterpretCast(const ooObj *, fromObject));
  return *this;
}
inline
ooCompareShortRef *
ooRef(ooCompareShortRef)::pin(ooMode  openMode) const
{
  return ooReinterpretCast(ooCompareShortRef *, this->pin_ref_internal(openMode));
}
inline
ooCompareShortRef *
ooRef(ooCompareShortRef)::vm(ooMode  openMode) const
{
  return this->pin(openMode);
}
#ifndef OO_BUGGY_TEMPLATES
inline
ooHandle(ooCompareShortRef) &
ooRef(ooCompareShortRef)::copy(const ooHandle(ooObj) &  nearH,
		ooHandle(ooCompareShortRef) &           result) const
{
  this->ooRef(ooObj)::copy(nearH, result);
  return result;
}
inline
ooRef(ooCompareShortRef) &
ooRef(ooCompareShortRef)::copy(const ooHandle(ooObj) &  nearH,
		ooRef(ooCompareShortRef) &              newObjRef) const
{
  this->ooRef(ooObj)::copy(nearH, newObjRef);
  return newObjRef;
}
inline
ooHandle(ooCompareShortRef)
ooRef(ooCompareShortRef)::copy(const ooHandle(ooObj) &  nearH) const
{
  ooHandle(ooCompareShortRef) result;
  this->ooRef(ooObj)::copy(nearH, result);
  return result;
}
#endif // !defined(OO_BUGGY_TEMPLATES)
inline
ooDeref(ooCompareShortRef)
ooRef(ooCompareShortRef)::operator->() const
{
  ooDeref(ooCompareShortRef) result(this->pin_ref_internal(oocRead));
  return result;
}


/* methods on ooShortRef(ooCompareShortRef) */
inline
ooShortRef(ooCompareShortRef) &
ooShortRef(ooCompareShortRef)::operator=(const ooShortRef(ooCompareShortRef) &  shortId)
{
  this->ooShortId::operator=(shortId);
  return *this;
}
inline
ooShortRef(ooCompareShortRef) &
ooShortRef(ooCompareShortRef)::operator=(const ooRef(ooCompareShortRef) &  id)
{
  this->ooShortId::operator=(id);
  return *this;
}
inline
ooShortRef(ooCompareShortRef) &
ooShortRef(ooCompareShortRef)::operator=(const ooHandleSuper(ooCompareShortRef) &  objH)
{
  this->ooShortId::operator=(objH);
  return *this;
}
inline
ooShortRef(ooCompareShortRef)&
ooShortRef(ooCompareShortRef)::operator=(const ooCompareShortRef *  fromObject)
{
  this->ooShortId::operator=(ooReinterpretCast(const ooObj *,fromObject));
  return *this;
}
inline
ooShortRef(ooCompareShortRef)::ooShortRefStructor(ooCompareShortRef)()
{
}
#ifdef OO_BUGGY_TEMPLATES
inline
ooShortRef(ooCompareShortRef)::ooShortRefStructor(ooCompareShortRef)(const ooShortRef(ooCompareShortRef) &  shortId)
{
  *this = shortId;
}
#else // !defined(OO_BUGGY_TEMPLATES)
inline
ooShortRef(ooCompareShortRef)::ooShortRefStructor(ooCompareShortRef)(const ooShortRef(ooCompareShortRef) &  shortId) :
    ooShortRef(ooCompare)(shortId)
{
}
#endif // !defined(OO_BUGGY_TEMPLATES)
#ifdef OO_BUGGY_TEMPLATES
inline
ooShortRef(ooCompareShortRef)::ooShortRefStructor(ooCompareShortRef)(const ooRef(ooCompareShortRef) &  id)
{
  *this = id;
}
#else // !defined(OO_BUGGY_TEMPLATES)
inline
ooShortRef(ooCompareShortRef)::ooShortRefStructor(ooCompareShortRef)(const ooRef(ooCompareShortRef) &  id) :
    ooShortRef(ooCompare)(id)
{
}
#endif // !defined(OO_BUGGY_TEMPLATES)
#ifdef OO_BUGGY_TEMPLATES
inline
ooShortRef(ooCompareShortRef)::ooShortRefStructor(ooCompareShortRef)(const ooHandleSuper(ooCompareShortRef) &  objH)
{
  *this = objH;
}
#else // !defined(OO_BUGGY_TEMPLATES)
inline
ooShortRef(ooCompareShortRef)::ooShortRefStructor(ooCompareShortRef)(const ooHandleSuper(ooCompareShortRef) &  objH) :
    ooShortRef(ooCompare)(objH)
{
}
#endif // !defined(OO_BUGGY_TEMPLATES)
#ifdef OO_BUGGY_TEMPLATES
inline
ooShortRef(ooCompareShortRef)::ooShortRefStructor(ooCompareShortRef)(const ooCompareShortRef *  fromObject)
{
  *this = fromObject;
}
#else // !defined(OO_BUGGY_TEMPLATES)
inline
ooShortRef(ooCompareShortRef)::ooShortRefStructor(ooCompareShortRef)(const ooCompareShortRef *  fromObject) :
    ooShortRef(ooCompare)(ooReinterpretCast(const ooCompare *,fromObject))
{
}
#endif // !defined(OO_BUGGY_TEMPLATES)


/* methods on ooHandle(ooCompareShortRef) */
inline
ooHandle(ooCompareShortRef)::ooHandleStructor(ooCompareShortRef)()
{
}
inline
ooHandle(ooCompareShortRef)::ooHandleStructor(ooCompareShortRef)(const ooHandle(ooCompareShortRef) &  objH) :
#ifdef OO_BUGGY_TEMPLATES
    ooHandle_superclass<ooCompareShortRef >(objH)
#else // !defined(OO_BUGGY_TEMPLATES)
    ooHandle(ooCompare)(objH)
#endif // !defined(OO_BUGGY_TEMPLATES)
{
}
inline
ooHandle(ooCompareShortRef)::ooHandleStructor(ooCompareShortRef)(const ooRef(ooCompareShortRef) &  id) :
#ifdef OO_BUGGY_TEMPLATES
    ooHandle_superclass<ooCompareShortRef >(id)
#else // !defined(OO_BUGGY_TEMPLATES)
    ooHandle(ooCompare)(id)
#endif // !defined(OO_BUGGY_TEMPLATES)
{
}
inline
ooHandle(ooCompareShortRef)::ooHandleStructor(ooCompareShortRef)(const ooCompareShortRef *  fromObject) :
#ifdef OO_BUGGY_TEMPLATES
    ooHandle_superclass<ooCompareShortRef >(ooReinterpretCast(const ooCompare *,fromObject))
#else // !defined(OO_BUGGY_TEMPLATES)
    ooHandle(ooCompare)(ooReinterpretCast(const ooCompare *,fromObject))
#endif // !defined(OO_BUGGY_TEMPLATES)
{
}
inline
ooHandle(ooCompareShortRef)&
ooHandle(ooCompareShortRef)::operator=(const ooRef(ooCompareShortRef) &  id)
{
  this->ooHandle(ooObj)::operator=(id);
  return *this;
}
inline
ooHandle(ooCompareShortRef)&
ooHandle(ooCompareShortRef)::operator=(const ooHandle(ooCompareShortRef) &  objH)
{
  this->ooHandle(ooObj)::operator=(objH);
  return *this;
}
inline
ooHandle(ooCompareShortRef)&
ooHandle(ooCompareShortRef)::operator=(const ooShortRef(ooCompareShortRef) &  shortId)
{
  this->ooHandle(ooObj)::operator=(shortId);
  return *this;
}
inline
ooHandle(ooCompareShortRef)&
ooHandle(ooCompareShortRef)::operator=(const ooCompareShortRef *  fromObject)
{
  this->ooHandle(ooObj)::operator=(ooReinterpretCast(const ooObj *,fromObject));
  return *this;
}
inline
ooCompareShortRef *
ooHandle(ooCompareShortRef)::pin(ooMode  openMode) const
{
  return ooReinterpretCast(ooCompareShortRef *, this->pin_obj_internal(openMode));
}
inline
ooCompareShortRef *
ooHandle(ooCompareShortRef)::operator->() const
{
  return this->vm();
}
inline
ooCompareShortRef &
ooHandle(ooCompareShortRef)::operator*() const
{
  return *(this->vm());
}
inline
ooHandle(ooCompareShortRef)::operator ooCompareShortRef *() const
{
  if ( _state == oocHandlePTR  )
    return ooReinterpretCast(ooCompareShortRef *, _ptr._obj);
  else return ooReinterpretCast(ooCompareShortRef *, this->get_vm());
}
inline
ooCompareShortRef *
ooHandle(ooCompareShortRef)::vm() const
{
  if ( _state == oocHandlePTR && _ptr._obj != NULL )
    return ooReinterpretCast(ooCompareShortRef *, _ptr._obj);
  else return ooReinterpretCast(ooCompareShortRef *, this->get_vm());
}
inline
ooRef(ooCompareShortRef) &
ooHandle(ooCompareShortRef)::copy(const ooHandle(ooObj) &  nearH,
		   ooRef(ooCompareShortRef) &              result) const
{
  this->ooHandle(ooObj)::copy(nearH, result);
  return result;
}


/* ODMG methods */
inline
ooCompareShortRef *
ooRef(ooCompareShortRef)::ptr() const
{
  return this->pin();
}
inline
ooCompareShortRef *
ooHandle(ooCompareShortRef)::ptr() const
{
  return this->operator ooCompareShortRef *();
}
class ooHashEntryPage;


/////////////////////////////////////////////////////////////////////////////

ooTemplateSpecialization
class ooDeref(ooHashEntryPage) : public ooDerefBase {
	friend class ooRef(ooHashEntryPage);
  public:
    ~ooDerefStructor(ooHashEntryPage)();
    inline ooHashEntryPage *operator->() const;
#ifndef OO_BUGGY_TEMPLATES
  private:
#endif // !defined(OO_BUGGY_TEMPLATES)
    ooDerefStructor(ooHashEntryPage)(ooDeref(ooHashEntryPage)& deref);
    ooDerefStructor(ooHashEntryPage)(ooObj *  fromObject);
};


#ifdef OO_BUGGY_TEMPLATES

class ooHandle_superclass<ooHashEntryPage > : public ooHandle(ooObj) {
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

class ooShortRef_superclass<ooHashEntryPage > : public ooShortRef(ooObj) {
};

#endif // OO_BUGGY_TEMPLATES

ooTemplateSpecialization
class ooRef(ooHashEntryPage) : public ooRef(ooObj) {
  public:
    ooRefStructor(ooHashEntryPage)()
      {}
    ooRefStructor(ooHashEntryPage)(const ooRef(ooHashEntryPage)& id) :
	  ooRef(ooObj)(id)
      {}
    inline ooRefStructor(ooHashEntryPage)(const ooHandleSuper(ooHashEntryPage)& objH);
    inline ooRefStructor(ooHashEntryPage)(const ooHashEntryPage *  fromObject);
    inline ooRef(ooHashEntryPage)& operator=(const ooRef(ooHashEntryPage)& id);
    inline ooRef(ooHashEntryPage)& operator=(const ooShortRefSuper(ooHashEntryPage) &shortId);
    inline ooRef(ooHashEntryPage)& operator=(const ooHandleSuper(ooHashEntryPage)& objH);
    inline ooRef(ooHashEntryPage)& operator=(const ooHashEntryPage *  fromObject);
    ooStatus lookupObj(const ooHandle(ooObj)& scopeH,
		       const ooKey& key,
		       ooMode openMode = oocRead);
    ooStatus lookupObj(const ooHandle(ooObj)& scopeH,
		       const char* name,
		       ooMode openMode = oocRead);
#ifndef OO_BUGGY_TEMPLATES
    inline ooRef(ooHashEntryPage)& copy(const ooHandle(ooObj)& nearH,
		    ooRef(ooHashEntryPage)& newObjRef) const;
    inline ooHandle(ooHashEntryPage)& copy(const ooHandle(ooObj)& nearH,
			ooHandle(ooHashEntryPage)& result) const;
    inline ooHandle(ooHashEntryPage) copy(const ooHandle(ooObj)& nearH) const;
#endif // !defined(OO_BUGGY_TEMPLATES)
    inline ooHashEntryPage *pin(ooMode openMode = oocRead) const;
    ooDeref(ooHashEntryPage) operator->() const;
    /* Use pin() or use ooHandle "operator ooHashEntryPage *" instead of vm. */
    /* OBSOLETE */ inline ooHashEntryPage *vm(ooMode openMode = oocRead) const;
    // ODMG methods:
    ooRefStructor(ooHashEntryPage)(const d_Ref_Any &from);
    ooHashEntryPage *ptr() const;
};

ooTemplateSpecialization
class ooShortRef(ooHashEntryPage) :
#ifdef OO_BUGGY_TEMPLATES
			public ooShortRef_superclass<ooHashEntryPage >
#else // !defined(OO_BUGGY_TEMPLATES)
			public ooShortRef(ooObj)
#endif // !defined(OO_BUGGY_TEMPLATES)
					            {
  public:
    ooShortRefStructor(ooHashEntryPage)();
    ooShortRefStructor(ooHashEntryPage)(const ooShortRef(ooHashEntryPage)& shortId);
    ooShortRefStructor(ooHashEntryPage)(const ooRef(ooHashEntryPage)& id);
    ooShortRefStructor(ooHashEntryPage)(const ooHandleSuper(ooHashEntryPage) &objH);
    ooShortRefStructor(ooHashEntryPage)(const ooHashEntryPage *  fromObject);
    ooShortRef(ooHashEntryPage)& operator=(const ooShortRef(ooHashEntryPage)& shortId);
    ooShortRef(ooHashEntryPage)& operator=(const ooRef(ooHashEntryPage)& id);
    ooShortRef(ooHashEntryPage)& operator=(const ooHandleSuper(ooHashEntryPage) &objH);
    ooShortRef(ooHashEntryPage)& operator=(const ooHashEntryPage *  fromObject);
};

ooTemplateSpecialization
class ooHandle(ooHashEntryPage) :
#ifdef OO_BUGGY_TEMPLATES
		      public ooHandle_superclass<ooHashEntryPage >
#else // !defined(OO_BUGGY_TEMPLATES)
		      public ooHandle(ooObj)
#endif // !defined(OO_BUGGY_TEMPLATES)
                                                {
  public:
    inline ooHandleStructor(ooHashEntryPage)();
    inline ooHandleStructor(ooHashEntryPage)(const ooRef(ooHashEntryPage)& id);
    inline ooHandleStructor(ooHashEntryPage)(const ooHandle(ooHashEntryPage)& objH);
    inline ooHandleStructor(ooHashEntryPage)(const ooHashEntryPage *  fromObject);
    inline ooHandle(ooHashEntryPage)& operator=(const ooRef(ooHashEntryPage)& id);
    inline ooHandle(ooHashEntryPage)& operator=(const ooHandle(ooHashEntryPage)& objH);
    inline ooHandle(ooHashEntryPage)& operator=(const ooShortRef(ooHashEntryPage)& shortId);
    inline ooHandle(ooHashEntryPage)& operator=(const ooHashEntryPage *  fromObject);
    ooStatus lookupObj(const ooHandle(ooObj)& scopeH,
		       const ooKey& key,
		       ooMode openMode = oocRead);
    ooStatus lookupObj(const ooHandle(ooObj)& scopeH,
		       const char* name,
		       ooMode openMode = oocRead);
    ooHandle(ooHashEntryPage)& copy(const ooHandle(ooObj)& nearH,
		       ooHandle(ooHashEntryPage)& result) const;
    inline ooRef(ooHashEntryPage)& copy(const ooHandle(ooObj)& nearH,
		    ooRef(ooHashEntryPage)& result) const;
    ooHandle(ooHashEntryPage) copy(const ooHandle(ooObj)& nearH) const;
    inline ooHashEntryPage *pin(ooMode openMode = oocRead) const;
    inline ooHashEntryPage *operator->() const;
    inline ooHashEntryPage &operator*() const;
    inline operator ooHashEntryPage *() const;
    /* Use "operator ooHashEntryPage *" instead of vm. */
    /* OBSOLETE */ inline ooHashEntryPage *vm() const;
    // ODMG methods:
    ooHandleStructor(ooHashEntryPage)(const d_Ref_Any &from);
    ooHashEntryPage *ptr() const;
};

ooTemplateSpecialization
class ooItr(ooHashEntryPage) : public ooHandle(ooHashEntryPage),
		    public ooIteratorObjOrContObj {
  public:
    ooItrStructor(ooHashEntryPage)();
    ~ooItrStructor(ooHashEntryPage)();
  private:
    // Defined only to prevent implicit definition:
    ooItrStructor(ooHashEntryPage)(ooItr(ooHashEntryPage)&);
    ooItr(ooHashEntryPage)    operator=(ooItr(ooHashEntryPage)&);
};


/* methods on ooDeref(ooHashEntryPage) */
inline
ooDeref(ooHashEntryPage)::ooDerefStructor(ooHashEntryPage)(ooDeref(ooHashEntryPage) &  deref) :
    ooDerefBase(deref.vm())
{
  this->pinCompensate();
}
inline
ooDeref(ooHashEntryPage)::ooDerefStructor(ooHashEntryPage)(ooObj *  fromObject) :
    ooDerefBase(fromObject)
{
}
inline
ooDeref(ooHashEntryPage)::~ooDerefStructor(ooHashEntryPage)()
{
}
inline
ooHashEntryPage *
ooDeref(ooHashEntryPage)::operator->() const
{
  return ooReinterpretCast(ooHashEntryPage *, this->vm());
}


/* methods on ooRef(ooHashEntryPage) */
inline
ooRef(ooHashEntryPage)::ooRefStructor(ooHashEntryPage)(const ooHandleSuper(ooHashEntryPage)& objH) :
    ooRef(ooObj)(objH)
{
}
inline
ooRef(ooHashEntryPage)::ooRefStructor(ooHashEntryPage)(const ooHashEntryPage *  fromObject) :
    ooRef(ooObj)(ooReinterpretCast(const ooObj *, fromObject))
{
}
inline
ooRef(ooHashEntryPage)&
ooRef(ooHashEntryPage)::operator=(const ooRef(ooHashEntryPage) &  id)
{
  this->ooId::operator=(id);
  return *this;
}
inline
ooRef(ooHashEntryPage)&
ooRef(ooHashEntryPage)::operator=(const ooShortRefSuper(ooHashEntryPage) &  shortId)
{
  this->ooRef(ooObj)::operator=(shortId);
  return *this;
}
inline
ooRef(ooHashEntryPage)&
ooRef(ooHashEntryPage)::operator=(const ooHandleSuper(ooHashEntryPage) &  objH)
{
  this->ooRef(ooObj)::operator=(objH);
  return *this;
}
inline
ooRef(ooHashEntryPage)&
ooRef(ooHashEntryPage)::operator=(const ooHashEntryPage *  fromObject)
{
  this->ooRef(ooObj)::operator=(ooReinterpretCast(const ooObj *, fromObject));
  return *this;
}
inline
ooHashEntryPage *
ooRef(ooHashEntryPage)::pin(ooMode  openMode) const
{
  return ooReinterpretCast(ooHashEntryPage *, this->pin_ref_internal(openMode));
}
inline
ooHashEntryPage *
ooRef(ooHashEntryPage)::vm(ooMode  openMode) const
{
  return this->pin(openMode);
}
#ifndef OO_BUGGY_TEMPLATES
inline
ooHandle(ooHashEntryPage) &
ooRef(ooHashEntryPage)::copy(const ooHandle(ooObj) &  nearH,
		ooHandle(ooHashEntryPage) &           result) const
{
  this->ooRef(ooObj)::copy(nearH, result);
  return result;
}
inline
ooRef(ooHashEntryPage) &
ooRef(ooHashEntryPage)::copy(const ooHandle(ooObj) &  nearH,
		ooRef(ooHashEntryPage) &              newObjRef) const
{
  this->ooRef(ooObj)::copy(nearH, newObjRef);
  return newObjRef;
}
inline
ooHandle(ooHashEntryPage)
ooRef(ooHashEntryPage)::copy(const ooHandle(ooObj) &  nearH) const
{
  ooHandle(ooHashEntryPage) result;
  this->ooRef(ooObj)::copy(nearH, result);
  return result;
}
#endif // !defined(OO_BUGGY_TEMPLATES)
inline
ooDeref(ooHashEntryPage)
ooRef(ooHashEntryPage)::operator->() const
{
  ooDeref(ooHashEntryPage) result(this->pin_ref_internal(oocRead));
  return result;
}


/* methods on ooShortRef(ooHashEntryPage) */
inline
ooShortRef(ooHashEntryPage) &
ooShortRef(ooHashEntryPage)::operator=(const ooShortRef(ooHashEntryPage) &  shortId)
{
  this->ooShortId::operator=(shortId);
  return *this;
}
inline
ooShortRef(ooHashEntryPage) &
ooShortRef(ooHashEntryPage)::operator=(const ooRef(ooHashEntryPage) &  id)
{
  this->ooShortId::operator=(id);
  return *this;
}
inline
ooShortRef(ooHashEntryPage) &
ooShortRef(ooHashEntryPage)::operator=(const ooHandleSuper(ooHashEntryPage) &  objH)
{
  this->ooShortId::operator=(objH);
  return *this;
}
inline
ooShortRef(ooHashEntryPage)&
ooShortRef(ooHashEntryPage)::operator=(const ooHashEntryPage *  fromObject)
{
  this->ooShortId::operator=(ooReinterpretCast(const ooObj *,fromObject));
  return *this;
}
inline
ooShortRef(ooHashEntryPage)::ooShortRefStructor(ooHashEntryPage)()
{
}
#ifdef OO_BUGGY_TEMPLATES
inline
ooShortRef(ooHashEntryPage)::ooShortRefStructor(ooHashEntryPage)(const ooShortRef(ooHashEntryPage) &  shortId)
{
  *this = shortId;
}
#else // !defined(OO_BUGGY_TEMPLATES)
inline
ooShortRef(ooHashEntryPage)::ooShortRefStructor(ooHashEntryPage)(const ooShortRef(ooHashEntryPage) &  shortId) :
    ooShortRef(ooObj)(shortId)
{
}
#endif // !defined(OO_BUGGY_TEMPLATES)
#ifdef OO_BUGGY_TEMPLATES
inline
ooShortRef(ooHashEntryPage)::ooShortRefStructor(ooHashEntryPage)(const ooRef(ooHashEntryPage) &  id)
{
  *this = id;
}
#else // !defined(OO_BUGGY_TEMPLATES)
inline
ooShortRef(ooHashEntryPage)::ooShortRefStructor(ooHashEntryPage)(const ooRef(ooHashEntryPage) &  id) :
    ooShortRef(ooObj)(id)
{
}
#endif // !defined(OO_BUGGY_TEMPLATES)
#ifdef OO_BUGGY_TEMPLATES
inline
ooShortRef(ooHashEntryPage)::ooShortRefStructor(ooHashEntryPage)(const ooHandleSuper(ooHashEntryPage) &  objH)
{
  *this = objH;
}
#else // !defined(OO_BUGGY_TEMPLATES)
inline
ooShortRef(ooHashEntryPage)::ooShortRefStructor(ooHashEntryPage)(const ooHandleSuper(ooHashEntryPage) &  objH) :
    ooShortRef(ooObj)(objH)
{
}
#endif // !defined(OO_BUGGY_TEMPLATES)
#ifdef OO_BUGGY_TEMPLATES
inline
ooShortRef(ooHashEntryPage)::ooShortRefStructor(ooHashEntryPage)(const ooHashEntryPage *  fromObject)
{
  *this = fromObject;
}
#else // !defined(OO_BUGGY_TEMPLATES)
inline
ooShortRef(ooHashEntryPage)::ooShortRefStructor(ooHashEntryPage)(const ooHashEntryPage *  fromObject) :
    ooShortRef(ooObj)(ooReinterpretCast(const ooObj *,fromObject))
{
}
#endif // !defined(OO_BUGGY_TEMPLATES)


/* methods on ooHandle(ooHashEntryPage) */
inline
ooHandle(ooHashEntryPage)::ooHandleStructor(ooHashEntryPage)()
{
}
inline
ooHandle(ooHashEntryPage)::ooHandleStructor(ooHashEntryPage)(const ooHandle(ooHashEntryPage) &  objH) :
#ifdef OO_BUGGY_TEMPLATES
    ooHandle_superclass<ooHashEntryPage >(objH)
#else // !defined(OO_BUGGY_TEMPLATES)
    ooHandle(ooObj)(objH)
#endif // !defined(OO_BUGGY_TEMPLATES)
{
}
inline
ooHandle(ooHashEntryPage)::ooHandleStructor(ooHashEntryPage)(const ooRef(ooHashEntryPage) &  id) :
#ifdef OO_BUGGY_TEMPLATES
    ooHandle_superclass<ooHashEntryPage >(id)
#else // !defined(OO_BUGGY_TEMPLATES)
    ooHandle(ooObj)(id)
#endif // !defined(OO_BUGGY_TEMPLATES)
{
}
inline
ooHandle(ooHashEntryPage)::ooHandleStructor(ooHashEntryPage)(const ooHashEntryPage *  fromObject) :
#ifdef OO_BUGGY_TEMPLATES
    ooHandle_superclass<ooHashEntryPage >(ooReinterpretCast(const ooObj *,fromObject))
#else // !defined(OO_BUGGY_TEMPLATES)
    ooHandle(ooObj)(ooReinterpretCast(const ooObj *,fromObject))
#endif // !defined(OO_BUGGY_TEMPLATES)
{
}
inline
ooHandle(ooHashEntryPage)&
ooHandle(ooHashEntryPage)::operator=(const ooRef(ooHashEntryPage) &  id)
{
  this->ooHandle(ooObj)::operator=(id);
  return *this;
}
inline
ooHandle(ooHashEntryPage)&
ooHandle(ooHashEntryPage)::operator=(const ooHandle(ooHashEntryPage) &  objH)
{
  this->ooHandle(ooObj)::operator=(objH);
  return *this;
}
inline
ooHandle(ooHashEntryPage)&
ooHandle(ooHashEntryPage)::operator=(const ooShortRef(ooHashEntryPage) &  shortId)
{
  this->ooHandle(ooObj)::operator=(shortId);
  return *this;
}
inline
ooHandle(ooHashEntryPage)&
ooHandle(ooHashEntryPage)::operator=(const ooHashEntryPage *  fromObject)
{
  this->ooHandle(ooObj)::operator=(ooReinterpretCast(const ooObj *,fromObject));
  return *this;
}
inline
ooHashEntryPage *
ooHandle(ooHashEntryPage)::pin(ooMode  openMode) const
{
  return ooReinterpretCast(ooHashEntryPage *, this->pin_obj_internal(openMode));
}
inline
ooHashEntryPage *
ooHandle(ooHashEntryPage)::operator->() const
{
  return this->vm();
}
inline
ooHashEntryPage &
ooHandle(ooHashEntryPage)::operator*() const
{
  return *(this->vm());
}
inline
ooHandle(ooHashEntryPage)::operator ooHashEntryPage *() const
{
  if ( _state == oocHandlePTR  )
    return ooReinterpretCast(ooHashEntryPage *, _ptr._obj);
  else return ooReinterpretCast(ooHashEntryPage *, this->get_vm());
}
inline
ooHashEntryPage *
ooHandle(ooHashEntryPage)::vm() const
{
  if ( _state == oocHandlePTR && _ptr._obj != NULL )
    return ooReinterpretCast(ooHashEntryPage *, _ptr._obj);
  else return ooReinterpretCast(ooHashEntryPage *, this->get_vm());
}
inline
ooRef(ooHashEntryPage) &
ooHandle(ooHashEntryPage)::copy(const ooHandle(ooObj) &  nearH,
		   ooRef(ooHashEntryPage) &              result) const
{
  this->ooHandle(ooObj)::copy(nearH, result);
  return result;
}


/* ODMG methods */
inline
ooHashEntryPage *
ooRef(ooHashEntryPage)::ptr() const
{
  return this->pin();
}
inline
ooHashEntryPage *
ooHandle(ooHashEntryPage)::ptr() const
{
  return this->operator ooHashEntryPage *();
}
class ooHashBucketX;


/////////////////////////////////////////////////////////////////////////////

ooTemplateSpecialization
class ooDeref(ooHashBucketX) : public ooDerefBase {
	friend class ooRef(ooHashBucketX);
  public:
    ~ooDerefStructor(ooHashBucketX)();
    inline ooHashBucketX *operator->() const;
#ifndef OO_BUGGY_TEMPLATES
  private:
#endif // !defined(OO_BUGGY_TEMPLATES)
    ooDerefStructor(ooHashBucketX)(ooDeref(ooHashBucketX)& deref);
    ooDerefStructor(ooHashBucketX)(ooObj *  fromObject);
};


#ifdef OO_BUGGY_TEMPLATES

class ooHandle_superclass<ooHashBucketX > : public ooHandle(ooObj) {
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

class ooShortRef_superclass<ooHashBucketX > : public ooShortRef(ooObj) {
};

#endif // OO_BUGGY_TEMPLATES

ooTemplateSpecialization
class ooRef(ooHashBucketX) : public ooRef(ooObj) {
  public:
    ooRefStructor(ooHashBucketX)()
      {}
    ooRefStructor(ooHashBucketX)(const ooRef(ooHashBucketX)& id) :
	  ooRef(ooObj)(id)
      {}
    inline ooRefStructor(ooHashBucketX)(const ooHandleSuper(ooHashBucketX)& objH);
    inline ooRefStructor(ooHashBucketX)(const ooHashBucketX *  fromObject);
    inline ooRef(ooHashBucketX)& operator=(const ooRef(ooHashBucketX)& id);
    inline ooRef(ooHashBucketX)& operator=(const ooShortRefSuper(ooHashBucketX) &shortId);
    inline ooRef(ooHashBucketX)& operator=(const ooHandleSuper(ooHashBucketX)& objH);
    inline ooRef(ooHashBucketX)& operator=(const ooHashBucketX *  fromObject);
    ooStatus lookupObj(const ooHandle(ooObj)& scopeH,
		       const ooKey& key,
		       ooMode openMode = oocRead);
    ooStatus lookupObj(const ooHandle(ooObj)& scopeH,
		       const char* name,
		       ooMode openMode = oocRead);
#ifndef OO_BUGGY_TEMPLATES
    inline ooRef(ooHashBucketX)& copy(const ooHandle(ooObj)& nearH,
		    ooRef(ooHashBucketX)& newObjRef) const;
    inline ooHandle(ooHashBucketX)& copy(const ooHandle(ooObj)& nearH,
			ooHandle(ooHashBucketX)& result) const;
    inline ooHandle(ooHashBucketX) copy(const ooHandle(ooObj)& nearH) const;
#endif // !defined(OO_BUGGY_TEMPLATES)
    inline ooHashBucketX *pin(ooMode openMode = oocRead) const;
    ooDeref(ooHashBucketX) operator->() const;
    /* Use pin() or use ooHandle "operator ooHashBucketX *" instead of vm. */
    /* OBSOLETE */ inline ooHashBucketX *vm(ooMode openMode = oocRead) const;
    // ODMG methods:
    ooRefStructor(ooHashBucketX)(const d_Ref_Any &from);
    ooHashBucketX *ptr() const;
};

ooTemplateSpecialization
class ooShortRef(ooHashBucketX) :
#ifdef OO_BUGGY_TEMPLATES
			public ooShortRef_superclass<ooHashBucketX >
#else // !defined(OO_BUGGY_TEMPLATES)
			public ooShortRef(ooObj)
#endif // !defined(OO_BUGGY_TEMPLATES)
					            {
  public:
    ooShortRefStructor(ooHashBucketX)();
    ooShortRefStructor(ooHashBucketX)(const ooShortRef(ooHashBucketX)& shortId);
    ooShortRefStructor(ooHashBucketX)(const ooRef(ooHashBucketX)& id);
    ooShortRefStructor(ooHashBucketX)(const ooHandleSuper(ooHashBucketX) &objH);
    ooShortRefStructor(ooHashBucketX)(const ooHashBucketX *  fromObject);
    ooShortRef(ooHashBucketX)& operator=(const ooShortRef(ooHashBucketX)& shortId);
    ooShortRef(ooHashBucketX)& operator=(const ooRef(ooHashBucketX)& id);
    ooShortRef(ooHashBucketX)& operator=(const ooHandleSuper(ooHashBucketX) &objH);
    ooShortRef(ooHashBucketX)& operator=(const ooHashBucketX *  fromObject);
};

ooTemplateSpecialization
class ooHandle(ooHashBucketX) :
#ifdef OO_BUGGY_TEMPLATES
		      public ooHandle_superclass<ooHashBucketX >
#else // !defined(OO_BUGGY_TEMPLATES)
		      public ooHandle(ooObj)
#endif // !defined(OO_BUGGY_TEMPLATES)
                                                {
  public:
    inline ooHandleStructor(ooHashBucketX)();
    inline ooHandleStructor(ooHashBucketX)(const ooRef(ooHashBucketX)& id);
    inline ooHandleStructor(ooHashBucketX)(const ooHandle(ooHashBucketX)& objH);
    inline ooHandleStructor(ooHashBucketX)(const ooHashBucketX *  fromObject);
    inline ooHandle(ooHashBucketX)& operator=(const ooRef(ooHashBucketX)& id);
    inline ooHandle(ooHashBucketX)& operator=(const ooHandle(ooHashBucketX)& objH);
    inline ooHandle(ooHashBucketX)& operator=(const ooShortRef(ooHashBucketX)& shortId);
    inline ooHandle(ooHashBucketX)& operator=(const ooHashBucketX *  fromObject);
    ooStatus lookupObj(const ooHandle(ooObj)& scopeH,
		       const ooKey& key,
		       ooMode openMode = oocRead);
    ooStatus lookupObj(const ooHandle(ooObj)& scopeH,
		       const char* name,
		       ooMode openMode = oocRead);
    ooHandle(ooHashBucketX)& copy(const ooHandle(ooObj)& nearH,
		       ooHandle(ooHashBucketX)& result) const;
    inline ooRef(ooHashBucketX)& copy(const ooHandle(ooObj)& nearH,
		    ooRef(ooHashBucketX)& result) const;
    ooHandle(ooHashBucketX) copy(const ooHandle(ooObj)& nearH) const;
    inline ooHashBucketX *pin(ooMode openMode = oocRead) const;
    inline ooHashBucketX *operator->() const;
    inline ooHashBucketX &operator*() const;
    inline operator ooHashBucketX *() const;
    /* Use "operator ooHashBucketX *" instead of vm. */
    /* OBSOLETE */ inline ooHashBucketX *vm() const;
    // ODMG methods:
    ooHandleStructor(ooHashBucketX)(const d_Ref_Any &from);
    ooHashBucketX *ptr() const;
};

ooTemplateSpecialization
class ooItr(ooHashBucketX) : public ooHandle(ooHashBucketX),
		    public ooIteratorObjOrContObj {
  public:
    ooItrStructor(ooHashBucketX)();
    ~ooItrStructor(ooHashBucketX)();
  private:
    // Defined only to prevent implicit definition:
    ooItrStructor(ooHashBucketX)(ooItr(ooHashBucketX)&);
    ooItr(ooHashBucketX)    operator=(ooItr(ooHashBucketX)&);
};


/* methods on ooDeref(ooHashBucketX) */
inline
ooDeref(ooHashBucketX)::ooDerefStructor(ooHashBucketX)(ooDeref(ooHashBucketX) &  deref) :
    ooDerefBase(deref.vm())
{
  this->pinCompensate();
}
inline
ooDeref(ooHashBucketX)::ooDerefStructor(ooHashBucketX)(ooObj *  fromObject) :
    ooDerefBase(fromObject)
{
}
inline
ooDeref(ooHashBucketX)::~ooDerefStructor(ooHashBucketX)()
{
}
inline
ooHashBucketX *
ooDeref(ooHashBucketX)::operator->() const
{
  return ooReinterpretCast(ooHashBucketX *, this->vm());
}


/* methods on ooRef(ooHashBucketX) */
inline
ooRef(ooHashBucketX)::ooRefStructor(ooHashBucketX)(const ooHandleSuper(ooHashBucketX)& objH) :
    ooRef(ooObj)(objH)
{
}
inline
ooRef(ooHashBucketX)::ooRefStructor(ooHashBucketX)(const ooHashBucketX *  fromObject) :
    ooRef(ooObj)(ooReinterpretCast(const ooObj *, fromObject))
{
}
inline
ooRef(ooHashBucketX)&
ooRef(ooHashBucketX)::operator=(const ooRef(ooHashBucketX) &  id)
{
  this->ooId::operator=(id);
  return *this;
}
inline
ooRef(ooHashBucketX)&
ooRef(ooHashBucketX)::operator=(const ooShortRefSuper(ooHashBucketX) &  shortId)
{
  this->ooRef(ooObj)::operator=(shortId);
  return *this;
}
inline
ooRef(ooHashBucketX)&
ooRef(ooHashBucketX)::operator=(const ooHandleSuper(ooHashBucketX) &  objH)
{
  this->ooRef(ooObj)::operator=(objH);
  return *this;
}
inline
ooRef(ooHashBucketX)&
ooRef(ooHashBucketX)::operator=(const ooHashBucketX *  fromObject)
{
  this->ooRef(ooObj)::operator=(ooReinterpretCast(const ooObj *, fromObject));
  return *this;
}
inline
ooHashBucketX *
ooRef(ooHashBucketX)::pin(ooMode  openMode) const
{
  return ooReinterpretCast(ooHashBucketX *, this->pin_ref_internal(openMode));
}
inline
ooHashBucketX *
ooRef(ooHashBucketX)::vm(ooMode  openMode) const
{
  return this->pin(openMode);
}
#ifndef OO_BUGGY_TEMPLATES
inline
ooHandle(ooHashBucketX) &
ooRef(ooHashBucketX)::copy(const ooHandle(ooObj) &  nearH,
		ooHandle(ooHashBucketX) &           result) const
{
  this->ooRef(ooObj)::copy(nearH, result);
  return result;
}
inline
ooRef(ooHashBucketX) &
ooRef(ooHashBucketX)::copy(const ooHandle(ooObj) &  nearH,
		ooRef(ooHashBucketX) &              newObjRef) const
{
  this->ooRef(ooObj)::copy(nearH, newObjRef);
  return newObjRef;
}
inline
ooHandle(ooHashBucketX)
ooRef(ooHashBucketX)::copy(const ooHandle(ooObj) &  nearH) const
{
  ooHandle(ooHashBucketX) result;
  this->ooRef(ooObj)::copy(nearH, result);
  return result;
}
#endif // !defined(OO_BUGGY_TEMPLATES)
inline
ooDeref(ooHashBucketX)
ooRef(ooHashBucketX)::operator->() const
{
  ooDeref(ooHashBucketX) result(this->pin_ref_internal(oocRead));
  return result;
}


/* methods on ooShortRef(ooHashBucketX) */
inline
ooShortRef(ooHashBucketX) &
ooShortRef(ooHashBucketX)::operator=(const ooShortRef(ooHashBucketX) &  shortId)
{
  this->ooShortId::operator=(shortId);
  return *this;
}
inline
ooShortRef(ooHashBucketX) &
ooShortRef(ooHashBucketX)::operator=(const ooRef(ooHashBucketX) &  id)
{
  this->ooShortId::operator=(id);
  return *this;
}
inline
ooShortRef(ooHashBucketX) &
ooShortRef(ooHashBucketX)::operator=(const ooHandleSuper(ooHashBucketX) &  objH)
{
  this->ooShortId::operator=(objH);
  return *this;
}
inline
ooShortRef(ooHashBucketX)&
ooShortRef(ooHashBucketX)::operator=(const ooHashBucketX *  fromObject)
{
  this->ooShortId::operator=(ooReinterpretCast(const ooObj *,fromObject));
  return *this;
}
inline
ooShortRef(ooHashBucketX)::ooShortRefStructor(ooHashBucketX)()
{
}
#ifdef OO_BUGGY_TEMPLATES
inline
ooShortRef(ooHashBucketX)::ooShortRefStructor(ooHashBucketX)(const ooShortRef(ooHashBucketX) &  shortId)
{
  *this = shortId;
}
#else // !defined(OO_BUGGY_TEMPLATES)
inline
ooShortRef(ooHashBucketX)::ooShortRefStructor(ooHashBucketX)(const ooShortRef(ooHashBucketX) &  shortId) :
    ooShortRef(ooObj)(shortId)
{
}
#endif // !defined(OO_BUGGY_TEMPLATES)
#ifdef OO_BUGGY_TEMPLATES
inline
ooShortRef(ooHashBucketX)::ooShortRefStructor(ooHashBucketX)(const ooRef(ooHashBucketX) &  id)
{
  *this = id;
}
#else // !defined(OO_BUGGY_TEMPLATES)
inline
ooShortRef(ooHashBucketX)::ooShortRefStructor(ooHashBucketX)(const ooRef(ooHashBucketX) &  id) :
    ooShortRef(ooObj)(id)
{
}
#endif // !defined(OO_BUGGY_TEMPLATES)
#ifdef OO_BUGGY_TEMPLATES
inline
ooShortRef(ooHashBucketX)::ooShortRefStructor(ooHashBucketX)(const ooHandleSuper(ooHashBucketX) &  objH)
{
  *this = objH;
}
#else // !defined(OO_BUGGY_TEMPLATES)
inline
ooShortRef(ooHashBucketX)::ooShortRefStructor(ooHashBucketX)(const ooHandleSuper(ooHashBucketX) &  objH) :
    ooShortRef(ooObj)(objH)
{
}
#endif // !defined(OO_BUGGY_TEMPLATES)
#ifdef OO_BUGGY_TEMPLATES
inline
ooShortRef(ooHashBucketX)::ooShortRefStructor(ooHashBucketX)(const ooHashBucketX *  fromObject)
{
  *this = fromObject;
}
#else // !defined(OO_BUGGY_TEMPLATES)
inline
ooShortRef(ooHashBucketX)::ooShortRefStructor(ooHashBucketX)(const ooHashBucketX *  fromObject) :
    ooShortRef(ooObj)(ooReinterpretCast(const ooObj *,fromObject))
{
}
#endif // !defined(OO_BUGGY_TEMPLATES)


/* methods on ooHandle(ooHashBucketX) */
inline
ooHandle(ooHashBucketX)::ooHandleStructor(ooHashBucketX)()
{
}
inline
ooHandle(ooHashBucketX)::ooHandleStructor(ooHashBucketX)(const ooHandle(ooHashBucketX) &  objH) :
#ifdef OO_BUGGY_TEMPLATES
    ooHandle_superclass<ooHashBucketX >(objH)
#else // !defined(OO_BUGGY_TEMPLATES)
    ooHandle(ooObj)(objH)
#endif // !defined(OO_BUGGY_TEMPLATES)
{
}
inline
ooHandle(ooHashBucketX)::ooHandleStructor(ooHashBucketX)(const ooRef(ooHashBucketX) &  id) :
#ifdef OO_BUGGY_TEMPLATES
    ooHandle_superclass<ooHashBucketX >(id)
#else // !defined(OO_BUGGY_TEMPLATES)
    ooHandle(ooObj)(id)
#endif // !defined(OO_BUGGY_TEMPLATES)
{
}
inline
ooHandle(ooHashBucketX)::ooHandleStructor(ooHashBucketX)(const ooHashBucketX *  fromObject) :
#ifdef OO_BUGGY_TEMPLATES
    ooHandle_superclass<ooHashBucketX >(ooReinterpretCast(const ooObj *,fromObject))
#else // !defined(OO_BUGGY_TEMPLATES)
    ooHandle(ooObj)(ooReinterpretCast(const ooObj *,fromObject))
#endif // !defined(OO_BUGGY_TEMPLATES)
{
}
inline
ooHandle(ooHashBucketX)&
ooHandle(ooHashBucketX)::operator=(const ooRef(ooHashBucketX) &  id)
{
  this->ooHandle(ooObj)::operator=(id);
  return *this;
}
inline
ooHandle(ooHashBucketX)&
ooHandle(ooHashBucketX)::operator=(const ooHandle(ooHashBucketX) &  objH)
{
  this->ooHandle(ooObj)::operator=(objH);
  return *this;
}
inline
ooHandle(ooHashBucketX)&
ooHandle(ooHashBucketX)::operator=(const ooShortRef(ooHashBucketX) &  shortId)
{
  this->ooHandle(ooObj)::operator=(shortId);
  return *this;
}
inline
ooHandle(ooHashBucketX)&
ooHandle(ooHashBucketX)::operator=(const ooHashBucketX *  fromObject)
{
  this->ooHandle(ooObj)::operator=(ooReinterpretCast(const ooObj *,fromObject));
  return *this;
}
inline
ooHashBucketX *
ooHandle(ooHashBucketX)::pin(ooMode  openMode) const
{
  return ooReinterpretCast(ooHashBucketX *, this->pin_obj_internal(openMode));
}
inline
ooHashBucketX *
ooHandle(ooHashBucketX)::operator->() const
{
  return this->vm();
}
inline
ooHashBucketX &
ooHandle(ooHashBucketX)::operator*() const
{
  return *(this->vm());
}
inline
ooHandle(ooHashBucketX)::operator ooHashBucketX *() const
{
  if ( _state == oocHandlePTR  )
    return ooReinterpretCast(ooHashBucketX *, _ptr._obj);
  else return ooReinterpretCast(ooHashBucketX *, this->get_vm());
}
inline
ooHashBucketX *
ooHandle(ooHashBucketX)::vm() const
{
  if ( _state == oocHandlePTR && _ptr._obj != NULL )
    return ooReinterpretCast(ooHashBucketX *, _ptr._obj);
  else return ooReinterpretCast(ooHashBucketX *, this->get_vm());
}
inline
ooRef(ooHashBucketX) &
ooHandle(ooHashBucketX)::copy(const ooHandle(ooObj) &  nearH,
		   ooRef(ooHashBucketX) &              result) const
{
  this->ooHandle(ooObj)::copy(nearH, result);
  return result;
}


/* ODMG methods */
inline
ooHashBucketX *
ooRef(ooHashBucketX)::ptr() const
{
  return this->pin();
}
inline
ooHashBucketX *
ooHandle(ooHashBucketX)::ptr() const
{
  return this->operator ooHashBucketX *();
}
class ooHashBasedCollection;


/////////////////////////////////////////////////////////////////////////////

ooTemplateSpecialization
class ooDeref(ooHashBasedCollection) : public ooDerefBase {
	friend class ooRef(ooHashBasedCollection);
  public:
    ~ooDerefStructor(ooHashBasedCollection)();
    inline ooHashBasedCollection *operator->() const;
#ifndef OO_BUGGY_TEMPLATES
  private:
#endif // !defined(OO_BUGGY_TEMPLATES)
    ooDerefStructor(ooHashBasedCollection)(ooDeref(ooHashBasedCollection)& deref);
    ooDerefStructor(ooHashBasedCollection)(ooObj *  fromObject);
};


#ifdef OO_BUGGY_TEMPLATES

class ooHandle_superclass<ooHashBasedCollection > : public ooHandle(ooCollection) {
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

class ooShortRef_superclass<ooHashBasedCollection > : public ooShortRef(ooCollection) {
};

#endif // OO_BUGGY_TEMPLATES

ooTemplateSpecialization
class ooRef(ooHashBasedCollection) : public ooRef(ooCollection) {
  public:
    ooRefStructor(ooHashBasedCollection)()
      {}
    ooRefStructor(ooHashBasedCollection)(const ooRef(ooHashBasedCollection)& id) :
	  ooRef(ooCollection)(id)
      {}
    inline ooRefStructor(ooHashBasedCollection)(const ooHandleSuper(ooHashBasedCollection)& objH);
    inline ooRefStructor(ooHashBasedCollection)(const ooHashBasedCollection *  fromObject);
    inline ooRef(ooHashBasedCollection)& operator=(const ooRef(ooHashBasedCollection)& id);
    inline ooRef(ooHashBasedCollection)& operator=(const ooShortRefSuper(ooHashBasedCollection) &shortId);
    inline ooRef(ooHashBasedCollection)& operator=(const ooHandleSuper(ooHashBasedCollection)& objH);
    inline ooRef(ooHashBasedCollection)& operator=(const ooHashBasedCollection *  fromObject);
    ooStatus lookupObj(const ooHandle(ooObj)& scopeH,
		       const ooKey& key,
		       ooMode openMode = oocRead);
    ooStatus lookupObj(const ooHandle(ooObj)& scopeH,
		       const char* name,
		       ooMode openMode = oocRead);
#ifndef OO_BUGGY_TEMPLATES
    inline ooRef(ooHashBasedCollection)& copy(const ooHandle(ooObj)& nearH,
		    ooRef(ooHashBasedCollection)& newObjRef) const;
    inline ooHandle(ooHashBasedCollection)& copy(const ooHandle(ooObj)& nearH,
			ooHandle(ooHashBasedCollection)& result) const;
    inline ooHandle(ooHashBasedCollection) copy(const ooHandle(ooObj)& nearH) const;
#endif // !defined(OO_BUGGY_TEMPLATES)
    inline ooHashBasedCollection *pin(ooMode openMode = oocRead) const;
    ooDeref(ooHashBasedCollection) operator->() const;
    /* Use pin() or use ooHandle "operator ooHashBasedCollection *" instead of vm. */
    /* OBSOLETE */ inline ooHashBasedCollection *vm(ooMode openMode = oocRead) const;
    // ODMG methods:
    ooRefStructor(ooHashBasedCollection)(const d_Ref_Any &from);
    ooHashBasedCollection *ptr() const;
};

ooTemplateSpecialization
class ooShortRef(ooHashBasedCollection) :
#ifdef OO_BUGGY_TEMPLATES
			public ooShortRef_superclass<ooHashBasedCollection >
#else // !defined(OO_BUGGY_TEMPLATES)
			public ooShortRef(ooCollection)
#endif // !defined(OO_BUGGY_TEMPLATES)
					            {
  public:
    ooShortRefStructor(ooHashBasedCollection)();
    ooShortRefStructor(ooHashBasedCollection)(const ooShortRef(ooHashBasedCollection)& shortId);
    ooShortRefStructor(ooHashBasedCollection)(const ooRef(ooHashBasedCollection)& id);
    ooShortRefStructor(ooHashBasedCollection)(const ooHandleSuper(ooHashBasedCollection) &objH);
    ooShortRefStructor(ooHashBasedCollection)(const ooHashBasedCollection *  fromObject);
    ooShortRef(ooHashBasedCollection)& operator=(const ooShortRef(ooHashBasedCollection)& shortId);
    ooShortRef(ooHashBasedCollection)& operator=(const ooRef(ooHashBasedCollection)& id);
    ooShortRef(ooHashBasedCollection)& operator=(const ooHandleSuper(ooHashBasedCollection) &objH);
    ooShortRef(ooHashBasedCollection)& operator=(const ooHashBasedCollection *  fromObject);
};

ooTemplateSpecialization
class ooHandle(ooHashBasedCollection) :
#ifdef OO_BUGGY_TEMPLATES
		      public ooHandle_superclass<ooHashBasedCollection >
#else // !defined(OO_BUGGY_TEMPLATES)
		      public ooHandle(ooCollection)
#endif // !defined(OO_BUGGY_TEMPLATES)
                                                {
  public:
    inline ooHandleStructor(ooHashBasedCollection)();
    inline ooHandleStructor(ooHashBasedCollection)(const ooRef(ooHashBasedCollection)& id);
    inline ooHandleStructor(ooHashBasedCollection)(const ooHandle(ooHashBasedCollection)& objH);
    inline ooHandleStructor(ooHashBasedCollection)(const ooHashBasedCollection *  fromObject);
    inline ooHandle(ooHashBasedCollection)& operator=(const ooRef(ooHashBasedCollection)& id);
    inline ooHandle(ooHashBasedCollection)& operator=(const ooHandle(ooHashBasedCollection)& objH);
    inline ooHandle(ooHashBasedCollection)& operator=(const ooShortRef(ooHashBasedCollection)& shortId);
    inline ooHandle(ooHashBasedCollection)& operator=(const ooHashBasedCollection *  fromObject);
    ooStatus lookupObj(const ooHandle(ooObj)& scopeH,
		       const ooKey& key,
		       ooMode openMode = oocRead);
    ooStatus lookupObj(const ooHandle(ooObj)& scopeH,
		       const char* name,
		       ooMode openMode = oocRead);
    ooHandle(ooHashBasedCollection)& copy(const ooHandle(ooObj)& nearH,
		       ooHandle(ooHashBasedCollection)& result) const;
    inline ooRef(ooHashBasedCollection)& copy(const ooHandle(ooObj)& nearH,
		    ooRef(ooHashBasedCollection)& result) const;
    ooHandle(ooHashBasedCollection) copy(const ooHandle(ooObj)& nearH) const;
    inline ooHashBasedCollection *pin(ooMode openMode = oocRead) const;
    inline ooHashBasedCollection *operator->() const;
    inline ooHashBasedCollection &operator*() const;
    inline operator ooHashBasedCollection *() const;
    /* Use "operator ooHashBasedCollection *" instead of vm. */
    /* OBSOLETE */ inline ooHashBasedCollection *vm() const;
    // ODMG methods:
    ooHandleStructor(ooHashBasedCollection)(const d_Ref_Any &from);
    ooHashBasedCollection *ptr() const;
};

ooTemplateSpecialization
class ooItr(ooHashBasedCollection) : public ooHandle(ooHashBasedCollection),
		    public ooIteratorObjOrContObj {
  public:
    ooItrStructor(ooHashBasedCollection)();
    ~ooItrStructor(ooHashBasedCollection)();
  private:
    // Defined only to prevent implicit definition:
    ooItrStructor(ooHashBasedCollection)(ooItr(ooHashBasedCollection)&);
    ooItr(ooHashBasedCollection)    operator=(ooItr(ooHashBasedCollection)&);
};


/* methods on ooDeref(ooHashBasedCollection) */
inline
ooDeref(ooHashBasedCollection)::ooDerefStructor(ooHashBasedCollection)(ooDeref(ooHashBasedCollection) &  deref) :
    ooDerefBase(deref.vm())
{
  this->pinCompensate();
}
inline
ooDeref(ooHashBasedCollection)::ooDerefStructor(ooHashBasedCollection)(ooObj *  fromObject) :
    ooDerefBase(fromObject)
{
}
inline
ooDeref(ooHashBasedCollection)::~ooDerefStructor(ooHashBasedCollection)()
{
}
inline
ooHashBasedCollection *
ooDeref(ooHashBasedCollection)::operator->() const
{
  return ooReinterpretCast(ooHashBasedCollection *, this->vm());
}


/* methods on ooRef(ooHashBasedCollection) */
inline
ooRef(ooHashBasedCollection)::ooRefStructor(ooHashBasedCollection)(const ooHandleSuper(ooHashBasedCollection)& objH) :
    ooRef(ooCollection)(objH)
{
}
inline
ooRef(ooHashBasedCollection)::ooRefStructor(ooHashBasedCollection)(const ooHashBasedCollection *  fromObject) :
    ooRef(ooCollection)(ooReinterpretCast(const ooCollection *, fromObject))
{
}
inline
ooRef(ooHashBasedCollection)&
ooRef(ooHashBasedCollection)::operator=(const ooRef(ooHashBasedCollection) &  id)
{
  this->ooId::operator=(id);
  return *this;
}
inline
ooRef(ooHashBasedCollection)&
ooRef(ooHashBasedCollection)::operator=(const ooShortRefSuper(ooHashBasedCollection) &  shortId)
{
  this->ooRef(ooObj)::operator=(shortId);
  return *this;
}
inline
ooRef(ooHashBasedCollection)&
ooRef(ooHashBasedCollection)::operator=(const ooHandleSuper(ooHashBasedCollection) &  objH)
{
  this->ooRef(ooObj)::operator=(objH);
  return *this;
}
inline
ooRef(ooHashBasedCollection)&
ooRef(ooHashBasedCollection)::operator=(const ooHashBasedCollection *  fromObject)
{
  this->ooRef(ooObj)::operator=(ooReinterpretCast(const ooObj *, fromObject));
  return *this;
}
inline
ooHashBasedCollection *
ooRef(ooHashBasedCollection)::pin(ooMode  openMode) const
{
  return ooReinterpretCast(ooHashBasedCollection *, this->pin_ref_internal(openMode));
}
inline
ooHashBasedCollection *
ooRef(ooHashBasedCollection)::vm(ooMode  openMode) const
{
  return this->pin(openMode);
}
#ifndef OO_BUGGY_TEMPLATES
inline
ooHandle(ooHashBasedCollection) &
ooRef(ooHashBasedCollection)::copy(const ooHandle(ooObj) &  nearH,
		ooHandle(ooHashBasedCollection) &           result) const
{
  this->ooRef(ooObj)::copy(nearH, result);
  return result;
}
inline
ooRef(ooHashBasedCollection) &
ooRef(ooHashBasedCollection)::copy(const ooHandle(ooObj) &  nearH,
		ooRef(ooHashBasedCollection) &              newObjRef) const
{
  this->ooRef(ooObj)::copy(nearH, newObjRef);
  return newObjRef;
}
inline
ooHandle(ooHashBasedCollection)
ooRef(ooHashBasedCollection)::copy(const ooHandle(ooObj) &  nearH) const
{
  ooHandle(ooHashBasedCollection) result;
  this->ooRef(ooObj)::copy(nearH, result);
  return result;
}
#endif // !defined(OO_BUGGY_TEMPLATES)
inline
ooDeref(ooHashBasedCollection)
ooRef(ooHashBasedCollection)::operator->() const
{
  ooDeref(ooHashBasedCollection) result(this->pin_ref_internal(oocRead));
  return result;
}


/* methods on ooShortRef(ooHashBasedCollection) */
inline
ooShortRef(ooHashBasedCollection) &
ooShortRef(ooHashBasedCollection)::operator=(const ooShortRef(ooHashBasedCollection) &  shortId)
{
  this->ooShortId::operator=(shortId);
  return *this;
}
inline
ooShortRef(ooHashBasedCollection) &
ooShortRef(ooHashBasedCollection)::operator=(const ooRef(ooHashBasedCollection) &  id)
{
  this->ooShortId::operator=(id);
  return *this;
}
inline
ooShortRef(ooHashBasedCollection) &
ooShortRef(ooHashBasedCollection)::operator=(const ooHandleSuper(ooHashBasedCollection) &  objH)
{
  this->ooShortId::operator=(objH);
  return *this;
}
inline
ooShortRef(ooHashBasedCollection)&
ooShortRef(ooHashBasedCollection)::operator=(const ooHashBasedCollection *  fromObject)
{
  this->ooShortId::operator=(ooReinterpretCast(const ooObj *,fromObject));
  return *this;
}
inline
ooShortRef(ooHashBasedCollection)::ooShortRefStructor(ooHashBasedCollection)()
{
}
#ifdef OO_BUGGY_TEMPLATES
inline
ooShortRef(ooHashBasedCollection)::ooShortRefStructor(ooHashBasedCollection)(const ooShortRef(ooHashBasedCollection) &  shortId)
{
  *this = shortId;
}
#else // !defined(OO_BUGGY_TEMPLATES)
inline
ooShortRef(ooHashBasedCollection)::ooShortRefStructor(ooHashBasedCollection)(const ooShortRef(ooHashBasedCollection) &  shortId) :
    ooShortRef(ooCollection)(shortId)
{
}
#endif // !defined(OO_BUGGY_TEMPLATES)
#ifdef OO_BUGGY_TEMPLATES
inline
ooShortRef(ooHashBasedCollection)::ooShortRefStructor(ooHashBasedCollection)(const ooRef(ooHashBasedCollection) &  id)
{
  *this = id;
}
#else // !defined(OO_BUGGY_TEMPLATES)
inline
ooShortRef(ooHashBasedCollection)::ooShortRefStructor(ooHashBasedCollection)(const ooRef(ooHashBasedCollection) &  id) :
    ooShortRef(ooCollection)(id)
{
}
#endif // !defined(OO_BUGGY_TEMPLATES)
#ifdef OO_BUGGY_TEMPLATES
inline
ooShortRef(ooHashBasedCollection)::ooShortRefStructor(ooHashBasedCollection)(const ooHandleSuper(ooHashBasedCollection) &  objH)
{
  *this = objH;
}
#else // !defined(OO_BUGGY_TEMPLATES)
inline
ooShortRef(ooHashBasedCollection)::ooShortRefStructor(ooHashBasedCollection)(const ooHandleSuper(ooHashBasedCollection) &  objH) :
    ooShortRef(ooCollection)(objH)
{
}
#endif // !defined(OO_BUGGY_TEMPLATES)
#ifdef OO_BUGGY_TEMPLATES
inline
ooShortRef(ooHashBasedCollection)::ooShortRefStructor(ooHashBasedCollection)(const ooHashBasedCollection *  fromObject)
{
  *this = fromObject;
}
#else // !defined(OO_BUGGY_TEMPLATES)
inline
ooShortRef(ooHashBasedCollection)::ooShortRefStructor(ooHashBasedCollection)(const ooHashBasedCollection *  fromObject) :
    ooShortRef(ooCollection)(ooReinterpretCast(const ooCollection *,fromObject))
{
}
#endif // !defined(OO_BUGGY_TEMPLATES)


/* methods on ooHandle(ooHashBasedCollection) */
inline
ooHandle(ooHashBasedCollection)::ooHandleStructor(ooHashBasedCollection)()
{
}
inline
ooHandle(ooHashBasedCollection)::ooHandleStructor(ooHashBasedCollection)(const ooHandle(ooHashBasedCollection) &  objH) :
#ifdef OO_BUGGY_TEMPLATES
    ooHandle_superclass<ooHashBasedCollection >(objH)
#else // !defined(OO_BUGGY_TEMPLATES)
    ooHandle(ooCollection)(objH)
#endif // !defined(OO_BUGGY_TEMPLATES)
{
}
inline
ooHandle(ooHashBasedCollection)::ooHandleStructor(ooHashBasedCollection)(const ooRef(ooHashBasedCollection) &  id) :
#ifdef OO_BUGGY_TEMPLATES
    ooHandle_superclass<ooHashBasedCollection >(id)
#else // !defined(OO_BUGGY_TEMPLATES)
    ooHandle(ooCollection)(id)
#endif // !defined(OO_BUGGY_TEMPLATES)
{
}
inline
ooHandle(ooHashBasedCollection)::ooHandleStructor(ooHashBasedCollection)(const ooHashBasedCollection *  fromObject) :
#ifdef OO_BUGGY_TEMPLATES
    ooHandle_superclass<ooHashBasedCollection >(ooReinterpretCast(const ooCollection *,fromObject))
#else // !defined(OO_BUGGY_TEMPLATES)
    ooHandle(ooCollection)(ooReinterpretCast(const ooCollection *,fromObject))
#endif // !defined(OO_BUGGY_TEMPLATES)
{
}
inline
ooHandle(ooHashBasedCollection)&
ooHandle(ooHashBasedCollection)::operator=(const ooRef(ooHashBasedCollection) &  id)
{
  this->ooHandle(ooObj)::operator=(id);
  return *this;
}
inline
ooHandle(ooHashBasedCollection)&
ooHandle(ooHashBasedCollection)::operator=(const ooHandle(ooHashBasedCollection) &  objH)
{
  this->ooHandle(ooObj)::operator=(objH);
  return *this;
}
inline
ooHandle(ooHashBasedCollection)&
ooHandle(ooHashBasedCollection)::operator=(const ooShortRef(ooHashBasedCollection) &  shortId)
{
  this->ooHandle(ooObj)::operator=(shortId);
  return *this;
}
inline
ooHandle(ooHashBasedCollection)&
ooHandle(ooHashBasedCollection)::operator=(const ooHashBasedCollection *  fromObject)
{
  this->ooHandle(ooObj)::operator=(ooReinterpretCast(const ooObj *,fromObject));
  return *this;
}
inline
ooHashBasedCollection *
ooHandle(ooHashBasedCollection)::pin(ooMode  openMode) const
{
  return ooReinterpretCast(ooHashBasedCollection *, this->pin_obj_internal(openMode));
}
inline
ooHashBasedCollection *
ooHandle(ooHashBasedCollection)::operator->() const
{
  return this->vm();
}
inline
ooHashBasedCollection &
ooHandle(ooHashBasedCollection)::operator*() const
{
  return *(this->vm());
}
inline
ooHandle(ooHashBasedCollection)::operator ooHashBasedCollection *() const
{
  if ( _state == oocHandlePTR  )
    return ooReinterpretCast(ooHashBasedCollection *, _ptr._obj);
  else return ooReinterpretCast(ooHashBasedCollection *, this->get_vm());
}
inline
ooHashBasedCollection *
ooHandle(ooHashBasedCollection)::vm() const
{
  if ( _state == oocHandlePTR && _ptr._obj != NULL )
    return ooReinterpretCast(ooHashBasedCollection *, _ptr._obj);
  else return ooReinterpretCast(ooHashBasedCollection *, this->get_vm());
}
inline
ooRef(ooHashBasedCollection) &
ooHandle(ooHashBasedCollection)::copy(const ooHandle(ooObj) &  nearH,
		   ooRef(ooHashBasedCollection) &              result) const
{
  this->ooHandle(ooObj)::copy(nearH, result);
  return result;
}


/* ODMG methods */
inline
ooHashBasedCollection *
ooRef(ooHashBasedCollection)::ptr() const
{
  return this->pin();
}
inline
ooHashBasedCollection *
ooHandle(ooHashBasedCollection)::ptr() const
{
  return this->operator ooHashBasedCollection *();
}
class ooHashSetX;


/////////////////////////////////////////////////////////////////////////////

ooTemplateSpecialization
class ooDeref(ooHashSetX) : public ooDerefBase {
	friend class ooRef(ooHashSetX);
  public:
    ~ooDerefStructor(ooHashSetX)();
    inline ooHashSetX *operator->() const;
#ifndef OO_BUGGY_TEMPLATES
  private:
#endif // !defined(OO_BUGGY_TEMPLATES)
    ooDerefStructor(ooHashSetX)(ooDeref(ooHashSetX)& deref);
    ooDerefStructor(ooHashSetX)(ooObj *  fromObject);
};


#ifdef OO_BUGGY_TEMPLATES

class ooHandle_superclass<ooHashSetX > : public ooHandle(ooHashBasedCollection) {
 protected:
  ooHandle_superclass()
    {}
  ooHandle_superclass(const ooHandle(ooHashBasedCollection) &  from) :
      ooHandle(ooHashBasedCollection)(from)
    {}
  ooHandle_superclass(const ooRef(ooHashBasedCollection) &  from) :
      ooHandle(ooHashBasedCollection)(from)
    {}
  ooHandle_superclass(const ooHashBasedCollection *  from) :
      ooHandle(ooHashBasedCollection)(from)
    {}
  ~ooHandle_superclass()
    {}
};

class ooShortRef_superclass<ooHashSetX > : public ooShortRef(ooHashBasedCollection) {
};

#endif // OO_BUGGY_TEMPLATES

ooTemplateSpecialization
class ooRef(ooHashSetX) : public ooRef(ooHashBasedCollection) {
  public:
    ooRefStructor(ooHashSetX)()
      {}
    ooRefStructor(ooHashSetX)(const ooRef(ooHashSetX)& id) :
	  ooRef(ooHashBasedCollection)(id)
      {}
    inline ooRefStructor(ooHashSetX)(const ooHandleSuper(ooHashSetX)& objH);
    inline ooRefStructor(ooHashSetX)(const ooHashSetX *  fromObject);
    inline ooRef(ooHashSetX)& operator=(const ooRef(ooHashSetX)& id);
    inline ooRef(ooHashSetX)& operator=(const ooShortRefSuper(ooHashSetX) &shortId);
    inline ooRef(ooHashSetX)& operator=(const ooHandleSuper(ooHashSetX)& objH);
    inline ooRef(ooHashSetX)& operator=(const ooHashSetX *  fromObject);
    ooStatus lookupObj(const ooHandle(ooObj)& scopeH,
		       const ooKey& key,
		       ooMode openMode = oocRead);
    ooStatus lookupObj(const ooHandle(ooObj)& scopeH,
		       const char* name,
		       ooMode openMode = oocRead);
#ifndef OO_BUGGY_TEMPLATES
    inline ooRef(ooHashSetX)& copy(const ooHandle(ooObj)& nearH,
		    ooRef(ooHashSetX)& newObjRef) const;
    inline ooHandle(ooHashSetX)& copy(const ooHandle(ooObj)& nearH,
			ooHandle(ooHashSetX)& result) const;
    inline ooHandle(ooHashSetX) copy(const ooHandle(ooObj)& nearH) const;
#endif // !defined(OO_BUGGY_TEMPLATES)
    inline ooHashSetX *pin(ooMode openMode = oocRead) const;
    ooDeref(ooHashSetX) operator->() const;
    /* Use pin() or use ooHandle "operator ooHashSetX *" instead of vm. */
    /* OBSOLETE */ inline ooHashSetX *vm(ooMode openMode = oocRead) const;
    // ODMG methods:
    ooRefStructor(ooHashSetX)(const d_Ref_Any &from);
    ooHashSetX *ptr() const;
};

ooTemplateSpecialization
class ooShortRef(ooHashSetX) :
#ifdef OO_BUGGY_TEMPLATES
			public ooShortRef_superclass<ooHashSetX >
#else // !defined(OO_BUGGY_TEMPLATES)
			public ooShortRef(ooHashBasedCollection)
#endif // !defined(OO_BUGGY_TEMPLATES)
					            {
  public:
    ooShortRefStructor(ooHashSetX)();
    ooShortRefStructor(ooHashSetX)(const ooShortRef(ooHashSetX)& shortId);
    ooShortRefStructor(ooHashSetX)(const ooRef(ooHashSetX)& id);
    ooShortRefStructor(ooHashSetX)(const ooHandleSuper(ooHashSetX) &objH);
    ooShortRefStructor(ooHashSetX)(const ooHashSetX *  fromObject);
    ooShortRef(ooHashSetX)& operator=(const ooShortRef(ooHashSetX)& shortId);
    ooShortRef(ooHashSetX)& operator=(const ooRef(ooHashSetX)& id);
    ooShortRef(ooHashSetX)& operator=(const ooHandleSuper(ooHashSetX) &objH);
    ooShortRef(ooHashSetX)& operator=(const ooHashSetX *  fromObject);
};

ooTemplateSpecialization
class ooHandle(ooHashSetX) :
#ifdef OO_BUGGY_TEMPLATES
		      public ooHandle_superclass<ooHashSetX >
#else // !defined(OO_BUGGY_TEMPLATES)
		      public ooHandle(ooHashBasedCollection)
#endif // !defined(OO_BUGGY_TEMPLATES)
                                                {
  public:
    inline ooHandleStructor(ooHashSetX)();
    inline ooHandleStructor(ooHashSetX)(const ooRef(ooHashSetX)& id);
    inline ooHandleStructor(ooHashSetX)(const ooHandle(ooHashSetX)& objH);
    inline ooHandleStructor(ooHashSetX)(const ooHashSetX *  fromObject);
    inline ooHandle(ooHashSetX)& operator=(const ooRef(ooHashSetX)& id);
    inline ooHandle(ooHashSetX)& operator=(const ooHandle(ooHashSetX)& objH);
    inline ooHandle(ooHashSetX)& operator=(const ooShortRef(ooHashSetX)& shortId);
    inline ooHandle(ooHashSetX)& operator=(const ooHashSetX *  fromObject);
    ooStatus lookupObj(const ooHandle(ooObj)& scopeH,
		       const ooKey& key,
		       ooMode openMode = oocRead);
    ooStatus lookupObj(const ooHandle(ooObj)& scopeH,
		       const char* name,
		       ooMode openMode = oocRead);
    ooHandle(ooHashSetX)& copy(const ooHandle(ooObj)& nearH,
		       ooHandle(ooHashSetX)& result) const;
    inline ooRef(ooHashSetX)& copy(const ooHandle(ooObj)& nearH,
		    ooRef(ooHashSetX)& result) const;
    ooHandle(ooHashSetX) copy(const ooHandle(ooObj)& nearH) const;
    inline ooHashSetX *pin(ooMode openMode = oocRead) const;
    inline ooHashSetX *operator->() const;
    inline ooHashSetX &operator*() const;
    inline operator ooHashSetX *() const;
    /* Use "operator ooHashSetX *" instead of vm. */
    /* OBSOLETE */ inline ooHashSetX *vm() const;
    // ODMG methods:
    ooHandleStructor(ooHashSetX)(const d_Ref_Any &from);
    ooHashSetX *ptr() const;
};

ooTemplateSpecialization
class ooItr(ooHashSetX) : public ooHandle(ooHashSetX),
		    public ooIteratorObjOrContObj {
  public:
    ooItrStructor(ooHashSetX)();
    ~ooItrStructor(ooHashSetX)();
  private:
    // Defined only to prevent implicit definition:
    ooItrStructor(ooHashSetX)(ooItr(ooHashSetX)&);
    ooItr(ooHashSetX)    operator=(ooItr(ooHashSetX)&);
};


/* methods on ooDeref(ooHashSetX) */
inline
ooDeref(ooHashSetX)::ooDerefStructor(ooHashSetX)(ooDeref(ooHashSetX) &  deref) :
    ooDerefBase(deref.vm())
{
  this->pinCompensate();
}
inline
ooDeref(ooHashSetX)::ooDerefStructor(ooHashSetX)(ooObj *  fromObject) :
    ooDerefBase(fromObject)
{
}
inline
ooDeref(ooHashSetX)::~ooDerefStructor(ooHashSetX)()
{
}
inline
ooHashSetX *
ooDeref(ooHashSetX)::operator->() const
{
  return ooReinterpretCast(ooHashSetX *, this->vm());
}


/* methods on ooRef(ooHashSetX) */
inline
ooRef(ooHashSetX)::ooRefStructor(ooHashSetX)(const ooHandleSuper(ooHashSetX)& objH) :
    ooRef(ooHashBasedCollection)(objH)
{
}
inline
ooRef(ooHashSetX)::ooRefStructor(ooHashSetX)(const ooHashSetX *  fromObject) :
    ooRef(ooHashBasedCollection)(ooReinterpretCast(const ooHashBasedCollection *, fromObject))
{
}
inline
ooRef(ooHashSetX)&
ooRef(ooHashSetX)::operator=(const ooRef(ooHashSetX) &  id)
{
  this->ooId::operator=(id);
  return *this;
}
inline
ooRef(ooHashSetX)&
ooRef(ooHashSetX)::operator=(const ooShortRefSuper(ooHashSetX) &  shortId)
{
  this->ooRef(ooObj)::operator=(shortId);
  return *this;
}
inline
ooRef(ooHashSetX)&
ooRef(ooHashSetX)::operator=(const ooHandleSuper(ooHashSetX) &  objH)
{
  this->ooRef(ooObj)::operator=(objH);
  return *this;
}
inline
ooRef(ooHashSetX)&
ooRef(ooHashSetX)::operator=(const ooHashSetX *  fromObject)
{
  this->ooRef(ooObj)::operator=(ooReinterpretCast(const ooObj *, fromObject));
  return *this;
}
inline
ooHashSetX *
ooRef(ooHashSetX)::pin(ooMode  openMode) const
{
  return ooReinterpretCast(ooHashSetX *, this->pin_ref_internal(openMode));
}
inline
ooHashSetX *
ooRef(ooHashSetX)::vm(ooMode  openMode) const
{
  return this->pin(openMode);
}
#ifndef OO_BUGGY_TEMPLATES
inline
ooHandle(ooHashSetX) &
ooRef(ooHashSetX)::copy(const ooHandle(ooObj) &  nearH,
		ooHandle(ooHashSetX) &           result) const
{
  this->ooRef(ooObj)::copy(nearH, result);
  return result;
}
inline
ooRef(ooHashSetX) &
ooRef(ooHashSetX)::copy(const ooHandle(ooObj) &  nearH,
		ooRef(ooHashSetX) &              newObjRef) const
{
  this->ooRef(ooObj)::copy(nearH, newObjRef);
  return newObjRef;
}
inline
ooHandle(ooHashSetX)
ooRef(ooHashSetX)::copy(const ooHandle(ooObj) &  nearH) const
{
  ooHandle(ooHashSetX) result;
  this->ooRef(ooObj)::copy(nearH, result);
  return result;
}
#endif // !defined(OO_BUGGY_TEMPLATES)
inline
ooDeref(ooHashSetX)
ooRef(ooHashSetX)::operator->() const
{
  ooDeref(ooHashSetX) result(this->pin_ref_internal(oocRead));
  return result;
}


/* methods on ooShortRef(ooHashSetX) */
inline
ooShortRef(ooHashSetX) &
ooShortRef(ooHashSetX)::operator=(const ooShortRef(ooHashSetX) &  shortId)
{
  this->ooShortId::operator=(shortId);
  return *this;
}
inline
ooShortRef(ooHashSetX) &
ooShortRef(ooHashSetX)::operator=(const ooRef(ooHashSetX) &  id)
{
  this->ooShortId::operator=(id);
  return *this;
}
inline
ooShortRef(ooHashSetX) &
ooShortRef(ooHashSetX)::operator=(const ooHandleSuper(ooHashSetX) &  objH)
{
  this->ooShortId::operator=(objH);
  return *this;
}
inline
ooShortRef(ooHashSetX)&
ooShortRef(ooHashSetX)::operator=(const ooHashSetX *  fromObject)
{
  this->ooShortId::operator=(ooReinterpretCast(const ooObj *,fromObject));
  return *this;
}
inline
ooShortRef(ooHashSetX)::ooShortRefStructor(ooHashSetX)()
{
}
#ifdef OO_BUGGY_TEMPLATES
inline
ooShortRef(ooHashSetX)::ooShortRefStructor(ooHashSetX)(const ooShortRef(ooHashSetX) &  shortId)
{
  *this = shortId;
}
#else // !defined(OO_BUGGY_TEMPLATES)
inline
ooShortRef(ooHashSetX)::ooShortRefStructor(ooHashSetX)(const ooShortRef(ooHashSetX) &  shortId) :
    ooShortRef(ooHashBasedCollection)(shortId)
{
}
#endif // !defined(OO_BUGGY_TEMPLATES)
#ifdef OO_BUGGY_TEMPLATES
inline
ooShortRef(ooHashSetX)::ooShortRefStructor(ooHashSetX)(const ooRef(ooHashSetX) &  id)
{
  *this = id;
}
#else // !defined(OO_BUGGY_TEMPLATES)
inline
ooShortRef(ooHashSetX)::ooShortRefStructor(ooHashSetX)(const ooRef(ooHashSetX) &  id) :
    ooShortRef(ooHashBasedCollection)(id)
{
}
#endif // !defined(OO_BUGGY_TEMPLATES)
#ifdef OO_BUGGY_TEMPLATES
inline
ooShortRef(ooHashSetX)::ooShortRefStructor(ooHashSetX)(const ooHandleSuper(ooHashSetX) &  objH)
{
  *this = objH;
}
#else // !defined(OO_BUGGY_TEMPLATES)
inline
ooShortRef(ooHashSetX)::ooShortRefStructor(ooHashSetX)(const ooHandleSuper(ooHashSetX) &  objH) :
    ooShortRef(ooHashBasedCollection)(objH)
{
}
#endif // !defined(OO_BUGGY_TEMPLATES)
#ifdef OO_BUGGY_TEMPLATES
inline
ooShortRef(ooHashSetX)::ooShortRefStructor(ooHashSetX)(const ooHashSetX *  fromObject)
{
  *this = fromObject;
}
#else // !defined(OO_BUGGY_TEMPLATES)
inline
ooShortRef(ooHashSetX)::ooShortRefStructor(ooHashSetX)(const ooHashSetX *  fromObject) :
    ooShortRef(ooHashBasedCollection)(ooReinterpretCast(const ooHashBasedCollection *,fromObject))
{
}
#endif // !defined(OO_BUGGY_TEMPLATES)


/* methods on ooHandle(ooHashSetX) */
inline
ooHandle(ooHashSetX)::ooHandleStructor(ooHashSetX)()
{
}
inline
ooHandle(ooHashSetX)::ooHandleStructor(ooHashSetX)(const ooHandle(ooHashSetX) &  objH) :
#ifdef OO_BUGGY_TEMPLATES
    ooHandle_superclass<ooHashSetX >(objH)
#else // !defined(OO_BUGGY_TEMPLATES)
    ooHandle(ooHashBasedCollection)(objH)
#endif // !defined(OO_BUGGY_TEMPLATES)
{
}
inline
ooHandle(ooHashSetX)::ooHandleStructor(ooHashSetX)(const ooRef(ooHashSetX) &  id) :
#ifdef OO_BUGGY_TEMPLATES
    ooHandle_superclass<ooHashSetX >(id)
#else // !defined(OO_BUGGY_TEMPLATES)
    ooHandle(ooHashBasedCollection)(id)
#endif // !defined(OO_BUGGY_TEMPLATES)
{
}
inline
ooHandle(ooHashSetX)::ooHandleStructor(ooHashSetX)(const ooHashSetX *  fromObject) :
#ifdef OO_BUGGY_TEMPLATES
    ooHandle_superclass<ooHashSetX >(ooReinterpretCast(const ooHashBasedCollection *,fromObject))
#else // !defined(OO_BUGGY_TEMPLATES)
    ooHandle(ooHashBasedCollection)(ooReinterpretCast(const ooHashBasedCollection *,fromObject))
#endif // !defined(OO_BUGGY_TEMPLATES)
{
}
inline
ooHandle(ooHashSetX)&
ooHandle(ooHashSetX)::operator=(const ooRef(ooHashSetX) &  id)
{
  this->ooHandle(ooObj)::operator=(id);
  return *this;
}
inline
ooHandle(ooHashSetX)&
ooHandle(ooHashSetX)::operator=(const ooHandle(ooHashSetX) &  objH)
{
  this->ooHandle(ooObj)::operator=(objH);
  return *this;
}
inline
ooHandle(ooHashSetX)&
ooHandle(ooHashSetX)::operator=(const ooShortRef(ooHashSetX) &  shortId)
{
  this->ooHandle(ooObj)::operator=(shortId);
  return *this;
}
inline
ooHandle(ooHashSetX)&
ooHandle(ooHashSetX)::operator=(const ooHashSetX *  fromObject)
{
  this->ooHandle(ooObj)::operator=(ooReinterpretCast(const ooObj *,fromObject));
  return *this;
}
inline
ooHashSetX *
ooHandle(ooHashSetX)::pin(ooMode  openMode) const
{
  return ooReinterpretCast(ooHashSetX *, this->pin_obj_internal(openMode));
}
inline
ooHashSetX *
ooHandle(ooHashSetX)::operator->() const
{
  return this->vm();
}
inline
ooHashSetX &
ooHandle(ooHashSetX)::operator*() const
{
  return *(this->vm());
}
inline
ooHandle(ooHashSetX)::operator ooHashSetX *() const
{
  if ( _state == oocHandlePTR  )
    return ooReinterpretCast(ooHashSetX *, _ptr._obj);
  else return ooReinterpretCast(ooHashSetX *, this->get_vm());
}
inline
ooHashSetX *
ooHandle(ooHashSetX)::vm() const
{
  if ( _state == oocHandlePTR && _ptr._obj != NULL )
    return ooReinterpretCast(ooHashSetX *, _ptr._obj);
  else return ooReinterpretCast(ooHashSetX *, this->get_vm());
}
inline
ooRef(ooHashSetX) &
ooHandle(ooHashSetX)::copy(const ooHandle(ooObj) &  nearH,
		   ooRef(ooHashSetX) &              result) const
{
  this->ooHandle(ooObj)::copy(nearH, result);
  return result;
}


/* ODMG methods */
inline
ooHashSetX *
ooRef(ooHashSetX)::ptr() const
{
  return this->pin();
}
inline
ooHashSetX *
ooHandle(ooHashSetX)::ptr() const
{
  return this->operator ooHashSetX *();
}
class ooHashSetShortRef;


/////////////////////////////////////////////////////////////////////////////

ooTemplateSpecialization
class ooDeref(ooHashSetShortRef) : public ooDerefBase {
	friend class ooRef(ooHashSetShortRef);
  public:
    ~ooDerefStructor(ooHashSetShortRef)();
    inline ooHashSetShortRef *operator->() const;
#ifndef OO_BUGGY_TEMPLATES
  private:
#endif // !defined(OO_BUGGY_TEMPLATES)
    ooDerefStructor(ooHashSetShortRef)(ooDeref(ooHashSetShortRef)& deref);
    ooDerefStructor(ooHashSetShortRef)(ooObj *  fromObject);
};


#ifdef OO_BUGGY_TEMPLATES

class ooHandle_superclass<ooHashSetShortRef > : public ooHandle(ooHashBasedCollection) {
 protected:
  ooHandle_superclass()
    {}
  ooHandle_superclass(const ooHandle(ooHashBasedCollection) &  from) :
      ooHandle(ooHashBasedCollection)(from)
    {}
  ooHandle_superclass(const ooRef(ooHashBasedCollection) &  from) :
      ooHandle(ooHashBasedCollection)(from)
    {}
  ooHandle_superclass(const ooHashBasedCollection *  from) :
      ooHandle(ooHashBasedCollection)(from)
    {}
  ~ooHandle_superclass()
    {}
};

class ooShortRef_superclass<ooHashSetShortRef > : public ooShortRef(ooHashBasedCollection) {
};

#endif // OO_BUGGY_TEMPLATES

ooTemplateSpecialization
class ooRef(ooHashSetShortRef) : public ooRef(ooHashBasedCollection) {
  public:
    ooRefStructor(ooHashSetShortRef)()
      {}
    ooRefStructor(ooHashSetShortRef)(const ooRef(ooHashSetShortRef)& id) :
	  ooRef(ooHashBasedCollection)(id)
      {}
    inline ooRefStructor(ooHashSetShortRef)(const ooHandleSuper(ooHashSetShortRef)& objH);
    inline ooRefStructor(ooHashSetShortRef)(const ooHashSetShortRef *  fromObject);
    inline ooRef(ooHashSetShortRef)& operator=(const ooRef(ooHashSetShortRef)& id);
    inline ooRef(ooHashSetShortRef)& operator=(const ooShortRefSuper(ooHashSetShortRef) &shortId);
    inline ooRef(ooHashSetShortRef)& operator=(const ooHandleSuper(ooHashSetShortRef)& objH);
    inline ooRef(ooHashSetShortRef)& operator=(const ooHashSetShortRef *  fromObject);
    ooStatus lookupObj(const ooHandle(ooObj)& scopeH,
		       const ooKey& key,
		       ooMode openMode = oocRead);
    ooStatus lookupObj(const ooHandle(ooObj)& scopeH,
		       const char* name,
		       ooMode openMode = oocRead);
#ifndef OO_BUGGY_TEMPLATES
    inline ooRef(ooHashSetShortRef)& copy(const ooHandle(ooObj)& nearH,
		    ooRef(ooHashSetShortRef)& newObjRef) const;
    inline ooHandle(ooHashSetShortRef)& copy(const ooHandle(ooObj)& nearH,
			ooHandle(ooHashSetShortRef)& result) const;
    inline ooHandle(ooHashSetShortRef) copy(const ooHandle(ooObj)& nearH) const;
#endif // !defined(OO_BUGGY_TEMPLATES)
    inline ooHashSetShortRef *pin(ooMode openMode = oocRead) const;
    ooDeref(ooHashSetShortRef) operator->() const;
    /* Use pin() or use ooHandle "operator ooHashSetShortRef *" instead of vm. */
    /* OBSOLETE */ inline ooHashSetShortRef *vm(ooMode openMode = oocRead) const;
    // ODMG methods:
    ooRefStructor(ooHashSetShortRef)(const d_Ref_Any &from);
    ooHashSetShortRef *ptr() const;
};

ooTemplateSpecialization
class ooShortRef(ooHashSetShortRef) :
#ifdef OO_BUGGY_TEMPLATES
			public ooShortRef_superclass<ooHashSetShortRef >
#else // !defined(OO_BUGGY_TEMPLATES)
			public ooShortRef(ooHashBasedCollection)
#endif // !defined(OO_BUGGY_TEMPLATES)
					            {
  public:
    ooShortRefStructor(ooHashSetShortRef)();
    ooShortRefStructor(ooHashSetShortRef)(const ooShortRef(ooHashSetShortRef)& shortId);
    ooShortRefStructor(ooHashSetShortRef)(const ooRef(ooHashSetShortRef)& id);
    ooShortRefStructor(ooHashSetShortRef)(const ooHandleSuper(ooHashSetShortRef) &objH);
    ooShortRefStructor(ooHashSetShortRef)(const ooHashSetShortRef *  fromObject);
    ooShortRef(ooHashSetShortRef)& operator=(const ooShortRef(ooHashSetShortRef)& shortId);
    ooShortRef(ooHashSetShortRef)& operator=(const ooRef(ooHashSetShortRef)& id);
    ooShortRef(ooHashSetShortRef)& operator=(const ooHandleSuper(ooHashSetShortRef) &objH);
    ooShortRef(ooHashSetShortRef)& operator=(const ooHashSetShortRef *  fromObject);
};

ooTemplateSpecialization
class ooHandle(ooHashSetShortRef) :
#ifdef OO_BUGGY_TEMPLATES
		      public ooHandle_superclass<ooHashSetShortRef >
#else // !defined(OO_BUGGY_TEMPLATES)
		      public ooHandle(ooHashBasedCollection)
#endif // !defined(OO_BUGGY_TEMPLATES)
                                                {
  public:
    inline ooHandleStructor(ooHashSetShortRef)();
    inline ooHandleStructor(ooHashSetShortRef)(const ooRef(ooHashSetShortRef)& id);
    inline ooHandleStructor(ooHashSetShortRef)(const ooHandle(ooHashSetShortRef)& objH);
    inline ooHandleStructor(ooHashSetShortRef)(const ooHashSetShortRef *  fromObject);
    inline ooHandle(ooHashSetShortRef)& operator=(const ooRef(ooHashSetShortRef)& id);
    inline ooHandle(ooHashSetShortRef)& operator=(const ooHandle(ooHashSetShortRef)& objH);
    inline ooHandle(ooHashSetShortRef)& operator=(const ooShortRef(ooHashSetShortRef)& shortId);
    inline ooHandle(ooHashSetShortRef)& operator=(const ooHashSetShortRef *  fromObject);
    ooStatus lookupObj(const ooHandle(ooObj)& scopeH,
		       const ooKey& key,
		       ooMode openMode = oocRead);
    ooStatus lookupObj(const ooHandle(ooObj)& scopeH,
		       const char* name,
		       ooMode openMode = oocRead);
    ooHandle(ooHashSetShortRef)& copy(const ooHandle(ooObj)& nearH,
		       ooHandle(ooHashSetShortRef)& result) const;
    inline ooRef(ooHashSetShortRef)& copy(const ooHandle(ooObj)& nearH,
		    ooRef(ooHashSetShortRef)& result) const;
    ooHandle(ooHashSetShortRef) copy(const ooHandle(ooObj)& nearH) const;
    inline ooHashSetShortRef *pin(ooMode openMode = oocRead) const;
    inline ooHashSetShortRef *operator->() const;
    inline ooHashSetShortRef &operator*() const;
    inline operator ooHashSetShortRef *() const;
    /* Use "operator ooHashSetShortRef *" instead of vm. */
    /* OBSOLETE */ inline ooHashSetShortRef *vm() const;
    // ODMG methods:
    ooHandleStructor(ooHashSetShortRef)(const d_Ref_Any &from);
    ooHashSetShortRef *ptr() const;
};

ooTemplateSpecialization
class ooItr(ooHashSetShortRef) : public ooHandle(ooHashSetShortRef),
		    public ooIteratorObjOrContObj {
  public:
    ooItrStructor(ooHashSetShortRef)();
    ~ooItrStructor(ooHashSetShortRef)();
  private:
    // Defined only to prevent implicit definition:
    ooItrStructor(ooHashSetShortRef)(ooItr(ooHashSetShortRef)&);
    ooItr(ooHashSetShortRef)    operator=(ooItr(ooHashSetShortRef)&);
};


/* methods on ooDeref(ooHashSetShortRef) */
inline
ooDeref(ooHashSetShortRef)::ooDerefStructor(ooHashSetShortRef)(ooDeref(ooHashSetShortRef) &  deref) :
    ooDerefBase(deref.vm())
{
  this->pinCompensate();
}
inline
ooDeref(ooHashSetShortRef)::ooDerefStructor(ooHashSetShortRef)(ooObj *  fromObject) :
    ooDerefBase(fromObject)
{
}
inline
ooDeref(ooHashSetShortRef)::~ooDerefStructor(ooHashSetShortRef)()
{
}
inline
ooHashSetShortRef *
ooDeref(ooHashSetShortRef)::operator->() const
{
  return ooReinterpretCast(ooHashSetShortRef *, this->vm());
}


/* methods on ooRef(ooHashSetShortRef) */
inline
ooRef(ooHashSetShortRef)::ooRefStructor(ooHashSetShortRef)(const ooHandleSuper(ooHashSetShortRef)& objH) :
    ooRef(ooHashBasedCollection)(objH)
{
}
inline
ooRef(ooHashSetShortRef)::ooRefStructor(ooHashSetShortRef)(const ooHashSetShortRef *  fromObject) :
    ooRef(ooHashBasedCollection)(ooReinterpretCast(const ooHashBasedCollection *, fromObject))
{
}
inline
ooRef(ooHashSetShortRef)&
ooRef(ooHashSetShortRef)::operator=(const ooRef(ooHashSetShortRef) &  id)
{
  this->ooId::operator=(id);
  return *this;
}
inline
ooRef(ooHashSetShortRef)&
ooRef(ooHashSetShortRef)::operator=(const ooShortRefSuper(ooHashSetShortRef) &  shortId)
{
  this->ooRef(ooObj)::operator=(shortId);
  return *this;
}
inline
ooRef(ooHashSetShortRef)&
ooRef(ooHashSetShortRef)::operator=(const ooHandleSuper(ooHashSetShortRef) &  objH)
{
  this->ooRef(ooObj)::operator=(objH);
  return *this;
}
inline
ooRef(ooHashSetShortRef)&
ooRef(ooHashSetShortRef)::operator=(const ooHashSetShortRef *  fromObject)
{
  this->ooRef(ooObj)::operator=(ooReinterpretCast(const ooObj *, fromObject));
  return *this;
}
inline
ooHashSetShortRef *
ooRef(ooHashSetShortRef)::pin(ooMode  openMode) const
{
  return ooReinterpretCast(ooHashSetShortRef *, this->pin_ref_internal(openMode));
}
inline
ooHashSetShortRef *
ooRef(ooHashSetShortRef)::vm(ooMode  openMode) const
{
  return this->pin(openMode);
}
#ifndef OO_BUGGY_TEMPLATES
inline
ooHandle(ooHashSetShortRef) &
ooRef(ooHashSetShortRef)::copy(const ooHandle(ooObj) &  nearH,
		ooHandle(ooHashSetShortRef) &           result) const
{
  this->ooRef(ooObj)::copy(nearH, result);
  return result;
}
inline
ooRef(ooHashSetShortRef) &
ooRef(ooHashSetShortRef)::copy(const ooHandle(ooObj) &  nearH,
		ooRef(ooHashSetShortRef) &              newObjRef) const
{
  this->ooRef(ooObj)::copy(nearH, newObjRef);
  return newObjRef;
}
inline
ooHandle(ooHashSetShortRef)
ooRef(ooHashSetShortRef)::copy(const ooHandle(ooObj) &  nearH) const
{
  ooHandle(ooHashSetShortRef) result;
  this->ooRef(ooObj)::copy(nearH, result);
  return result;
}
#endif // !defined(OO_BUGGY_TEMPLATES)
inline
ooDeref(ooHashSetShortRef)
ooRef(ooHashSetShortRef)::operator->() const
{
  ooDeref(ooHashSetShortRef) result(this->pin_ref_internal(oocRead));
  return result;
}


/* methods on ooShortRef(ooHashSetShortRef) */
inline
ooShortRef(ooHashSetShortRef) &
ooShortRef(ooHashSetShortRef)::operator=(const ooShortRef(ooHashSetShortRef) &  shortId)
{
  this->ooShortId::operator=(shortId);
  return *this;
}
inline
ooShortRef(ooHashSetShortRef) &
ooShortRef(ooHashSetShortRef)::operator=(const ooRef(ooHashSetShortRef) &  id)
{
  this->ooShortId::operator=(id);
  return *this;
}
inline
ooShortRef(ooHashSetShortRef) &
ooShortRef(ooHashSetShortRef)::operator=(const ooHandleSuper(ooHashSetShortRef) &  objH)
{
  this->ooShortId::operator=(objH);
  return *this;
}
inline
ooShortRef(ooHashSetShortRef)&
ooShortRef(ooHashSetShortRef)::operator=(const ooHashSetShortRef *  fromObject)
{
  this->ooShortId::operator=(ooReinterpretCast(const ooObj *,fromObject));
  return *this;
}
inline
ooShortRef(ooHashSetShortRef)::ooShortRefStructor(ooHashSetShortRef)()
{
}
#ifdef OO_BUGGY_TEMPLATES
inline
ooShortRef(ooHashSetShortRef)::ooShortRefStructor(ooHashSetShortRef)(const ooShortRef(ooHashSetShortRef) &  shortId)
{
  *this = shortId;
}
#else // !defined(OO_BUGGY_TEMPLATES)
inline
ooShortRef(ooHashSetShortRef)::ooShortRefStructor(ooHashSetShortRef)(const ooShortRef(ooHashSetShortRef) &  shortId) :
    ooShortRef(ooHashBasedCollection)(shortId)
{
}
#endif // !defined(OO_BUGGY_TEMPLATES)
#ifdef OO_BUGGY_TEMPLATES
inline
ooShortRef(ooHashSetShortRef)::ooShortRefStructor(ooHashSetShortRef)(const ooRef(ooHashSetShortRef) &  id)
{
  *this = id;
}
#else // !defined(OO_BUGGY_TEMPLATES)
inline
ooShortRef(ooHashSetShortRef)::ooShortRefStructor(ooHashSetShortRef)(const ooRef(ooHashSetShortRef) &  id) :
    ooShortRef(ooHashBasedCollection)(id)
{
}
#endif // !defined(OO_BUGGY_TEMPLATES)
#ifdef OO_BUGGY_TEMPLATES
inline
ooShortRef(ooHashSetShortRef)::ooShortRefStructor(ooHashSetShortRef)(const ooHandleSuper(ooHashSetShortRef) &  objH)
{
  *this = objH;
}
#else // !defined(OO_BUGGY_TEMPLATES)
inline
ooShortRef(ooHashSetShortRef)::ooShortRefStructor(ooHashSetShortRef)(const ooHandleSuper(ooHashSetShortRef) &  objH) :
    ooShortRef(ooHashBasedCollection)(objH)
{
}
#endif // !defined(OO_BUGGY_TEMPLATES)
#ifdef OO_BUGGY_TEMPLATES
inline
ooShortRef(ooHashSetShortRef)::ooShortRefStructor(ooHashSetShortRef)(const ooHashSetShortRef *  fromObject)
{
  *this = fromObject;
}
#else // !defined(OO_BUGGY_TEMPLATES)
inline
ooShortRef(ooHashSetShortRef)::ooShortRefStructor(ooHashSetShortRef)(const ooHashSetShortRef *  fromObject) :
    ooShortRef(ooHashBasedCollection)(ooReinterpretCast(const ooHashBasedCollection *,fromObject))
{
}
#endif // !defined(OO_BUGGY_TEMPLATES)


/* methods on ooHandle(ooHashSetShortRef) */
inline
ooHandle(ooHashSetShortRef)::ooHandleStructor(ooHashSetShortRef)()
{
}
inline
ooHandle(ooHashSetShortRef)::ooHandleStructor(ooHashSetShortRef)(const ooHandle(ooHashSetShortRef) &  objH) :
#ifdef OO_BUGGY_TEMPLATES
    ooHandle_superclass<ooHashSetShortRef >(objH)
#else // !defined(OO_BUGGY_TEMPLATES)
    ooHandle(ooHashBasedCollection)(objH)
#endif // !defined(OO_BUGGY_TEMPLATES)
{
}
inline
ooHandle(ooHashSetShortRef)::ooHandleStructor(ooHashSetShortRef)(const ooRef(ooHashSetShortRef) &  id) :
#ifdef OO_BUGGY_TEMPLATES
    ooHandle_superclass<ooHashSetShortRef >(id)
#else // !defined(OO_BUGGY_TEMPLATES)
    ooHandle(ooHashBasedCollection)(id)
#endif // !defined(OO_BUGGY_TEMPLATES)
{
}
inline
ooHandle(ooHashSetShortRef)::ooHandleStructor(ooHashSetShortRef)(const ooHashSetShortRef *  fromObject) :
#ifdef OO_BUGGY_TEMPLATES
    ooHandle_superclass<ooHashSetShortRef >(ooReinterpretCast(const ooHashBasedCollection *,fromObject))
#else // !defined(OO_BUGGY_TEMPLATES)
    ooHandle(ooHashBasedCollection)(ooReinterpretCast(const ooHashBasedCollection *,fromObject))
#endif // !defined(OO_BUGGY_TEMPLATES)
{
}
inline
ooHandle(ooHashSetShortRef)&
ooHandle(ooHashSetShortRef)::operator=(const ooRef(ooHashSetShortRef) &  id)
{
  this->ooHandle(ooObj)::operator=(id);
  return *this;
}
inline
ooHandle(ooHashSetShortRef)&
ooHandle(ooHashSetShortRef)::operator=(const ooHandle(ooHashSetShortRef) &  objH)
{
  this->ooHandle(ooObj)::operator=(objH);
  return *this;
}
inline
ooHandle(ooHashSetShortRef)&
ooHandle(ooHashSetShortRef)::operator=(const ooShortRef(ooHashSetShortRef) &  shortId)
{
  this->ooHandle(ooObj)::operator=(shortId);
  return *this;
}
inline
ooHandle(ooHashSetShortRef)&
ooHandle(ooHashSetShortRef)::operator=(const ooHashSetShortRef *  fromObject)
{
  this->ooHandle(ooObj)::operator=(ooReinterpretCast(const ooObj *,fromObject));
  return *this;
}
inline
ooHashSetShortRef *
ooHandle(ooHashSetShortRef)::pin(ooMode  openMode) const
{
  return ooReinterpretCast(ooHashSetShortRef *, this->pin_obj_internal(openMode));
}
inline
ooHashSetShortRef *
ooHandle(ooHashSetShortRef)::operator->() const
{
  return this->vm();
}
inline
ooHashSetShortRef &
ooHandle(ooHashSetShortRef)::operator*() const
{
  return *(this->vm());
}
inline
ooHandle(ooHashSetShortRef)::operator ooHashSetShortRef *() const
{
  if ( _state == oocHandlePTR  )
    return ooReinterpretCast(ooHashSetShortRef *, _ptr._obj);
  else return ooReinterpretCast(ooHashSetShortRef *, this->get_vm());
}
inline
ooHashSetShortRef *
ooHandle(ooHashSetShortRef)::vm() const
{
  if ( _state == oocHandlePTR && _ptr._obj != NULL )
    return ooReinterpretCast(ooHashSetShortRef *, _ptr._obj);
  else return ooReinterpretCast(ooHashSetShortRef *, this->get_vm());
}
inline
ooRef(ooHashSetShortRef) &
ooHandle(ooHashSetShortRef)::copy(const ooHandle(ooObj) &  nearH,
		   ooRef(ooHashSetShortRef) &              result) const
{
  this->ooHandle(ooObj)::copy(nearH, result);
  return result;
}


/* ODMG methods */
inline
ooHashSetShortRef *
ooRef(ooHashSetShortRef)::ptr() const
{
  return this->pin();
}
inline
ooHashSetShortRef *
ooHandle(ooHashSetShortRef)::ptr() const
{
  return this->operator ooHashSetShortRef *();
}
class ooHashMapX;


/////////////////////////////////////////////////////////////////////////////

ooTemplateSpecialization
class ooDeref(ooHashMapX) : public ooDerefBase {
	friend class ooRef(ooHashMapX);
  public:
    ~ooDerefStructor(ooHashMapX)();
    inline ooHashMapX *operator->() const;
#ifndef OO_BUGGY_TEMPLATES
  private:
#endif // !defined(OO_BUGGY_TEMPLATES)
    ooDerefStructor(ooHashMapX)(ooDeref(ooHashMapX)& deref);
    ooDerefStructor(ooHashMapX)(ooObj *  fromObject);
};


#ifdef OO_BUGGY_TEMPLATES

class ooHandle_superclass<ooHashMapX > : public ooHandle(ooHashBasedCollection) {
 protected:
  ooHandle_superclass()
    {}
  ooHandle_superclass(const ooHandle(ooHashBasedCollection) &  from) :
      ooHandle(ooHashBasedCollection)(from)
    {}
  ooHandle_superclass(const ooRef(ooHashBasedCollection) &  from) :
      ooHandle(ooHashBasedCollection)(from)
    {}
  ooHandle_superclass(const ooHashBasedCollection *  from) :
      ooHandle(ooHashBasedCollection)(from)
    {}
  ~ooHandle_superclass()
    {}
};

class ooShortRef_superclass<ooHashMapX > : public ooShortRef(ooHashBasedCollection) {
};

#endif // OO_BUGGY_TEMPLATES

ooTemplateSpecialization
class ooRef(ooHashMapX) : public ooRef(ooHashBasedCollection) {
  public:
    ooRefStructor(ooHashMapX)()
      {}
    ooRefStructor(ooHashMapX)(const ooRef(ooHashMapX)& id) :
	  ooRef(ooHashBasedCollection)(id)
      {}
    inline ooRefStructor(ooHashMapX)(const ooHandleSuper(ooHashMapX)& objH);
    inline ooRefStructor(ooHashMapX)(const ooHashMapX *  fromObject);
    inline ooRef(ooHashMapX)& operator=(const ooRef(ooHashMapX)& id);
    inline ooRef(ooHashMapX)& operator=(const ooShortRefSuper(ooHashMapX) &shortId);
    inline ooRef(ooHashMapX)& operator=(const ooHandleSuper(ooHashMapX)& objH);
    inline ooRef(ooHashMapX)& operator=(const ooHashMapX *  fromObject);
    ooStatus lookupObj(const ooHandle(ooObj)& scopeH,
		       const ooKey& key,
		       ooMode openMode = oocRead);
    ooStatus lookupObj(const ooHandle(ooObj)& scopeH,
		       const char* name,
		       ooMode openMode = oocRead);
#ifndef OO_BUGGY_TEMPLATES
    inline ooRef(ooHashMapX)& copy(const ooHandle(ooObj)& nearH,
		    ooRef(ooHashMapX)& newObjRef) const;
    inline ooHandle(ooHashMapX)& copy(const ooHandle(ooObj)& nearH,
			ooHandle(ooHashMapX)& result) const;
    inline ooHandle(ooHashMapX) copy(const ooHandle(ooObj)& nearH) const;
#endif // !defined(OO_BUGGY_TEMPLATES)
    inline ooHashMapX *pin(ooMode openMode = oocRead) const;
    ooDeref(ooHashMapX) operator->() const;
    /* Use pin() or use ooHandle "operator ooHashMapX *" instead of vm. */
    /* OBSOLETE */ inline ooHashMapX *vm(ooMode openMode = oocRead) const;
    // ODMG methods:
    ooRefStructor(ooHashMapX)(const d_Ref_Any &from);
    ooHashMapX *ptr() const;
};

ooTemplateSpecialization
class ooShortRef(ooHashMapX) :
#ifdef OO_BUGGY_TEMPLATES
			public ooShortRef_superclass<ooHashMapX >
#else // !defined(OO_BUGGY_TEMPLATES)
			public ooShortRef(ooHashBasedCollection)
#endif // !defined(OO_BUGGY_TEMPLATES)
					            {
  public:
    ooShortRefStructor(ooHashMapX)();
    ooShortRefStructor(ooHashMapX)(const ooShortRef(ooHashMapX)& shortId);
    ooShortRefStructor(ooHashMapX)(const ooRef(ooHashMapX)& id);
    ooShortRefStructor(ooHashMapX)(const ooHandleSuper(ooHashMapX) &objH);
    ooShortRefStructor(ooHashMapX)(const ooHashMapX *  fromObject);
    ooShortRef(ooHashMapX)& operator=(const ooShortRef(ooHashMapX)& shortId);
    ooShortRef(ooHashMapX)& operator=(const ooRef(ooHashMapX)& id);
    ooShortRef(ooHashMapX)& operator=(const ooHandleSuper(ooHashMapX) &objH);
    ooShortRef(ooHashMapX)& operator=(const ooHashMapX *  fromObject);
};

ooTemplateSpecialization
class ooHandle(ooHashMapX) :
#ifdef OO_BUGGY_TEMPLATES
		      public ooHandle_superclass<ooHashMapX >
#else // !defined(OO_BUGGY_TEMPLATES)
		      public ooHandle(ooHashBasedCollection)
#endif // !defined(OO_BUGGY_TEMPLATES)
                                                {
  public:
    inline ooHandleStructor(ooHashMapX)();
    inline ooHandleStructor(ooHashMapX)(const ooRef(ooHashMapX)& id);
    inline ooHandleStructor(ooHashMapX)(const ooHandle(ooHashMapX)& objH);
    inline ooHandleStructor(ooHashMapX)(const ooHashMapX *  fromObject);
    inline ooHandle(ooHashMapX)& operator=(const ooRef(ooHashMapX)& id);
    inline ooHandle(ooHashMapX)& operator=(const ooHandle(ooHashMapX)& objH);
    inline ooHandle(ooHashMapX)& operator=(const ooShortRef(ooHashMapX)& shortId);
    inline ooHandle(ooHashMapX)& operator=(const ooHashMapX *  fromObject);
    ooStatus lookupObj(const ooHandle(ooObj)& scopeH,
		       const ooKey& key,
		       ooMode openMode = oocRead);
    ooStatus lookupObj(const ooHandle(ooObj)& scopeH,
		       const char* name,
		       ooMode openMode = oocRead);
    ooHandle(ooHashMapX)& copy(const ooHandle(ooObj)& nearH,
		       ooHandle(ooHashMapX)& result) const;
    inline ooRef(ooHashMapX)& copy(const ooHandle(ooObj)& nearH,
		    ooRef(ooHashMapX)& result) const;
    ooHandle(ooHashMapX) copy(const ooHandle(ooObj)& nearH) const;
    inline ooHashMapX *pin(ooMode openMode = oocRead) const;
    inline ooHashMapX *operator->() const;
    inline ooHashMapX &operator*() const;
    inline operator ooHashMapX *() const;
    /* Use "operator ooHashMapX *" instead of vm. */
    /* OBSOLETE */ inline ooHashMapX *vm() const;
    // ODMG methods:
    ooHandleStructor(ooHashMapX)(const d_Ref_Any &from);
    ooHashMapX *ptr() const;
};

ooTemplateSpecialization
class ooItr(ooHashMapX) : public ooHandle(ooHashMapX),
		    public ooIteratorObjOrContObj {
  public:
    ooItrStructor(ooHashMapX)();
    ~ooItrStructor(ooHashMapX)();
  private:
    // Defined only to prevent implicit definition:
    ooItrStructor(ooHashMapX)(ooItr(ooHashMapX)&);
    ooItr(ooHashMapX)    operator=(ooItr(ooHashMapX)&);
};


/* methods on ooDeref(ooHashMapX) */
inline
ooDeref(ooHashMapX)::ooDerefStructor(ooHashMapX)(ooDeref(ooHashMapX) &  deref) :
    ooDerefBase(deref.vm())
{
  this->pinCompensate();
}
inline
ooDeref(ooHashMapX)::ooDerefStructor(ooHashMapX)(ooObj *  fromObject) :
    ooDerefBase(fromObject)
{
}
inline
ooDeref(ooHashMapX)::~ooDerefStructor(ooHashMapX)()
{
}
inline
ooHashMapX *
ooDeref(ooHashMapX)::operator->() const
{
  return ooReinterpretCast(ooHashMapX *, this->vm());
}


/* methods on ooRef(ooHashMapX) */
inline
ooRef(ooHashMapX)::ooRefStructor(ooHashMapX)(const ooHandleSuper(ooHashMapX)& objH) :
    ooRef(ooHashBasedCollection)(objH)
{
}
inline
ooRef(ooHashMapX)::ooRefStructor(ooHashMapX)(const ooHashMapX *  fromObject) :
    ooRef(ooHashBasedCollection)(ooReinterpretCast(const ooHashBasedCollection *, fromObject))
{
}
inline
ooRef(ooHashMapX)&
ooRef(ooHashMapX)::operator=(const ooRef(ooHashMapX) &  id)
{
  this->ooId::operator=(id);
  return *this;
}
inline
ooRef(ooHashMapX)&
ooRef(ooHashMapX)::operator=(const ooShortRefSuper(ooHashMapX) &  shortId)
{
  this->ooRef(ooObj)::operator=(shortId);
  return *this;
}
inline
ooRef(ooHashMapX)&
ooRef(ooHashMapX)::operator=(const ooHandleSuper(ooHashMapX) &  objH)
{
  this->ooRef(ooObj)::operator=(objH);
  return *this;
}
inline
ooRef(ooHashMapX)&
ooRef(ooHashMapX)::operator=(const ooHashMapX *  fromObject)
{
  this->ooRef(ooObj)::operator=(ooReinterpretCast(const ooObj *, fromObject));
  return *this;
}
inline
ooHashMapX *
ooRef(ooHashMapX)::pin(ooMode  openMode) const
{
  return ooReinterpretCast(ooHashMapX *, this->pin_ref_internal(openMode));
}
inline
ooHashMapX *
ooRef(ooHashMapX)::vm(ooMode  openMode) const
{
  return this->pin(openMode);
}
#ifndef OO_BUGGY_TEMPLATES
inline
ooHandle(ooHashMapX) &
ooRef(ooHashMapX)::copy(const ooHandle(ooObj) &  nearH,
		ooHandle(ooHashMapX) &           result) const
{
  this->ooRef(ooObj)::copy(nearH, result);
  return result;
}
inline
ooRef(ooHashMapX) &
ooRef(ooHashMapX)::copy(const ooHandle(ooObj) &  nearH,
		ooRef(ooHashMapX) &              newObjRef) const
{
  this->ooRef(ooObj)::copy(nearH, newObjRef);
  return newObjRef;
}
inline
ooHandle(ooHashMapX)
ooRef(ooHashMapX)::copy(const ooHandle(ooObj) &  nearH) const
{
  ooHandle(ooHashMapX) result;
  this->ooRef(ooObj)::copy(nearH, result);
  return result;
}
#endif // !defined(OO_BUGGY_TEMPLATES)
inline
ooDeref(ooHashMapX)
ooRef(ooHashMapX)::operator->() const
{
  ooDeref(ooHashMapX) result(this->pin_ref_internal(oocRead));
  return result;
}


/* methods on ooShortRef(ooHashMapX) */
inline
ooShortRef(ooHashMapX) &
ooShortRef(ooHashMapX)::operator=(const ooShortRef(ooHashMapX) &  shortId)
{
  this->ooShortId::operator=(shortId);
  return *this;
}
inline
ooShortRef(ooHashMapX) &
ooShortRef(ooHashMapX)::operator=(const ooRef(ooHashMapX) &  id)
{
  this->ooShortId::operator=(id);
  return *this;
}
inline
ooShortRef(ooHashMapX) &
ooShortRef(ooHashMapX)::operator=(const ooHandleSuper(ooHashMapX) &  objH)
{
  this->ooShortId::operator=(objH);
  return *this;
}
inline
ooShortRef(ooHashMapX)&
ooShortRef(ooHashMapX)::operator=(const ooHashMapX *  fromObject)
{
  this->ooShortId::operator=(ooReinterpretCast(const ooObj *,fromObject));
  return *this;
}
inline
ooShortRef(ooHashMapX)::ooShortRefStructor(ooHashMapX)()
{
}
#ifdef OO_BUGGY_TEMPLATES
inline
ooShortRef(ooHashMapX)::ooShortRefStructor(ooHashMapX)(const ooShortRef(ooHashMapX) &  shortId)
{
  *this = shortId;
}
#else // !defined(OO_BUGGY_TEMPLATES)
inline
ooShortRef(ooHashMapX)::ooShortRefStructor(ooHashMapX)(const ooShortRef(ooHashMapX) &  shortId) :
    ooShortRef(ooHashBasedCollection)(shortId)
{
}
#endif // !defined(OO_BUGGY_TEMPLATES)
#ifdef OO_BUGGY_TEMPLATES
inline
ooShortRef(ooHashMapX)::ooShortRefStructor(ooHashMapX)(const ooRef(ooHashMapX) &  id)
{
  *this = id;
}
#else // !defined(OO_BUGGY_TEMPLATES)
inline
ooShortRef(ooHashMapX)::ooShortRefStructor(ooHashMapX)(const ooRef(ooHashMapX) &  id) :
    ooShortRef(ooHashBasedCollection)(id)
{
}
#endif // !defined(OO_BUGGY_TEMPLATES)
#ifdef OO_BUGGY_TEMPLATES
inline
ooShortRef(ooHashMapX)::ooShortRefStructor(ooHashMapX)(const ooHandleSuper(ooHashMapX) &  objH)
{
  *this = objH;
}
#else // !defined(OO_BUGGY_TEMPLATES)
inline
ooShortRef(ooHashMapX)::ooShortRefStructor(ooHashMapX)(const ooHandleSuper(ooHashMapX) &  objH) :
    ooShortRef(ooHashBasedCollection)(objH)
{
}
#endif // !defined(OO_BUGGY_TEMPLATES)
#ifdef OO_BUGGY_TEMPLATES
inline
ooShortRef(ooHashMapX)::ooShortRefStructor(ooHashMapX)(const ooHashMapX *  fromObject)
{
  *this = fromObject;
}
#else // !defined(OO_BUGGY_TEMPLATES)
inline
ooShortRef(ooHashMapX)::ooShortRefStructor(ooHashMapX)(const ooHashMapX *  fromObject) :
    ooShortRef(ooHashBasedCollection)(ooReinterpretCast(const ooHashBasedCollection *,fromObject))
{
}
#endif // !defined(OO_BUGGY_TEMPLATES)


/* methods on ooHandle(ooHashMapX) */
inline
ooHandle(ooHashMapX)::ooHandleStructor(ooHashMapX)()
{
}
inline
ooHandle(ooHashMapX)::ooHandleStructor(ooHashMapX)(const ooHandle(ooHashMapX) &  objH) :
#ifdef OO_BUGGY_TEMPLATES
    ooHandle_superclass<ooHashMapX >(objH)
#else // !defined(OO_BUGGY_TEMPLATES)
    ooHandle(ooHashBasedCollection)(objH)
#endif // !defined(OO_BUGGY_TEMPLATES)
{
}
inline
ooHandle(ooHashMapX)::ooHandleStructor(ooHashMapX)(const ooRef(ooHashMapX) &  id) :
#ifdef OO_BUGGY_TEMPLATES
    ooHandle_superclass<ooHashMapX >(id)
#else // !defined(OO_BUGGY_TEMPLATES)
    ooHandle(ooHashBasedCollection)(id)
#endif // !defined(OO_BUGGY_TEMPLATES)
{
}
inline
ooHandle(ooHashMapX)::ooHandleStructor(ooHashMapX)(const ooHashMapX *  fromObject) :
#ifdef OO_BUGGY_TEMPLATES
    ooHandle_superclass<ooHashMapX >(ooReinterpretCast(const ooHashBasedCollection *,fromObject))
#else // !defined(OO_BUGGY_TEMPLATES)
    ooHandle(ooHashBasedCollection)(ooReinterpretCast(const ooHashBasedCollection *,fromObject))
#endif // !defined(OO_BUGGY_TEMPLATES)
{
}
inline
ooHandle(ooHashMapX)&
ooHandle(ooHashMapX)::operator=(const ooRef(ooHashMapX) &  id)
{
  this->ooHandle(ooObj)::operator=(id);
  return *this;
}
inline
ooHandle(ooHashMapX)&
ooHandle(ooHashMapX)::operator=(const ooHandle(ooHashMapX) &  objH)
{
  this->ooHandle(ooObj)::operator=(objH);
  return *this;
}
inline
ooHandle(ooHashMapX)&
ooHandle(ooHashMapX)::operator=(const ooShortRef(ooHashMapX) &  shortId)
{
  this->ooHandle(ooObj)::operator=(shortId);
  return *this;
}
inline
ooHandle(ooHashMapX)&
ooHandle(ooHashMapX)::operator=(const ooHashMapX *  fromObject)
{
  this->ooHandle(ooObj)::operator=(ooReinterpretCast(const ooObj *,fromObject));
  return *this;
}
inline
ooHashMapX *
ooHandle(ooHashMapX)::pin(ooMode  openMode) const
{
  return ooReinterpretCast(ooHashMapX *, this->pin_obj_internal(openMode));
}
inline
ooHashMapX *
ooHandle(ooHashMapX)::operator->() const
{
  return this->vm();
}
inline
ooHashMapX &
ooHandle(ooHashMapX)::operator*() const
{
  return *(this->vm());
}
inline
ooHandle(ooHashMapX)::operator ooHashMapX *() const
{
  if ( _state == oocHandlePTR  )
    return ooReinterpretCast(ooHashMapX *, _ptr._obj);
  else return ooReinterpretCast(ooHashMapX *, this->get_vm());
}
inline
ooHashMapX *
ooHandle(ooHashMapX)::vm() const
{
  if ( _state == oocHandlePTR && _ptr._obj != NULL )
    return ooReinterpretCast(ooHashMapX *, _ptr._obj);
  else return ooReinterpretCast(ooHashMapX *, this->get_vm());
}
inline
ooRef(ooHashMapX) &
ooHandle(ooHashMapX)::copy(const ooHandle(ooObj) &  nearH,
		   ooRef(ooHashMapX) &              result) const
{
  this->ooHandle(ooObj)::copy(nearH, result);
  return result;
}


/* ODMG methods */
inline
ooHashMapX *
ooRef(ooHashMapX)::ptr() const
{
  return this->pin();
}
inline
ooHashMapX *
ooHandle(ooHashMapX)::ptr() const
{
  return this->operator ooHashMapX *();
}
class ooTreeBasedCollection;


/////////////////////////////////////////////////////////////////////////////

ooTemplateSpecialization
class ooDeref(ooTreeBasedCollection) : public ooDerefBase {
	friend class ooRef(ooTreeBasedCollection);
  public:
    ~ooDerefStructor(ooTreeBasedCollection)();
    inline ooTreeBasedCollection *operator->() const;
#ifndef OO_BUGGY_TEMPLATES
  private:
#endif // !defined(OO_BUGGY_TEMPLATES)
    ooDerefStructor(ooTreeBasedCollection)(ooDeref(ooTreeBasedCollection)& deref);
    ooDerefStructor(ooTreeBasedCollection)(ooObj *  fromObject);
};


#ifdef OO_BUGGY_TEMPLATES

class ooHandle_superclass<ooTreeBasedCollection > : public ooHandle(ooCollection) {
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

class ooShortRef_superclass<ooTreeBasedCollection > : public ooShortRef(ooCollection) {
};

#endif // OO_BUGGY_TEMPLATES

ooTemplateSpecialization
class ooRef(ooTreeBasedCollection) : public ooRef(ooCollection) {
  public:
    ooRefStructor(ooTreeBasedCollection)()
      {}
    ooRefStructor(ooTreeBasedCollection)(const ooRef(ooTreeBasedCollection)& id) :
	  ooRef(ooCollection)(id)
      {}
    inline ooRefStructor(ooTreeBasedCollection)(const ooHandleSuper(ooTreeBasedCollection)& objH);
    inline ooRefStructor(ooTreeBasedCollection)(const ooTreeBasedCollection *  fromObject);
    inline ooRef(ooTreeBasedCollection)& operator=(const ooRef(ooTreeBasedCollection)& id);
    inline ooRef(ooTreeBasedCollection)& operator=(const ooShortRefSuper(ooTreeBasedCollection) &shortId);
    inline ooRef(ooTreeBasedCollection)& operator=(const ooHandleSuper(ooTreeBasedCollection)& objH);
    inline ooRef(ooTreeBasedCollection)& operator=(const ooTreeBasedCollection *  fromObject);
    ooStatus lookupObj(const ooHandle(ooObj)& scopeH,
		       const ooKey& key,
		       ooMode openMode = oocRead);
    ooStatus lookupObj(const ooHandle(ooObj)& scopeH,
		       const char* name,
		       ooMode openMode = oocRead);
#ifndef OO_BUGGY_TEMPLATES
    inline ooRef(ooTreeBasedCollection)& copy(const ooHandle(ooObj)& nearH,
		    ooRef(ooTreeBasedCollection)& newObjRef) const;
    inline ooHandle(ooTreeBasedCollection)& copy(const ooHandle(ooObj)& nearH,
			ooHandle(ooTreeBasedCollection)& result) const;
    inline ooHandle(ooTreeBasedCollection) copy(const ooHandle(ooObj)& nearH) const;
#endif // !defined(OO_BUGGY_TEMPLATES)
    inline ooTreeBasedCollection *pin(ooMode openMode = oocRead) const;
    ooDeref(ooTreeBasedCollection) operator->() const;
    /* Use pin() or use ooHandle "operator ooTreeBasedCollection *" instead of vm. */
    /* OBSOLETE */ inline ooTreeBasedCollection *vm(ooMode openMode = oocRead) const;
    // ODMG methods:
    ooRefStructor(ooTreeBasedCollection)(const d_Ref_Any &from);
    ooTreeBasedCollection *ptr() const;
};

ooTemplateSpecialization
class ooShortRef(ooTreeBasedCollection) :
#ifdef OO_BUGGY_TEMPLATES
			public ooShortRef_superclass<ooTreeBasedCollection >
#else // !defined(OO_BUGGY_TEMPLATES)
			public ooShortRef(ooCollection)
#endif // !defined(OO_BUGGY_TEMPLATES)
					            {
  public:
    ooShortRefStructor(ooTreeBasedCollection)();
    ooShortRefStructor(ooTreeBasedCollection)(const ooShortRef(ooTreeBasedCollection)& shortId);
    ooShortRefStructor(ooTreeBasedCollection)(const ooRef(ooTreeBasedCollection)& id);
    ooShortRefStructor(ooTreeBasedCollection)(const ooHandleSuper(ooTreeBasedCollection) &objH);
    ooShortRefStructor(ooTreeBasedCollection)(const ooTreeBasedCollection *  fromObject);
    ooShortRef(ooTreeBasedCollection)& operator=(const ooShortRef(ooTreeBasedCollection)& shortId);
    ooShortRef(ooTreeBasedCollection)& operator=(const ooRef(ooTreeBasedCollection)& id);
    ooShortRef(ooTreeBasedCollection)& operator=(const ooHandleSuper(ooTreeBasedCollection) &objH);
    ooShortRef(ooTreeBasedCollection)& operator=(const ooTreeBasedCollection *  fromObject);
};

ooTemplateSpecialization
class ooHandle(ooTreeBasedCollection) :
#ifdef OO_BUGGY_TEMPLATES
		      public ooHandle_superclass<ooTreeBasedCollection >
#else // !defined(OO_BUGGY_TEMPLATES)
		      public ooHandle(ooCollection)
#endif // !defined(OO_BUGGY_TEMPLATES)
                                                {
  public:
    inline ooHandleStructor(ooTreeBasedCollection)();
    inline ooHandleStructor(ooTreeBasedCollection)(const ooRef(ooTreeBasedCollection)& id);
    inline ooHandleStructor(ooTreeBasedCollection)(const ooHandle(ooTreeBasedCollection)& objH);
    inline ooHandleStructor(ooTreeBasedCollection)(const ooTreeBasedCollection *  fromObject);
    inline ooHandle(ooTreeBasedCollection)& operator=(const ooRef(ooTreeBasedCollection)& id);
    inline ooHandle(ooTreeBasedCollection)& operator=(const ooHandle(ooTreeBasedCollection)& objH);
    inline ooHandle(ooTreeBasedCollection)& operator=(const ooShortRef(ooTreeBasedCollection)& shortId);
    inline ooHandle(ooTreeBasedCollection)& operator=(const ooTreeBasedCollection *  fromObject);
    ooStatus lookupObj(const ooHandle(ooObj)& scopeH,
		       const ooKey& key,
		       ooMode openMode = oocRead);
    ooStatus lookupObj(const ooHandle(ooObj)& scopeH,
		       const char* name,
		       ooMode openMode = oocRead);
    ooHandle(ooTreeBasedCollection)& copy(const ooHandle(ooObj)& nearH,
		       ooHandle(ooTreeBasedCollection)& result) const;
    inline ooRef(ooTreeBasedCollection)& copy(const ooHandle(ooObj)& nearH,
		    ooRef(ooTreeBasedCollection)& result) const;
    ooHandle(ooTreeBasedCollection) copy(const ooHandle(ooObj)& nearH) const;
    inline ooTreeBasedCollection *pin(ooMode openMode = oocRead) const;
    inline ooTreeBasedCollection *operator->() const;
    inline ooTreeBasedCollection &operator*() const;
    inline operator ooTreeBasedCollection *() const;
    /* Use "operator ooTreeBasedCollection *" instead of vm. */
    /* OBSOLETE */ inline ooTreeBasedCollection *vm() const;
    // ODMG methods:
    ooHandleStructor(ooTreeBasedCollection)(const d_Ref_Any &from);
    ooTreeBasedCollection *ptr() const;
};

ooTemplateSpecialization
class ooItr(ooTreeBasedCollection) : public ooHandle(ooTreeBasedCollection),
		    public ooIteratorObjOrContObj {
  public:
    ooItrStructor(ooTreeBasedCollection)();
    ~ooItrStructor(ooTreeBasedCollection)();
  private:
    // Defined only to prevent implicit definition:
    ooItrStructor(ooTreeBasedCollection)(ooItr(ooTreeBasedCollection)&);
    ooItr(ooTreeBasedCollection)    operator=(ooItr(ooTreeBasedCollection)&);
};


/* methods on ooDeref(ooTreeBasedCollection) */
inline
ooDeref(ooTreeBasedCollection)::ooDerefStructor(ooTreeBasedCollection)(ooDeref(ooTreeBasedCollection) &  deref) :
    ooDerefBase(deref.vm())
{
  this->pinCompensate();
}
inline
ooDeref(ooTreeBasedCollection)::ooDerefStructor(ooTreeBasedCollection)(ooObj *  fromObject) :
    ooDerefBase(fromObject)
{
}
inline
ooDeref(ooTreeBasedCollection)::~ooDerefStructor(ooTreeBasedCollection)()
{
}
inline
ooTreeBasedCollection *
ooDeref(ooTreeBasedCollection)::operator->() const
{
  return ooReinterpretCast(ooTreeBasedCollection *, this->vm());
}


/* methods on ooRef(ooTreeBasedCollection) */
inline
ooRef(ooTreeBasedCollection)::ooRefStructor(ooTreeBasedCollection)(const ooHandleSuper(ooTreeBasedCollection)& objH) :
    ooRef(ooCollection)(objH)
{
}
inline
ooRef(ooTreeBasedCollection)::ooRefStructor(ooTreeBasedCollection)(const ooTreeBasedCollection *  fromObject) :
    ooRef(ooCollection)(ooReinterpretCast(const ooCollection *, fromObject))
{
}
inline
ooRef(ooTreeBasedCollection)&
ooRef(ooTreeBasedCollection)::operator=(const ooRef(ooTreeBasedCollection) &  id)
{
  this->ooId::operator=(id);
  return *this;
}
inline
ooRef(ooTreeBasedCollection)&
ooRef(ooTreeBasedCollection)::operator=(const ooShortRefSuper(ooTreeBasedCollection) &  shortId)
{
  this->ooRef(ooObj)::operator=(shortId);
  return *this;
}
inline
ooRef(ooTreeBasedCollection)&
ooRef(ooTreeBasedCollection)::operator=(const ooHandleSuper(ooTreeBasedCollection) &  objH)
{
  this->ooRef(ooObj)::operator=(objH);
  return *this;
}
inline
ooRef(ooTreeBasedCollection)&
ooRef(ooTreeBasedCollection)::operator=(const ooTreeBasedCollection *  fromObject)
{
  this->ooRef(ooObj)::operator=(ooReinterpretCast(const ooObj *, fromObject));
  return *this;
}
inline
ooTreeBasedCollection *
ooRef(ooTreeBasedCollection)::pin(ooMode  openMode) const
{
  return ooReinterpretCast(ooTreeBasedCollection *, this->pin_ref_internal(openMode));
}
inline
ooTreeBasedCollection *
ooRef(ooTreeBasedCollection)::vm(ooMode  openMode) const
{
  return this->pin(openMode);
}
#ifndef OO_BUGGY_TEMPLATES
inline
ooHandle(ooTreeBasedCollection) &
ooRef(ooTreeBasedCollection)::copy(const ooHandle(ooObj) &  nearH,
		ooHandle(ooTreeBasedCollection) &           result) const
{
  this->ooRef(ooObj)::copy(nearH, result);
  return result;
}
inline
ooRef(ooTreeBasedCollection) &
ooRef(ooTreeBasedCollection)::copy(const ooHandle(ooObj) &  nearH,
		ooRef(ooTreeBasedCollection) &              newObjRef) const
{
  this->ooRef(ooObj)::copy(nearH, newObjRef);
  return newObjRef;
}
inline
ooHandle(ooTreeBasedCollection)
ooRef(ooTreeBasedCollection)::copy(const ooHandle(ooObj) &  nearH) const
{
  ooHandle(ooTreeBasedCollection) result;
  this->ooRef(ooObj)::copy(nearH, result);
  return result;
}
#endif // !defined(OO_BUGGY_TEMPLATES)
inline
ooDeref(ooTreeBasedCollection)
ooRef(ooTreeBasedCollection)::operator->() const
{
  ooDeref(ooTreeBasedCollection) result(this->pin_ref_internal(oocRead));
  return result;
}


/* methods on ooShortRef(ooTreeBasedCollection) */
inline
ooShortRef(ooTreeBasedCollection) &
ooShortRef(ooTreeBasedCollection)::operator=(const ooShortRef(ooTreeBasedCollection) &  shortId)
{
  this->ooShortId::operator=(shortId);
  return *this;
}
inline
ooShortRef(ooTreeBasedCollection) &
ooShortRef(ooTreeBasedCollection)::operator=(const ooRef(ooTreeBasedCollection) &  id)
{
  this->ooShortId::operator=(id);
  return *this;
}
inline
ooShortRef(ooTreeBasedCollection) &
ooShortRef(ooTreeBasedCollection)::operator=(const ooHandleSuper(ooTreeBasedCollection) &  objH)
{
  this->ooShortId::operator=(objH);
  return *this;
}
inline
ooShortRef(ooTreeBasedCollection)&
ooShortRef(ooTreeBasedCollection)::operator=(const ooTreeBasedCollection *  fromObject)
{
  this->ooShortId::operator=(ooReinterpretCast(const ooObj *,fromObject));
  return *this;
}
inline
ooShortRef(ooTreeBasedCollection)::ooShortRefStructor(ooTreeBasedCollection)()
{
}
#ifdef OO_BUGGY_TEMPLATES
inline
ooShortRef(ooTreeBasedCollection)::ooShortRefStructor(ooTreeBasedCollection)(const ooShortRef(ooTreeBasedCollection) &  shortId)
{
  *this = shortId;
}
#else // !defined(OO_BUGGY_TEMPLATES)
inline
ooShortRef(ooTreeBasedCollection)::ooShortRefStructor(ooTreeBasedCollection)(const ooShortRef(ooTreeBasedCollection) &  shortId) :
    ooShortRef(ooCollection)(shortId)
{
}
#endif // !defined(OO_BUGGY_TEMPLATES)
#ifdef OO_BUGGY_TEMPLATES
inline
ooShortRef(ooTreeBasedCollection)::ooShortRefStructor(ooTreeBasedCollection)(const ooRef(ooTreeBasedCollection) &  id)
{
  *this = id;
}
#else // !defined(OO_BUGGY_TEMPLATES)
inline
ooShortRef(ooTreeBasedCollection)::ooShortRefStructor(ooTreeBasedCollection)(const ooRef(ooTreeBasedCollection) &  id) :
    ooShortRef(ooCollection)(id)
{
}
#endif // !defined(OO_BUGGY_TEMPLATES)
#ifdef OO_BUGGY_TEMPLATES
inline
ooShortRef(ooTreeBasedCollection)::ooShortRefStructor(ooTreeBasedCollection)(const ooHandleSuper(ooTreeBasedCollection) &  objH)
{
  *this = objH;
}
#else // !defined(OO_BUGGY_TEMPLATES)
inline
ooShortRef(ooTreeBasedCollection)::ooShortRefStructor(ooTreeBasedCollection)(const ooHandleSuper(ooTreeBasedCollection) &  objH) :
    ooShortRef(ooCollection)(objH)
{
}
#endif // !defined(OO_BUGGY_TEMPLATES)
#ifdef OO_BUGGY_TEMPLATES
inline
ooShortRef(ooTreeBasedCollection)::ooShortRefStructor(ooTreeBasedCollection)(const ooTreeBasedCollection *  fromObject)
{
  *this = fromObject;
}
#else // !defined(OO_BUGGY_TEMPLATES)
inline
ooShortRef(ooTreeBasedCollection)::ooShortRefStructor(ooTreeBasedCollection)(const ooTreeBasedCollection *  fromObject) :
    ooShortRef(ooCollection)(ooReinterpretCast(const ooCollection *,fromObject))
{
}
#endif // !defined(OO_BUGGY_TEMPLATES)


/* methods on ooHandle(ooTreeBasedCollection) */
inline
ooHandle(ooTreeBasedCollection)::ooHandleStructor(ooTreeBasedCollection)()
{
}
inline
ooHandle(ooTreeBasedCollection)::ooHandleStructor(ooTreeBasedCollection)(const ooHandle(ooTreeBasedCollection) &  objH) :
#ifdef OO_BUGGY_TEMPLATES
    ooHandle_superclass<ooTreeBasedCollection >(objH)
#else // !defined(OO_BUGGY_TEMPLATES)
    ooHandle(ooCollection)(objH)
#endif // !defined(OO_BUGGY_TEMPLATES)
{
}
inline
ooHandle(ooTreeBasedCollection)::ooHandleStructor(ooTreeBasedCollection)(const ooRef(ooTreeBasedCollection) &  id) :
#ifdef OO_BUGGY_TEMPLATES
    ooHandle_superclass<ooTreeBasedCollection >(id)
#else // !defined(OO_BUGGY_TEMPLATES)
    ooHandle(ooCollection)(id)
#endif // !defined(OO_BUGGY_TEMPLATES)
{
}
inline
ooHandle(ooTreeBasedCollection)::ooHandleStructor(ooTreeBasedCollection)(const ooTreeBasedCollection *  fromObject) :
#ifdef OO_BUGGY_TEMPLATES
    ooHandle_superclass<ooTreeBasedCollection >(ooReinterpretCast(const ooCollection *,fromObject))
#else // !defined(OO_BUGGY_TEMPLATES)
    ooHandle(ooCollection)(ooReinterpretCast(const ooCollection *,fromObject))
#endif // !defined(OO_BUGGY_TEMPLATES)
{
}
inline
ooHandle(ooTreeBasedCollection)&
ooHandle(ooTreeBasedCollection)::operator=(const ooRef(ooTreeBasedCollection) &  id)
{
  this->ooHandle(ooObj)::operator=(id);
  return *this;
}
inline
ooHandle(ooTreeBasedCollection)&
ooHandle(ooTreeBasedCollection)::operator=(const ooHandle(ooTreeBasedCollection) &  objH)
{
  this->ooHandle(ooObj)::operator=(objH);
  return *this;
}
inline
ooHandle(ooTreeBasedCollection)&
ooHandle(ooTreeBasedCollection)::operator=(const ooShortRef(ooTreeBasedCollection) &  shortId)
{
  this->ooHandle(ooObj)::operator=(shortId);
  return *this;
}
inline
ooHandle(ooTreeBasedCollection)&
ooHandle(ooTreeBasedCollection)::operator=(const ooTreeBasedCollection *  fromObject)
{
  this->ooHandle(ooObj)::operator=(ooReinterpretCast(const ooObj *,fromObject));
  return *this;
}
inline
ooTreeBasedCollection *
ooHandle(ooTreeBasedCollection)::pin(ooMode  openMode) const
{
  return ooReinterpretCast(ooTreeBasedCollection *, this->pin_obj_internal(openMode));
}
inline
ooTreeBasedCollection *
ooHandle(ooTreeBasedCollection)::operator->() const
{
  return this->vm();
}
inline
ooTreeBasedCollection &
ooHandle(ooTreeBasedCollection)::operator*() const
{
  return *(this->vm());
}
inline
ooHandle(ooTreeBasedCollection)::operator ooTreeBasedCollection *() const
{
  if ( _state == oocHandlePTR  )
    return ooReinterpretCast(ooTreeBasedCollection *, _ptr._obj);
  else return ooReinterpretCast(ooTreeBasedCollection *, this->get_vm());
}
inline
ooTreeBasedCollection *
ooHandle(ooTreeBasedCollection)::vm() const
{
  if ( _state == oocHandlePTR && _ptr._obj != NULL )
    return ooReinterpretCast(ooTreeBasedCollection *, _ptr._obj);
  else return ooReinterpretCast(ooTreeBasedCollection *, this->get_vm());
}
inline
ooRef(ooTreeBasedCollection) &
ooHandle(ooTreeBasedCollection)::copy(const ooHandle(ooObj) &  nearH,
		   ooRef(ooTreeBasedCollection) &              result) const
{
  this->ooHandle(ooObj)::copy(nearH, result);
  return result;
}


/* ODMG methods */
inline
ooTreeBasedCollection *
ooRef(ooTreeBasedCollection)::ptr() const
{
  return this->pin();
}
inline
ooTreeBasedCollection *
ooHandle(ooTreeBasedCollection)::ptr() const
{
  return this->operator ooTreeBasedCollection *();
}
class ooTreeInternalNode;


/////////////////////////////////////////////////////////////////////////////

ooTemplateSpecialization
class ooDeref(ooTreeInternalNode) : public ooDerefBase {
	friend class ooRef(ooTreeInternalNode);
  public:
    ~ooDerefStructor(ooTreeInternalNode)();
    inline ooTreeInternalNode *operator->() const;
#ifndef OO_BUGGY_TEMPLATES
  private:
#endif // !defined(OO_BUGGY_TEMPLATES)
    ooDerefStructor(ooTreeInternalNode)(ooDeref(ooTreeInternalNode)& deref);
    ooDerefStructor(ooTreeInternalNode)(ooObj *  fromObject);
};


#ifdef OO_BUGGY_TEMPLATES

class ooHandle_superclass<ooTreeInternalNode > : public ooHandle(ooTreeBasedCollection) {
 protected:
  ooHandle_superclass()
    {}
  ooHandle_superclass(const ooHandle(ooTreeBasedCollection) &  from) :
      ooHandle(ooTreeBasedCollection)(from)
    {}
  ooHandle_superclass(const ooRef(ooTreeBasedCollection) &  from) :
      ooHandle(ooTreeBasedCollection)(from)
    {}
  ooHandle_superclass(const ooTreeBasedCollection *  from) :
      ooHandle(ooTreeBasedCollection)(from)
    {}
  ~ooHandle_superclass()
    {}
};

class ooShortRef_superclass<ooTreeInternalNode > : public ooShortRef(ooTreeBasedCollection) {
};

#endif // OO_BUGGY_TEMPLATES

ooTemplateSpecialization
class ooRef(ooTreeInternalNode) : public ooRef(ooTreeBasedCollection) {
  public:
    ooRefStructor(ooTreeInternalNode)()
      {}
    ooRefStructor(ooTreeInternalNode)(const ooRef(ooTreeInternalNode)& id) :
	  ooRef(ooTreeBasedCollection)(id)
      {}
    inline ooRefStructor(ooTreeInternalNode)(const ooHandleSuper(ooTreeInternalNode)& objH);
    inline ooRefStructor(ooTreeInternalNode)(const ooTreeInternalNode *  fromObject);
    inline ooRef(ooTreeInternalNode)& operator=(const ooRef(ooTreeInternalNode)& id);
    inline ooRef(ooTreeInternalNode)& operator=(const ooShortRefSuper(ooTreeInternalNode) &shortId);
    inline ooRef(ooTreeInternalNode)& operator=(const ooHandleSuper(ooTreeInternalNode)& objH);
    inline ooRef(ooTreeInternalNode)& operator=(const ooTreeInternalNode *  fromObject);
    ooStatus lookupObj(const ooHandle(ooObj)& scopeH,
		       const ooKey& key,
		       ooMode openMode = oocRead);
    ooStatus lookupObj(const ooHandle(ooObj)& scopeH,
		       const char* name,
		       ooMode openMode = oocRead);
#ifndef OO_BUGGY_TEMPLATES
    inline ooRef(ooTreeInternalNode)& copy(const ooHandle(ooObj)& nearH,
		    ooRef(ooTreeInternalNode)& newObjRef) const;
    inline ooHandle(ooTreeInternalNode)& copy(const ooHandle(ooObj)& nearH,
			ooHandle(ooTreeInternalNode)& result) const;
    inline ooHandle(ooTreeInternalNode) copy(const ooHandle(ooObj)& nearH) const;
#endif // !defined(OO_BUGGY_TEMPLATES)
    inline ooTreeInternalNode *pin(ooMode openMode = oocRead) const;
    ooDeref(ooTreeInternalNode) operator->() const;
    /* Use pin() or use ooHandle "operator ooTreeInternalNode *" instead of vm. */
    /* OBSOLETE */ inline ooTreeInternalNode *vm(ooMode openMode = oocRead) const;
    // ODMG methods:
    ooRefStructor(ooTreeInternalNode)(const d_Ref_Any &from);
    ooTreeInternalNode *ptr() const;
};

ooTemplateSpecialization
class ooShortRef(ooTreeInternalNode) :
#ifdef OO_BUGGY_TEMPLATES
			public ooShortRef_superclass<ooTreeInternalNode >
#else // !defined(OO_BUGGY_TEMPLATES)
			public ooShortRef(ooTreeBasedCollection)
#endif // !defined(OO_BUGGY_TEMPLATES)
					            {
  public:
    ooShortRefStructor(ooTreeInternalNode)();
    ooShortRefStructor(ooTreeInternalNode)(const ooShortRef(ooTreeInternalNode)& shortId);
    ooShortRefStructor(ooTreeInternalNode)(const ooRef(ooTreeInternalNode)& id);
    ooShortRefStructor(ooTreeInternalNode)(const ooHandleSuper(ooTreeInternalNode) &objH);
    ooShortRefStructor(ooTreeInternalNode)(const ooTreeInternalNode *  fromObject);
    ooShortRef(ooTreeInternalNode)& operator=(const ooShortRef(ooTreeInternalNode)& shortId);
    ooShortRef(ooTreeInternalNode)& operator=(const ooRef(ooTreeInternalNode)& id);
    ooShortRef(ooTreeInternalNode)& operator=(const ooHandleSuper(ooTreeInternalNode) &objH);
    ooShortRef(ooTreeInternalNode)& operator=(const ooTreeInternalNode *  fromObject);
};

ooTemplateSpecialization
class ooHandle(ooTreeInternalNode) :
#ifdef OO_BUGGY_TEMPLATES
		      public ooHandle_superclass<ooTreeInternalNode >
#else // !defined(OO_BUGGY_TEMPLATES)
		      public ooHandle(ooTreeBasedCollection)
#endif // !defined(OO_BUGGY_TEMPLATES)
                                                {
  public:
    inline ooHandleStructor(ooTreeInternalNode)();
    inline ooHandleStructor(ooTreeInternalNode)(const ooRef(ooTreeInternalNode)& id);
    inline ooHandleStructor(ooTreeInternalNode)(const ooHandle(ooTreeInternalNode)& objH);
    inline ooHandleStructor(ooTreeInternalNode)(const ooTreeInternalNode *  fromObject);
    inline ooHandle(ooTreeInternalNode)& operator=(const ooRef(ooTreeInternalNode)& id);
    inline ooHandle(ooTreeInternalNode)& operator=(const ooHandle(ooTreeInternalNode)& objH);
    inline ooHandle(ooTreeInternalNode)& operator=(const ooShortRef(ooTreeInternalNode)& shortId);
    inline ooHandle(ooTreeInternalNode)& operator=(const ooTreeInternalNode *  fromObject);
    ooStatus lookupObj(const ooHandle(ooObj)& scopeH,
		       const ooKey& key,
		       ooMode openMode = oocRead);
    ooStatus lookupObj(const ooHandle(ooObj)& scopeH,
		       const char* name,
		       ooMode openMode = oocRead);
    ooHandle(ooTreeInternalNode)& copy(const ooHandle(ooObj)& nearH,
		       ooHandle(ooTreeInternalNode)& result) const;
    inline ooRef(ooTreeInternalNode)& copy(const ooHandle(ooObj)& nearH,
		    ooRef(ooTreeInternalNode)& result) const;
    ooHandle(ooTreeInternalNode) copy(const ooHandle(ooObj)& nearH) const;
    inline ooTreeInternalNode *pin(ooMode openMode = oocRead) const;
    inline ooTreeInternalNode *operator->() const;
    inline ooTreeInternalNode &operator*() const;
    inline operator ooTreeInternalNode *() const;
    /* Use "operator ooTreeInternalNode *" instead of vm. */
    /* OBSOLETE */ inline ooTreeInternalNode *vm() const;
    // ODMG methods:
    ooHandleStructor(ooTreeInternalNode)(const d_Ref_Any &from);
    ooTreeInternalNode *ptr() const;
};

ooTemplateSpecialization
class ooItr(ooTreeInternalNode) : public ooHandle(ooTreeInternalNode),
		    public ooIteratorObjOrContObj {
  public:
    ooItrStructor(ooTreeInternalNode)();
    ~ooItrStructor(ooTreeInternalNode)();
  private:
    // Defined only to prevent implicit definition:
    ooItrStructor(ooTreeInternalNode)(ooItr(ooTreeInternalNode)&);
    ooItr(ooTreeInternalNode)    operator=(ooItr(ooTreeInternalNode)&);
};


/* methods on ooDeref(ooTreeInternalNode) */
inline
ooDeref(ooTreeInternalNode)::ooDerefStructor(ooTreeInternalNode)(ooDeref(ooTreeInternalNode) &  deref) :
    ooDerefBase(deref.vm())
{
  this->pinCompensate();
}
inline
ooDeref(ooTreeInternalNode)::ooDerefStructor(ooTreeInternalNode)(ooObj *  fromObject) :
    ooDerefBase(fromObject)
{
}
inline
ooDeref(ooTreeInternalNode)::~ooDerefStructor(ooTreeInternalNode)()
{
}
inline
ooTreeInternalNode *
ooDeref(ooTreeInternalNode)::operator->() const
{
  return ooReinterpretCast(ooTreeInternalNode *, this->vm());
}


/* methods on ooRef(ooTreeInternalNode) */
inline
ooRef(ooTreeInternalNode)::ooRefStructor(ooTreeInternalNode)(const ooHandleSuper(ooTreeInternalNode)& objH) :
    ooRef(ooTreeBasedCollection)(objH)
{
}
inline
ooRef(ooTreeInternalNode)::ooRefStructor(ooTreeInternalNode)(const ooTreeInternalNode *  fromObject) :
    ooRef(ooTreeBasedCollection)(ooReinterpretCast(const ooTreeBasedCollection *, fromObject))
{
}
inline
ooRef(ooTreeInternalNode)&
ooRef(ooTreeInternalNode)::operator=(const ooRef(ooTreeInternalNode) &  id)
{
  this->ooId::operator=(id);
  return *this;
}
inline
ooRef(ooTreeInternalNode)&
ooRef(ooTreeInternalNode)::operator=(const ooShortRefSuper(ooTreeInternalNode) &  shortId)
{
  this->ooRef(ooObj)::operator=(shortId);
  return *this;
}
inline
ooRef(ooTreeInternalNode)&
ooRef(ooTreeInternalNode)::operator=(const ooHandleSuper(ooTreeInternalNode) &  objH)
{
  this->ooRef(ooObj)::operator=(objH);
  return *this;
}
inline
ooRef(ooTreeInternalNode)&
ooRef(ooTreeInternalNode)::operator=(const ooTreeInternalNode *  fromObject)
{
  this->ooRef(ooObj)::operator=(ooReinterpretCast(const ooObj *, fromObject));
  return *this;
}
inline
ooTreeInternalNode *
ooRef(ooTreeInternalNode)::pin(ooMode  openMode) const
{
  return ooReinterpretCast(ooTreeInternalNode *, this->pin_ref_internal(openMode));
}
inline
ooTreeInternalNode *
ooRef(ooTreeInternalNode)::vm(ooMode  openMode) const
{
  return this->pin(openMode);
}
#ifndef OO_BUGGY_TEMPLATES
inline
ooHandle(ooTreeInternalNode) &
ooRef(ooTreeInternalNode)::copy(const ooHandle(ooObj) &  nearH,
		ooHandle(ooTreeInternalNode) &           result) const
{
  this->ooRef(ooObj)::copy(nearH, result);
  return result;
}
inline
ooRef(ooTreeInternalNode) &
ooRef(ooTreeInternalNode)::copy(const ooHandle(ooObj) &  nearH,
		ooRef(ooTreeInternalNode) &              newObjRef) const
{
  this->ooRef(ooObj)::copy(nearH, newObjRef);
  return newObjRef;
}
inline
ooHandle(ooTreeInternalNode)
ooRef(ooTreeInternalNode)::copy(const ooHandle(ooObj) &  nearH) const
{
  ooHandle(ooTreeInternalNode) result;
  this->ooRef(ooObj)::copy(nearH, result);
  return result;
}
#endif // !defined(OO_BUGGY_TEMPLATES)
inline
ooDeref(ooTreeInternalNode)
ooRef(ooTreeInternalNode)::operator->() const
{
  ooDeref(ooTreeInternalNode) result(this->pin_ref_internal(oocRead));
  return result;
}


/* methods on ooShortRef(ooTreeInternalNode) */
inline
ooShortRef(ooTreeInternalNode) &
ooShortRef(ooTreeInternalNode)::operator=(const ooShortRef(ooTreeInternalNode) &  shortId)
{
  this->ooShortId::operator=(shortId);
  return *this;
}
inline
ooShortRef(ooTreeInternalNode) &
ooShortRef(ooTreeInternalNode)::operator=(const ooRef(ooTreeInternalNode) &  id)
{
  this->ooShortId::operator=(id);
  return *this;
}
inline
ooShortRef(ooTreeInternalNode) &
ooShortRef(ooTreeInternalNode)::operator=(const ooHandleSuper(ooTreeInternalNode) &  objH)
{
  this->ooShortId::operator=(objH);
  return *this;
}
inline
ooShortRef(ooTreeInternalNode)&
ooShortRef(ooTreeInternalNode)::operator=(const ooTreeInternalNode *  fromObject)
{
  this->ooShortId::operator=(ooReinterpretCast(const ooObj *,fromObject));
  return *this;
}
inline
ooShortRef(ooTreeInternalNode)::ooShortRefStructor(ooTreeInternalNode)()
{
}
#ifdef OO_BUGGY_TEMPLATES
inline
ooShortRef(ooTreeInternalNode)::ooShortRefStructor(ooTreeInternalNode)(const ooShortRef(ooTreeInternalNode) &  shortId)
{
  *this = shortId;
}
#else // !defined(OO_BUGGY_TEMPLATES)
inline
ooShortRef(ooTreeInternalNode)::ooShortRefStructor(ooTreeInternalNode)(const ooShortRef(ooTreeInternalNode) &  shortId) :
    ooShortRef(ooTreeBasedCollection)(shortId)
{
}
#endif // !defined(OO_BUGGY_TEMPLATES)
#ifdef OO_BUGGY_TEMPLATES
inline
ooShortRef(ooTreeInternalNode)::ooShortRefStructor(ooTreeInternalNode)(const ooRef(ooTreeInternalNode) &  id)
{
  *this = id;
}
#else // !defined(OO_BUGGY_TEMPLATES)
inline
ooShortRef(ooTreeInternalNode)::ooShortRefStructor(ooTreeInternalNode)(const ooRef(ooTreeInternalNode) &  id) :
    ooShortRef(ooTreeBasedCollection)(id)
{
}
#endif // !defined(OO_BUGGY_TEMPLATES)
#ifdef OO_BUGGY_TEMPLATES
inline
ooShortRef(ooTreeInternalNode)::ooShortRefStructor(ooTreeInternalNode)(const ooHandleSuper(ooTreeInternalNode) &  objH)
{
  *this = objH;
}
#else // !defined(OO_BUGGY_TEMPLATES)
inline
ooShortRef(ooTreeInternalNode)::ooShortRefStructor(ooTreeInternalNode)(const ooHandleSuper(ooTreeInternalNode) &  objH) :
    ooShortRef(ooTreeBasedCollection)(objH)
{
}
#endif // !defined(OO_BUGGY_TEMPLATES)
#ifdef OO_BUGGY_TEMPLATES
inline
ooShortRef(ooTreeInternalNode)::ooShortRefStructor(ooTreeInternalNode)(const ooTreeInternalNode *  fromObject)
{
  *this = fromObject;
}
#else // !defined(OO_BUGGY_TEMPLATES)
inline
ooShortRef(ooTreeInternalNode)::ooShortRefStructor(ooTreeInternalNode)(const ooTreeInternalNode *  fromObject) :
    ooShortRef(ooTreeBasedCollection)(ooReinterpretCast(const ooTreeBasedCollection *,fromObject))
{
}
#endif // !defined(OO_BUGGY_TEMPLATES)


/* methods on ooHandle(ooTreeInternalNode) */
inline
ooHandle(ooTreeInternalNode)::ooHandleStructor(ooTreeInternalNode)()
{
}
inline
ooHandle(ooTreeInternalNode)::ooHandleStructor(ooTreeInternalNode)(const ooHandle(ooTreeInternalNode) &  objH) :
#ifdef OO_BUGGY_TEMPLATES
    ooHandle_superclass<ooTreeInternalNode >(objH)
#else // !defined(OO_BUGGY_TEMPLATES)
    ooHandle(ooTreeBasedCollection)(objH)
#endif // !defined(OO_BUGGY_TEMPLATES)
{
}
inline
ooHandle(ooTreeInternalNode)::ooHandleStructor(ooTreeInternalNode)(const ooRef(ooTreeInternalNode) &  id) :
#ifdef OO_BUGGY_TEMPLATES
    ooHandle_superclass<ooTreeInternalNode >(id)
#else // !defined(OO_BUGGY_TEMPLATES)
    ooHandle(ooTreeBasedCollection)(id)
#endif // !defined(OO_BUGGY_TEMPLATES)
{
}
inline
ooHandle(ooTreeInternalNode)::ooHandleStructor(ooTreeInternalNode)(const ooTreeInternalNode *  fromObject) :
#ifdef OO_BUGGY_TEMPLATES
    ooHandle_superclass<ooTreeInternalNode >(ooReinterpretCast(const ooTreeBasedCollection *,fromObject))
#else // !defined(OO_BUGGY_TEMPLATES)
    ooHandle(ooTreeBasedCollection)(ooReinterpretCast(const ooTreeBasedCollection *,fromObject))
#endif // !defined(OO_BUGGY_TEMPLATES)
{
}
inline
ooHandle(ooTreeInternalNode)&
ooHandle(ooTreeInternalNode)::operator=(const ooRef(ooTreeInternalNode) &  id)
{
  this->ooHandle(ooObj)::operator=(id);
  return *this;
}
inline
ooHandle(ooTreeInternalNode)&
ooHandle(ooTreeInternalNode)::operator=(const ooHandle(ooTreeInternalNode) &  objH)
{
  this->ooHandle(ooObj)::operator=(objH);
  return *this;
}
inline
ooHandle(ooTreeInternalNode)&
ooHandle(ooTreeInternalNode)::operator=(const ooShortRef(ooTreeInternalNode) &  shortId)
{
  this->ooHandle(ooObj)::operator=(shortId);
  return *this;
}
inline
ooHandle(ooTreeInternalNode)&
ooHandle(ooTreeInternalNode)::operator=(const ooTreeInternalNode *  fromObject)
{
  this->ooHandle(ooObj)::operator=(ooReinterpretCast(const ooObj *,fromObject));
  return *this;
}
inline
ooTreeInternalNode *
ooHandle(ooTreeInternalNode)::pin(ooMode  openMode) const
{
  return ooReinterpretCast(ooTreeInternalNode *, this->pin_obj_internal(openMode));
}
inline
ooTreeInternalNode *
ooHandle(ooTreeInternalNode)::operator->() const
{
  return this->vm();
}
inline
ooTreeInternalNode &
ooHandle(ooTreeInternalNode)::operator*() const
{
  return *(this->vm());
}
inline
ooHandle(ooTreeInternalNode)::operator ooTreeInternalNode *() const
{
  if ( _state == oocHandlePTR  )
    return ooReinterpretCast(ooTreeInternalNode *, _ptr._obj);
  else return ooReinterpretCast(ooTreeInternalNode *, this->get_vm());
}
inline
ooTreeInternalNode *
ooHandle(ooTreeInternalNode)::vm() const
{
  if ( _state == oocHandlePTR && _ptr._obj != NULL )
    return ooReinterpretCast(ooTreeInternalNode *, _ptr._obj);
  else return ooReinterpretCast(ooTreeInternalNode *, this->get_vm());
}
inline
ooRef(ooTreeInternalNode) &
ooHandle(ooTreeInternalNode)::copy(const ooHandle(ooObj) &  nearH,
		   ooRef(ooTreeInternalNode) &              result) const
{
  this->ooHandle(ooObj)::copy(nearH, result);
  return result;
}


/* ODMG methods */
inline
ooTreeInternalNode *
ooRef(ooTreeInternalNode)::ptr() const
{
  return this->pin();
}
inline
ooTreeInternalNode *
ooHandle(ooTreeInternalNode)::ptr() const
{
  return this->operator ooTreeInternalNode *();
}
class ooTreeLeafNode;


/////////////////////////////////////////////////////////////////////////////

ooTemplateSpecialization
class ooDeref(ooTreeLeafNode) : public ooDerefBase {
	friend class ooRef(ooTreeLeafNode);
  public:
    ~ooDerefStructor(ooTreeLeafNode)();
    inline ooTreeLeafNode *operator->() const;
#ifndef OO_BUGGY_TEMPLATES
  private:
#endif // !defined(OO_BUGGY_TEMPLATES)
    ooDerefStructor(ooTreeLeafNode)(ooDeref(ooTreeLeafNode)& deref);
    ooDerefStructor(ooTreeLeafNode)(ooObj *  fromObject);
};


#ifdef OO_BUGGY_TEMPLATES

class ooHandle_superclass<ooTreeLeafNode > : public ooHandle(ooTreeInternalNode) {
 protected:
  ooHandle_superclass()
    {}
  ooHandle_superclass(const ooHandle(ooTreeInternalNode) &  from) :
      ooHandle(ooTreeInternalNode)(from)
    {}
  ooHandle_superclass(const ooRef(ooTreeInternalNode) &  from) :
      ooHandle(ooTreeInternalNode)(from)
    {}
  ooHandle_superclass(const ooTreeInternalNode *  from) :
      ooHandle(ooTreeInternalNode)(from)
    {}
  ~ooHandle_superclass()
    {}
};

class ooShortRef_superclass<ooTreeLeafNode > : public ooShortRef(ooTreeInternalNode) {
};

#endif // OO_BUGGY_TEMPLATES

ooTemplateSpecialization
class ooRef(ooTreeLeafNode) : public ooRef(ooTreeInternalNode) {
  public:
    ooRefStructor(ooTreeLeafNode)()
      {}
    ooRefStructor(ooTreeLeafNode)(const ooRef(ooTreeLeafNode)& id) :
	  ooRef(ooTreeInternalNode)(id)
      {}
    inline ooRefStructor(ooTreeLeafNode)(const ooHandleSuper(ooTreeLeafNode)& objH);
    inline ooRefStructor(ooTreeLeafNode)(const ooTreeLeafNode *  fromObject);
    inline ooRef(ooTreeLeafNode)& operator=(const ooRef(ooTreeLeafNode)& id);
    inline ooRef(ooTreeLeafNode)& operator=(const ooShortRefSuper(ooTreeLeafNode) &shortId);
    inline ooRef(ooTreeLeafNode)& operator=(const ooHandleSuper(ooTreeLeafNode)& objH);
    inline ooRef(ooTreeLeafNode)& operator=(const ooTreeLeafNode *  fromObject);
    ooStatus lookupObj(const ooHandle(ooObj)& scopeH,
		       const ooKey& key,
		       ooMode openMode = oocRead);
    ooStatus lookupObj(const ooHandle(ooObj)& scopeH,
		       const char* name,
		       ooMode openMode = oocRead);
#ifndef OO_BUGGY_TEMPLATES
    inline ooRef(ooTreeLeafNode)& copy(const ooHandle(ooObj)& nearH,
		    ooRef(ooTreeLeafNode)& newObjRef) const;
    inline ooHandle(ooTreeLeafNode)& copy(const ooHandle(ooObj)& nearH,
			ooHandle(ooTreeLeafNode)& result) const;
    inline ooHandle(ooTreeLeafNode) copy(const ooHandle(ooObj)& nearH) const;
#endif // !defined(OO_BUGGY_TEMPLATES)
    inline ooTreeLeafNode *pin(ooMode openMode = oocRead) const;
    ooDeref(ooTreeLeafNode) operator->() const;
    /* Use pin() or use ooHandle "operator ooTreeLeafNode *" instead of vm. */
    /* OBSOLETE */ inline ooTreeLeafNode *vm(ooMode openMode = oocRead) const;
    // ODMG methods:
    ooRefStructor(ooTreeLeafNode)(const d_Ref_Any &from);
    ooTreeLeafNode *ptr() const;
};

ooTemplateSpecialization
class ooShortRef(ooTreeLeafNode) :
#ifdef OO_BUGGY_TEMPLATES
			public ooShortRef_superclass<ooTreeLeafNode >
#else // !defined(OO_BUGGY_TEMPLATES)
			public ooShortRef(ooTreeInternalNode)
#endif // !defined(OO_BUGGY_TEMPLATES)
					            {
  public:
    ooShortRefStructor(ooTreeLeafNode)();
    ooShortRefStructor(ooTreeLeafNode)(const ooShortRef(ooTreeLeafNode)& shortId);
    ooShortRefStructor(ooTreeLeafNode)(const ooRef(ooTreeLeafNode)& id);
    ooShortRefStructor(ooTreeLeafNode)(const ooHandleSuper(ooTreeLeafNode) &objH);
    ooShortRefStructor(ooTreeLeafNode)(const ooTreeLeafNode *  fromObject);
    ooShortRef(ooTreeLeafNode)& operator=(const ooShortRef(ooTreeLeafNode)& shortId);
    ooShortRef(ooTreeLeafNode)& operator=(const ooRef(ooTreeLeafNode)& id);
    ooShortRef(ooTreeLeafNode)& operator=(const ooHandleSuper(ooTreeLeafNode) &objH);
    ooShortRef(ooTreeLeafNode)& operator=(const ooTreeLeafNode *  fromObject);
};

ooTemplateSpecialization
class ooHandle(ooTreeLeafNode) :
#ifdef OO_BUGGY_TEMPLATES
		      public ooHandle_superclass<ooTreeLeafNode >
#else // !defined(OO_BUGGY_TEMPLATES)
		      public ooHandle(ooTreeInternalNode)
#endif // !defined(OO_BUGGY_TEMPLATES)
                                                {
  public:
    inline ooHandleStructor(ooTreeLeafNode)();
    inline ooHandleStructor(ooTreeLeafNode)(const ooRef(ooTreeLeafNode)& id);
    inline ooHandleStructor(ooTreeLeafNode)(const ooHandle(ooTreeLeafNode)& objH);
    inline ooHandleStructor(ooTreeLeafNode)(const ooTreeLeafNode *  fromObject);
    inline ooHandle(ooTreeLeafNode)& operator=(const ooRef(ooTreeLeafNode)& id);
    inline ooHandle(ooTreeLeafNode)& operator=(const ooHandle(ooTreeLeafNode)& objH);
    inline ooHandle(ooTreeLeafNode)& operator=(const ooShortRef(ooTreeLeafNode)& shortId);
    inline ooHandle(ooTreeLeafNode)& operator=(const ooTreeLeafNode *  fromObject);
    ooStatus lookupObj(const ooHandle(ooObj)& scopeH,
		       const ooKey& key,
		       ooMode openMode = oocRead);
    ooStatus lookupObj(const ooHandle(ooObj)& scopeH,
		       const char* name,
		       ooMode openMode = oocRead);
    ooHandle(ooTreeLeafNode)& copy(const ooHandle(ooObj)& nearH,
		       ooHandle(ooTreeLeafNode)& result) const;
    inline ooRef(ooTreeLeafNode)& copy(const ooHandle(ooObj)& nearH,
		    ooRef(ooTreeLeafNode)& result) const;
    ooHandle(ooTreeLeafNode) copy(const ooHandle(ooObj)& nearH) const;
    inline ooTreeLeafNode *pin(ooMode openMode = oocRead) const;
    inline ooTreeLeafNode *operator->() const;
    inline ooTreeLeafNode &operator*() const;
    inline operator ooTreeLeafNode *() const;
    /* Use "operator ooTreeLeafNode *" instead of vm. */
    /* OBSOLETE */ inline ooTreeLeafNode *vm() const;
    // ODMG methods:
    ooHandleStructor(ooTreeLeafNode)(const d_Ref_Any &from);
    ooTreeLeafNode *ptr() const;
};

ooTemplateSpecialization
class ooItr(ooTreeLeafNode) : public ooHandle(ooTreeLeafNode),
		    public ooIteratorObjOrContObj {
  public:
    ooItrStructor(ooTreeLeafNode)();
    ~ooItrStructor(ooTreeLeafNode)();
  private:
    // Defined only to prevent implicit definition:
    ooItrStructor(ooTreeLeafNode)(ooItr(ooTreeLeafNode)&);
    ooItr(ooTreeLeafNode)    operator=(ooItr(ooTreeLeafNode)&);
};


/* methods on ooDeref(ooTreeLeafNode) */
inline
ooDeref(ooTreeLeafNode)::ooDerefStructor(ooTreeLeafNode)(ooDeref(ooTreeLeafNode) &  deref) :
    ooDerefBase(deref.vm())
{
  this->pinCompensate();
}
inline
ooDeref(ooTreeLeafNode)::ooDerefStructor(ooTreeLeafNode)(ooObj *  fromObject) :
    ooDerefBase(fromObject)
{
}
inline
ooDeref(ooTreeLeafNode)::~ooDerefStructor(ooTreeLeafNode)()
{
}
inline
ooTreeLeafNode *
ooDeref(ooTreeLeafNode)::operator->() const
{
  return ooReinterpretCast(ooTreeLeafNode *, this->vm());
}


/* methods on ooRef(ooTreeLeafNode) */
inline
ooRef(ooTreeLeafNode)::ooRefStructor(ooTreeLeafNode)(const ooHandleSuper(ooTreeLeafNode)& objH) :
    ooRef(ooTreeInternalNode)(objH)
{
}
inline
ooRef(ooTreeLeafNode)::ooRefStructor(ooTreeLeafNode)(const ooTreeLeafNode *  fromObject) :
    ooRef(ooTreeInternalNode)(ooReinterpretCast(const ooTreeInternalNode *, fromObject))
{
}
inline
ooRef(ooTreeLeafNode)&
ooRef(ooTreeLeafNode)::operator=(const ooRef(ooTreeLeafNode) &  id)
{
  this->ooId::operator=(id);
  return *this;
}
inline
ooRef(ooTreeLeafNode)&
ooRef(ooTreeLeafNode)::operator=(const ooShortRefSuper(ooTreeLeafNode) &  shortId)
{
  this->ooRef(ooObj)::operator=(shortId);
  return *this;
}
inline
ooRef(ooTreeLeafNode)&
ooRef(ooTreeLeafNode)::operator=(const ooHandleSuper(ooTreeLeafNode) &  objH)
{
  this->ooRef(ooObj)::operator=(objH);
  return *this;
}
inline
ooRef(ooTreeLeafNode)&
ooRef(ooTreeLeafNode)::operator=(const ooTreeLeafNode *  fromObject)
{
  this->ooRef(ooObj)::operator=(ooReinterpretCast(const ooObj *, fromObject));
  return *this;
}
inline
ooTreeLeafNode *
ooRef(ooTreeLeafNode)::pin(ooMode  openMode) const
{
  return ooReinterpretCast(ooTreeLeafNode *, this->pin_ref_internal(openMode));
}
inline
ooTreeLeafNode *
ooRef(ooTreeLeafNode)::vm(ooMode  openMode) const
{
  return this->pin(openMode);
}
#ifndef OO_BUGGY_TEMPLATES
inline
ooHandle(ooTreeLeafNode) &
ooRef(ooTreeLeafNode)::copy(const ooHandle(ooObj) &  nearH,
		ooHandle(ooTreeLeafNode) &           result) const
{
  this->ooRef(ooObj)::copy(nearH, result);
  return result;
}
inline
ooRef(ooTreeLeafNode) &
ooRef(ooTreeLeafNode)::copy(const ooHandle(ooObj) &  nearH,
		ooRef(ooTreeLeafNode) &              newObjRef) const
{
  this->ooRef(ooObj)::copy(nearH, newObjRef);
  return newObjRef;
}
inline
ooHandle(ooTreeLeafNode)
ooRef(ooTreeLeafNode)::copy(const ooHandle(ooObj) &  nearH) const
{
  ooHandle(ooTreeLeafNode) result;
  this->ooRef(ooObj)::copy(nearH, result);
  return result;
}
#endif // !defined(OO_BUGGY_TEMPLATES)
inline
ooDeref(ooTreeLeafNode)
ooRef(ooTreeLeafNode)::operator->() const
{
  ooDeref(ooTreeLeafNode) result(this->pin_ref_internal(oocRead));
  return result;
}


/* methods on ooShortRef(ooTreeLeafNode) */
inline
ooShortRef(ooTreeLeafNode) &
ooShortRef(ooTreeLeafNode)::operator=(const ooShortRef(ooTreeLeafNode) &  shortId)
{
  this->ooShortId::operator=(shortId);
  return *this;
}
inline
ooShortRef(ooTreeLeafNode) &
ooShortRef(ooTreeLeafNode)::operator=(const ooRef(ooTreeLeafNode) &  id)
{
  this->ooShortId::operator=(id);
  return *this;
}
inline
ooShortRef(ooTreeLeafNode) &
ooShortRef(ooTreeLeafNode)::operator=(const ooHandleSuper(ooTreeLeafNode) &  objH)
{
  this->ooShortId::operator=(objH);
  return *this;
}
inline
ooShortRef(ooTreeLeafNode)&
ooShortRef(ooTreeLeafNode)::operator=(const ooTreeLeafNode *  fromObject)
{
  this->ooShortId::operator=(ooReinterpretCast(const ooObj *,fromObject));
  return *this;
}
inline
ooShortRef(ooTreeLeafNode)::ooShortRefStructor(ooTreeLeafNode)()
{
}
#ifdef OO_BUGGY_TEMPLATES
inline
ooShortRef(ooTreeLeafNode)::ooShortRefStructor(ooTreeLeafNode)(const ooShortRef(ooTreeLeafNode) &  shortId)
{
  *this = shortId;
}
#else // !defined(OO_BUGGY_TEMPLATES)
inline
ooShortRef(ooTreeLeafNode)::ooShortRefStructor(ooTreeLeafNode)(const ooShortRef(ooTreeLeafNode) &  shortId) :
    ooShortRef(ooTreeInternalNode)(shortId)
{
}
#endif // !defined(OO_BUGGY_TEMPLATES)
#ifdef OO_BUGGY_TEMPLATES
inline
ooShortRef(ooTreeLeafNode)::ooShortRefStructor(ooTreeLeafNode)(const ooRef(ooTreeLeafNode) &  id)
{
  *this = id;
}
#else // !defined(OO_BUGGY_TEMPLATES)
inline
ooShortRef(ooTreeLeafNode)::ooShortRefStructor(ooTreeLeafNode)(const ooRef(ooTreeLeafNode) &  id) :
    ooShortRef(ooTreeInternalNode)(id)
{
}
#endif // !defined(OO_BUGGY_TEMPLATES)
#ifdef OO_BUGGY_TEMPLATES
inline
ooShortRef(ooTreeLeafNode)::ooShortRefStructor(ooTreeLeafNode)(const ooHandleSuper(ooTreeLeafNode) &  objH)
{
  *this = objH;
}
#else // !defined(OO_BUGGY_TEMPLATES)
inline
ooShortRef(ooTreeLeafNode)::ooShortRefStructor(ooTreeLeafNode)(const ooHandleSuper(ooTreeLeafNode) &  objH) :
    ooShortRef(ooTreeInternalNode)(objH)
{
}
#endif // !defined(OO_BUGGY_TEMPLATES)
#ifdef OO_BUGGY_TEMPLATES
inline
ooShortRef(ooTreeLeafNode)::ooShortRefStructor(ooTreeLeafNode)(const ooTreeLeafNode *  fromObject)
{
  *this = fromObject;
}
#else // !defined(OO_BUGGY_TEMPLATES)
inline
ooShortRef(ooTreeLeafNode)::ooShortRefStructor(ooTreeLeafNode)(const ooTreeLeafNode *  fromObject) :
    ooShortRef(ooTreeInternalNode)(ooReinterpretCast(const ooTreeInternalNode *,fromObject))
{
}
#endif // !defined(OO_BUGGY_TEMPLATES)


/* methods on ooHandle(ooTreeLeafNode) */
inline
ooHandle(ooTreeLeafNode)::ooHandleStructor(ooTreeLeafNode)()
{
}
inline
ooHandle(ooTreeLeafNode)::ooHandleStructor(ooTreeLeafNode)(const ooHandle(ooTreeLeafNode) &  objH) :
#ifdef OO_BUGGY_TEMPLATES
    ooHandle_superclass<ooTreeLeafNode >(objH)
#else // !defined(OO_BUGGY_TEMPLATES)
    ooHandle(ooTreeInternalNode)(objH)
#endif // !defined(OO_BUGGY_TEMPLATES)
{
}
inline
ooHandle(ooTreeLeafNode)::ooHandleStructor(ooTreeLeafNode)(const ooRef(ooTreeLeafNode) &  id) :
#ifdef OO_BUGGY_TEMPLATES
    ooHandle_superclass<ooTreeLeafNode >(id)
#else // !defined(OO_BUGGY_TEMPLATES)
    ooHandle(ooTreeInternalNode)(id)
#endif // !defined(OO_BUGGY_TEMPLATES)
{
}
inline
ooHandle(ooTreeLeafNode)::ooHandleStructor(ooTreeLeafNode)(const ooTreeLeafNode *  fromObject) :
#ifdef OO_BUGGY_TEMPLATES
    ooHandle_superclass<ooTreeLeafNode >(ooReinterpretCast(const ooTreeInternalNode *,fromObject))
#else // !defined(OO_BUGGY_TEMPLATES)
    ooHandle(ooTreeInternalNode)(ooReinterpretCast(const ooTreeInternalNode *,fromObject))
#endif // !defined(OO_BUGGY_TEMPLATES)
{
}
inline
ooHandle(ooTreeLeafNode)&
ooHandle(ooTreeLeafNode)::operator=(const ooRef(ooTreeLeafNode) &  id)
{
  this->ooHandle(ooObj)::operator=(id);
  return *this;
}
inline
ooHandle(ooTreeLeafNode)&
ooHandle(ooTreeLeafNode)::operator=(const ooHandle(ooTreeLeafNode) &  objH)
{
  this->ooHandle(ooObj)::operator=(objH);
  return *this;
}
inline
ooHandle(ooTreeLeafNode)&
ooHandle(ooTreeLeafNode)::operator=(const ooShortRef(ooTreeLeafNode) &  shortId)
{
  this->ooHandle(ooObj)::operator=(shortId);
  return *this;
}
inline
ooHandle(ooTreeLeafNode)&
ooHandle(ooTreeLeafNode)::operator=(const ooTreeLeafNode *  fromObject)
{
  this->ooHandle(ooObj)::operator=(ooReinterpretCast(const ooObj *,fromObject));
  return *this;
}
inline
ooTreeLeafNode *
ooHandle(ooTreeLeafNode)::pin(ooMode  openMode) const
{
  return ooReinterpretCast(ooTreeLeafNode *, this->pin_obj_internal(openMode));
}
inline
ooTreeLeafNode *
ooHandle(ooTreeLeafNode)::operator->() const
{
  return this->vm();
}
inline
ooTreeLeafNode &
ooHandle(ooTreeLeafNode)::operator*() const
{
  return *(this->vm());
}
inline
ooHandle(ooTreeLeafNode)::operator ooTreeLeafNode *() const
{
  if ( _state == oocHandlePTR  )
    return ooReinterpretCast(ooTreeLeafNode *, _ptr._obj);
  else return ooReinterpretCast(ooTreeLeafNode *, this->get_vm());
}
inline
ooTreeLeafNode *
ooHandle(ooTreeLeafNode)::vm() const
{
  if ( _state == oocHandlePTR && _ptr._obj != NULL )
    return ooReinterpretCast(ooTreeLeafNode *, _ptr._obj);
  else return ooReinterpretCast(ooTreeLeafNode *, this->get_vm());
}
inline
ooRef(ooTreeLeafNode) &
ooHandle(ooTreeLeafNode)::copy(const ooHandle(ooObj) &  nearH,
		   ooRef(ooTreeLeafNode) &              result) const
{
  this->ooHandle(ooObj)::copy(nearH, result);
  return result;
}


/* ODMG methods */
inline
ooTreeLeafNode *
ooRef(ooTreeLeafNode)::ptr() const
{
  return this->pin();
}
inline
ooTreeLeafNode *
ooHandle(ooTreeLeafNode)::ptr() const
{
  return this->operator ooTreeLeafNode *();
}
class ooTreeLeafNodeMap;


/////////////////////////////////////////////////////////////////////////////

ooTemplateSpecialization
class ooDeref(ooTreeLeafNodeMap) : public ooDerefBase {
	friend class ooRef(ooTreeLeafNodeMap);
  public:
    ~ooDerefStructor(ooTreeLeafNodeMap)();
    inline ooTreeLeafNodeMap *operator->() const;
#ifndef OO_BUGGY_TEMPLATES
  private:
#endif // !defined(OO_BUGGY_TEMPLATES)
    ooDerefStructor(ooTreeLeafNodeMap)(ooDeref(ooTreeLeafNodeMap)& deref);
    ooDerefStructor(ooTreeLeafNodeMap)(ooObj *  fromObject);
};


#ifdef OO_BUGGY_TEMPLATES

class ooHandle_superclass<ooTreeLeafNodeMap > : public ooHandle(ooTreeLeafNode) {
 protected:
  ooHandle_superclass()
    {}
  ooHandle_superclass(const ooHandle(ooTreeLeafNode) &  from) :
      ooHandle(ooTreeLeafNode)(from)
    {}
  ooHandle_superclass(const ooRef(ooTreeLeafNode) &  from) :
      ooHandle(ooTreeLeafNode)(from)
    {}
  ooHandle_superclass(const ooTreeLeafNode *  from) :
      ooHandle(ooTreeLeafNode)(from)
    {}
  ~ooHandle_superclass()
    {}
};

class ooShortRef_superclass<ooTreeLeafNodeMap > : public ooShortRef(ooTreeLeafNode) {
};

#endif // OO_BUGGY_TEMPLATES

ooTemplateSpecialization
class ooRef(ooTreeLeafNodeMap) : public ooRef(ooTreeLeafNode) {
  public:
    ooRefStructor(ooTreeLeafNodeMap)()
      {}
    ooRefStructor(ooTreeLeafNodeMap)(const ooRef(ooTreeLeafNodeMap)& id) :
	  ooRef(ooTreeLeafNode)(id)
      {}
    inline ooRefStructor(ooTreeLeafNodeMap)(const ooHandleSuper(ooTreeLeafNodeMap)& objH);
    inline ooRefStructor(ooTreeLeafNodeMap)(const ooTreeLeafNodeMap *  fromObject);
    inline ooRef(ooTreeLeafNodeMap)& operator=(const ooRef(ooTreeLeafNodeMap)& id);
    inline ooRef(ooTreeLeafNodeMap)& operator=(const ooShortRefSuper(ooTreeLeafNodeMap) &shortId);
    inline ooRef(ooTreeLeafNodeMap)& operator=(const ooHandleSuper(ooTreeLeafNodeMap)& objH);
    inline ooRef(ooTreeLeafNodeMap)& operator=(const ooTreeLeafNodeMap *  fromObject);
    ooStatus lookupObj(const ooHandle(ooObj)& scopeH,
		       const ooKey& key,
		       ooMode openMode = oocRead);
    ooStatus lookupObj(const ooHandle(ooObj)& scopeH,
		       const char* name,
		       ooMode openMode = oocRead);
#ifndef OO_BUGGY_TEMPLATES
    inline ooRef(ooTreeLeafNodeMap)& copy(const ooHandle(ooObj)& nearH,
		    ooRef(ooTreeLeafNodeMap)& newObjRef) const;
    inline ooHandle(ooTreeLeafNodeMap)& copy(const ooHandle(ooObj)& nearH,
			ooHandle(ooTreeLeafNodeMap)& result) const;
    inline ooHandle(ooTreeLeafNodeMap) copy(const ooHandle(ooObj)& nearH) const;
#endif // !defined(OO_BUGGY_TEMPLATES)
    inline ooTreeLeafNodeMap *pin(ooMode openMode = oocRead) const;
    ooDeref(ooTreeLeafNodeMap) operator->() const;
    /* Use pin() or use ooHandle "operator ooTreeLeafNodeMap *" instead of vm. */
    /* OBSOLETE */ inline ooTreeLeafNodeMap *vm(ooMode openMode = oocRead) const;
    // ODMG methods:
    ooRefStructor(ooTreeLeafNodeMap)(const d_Ref_Any &from);
    ooTreeLeafNodeMap *ptr() const;
};

ooTemplateSpecialization
class ooShortRef(ooTreeLeafNodeMap) :
#ifdef OO_BUGGY_TEMPLATES
			public ooShortRef_superclass<ooTreeLeafNodeMap >
#else // !defined(OO_BUGGY_TEMPLATES)
			public ooShortRef(ooTreeLeafNode)
#endif // !defined(OO_BUGGY_TEMPLATES)
					            {
  public:
    ooShortRefStructor(ooTreeLeafNodeMap)();
    ooShortRefStructor(ooTreeLeafNodeMap)(const ooShortRef(ooTreeLeafNodeMap)& shortId);
    ooShortRefStructor(ooTreeLeafNodeMap)(const ooRef(ooTreeLeafNodeMap)& id);
    ooShortRefStructor(ooTreeLeafNodeMap)(const ooHandleSuper(ooTreeLeafNodeMap) &objH);
    ooShortRefStructor(ooTreeLeafNodeMap)(const ooTreeLeafNodeMap *  fromObject);
    ooShortRef(ooTreeLeafNodeMap)& operator=(const ooShortRef(ooTreeLeafNodeMap)& shortId);
    ooShortRef(ooTreeLeafNodeMap)& operator=(const ooRef(ooTreeLeafNodeMap)& id);
    ooShortRef(ooTreeLeafNodeMap)& operator=(const ooHandleSuper(ooTreeLeafNodeMap) &objH);
    ooShortRef(ooTreeLeafNodeMap)& operator=(const ooTreeLeafNodeMap *  fromObject);
};

ooTemplateSpecialization
class ooHandle(ooTreeLeafNodeMap) :
#ifdef OO_BUGGY_TEMPLATES
		      public ooHandle_superclass<ooTreeLeafNodeMap >
#else // !defined(OO_BUGGY_TEMPLATES)
		      public ooHandle(ooTreeLeafNode)
#endif // !defined(OO_BUGGY_TEMPLATES)
                                                {
  public:
    inline ooHandleStructor(ooTreeLeafNodeMap)();
    inline ooHandleStructor(ooTreeLeafNodeMap)(const ooRef(ooTreeLeafNodeMap)& id);
    inline ooHandleStructor(ooTreeLeafNodeMap)(const ooHandle(ooTreeLeafNodeMap)& objH);
    inline ooHandleStructor(ooTreeLeafNodeMap)(const ooTreeLeafNodeMap *  fromObject);
    inline ooHandle(ooTreeLeafNodeMap)& operator=(const ooRef(ooTreeLeafNodeMap)& id);
    inline ooHandle(ooTreeLeafNodeMap)& operator=(const ooHandle(ooTreeLeafNodeMap)& objH);
    inline ooHandle(ooTreeLeafNodeMap)& operator=(const ooShortRef(ooTreeLeafNodeMap)& shortId);
    inline ooHandle(ooTreeLeafNodeMap)& operator=(const ooTreeLeafNodeMap *  fromObject);
    ooStatus lookupObj(const ooHandle(ooObj)& scopeH,
		       const ooKey& key,
		       ooMode openMode = oocRead);
    ooStatus lookupObj(const ooHandle(ooObj)& scopeH,
		       const char* name,
		       ooMode openMode = oocRead);
    ooHandle(ooTreeLeafNodeMap)& copy(const ooHandle(ooObj)& nearH,
		       ooHandle(ooTreeLeafNodeMap)& result) const;
    inline ooRef(ooTreeLeafNodeMap)& copy(const ooHandle(ooObj)& nearH,
		    ooRef(ooTreeLeafNodeMap)& result) const;
    ooHandle(ooTreeLeafNodeMap) copy(const ooHandle(ooObj)& nearH) const;
    inline ooTreeLeafNodeMap *pin(ooMode openMode = oocRead) const;
    inline ooTreeLeafNodeMap *operator->() const;
    inline ooTreeLeafNodeMap &operator*() const;
    inline operator ooTreeLeafNodeMap *() const;
    /* Use "operator ooTreeLeafNodeMap *" instead of vm. */
    /* OBSOLETE */ inline ooTreeLeafNodeMap *vm() const;
    // ODMG methods:
    ooHandleStructor(ooTreeLeafNodeMap)(const d_Ref_Any &from);
    ooTreeLeafNodeMap *ptr() const;
};

ooTemplateSpecialization
class ooItr(ooTreeLeafNodeMap) : public ooHandle(ooTreeLeafNodeMap),
		    public ooIteratorObjOrContObj {
  public:
    ooItrStructor(ooTreeLeafNodeMap)();
    ~ooItrStructor(ooTreeLeafNodeMap)();
  private:
    // Defined only to prevent implicit definition:
    ooItrStructor(ooTreeLeafNodeMap)(ooItr(ooTreeLeafNodeMap)&);
    ooItr(ooTreeLeafNodeMap)    operator=(ooItr(ooTreeLeafNodeMap)&);
};


/* methods on ooDeref(ooTreeLeafNodeMap) */
inline
ooDeref(ooTreeLeafNodeMap)::ooDerefStructor(ooTreeLeafNodeMap)(ooDeref(ooTreeLeafNodeMap) &  deref) :
    ooDerefBase(deref.vm())
{
  this->pinCompensate();
}
inline
ooDeref(ooTreeLeafNodeMap)::ooDerefStructor(ooTreeLeafNodeMap)(ooObj *  fromObject) :
    ooDerefBase(fromObject)
{
}
inline
ooDeref(ooTreeLeafNodeMap)::~ooDerefStructor(ooTreeLeafNodeMap)()
{
}
inline
ooTreeLeafNodeMap *
ooDeref(ooTreeLeafNodeMap)::operator->() const
{
  return ooReinterpretCast(ooTreeLeafNodeMap *, this->vm());
}


/* methods on ooRef(ooTreeLeafNodeMap) */
inline
ooRef(ooTreeLeafNodeMap)::ooRefStructor(ooTreeLeafNodeMap)(const ooHandleSuper(ooTreeLeafNodeMap)& objH) :
    ooRef(ooTreeLeafNode)(objH)
{
}
inline
ooRef(ooTreeLeafNodeMap)::ooRefStructor(ooTreeLeafNodeMap)(const ooTreeLeafNodeMap *  fromObject) :
    ooRef(ooTreeLeafNode)(ooReinterpretCast(const ooTreeLeafNode *, fromObject))
{
}
inline
ooRef(ooTreeLeafNodeMap)&
ooRef(ooTreeLeafNodeMap)::operator=(const ooRef(ooTreeLeafNodeMap) &  id)
{
  this->ooId::operator=(id);
  return *this;
}
inline
ooRef(ooTreeLeafNodeMap)&
ooRef(ooTreeLeafNodeMap)::operator=(const ooShortRefSuper(ooTreeLeafNodeMap) &  shortId)
{
  this->ooRef(ooObj)::operator=(shortId);
  return *this;
}
inline
ooRef(ooTreeLeafNodeMap)&
ooRef(ooTreeLeafNodeMap)::operator=(const ooHandleSuper(ooTreeLeafNodeMap) &  objH)
{
  this->ooRef(ooObj)::operator=(objH);
  return *this;
}
inline
ooRef(ooTreeLeafNodeMap)&
ooRef(ooTreeLeafNodeMap)::operator=(const ooTreeLeafNodeMap *  fromObject)
{
  this->ooRef(ooObj)::operator=(ooReinterpretCast(const ooObj *, fromObject));
  return *this;
}
inline
ooTreeLeafNodeMap *
ooRef(ooTreeLeafNodeMap)::pin(ooMode  openMode) const
{
  return ooReinterpretCast(ooTreeLeafNodeMap *, this->pin_ref_internal(openMode));
}
inline
ooTreeLeafNodeMap *
ooRef(ooTreeLeafNodeMap)::vm(ooMode  openMode) const
{
  return this->pin(openMode);
}
#ifndef OO_BUGGY_TEMPLATES
inline
ooHandle(ooTreeLeafNodeMap) &
ooRef(ooTreeLeafNodeMap)::copy(const ooHandle(ooObj) &  nearH,
		ooHandle(ooTreeLeafNodeMap) &           result) const
{
  this->ooRef(ooObj)::copy(nearH, result);
  return result;
}
inline
ooRef(ooTreeLeafNodeMap) &
ooRef(ooTreeLeafNodeMap)::copy(const ooHandle(ooObj) &  nearH,
		ooRef(ooTreeLeafNodeMap) &              newObjRef) const
{
  this->ooRef(ooObj)::copy(nearH, newObjRef);
  return newObjRef;
}
inline
ooHandle(ooTreeLeafNodeMap)
ooRef(ooTreeLeafNodeMap)::copy(const ooHandle(ooObj) &  nearH) const
{
  ooHandle(ooTreeLeafNodeMap) result;
  this->ooRef(ooObj)::copy(nearH, result);
  return result;
}
#endif // !defined(OO_BUGGY_TEMPLATES)
inline
ooDeref(ooTreeLeafNodeMap)
ooRef(ooTreeLeafNodeMap)::operator->() const
{
  ooDeref(ooTreeLeafNodeMap) result(this->pin_ref_internal(oocRead));
  return result;
}


/* methods on ooShortRef(ooTreeLeafNodeMap) */
inline
ooShortRef(ooTreeLeafNodeMap) &
ooShortRef(ooTreeLeafNodeMap)::operator=(const ooShortRef(ooTreeLeafNodeMap) &  shortId)
{
  this->ooShortId::operator=(shortId);
  return *this;
}
inline
ooShortRef(ooTreeLeafNodeMap) &
ooShortRef(ooTreeLeafNodeMap)::operator=(const ooRef(ooTreeLeafNodeMap) &  id)
{
  this->ooShortId::operator=(id);
  return *this;
}
inline
ooShortRef(ooTreeLeafNodeMap) &
ooShortRef(ooTreeLeafNodeMap)::operator=(const ooHandleSuper(ooTreeLeafNodeMap) &  objH)
{
  this->ooShortId::operator=(objH);
  return *this;
}
inline
ooShortRef(ooTreeLeafNodeMap)&
ooShortRef(ooTreeLeafNodeMap)::operator=(const ooTreeLeafNodeMap *  fromObject)
{
  this->ooShortId::operator=(ooReinterpretCast(const ooObj *,fromObject));
  return *this;
}
inline
ooShortRef(ooTreeLeafNodeMap)::ooShortRefStructor(ooTreeLeafNodeMap)()
{
}
#ifdef OO_BUGGY_TEMPLATES
inline
ooShortRef(ooTreeLeafNodeMap)::ooShortRefStructor(ooTreeLeafNodeMap)(const ooShortRef(ooTreeLeafNodeMap) &  shortId)
{
  *this = shortId;
}
#else // !defined(OO_BUGGY_TEMPLATES)
inline
ooShortRef(ooTreeLeafNodeMap)::ooShortRefStructor(ooTreeLeafNodeMap)(const ooShortRef(ooTreeLeafNodeMap) &  shortId) :
    ooShortRef(ooTreeLeafNode)(shortId)
{
}
#endif // !defined(OO_BUGGY_TEMPLATES)
#ifdef OO_BUGGY_TEMPLATES
inline
ooShortRef(ooTreeLeafNodeMap)::ooShortRefStructor(ooTreeLeafNodeMap)(const ooRef(ooTreeLeafNodeMap) &  id)
{
  *this = id;
}
#else // !defined(OO_BUGGY_TEMPLATES)
inline
ooShortRef(ooTreeLeafNodeMap)::ooShortRefStructor(ooTreeLeafNodeMap)(const ooRef(ooTreeLeafNodeMap) &  id) :
    ooShortRef(ooTreeLeafNode)(id)
{
}
#endif // !defined(OO_BUGGY_TEMPLATES)
#ifdef OO_BUGGY_TEMPLATES
inline
ooShortRef(ooTreeLeafNodeMap)::ooShortRefStructor(ooTreeLeafNodeMap)(const ooHandleSuper(ooTreeLeafNodeMap) &  objH)
{
  *this = objH;
}
#else // !defined(OO_BUGGY_TEMPLATES)
inline
ooShortRef(ooTreeLeafNodeMap)::ooShortRefStructor(ooTreeLeafNodeMap)(const ooHandleSuper(ooTreeLeafNodeMap) &  objH) :
    ooShortRef(ooTreeLeafNode)(objH)
{
}
#endif // !defined(OO_BUGGY_TEMPLATES)
#ifdef OO_BUGGY_TEMPLATES
inline
ooShortRef(ooTreeLeafNodeMap)::ooShortRefStructor(ooTreeLeafNodeMap)(const ooTreeLeafNodeMap *  fromObject)
{
  *this = fromObject;
}
#else // !defined(OO_BUGGY_TEMPLATES)
inline
ooShortRef(ooTreeLeafNodeMap)::ooShortRefStructor(ooTreeLeafNodeMap)(const ooTreeLeafNodeMap *  fromObject) :
    ooShortRef(ooTreeLeafNode)(ooReinterpretCast(const ooTreeLeafNode *,fromObject))
{
}
#endif // !defined(OO_BUGGY_TEMPLATES)


/* methods on ooHandle(ooTreeLeafNodeMap) */
inline
ooHandle(ooTreeLeafNodeMap)::ooHandleStructor(ooTreeLeafNodeMap)()
{
}
inline
ooHandle(ooTreeLeafNodeMap)::ooHandleStructor(ooTreeLeafNodeMap)(const ooHandle(ooTreeLeafNodeMap) &  objH) :
#ifdef OO_BUGGY_TEMPLATES
    ooHandle_superclass<ooTreeLeafNodeMap >(objH)
#else // !defined(OO_BUGGY_TEMPLATES)
    ooHandle(ooTreeLeafNode)(objH)
#endif // !defined(OO_BUGGY_TEMPLATES)
{
}
inline
ooHandle(ooTreeLeafNodeMap)::ooHandleStructor(ooTreeLeafNodeMap)(const ooRef(ooTreeLeafNodeMap) &  id) :
#ifdef OO_BUGGY_TEMPLATES
    ooHandle_superclass<ooTreeLeafNodeMap >(id)
#else // !defined(OO_BUGGY_TEMPLATES)
    ooHandle(ooTreeLeafNode)(id)
#endif // !defined(OO_BUGGY_TEMPLATES)
{
}
inline
ooHandle(ooTreeLeafNodeMap)::ooHandleStructor(ooTreeLeafNodeMap)(const ooTreeLeafNodeMap *  fromObject) :
#ifdef OO_BUGGY_TEMPLATES
    ooHandle_superclass<ooTreeLeafNodeMap >(ooReinterpretCast(const ooTreeLeafNode *,fromObject))
#else // !defined(OO_BUGGY_TEMPLATES)
    ooHandle(ooTreeLeafNode)(ooReinterpretCast(const ooTreeLeafNode *,fromObject))
#endif // !defined(OO_BUGGY_TEMPLATES)
{
}
inline
ooHandle(ooTreeLeafNodeMap)&
ooHandle(ooTreeLeafNodeMap)::operator=(const ooRef(ooTreeLeafNodeMap) &  id)
{
  this->ooHandle(ooObj)::operator=(id);
  return *this;
}
inline
ooHandle(ooTreeLeafNodeMap)&
ooHandle(ooTreeLeafNodeMap)::operator=(const ooHandle(ooTreeLeafNodeMap) &  objH)
{
  this->ooHandle(ooObj)::operator=(objH);
  return *this;
}
inline
ooHandle(ooTreeLeafNodeMap)&
ooHandle(ooTreeLeafNodeMap)::operator=(const ooShortRef(ooTreeLeafNodeMap) &  shortId)
{
  this->ooHandle(ooObj)::operator=(shortId);
  return *this;
}
inline
ooHandle(ooTreeLeafNodeMap)&
ooHandle(ooTreeLeafNodeMap)::operator=(const ooTreeLeafNodeMap *  fromObject)
{
  this->ooHandle(ooObj)::operator=(ooReinterpretCast(const ooObj *,fromObject));
  return *this;
}
inline
ooTreeLeafNodeMap *
ooHandle(ooTreeLeafNodeMap)::pin(ooMode  openMode) const
{
  return ooReinterpretCast(ooTreeLeafNodeMap *, this->pin_obj_internal(openMode));
}
inline
ooTreeLeafNodeMap *
ooHandle(ooTreeLeafNodeMap)::operator->() const
{
  return this->vm();
}
inline
ooTreeLeafNodeMap &
ooHandle(ooTreeLeafNodeMap)::operator*() const
{
  return *(this->vm());
}
inline
ooHandle(ooTreeLeafNodeMap)::operator ooTreeLeafNodeMap *() const
{
  if ( _state == oocHandlePTR  )
    return ooReinterpretCast(ooTreeLeafNodeMap *, _ptr._obj);
  else return ooReinterpretCast(ooTreeLeafNodeMap *, this->get_vm());
}
inline
ooTreeLeafNodeMap *
ooHandle(ooTreeLeafNodeMap)::vm() const
{
  if ( _state == oocHandlePTR && _ptr._obj != NULL )
    return ooReinterpretCast(ooTreeLeafNodeMap *, _ptr._obj);
  else return ooReinterpretCast(ooTreeLeafNodeMap *, this->get_vm());
}
inline
ooRef(ooTreeLeafNodeMap) &
ooHandle(ooTreeLeafNodeMap)::copy(const ooHandle(ooObj) &  nearH,
		   ooRef(ooTreeLeafNodeMap) &              result) const
{
  this->ooHandle(ooObj)::copy(nearH, result);
  return result;
}


/* ODMG methods */
inline
ooTreeLeafNodeMap *
ooRef(ooTreeLeafNodeMap)::ptr() const
{
  return this->pin();
}
inline
ooTreeLeafNodeMap *
ooHandle(ooTreeLeafNodeMap)::ptr() const
{
  return this->operator ooTreeLeafNodeMap *();
}
class ooTreeSetX;


/////////////////////////////////////////////////////////////////////////////

ooTemplateSpecialization
class ooDeref(ooTreeSetX) : public ooDerefBase {
	friend class ooRef(ooTreeSetX);
  public:
    ~ooDerefStructor(ooTreeSetX)();
    inline ooTreeSetX *operator->() const;
#ifndef OO_BUGGY_TEMPLATES
  private:
#endif // !defined(OO_BUGGY_TEMPLATES)
    ooDerefStructor(ooTreeSetX)(ooDeref(ooTreeSetX)& deref);
    ooDerefStructor(ooTreeSetX)(ooObj *  fromObject);
};


#ifdef OO_BUGGY_TEMPLATES

class ooHandle_superclass<ooTreeSetX > : public ooHandle(ooTreeBasedCollection) {
 protected:
  ooHandle_superclass()
    {}
  ooHandle_superclass(const ooHandle(ooTreeBasedCollection) &  from) :
      ooHandle(ooTreeBasedCollection)(from)
    {}
  ooHandle_superclass(const ooRef(ooTreeBasedCollection) &  from) :
      ooHandle(ooTreeBasedCollection)(from)
    {}
  ooHandle_superclass(const ooTreeBasedCollection *  from) :
      ooHandle(ooTreeBasedCollection)(from)
    {}
  ~ooHandle_superclass()
    {}
};

class ooShortRef_superclass<ooTreeSetX > : public ooShortRef(ooTreeBasedCollection) {
};

#endif // OO_BUGGY_TEMPLATES

ooTemplateSpecialization
class ooRef(ooTreeSetX) : public ooRef(ooTreeBasedCollection) {
  public:
    ooRefStructor(ooTreeSetX)()
      {}
    ooRefStructor(ooTreeSetX)(const ooRef(ooTreeSetX)& id) :
	  ooRef(ooTreeBasedCollection)(id)
      {}
    inline ooRefStructor(ooTreeSetX)(const ooHandleSuper(ooTreeSetX)& objH);
    inline ooRefStructor(ooTreeSetX)(const ooTreeSetX *  fromObject);
    inline ooRef(ooTreeSetX)& operator=(const ooRef(ooTreeSetX)& id);
    inline ooRef(ooTreeSetX)& operator=(const ooShortRefSuper(ooTreeSetX) &shortId);
    inline ooRef(ooTreeSetX)& operator=(const ooHandleSuper(ooTreeSetX)& objH);
    inline ooRef(ooTreeSetX)& operator=(const ooTreeSetX *  fromObject);
    ooStatus lookupObj(const ooHandle(ooObj)& scopeH,
		       const ooKey& key,
		       ooMode openMode = oocRead);
    ooStatus lookupObj(const ooHandle(ooObj)& scopeH,
		       const char* name,
		       ooMode openMode = oocRead);
#ifndef OO_BUGGY_TEMPLATES
    inline ooRef(ooTreeSetX)& copy(const ooHandle(ooObj)& nearH,
		    ooRef(ooTreeSetX)& newObjRef) const;
    inline ooHandle(ooTreeSetX)& copy(const ooHandle(ooObj)& nearH,
			ooHandle(ooTreeSetX)& result) const;
    inline ooHandle(ooTreeSetX) copy(const ooHandle(ooObj)& nearH) const;
#endif // !defined(OO_BUGGY_TEMPLATES)
    inline ooTreeSetX *pin(ooMode openMode = oocRead) const;
    ooDeref(ooTreeSetX) operator->() const;
    /* Use pin() or use ooHandle "operator ooTreeSetX *" instead of vm. */
    /* OBSOLETE */ inline ooTreeSetX *vm(ooMode openMode = oocRead) const;
    // ODMG methods:
    ooRefStructor(ooTreeSetX)(const d_Ref_Any &from);
    ooTreeSetX *ptr() const;
};

ooTemplateSpecialization
class ooShortRef(ooTreeSetX) :
#ifdef OO_BUGGY_TEMPLATES
			public ooShortRef_superclass<ooTreeSetX >
#else // !defined(OO_BUGGY_TEMPLATES)
			public ooShortRef(ooTreeBasedCollection)
#endif // !defined(OO_BUGGY_TEMPLATES)
					            {
  public:
    ooShortRefStructor(ooTreeSetX)();
    ooShortRefStructor(ooTreeSetX)(const ooShortRef(ooTreeSetX)& shortId);
    ooShortRefStructor(ooTreeSetX)(const ooRef(ooTreeSetX)& id);
    ooShortRefStructor(ooTreeSetX)(const ooHandleSuper(ooTreeSetX) &objH);
    ooShortRefStructor(ooTreeSetX)(const ooTreeSetX *  fromObject);
    ooShortRef(ooTreeSetX)& operator=(const ooShortRef(ooTreeSetX)& shortId);
    ooShortRef(ooTreeSetX)& operator=(const ooRef(ooTreeSetX)& id);
    ooShortRef(ooTreeSetX)& operator=(const ooHandleSuper(ooTreeSetX) &objH);
    ooShortRef(ooTreeSetX)& operator=(const ooTreeSetX *  fromObject);
};

ooTemplateSpecialization
class ooHandle(ooTreeSetX) :
#ifdef OO_BUGGY_TEMPLATES
		      public ooHandle_superclass<ooTreeSetX >
#else // !defined(OO_BUGGY_TEMPLATES)
		      public ooHandle(ooTreeBasedCollection)
#endif // !defined(OO_BUGGY_TEMPLATES)
                                                {
  public:
    inline ooHandleStructor(ooTreeSetX)();
    inline ooHandleStructor(ooTreeSetX)(const ooRef(ooTreeSetX)& id);
    inline ooHandleStructor(ooTreeSetX)(const ooHandle(ooTreeSetX)& objH);
    inline ooHandleStructor(ooTreeSetX)(const ooTreeSetX *  fromObject);
    inline ooHandle(ooTreeSetX)& operator=(const ooRef(ooTreeSetX)& id);
    inline ooHandle(ooTreeSetX)& operator=(const ooHandle(ooTreeSetX)& objH);
    inline ooHandle(ooTreeSetX)& operator=(const ooShortRef(ooTreeSetX)& shortId);
    inline ooHandle(ooTreeSetX)& operator=(const ooTreeSetX *  fromObject);
    ooStatus lookupObj(const ooHandle(ooObj)& scopeH,
		       const ooKey& key,
		       ooMode openMode = oocRead);
    ooStatus lookupObj(const ooHandle(ooObj)& scopeH,
		       const char* name,
		       ooMode openMode = oocRead);
    ooHandle(ooTreeSetX)& copy(const ooHandle(ooObj)& nearH,
		       ooHandle(ooTreeSetX)& result) const;
    inline ooRef(ooTreeSetX)& copy(const ooHandle(ooObj)& nearH,
		    ooRef(ooTreeSetX)& result) const;
    ooHandle(ooTreeSetX) copy(const ooHandle(ooObj)& nearH) const;
    inline ooTreeSetX *pin(ooMode openMode = oocRead) const;
    inline ooTreeSetX *operator->() const;
    inline ooTreeSetX &operator*() const;
    inline operator ooTreeSetX *() const;
    /* Use "operator ooTreeSetX *" instead of vm. */
    /* OBSOLETE */ inline ooTreeSetX *vm() const;
    // ODMG methods:
    ooHandleStructor(ooTreeSetX)(const d_Ref_Any &from);
    ooTreeSetX *ptr() const;
};

ooTemplateSpecialization
class ooItr(ooTreeSetX) : public ooHandle(ooTreeSetX),
		    public ooIteratorObjOrContObj {
  public:
    ooItrStructor(ooTreeSetX)();
    ~ooItrStructor(ooTreeSetX)();
  private:
    // Defined only to prevent implicit definition:
    ooItrStructor(ooTreeSetX)(ooItr(ooTreeSetX)&);
    ooItr(ooTreeSetX)    operator=(ooItr(ooTreeSetX)&);
};


/* methods on ooDeref(ooTreeSetX) */
inline
ooDeref(ooTreeSetX)::ooDerefStructor(ooTreeSetX)(ooDeref(ooTreeSetX) &  deref) :
    ooDerefBase(deref.vm())
{
  this->pinCompensate();
}
inline
ooDeref(ooTreeSetX)::ooDerefStructor(ooTreeSetX)(ooObj *  fromObject) :
    ooDerefBase(fromObject)
{
}
inline
ooDeref(ooTreeSetX)::~ooDerefStructor(ooTreeSetX)()
{
}
inline
ooTreeSetX *
ooDeref(ooTreeSetX)::operator->() const
{
  return ooReinterpretCast(ooTreeSetX *, this->vm());
}


/* methods on ooRef(ooTreeSetX) */
inline
ooRef(ooTreeSetX)::ooRefStructor(ooTreeSetX)(const ooHandleSuper(ooTreeSetX)& objH) :
    ooRef(ooTreeBasedCollection)(objH)
{
}
inline
ooRef(ooTreeSetX)::ooRefStructor(ooTreeSetX)(const ooTreeSetX *  fromObject) :
    ooRef(ooTreeBasedCollection)(ooReinterpretCast(const ooTreeBasedCollection *, fromObject))
{
}
inline
ooRef(ooTreeSetX)&
ooRef(ooTreeSetX)::operator=(const ooRef(ooTreeSetX) &  id)
{
  this->ooId::operator=(id);
  return *this;
}
inline
ooRef(ooTreeSetX)&
ooRef(ooTreeSetX)::operator=(const ooShortRefSuper(ooTreeSetX) &  shortId)
{
  this->ooRef(ooObj)::operator=(shortId);
  return *this;
}
inline
ooRef(ooTreeSetX)&
ooRef(ooTreeSetX)::operator=(const ooHandleSuper(ooTreeSetX) &  objH)
{
  this->ooRef(ooObj)::operator=(objH);
  return *this;
}
inline
ooRef(ooTreeSetX)&
ooRef(ooTreeSetX)::operator=(const ooTreeSetX *  fromObject)
{
  this->ooRef(ooObj)::operator=(ooReinterpretCast(const ooObj *, fromObject));
  return *this;
}
inline
ooTreeSetX *
ooRef(ooTreeSetX)::pin(ooMode  openMode) const
{
  return ooReinterpretCast(ooTreeSetX *, this->pin_ref_internal(openMode));
}
inline
ooTreeSetX *
ooRef(ooTreeSetX)::vm(ooMode  openMode) const
{
  return this->pin(openMode);
}
#ifndef OO_BUGGY_TEMPLATES
inline
ooHandle(ooTreeSetX) &
ooRef(ooTreeSetX)::copy(const ooHandle(ooObj) &  nearH,
		ooHandle(ooTreeSetX) &           result) const
{
  this->ooRef(ooObj)::copy(nearH, result);
  return result;
}
inline
ooRef(ooTreeSetX) &
ooRef(ooTreeSetX)::copy(const ooHandle(ooObj) &  nearH,
		ooRef(ooTreeSetX) &              newObjRef) const
{
  this->ooRef(ooObj)::copy(nearH, newObjRef);
  return newObjRef;
}
inline
ooHandle(ooTreeSetX)
ooRef(ooTreeSetX)::copy(const ooHandle(ooObj) &  nearH) const
{
  ooHandle(ooTreeSetX) result;
  this->ooRef(ooObj)::copy(nearH, result);
  return result;
}
#endif // !defined(OO_BUGGY_TEMPLATES)
inline
ooDeref(ooTreeSetX)
ooRef(ooTreeSetX)::operator->() const
{
  ooDeref(ooTreeSetX) result(this->pin_ref_internal(oocRead));
  return result;
}


/* methods on ooShortRef(ooTreeSetX) */
inline
ooShortRef(ooTreeSetX) &
ooShortRef(ooTreeSetX)::operator=(const ooShortRef(ooTreeSetX) &  shortId)
{
  this->ooShortId::operator=(shortId);
  return *this;
}
inline
ooShortRef(ooTreeSetX) &
ooShortRef(ooTreeSetX)::operator=(const ooRef(ooTreeSetX) &  id)
{
  this->ooShortId::operator=(id);
  return *this;
}
inline
ooShortRef(ooTreeSetX) &
ooShortRef(ooTreeSetX)::operator=(const ooHandleSuper(ooTreeSetX) &  objH)
{
  this->ooShortId::operator=(objH);
  return *this;
}
inline
ooShortRef(ooTreeSetX)&
ooShortRef(ooTreeSetX)::operator=(const ooTreeSetX *  fromObject)
{
  this->ooShortId::operator=(ooReinterpretCast(const ooObj *,fromObject));
  return *this;
}
inline
ooShortRef(ooTreeSetX)::ooShortRefStructor(ooTreeSetX)()
{
}
#ifdef OO_BUGGY_TEMPLATES
inline
ooShortRef(ooTreeSetX)::ooShortRefStructor(ooTreeSetX)(const ooShortRef(ooTreeSetX) &  shortId)
{
  *this = shortId;
}
#else // !defined(OO_BUGGY_TEMPLATES)
inline
ooShortRef(ooTreeSetX)::ooShortRefStructor(ooTreeSetX)(const ooShortRef(ooTreeSetX) &  shortId) :
    ooShortRef(ooTreeBasedCollection)(shortId)
{
}
#endif // !defined(OO_BUGGY_TEMPLATES)
#ifdef OO_BUGGY_TEMPLATES
inline
ooShortRef(ooTreeSetX)::ooShortRefStructor(ooTreeSetX)(const ooRef(ooTreeSetX) &  id)
{
  *this = id;
}
#else // !defined(OO_BUGGY_TEMPLATES)
inline
ooShortRef(ooTreeSetX)::ooShortRefStructor(ooTreeSetX)(const ooRef(ooTreeSetX) &  id) :
    ooShortRef(ooTreeBasedCollection)(id)
{
}
#endif // !defined(OO_BUGGY_TEMPLATES)
#ifdef OO_BUGGY_TEMPLATES
inline
ooShortRef(ooTreeSetX)::ooShortRefStructor(ooTreeSetX)(const ooHandleSuper(ooTreeSetX) &  objH)
{
  *this = objH;
}
#else // !defined(OO_BUGGY_TEMPLATES)
inline
ooShortRef(ooTreeSetX)::ooShortRefStructor(ooTreeSetX)(const ooHandleSuper(ooTreeSetX) &  objH) :
    ooShortRef(ooTreeBasedCollection)(objH)
{
}
#endif // !defined(OO_BUGGY_TEMPLATES)
#ifdef OO_BUGGY_TEMPLATES
inline
ooShortRef(ooTreeSetX)::ooShortRefStructor(ooTreeSetX)(const ooTreeSetX *  fromObject)
{
  *this = fromObject;
}
#else // !defined(OO_BUGGY_TEMPLATES)
inline
ooShortRef(ooTreeSetX)::ooShortRefStructor(ooTreeSetX)(const ooTreeSetX *  fromObject) :
    ooShortRef(ooTreeBasedCollection)(ooReinterpretCast(const ooTreeBasedCollection *,fromObject))
{
}
#endif // !defined(OO_BUGGY_TEMPLATES)


/* methods on ooHandle(ooTreeSetX) */
inline
ooHandle(ooTreeSetX)::ooHandleStructor(ooTreeSetX)()
{
}
inline
ooHandle(ooTreeSetX)::ooHandleStructor(ooTreeSetX)(const ooHandle(ooTreeSetX) &  objH) :
#ifdef OO_BUGGY_TEMPLATES
    ooHandle_superclass<ooTreeSetX >(objH)
#else // !defined(OO_BUGGY_TEMPLATES)
    ooHandle(ooTreeBasedCollection)(objH)
#endif // !defined(OO_BUGGY_TEMPLATES)
{
}
inline
ooHandle(ooTreeSetX)::ooHandleStructor(ooTreeSetX)(const ooRef(ooTreeSetX) &  id) :
#ifdef OO_BUGGY_TEMPLATES
    ooHandle_superclass<ooTreeSetX >(id)
#else // !defined(OO_BUGGY_TEMPLATES)
    ooHandle(ooTreeBasedCollection)(id)
#endif // !defined(OO_BUGGY_TEMPLATES)
{
}
inline
ooHandle(ooTreeSetX)::ooHandleStructor(ooTreeSetX)(const ooTreeSetX *  fromObject) :
#ifdef OO_BUGGY_TEMPLATES
    ooHandle_superclass<ooTreeSetX >(ooReinterpretCast(const ooTreeBasedCollection *,fromObject))
#else // !defined(OO_BUGGY_TEMPLATES)
    ooHandle(ooTreeBasedCollection)(ooReinterpretCast(const ooTreeBasedCollection *,fromObject))
#endif // !defined(OO_BUGGY_TEMPLATES)
{
}
inline
ooHandle(ooTreeSetX)&
ooHandle(ooTreeSetX)::operator=(const ooRef(ooTreeSetX) &  id)
{
  this->ooHandle(ooObj)::operator=(id);
  return *this;
}
inline
ooHandle(ooTreeSetX)&
ooHandle(ooTreeSetX)::operator=(const ooHandle(ooTreeSetX) &  objH)
{
  this->ooHandle(ooObj)::operator=(objH);
  return *this;
}
inline
ooHandle(ooTreeSetX)&
ooHandle(ooTreeSetX)::operator=(const ooShortRef(ooTreeSetX) &  shortId)
{
  this->ooHandle(ooObj)::operator=(shortId);
  return *this;
}
inline
ooHandle(ooTreeSetX)&
ooHandle(ooTreeSetX)::operator=(const ooTreeSetX *  fromObject)
{
  this->ooHandle(ooObj)::operator=(ooReinterpretCast(const ooObj *,fromObject));
  return *this;
}
inline
ooTreeSetX *
ooHandle(ooTreeSetX)::pin(ooMode  openMode) const
{
  return ooReinterpretCast(ooTreeSetX *, this->pin_obj_internal(openMode));
}
inline
ooTreeSetX *
ooHandle(ooTreeSetX)::operator->() const
{
  return this->vm();
}
inline
ooTreeSetX &
ooHandle(ooTreeSetX)::operator*() const
{
  return *(this->vm());
}
inline
ooHandle(ooTreeSetX)::operator ooTreeSetX *() const
{
  if ( _state == oocHandlePTR  )
    return ooReinterpretCast(ooTreeSetX *, _ptr._obj);
  else return ooReinterpretCast(ooTreeSetX *, this->get_vm());
}
inline
ooTreeSetX *
ooHandle(ooTreeSetX)::vm() const
{
  if ( _state == oocHandlePTR && _ptr._obj != NULL )
    return ooReinterpretCast(ooTreeSetX *, _ptr._obj);
  else return ooReinterpretCast(ooTreeSetX *, this->get_vm());
}
inline
ooRef(ooTreeSetX) &
ooHandle(ooTreeSetX)::copy(const ooHandle(ooObj) &  nearH,
		   ooRef(ooTreeSetX) &              result) const
{
  this->ooHandle(ooObj)::copy(nearH, result);
  return result;
}


/* ODMG methods */
inline
ooTreeSetX *
ooRef(ooTreeSetX)::ptr() const
{
  return this->pin();
}
inline
ooTreeSetX *
ooHandle(ooTreeSetX)::ptr() const
{
  return this->operator ooTreeSetX *();
}
class ooTreeListX;


/////////////////////////////////////////////////////////////////////////////

ooTemplateSpecialization
class ooDeref(ooTreeListX) : public ooDerefBase {
	friend class ooRef(ooTreeListX);
  public:
    ~ooDerefStructor(ooTreeListX)();
    inline ooTreeListX *operator->() const;
#ifndef OO_BUGGY_TEMPLATES
  private:
#endif // !defined(OO_BUGGY_TEMPLATES)
    ooDerefStructor(ooTreeListX)(ooDeref(ooTreeListX)& deref);
    ooDerefStructor(ooTreeListX)(ooObj *  fromObject);
};


#ifdef OO_BUGGY_TEMPLATES

class ooHandle_superclass<ooTreeListX > : public ooHandle(ooTreeBasedCollection) {
 protected:
  ooHandle_superclass()
    {}
  ooHandle_superclass(const ooHandle(ooTreeBasedCollection) &  from) :
      ooHandle(ooTreeBasedCollection)(from)
    {}
  ooHandle_superclass(const ooRef(ooTreeBasedCollection) &  from) :
      ooHandle(ooTreeBasedCollection)(from)
    {}
  ooHandle_superclass(const ooTreeBasedCollection *  from) :
      ooHandle(ooTreeBasedCollection)(from)
    {}
  ~ooHandle_superclass()
    {}
};

class ooShortRef_superclass<ooTreeListX > : public ooShortRef(ooTreeBasedCollection) {
};

#endif // OO_BUGGY_TEMPLATES

ooTemplateSpecialization
class ooRef(ooTreeListX) : public ooRef(ooTreeBasedCollection) {
  public:
    ooRefStructor(ooTreeListX)()
      {}
    ooRefStructor(ooTreeListX)(const ooRef(ooTreeListX)& id) :
	  ooRef(ooTreeBasedCollection)(id)
      {}
    inline ooRefStructor(ooTreeListX)(const ooHandleSuper(ooTreeListX)& objH);
    inline ooRefStructor(ooTreeListX)(const ooTreeListX *  fromObject);
    inline ooRef(ooTreeListX)& operator=(const ooRef(ooTreeListX)& id);
    inline ooRef(ooTreeListX)& operator=(const ooShortRefSuper(ooTreeListX) &shortId);
    inline ooRef(ooTreeListX)& operator=(const ooHandleSuper(ooTreeListX)& objH);
    inline ooRef(ooTreeListX)& operator=(const ooTreeListX *  fromObject);
    ooStatus lookupObj(const ooHandle(ooObj)& scopeH,
		       const ooKey& key,
		       ooMode openMode = oocRead);
    ooStatus lookupObj(const ooHandle(ooObj)& scopeH,
		       const char* name,
		       ooMode openMode = oocRead);
#ifndef OO_BUGGY_TEMPLATES
    inline ooRef(ooTreeListX)& copy(const ooHandle(ooObj)& nearH,
		    ooRef(ooTreeListX)& newObjRef) const;
    inline ooHandle(ooTreeListX)& copy(const ooHandle(ooObj)& nearH,
			ooHandle(ooTreeListX)& result) const;
    inline ooHandle(ooTreeListX) copy(const ooHandle(ooObj)& nearH) const;
#endif // !defined(OO_BUGGY_TEMPLATES)
    inline ooTreeListX *pin(ooMode openMode = oocRead) const;
    ooDeref(ooTreeListX) operator->() const;
    /* Use pin() or use ooHandle "operator ooTreeListX *" instead of vm. */
    /* OBSOLETE */ inline ooTreeListX *vm(ooMode openMode = oocRead) const;
    // ODMG methods:
    ooRefStructor(ooTreeListX)(const d_Ref_Any &from);
    ooTreeListX *ptr() const;
};

ooTemplateSpecialization
class ooShortRef(ooTreeListX) :
#ifdef OO_BUGGY_TEMPLATES
			public ooShortRef_superclass<ooTreeListX >
#else // !defined(OO_BUGGY_TEMPLATES)
			public ooShortRef(ooTreeBasedCollection)
#endif // !defined(OO_BUGGY_TEMPLATES)
					            {
  public:
    ooShortRefStructor(ooTreeListX)();
    ooShortRefStructor(ooTreeListX)(const ooShortRef(ooTreeListX)& shortId);
    ooShortRefStructor(ooTreeListX)(const ooRef(ooTreeListX)& id);
    ooShortRefStructor(ooTreeListX)(const ooHandleSuper(ooTreeListX) &objH);
    ooShortRefStructor(ooTreeListX)(const ooTreeListX *  fromObject);
    ooShortRef(ooTreeListX)& operator=(const ooShortRef(ooTreeListX)& shortId);
    ooShortRef(ooTreeListX)& operator=(const ooRef(ooTreeListX)& id);
    ooShortRef(ooTreeListX)& operator=(const ooHandleSuper(ooTreeListX) &objH);
    ooShortRef(ooTreeListX)& operator=(const ooTreeListX *  fromObject);
};

ooTemplateSpecialization
class ooHandle(ooTreeListX) :
#ifdef OO_BUGGY_TEMPLATES
		      public ooHandle_superclass<ooTreeListX >
#else // !defined(OO_BUGGY_TEMPLATES)
		      public ooHandle(ooTreeBasedCollection)
#endif // !defined(OO_BUGGY_TEMPLATES)
                                                {
  public:
    inline ooHandleStructor(ooTreeListX)();
    inline ooHandleStructor(ooTreeListX)(const ooRef(ooTreeListX)& id);
    inline ooHandleStructor(ooTreeListX)(const ooHandle(ooTreeListX)& objH);
    inline ooHandleStructor(ooTreeListX)(const ooTreeListX *  fromObject);
    inline ooHandle(ooTreeListX)& operator=(const ooRef(ooTreeListX)& id);
    inline ooHandle(ooTreeListX)& operator=(const ooHandle(ooTreeListX)& objH);
    inline ooHandle(ooTreeListX)& operator=(const ooShortRef(ooTreeListX)& shortId);
    inline ooHandle(ooTreeListX)& operator=(const ooTreeListX *  fromObject);
    ooStatus lookupObj(const ooHandle(ooObj)& scopeH,
		       const ooKey& key,
		       ooMode openMode = oocRead);
    ooStatus lookupObj(const ooHandle(ooObj)& scopeH,
		       const char* name,
		       ooMode openMode = oocRead);
    ooHandle(ooTreeListX)& copy(const ooHandle(ooObj)& nearH,
		       ooHandle(ooTreeListX)& result) const;
    inline ooRef(ooTreeListX)& copy(const ooHandle(ooObj)& nearH,
		    ooRef(ooTreeListX)& result) const;
    ooHandle(ooTreeListX) copy(const ooHandle(ooObj)& nearH) const;
    inline ooTreeListX *pin(ooMode openMode = oocRead) const;
    inline ooTreeListX *operator->() const;
    inline ooTreeListX &operator*() const;
    inline operator ooTreeListX *() const;
    /* Use "operator ooTreeListX *" instead of vm. */
    /* OBSOLETE */ inline ooTreeListX *vm() const;
    // ODMG methods:
    ooHandleStructor(ooTreeListX)(const d_Ref_Any &from);
    ooTreeListX *ptr() const;
};

ooTemplateSpecialization
class ooItr(ooTreeListX) : public ooHandle(ooTreeListX),
		    public ooIteratorObjOrContObj {
  public:
    ooItrStructor(ooTreeListX)();
    ~ooItrStructor(ooTreeListX)();
  private:
    // Defined only to prevent implicit definition:
    ooItrStructor(ooTreeListX)(ooItr(ooTreeListX)&);
    ooItr(ooTreeListX)    operator=(ooItr(ooTreeListX)&);
};


/* methods on ooDeref(ooTreeListX) */
inline
ooDeref(ooTreeListX)::ooDerefStructor(ooTreeListX)(ooDeref(ooTreeListX) &  deref) :
    ooDerefBase(deref.vm())
{
  this->pinCompensate();
}
inline
ooDeref(ooTreeListX)::ooDerefStructor(ooTreeListX)(ooObj *  fromObject) :
    ooDerefBase(fromObject)
{
}
inline
ooDeref(ooTreeListX)::~ooDerefStructor(ooTreeListX)()
{
}
inline
ooTreeListX *
ooDeref(ooTreeListX)::operator->() const
{
  return ooReinterpretCast(ooTreeListX *, this->vm());
}


/* methods on ooRef(ooTreeListX) */
inline
ooRef(ooTreeListX)::ooRefStructor(ooTreeListX)(const ooHandleSuper(ooTreeListX)& objH) :
    ooRef(ooTreeBasedCollection)(objH)
{
}
inline
ooRef(ooTreeListX)::ooRefStructor(ooTreeListX)(const ooTreeListX *  fromObject) :
    ooRef(ooTreeBasedCollection)(ooReinterpretCast(const ooTreeBasedCollection *, fromObject))
{
}
inline
ooRef(ooTreeListX)&
ooRef(ooTreeListX)::operator=(const ooRef(ooTreeListX) &  id)
{
  this->ooId::operator=(id);
  return *this;
}
inline
ooRef(ooTreeListX)&
ooRef(ooTreeListX)::operator=(const ooShortRefSuper(ooTreeListX) &  shortId)
{
  this->ooRef(ooObj)::operator=(shortId);
  return *this;
}
inline
ooRef(ooTreeListX)&
ooRef(ooTreeListX)::operator=(const ooHandleSuper(ooTreeListX) &  objH)
{
  this->ooRef(ooObj)::operator=(objH);
  return *this;
}
inline
ooRef(ooTreeListX)&
ooRef(ooTreeListX)::operator=(const ooTreeListX *  fromObject)
{
  this->ooRef(ooObj)::operator=(ooReinterpretCast(const ooObj *, fromObject));
  return *this;
}
inline
ooTreeListX *
ooRef(ooTreeListX)::pin(ooMode  openMode) const
{
  return ooReinterpretCast(ooTreeListX *, this->pin_ref_internal(openMode));
}
inline
ooTreeListX *
ooRef(ooTreeListX)::vm(ooMode  openMode) const
{
  return this->pin(openMode);
}
#ifndef OO_BUGGY_TEMPLATES
inline
ooHandle(ooTreeListX) &
ooRef(ooTreeListX)::copy(const ooHandle(ooObj) &  nearH,
		ooHandle(ooTreeListX) &           result) const
{
  this->ooRef(ooObj)::copy(nearH, result);
  return result;
}
inline
ooRef(ooTreeListX) &
ooRef(ooTreeListX)::copy(const ooHandle(ooObj) &  nearH,
		ooRef(ooTreeListX) &              newObjRef) const
{
  this->ooRef(ooObj)::copy(nearH, newObjRef);
  return newObjRef;
}
inline
ooHandle(ooTreeListX)
ooRef(ooTreeListX)::copy(const ooHandle(ooObj) &  nearH) const
{
  ooHandle(ooTreeListX) result;
  this->ooRef(ooObj)::copy(nearH, result);
  return result;
}
#endif // !defined(OO_BUGGY_TEMPLATES)
inline
ooDeref(ooTreeListX)
ooRef(ooTreeListX)::operator->() const
{
  ooDeref(ooTreeListX) result(this->pin_ref_internal(oocRead));
  return result;
}


/* methods on ooShortRef(ooTreeListX) */
inline
ooShortRef(ooTreeListX) &
ooShortRef(ooTreeListX)::operator=(const ooShortRef(ooTreeListX) &  shortId)
{
  this->ooShortId::operator=(shortId);
  return *this;
}
inline
ooShortRef(ooTreeListX) &
ooShortRef(ooTreeListX)::operator=(const ooRef(ooTreeListX) &  id)
{
  this->ooShortId::operator=(id);
  return *this;
}
inline
ooShortRef(ooTreeListX) &
ooShortRef(ooTreeListX)::operator=(const ooHandleSuper(ooTreeListX) &  objH)
{
  this->ooShortId::operator=(objH);
  return *this;
}
inline
ooShortRef(ooTreeListX)&
ooShortRef(ooTreeListX)::operator=(const ooTreeListX *  fromObject)
{
  this->ooShortId::operator=(ooReinterpretCast(const ooObj *,fromObject));
  return *this;
}
inline
ooShortRef(ooTreeListX)::ooShortRefStructor(ooTreeListX)()
{
}
#ifdef OO_BUGGY_TEMPLATES
inline
ooShortRef(ooTreeListX)::ooShortRefStructor(ooTreeListX)(const ooShortRef(ooTreeListX) &  shortId)
{
  *this = shortId;
}
#else // !defined(OO_BUGGY_TEMPLATES)
inline
ooShortRef(ooTreeListX)::ooShortRefStructor(ooTreeListX)(const ooShortRef(ooTreeListX) &  shortId) :
    ooShortRef(ooTreeBasedCollection)(shortId)
{
}
#endif // !defined(OO_BUGGY_TEMPLATES)
#ifdef OO_BUGGY_TEMPLATES
inline
ooShortRef(ooTreeListX)::ooShortRefStructor(ooTreeListX)(const ooRef(ooTreeListX) &  id)
{
  *this = id;
}
#else // !defined(OO_BUGGY_TEMPLATES)
inline
ooShortRef(ooTreeListX)::ooShortRefStructor(ooTreeListX)(const ooRef(ooTreeListX) &  id) :
    ooShortRef(ooTreeBasedCollection)(id)
{
}
#endif // !defined(OO_BUGGY_TEMPLATES)
#ifdef OO_BUGGY_TEMPLATES
inline
ooShortRef(ooTreeListX)::ooShortRefStructor(ooTreeListX)(const ooHandleSuper(ooTreeListX) &  objH)
{
  *this = objH;
}
#else // !defined(OO_BUGGY_TEMPLATES)
inline
ooShortRef(ooTreeListX)::ooShortRefStructor(ooTreeListX)(const ooHandleSuper(ooTreeListX) &  objH) :
    ooShortRef(ooTreeBasedCollection)(objH)
{
}
#endif // !defined(OO_BUGGY_TEMPLATES)
#ifdef OO_BUGGY_TEMPLATES
inline
ooShortRef(ooTreeListX)::ooShortRefStructor(ooTreeListX)(const ooTreeListX *  fromObject)
{
  *this = fromObject;
}
#else // !defined(OO_BUGGY_TEMPLATES)
inline
ooShortRef(ooTreeListX)::ooShortRefStructor(ooTreeListX)(const ooTreeListX *  fromObject) :
    ooShortRef(ooTreeBasedCollection)(ooReinterpretCast(const ooTreeBasedCollection *,fromObject))
{
}
#endif // !defined(OO_BUGGY_TEMPLATES)


/* methods on ooHandle(ooTreeListX) */
inline
ooHandle(ooTreeListX)::ooHandleStructor(ooTreeListX)()
{
}
inline
ooHandle(ooTreeListX)::ooHandleStructor(ooTreeListX)(const ooHandle(ooTreeListX) &  objH) :
#ifdef OO_BUGGY_TEMPLATES
    ooHandle_superclass<ooTreeListX >(objH)
#else // !defined(OO_BUGGY_TEMPLATES)
    ooHandle(ooTreeBasedCollection)(objH)
#endif // !defined(OO_BUGGY_TEMPLATES)
{
}
inline
ooHandle(ooTreeListX)::ooHandleStructor(ooTreeListX)(const ooRef(ooTreeListX) &  id) :
#ifdef OO_BUGGY_TEMPLATES
    ooHandle_superclass<ooTreeListX >(id)
#else // !defined(OO_BUGGY_TEMPLATES)
    ooHandle(ooTreeBasedCollection)(id)
#endif // !defined(OO_BUGGY_TEMPLATES)
{
}
inline
ooHandle(ooTreeListX)::ooHandleStructor(ooTreeListX)(const ooTreeListX *  fromObject) :
#ifdef OO_BUGGY_TEMPLATES
    ooHandle_superclass<ooTreeListX >(ooReinterpretCast(const ooTreeBasedCollection *,fromObject))
#else // !defined(OO_BUGGY_TEMPLATES)
    ooHandle(ooTreeBasedCollection)(ooReinterpretCast(const ooTreeBasedCollection *,fromObject))
#endif // !defined(OO_BUGGY_TEMPLATES)
{
}
inline
ooHandle(ooTreeListX)&
ooHandle(ooTreeListX)::operator=(const ooRef(ooTreeListX) &  id)
{
  this->ooHandle(ooObj)::operator=(id);
  return *this;
}
inline
ooHandle(ooTreeListX)&
ooHandle(ooTreeListX)::operator=(const ooHandle(ooTreeListX) &  objH)
{
  this->ooHandle(ooObj)::operator=(objH);
  return *this;
}
inline
ooHandle(ooTreeListX)&
ooHandle(ooTreeListX)::operator=(const ooShortRef(ooTreeListX) &  shortId)
{
  this->ooHandle(ooObj)::operator=(shortId);
  return *this;
}
inline
ooHandle(ooTreeListX)&
ooHandle(ooTreeListX)::operator=(const ooTreeListX *  fromObject)
{
  this->ooHandle(ooObj)::operator=(ooReinterpretCast(const ooObj *,fromObject));
  return *this;
}
inline
ooTreeListX *
ooHandle(ooTreeListX)::pin(ooMode  openMode) const
{
  return ooReinterpretCast(ooTreeListX *, this->pin_obj_internal(openMode));
}
inline
ooTreeListX *
ooHandle(ooTreeListX)::operator->() const
{
  return this->vm();
}
inline
ooTreeListX &
ooHandle(ooTreeListX)::operator*() const
{
  return *(this->vm());
}
inline
ooHandle(ooTreeListX)::operator ooTreeListX *() const
{
  if ( _state == oocHandlePTR  )
    return ooReinterpretCast(ooTreeListX *, _ptr._obj);
  else return ooReinterpretCast(ooTreeListX *, this->get_vm());
}
inline
ooTreeListX *
ooHandle(ooTreeListX)::vm() const
{
  if ( _state == oocHandlePTR && _ptr._obj != NULL )
    return ooReinterpretCast(ooTreeListX *, _ptr._obj);
  else return ooReinterpretCast(ooTreeListX *, this->get_vm());
}
inline
ooRef(ooTreeListX) &
ooHandle(ooTreeListX)::copy(const ooHandle(ooObj) &  nearH,
		   ooRef(ooTreeListX) &              result) const
{
  this->ooHandle(ooObj)::copy(nearH, result);
  return result;
}


/* ODMG methods */
inline
ooTreeListX *
ooRef(ooTreeListX)::ptr() const
{
  return this->pin();
}
inline
ooTreeListX *
ooHandle(ooTreeListX)::ptr() const
{
  return this->operator ooTreeListX *();
}
class ooTreeMapX;


/////////////////////////////////////////////////////////////////////////////

ooTemplateSpecialization
class ooDeref(ooTreeMapX) : public ooDerefBase {
	friend class ooRef(ooTreeMapX);
  public:
    ~ooDerefStructor(ooTreeMapX)();
    inline ooTreeMapX *operator->() const;
#ifndef OO_BUGGY_TEMPLATES
  private:
#endif // !defined(OO_BUGGY_TEMPLATES)
    ooDerefStructor(ooTreeMapX)(ooDeref(ooTreeMapX)& deref);
    ooDerefStructor(ooTreeMapX)(ooObj *  fromObject);
};


#ifdef OO_BUGGY_TEMPLATES

class ooHandle_superclass<ooTreeMapX > : public ooHandle(ooTreeSetX) {
 protected:
  ooHandle_superclass()
    {}
  ooHandle_superclass(const ooHandle(ooTreeSetX) &  from) :
      ooHandle(ooTreeSetX)(from)
    {}
  ooHandle_superclass(const ooRef(ooTreeSetX) &  from) :
      ooHandle(ooTreeSetX)(from)
    {}
  ooHandle_superclass(const ooTreeSetX *  from) :
      ooHandle(ooTreeSetX)(from)
    {}
  ~ooHandle_superclass()
    {}
};

class ooShortRef_superclass<ooTreeMapX > : public ooShortRef(ooTreeSetX) {
};

#endif // OO_BUGGY_TEMPLATES

ooTemplateSpecialization
class ooRef(ooTreeMapX) : public ooRef(ooTreeSetX) {
  public:
    ooRefStructor(ooTreeMapX)()
      {}
    ooRefStructor(ooTreeMapX)(const ooRef(ooTreeMapX)& id) :
	  ooRef(ooTreeSetX)(id)
      {}
    inline ooRefStructor(ooTreeMapX)(const ooHandleSuper(ooTreeMapX)& objH);
    inline ooRefStructor(ooTreeMapX)(const ooTreeMapX *  fromObject);
    inline ooRef(ooTreeMapX)& operator=(const ooRef(ooTreeMapX)& id);
    inline ooRef(ooTreeMapX)& operator=(const ooShortRefSuper(ooTreeMapX) &shortId);
    inline ooRef(ooTreeMapX)& operator=(const ooHandleSuper(ooTreeMapX)& objH);
    inline ooRef(ooTreeMapX)& operator=(const ooTreeMapX *  fromObject);
    ooStatus lookupObj(const ooHandle(ooObj)& scopeH,
		       const ooKey& key,
		       ooMode openMode = oocRead);
    ooStatus lookupObj(const ooHandle(ooObj)& scopeH,
		       const char* name,
		       ooMode openMode = oocRead);
#ifndef OO_BUGGY_TEMPLATES
    inline ooRef(ooTreeMapX)& copy(const ooHandle(ooObj)& nearH,
		    ooRef(ooTreeMapX)& newObjRef) const;
    inline ooHandle(ooTreeMapX)& copy(const ooHandle(ooObj)& nearH,
			ooHandle(ooTreeMapX)& result) const;
    inline ooHandle(ooTreeMapX) copy(const ooHandle(ooObj)& nearH) const;
#endif // !defined(OO_BUGGY_TEMPLATES)
    inline ooTreeMapX *pin(ooMode openMode = oocRead) const;
    ooDeref(ooTreeMapX) operator->() const;
    /* Use pin() or use ooHandle "operator ooTreeMapX *" instead of vm. */
    /* OBSOLETE */ inline ooTreeMapX *vm(ooMode openMode = oocRead) const;
    // ODMG methods:
    ooRefStructor(ooTreeMapX)(const d_Ref_Any &from);
    ooTreeMapX *ptr() const;
};

ooTemplateSpecialization
class ooShortRef(ooTreeMapX) :
#ifdef OO_BUGGY_TEMPLATES
			public ooShortRef_superclass<ooTreeMapX >
#else // !defined(OO_BUGGY_TEMPLATES)
			public ooShortRef(ooTreeSetX)
#endif // !defined(OO_BUGGY_TEMPLATES)
					            {
  public:
    ooShortRefStructor(ooTreeMapX)();
    ooShortRefStructor(ooTreeMapX)(const ooShortRef(ooTreeMapX)& shortId);
    ooShortRefStructor(ooTreeMapX)(const ooRef(ooTreeMapX)& id);
    ooShortRefStructor(ooTreeMapX)(const ooHandleSuper(ooTreeMapX) &objH);
    ooShortRefStructor(ooTreeMapX)(const ooTreeMapX *  fromObject);
    ooShortRef(ooTreeMapX)& operator=(const ooShortRef(ooTreeMapX)& shortId);
    ooShortRef(ooTreeMapX)& operator=(const ooRef(ooTreeMapX)& id);
    ooShortRef(ooTreeMapX)& operator=(const ooHandleSuper(ooTreeMapX) &objH);
    ooShortRef(ooTreeMapX)& operator=(const ooTreeMapX *  fromObject);
};

ooTemplateSpecialization
class ooHandle(ooTreeMapX) :
#ifdef OO_BUGGY_TEMPLATES
		      public ooHandle_superclass<ooTreeMapX >
#else // !defined(OO_BUGGY_TEMPLATES)
		      public ooHandle(ooTreeSetX)
#endif // !defined(OO_BUGGY_TEMPLATES)
                                                {
  public:
    inline ooHandleStructor(ooTreeMapX)();
    inline ooHandleStructor(ooTreeMapX)(const ooRef(ooTreeMapX)& id);
    inline ooHandleStructor(ooTreeMapX)(const ooHandle(ooTreeMapX)& objH);
    inline ooHandleStructor(ooTreeMapX)(const ooTreeMapX *  fromObject);
    inline ooHandle(ooTreeMapX)& operator=(const ooRef(ooTreeMapX)& id);
    inline ooHandle(ooTreeMapX)& operator=(const ooHandle(ooTreeMapX)& objH);
    inline ooHandle(ooTreeMapX)& operator=(const ooShortRef(ooTreeMapX)& shortId);
    inline ooHandle(ooTreeMapX)& operator=(const ooTreeMapX *  fromObject);
    ooStatus lookupObj(const ooHandle(ooObj)& scopeH,
		       const ooKey& key,
		       ooMode openMode = oocRead);
    ooStatus lookupObj(const ooHandle(ooObj)& scopeH,
		       const char* name,
		       ooMode openMode = oocRead);
    ooHandle(ooTreeMapX)& copy(const ooHandle(ooObj)& nearH,
		       ooHandle(ooTreeMapX)& result) const;
    inline ooRef(ooTreeMapX)& copy(const ooHandle(ooObj)& nearH,
		    ooRef(ooTreeMapX)& result) const;
    ooHandle(ooTreeMapX) copy(const ooHandle(ooObj)& nearH) const;
    inline ooTreeMapX *pin(ooMode openMode = oocRead) const;
    inline ooTreeMapX *operator->() const;
    inline ooTreeMapX &operator*() const;
    inline operator ooTreeMapX *() const;
    /* Use "operator ooTreeMapX *" instead of vm. */
    /* OBSOLETE */ inline ooTreeMapX *vm() const;
    // ODMG methods:
    ooHandleStructor(ooTreeMapX)(const d_Ref_Any &from);
    ooTreeMapX *ptr() const;
};

ooTemplateSpecialization
class ooItr(ooTreeMapX) : public ooHandle(ooTreeMapX),
		    public ooIteratorObjOrContObj {
  public:
    ooItrStructor(ooTreeMapX)();
    ~ooItrStructor(ooTreeMapX)();
  private:
    // Defined only to prevent implicit definition:
    ooItrStructor(ooTreeMapX)(ooItr(ooTreeMapX)&);
    ooItr(ooTreeMapX)    operator=(ooItr(ooTreeMapX)&);
};


/* methods on ooDeref(ooTreeMapX) */
inline
ooDeref(ooTreeMapX)::ooDerefStructor(ooTreeMapX)(ooDeref(ooTreeMapX) &  deref) :
    ooDerefBase(deref.vm())
{
  this->pinCompensate();
}
inline
ooDeref(ooTreeMapX)::ooDerefStructor(ooTreeMapX)(ooObj *  fromObject) :
    ooDerefBase(fromObject)
{
}
inline
ooDeref(ooTreeMapX)::~ooDerefStructor(ooTreeMapX)()
{
}
inline
ooTreeMapX *
ooDeref(ooTreeMapX)::operator->() const
{
  return ooReinterpretCast(ooTreeMapX *, this->vm());
}


/* methods on ooRef(ooTreeMapX) */
inline
ooRef(ooTreeMapX)::ooRefStructor(ooTreeMapX)(const ooHandleSuper(ooTreeMapX)& objH) :
    ooRef(ooTreeSetX)(objH)
{
}
inline
ooRef(ooTreeMapX)::ooRefStructor(ooTreeMapX)(const ooTreeMapX *  fromObject) :
    ooRef(ooTreeSetX)(ooReinterpretCast(const ooTreeSetX *, fromObject))
{
}
inline
ooRef(ooTreeMapX)&
ooRef(ooTreeMapX)::operator=(const ooRef(ooTreeMapX) &  id)
{
  this->ooId::operator=(id);
  return *this;
}
inline
ooRef(ooTreeMapX)&
ooRef(ooTreeMapX)::operator=(const ooShortRefSuper(ooTreeMapX) &  shortId)
{
  this->ooRef(ooObj)::operator=(shortId);
  return *this;
}
inline
ooRef(ooTreeMapX)&
ooRef(ooTreeMapX)::operator=(const ooHandleSuper(ooTreeMapX) &  objH)
{
  this->ooRef(ooObj)::operator=(objH);
  return *this;
}
inline
ooRef(ooTreeMapX)&
ooRef(ooTreeMapX)::operator=(const ooTreeMapX *  fromObject)
{
  this->ooRef(ooObj)::operator=(ooReinterpretCast(const ooObj *, fromObject));
  return *this;
}
inline
ooTreeMapX *
ooRef(ooTreeMapX)::pin(ooMode  openMode) const
{
  return ooReinterpretCast(ooTreeMapX *, this->pin_ref_internal(openMode));
}
inline
ooTreeMapX *
ooRef(ooTreeMapX)::vm(ooMode  openMode) const
{
  return this->pin(openMode);
}
#ifndef OO_BUGGY_TEMPLATES
inline
ooHandle(ooTreeMapX) &
ooRef(ooTreeMapX)::copy(const ooHandle(ooObj) &  nearH,
		ooHandle(ooTreeMapX) &           result) const
{
  this->ooRef(ooObj)::copy(nearH, result);
  return result;
}
inline
ooRef(ooTreeMapX) &
ooRef(ooTreeMapX)::copy(const ooHandle(ooObj) &  nearH,
		ooRef(ooTreeMapX) &              newObjRef) const
{
  this->ooRef(ooObj)::copy(nearH, newObjRef);
  return newObjRef;
}
inline
ooHandle(ooTreeMapX)
ooRef(ooTreeMapX)::copy(const ooHandle(ooObj) &  nearH) const
{
  ooHandle(ooTreeMapX) result;
  this->ooRef(ooObj)::copy(nearH, result);
  return result;
}
#endif // !defined(OO_BUGGY_TEMPLATES)
inline
ooDeref(ooTreeMapX)
ooRef(ooTreeMapX)::operator->() const
{
  ooDeref(ooTreeMapX) result(this->pin_ref_internal(oocRead));
  return result;
}


/* methods on ooShortRef(ooTreeMapX) */
inline
ooShortRef(ooTreeMapX) &
ooShortRef(ooTreeMapX)::operator=(const ooShortRef(ooTreeMapX) &  shortId)
{
  this->ooShortId::operator=(shortId);
  return *this;
}
inline
ooShortRef(ooTreeMapX) &
ooShortRef(ooTreeMapX)::operator=(const ooRef(ooTreeMapX) &  id)
{
  this->ooShortId::operator=(id);
  return *this;
}
inline
ooShortRef(ooTreeMapX) &
ooShortRef(ooTreeMapX)::operator=(const ooHandleSuper(ooTreeMapX) &  objH)
{
  this->ooShortId::operator=(objH);
  return *this;
}
inline
ooShortRef(ooTreeMapX)&
ooShortRef(ooTreeMapX)::operator=(const ooTreeMapX *  fromObject)
{
  this->ooShortId::operator=(ooReinterpretCast(const ooObj *,fromObject));
  return *this;
}
inline
ooShortRef(ooTreeMapX)::ooShortRefStructor(ooTreeMapX)()
{
}
#ifdef OO_BUGGY_TEMPLATES
inline
ooShortRef(ooTreeMapX)::ooShortRefStructor(ooTreeMapX)(const ooShortRef(ooTreeMapX) &  shortId)
{
  *this = shortId;
}
#else // !defined(OO_BUGGY_TEMPLATES)
inline
ooShortRef(ooTreeMapX)::ooShortRefStructor(ooTreeMapX)(const ooShortRef(ooTreeMapX) &  shortId) :
    ooShortRef(ooTreeSetX)(shortId)
{
}
#endif // !defined(OO_BUGGY_TEMPLATES)
#ifdef OO_BUGGY_TEMPLATES
inline
ooShortRef(ooTreeMapX)::ooShortRefStructor(ooTreeMapX)(const ooRef(ooTreeMapX) &  id)
{
  *this = id;
}
#else // !defined(OO_BUGGY_TEMPLATES)
inline
ooShortRef(ooTreeMapX)::ooShortRefStructor(ooTreeMapX)(const ooRef(ooTreeMapX) &  id) :
    ooShortRef(ooTreeSetX)(id)
{
}
#endif // !defined(OO_BUGGY_TEMPLATES)
#ifdef OO_BUGGY_TEMPLATES
inline
ooShortRef(ooTreeMapX)::ooShortRefStructor(ooTreeMapX)(const ooHandleSuper(ooTreeMapX) &  objH)
{
  *this = objH;
}
#else // !defined(OO_BUGGY_TEMPLATES)
inline
ooShortRef(ooTreeMapX)::ooShortRefStructor(ooTreeMapX)(const ooHandleSuper(ooTreeMapX) &  objH) :
    ooShortRef(ooTreeSetX)(objH)
{
}
#endif // !defined(OO_BUGGY_TEMPLATES)
#ifdef OO_BUGGY_TEMPLATES
inline
ooShortRef(ooTreeMapX)::ooShortRefStructor(ooTreeMapX)(const ooTreeMapX *  fromObject)
{
  *this = fromObject;
}
#else // !defined(OO_BUGGY_TEMPLATES)
inline
ooShortRef(ooTreeMapX)::ooShortRefStructor(ooTreeMapX)(const ooTreeMapX *  fromObject) :
    ooShortRef(ooTreeSetX)(ooReinterpretCast(const ooTreeSetX *,fromObject))
{
}
#endif // !defined(OO_BUGGY_TEMPLATES)


/* methods on ooHandle(ooTreeMapX) */
inline
ooHandle(ooTreeMapX)::ooHandleStructor(ooTreeMapX)()
{
}
inline
ooHandle(ooTreeMapX)::ooHandleStructor(ooTreeMapX)(const ooHandle(ooTreeMapX) &  objH) :
#ifdef OO_BUGGY_TEMPLATES
    ooHandle_superclass<ooTreeMapX >(objH)
#else // !defined(OO_BUGGY_TEMPLATES)
    ooHandle(ooTreeSetX)(objH)
#endif // !defined(OO_BUGGY_TEMPLATES)
{
}
inline
ooHandle(ooTreeMapX)::ooHandleStructor(ooTreeMapX)(const ooRef(ooTreeMapX) &  id) :
#ifdef OO_BUGGY_TEMPLATES
    ooHandle_superclass<ooTreeMapX >(id)
#else // !defined(OO_BUGGY_TEMPLATES)
    ooHandle(ooTreeSetX)(id)
#endif // !defined(OO_BUGGY_TEMPLATES)
{
}
inline
ooHandle(ooTreeMapX)::ooHandleStructor(ooTreeMapX)(const ooTreeMapX *  fromObject) :
#ifdef OO_BUGGY_TEMPLATES
    ooHandle_superclass<ooTreeMapX >(ooReinterpretCast(const ooTreeSetX *,fromObject))
#else // !defined(OO_BUGGY_TEMPLATES)
    ooHandle(ooTreeSetX)(ooReinterpretCast(const ooTreeSetX *,fromObject))
#endif // !defined(OO_BUGGY_TEMPLATES)
{
}
inline
ooHandle(ooTreeMapX)&
ooHandle(ooTreeMapX)::operator=(const ooRef(ooTreeMapX) &  id)
{
  this->ooHandle(ooObj)::operator=(id);
  return *this;
}
inline
ooHandle(ooTreeMapX)&
ooHandle(ooTreeMapX)::operator=(const ooHandle(ooTreeMapX) &  objH)
{
  this->ooHandle(ooObj)::operator=(objH);
  return *this;
}
inline
ooHandle(ooTreeMapX)&
ooHandle(ooTreeMapX)::operator=(const ooShortRef(ooTreeMapX) &  shortId)
{
  this->ooHandle(ooObj)::operator=(shortId);
  return *this;
}
inline
ooHandle(ooTreeMapX)&
ooHandle(ooTreeMapX)::operator=(const ooTreeMapX *  fromObject)
{
  this->ooHandle(ooObj)::operator=(ooReinterpretCast(const ooObj *,fromObject));
  return *this;
}
inline
ooTreeMapX *
ooHandle(ooTreeMapX)::pin(ooMode  openMode) const
{
  return ooReinterpretCast(ooTreeMapX *, this->pin_obj_internal(openMode));
}
inline
ooTreeMapX *
ooHandle(ooTreeMapX)::operator->() const
{
  return this->vm();
}
inline
ooTreeMapX &
ooHandle(ooTreeMapX)::operator*() const
{
  return *(this->vm());
}
inline
ooHandle(ooTreeMapX)::operator ooTreeMapX *() const
{
  if ( _state == oocHandlePTR  )
    return ooReinterpretCast(ooTreeMapX *, _ptr._obj);
  else return ooReinterpretCast(ooTreeMapX *, this->get_vm());
}
inline
ooTreeMapX *
ooHandle(ooTreeMapX)::vm() const
{
  if ( _state == oocHandlePTR && _ptr._obj != NULL )
    return ooReinterpretCast(ooTreeMapX *, _ptr._obj);
  else return ooReinterpretCast(ooTreeMapX *, this->get_vm());
}
inline
ooRef(ooTreeMapX) &
ooHandle(ooTreeMapX)::copy(const ooHandle(ooObj) &  nearH,
		   ooRef(ooTreeMapX) &              result) const
{
  this->ooHandle(ooObj)::copy(nearH, result);
  return result;
}


/* ODMG methods */
inline
ooTreeMapX *
ooRef(ooTreeMapX)::ptr() const
{
  return this->pin();
}
inline
ooTreeMapX *
ooHandle(ooTreeMapX)::ptr() const
{
  return this->operator ooTreeMapX *();
}
#if defined(_MSC_VER) && !defined(OO_DDL_TRANSLATION)
#pragma pack(pop)
#endif

#endif /* OO_COLLECTION_BASE_REF_H */

