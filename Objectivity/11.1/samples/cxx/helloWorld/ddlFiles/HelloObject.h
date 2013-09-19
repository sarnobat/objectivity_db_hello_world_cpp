/* C++ header file: Objectivity/DB DDL Version: 11.1 */

#ifndef _HELLO_OBJECT_H
#define _HELLO_OBJECT_H

#ifdef OO_DDL_TRANSLATION
#pragma ooddlout "HelloObject.ddl"
class opiDummyDeclaration;
#endif

#ifndef OO_H
#include <oo.h>
#endif

#ifndef _HELLO_OBJECT_REF_H
#include "HelloObject_ref.h"
#endif

#line 6 "HelloObject.ddl"
class HelloObject : public ooObj { 




public: HelloObject(); 


const char *getHelloMsg() const; 


void setHelloMsg(const char *); 



private: ooVString mHelloMsg; 
public: 
#ifndef OO_DDL_TRANSLATION
    virtual ooTypeNumber ooGetTypeN() const;
    virtual char* ooGetTypeName() const;
    ooBoolean ooIsKindOf(ooTypeNumber oo_typeN) const;
    ooHandle(HelloObject)& ooThis(ooHandle(HelloObject)& objH,
			 ooMode aMode = oocNoOpen) const
      {
	return *ooReinterpretCast(ooHandle(HelloObject) *, &(this->ooObj::ooThis(objH, aMode)));
      }
    ooHandle(HelloObject) ooThis(ooMode aMode = oocNoOpen) const;
    void *operator new(size_t);
    void *operator new(size_t, const ooHandle(ooObj) &nearH);
    void *operator new(size_t, const ooHandle(ooObj) &nearH, ooClusterStrategy& strategy)
	{
		return strategy.newObj(ooTypeN(HelloObject), nearH);
	}
    void *operator new(size_t, const ooId& nearR, ooClusterStrategy& strategy)
	{
		return strategy.newObj(ooTypeN(HelloObject), nearR);
	}
    void *operator new(size_t, ooClusterStrategy& strategy)
	{
		return strategy.newObj(ooTypeN(HelloObject));
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
    ooRef(HelloObject)& ooThis(ooRef(HelloObject)& objId, ooMode aMode = oocNoOpen) const;
    HelloObject(ooInternalObj iobj);
#endif /* !defined(OO_DDL_TRANSLATION) */
}; 

#endif /* !defined(_HELLO_OBJECT_H) */
