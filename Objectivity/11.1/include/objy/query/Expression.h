//***************************************************************************//
//                                                                           //
//                Copyright © 2007 Objectivity Inc, USA.                     //
//                                                                           //
//    All Rights Reserved. Unauthorized use, duplication or distribution     //
//         of this software, or any portion of it, is prohibited.            //
//                                                                           //
//***************************************************************************//
#ifndef Expression_h 
#define Expression_h

#include "ObjectQualificationSS.h"
#include "ReferenceCounted.h"
#include "ExpressionResult.h"
#include "ExpressionSetupError.h"

namespace objy {namespace placement {class PredicateSplitter; class RelatedPredicateSplitter;}}

namespace objy {namespace query {

typedef ReferenceCountedHandle<Expression> ExpressionHandle;

//-----------------------------------------------------------------------------
// Enum capturing the different types of expression nodes possible in a 
// predicate expression tree.
//-----------------------------------------------------------------------------
enum ExpressionType
{
   oocOperatorExpression,
   oocAttributeValueExpression,
   oocIntLiteralValueExpression,
   oocUIntLiteralValueExpression,
   oocFloatLiteralValueExpression,
   oocBoolLiteralValueExpression,
   oocStringLiteralValueExpression,
   oocDateLiteralValueExpression,
   oocTimeLiteralValueExpression,
   oocDateTimeLiteralValueExpression,
   oocIntervalLiteralValueExpression,
   oocOrderedListLiteralValueExpression,
   oocClassTypeLiteralValueExpression,
   oocOidLiteralValueExpression,
   oocObjectLiteralValueExpression
};

//-----------------------------------------------------------------------------
// The base class for user defined classes that define data that can be added 
// to predicate expression tree nodes.
//-----------------------------------------------------------------------------
class OQ_STORAGE_SPECIFIER ExpressionData
{
   public:

      // Constructor taking the flag to specify if the data is owned by the expression.
      ExpressionData(bool isExpressionOwned) 
         : mIsExpressionOwned(isExpressionOwned) {}

      // Destructor
      virtual ~ExpressionData() {}

      // Clone
      virtual ExpressionData* clone() const = 0;

   private:

      bool mIsExpressionOwned;

      friend class Expression;
};

//-----------------------------------------------------------------------------
// The base class for operator defined classes that define data to be set on 
// predicate expression tree nodes for its purposes, often optimization.
//-----------------------------------------------------------------------------
class OQ_STORAGE_SPECIFIER OperatorData
{
   public:

      // Constructor
      OperatorData() {}

      // Destructor
      virtual ~OperatorData() {}

      // Clone
      virtual OperatorData* clone() const = 0;
};

//-----------------------------------------------------------------------------
// forward declares.
//-----------------------------------------------------------------------------
class ExpressionTree;
class AttributeValueExpression;
class OperatorExpression;
class LiteralValueExpression;
class BoolLiteralValueExpression;
class StringLiteralValueExpression;
class IntLiteralValueExpression;
class UIntLiteralValueExpression;
class FloatLiteralValueExpression;
class DateLiteralValueExpression;
class TimeLiteralValueExpression;
class DateTimeLiteralValueExpression;
class IntervalLiteralValueExpression;
class OrderedListLiteralValueExpression;
class ClassTypeLiteralValueExpression;
class OidLiteralValueExpression;
class ObjectLiteralValueExpression;
class ObjectLiteralAttribute;

//-----------------------------------------------------------------------------
// Represents the current context that expressions are to use when completing
// setup.
//-----------------------------------------------------------------------------
class OQ_STORAGE_SPECIFIER CompleteSetupContext
{
   public:

      CompleteSetupContext
         (ooTypeNumber shapeNumber,
          ExpressionSetupErrorHandler* errorHandler,
          bool isClassContextChanged)
         : mShapeNumber(shapeNumber),
           mErrorHandler(errorHandler),
           mIsClassContextChanged(isClassContextChanged)

      {
      }

      ExpressionSetupErrorHandler* getErrorHandler() const
      {return mErrorHandler;}

      ooTypeNumber getShapeNumber() const
      {return mShapeNumber;}

      bool isClassContextChanged()
      { return mIsClassContextChanged;}
         
   private:

      // the current class context
      ooTypeNumber mShapeNumber;

      // the error handler to use
      ExpressionSetupErrorHandler* mErrorHandler;

      // indicate if the class context is different than the original qualifying class
      bool mIsClassContextChanged;
};

//-----------------------------------------------------------------------------
// A base class for predicate expression tree visitors.
//-----------------------------------------------------------------------------
class OQ_STORAGE_SPECIFIER ExpressionVisitor
{
   public:

      // Visit operation on an expression.  
      // Called automatically by all non-overriden more specific visit 
      // operations below.
      virtual void visitExpression(Expression* expression) {}

      // Visit operation on a literal value expression.  
      // Called automatically by all non-overriden more specific visit 
      // operations below.
      virtual void visitLiteralValue
        (LiteralValueExpression* literalValueExpression);

      // Visit operation on attribute value expression
      virtual void visitAttributeValue
         (AttributeValueExpression* attributeValue);

      // Visit operation on operator expression.
      virtual bool visitOperator(OperatorExpression* op);

      // Visit operation inbetween operands
      virtual void visitOperatorMiddle(OperatorExpression* op) {}

      // Visit operation after all operands
      virtual void visitOperatorEnd(OperatorExpression* op) {}

      // Visit operation on boolean literal value expression.
      virtual void visitBoolLiteralValue
         (BoolLiteralValueExpression* boolLiteralValue);

      // Visit operation on string literal value expression.
      virtual void visitStringLiteralValue
         (StringLiteralValueExpression* stringLiteralValue);

      // Visit operation on int literal value expression.
      virtual void visitIntLiteralValue
         (IntLiteralValueExpression* intLiteralValue);

      // Visit operation on unsigned int literal value expression.
      virtual void visitUIntLiteralValue
         (UIntLiteralValueExpression* uintLiteralValue);

      // Visit operation on float literal value expression.
      virtual void visitFloatLiteralValue
         (FloatLiteralValueExpression* floatLiteralValue);

      // Visit operation on date literal value expression.
      virtual void visitDateLiteralValue
         (DateLiteralValueExpression* dateLiteralValue);

      // Visit operation on time literal value expression.
      virtual void visitTimeLiteralValue
         (TimeLiteralValueExpression* timeLiteralValue);

      // Visit operation on datetime literal value expression.
      virtual void visitDateTimeLiteralValue
         (DateTimeLiteralValueExpression* dateTimeLiteralValue);

      // Visit operation on interval literal value expression.
      virtual void visitIntervalLiteralValue
         (IntervalLiteralValueExpression* intervalLiteralValue);
      
      // Visit operation on ordered list literal value expression.
      virtual void visitOrderedListLiteralValue
         (OrderedListLiteralValueExpression* orderedListLiteralValue);

      // Visit operation on ordered list literal value expression.
      virtual void visitOrderedListLiteralValueMiddle
         (OrderedListLiteralValueExpression* orderedListLiteralValue) {}

      // Visit operation on ordered list literal value expression.
      virtual void visitOrderedListLiteralValueEnd
         (OrderedListLiteralValueExpression* orderedListLiteralValue) {}

      // Visit operation on class type literal value expression.
      virtual void visitClassTypeLiteralValue
         (ClassTypeLiteralValueExpression* classTypeLiteralValue);

      // Visit operation on oid literal value expression.
      virtual void visitOidLiteralValue
         (OidLiteralValueExpression* oidLiteralValue);

      // Visit operation on object literal value expression.
      virtual void visitObjectLiteralValue
         (ObjectLiteralValueExpression* objectLiteralValue);

      // Visit operation between object literal attributes.
      virtual void visitObjectLiteralValueMiddle
         (ObjectLiteralValueExpression* objectLiteralValue) {}

      // Visit operation after all object literal attributes.
      virtual void visitObjectLiteralValueEnd
         (ObjectLiteralValueExpression* objectLiteralValue) {}

      // Visit operation for object literal attribute
      virtual void visitObjectLiteralAttribute
         (ObjectLiteralAttribute* objectLiteralAttribute) {}

      // Visit operation between object literal attribute name and value.
      virtual void visitObjectLiteralAttributeMiddle
         (ObjectLiteralAttribute* objectLiteralAttribute) {}

      // Visit operation for object literal attribute end
      virtual void visitObjectLiteralAttributeEnd
         (ObjectLiteralAttribute* objectLiteralAttribute) {}

};

//-----------------------------------------------------------------------------
class OQ_STORAGE_SPECIFIER IndexCompareValue
{
  public:
    
    IndexCompareValue()
      : mNumericValue(0), mStringValue(0) {}

    void* getCompareValue() const
    {return (mStringValue)? mStringValue : (void*)&mNumericValue;}

    void setStringValue(void* stringValue)
    {mStringValue = stringValue;}

    uint64& numbericValue()
    {return mNumericValue;}

  private:

    uint64 mNumericValue;
    void* mStringValue;
};

//-----------------------------------------------------------------------------
// The base class for classes that represent specific types of nodes within a
// predicate expression tree.
//-----------------------------------------------------------------------------
class OQ_STORAGE_SPECIFIER Expression: public ReferenceCounted 
{
   public:
    
      // Destructor
      virtual ~Expression();

      // Returns the specific type of expression.
      virtual ExpressionType getExpressionType() const = 0;

      // Returns the type of result this expression produces.
      ExpressionResultSpec& getResultSpec() const;

      // Resets the result spec
      void setResultSpec(ExpressionResultSpec* resultSpec);

      // Causes the expression to evaluate itself using the provided object and
      // place the result in the passed in result object.
      virtual void evaluate
       (const ooObjectBaseInt* object, ExpressionResult& result) const = 0;

      // Causes specific derived expression node types to call the 
      // corresponding visit method on the passed in visitor.
      virtual void accept(ExpressionVisitor& visitor) = 0;

      // Sets the user defined expression data.
      void setExpressionData(ExpressionData* expressionData);

      // Returns the user defined expression data, or null if none was set.
      ExpressionData* getExpressionData() const
      {return mExpressionData;}

      // Completes expression setup, which happens after the expression tree
      // is constructed and before it is used for evaluating objects.
      virtual void completeSetup(CompleteSetupContext& context) = 0;

      // Returns true if setup has been completed for this expression node;
      // false otherwise.
      bool setupCompleted() const
      {return mSetupCompleted;}

      // Returns the PQL string for the expression tree rooted from this expression.
      // Returns 0 if the mSetupCompleted is false.
      // The returned char* is not owned by the expression, so the caller should be
      // responsible to the returned string memory cleanup.
      char* getPQLRepresentation() const;

      // Returns the PQL string for the expression tree rooted from this expression.
      // Returns 0 if the mSetupCompleted is false.
      // The returned wchar_t* is not owned by the expression, so the caller should be
      // responsible to the returned string memory cleanup.
      wchar_t* getWPQLRepresentation() const;

      // Sets the expression tree this expression is a part of.
      virtual void setExpressionTree(ExpressionTree* expressionTree)
      {mExpressionTree = expressionTree;}

      // Returns the expression tree this expression is a part of.
      ExpressionTree* getExpressionTree() const
      {return mExpressionTree;}

      // Returns the parent operator, or null if there is none.
      OperatorExpression* getParentOperatorExpression() const
      {return mParentOperatorExpression;}

      // Returns the data set by the operator for its use, or null if none set.
      OperatorData* getOperatorData() const
      {return mOperatorData;}

      // Set the data to be associated with this expression for operator use.
      // Some operators will use operator data for optimization by 
      // precalculating some aspect of its operation and storing the results on
      // relevent expressions during completeSetup for later use during 
      // evaluate, though there is no restriction on what operator data is used
      // for.
      void setOperatorData(OperatorData* operatorData);

      // builds the LookupKey for the predicate expression tree
      virtual void buildLookupKey(const ooHandle(ooObj) &sysOjbectH, 
                      const ooTypeNumber typeNumber, 
                      ooLookupKey* lookupKey) 
      {};

      // Sets if this is the head of a parenthesis sub expression or not.
      void setIsParenthesisSubexpressionHead(bool value)
      {mIsParenthesisSubexpressionHead = value;}

      // Returns true if this is the head of a parenthesis sub expresion;
      // false otherwise.
      bool isParenthesisSubexpressionHead() const
      {return mIsParenthesisSubexpressionHead;}

      // Returns a relative evaluation cost used to optimize the expression 
      // tree for minimum evaluation time.
      virtual unsigned getEvaluationCost() const = 0;

      // Optimize the expression tree for performance.
      virtual void optimize()
      {}

      // Returns a clone of the current instance 
      virtual Expression* clone(bool deep = true) const = 0;

      // Returns true if the expression tree rooted from this expression node
      // is identical to the other specified one.
      virtual bool isEqualTo(const Expression* other) const = 0;

      IndexCompareValue& getIndexCompareValue()
      {return mIndexCompareValue;}

      // Sets the setup completed indicator for this operator.  
      // Intended for advanced use only, this value is normally set via 
      // calling completeSetup.
      void setSetupCompleted(bool value)
      {mSetupCompleted = value;}

   protected:
      static ExpressionResultSpec smNoResultSpec;
      static ExpressionSetupErrorHandler smErrorHdlrByException;

      ExpressionTree* mExpressionTree;
      bool mSetupCompleted;
      OperatorExpression* mParentOperatorExpression;
      ExpressionData* mExpressionData;
      OperatorData* mOperatorData;
      ExpressionResultSpec* mResultSpec;

      bool mIsParenthesisSubexpressionHead;

      Expression();

      // Copy constructor (for clone())
      Expression( const Expression& other );

      void setParentOperatorExpression(
         OperatorExpression* parentOperatorExpression)
      {mParentOperatorExpression = parentOperatorExpression;}

      void onChanged();

      virtual ExpressionResultSpec* computeResultSpec() const = 0;

   private:

      // Prevent assignment
      Expression& operator=(const Expression& rhs);

      IndexCompareValue mIndexCompareValue;

      bool mIsAttached;
      bool mIsSharingAllowed;

      bool isAttached()
      {return mIsAttached;}

      void setAttached(bool value)
      {mIsAttached = value;}

      bool isSharingAllowed()
      {return mIsSharingAllowed;}

      void setAllowSharing(bool value)
      {mIsSharingAllowed = value;}

      friend class ObjectQualifier;
      friend class OperandList;
      friend class Operator;
      friend class objy::placement::PredicateSplitter;
      friend class objy::placement::RelatedPredicateSplitter;
};

//-----------------------------------------------------------------------------
// An exception that represents a predicate expression error.
//-----------------------------------------------------------------------------
class OQ_STORAGE_SPECIFIER ExpressionException : public ooException 
{
   public:
       virtual int get_kind() const { return -500; }

   protected:

      ExpressionException() {}

      virtual ~ExpressionException() OO_WHAT_THROW_NONE {};

};

//-----------------------------------------------------------------------------
// An exception that represents a predicate expression setup error.
//-----------------------------------------------------------------------------
class OQ_STORAGE_SPECIFIER ExpressionSetupException 
   : public ExpressionException 
{
   public:

      ExpressionSetupException(const ExpressionSetupError& error)
         : mError(error) {}

      ~ExpressionSetupException() OO_WHAT_THROW_NONE {};

      const char* what() const OO_WHAT_THROW_NONE
      {return mError.getDescription().c_str();}

      const ExpressionSetupError& getError() const
      {return mError;}

      virtual int get_kind() const { return -501; }

   private:

      ExpressionSetupError mError;
};

//-----------------------------------------------------------------------------
// An exception that represents a predicate expression evaluation error.
//-----------------------------------------------------------------------------
class OQ_STORAGE_SPECIFIER ExpressionEvaluationException 
   : public ExpressionException 
{
   public:

      ExpressionEvaluationException(const char* message)
         : mMessage(message) {}

      const char* what() const OO_WHAT_THROW_NONE
      {
         return mMessage.c_str();
      }

      ~ExpressionEvaluationException() OO_WHAT_THROW_NONE {};

      virtual int get_kind() const { return -502; }

   private:

      std::string mMessage;
};


//-----------------------------------------------------------------------------
// An exception that represents an expression tree construction error.
//-----------------------------------------------------------------------------
class OQ_STORAGE_SPECIFIER ExpressionConstructionException 
   : public ExpressionException 
{
  public:

    ExpressionConstructionException(const char* message, Expression* expression)
       : mMessage(message), mExpression(expression) {}

    const char* what() const OO_WHAT_THROW_NONE
    {
      return mMessage.c_str();
    }

    ~ExpressionConstructionException() OO_WHAT_THROW_NONE {};

    virtual int get_kind() const { return -502; }

  private:

    std::string mMessage;
    Expression* mExpression;
};

}/* end query namespace */} /* end objy namespace */

#endif

