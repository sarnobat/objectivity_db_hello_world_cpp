/**************************************************************************
		Copyright (c) 1989-2000 Objectivity, Inc.
			  All Rights Reserved


	THIS IS UNPUBLISHED PROPRIETARY SOURCE CODE OF OBJECTIVITY, INC.


	The copyright notice above does not evidence any
	actual or intended publication of such source code.


*****************************************************************************/

// This file must match files builtin.ddl, ooSchema_ref.h, and opiBuiltin.C.

// "@(#)$Id$"

#ifndef OO_SCHEMA_H
#define OO_SCHEMA_H


#if defined(_MSC_VER) && !defined(OO_DDL_TRANSLATION)
#pragma pack(push,8)
#endif

#ifndef OO_H
#include <oo.h>
#endif
// Note that file ooSchema_ref.h #includes file ooDecl.h.
#ifndef OO_SCHEMA_REF_H
#include <ooSchema_ref.h>
#endif
#ifndef OO_PREDEFINED_REF_H
#include <ooPredef_ref.h>
#endif
#ifndef OO_MAP_REF_H
#include <ooMap_ref.h>
#endif

class OO_STORAGE_SPECIFIER ooCheckOutInfoObj;
class OO_STORAGE_SPECIFIER ooGeneObj;
class OO_STORAGE_SPECIFIER ooMapElem;
class OO_STORAGE_SPECIFIER ooSysIndex;
class OO_STORAGE_SPECIFIER ooDefaultAssocArray;

///////////////////////////////////////////////////////////////////////////////

/* 
ooAbstractObj ensures that the C++ virtual function table pointer is at the
start of each persistent object, since the class has neither base classes nor
member data that can precede the virtual function table pointer.
*/
class OO_STORAGE_SPECIFIER ooAbstractObj {
  public:
    virtual ooBoolean ooIsKindOf(ooTypeNumber) const { return ((ooBoolean) 0); }
    virtual ooTypeNumber ooGetTypeN() const = 0;
    virtual ooBoolean ooValidate();
    static const ooTypeNumber opiTypeN;
  protected:
    ooAbstractObj() {}
};


// Root persistent class.
class OO_STORAGE_SPECIFIER ooObj : public ooAbstractObj {
public:
  virtual ooTypeNumber ooGetTypeN() const;
  virtual char* ooGetTypeName() const;
  ooBoolean ooIsKindOf(ooTypeNumber typeN) const
  { return ooTypeN(ooObj) == typeN || ooAbstractObj::ooIsKindOf(typeN); }
  ooHandle(ooObj)& ooThis(ooHandle(ooObj)& objH,
    ooMode mode = oocNoOpen) const;
  ooHandle(ooObj) ooThis(ooMode mode = oocNoOpen) const;
  ooRef(ooObj)& ooThis(ooRef(ooObj)& objId, ooMode mode = oocNoOpen) const;
  void* operator new(size_t);
  void* operator new(size_t, const ooHandle(ooObj)& nearH);
  void* operator new(size_t, const ooHandle(ooObj)& nearH, ooClusterStrategy& strategy);
  void* operator new(size_t, const ooId& nearR, ooClusterStrategy& strategy)
  {
    return strategy.newObj(ooTypeN(ooObj), nearR);
  }
  void* operator new(size_t, ooClusterStrategy& strategy)
  {
    return strategy.newObj(ooTypeN(ooObj));
  }
  void* operator new(size_t, const ooId& nearId);
  void* operator new(size_t, const ooObj * nearObj);
#ifdef OO_PLACEMENT_DELETE
  void operator delete(void* object, const ooHandle(ooObj)&) {
    ooObj::operator delete(object);
  }
  void operator delete(void* object, const ooHandle(ooObj)&, ooClusterStrategy&) {
    ooObj::operator delete(object);
  }
   void operator delete(void* object, const ooId&, ooClusterStrategy&) {
    ooObj::operator delete(object);
  }
 void operator delete(void* object, ooClusterStrategy&) {
    ooObj::operator delete(object);
  }
  void operator delete(void* object, const ooId&) {
    ooObj::operator delete(object);
  }
  void operator delete(void* object, const ooObj* ) {
    ooObj::operator delete(object);
  }
#endif
  ooObj(ooInternalObj){}
  static const ooTypeNumber opiTypeN;
  static const ooAssocNumber checkoutInfo_ooAssocN;
  static const ooAssocNumber defaultToGeneObj_ooAssocN;
  static const ooAssocNumber derivatives_ooAssocN;
  static const ooAssocNumber derivedFrom_ooAssocN;
  static const ooAssocNumber geneObj_ooAssocN;
  static ooAssocNumber mapElems_ooAssocN;
  static const ooAssocNumber nameObj_ooAssocN;
  static const ooAssocNumber nameScope_ooAssocN;
  static const ooAssocNumber nextVers_ooAssocN;
  static const ooAssocNumber prevVers_ooAssocN;
  static const ooAssocNumber owner_ooAssocN;
  static const ooAssocNumber owns_ooAssocN;
public:
  ooObj(){}
  ooObj(const ooObj &) : ooAbstractObj() {}
  virtual  ~ooObj() {}
  virtual ooBoolean ooValidate();
  virtual ooStatus ooNewVersInit();
  virtual ooStatus ooCopyInit();
  virtual ooStatus ooPreMoveInit();
  virtual ooStatus ooPostMoveInit();
  uint32 ooGetSize() const;
  ooId &ooThisId(ooId &id) const;
  ooId ooThisId() const;
  ooStatus ooUpdate();
  ooStatus ooUnpin();
  ooStatus ooIncOpenCount();
  void operator delete(void *);
  void *ooDysoc() const { return(_assocVArray._data); }
  ooObj &operator =(const ooObj &) {
    // ooObj contains only identity data, so do not copy anything.
    return (*this);
  }
  ooDefaultAssocArray* defaultAssociationArray();
  static ooHandle(ooObj)
    enclosingPersistentObject(const void *       data);
  static ooHandle(ooObj) &
    enclosingPersistentObject(const void *       data,
    ooHandle(ooObj) &  handle_buffer);
  static ooRef(ooObj) &
    enclosingPersistentObject(const void *    data,
    ooRef(ooObj) &  ref_buffer);
#ifdef OO_DDL_TRANSLATION
  ooRef(ooObj) nextVers[] <-> prevVers ;
#else /* !defined(OO_DDL_TRANSLATION) */
  /* Methods for bidirectional association link: nextVers[] */
  ooStatus nextVers(ooItr(ooObj)& itr, ooMode mode = oocNoOpen) const;
  ooStatus nextVers(ooItr(ooObj)& itr,const char* predicate) const;
  ooStatus nextVers(ooItr(ooObj)& itr,ooMode mode,
    const ooAccessMode access, const char* predicate) const;
  ooStatus add_nextVers(const ooHandle(ooObj)& newObjH);
  ooStatus sub_nextVers(const ooHandle(ooObj)& objH);
  ooStatus del_nextVers() { return opiDelAssoc(ooDysoc(), ooAssocN(ooObj,nextVers)); }
  ooBoolean exist_nextVers(const ooHandle(ooObj)& objH) const;
  ooBoolean exist_nextVers() const
  {
    return this->exist_nextVers((const ooHandle(ooObj) &) (oocNullHandle));
  }
#endif /* !defined(OO_DDL_TRANSLATION) */
#ifdef OO_DDL_TRANSLATION
  ooRef(ooObj) prevVers <-> nextVers[] ;
#else /* !defined(OO_DDL_TRANSLATION) */
  /* Methods for bidirectional association link: prevVers */
  ooHandle(ooObj) prevVers(ooMode mode = oocNoOpen) const;
  ooHandle(ooObj)& prevVers(ooHandle(ooObj)& objH,
    ooMode mode = oocNoOpen) const;
  ooRef(ooObj)& prevVers(ooRef(ooObj)& objId, ooMode mode = oocNoOpen) const;
  ooStatus set_prevVers (const ooHandle(ooObj)& objH);
  ooStatus del_prevVers() { return opiDelAssoc_1(ooDysoc(), ooAssocN(ooObj,prevVers)); }
  ooBoolean exist_prevVers(const ooHandle(ooObj)& objH) const;
  ooBoolean exist_prevVers() const
  {
    return this->exist_prevVers((const ooHandle(ooObj) &) (oocNullHandle));
  }
#endif /* !defined(OO_DDL_TRANSLATION) */
#ifdef OO_DDL_TRANSLATION
  ooRef(ooGeneObj) geneObj <-> allVers[]  : version(copy);
#else /* !defined(OO_DDL_TRANSLATION) */
  /* Methods for bidirectional association link: geneObj */
  ooHandle(ooGeneObj) geneObj(ooMode mode = oocNoOpen) const;
  ooHandle(ooGeneObj)& geneObj(ooHandle(ooGeneObj)& objH,
    ooMode mode = oocNoOpen) const;
  ooRef(ooGeneObj)& geneObj(ooRef(ooGeneObj)& objId, ooMode mode = oocNoOpen) const;
  ooStatus set_geneObj (const ooHandle(ooGeneObj)& objH);
  ooStatus del_geneObj() { return opiDelAssoc_1(ooDysoc(), ooAssocN(ooObj,geneObj)); }
  ooBoolean exist_geneObj(const ooHandle(ooGeneObj)& objH) const;
  ooBoolean exist_geneObj() const
  {
    return this->exist_geneObj((const ooHandle(ooGeneObj) &)
      (oocNullHandle));
  }
#endif /* !defined(OO_DDL_TRANSLATION) */
#ifdef OO_DDL_TRANSLATION
  ooRef(ooGeneObj) defaultToGeneObj <-> defaultVers ;
#else /* !defined(OO_DDL_TRANSLATION) */
  /* Methods for bidirectional association link: defaultToGeneObj */
  ooHandle(ooGeneObj) defaultToGeneObj(ooMode mode = oocNoOpen) const;
  ooHandle(ooGeneObj)& defaultToGeneObj(ooHandle(ooGeneObj)& objH,
    ooMode mode = oocNoOpen) const;
  ooRef(ooGeneObj)& defaultToGeneObj(ooRef(ooGeneObj)& objId, ooMode mode = oocNoOpen) const;
  ooStatus set_defaultToGeneObj (const ooHandle(ooGeneObj)& objH);
  ooStatus del_defaultToGeneObj() { return opiDelAssoc_1(ooDysoc(), ooAssocN(ooObj,defaultToGeneObj)); }
  ooBoolean exist_defaultToGeneObj(const ooHandle(ooGeneObj)& objH) const;
  ooBoolean exist_defaultToGeneObj() const
  {
    return this->exist_defaultToGeneObj((const ooHandle(ooGeneObj) &)
      (oocNullHandle));
  }
#endif /* !defined(OO_DDL_TRANSLATION) */
#ifdef OO_DDL_TRANSLATION
  ooRef(ooObj) derivatives[] <-> derivedFrom[] ;
#else /* !defined(OO_DDL_TRANSLATION) */
  /* Methods for bidirectional association link: derivatives[] */
  ooStatus derivatives(ooItr(ooObj)& itr, ooMode mode = oocNoOpen) const;
  ooStatus derivatives(ooItr(ooObj)& itr,const char* predicate) const;
  ooStatus derivatives(ooItr(ooObj)& itr,ooMode mode,
    const ooAccessMode access, const char* predicate) const;
  ooStatus add_derivatives(const ooHandle(ooObj)& newObjH);
  ooStatus sub_derivatives(const ooHandle(ooObj)& objH, uint32 number = 1);
  ooStatus del_derivatives() { return opiDelAssoc(ooDysoc(),ooAssocN(ooObj,derivatives)); }
  ooBoolean exist_derivatives(const ooHandle(ooObj)& objH) const;
  ooBoolean exist_derivatives() const
  {
    return this->exist_derivatives((const ooHandle(ooObj) &)
      (oocNullHandle));
  }
#endif  /* OO_DDL_TRANSLATION */
#ifdef OO_DDL_TRANSLATION
  ooRef(ooObj) derivedFrom[] <-> derivatives[] ;
#else /* !defined(OO_DDL_TRANSLATION) */
  /* Methods for bidirectional association link: derivedFrom[] */
  ooStatus derivedFrom(ooItr(ooObj)& itr, ooMode mode = oocNoOpen) const;
  ooStatus derivedFrom(ooItr(ooObj)& itr,const char* predicate) const;
  ooStatus derivedFrom(ooItr(ooObj)& itr,ooMode mode,
    const ooAccessMode access, const char* predicate) const;
  ooStatus add_derivedFrom(const ooHandle(ooObj)& newObjH);
  ooStatus sub_derivedFrom(const ooHandle(ooObj)& objH, uint32 number = 1);
  ooStatus del_derivedFrom() { return opiDelAssoc(ooDysoc(),ooAssocN(ooObj,derivedFrom)); }
  ooBoolean exist_derivedFrom(const ooHandle(ooObj)& objH) const;
  ooBoolean exist_derivedFrom() const
  {
    return this->exist_derivedFrom((const ooHandle(ooObj) &)
      (oocNullHandle));
  }
#endif  /* OO_DDL_TRANSLATION */
#ifdef OO_DDL_TRANSLATION
  ooRef(ooMapElem) mapElems[] : delete(propagate);
#else /* !defined(OO_DDL_TRANSLATION) */
  /* Methods for unidirectional association link: mapElems[] */
  ooStatus mapElems(ooItr(ooMapElem)& itr, ooMode mode = oocNoOpen) const;
  ooStatus mapElems(ooItr(ooMapElem)& itr,const char* predicate) const;
  ooStatus mapElems(ooItr(ooMapElem)& itr,ooMode mode,
    const ooAccessMode access, const char* predicate) const;
  ooStatus add_mapElems(const ooHandle(ooMapElem)& newObjH);
  ooStatus sub_mapElems(const ooHandle(ooMapElem)& objH, uint32 number = 1);
  ooStatus del_mapElems() { return opiDelUssoc(ooDysoc(), ooAssocN(ooObj,mapElems)); }
  ooBoolean exist_mapElems(const ooHandle(ooMapElem)& objH) const;
  ooBoolean exist_mapElems() const
  {
    return this->exist_mapElems((const ooHandle(ooMapElem) &)
      (oocNullHandle));
  }
#endif /* !defined(OO_DDL_TRANSLATION) */
  // ODMG methods:
  void *operator new(size_t size, const ooHandle(ooObj) &nearH, const char *)
  { return operator new(size, nearH); }
#ifdef OO_PLACEMENT_DELETE
  void
    operator delete(void * object,
    const ooHandle(ooObj) &,
    const char *             ) {
      ooObj::operator delete(object);
    }
#endif
#ifdef OO_ODMG
    void *operator new(size_t size, d_Database *db, const char *type_name = 0);
#ifdef OO_PLACEMENT_DELETE
    inline void
      operator delete(void * object,
      d_Database *,
      const char *) {
        ooObj::operator delete(object);
      }
#endif
#endif
      void mark_modified()
      {
        this->ooUpdate();
      }
private:
  ooDefaultVArray _assocVArray;
#ifdef OO_DDL_TRANSLATION
  ooRef(ooCheckOutInfoObj) checkoutInfo[] <-> checkout ;
#else /* !defined(OO_DDL_TRANSLATION) */
  /* Methods for bidirectional association link: checkoutInfo[] */
  ooStatus checkoutInfo(ooItr(ooCheckOutInfoObj)& itr, ooMode mode = oocNoOpen) const;
  ooStatus checkoutInfo(ooItr(ooCheckOutInfoObj)& itr,const char* predicate) const;
  ooStatus checkoutInfo(ooItr(ooCheckOutInfoObj)& itr,ooMode mode,
    const ooAccessMode access, const char* predicate) const;
  ooStatus add_checkoutInfo(const ooHandle(ooCheckOutInfoObj)& newObjH);
  ooStatus sub_checkoutInfo(const ooHandle(ooCheckOutInfoObj)& objH);
  ooStatus del_checkoutInfo() { return opiDelAssoc(ooDysoc(), ooAssocN(ooObj,checkoutInfo)); }
  ooBoolean exist_checkoutInfo(
    const ooHandle(ooCheckOutInfoObj)& objH) const;
  ooBoolean exist_checkoutInfo() const
  {
    return this->exist_checkoutInfo((const ooHandle(ooCheckOutInfoObj) &)
      (oocNullHandle));
  }
#endif /* !defined(OO_DDL_TRANSLATION) */
#ifdef OO_DDL_TRANSLATION
  ooRef(ooObj) nameScope[] <-> nameObj[] ;
#else /* !defined(OO_DDL_TRANSLATION) */
  /* Methods for bidirectional association link: nameScope[] */
  ooStatus nameScope(ooItr(ooObj)& itr, ooMode mode = oocNoOpen) const;
  ooStatus nameScope(ooItr(ooObj)& itr,const char* predicate) const;
  ooStatus nameScope(ooItr(ooObj)& itr,ooMode mode,
    const ooAccessMode access, const char* predicate) const;
  ooStatus add_nameScope(const ooHandle(ooObj)& newObjH);
  ooStatus sub_nameScope(const ooHandle(ooObj)& objH, uint32 number = 1);
  ooStatus del_nameScope() { return opiDelAssoc(ooDysoc(),ooAssocN(ooObj,nameScope)); }
  ooBoolean exist_nameScope(const ooHandle(ooObj)& objH) const;
  ooBoolean exist_nameScope() const
  {
    return this->exist_nameScope((const ooHandle(ooObj) &)
      (oocNullHandle));
  }
#endif  /* OO_DDL_TRANSLATION */
#ifdef OO_DDL_TRANSLATION
  ooRef(ooObj) nameObj[] <-> nameScope[] ;
#else /* !defined(OO_DDL_TRANSLATION) */
  /* Methods for bidirectional association link: nameObj[] */
  ooStatus nameObj(ooItr(ooObj)& itr, ooMode mode = oocNoOpen) const;
  ooStatus nameObj(ooItr(ooObj)& itr,const char* predicate) const;
  ooStatus nameObj(ooItr(ooObj)& itr,ooMode mode,
    const ooAccessMode access, const char* predicate) const;
  ooStatus add_nameObj(const ooHandle(ooObj)& newObjH);
  ooStatus sub_nameObj(const ooHandle(ooObj)& objH, uint32 number = 1);
  ooStatus del_nameObj() { return opiDelAssoc(ooDysoc(),ooAssocN(ooObj,nameObj)); }
  ooBoolean exist_nameObj(const ooHandle(ooObj)& objH) const;
  ooBoolean exist_nameObj() const
  {
    return this->exist_nameObj((const ooHandle(ooObj) &) (oocNullHandle));
  }
#endif  /* OO_DDL_TRANSLATION */
public:
#ifdef OO_DDL_TRANSLATION
  ooRef(ooObj) owner <-> owns[] ;
#else /* !defined(OO_DDL_TRANSLATION) */
  /* Methods for bidirectional association link: owner */
  ooHandle(ooObj) owner(ooMode mode = oocNoOpen) const;
  ooHandle(ooObj)& owner(ooHandle(ooObj)& objH,
    ooMode mode = oocNoOpen) const;
  ooRef(ooObj)& owner(ooRef(ooObj)& objId, ooMode mode = oocNoOpen) const;
  ooStatus set_owner (const ooHandle(ooObj)& objH);
  ooStatus del_owner() { return opiDelAssoc_1(ooDysoc(), ooAssocN(ooObj,owner)); }
  ooBoolean exist_owner(const ooHandle(ooObj)& objH) const;
  ooBoolean exist_owner() const
  {
    return this->exist_owner((const ooHandle(ooObj) &) (oocNullHandle));
  }
#endif /* !defined(OO_DDL_TRANSLATION) */
#ifdef OO_DDL_TRANSLATION
  ooRef(ooObj) owns[] <-> owner ;
#else /* !defined(OO_DDL_TRANSLATION) */
  /* Methods for bidirectional association link: owns[] */
  ooStatus owns(ooItr(ooObj)& itr, ooMode mode = oocNoOpen) const;
  ooStatus owns(ooItr(ooObj)& itr,const char* predicate) const;
  ooStatus owns(ooItr(ooObj)& itr,ooMode mode,
    const ooAccessMode access, const char* predicate) const;
  ooStatus add_owns(const ooHandle(ooObj)& newObjH);
  ooStatus sub_owns(const ooHandle(ooObj)& objH);
  ooStatus del_owns() { return opiDelAssoc(ooDysoc(), ooAssocN(ooObj,owns)); }
  ooBoolean exist_owns(const ooHandle(ooObj)& objH) const;
  ooBoolean exist_owns() const
  {
    return this->exist_owns((const ooHandle(ooObj) &) (oocNullHandle));
  }
#endif /* !defined(OO_DDL_TRANSLATION) */
};

class OO_STORAGE_SPECIFIER d_Timestamp;

class OO_STORAGE_SPECIFIER ooFDObj : public ooObj {
  public:
    virtual ooBoolean ooValidate();
    static const ooTypeNumber opiTypeN;
    static const char* restore(const char* archiveDirPath = 0, const char* archiveDirHost = 0, 
      const char* destinationPath  = 0, const char* destinationHost = 0, const char* backupName = "backup", 
      bool upgrade = false, d_Timestamp* upToTime = 0);
};


class OO_STORAGE_SPECIFIER ooAPObj : public ooObj {
  public:
    void *operator new(size_t);
    void *operator new(size_t, const ooHandle(ooFDObj) &fdH);
    void *operator new(size_t, const ooRef(ooFDObj) &fdId);
    // ooAPObj::operator delete does nothing because operator new does not
    // actually allocate heap storage.  (see SPR 15904 and 15927)
    void operator delete(void*) { }
#ifdef OO_PLACEMENT_DELETE
    void operator delete(void*, const ooHandle(ooFDObj)&) { }
    void operator delete(void*, const ooRef(ooFDObj)&) { }
#endif
    virtual ooBoolean ooValidate();
    ooAPObj(const char *systemName,
	    const char *lockServerHost,
	    const char *systemDbFileHost,
	    const char *systemDbFilePath,
	    const char *bootFileHost =	0,
	    const char *bootFilePath =	0,
	    const char *journalDirHost =  0,
	    const char *journalDirPath =  0,
	    unsigned int weight = 1,
            unsigned apId = 1); // apId parameter is for new catalogs only - Objectivity internal use
    static const ooTypeNumber opiTypeN;
};


class OO_STORAGE_SPECIFIER ooDBObj : public ooObj {
  public:
    void *operator new(size_t);
    void *operator new(size_t, const ooHandle(ooFDObj) &fdH);
    void *operator new(size_t, const ooRef(ooFDObj) &fdId);
    void *operator new(size_t, const ooHandle(ooFDObj) &containingFdH, const ooHandle(ooAPObj) &controllingApH);
    void *operator new(size_t, const ooHandle(ooFDObj) &containingFdH, const ooRef(ooAPObj) &controllingApId);
    void *operator new(size_t, const ooRef(ooFDObj) &containingFdId, const ooHandle(ooAPObj) &controllingApH);
    void *operator new(size_t, const ooRef(ooFDObj) &containingFdId, const ooRef(ooAPObj) &controllingApId);
    // ooDBObj::operator delete does nothing because operator new does not
    // actually allocate heap storage.  (see SPR 15904 and 15927)
    void operator delete(void*) { }
#ifdef OO_PLACEMENT_DELETE
    void operator delete(void*, const ooHandle(ooFDObj)&) { }
    void operator delete(void*, const ooRef(ooFDObj)& ) { }
    void operator delete(void*, const ooHandle(ooFDObj)&, const ooHandle(ooAPObj)&) { }
    void operator delete(void*, const ooHandle(ooFDObj)&, const ooRef(ooAPObj)&) { }
    void operator delete(void*, const ooRef(ooFDObj)&, const ooHandle(ooAPObj)&) { }
    void operator delete(void*, const ooRef(ooFDObj)&, const ooRef(ooAPObj)&) { }
#endif
    virtual ooBoolean ooValidate();
    ooDBObj(const char *DBname,
	    uint32 initPages = 0,
	    uint32 percentGrow = 0,
	    const char *hostName =  0,
	    const char *pathName =  0,
	    uint32 weight = 1,
	    uint16 userDBID = 0,
	    unsigned pageSize = 0,
            unsigned numberOfInitialPages = 0);
    static const ooTypeNumber opiTypeN;
};


class OO_STORAGE_SPECIFIER ooContObj : public ooObj {
  public:
    virtual ooTypeNumber ooGetTypeN() const;
    virtual char* ooGetTypeName() const;
    ooBoolean ooIsKindOf(ooTypeNumber typeN) const
	{ return ooTypeN(ooContObj) == typeN || ooObj::ooIsKindOf(typeN); }
    ooHandle(ooContObj)& ooThis(ooHandle(ooContObj)& objH,
			  ooMode mode = oocNoOpen) const
	{
	  return *((ooHandle(ooContObj) *)
		   (&(this->ooObj::ooThis(objH, mode))));
	}
    ooHandle(ooContObj) ooThis(ooMode mode = oocNoOpen) const;
    ooRef(ooContObj)& ooThis(ooRef(ooContObj)& objId, ooMode mode = oocNoOpen) const;

    void* operator new(size_t);
    void* operator new(size_t, const ooHandle(ooObj)& nearH,
		       uint16 initPages = 4, uint16 percentGrowPageMap = 0, 
		       const char* name = 0, uint16 userContID = 0,
		       ooBoolean externalContainer = oocFalse,
		       const char *hostName = 0, const char *pathName = 0,
		       const unsigned pageSize = 0);
    void* operator new(size_t, const ooId& nearId);
    void* operator new(size_t, const ooObj* nearObj);

		// deprecated (old catalog) operator new
    void* operator new(size_t, const char* name, uint32 hash, uint32 initPages, uint32 grow, const ooHandle(ooObj)& nearH);
    void* operator new(size_t, const char* name, uint32 hash, uint32 initPages, uint32 grow, const ooId& nearId);
    void* operator new(size_t, const char* name, uint32 hash, uint32 initPages, uint32 grow, const ooObj* nearObj);
#ifdef OO_PLACEMENT_DELETE
    void operator delete(void* object) {
	  ooObj::operator delete(object);
	}
#ifdef __SUNPRO_CC
    // The Sun compiler requires defaults for parameters that are optional 
    // in `new', but the Microsoft compiler doesn't allow them.
    void operator delete(void* object, const ooHandle(ooObj)&, 
			 uint16 = 4, uint16 = 0, const char* = 0, uint16 = 0,
			 ooBoolean = oocFalse, const char* = 0,
			 const char* = 0, const unsigned = 0)
	{
	  ooObj::operator delete(object);
	}
#else
    void operator delete(void* object, const ooHandle(ooObj)&, uint16, uint16,
			const char*, uint16, ooBoolean, const char*, const char*, const unsigned) {
	  ooObj::operator delete(object);
	}
#endif
    void operator delete(void* object, const ooId&) {
	  ooObj::operator delete(object);
	}
    void operator delete(void* object, const ooObj*) {
	  ooObj::operator delete(object);
	}
    void operator delete(void* object, const char*, uint32, uint32 , uint32) {
	  ooObj::operator delete(object);
	}
    void operator delete(void* object, const char*, uint32, uint32 , uint32 , const ooHandle(ooObj)&) {
	  ooObj::operator delete(object);
	}
    void operator delete(void* object, const char* , uint32, uint32, uint32, const ooId &) {
	  ooObj::operator delete(object);
	}
    void operator delete(void* object, const char *, uint32, uint32, uint32, const ooObj*) {
	  ooObj::operator delete(object);
	}
#endif
    ooContObj(ooInternalObj iobj);
    static const ooTypeNumber opiTypeN;
    static const ooAssocNumber indexes_ooAssocN;
  public:
     ooContObj() {}
    // ODMG methods:
    void *operator new(size_t size, const ooHandle(ooObj) &nearH, const char *) {
	   return operator new(size, nearH);
    }
#ifdef OO_PLACEMENT_DELETE
    void operator delete(void* object, const ooHandle(ooObj)&, const char*) {
	  ooObj::operator delete(object);
	}
#endif
#ifdef OO_ODMG
    void *operator new(size_t size, d_Database *db, const char *type_name = 0);
#ifdef OO_PLACEMENT_DELETE
    void operator delete(void* object, d_Database*, const char*) {
	  ooObj::operator delete(object);
	}
#endif
#endif
// Objectivity internal use only
#ifdef OO_DDL_TRANSLATION
    ooRef(ooSysIndex) indexes[] <-> container  : lock(propagate),
						 delete(propagate);
#else /* !defined(OO_DDL_TRANSLATION) */
    /* Methods for bidirectional association link: indexes[] */
    ooStatus indexes(ooItr(ooSysIndex)& itr, ooMode mode = oocNoOpen) const;
    ooStatus indexes(ooItr(ooSysIndex)& itr,const char* predicate) const;
    ooStatus indexes(ooItr(ooSysIndex)& itr,ooMode mode,
		 const ooAccessMode access, const char* predicate) const;
    ooStatus add_indexes(const ooHandle(ooSysIndex)& newObjH);
    ooStatus sub_indexes(const ooHandle(ooSysIndex)& objH);
    ooStatus del_indexes() { return opiDelAssoc(ooDysoc(), ooAssocN(ooContObj,indexes)); }
    ooBoolean exist_indexes(const ooHandle(ooSysIndex)& objH) const;
    ooBoolean exist_indexes() const
      {
        return this->exist_indexes((const ooHandle(ooSysIndex) &)
				   (oocNullHandle));
      }
#endif /* !defined(OO_DDL_TRANSLATION) */
};

// Introduced ostensibly for SPR 17152, this class provides a minimally
// functional vtable for Active Schema objects, which don't have the C++
// language support found in ooddlx-generated source files
// NOTE if you add any virtual functions to this class you must modify
// NUM_AS_FUNC_POINTERS found in otmPvt.h
class OO_STORAGE_SPECIFIER ooAsObj : public ooObj {
public:
  virtual ooBoolean ooIsKindOf(ooTypeNumber typeN) const;
  virtual ooTypeNumber ooGetTypeN() const;
  virtual ooBoolean ooValidate() { return oocTrue; }
  ooAsObj(ooInternalObj) {}
protected:
  ooAsObj() {}
};


///////////////////////////////////////////////////////////////////////////////

#ifdef OO_ODMG

inline
void *
ooObj::operator new(size_t size, d_Database *db, const char *)
{
  return opiODMGDatabaseNew(size, ooTypeN(ooObj), db);
}

inline
void *
ooContObj::operator new(size_t size, d_Database *db, const char *)
{
  return opiODMGDatabaseNew(size, ooTypeN(ooContObj), db);
}

#endif


inline
void 
ooRef(ooObj)::delete_object()
{
delete this->ptr();
}
inline
void 
ooHandle(ooObj)::delete_object()
{
delete this->ptr();
}


#ifndef OO_DDL_TRANSLATION

inline
ooStatus
ooObj::nextVers(ooItr(ooObj) &itr,
		const char* predicate) const
{
  return opiInitAssocVPredItr(itr,
			      ooDysoc(),
			      ooAssocN(ooObj, nextVers),
			      predicate,
			      oocPublic,
			      oocNoOpen);
}

inline
ooStatus
ooObj::nextVers(ooItr(ooObj) &itr,
		ooMode mode,
		const ooAccessMode access,
		const char* predicate) const
{
  return opiInitAssocVPredItr(itr,
			      ooDysoc(),
			      ooAssocN(ooObj, nextVers),
			      predicate,
			      access,
			      mode);
}

inline
ooStatus
ooObj::derivatives(ooItr(ooObj) &itr,
		   const char* predicate) const
{
  return opiInitAssocVPredItr(itr,
			      ooDysoc(),
			      ooAssocN(ooObj, derivatives),
			      predicate,
			      oocPublic,
			      oocNoOpen);
}

inline
ooStatus
ooObj::derivatives(ooItr(ooObj) &itr,
		   ooMode mode,
		   const ooAccessMode access,
		   const char* predicate) const
{
  return opiInitAssocVPredItr(itr,
			      ooDysoc(),
			      ooAssocN(ooObj, derivatives),
			      predicate,
			      access,
			      mode);
}


inline
ooStatus
ooObj::derivedFrom(ooItr(ooObj) &itr,
		   const char* predicate) const
{
  return opiInitAssocVPredItr(itr,
			      ooDysoc(),
			      ooAssocN(ooObj, derivedFrom),
			      predicate,
			      oocPublic,
			      oocNoOpen);
}

inline
ooStatus
ooObj::derivedFrom(ooItr(ooObj) &itr,
		   ooMode mode,
		   const ooAccessMode access,
		   const char* predicate) const
{
  return opiInitAssocVPredItr(itr,
			      ooDysoc(),
			      ooAssocN(ooObj, derivedFrom),
			      predicate,
			      access,
			      mode);
}

inline
ooStatus
ooObj::mapElems(ooItr(ooMapElem) &itr,
		const char* predicate) const
{
  return opiInitAssocVPredItr(itr,
			      ooDysoc(),
			      ooAssocN(ooObj, mapElems),
			      predicate,
			      oocPublic,
			      oocNoOpen);
}

inline
ooStatus
ooObj::mapElems(ooItr(ooMapElem) &itr,
		ooMode mode,
		const ooAccessMode access,
		const char* predicate) const
{
  return opiInitAssocVPredItr(itr,
			      ooDysoc(),
			      ooAssocN(ooObj, mapElems),
			      predicate,
			      access,
			      mode);
}


inline
ooStatus
ooObj::checkoutInfo(ooItr(ooCheckOutInfoObj) &itr,
		    const char* predicate) const
{
  return opiInitAssocVPredItr(itr,
			      ooDysoc(),
			      ooAssocN(ooObj, checkoutInfo),
			      predicate,
			      oocPublic,
			      oocNoOpen);
}

inline
ooStatus
ooObj::checkoutInfo(ooItr(ooCheckOutInfoObj) &itr,
		    ooMode mode,
		    const ooAccessMode access,
		    const char* predicate) const
{
  return opiInitAssocVPredItr(itr,
			      ooDysoc(),
			      ooAssocN(ooObj, checkoutInfo),
			      predicate,
			      access,
			      mode);
}


inline
ooStatus
ooObj::nameScope(ooItr(ooObj) &itr,
		 const char* predicate) const
{
  return opiInitAssocVPredItr(itr,
			      ooDysoc(),
			      ooAssocN(ooObj, nameScope),
			      predicate,
			      oocPublic,
			      oocNoOpen);
}

inline
ooStatus
ooObj::nameScope(ooItr(ooObj) &itr,
		 ooMode mode,
		 const ooAccessMode access,
		 const char* predicate) const
{
  return opiInitAssocVPredItr(itr,
			      ooDysoc(),
			      ooAssocN(ooObj, nameScope),
			      predicate,
			      access,
			      mode);
}

inline
ooStatus
ooObj::nameObj(ooItr(ooObj) &itr,
	       const char* predicate) const
{
  return opiInitAssocVPredItr(itr,
			      ooDysoc(),
			      ooAssocN(ooObj, nameObj),
			      predicate,
			      oocPublic,
			      oocNoOpen);
}

inline
ooStatus
ooObj::nameObj(ooItr(ooObj) &itr,
	       ooMode mode,
	       const ooAccessMode access,
	       const char* predicate) const
{
  return opiInitAssocVPredItr(itr,
			      ooDysoc(),
			      ooAssocN(ooObj, nameObj),
			      predicate,
			      access,
			      mode);
}


inline
ooStatus
ooContObj::indexes(ooItr(ooSysIndex) &itr,
		   const char* predicate) const
{
  return opiInitAssocVPredItr(itr,
			      ooDysoc(),
			      ooAssocN(ooContObj, indexes),
			      predicate,
			      oocPublic,
			      oocNoOpen);
}

inline
ooStatus
ooContObj::indexes(ooItr(ooSysIndex) &itr,
		   ooMode mode,
		   const ooAccessMode access,
		   const char* predicate) const
{
  return opiInitAssocVPredItr(itr,
			      ooDysoc(),
			      ooAssocN(ooContObj, indexes),
			      predicate,
			      access,
			      mode);
}

inline
ooStatus
ooObj::owns(ooItr(ooObj) &itr,
		const char* predicate) const
{
  return opiInitAssocVPredItr(itr,
			      ooDysoc(),
			      ooAssocN(ooObj, owns),
			      predicate,
			      oocPublic,
			      oocNoOpen);
}

inline
ooStatus
ooObj::owns(ooItr(ooObj) &itr,
		ooMode mode,
		const ooAccessMode access,
		const char* predicate) const
{
  return opiInitAssocVPredItr(itr,
			      ooDysoc(),
			      ooAssocN(ooObj, owns),
			      predicate,
			      access,
			      mode);
}

#endif /* !defined(OO_DDL_TRANSLATION) */


///////////////////////////////////////////////////////////////////////////////

#if defined(_MSC_VER) && !defined(OO_DDL_TRANSLATION)
#pragma pack(pop)
#endif

#endif /* OO_SCHEMA_H */
