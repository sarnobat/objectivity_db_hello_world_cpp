//***************************************************************************//
//                                                                           //
//                Copyright © 2007 Objectivity Inc, USA.                     //
//                                                                           //
//    All Rights Reserved. Unauthorized use, duplication or distribution     //
//         of this software, or any portion of it, is prohibited.            //
//                                                                           //
//***************************************************************************//
#ifndef ExpressionSetupError_h 
#define ExpressionSetupError_h

#include "ObjectQualificationSS.h"

namespace objy {namespace query
{

//-----------------------------------------------------------------------------
// Enum capturing the types of errors that a predicate expression can have.
//-----------------------------------------------------------------------------
enum ExpressionSetupErrorType
{
   oocPQLSyntaxError,
   oocInvalidPredicateTypeError,
   oocUnknownTypeError,
   oocUnknownAttributeError,
   oocUnknownTokenError,
   oocOperandMismatchError,
   oocTooFewOperandsError,
   oocTooManyOperandsError,
   oocIncompatibleOperandError,
   oocInvalidRegularExpressionError,
   oocOperandCrossIncompatibleError,
   oocElementCrossIncompatibleError,
   oocOperatorImplementationError,
   oocObjectLitValueIncompatibleError,
   oocUnknownVariableTypeError,
   oocUndefinedVariableError,
   oocVariableValueNotSetError,
   oocIncompatibleVariableValueError,
   oocCreateLookupFieldError
};

class ExpressionSetupErrorHandler;
class Expression;

//-----------------------------------------------------------------------------
// Represents a semantic error found with the expression durring setup.
//-----------------------------------------------------------------------------
class OQ_STORAGE_SPECIFIER ExpressionSetupError
{
   public:

      ExpressionSetupError(ExpressionSetupErrorType type, 
                        const Expression* expression,
                        const Expression* operand,
                        const char* detailMsg); 

      // Copy constructor
      ExpressionSetupError(const ExpressionSetupError& other);
    
      ~ExpressionSetupError();

      // Assignment
      ExpressionSetupError& operator = (const ExpressionSetupError& other);

      // Returns the error's type.
      ExpressionSetupErrorType getErrorType() const
      {return mType;}

      // Returns a description of the error.
      const std::string& getDescription() const
      {return mDescription;}

      // Returns the expression node that has the error or null if there is
      // no associated expression node.
      const Expression* getExpression() const
      {return mExpression;}

      // Returns the operand that has the error if applicable;
      // null otherwise.
      const Expression* getOperand() const
      {return mOperand;}

      // Get the next error or null if there are no more errors.
      const ExpressionSetupError* getNextError() const
      {return mNext;}

   private:

      ExpressionSetupErrorType mType;
      const Expression* mExpression;
      const Expression* mOperand;
      const ExpressionSetupError* mNext;
      std::string mDescription;

      void setNext(const ExpressionSetupError* next)
      {mNext = next;}

      friend class ExpressionSetupErrorHandler;
      friend class ExpressionSetupException;
      friend class ObjectQualifier;
      friend class OperatorExpression;
};

//-----------------------------------------------------------------------------
// A handler of predicate expression errors.
//-----------------------------------------------------------------------------
class OQ_STORAGE_SPECIFIER ExpressionSetupErrorHandler
{
   public:

       // Default constructor
       ExpressionSetupErrorHandler();
       
	     // Constructor that take a throw exception on error policy.
       ExpressionSetupErrorHandler(bool throwExceptionOnError);

       // Destructor
       ~ExpressionSetupErrorHandler();
       
       // Get the first expression error from the errors list
       const ExpressionSetupError* getFirstError() const;

       // Get the total number of errors
       int getNumberOfErrors() const;

       // Clear the errors
       void clearErrors();

       void onError(const ExpressionSetupError& error);

       void onError(ExpressionSetupErrorType type, 
                    const Expression* expression,
                    const Expression* operand, 
                    const char* detailMsg); 

   private:

      bool mThrowExceptionOnError;
      ExpressionSetupError* mFirstError;
      ExpressionSetupError* mLastError;
      
      friend class OperatorExpression;
      friend class AttributeValueExpression;
      friend class RegExpOperator;
      friend class SetEqualityOperator;
      friend class Operator;
      friend class ObjectQualifier;
      friend class OrderedListLiteralValueExpression;
      friend class ClassTypeLiteralValueExpression;
      friend class ObjectLiteralValueExpression;
      friend class PathOperatorBase;
      friend class SubscriptOperator;
      friend class SetQualifyOperator;
      friend class LiteralValueExpression;
      friend class ExpressionTree;
};

}/* end query namespace */} /* end objy namespace */

#endif
