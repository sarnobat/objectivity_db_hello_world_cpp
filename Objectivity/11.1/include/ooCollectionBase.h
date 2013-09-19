/* C++ header file: Objectivity/DB DDL Version: 11.1 */

#ifndef OO_COLLECTION_BASE_H
#define OO_COLLECTION_BASE_H

#ifdef OO_DDL_TRANSLATION
#pragma ooddlout "ooCollectionBase.ddl"
class opiDummyDeclaration;
#endif

#ifndef OO_H
#include <oo.h>
#endif

#ifndef OO_COLLECTION_BASE_REF_H
#include "ooCollectionBase_ref.h"
#endif

class ooHashSetX; 
class ooHashMapX; 
class ooHashIteratorX; 
class ooHashMapXIterator; 
class ooHashMapXValueIterator; 
class ooHashBucketX; 
class ooHashInternalObjectsIterator; 
class ooBTree; 
class ooTreeList; 

class ooCompare : public ooObj { 


public: inline virtual ~ooCompare() { }
static int compareOoId(const ooHandle(ooObj) &, const ooHandle(ooObj) &); 
static int compareOoId(const ooId &, const ooId &); 
static inline ooBoolean lessOoId(const ooHandle(ooObj) &obj1, const ooHandle(ooObj) &obj2) 
{ return compareOoId (obj1, obj2) < 0; }
static inline ooBoolean lessOrEqualOoId(const ooHandle(ooObj) &obj1, const ooHandle(ooObj) &obj2) 
{ return compareOoId (obj1, obj2) <= 0; }
static inline ooBoolean greaterOoId(const ooHandle(ooObj) &obj1, const ooHandle(ooObj) &obj2) 
{ return compareOoId (obj1, obj2)> 0; }
static inline ooBoolean greaterOrEqualOoId(const ooHandle(ooObj) &obj1, const ooHandle(ooObj) &obj2) 
{ return compareOoId (obj1, obj2) >= 0; }
static inline ooBoolean equalOoId(const ooHandle(ooObj) &obj1, const ooHandle(ooObj) &obj2) 
{ return compareOoId (obj1, obj2) == 0; }

virtual int compare(const ooHandle(ooObj) &, const void *&) const; 
inline virtual int compare(const ooHandle(ooObj) &obj1, const ooHandle(ooObj) &obj2) const 


{ return compareOoId (obj1, obj2); }
static ooUInt32 hashOoId(const ooHandle(ooObj) &); 
inline virtual int hash(const void *&obj) const 


{ return hashOoId ((const ooHandle(ooObj) &) obj); }
inline virtual int hash(const ooHandle(ooObj) &obj) const 


{ return hashOoId (obj); }
inline ooBoolean less(const ooHandle(ooObj) &obj1, const void *obj2) const 
{ return this -> compare (obj1, obj2) < 0; }
inline ooBoolean lessOrEqual(const ooHandle(ooObj) &obj1, const void *obj2) const 
{ return this -> compare (obj1, obj2) <= 0; }
inline ooBoolean greater(const ooHandle(ooObj) &obj1, const void *obj2) const 
{ return this -> compare (obj1, obj2)> 0; }
inline ooBoolean greaterOrEqual(const ooHandle(ooObj) &obj1, const void *obj2) const 
{ return this -> compare (obj1, obj2) >= 0; }
inline ooBoolean equal(const ooHandle(ooObj) &obj1, const void *obj2) const 
{ return this -> compare (obj1, obj2) == 0; }
inline ooBoolean less(const ooHandle(ooObj) &obj1, const ooHandle(ooObj) &obj2) const 
{ return this -> compare (obj1, obj2) < 0; }
inline ooBoolean lessOrEqual(const ooHandle(ooObj) &obj1, const ooHandle(ooObj) &obj2) const 
{ return this -> compare (obj1, obj2) <= 0; }
inline ooBoolean greater(const ooHandle(ooObj) &obj1, const ooHandle(ooObj) &obj2) const 
{ return this -> compare (obj1, obj2)> 0; }
inline ooBoolean greaterOrEqual(const ooHandle(ooObj) &obj1, const ooHandle(ooObj) &obj2) const 
{ return this -> compare (obj1, obj2) >= 0; }
inline ooBoolean equal(const ooHandle(ooObj) &obj1, const ooHandle(ooObj) &obj2) const 
{ return this -> compare (obj1, obj2) == 0; }
ooBoolean equal(const ooHandle(ooCompare) &, const ooHandle(ooObj) &, const ooHandle(ooObj) &) const; 
inline virtual unsigned comparisonArraySize() const 


{ return 0; }
inline virtual void setComparisonArrayFromKey(const void *lookupKey, uint32 *compareArray) const 



{ if (comparisonArraySize ()> 0) throw ooSimpleException ("Must override ooCompare::setComparisonArrayFromKey when ooCompare::comparisonArraySize() is overriden"); }
inline virtual void setComparisonArrayFromObject(const ooHandle(ooObj) &objH, uint32 *compareArray) const 



{ if (comparisonArraySize ()> 0) throw ooSimpleException ("Must override ooCompare::setComparisonArrayFromObject when ooCompare::comparisonArraySize() is overriden"); }


static int compare(const ooHandle(ooObj) &, jobject &, jobject &, JNIEnv *); 
static int hash(jobject &, jobject &, JNIEnv *); 
static inline ooBoolean less(const ooHandle(ooObj) &obj1, jobject &obj2, jobject &tree, JNIEnv *env) 
{ return compare (obj1, obj2, tree, env) < 0; }
static inline ooBoolean lessOrEqual(const ooHandle(ooObj) &obj1, jobject &obj2, jobject &tree, JNIEnv *env) 
{ return compare (obj1, obj2, tree, env) <= 0; }
static inline ooBoolean greater(const ooHandle(ooObj) &obj1, jobject &obj2, jobject &tree, JNIEnv *env) 
{ return compare (obj1, obj2, tree, env)> 0; }
static inline ooBoolean greaterOrEqual(const ooHandle(ooObj) &obj1, jobject &obj2, jobject &tree, JNIEnv *env) 
{ return compare (obj1, obj2, tree, env) >= 0; }
static inline ooBoolean equal(const ooHandle(ooObj) &obj1, jobject &obj2, jobject &tree, JNIEnv *env) 
{ return compare (obj1, obj2, tree, env) == 0; }

static int compare(const ooHandle(ooObj) &, const ooHandle(ooObj) &, jobject &, JNIEnv *); 
static int hash(const ooHandle(ooObj) &, jobject &, JNIEnv *); 
static inline ooBoolean less(const ooHandle(ooObj) &obj1, const ooHandle(ooObj) &obj2, jobject &tree, JNIEnv *env) 
{ return compare (obj1, obj2, tree, env) < 0; }
static inline ooBoolean lessOrEqual(const ooHandle(ooObj) &obj1, const ooHandle(ooObj) &obj2, jobject &tree, JNIEnv *env) 
{ return compare (obj1, obj2, tree, env) <= 0; }
static inline ooBoolean greater(const ooHandle(ooObj) &obj1, const ooHandle(ooObj) &obj2, jobject &tree, JNIEnv *env) 
{ return compare (obj1, obj2, tree, env)> 0; }
static inline ooBoolean greaterOrEqual(const ooHandle(ooObj) &obj1, const ooHandle(ooObj) &obj2, jobject &tree, JNIEnv *env) 
{ return compare (obj1, obj2, tree, env) >= 0; }
static inline ooBoolean equal(const ooHandle(ooObj) &obj1, const ooHandle(ooObj) &obj2, jobject &tree, JNIEnv *env) 
{ return compare (obj1, obj2, tree, env) == 0; }


static int compare(const ooHandle(ooObj) &, smalltalk_callback); 
static int hash(const ooHandle(ooObj) &, smalltalk_callback); 
static inline ooBoolean less(const ooHandle(ooObj) &obj1, smalltalk_callback smalltalk) 
{ return compare (obj1, smalltalk) < 0; }
static inline ooBoolean lessOrEqual(const ooHandle(ooObj) &obj1, smalltalk_callback smalltalk) 
{ return compare (obj1, smalltalk) <= 0; }
static inline ooBoolean greater(const ooHandle(ooObj) &obj1, smalltalk_callback smalltalk) 
{ return compare (obj1, smalltalk)> 0; }
static inline ooBoolean greaterOrEqual(const ooHandle(ooObj) &obj1, smalltalk_callback smalltalk) 
{ return compare (obj1, smalltalk) >= 0; }
static inline ooBoolean equal(const ooHandle(ooObj) &obj1, smalltalk_callback smalltalk) 
{ return compare (obj1, smalltalk) == 0; }
#ifndef OO_DDL_TRANSLATION
    virtual ooTypeNumber ooGetTypeN() const;
    virtual char* ooGetTypeName() const;
    ooBoolean ooIsKindOf(ooTypeNumber oo_typeN) const;
    ooHandle(ooCompare)& ooThis(ooHandle(ooCompare)& objH,
			 ooMode aMode = oocNoOpen) const
      {
	return *ooReinterpretCast(ooHandle(ooCompare) *, &(this->ooObj::ooThis(objH, aMode)));
      }
    ooHandle(ooCompare) ooThis(ooMode aMode = oocNoOpen) const;
    void *operator new(size_t);
    void *operator new(size_t, const ooHandle(ooObj) &nearH);
    void *operator new(size_t, const ooHandle(ooObj) &nearH, ooClusterStrategy& strategy)
	{
		return strategy.newObj(ooTypeN(ooCompare), nearH);
	}
    void *operator new(size_t, const ooId& nearR, ooClusterStrategy& strategy)
	{
		return strategy.newObj(ooTypeN(ooCompare), nearR);
	}
    void *operator new(size_t, ooClusterStrategy& strategy)
	{
		return strategy.newObj(ooTypeN(ooCompare));
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
    ooRef(ooCompare)& ooThis(ooRef(ooCompare)& objId, ooMode aMode = oocNoOpen) const;
    ooCompare(ooInternalObj iobj);
    ooCompare() {}
#endif /* !defined(OO_DDL_TRANSLATION) */
}; 


class ooCollection : public ooObj { 


protected: virtual ooBoolean isRoot() const; 
virtual ooBoolean isMap() const; 

public: static ooStatus deleteIfEmptyUnnamedNonGC(ooHandle(ooContObj) &); 
ooBoolean equal(const ooHandle(ooObj) &, const ooHandle(ooObj) &) const; 
inline virtual ~ooCollection() { }

virtual ooBoolean add(const ooHandle(ooObj) &) = 0; 



virtual ooBoolean addAll(const ooHandle(ooCollection) &); 


virtual void clear() = 0; 
virtual const char *className() const; 

virtual const ooRef(ooCompare) comparator() const = 0; 


virtual ooBoolean containsAll(const ooHandle(ooCollection) &) const; 


virtual ooBoolean contains(const void *) const; 
virtual ooBoolean contains(const ooHandle(ooObj) &) const = 0; 


virtual ooRef(ooObj) get(const void *) const = 0; 



virtual ooCollectionIterator *iterator() const = 0; 



inline virtual ooCollectionIterator *keyIterator() const 
{ return this -> iterator (); }


virtual ooBoolean isEmpty() const = 0; 


inline ooBoolean notEmpty() const 
{ return ! this -> isEmpty (); }
virtual ooStatus refresh(ooMode) const = 0; 


virtual ooBoolean remove(const ooHandle(ooObj) &) = 0; 


virtual ooBoolean removeAll(ooHandle(ooCollection) &); 


virtual void removeAllDeleted(); 




virtual ooBoolean retainAll(ooHandle(ooCollection) &); 


virtual int size() const = 0; 




inline virtual ooCollectionIterator *valueIterator() const 
{ return this -> iterator (); }
#ifndef OO_DDL_TRANSLATION
    virtual ooTypeNumber ooGetTypeN() const;
    virtual char* ooGetTypeName() const;
    ooBoolean ooIsKindOf(ooTypeNumber oo_typeN) const;
    ooHandle(ooCollection)& ooThis(ooHandle(ooCollection)& objH,
			 ooMode aMode = oocNoOpen) const
      {
	return *ooReinterpretCast(ooHandle(ooCollection) *, &(this->ooObj::ooThis(objH, aMode)));
      }
    ooHandle(ooCollection) ooThis(ooMode aMode = oocNoOpen) const;
    void *operator new(size_t);
    void *operator new(size_t, const ooHandle(ooObj) &nearH);
    void *operator new(size_t, const ooHandle(ooObj) &nearH, ooClusterStrategy& strategy)
	{
		return strategy.newObj(ooTypeN(ooCollection), nearH);
	}
    void *operator new(size_t, const ooId& nearR, ooClusterStrategy& strategy)
	{
		return strategy.newObj(ooTypeN(ooCollection), nearR);
	}
    void *operator new(size_t, ooClusterStrategy& strategy)
	{
		return strategy.newObj(ooTypeN(ooCollection));
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
    ooRef(ooCollection)& ooThis(ooRef(ooCollection)& objId, ooMode aMode = oocNoOpen) const;
    ooCollection(ooInternalObj iobj);
    ooCollection() {}
#endif /* !defined(OO_DDL_TRANSLATION) */
}; 


class ooCompareShortRef : public ooCompare { 

public: inline virtual ~ooCompareShortRef() { }
static int compareOoId(const ooHandle(ooObj) &, const ooHandle(ooObj) &); 
static inline ooBoolean lessOoId(const ooHandle(ooObj) &obj1, const ooHandle(ooObj) &obj2) 
{ return compareOoId (obj1, obj2) < 0; }
static inline ooBoolean lessOrEqualOoId(const ooHandle(ooObj) &obj1, const ooHandle(ooObj) &obj2) 
{ return compareOoId (obj1, obj2) <= 0; }
static inline ooBoolean greaterOoId(const ooHandle(ooObj) &obj1, const ooHandle(ooObj) &obj2) 
{ return compareOoId (obj1, obj2)> 0; }
static inline ooBoolean greaterOrEqualOoId(const ooHandle(ooObj) &obj1, const ooHandle(ooObj) &obj2) 
{ return compareOoId (obj1, obj2) >= 0; }
static inline ooBoolean equalOoId(const ooHandle(ooObj) &obj1, const ooHandle(ooObj) &obj2) 
{ return compareOoId (obj1, obj2) == 0; }

inline virtual int compare(const ooHandle(ooObj) &obj1, const void *&obj2) const 
{ return compareOoId (obj1, (const ooHandle(ooObj) &) obj2); }
inline virtual int compare(const ooHandle(ooObj) &obj1, const ooHandle(ooObj) &obj2) const 
{ return compareOoId (obj1, obj2); }
static ooUInt32 hashOoId(const ooHandle(ooObj) &); 
static int hashShortId(const ooShortRef(ooObj) &); 
inline virtual int hash(const void *&obj) const 
{ return hashOoId ((const ooHandle(ooObj) &) obj); }
inline virtual int hash(const ooHandle(ooObj) &obj) const 
{ return hashOoId (obj); }
inline ooBoolean less(const ooHandle(ooObj) &obj1, const void *obj2) const 
{ return this -> compare (obj1, obj2) < 0; }
inline ooBoolean lessOrEqual(const ooHandle(ooObj) &obj1, const void *obj2) const 
{ return this -> compare (obj1, obj2) <= 0; }
inline ooBoolean greater(const ooHandle(ooObj) &obj1, const void *obj2) const 
{ return this -> compare (obj1, obj2)> 0; }
inline ooBoolean greaterOrEqual(const ooHandle(ooObj) &obj1, const void *obj2) const 
{ return this -> compare (obj1, obj2) >= 0; }
inline ooBoolean equal(const ooHandle(ooObj) &obj1, const void *obj2) const 
{ return this -> compare (obj1, obj2) == 0; }
inline ooBoolean less(const ooHandle(ooObj) &obj1, const ooHandle(ooObj) &obj2) const 
{ return this -> compare (obj1, obj2) < 0; }
inline ooBoolean lessOrEqual(const ooHandle(ooObj) &obj1, const ooHandle(ooObj) &obj2) const 
{ return this -> compare (obj1, obj2) <= 0; }
inline ooBoolean greater(const ooHandle(ooObj) &obj1, const ooHandle(ooObj) &obj2) const 
{ return this -> compare (obj1, obj2)> 0; }
inline ooBoolean greaterOrEqual(const ooHandle(ooObj) &obj1, const ooHandle(ooObj) &obj2) const 
{ return this -> compare (obj1, obj2) >= 0; }
inline ooBoolean equal(const ooHandle(ooObj) &obj1, const ooHandle(ooObj) &obj2) const 
{ return this -> compare (obj1, obj2) == 0; }
#ifndef OO_DDL_TRANSLATION
    virtual ooTypeNumber ooGetTypeN() const;
    virtual char* ooGetTypeName() const;
    ooBoolean ooIsKindOf(ooTypeNumber oo_typeN) const;
    ooHandle(ooCompareShortRef)& ooThis(ooHandle(ooCompareShortRef)& objH,
			 ooMode aMode = oocNoOpen) const
      {
	return *ooReinterpretCast(ooHandle(ooCompareShortRef) *, &(this->ooObj::ooThis(objH, aMode)));
      }
    ooHandle(ooCompareShortRef) ooThis(ooMode aMode = oocNoOpen) const;
    void *operator new(size_t);
    void *operator new(size_t, const ooHandle(ooObj) &nearH);
    void *operator new(size_t, const ooHandle(ooObj) &nearH, ooClusterStrategy& strategy)
	{
		return strategy.newObj(ooTypeN(ooCompareShortRef), nearH);
	}
    void *operator new(size_t, const ooId& nearR, ooClusterStrategy& strategy)
	{
		return strategy.newObj(ooTypeN(ooCompareShortRef), nearR);
	}
    void *operator new(size_t, ooClusterStrategy& strategy)
	{
		return strategy.newObj(ooTypeN(ooCompareShortRef));
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
    ooRef(ooCompareShortRef)& ooThis(ooRef(ooCompareShortRef)& objId, ooMode aMode = oocNoOpen) const;
    ooCompareShortRef(ooInternalObj iobj);
    ooCompareShortRef() {}
#endif /* !defined(OO_DDL_TRANSLATION) */
}; 


class ooCollectionIterator { 

friend class ooBTree; 
friend class ooCollection; 
friend class ooTreeList; 

protected: int _at; 
virtual ooRef(ooObj) &currentP(ooBoolean = (oocFalse)) = 0; 

ooId collectionOid; 
ooTypeNumber collectionTypeN; 
ooEventListener::ooCollectionIterationKind iterationKind; 


public: inline virtual ~ooCollectionIterator() { }


virtual ooHandle(ooCollection) collection() = 0; 


virtual ooRef(ooObj) current() = 0; 



inline virtual ooRef(ooObj) currentValue() 
{ return this -> current (); }


virtual int currentIndex() = 0; 



virtual ooBoolean goTo(const void *, ooBoolean = (oocTrue)) = 0; 
virtual ooBoolean goTo(const ooHandle(ooObj) &) = 0; 



virtual ooRef(ooObj) goToIndex(int) = 0; 
virtual ooRef(ooObj) goToLast(); 

virtual ooBoolean hasNext() = 0; 


virtual ooBoolean hasPrevious(); 
virtual ooStatus moveCurrentTo(const ooHandle(ooObj) &) = 0; 


virtual ooRef(ooObj) next() = 0; 


virtual int nextIndex(); 


virtual ooRef(ooObj) previous() = 0; 


virtual int previousIndex(); 


virtual ooStatus remove() = 0; 


virtual void reset() = 0; 


inline virtual ooStatus set(const ooHandle(ooObj) &objH) 
{ return ((ooStatus) 0); }


virtual ooBoolean goTo(const ooUInt32, smalltalk_callback) = 0; 
}; 

class ooHashEntryPage : public ooObj { 


public: ooVArray(uint32) entryArray; 
ooHashEntryPage(unsigned); 
#ifndef OO_DDL_TRANSLATION
    virtual ooTypeNumber ooGetTypeN() const;
    virtual char* ooGetTypeName() const;
    ooBoolean ooIsKindOf(ooTypeNumber oo_typeN) const;
    ooHandle(ooHashEntryPage)& ooThis(ooHandle(ooHashEntryPage)& objH,
			 ooMode aMode = oocNoOpen) const
      {
	return *ooReinterpretCast(ooHandle(ooHashEntryPage) *, &(this->ooObj::ooThis(objH, aMode)));
      }
    ooHandle(ooHashEntryPage) ooThis(ooMode aMode = oocNoOpen) const;
    void *operator new(size_t);
    void *operator new(size_t, const ooHandle(ooObj) &nearH);
    void *operator new(size_t, const ooHandle(ooObj) &nearH, ooClusterStrategy& strategy)
	{
		return strategy.newObj(ooTypeN(ooHashEntryPage), nearH);
	}
    void *operator new(size_t, const ooId& nearR, ooClusterStrategy& strategy)
	{
		return strategy.newObj(ooTypeN(ooHashEntryPage), nearR);
	}
    void *operator new(size_t, ooClusterStrategy& strategy)
	{
		return strategy.newObj(ooTypeN(ooHashEntryPage));
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
    ooRef(ooHashEntryPage)& ooThis(ooRef(ooHashEntryPage)& objId, ooMode aMode = oocNoOpen) const;
    ooHashEntryPage(ooInternalObj iobj);
#endif /* !defined(OO_DDL_TRANSLATION) */
}; 


class ooHashBucketX : public ooObj { 


public: ooVArray(uint16) pageNumberArray; 

uint16 depth; 
uint16 entrySize; 
uint32 *getEntry(uint32, unsigned, unsigned, ooRef(ooHashBucketX), unsigned, ocmSession *, ooHandle(ooHashEntryPage) &, ooBoolean = (oocFalse), ooBoolean = (oocFalse)); 



ooHashBucketX(int, unsigned, unsigned, unsigned, unsigned); 

virtual ~ooHashBucketX(); 
int bucketSize(const ooHandle(ooHashBucketX) &, unsigned, unsigned = (0)); 
void setHandleId(ooHandle(ooHashEntryPage) &, int, ooRef(ooHashBucketX) &); 
#ifndef OO_DDL_TRANSLATION
    virtual ooTypeNumber ooGetTypeN() const;
    virtual char* ooGetTypeName() const;
    ooBoolean ooIsKindOf(ooTypeNumber oo_typeN) const;
    ooHandle(ooHashBucketX)& ooThis(ooHandle(ooHashBucketX)& objH,
			 ooMode aMode = oocNoOpen) const
      {
	return *ooReinterpretCast(ooHandle(ooHashBucketX) *, &(this->ooObj::ooThis(objH, aMode)));
      }
    ooHandle(ooHashBucketX) ooThis(ooMode aMode = oocNoOpen) const;
    void *operator new(size_t);
    void *operator new(size_t, const ooHandle(ooObj) &nearH);
    void *operator new(size_t, const ooHandle(ooObj) &nearH, ooClusterStrategy& strategy)
	{
		return strategy.newObj(ooTypeN(ooHashBucketX), nearH);
	}
    void *operator new(size_t, const ooId& nearR, ooClusterStrategy& strategy)
	{
		return strategy.newObj(ooTypeN(ooHashBucketX), nearR);
	}
    void *operator new(size_t, ooClusterStrategy& strategy)
	{
		return strategy.newObj(ooTypeN(ooHashBucketX));
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
    ooRef(ooHashBucketX)& ooThis(ooRef(ooHashBucketX)& objId, ooMode aMode = oocNoOpen) const;
    ooHashBucketX(ooInternalObj iobj);
#endif /* !defined(OO_DDL_TRANSLATION) */
}; 


class ooHashBasedCollection : public ooCollection { 

friend class ooHashIteratorX; 
friend class ooHashMapXIterator; 
friend class ooHashMapXValueIterator; 
friend class ooHashSetX; 
friend class ooHashInternalObjectsIterator; 

protected: ooHashBasedCollection(uint16, uint8); 

uint32 _bucketCapacity; 
uint16 pagesPerBucket; 
uint16 bucketPageCapacity; 
uint16 otherPageCapacity; 
uint16 depth; 
uint8 entryType; 

ooBoolean bucketFull(ooHandle(ooHashBucketX) &, const ooHandle(ooObj) &, const ooHandle(ooObj) &, unsigned); 
ooBoolean rehash(const ooRef(ooObj) &, const ooRef(ooObj) &, unsigned, unsigned); 
uint32 *entry(const void *) const; 
uint32 *entry(const ooHandle(ooObj) &, uint32) const; 
virtual void entryClear(uint32 *) const = 0; 
virtual unsigned entryHashCode(uint32 *) const = 0; 
virtual ooRef(ooObj) entryKey(uint32 *) const = 0; 
ooBoolean entryRemove(ooHandle(ooHashBucketX) &, uint32 *, unsigned); 
virtual unsigned entrySize() const = 0; 
virtual ooRef(ooObj) entryValue(uint32 *) const = 0; 
inline ooBoolean entryInUse(uint32 *entry) const { return entryKey (entry) . _DB != 0; }
virtual void entrySetData(uint32 *, const ooRef(ooObj) &, const ooRef(ooObj) &, unsigned) const = 0; 
virtual ooBoolean equal(uint32 *, const ooHandle(ooObj) &, uint32) const = 0; 
virtual ooBoolean equal(uint32 *, const void *, uint32, const ooHandle(ooCompare) &) const = 0; 
ooBoolean addKeyValue(const ooHandle(ooObj) &, const ooHandle(ooObj) &); 
virtual ooBoolean addKeyValue(const ooHandle(ooObj) &, const ooHandle(ooObj) &, ooUInt32, ooRef(ooObj) *); 
ooStatus expandDirectory(); 
virtual ooHandle(ooHashBucketX) getBucket(unsigned) const = 0; 
virtual void setBucket(unsigned, const ooHandle(ooHashBucketX) &) = 0; 
virtual ooStatus updateDirectory() = 0; 
virtual ooStatus resizeDirectoryArray(unsigned) = 0; 
inline unsigned lastEntryPos() const 


{ return bucketPageCapacity + (otherPageCapacity * pagesPerBucket) - 1; }
void setCapacityValues(ooHandle(ooObj) &); 
virtual ooHandle(ooObj) newBucketContainer(ooHandle(ooHashBucketX) &) const; 

public: enum { hashEntry, hashEntryWithHash, hashMapEntry, hashMapEntryWithHash, hashEntryShort, hashEntryShortWithHash}; 
virtual ooBoolean add(const ooHandle(ooObj) &); 
ooBoolean add(const ooHandle(ooObj) &, uint32); 
virtual void clear(); 
virtual ooBoolean contains(const void *) const; 
virtual ooBoolean contains(const ooHandle(ooObj) &) const; 
ooBoolean contains(const ooHandle(ooObj) &, uint32) const; 
virtual unsigned directorySize() const = 0; 
virtual ooRef(ooObj) get(const void *) const; 
virtual ooRef(ooObj) get(const ooHandle(ooObj) &, uint32) const; 


virtual ooUInt32 hashOf(const ooHandle(ooObj) &) const; 

virtual ooBoolean isEmpty() const; 
virtual ooCollectionIterator *iterator() const; 
virtual ooStatus refresh(ooMode) const; 

virtual void rememberLastObjectAddedId(const ooHandle(ooObj) &) = 0; 
virtual ooBoolean remove(const ooHandle(ooObj) &); 
ooBoolean remove(const ooHandle(ooObj) &, uint32, ooRef(ooObj) * = 0); 
ooBoolean remove(const void *); 


virtual int size() const; 
void statistics(); 
#ifndef OO_DDL_TRANSLATION
    virtual ooTypeNumber ooGetTypeN() const;
    virtual char* ooGetTypeName() const;
    ooBoolean ooIsKindOf(ooTypeNumber oo_typeN) const;
    ooHandle(ooHashBasedCollection)& ooThis(ooHandle(ooHashBasedCollection)& objH,
			 ooMode aMode = oocNoOpen) const
      {
	return *ooReinterpretCast(ooHandle(ooHashBasedCollection) *, &(this->ooObj::ooThis(objH, aMode)));
      }
    ooHandle(ooHashBasedCollection) ooThis(ooMode aMode = oocNoOpen) const;
    void *operator new(size_t);
    void *operator new(size_t, const ooHandle(ooObj) &nearH);
    void *operator new(size_t, const ooHandle(ooObj) &nearH, ooClusterStrategy& strategy)
	{
		return strategy.newObj(ooTypeN(ooHashBasedCollection), nearH);
	}
    void *operator new(size_t, const ooId& nearR, ooClusterStrategy& strategy)
	{
		return strategy.newObj(ooTypeN(ooHashBasedCollection), nearR);
	}
    void *operator new(size_t, ooClusterStrategy& strategy)
	{
		return strategy.newObj(ooTypeN(ooHashBasedCollection));
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
    ooRef(ooHashBasedCollection)& ooThis(ooRef(ooHashBasedCollection)& objId, ooMode aMode = oocNoOpen) const;
    ooHashBasedCollection(ooInternalObj iobj);
#endif /* !defined(OO_DDL_TRANSLATION) */
}; 
class ooHashSetX : public ooHashBasedCollection { 

friend class ooHashIteratorX; 
friend class ooHashMapXIterator; 
friend class ooHashMapXValueIterator; 


protected: ooVArray(ooRef(ooHashBucketX)) bucketArray; 
ooRef(ooCompare) _compare; 

virtual void entryClear(uint32 *) const; 
virtual unsigned entryHashCode(uint32 *) const; 
virtual ooRef(ooObj) entryKey(uint32 *) const; 
virtual unsigned entrySize() const; 
virtual ooRef(ooObj) entryValue(uint32 *) const; 
virtual void entrySetData(uint32 *, const ooRef(ooObj) &, const ooRef(ooObj) &, unsigned) const; 
virtual ooBoolean equal(uint32 *, const ooHandle(ooObj) &, uint32) const; 
virtual ooBoolean equal(uint32 *, const void *, uint32, const ooHandle(ooCompare) &) const; 
inline virtual void setBucket(unsigned i, const ooHandle(ooHashBucketX) &bucketH) { bucketArray . elem (i) = bucketH; }
inline virtual ooHandle(ooHashBucketX) getBucket(unsigned i) const { return bucketArray . elem (i); }
inline virtual ooStatus updateDirectory() { return bucketArray . update (); }
virtual void rememberLastObjectAddedId(const ooHandle(ooObj) &); 
inline virtual ooStatus resizeDirectoryArray(unsigned s) { return bucketArray . resize (s); }


public: ooHashSetX(int = (100), ooHandle(ooObj) = ooHandle(ooObj)((0))); 
ooHashSetX(ooHandle(ooCompare) &, int = (100), ooHandle(ooObj) = ooHandle(ooObj)((0))); 

virtual ~ooHashSetX(); 
inline virtual unsigned directorySize() const { return bucketArray . size (); }
inline virtual const ooRef(ooCompare) comparator() const 
{ return _compare; }
#ifndef OO_DDL_TRANSLATION
    virtual ooTypeNumber ooGetTypeN() const;
    virtual char* ooGetTypeName() const;
    ooBoolean ooIsKindOf(ooTypeNumber oo_typeN) const;
    ooHandle(ooHashSetX)& ooThis(ooHandle(ooHashSetX)& objH,
			 ooMode aMode = oocNoOpen) const
      {
	return *ooReinterpretCast(ooHandle(ooHashSetX) *, &(this->ooObj::ooThis(objH, aMode)));
      }
    ooHandle(ooHashSetX) ooThis(ooMode aMode = oocNoOpen) const;
    void *operator new(size_t);
    void *operator new(size_t, const ooHandle(ooObj) &nearH);
    void *operator new(size_t, const ooHandle(ooObj) &nearH, ooClusterStrategy& strategy)
	{
		return strategy.newObj(ooTypeN(ooHashSetX), nearH);
	}
    void *operator new(size_t, const ooId& nearR, ooClusterStrategy& strategy)
	{
		return strategy.newObj(ooTypeN(ooHashSetX), nearR);
	}
    void *operator new(size_t, ooClusterStrategy& strategy)
	{
		return strategy.newObj(ooTypeN(ooHashSetX));
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
    ooRef(ooHashSetX)& ooThis(ooRef(ooHashSetX)& objId, ooMode aMode = oocNoOpen) const;
    ooHashSetX(ooInternalObj iobj);
#endif /* !defined(OO_DDL_TRANSLATION) */
}; 
class ooHashSetShortRef : public ooHashBasedCollection { 

friend class ooHashIteratorX; 
friend class ooHashMapXIterator; 
friend class ooHashMapXValueIterator; 


protected: ooVArray(ooShortRef(ooHashBucketX)) bucketArray; 
ooShortRef(ooCompare) _compare; 
uint16 _lastObjectPage; 

virtual ooBoolean addKeyValue(const ooHandle(ooObj) &, const ooHandle(ooObj) &, ooUInt32, ooRef(ooObj) *); 
virtual void entryClear(uint32 *) const; 
virtual unsigned entryHashCode(uint32 *) const; 
virtual ooRef(ooObj) entryKey(uint32 *) const; 
virtual unsigned entrySize() const; 
virtual ooRef(ooObj) entryValue(uint32 *) const; 
virtual void entrySetData(uint32 *, const ooRef(ooObj) &, const ooRef(ooObj) &, unsigned) const; 
virtual ooBoolean equal(uint32 *, const ooHandle(ooObj) &, uint32) const; 
virtual ooBoolean equal(uint32 *, const void *, uint32, const ooHandle(ooCompare) &) const; 
virtual ooHandle(ooHashBucketX) getBucket(unsigned) const; 
inline virtual void setBucket(unsigned i, const ooHandle(ooHashBucketX) &bucketH) { bucketArray . elem (i) = bucketH; }
virtual ooHandle(ooObj) newBucketContainer(ooHandle(ooHashBucketX) &) const; 
inline virtual ooStatus updateDirectory() { return bucketArray . update (); }
inline virtual ooStatus resizeDirectoryArray(unsigned s) { return bucketArray . resize (s); }


public: ooHashSetShortRef(int = (100)); 
ooHashSetShortRef(ooHandle(ooCompare) &, int = (100)); 

virtual ~ooHashSetShortRef(); 
inline virtual unsigned directorySize() const { return bucketArray . size (); }
virtual const ooRef(ooCompare) comparator() const; 
virtual ooUInt32 hashOf(const ooHandle(ooObj) &) const; 
inline uint16 lastObjectPage() { return _lastObjectPage; }
virtual void rememberLastObjectAddedId(const ooHandle(ooObj) &); 
#ifndef OO_DDL_TRANSLATION
    virtual ooTypeNumber ooGetTypeN() const;
    virtual char* ooGetTypeName() const;
    ooBoolean ooIsKindOf(ooTypeNumber oo_typeN) const;
    ooHandle(ooHashSetShortRef)& ooThis(ooHandle(ooHashSetShortRef)& objH,
			 ooMode aMode = oocNoOpen) const
      {
	return *ooReinterpretCast(ooHandle(ooHashSetShortRef) *, &(this->ooObj::ooThis(objH, aMode)));
      }
    ooHandle(ooHashSetShortRef) ooThis(ooMode aMode = oocNoOpen) const;
    void *operator new(size_t);
    void *operator new(size_t, const ooHandle(ooObj) &nearH);
    void *operator new(size_t, const ooHandle(ooObj) &nearH, ooClusterStrategy& strategy)
	{
		return strategy.newObj(ooTypeN(ooHashSetShortRef), nearH);
	}
    void *operator new(size_t, const ooId& nearR, ooClusterStrategy& strategy)
	{
		return strategy.newObj(ooTypeN(ooHashSetShortRef), nearR);
	}
    void *operator new(size_t, ooClusterStrategy& strategy)
	{
		return strategy.newObj(ooTypeN(ooHashSetShortRef));
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
    ooRef(ooHashSetShortRef)& ooThis(ooRef(ooHashSetShortRef)& objId, ooMode aMode = oocNoOpen) const;
    ooHashSetShortRef(ooInternalObj iobj);
#endif /* !defined(OO_DDL_TRANSLATION) */
}; 



class ooHashMapX : public ooHashBasedCollection { 

friend class ooHashIteratorX; 

protected: ooVArray(ooRef(ooHashBucketX)) bucketArray; 
ooRef(ooCompare) _compare; 
enum { error, success, tryAgain}; 
virtual ooBoolean add(const ooHandle(ooObj) &); 
virtual void entryClear(uint32 *) const; 
virtual unsigned entryHashCode(uint32 *) const; 
virtual ooRef(ooObj) entryKey(uint32 *) const; 
virtual unsigned entrySize() const; 
virtual ooRef(ooObj) entryValue(uint32 *) const; 
virtual void entrySetData(uint32 *, const ooRef(ooObj) &, const ooRef(ooObj) &, unsigned) const; 
virtual ooBoolean equal(uint32 *, const ooHandle(ooObj) &, uint32) const; 
virtual ooBoolean equal(uint32 *, const void *, uint32, const ooHandle(ooCompare) &) const; 
virtual ooBoolean isMap() const; 
inline virtual ooStatus updateDirectory() { return bucketArray . update (); }
inline virtual ooStatus resizeDirectoryArray(unsigned s) { return bucketArray . resize (s); }
virtual ooHandle(ooHashBucketX) getBucket(unsigned) const; 
inline virtual void setBucket(unsigned i, const ooHandle(ooHashBucketX) &bucketH) { bucketArray . elem (i) = bucketH; }
inline virtual void rememberLastObjectAddedId(const ooHandle(ooObj) &objH) { }


public: ooHashMapX(int = (100), ooHandle(ooObj) = ooHandle(ooObj)((0))); 
ooHashMapX(ooHandle(ooCompare) &, int = (100), ooHandle(ooObj) = ooHandle(ooObj)((0))); 

virtual ~ooHashMapX(); 
virtual ooBoolean addAll(const ooHandle(ooCollection) &); 


inline virtual const ooRef(ooCompare) comparator() const 
{ return _compare; }
ooBoolean containsKey(const void *) const; 
ooBoolean containsKey(const ooHandle(ooObj) &) const; 
ooBoolean containsValue(const ooHandle(ooObj) &) const; 

inline virtual unsigned directorySize() const { return bucketArray . size (); }


virtual ooRef(ooObj) get(const void *) const; 
ooRef(ooObj) get(const ooHandle(ooObj) &) const; 
virtual ooRef(ooObj) get(const ooHandle(ooObj) &, uint32) const; 

ooStatus put(const ooHandle(ooObj) &, const ooHandle(ooObj) &); 
inline ooStatus put(const ooHandle(ooObj) &key, const ooHandle(ooObj) &value, unsigned hash, ooRef(ooObj) *oldValue = 0) 


{ return addKeyValue (key, value, hash, oldValue) == oocTrue; }


virtual void removeAllDeleted(); 
virtual ooCollectionIterator *valueIterator() const; 
ooRef(ooObj) unbind(const ooHandle(ooObj) &); 
#ifndef OO_DDL_TRANSLATION
    virtual ooTypeNumber ooGetTypeN() const;
    virtual char* ooGetTypeName() const;
    ooBoolean ooIsKindOf(ooTypeNumber oo_typeN) const;
    ooHandle(ooHashMapX)& ooThis(ooHandle(ooHashMapX)& objH,
			 ooMode aMode = oocNoOpen) const
      {
	return *ooReinterpretCast(ooHandle(ooHashMapX) *, &(this->ooObj::ooThis(objH, aMode)));
      }
    ooHandle(ooHashMapX) ooThis(ooMode aMode = oocNoOpen) const;
    void *operator new(size_t);
    void *operator new(size_t, const ooHandle(ooObj) &nearH);
    void *operator new(size_t, const ooHandle(ooObj) &nearH, ooClusterStrategy& strategy)
	{
		return strategy.newObj(ooTypeN(ooHashMapX), nearH);
	}
    void *operator new(size_t, const ooId& nearR, ooClusterStrategy& strategy)
	{
		return strategy.newObj(ooTypeN(ooHashMapX), nearR);
	}
    void *operator new(size_t, ooClusterStrategy& strategy)
	{
		return strategy.newObj(ooTypeN(ooHashMapX));
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
    ooRef(ooHashMapX)& ooThis(ooRef(ooHashMapX)& objId, ooMode aMode = oocNoOpen) const;
    ooHashMapX(ooInternalObj iobj);
#endif /* !defined(OO_DDL_TRANSLATION) */
}; 


class ooHashIteratorX : public ooCollectionIterator { 


protected: ooHandle(ooHashBasedCollection) _hashSet; 
ooInt32 _dirPos; 
ooInt32 _bucketPos; 
uint32 *currentEntry(); 
uint32 *nextEntry(); 
uint32 *previousEntry(); 
virtual ooRef(ooObj) &currentP(ooBoolean = (oocFalse)); 
inline virtual ooBoolean goTo(const ooUInt32 hash, smalltalk_callback) { return oocFalse; }
bool isKeyIterator; 

public: ooHashIteratorX(const ooHandle(ooHashBasedCollection) &, bool = (true)); 
virtual ~ooHashIteratorX(); 
virtual ooHandle(ooCollection) collection(); 
virtual ooRef(ooObj) current(); 
virtual ooRef(ooObj) currentValue(); 
virtual int currentIndex(); 
virtual ooBoolean goTo(const void *, ooBoolean = (oocTrue)); 
virtual ooBoolean goTo(const ooHandle(ooObj) &); 
ooBoolean goTo(const ooHandle(ooObj) &, uint32); 
virtual ooRef(ooObj) goToIndex(int); 
virtual ooBoolean hasNext(); 
virtual ooBoolean hasPrevious(); 
virtual ooRef(ooObj) next(); 
virtual ooRef(ooObj) previous(); 
virtual ooStatus moveCurrentTo(const ooHandle(ooObj) &); 
virtual ooStatus remove(); 
virtual void reset(); 
}; 

class ooHashInternalObjectsIterator { 

ooHandle(ooHashBasedCollection) coH; 
ooHandle(ooHashBucketX) bucketH; 
ooRef(ooHashBucketX) bucketR; 
ooHandle(ooHashEntryPage) entryPageH; 
int pageArraySize; 
int bucket; 
int page; 

public: ooHashInternalObjectsIterator(ooHandle(ooHashBasedCollection) &); 
ooRef(ooObj) next(); 
}; 

class ooHashMapXValueIterator : public ooHashIteratorX { 


inline virtual ooBoolean goTo(const void *objH, ooBoolean mayHaveDublicateMatches = (oocTrue)) { return oocFalse; }
inline virtual ooBoolean goTo(const ooUInt32 hash, smalltalk_callback) { return oocFalse; }

public: ooHashMapXValueIterator(const ooHandle(ooHashMapX) &); 
virtual ooBoolean goTo(const ooHandle(ooObj) &); 
inline ooBoolean goTo(const ooHandle(ooObj) &objH, uint32 hashValue) 
{ return ooHashIteratorX :: goTo (objH, hashValue); }
virtual ooRef(ooObj) current(); 
virtual ooRef(ooObj) next(); 
virtual ooRef(ooObj) previous(); 
virtual ooStatus remove(); 
virtual ooStatus set(const ooHandle(ooObj) &); 
ooStatus set(const ooHandle(ooObj) &, uint32); 
}; 

class ooTreeSetX; 
class ooTreeMapX; 
class ooTreeListX; 
class ooTreeBasedIterator; 
class ooTreeBasedCollectionInternalObjectsIterator; 
class ooTreeInternalNode; 
class ooTreeLeafNode; 
class ooTreeBasedIterator; 
class ooTreeBasedCollection; 

class ooTreeBasedCollectionListener { 


public: bool pause; 
inline ooTreeBasedCollectionListener() : pause (false) { }
virtual void onAddedObject(const ooRef(ooTreeBasedCollection), const ooHandle(ooObj) &, unsigned) = 0; 
virtual void onCreatedRoot(const ooHandle(ooTreeBasedCollection) &) = 0; 
virtual void onCreatedInternalNode(const ooHandle(ooTreeInternalNode) &, unsigned) = 0; 
virtual void onChangedParent(const ooRef(ooObj), bool, const ooRef(ooTreeBasedCollection) &, unsigned) = 0; 
virtual void onDeletedNode(const ooRef(ooTreeBasedCollection) &) = 0; 
virtual void onObjectMap(ooRef(ooObj), ooRef(ooObj)) = 0; 
virtual void onOpenArray(const ooHandle(ooTreeBasedCollection) &, ooMode = oocRead) = 0; 
virtual void onOpenNode(const ooHandle(ooTreeBasedCollection) &, ooMode = oocRead) = 0; 
virtual void onOpenedObject(ooRef(ooObj)) = 0; 
virtual void onRemovedObject(ooRef(ooObj)) = 0; 
}; 

class ooTreeBasedCollection : public ooCollection { 

friend class ooCompare; 
friend class ooTreeSetX; 
friend class ooTreeListX; 
friend class ooTreeMapX; 
friend class ooTreeBasedIterator; 
friend class ooTreeBasedCollectionInternalObjectsIterator; 
friend class ooTreeInternalNode; 
friend class ooTreeLeafNode; 

public: enum packHint { twoThirdsPack, leftPack, rightPack}; 

protected: enum { isLeafNode = 1, shortRefs, fakeRefs = 4, completeKey = 8}; 

ooVArray(uint32) refsAndData; 
uint16 entriesInUseSize; 
inline ooTreeBasedCollection(unsigned arraySize) : refsAndData (arraySize), entriesInUseSize (0) { }

ooInt32 binarySearch(const ooHandle(ooObj) &, const ooHandle(ooCompare) &, const uint32 *, bool &, uint8, uint8, bool) const; 
ooInt32 binarySearchLeaf(const ooHandle(ooObj) &, const ooHandle(ooCompare) &, const uint32 *, bool &, uint8, uint8, bool) const; 
ooInt32 binarySearchLookup(const ooHandle(ooCompare) &, const void *, const uint32 *, bool &, uint8, uint8, bool) const; 
ooInt32 binarySearchLeafLookup(const ooHandle(ooCompare) &, const void *, const uint32 *, bool &, uint8, uint8, bool) const; 

ooStatus compactInternalNodes(ocmSession *); 
ooStatus compactLeafNodes(ooHandle(ooTreeLeafNode) &, uint8, uint8, unsigned, bool &, bool = (true), bool = (true), float = ((5.000000000000000000e-01))); 
void compactPart2(); 
int compare(unsigned, const uint32 *, unsigned, uint8, uint8) const; 
virtual unsigned depth(unsigned, ocmSession *) const; 
virtual uint8 entrySize() const = 0; 
virtual ooStatus full(const ooHandle(ooTreeBasedCollection) &, uint8, uint8, unsigned, packHint = twoThirdsPack) = 0; 
ooStatus fullRootInternal(); 
ooStatus fullRootLeaf(const ooHandle(ooTreeBasedCollection) &, packHint); 

uint32 *getComparisonData(unsigned, uint8, uint8) const; 
ooRef(ooObj) getFromLeaf(const ooHandle(ooCompare), const void *, const uint32 *, uint8, uint8, bool) const; 
virtual ooRef(ooTreeBasedCollection) getLastNode() const; 
ooRef(ooObj) getOid(unsigned, uint8, uint8) const; 
virtual ooRef(ooObj) getOidMap(unsigned, uint8) const; 
int inNodeIndexOf(const ooRef(ooObj), uint8, uint8) const; 
void insertBefore(const ooRef(ooObj) &, const uint32 *, unsigned, uint8, uint8); 
bool insertLeafNodeAfter(ooHandle(ooTreeLeafNode) &, ooRef(ooTreeLeafNode), uint8, uint8); 
bool insertLeafNodeBefore(ooHandle(ooTreeLeafNode) &, ooRef(ooTreeLeafNode), uint8, uint8); 
bool insertNodeAfter(ooHandle(ooTreeInternalNode) &, ooRef(ooTreeLeafNode), uint8, uint8); 
virtual ooStatus leftShiftMapOids(unsigned, unsigned, uint8); 
virtual unsigned maxEntries() const = 0; 
unsigned maxEntriesPerNode(uint8) const; 


inline bool isFull(unsigned maxEntriesNode) const 


{ return maxEntriesNode == entriesInUseSize; }

virtual bool isMap() const; 
inline ooInt16 lastIndex() const 
{ return entriesInUseSize - 1; }
virtual void newLastNode(const ooRef(ooTreeLeafNode) &); 

virtual unsigned oidSize() const = 0; 


static bool openArray(const ooHandle(ooTreeBasedCollection) &, ocmSession *, ooMode = oocRead); 
static bool openNode(const ooHandle(ooTreeBasedCollection) &, ocmSession *, ooMode = oocRead); 




ooHandle(ooTreeLeafNode) potentialParentOf(const ooHandle(ooCompare) &, ooHandle(ooTreeBasedCollection), const void *, const uint32 *, uint8, uint8, bool) const; 
ooHandle(ooTreeLeafNode) potentialParentOf(ooHandle(ooTreeBasedCollection), const ooHandle(ooObj) &, const ooHandle(ooCompare) &, const uint32 *, uint8, uint8, bool) const; 


ooRef(ooTreeBasedCollection) previous() const; 
void printRefsAndDataArray(uint8) const; 
virtual bool removeLeafNode(ooRef(ooTreeLeafNode) &, uint8, uint8); 

void removeFirst(); 
virtual ooStatus removeIndex(unsigned, uint8, uint8, ocmSession *); 

void removeLast(); 
virtual ooStatus setLastNode(const ooHandle(ooTreeLeafNode) &); 
void setOid(ooRef(ooObj), unsigned, uint8, uint8); 
virtual void setOidMap(ooRef(ooObj), unsigned, uint8, bool = (false)); 
virtual void setToLeafNode(bool = (true)); 
void shiftArrayRight(unsigned, uint8, unsigned, unsigned); 
virtual void shiftMapArrayRight(unsigned, uint8, unsigned, unsigned); 
int treeIndex(const ooHandle(ooTreeBasedCollection) &) const; 
virtual void updateInternalComparisonData(ooRef(ooTreeLeafNode) &, const uint32 *, uint8, uint8); 
bool updateMyInternalComparisonData(ooRef(ooTreeLeafNode) &, const uint32 *, uint8, uint8); 
virtual void updateInternalComparisonData(ooHandle(ooTreeLeafNode) &, uint8, uint8); 
bool updateMyInternalComparisonData(ooHandle(ooTreeLeafNode) &, uint8, uint8); 
virtual void updateInternalData(ooHandle(ooTreeLeafNode) &, ooRef(ooTreeLeafNode) &, uint8, uint8); 
bool updateMyInternalData(ooHandle(ooTreeLeafNode) &, ooRef(ooTreeLeafNode) &, uint8, uint8); 
inline bool usesShortRefs(unsigned idSize) const { return idSize == 1; }

public: static ooTreeBasedCollectionListener *listener; 

bool checkDataSortOrder() const; 
bool checkDataSortOrderAll() const; 
virtual const char *className() const; 
virtual void clear(); 
ooStatus compact(float = ((1.000000000000000000e+00))); 
virtual ooBoolean contains(const ooHandle(ooObj) &) const; 
virtual ooBoolean contains(const void *) const; 


unsigned depth() const; 


virtual ooRef(ooObj) first() const; 

virtual ooRef(ooObj) get(const void *) const; 
ooRef(ooObj) get(unsigned) const; 



virtual ooBoolean isEmpty() const; 

ooBoolean isSortOrderOK(unsigned &) const; 
virtual ooBoolean isLeaf() const; 
virtual ooCollectionIterator *iterator() const; 


ooRef(ooObj) last() const; 

virtual ooStatus refresh(ooMode) const; 
ooHandle(ooTreeBasedCollection) root() const; 




virtual void setUsesFakeObjectReferences(bool) = 0; 

virtual int size() const; 




virtual bool usesFakeRefs() const; 

inline bool usesShortRefs() const { return oidSize () == 1; }
bool verify_internal(unsigned = (0)) const; 
#ifndef OO_DDL_TRANSLATION
    virtual ooTypeNumber ooGetTypeN() const;
    virtual char* ooGetTypeName() const;
    ooBoolean ooIsKindOf(ooTypeNumber oo_typeN) const;
    ooHandle(ooTreeBasedCollection)& ooThis(ooHandle(ooTreeBasedCollection)& objH,
			 ooMode aMode = oocNoOpen) const
      {
	return *ooReinterpretCast(ooHandle(ooTreeBasedCollection) *, &(this->ooObj::ooThis(objH, aMode)));
      }
    ooHandle(ooTreeBasedCollection) ooThis(ooMode aMode = oocNoOpen) const;
    void *operator new(size_t);
    void *operator new(size_t, const ooHandle(ooObj) &nearH);
    void *operator new(size_t, const ooHandle(ooObj) &nearH, ooClusterStrategy& strategy)
	{
		return strategy.newObj(ooTypeN(ooTreeBasedCollection), nearH);
	}
    void *operator new(size_t, const ooId& nearR, ooClusterStrategy& strategy)
	{
		return strategy.newObj(ooTypeN(ooTreeBasedCollection), nearR);
	}
    void *operator new(size_t, ooClusterStrategy& strategy)
	{
		return strategy.newObj(ooTypeN(ooTreeBasedCollection));
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
    ooRef(ooTreeBasedCollection)& ooThis(ooRef(ooTreeBasedCollection)& objId, ooMode aMode = oocNoOpen) const;
    ooTreeBasedCollection(ooInternalObj iobj);
#endif /* !defined(OO_DDL_TRANSLATION) */
}; 


class ooTreeInternalNode : public ooTreeBasedCollection { 

friend class ooTreeBasedCollection; 
friend class ooTreeLeafNode; 
friend class ooTreeBasedCollectionInternalObjectsIterator; 


protected: ooRef(ooTreeBasedCollection) theParent; 
ooRef(ooTreeInternalNode) left; 
ooRef(ooTreeInternalNode) right; 

ooTreeInternalNode(const ooHandle(ooTreeBasedCollection) &, const ooRef(ooTreeInternalNode), const ooRef(ooTreeInternalNode), unsigned); 

virtual ~ooTreeInternalNode(); 
virtual ooBoolean add(const ooHandle(ooObj) &); 
bool checkParentChild(ooHandle(ooTreeLeafNode) &) const; 
virtual const char *className() const; 
ooStatus compactInternalNode(ocmSession *, uint8, uint8); 
const ooRef(ooCompare) getComparator(ocmSession *) const; 
virtual unsigned depth(unsigned, ocmSession *) const; 
virtual uint8 entrySize() const; 
virtual ooStatus full(const ooHandle(ooTreeBasedCollection) &, uint8, uint8, unsigned, ooTreeBasedCollection::packHint = ooTreeBasedCollection::twoThirdsPack); 
virtual ooBoolean isRoot() const; 
virtual unsigned maxEntries() const; 
virtual unsigned oidSize() const; 
void setParent(ooRef(ooTreeBasedCollection)); 
virtual ooBoolean remove(const ooHandle(ooObj) &); 
bool removeInternalNodeFixLeftRight(ocmSession *); 
virtual bool removeLeafNode(ooRef(ooTreeLeafNode) &, uint8, uint8); 
virtual void updateInternalComparisonData(ooHandle(ooTreeLeafNode) &, uint8, uint8); 
virtual void updateInternalComparisonData(ooRef(ooTreeLeafNode) &, const uint32 *, uint8, uint8); 
virtual void updateInternalData(ooHandle(ooTreeLeafNode) &, ooRef(ooTreeLeafNode) &, uint8, uint8); 
virtual void setUsesFakeObjectReferences(bool); 

public: inline ooInt16 lastIndex() const 


{ return ooTreeBasedCollection :: lastIndex (); }
inline ooRef(ooTreeInternalNode) getRight() const 


{ return right; }
virtual const ooRef(ooCompare) comparator() const; 
virtual ooBoolean isLeaf() const; 
inline ooRef(ooTreeBasedCollection) getParent() { return theParent; }
#ifndef OO_DDL_TRANSLATION
    virtual ooTypeNumber ooGetTypeN() const;
    virtual char* ooGetTypeName() const;
    ooBoolean ooIsKindOf(ooTypeNumber oo_typeN) const;
    ooHandle(ooTreeInternalNode)& ooThis(ooHandle(ooTreeInternalNode)& objH,
			 ooMode aMode = oocNoOpen) const
      {
	return *ooReinterpretCast(ooHandle(ooTreeInternalNode) *, &(this->ooObj::ooThis(objH, aMode)));
      }
    ooHandle(ooTreeInternalNode) ooThis(ooMode aMode = oocNoOpen) const;
    void *operator new(size_t);
    void *operator new(size_t, const ooHandle(ooObj) &nearH);
    void *operator new(size_t, const ooHandle(ooObj) &nearH, ooClusterStrategy& strategy)
	{
		return strategy.newObj(ooTypeN(ooTreeInternalNode), nearH);
	}
    void *operator new(size_t, const ooId& nearR, ooClusterStrategy& strategy)
	{
		return strategy.newObj(ooTypeN(ooTreeInternalNode), nearR);
	}
    void *operator new(size_t, ooClusterStrategy& strategy)
	{
		return strategy.newObj(ooTypeN(ooTreeInternalNode));
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
    ooRef(ooTreeInternalNode)& ooThis(ooRef(ooTreeInternalNode)& objId, ooMode aMode = oocNoOpen) const;
    ooTreeInternalNode(ooInternalObj iobj);
#endif /* !defined(OO_DDL_TRANSLATION) */
}; 


class ooTreeLeafNode : public ooTreeInternalNode { 

friend class ooTreeSetX; 
friend class ooTreeBasedCollection; 
friend class ooTreeBasedIterator; 
friend class ooTreeInternalNode; 



protected: ooTreeLeafNode(const ooHandle(ooTreeBasedCollection) &, const ooRef(ooTreeLeafNode), const ooRef(ooTreeLeafNode), unsigned); 


static bool deleteLeafNode(ooHandle(ooTreeLeafNode) &, uint8, uint8); 
virtual ooStatus full(const ooHandle(ooTreeBasedCollection) &, uint8, uint8, unsigned, ooTreeBasedCollection::packHint = ooTreeBasedCollection::twoThirdsPack); 

public: virtual const char *className() const; 
virtual ooBoolean isLeaf() const; 
#ifndef OO_DDL_TRANSLATION
    virtual ooTypeNumber ooGetTypeN() const;
    virtual char* ooGetTypeName() const;
    ooBoolean ooIsKindOf(ooTypeNumber oo_typeN) const;
    ooHandle(ooTreeLeafNode)& ooThis(ooHandle(ooTreeLeafNode)& objH,
			 ooMode aMode = oocNoOpen) const
      {
	return *ooReinterpretCast(ooHandle(ooTreeLeafNode) *, &(this->ooObj::ooThis(objH, aMode)));
      }
    ooHandle(ooTreeLeafNode) ooThis(ooMode aMode = oocNoOpen) const;
    void *operator new(size_t);
    void *operator new(size_t, const ooHandle(ooObj) &nearH);
    void *operator new(size_t, const ooHandle(ooObj) &nearH, ooClusterStrategy& strategy)
	{
		return strategy.newObj(ooTypeN(ooTreeLeafNode), nearH);
	}
    void *operator new(size_t, const ooId& nearR, ooClusterStrategy& strategy)
	{
		return strategy.newObj(ooTypeN(ooTreeLeafNode), nearR);
	}
    void *operator new(size_t, ooClusterStrategy& strategy)
	{
		return strategy.newObj(ooTypeN(ooTreeLeafNode));
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
    ooRef(ooTreeLeafNode)& ooThis(ooRef(ooTreeLeafNode)& objId, ooMode aMode = oocNoOpen) const;
    ooTreeLeafNode(ooInternalObj iobj);
#endif /* !defined(OO_DDL_TRANSLATION) */
}; 


class ooTreeLeafNodeMap : public ooTreeLeafNode { 

friend class ooTreeSetX; 
friend class ooTreeMapX; 
friend class ooTreeBasedCollection; 
friend class ooTreeBasedIterator; 
friend class ooTreeInternalNode; 
friend class ooTreeLeafNode; 


protected: ooVArray(uint32) mapRefs; 

ooTreeLeafNodeMap(const ooHandle(ooTreeBasedCollection) &, const ooRef(ooTreeLeafNode), const ooRef(ooTreeLeafNode), unsigned, unsigned); 



virtual const char *className() const; 
virtual ooRef(ooObj) getOidMap(unsigned, uint8) const; 
virtual bool isMap() const; 
virtual ooStatus leftShiftMapOids(unsigned, unsigned, uint8); 
virtual ooStatus removeIndex(unsigned, uint8, uint8, ocmSession *); 
virtual void setOidMap(ooRef(ooObj), unsigned, uint8, bool = (false)); 
virtual void shiftMapArrayRight(unsigned, uint8, unsigned, unsigned); 
public: 
#ifndef OO_DDL_TRANSLATION
    virtual ooTypeNumber ooGetTypeN() const;
    virtual char* ooGetTypeName() const;
    ooBoolean ooIsKindOf(ooTypeNumber oo_typeN) const;
    ooHandle(ooTreeLeafNodeMap)& ooThis(ooHandle(ooTreeLeafNodeMap)& objH,
			 ooMode aMode = oocNoOpen) const
      {
	return *ooReinterpretCast(ooHandle(ooTreeLeafNodeMap) *, &(this->ooObj::ooThis(objH, aMode)));
      }
    ooHandle(ooTreeLeafNodeMap) ooThis(ooMode aMode = oocNoOpen) const;
    void *operator new(size_t);
    void *operator new(size_t, const ooHandle(ooObj) &nearH);
    void *operator new(size_t, const ooHandle(ooObj) &nearH, ooClusterStrategy& strategy)
	{
		return strategy.newObj(ooTypeN(ooTreeLeafNodeMap), nearH);
	}
    void *operator new(size_t, const ooId& nearR, ooClusterStrategy& strategy)
	{
		return strategy.newObj(ooTypeN(ooTreeLeafNodeMap), nearR);
	}
    void *operator new(size_t, ooClusterStrategy& strategy)
	{
		return strategy.newObj(ooTypeN(ooTreeLeafNodeMap));
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
    ooRef(ooTreeLeafNodeMap)& ooThis(ooRef(ooTreeLeafNodeMap)& objId, ooMode aMode = oocNoOpen) const;
    ooTreeLeafNodeMap(ooInternalObj iobj);
#endif /* !defined(OO_DDL_TRANSLATION) */
}; 


class ooTreeSetX : public ooTreeBasedCollection { 



protected: ooRef(ooCompare) theComparator; 
int16 maxEntriesNode; 
uint8 numberOfUint32PerEntry; 
uint8 rootFlags; 

ooBoolean addToLeafRoot(const ooHandle(ooObj) &, const uint32 *, const ooHandle(ooObj) *, ooRef(ooObj) *); 
ooBoolean containsLeafRoot(const ooHandle(ooObj) &, const uint32 *) const; 
inline virtual uint8 entrySize() const { return numberOfUint32PerEntry; }
virtual ooStatus full(const ooHandle(ooTreeBasedCollection) &, uint8, uint8, unsigned, ooTreeBasedCollection::packHint = ooTreeBasedCollection::twoThirdsPack); 
virtual ooBoolean isLeaf() const; 
inline virtual unsigned maxEntries() const { return maxEntriesNode; }
virtual unsigned oidSize() const; 
ooBoolean removeFromLeafRoot(const ooHandle(ooObj) &, const uint32 *); 
ooBoolean removeFromLeafRootByLookupKey(const void *, const uint32 *); 
virtual bool removeLeafNode(ooRef(ooTreeLeafNode) &, uint8, uint8); 
virtual void setToLeafNode(bool = (true)); 

public: virtual ~ooTreeSetX(); 
ooTreeSetX(uint16 = (5), ooBoolean = (oocFalse)); 
ooTreeSetX(ooHandle(ooCompare) &, uint16 = (5), ooBoolean = (oocFalse), bool = (false)); 
ooTreeSetX(ooHandle(ooCompare) &, uint16, ooBoolean, unsigned, bool); 
virtual ooBoolean add(const ooHandle(ooObj) &); 
ooBoolean add(const ooHandle(ooObj) &, const uint32 *, const ooHandle(ooObj) * = 0, ooRef(ooObj) * = 0); 
virtual const char *className() const; 
inline virtual const ooRef(ooCompare) comparator() const 
{ return theComparator; }
inline bool comparisonArrayIsCompleteKey() const { return (rootFlags & completeKey)> 0; }
virtual ooBoolean contains(const void *) const; 
virtual ooBoolean contains(const ooHandle(ooObj) &) const; 
ooBoolean contains(const ooHandle(ooObj) &, const uint32 *) const; 
virtual ooRef(ooObj) get(const void *) const; 
inline ooRef(ooObj) get(unsigned index) const 


{ return ooTreeBasedCollection :: get (index); }
virtual ooRef(ooObj) get(const ooHandle(ooObj) &, const uint32 *) const; 
virtual ooBoolean remove(const ooHandle(ooObj) &); 
ooBoolean remove(const ooHandle(ooObj) &, const uint32 *); 
ooBoolean remove(const void *); 
ooBoolean remove(const void *, const uint32 *); 
virtual void setUsesFakeObjectReferences(bool); 
virtual bool usesFakeRefs() const; 
#ifndef OO_DDL_TRANSLATION
    virtual ooTypeNumber ooGetTypeN() const;
    virtual char* ooGetTypeName() const;
    ooBoolean ooIsKindOf(ooTypeNumber oo_typeN) const;
    ooHandle(ooTreeSetX)& ooThis(ooHandle(ooTreeSetX)& objH,
			 ooMode aMode = oocNoOpen) const
      {
	return *ooReinterpretCast(ooHandle(ooTreeSetX) *, &(this->ooObj::ooThis(objH, aMode)));
      }
    ooHandle(ooTreeSetX) ooThis(ooMode aMode = oocNoOpen) const;
    void *operator new(size_t);
    void *operator new(size_t, const ooHandle(ooObj) &nearH);
    void *operator new(size_t, const ooHandle(ooObj) &nearH, ooClusterStrategy& strategy)
	{
		return strategy.newObj(ooTypeN(ooTreeSetX), nearH);
	}
    void *operator new(size_t, const ooId& nearR, ooClusterStrategy& strategy)
	{
		return strategy.newObj(ooTypeN(ooTreeSetX), nearR);
	}
    void *operator new(size_t, ooClusterStrategy& strategy)
	{
		return strategy.newObj(ooTypeN(ooTreeSetX));
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
    ooRef(ooTreeSetX)& ooThis(ooRef(ooTreeSetX)& objId, ooMode aMode = oocNoOpen) const;
    ooTreeSetX(ooInternalObj iobj);
#endif /* !defined(OO_DDL_TRANSLATION) */
}; 


class ooTreeListX : public ooTreeBasedCollection { 



protected: ooRef(ooTreeBasedCollection) lastNode; 
int16 maxEntriesNode; 
uint8 numberOfUint32PerEntry; 
uint8 rootFlags; 

inline virtual const ooRef(ooCompare) comparator() const { return 0; }
virtual ooBoolean contains(const void *) const; 
inline virtual uint8 entrySize() const { return numberOfUint32PerEntry; }
virtual ooStatus full(const ooHandle(ooTreeBasedCollection) &, uint8, uint8, unsigned, ooTreeBasedCollection::packHint = ooTreeBasedCollection::twoThirdsPack); 
virtual ooRef(ooTreeBasedCollection) getLastNode() const; 
virtual ooBoolean isLeaf() const; 
inline virtual unsigned maxEntries() const { return maxEntriesNode; }
virtual void newLastNode(const ooRef(ooTreeLeafNode) &); 
virtual unsigned oidSize() const; 
virtual bool removeLeafNode(ooRef(ooTreeLeafNode) &, uint8, uint8); 
virtual ooStatus setLastNode(const ooHandle(ooTreeLeafNode) &); 
virtual void setToLeafNode(bool = (true)); 

public: virtual ~ooTreeListX(); 
ooTreeListX(uint16 = (5), ooBoolean = (oocFalse)); 
inline virtual ooBoolean add(const ooHandle(ooObj) &obj) 
{ return addLast (obj) != ((ooStatus) 0); }

ooStatus add(unsigned, const ooHandle(ooObj) &); 
virtual ooBoolean addAll(const ooHandle(ooCollection) &); 
ooStatus addAll(unsigned, ooHandle(ooCollection) &); 
ooStatus addFirst(const ooHandle(ooObj) &); 
ooStatus addLast(const ooHandle(ooObj) &); 
virtual const char *className() const; 
virtual ooBoolean contains(const ooHandle(ooObj) &) const; 


int indexOf(const ooRef(ooObj) &, unsigned = (0)) const; 


int lastIndexOf(const ooRef(ooObj) &, unsigned) const; 



inline int lastIndexOf(const ooHandle(ooObj) &objH) const 
{ return this -> lastIndexOf (objH, this -> size () - 1); }
ooRef(ooObj) remove(unsigned); 
virtual ooBoolean remove(const ooHandle(ooObj) &); 
virtual void removeAllDeleted(); 
ooStatus removeRange(unsigned, unsigned); 
ooStatus set(unsigned, const ooHandle(ooObj) &, ooRef(ooObj) * = 0); 
virtual void setUsesFakeObjectReferences(bool); 
virtual bool usesFakeRefs() const; 
#ifndef OO_DDL_TRANSLATION
    virtual ooTypeNumber ooGetTypeN() const;
    virtual char* ooGetTypeName() const;
    ooBoolean ooIsKindOf(ooTypeNumber oo_typeN) const;
    ooHandle(ooTreeListX)& ooThis(ooHandle(ooTreeListX)& objH,
			 ooMode aMode = oocNoOpen) const
      {
	return *ooReinterpretCast(ooHandle(ooTreeListX) *, &(this->ooObj::ooThis(objH, aMode)));
      }
    ooHandle(ooTreeListX) ooThis(ooMode aMode = oocNoOpen) const;
    void *operator new(size_t);
    void *operator new(size_t, const ooHandle(ooObj) &nearH);
    void *operator new(size_t, const ooHandle(ooObj) &nearH, ooClusterStrategy& strategy)
	{
		return strategy.newObj(ooTypeN(ooTreeListX), nearH);
	}
    void *operator new(size_t, const ooId& nearR, ooClusterStrategy& strategy)
	{
		return strategy.newObj(ooTypeN(ooTreeListX), nearR);
	}
    void *operator new(size_t, ooClusterStrategy& strategy)
	{
		return strategy.newObj(ooTypeN(ooTreeListX));
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
    ooRef(ooTreeListX)& ooThis(ooRef(ooTreeListX)& objId, ooMode aMode = oocNoOpen) const;
    ooTreeListX(ooInternalObj iobj);
#endif /* !defined(OO_DDL_TRANSLATION) */
}; 


class ooTreeMapX : public ooTreeSetX { 

friend class ooTreeBasedCollection; 


protected: ooVArray(uint32) mapRefs; 

virtual ooRef(ooObj) getOidMap(unsigned, uint8) const; 
virtual ooStatus leftShiftMapOids(unsigned, unsigned, uint8); 
virtual bool isMap() const; 
virtual ooStatus removeIndex(unsigned, uint8, uint8, ocmSession *); 
virtual bool removeLeafNode(ooRef(ooTreeLeafNode) &, uint8, uint8); 
virtual void setOidMap(ooRef(ooObj), unsigned, uint8, bool = (false)); 
virtual void setToLeafNode(bool = (true)); 
virtual void shiftMapArrayRight(unsigned, uint8, unsigned, unsigned); 

public: virtual ~ooTreeMapX(); 
ooTreeMapX(uint16 = (5), ooBoolean = (oocFalse)); 
ooTreeMapX(ooHandle(ooCompare) &, uint16 = (5), ooBoolean = (oocFalse), bool = (false)); 
ooTreeMapX(ooHandle(ooCompare) &, uint16, ooBoolean, unsigned, bool); 
virtual ooBoolean add(const ooHandle(ooObj) &); 
ooBoolean add(const ooHandle(ooObj) &, const uint32 *); 

virtual ooBoolean addAll(const ooHandle(ooCollection) &); 

virtual const char *className() const; 
inline ooBoolean containsKey(const void *key) 
{ return contains (key); }
inline ooBoolean containsKey(const ooHandle(ooObj) &key) 
{ return contains (key); }


ooBoolean containsValue(const ooHandle(ooObj) &) const; 


virtual ooRef(ooObj) get(const void *) const; 
ooRef(ooObj) get(const ooHandle(ooObj) &) const; 
virtual ooRef(ooObj) get(const ooHandle(ooObj) &, const uint32 *) const; 
inline ooRef(ooObj) get(unsigned index) const 


{ return ooTreeBasedCollection :: get (index); }


ooStatus put(const ooHandle(ooObj) &, const ooHandle(ooObj) &); 
ooStatus put(const ooHandle(ooObj) &, const ooHandle(ooObj) &, const uint32 *, ooRef(ooObj) * = 0); 



virtual ooCollectionIterator *valueIterator() const; 

ooBoolean removeReturnOldValue(const ooHandle(ooObj) &, const uint32 *, ooRef(ooObj) &); 
#ifndef OO_DDL_TRANSLATION
    virtual ooTypeNumber ooGetTypeN() const;
    virtual char* ooGetTypeName() const;
    ooBoolean ooIsKindOf(ooTypeNumber oo_typeN) const;
    ooHandle(ooTreeMapX)& ooThis(ooHandle(ooTreeMapX)& objH,
			 ooMode aMode = oocNoOpen) const
      {
	return *ooReinterpretCast(ooHandle(ooTreeMapX) *, &(this->ooObj::ooThis(objH, aMode)));
      }
    ooHandle(ooTreeMapX) ooThis(ooMode aMode = oocNoOpen) const;
    void *operator new(size_t);
    void *operator new(size_t, const ooHandle(ooObj) &nearH);
    void *operator new(size_t, const ooHandle(ooObj) &nearH, ooClusterStrategy& strategy)
	{
		return strategy.newObj(ooTypeN(ooTreeMapX), nearH);
	}
    void *operator new(size_t, const ooId& nearR, ooClusterStrategy& strategy)
	{
		return strategy.newObj(ooTypeN(ooTreeMapX), nearR);
	}
    void *operator new(size_t, ooClusterStrategy& strategy)
	{
		return strategy.newObj(ooTypeN(ooTreeMapX));
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
    ooRef(ooTreeMapX)& ooThis(ooRef(ooTreeMapX)& objId, ooMode aMode = oocNoOpen) const;
    ooTreeMapX(ooInternalObj iobj);
#endif /* !defined(OO_DDL_TRANSLATION) */
}; 


class ooTreeBasedIterator : public ooCollectionIterator { 

friend class ooTreeMapX; 
friend class ooTreeListX; 

protected: ocmSession *session; 
uint8 entrySize; 
uint8 oidSize; 
ooHandle(ooTreeBasedCollection) theTreeH; 
ooHandle(ooTreeLeafNode) leafNodeH; 
ooHandle(ooTreeLeafNode) adjacentNodeH; 
uint16 maxEntriesNode; 
ooInt32 theIndex; 
virtual ooRef(ooObj) &currentP(ooBoolean = (oocFalse)); 
bool isKeyIterator; 

public: ooTreeBasedIterator(ooHandle(ooTreeBasedCollection) &, bool = (true)); 
virtual ~ooTreeBasedIterator(); 
ooBoolean add(ooRef(ooObj)); 
ooBoolean add(ooRef(ooObj), const uint32 *); 
virtual ooHandle(ooCollection) collection(); 
virtual ooRef(ooObj) current(); 
ooHandle(ooTreeBasedCollection) &currentNode(); 
virtual int currentIndex(); 
virtual ooRef(ooObj) currentValue(); 
virtual ooBoolean goTo(const void *, ooBoolean = (oocTrue)); 
virtual ooBoolean goTo(const ooHandle(ooObj) &); 
ooBoolean goTo(const ooHandle(ooObj) &, const uint32 *); 
virtual ooRef(ooObj) goToIndex(int); 
ooRef(ooObj) goToIndex(int, ooStatus &); 
virtual ooRef(ooObj) goToLast(); 
inline ooHandle(ooTreeLeafNode) leafNode() const { return leafNodeH; }
virtual ooRef(ooObj) next(); 
virtual ooBoolean hasNext(); 
virtual ooBoolean hasPrevious(); 
virtual ooStatus moveCurrentTo(const ooHandle(ooObj) &); 
virtual ooRef(ooObj) previous(); 
virtual ooStatus remove(); 
virtual void reset(); 
virtual ooStatus set(const ooHandle(ooObj) &); 
ooStatus setValue(const ooHandle(ooObj) &); 


inline virtual ooBoolean goTo(const ooUInt32 hash, smalltalk_callback) { return oocFalse; }
}; 

struct oomDBMap; 

class ooTreeBasedCollectionInternalObjectsIterator { 

ooHandle(ooTreeBasedCollection) theTreeH; 
ooHandle(ooTreeInternalNode) currentNodeH; 
uint8 entrySize; 
uint8 oidSize; 

public: ooTreeBasedCollectionInternalObjectsIterator(ooHandle(ooTreeBasedCollection) &); 
uint16 keyArrayLogicalPage(); 
ooRef(ooTreeInternalNode) next(); 
ooRef(ooTreeInternalNode) fixNext(oomDBMap *); 
}; 

#endif /* !defined(OO_COLLECTION_BASE_H) */
