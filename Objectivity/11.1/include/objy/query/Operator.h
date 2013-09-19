//***************************************************************************//
//                                                                           //
//                Copyright © 2007 Objectivity Inc, USA.                     //
//                                                                           //
//    All Rights Reserved. Unauthorized use, duplication or distribution     //
//         of this software, or any portion of it, is prohibited.            //
//                                                                           //
//***************************************************************************//
#ifndef Operator_h
#define Operator_h

#include "ObjectQualificationSS.h"
#include "ExpressionResult.h"
#include "ExpressionSetupError.h"


class ooAttributeWithPath;
class ooExtensionPoint;

namespace objy {namespace query
{

// global function
// memoery allocated for the returned string
char* toLowerString(const char* strToConvert);
char* toUpperString(const char* strToConvert);

class OperatorExpression;
class CompleteSetupContext;

//-----------------------------------------------------------------------------
// Enum capturing the different operator presentation types for PQL sting.
enum OperatorPresentationType
{
  oocUnaryOperatorPresentation,
  oocBinaryOperatorPresentation,
  oocFunctionOperatorPresentation,
  oocPathOperatorPresentation,
  oocSubscriptOperatorPresentation,
  oocNameMapLookupOperatorPresentation
};

//-----------------------------------------------------------------------------
// Instances of Operator derived classes are delegated to by instances of 
// OperatorExpression to perform node value evaluation.
class OQ_STORAGE_SPECIFIER Operator
{
   public:

      enum StandardBehavior
      {
        NONE,
        AND,
        EQUAL,
        LESS_THAN,
        GREATER_THAN,
        LESS_THAN_OR_EQUAL,
        GREATER_THAN_OR_EQUAL,
        MATCH,
        PATH
      };
  
      // Constuctor
      Operator();

      // Destructor
      virtual ~Operator(){};

      // Returns the operator's name.
      const char* getName() const
      {return mName;}

      // Returns the operator's tokens list.
      NameList& getTokens()
      {return mTokens;}

      // Const version of above for users of const Operator*.
      const NameList& getTokens() const
      {return mTokens;}

      // Returns the operator's description.
      const char* getDescription() const
      {return mDescription;}

      // Operators whose behavior conforms to a standard behavior can and
      // are recommended to override this method to provide an indication 
      // what that standard behavior is.
      // By doing so they make their operands available for possible index
      // evaluation.
      virtual StandardBehavior getStandardBehavior() const
      {return NONE;}

      // Returns true if the operator changes the class context; false otherwise.
      bool getDoesChangeClassContext() const
      {return mDoesChangeClassContext;}

      // Returns the minimum number of operands the operator requires.
      int getMinNumberOfOperands() const
      {return mMinNumberOfOperands;}

      // Returns the maximum number of operands the operator can take,
      // or 0 for no limit.
      int getMaxNumberOfOperands() const
      {return mMaxNumberOfOperands;}

      // Returns the result spec of the operator.
      const ExpressionResultSpec& getResultSpec() const
      {return mResultSpec;}

      // Returns the precedence level of the operator with 1 being the highest 
      // (higher numbers indicating lower precedence) 
      // and 0 indicating undefined. An undefined precedence is automatically 
      // equal to the lowest precedence.
      // Note: this value only pertains to binary operators used as infix 
      // operators, i.e. not as two input functions.  The precedence for all
      // other operators is set in the grammar.
      unsigned getPrecedenceLevel() const
      {return mPrecedenceLevel;}

      // Returns the valid result spec for the specified operand number.
      virtual ExpressionResultSpec getValidOperandResultSpec
         (int operandNumber) const = 0;

      // Returns the specific result spec for the specified 
      // OperatorExpression. This only needs to be overridden by operators
      // whose result spec depends on the actual result specs of its operands.
      virtual ExpressionResultSpec* computeSpecificResultSpec
         (const OperatorExpression* operatorExpression) const
      {return new ExpressionResultSpec(mResultSpec);}

      // Evaluates the result for the specified OperatorExpression against
      // the specified object.
      virtual void evaluate(const OperatorExpression* operatorExpression,
         const ooObjectBaseInt* object, ExpressionResult& result) const = 0;

      // This virtual function needs to be overridden by operators whose 
      // mDoesChangeClassContext property is set to true to do top-down 
      // comleteSetup; or operators that need additional validation at the 
      // operator level. 
      virtual void completeSetup(OperatorExpression* 
                                    operatorExpression, 
                                 CompleteSetupContext& context) const
      {};

      // Returns the operator presentation's type in a PQL string 
      // as represented by the enumeration OperatorPresentationType.
      // Note: Operators need to override this function only if the  
      // presentation type is different than: 
      //    1 operand --- oocUnaryOperatorPresentation, 
      //    2 operands --- oocBinaryOperatorPresentation, 
      //    3 or more operands --- oocFunctionOperatorPresentation.
      virtual OperatorPresentationType getPresentationType
         (const OperatorExpression* operatorExpression) const;

      // Returns a relative evaluation cost used to optimize the expression 
      // tree for minimum evaluation time.
      virtual unsigned getEvaluationCost
         (const OperatorExpression* operatorExpression) const
      {return 1;}

      // Optimize the operator expression.
      // Overridden only by operators who can improve performance by
      // changing the given operator expression.
      virtual void optimize(OperatorExpression* operatorExpression) const
      {}

   protected:

      // Sets the operator's properties.
      void setProperties(const char* name, const char* description, 
            bool doesChangeClassContext, int minNumberOfOperands, 
            int maxNumberOfOperands, const ExpressionResultSpec& resultSpec,
            unsigned precedenceLevel = 0 /*undefined*/);

      void addToken(const char* token);

      // Perform optimizaton by merging the operands of operands using the
      // same operator and removing those operands if mergeLikeOperands is
      // true and by sorting the operands so that the lower cost operands
      // come before higher cost ones if sortForLowestCost is true.
      void doOptimize(OperatorExpression* operatorExpression,
                      bool mergeLikeOperands, bool sortForLowestCost) const;

      // Set the preferred type of string literals so as to avoid comparisons
      // between different string types whenever possible.
      static void normalizeLiteralOperandStringTypes
         (const OperatorExpression* operatorExpression);

      // Set the preferred type of float literals
      static void normalizeLiteralOperandFloatTypes
         (const OperatorExpression* operatorExpression);

      // Check if all operands result types are compatible types.
      static void ensureAllOperandsAreCrossCompatible
         (const OperatorExpression* operatorExpression,
          ExpressionSetupErrorHandler* errorHandler);

   protected:
      ExpressionResultSpec mResultSpec;

   private:

      //======================================================================================
      // - If symbolic token exists, add it as the first in the token list (required by Assist)
      // - For operators that merge optimization could be applied; add a name token as the 2nd
      //   in the token list(required by generatePQLRepresentation())
      //======================================================================================
      NameList mTokens;

      const char* mName;
      const char* mDescription;
      bool mDoesChangeClassContext;
      int mMinNumberOfOperands;
      int mMaxNumberOfOperands;
      unsigned mPrecedenceLevel; 

      // Prevent copy constructing or assignment
      Operator(const Operator& other);
      Operator& operator = (const Operator& other);

};

//-----------------------------------------------------------------------------
// A group of operators.
class OQ_STORAGE_SPECIFIER OperatorGroup
{
   public:

      // Constructor
      OperatorGroup(const char* operatorGroupName);

      // Destructor
      ~OperatorGroup();

      // Returns the operator group's name.
      const char* getName() const;

      // Adds a specified operator to the group.
      void addOperator(const Operator* op);

      // Removes the specified operator from the group.
      void removeOperator(const Operator* op);

      // Returns the total number of operators in the group.
      int getNumberOfOperators() const;

      // Returns the operator for the specified index. 
      const Operator* getOperator(int index) const;

      // Returns the operator with the specified operator name
      const Operator* getOperator(const char* operatorName) const;

   private:
      
      char* mOptGroupName;
      bool mDoesOwnOperators;

      // Constructor 
      OperatorGroup(bool doesOwnOperators)
         : mOptGroupName(0), mDoesOwnOperators(doesOwnOperators) {}

#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable : 4251)
#endif
      typedef std::vector<const Operator*> VectorOperator;
      VectorOperator mOperatorList;
#ifdef _MSC_VER
#pragma warning(pop)
#endif

      // Prevent copy constructing or assignment
      OperatorGroup(const OperatorGroup& other);
      OperatorGroup& operator = (const OperatorGroup& other);


      friend class OperatorGroupRegistry;
      friend class OperatorExpression;

};

//-----------------------------------------------------------------------------
// A global registry for operator groups. 
class OQ_STORAGE_SPECIFIER OperatorGroupRegistry
{
   public:

      // Creates an operator group with the specified name and 
      // adds it to the registry.
      static OperatorGroup* createAddOperatorGroup(const char* name);

      // Removes the specified operator group.
      static void removeOperatorGroup(const OperatorGroup* group);

      // Returns the total number of operator groups.
      static int getNumberOfOperatorGroups();

      // Returns the operator group for the specified index.
      static OperatorGroup* getOperatorGroup(int index);

      // Returns the operator group with the specified name, 
      // or null if no such group exists.
      static OperatorGroup* getOperatorGroup(const char* name);

      // Returns all operators that have a result type compatible with that 
      // specified.
      // The caller is responsible for deleting the returned group.
      static OperatorGroup* getCompatibleOperators
         (const ExpressionResultSpec& resultType);

      // Returns all operators having a token name that matches the specified 
      // tokenName. The operator groups in the registry are iterated in reverse
      // order, so the later overloaded operators are looked up first. 
      // This method is called from OperatorExpression::completSetup() to get
      // all matching operators by token in order to perform the operator lookup.
      // The caller is responsible for deleting the returned group.
      static OperatorGroup* getMatchingOperators(const char* tokenName);

   private:

      static bool smIsInitialized;

#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable : 4251)
#endif
      typedef std::vector<OperatorGroup*> VectorOperatorGroup;
      static VectorOperatorGroup smOperatorGroupList;
#ifdef _MSC_VER
#pragma warning(pop)
#endif

      static void initializeIfNeeded();
      static void initialize();
      static void initializeCustomOperator();

      // The following is to allow the operator group registry to initially 
      // register the default and custom plugin operators without triggering
      // a recursive initializeIfNeeded() call. 
      // There should be no reason to use it for any other purpose.
      static OperatorGroup* getOperatorGroupInternal(const char* name);

      static ooExtensionPoint* smOperatorExtensionPoint;

      friend class RegisterOperator;

};

//-----------------------------------------------------------------------------
// The following class and macro simplifies operator registration
class RegisterOperator
{
   public:
      RegisterOperator(const char* groupName, const Operator* op)
      {
         OperatorGroup* group = 
            const_cast<OperatorGroup*>
            (OperatorGroupRegistry::getOperatorGroupInternal(groupName));
         if (!group)
         {
            group = OperatorGroupRegistry::createAddOperatorGroup(groupName);   
         }
         group->addOperator(op);
      }
};

#define RegisterOperator(groupName, operatorClass) \
{ \
   RegisterOperator reg(groupName, new operatorClass); \
}

//-----------------------------------------------------------------------------
// The following two global functions are provided to give limitited access for the opaque class ooObjectBaseInt
OQ_STORAGE_SPECIFIER ooHandle(ooObj)& ooGetObjectHandle(const ooObjectBaseInt*);
OQ_STORAGE_SPECIFIER ooTypeNumber ooGetShapeNumber(const ooObjectBaseInt*);

}/* end query namespace */} /* end objy namespace */

#endif
