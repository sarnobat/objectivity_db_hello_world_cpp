//***************************************************************************//
//                                                                           //
//                Copyright © 2007 Objectivity Inc, USA.                     //
//                                                                           //
//    All Rights Reserved. Unauthorized use, duplication or distribution     //
//         of this software, or any portion of it, is prohibited.            //
//                                                                           //
//***************************************************************************//
#ifndef LiteralValueExpressions_h 
#define LiteralValueExpressions_h

#include "Expression.h"
#include "AttributeValueExpression.h"

class ooShapeInt;

namespace objy {namespace query
{
//-----------------------------------------------------------------------------
// A base class for values that are part of the predicate expression
// (not obtained via a calculation or from the object being qualified).
//-----------------------------------------------------------------------------
class OQ_STORAGE_SPECIFIER LiteralValueExpression : public Expression 
{
   public:
   
      LiteralValueExpression()
         : mVariableName(0), mIsValueSet(false) {}

      virtual ~LiteralValueExpression()
      { delete[] mVariableName; }

      // Returns the variable name
      const char* getVariableName()
      { return mVariableName;}

      // Sets the variable name if literal is defined as variable
      void setVariableName(const char* variableName);

      bool isValueSet()
      { return mIsValueSet; }

      // Sets the literal value from ExpressionResult
      virtual void setValue(const ExpressionResult& valueResult) = 0;

      virtual void completeSetup(CompleteSetupContext& context);

      virtual void evaluate
       (const ooObjectBaseInt* object, ExpressionResult& result) const;

   protected:

      // Copy constructor (for clone())
      LiteralValueExpression( const LiteralValueExpression& other );

      // Returns a relative evaluation cost used to optimize the expression 
      // tree for minimum evaluation time.
      virtual unsigned getEvaluationCost() const
      {return 1;}

      // variable name for literal defined as variable 
      char* mVariableName;

      // flag to indicate if the literal value is set
      bool mIsValueSet;

   private:

    // Prevent assignment
    LiteralValueExpression& operator = (const LiteralValueExpression& other);

};

//-----------------------------------------------------------------------------
// A boolean literal value.
//-----------------------------------------------------------------------------
class OQ_STORAGE_SPECIFIER BoolLiteralValueExpression 
  : public LiteralValueExpression
{
  public:

    // Default constructor
    BoolLiteralValueExpression() {}

    // Constructor taking a bool value
    BoolLiteralValueExpression(bool value) : mValue(value) 
    {mIsValueSet = true;}

    // Returns the bool literal value
    bool getValue() const
    {return mValue;}

    // Sets the bool literal value.
    void setValue(bool value)
    {mValue = value;  mIsValueSet = true; onChanged();
    }

    // Sets the literal value from ExpressionResult
    virtual void setValue(const ExpressionResult& valueResult);

    // Returns the expression's type (oocBoolLiteralExpression).
    virtual ExpressionType getExpressionType() const
    {return oocBoolLiteralValueExpression;}

    // Returns the expression's result type (oocQBoolType, isLiteral=true)
    virtual ExpressionResultSpec* computeResultSpec() const
    {return new ExpressionResultSpec(oocQBool, true);}

    // Causes the expression to evaluate itself using the provided object and
    // place the result in the passed in result object.
    virtual void evaluate
     (const ooObjectBaseInt* object, ExpressionResult& result) const
    { LiteralValueExpression::evaluate(object, result); 
      result.setBoolResult(mValue);}

    // Calls visitBoolLiteralValue on the passed in visitor passing in this
    // bool literal value expression.
    virtual void accept(ExpressionVisitor& visitor) 
    {visitor.visitBoolLiteralValue(this);}

    virtual Expression* clone(bool /*deep*/) const 
    { return new BoolLiteralValueExpression( *this ); }

    virtual bool isEqualTo(const Expression* other) const;

  protected:

    // Copy constructor (for clone)
    BoolLiteralValueExpression( const BoolLiteralValueExpression& other )
      : LiteralValueExpression( other ), mValue( other.mValue )
    {
    }

  private:

    bool mValue;

    // Prevent assignment
    BoolLiteralValueExpression& operator=( const BoolLiteralValueExpression& rhs );
};

//-----------------------------------------------------------------------------
// A string literal value.
//-----------------------------------------------------------------------------
class OQ_STORAGE_SPECIFIER StringLiteralValueExpression
  : public LiteralValueExpression
{
  public:

    // Default constructor
    StringLiteralValueExpression()
       : m8BitValue(0) {}

    // Constructor taking a 8-bit or UTF-8 string value.
    StringLiteralValueExpression(const char* value) ;

    // Constructor taking a wide string value.
    StringLiteralValueExpression(const wchar_t* value) ;

    // Destructor
    virtual ~StringLiteralValueExpression();

    // Sets the string literal value to that specified 8-bit string
    // (the value is copied).
    void setValue(const char* value);

    // Sets the string literal values to that specified wide string
    // (the value is copied).
    void setValue(const wchar_t* value);

    // Sets the literal value from ExpressionResult
    virtual void setValue(const ExpressionResult& valueResult);

    // Returns the string literal value as char*.
    const char* get8BitValue() const
    {return m8BitValue;}

    // Returns the string literal value as UTF-8.
    const ooUtf8String& getUtf8Value() const
    {return mUtf8Value;}

    // Returns the string literal value as UTF-16.
    const ooUtf16String& getUtf16Value() const
    {return mUtf16Value;}

    // Returns the string literal value as UTF-32.
    const ooUtf32String& getUtf32Value() const
    {return mUtf32Value;}

    // Returns the string literal value as wchar_t*.
    const wchar_t* getWStringValue() const;

    // Returns the expression's type (oocStringLiteralExpression).
    virtual ExpressionType getExpressionType() const
    {return oocStringLiteralValueExpression;}

    // Returns the expression's result type.
    virtual ExpressionResultSpec* computeResultSpec() const;

    // Causes the expression to evaluate itself using the provided object and
    // place the result in the passed in result object.
    virtual void evaluate
     (const ooObjectBaseInt* object, ExpressionResult& result) const;

    // Calls visitStringLiteralValue on the passed in visitor passing in this
    // string literal value expression.
    virtual void accept(ExpressionVisitor& visitor)
    {visitor.visitStringLiteralValue(this);}

    virtual Expression* clone(bool /*deep*/) const 
    { return new StringLiteralValueExpression( *this ); }

    virtual bool isEqualTo(const Expression* other) const;

  protected:

    // Copy constructor (for clone)
    StringLiteralValueExpression( const StringLiteralValueExpression& other );

  private:

    char* m8BitValue;
    ooUtf8String mUtf8Value;
    ooUtf16String mUtf16Value;
    ooUtf32String mUtf32Value;
    QDataType mPreferredEvaluateType;

    // Prevent assignment
    StringLiteralValueExpression& operator=( const StringLiteralValueExpression& rhs );

    void setPreferredEvaluateType(QDataType preferred)
    {mPreferredEvaluateType = preferred;}

    void assignTo8bitValue();

    // Sets the string literal value to that specified Utf8String
    void setValueFromUtf8(const char* value);

    // Sets the string literal value to that specified Utf16String
    void setValueFromUtf16(const ooChar16* value);

    // Sets the string literal value to that specified Utf32String
    void setValueFromUtf32(const ooChar32* value);

    friend class Operator;
    friend class SetEqualityOperator;

};

#define setValueFromUtf\
   mUtf8Value = value;\
   mUtf16Value = value;\
   mUtf32Value = value;\
   assignTo8bitValue();\
   mIsValueSet = true;\
   onChanged();\

//-----------------------------------------------------------------------------
// An int literal value.
//-----------------------------------------------------------------------------
class OQ_STORAGE_SPECIFIER IntLiteralValueExpression
  : public LiteralValueExpression
{
  public:

    // Default constructor
    IntLiteralValueExpression() {}

    // Constructor taking an int value
    IntLiteralValueExpression(int64 value) : mValue(value)
    {mIsValueSet = true;}

    // Returns the int literal value.
    int64 getValue() const
    {return mValue;}

    // Sets the int literal value.
    void setValue(int64 value)
    {mValue = value; mIsValueSet = true; onChanged();
    }

    // Sets the literal value from ExpressionResult
    virtual void setValue(const ExpressionResult& valueResult);

    // Returns the expression's type (oocIntLiteralExpression).
    virtual ExpressionType getExpressionType() const
    {return oocIntLiteralValueExpression;}

    // Returns the expression's result type (oocQInt, isLiteral=true)
    virtual ExpressionResultSpec* computeResultSpec() const
    {return new ExpressionResultSpec(oocQInt, true);}

    // Causes the expression to evaluate itself using the provided object and
    // place the result in the passed in result object.
    virtual void evaluate
    (const ooObjectBaseInt* object, ExpressionResult& result) const
    {LiteralValueExpression::evaluate(object, result); 
     result.setIntResult(mValue);}

    // Calls visitIntLiteralValue on the passed in visitor passing in this
    // int literal value expression.
    virtual void accept(ExpressionVisitor& visitor) 
    {visitor.visitIntLiteralValue(this);}  

    virtual Expression* clone(bool /*deep*/) const
    { return new IntLiteralValueExpression( *this ); }

    virtual bool isEqualTo(const Expression* other) const;

  protected:

    // Copy constructor (for clone)
    IntLiteralValueExpression( const IntLiteralValueExpression& other )
       : LiteralValueExpression( other ), mValue( other.mValue )
    {
    }

  private:
    int64 mValue;

    // Prevent assignment
    IntLiteralValueExpression& operator=( const IntLiteralValueExpression& rhs );
};

//-----------------------------------------------------------------------------
// A uint literal value.
//-----------------------------------------------------------------------------
class OQ_STORAGE_SPECIFIER UIntLiteralValueExpression
  : public LiteralValueExpression
{
  public:

    // Default constructor
    UIntLiteralValueExpression() {}

    // Constructor taking an unsigned int value.
    UIntLiteralValueExpression(uint64 value) : mValue(value)
    {mIsValueSet = true;}

    // Returns the unsigned int literal value
    uint64 getValue() const
    {return mValue;}

    // Sets the unsigned int literal value.
    void setValue(uint64 value)
    {mValue = value; mIsValueSet = true; onChanged();
    }

    // Sets the literal value from ExpressionResult
    virtual void setValue(const ExpressionResult& valueResult);

    // Returns the expression's type (oocUIntLiteralExpression).
    virtual ExpressionType getExpressionType() const
    {return oocUIntLiteralValueExpression;}

    // Returns the expression's result type (oocQUInt, isLiteral=true)
    virtual ExpressionResultSpec* computeResultSpec() const
    {return new ExpressionResultSpec(oocQUInt, true);}

    // Causes the expression to evaluate itself using the provided object and
    // place the result in the passed in result object.
    virtual void evaluate
    (const ooObjectBaseInt* object, ExpressionResult& result) const
    {LiteralValueExpression::evaluate(object, result); 
     result.setUIntResult(mValue);}

    // Calls visitUIntLiteralValue on the passed in visitor passing in this
    // uint literal value expression.
    virtual void accept(ExpressionVisitor& visitor) 
    {visitor.visitUIntLiteralValue(this);}     

    virtual Expression* clone(bool /*deep*/) const 
    { return new UIntLiteralValueExpression( *this ); }

    virtual bool isEqualTo(const Expression* other) const;

  protected:

    // Copy constructor (for clone)
    UIntLiteralValueExpression( const UIntLiteralValueExpression& other )
       : LiteralValueExpression( other ), mValue( other.mValue )
    {
    }

  private:

    uint64 mValue;

    // Prevent assignment
    UIntLiteralValueExpression& operator=( const UIntLiteralValueExpression& rhs );
};

//-----------------------------------------------------------------------------
// A float literal value.
//-----------------------------------------------------------------------------
class OQ_STORAGE_SPECIFIER FloatLiteralValueExpression
  : public LiteralValueExpression
{
  public:

    // Default constructor
    FloatLiteralValueExpression() {}

    // Constructor taking an float value.
    FloatLiteralValueExpression(float64 value);

    // Returns the float literal value as float64.
    float32 getFloat32Value() const
    {return mFloat32Value;}

    // Returns the float literal value as float64.
    float64 getFloat64Value() const
    {return mFloat64Value;}
    
    // Sets the float32 literal value.
    void setValue(float32 value);

    // Sets the float64 literal value.
    void setValue(float64 value);

    // Sets the literal value from ExpressionResult
    virtual void setValue(const ExpressionResult& valueResult);

    // Returns the expression's type (oocFloatLiteralExpression).
    virtual ExpressionType getExpressionType() const
    {return oocFloatLiteralValueExpression;}

    // Returns the expression's result type (oocQFloat, isLiteral=true)
    virtual ExpressionResultSpec* computeResultSpec() const
    {return new ExpressionResultSpec(oocQFloat, true);}

    // Causes the expression to evaluate itself using the provided object and
    // place the result in the passed in result object.
    virtual void evaluate
    (const ooObjectBaseInt* object, ExpressionResult& result) const;

    // Calls visitFloatLiteralValue on the passed in visitor passing in this
    // float literal value expression.
    virtual void accept(ExpressionVisitor& visitor)
    {visitor.visitFloatLiteralValue(this);}      

    virtual Expression* clone(bool /*deep*/) const
    { return new FloatLiteralValueExpression( *this ); }

    virtual bool isEqualTo(const Expression* other) const;

  protected:

    // Copy constructor (for clone)
    FloatLiteralValueExpression( const FloatLiteralValueExpression& other )
       : LiteralValueExpression( other ), mFloat32Value( other.mFloat32Value ),
         mFloat64Value( other.mFloat64Value ), mPreferredEvaluateType( other.mPreferredEvaluateType )
    {
    }

  private:
    float32 mFloat32Value;
    float64 mFloat64Value;
    QDataType mPreferredEvaluateType;

    // Prevent assignment
    FloatLiteralValueExpression& operator=( const FloatLiteralValueExpression& rhs );

    void setPreferredEvaluateType(QDataType preferred)
    {mPreferredEvaluateType = preferred;}

    friend class Operator;
};

//-----------------------------------------------------------------------------
// A date literal value.
//-----------------------------------------------------------------------------
class OQ_STORAGE_SPECIFIER DateLiteralValueExpression
  : public LiteralValueExpression
{
  public:

    // Default constructor
    DateLiteralValueExpression() {}

    // Constructor taking a date value.
    DateLiteralValueExpression(ooDate value) : mValue(value)
    {mIsValueSet = true;}

    // Returns the date literal value.
    ooDate getValue() const
    {return mValue;}

    // Sets the date literal value.
    void setValue(ooDate value)
    {mValue = value; mIsValueSet = true; onChanged();
    }

    // Sets the literal value from ExpressionResult
    virtual void setValue(const ExpressionResult& valueResult);

    // Returns the expression's type (oocDateLiteralExpression).
    virtual ExpressionType getExpressionType() const
    {return oocDateLiteralValueExpression;}

    // Returns the expression's result type (oocQDate, isLiteral=true)
    virtual ExpressionResultSpec* computeResultSpec() const
    {return new ExpressionResultSpec(oocQDate, true);}

    // Causes the expression to evaluate itself using the provided object and
    // place the result in the passed in result object.
    virtual void evaluate
    (const ooObjectBaseInt* object, ExpressionResult& result) const
    {LiteralValueExpression::evaluate(object, result); 
     result.setDateResult(mValue);}

    // Calls visitDateLiteralValue on the passed in visitor passing in this
    // date literal value expression.
    virtual void accept(ExpressionVisitor& visitor)
    {visitor.visitDateLiteralValue(this);}      

    virtual Expression* clone(bool /*deep*/) const
    { return new DateLiteralValueExpression( *this ); }

    virtual bool isEqualTo(const Expression* other) const;

  protected:

    // Copy constructor (for clone)
    DateLiteralValueExpression( const DateLiteralValueExpression& other )
       : LiteralValueExpression( other ), mValue( other.mValue )
    {
    }

  private:

    ooDate mValue;

    // Prevent assignment
    DateLiteralValueExpression& operator=( const DateLiteralValueExpression& rhs );
};

//-----------------------------------------------------------------------------
// A time literal value.
//-----------------------------------------------------------------------------
class OQ_STORAGE_SPECIFIER TimeLiteralValueExpression
  : public LiteralValueExpression
{
  public:

    // Default constructor
    TimeLiteralValueExpression() {}

    // Constructor taking a time value.
    TimeLiteralValueExpression(ooTime value) : mValue(value)
    {mIsValueSet = true;}

    // Returns the time literal value.
    ooTime getValue() const
    {return mValue;}

    // Sets the time literal value.
    void setValue(ooTime value)
    {mValue = value; mIsValueSet = true; onChanged();
    }

    // Sets the literal value from ExpressionResult
    virtual void setValue(const ExpressionResult& valueResult);

    // Returns the expression's type (oocTimeLiteralExpression).
    virtual ExpressionType getExpressionType() const
    {return oocTimeLiteralValueExpression;}

    // Returns the expression's result type (oocQTime, isLiteral=true)
    virtual ExpressionResultSpec* computeResultSpec() const
    {return new ExpressionResultSpec(oocQTime, true);}

    // Causes the expression to evaluate itself using the provided object and
    // place the result in the passed in result object.
    virtual void evaluate
    (const ooObjectBaseInt* object, ExpressionResult& result) const
    {LiteralValueExpression::evaluate(object, result);
     result.setTimeResult(mValue);}

    // Calls visitTimeLiteralValue on the passed in visitor passing in this
    // time literal value expression.
    virtual void accept(ExpressionVisitor& visitor)
    {visitor.visitTimeLiteralValue(this);}      

    virtual Expression* clone(bool /*deep*/) const
    { return new TimeLiteralValueExpression( *this ); }

    virtual bool isEqualTo(const Expression* other) const;

  protected:

    // Copy constructor (for clone)
    TimeLiteralValueExpression( const TimeLiteralValueExpression& other )
       : LiteralValueExpression( other ), mValue( other.mValue )
    {
    }

  private:

    ooTime mValue;

    // Prevent assignment
    TimeLiteralValueExpression& operator=( const TimeLiteralValueExpression& rhs );
  };

//-----------------------------------------------------------------------------
// A date/time literal value.
//-----------------------------------------------------------------------------
class OQ_STORAGE_SPECIFIER DateTimeLiteralValueExpression
  : public LiteralValueExpression
{
  public:

    // Default constructor
    DateTimeLiteralValueExpression() {}

    // Constructor taking a date/time value.
    DateTimeLiteralValueExpression(ooDateTime value) : mValue(value)
    {mIsValueSet = true;}

    // Returns the date/time literal value.
    ooDateTime getValue() const
    {return mValue;}

    // Sets the date/time literal value.
    void setValue(ooDateTime value)
    {mValue = value; mIsValueSet = true; onChanged();
    }

    // Sets the literal value from ExpressionResult
    virtual void setValue(const ExpressionResult& valueResult);

    // Returns the expression's type (oocDateTimeLiteralExpression).
    virtual ExpressionType getExpressionType() const
    {return oocDateTimeLiteralValueExpression;}

    // Returns the expression's result type (oocQDateTime, isLiteral=true)
    virtual ExpressionResultSpec* computeResultSpec() const
    {return new ExpressionResultSpec(oocQDateTime, true);}

    // Causes the expression to evaluate itself using the provided object and
    // place the result in the passed in result object.
    virtual void evaluate
    (const ooObjectBaseInt* object, ExpressionResult& result) const
    {LiteralValueExpression::evaluate(object, result); 
     result.setDateTimeResult(mValue);}

    // Calls visitDateTimeLiteralValue on the passed in visitor passing in
    // this date/time literal value expression.
    virtual void accept(ExpressionVisitor& visitor)
    {visitor.visitDateTimeLiteralValue(this);}      

    virtual Expression* clone(bool /*deep*/) const
    { return new DateTimeLiteralValueExpression( *this ); }

    virtual bool isEqualTo(const Expression* other) const;

  protected:

    // Copy constructor (for clone)
    DateTimeLiteralValueExpression( const DateTimeLiteralValueExpression& other )
       : LiteralValueExpression( other ), mValue( other.mValue )
    {
    }

  private:

    ooDateTime mValue;

    // Prevent assignment
    DateTimeLiteralValueExpression& operator=( const DateTimeLiteralValueExpression& rhs );
};

//-----------------------------------------------------------------------------
// An interval literal value.
//-----------------------------------------------------------------------------
class OQ_STORAGE_SPECIFIER IntervalLiteralValueExpression
  : public LiteralValueExpression
{
  public:

    // Default constructor
    IntervalLiteralValueExpression() {}

    // Constructor taking an interval value.
    IntervalLiteralValueExpression(ooInterval value) : mValue(value)
    {mIsValueSet = true;}

    // Returns the interval literal value.
    ooInterval getValue() const
    {return mValue;}

    // Sets the interval literal value.
    void setValue(ooInterval value)
    {mValue = value; mIsValueSet = true; onChanged();
    }

    // Sets the literal value from ExpressionResult
    virtual void setValue(const ExpressionResult& valueResult);

    // Returns the expression's type (oocIntervalLiteralExpression).
    virtual ExpressionType getExpressionType() const
    {return oocIntervalLiteralValueExpression;}

    // Returns the expression's result type (oocQInterval, isLiteral=true)
    virtual ExpressionResultSpec* computeResultSpec() const
    {return new ExpressionResultSpec(oocQInterval, true);}

    // Causes the expression to evaluate itself using the provided object and
    // place the result in the passed in result object.
    virtual void evaluate
    (const ooObjectBaseInt* object, ExpressionResult& result) const
    {LiteralValueExpression::evaluate(object, result); 
     result.setIntervalResult(mValue);}

    // Calls visitIntervalLiteralValue on the passed in visitor passing in this
    // interval literal value expression.
    virtual void accept(ExpressionVisitor& visitor)
    {visitor.visitIntervalLiteralValue(this);}      

    virtual Expression* clone(bool /*deep*/) const
    { return new IntervalLiteralValueExpression( *this ); }

    virtual bool isEqualTo(const Expression* other) const;

  protected:

    // Copy constructor (for clone)
    IntervalLiteralValueExpression( const IntervalLiteralValueExpression& other )
       : LiteralValueExpression( other ), mValue( other.mValue )
    {
    }

  private:

    ooInterval mValue;

    // Prevent assignment
    IntervalLiteralValueExpression& operator=( const IntervalLiteralValueExpression& rhs );
};

class OrderedListLiteralCollection;

//-----------------------------------------------------------------------------
// An ordered list literal value.
// TODO: if the element type is other than oocQNumeric or oocQString, then  
// an exception should be thrown. Define that exception. Also need an 
// exception if the collection is not homogonous.
//-----------------------------------------------------------------------------
class OQ_STORAGE_SPECIFIER OrderedListLiteralValueExpression
  : public LiteralValueExpression
{
  public:

    // Constructor taking an element data type
    OrderedListLiteralValueExpression(QDataType elementType);

    // Destructor 
    virtual ~OrderedListLiteralValueExpression();

    // Returns the ordered list literal value.
    const QCollection* getValue() const;

    // Returns the element type
    const QDataType getElementType()
    {return mElementType;}

    // Adds a value to the ordered list literal value at the specified index
    // or at the end if index == -1.
    void addElement(LiteralValueExpression* value, int index = -1);

    // Sets a value in the ordered list literal value at the specified index.
    // Does nothing if index is not within the range of the collection.
    void setElement(int index, LiteralValueExpression* value);

    // Removes the value at the specified index.
    // Does nothing if index is not within the range of the collection.
    void removeElement(int index);

    // Removes all values from the collection.
    void clear();

    // Returns the expression's type (oocOrderedListLiteralValueExpression).
    virtual ExpressionType getExpressionType() const
    {return oocOrderedListLiteralValueExpression;}

    // Returns the expression's result type 
    //   (oocQOrderedList[elementType], isLiteral=true)
    virtual ExpressionResultSpec* computeResultSpec() const;

    // Causes the expression to evaluate itself using the provided object and
    // place the result in the passed in result object.
    virtual void evaluate
      (const ooObjectBaseInt* object, ExpressionResult& result) const;

    // Calls visitOrderedListLiteralValue on the passed in visitor passing in
    // this ordered list literal value expression.
    virtual void accept(ExpressionVisitor& visitor);  

    virtual void completeSetup(CompleteSetupContext& context);

    virtual Expression* clone(bool /*deep*/) const
    { return new OrderedListLiteralValueExpression( *this ); }

    virtual bool isEqualTo(const Expression* other) const;

  private:

    OrderedListLiteralCollection* mValue;
    QDataType mElementType;

    // prevent calling default constructor
    OrderedListLiteralValueExpression();

    // Prevent copy constructing & assignment
    OrderedListLiteralValueExpression(const OrderedListLiteralValueExpression& other);
    OrderedListLiteralValueExpression& 
      operator=( const OrderedListLiteralValueExpression& rhs );

    // Sets the literal value from ExpressionResult (not supported)
    virtual void setValue(const ExpressionResult& valueResult) {}

};

//-----------------------------------------------------------------------------
// A classType literal value.
//-----------------------------------------------------------------------------
class OQ_STORAGE_SPECIFIER ClassTypeLiteralValueExpression 
  : public LiteralValueExpression
{
  public:

    // Default constructor
    ClassTypeLiteralValueExpression() 
       : mClassName(0), mClassType(0), mShape(0) {}

    // Constructor taking a class name for the class type
    ClassTypeLiteralValueExpression(const char* className);

    ClassTypeLiteralValueExpression(ooTypeNumber classType)
       : mClassType(classType), mClassName(0), mShape(0)
   {mIsValueSet = true;}

    ~ClassTypeLiteralValueExpression();

    // Returns the class type number value
    ooTypeNumber getClassType() const
    {return mClassType;}

    // Returns the class type number value
    const char* getClassName() const
    {return mClassName;}

    // Sets the class name for the class literal
    void setValue(const char* className);

    // Sets the class type for the class literal
    void setValue(ooTypeNumber classType);

    // Sets the literal value from ExpressionResult
    virtual void setValue(const ExpressionResult& valueResult);

    // Returns the expression's type (oocClassTypeLiteralExpression).
    virtual ExpressionType getExpressionType() const
    {return oocClassTypeLiteralValueExpression;}

    // Returns the expression's result type (oocQClassTypeType, isLiteral=true)
    virtual ExpressionResultSpec* computeResultSpec() const
    {return new ExpressionResultSpec(oocQClass, true);}

    // Causes the expression to evaluate itself using the provided object and
    // place the result in the passed in result object.
    virtual void evaluate
      (const ooObjectBaseInt* object, ExpressionResult& result) const;

    // Calls visitClassTypeLiteralValue on the passed in visitor passing in this
    // bool literal value expression.
    virtual void accept(ExpressionVisitor& visitor) 
    {visitor.visitClassTypeLiteralValue(this);}

    virtual void completeSetup(CompleteSetupContext& context);

    virtual Expression* clone(bool /*deep*/) const
    { return new ClassTypeLiteralValueExpression( *this ); }

    virtual bool isEqualTo(const Expression* other) const;

  protected:

    // Copy constructor (for clone)
    ClassTypeLiteralValueExpression( const ClassTypeLiteralValueExpression& other );

  private:

    char* mClassName;
    ooTypeNumber mClassType;
    const ooShapeInt* mShape;

    // Prevent assignment
    ClassTypeLiteralValueExpression& operator=( const ClassTypeLiteralValueExpression& rhs );

    // Returns the shape literal value
    const ooShapeInt* getShape() const
    {return mShape;}

    // Sets the shape literal value.
    void setShape(const ooShapeInt* value)
    {mShape = value; mIsValueSet = true; onChanged();}
};

//-----------------------------------------------------------------------------
// An Oid literal value.
//-----------------------------------------------------------------------------
class OQ_STORAGE_SPECIFIER OidLiteralValueExpression 
  : public LiteralValueExpression
{
  public:

    // Default constructor
    OidLiteralValueExpression() {}

    // Constructor taking an oid value
    OidLiteralValueExpression(const ooRef(ooObj)& oidRef)
       : mValue(oidRef)
    {mIsValueSet = true;}

    // Returns the corresponded ref value
    ooRef(ooObj) getValue() const
    {return mValue;}

    // Sets the oid literal value.
    void setValue(const ooRef(ooObj)& value)
    {mValue = value; mIsValueSet = true; onChanged();}

    // Sets the literal value from ExpressionResult
    virtual void setValue(const ExpressionResult& valueResult);

    // Returns the expression's type (oocClassTypeLiteralExpression).
    virtual ExpressionType getExpressionType() const
    {return oocOidLiteralValueExpression;}

    // Returns the expression's result type (oocQReference, isLiteral=true)
    virtual ExpressionResultSpec* computeResultSpec() const;

    // Causes the expression to evaluate itself using the provided object and
    // place the result in the passed in result object.
    virtual void evaluate
      (const ooObjectBaseInt* object, ExpressionResult& result) const;

    // Calls visitClassTypeLiteralValue on the passed in visitor passing in this
    // bool literal value expression.
    virtual void accept(ExpressionVisitor& visitor) 
    {visitor.visitOidLiteralValue(this);}

    virtual Expression* clone(bool /*deep*/) const
    { return new OidLiteralValueExpression( *this ); }

    virtual bool isEqualTo(const Expression* other) const;

  protected:

    // Copy constructor (for clone)
    OidLiteralValueExpression( const OidLiteralValueExpression& other )
      : LiteralValueExpression( other ), mValue( other.mValue )
    {
    }

  private:

    ooRef(ooObj) mValue;

    // Prevent assignment
    OidLiteralValueExpression& operator=( const OidLiteralValueExpression& rhs );
};

//-----------------------------------------------------------------------------
// Instance of ObjectLiteralAttribute represents an attribute within an object literal
//-----------------------------------------------------------------------------
class OQ_STORAGE_SPECIFIER ObjectLiteralAttribute
{
  public:

   ObjectLiteralAttribute(AttributeValueExpression* attributeExp,
      LiteralValueExpression* literalValueExp)
      : mAttributeExp(attributeExp), mLiteralValueExp(literalValueExp)
   {}

   ~ObjectLiteralAttribute()
   {
      delete mAttributeExp;
      delete mLiteralValueExp;
   }

   AttributeValueExpression* getAttribute() const
   {return mAttributeExp;}

   LiteralValueExpression* getValue() const
   {return mLiteralValueExp;}

    void accept(ExpressionVisitor& visitor);
  
    bool isEqualTo(const ObjectLiteralAttribute* other) const;

  private:

   AttributeValueExpression* mAttributeExp;
   LiteralValueExpression* mLiteralValueExp;

   // Prevent copy constructing and assgnment
   ObjectLiteralAttribute(const ObjectLiteralAttribute& other);
   ObjectLiteralAttribute& operator = (const ObjectLiteralAttribute& other);

};

//-----------------------------------------------------------------------------
// An object literal value.
//-----------------------------------------------------------------------------

typedef std::vector<ObjectLiteralAttribute*> ObjectAttributeVector;

class OQ_STORAGE_SPECIFIER ObjectLiteralValueExpression 
  : public LiteralValueExpression
{
  public:

    // Default constructor
    ObjectLiteralValueExpression()
       : mClassName(0), mShape(0) {}

    // constructor taking a class name for the object literal
    ObjectLiteralValueExpression(const char* className);

    ~ObjectLiteralValueExpression();

    // Returns the expression's type (oocClassTypeLiteralExpression).
    virtual ExpressionType getExpressionType() const
    {return oocObjectLiteralValueExpression;}

     // Adds an object attribute value
    void addAttributeValue(AttributeValueExpression* attributeExp,
                           LiteralValueExpression* literalValueExp);

    // Returns the expression's result type (oocQReference, isLiteral=true)
    virtual ExpressionResultSpec* computeResultSpec() const
    {return new ExpressionResultSpec(oocQObject, true);}

    virtual void completeSetup(CompleteSetupContext& context);

    // Causes the expression to evaluate itself using the provided object and
    // place the result in the passed in result object.
    virtual void evaluate
     (const ooObjectBaseInt* object, ExpressionResult& result) const;

    // Calls visitObjectTypeLiteralValue on the passed in visitor.
    virtual void accept(ExpressionVisitor& visitor);

    virtual Expression* clone(bool /*deep*/) const
    {return new ObjectLiteralValueExpression(*this);}

    const char* getClassName() const
    {return mClassName;}

    const ObjectAttributeVector& getObjectAttributes() const
    {return mObjAttributeVector;}

    virtual bool isEqualTo(const Expression* other) const;

  private:

    char* mClassName;
    ooShapeInt* mShape;

#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable : 4251)
#endif
    ObjectAttributeVector mObjAttributeVector;
#ifdef _MSC_VER
#pragma warning(pop)
#endif

    // Prevent copy constructing and assgnment
    ObjectLiteralValueExpression(const ObjectLiteralValueExpression& other);
    ObjectLiteralValueExpression& operator=( const ObjectLiteralValueExpression& rhs );

    bool compareToOtherObjectResult(const ExpressionResult& resultOfOtherObject);

    // Sets the literal value from ExpressionResult (not supported)
    virtual void setValue(const ExpressionResult& valueResult) {}

    friend class EqualOperator;
    friend class NotEqualOperator;
};

}/* end query namespace */} /* end objy namespace */

#endif
