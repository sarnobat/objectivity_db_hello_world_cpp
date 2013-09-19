/* C++ methods file: Objectivity/DB DDL Version: 11.1 */

#include "HelloObject.h"

#if defined(_MSC_VER) && !defined(OO_DDL_TRANSLATION)
#pragma pack(push,8)
#endif
const ooTypeNumber HelloObject::opiTypeN = 1000000;


/* methods on ooHandle(HelloObject) */
ooHandle(HelloObject)
ooHandle(HelloObject)::copy(const ooHandle(ooObj) &  nearH) const
{
  ooHandle(HelloObject) result;
  this->ooHandle(ooObj)::copy(nearH, result);
  return result;
}
ooHandle(HelloObject) &
ooHandle(HelloObject)::copy(const ooHandle(ooObj) &  nearH,
		   ooHandle(HelloObject) &           result) const
{
  this->ooHandle(ooObj)::copy(nearH, result);
  return result;
}
ooStatus
ooHandle(HelloObject)::lookupObj(const ooHandle(ooObj) &  scopeH,
			const ooKey &            key,
			ooMode                   openMode)
{
  return opiLookupObj(ooTypeN(HelloObject), *this, scopeH, key, openMode);
}
ooStatus
ooHandle(HelloObject)::lookupObj(const ooHandle(ooObj) &  scopeH,
			const char *             name,
			ooMode                   openMode)
{
  return opiLookupObj(ooTypeN(HelloObject), *this, scopeH, name, openMode);
}


/* methods on ooItr(HelloObject) */
ooItr(HelloObject)::ooItrStructor(HelloObject)() :
    ooIteratorObjOrContObj(ooTypeN(HelloObject))
{
}
ooItr(HelloObject)::~ooItrStructor(HelloObject)()
{
}



/* methods on ooRef(HelloObject) */
ooStatus
ooRef(HelloObject)::lookupObj(const ooHandle(ooObj) &  scopeH,
		     const ooKey &            key,
		     ooMode                   openMode)
{
  ooHandle(HelloObject) thisH;
  ooStatus result = thisH.lookupObj(scopeH, key, openMode);
  *this = thisH;
  return result;
}
ooStatus
ooRef(HelloObject)::lookupObj(const ooHandle(ooObj) &  scopeH,
		     const char *             name,
		     ooMode                   openMode)
{
  ooHandle(HelloObject) thisH;
  ooStatus result = thisH.lookupObj(scopeH, name, openMode);
  *this = thisH;
  return result;
}
// ODMG methods:
ooRef(HelloObject)::ooRefStructor(HelloObject)(const d_Ref_Any &  from) :
    ooRef(ooObj)(from)
{
}
#ifdef OO_BUGGY_TEMPLATES
ooHandle(HelloObject)::ooHandleStructor(HelloObject)(const d_Ref_Any &  from)
{
  *this = *ooReinterpretCast(ooRef(HelloObject) *, &from);
}
#else // !defined(OO_BUGGY_TEMPLATES)
ooHandle(HelloObject)::ooHandleStructor(HelloObject)(const d_Ref_Any &  from) :
    ooHandle(ooObj)(from)
{
}
#endif // !defined(OO_BUGGY_TEMPLATES)

ooTypeNumber
HelloObject::ooGetTypeN() const
{
  return ooTypeN(HelloObject);
}

char*
HelloObject::ooGetTypeName() const
{
  return OO_CHAR_PTR("HelloObject");
}

ooBoolean
HelloObject::ooIsKindOf(ooTypeNumber oo_typeN) const
{
  return ((oo_typeN == ooTypeN(HelloObject)) || (this->ooObj::ooIsKindOf(oo_typeN)));
}

ooHandle(HelloObject)
HelloObject::ooThis(ooMode  aMode) const
{
  ooHandle(HelloObject) result;
  return this->ooThis(result, aMode);
}

void*
HelloObject::operator new(size_t size)
{
  ooId nearId = opiGetTopDB();
  return ooGetClusterStrategy()->newObj(ooTypeN(HelloObject), nearId);
}

void*
HelloObject::operator new(size_t size, const ooHandle(ooObj)& nearH)
{
  ooId nearId = nearH;
  return ooGetClusterStrategy(nearH)->newObj(ooTypeN(HelloObject), nearId);
}

void*
HelloObject::operator new(size_t size, const ooId& nearId)
{
  return ooGetClusterStrategy()->newObj(ooTypeN(HelloObject), nearId);
}

void*
HelloObject::operator new(size_t size, const objy::placement::Conditions& conditions)
{
  return ooNewObject(ooTypeN(HelloObject), conditions);
}

void*
HelloObject::operator new(size_t size, const ooObj*  nearObj)
{
  return opiNewObj(ooTypeN(HelloObject), size, nearObj);
}

void*
HelloObject::operator new(size_t size, const ooHandle(ooObj)&  nearH, const char*)
{
  return HelloObject::operator new(size, nearH);
}
#ifdef OO_ODMG

void*
HelloObject::operator new(size_t size, d_Database*  odmg_db)
{
  return opiODMGDatabaseNew(size, ooTypeN(HelloObject), odmg_db);
}

void*
HelloObject::operator new(size_t size, d_Database*  odmg_db, const char*)
{
  return HelloObject::operator new(size, odmg_db);
}
#endif
// static
void
HelloObject::ooAssocRegister()
{
}

ooRef(HelloObject) &
HelloObject::ooThis(ooRef(HelloObject) &  result,
	   ooMode       aMode) const
{
  this->ooObj::ooThis(result, aMode);
  return result;
}
HelloObject::HelloObject(::ooInternalObj iobj): ooObj(iobj){}


static void ooInitVTables();

static
int
ooDoFileInit()
{

  HelloObject::ooAssocRegister();

    return otmAddToVTableInitList(ooInitVTables);
}

#ifdef OO_AIX
struct ooVTableInitializer {
    int x;
    ooVTableInitializer() {
      ooDoFileInit();
    }
};
static ooVTableInitializer ooInitializer;
#else
static int ooInitializer = ooDoFileInit();
#endif

static
void
ooInitVTables()
{
    ooInternalObj oo__iobj;
    {
	double oo__buf[(sizeof(HelloObject) + sizeof(double) - 1)/sizeof(double)];
	HelloObject *oo__ptr = ::new(opiPlacementNewValue, oo__buf) HelloObject(oo__iobj);
	otmStealVtbls(ooTypeN(HelloObject), (void *) oo__ptr);
    }
}


#if defined(_MSC_VER) && !defined(OO_DDL_TRANSLATION)
#pragma pack(pop)
#endif
