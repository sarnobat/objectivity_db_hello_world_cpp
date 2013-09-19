//***************************************************************************//
//                                                                           //
//                Copyright © 2007 Objectivity Inc, USA.                     //
//                                                                           //
//    All Rights Reserved. Unauthorized use, duplication or distribution     //
//         of this software, or any portion of it, is prohibited.            //
//                                                                           //
//***************************************************************************//
#ifndef ExpressionTree_h 
#define ExpressionTree_h

#include "ObjectQualificationSS.h"
#include "OperatorExpression.h"
#include "AttributeValueExpression.h"
#include "LiteralValueExpressions.h"

namespace objy {namespace query
{

class ExpressionTreeUser;

//-----------------------------------------------------------------------------
// Instances of ExpressionTree represent a predicate or query expression.
//-----------------------------------------------------------------------------
class OQ_STORAGE_SPECIFIER ExpressionTree
{
  public:

    // Constructor.
    ExpressionTree();

    // Destructor
    ~ExpressionTree();

    // Sets the owner of this expression tree.
    void setUser(ExpressionTreeUser* user);

    // Sets the error handler to use.
    // The caller is responsible to clean up the memory of the passed handler.
    void setErrorHandler(ExpressionSetupErrorHandler* errorHandler);

    // Sets the result required from the head expression node.
    void setRequiredResult(const ExpressionResultSpec& required,
      const char* requiredResultTypeMessage);

    // Returns the currently set error handler.
    ExpressionSetupErrorHandler* getErrorHandler() const;

    // Sets the class number or shape and the predicate string.
    // Validating the existence of the class and the expression tree by 
    // calling completeSetup implicitly will be done as part of the setup.
    void setup(ooTypeNumber classOrShapeNumber, 
               const char* pqlPredicate);

    // Wide character version of above.
    void setup(ooTypeNumber classOrShapeNumber, 
               const wchar_t* wPqlPredicate);

    // Sets the class number or shape and the predicate expression 
    // (root of the expression tree).
    // Validating the existence of the class and the expression tree by 
    // calling completeSetup implicitly will be done as part of the setup.
    void setup(ooTypeNumber classOrShapeNumber, 
               Expression* predicateExpression);

    // Sets the class name and the predicate string.
    // Validating the existence of the class and the expression tree by 
    // calling completeSetup implicitly will be done as part of the setup.
    void setup(const char* className, 
               const char* pqlPredicate);

    // Wide character version of above.
    void setup(const char* className, 
               const wchar_t* wPqlPredicate);

    // Sets the class name or shape and the predicate expression 
    // (root of the expression tree).
    // Validating the existence of the class and the expression tree by 
    // calling completeSetup implicitly will be done as part of the setup.
    void setup(const char* className, 
               Expression* predicateExpression);

    // Sets whether or not to perform predicate optimization.  
    // If true then the predicate expression is optimized as part of 
    // complete setup.
    // The default is true unless changed by setDefaultDoPerformOptimization.
    // Set to false if tree modification is not desired.
    void setDoPerformOptimization(bool value);

    // Sets whether or not to perform predicate optimization by default,
    // which can always be overridden by calling setDoPerformOptimization
    // on specific ExpressionTree instances.  
    // If true then the default is that predicate expression is optimized 
    // as part of complete setup.
    // The initial value of this default is true.
    static void setDefaultDoPerformOptimization(bool value);

    // Returns the latest shape number of the qualification class.
    ooTypeNumber getShapeNumber() const;

    // Returns the latest shape of the qualification class.
    ooShapeInt* getShape() const;

    // Returns the predicate expression used for qualification.
    Expression* getPredicateExpression() const;

    // Returns the PQL string representation for the predicate expression.
    // This is a cached value, so it will be replaced on subsequent calls if the 
    // expression tree has been changed; and the caller should never delete it.
    const char* getPQLRepresentation();

    // Returns the PQL string representation for the predicate expression.
    // This is a cached value, so it will be replaced on subsequent calls if the 
    // expression tree has been changed; and the caller should never delete it.
    const wchar_t* getWPQLRepresentation();

    // Returns the lookup key
    ooLookupKey* getLookupKey();

    // Builds the lookup key from the expression tree, returns true 
    // if the lookup keys are compatible with the index key fields.
    bool hasCompatibleIndex(const ooHandle(ooObj) &sysOjbectH);

    // Completes predicate expression setup (operator selection if needed, 
    // error detection, and optimization). 
    // The default error handling behavior is throwing exception upon first error.
    // If error handler was set(calling setErrorHandler()), all errors are 
    // collected by the user's error handler.
    void completeSetup();

    // Returns true if setup has been completed; false otherwise.
    bool isSetupCompleted() const;

    // Clears the setup completed flag.
    void clearSetupCompleted();

    // Returns true if the source used to generate the expression tree is a
    // wide string; false otherwise.
    bool isSourceWString() const;

    static Expression*  generateExpressionTreeFromPQL
       (const char* predicate, ExpressionSetupErrorHandler* errorHandler=0);
    static Expression*  generateExpressionTreeFromWPQL
       (const wchar_t* wPredicate, ExpressionSetupErrorHandler* errorHandler=0);

    // Sets all the literalValueExpression value paired with the specified 
    // variableName.
    // Throws ExpressionSetupException if not found or the literal's 
    // type is not that specified by expectedType.
    void setVariableLiteralValue(const char* variableName, 
      const ExpressionResult& valueResult);

    static const char* USE_SCHEMA_NAMES_INDICATOR;
    static const wchar_t* USE_SCHEMA_NAMES_INDICATOR_W;

    // Returns true if the class and attribute names should be interpreted
    // as schema names, not application names.
    bool useSchemaNames() const;

  private:

    class Impl;
    Impl* mImpl;

    void setExpressionTree();

    // Prevent copy constructing or assignment
    ExpressionTree(const ExpressionTree& other);
    ExpressionTree& operator = (const ExpressionTree& other);

};

}/* end query namespace */} /* end objy namespace */

#endif
