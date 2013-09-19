/**************************************************************************
  		  Copyright (c) 1992-2002 Objectivity, Inc.
 	  		  All Rights Reserved

 	THIS IS UNPUBLISHED PROPRIETARY SOURCE CODE OF OBJECTIVITY, INC.

 	The copyright notice above does not evidence any
 	actual or intended publication of such source code.

*****************************************************************************/

#ifndef OO_INDEX_H_TMP
#define OO_INDEX_H_TMP

#ifdef OO_DDL_TRANSLATION
#pragma ooddlout "ooIndex.ddl"
class opiDummyDeclaration;
#endif

#ifndef OO_H
#include <oo.h>
#endif

#ifndef OO_INDEX_REF_H_TMP
#include "ooIndex_ref.h"
#endif

class ooIndexDescBase; 
class ooIndexBase : public ooSysIndex { 

public: inline virtual ~ooIndexBase() { }

ooStatus getIndexDesc(ooHandle(ooIndexDescBase) &) const; 
ooStatus getIndexDesc(ooRef(ooIndexDescBase) &) const; 
ooBoolean sameDomain(const ooHandle(ooObj) &) const; 
ooTypeNumber objectTypeN() const; 
inline uint8 get_domain() { return IndexDomain; }
inline uint32 version_of_schema() const { return schema_version; }


protected: ooIndexBase(); 


public: uint32 rootPage; 
uint32 rootPage2; 
uint8 IndexDomain; 
uint16 IndexOC; 
uint32 schema_version; 
#ifdef OO_DDL_TRANSLATION
    ooRef(ooIndexDescBase) description <-> indexes[] : lock(propagate);
#else /* !defined(OO_DDL_TRANSLATION) */
    /* Methods for bidirectional association link: description */
    ooHandle(ooIndexDescBase) description(ooMode mode = oocNoOpen) const;
    ooHandle(ooIndexDescBase)& description(ooHandle(ooIndexDescBase)& objH,
		       ooMode mode = oocNoOpen) const;
    ooStatus set_description(const ooHandle(ooIndexDescBase)& objH);
    ooStatus del_description()
      {
	return opiDelAssoc_1(this->ooDysoc(), ooAssocN(ooIndexBase,description));
      }
    ooBoolean exist_description(const ooHandle(ooIndexDescBase)& objH) const;
    ooBoolean exist_description() const
      {
        return this->exist_description(*ooReinterpretCast(ooHandle(ooIndexDescBase) *,
						 &oocNullHandle));
      }
    static ooAssocNumber description_ooAssocN;
    ooRef(ooIndexDescBase)& description(ooRef(ooIndexDescBase)& objId, ooMode mode = oocNoOpen) const;
#endif /* !defined(OO_DDL_TRANSLATION) */
#ifndef OO_DDL_TRANSLATION
    virtual ooTypeNumber ooGetTypeN() const;
    virtual char* ooGetTypeName() const;
    ooBoolean ooIsKindOf(ooTypeNumber oo_typeN) const;
    ooHandle(ooIndexBase)& ooThis(ooHandle(ooIndexBase)& objH,
			 ooMode aMode = oocNoOpen) const
      {
	return *ooReinterpretCast(ooHandle(ooIndexBase) *, &(this->ooObj::ooThis(objH, aMode)));
      }
    ooHandle(ooIndexBase) ooThis(ooMode aMode = oocNoOpen) const;
    void *operator new(size_t);
    void *operator new(size_t, const ooHandle(ooObj) &nearH);
    void *operator new(size_t, const ooHandle(ooObj) &nearH, ooClusterStrategy& strategy)
	{
		return strategy.newObj(ooTypeN(ooIndexBase), nearH);
	}
    void *operator new(size_t, const ooId& nearR, ooClusterStrategy& strategy)
	{
		return strategy.newObj(ooTypeN(ooIndexBase), nearR);
	}
    void *operator new(size_t, ooClusterStrategy& strategy)
	{
		return strategy.newObj(ooTypeN(ooIndexBase));
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
    ooRef(ooIndexBase)& ooThis(ooRef(ooIndexBase)& objId, ooMode aMode = oocNoOpen) const;
    ooIndexBase(ooInternalObj iobj);
#endif /* !defined(OO_DDL_TRANSLATION) */


}; 




class ooKeyDesc; 
class ooKeyedIndex : public ooIndexBase { 

public: inline ooKeyedIndex() { }
#ifndef OO_DDL_TRANSLATION
    virtual ooTypeNumber ooGetTypeN() const;
    virtual char* ooGetTypeName() const;
    ooBoolean ooIsKindOf(ooTypeNumber oo_typeN) const;
    ooHandle(ooKeyedIndex)& ooThis(ooHandle(ooKeyedIndex)& objH,
			 ooMode aMode = oocNoOpen) const
      {
	return *ooReinterpretCast(ooHandle(ooKeyedIndex) *, &(this->ooObj::ooThis(objH, aMode)));
      }
    ooHandle(ooKeyedIndex) ooThis(ooMode aMode = oocNoOpen) const;
    void *operator new(size_t);
    void *operator new(size_t, const ooHandle(ooObj) &nearH);
    void *operator new(size_t, const ooHandle(ooObj) &nearH, ooClusterStrategy& strategy)
	{
		return strategy.newObj(ooTypeN(ooKeyedIndex), nearH);
	}
    void *operator new(size_t, const ooId& nearR, ooClusterStrategy& strategy)
	{
		return strategy.newObj(ooTypeN(ooKeyedIndex), nearR);
	}
    void *operator new(size_t, ooClusterStrategy& strategy)
	{
		return strategy.newObj(ooTypeN(ooKeyedIndex));
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
    ooRef(ooKeyedIndex)& ooThis(ooRef(ooKeyedIndex)& objId, ooMode aMode = oocNoOpen) const;
    ooKeyedIndex(ooInternalObj iobj);
#endif /* !defined(OO_DDL_TRANSLATION) */
}; 
class ooKeyField : public ooObj { 

public: ooKeyField(const ooKeyField &); 
ooKeyField(ooTypeNumber, const char *, ooBoolean = (oocFalse), int = (24)); 
inline virtual ~ooKeyField() { }

virtual char *getName() const; 
virtual ooBoolean isNamed(const char *) const; 
ooBoolean isSameAs(ooKeyField *) const; 
inline ooTypeNumber getTypeN() const { return typeN; }
inline ooMemberID getID() const { return memberID; }
inline ooBaseType getType() const { return baseType; }
virtual ooBoolean isConsistent() const; 
inline uint32 getLength() const { return length; }

inline void nullify() 
{ path . resize (0); memberID = 0; baseType = oocTypeCHAR; dummy1 = 0; dummy2 = 0; }


private: const char *getNameInternal(char *, int, ocmSession *) const; 


protected: ooVArray(ooMemberID) path; 

uint32 typeN; 
ooMemberID memberID; 
ooBaseType baseType; 
uint32 length; 
uint32 dummy1; 


uint32 dummy2; 
public: 
#ifndef OO_DDL_TRANSLATION
    virtual ooTypeNumber ooGetTypeN() const;
    virtual char* ooGetTypeName() const;
    ooBoolean ooIsKindOf(ooTypeNumber oo_typeN) const;
    ooHandle(ooKeyField)& ooThis(ooHandle(ooKeyField)& objH,
			 ooMode aMode = oocNoOpen) const
      {
	return *ooReinterpretCast(ooHandle(ooKeyField) *, &(this->ooObj::ooThis(objH, aMode)));
      }
    ooHandle(ooKeyField) ooThis(ooMode aMode = oocNoOpen) const;
    void *operator new(size_t);
    void *operator new(size_t, const ooHandle(ooObj) &nearH);
    void *operator new(size_t, const ooHandle(ooObj) &nearH, ooClusterStrategy& strategy)
	{
		return strategy.newObj(ooTypeN(ooKeyField), nearH);
	}
    void *operator new(size_t, const ooId& nearR, ooClusterStrategy& strategy)
	{
		return strategy.newObj(ooTypeN(ooKeyField), nearR);
	}
    void *operator new(size_t, ooClusterStrategy& strategy)
	{
		return strategy.newObj(ooTypeN(ooKeyField));
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
    ooRef(ooKeyField)& ooThis(ooRef(ooKeyField)& objId, ooMode aMode = oocNoOpen) const;
    ooKeyField(ooInternalObj iobj);
#endif /* !defined(OO_DDL_TRANSLATION) */
}; 



struct string_holder : public ooObj { 
ooVArray(ooChar) string; 
#ifndef OO_DDL_TRANSLATION
    virtual ooTypeNumber ooGetTypeN() const;
    virtual char* ooGetTypeName() const;
    ooBoolean ooIsKindOf(ooTypeNumber oo_typeN) const;
    ooHandle(string_holder)& ooThis(ooHandle(string_holder)& objH,
			 ooMode aMode = oocNoOpen) const
      {
	return *ooReinterpretCast(ooHandle(string_holder) *, &(this->ooObj::ooThis(objH, aMode)));
      }
    ooHandle(string_holder) ooThis(ooMode aMode = oocNoOpen) const;
    void *operator new(size_t);
    void *operator new(size_t, const ooHandle(ooObj) &nearH);
    void *operator new(size_t, const ooHandle(ooObj) &nearH, ooClusterStrategy& strategy)
	{
		return strategy.newObj(ooTypeN(string_holder), nearH);
	}
    void *operator new(size_t, const ooId& nearR, ooClusterStrategy& strategy)
	{
		return strategy.newObj(ooTypeN(string_holder), nearR);
	}
    void *operator new(size_t, ooClusterStrategy& strategy)
	{
		return strategy.newObj(ooTypeN(string_holder));
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
    ooRef(string_holder)& ooThis(ooRef(string_holder)& objId, ooMode aMode = oocNoOpen) const;
    string_holder(ooInternalObj iobj);
    string_holder() {}
#endif /* !defined(OO_DDL_TRANSLATION) */
}; 
class ooIndexDescBase : public ooObj { 

public: inline ooIndexDescBase(ooTypeNumber typeNumber) : typeN (typeNumber) { }
inline virtual ~ooIndexDescBase() { }

inline ooTypeNumber getTypeN() const { return typeN; }
const char *getTypeName() const; 

virtual ooStatus createIndex(const ooHandle(ooObj) &) = 0; 
virtual ooStatus dropIndex(const ooHandle(ooObj) &) = 0; 
virtual ooBoolean isConsistent() const = 0; 
ooStatus removeIndexes(); 


protected: ooStatus checkForDuplicateIndex(const ooHandle(ooObj) &); 
ooTypeNumber typeN; 
#ifdef OO_DDL_TRANSLATION
    ooRef(ooIndexBase) indexes[] <-> description : lock(propagate), delete(propagate);
#else /* !defined(OO_DDL_TRANSLATION) */
    /* Methods for bidirectional association link: indexes[] */
    ooStatus indexes(ooItr(ooIndexBase)& itr, ooMode mode = oocNoOpen) const;
    ooStatus indexes(ooItr(ooIndexBase)& itr, const char* predicate) const
      {
	return opiInitAssocVPredItr(*ooReinterpretCast(ooHandle(ooObj) *,
						       &itr),
				    this->ooDysoc(),
				    ooAssocN(ooIndexDescBase,indexes),
				    predicate,
				    oocPublic,
				    oocNoOpen);
      }
    ooStatus indexes(ooItr(ooIndexBase)& itr,
		 ooMode mode,
		 const ooAccessMode access,
		 const char* predicate) const
      {
	return opiInitAssocVPredItr(*ooReinterpretCast(ooHandle(ooObj) *,
						       &itr),
				    this->ooDysoc(),
				    ooAssocN(ooIndexDescBase,indexes),
				    predicate,
				    access,
				    mode);
      }
    ooStatus indexes(ooItr(ooIndexBase)& itr, 
               ooMode mode,
               const objy::query::ObjectQualifier& objQualifier) const
      {
	return opiInitAssocVQualItr(*ooReinterpretCast(ooHandle(ooObj) *,
						       &itr),
				    this->ooDysoc(),
				    ooAssocN(ooIndexDescBase,indexes),
				    objQualifier,
				    mode);
      }
    ooStatus add_indexes(const ooHandle(ooIndexBase)& newObjH);
    ooStatus sub_indexes(const ooHandle(ooIndexBase)& objH);
    ooStatus del_indexes()
      {
	return opiDelAssoc(this->ooDysoc(), ooAssocN(ooIndexDescBase,indexes));
      }
    ooBoolean exist_indexes(const ooHandle(ooIndexBase)& objH) const;
    ooBoolean exist_indexes() const
      {
        return this->exist_indexes(*ooReinterpretCast(ooHandle(ooIndexBase) *,
						 &oocNullHandle));
      }
    static ooAssocNumber indexes_ooAssocN;
#endif /* !defined(OO_DDL_TRANSLATION) */
public: 
#ifndef OO_DDL_TRANSLATION
    virtual ooTypeNumber ooGetTypeN() const;
    virtual char* ooGetTypeName() const;
    ooBoolean ooIsKindOf(ooTypeNumber oo_typeN) const;
    ooHandle(ooIndexDescBase)& ooThis(ooHandle(ooIndexDescBase)& objH,
			 ooMode aMode = oocNoOpen) const
      {
	return *ooReinterpretCast(ooHandle(ooIndexDescBase) *, &(this->ooObj::ooThis(objH, aMode)));
      }
    ooHandle(ooIndexDescBase) ooThis(ooMode aMode = oocNoOpen) const;
    void *operator new(size_t);
    void *operator new(size_t, const ooHandle(ooObj) &nearH);
    void *operator new(size_t, const ooHandle(ooObj) &nearH, ooClusterStrategy& strategy)
	{
		return strategy.newObj(ooTypeN(ooIndexDescBase), nearH);
	}
    void *operator new(size_t, const ooId& nearR, ooClusterStrategy& strategy)
	{
		return strategy.newObj(ooTypeN(ooIndexDescBase), nearR);
	}
    void *operator new(size_t, ooClusterStrategy& strategy)
	{
		return strategy.newObj(ooTypeN(ooIndexDescBase));
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
    ooRef(ooIndexDescBase)& ooThis(ooRef(ooIndexDescBase)& objId, ooMode aMode = oocNoOpen) const;
    ooIndexDescBase(ooInternalObj iobj);
#endif /* !defined(OO_DDL_TRANSLATION) */


}; 
class ooKeyDesc : public ooIndexDescBase { 

public: ooKeyDesc(ooTypeNumber, ooBoolean = (oocFalse)); 
virtual ~ooKeyDesc(); 

ooStatus addField(ooHandle(ooKeyField) &); 
inline uint32 nField() const { return keyField . size (); }
inline const ooRef(ooKeyField) &field(uint32 n) { return keyField [ n ]; }
virtual ooStatus createIndex(const ooHandle(ooObj) &); 
virtual ooStatus dropIndex(const ooHandle(ooObj) &); 
inline ooBoolean isUnique() const { return unique; }
virtual ooBoolean isConsistent() const; 


ooStatus getIndex(const ooHandle(ooObj) &, ooHandle(ooIndexBase) &) const; 



protected: ooBoolean unique; 
ooVArray(ooRef(ooKeyField)) keyField; 
inline ooStatus getIndex(const ooHandle(ooObj) &domainH, ooRef(ooIndexBase) &
indexId) const 

{ ooHandle(ooIndexBase) indexH; ooStatus status; status = getIndex (domainH, indexH); indexId = indexH; return status; }
public: 
#ifndef OO_DDL_TRANSLATION
    virtual ooTypeNumber ooGetTypeN() const;
    virtual char* ooGetTypeName() const;
    ooBoolean ooIsKindOf(ooTypeNumber oo_typeN) const;
    ooHandle(ooKeyDesc)& ooThis(ooHandle(ooKeyDesc)& objH,
			 ooMode aMode = oocNoOpen) const
      {
	return *ooReinterpretCast(ooHandle(ooKeyDesc) *, &(this->ooObj::ooThis(objH, aMode)));
      }
    ooHandle(ooKeyDesc) ooThis(ooMode aMode = oocNoOpen) const;
    void *operator new(size_t);
    void *operator new(size_t, const ooHandle(ooObj) &nearH);
    void *operator new(size_t, const ooHandle(ooObj) &nearH, ooClusterStrategy& strategy)
	{
		return strategy.newObj(ooTypeN(ooKeyDesc), nearH);
	}
    void *operator new(size_t, const ooId& nearR, ooClusterStrategy& strategy)
	{
		return strategy.newObj(ooTypeN(ooKeyDesc), nearR);
	}
    void *operator new(size_t, ooClusterStrategy& strategy)
	{
		return strategy.newObj(ooTypeN(ooKeyDesc));
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
    ooRef(ooKeyDesc)& ooThis(ooRef(ooKeyDesc)& objId, ooMode aMode = oocNoOpen) const;
    ooKeyDesc(ooInternalObj iobj);
#endif /* !defined(OO_DDL_TRANSLATION) */
}; 
class ooLookupFieldBase { 


public: virtual ~ooLookupFieldBase(); 
inline virtual ooRelatOp getRelatOp() const { return op; }

inline virtual ooMemberID getID() const { return keyField . getID (); }
inline virtual ooBaseType getType() const { return keyField . getType (); }
inline virtual uint32 getLength() const { return keyField . getLength (); }
inline virtual const void *getValue() const { return valuePtr; }

inline virtual void nullify() { keyField . nullify (); valuePtr = 0; }
virtual ooBoolean isNamed(const char *) const; 


protected: ooLookupFieldBase(const ooKeyField &, const void *, ooRelatOp = oocEQ); 

ooLookupFieldBase(ooTypeNumber, const char *, const void *, ooRelatOp = oocEQ); 


ooKeyField keyField; 
const void *valuePtr; 
ooRelatOp op; 
}; 

class ooEqualLookupField : public ooLookupFieldBase { 

public: inline ooEqualLookupField(const ooKeyField &field, const void *aValuePtr) 
: ooLookupFieldBase (field, aValuePtr, oocEQ) { }
inline ooEqualLookupField(ooTypeNumber typeN, const char *name, const void *
aValuePtr) 
: ooLookupFieldBase (typeN, name, aValuePtr, oocEQ) { }
virtual ~ooEqualLookupField(); 
}; 

class ooGreaterThanLookupField : public ooLookupFieldBase { 

public: inline ooGreaterThanLookupField(const ooKeyField &field, const void *aValuePtr) 
: ooLookupFieldBase (field, aValuePtr, oocGT) { }
inline ooGreaterThanLookupField(ooTypeNumber typeN, const char *name, const void *
aValuePtr) 
: ooLookupFieldBase (typeN, name, aValuePtr, oocGT) { }
virtual ~ooGreaterThanLookupField(); 
}; 

class ooLessThanLookupField : public ooLookupFieldBase { 

public: inline ooLessThanLookupField(const ooKeyField &field, const void *aValuePtr) 
: ooLookupFieldBase (field, aValuePtr, oocLT) { }
inline ooLessThanLookupField(ooTypeNumber typeN, const char *name, const void *
aValuePtr) 
: ooLookupFieldBase (typeN, name, aValuePtr, oocLT) { }
virtual ~ooLessThanLookupField(); 
}; 

class ooGreaterThanEqualLookupField : public ooLookupFieldBase { 

public: inline ooGreaterThanEqualLookupField(const ooKeyField &field, const void *
aValuePtr) 
: ooLookupFieldBase (field, aValuePtr, oocGE) { }
inline ooGreaterThanEqualLookupField(ooTypeNumber typeN, const char *name, const void *
aValuePtr) 
: ooLookupFieldBase (typeN, name, aValuePtr, oocGE) { }
virtual ~ooGreaterThanEqualLookupField(); 
}; 

class ooLessThanEqualLookupField : public ooLookupFieldBase { 

public: inline ooLessThanEqualLookupField(const ooKeyField &field, const void *
aValuePtr) 
: ooLookupFieldBase (field, aValuePtr, oocLE) { }
inline ooLessThanEqualLookupField(ooTypeNumber typeN, const char *name, const void *
aValuePtr) 
: ooLookupFieldBase (typeN, name, aValuePtr, oocLE) { }
virtual ~ooLessThanEqualLookupField(); 
}; 
class ooLookupKey { 


public: ooLookupKey(ooTypeNumber, uint32); 
~ooLookupKey(); 

ooStatus addField(const ooLookupFieldBase &); 
inline ooLookupFieldBase *operator[](uint32 fieldNumber) const 
{ return keyFieldPtr [ fieldNumber ]; }
inline uint32 nField() const { return numFields; }

ooBoolean anyIndex(const ooHandle(ooObj) &) const; 


protected: ooTypeNumber typeN; 
uint32 numFields; 
uint32 size; 
ooLookupFieldBase **keyFieldPtr; 
}; 

#endif /* !defined(OO_INDEX_H_TMP) */
