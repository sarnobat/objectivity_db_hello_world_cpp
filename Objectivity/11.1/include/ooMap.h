/**************************************************************************
  		  Copyright (c) 1992-2002 Objectivity, Inc.
 	  		  All Rights Reserved

 	THIS IS UNPUBLISHED PROPRIETARY SOURCE CODE OF OBJECTIVITY, INC.

 	The copyright notice above does not evidence any
 	actual or intended publication of such source code.

*****************************************************************************/

#ifndef OO_MAP_H_TMP
#define OO_MAP_H_TMP

#ifdef OO_DDL_TRANSLATION
#pragma ooddlout "ooMap.ddl"
class opiDummyDeclaration;
#endif

#ifndef OO_H
#include <oo.h>
#endif

#ifndef OO_MAP_REF_H_TMP
#include "ooMap_ref.h"
#endif

extern ooHandle(ooMapElem) &oocDefaultMapElemHandle; 


class ooMapElem : public ooObj { 

public: inline const char *name() const { return _key; }
inline ooRef(ooObj) oid() const { return ((ooRef(ooObj)) (_value)); }
ooStatus set_oid(const ooId &); 


void print(); 
void print(FILE *); 
void dump(); 
void dump(FILE *); 


friend class ooMap; 
friend class ooMapItr; 
friend class ooItrMapState; 

private: ooMapElem(const char *); 
virtual ~ooMapElem(); 
inline void operator=(const ooMapElem &) { }

ooVString _key; 
ooId _value; 
ooShortRef(ooMap) _map; 
ooRef(ooMapElem) _next; 
public: 
#ifndef OO_DDL_TRANSLATION
    virtual ooTypeNumber ooGetTypeN() const;
    virtual char* ooGetTypeName() const;
    ooBoolean ooIsKindOf(ooTypeNumber oo_typeN) const;
    ooHandle(ooMapElem)& ooThis(ooHandle(ooMapElem)& objH,
			 ooMode aMode = oocNoOpen) const
      {
	return *ooReinterpretCast(ooHandle(ooMapElem) *, &(this->ooObj::ooThis(objH, aMode)));
      }
    ooHandle(ooMapElem) ooThis(ooMode aMode = oocNoOpen) const;
    void *operator new(size_t);
    void *operator new(size_t, const ooHandle(ooObj) &nearH);
    void *operator new(size_t, const ooHandle(ooObj) &nearH, ooClusterStrategy& strategy)
	{
		return strategy.newObj(ooTypeN(ooMapElem), nearH);
	}
    void *operator new(size_t, const ooId& nearR, ooClusterStrategy& strategy)
	{
		return strategy.newObj(ooTypeN(ooMapElem), nearR);
	}
    void *operator new(size_t, ooClusterStrategy& strategy)
	{
		return strategy.newObj(ooTypeN(ooMapElem));
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
    ooRef(ooMapElem)& ooThis(ooRef(ooMapElem)& objId, ooMode aMode = oocNoOpen) const;
    ooMapElem(ooInternalObj iobj);
#endif /* !defined(OO_DDL_TRANSLATION) */
}; 




struct ooMapBin { 
ooMapBin(); 

ooRef(ooMapElem) _head; 
}; 
class ooMap : public ooObj { 
void deinitialize(); 

public: ooMap(uint32 = (11), uint32 = (5), uint32 = (100)); 


virtual ~ooMap(); 

ooBoolean isMember(const char *); 
ooRef(ooObj) lookup(const char *); 
ooStatus lookup(const char *, ooId &); 
ooStatus lookup(const char *, ooHandle(ooMapElem) &); 
inline ooStatus lookup(const char *name, ooRef(ooMapElem) &elemId) 

{ ooHandle(ooMapElem) elemH; ooStatus status; status = lookup (name, elemH); elemId = elemH; return status; }
ooStatus lookup(const char *, ooHandle(ooObj) &, ooMode = oocRead); 

inline ooStatus lookup(const char *name, ooRef(ooObj) &
objId, ooMode 
openMode = oocRead) 

{ ooHandle(ooObj) objH; ooStatus status; status = lookup (name, objH, openMode); objId = objH; return status; }

ooStatus replace(const char *, const ooHandle(ooObj) &, ooHandle(ooMapElem) & = oocDefaultMapElemHandle); 

inline ooStatus replace(const char *name, const ooHandle(ooObj) &id, ooRef(ooMapElem) &
elemId) 

{ ooHandle(ooMapElem) elemH; ooStatus status; status = replace (name, id, elemH); elemId = elemH; return status; }

ooStatus add(const char *, const ooHandle(ooObj) &, ooHandle(ooMapElem) & = oocDefaultMapElemHandle); 

inline ooStatus add(const char *name, const ooHandle(ooObj) &id, ooRef(ooMapElem) &
elemId) 

{ ooHandle(ooMapElem) elemH; ooStatus status; status = add (name, id, elemH); elemId = elemH; return status; }

ooStatus forceAdd(const char *, const ooHandle(ooObj) &, ooHandle(ooMapElem) & = oocDefaultMapElemHandle); 

inline ooStatus forceAdd(const char *name, const ooHandle(ooObj) &id, ooRef(ooMapElem) &
elemId) 

{ ooHandle(ooMapElem) elemH; ooStatus status; status = forceAdd (name, id, elemH); elemId = elemH; return status; }

ooStatus remove(const char *); 


ooBoolean isMember(const wchar_t *); 
ooRef(ooObj) lookup(const wchar_t *); 
ooStatus lookup(const wchar_t *, ooId &); 
ooStatus lookup(const wchar_t *, ooHandle(ooMapElem) &); 
inline ooStatus lookup(const wchar_t *name, ooRef(ooMapElem) &elemId) 

{ ooHandle(ooMapElem) elemH; ooStatus status; status = lookup (name, elemH); elemId = elemH; return status; }
ooStatus lookup(const wchar_t *, ooHandle(ooObj) &, ooMode = oocRead); 
inline ooStatus lookup(const wchar_t *name, ooRef(ooObj) &objId, ooMode openMode = oocRead) 

{ ooHandle(ooObj) objH; ooStatus status; status = lookup (name, objH, openMode); objId = objH; return status; }

ooStatus replace(const wchar_t *, const ooHandle(ooObj) &, ooHandle(ooMapElem) & = oocDefaultMapElemHandle); 
inline ooStatus replace(const wchar_t *name, const ooHandle(ooObj) &id, ooRef(ooMapElem) &elemId) 

{ ooHandle(ooMapElem) elemH; ooStatus status; status = replace (name, id, elemH); elemId = elemH; return status; }

ooStatus add(const wchar_t *, const ooHandle(ooObj) &, ooHandle(ooMapElem) & = oocDefaultMapElemHandle); 
inline ooStatus add(const wchar_t *name, const ooHandle(ooObj) &id, ooRef(ooMapElem) &elemId) 

{ ooHandle(ooMapElem) elemH; ooStatus status; status = add (name, id, elemH); elemId = elemH; return status; }

ooStatus forceAdd(const wchar_t *, const ooHandle(ooObj) &, ooHandle(ooMapElem) & = oocDefaultMapElemHandle); 
inline ooStatus forceAdd(const wchar_t *name, const ooHandle(ooObj) &id, ooRef(ooMapElem) &elemId) 

{ ooHandle(ooMapElem) elemH; ooStatus status; status = forceAdd (name, id, elemH); elemId = elemH; return status; }

ooStatus remove(const wchar_t *); 


ooStatus remove(const ooHandle(ooMapElem) &); 

ooStatus rehash(uint32 = (11)); 
ooStatus clearParam(); 

inline uint32 nElement() const { return _nElement; }
inline uint32 nBin() const { return _nBin; }
inline uint32 maxAvgDensity() const { return _maxAvgDensity; }
inline uint32 percentGrow() const { return _percentGrow; }
void printStat() const; 
void printStat(FILE *) const; 

static ooNameHashFuncPtr nameHashFunction(); 
static void set_nameHashFunction(ooNameHashFuncPtr); 

inline ooBoolean refEnable() const { return _refEnable; }
ooStatus set_refEnable(ooBoolean = (oocTrue)); 


void print(); 
void print(FILE *); 
ooStatus verify_internal(); 
ooStatus verify_internal(FILE *); 
private: static ooNameHashFuncPtr _hashFunc; 

friend class ooMapElem; 
friend class ooMapItr; 
friend class ooItrMapState; 

inline ooMap(const ooMap &map) : ooObj (map) { }
inline void operator=(const ooMap &) { }

ooStatus findElem(uint32, const char *, ooHandle(ooMapElem) &, ocmSession *); 

ooStatus findElem(uint32, const char *, ooHandle(ooMapElem) &, ooHandle(ooMapElem) &); 


ooStatus addElem(const char *, const ooHandle(ooObj) &, uint32, ooHandle(ooMapElem) &); 


ooStatus chainElem(ooHandle(ooMapElem) &, ooRef(ooMapElem) &); 

inline uint32 hash(const char *name, uint32 modulus) 


{ return _hashFunc (name, modulus); }

inline uint32 hash(const ooVString &s, uint32 modulus) 



{ char * p = s . head (); return (p) ? hash (p, modulus) : 0; }
ooStatus rehash(ooBoolean, uint32); 

uint32 _nBin; 
uint32 _nElement; 
uint32 _maxAvgDensity; 
uint32 _nAdd; 
uint32 _nDelete; 
uint32 _nLookup; 
uint32 _nCmp; 
uint32 _nRehash; 
uint32 _percentGrow; 
ooVArray(ooMapBin) _bin; 
ooBoolean _refEnable; 
public: 
#ifndef OO_DDL_TRANSLATION
    virtual ooTypeNumber ooGetTypeN() const;
    virtual char* ooGetTypeName() const;
    ooBoolean ooIsKindOf(ooTypeNumber oo_typeN) const;
    ooHandle(ooMap)& ooThis(ooHandle(ooMap)& objH,
			 ooMode aMode = oocNoOpen) const
      {
	return *ooReinterpretCast(ooHandle(ooMap) *, &(this->ooObj::ooThis(objH, aMode)));
      }
    ooHandle(ooMap) ooThis(ooMode aMode = oocNoOpen) const;
    void *operator new(size_t);
    void *operator new(size_t, const ooHandle(ooObj) &nearH);
    void *operator new(size_t, const ooHandle(ooObj) &nearH, ooClusterStrategy& strategy)
	{
		return strategy.newObj(ooTypeN(ooMap), nearH);
	}
    void *operator new(size_t, const ooId& nearR, ooClusterStrategy& strategy)
	{
		return strategy.newObj(ooTypeN(ooMap), nearR);
	}
    void *operator new(size_t, ooClusterStrategy& strategy)
	{
		return strategy.newObj(ooTypeN(ooMap));
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
    ooRef(ooMap)& ooThis(ooRef(ooMap)& objId, ooMode aMode = oocNoOpen) const;
    ooMap(ooInternalObj iobj);
#endif /* !defined(OO_DDL_TRANSLATION) */
}; 



class ooMapItr : public ooItr(ooMapElem) { 

public: ooMapItr(); 
~ooMapItr(); 

ooMapItr(ooHandle(ooMap) &); 
ooMapItr(ooRef(ooMap) &); 
ooMapItr &operator=(ooHandle(ooMap) &); 
inline ooMapItr &operator=(ooRef(ooMap) &mapId) 
{ ooHandle(ooMap) mapH (mapId); return this -> operator = (mapH); }
ooStatus end(); 


private: ooStatus init(ooHandle(ooMap) &); 

ooMapItr(const ooMapItr &); 
ooMapItr &operator=(const ooMapItr &); 
}; 

#endif /* !defined(OO_MAP_H_TMP) */
