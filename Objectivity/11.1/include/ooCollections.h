/* C++ header file: Objectivity/DB DDL Version: 11.1 */

#ifndef OO_COLLECTIONS_H
#define OO_COLLECTIONS_H

#ifdef OO_DDL_TRANSLATION
#pragma ooddlout "ooCollections.ddl"
class opiDummyDeclaration;
#endif

#ifndef OO_H
#include <oo.h>
#endif
#include <ooCollectionBase.h>
#include <ooCollectionsSS.h>

#ifndef OO_COLLECTIONS_REF_H
#include "ooCollections_ref.h"
#endif

class CO_STORAGE_SPECIFIER ooTreeIterator; 
class CO_STORAGE_SPECIFIER ooTreeListIterator; 
class ooBTree; 
class CO_STORAGE_SPECIFIER ooBTreeNode; 
class ooTreeList; 
class CO_STORAGE_SPECIFIER ooTreeListNode; 
class CO_STORAGE_SPECIFIER ooTreeSet; 
class CO_STORAGE_SPECIFIER ooTreeMap; 
class CO_STORAGE_SPECIFIER ooTreeMapNode; 
class CO_STORAGE_SPECIFIER ooAdmin; 
class CO_STORAGE_SPECIFIER ooTreeAdmin; 
class CO_STORAGE_SPECIFIER ooTreeMapKeyIterator; 
class CO_STORAGE_SPECIFIER ooTreeMapValueIterator; 

class CO_STORAGE_SPECIFIER ooUnsortedArray : public ooObj { 

friend class ooBTree; 
friend class ooBTreeNode; 
friend class ooTreeIterator; 
friend class ooTreeListIterator; 
friend class ooTreeList; 
friend class ooTreeListNode; 
friend class ooTreeMap; 
friend class ooTreeMapNode; 
friend class ooTreeMapKeyIterator; 
friend class ooTreeMapValueIterator; 
friend class ooTreeSet; 

protected: ooInt32 _lastIndex; 
ooVArray(ooRef(ooObj)) _array; 

public: ooUnsortedArray(int); 
inline virtual ~ooUnsortedArray() { }
ooRef(ooObj) &operator[](ooInt32); 
ooInt32 add(const ooRef(ooObj) &); 
ooStatus addLast(const ooRef(ooObj) &); 
ooStatus addLast(const ooHandle(ooObj) &); 
ooRef(ooObj) &after(const ooHandle(ooObj) &) const; 
ooStatus atPut(const ooInt32, const ooRef(ooObj) &); 
ooRef(ooObj) &before(const ooHandle(ooObj) &) const; 
inline ooInt32 find(const void *obj) const 
{ return - 1; }
ooInt32 find(const ooHandle(ooObj) &) const; 
inline ooRef(ooObj) &first() const 
{ return _array . elem (0); }
ooBoolean contains(const void *) const; 
ooBoolean contains(const ooHandle(ooObj) &) const; 
ooInt32 indexOf(const ooHandle(ooObj) &, ooInt32) const; 
ooStatus insertBefore(const ooHandle(ooObj) &, const ooInt32); 
ooBoolean isEmpty() const; 
ooBoolean isFull() const; 
inline ooRef(ooObj) &last() const 
{ return _array . elem (_lastIndex); }
inline ooInt32 lastIndex() const 
{ return _lastIndex; }
ooInt32 lastIndexOf(const ooHandle(ooObj) &, ooInt32) const; 
inline ooInt32 lastIndexOf(const ooHandle(ooObj) &obj) const 
{ return lastIndexOf (obj, _lastIndex); }
ooBoolean notEmpty() const; 
ooBoolean notFull() const; 
void removeAll(); 
void removeFirst(); 
ooStatus removeIndex(ooInt32); 
void removeLast(); 
ooInt32 size() const; 
ooInt32 usedSize() const; 
ooBoolean remove(ooHandle(ooObj) &); 
void resize(ooInt32); 
#ifndef OO_DDL_TRANSLATION
    virtual ooTypeNumber ooGetTypeN() const;
    virtual char* ooGetTypeName() const;
    ooBoolean ooIsKindOf(ooTypeNumber oo_typeN) const;
    ooHandle(ooUnsortedArray)& ooThis(ooHandle(ooUnsortedArray)& objH,
			 ooMode aMode = oocNoOpen) const
      {
	return *ooReinterpretCast(ooHandle(ooUnsortedArray) *, &(this->ooObj::ooThis(objH, aMode)));
      }
    ooHandle(ooUnsortedArray) ooThis(ooMode aMode = oocNoOpen) const;
    void *operator new(size_t);
    void *operator new(size_t, const ooHandle(ooObj) &nearH);
    void *operator new(size_t, const ooHandle(ooObj) &nearH, ooClusterStrategy& strategy)
	{
		return strategy.newObj(ooTypeN(ooUnsortedArray), nearH);
	}
    void *operator new(size_t, const ooId& nearR, ooClusterStrategy& strategy)
	{
		return strategy.newObj(ooTypeN(ooUnsortedArray), nearR);
	}
    void *operator new(size_t, ooClusterStrategy& strategy)
	{
		return strategy.newObj(ooTypeN(ooUnsortedArray));
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
    ooRef(ooUnsortedArray)& ooThis(ooRef(ooUnsortedArray)& objId, ooMode aMode = oocNoOpen) const;
    ooUnsortedArray(ooInternalObj iobj);
#endif /* !defined(OO_DDL_TRANSLATION) */
}; 


class CO_STORAGE_SPECIFIER ooSortedArray : public ooUnsortedArray { 


public: ooSortedArray(int); 

ooInt32 add(const ooHandle(ooObj) &, ooHandle(ooCompare) &, const ooBoolean); 
ooInt32 binarySearch(const ooHandle(ooObj) &, ooHandle(ooCompare) &, const ooBoolean) const; 
ooInt32 binarySearch(const void *, ooHandle(ooCompare) &, const ooBoolean) const; 


ooInt32 add(const ooHandle(ooObj) &, jobject &, jobject &, JNIEnv *, const ooBoolean); 
ooInt32 binarySearch(jobject &, jobject &, JNIEnv *, const ooBoolean) const; 


ooInt32 binarySearch(smalltalk_callback, const ooBoolean) const; 
#ifndef OO_DDL_TRANSLATION
    virtual ooTypeNumber ooGetTypeN() const;
    virtual char* ooGetTypeName() const;
    ooBoolean ooIsKindOf(ooTypeNumber oo_typeN) const;
    ooHandle(ooSortedArray)& ooThis(ooHandle(ooSortedArray)& objH,
			 ooMode aMode = oocNoOpen) const
      {
	return *ooReinterpretCast(ooHandle(ooSortedArray) *, &(this->ooObj::ooThis(objH, aMode)));
      }
    ooHandle(ooSortedArray) ooThis(ooMode aMode = oocNoOpen) const;
    void *operator new(size_t);
    void *operator new(size_t, const ooHandle(ooObj) &nearH);
    void *operator new(size_t, const ooHandle(ooObj) &nearH, ooClusterStrategy& strategy)
	{
		return strategy.newObj(ooTypeN(ooSortedArray), nearH);
	}
    void *operator new(size_t, const ooId& nearR, ooClusterStrategy& strategy)
	{
		return strategy.newObj(ooTypeN(ooSortedArray), nearR);
	}
    void *operator new(size_t, ooClusterStrategy& strategy)
	{
		return strategy.newObj(ooTypeN(ooSortedArray));
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
    ooRef(ooSortedArray)& ooThis(ooRef(ooSortedArray)& objId, ooMode aMode = oocNoOpen) const;
    ooSortedArray(ooInternalObj iobj);
#endif /* !defined(OO_DDL_TRANSLATION) */
}; 


class CO_STORAGE_SPECIFIER ooBTree : public ooCollection { 

friend class ooCompare; 
friend class ooBTreeNode; 
friend class ooTreeList; 
friend class ooTreeListNode; 
friend class ooTreeAdmin; 
friend class ooTreeSet; 
friend class ooTreeMap; 
friend class ooTreeMapNode; 
friend class ooTreeIterator; 
friend class ooTreeListIterator; 
friend class ooTreeMapKeyIterator; 
friend class ooTreeMapValueIterator; 
friend class ooSortedArray; 



protected: ooRef(ooUnsortedArray) _children; 



ooRef(ooObj) _first; 




unsigned maxRefsPerNodeUsingSinglePage() const; 
ooRef(ooBTree) atFirst() const; 


virtual ooHandle(ooBTree) childOf(const ooHandle(ooBTree) &) const; 
ooRef(ooBTree) atLast() const; 




void compactPart2(); 
ooInt32 depth(ooInt32) const; 
virtual ooStatus first(const ooHandle(ooObj) &); 
virtual ooStatus full(const int = (fiftyFifty)); 

int maxNumberOfChildren() const; 
virtual ooStatus newLow(ooHandle(ooBTree) &) = 0; 

virtual ooRef(ooBTree) next() const; 

virtual ooHandle(ooBTree) parent() const = 0; 
virtual ooStatus parent(const ooHandle(ooBTree) &) = 0; 




ooHandle(ooBTree) potentialParentOf(const void *) const; 
ooHandle(ooBTree) potentialParentOf(const ooHandle(ooObj) &) const; 


ooRef(ooBTree) previous() const; 
virtual ooStatus removeNode(ooHandle(ooBTree) &) = 0; 

virtual ooBoolean isLeaf() const; 
ooBoolean isFull() const; 

virtual ooStatus removeKeyValueAt(const ooInt32) const; 

virtual ooHandle(ooBTree) root() const; 


void removeFirst(); 

void removeLast(); 
int treeIndex(const ooHandle(ooBTree) &) const; 
inline virtual ooRef(ooUnsortedArray) values() const 
{ return 0; }

public: enum { fiftyFifty, leftPack, rightPack}; 

virtual ooRef(ooAdmin) &admin() const = 0; 

virtual void clear(); 
virtual void compact(); 


int depth() const; 


virtual ooRef(ooObj) first() const; 


virtual ooRef(ooObj) get(const void *) const = 0; 

ooRef(ooObj) get(const ooInt32) const; 


inline virtual ooBoolean contains(const void *obj) const 
{ return oocFalse; }
virtual ooBoolean contains(const ooHandle(ooObj) &) const; 



virtual int indexOf(const ooHandle(ooObj) &, const int = (0)) const; 
virtual ooBoolean isEmpty() const; 

virtual ooCollectionIterator *iterator() const; 


ooRef(ooObj) last() const; 



int lastIndexOf(const ooHandle(ooObj) &, const int) const; 



inline int lastIndexOf(const ooHandle(ooObj) &obj) const 
{ return this -> lastIndexOf (obj, this -> size () - 1); }


inline ooBoolean notEmpty() const 
{ return ! this -> isEmpty (); }

virtual ooStatus refresh(ooMode) const; 


virtual ooBoolean remove(const ooHandle(ooObj) &); 


virtual int size() const; 




ooHandle(ooBTree) potentialParentOf(jobject &, jobject &, JNIEnv *) const; 




ooHandle(ooBTree) potentialParentOf(smalltalk_callback) const; 
#ifndef OO_DDL_TRANSLATION
    virtual ooTypeNumber ooGetTypeN() const;
    virtual char* ooGetTypeName() const;
    ooBoolean ooIsKindOf(ooTypeNumber oo_typeN) const;
    ooHandle(ooBTree)& ooThis(ooHandle(ooBTree)& objH,
			 ooMode aMode = oocNoOpen) const
      {
	return *ooReinterpretCast(ooHandle(ooBTree) *, &(this->ooObj::ooThis(objH, aMode)));
      }
    ooHandle(ooBTree) ooThis(ooMode aMode = oocNoOpen) const;
    void *operator new(size_t);
    void *operator new(size_t, const ooHandle(ooObj) &nearH);
    void *operator new(size_t, const ooHandle(ooObj) &nearH, ooClusterStrategy& strategy)
	{
		return strategy.newObj(ooTypeN(ooBTree), nearH);
	}
    void *operator new(size_t, const ooId& nearR, ooClusterStrategy& strategy)
	{
		return strategy.newObj(ooTypeN(ooBTree), nearR);
	}
    void *operator new(size_t, ooClusterStrategy& strategy)
	{
		return strategy.newObj(ooTypeN(ooBTree));
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
    ooRef(ooBTree)& ooThis(ooRef(ooBTree)& objId, ooMode aMode = oocNoOpen) const;
    ooBTree(ooInternalObj iobj);
    ooBTree() {}
#endif /* !defined(OO_DDL_TRANSLATION) */
}; 


class CO_STORAGE_SPECIFIER ooBTreeNode : public ooBTree { 

friend class ooBTree; 

protected: ooRef(ooBTree) _parent; 
virtual ooHandle(ooBTree) childOf(const ooHandle(ooBTree) &) const; 

virtual ooStatus full(const int = (ooBTree::fiftyFifty)); 
virtual ooBoolean isLeaf() const; 
virtual ooStatus newLow(ooHandle(ooBTree) &); 

virtual ooHandle(ooBTree) parent() const; 
virtual ooStatus parent(const ooHandle(ooBTree) &); 

virtual ooStatus removeNode(ooHandle(ooBTree) &); 
virtual ooHandle(ooBTree) root() const; 

public: virtual ~ooBTreeNode(); 
inline ooBTreeNode() 
{ _parent = 0; _children = 0; }
ooBTreeNode(ooHandle(ooBTree) &); 
inline virtual ooRef(ooAdmin) &admin() const 
{ return _parent -> admin (); }
virtual ooBoolean add(const ooHandle(ooObj) &); 
inline virtual const ooRef(ooCompare) comparator() const 
{ return _parent -> comparator (); }

inline virtual ooRef(ooObj) get(const void *key) const 
{ return _parent -> get (key); }
#ifndef OO_DDL_TRANSLATION
    virtual ooTypeNumber ooGetTypeN() const;
    virtual char* ooGetTypeName() const;
    ooBoolean ooIsKindOf(ooTypeNumber oo_typeN) const;
    ooHandle(ooBTreeNode)& ooThis(ooHandle(ooBTreeNode)& objH,
			 ooMode aMode = oocNoOpen) const
      {
	return *ooReinterpretCast(ooHandle(ooBTreeNode) *, &(this->ooObj::ooThis(objH, aMode)));
      }
    ooHandle(ooBTreeNode) ooThis(ooMode aMode = oocNoOpen) const;
    void *operator new(size_t);
    void *operator new(size_t, const ooHandle(ooObj) &nearH);
    void *operator new(size_t, const ooHandle(ooObj) &nearH, ooClusterStrategy& strategy)
	{
		return strategy.newObj(ooTypeN(ooBTreeNode), nearH);
	}
    void *operator new(size_t, const ooId& nearR, ooClusterStrategy& strategy)
	{
		return strategy.newObj(ooTypeN(ooBTreeNode), nearR);
	}
    void *operator new(size_t, ooClusterStrategy& strategy)
	{
		return strategy.newObj(ooTypeN(ooBTreeNode));
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
    ooRef(ooBTreeNode)& ooThis(ooRef(ooBTreeNode)& objId, ooMode aMode = oocNoOpen) const;
    ooBTreeNode(ooInternalObj iobj);
#endif /* !defined(OO_DDL_TRANSLATION) */




}; 


class CO_STORAGE_SPECIFIER ooTreeIterator : public ooCollectionIterator { 


protected: ooHandle(ooBTree) _bTree; 
ooInt32 _index; 
ooHandle(ooUnsortedArray) childrenH; 
ooHandle(ooSortedArray) childrenSortedH; 
virtual ooRef(ooObj) &currentP(ooBoolean = (oocFalse)); 

public: ooTreeIterator(ooHandle(ooBTree) &); 
inline virtual ~ooTreeIterator() 
{ _bTree = 0; }
virtual ooHandle(ooCollection) collection(); 
virtual ooRef(ooObj) current(); 
virtual int currentIndex(); 
virtual ooBoolean goTo(const void *, ooBoolean = (oocTrue)); 
virtual ooBoolean goTo(const ooHandle(ooObj) &); 
virtual ooRef(ooObj) goToIndex(int); 
virtual ooRef(ooObj) next(); 
virtual ooBoolean hasNext(); 
virtual ooBoolean hasPrevious(); 
virtual ooStatus moveCurrentTo(const ooHandle(ooObj) &); 
virtual ooRef(ooObj) previous(); 
virtual ooStatus remove(); 
virtual void reset(); 



virtual ooBoolean goTo(const ooUInt32, smalltalk_callback); 


ooBoolean goTo(jobject &, jobject &, JNIEnv *); 
}; 

class CO_STORAGE_SPECIFIER ooTreeListIterator : public ooTreeIterator { 


public: ooTreeListIterator(ooHandle(ooTreeList) &); 

virtual ooBoolean goTo(const ooHandle(ooObj) &); 
inline virtual ooBoolean goTo(const void *obj, ooBoolean mayHaveDublicateMatches = (oocTrue)) 
{ return goTo ((const ooHandle(ooObj) &) obj, mayHaveDublicateMatches); }
virtual ooStatus moveCurrentTo(const ooHandle(ooObj) &); 

virtual ooStatus set(const ooHandle(ooObj) &); 


inline virtual ooBoolean goTo(const ooUInt32, smalltalk_callback) 
{ return oocFalse; }
}; 

class CO_STORAGE_SPECIFIER ooTreeMapValueIterator : public ooTreeIterator { 


protected: virtual ooRef(ooObj) &currentP(ooBoolean = (oocFalse)); 

public: ooTreeMapValueIterator(ooHandle(ooTreeMap) &); 
virtual ooRef(ooObj) current(); 
virtual ooBoolean goTo(const ooHandle(ooObj) &); 
inline virtual ooBoolean goTo(const void *obj, ooBoolean mayHaveDublicateMatches = (oocTrue)) 
{ return goTo ((const ooHandle(ooObj) &) obj, mayHaveDublicateMatches); }
virtual ooRef(ooObj) next(); 
virtual ooRef(ooObj) previous(); 
virtual ooStatus set(const ooHandle(ooObj) &); 

inline virtual ooBoolean goTo(const ooUInt32 i, smalltalk_callback c) 
{ return ooTreeIterator :: goTo (i, c); }

inline ooBoolean goTo(jobject &jobj, jobject &tree, JNIEnv *env) 
{ return ooTreeIterator :: goTo (jobj, tree, env); }
}; 

class CO_STORAGE_SPECIFIER ooTreeMapKeyIterator : public ooTreeIterator { 


public: ooTreeMapKeyIterator(ooHandle(ooTreeMap) &); 
virtual ooRef(ooObj) currentValue(); 
}; 

class CO_STORAGE_SPECIFIER ooTreeSet : public ooBTree { 


protected: ooRef(ooTreeAdmin) _admin; 
ooRef(ooCompare) _compare; 
virtual ooStatus newLow(ooHandle(ooBTree) &); 

inline virtual ooHandle(ooBTree) parent() const 
{ return 0; }
inline virtual ooStatus parent(const ooHandle(ooBTree) &obj) 
{ return ((ooStatus) 0); }

virtual ooStatus removeNode(ooHandle(ooBTree) &); 

public: virtual ~ooTreeSet(); 

ooTreeSet(int = (0), ooHandle(ooContObj) = ooHandle(ooContObj)((0)), ooHandle(ooContObj) = ooHandle(ooContObj)((0))); 

ooTreeSet(ooHandle(ooCompare) &, int = (0), ooHandle(ooContObj) = ooHandle(ooContObj)((0)), ooHandle(ooContObj) = ooHandle(ooContObj)((0))); 


virtual ooBoolean add(const ooHandle(ooObj) &, const int); 
inline virtual ooBoolean add(const ooHandle(ooObj) &obj) 
{ return add (obj, fiftyFifty); }
inline virtual ooRef(ooAdmin) &admin() const 
{ return (ooRef(ooAdmin) &) _admin; }
inline virtual const ooRef(ooCompare) comparator() const 
{ return _compare; }
virtual ooBoolean contains(const void *) const; 
virtual ooBoolean contains(const ooHandle(ooObj) &) const; 

inline ooRef(ooObj) get(const ooInt32 index) const 
{ return ooBTree :: get (index); }
virtual ooRef(ooObj) get(const void *) const; 
virtual ooBoolean remove(const ooHandle(ooObj) &); 
virtual ooBoolean remove(const void *); 


ooBoolean add(const ooHandle(ooObj) &, jobject &, jobject &, JNIEnv *); 
ooBoolean contains(jobject &, jobject &, JNIEnv *); 
virtual ooRef(ooObj) get(jobject &, jobject &, JNIEnv *) const; 
virtual ooBoolean remove(jobject &, jobject &, JNIEnv *); 


ooBoolean add(const ooHandle(ooObj) &, smalltalk_callback); 
ooBoolean contains(smalltalk_callback) const; 
virtual ooRef(ooObj) get(smalltalk_callback) const; 
ooBoolean remove(smalltalk_callback); 
#ifndef OO_DDL_TRANSLATION
    virtual ooTypeNumber ooGetTypeN() const;
    virtual char* ooGetTypeName() const;
    ooBoolean ooIsKindOf(ooTypeNumber oo_typeN) const;
    ooHandle(ooTreeSet)& ooThis(ooHandle(ooTreeSet)& objH,
			 ooMode aMode = oocNoOpen) const
      {
	return *ooReinterpretCast(ooHandle(ooTreeSet) *, &(this->ooObj::ooThis(objH, aMode)));
      }
    ooHandle(ooTreeSet) ooThis(ooMode aMode = oocNoOpen) const;
    void *operator new(size_t);
    void *operator new(size_t, const ooHandle(ooObj) &nearH);
    void *operator new(size_t, const ooHandle(ooObj) &nearH, ooClusterStrategy& strategy)
	{
		return strategy.newObj(ooTypeN(ooTreeSet), nearH);
	}
    void *operator new(size_t, const ooId& nearR, ooClusterStrategy& strategy)
	{
		return strategy.newObj(ooTypeN(ooTreeSet), nearR);
	}
    void *operator new(size_t, ooClusterStrategy& strategy)
	{
		return strategy.newObj(ooTypeN(ooTreeSet));
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
    ooRef(ooTreeSet)& ooThis(ooRef(ooTreeSet)& objId, ooMode aMode = oocNoOpen) const;
    ooTreeSet(ooInternalObj iobj);
#endif /* !defined(OO_DDL_TRANSLATION) */
}; 


class CO_STORAGE_SPECIFIER ooTreeList : public ooBTree { 


protected: ooRef(ooTreeAdmin) _admin; 
virtual ooStatus first(const ooHandle(ooObj) &); 
virtual ooStatus full(const int = (ooBTree::fiftyFifty)); 
virtual ooBoolean isLeaf() const; 
virtual ooStatus newLow(ooHandle(ooBTree) &); 
inline virtual ooHandle(ooBTree) parent() const 
{ return 0; }
inline virtual ooStatus parent(const ooHandle(ooBTree) &obj) 
{ return ((ooStatus) 0); }

virtual ooStatus removeNode(ooHandle(ooBTree) &); 

public: virtual ~ooTreeList(); 

ooTreeList(int = (0), ooHandle(ooContObj) = ooHandle(ooContObj)((0)), ooHandle(ooContObj) = ooHandle(ooContObj)((0))); 


inline ooBoolean add(const ooHandle(ooObj) &obj, const int packHint) 
{ return addLast (obj, packHint) != ((ooStatus) 0); }
ooStatus addFirst(const ooHandle(ooObj) &, const int = (ooBTree::rightPack)); 
inline virtual ooBoolean add(const ooHandle(ooObj) &obj) 
{ return addLast (obj) != ((ooStatus) 0); }

ooStatus add(const ooInt32, const ooHandle(ooObj) &); 
virtual ooBoolean addAll(const ooHandle(ooCollection) &); 
ooStatus addAll(int, ooHandle(ooCollection) &); 
ooStatus addLast(const ooHandle(ooObj) &, const int = (ooBTree::leftPack)); 
inline virtual ooRef(ooAdmin) &admin() const 
{ return (ooRef(ooAdmin) &) _admin; }

virtual void clear(); 

inline virtual const ooRef(ooCompare) comparator() const { return 0; }
virtual ooBoolean contains(const ooHandle(ooObj) &) const; 
inline virtual ooBoolean contains(const void *obj) const 
{ return contains ((const ooHandle(ooObj) &) obj); }


virtual ooRef(ooObj) first() const; 
inline ooRef(ooObj) get(const ooInt32 index) const 
{ return ooBTree :: get (index); }
inline virtual ooRef(ooObj) get(const void *key) const 
{ return 0; }
virtual ooCollectionIterator *iterator() const; 
virtual ooBoolean remove(const ooHandle(ooObj) &); 
virtual void removeAllDeleted(); 
ooStatus removeRange(int, int); 
ooStatus set(const int, const ooHandle(ooObj) &); 


inline ooBoolean add(const ooHandle(ooObj) &obj, smalltalk_callback) 
{ return oocFalse; }
#ifndef OO_DDL_TRANSLATION
    virtual ooTypeNumber ooGetTypeN() const;
    virtual char* ooGetTypeName() const;
    ooBoolean ooIsKindOf(ooTypeNumber oo_typeN) const;
    ooHandle(ooTreeList)& ooThis(ooHandle(ooTreeList)& objH,
			 ooMode aMode = oocNoOpen) const
      {
	return *ooReinterpretCast(ooHandle(ooTreeList) *, &(this->ooObj::ooThis(objH, aMode)));
      }
    ooHandle(ooTreeList) ooThis(ooMode aMode = oocNoOpen) const;
    void *operator new(size_t);
    void *operator new(size_t, const ooHandle(ooObj) &nearH);
    void *operator new(size_t, const ooHandle(ooObj) &nearH, ooClusterStrategy& strategy)
	{
		return strategy.newObj(ooTypeN(ooTreeList), nearH);
	}
    void *operator new(size_t, const ooId& nearR, ooClusterStrategy& strategy)
	{
		return strategy.newObj(ooTypeN(ooTreeList), nearR);
	}
    void *operator new(size_t, ooClusterStrategy& strategy)
	{
		return strategy.newObj(ooTypeN(ooTreeList));
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
    ooRef(ooTreeList)& ooThis(ooRef(ooTreeList)& objId, ooMode aMode = oocNoOpen) const;
    ooTreeList(ooInternalObj iobj);
#endif /* !defined(OO_DDL_TRANSLATION) */
}; 


class CO_STORAGE_SPECIFIER ooTreeListNode : public ooBTree { 

friend class ooTreeList; 

protected: ooRef(ooBTree) _parent; 
virtual ooHandle(ooBTree) childOf(const ooHandle(ooBTree) &) const; 
virtual ooBoolean isLeaf() const; 

virtual ooRef(ooObj) first() const; 
virtual ooStatus first(const ooHandle(ooObj) &); 
virtual ooStatus full(const int = (ooBTree::fiftyFifty)); 
virtual ooStatus newLow(ooHandle(ooBTree) &); 


virtual ooHandle(ooBTree) parent() const; 
virtual ooStatus parent(const ooHandle(ooBTree) &); 
virtual ooStatus removeNode(ooHandle(ooBTree) &); 
virtual ooHandle(ooBTree) root() const; 

public: virtual ~ooTreeListNode(); 
ooTreeListNode(ooHandle(ooBTree) &); 
virtual ooBoolean add(const ooHandle(ooObj) &); 
inline virtual ooRef(ooAdmin) &admin() const 
{ return _parent -> admin (); }

inline virtual const ooRef(ooCompare) comparator() const { return 0; }
inline virtual ooRef(ooObj) get(const void *key) const 
{ return 0; }
#ifndef OO_DDL_TRANSLATION
    virtual ooTypeNumber ooGetTypeN() const;
    virtual char* ooGetTypeName() const;
    ooBoolean ooIsKindOf(ooTypeNumber oo_typeN) const;
    ooHandle(ooTreeListNode)& ooThis(ooHandle(ooTreeListNode)& objH,
			 ooMode aMode = oocNoOpen) const
      {
	return *ooReinterpretCast(ooHandle(ooTreeListNode) *, &(this->ooObj::ooThis(objH, aMode)));
      }
    ooHandle(ooTreeListNode) ooThis(ooMode aMode = oocNoOpen) const;
    void *operator new(size_t);
    void *operator new(size_t, const ooHandle(ooObj) &nearH);
    void *operator new(size_t, const ooHandle(ooObj) &nearH, ooClusterStrategy& strategy)
	{
		return strategy.newObj(ooTypeN(ooTreeListNode), nearH);
	}
    void *operator new(size_t, const ooId& nearR, ooClusterStrategy& strategy)
	{
		return strategy.newObj(ooTypeN(ooTreeListNode), nearR);
	}
    void *operator new(size_t, ooClusterStrategy& strategy)
	{
		return strategy.newObj(ooTypeN(ooTreeListNode));
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
    ooRef(ooTreeListNode)& ooThis(ooRef(ooTreeListNode)& objId, ooMode aMode = oocNoOpen) const;
    ooTreeListNode(ooInternalObj iobj);
#endif /* !defined(OO_DDL_TRANSLATION) */


}; 


class CO_STORAGE_SPECIFIER ooTreeMap : public ooTreeSet { 

friend class ooTreeMapNode; 
friend class ooTreeMapValueIterator; 

protected: ooRef(ooUnsortedArray) _values; 
virtual ooStatus full(const int = (ooBTree::fiftyFifty)); 

virtual ooStatus removeKeyValueAt(const ooInt32) const; 
inline virtual ooRef(ooUnsortedArray) values() const 
{ return _values; }


public: virtual ~ooTreeMap(); 

ooTreeMap(int = (0), ooHandle(ooContObj) = ooHandle(ooContObj)((0)), ooHandle(ooContObj) = ooHandle(ooContObj)((0))); 

ooTreeMap(ooHandle(ooCompare) &, int = (0), ooHandle(ooContObj) = ooHandle(ooContObj)((0)), ooHandle(ooContObj) = ooHandle(ooContObj)((0))); 


virtual ooBoolean add(const ooHandle(ooObj) &, const int); 
inline virtual ooBoolean add(const ooHandle(ooObj) &obj) 
{ return add (obj, fiftyFifty); }

virtual ooBoolean addAll(const ooHandle(ooCollection) &); 


virtual void compact(); 


inline ooBoolean containsKey(const void *key) 
{ return contains (key); }
inline ooBoolean containsKey(const ooHandle(ooObj) &key) 
{ return contains (key); }


ooBoolean containsValue(const ooHandle(ooObj) &) const; 


virtual ooRef(ooObj) get(const void *) const; 
ooRef(ooObj) get(const ooHandle(ooObj) &) const; 


ooStatus put(const ooHandle(ooObj) &, const ooHandle(ooObj) &, const int = (ooBTree::fiftyFifty)); 



virtual ooCollectionIterator *iterator() const; 



virtual ooCollectionIterator *valueIterator() const; 


virtual ooBoolean remove(const ooHandle(ooObj) &); 
virtual ooBoolean remove(const void *); 
virtual void removeAllDeleted(); 

virtual ooRef(ooObj) get(jobject &, jobject &, JNIEnv *) const; 
ooStatus put(const ooHandle(ooObj) &, const ooHandle(ooObj) &, jobject &, jobject &, JNIEnv *); 
virtual ooBoolean remove(jobject &, jobject &, JNIEnv *); 


virtual ooRef(ooObj) get(smalltalk_callback) const; 
ooStatus put(const ooHandle(ooObj) &, const ooHandle(ooObj) &, smalltalk_callback); 
ooBoolean remove(smalltalk_callback); 
#ifndef OO_DDL_TRANSLATION
    virtual ooTypeNumber ooGetTypeN() const;
    virtual char* ooGetTypeName() const;
    ooBoolean ooIsKindOf(ooTypeNumber oo_typeN) const;
    ooHandle(ooTreeMap)& ooThis(ooHandle(ooTreeMap)& objH,
			 ooMode aMode = oocNoOpen) const
      {
	return *ooReinterpretCast(ooHandle(ooTreeMap) *, &(this->ooObj::ooThis(objH, aMode)));
      }
    ooHandle(ooTreeMap) ooThis(ooMode aMode = oocNoOpen) const;
    void *operator new(size_t);
    void *operator new(size_t, const ooHandle(ooObj) &nearH);
    void *operator new(size_t, const ooHandle(ooObj) &nearH, ooClusterStrategy& strategy)
	{
		return strategy.newObj(ooTypeN(ooTreeMap), nearH);
	}
    void *operator new(size_t, const ooId& nearR, ooClusterStrategy& strategy)
	{
		return strategy.newObj(ooTypeN(ooTreeMap), nearR);
	}
    void *operator new(size_t, ooClusterStrategy& strategy)
	{
		return strategy.newObj(ooTypeN(ooTreeMap));
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
    ooRef(ooTreeMap)& ooThis(ooRef(ooTreeMap)& objId, ooMode aMode = oocNoOpen) const;
    ooTreeMap(ooInternalObj iobj);
#endif /* !defined(OO_DDL_TRANSLATION) */
}; 


class CO_STORAGE_SPECIFIER ooTreeMapNode : public ooBTree { 

friend class ooTreeMap; 

protected: ooRef(ooUnsortedArray) _values; 
ooRef(ooBTree) _parent; 
virtual ooHandle(ooBTree) childOf(const ooHandle(ooBTree) &) const; 
virtual ooStatus full(const int = (ooBTree::fiftyFifty)); 
virtual ooBoolean isLeaf() const; 
virtual ooStatus newLow(ooHandle(ooBTree) &); 

virtual ooHandle(ooBTree) parent() const; 
virtual ooStatus parent(const ooHandle(ooBTree) &); 


virtual ooStatus removeKeyValueAt(const ooInt32) const; 
virtual ooStatus removeNode(ooHandle(ooBTree) &); 
virtual ooHandle(ooBTree) root() const; 
inline virtual ooRef(ooUnsortedArray) values() const 
{ return _values; }

public: inline ooTreeMapNode() 
{ _parent = 0; _children = 0; }
virtual ~ooTreeMapNode(); 
ooTreeMapNode(ooHandle(ooBTree) &, ooBoolean); 
virtual ooBoolean add(const ooHandle(ooObj) &); 
inline virtual ooRef(ooAdmin) &admin() const 
{ return _parent -> admin (); }
inline virtual ooRef(ooObj) get(const void *key) const 
{ return _parent -> get (key); }
inline virtual const ooRef(ooCompare) comparator() const 
{ return _parent -> comparator (); }
virtual ooBoolean remove(const ooHandle(ooObj) &); 
#ifndef OO_DDL_TRANSLATION
    virtual ooTypeNumber ooGetTypeN() const;
    virtual char* ooGetTypeName() const;
    ooBoolean ooIsKindOf(ooTypeNumber oo_typeN) const;
    ooHandle(ooTreeMapNode)& ooThis(ooHandle(ooTreeMapNode)& objH,
			 ooMode aMode = oocNoOpen) const
      {
	return *ooReinterpretCast(ooHandle(ooTreeMapNode) *, &(this->ooObj::ooThis(objH, aMode)));
      }
    ooHandle(ooTreeMapNode) ooThis(ooMode aMode = oocNoOpen) const;
    void *operator new(size_t);
    void *operator new(size_t, const ooHandle(ooObj) &nearH);
    void *operator new(size_t, const ooHandle(ooObj) &nearH, ooClusterStrategy& strategy)
	{
		return strategy.newObj(ooTypeN(ooTreeMapNode), nearH);
	}
    void *operator new(size_t, const ooId& nearR, ooClusterStrategy& strategy)
	{
		return strategy.newObj(ooTypeN(ooTreeMapNode), nearR);
	}
    void *operator new(size_t, ooClusterStrategy& strategy)
	{
		return strategy.newObj(ooTypeN(ooTreeMapNode));
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
    ooRef(ooTreeMapNode)& ooThis(ooRef(ooTreeMapNode)& objId, ooMode aMode = oocNoOpen) const;
    ooTreeMapNode(ooInternalObj iobj);
#endif /* !defined(OO_DDL_TRANSLATION) */


}; 


class CO_STORAGE_SPECIFIER ooAdmin : public ooObj { 

friend class ooTreeSet; 
friend class ooTreeMapNode; 
friend class ooTreeListNode; 

protected: virtual ooBoolean inUse(const ooRef(ooContObj)) = 0; 
virtual ooHandle(ooContObj) newContainer(ooRef(ooContObj) &); 

public: inline virtual ~ooAdmin() { }
#ifndef OO_DDL_TRANSLATION
    virtual ooTypeNumber ooGetTypeN() const;
    virtual char* ooGetTypeName() const;
    ooBoolean ooIsKindOf(ooTypeNumber oo_typeN) const;
    ooHandle(ooAdmin)& ooThis(ooHandle(ooAdmin)& objH,
			 ooMode aMode = oocNoOpen) const
      {
	return *ooReinterpretCast(ooHandle(ooAdmin) *, &(this->ooObj::ooThis(objH, aMode)));
      }
    ooHandle(ooAdmin) ooThis(ooMode aMode = oocNoOpen) const;
    void *operator new(size_t);
    void *operator new(size_t, const ooHandle(ooObj) &nearH);
    void *operator new(size_t, const ooHandle(ooObj) &nearH, ooClusterStrategy& strategy)
	{
		return strategy.newObj(ooTypeN(ooAdmin), nearH);
	}
    void *operator new(size_t, const ooId& nearR, ooClusterStrategy& strategy)
	{
		return strategy.newObj(ooTypeN(ooAdmin), nearR);
	}
    void *operator new(size_t, ooClusterStrategy& strategy)
	{
		return strategy.newObj(ooTypeN(ooAdmin));
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
    ooRef(ooAdmin)& ooThis(ooRef(ooAdmin)& objId, ooMode aMode = oocNoOpen) const;
    ooAdmin(ooInternalObj iobj);
    ooAdmin() {}
#endif /* !defined(OO_DDL_TRANSLATION) */
}; 


class CO_STORAGE_SPECIFIER ooTreeAdmin : public ooAdmin { 

friend class ooBTree; 
friend class ooBTreeNode; 
friend class ooTreeList; 
friend class ooTreeListNode; 
friend class ooTreeMap; 
friend class ooTreeMapNode; 
friend class ooTreeSet; 

protected: ooRef(ooBTree) _tree; 
ooRef(ooContObj) _nodeContainer; 
ooRef(ooContObj) _vArrayContainer; 
ooInt32 _nodeCountContainer; 
ooInt32 _vArrayCountContainer; 
ooTreeAdmin(ooHandle(ooBTree) &); 
ooInt32 _maxNodesPerContainer; 
ooInt32 _maxVArraysPerContainer; 



int calculateAndSetNodeCountContainer(); 
int calculateAndSetVArrayCountContainer(); 
virtual ooRef(ooContObj) provideVArrayContainer(); 
virtual ooRef(ooContObj) provideNodeContainer(); 
inline virtual ooBoolean inUse(const ooRef(ooContObj) contR) 
{ return (contR == _nodeContainer || contR == _vArrayContainer); }

public: inline ooInt32 maxNodesPerContainer() 
{ return _maxNodesPerContainer; }
void nodeContainer(ooHandle(ooContObj) &, int = (0)); 
inline void setMaxNodesPerContainer(ooInt32 max) 
{ ooUpdate (); _maxNodesPerContainer = max; }
inline ooInt32 maxVArraysPerContainer() 
{ return _maxVArraysPerContainer; }
inline void setMaxVArraysPerContainer(ooInt32 max) 
{ ooUpdate (); _maxVArraysPerContainer = max; }
inline ooRef(ooContObj) nodeContainer() 
{ return _nodeContainer; }
inline ooRef(ooContObj) vArrayContainer() 
{ return _vArrayContainer; }
void vArrayContainer(ooHandle(ooContObj) &, int = (0)); 
#ifndef OO_DDL_TRANSLATION
    virtual ooTypeNumber ooGetTypeN() const;
    virtual char* ooGetTypeName() const;
    ooBoolean ooIsKindOf(ooTypeNumber oo_typeN) const;
    ooHandle(ooTreeAdmin)& ooThis(ooHandle(ooTreeAdmin)& objH,
			 ooMode aMode = oocNoOpen) const
      {
	return *ooReinterpretCast(ooHandle(ooTreeAdmin) *, &(this->ooObj::ooThis(objH, aMode)));
      }
    ooHandle(ooTreeAdmin) ooThis(ooMode aMode = oocNoOpen) const;
    void *operator new(size_t);
    void *operator new(size_t, const ooHandle(ooObj) &nearH);
    void *operator new(size_t, const ooHandle(ooObj) &nearH, ooClusterStrategy& strategy)
	{
		return strategy.newObj(ooTypeN(ooTreeAdmin), nearH);
	}
    void *operator new(size_t, const ooId& nearR, ooClusterStrategy& strategy)
	{
		return strategy.newObj(ooTypeN(ooTreeAdmin), nearR);
	}
    void *operator new(size_t, ooClusterStrategy& strategy)
	{
		return strategy.newObj(ooTypeN(ooTreeAdmin));
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
    ooRef(ooTreeAdmin)& ooThis(ooRef(ooTreeAdmin)& objId, ooMode aMode = oocNoOpen) const;
    ooTreeAdmin(ooInternalObj iobj);
#endif /* !defined(OO_DDL_TRANSLATION) */
}; 



class CO_STORAGE_SPECIFIER ooHashSet; 
class CO_STORAGE_SPECIFIER ooHashMap; 
class CO_STORAGE_SPECIFIER ooHashIterator; 
class CO_STORAGE_SPECIFIER ooHashMapIterator; 
class CO_STORAGE_SPECIFIER ooHashMapValueIterator; 

class CO_STORAGE_SPECIFIER ooHashMapEntry : public ooObj { 

friend class ooHashMap; 
friend class ooHashMapIterator; 
friend class ooHashMapValueIterator; 

protected: ooRef(ooObj) _key; 
ooRef(ooObj) _value; 

public: inline ooHashMapEntry(ooRef(ooObj) key, ooRef(ooObj) value) 
{ _key = key; _value = value; }

inline ooRef(ooObj) &key() 
{ return _key; }

inline ooRef(ooObj) &value() 
{ return _value; }

inline void value(ooRef(ooObj) value) 
{ _value = value; }
#ifndef OO_DDL_TRANSLATION
    virtual ooTypeNumber ooGetTypeN() const;
    virtual char* ooGetTypeName() const;
    ooBoolean ooIsKindOf(ooTypeNumber oo_typeN) const;
    ooHandle(ooHashMapEntry)& ooThis(ooHandle(ooHashMapEntry)& objH,
			 ooMode aMode = oocNoOpen) const
      {
	return *ooReinterpretCast(ooHandle(ooHashMapEntry) *, &(this->ooObj::ooThis(objH, aMode)));
      }
    ooHandle(ooHashMapEntry) ooThis(ooMode aMode = oocNoOpen) const;
    void *operator new(size_t);
    void *operator new(size_t, const ooHandle(ooObj) &nearH);
    void *operator new(size_t, const ooHandle(ooObj) &nearH, ooClusterStrategy& strategy)
	{
		return strategy.newObj(ooTypeN(ooHashMapEntry), nearH);
	}
    void *operator new(size_t, const ooId& nearR, ooClusterStrategy& strategy)
	{
		return strategy.newObj(ooTypeN(ooHashMapEntry), nearR);
	}
    void *operator new(size_t, ooClusterStrategy& strategy)
	{
		return strategy.newObj(ooTypeN(ooHashMapEntry));
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
    ooRef(ooHashMapEntry)& ooThis(ooRef(ooHashMapEntry)& objId, ooMode aMode = oocNoOpen) const;
    ooHashMapEntry(ooInternalObj iobj);
#endif /* !defined(OO_DDL_TRANSLATION) */
}; 


class CO_STORAGE_SPECIFIER ooHashAdmin : public ooAdmin { 

friend class ooHashSet; 
friend class ooHashMap; 

protected: ooRef(ooHashSet) _coll; 
ooRef(ooContObj) _bucketContainer; 
ooInt32 _bucketCountContainer; 
ooInt32 _maxBucketsPerContainer; 
ooHashAdmin(ooHandle(ooHashSet) &); 
virtual ooStatus deleteBucket(ooHandle(ooContObj) &); 
virtual ooRef(ooContObj) provideBucketContainer(); 
inline virtual ooBoolean inUse(const ooRef(ooContObj) contR) 
{ return contR == _bucketContainer; }

public: inline ooRef(ooContObj) bucketContainer() 
{ return _bucketContainer; }
void bucketContainer(ooHandle(ooContObj) &, int = (0)); 
inline ooInt32 maxBucketsPerContainer() 
{ return _maxBucketsPerContainer; }
inline void setMaxBucketsPerContainer(ooInt32 max) 
{ ooUpdate (); _maxBucketsPerContainer = max; }
#ifndef OO_DDL_TRANSLATION
    virtual ooTypeNumber ooGetTypeN() const;
    virtual char* ooGetTypeName() const;
    ooBoolean ooIsKindOf(ooTypeNumber oo_typeN) const;
    ooHandle(ooHashAdmin)& ooThis(ooHandle(ooHashAdmin)& objH,
			 ooMode aMode = oocNoOpen) const
      {
	return *ooReinterpretCast(ooHandle(ooHashAdmin) *, &(this->ooObj::ooThis(objH, aMode)));
      }
    ooHandle(ooHashAdmin) ooThis(ooMode aMode = oocNoOpen) const;
    void *operator new(size_t);
    void *operator new(size_t, const ooHandle(ooObj) &nearH);
    void *operator new(size_t, const ooHandle(ooObj) &nearH, ooClusterStrategy& strategy)
	{
		return strategy.newObj(ooTypeN(ooHashAdmin), nearH);
	}
    void *operator new(size_t, const ooId& nearR, ooClusterStrategy& strategy)
	{
		return strategy.newObj(ooTypeN(ooHashAdmin), nearR);
	}
    void *operator new(size_t, ooClusterStrategy& strategy)
	{
		return strategy.newObj(ooTypeN(ooHashAdmin));
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
    ooRef(ooHashAdmin)& ooThis(ooRef(ooHashAdmin)& objId, ooMode aMode = oocNoOpen) const;
    ooHashAdmin(ooInternalObj iobj);
#endif /* !defined(OO_DDL_TRANSLATION) */
}; 


class CO_STORAGE_SPECIFIER ooHashChain : public ooObj { 


public: ooVArray(ooRef(ooObj)) _array; 
ooHashChain(const ooHandle(ooObj) &, const ooHandle(ooObj) &); 
#ifndef OO_DDL_TRANSLATION
    virtual ooTypeNumber ooGetTypeN() const;
    virtual char* ooGetTypeName() const;
    ooBoolean ooIsKindOf(ooTypeNumber oo_typeN) const;
    ooHandle(ooHashChain)& ooThis(ooHandle(ooHashChain)& objH,
			 ooMode aMode = oocNoOpen) const
      {
	return *ooReinterpretCast(ooHandle(ooHashChain) *, &(this->ooObj::ooThis(objH, aMode)));
      }
    ooHandle(ooHashChain) ooThis(ooMode aMode = oocNoOpen) const;
    void *operator new(size_t);
    void *operator new(size_t, const ooHandle(ooObj) &nearH);
    void *operator new(size_t, const ooHandle(ooObj) &nearH, ooClusterStrategy& strategy)
	{
		return strategy.newObj(ooTypeN(ooHashChain), nearH);
	}
    void *operator new(size_t, const ooId& nearR, ooClusterStrategy& strategy)
	{
		return strategy.newObj(ooTypeN(ooHashChain), nearR);
	}
    void *operator new(size_t, ooClusterStrategy& strategy)
	{
		return strategy.newObj(ooTypeN(ooHashChain));
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
    ooRef(ooHashChain)& ooThis(ooRef(ooHashChain)& objId, ooMode aMode = oocNoOpen) const;
    ooHashChain(ooInternalObj iobj);
#endif /* !defined(OO_DDL_TRANSLATION) */
}; 


class CO_STORAGE_SPECIFIER ooHashBucket : public ooObj { 


public: ooInt32 _depth; 
ooInt32 _chainedSize; 
ooInt32 _unchainedSize; 
ooVArray(ooRef(ooObj)) _array; 
ooHashBucket(int, int); 
inline int size() 
{ return _chainedSize + _unchainedSize; }
#ifndef OO_DDL_TRANSLATION
    virtual ooTypeNumber ooGetTypeN() const;
    virtual char* ooGetTypeName() const;
    ooBoolean ooIsKindOf(ooTypeNumber oo_typeN) const;
    ooHandle(ooHashBucket)& ooThis(ooHandle(ooHashBucket)& objH,
			 ooMode aMode = oocNoOpen) const
      {
	return *ooReinterpretCast(ooHandle(ooHashBucket) *, &(this->ooObj::ooThis(objH, aMode)));
      }
    ooHandle(ooHashBucket) ooThis(ooMode aMode = oocNoOpen) const;
    void *operator new(size_t);
    void *operator new(size_t, const ooHandle(ooObj) &nearH);
    void *operator new(size_t, const ooHandle(ooObj) &nearH, ooClusterStrategy& strategy)
	{
		return strategy.newObj(ooTypeN(ooHashBucket), nearH);
	}
    void *operator new(size_t, const ooId& nearR, ooClusterStrategy& strategy)
	{
		return strategy.newObj(ooTypeN(ooHashBucket), nearR);
	}
    void *operator new(size_t, ooClusterStrategy& strategy)
	{
		return strategy.newObj(ooTypeN(ooHashBucket));
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
    ooRef(ooHashBucket)& ooThis(ooRef(ooHashBucket)& objId, ooMode aMode = oocNoOpen) const;
    ooHashBucket(ooInternalObj iobj);
#endif /* !defined(OO_DDL_TRANSLATION) */
}; 




class CO_STORAGE_SPECIFIER ooHashSet : public ooCollection { 

friend class ooHashIterator; 
friend class ooHashMapIterator; 

protected: ooRef(ooHashAdmin) _admin; 
ooRef(ooCompare) _compare; 
ooInt32 _bucketCapacity; 
ooInt32 _depth; 
ooVArray(ooRef(ooHashBucket)) _array; 
virtual ooBoolean rehash(const ooHandle(ooObj) &, const ooUInt32); 

public: static int bucketSizeSelection(int, int); 
ooStatus expandDirectory(); 

ooHashSet(int = (30011), int = (1), ooHandle(ooContObj) = ooHandle(ooContObj)((0)), ooHandle(ooContObj) = ooHandle(ooContObj)((0))); 

ooHashSet(ooHandle(ooCompare) &, int = (30011), int = (1), ooHandle(ooContObj) = ooHandle(ooContObj)((0)), ooHandle(ooContObj) = ooHandle(ooContObj)((0))); 


virtual ~ooHashSet(); 


virtual ooBoolean add(const ooHandle(ooObj) &); 
inline ooRef(ooAdmin) &admin() const 
{ return (ooRef(ooAdmin) &) _admin; }

virtual void clear(); 
inline virtual const ooRef(ooCompare) comparator() const 
{ return _compare; }


virtual ooBoolean contains(const void *) const; 
virtual ooBoolean contains(const ooHandle(ooObj) &) const; 

virtual ooRef(ooObj) get(const void *) const; 


int hashOf(const ooHandle(ooObj) &) const; 

virtual ooBoolean isEmpty() const; 


virtual ooCollectionIterator *iterator() const; 

virtual ooStatus refresh(ooMode) const; 


virtual ooBoolean remove(const ooHandle(ooObj) &); 


virtual int size() const; 
void statistics(); 


ooBoolean add(const ooHandle(ooObj) &, jobject &, jobject &, JNIEnv *); 
virtual ooRef(ooObj) get(const ooUInt32, jobject &, jobject &, JNIEnv *) const; 
virtual ooBoolean contains(const ooUInt32, jobject &, jobject &, JNIEnv *) const; 
virtual ooBoolean remove(jobject &, jobject &, JNIEnv *); 


ooBoolean add(const ooHandle(ooObj) &, const ooUInt32, smalltalk_callback, smalltalk_callback); 
virtual ooBoolean contains(const ooUInt32, smalltalk_callback) const; 
virtual ooRef(ooObj) get(const ooUInt32, smalltalk_callback) const; 
ooBoolean remove(const ooUInt32, smalltalk_callback); 
#ifndef OO_DDL_TRANSLATION
    virtual ooTypeNumber ooGetTypeN() const;
    virtual char* ooGetTypeName() const;
    ooBoolean ooIsKindOf(ooTypeNumber oo_typeN) const;
    ooHandle(ooHashSet)& ooThis(ooHandle(ooHashSet)& objH,
			 ooMode aMode = oocNoOpen) const
      {
	return *ooReinterpretCast(ooHandle(ooHashSet) *, &(this->ooObj::ooThis(objH, aMode)));
      }
    ooHandle(ooHashSet) ooThis(ooMode aMode = oocNoOpen) const;
    void *operator new(size_t);
    void *operator new(size_t, const ooHandle(ooObj) &nearH);
    void *operator new(size_t, const ooHandle(ooObj) &nearH, ooClusterStrategy& strategy)
	{
		return strategy.newObj(ooTypeN(ooHashSet), nearH);
	}
    void *operator new(size_t, const ooId& nearR, ooClusterStrategy& strategy)
	{
		return strategy.newObj(ooTypeN(ooHashSet), nearR);
	}
    void *operator new(size_t, ooClusterStrategy& strategy)
	{
		return strategy.newObj(ooTypeN(ooHashSet));
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
    ooRef(ooHashSet)& ooThis(ooRef(ooHashSet)& objId, ooMode aMode = oocNoOpen) const;
    ooHashSet(ooInternalObj iobj);
#endif /* !defined(OO_DDL_TRANSLATION) */
}; 


class CO_STORAGE_SPECIFIER ooHashMap : public ooHashSet { 

friend class ooHashIterator; 

protected: enum { error, success, tryAgain}; 
ooHandle(ooHashMapEntry) entry(const void *) const; 
ooHandle(ooHashMapEntry) entry(const ooHandle(ooObj) &) const; 
int addNewEntry(const ooHandle(ooObj) &, const ooHandle(ooObj) &, ooHandle(ooHashBucket) &, const ooUInt32); 
virtual ooBoolean rehash(const ooHandle(ooObj) &, const ooUInt32); 

ooBoolean addNewEntry(const ooHandle(ooObj) &, const ooHandle(ooObj) &, ooHandle(ooHashBucket) &, const ooUInt32, jobject &, jobject &, JNIEnv *); 


ooBoolean addNewEntry(const ooHandle(ooObj) &, const ooHandle(ooObj) &, ooHandle(ooHashBucket) &, const ooUInt32, smalltalk_callback, smalltalk_callback); 


public: ooHashMap(int = (30011), int = (1), ooHandle(ooContObj) = ooHandle(ooContObj)((0)), ooHandle(ooContObj) = ooHandle(ooContObj)((0))); 

ooHashMap(ooHandle(ooCompare) &, int = (30011), int = (1), ooHandle(ooContObj) = ooHandle(ooContObj)((0)), ooHandle(ooContObj) = ooHandle(ooContObj)((0))); 


virtual ~ooHashMap(); 

virtual ooBoolean add(const ooHandle(ooObj) &); 
virtual ooBoolean addAll(const ooHandle(ooCollection) &); 

virtual ooBoolean contains(const void *) const; 
virtual ooBoolean contains(const ooHandle(ooObj) &) const; 


ooBoolean containsKey(const void *) const; 
ooBoolean containsKey(const ooHandle(ooObj) &) const; 


ooBoolean containsValue(const ooHandle(ooObj) &) const; 


virtual ooRef(ooObj) get(const void *) const; 
ooRef(ooObj) get(const ooHandle(ooObj) &) const; 
virtual ooCollectionIterator *iterator() const; 
virtual ooCollectionIterator *keyIterator() const; 


ooStatus put(const ooHandle(ooObj) &, const ooHandle(ooObj) &); 


virtual ooBoolean remove(const ooHandle(ooObj) &); 
virtual void removeAllDeleted(); 
virtual ooCollectionIterator *valueIterator() const; 


virtual ooBoolean contains(const ooUInt32, jobject &, jobject &, JNIEnv *) const; 
ooHandle(ooHashMapEntry) entry(jobject &, jobject &, JNIEnv *) const; 
virtual ooRef(ooObj) get(const ooUInt32, jobject &, jobject &, JNIEnv *) const; 
ooStatus put(const ooHandle(ooObj) &, const ooHandle(ooObj) &, jobject &, jobject &, JNIEnv *); 

virtual ooBoolean remove(jobject &, jobject &, JNIEnv *); 



ooRef(ooObj) unbind(const ooHandle(ooObj) &); 
virtual ooBoolean contains(const ooUInt32, smalltalk_callback) const; 
ooHandle(ooHashMapEntry) entry(const ooUInt32, smalltalk_callback) const; 
virtual ooRef(ooObj) get(const ooUInt32, smalltalk_callback) const; 
ooStatus put(const ooHandle(ooObj) &, const ooHandle(ooObj) &, const ooUInt32, smalltalk_callback, smalltalk_callback); 

ooHandle(ooObj) unbind(const ooUInt32, smalltalk_callback); 
#ifndef OO_DDL_TRANSLATION
    virtual ooTypeNumber ooGetTypeN() const;
    virtual char* ooGetTypeName() const;
    ooBoolean ooIsKindOf(ooTypeNumber oo_typeN) const;
    ooHandle(ooHashMap)& ooThis(ooHandle(ooHashMap)& objH,
			 ooMode aMode = oocNoOpen) const
      {
	return *ooReinterpretCast(ooHandle(ooHashMap) *, &(this->ooObj::ooThis(objH, aMode)));
      }
    ooHandle(ooHashMap) ooThis(ooMode aMode = oocNoOpen) const;
    void *operator new(size_t);
    void *operator new(size_t, const ooHandle(ooObj) &nearH);
    void *operator new(size_t, const ooHandle(ooObj) &nearH, ooClusterStrategy& strategy)
	{
		return strategy.newObj(ooTypeN(ooHashMap), nearH);
	}
    void *operator new(size_t, const ooId& nearR, ooClusterStrategy& strategy)
	{
		return strategy.newObj(ooTypeN(ooHashMap), nearR);
	}
    void *operator new(size_t, ooClusterStrategy& strategy)
	{
		return strategy.newObj(ooTypeN(ooHashMap));
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
    ooRef(ooHashMap)& ooThis(ooRef(ooHashMap)& objId, ooMode aMode = oocNoOpen) const;
    ooHashMap(ooInternalObj iobj);
#endif /* !defined(OO_DDL_TRANSLATION) */
}; 


class CO_STORAGE_SPECIFIER ooHashIterator : public ooCollectionIterator { 


protected: ooHandle(ooHashSet) _hashSet; 
ooInt32 _dirPos; 
ooInt32 _bucketPos; 
ooInt32 _chainPos; 
virtual ooRef(ooObj) &currentP(ooBoolean = (oocFalse)); 
virtual void deleteEntry(ooRef(ooObj) &); 

public: ooHashIterator(const ooHandle(ooHashSet) &); 
virtual ooHandle(ooCollection) collection(); 
virtual ooRef(ooObj) current(); 
virtual int currentIndex(); 
virtual ooBoolean goTo(const void *, ooBoolean = (oocTrue)); 
virtual ooBoolean goTo(const ooHandle(ooObj) &); 
virtual ooRef(ooObj) goToIndex(int); 
virtual ooBoolean hasNext(); 
virtual ooRef(ooObj) next(); 
virtual ooRef(ooObj) previous(); 
virtual ooStatus moveCurrentTo(const ooHandle(ooObj) &); 
virtual ooStatus remove(); 
virtual void reset(); 


virtual ooBoolean goTo(const ooUInt32, smalltalk_callback); 

ooBoolean goTo(const ooUInt32, jobject &, jobject &, JNIEnv *); 
}; 

class CO_STORAGE_SPECIFIER ooHashMapIterator : public ooHashIterator { 

virtual void deleteEntry(ooRef(ooObj) &); 

public: ooHashMapIterator(const ooHandle(ooHashMap) &); 

}; 

class CO_STORAGE_SPECIFIER ooHashMapKeyIterator : public ooHashMapIterator { 


protected: virtual ooRef(ooObj) &currentP(ooBoolean = (oocFalse)); 

public: ooHashMapKeyIterator(const ooHandle(ooHashMap) &); 
virtual ooRef(ooObj) current(); 
virtual ooRef(ooObj) next(); 
virtual ooRef(ooObj) previous(); 
virtual ooRef(ooObj) currentValue(); 
}; 

class CO_STORAGE_SPECIFIER ooHashMapValueIterator : public ooHashMapIterator { 


protected: virtual ooRef(ooObj) &currentP(ooBoolean = (oocFalse)); 

public: ooHashMapValueIterator(const ooHandle(ooHashMap) &); 
virtual ooRef(ooObj) current(); 
virtual ooRef(ooObj) next(); 
virtual ooRef(ooObj) previous(); 
virtual ooStatus remove(); 
virtual ooStatus set(const ooHandle(ooObj) &); 
}; 

#endif /* !defined(OO_COLLECTIONS_H) */
