/**************************************************************************
  		  Copyright (c) 1992-2002 Objectivity, Inc.
 	  		  All Rights Reserved

 	THIS IS UNPUBLISHED PROPRIETARY SOURCE CODE OF OBJECTIVITY, INC.

 	The copyright notice above does not evidence any
 	actual or intended publication of such source code.

*****************************************************************************/

#ifndef OO_PREDEFINED_H
#define OO_PREDEFINED_H

#ifdef OO_DDL_TRANSLATION
#pragma ooddlout "predefined.ddl"
#pragma ooddlout "./predefined_assign.ddl"
class opiDummyDeclaration;
#endif

#ifndef OO_H
#include <oo.h>
#endif
#include <ooString.h>

#ifndef OO_PREDEFINED_REF_H
#include "ooPredef_ref.h"
#endif

class ooDefaultContObj : public ooContObj { 

public: ooDefaultContObj(uint16, uint16, const char *); 

private: char name[32]; 
uint16 dbId; 
uint16 ocId; 
uint32 nOpen; 
uint32 nClose; 
public: 
#ifndef OO_DDL_TRANSLATION
    virtual ooTypeNumber ooGetTypeN() const;
    virtual char* ooGetTypeName() const;
    ooBoolean ooIsKindOf(ooTypeNumber oo_typeN) const;
    ooHandle(ooDefaultContObj)& ooThis(ooHandle(ooDefaultContObj)& objH,
			 ooMode aMode = oocNoOpen) const
      {
	return *ooReinterpretCast(ooHandle(ooDefaultContObj) *, &(this->ooObj::ooThis(objH, aMode)));
      }
    ooHandle(ooDefaultContObj) ooThis(ooMode aMode = oocNoOpen) const;
    void *operator new(size_t);
    void *operator new(size_t, const ooHandle(ooObj) &nearH);
    void *operator new(size_t, const ooHandle(ooObj) &nearH, ooClusterStrategy& strategy)
	{
		return strategy.newObj(ooTypeN(ooDefaultContObj), nearH);
	}
    void *operator new(size_t, const ooId& nearR, ooClusterStrategy& strategy)
	{
		return strategy.newObj(ooTypeN(ooDefaultContObj), nearR);
	}
    void *operator new(size_t, ooClusterStrategy& strategy)
	{
		return strategy.newObj(ooTypeN(ooDefaultContObj));
	}
    void *operator new(size_t, const ooId& nearId);
    void *operator new(size_t, const objy::placement::Conditions& conditions);
    void *operator new(size_t, const ooObj *nearObj);
    void *operator new(size_t, const ooHandle(ooObj) &nearH, const char *typeName);
#ifdef OO_PLACEMENT_DELETE
    void operator delete(void* object) {
	  ooObj::operator delete(object);
	}
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
    void operator delete(void* object, const objy::placement::Conditions&) {
	  ooObj::operator delete(object);
	}
    void operator delete(void* object, const ooObj*) {
	  ooObj::operator delete(object);
	}
    void operator delete(void* object, const ooHandle(ooObj)&, const char*) {
	  ooObj::operator delete(object);
	}
#endif
#ifdef OO_ODMG
    void *operator new(size_t  size, d_Database *odmg_db);
    void *operator new(size_t  size, d_Database *odmg_db, const char *);
#ifdef OO_PLACEMENT_DELETE
    void operator delete(void* object, d_Database*) {
	  ooObj::operator delete(object);
	}
    void operator delete(void* object, d_Database*  odmg_db, const char*) {
	  ooObj::operator delete(object);
	}
#endif
#endif
    static const ooTypeNumber opiTypeN;
    static void ooAssocRegister();
    void* operator new(size_t, const char*, uint32, uint32, uint32);
    void* operator new(size_t, const char*, uint32, uint32, uint32, const ooHandle(ooObj)& nearH);
    void* operator new(size_t, const char*, uint32, uint32, uint32, const ooId& nearId);
    void* operator new(size_t, const char*, uint32, uint32, uint32, const ooObj *nearObj);
    void* operator new(size_t size, const ooHandle(ooObj)& nearH,
		       uint16 initPages, uint16 percentGrowPageMap = 0, 
		       const char* name = 0, uint16 userContID = 0,
		       ooBoolean externalContainer = oocFalse,
		       const char *hostName = 0, const char *pathName = 0,
		       const unsigned pageSize = 0);
#ifdef OO_PLACEMENT_DELETE
    void operator delete(void* object, const char*, uint32, uint32, uint32) {
	  ooObj::operator delete(object);
	}
    void operator delete(void* object, const char*, uint32, uint32, uint32, const ooHandle(ooObj)&) {
	  ooObj::operator delete(object);
	}
    void operator delete(void* object, const char*, uint32, uint32, uint32, const ooId&) {
	  ooObj::operator delete(object);
	}
    void operator delete(void* object, const char*, uint32, uint32, uint32, const ooObj*) {
	  ooObj::operator delete(object);
	}
#ifdef __SUNPRO_CC
    void operator delete(void* object, const ooHandle(ooObj)&,
		       uint16, uint16 = 0, 
		       const char* = 0, uint16 = 0,
		       ooBoolean = oocFalse,
		       const char* = 0, const char* = 0,
		       const unsigned = 0) {
	  ooObj::operator delete(object);
	}
#else
    void operator delete(void* object, const ooHandle(ooObj)&,
		       uint16, uint16, 
		       const char*, uint16,
		       ooBoolean,
		       const char*, const char*,
		       const unsigned) {
	  ooObj::operator delete(object);
	}
#endif
#endif
    ooRef(ooDefaultContObj)& ooThis(ooRef(ooDefaultContObj)& objId, ooMode aMode = oocNoOpen) const;
    ooDefaultContObj(ooInternalObj iobj);
#endif /* !defined(OO_DDL_TRANSLATION) */
}; 

class ooGCContObj : public ooContObj { 
public: 
#ifndef OO_DDL_TRANSLATION
    virtual ooTypeNumber ooGetTypeN() const;
    virtual char* ooGetTypeName() const;
    ooBoolean ooIsKindOf(ooTypeNumber oo_typeN) const;
    ooHandle(ooGCContObj)& ooThis(ooHandle(ooGCContObj)& objH,
			 ooMode aMode = oocNoOpen) const
      {
	return *ooReinterpretCast(ooHandle(ooGCContObj) *, &(this->ooObj::ooThis(objH, aMode)));
      }
    ooHandle(ooGCContObj) ooThis(ooMode aMode = oocNoOpen) const;
    void *operator new(size_t);
    void *operator new(size_t, const ooHandle(ooObj) &nearH);
    void *operator new(size_t, const ooHandle(ooObj) &nearH, ooClusterStrategy& strategy)
	{
		return strategy.newObj(ooTypeN(ooGCContObj), nearH);
	}
    void *operator new(size_t, const ooId& nearR, ooClusterStrategy& strategy)
	{
		return strategy.newObj(ooTypeN(ooGCContObj), nearR);
	}
    void *operator new(size_t, ooClusterStrategy& strategy)
	{
		return strategy.newObj(ooTypeN(ooGCContObj));
	}
    void *operator new(size_t, const ooId& nearId);
    void *operator new(size_t, const objy::placement::Conditions& conditions);
    void *operator new(size_t, const ooObj *nearObj);
    void *operator new(size_t, const ooHandle(ooObj) &nearH, const char *typeName);
#ifdef OO_PLACEMENT_DELETE
    void operator delete(void* object) {
	  ooObj::operator delete(object);
	}
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
    void operator delete(void* object, const objy::placement::Conditions&) {
	  ooObj::operator delete(object);
	}
    void operator delete(void* object, const ooObj*) {
	  ooObj::operator delete(object);
	}
    void operator delete(void* object, const ooHandle(ooObj)&, const char*) {
	  ooObj::operator delete(object);
	}
#endif
#ifdef OO_ODMG
    void *operator new(size_t  size, d_Database *odmg_db);
    void *operator new(size_t  size, d_Database *odmg_db, const char *);
#ifdef OO_PLACEMENT_DELETE
    void operator delete(void* object, d_Database*) {
	  ooObj::operator delete(object);
	}
    void operator delete(void* object, d_Database*  odmg_db, const char*) {
	  ooObj::operator delete(object);
	}
#endif
#endif
    static const ooTypeNumber opiTypeN;
    static void ooAssocRegister();
    void* operator new(size_t, const char*, uint32, uint32, uint32);
    void* operator new(size_t, const char*, uint32, uint32, uint32, const ooHandle(ooObj)& nearH);
    void* operator new(size_t, const char*, uint32, uint32, uint32, const ooId& nearId);
    void* operator new(size_t, const char*, uint32, uint32, uint32, const ooObj *nearObj);
    void* operator new(size_t size, const ooHandle(ooObj)& nearH,
		       uint16 initPages, uint16 percentGrowPageMap = 0, 
		       const char* name = 0, uint16 userContID = 0,
		       ooBoolean externalContainer = oocFalse,
		       const char *hostName = 0, const char *pathName = 0,
		       const unsigned pageSize = 0);
#ifdef OO_PLACEMENT_DELETE
    void operator delete(void* object, const char*, uint32, uint32, uint32) {
	  ooObj::operator delete(object);
	}
    void operator delete(void* object, const char*, uint32, uint32, uint32, const ooHandle(ooObj)&) {
	  ooObj::operator delete(object);
	}
    void operator delete(void* object, const char*, uint32, uint32, uint32, const ooId&) {
	  ooObj::operator delete(object);
	}
    void operator delete(void* object, const char*, uint32, uint32, uint32, const ooObj*) {
	  ooObj::operator delete(object);
	}
#ifdef __SUNPRO_CC
    void operator delete(void* object, const ooHandle(ooObj)&,
		       uint16, uint16 = 0, 
		       const char* = 0, uint16 = 0,
		       ooBoolean = oocFalse,
		       const char* = 0, const char* = 0,
		       const unsigned = 0) {
	  ooObj::operator delete(object);
	}
#else
    void operator delete(void* object, const ooHandle(ooObj)&,
		       uint16, uint16, 
		       const char*, uint16,
		       ooBoolean,
		       const char*, const char*,
		       const unsigned) {
	  ooObj::operator delete(object);
	}
#endif
#endif
    ooRef(ooGCContObj)& ooThis(ooRef(ooGCContObj)& objId, ooMode aMode = oocNoOpen) const;
    ooGCContObj(ooInternalObj iobj);
    ooGCContObj() {}
#endif /* !defined(OO_DDL_TRANSLATION) */
}; 
class ooGCRootsCont : public ooGCContObj { 
public: 
#ifndef OO_DDL_TRANSLATION
    virtual ooTypeNumber ooGetTypeN() const;
    virtual char* ooGetTypeName() const;
    ooBoolean ooIsKindOf(ooTypeNumber oo_typeN) const;
    ooHandle(ooGCRootsCont)& ooThis(ooHandle(ooGCRootsCont)& objH,
			 ooMode aMode = oocNoOpen) const
      {
	return *ooReinterpretCast(ooHandle(ooGCRootsCont) *, &(this->ooObj::ooThis(objH, aMode)));
      }
    ooHandle(ooGCRootsCont) ooThis(ooMode aMode = oocNoOpen) const;
    void *operator new(size_t);
    void *operator new(size_t, const ooHandle(ooObj) &nearH);
    void *operator new(size_t, const ooHandle(ooObj) &nearH, ooClusterStrategy& strategy)
	{
		return strategy.newObj(ooTypeN(ooGCRootsCont), nearH);
	}
    void *operator new(size_t, const ooId& nearR, ooClusterStrategy& strategy)
	{
		return strategy.newObj(ooTypeN(ooGCRootsCont), nearR);
	}
    void *operator new(size_t, ooClusterStrategy& strategy)
	{
		return strategy.newObj(ooTypeN(ooGCRootsCont));
	}
    void *operator new(size_t, const ooId& nearId);
    void *operator new(size_t, const objy::placement::Conditions& conditions);
    void *operator new(size_t, const ooObj *nearObj);
    void *operator new(size_t, const ooHandle(ooObj) &nearH, const char *typeName);
#ifdef OO_PLACEMENT_DELETE
    void operator delete(void* object) {
	  ooObj::operator delete(object);
	}
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
    void operator delete(void* object, const objy::placement::Conditions&) {
	  ooObj::operator delete(object);
	}
    void operator delete(void* object, const ooObj*) {
	  ooObj::operator delete(object);
	}
    void operator delete(void* object, const ooHandle(ooObj)&, const char*) {
	  ooObj::operator delete(object);
	}
#endif
#ifdef OO_ODMG
    void *operator new(size_t  size, d_Database *odmg_db);
    void *operator new(size_t  size, d_Database *odmg_db, const char *);
#ifdef OO_PLACEMENT_DELETE
    void operator delete(void* object, d_Database*) {
	  ooObj::operator delete(object);
	}
    void operator delete(void* object, d_Database*  odmg_db, const char*) {
	  ooObj::operator delete(object);
	}
#endif
#endif
    static const ooTypeNumber opiTypeN;
    static void ooAssocRegister();
    void* operator new(size_t, const char*, uint32, uint32, uint32);
    void* operator new(size_t, const char*, uint32, uint32, uint32, const ooHandle(ooObj)& nearH);
    void* operator new(size_t, const char*, uint32, uint32, uint32, const ooId& nearId);
    void* operator new(size_t, const char*, uint32, uint32, uint32, const ooObj *nearObj);
    void* operator new(size_t size, const ooHandle(ooObj)& nearH,
		       uint16 initPages, uint16 percentGrowPageMap = 0, 
		       const char* name = 0, uint16 userContID = 0,
		       ooBoolean externalContainer = oocFalse,
		       const char *hostName = 0, const char *pathName = 0,
		       const unsigned pageSize = 0);
#ifdef OO_PLACEMENT_DELETE
    void operator delete(void* object, const char*, uint32, uint32, uint32) {
	  ooObj::operator delete(object);
	}
    void operator delete(void* object, const char*, uint32, uint32, uint32, const ooHandle(ooObj)&) {
	  ooObj::operator delete(object);
	}
    void operator delete(void* object, const char*, uint32, uint32, uint32, const ooId&) {
	  ooObj::operator delete(object);
	}
    void operator delete(void* object, const char*, uint32, uint32, uint32, const ooObj*) {
	  ooObj::operator delete(object);
	}
#ifdef __SUNPRO_CC
    void operator delete(void* object, const ooHandle(ooObj)&,
		       uint16, uint16 = 0, 
		       const char* = 0, uint16 = 0,
		       ooBoolean = oocFalse,
		       const char* = 0, const char* = 0,
		       const unsigned = 0) {
	  ooObj::operator delete(object);
	}
#else
    void operator delete(void* object, const ooHandle(ooObj)&,
		       uint16, uint16, 
		       const char*, uint16,
		       ooBoolean,
		       const char*, const char*,
		       const unsigned) {
	  ooObj::operator delete(object);
	}
#endif
#endif
    ooRef(ooGCRootsCont)& ooThis(ooRef(ooGCRootsCont)& objId, ooMode aMode = oocNoOpen) const;
    ooGCRootsCont(ooInternalObj iobj);
    ooGCRootsCont() {}
#endif /* !defined(OO_DDL_TRANSLATION) */
}; 




class ooCheckOutInfoObj : public ooObj { 

public: inline ooCheckOutInfoObj() { }

private: uint8 mode; 
char userName[32]; 
int32 time; 
#ifdef OO_DDL_TRANSLATION
    ooRef(ooObj) checkout <-> checkoutInfo[];
#else /* !defined(OO_DDL_TRANSLATION) */
    /* Methods for bidirectional association link: checkout */
    ooHandle(ooObj) checkout(ooMode mode = oocNoOpen) const;
    ooHandle(ooObj)& checkout(ooHandle(ooObj)& objH,
		       ooMode mode = oocNoOpen) const;
    ooStatus set_checkout(const ooHandle(ooObj)& objH);
    ooStatus del_checkout()
      {
	return opiDelAssoc_1(this->ooDysoc(), ooAssocN(ooCheckOutInfoObj,checkout));
      }
    ooBoolean exist_checkout(const ooHandle(ooObj)& objH) const;
    ooBoolean exist_checkout() const
      {
        return this->exist_checkout(*ooReinterpretCast(ooHandle(ooObj) *,
						 &oocNullHandle));
      }
    static ooAssocNumber checkout_ooAssocN;
    ooRef(ooObj)& checkout(ooRef(ooObj)& objId, ooMode mode = oocNoOpen) const;
#endif /* !defined(OO_DDL_TRANSLATION) */
public: 
#ifndef OO_DDL_TRANSLATION
    virtual ooTypeNumber ooGetTypeN() const;
    virtual char* ooGetTypeName() const;
    ooBoolean ooIsKindOf(ooTypeNumber oo_typeN) const;
    ooHandle(ooCheckOutInfoObj)& ooThis(ooHandle(ooCheckOutInfoObj)& objH,
			 ooMode aMode = oocNoOpen) const
      {
	return *ooReinterpretCast(ooHandle(ooCheckOutInfoObj) *, &(this->ooObj::ooThis(objH, aMode)));
      }
    ooHandle(ooCheckOutInfoObj) ooThis(ooMode aMode = oocNoOpen) const;
    void *operator new(size_t);
    void *operator new(size_t, const ooHandle(ooObj) &nearH);
    void *operator new(size_t, const ooHandle(ooObj) &nearH, ooClusterStrategy& strategy)
	{
		return strategy.newObj(ooTypeN(ooCheckOutInfoObj), nearH);
	}
    void *operator new(size_t, const ooId& nearR, ooClusterStrategy& strategy)
	{
		return strategy.newObj(ooTypeN(ooCheckOutInfoObj), nearR);
	}
    void *operator new(size_t, ooClusterStrategy& strategy)
	{
		return strategy.newObj(ooTypeN(ooCheckOutInfoObj));
	}
    void *operator new(size_t, const ooId& nearId);
    void *operator new(size_t, const objy::placement::Conditions& conditions);
    void *operator new(size_t, const ooObj *nearObj);
    void *operator new(size_t, const ooHandle(ooObj) &nearH, const char *typeName);
#ifdef OO_PLACEMENT_DELETE
    void operator delete(void* object) {
	  ooObj::operator delete(object);
	}
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
    void operator delete(void* object, const objy::placement::Conditions&) {
	  ooObj::operator delete(object);
	}
    void operator delete(void* object, const ooObj*) {
	  ooObj::operator delete(object);
	}
    void operator delete(void* object, const ooHandle(ooObj)&, const char*) {
	  ooObj::operator delete(object);
	}
#endif
#ifdef OO_ODMG
    void *operator new(size_t  size, d_Database *odmg_db);
    void *operator new(size_t  size, d_Database *odmg_db, const char *);
#ifdef OO_PLACEMENT_DELETE
    void operator delete(void* object, d_Database*) {
	  ooObj::operator delete(object);
	}
    void operator delete(void* object, d_Database*  odmg_db, const char*) {
	  ooObj::operator delete(object);
	}
#endif
#endif
    static const ooTypeNumber opiTypeN;
    static void ooAssocRegister();
    ooRef(ooCheckOutInfoObj)& ooThis(ooRef(ooCheckOutInfoObj)& objId, ooMode aMode = oocNoOpen) const;
    ooCheckOutInfoObj(ooInternalObj iobj);
#endif /* !defined(OO_DDL_TRANSLATION) */
}; 




class ooGeneObj : public ooObj { 



friend ooStatus ooHandle(ooObj)::getDefaultVers(ooHandle(ooObj) &) const; 


public: inline ooGeneObj() { }
#ifdef OO_DDL_TRANSLATION
    ooRef(ooObj) allVers[] <-> geneObj;
#else /* !defined(OO_DDL_TRANSLATION) */
    /* Methods for bidirectional association link: allVers[] */
    ooStatus allVers(ooItr(ooObj)& itr, ooMode mode = oocNoOpen) const;
    ooStatus allVers(ooItr(ooObj)& itr, const char* predicate) const
      {
	return opiInitAssocVPredItr(*ooReinterpretCast(ooHandle(ooObj) *,
						       &itr),
				    this->ooDysoc(),
				    ooAssocN(ooGeneObj,allVers),
				    predicate,
				    oocPublic,
				    oocNoOpen);
      }
    ooStatus allVers(ooItr(ooObj)& itr,
		 ooMode mode,
		 const ooAccessMode access,
		 const char* predicate) const
      {
	return opiInitAssocVPredItr(*ooReinterpretCast(ooHandle(ooObj) *,
						       &itr),
				    this->ooDysoc(),
				    ooAssocN(ooGeneObj,allVers),
				    predicate,
				    access,
				    mode);
      }
    ooStatus allVers(ooItr(ooObj)& itr, 
               ooMode mode,
               const objy::query::ObjectQualifier& objQualifier) const
      {
	return opiInitAssocVQualItr(*ooReinterpretCast(ooHandle(ooObj) *,
						       &itr),
				    this->ooDysoc(),
				    ooAssocN(ooGeneObj,allVers),
				    objQualifier,
				    mode);
      }
    ooStatus add_allVers(const ooHandle(ooObj)& newObjH);
    ooStatus sub_allVers(const ooHandle(ooObj)& objH);
    ooStatus del_allVers()
      {
	return opiDelAssoc(this->ooDysoc(), ooAssocN(ooGeneObj,allVers));
      }
    ooBoolean exist_allVers(const ooHandle(ooObj)& objH) const;
    ooBoolean exist_allVers() const
      {
        return this->exist_allVers(*ooReinterpretCast(ooHandle(ooObj) *,
						 &oocNullHandle));
      }
    static ooAssocNumber allVers_ooAssocN;
#endif /* !defined(OO_DDL_TRANSLATION) */
#ifdef OO_DDL_TRANSLATION
    ooRef(ooObj) defaultVers <-> defaultToGeneObj;
#else /* !defined(OO_DDL_TRANSLATION) */
    /* Methods for bidirectional association link: defaultVers */
    ooHandle(ooObj) defaultVers(ooMode mode = oocNoOpen) const;
    ooHandle(ooObj)& defaultVers(ooHandle(ooObj)& objH,
		       ooMode mode = oocNoOpen) const;
    ooStatus set_defaultVers(const ooHandle(ooObj)& objH);
    ooStatus del_defaultVers()
      {
	return opiDelAssoc_1(this->ooDysoc(), ooAssocN(ooGeneObj,defaultVers));
      }
    ooBoolean exist_defaultVers(const ooHandle(ooObj)& objH) const;
    ooBoolean exist_defaultVers() const
      {
        return this->exist_defaultVers(*ooReinterpretCast(ooHandle(ooObj) *,
						 &oocNullHandle));
      }
    static ooAssocNumber defaultVers_ooAssocN;
    ooRef(ooObj)& defaultVers(ooRef(ooObj)& objId, ooMode mode = oocNoOpen) const;
#endif /* !defined(OO_DDL_TRANSLATION) */


private: ooId id; 
public: 
#ifndef OO_DDL_TRANSLATION
    virtual ooTypeNumber ooGetTypeN() const;
    virtual char* ooGetTypeName() const;
    ooBoolean ooIsKindOf(ooTypeNumber oo_typeN) const;
    ooHandle(ooGeneObj)& ooThis(ooHandle(ooGeneObj)& objH,
			 ooMode aMode = oocNoOpen) const
      {
	return *ooReinterpretCast(ooHandle(ooGeneObj) *, &(this->ooObj::ooThis(objH, aMode)));
      }
    ooHandle(ooGeneObj) ooThis(ooMode aMode = oocNoOpen) const;
    void *operator new(size_t);
    void *operator new(size_t, const ooHandle(ooObj) &nearH);
    void *operator new(size_t, const ooHandle(ooObj) &nearH, ooClusterStrategy& strategy)
	{
		return strategy.newObj(ooTypeN(ooGeneObj), nearH);
	}
    void *operator new(size_t, const ooId& nearR, ooClusterStrategy& strategy)
	{
		return strategy.newObj(ooTypeN(ooGeneObj), nearR);
	}
    void *operator new(size_t, ooClusterStrategy& strategy)
	{
		return strategy.newObj(ooTypeN(ooGeneObj));
	}
    void *operator new(size_t, const ooId& nearId);
    void *operator new(size_t, const objy::placement::Conditions& conditions);
    void *operator new(size_t, const ooObj *nearObj);
    void *operator new(size_t, const ooHandle(ooObj) &nearH, const char *typeName);
#ifdef OO_PLACEMENT_DELETE
    void operator delete(void* object) {
	  ooObj::operator delete(object);
	}
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
    void operator delete(void* object, const objy::placement::Conditions&) {
	  ooObj::operator delete(object);
	}
    void operator delete(void* object, const ooObj*) {
	  ooObj::operator delete(object);
	}
    void operator delete(void* object, const ooHandle(ooObj)&, const char*) {
	  ooObj::operator delete(object);
	}
#endif
#ifdef OO_ODMG
    void *operator new(size_t  size, d_Database *odmg_db);
    void *operator new(size_t  size, d_Database *odmg_db, const char *);
#ifdef OO_PLACEMENT_DELETE
    void operator delete(void* object, d_Database*) {
	  ooObj::operator delete(object);
	}
    void operator delete(void* object, d_Database*  odmg_db, const char*) {
	  ooObj::operator delete(object);
	}
#endif
#endif
    static const ooTypeNumber opiTypeN;
    static void ooAssocRegister();
    ooRef(ooGeneObj)& ooThis(ooRef(ooGeneObj)& objId, ooMode aMode = oocNoOpen) const;
    ooGeneObj(ooInternalObj iobj);
#endif /* !defined(OO_DDL_TRANSLATION) */
}; 
class ooSysIndex : public ooObj { 

public: 
#ifdef OO_DDL_TRANSLATION
    ooRef(ooContObj) container <-> indexes[] : lock(propagate);
#else /* !defined(OO_DDL_TRANSLATION) */
    /* Methods for bidirectional association link: container */
    ooHandle(ooContObj) container(ooMode mode = oocNoOpen) const;
    ooHandle(ooContObj)& container(ooHandle(ooContObj)& objH,
		       ooMode mode = oocNoOpen) const;
    ooStatus set_container(const ooHandle(ooContObj)& objH);
    ooStatus del_container()
      {
	return opiDelAssoc_1(this->ooDysoc(), ooAssocN(ooSysIndex,container));
      }
    ooBoolean exist_container(const ooHandle(ooContObj)& objH) const;
    ooBoolean exist_container() const
      {
        return this->exist_container(*ooReinterpretCast(ooHandle(ooContObj) *,
						 &oocNullHandle));
      }
    static ooAssocNumber container_ooAssocN;
    ooRef(ooContObj)& container(ooRef(ooContObj)& objId, ooMode mode = oocNoOpen) const;
#endif /* !defined(OO_DDL_TRANSLATION) */
#ifndef OO_DDL_TRANSLATION
    virtual ooTypeNumber ooGetTypeN() const;
    virtual char* ooGetTypeName() const;
    ooBoolean ooIsKindOf(ooTypeNumber oo_typeN) const;
    ooHandle(ooSysIndex)& ooThis(ooHandle(ooSysIndex)& objH,
			 ooMode aMode = oocNoOpen) const
      {
	return *ooReinterpretCast(ooHandle(ooSysIndex) *, &(this->ooObj::ooThis(objH, aMode)));
      }
    ooHandle(ooSysIndex) ooThis(ooMode aMode = oocNoOpen) const;
    void *operator new(size_t);
    void *operator new(size_t, const ooHandle(ooObj) &nearH);
    void *operator new(size_t, const ooHandle(ooObj) &nearH, ooClusterStrategy& strategy)
	{
		return strategy.newObj(ooTypeN(ooSysIndex), nearH);
	}
    void *operator new(size_t, const ooId& nearR, ooClusterStrategy& strategy)
	{
		return strategy.newObj(ooTypeN(ooSysIndex), nearR);
	}
    void *operator new(size_t, ooClusterStrategy& strategy)
	{
		return strategy.newObj(ooTypeN(ooSysIndex));
	}
    void *operator new(size_t, const ooId& nearId);
    void *operator new(size_t, const objy::placement::Conditions& conditions);
    void *operator new(size_t, const ooObj *nearObj);
    void *operator new(size_t, const ooHandle(ooObj) &nearH, const char *typeName);
#ifdef OO_PLACEMENT_DELETE
    void operator delete(void* object) {
	  ooObj::operator delete(object);
	}
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
    void operator delete(void* object, const objy::placement::Conditions&) {
	  ooObj::operator delete(object);
	}
    void operator delete(void* object, const ooObj*) {
	  ooObj::operator delete(object);
	}
    void operator delete(void* object, const ooHandle(ooObj)&, const char*) {
	  ooObj::operator delete(object);
	}
#endif
#ifdef OO_ODMG
    void *operator new(size_t  size, d_Database *odmg_db);
    void *operator new(size_t  size, d_Database *odmg_db, const char *);
#ifdef OO_PLACEMENT_DELETE
    void operator delete(void* object, d_Database*) {
	  ooObj::operator delete(object);
	}
    void operator delete(void* object, d_Database*  odmg_db, const char*) {
	  ooObj::operator delete(object);
	}
#endif
#endif
    static const ooTypeNumber opiTypeN;
    static void ooAssocRegister();
    ooRef(ooSysIndex)& ooThis(ooRef(ooSysIndex)& objId, ooMode aMode = oocNoOpen) const;
    ooSysIndex(ooInternalObj iobj);
    ooSysIndex() {}
#endif /* !defined(OO_DDL_TRANSLATION) */

}; 


class ooVStringHolder : public ooObj { 


public: ooVString mString; 
#ifndef OO_DDL_TRANSLATION
    virtual ooTypeNumber ooGetTypeN() const;
    virtual char* ooGetTypeName() const;
    ooBoolean ooIsKindOf(ooTypeNumber oo_typeN) const;
    ooHandle(ooVStringHolder)& ooThis(ooHandle(ooVStringHolder)& objH,
			 ooMode aMode = oocNoOpen) const
      {
	return *ooReinterpretCast(ooHandle(ooVStringHolder) *, &(this->ooObj::ooThis(objH, aMode)));
      }
    ooHandle(ooVStringHolder) ooThis(ooMode aMode = oocNoOpen) const;
    void *operator new(size_t);
    void *operator new(size_t, const ooHandle(ooObj) &nearH);
    void *operator new(size_t, const ooHandle(ooObj) &nearH, ooClusterStrategy& strategy)
	{
		return strategy.newObj(ooTypeN(ooVStringHolder), nearH);
	}
    void *operator new(size_t, const ooId& nearR, ooClusterStrategy& strategy)
	{
		return strategy.newObj(ooTypeN(ooVStringHolder), nearR);
	}
    void *operator new(size_t, ooClusterStrategy& strategy)
	{
		return strategy.newObj(ooTypeN(ooVStringHolder));
	}
    void *operator new(size_t, const ooId& nearId);
    void *operator new(size_t, const objy::placement::Conditions& conditions);
    void *operator new(size_t, const ooObj *nearObj);
    void *operator new(size_t, const ooHandle(ooObj) &nearH, const char *typeName);
#ifdef OO_PLACEMENT_DELETE
    void operator delete(void* object) {
	  ooObj::operator delete(object);
	}
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
    void operator delete(void* object, const objy::placement::Conditions&) {
	  ooObj::operator delete(object);
	}
    void operator delete(void* object, const ooObj*) {
	  ooObj::operator delete(object);
	}
    void operator delete(void* object, const ooHandle(ooObj)&, const char*) {
	  ooObj::operator delete(object);
	}
#endif
#ifdef OO_ODMG
    void *operator new(size_t  size, d_Database *odmg_db);
    void *operator new(size_t  size, d_Database *odmg_db, const char *);
#ifdef OO_PLACEMENT_DELETE
    void operator delete(void* object, d_Database*) {
	  ooObj::operator delete(object);
	}
    void operator delete(void* object, d_Database*  odmg_db, const char*) {
	  ooObj::operator delete(object);
	}
#endif
#endif
    static const ooTypeNumber opiTypeN;
    static void ooAssocRegister();
    ooRef(ooVStringHolder)& ooThis(ooRef(ooVStringHolder)& objId, ooMode aMode = oocNoOpen) const;
    ooVStringHolder(ooInternalObj iobj);
    ooVStringHolder() {}
#endif /* !defined(OO_DDL_TRANSLATION) */
}; 

class ooUtf8StringHolder : public ooObj { 


public: ooUtf8String mString; 
#ifndef OO_DDL_TRANSLATION
    virtual ooTypeNumber ooGetTypeN() const;
    virtual char* ooGetTypeName() const;
    ooBoolean ooIsKindOf(ooTypeNumber oo_typeN) const;
    ooHandle(ooUtf8StringHolder)& ooThis(ooHandle(ooUtf8StringHolder)& objH,
			 ooMode aMode = oocNoOpen) const
      {
	return *ooReinterpretCast(ooHandle(ooUtf8StringHolder) *, &(this->ooObj::ooThis(objH, aMode)));
      }
    ooHandle(ooUtf8StringHolder) ooThis(ooMode aMode = oocNoOpen) const;
    void *operator new(size_t);
    void *operator new(size_t, const ooHandle(ooObj) &nearH);
    void *operator new(size_t, const ooHandle(ooObj) &nearH, ooClusterStrategy& strategy)
	{
		return strategy.newObj(ooTypeN(ooUtf8StringHolder), nearH);
	}
    void *operator new(size_t, const ooId& nearR, ooClusterStrategy& strategy)
	{
		return strategy.newObj(ooTypeN(ooUtf8StringHolder), nearR);
	}
    void *operator new(size_t, ooClusterStrategy& strategy)
	{
		return strategy.newObj(ooTypeN(ooUtf8StringHolder));
	}
    void *operator new(size_t, const ooId& nearId);
    void *operator new(size_t, const objy::placement::Conditions& conditions);
    void *operator new(size_t, const ooObj *nearObj);
    void *operator new(size_t, const ooHandle(ooObj) &nearH, const char *typeName);
#ifdef OO_PLACEMENT_DELETE
    void operator delete(void* object) {
	  ooObj::operator delete(object);
	}
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
    void operator delete(void* object, const objy::placement::Conditions&) {
	  ooObj::operator delete(object);
	}
    void operator delete(void* object, const ooObj*) {
	  ooObj::operator delete(object);
	}
    void operator delete(void* object, const ooHandle(ooObj)&, const char*) {
	  ooObj::operator delete(object);
	}
#endif
#ifdef OO_ODMG
    void *operator new(size_t  size, d_Database *odmg_db);
    void *operator new(size_t  size, d_Database *odmg_db, const char *);
#ifdef OO_PLACEMENT_DELETE
    void operator delete(void* object, d_Database*) {
	  ooObj::operator delete(object);
	}
    void operator delete(void* object, d_Database*  odmg_db, const char*) {
	  ooObj::operator delete(object);
	}
#endif
#endif
    static const ooTypeNumber opiTypeN;
    static void ooAssocRegister();
    ooRef(ooUtf8StringHolder)& ooThis(ooRef(ooUtf8StringHolder)& objId, ooMode aMode = oocNoOpen) const;
    ooUtf8StringHolder(ooInternalObj iobj);
    ooUtf8StringHolder() {}
#endif /* !defined(OO_DDL_TRANSLATION) */
}; 

class ooUtf16StringHolder : public ooObj { 


public: ooUtf16String mString; 
#ifndef OO_DDL_TRANSLATION
    virtual ooTypeNumber ooGetTypeN() const;
    virtual char* ooGetTypeName() const;
    ooBoolean ooIsKindOf(ooTypeNumber oo_typeN) const;
    ooHandle(ooUtf16StringHolder)& ooThis(ooHandle(ooUtf16StringHolder)& objH,
			 ooMode aMode = oocNoOpen) const
      {
	return *ooReinterpretCast(ooHandle(ooUtf16StringHolder) *, &(this->ooObj::ooThis(objH, aMode)));
      }
    ooHandle(ooUtf16StringHolder) ooThis(ooMode aMode = oocNoOpen) const;
    void *operator new(size_t);
    void *operator new(size_t, const ooHandle(ooObj) &nearH);
    void *operator new(size_t, const ooHandle(ooObj) &nearH, ooClusterStrategy& strategy)
	{
		return strategy.newObj(ooTypeN(ooUtf16StringHolder), nearH);
	}
    void *operator new(size_t, const ooId& nearR, ooClusterStrategy& strategy)
	{
		return strategy.newObj(ooTypeN(ooUtf16StringHolder), nearR);
	}
    void *operator new(size_t, ooClusterStrategy& strategy)
	{
		return strategy.newObj(ooTypeN(ooUtf16StringHolder));
	}
    void *operator new(size_t, const ooId& nearId);
    void *operator new(size_t, const objy::placement::Conditions& conditions);
    void *operator new(size_t, const ooObj *nearObj);
    void *operator new(size_t, const ooHandle(ooObj) &nearH, const char *typeName);
#ifdef OO_PLACEMENT_DELETE
    void operator delete(void* object) {
	  ooObj::operator delete(object);
	}
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
    void operator delete(void* object, const objy::placement::Conditions&) {
	  ooObj::operator delete(object);
	}
    void operator delete(void* object, const ooObj*) {
	  ooObj::operator delete(object);
	}
    void operator delete(void* object, const ooHandle(ooObj)&, const char*) {
	  ooObj::operator delete(object);
	}
#endif
#ifdef OO_ODMG
    void *operator new(size_t  size, d_Database *odmg_db);
    void *operator new(size_t  size, d_Database *odmg_db, const char *);
#ifdef OO_PLACEMENT_DELETE
    void operator delete(void* object, d_Database*) {
	  ooObj::operator delete(object);
	}
    void operator delete(void* object, d_Database*  odmg_db, const char*) {
	  ooObj::operator delete(object);
	}
#endif
#endif
    static const ooTypeNumber opiTypeN;
    static void ooAssocRegister();
    ooRef(ooUtf16StringHolder)& ooThis(ooRef(ooUtf16StringHolder)& objId, ooMode aMode = oocNoOpen) const;
    ooUtf16StringHolder(ooInternalObj iobj);
    ooUtf16StringHolder() {}
#endif /* !defined(OO_DDL_TRANSLATION) */
}; 

class ooUtf32StringHolder : public ooObj { 


public: ooUtf32String mString; 
#ifndef OO_DDL_TRANSLATION
    virtual ooTypeNumber ooGetTypeN() const;
    virtual char* ooGetTypeName() const;
    ooBoolean ooIsKindOf(ooTypeNumber oo_typeN) const;
    ooHandle(ooUtf32StringHolder)& ooThis(ooHandle(ooUtf32StringHolder)& objH,
			 ooMode aMode = oocNoOpen) const
      {
	return *ooReinterpretCast(ooHandle(ooUtf32StringHolder) *, &(this->ooObj::ooThis(objH, aMode)));
      }
    ooHandle(ooUtf32StringHolder) ooThis(ooMode aMode = oocNoOpen) const;
    void *operator new(size_t);
    void *operator new(size_t, const ooHandle(ooObj) &nearH);
    void *operator new(size_t, const ooHandle(ooObj) &nearH, ooClusterStrategy& strategy)
	{
		return strategy.newObj(ooTypeN(ooUtf32StringHolder), nearH);
	}
    void *operator new(size_t, const ooId& nearR, ooClusterStrategy& strategy)
	{
		return strategy.newObj(ooTypeN(ooUtf32StringHolder), nearR);
	}
    void *operator new(size_t, ooClusterStrategy& strategy)
	{
		return strategy.newObj(ooTypeN(ooUtf32StringHolder));
	}
    void *operator new(size_t, const ooId& nearId);
    void *operator new(size_t, const objy::placement::Conditions& conditions);
    void *operator new(size_t, const ooObj *nearObj);
    void *operator new(size_t, const ooHandle(ooObj) &nearH, const char *typeName);
#ifdef OO_PLACEMENT_DELETE
    void operator delete(void* object) {
	  ooObj::operator delete(object);
	}
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
    void operator delete(void* object, const objy::placement::Conditions&) {
	  ooObj::operator delete(object);
	}
    void operator delete(void* object, const ooObj*) {
	  ooObj::operator delete(object);
	}
    void operator delete(void* object, const ooHandle(ooObj)&, const char*) {
	  ooObj::operator delete(object);
	}
#endif
#ifdef OO_ODMG
    void *operator new(size_t  size, d_Database *odmg_db);
    void *operator new(size_t  size, d_Database *odmg_db, const char *);
#ifdef OO_PLACEMENT_DELETE
    void operator delete(void* object, d_Database*) {
	  ooObj::operator delete(object);
	}
    void operator delete(void* object, d_Database*  odmg_db, const char*) {
	  ooObj::operator delete(object);
	}
#endif
#endif
    static const ooTypeNumber opiTypeN;
    static void ooAssocRegister();
    ooRef(ooUtf32StringHolder)& ooThis(ooRef(ooUtf32StringHolder)& objId, ooMode aMode = oocNoOpen) const;
    ooUtf32StringHolder(ooInternalObj iobj);
    ooUtf32StringHolder() {}
#endif /* !defined(OO_DDL_TRANSLATION) */
}; 

#endif /* !defined(OO_PREDEFINED_H) */
