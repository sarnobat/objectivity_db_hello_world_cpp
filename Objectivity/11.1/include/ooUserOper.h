
/**************************************************************************
		    Copyright (c) 1989-2000 Objectivity, Inc.
			  All Rights Reserved  	

	THIS IS UNPUBLISHED PROPRIETARY SOURCE CODE OF OBJECTIVITY, INC.
	
	The copyright notice above does not evidence any   	
	actual or intended publication of such source code.

*****************************************************************************/

#ifndef _OO_USER_OPER_H
#define _OO_USER_OPER_H

#if defined(_MSC_VER) && !defined(OO_DDL_TRANSLATION)
#pragma pack(push,8)
#endif

#include <oo.h>

#ifndef  OOQR_EXPORTS // {
#if defined(_MSC_VER) && defined(_DLL) // {
#define OOQR_EXPORTS    __declspec(dllimport)
#ifdef _DEBUG
/* Dynamic debug link */
#pragma comment(lib, "ooqrd.lib")
#else
/* Dynamic non-debug link */
#pragma comment(lib, "ooqr.lib")
#endif
#else
// }{
#define OOQR_EXPORTS
#endif // }
#endif // }

//SPR19108: added oocChar16PtrT, oocChar32PtrT
enum oqrDataType {
   oocInt64T, oocUint64T, oocFloat64T, oocCharPtrT, oocChar16PtrT, oocChar32PtrT, 
   oocBooleanT, oocInvalidTypeT
};
typedef ooBoolean (*oqrFuncPtr)(const void *, const void *, oqrDataType, oqrDataType);

typedef oqrDataType             ooDataType;
typedef oqrFuncPtr              ooQueryOperatorPtr;

class OOQR_EXPORTS oqrUserOperator {

    char          *token;
    oqrFuncPtr function;

public:
    oqrUserOperator() : token(0), function(0) {}
    ~oqrUserOperator() { if (token) delete[] token; }

    ooStatus 	   	   set(const char *s, oqrFuncPtr f);
    const char*    	   getToken() const { return token; }
    oqrFuncPtr 	   	   getFunction() const { return function; }
};

class OOQR_EXPORTS oqrUserOperatorSet {

    ooVArray(oqrUserOperator)	operator_;

public:
    oqrUserOperatorSet() {}
    ~oqrUserOperatorSet() {}
    
    void     clear() { operator_.resize(0); }
    ooStatus registerOperator(const char *s, oqrFuncPtr f);
    const oqrUserOperator* matchUserOperator(const char* s) const;
};

typedef oqrUserOperatorSet      ooOperatorSet;

OOQR_EXPORTS extern  oqrUserOperatorSet     *ooUserDefinedOperators;

#if defined(_MSC_VER) && !defined(OO_DDL_TRANSLATION)
#pragma pack(pop)
#endif


#endif
