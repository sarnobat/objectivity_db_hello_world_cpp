/**************************************************************************
		  Copyright (c) 1999-2008 Objectivity, Inc.
			  All Rights Reserved

	THIS IS UNPUBLISHED PROPRIETARY SOURCE CODE OF OBJECTIVITY, INC.

	The copyright notice above does not evidence any
	actual or intended publication of such source code.

*****************************************************************************/

#ifndef _OOSCHEMANUMERIC_H
#define _OOSCHEMANUMERIC_H

#include <ooSchemaODMG.h>
#include <ooActiveSchemaException.h>

#ifndef OO_NO_NAMESPACE
namespace ooas {
#endif // !OO_NO_NAMESPACE

// Numeric_Value provides a buffering of type safety between a persistent
// object of arbitrary class opened by Objectivity Active Schema and the
// program accessing primitive data member values.  Numeric_Value
// encapsulates up to 64 bits of raw data and a type designation whose
// domain is the set of possible return values of Basic_Type::base_type().
//
// Ordinarily the programmer will never explicitly use a Numeric_Value;
// it will be constructed implicitly as a return value on the call stack.
// Numeric_Value is not part of the ODMG standard.

class AS_STORAGE_SPECIFIER Numeric_Value
{
    friend class VArray_Object;
    friend class Proposed_Property;
    friend class Proposed_Property_Int;
public:
    operator char() const;
    operator int8() const;
    operator uint8() const;
    operator int16() const;
    operator uint16() const;
    operator int32() const;
    operator uint32() const;
    operator float32() const;
    operator float64() const;
    operator int64() const;
    operator uint64() const;
    operator void*() const;

    int operator==(const Numeric_Value &);
    int operator!=(const Numeric_Value &);
    int operator>(const Numeric_Value &);
    int operator<(const Numeric_Value &);
    int operator>=(const Numeric_Value &);
    int operator<=(const Numeric_Value &);

    // Default ctor
    //
    Numeric_Value()
	: _numericalData(0),
	  _baseType(oocTypeNONE) {;}

    // Ctor given untyped pointer to data; used when accessing data
    // from a Class_Object.  A Numeric_Value will be created on the
    // stack as the return value for the get*() methods.  The lvalue
    // of the expression calling the accessor will determine which
    // of a matrix of numeric conversions will be used to compute the
    // actual result.
    //
    Numeric_Value(void *, ooBaseType);

    // Ctor given a maximum-precision float or integer; these are used
    // creating Proposed_Basic_Attribute default values.
    //
    Numeric_Value(int64, ooBaseType);
    Numeric_Value(uint64, ooBaseType);
    Numeric_Value(float64, ooBaseType);

    // Ctor given typed numerical data; used by the Class_Object set()
    // method.  A Numeric_Value will be created on the stack from the
    // typed value specified in application code.  Compiler type safety
    // will thus pass to runtime type safety wherein ooBaseTypes in this
    // structure are checked against types expected by Class_Object
    // attribute types.
    //
    inline Numeric_Value(char);
    inline Numeric_Value(int8);
    inline Numeric_Value(uint8);
    inline Numeric_Value(int16);
    inline Numeric_Value(uint16);
    inline Numeric_Value(int32);
    inline Numeric_Value(uint32);
    inline Numeric_Value(int64);
    inline Numeric_Value(uint64);
    inline Numeric_Value(float32);
    inline Numeric_Value(float64);
    inline Numeric_Value(void *);

    bool		is_valid() const;
    ooBaseType		type() const { return _baseType; }
    int64 numericalData() {return _numericalData;}

protected:
    //
    // Note: This source is also used to construct the public header "ooas.h,"
    // WITH THE PROTECTED MEMBERS STRIPPED.  Beware adding virtual protected
    // methods, as this might cause the class layout size seen at library
    // build time to differ from that seen at library use time.
    //
    void *		address() const {
	return ooStaticCast(void *, ooConstCast(int64 *, &_numericalData));
    }
    bool		isFloat() const {
	return ((_baseType == oocTypeFLOAT32) ||
		(_baseType == oocTypeFLOAT64));
    }
    bool		is64Int() const {
	return ((_baseType == oocTypeUINT64) ||
		(_baseType == oocTypeINT64));
    }
    bool		isSmall() const {
	return ((_baseType == oocTypeCHAR) ||
		(_baseType == oocTypeINT8) ||
		(_baseType == oocTypeBOOLEAN) ||
		(_baseType == oocTypeUINT8) ||
		(_baseType == oocTypeINT16) ||
		(_baseType == oocTypeUINT16) ||
		(_baseType == oocTypeCHAR16));
    }

private:
    int64		_numericalData;
    ooBaseType		_baseType;
};

inline
Numeric_Value::Numeric_Value(char c)
    : _baseType(ooStaticCast(ooBaseType, ooStaticCast(int, ooCHAR)))
{
    *(ooReinterpretCast(char *, &_numericalData)) = c;
}

inline
Numeric_Value::Numeric_Value(int8 i)
    : _baseType(ooStaticCast(ooBaseType, ooStaticCast(int, ooINT8)))
{
    *(ooReinterpretCast(int8 *, &_numericalData)) = i;
}

inline
Numeric_Value::Numeric_Value(uint8 i)
    : _baseType(ooStaticCast(ooBaseType, ooStaticCast(int, ooUINT8)))
{
    *(ooReinterpretCast(uint8 *, &_numericalData)) = i;
}

inline
Numeric_Value::Numeric_Value(int16 i)
    : _baseType(ooStaticCast(ooBaseType, ooStaticCast(int, ooINT16)))
{
    *(ooReinterpretCast(int16 *, &_numericalData)) = i;
}

inline
Numeric_Value::Numeric_Value(uint16 i)
    : _baseType(ooStaticCast(ooBaseType, ooStaticCast(int, ooUINT16)))
{
    *(ooReinterpretCast(uint16 *, &_numericalData)) = i;
}

inline
Numeric_Value::Numeric_Value(int32 i)
    : _baseType(ooStaticCast(ooBaseType, ooStaticCast(int, ooINT32)))
{
    *(ooReinterpretCast(int32 *, &_numericalData)) = i;
}

inline
Numeric_Value::Numeric_Value(uint32 i)
    : _baseType(ooStaticCast(ooBaseType, ooStaticCast(int, ooUINT32)))
{
    *(ooReinterpretCast(uint32 *, &_numericalData)) = i;
}

inline
Numeric_Value::Numeric_Value(int64 i)
    : _baseType(ooStaticCast(ooBaseType, ooStaticCast(int, ooINT64)))
{
    *(ooReinterpretCast(int64 *, &_numericalData)) = i;
}

inline
Numeric_Value::Numeric_Value(uint64 i)
    : _baseType(ooStaticCast(ooBaseType, ooStaticCast(int, ooUINT64)))
{
    *(ooReinterpretCast(uint64 *, &_numericalData)) = i;
}

inline
Numeric_Value::Numeric_Value(float32 i)
    : _baseType(ooStaticCast(ooBaseType, ooStaticCast(int, ooFLOAT32)))
{
    *(ooReinterpretCast(float32 *, &_numericalData)) = i;
}

inline
Numeric_Value::Numeric_Value(float64 i)
    : _baseType(ooStaticCast(ooBaseType, ooStaticCast(int, ooFLOAT64)))
{
    *(ooReinterpretCast(float64 *, &_numericalData)) = i;
}

inline
Numeric_Value::Numeric_Value(void *i)
    : _baseType(ooStaticCast(ooBaseType, ooStaticCast(int, ooPTR)))
{
    *(ooReinterpretCast(void **, &_numericalData)) = i;
}

class AS_STORAGE_SPECIFIER ooCHAR_t : public ooIntegerType {
public:
    ooCHAR_t(ooCHARenum_t ty) : ooIntegerType(ty) {;}
};

class AS_STORAGE_SPECIFIER ooINT8_t : public ooIntegerType {
public:
    ooINT8_t(ooINT8enum_t ty) : ooIntegerType(ty) {;}
};

class AS_STORAGE_SPECIFIER ooUINT8_t : public ooIntegerType {
public:
    ooUINT8_t(ooUINT8enum_t ty) : ooIntegerType(ty) {;}
};

class AS_STORAGE_SPECIFIER ooBOOLEAN_t : public ooIntegerType {
public:
    ooBOOLEAN_t(ooBOOLEANenum_t ty) : ooIntegerType(ty) {;}
};

class AS_STORAGE_SPECIFIER ooINT16_t : public ooIntegerType {
public:
    ooINT16_t(ooINT16enum_t ty) : ooIntegerType(ty) {;}
};

class AS_STORAGE_SPECIFIER ooUINT16_t : public ooIntegerType {
public:
    ooUINT16_t(ooUINT16enum_t ty) : ooIntegerType(ty) {;}
};

class AS_STORAGE_SPECIFIER ooCHAR16_t : public ooIntegerType {
public:
    ooCHAR16_t(ooCHAR16enum_t ty) : ooIntegerType(ty) {;}
};

class AS_STORAGE_SPECIFIER ooINT32_t : public ooIntegerType {
public:
    ooINT32_t(ooINT32enum_t ty) : ooIntegerType(ty) {;}
};

class AS_STORAGE_SPECIFIER ooUINT32_t : public ooIntegerType {
public:
    ooUINT32_t(ooUINT32enum_t ty) : ooIntegerType(ty) {;}
};

class AS_STORAGE_SPECIFIER ooCHAR32_t : public ooIntegerType {
public:
    ooCHAR32_t(ooCHAR32enum_t ty) : ooIntegerType(ty) {;}
};

class AS_STORAGE_SPECIFIER ooINT64_t : public ooIntegerType {
public:
    ooINT64_t(ooINT64enum_t ty) : ooIntegerType(ty) {;}
};

class AS_STORAGE_SPECIFIER ooFLOAT32_t : public ooFloatType {
public:
    ooFLOAT32_t(ooFLOAT32enum_t ty) : ooFloatType(ty) {;}
};

class AS_STORAGE_SPECIFIER ooFLOAT64_t : public ooFloatType {
public:
    ooFLOAT64_t(ooFLOAT64enum_t ty) : ooFloatType(ty) {;}
};

#ifndef OO_NO_NAMESPACE
}
#endif // !OO_NO_NAMESPACE

#endif // ! _OOSCHEMANUMERIC_H
