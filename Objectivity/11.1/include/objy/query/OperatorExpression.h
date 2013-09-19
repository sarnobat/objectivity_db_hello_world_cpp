//***************************************************************************//
//                                                                           //
//                Copyright © 2007 Objectivity Inc, USA.                     //
//                                                                           //
//    All Rights Reserved. Unauthorized use, duplication or distribution     //
//         of this software, or any portion of it, is prohibited.            //
//                                                                           //
//***************************************************************************//
#ifndef OperatorExpression_h 
#define OperatorExpression_h

#include "Expression.h"
#include "Operator.h"

namespace objy {namespace query
{

typedef ReferenceCountedHandle<OperatorExpression> OperatorExpressionHandle;

//-----------------------------------------------------------------------------
// Represents a list of operands owned by an operator.
//-----------------------------------------------------------------------------
class OQ_STORAGE_SPECIFIER OperandList
{
  public:
    // copy constructor
    OperandList
      (const OperandList& other, OperatorExpression* parent, bool deep);

    // Destructor
    ~OperandList();

    // Adds the specified operand to the enclosing operator expression
    // before the specified operand or at the end if it is 0.
    void addOperand
       (Expression* operand, const Expression* before = 0);

    // Adds the specified operand to the enclosing operator expression
    // at the specified position. The list is expanded if needed.  If an
    // operand exists at the specified position, it and all subsequent ones
    // are moved down in the list by one.
    void addOperand(Expression* operand, unsigned position);

    // Sets the operand to the specified position.  The list is expanded
    // if needed.  If an operand exists at the spedified position, it
    // is replaced.
    void setOperand(Expression* operand, unsigned position);

    // Returns the operand for the specified position, or null 
    // if none exists.
    Expression* getOperand(unsigned position) const;

    // Removes the specified operand. 
    // The caller is responsible for deleting the operand if it is not
    // later made the head of an expression tree or added as an operand
    // of another operand list.
    void removeOperand(Expression* operand);

    // Returns the total number of operands.
    unsigned getNumberOfOperands() const;

    // Returns the position of the operand within the list, or -1 if not 
    // found.
    int getPositionOfOperand(Expression* operand);

    OperatorExpression* getParentOperatorExpression()
    {return mParentOperatorExpression;}

  private:

    OperatorExpression* mParentOperatorExpression;

#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable : 4251)
#endif
    typedef std::vector<ExpressionHandle> VectorExpression;
    VectorExpression mOperandList;
#ifdef _MSC_VER
#pragma warning(pop)
#endif

    bool isOperandHeadOfExpressionTree(Expression* operand);

    // Prevent from construting by default constructor
    OperandList();

    // Prevent copy constructing or assignment
    OperandList& operator = (const OperandList& other);

    void setParentOperatorExpression(OperatorExpression* parentOperator)
    {mParentOperatorExpression = parentOperator;}

    friend class OperatorExpression;
};

//-----------------------------------------------------------------------------
// Instances of OperatorExpression represent operator nodes in the
// predicate expression tree.  Operator expressions have child expression 
// nodes (operands) and delegate to some registered Operator instance to
// perform its evaluation.
//-----------------------------------------------------------------------------
class OQ_STORAGE_SPECIFIER OperatorExpression : public Expression 
{
  public:

  // Constructor taking an optional token name
  OperatorExpression(const char* tokenName = 0);

  // Destructor
  ~OperatorExpression();

  // Returns the token name, or null if none has been assigned.
  const char* getTokenName() const;

  // Sets the operator to delegate to for evaluation. 
  // This method enables query builders and some non PQL parsers 
  // to set the operator explicitly instead of utilizing the automatic
  // operator selection based on token name and operand characteristics
  // performed durring complete setup.
  void setOperator(const Operator* op);

  // Returns the operator delegated to for evaluation.
  const Operator* getOperator() const
  { return mOperator; }

  // Returns the operand list, with which the operands can be retrieved.
  OperandList& getOperandList()
  {return mOperandList;}

  // Const version of above for users of const OperatorExpression*.
  const OperandList& getOperandList() const
  {return mOperandList;}

  // Returns the expression's type (oocOperatorExpression).
  virtual ExpressionType getExpressionType() const
  {return oocOperatorExpression;}

  virtual void completeSetup(CompleteSetupContext& context);

  // Causes the expression to evaluate itself using the provided object and
  // place the result in the passed in result object.
  virtual void evaluate
   (const ooObjectBaseInt* object, ExpressionResult& result) const;

  // Calls visitOperator on the passed in visitor passing in this operator
  // expression, and if that returns true calls accept on each operand 
  // passing in the visitor.
  virtual void accept(ExpressionVisitor& visitor);

  // Builds the LookupKey for the current operator expression, 
  // if find the optimized condition.
  void buildLookupKey(const ooHandle(ooObj) &sysOjbectH, 
                  const ooTypeNumber typeNumber, 
                  ooLookupKey* lookupKey); 

  // Sets if this is operator expression represents an infix operator   
  // when there are two operands rather than a function.
  void setIsInfix(bool value)
  {mIsInfix = value;}

  // Returns true if operator expression represents an infix operator;
  // false otherwise.
  bool isInfix() const
  {return mIsInfix;}

  // Sets if the operator expression has string literal operand
  void setHasStrLitOperand(bool value)
  {mHasStrLitOperand = value;}

  // Returns true if the operator expression has string literal operand
  bool hasStrLitOperand() const
  {return mHasStrLitOperand;}

  // Sets if the operator expression has float literal operand
  void setHasFloatLitOperand(bool value)
  {mHasFloatLitOperand = value;}

  // Returns true if the operator expression has float literal operand
  bool hasFloatLitOperand() const
  {return mHasFloatLitOperand;}

  // Sets if the operator expression has object literal operand
  void setHasObjectLitOperand(bool value)
  {mHasObjectLitOperand = value;}

  // Returns true if the operator expression has object literal operand
  bool hasObjectLitOperand() const
  {return mHasObjectLitOperand;}

  // Sets if the operator expression has been merged by merging optimization
  void setIsMerged(bool value)
  {mIsMerged = value;}

  // Returns true if the operator expression has been merged by merging optimization
  bool isMerged() const
  {return mIsMerged;}

  // Returns a relative evaluation cost used to optimize the expression 
  // tree for minimum evaluation time.
  virtual unsigned getEvaluationCost() const;

  // Optimize the expression tree for performance.
  virtual void optimize();

  // Sets the expression tree for this operator expression and its operands
  virtual void setExpressionTree(ExpressionTree* expressionTree);

  virtual Expression* clone(bool deep = true) const 
  {return new OperatorExpression(*this, deep);}

  virtual bool isEqualTo(const Expression* other) const;

  private:

  char* mTokenName;
  bool mIsInfix;
  uint32 mPrecedenceLevel;
  const Operator* mOperator;
  OperandList mOperandList;
  bool mHasStrLitOperand;
  bool mHasFloatLitOperand;
  bool mHasObjectLitOperand;
  bool mIsMerged;

  // Prevent copy constructing or assignment 
  OperatorExpression(const OperatorExpression& other, bool deep);
  OperatorExpression& operator=(const OperatorExpression& rhs);

  void setPrecedenceLevel(uint32 precedenceLevel)
  {mPrecedenceLevel = precedenceLevel;}

  uint32 precedenceLevel() const
  {return mPrecedenceLevel;}

  bool isAnInfixOperator() const
  {return mIsInfix && getOperandList().getNumberOfOperands() == 2;}

  virtual ExpressionResultSpec* computeResultSpec() const;

  const Operator* findContextChangingOperator(OperatorGroup* allMatchOperators, 
     CompleteSetupContext& context);

  const Operator* findNonContextChangingOperator(OperatorGroup* allMatchOperators, 
     CompleteSetupContext& context);

  // Functions related to the lookupKey to support building the index lookup key
  // (initially copied from oqrTree.cxx)

  // Creates the lookup field for the specified relational operation
  bool createLookupField(ooLookupFieldBase **ppField, ooRelatOp operation, 
                       ooTypeNumber typeN, const char *fieldName, void* valPtr);

  // Builds the LookupKey for regular expression case sensitive string match operator
  void buildREEQKey(const ooTypeNumber typeNumber, const char* fieldName, 
                    const char* REStr, ooLookupKey *lookupKey);

  // Builds the valid path lookup key field starting from this operator expression
  // (only applies to path operator expression)
  bool createPathKeyFieldName(std::string& validPathKeyFieldName);

  // Checks if the string starts with magic characters
  int nonMagic(char *ptr);

  // Get the successor char
  char oo_successor(char x);

  friend class AssignPrecendenceLevelsVisitor;
  friend class AdjustPrecendenceVisitor;

};

}/* end query namespace */} /* end objy namespace */

#endif
