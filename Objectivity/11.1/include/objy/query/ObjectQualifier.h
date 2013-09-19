//***************************************************************************//
//                                                                           //
//                Copyright © 2007 Objectivity Inc, USA.                     //
//                                                                           //
//    All Rights Reserved. Unauthorized use, duplication or distribution     //
//         of this software, or any portion of it, is prohibited.            //
//                                                                           //
//***************************************************************************//
#ifndef ObjectQualifier_h 
#define ObjectQualifier_h

#include "ObjectQualificationSS.h"
#include "ExpressionTreeUser.h"
#include "LiteralValueExpressions.h"

class ooObjectInt;
class ooShapeInt;


namespace objy {namespace query
{

//-----------------------------------------------------------------------------
// Instances of ObjectQualifier are used to determine if objects qualify 
// (i.e. their classes are compatible with a given class and their values
// match conditions specified in a predicate expression, perhaps specified
// as a PQL (Predicate Query Language) string.
//-----------------------------------------------------------------------------
class OQ_STORAGE_SPECIFIER ObjectQualifier : public ExpressionTreeUser
{
  public:

    // Default Constructor.
    ObjectQualifier();

    // Constructor taking a class number or shape specifying the type of 
    // objects this qualifier is for, a PQL string that specifies the 
    // conditions that must be met by objects to qualify.
    ObjectQualifier(ooTypeNumber classOrShapeNumber, 
                      const char* pqlPredicate);

    // Wide character version of above.
    ObjectQualifier(ooTypeNumber classOrShapeNumber, 
                      const wchar_t* wPqlPredicate);

    // Constructor taking a class name of the objects this qualifier is 
    // for, a PQL string that specifies the conditions that must be met 
    // by objects to qualify.
    ObjectQualifier(const char* className, 
                      const char* pqlPredicate);

    // Wide character version of above.
    ObjectQualifier(const char* className, 
                      const wchar_t* wPqlPredicate);

    // Clone itself 
    // if shareExpressionTree is true, expression tree is shared using the reference
    // counting mechanism
    ObjectQualifier* cloneQualifier(bool shareExpressionTree) const;

    // Returns true if the provided object qualifies; false otherwise.  
    // If qualifyClass is true then the object's class is checked in addition
    // to evaluating the predicate.
    bool doesQualify
       (const ooHandle(ooObj)& object, bool qualifyClass = true);

};

}/* end query namespace */} /* end objy namespace */

#endif
