//***************************************************************************//
//                                                                           //
//                Copyright © 2007 Objectivity Inc, USA.                     //
//                                                                           //
//    All Rights Reserved. Unauthorized use, duplication or distribution     //
//         of this software, or any portion of it, is prohibited.            //
//                                                                           //
//***************************************************************************//
#ifndef ooExpressionResult_h
#define ooExpressionResult_h

#include "ObjectQualificationSS.h"


class ooObjectBaseInt;
class ooShapeInt;
class ooStringObjectInt;

namespace objy {namespace query
{

//-----------------------------------------------------------------------------
// Enum capturing the data types supported within the query subsystem.
// Any change to this enum must be reflected in the definition of the data type enum in 
// com.objy.assist.api/QDataType.java
enum QDataType
{
  oocQNoDataType = 0,
  oocQUInt = 1,
  oocQInt = 2,
  oocQWholeNumber = oocQUInt | oocQInt,
  oocQFloat32 = 4,
  oocQFloat64 = 8,
  oocQFloat = oocQFloat32 | oocQFloat64,
  oocQNumeric = oocQUInt | oocQInt | oocQFloat,
  oocQBool = 16,
  oocQ8BitString = 32,
  oocQUtf8String = 64,
  oocQUtf16String = 128,
  oocQUtf32String = 256,
  oocQUtfString = oocQUtf8String | oocQUtf16String | oocQUtf32String,
  oocQString = oocQ8BitString | oocQUtfString,
  oocQDate = 512,
  oocQTime = 1024,
  oocQDateTime = 2048,
  oocQAllDate = oocQDate | oocQDateTime,
  oocQInterval = 4096,
  oocQSimple = oocQNumeric | oocQBool | oocQString 
             | oocQDate | oocQTime | oocQDateTime | oocQInterval,
  oocQClass = 8192,
  oocQReference = 16384,
  oocQEmbedded = 32768,
  oocQObject = oocQReference | oocQEmbedded,
  oocQOrderedArray = 65536,
  oocQOrderedList = 131072,
  oocQOrderedSet = 262144,
  oocQOrderedMap = 524288,
  oocQOldOrderedCollection = 1048576,
  oocQOrderedCollection = oocQOrderedArray | oocQOrderedList | oocQOrderedSet | oocQOrderedMap
                        | oocQOldOrderedCollection,
  oocQUnorderedArray = 2097152,
  oocQUnorderedSet = 4194304,
  oocQUnorderedMap = 8388608,
  oocQOldUnorderedCollection = 16777216,
  oocQUnorderedCollection = oocQUnorderedArray | oocQUnorderedSet | oocQUnorderedMap
                          | oocQOldUnorderedCollection,
  oocQKeyedCollection = oocQOrderedSet | oocQUnorderedSet | oocQOrderedMap | oocQUnorderedMap,
  oocQReferencedCollection = oocQOrderedList | oocQKeyedCollection 
                           | oocQOldOrderedCollection | oocQOldUnorderedCollection, 
  oocQReferenceAccessible = oocQReference | oocQReferencedCollection,
  oocQCollection = oocQOrderedCollection | oocQUnorderedCollection,
  oocQNonCollection = oocQSimple | oocQObject | oocQClass,
  oocQAllDataTypes = oocQNonCollection | oocQCollection
};
 
//-----------------------------------------------------------------------------
// Value class capturing compatible result types of an operator's input, 
// the possible result types of an operator, or the actual result types
// of an expression node.
class OQ_STORAGE_SPECIFIER ExpressionResultSpec
{
  public:

    // Default constructor. Creates a null result spec.
    ExpressionResultSpec();

    // Constructor for simple (non-collection) results.
    ExpressionResultSpec(QDataType dataType, bool isLiteral = false);

    // Constructor for collection results.
    ExpressionResultSpec(QDataType dataType, 
                           const ExpressionResultSpec& elementSpec, 
                           bool isLiteral = false);

    // Constructor for object results.
    ExpressionResultSpec(QDataType dataType, ooTypeNumber associatedClass, bool isLiteral = false);

    // Copy Constructor
    ExpressionResultSpec(const ExpressionResultSpec& other);

    // Destructor
    ~ExpressionResultSpec();

    // Assignment Operator
    ExpressionResultSpec& operator = (const ExpressionResultSpec& other);

    // Returns the data type
    QDataType getDataType() const
    {return mDataType;}

    // Returns the element result spec for results whose data type includes
    // oocQCollection.
    ExpressionResultSpec& getElementSpec() const;

    // Returns the key class to use with the keyed collection.
    // (Only valid for use when the return from getDataType() includes 
    // oocQKeyedCollection.)
    ooTypeNumber getKeyClass() const
    {return mKeyClass;}

    // Returns the referenced or embedded class for object results; 
    // 0 for other results.  
    ooTypeNumber getAssociatedClass() const
    {return mAssociatedClass;}

    // Sets the associated class type for referenced or embedded object results
    void setAssociatedClass(ooTypeNumber associatedClass)
    {mAssociatedClass = associatedClass;}

    // Returns true if the value is a literal, meaning that its value is
    // not derived from objects being evaluated.
    bool isLiteral() const
    {return mIsLiteral;}

    // Returns a string representation of the data type.
    std::string getDataTypeName() const;

    // Returns true if the specified result is a collection; false otherwise.
    bool isCollection() const
    {return (mDataType & oocQCollection) != 0;}

    // Checks if two data types are compatible with each other
    // used for validating the operand type compatibility in completSetup
    static bool isCompatibleDataType
       (QDataType requiredType, QDataType providedType);

    // Checks if two data types can be promoted to be compatible
    // used for operands across compatibility check for some operators
    static bool isPromoteCompatible(QDataType type1, QDataType type2);

    // Clone
    ExpressionResultSpec* clone() const
    {
       return new ExpressionResultSpec( *this );
    }

  private:

    static ExpressionResultSpec smNoResultSpec;
    static ExpressionResultSpec smStringElementResultSpec;

    QDataType mDataType;
    ExpressionResultSpec* mElementSpec; // used only for collections types
    ooTypeNumber mKeyClass; // used only for keyed collections
    ooTypeNumber mAssociatedClass; // used only for object types
    ooTypeNumber mCollectionClass; // used only for built in collections
    bool mIsLiteral;

    // Constructor for built in collection results.
    ExpressionResultSpec(QDataType dataType, 
                           const ExpressionResultSpec& elementSpec, 
                           ooTypeNumber collectionClass,
                           ooTypeNumber keyClass);

    bool isCompatibleOperand(const ExpressionResultSpec& operandResultSpec) const;

    ooTypeNumber collectionClass() const
    {return mCollectionClass;}

    friend class OperatorExpression;
    friend class OperatorGroupRegistry;
    friend class ArrayResult;
    friend class QCollection;
    friend class AttributeValueExpression;
    friend class ExpressionResult;
};

class ExpressionResult;

//-----------------------------------------------------------------------------
// An abstract base class (ABC) that specifies the interface to be met by
// various specific derived classes that provide iterators for various types of 
// lists (literal, fixed array, variable array, collection, etc).
class OQ_STORAGE_SPECIFIER QCollectionIterator
{
  public:
  
    // Default constructor
    QCollectionIterator(const ExpressionResultSpec& elementResultSpec) 
       : mElementResultSpec(elementResultSpec) {}

    // Destructor
    virtual ~QCollectionIterator() {}

    // Returns the result spec that describes the items of iteration.
    const ExpressionResultSpec& getElementResultSpec() const
    {return mElementResultSpec;}

    // Increments the iterator to the next item if one exists.
    // Returns true if the next item exists; false otherwise.
    virtual bool gotoNext() = 0;

    // Sets the current item result on the passed in result object.
    virtual void getResult(ExpressionResult& result) const = 0;

  private:

    const ExpressionResultSpec& mElementResultSpec;
};

//-----------------------------------------------------------------------------
// An base class that specifies the interface to be met by
// various specific derived classes that provide access to various types of 
// lists (fixed array, variable array, ToMany relationship, collection, etc).
class OQ_STORAGE_SPECIFIER QCollection
{
  public:

    // Constructor
    QCollection(const ExpressionResultSpec& resultSpec) 
       : mResultSpec(resultSpec)  {}

    // Destructor
    virtual ~QCollection() {}

    // Returns a copy of the collection.  The caller is responsible for deleting
    // the returned collection.
    virtual QCollection* clone() const = 0;

    // Returns the result spec that describes this collection.
    const ExpressionResultSpec& getResultSpec() const
    {return mResultSpec;}

    // Default set to false. When overridden to return true, indicates that calls to 
    // getIterator() will succeed.
    virtual bool supportsIteration() const
    {return false;}

    // Default set to false. When overridden to return true, indicates that calls to 
    // getResult() will succeed.
    virtual bool supportsIndexedAccess() const
    {return false;}

    // Default set to false. When overridden to return true, indicates that calls to 
    // getResultWithKey() will succeed.
    virtual bool supportsKeyedAccess() const
    {return false;}

    // Returns the length of the list.
    virtual unsigned getLength() const = 0;

    // Returns true if the list is empty; false otherwise.
    virtual bool isEmpty() const = 0;

    // Returns an iterator that can be used to iterate over the
    // collection's contents.
    // It's the caller's responsibility to delete the returned 
    // QCollectionIterator instance.
    // Needs to override when supportsIteration() returns true.
    virtual QCollectionIterator* getIterator() const
    {return 0;}

    // Gets result of the item with the given index on the passed in result 
    // object. Needs to override when supportsIndexedAccess() returns true.
    virtual void getResult(unsigned index, ExpressionResult& result) const
    {}

    // Gets result of the item with the given key on the passed in result 
    // object.  Only valid for collections with keys.
    virtual void getResultWithKey(const void* keyData, ExpressionResult& result) const
    {}

    // Returns the reference to the collection, or a null
    // reference if no reference is involved.
    virtual const ooRef(ooObj)& getReference() const
    {static ooRef(ooObj) nullRef; return nullRef;}

  private:

    const ExpressionResultSpec& mResultSpec;

};

//-----------------------------------------------------------------------------
// ExpressionResult instances are used to gather results of expression nodes.
class OQ_STORAGE_SPECIFIER ExpressionResult
{
  public:
  
    // Default constructor
    ExpressionResult() 
       : mResultSpec(&smNoResultSpec), mNumericResult(0), 
         mPtrResult(0), mCleanupTask(NoCleanup),
         mPtrIsStringObject(false) {}

    // Destructor
    ~ExpressionResult()
    {if (mCleanupTask) cleanupResult();}

    // Returns true if this result is null (unknown); false otherwise.
    bool isNull() const
    {return mResultSpec == &smNoResultSpec;}

    // Sets that this result is null (unknown).
    void setIsNull();

    // Returns the result's type. 
    const ExpressionResultSpec& getResultSpec() const
    {return *mResultSpec;}

    // Equalizes data types (for numerical data types only) of this result
    // with the otherResult. The conversion precedence is: float, int, uint.
    void equalizeDataTypes(ExpressionResult& otherResult);

    // Overloaded operators (valid for all data types)
    bool operator == (ExpressionResult& other);
    bool operator != (ExpressionResult& other);

    // Overloaded operators (valid only to oocQSimple type)
    bool operator > (ExpressionResult& other);
    bool operator >= (ExpressionResult& other);
    bool operator < (ExpressionResult& other);
    bool operator <= (ExpressionResult& other);

    //-------------------------------------------------------------------------//
    //        set/get methods for different types of expression results        // 
    //-------------------------------------------------------------------------//

    // Sets the result as a boolean value.
    void setBoolResult(bool value);

    // Sets the result as an int64 value.
    void setIntResult(int64 value);

    // Sets the result as a uint64 value.
    void setUIntResult(uint64 value);

    // Sets the result as a float32 value.
    void setFloat32Result(float32 value);

    // Sets the result as a float64 value.
    void setFloat64Result(float64 value);

    // Sets the result as an 8 bit string value.
    void set8BitStringResult(const char* value);

    // Sets the result as an 8 bit string value.
    void set8BitStringResult(char* value, bool takeOwnership = false);

    // Sets the result as a utf8 string value.
    void setUtf8StringResult(const char* value);

    // Sets the result as a utf8 string value.
    void setUtf8StringResult(char* value, bool takeOwnership = false);

    // Sets the result as a utf16 string value.
    void setUtf16StringResult(const ooChar16* value);

    // Sets the result as a utf16 string value.
    void setUtf16StringResult(ooChar16* value, bool takeOwnership = false);

    // Sets the result as a utf32 string value.
    void setUtf32StringResult(const ooChar32* value);

    // Sets the result as a utf32 string value.
    void setUtf32StringResult(ooChar32* value, bool takeOwnership = false);

    // Sets the result as a string object.
    void setStringObjectResult(ooStringObjectInt* stringObject);

    // Sets the result as a date value.
    void setDateResult(ooDate date);

    // Sets the result as a time value.
    void setTimeResult(ooTime time);

    // Sets the result as a datetime value.
    void setDateTimeResult(ooDateTime dateTime);

    // Sets the result as an interval value.
    void setIntervalResult(ooInterval interval);

    // Sets the result as a class value.
    void setClassResult(const ooShapeInt* value);

    // Sets the result as a reference value.
    void setReferenceResult(const ooRef(ooObj)& value, 
                            const ExpressionResultSpec& resultSpec);

    // Sets the result as a embedded value.
    void setEmbeddedResult(ooObjectBaseInt* embedded, 
                           const ExpressionResultSpec& resultSpec);

    // Sets the result as a list value.
    void setCollectionResult
       (const QCollection* value, bool takeOwnership = true);

    // Returns the result as a bool value.
    bool getBoolResult() const
    {return (mNumericResult > 0)? true : false;}

    // Returns the result as an int64 value.
    int64 getIntResult() const
    {return *(ooReinterpretCast(const int64*, &mNumericResult));}

    // Returns the result as an uint64 value.
    uint64 getUIntResult() const
    {return mNumericResult;}

    // Returns the result as a float32 value.
    float32 getFloat32Result() const
    {return *(ooReinterpretCast(const float32*, &mNumericResult));}

    // Returns the result as a float64 value.
    float64 getFloat64Result() const
    {return *(ooReinterpretCast(const float64*, &mNumericResult));}

    // Returns the result as a 8-bit string value.
    const char* get8BitStringResult() const;

    // Returns the result as an utf8 string value.
    const char* getUtf8StringResult() const;

    // Returns the result as an utf16 string value.
    const ooChar16* getUtf16StringResult() const;

    // Returns the result as an utf32 string value.
    const ooChar32* getUtf32StringResult() const;

    // Returns the result as a date value.
    ooDate getDateResult() const;  

    // Returns the result as a time value.
    ooTime getTimeResult() const;  

    // Returns the result as a date/time value.
    ooDateTime getDateTimeResult() const;  

    // Returns the result as a date time value.
    ooInterval getIntervalResult() const;  

    // Returns the result as a class value.
    const ooShapeInt* getClassResult() const;  

    // Returns the result as a reference value.
    const ooRef(ooObj)& getReferenceResult() const;

    // Returns the result as a list value.
    const QCollection& getCollectionResult() const;  

    // Returns the result as an object ptr, or null if a null reference.
    // Only valid for use if the result type is oocQReference or
    // oocQEmbedded.
    const ooObjectBaseInt* getObjectResult() const;

  private:

    static ExpressionResultSpec smNoResultSpec;
    static ExpressionResultSpec smUIntResultSpec;
    static ExpressionResultSpec smIntResultSpec;
    static ExpressionResultSpec smFloat32ResultSpec;
    static ExpressionResultSpec smFloat64ResultSpec;
    static ExpressionResultSpec smBoolResultSpec;
    static ExpressionResultSpec sm8BitStringResultSpec;
    static ExpressionResultSpec smUtf8StringResultSpec;
    static ExpressionResultSpec smUtf16StringResultSpec;
    static ExpressionResultSpec smUtf32StringResultSpec;
    static ExpressionResultSpec smDateResultSpec;
    static ExpressionResultSpec smTimeResultSpec;
    static ExpressionResultSpec smDateTimeResultSpec;
    static ExpressionResultSpec smIntervalResultSpec;
    static ExpressionResultSpec smClassResultSpec;

    static const char smEmptyStringChar;
    static const ooChar16 smEmptyStringChar16;
    static const ooChar32 smEmptyStringChar32;

    const ExpressionResultSpec* mResultSpec;

    // For holding int64, uint64, float, bool, datatime, interval, reference and char result
    uint64 mNumericResult;

    // Pointer to string, embedded or list result(QCollection)
    void* mPtrResult;

    enum {NoCleanup,
          Cleanup8BitString,
          CleanupChar16String,
          CleanupChar32String,
          CleanupCollection,
          CleanupReferenceCountedObject} mCleanupTask;

    bool mPtrIsStringObject;

    void cleanupResult();

    // Sets the char result as an 8 bit string value.
    void set8BitStringResult(int64 charValue);

    // Sets the char result as an utf16 string value.
    void setUtf16StringResult(uint64 charValue);

    // Sets the char result as an utf32 string value.
    void setUtf32StringResult(uint64 charValue);

    // Compares this non-list result to other result of the same type
    // (applies only to non-list simple result)
    // returns:
    // < 0  --- this < other
    //  0  --- this == other
    // > 0  --- this > other
    int compareToOtherResult(ExpressionResult& other);

    // Prevent copy constructing or assignment
    ExpressionResult(const ExpressionResult& other);
    ExpressionResult& operator = (const ExpressionResult& other);

    void handleBackwardCompatibility(ExpressionResult& other);

    friend class AttributeValueExpression;
    friend class JArrayOfCharacterResult;
};

}/* end query namespace */} /* end objy namespace */

#endif
