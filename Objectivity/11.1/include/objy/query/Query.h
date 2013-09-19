//***************************************************************************//
//                                                                           //
//                   Copyright © 2012 Objectivity Inc, USA.                  //
//                                                                           //
//    All Rights Reserved. Unauthorized use, duplication or distribution     //
//         of this software, or any portion of it, is prohibited.            //
//                                                                           //
//***************************************************************************//

#if _MSC_VER > 1000
	#pragma once
#endif 

#ifndef query_Query_h
#define query_Query_h

#include "objy/placement/Placement.h"
#include "objy/query/ExpressionTreeUser.h"
#include "oo.h"

namespace objy {namespace query
{

const unsigned NO_MAX_PREFERENCE_RANK = 65535;

//-----------------------------------------------------------------------------
// Experimental and subject to change.
class PLACEMENT_EXPORT Query : public ExpressionTreeUser
{
  public:

    Query(const char* className, const char* predicate = 0);

    Query(ooTypeNumber classOrShapeNumber, const char* predicate = 0);

    Query(const char* className, const wchar_t* predicate);

    Query(ooTypeNumber classOrShapeNumber, const wchar_t* predicate);

    ~Query();

    ooStatus execute
      (ooItr(ooObj)& iterator, ooMode openMode = oocNoOpen,
       unsigned maxPreferenceRank = NO_MAX_PREFERENCE_RANK) const;

    uint64 getCount(unsigned maxPreferenceRank = NO_MAX_PREFERENCE_RANK) const;

  private:  

    class Impl;
    Impl* mImpl;
 
    virtual void onExpressionChanged(const objy::query::Expression* expression);

    virtual bool useSchemaNames() const;

};

}/* end query namespace */} /* end objy namespace */

#endif
