//***************************************************************************//
//                                                                           //
//                Copyright © 2007 Objectivity Inc, USA.                     //
//                                                                           //
//    All Rights Reserved. Unauthorized use, duplication or distribution     //
//         of this software, or any portion of it, is prohibited.            //
//                                                                           //
//***************************************************************************//
#ifndef AttributeValueExpression_h 
#define AttributeValueExpression_h

#include "Expression.h"

class ooAttributeInt;
class ooAttributeWithPath;

namespace objy {namespace query
{

//-----------------------------------------------------------------------------
// Instances of AttributeValueExpression represent attribute values on the
// objects being qualified or those on related ones.
//-----------------------------------------------------------------------------
class OQ_STORAGE_SPECIFIER AttributeValueExpression : public Expression 
{
   public:
  
      // Constructor taking an attribute name optionally prefixed with the 
      // base class name; e.g. persion::name.
      AttributeValueExpression(const char* attributeName);

      // Constructor taking an ooAttributeWithPath
      AttributeValueExpression(const ooAttributeWithPath* awp);

      // Destructor
      ~AttributeValueExpression();

      // Returns the attribute's name.
      const char* getAttributeName() const;

      // Sets the attribute name to that specified.
      void setAttributeName(const char* attributeName);

      // Returns the expression's type (oocAttributeValueExpression).
      virtual ExpressionType getExpressionType() const
      { return oocAttributeValueExpression; }

      virtual void completeSetup(CompleteSetupContext& context);

      // Causes the expression to evaluate itself using the provided object and
      // place the result in the passed in result object.
      virtual void evaluate
       (const ooObjectBaseInt* object, ExpressionResult& result) const;

      // Calls visitAttributeValue on the passed in visitor passing in this
      // attribute value expression.
      virtual void accept(ExpressionVisitor& visitor)
      {visitor.visitAttributeValue(this);}

      // Returns a relative evaluation cost used to optimize the expression 
      // tree for minimum evaluation time.
      virtual unsigned getEvaluationCost() const;

      virtual Expression* clone(bool /*deep*/) const 
      {return new AttributeValueExpression(*this);}

      const ooAttributeWithPath* getAwp() const;

      bool attributeNameIsNotApplicationName() const;

      virtual bool isEqualTo(const Expression* other) const;

   protected:
   
      // Copy constructor (for clone())
      AttributeValueExpression( const AttributeValueExpression& other );

   private:
 
      char* mAttributeName; 
      ooAttributeAccessor* mAttributeAccessor;
      
      // set to true if the class context for this attribute is different than the original one
      bool mIsClassContextChanged;

      // cached values for performance
      uint32 mAccessType;
      uint32 mAttributeType;
      uint32 mBasicType;
      uint32 mStringType;
      const ooAttributeInt* mAttribute;

      // Prevent assignment 
      AttributeValueExpression& operator=( const AttributeValueExpression& rhs );

      virtual ExpressionResultSpec* computeResultSpec() const;

      const ooAttributeAccessor* getAttributeAccessor() const
      {return mAttributeAccessor;}

      void initializeCachedValues();

      friend class OperatorExpression;
};

}/* end query namespace */} /* end objy namespace */

#endif
