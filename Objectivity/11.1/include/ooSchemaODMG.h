/**************************************************************************
		    Copyright (c) 1989-2008 Objectivity, Inc.
			  All Rights Reserved	

	THIS IS UNPUBLISHED PROPRIETARY SOURCE CODE OF OBJECTIVITY, INC.
	
	The copyright notice above does not evidence any	
	actual or intended publication of such source code.

*****************************************************************************/

#ifndef _OOSCHEMAODMG_H
#define _OOSCHEMAODMG_H

#if defined(OOTM_PVT_H) || defined(OOTM_BOOTSTRAPPING)
// Bootstrapping context: ooHandle(ooObj) is not defined yet
#  include <ooConfig.h>		// For OO_STORAGE_SPECIFIER
#  include <oost.h>		// For ost_table, etc.
#  define OO_REF_TYPE ooIdBase
#  define OO_FD_HANDLE_TYPE ooHandleBase
#else
#  include <oo.h>
#  define OO_REF_TYPE ooRef(ooObj)
#  define OO_FD_HANDLE_TYPE ooHandle(ooFDObj)
#endif

// Each of class, schema, and namespace name is limited to namescope
// name length (pad for "/" and "::")
static const unsigned OO_MAX_CLASSNAME_LEN = 500; // = OM_NAME_TUPLE_SIZE
static const unsigned OO_MAX_CLASSNAME_LEN_WITH_NAMESPACE =
  (OO_MAX_CLASSNAME_LEN * 2) + 2;
static const unsigned OO_MAXKEYLEN = (OO_MAX_CLASSNAME_LEN * 3) + 3;

struct OO_STORAGE_SPECIFIER ost_table;

// ODMG's bool type
#ifndef d_Boolean
#  define d_Boolean ooBoolean
#  define d_False 0
#  define d_True 1
#endif

struct OO_STORAGE_SPECIFIER otmAlignData;
struct OO_STORAGE_SPECIFIER otmAssocShape;
class OO_STORAGE_SPECIFIER ooSession;
class OO_STORAGE_SPECIFIER otiSchemaRef;
class OO_STORAGE_SPECIFIER otmFdSchema;
class OO_STORAGE_SPECIFIER ooTrans;
class OO_STORAGE_SPECIFIER otmEntry;
class otmMutexBlock;

typedef uint32 ooMemberType;

#ifdef OOTM_BOOTSTRAPPING
#  include <ooBase.h>
#else
#  include <ooVArray.h>		// For ooTVArray
#endif // !OOTM_BOOTSTRAPPING

#ifndef OO_NO_NAMESPACE
namespace ooas {
#endif // !OO_NO_NAMESPACE

// Descriptor classes whose names are prefixed with "d_" are modeled on
// the ODMG schema access standard.

class OO_STORAGE_SPECIFIER d_Meta_Object;
class OO_STORAGE_SPECIFIER d_Scope;
class OO_STORAGE_SPECIFIER d_Class;
class OO_STORAGE_SPECIFIER d_Module;
class OO_STORAGE_SPECIFIER d_Type;
class OO_STORAGE_SPECIFIER d_Constant;
class OO_STORAGE_SPECIFIER d_Operation;
class OO_STORAGE_SPECIFIER d_Property_Int;
class OO_STORAGE_SPECIFIER d_Attribute_Int;
class OO_STORAGE_SPECIFIER d_Collection_Type;
class OO_STORAGE_SPECIFIER d_Alias_Type;
class OO_STORAGE_SPECIFIER d_Keyed_Collection_Type;
class OO_STORAGE_SPECIFIER d_Ref_Type;
class OO_STORAGE_SPECIFIER d_Property;
class OO_STORAGE_SPECIFIER d_Attribute;
class OO_STORAGE_SPECIFIER d_Relationship;
class OO_STORAGE_SPECIFIER d_Inheritance;
class OO_STORAGE_SPECIFIER Property_Type;
class OO_STORAGE_SPECIFIER Attribute_Type;
class OO_STORAGE_SPECIFIER Basic_Type;
class OO_STORAGE_SPECIFIER Relationship_Type;
class OO_STORAGE_SPECIFIER Unidirectional_Relationship_Type;
class OO_STORAGE_SPECIFIER Bidirectional_Relationship_Type;
class OO_STORAGE_SPECIFIER VArray_Basic_Type;
class OO_STORAGE_SPECIFIER VArray_Embedded_Class_Type;
class OO_STORAGE_SPECIFIER VArray_Ref_Type;
#ifndef ____AS_SP_defined_locally
#  ifdef OO_NT
#    ifndef  AS_STORAGE_SPECIFIER
#      if defined(_MSC_VER) && defined(_DLL)
#        define AS_STORAGE_SPECIFIER    __declspec(dllimport)
#      else  // following is for: !_MSC_VER || !_DLL
#        define AS_STORAGE_SPECIFIER
#      endif // _MSC_VER && _DLL (else)
#      define ____AS_SP_defined_locally 1
#    endif // AS_STORAGE_SPECIFIER
#  else // following is for: !OO_NT
#    define AS_STORAGE_SPECIFIER
#    define ____AS_SP_defined_locally 1
#  endif // OO_NT
#endif // !____AS_SP_defined_locally
class AS_STORAGE_SPECIFIER Numeric_Value;
class OO_STORAGE_SPECIFIER String_Value;
class OO_STORAGE_SPECIFIER Optimized_String_Value;
class OO_STORAGE_SPECIFIER Class_Object;
class OO_STORAGE_SPECIFIER VArray_Object;
class OO_STORAGE_SPECIFIER Relationship_Object;
class OO_STORAGE_SPECIFIER Proposed_Class;
class OO_STORAGE_SPECIFIER Proposed_Base_Class;
class OO_STORAGE_SPECIFIER Proposed_Property;
class OO_STORAGE_SPECIFIER Proposed_Attribute;
class OO_STORAGE_SPECIFIER Proposed_Collection_Attribute;
class OO_STORAGE_SPECIFIER Proposed_Basic_Attribute;
class OO_STORAGE_SPECIFIER Proposed_Embedded_Class_Attribute;
class OO_STORAGE_SPECIFIER Proposed_Relationship;
class OO_STORAGE_SPECIFIER Proposed_Ref_Attribute;
class OO_STORAGE_SPECIFIER Proposed_VArray_Attribute;
class OO_STORAGE_SPECIFIER Proposed_Base_Change;
class OO_STORAGE_SPECIFIER Top_Level_Module;
class OO_STORAGE_SPECIFIER Namespace;
class OO_STORAGE_SPECIFIER d_Meta_Object_Int;
class OO_STORAGE_SPECIFIER d_Type_Int;
class OO_STORAGE_SPECIFIER Scope_Base;
class OO_STORAGE_SPECIFIER ooEvolveSession;
class OO_STORAGE_SPECIFIER Type_Descriptor;
class OO_STORAGE_SPECIFIER Property_Descriptor;
class OO_STORAGE_SPECIFIER otmEvolveInterface;

typedef enum {
    None_t,
    d_Scope_t,
    d_Meta_Object_t,
    d_Class_t,
    d_Module_t,
    d_Type_t,
    d_Constant_t,
    d_Operation_t,
    d_Collection_Type_t,
    d_Alias_Type_t,
    d_Keyed_Collection_Type_t,
    d_Ref_Type_t,
    d_Property_t,
    d_Exception_t,
    d_Parameter_t,
    d_Attribute_t,
    d_Relationship_t,
    d_Inheritance_t,
    Basic_Type_t,
    Relationship_Type_t,
    Unidirectional_Relationship_Type_t,
    Bidirectional_Relationship_Type_t,
    VArray_Basic_Type_t,
    VArray_Embedded_Class_Type_t,
    VArray_Ref_Type_t,
    Short_Ref_Type_t,		// Used only in Proposed_*_Attribute
    Numeric_Value_t,
    Class_Object_t,
    VArray_Object_t,
    String_Type_t,
    VArray_String_Type_t,
    Relationship_Object_t,
    Class_Or_Ref_Type_t,
    VArray_Class_Or_Ref_Type_t,
    Proposed_Class_t,
    Proposed_Base_Class_t,
    Proposed_Basic_Attribute_t,
    Proposed_Embedded_Class_Attribute_t,
    Proposed_Relationship_t,
    Proposed_Ref_Attribute_t,
    Proposed_VArray_Attribute_t,
    Namespace_t
} ooAsType;

typedef enum {
    No_Iter_t,
    STL_Iter_t,
    meta_object_iterator_t,
    type_iterator_t,
    attribute_plus_inherited_iterator_t,
    base_class_plus_inherited_iterator_t
} ooAsIterType;

typedef enum {
  oocIsNull
} ooIsNull;

enum ooNONEenum_t { ooNONE = oocTypeNONE };
enum ooCHARenum_t { ooCHAR = oocTypeCHAR };
enum ooINT8enum_t { ooINT8 = oocTypeINT8 };
enum ooUINT8enum_t { ooUINT8 = oocTypeUINT8 };
enum ooBOOLEANenum_t { ooBOOLEAN = oocTypeBOOLEAN };
enum ooINT16enum_t { ooINT16 = oocTypeINT16 };
enum ooUINT16enum_t { ooUINT16 = oocTypeUINT16 };
enum ooCHAR16enum_t { ooCHAR16 = oocTypeCHAR16 };
enum ooINT32enum_t { ooINT32 = oocTypeINT32 };
enum ooUINT32enum_t { ooUINT32 = oocTypeUINT32 };
enum ooCHAR32enum_t { ooCHAR32 = oocTypeCHAR32 };
enum ooINT64enum_t { ooINT64 = oocTypeINT64 };
enum ooUINT64enum_t { ooUINT64 = oocTypeUINT64 };
enum ooFLOAT32enum_t { ooFLOAT32 = oocTypeFLOAT32 };
enum ooFLOAT64enum_t { ooFLOAT64 = oocTypeFLOAT64 };
enum ooCHAR_PTRenum_t { ooCHAR_PTR = oocTypeCHAR_PTR };
enum ooFUNCTION_PTRenum_t { ooFUNCTION_PTR = oocTypeFUNCTION_PTR };
enum ooDEFAULT_VARRAYenum_t { ooDEFAULT_VARRAY = oocTypeDEFAULT_VARRAY };
enum ooPTRenum_t { ooPTR = oocTypePTR };

class OO_STORAGE_SPECIFIER ooNumberType;
class OO_STORAGE_SPECIFIER ooIntegerType;
class OO_STORAGE_SPECIFIER ooFloatType;
class OO_STORAGE_SPECIFIER ooCHAR_t;
class OO_STORAGE_SPECIFIER ooINT8_t;
class OO_STORAGE_SPECIFIER ooUINT8_t;
class OO_STORAGE_SPECIFIER ooBOOLEAN_t;
class OO_STORAGE_SPECIFIER ooINT16_t;
class OO_STORAGE_SPECIFIER ooUINT16_t;
class OO_STORAGE_SPECIFIER ooCHAR16_t;
class OO_STORAGE_SPECIFIER ooINT32_t;
class OO_STORAGE_SPECIFIER ooUINT32_t;
class OO_STORAGE_SPECIFIER ooCHAR32_t;
class OO_STORAGE_SPECIFIER ooINT64_t;
class OO_STORAGE_SPECIFIER ooUINT64_t;
class OO_STORAGE_SPECIFIER ooFLOAT32_t;
class OO_STORAGE_SPECIFIER ooFLOAT64_t;

// The motivation for the following type hierarchy is that proposed
// basic attributes can have default values, and we want them to convert
// from Numeric_Value in the least lossy way according to the basic
// type provided to Proposed_Class::add_basic_attribute() by the
// application.

class OO_STORAGE_SPECIFIER ooNumberType {
public:
    ooNumberType(ooBaseType bt) : _baseType(bt) {;}
    ooNumberType(ooCHARenum_t ty)
	: _baseType(static_cast<ooBaseType>(static_cast<int>(ty))) {;}
    ooNumberType(ooINT8enum_t ty)
	: _baseType(static_cast<ooBaseType>(static_cast<int>(ty))) {;}
    ooNumberType(ooUINT8enum_t ty)
	: _baseType(static_cast<ooBaseType>(static_cast<int>(ty))) {;}
    ooNumberType(ooBOOLEANenum_t ty)
	: _baseType(static_cast<ooBaseType>(static_cast<int>(ty))) {;}
    ooNumberType(ooINT16enum_t ty)
	: _baseType(static_cast<ooBaseType>(static_cast<int>(ty))) {;}
    ooNumberType(ooUINT16enum_t ty)
	: _baseType(static_cast<ooBaseType>(static_cast<int>(ty))) {;}
    ooNumberType(ooCHAR16enum_t ty)
	: _baseType(static_cast<ooBaseType>(static_cast<int>(ty))) {;}
    ooNumberType(ooINT32enum_t ty)
	: _baseType(static_cast<ooBaseType>(static_cast<int>(ty))) {;}
    ooNumberType(ooUINT32enum_t ty)
	: _baseType(static_cast<ooBaseType>(static_cast<int>(ty))) {;}
    ooNumberType(ooCHAR32enum_t ty)
	: _baseType(static_cast<ooBaseType>(static_cast<int>(ty))) {;}
    ooNumberType(ooINT64enum_t ty)
	: _baseType(static_cast<ooBaseType>(static_cast<int>(ty))) {;}
    ooNumberType(ooUINT64enum_t ty)
	: _baseType(static_cast<ooBaseType>(static_cast<int>(ty))) {;}
    ooNumberType(ooFLOAT32enum_t ty)
	: _baseType(static_cast<ooBaseType>(static_cast<int>(ty))) {;}
    ooNumberType(ooFLOAT64enum_t ty)
	: _baseType(static_cast<ooBaseType>(static_cast<int>(ty))) {;}
    ooNumberType(ooPTRenum_t ty)
	: _baseType(static_cast<ooBaseType>(static_cast<int>(ty))) {;}
    operator ooBaseType() const { return _baseType; }

private:
    ooBaseType		_baseType;
};

class OO_STORAGE_SPECIFIER ooIntegerType : public ooNumberType {
public:
    ooIntegerType(ooCHARenum_t ty)
      : ooNumberType(static_cast<ooBaseType>(static_cast<int>(ty))) {;}
    ooIntegerType(ooINT8enum_t ty)
      : ooNumberType(static_cast<ooBaseType>(static_cast<int>(ty))) {;}
    ooIntegerType(ooUINT8enum_t ty)
      : ooNumberType(static_cast<ooBaseType>(static_cast<int>(ty))) {;}
    ooIntegerType(ooBOOLEANenum_t ty)
      : ooNumberType(static_cast<ooBaseType>(static_cast<int>(ty))) {;}
    ooIntegerType(ooINT16enum_t ty)
      : ooNumberType(static_cast<ooBaseType>(static_cast<int>(ty))) {;}
    ooIntegerType(ooUINT16enum_t ty)
      : ooNumberType(static_cast<ooBaseType>(static_cast<int>(ty))) {;}
    ooIntegerType(ooCHAR16enum_t ty)
      : ooNumberType(static_cast<ooBaseType>(static_cast<int>(ty))) {;}
    ooIntegerType(ooINT32enum_t ty)
      : ooNumberType(static_cast<ooBaseType>(static_cast<int>(ty))) {;}
    ooIntegerType(ooUINT32enum_t ty)
      : ooNumberType(static_cast<ooBaseType>(static_cast<int>(ty))) {;}
    ooIntegerType(ooCHAR32enum_t ty)
      : ooNumberType(static_cast<ooBaseType>(static_cast<int>(ty))) {;}
    ooIntegerType(ooINT64enum_t ty)
      : ooNumberType(static_cast<ooBaseType>(static_cast<int>(ty))) {;}
    ooIntegerType(ooBaseType bt) : ooNumberType(bt) {;}
};

class OO_STORAGE_SPECIFIER ooUINT64_t : public ooNumberType {
public:
  ooUINT64_t(ooUINT64enum_t ty)
    : ooNumberType(static_cast<ooBaseType>(static_cast<int>(ty))) {;}
};

class OO_STORAGE_SPECIFIER ooFloatType : public ooNumberType {
public:
  ooFloatType(ooFLOAT32enum_t ty)
    : ooNumberType(static_cast<ooBaseType>(static_cast<int>(ty))) {;}
  ooFloatType(ooFLOAT64enum_t ty)
    : ooNumberType(static_cast<ooBaseType>(static_cast<int>(ty))) {;}
  ooFloatType(ooBaseType bt) : ooNumberType(bt) {;}
};

class OO_STORAGE_SPECIFIER ooPTR_t : public ooNumberType {
public:
    ooPTR_t(ooPTRenum_t ty)
	: ooNumberType(static_cast<ooBaseType>(static_cast<int>(ty)))
	{;}
};

static const int32 oocLast = -1;
static const int32 oocLatestVersion = 0;
static const int32 oocCurrentMrow = -1;
static const int32 oocCurrentTransWait = -2;
static const int32 oocCurrentSensitivity = -1;
static const uint32 oocNoID = static_cast<uint32>(-1);
static const size_t oocUninitializedSize_t = static_cast<size_t>(-1);
static const bool oocUninitializedBool = static_cast<bool>(-1);
static const void *oocUninitializedPtr = reinterpret_cast<void *>(-1);
static const char *defaultNameStr = "<UNKNOWN>";

typedef enum {
    REF,
    POINTER
} d_Ref_Kind;

typedef enum {
    oocNotCollection = 0,
    LIST,
    ARRAY,
    BAG,
    SET,
    DICTIONARY,
    STL_LIST,
    STL_SET,
    STL_MULTISET,
    STL_VECTOR,
    STL_MAP,
    STL_MULTIMAP
} Collection_Kind;

typedef Collection_Kind d_Kind;

typedef enum {
    d_PUBLIC,
    d_PROTECTED,
    d_PRIVATE,
    d_INVALID
} d_Access_Kind;

typedef enum {
    REL_REF,
    REL_SET,
    REL_LIST
} d_Rel_Kind;

#ifndef OO_NT
typedef enum {
    IN,
    OUT,
    INOUT
} d_Mode;
#endif

enum ooAsLanguages
{
  ooAsLanguageNone = 0,
  ooAsLanguageCpp = 1,
  ooAsLanguageJava = 2,
  ooAsLanguageSmalltalk = 3,
  ooAsLanguagePython = 4,
  ooAsLanguageActiveSchema = 5
};

#define ooMemberInvalid otiMemberInvalid
#define ooMemberBasic otiMemberBasic
#define ooMemberEmbedded otiMemberEmbedded
#define ooMemberVArrayBasic otiMemberVArrayBasic
#define ooMemberVArrayClass otiMemberVArrayStruct
#define ooMemberVArrayRef otiMemberVArrayOid
#define ooMemberUniRel otiMemberUniAssoc
#define ooMemberBiRel otiMemberBiAssoc
#define ooMemberRef otiMemberOid

class OO_STORAGE_SPECIFIER oasHeapData
{
public:
    void* operator new (size_t s);
    void* operator new (size_t, void *mem) { return mem; }
    void  operator delete (void* mem);
#ifndef OO_IRIX
    void  operator delete (void* mem, void *);
#endif
};

// List of simple smart pointers.  They need the size_t (unsigned int)
// operator to qualify as UDT.
//
template<class T>
class listElementP
{
public:
  operator size_t() const {		// for hashing purposes
    return static_cast<size_t>(*_data);
  }
  T *operator ->() { return _data; }
  T &operator *() { return *_data; } // Simple dereference
#ifndef OO_IBM_RS6000
  operator const T*() const { return static_cast<const T *>(_data); }
#endif
  void set_data(T *data) { _data = data; }
  listElementP(T *p) : _data(p) {;}
  listElementP() : _data(NULL) {;}
  ~listElementP() {;}

private:
  T *_data;
};

class OO_STORAGE_SPECIFIER asIterator
{
public:
  virtual ooAsIterType	asType() const = 0;
};

#ifdef OOTM_BOOTSTRAPPING
template<class T>
class list_iterator : public d_IteratorBase, public asIterator 
{
public:
  ooAsIterType		asType() const { return STL_Iter_t; }
};
#else // Following is for: !OOTM_BOOTSTRAPPING
template<class T>
class list_iterator
  : public d_Iterator<listElementP<T > >, public asIterator
{
public:
  inline list_iterator<T > &	operator=(const list_iterator<T > &);
  inline int			operator==(const list_iterator<T > &) const;
  inline int			operator!=(const list_iterator<T > &) const;
  inline list_iterator<T > &	operator++();
  inline list_iterator<T >	operator++(int);
  inline const T &		operator*() const;

  list_iterator() {;}

  // Constructor taking a list (TVArray) and a boolean: "true" specifies
  // a terminated iterator against which to compare in "while" loops
  //
  list_iterator<T >(const ooTVArray(listElementP<T >) &varrayList,
		    bool end = false,
		    int truncateAt = 0)
    : d_Iterator<listElementP<T > >(
      const_cast<ooTVArray(listElementP<T >) *>(&varrayList),
      (end ? (truncateAt ? truncateAt : varrayList.size()) : 0),
      varrayList.size())
    {;}
  list_iterator<T >(const d_Iterator<listElementP<T > > &itr)
    : d_Iterator<listElementP<T > >(itr) {;}
  ooAsIterType		asType() const { return STL_Iter_t; }
  bool                  isAtEnd() const { return !this->not_done(); }
};

template<class T>
inline int
list_iterator<T >::operator!=(const list_iterator<T > &otherIteratorR) const
{
  if (otherIteratorR.not_done()) {
    return ((this->get_vector() != otherIteratorR.get_vector()) ||
	    (this->get_index() != otherIteratorR.get_index()));
  } else {
    // This is the "... != ..._end()" case where we're just testing for the
    // end of an iteration.  So return true if we're not at the end (last
    // element) yet.
    return this->not_done();
  }
}

template<class T>
inline int
list_iterator<T >::operator==(const list_iterator<T > &otherIteratorR) const
{
  if (otherIteratorR.not_done()) {
    return ((this->get_vector() == otherIteratorR.get_vector()) &&
	    (this->get_index() == otherIteratorR.get_index()));
  } else {
    // This is the "... == ..._end()" case where we're just testing for the
    // end of an iteration.  So return true if we *are* at the end (last
    // element).
    return (this->not_done() == 0);
  }
}

// Assignment operator
//
template <class T>
inline list_iterator<T > &
list_iterator<T >::operator=(const list_iterator<T > &otherIteratorR)
{
  static_cast<d_Iterator<listElementP<T > > &>(*this) = otherIteratorR;
  return *this;
}

template<class T>
inline list_iterator<T > &
list_iterator<T >::operator++()
{
  static_cast<d_Iterator<listElementP<T > > &>(*this).operator++();
  return *this;
}

template<class T>
inline list_iterator<T >
list_iterator<T >::operator++(int)
{
  list_iterator<T > result(*this);
  this->d_Iterator<listElementP<T > >::operator++();
  return result;
}

// Dereference operator
//
template<class T>
inline const T &
list_iterator<T >::operator*() const
{
  ooTVArray(listElementP<T >) *vectorP = 
    reinterpret_cast<ooTVArray(listElementP<T >) *>(
      d_Iterator<listElementP<T > >::get_vector());
  int currentIndex = d_Iterator<listElementP<T > >::get_index();
  const listElementP<T > &elementSmartPtrR = (*vectorP)[currentIndex];
  const T &retval =
    const_cast<listElementP<T > & >(elementSmartPtrR).operator*();
  return retval;
}
#endif // OOTM_BOOTSTRAPPING (else)

// d_Meta_Object is part of the ODMG standard.  A d_Meta_Object has a name
// which can be looked up in a scope.  Types, including classes, are
// meta-objects named in d_Module (schema) scope and class attributes are
// meta-objects named in d_Class scope.
//
// All d_Meta_Objects have a name string returned by name().  Comments
// added with set_comment() are transient only; they are not saved in
// the database.  The id() method returns an unsigned integer unique to
// the meta-object within its scope; for subclasses of d_Type, its return
// value will be the same as for type_number(), and for subclasses of
// d_Property, its return value will be the Objectivity member ID.  The
// method defined_in() returns the scope of the object.
//
// d_Meta_Objects are never constructed by an application.  They are
// returned by scope methods.  For example:
//
//   const d_Meta_Object &metaObjConstRef = module.resolve("typeName");
//
class OO_STORAGE_SPECIFIER d_Meta_Object : public oasHeapData
{
  friend class ::otmEntry;
  friend class d_Module;
  friend class d_Class;
  friend class d_Type;
  friend class d_Attribute;
  friend class d_Property;
  friend class d_Meta_Object_Int;
  friend class otmSchemaAccessInterface;
  friend class otmSchemaAccessOverrides;
  friend class Proposed_Property;
  friend class Proposed_Base_Class;
  friend class Proposed_Class;
  friend class Property_Type;
  friend class Property_Descriptor;
public:
  virtual const char *	name() const { return (_name ? _name : defaultNameStr); }
  const char *		comment() const { return _commentP; }
  const d_Scope &	defined_in() const;
  virtual uint32	id() const { return (_isNull ? 0 : oocNoID); }

  // The following methods are additions to the ODMG standard.
  //
  virtual bool		is_type() const { return false; }
  virtual bool		is_class() const { return false; }
  virtual bool		is_module() const { return false; }
  virtual bool		is_namespace() const { return false; }
  virtual bool		is_proposed() const { return false; }
  virtual ooAsType	descriptor_kind() const { return d_Meta_Object_t; }
  virtual const char *  module_name() const { return NULL; }
  virtual const char *  namespace_name() const { return NULL; }
  void			set_comment(const char *);
  //
  // We use the size_t() conversion to obtain keys for string hashing.
  // In most subclasses of d_Meta_Object, conversion to size_t works in
  // lieu of == and != operators.
  //
  virtual		operator size_t() const;
  //
  // Since ODMG defines the result of a look-up within a scope to be
  // a reference to an object, AS is implemented with a dedicated null
  // d_Meta_Object used as the null result of searches when appropriate.
  // It converts to 0 via the size_t() operator.
  //
  static const d_Meta_Object	null;
  virtual const char * sprint(char *buffer) const;
  virtual ~d_Meta_Object();

protected:
  d_Meta_Object(const char *name);
  d_Meta_Object(d_Module *modP,
		const char *name,
		bool isShape = false,
		bool isProposed = false);
  d_Meta_Object(Type_Descriptor *classP, const char *name);
  d_Meta_Object(ooIsNull);	// Just for creating null object(s)
  d_Meta_Object();
  void                  set_name(const char *name);

private:
  const char *		_name;
  const char *		_commentP;
  Scope_Base *		_scopeP;
  Namespace *		_namespaceP;
  bool                  _isNull;
};

#ifndef oocCopyDrop
#define oocCopyDrop 1
#endif

#ifndef oocCopyMove
#define oocCopyMove 2
#endif

#ifndef oocCopyCopy
#define oocCopyCopy 3
#endif

#ifndef oocVersionDrop
#define oocVersionDrop 1
#endif

#ifndef oocVersionMove
#define oocVersionMove 2
#endif

#ifndef oocVersionCopy
#define oocVersionCopy 3
#endif

#ifndef oocLockPropagationYesDeletePropagationNo
#define oocLockPropagationYesDeletePropagationNo 1
#endif

#ifndef oocLockPropagationNoDeletePropagationYes
#define oocLockPropagationNoDeletePropagationYes 4
#endif

#ifndef oocLockPropagationYesDeletePropagationYes
#define oocLockPropagationYesDeletePropagationYes (1 | 4)
#endif

class OO_STORAGE_SPECIFIER Type_Descriptor : public d_Meta_Object
{
  friend class Type_Descriptor_Int;
  friend class d_Type;
  friend class Proposed_Class;
  friend class Proposed_Class_Int;
  friend class otmEvolveInterface;
  friend class ::otmEntry;
  friend class ::otmFdSchema;
public:
  virtual const char *	 namespace_name() const { return _namespaceName; }
  virtual const char *	 module_name() const { return _moduleName; }
  virtual d_Boolean      persistent_capable() const;// ODMG specifies d_Boolean
  virtual ooTypeNumber   type_number() const { return _explicitTypeNumber; }
  size_t                 number_of_attributes() const { return _memberCount; }
  bool                   is_container() const { return _isContainer; }
  virtual bool	         has_virtual_method() const;
  virtual bool	         has_original_virtual_method() const;
  virtual bool           has_added_virtual_table() const;
  virtual const char *   print(char *buffer = NULL) const;

  virtual void           set_namespace_name(const char *);
  void                   set_module_name(const char *);
  virtual void           set_has_added_virtual_table(bool val);
  virtual void	         set_has_virtual_method(bool val);
  virtual void           set_has_original_virtual_method(bool val);
  static const Type_Descriptor null;

protected:
  Type_Descriptor(const char *,  // class name
		  const char *,  // module name
		  unsigned long, // type number
		  const char *); // namespace name

  Type_Descriptor(d_Module *modP,
		  const char *name,
		  bool isShape,
		  bool isProposed)
    : d_Meta_Object(modP, name, isShape, isProposed),
      _moduleName(NULL),
      _namespaceName(NULL),
      _explicitTypeNumber(0),
      _memberCount(0),
      _persistentCapable(oocUninitializedBool),
      _isContainer(false),
      _hasVirtualMethod(false),
      _hasOriginalVirtFunc(false),
      _addsVTable(false) {;}
  Type_Descriptor(ooIsNull) : d_Meta_Object(oocIsNull) {;}
  Type_Descriptor();

private:
  char * _moduleName;
  char * _namespaceName;
  unsigned long _explicitTypeNumber;
  size_t _memberCount;
  bool _persistentCapable;
  bool _isContainer;
  bool _hasVirtualMethod;
  bool _hasOriginalVirtFunc;
  bool _addsVTable;
};

class OO_STORAGE_SPECIFIER Property_Descriptor : public d_Meta_Object
{
  friend class d_Property;
  friend class d_Property_Int;
  friend class Proposed_Property;
  friend class Proposed_Property_Int;
  friend class Proposed_Ref_Attribute;
  friend class Proposed_Relationship;
  friend class Proposed_Base_Class;
  friend class Proposed_Embedded_Class_Attribute;
  friend class Proposed_VArray_Attribute;
  friend class d_Attribute;
  friend class ::otmEntry;

public:
  // We'd like to define type_of here, but it's an ODMG method required
  // to return d_Type.
  //      virtual Type_Descriptor &type_of() const;
  virtual uint32        id() const { return _id; }
  virtual const char *  other_class_name() const { return NULL; }
  virtual const char *  other_class_namespace_name() const { return NULL; }
  virtual ooTypeNumber  other_class_number() const;
  void			set_other_class_number(ooTypeNumber);
  ooMemberType          member_type() const { return _memberType; }
  virtual ooBaseType    base_type() const { return _baseType; }
  void                  set_base_type(ooBaseType bt) { _baseType = bt; }

protected:
  Property_Descriptor(const char *name,
		      uint32 = 0, // id
		      ooMemberType = 0); // definingClassP
  Property_Descriptor(ooIsNull) : d_Meta_Object(oocIsNull) {;}
  Property_Descriptor();

private:
  Type_Descriptor *	_typeP;
  Type_Descriptor *	_inClassP;
  d_Access_Kind         _visibility;
  uint32                _id;
  ooMemberType          _memberType;
  ooBaseType            _baseType;
  char *	        _otherClassName;
  char *	        _otherClassNamespaceName;
  ooTypeNumber		_otherClassNumber;
};

class OO_STORAGE_SPECIFIER Scope_Base
{
  friend class d_Meta_Object;
  friend class d_Meta_Object_Int;
protected:
  virtual void removeFromScope(d_Meta_Object *) {;}
  virtual bool is_module() const { return false; }
};

#ifndef OOTM_BOOTSTRAPPING

#if defined(_MSC_VER) && _MSC_VER > 1300
ooExplicitTemplateInstantiation OO_STORAGE_SPECIFIER ooTVArray(listElementP<d_Meta_Object >);
ooExplicitTemplateInstantiation OO_STORAGE_SPECIFIER ooTVArray(listElementP<d_Property >) ;
ooExplicitTemplateInstantiation OO_STORAGE_SPECIFIER ooTVArray(listElementP<d_Ref_Type >);
ooExplicitTemplateInstantiation OO_STORAGE_SPECIFIER ooTVArray(listElementP<d_Collection_Type >);
ooExplicitTemplateInstantiation OO_STORAGE_SPECIFIER ooTVArray(listElementP<d_Class >);
ooExplicitTemplateInstantiation OO_STORAGE_SPECIFIER ooTVArray(listElementP<Proposed_Class >);
ooExplicitTemplateInstantiation OO_STORAGE_SPECIFIER ooTVArray(listElementP<Namespace >);
ooExplicitTemplateInstantiation OO_STORAGE_SPECIFIER ooTVArray(listElementP<d_Module >);
ooExplicitTemplateInstantiation OO_STORAGE_SPECIFIER ooTVArray(listElementP<d_Attribute >);
ooExplicitTemplateInstantiation OO_STORAGE_SPECIFIER ooTVArray(listElementP<d_Relationship >);
ooExplicitTemplateInstantiation OO_STORAGE_SPECIFIER ooTVArray(listElementP<d_Inheritance >);
#endif

class OO_STORAGE_SPECIFIER metaObjectVector
{
public:
  metaObjectVector(uint32 growth = 10) : _growth(growth), _nextAvail(0) {}
  void add(const d_Meta_Object *);
  void truncate();
  ooTVArray(listElementP<d_Meta_Object >) _vector;
  uint32 _nextAvail;
  uint32 _growth;
};

class OO_STORAGE_SPECIFIER d_Property : public Property_Descriptor
{
  friend class d_Property_Int;
public:
  const d_Type &	type_of() const;
  d_Access_Kind		access_kind() const { return _visibility; }

  // The following methods are additions to the ODMG standard.
  //
  const d_Class &	defined_in_class() const;
  virtual bool		is_relationship() const { return false; }

  static const d_Property null;
  virtual ~d_Property() {;}

protected: // External calls prohibited
  d_Property(d_Class *,			// containingCP
	     const char *,		// name
	     ooMemberType,
	     otmAlignData *,
	     otmAssocShape *,
	     d_Module &);
  d_Property(ooIsNull) : Property_Descriptor(oocIsNull) {;}
  d_Property() {;}
};

class OO_STORAGE_SPECIFIER d_Attribute : public d_Property
{
  friend class ::otmEntry;
  friend class ::otmFdSchema;
  friend class d_Attribute_Int;
  friend class d_Relationship;
  friend class otmEvolveOverrides;
public:

  // Objectivity does not support static or read-only attributes, and
  // hence is_read_only() and is_static() always return false.
  //
  d_Boolean		is_read_only() const { return false; }
  d_Boolean		is_static() const { return false; }

  // dimension() returns the layout size of the attribute on the platform
  // running the application.
  //
  unsigned long	        dimension() const;

  // Virtual member function of d_Meta_Object base class of d_Property
  //
  // Usage of id() is primarily internal.  Its significance is that,
  // unlike position(), it returns a value which stays constant
  // across a schema evolution.
  //
  virtual uint32	id() const;

  // The following methods are additions to the ODMG standard.
  //
  // A d_Attribute has a unique position() value within a d_Class, and
  // this value is used by Active Schema to access objects of the class.
  // 
  // Remember that d_Attribute::position() returns a value relative to
  // its *defining* d_Class; a d_Class may, for example, inherit from
  // three different d_Classes, each of which has a d_Attribute at position
  // 0.  To avoid misinterpretation, use d_Class::position_in_class(),
  // which returns a Class_Position structure with inheritance context.
  // 
  size_t                position() const;

  // For static array attributes, array_size() returns the cardinality
  // of the array--or 1 if it is not an array.
  //
  size_t		array_size() const;

  // element_size() returns the size in bytes of the type of the attribute
  // on the running platform.  Therefore, dimension() is
  // (element_size() * array_size()).
  //
  size_t		element_size() const { return _elementSize; }
  bool		        is_base_class() const { return _isBaseClass; }
  const d_Class &	class_type_of() const;
  bool		        has_default_value() const;
  Numeric_Value &	default_value() const;
  virtual const char *  namespace_name() const { return _namespaceName; }
  virtual bool          is_relationship() const;
  virtual ooAsType	descriptor_kind() const { return d_Attribute_t; }
  int			operator==(const d_Attribute &) const;

  // The following methods are intended for internal Objectivity use only
  //
  size_t		offset() const;
  size_t		align() const { return _align; }
  virtual const d_Class &other_class() const;
  virtual const char *  other_class_name() const;
  virtual const char *  other_class_namespace_name() const;
  otmAlignData *	physical_data() const { return _alignP; }

  static const d_Attribute    null;
  virtual ~d_Attribute();

protected:
  d_Attribute(const char *,		// name
	      otmEntry *,		// containingClassR
	      ooMemberType,
	      size_t,			// eltSiz
	      size_t,			// align
	      otmAlignData *,
	      otmAssocShape *,
	      ooAssocNumber,	        // encodedAssocNum
	      d_Module &);
  d_Attribute() : _otiType(0) {;} // 0 = otiMemberInvalid
  d_Attribute(ooIsNull) : d_Property(oocIsNull) {;}

private:
  otmAlignData *_alignP;	// align_type, array_size, assoc/VAr, offset
  otmAssocShape *_assocShapeP;
  Numeric_Value	*_defaultValueP;
  const char *	_namespaceName;
  size_t	_elementSize;
  size_t	_align;
  ooMemberType	_otiType;	  // uint32
  int32		_position;
  uint32	_inverseID;       // applies only to relationships
  ooAssocNumber	_encodedAssocNum; // applies only to relationships
  ooAssocNumber	_rawAssocNum; // applies only to relationships
  bool		_isBaseClass;
  uint8         _copy;		  // applies only to relationships
  uint8         _version;	  // applies only to relationships
  uint8         _prop;		  // applies only to relationships
  uint8         _direction;       // applies only to relationships
  unsigned int  _isBi          : 1;	  // applies only to relationships
  unsigned int  _isInline      : 1;	  // applies only to relationships
  unsigned int  _isShort       : 1;	  // applies only to relationships
  unsigned int  _isToMany      : 1;	  // applies only to relationships
  unsigned int  _otherIsToMany : 1;	  // applies only to relationships
};

class OO_STORAGE_SPECIFIER d_Relationship : public d_Attribute
{
// Be sure not to add data members to derived classes of d_Attribute;
// d_Attribute objects are assumed to be the same size and are stored in
// an array block.
//
public:
  // rel_kind() returns REL_REF for to-one associations, REL_LIST
  // for to-many associations.  REL_SET is not used.
  //
  d_Rel_Kind            rel_kind() const;
  //
  // Note: defined_in_class() is inherited from d_Property
  //
  const d_Relationship &inverse() const;

  // The following methods are additions to the ODMG standard.
  //
  bool	                is_bidirectional() const;
  bool	                is_inline() const;
  bool	                is_short() const;
  bool	                is_to_many() const;
  bool	                inverse_is_to_many() const;
  uint32	        inverse_id() const;
  virtual ooAsType	descriptor_kind() const { return d_Relationship_t; }
  // const d_Class &    other_class() const; // From d_Attribute
  //
  // The "encoded_assoc_number" is a 32-bit serially-allocated integer
  // with some of the high-order bits set as internal code for direction,
  // cardinality (whether is_to_many() is true or false), and other
  // properties.
  //
  ooTypeNumber	        encoded_assoc_number() const;
  ooTypeNumber	        assoc_number() const; // Without property bits
  //
  // The propagation behavior of the relationship is encoded in 8-bit
  // integers which are obtainable through the remaining functions.
  //
  // The values returned by versioning() mean:
  //     0	No version information.
  //     oocVersionDrop
  // 	Delete the association in the new version of a versioned object.
  //     oocVersionMove
  // 	Move the association from the old version to the new version.
  //     oocVersionCopy
  // 	Copy the association from the old version to the new version.
  //
  uint8		versioning() const;
  //
  // The values returned by propagation() can be one of:
  //     0   No lock or delete propagation.
  //     oocLockPropagationYesDeletePropagationNo
  //     oocLockPropagationNoDeletePropagationYes
  //     oocLockPropagationYesDeletePropagationYes
  //
  uint8		propagation() const;
  //
  // The values returned by copy_mode() mean:
  //     0		  No copy information.
  //     oocCopyDrop
  //      Delete the association when a new object is created.
  //     oocCopyMove
  //      Move the association from the old object to the new object.
  //     oocCopyCopy
  //      Copy the association from the old object to the new object.
  //
  uint8		copy_mode() const;
  uint8		direction() const; // "down" (1), "up" (2), "uni" (3)
  static const d_Relationship null;

protected:
  d_Relationship(ooIsNull) : d_Attribute(oocIsNull) {;}
  d_Relationship() {;}
};

// d_Inheritance is part of the ODMG standard.  It describes an inheritance
// relationship, not either of the classes involved.  A descriptor for the
// base class is returned by the derives_from() method, and a descriptor for
// the derived class is returned by the inherits_to() method.

class OO_STORAGE_SPECIFIER d_Inheritance
{
  friend class ::otmEntry;
public:
  d_Access_Kind	access_kind() const { return _visibility; }
  //
  // Objectivity does not currently support persistent virtual
  // inheritance.
  //
  d_Boolean		is_virtual() const { return oocFalse; }
  const d_Class &	derives_from() const;
  const d_Class &	inherits_to() const;

  // The following methods are additions to the ODMG standard.
  //
  size_t		position() const { return _position; }
  operator size_t() const { return _position; }

protected:
  d_Inheritance(const d_Class &baseClassR,
		d_Class &derivedClassR,
		size_t position,
		d_Access_Kind visibility)
    : _toBaseP(&const_cast<d_Class &>(baseClassR)),
      _toDerivedP(&derivedClassR),
      _position(position),
      _visibility(visibility) {;}

private:
  d_Class *		_toBaseP;
  d_Class *		_toDerivedP;
  size_t		_position;
  d_Access_Kind	        _visibility;
};

typedef list_iterator<d_Meta_Object > meta_object_iterator;
typedef list_iterator<d_Attribute > attribute_iterator;
typedef list_iterator<d_Inheritance > inheritance_iterator;
typedef list_iterator<d_Relationship > relationship_iterator;
typedef list_iterator<d_Collection_Type > collection_type_iterator;
typedef list_iterator<d_Ref_Type > ref_type_iterator;
typedef list_iterator<d_Property > property_iterator;
typedef list_iterator<d_Module > module_iterator;
typedef list_iterator<Proposed_Class > proposed_class_iterator;
typedef list_iterator<Proposed_Base_Class > proposed_base_class_iterator;
typedef list_iterator<Proposed_Property > proposed_property_iterator;
typedef list_iterator<Namespace > namespace_iterator;
#ifdef OO_NT
template class OO_STORAGE_SPECIFIER list_iterator<d_Meta_Object >;
template class OO_STORAGE_SPECIFIER list_iterator<d_Attribute >;
template class OO_STORAGE_SPECIFIER list_iterator<d_Inheritance >;
template class OO_STORAGE_SPECIFIER list_iterator<d_Relationship >;
template class OO_STORAGE_SPECIFIER list_iterator<d_Collection_Type >;
template class OO_STORAGE_SPECIFIER list_iterator<d_Ref_Type >;
template class OO_STORAGE_SPECIFIER list_iterator<d_Property >;
template class OO_STORAGE_SPECIFIER list_iterator<d_Class >;
template class OO_STORAGE_SPECIFIER list_iterator<d_Module >;
template class OO_STORAGE_SPECIFIER list_iterator<Proposed_Class >;
template class OO_STORAGE_SPECIFIER list_iterator<Proposed_Property >;
template class OO_STORAGE_SPECIFIER list_iterator<Proposed_Base_Class >;
template class OO_STORAGE_SPECIFIER list_iterator<Namespace >;
#endif // OO_NT

class OO_STORAGE_SPECIFIER type_iterator
  : public list_iterator<d_Meta_Object >
{
  friend class d_Module;
public:
  inline type_iterator &	operator=(const type_iterator &);
  inline int			operator==(const type_iterator &) const;
  inline int			operator!=(const type_iterator &) const;
  type_iterator &               operator++();
  type_iterator                 operator++(int);
  const d_Type &		operator*() const;
  ooAsIterType		        asType() const { return type_iterator_t; }

  type_iterator() : _truncateAt(0) {;}

  // Constructor taking a d_Meta_Object ooTVarray and a boolean
  // specifying a terminated iterator against which to compare in
  // "while" loops
  //
  type_iterator(const d_Iterator<listElementP<d_Meta_Object > > &itr,
		size_t truncateAt)
    : list_iterator<d_Meta_Object >(itr), _truncateAt(truncateAt) {
    this->positionAtNextTypeItem();
  }
  void		positionAtNextTypeItem() const;
private:
  size_t	_truncateAt;
};

// Assignment operator
//
type_iterator &
type_iterator::operator=(const type_iterator &moI)
{
  *static_cast<list_iterator<d_Meta_Object > *>(this) = moI;
  _truncateAt = moI._truncateAt;
  return *this;
}

int
type_iterator::operator==(const type_iterator &moI) const
{
  return (*static_cast<const list_iterator<d_Meta_Object > *>(this) == moI);
}

int
type_iterator::operator!=(const type_iterator &moI) const
{
  return (*static_cast<const list_iterator<d_Meta_Object > *>(this) != moI);
}

// iteratorStack supports the attribute_iterator_scope/base_class_iterator-
// scope mechanism.  d_Attributes of a d_Class are iterated, but if an
// attribute is a base class, we will descend into it, pushing the new
// iterator onto a stack of iterators.  The stack will grow as deep as
// the level of base class nesting.
//
// base_class_iterator_scope works similarly, except that because of the
// way the stack works, we need to record whether an iterator was just
// pushed on the stack or has been there for at least one dereference.
// The reason for this is that besides being a node into which we want
// to descend, the base class is itself an item we want to visit.
//
// Each stack element also has an iterator, its end() object for termination
// equality, and a pointer to the rest of the stack.
//
template <class T, class ITERATOR>
class iteratorStack : public oasHeapData
{
public:
  iteratorStack(ooTVArray(listElementP<T >) &varray)
    : _itr(ITERATOR(varray)),
      _end(ITERATOR(varray, /*end=*/true)),
      _nextP(NULL) {;}
  inline        iteratorStack(const iteratorStack<T, ITERATOR > &);
  inline        ~iteratorStack();
  ITERATOR &    iterator() { return _itr; }
  ITERATOR &    end() { return _end; }
  iteratorStack<T, ITERATOR > *
                nextP() const { return _nextP; }
  inline iteratorStack<T, ITERATOR > *
                push(iteratorStack<T, ITERATOR > *);
  inline iteratorStack<T, ITERATOR > *
                pop();
  inline int	operator==(const iteratorStack<T, ITERATOR > &) const;
  void		set_iterator(ITERATOR i) { _itr = i; }
  void	        set_nextP(iteratorStack<T, ITERATOR > *n) { _nextP = n; }

private:
  ITERATOR	_itr;
  ITERATOR	_end;
  iteratorStack<T, ITERATOR > * _nextP;
};

template <class T, class ITERATOR >
inline int
iteratorStack<T, ITERATOR >::operator==
(const iteratorStack<T, ITERATOR > &other) const
{
  iteratorStack<T, ITERATOR > *varThis =
    (iteratorStack<T, ITERATOR > *)this;
  iteratorStack<T, ITERATOR > &varOther =
    (iteratorStack<T, ITERATOR > &)other;
  if (varThis->iterator() != varOther.iterator()) {
    return 0;
  } else if ((varThis->nextP() == NULL) && (other.nextP() == NULL)) {
    return 1;
  } else if ((varThis->nextP() == NULL) || (other.nextP() == NULL)) {
    return 0;
  } else {
    return (*(varThis->nextP()) == *(other.nextP()));
  }
}

#ifndef OO_COMMA
#define OO_COMMA ,
#endif

// Copy constructor
//
template <class T, class ITERATOR >
inline
iteratorStack<T, ITERATOR >::iteratorStack
(const iteratorStack<T, ITERATOR > &origR)
  : _itr(const_cast<iteratorStack<T OO_COMMA ITERATOR > &>(origR).iterator()),
    _end(const_cast<iteratorStack<T OO_COMMA ITERATOR > &>(origR).end()),
    _nextP(NULL)
{
  iteratorStack<T, ITERATOR > *origNextP = origR.nextP();
  if (origNextP != NULL) {
    //
    // Copy constructs recursively
    //
    this->set_nextP(new iteratorStack<T, ITERATOR >(*origNextP));
  }
}

template <class T, class ITERATOR >
inline iteratorStack<T, ITERATOR > *
iteratorStack<T, ITERATOR >::push(iteratorStack<T, ITERATOR > *itrStackP)
{
  itrStackP->set_nextP(this);
  return itrStackP;
}

template <class T, class ITERATOR >
inline iteratorStack<T, ITERATOR > *
iteratorStack<T, ITERATOR >::pop()
{
  iteratorStack<T, ITERATOR > *oldHeadP = this;
  iteratorStack<T, ITERATOR > *newHeadP = this->nextP();
  oldHeadP->set_nextP(NULL);	// Prevent recursive delete
  delete oldHeadP;
  return newHeadP;
}

template <class T, class ITERATOR >
inline
iteratorStack<T, ITERATOR >::~iteratorStack()
{
  delete _nextP;
}

class OO_STORAGE_SPECIFIER attribute_plus_inherited_iterator
: public asIterator
{
  friend class d_Class;
public:
  attribute_plus_inherited_iterator &
		operator=(const attribute_plus_inherited_iterator &);
  int		operator==(const attribute_plus_inherited_iterator &) const;
  int		operator!=(const attribute_plus_inherited_iterator &) const;
  attribute_plus_inherited_iterator &
		operator++();
  attribute_plus_inherited_iterator
		operator++(int);
  const d_Attribute &
		operator*() const;
  ooAsIterType
		asType() const { return attribute_plus_inherited_iterator_t; }
  bool          isAtEnd() const;

  // Copy constructor
  //
  attribute_plus_inherited_iterator
	(const attribute_plus_inherited_iterator &);
  attribute_plus_inherited_iterator() : _itrStackP(NULL) {;}
  virtual ~attribute_plus_inherited_iterator();

protected:
  attribute_plus_inherited_iterator(ooTVArray(listElementP<d_Attribute >) &);
  iteratorStack<d_Attribute, attribute_iterator > *
                itrStackP() const { return _itrStackP; }
  void          set_itrStackP(iteratorStack<d_Attribute,
			      attribute_iterator > *aisP) {
    _itrStackP = aisP;
  }
  void          pushBaseIterator(ooTVArray(listElementP<d_Attribute >) *);
  void          popBaseIterator() {
    this->set_itrStackP(this->itrStackP()->pop());
  }
  void          positionAtNextItem();

private:
  iteratorStack<d_Attribute, attribute_iterator > *
		_itrStackP;
};

class OO_STORAGE_SPECIFIER base_class_plus_inherited_iterator
  : public asIterator
{
public:
    base_class_plus_inherited_iterator &
		operator=(const base_class_plus_inherited_iterator &);
    int		operator==(const base_class_plus_inherited_iterator &) const;
    int		operator!=(const base_class_plus_inherited_iterator &) const;
    base_class_plus_inherited_iterator &
		operator++();
    base_class_plus_inherited_iterator
		operator++(int);
    const d_Class &
		operator*() const;
    ooAsIterType
		asType() const { return base_class_plus_inherited_iterator_t; }
    bool	isAtEnd() const;

    base_class_plus_inherited_iterator(
      ooTVArray(listElementP<d_Inheritance >) &);
    base_class_plus_inherited_iterator // Copy constructor
	(const base_class_plus_inherited_iterator &);
    base_class_plus_inherited_iterator() : _itrStackP(NULL) {;}
    virtual ~base_class_plus_inherited_iterator();

protected:
    iteratorStack<d_Inheritance, inheritance_iterator > *
		itrStackP() const { return _itrStackP; }
    void	set_itrStackP(iteratorStack<d_Inheritance,
					    inheritance_iterator > *aisP) {
	_itrStackP = aisP;
    }
    void	pushBaseIterator(ooTVArray(listElementP<d_Inheritance >) *);
    void	popBaseIterator() {
	this->set_itrStackP(this->itrStackP()->pop());
    }

private:
    iteratorStack<d_Inheritance, inheritance_iterator > *
		_itrStackP;
};

template<class T>
list_iterator<T >
erase(ooTVArray(listElementP<T >) *vectorP, list_iterator<T > &i)
{
  int curIndex = i.d_Iterator<listElementP<T > >::get_index();
  unsigned int vectorSize = vectorP->size();
  if (vectorSize == 0) {
    return i;
  }
  for (unsigned int ix = curIndex; ix < (vectorSize - 1); ++ix) {
    (*vectorP)[ix] = (*vectorP)[ix + 1];
  }
  vectorP->resize(vectorSize - 1);
  d_Iterator<listElementP<T > > returnIterator(vectorP, curIndex, vectorSize);
  return list_iterator<T >(returnIterator);
}

template<class T>
list_iterator<T >
insert(ooTVArray(listElementP<T >) *vectorP,
       list_iterator<T > &i,
       const listElementP<T > *elP)
{
  int curIndex = i.d_Iterator<listElementP<T > >::get_index();
  unsigned int vectorSize = vectorP->size();
  vectorP->resize((vectorSize + 1), /*copy=*/true);
  for (int ix = (vectorSize - 1); ix >= curIndex; --ix) {
    (*vectorP)[ix + 1] = (*vectorP)[ix];
  }
  (*vectorP)[curIndex] = *elP;
  d_Iterator<listElementP<T > > returnIterator(vectorP,
					       (curIndex + 1),
					       (vectorSize + 1));
  return list_iterator<T >(returnIterator);
}

class OO_STORAGE_SPECIFIER d_Scope : public Scope_Base
{
  friend class d_Meta_Object;
  friend class d_Type;
  friend class d_Class;
  friend class d_Module;

public:
  // If the Objectivity "class versioning" feature has been used, the
  // second argument can be used to discern among versions.
  //
  virtual const d_Meta_Object &	resolve(const char *,	// name
					int32 =		// version
					oocLatestVersion,
					const char * =	// namespace
					NULL) const = 0;

  // The method defines_begin() returns an iterator over the name string
  // hash table of this d_Scope.
  //
  virtual meta_object_iterator	defines_begin() const = 0;
  virtual meta_object_iterator	defines_end() const = 0;

  virtual bool			is_module() const { return false; }
  virtual bool			is_class() const { return false; }
  virtual bool			is_namespace() const { return false; }

  virtual ~d_Scope() { _destructing = true; }

protected:
  d_Scope() : _destructing(false) {;}
  virtual void          removeFromScope(d_Meta_Object *);
  bool			destructing() const { return _destructing; }

private:
  bool			_destructing;
};

class OO_STORAGE_SPECIFIER Namespace
  : public d_Scope, public d_Meta_Object
{
  friend class Namespace_Int;
  friend class d_Module;
  friend class otmEvolveOverrides;
  friend class ::otmEntry;
public:
  // Virtual methods of d_Scope
  //
  virtual const d_Meta_Object &	resolve(const char *,	// name
					int32 =		// version
					oocLatestVersion,
					const char * =	// namespace
					NULL) const;
  virtual meta_object_iterator	defines_begin() const;
  virtual meta_object_iterator	defines_end() const;

  virtual bool	        is_namespace() const { return true; }
  bool		        is_deleted() const { return _deleted; }
  ooAsLanguages	        language() const { return _language; }
  virtual ooAsType	descriptor_kind() const { return Namespace_t; }

  void		        set_isDeleted(bool TorF) { _deleted = TorF; }

  // The following methods are intended for internal Objectivity use only
  //
  ooStatus init();
  ost_table *defines() { return _defines; }
  ooTVArray(listElementP<d_Meta_Object >) &definesList() {
    return _definesList;
  }
  static const Namespace null;

protected:
  Namespace(d_Module *, const char *name, ooAsLanguages);
  Namespace(ooIsNull) // Just for creating Namespace::null
    : d_Meta_Object(oocIsNull) {;}
  Namespace();

private:
  ost_table *		_defines;
  ooTVArray(listElementP<d_Meta_Object >)
                        _definesList;
  ooAsLanguages	        _language;
  bool		        _deleted;
};

class OO_STORAGE_SPECIFIER d_Type : public Type_Descriptor
{
  friend class d_Ref_Type;
  friend class Relationship_Type;
  friend class VArray_Basic_Type;
  friend class VArray_Embedded_Class_Type;
  friend class d_Type_Int;
  friend class Class_Object;
  friend class VArray_Object;
  friend class ::otmFdSchema;
public:
  collection_type_iterator	used_in_collection_type_begin() const;
  collection_type_iterator	used_in_collection_type_end() const;

  ref_type_iterator		used_in_ref_type_begin() const;
  ref_type_iterator		used_in_ref_type_end() const;

  property_iterator		used_in_property_begin() const;
  property_iterator		used_in_property_end() const;

  // Virtual member function of d_Meta_Object base
  //
  bool                          is_type() const { return true; }

  virtual size_t                dimension() const { return _size; }

  // The following methods are additions to the ODMG standard.

  // Non-class types will be assigned a unique 32-bit AStypeNumberCode
  // OR-constructed with a set high bit, the ooMemberType shifted left
  // 27, and the referenced or collected class number or referenced
  // ooBaseType.  For class types, type_number returns the Objectivity
  // type number.
  //
  // ooTypeNumber type_number()           // From Type_Descriptor
  // size_t       number_of_attributes()  // From Type_Descriptor
  const d_Module &
                defined_in_module() const;
  virtual const char *  module_name() const;
  virtual const char *  namespace_name() const;
  virtual bool	is_basic_type() const { return false; }
  virtual bool	is_varray_type() const { return false; }
  virtual bool	is_varray_basic_type() const { return false; }
  virtual bool	is_varray_embedded_class_type() const { return false; }
  virtual bool	is_varray_ref_type() const { return false; }
  virtual bool	is_varray_string_type() const { return false; }
  virtual bool	is_relationship_type() const { return false; }
  virtual bool	is_unidirectional_relationship_type() const { return false; }
  virtual bool	is_bidirectional_relationship_type() const { return false; }
  virtual bool	is_ref_type() const { return false; }
  virtual bool	is_string_type() const { return false; }

  // The following methods are intended for internal Objectivity use only
  //
  bool insertProperty(d_Property *);
  bool insertCollectionType(d_Collection_Type *, bool search = true);
  bool insertRefType(d_Ref_Type *, bool search = true);
  void set_size(size_t s) { _size = s; }
  virtual ~d_Type();
  static const d_Type null;

protected:
  d_Type(ooIsNull) : Type_Descriptor(oocIsNull) {;}
  d_Type(d_Module *modP,
	 const char *name = NULL,
	 size_t eltSize = oocUninitializedSize_t,
	 bool isShape = false);
  d_Type() {;}
  bool		isOptimizedStringType() const;

private:
  size_t			              _size;
  metaObjectVector			      _used_in_property;
  ooTVArray(listElementP<d_Ref_Type >)        _used_in_ref_type;
  ooTVArray(listElementP<d_Collection_Type >) _used_in_collection_type;
};

// A Property_Type describes a non-class type for class attributes or
// relationships.  Property_Type is not part of the ODMG standard.

class OO_STORAGE_SPECIFIER Property_Type : public d_Type
{
    friend class Basic_Type;
public:
    virtual			operator size_t() const;
    inline virtual ooTypeNumber	type_number() const;
    virtual uint32		id() const;

protected: // External calls prohibited
    Property_Type(const char *,		// name
		  uint32,		// AStypeNumberCode
		  void *,		// baseData
		  size_t,		// eltSize
		  d_Module &);
    void *			baseData() const { return _baseData; }
    void			set_baseData(void *d) { _baseData = d; }

private:
    uint32			_AStypeNumberCode;
    void *			_baseData;
};

inline ooTypeNumber
Property_Type::type_number() const
{
    return _AStypeNumberCode;
}

inline uint32
Property_Type::id() const
{
  return (_isNull ? 0 : _AStypeNumberCode);
}

// An Attribute_Type describes a non-class type for class attributes.
// Property_Type is not part of the ODMG standard.

class OO_STORAGE_SPECIFIER Attribute_Type : public Property_Type
{
protected: // External calls prohibited
    Attribute_Type(const Attribute_Type &);
    Attribute_Type &operator=(const Attribute_Type &);
    Attribute_Type(const char *,	// name
		   uint32,		// AStypeNumberCode
		   void *,		// baseData
		   size_t,		// eltSize
		   d_Module &);
    virtual	~Attribute_Type() {;}
};

// d_Collection_Type is part of the ODMG standard.  Objectivity supports
// only one collection type that is primitive with respect to the schema:
// ooVArray (ooMap, for instance, is defined in terms of other primitives);
// therefore, kind() always returns ARRAY.  d_Collection_Type therefore
// describes the type of a VArray attribute.

class OO_STORAGE_SPECIFIER d_Collection_Type : public Attribute_Type
{
  friend class d_Class;
  friend class d_Type_Int;
  friend class otmSchemaAccessOverrides;
  friend class ::otmEntry;
public:
  virtual d_Kind		kind() const = 0; // will return ARRAY
  virtual const d_Type &	element_type() const;

protected: // External calls prohibited
  d_Collection_Type(const d_Collection_Type &);
  d_Collection_Type &operator=(const d_Collection_Type &);
  inline d_Collection_Type(d_Type *,		// typeP
			   const char *,	// name
			   uint32,		// AStypeNumberCode
			   d_Module &);
  virtual ~d_Collection_Type() {;}
protected:
  void			set_elementType(const d_Type &typeR) {
    this->set_baseData(static_cast<void *>(const_cast<d_Type *>(&typeR)));
  }
};

inline
d_Collection_Type::d_Collection_Type(d_Type *typeP,
				     const char *name,
				     uint32 AStypeNumberCode,
				     d_Module &topModR)
  : Attribute_Type(name,
		   AStypeNumberCode,
		   typeP,			// baseData
		   sizeof(opiVArray<int>),      // eltSiz
		   topModR)
{;}

// d_Ref_Type is part of the ODMG standard.  In Active Schema it describes
// the type of the Objectivity construct ooRef(T) where T inherits from
// ooObj.

class OO_STORAGE_SPECIFIER d_Ref_Type
  : public Attribute_Type
{
  friend class d_Class;
  friend class d_Property;
  friend class d_Type_Int;
  friend class otmSchemaAccessOverrides;
  friend class ::otmFdSchema;
  friend class ::otmEntry;
public:
  d_Ref_Kind		ref_kind() const { return _refKind; }
  //
  // referenced_type() returns a reference to the d_Class describing T.
  //
  const d_Type &	referenced_type() const;

  // The following methods are additions to the ODMG standard.
  //
  bool			is_short() const { return _isShort; }
  virtual bool		is_ref_type() const { return true; }
  virtual ooAsType	descriptor_kind() const { return d_Ref_Type_t; }

protected: // External calls prohibited
  d_Ref_Type(d_Ref_Kind,	// = REF (not POINTER)
	     d_Type *,		// refTypeP
	     ooTypeNumber,	// refClassNumber
	     uint32,		// AStypeNumberCode
	     bool,		// isShort
	     d_Module &);
  d_Ref_Type(const d_Ref_Type &);
  d_Ref_Type &operator=(const d_Ref_Type &);
  void		set_referencedType(const d_Type &typeR) {
    this->set_baseData(static_cast<void *>(const_cast<d_Type *>(&typeR)));
  }
private:
  d_Ref_Kind	_refKind;
  bool		_isShort;
};

// Basic_Type is roughly equivalent to the ODMG class d_Primitive_Type,
// except that the domain of values is Objectivity's set of primitive
// data types.  It describes the type of a numeric or character
// attribute.
//
class OO_STORAGE_SPECIFIER Basic_Type
  : public Attribute_Type
{
  friend class d_Property;
  friend class d_Module;
  friend class ::otmFdSchema;
public:
  //
  // base_type() returns one of:
  //
  // oocTypeNONE	oocTypeCHAR	oocTypeINT8	oocTypeUINT8
  // oocTypeBOOLEAN	oocTypeINT16	oocTypeUINT16	oocTypeCHAR16
  // oocTypeINT32	oocTypeUINT32	oocTypeCHAR32	oocTypeINT64
  // oocTypeUINT64	oocTypeFLOAT32	oocTypeFLOAT64	oocTypePTR
  //
  virtual ooBaseType	base_type() const;
  virtual bool	        is_basic_type() const { return true; }
  virtual ooAsType	descriptor_kind() const { return Basic_Type_t; }

protected: // External calls prohibited
  Basic_Type(ooBaseType,
	     uint32,		// AStypeNumberCode
	     size_t,		// eltSize
	     d_Module &);
  Basic_Type(const Basic_Type &);
  Basic_Type &operator=(const Basic_Type &);
};

// Relationship_Type describes the type of a relationship (association)
// property of a d_Class.  Relationship_Type is not part of the ODMG
// standard.

class OO_STORAGE_SPECIFIER Relationship_Type : public Property_Type
{
  friend class d_Class;
  friend class d_Property;
  friend class d_Attribute;
  friend class d_Relationship;
  friend class d_Type_Int;
  friend class Unidirectional_Relationship_Type;
  friend class Bidirectional_Relationship_Type;
  friend class Class_Object;
  friend class Relationship_Object;
  friend class otmSchemaAccessOverrides;
  friend class ::otmFdSchema;
  friend class ::otmEntry;
public:
  const d_Class &	other_class() const;
  virtual bool	        is_relationship_type() const { return true; }

protected: // External calls prohibited
  Relationship_Type(d_Class *,	// otherCP
		    d_Class *,	// thisCP
		    uint32,	// AStypeNumberCode
		    otmAssocShape *,
		    d_Module &);
  virtual	~Relationship_Type() {;}
  void		set_otherClassP(d_Class *p) { _otherClassP = p; }

private:
  d_Class *	_otherClassP;
};

// Unidirectional_Relationship_Type describes the type of a
// unidirectional relationship (association) property of a d_Class.
// Unidirectional_Relationship_Type is not part of the ODMG standard.

class OO_STORAGE_SPECIFIER Unidirectional_Relationship_Type
    : public Relationship_Type
{
  friend class d_Property;
  friend class ::otmFdSchema;
public:
  virtual bool	        is_unidirectional_relationship_type() const {
    return true;
  }
  virtual ooAsType	descriptor_kind() const {
    return Unidirectional_Relationship_Type_t;
  }
protected: // External calls prohibited
  Unidirectional_Relationship_Type(d_Class *,	// otherCP
				   d_Class *,	// thisCP
				   uint32,	// AStypeNumberCode
				   otmAssocShape *,
				   d_Module &);
  Unidirectional_Relationship_Type
  (const Unidirectional_Relationship_Type &);
  Unidirectional_Relationship_Type &operator=
  (const Unidirectional_Relationship_Type &);
};

// Bidirectional_Relationship_Type describes the type of a
// bidirectional relationship (association) property of a d_Class.
// Bidirectional_Relationship_Type is not part of the ODMG standard.

class OO_STORAGE_SPECIFIER Bidirectional_Relationship_Type
    : public Relationship_Type
{
  friend class d_Property;
  friend class ::otmFdSchema;
public:
  virtual bool	        is_bidirectional_relationship_type() const {
    return true;
  }
  virtual ooAsType	descriptor_kind() const {
    return Bidirectional_Relationship_Type_t;
  }
protected: // External calls prohibited
  Bidirectional_Relationship_Type(d_Class *,	// otherCP
				  d_Class *,	// thisCP
				  uint32,	// AStypeNumberCode
				  otmAssocShape *,
				  d_Module &);
  Bidirectional_Relationship_Type(const Bidirectional_Relationship_Type &);
  Bidirectional_Relationship_Type &operator=
  (const Bidirectional_Relationship_Type &);
};

// VArray_Basic_Type describes the type of a VArray attribute whose
// elements are numeric or character primitives.  VArray_Basic_Type is
// not part of the ODMG standard.

class OO_STORAGE_SPECIFIER VArray_Basic_Type
    : public d_Collection_Type
{
  friend class d_Property;
  friend class ::otmFdSchema;
public:
  d_Kind		kind() const { return ARRAY; }
  ooBaseType		element_base_type() const;
  virtual bool	        is_varray_type() const { return true; }
  virtual bool	        is_varray_basic_type() const { return true; }
  virtual ooAsType	descriptor_kind() const { return VArray_Basic_Type_t; }

protected: // External calls prohibited
  VArray_Basic_Type(ooBaseType,	// btype
		    uint32,	// AStypeNumberCode
		    d_Type *,	// eltTypeP
		    d_Module &);
  VArray_Basic_Type(const VArray_Basic_Type &);
  VArray_Basic_Type &operator=(const VArray_Basic_Type &);
};

// VArray_Embedded_Class_Type describes the type of a VArray attribute
// whose elements are are class objects.  VArray_Embedded_Class_Type
// is not part of the ODMG standard.

class OO_STORAGE_SPECIFIER VArray_Embedded_Class_Type
    : public d_Collection_Type
{
  friend class d_Property;
  friend class ::otmFdSchema;
public:
  d_Kind		kind() const { return ARRAY; }
  const d_Class &	element_class_type() const;
  bool		        is_varray_type() const { return true; }
  virtual bool	        is_varray_embedded_class_type() const {
    return true;
  }
  virtual bool	        is_varray_string_type() const;
  virtual ooAsType	descriptor_kind() const {
    return VArray_Embedded_Class_Type_t;
  }

protected: // External calls prohibited
  VArray_Embedded_Class_Type(ooTypeNumber,	// eltClassNum
			     uint32,		// AStypeNumberCode
			     d_Type *,		// eltTypeP
			     d_Module &);
  VArray_Embedded_Class_Type(const VArray_Embedded_Class_Type &);
  VArray_Embedded_Class_Type &operator=(const VArray_Embedded_Class_Type &);
};

// VArray_Ref_Type describes the type of a VArray attribute whose
// elements are object references (ooRefs).  VArray_Ref_Type is not
// part of the ODMG standard.

class OO_STORAGE_SPECIFIER VArray_Ref_Type
  : public d_Collection_Type
{
  friend class d_Property;
  friend class ::otmFdSchema;
public:
  d_Kind		kind() const { return ARRAY; }
  const d_Ref_Type &	element_ref_type() const;
  bool		        is_varray_type() const { return true; }
  bool		        is_varray_ref_type() const { return true; }
  virtual ooAsType	descriptor_kind() const { return VArray_Ref_Type_t; }

protected: // External calls prohibited
  VArray_Ref_Type(ooTypeNumber,	// refClassNum
		  uint32,	// AStypeNumberCode
		  d_Type *,	// eltTypeP
		  bool,		// isShort
		  d_Module &);
  VArray_Ref_Type(const VArray_Ref_Type &);
  VArray_Ref_Type &operator=(const VArray_Ref_Type &);
};

#define OAS_ATTACHING_MASK 1
#define OAS_INHERITANCE_PROCESSED_MASK 1 << 1
#define OAS_ATTRIBUTES_PROCESSED_MASK 1 << 2
// Don't go up to 8 here

// Not for public use; facilitates memory reclamation.  Ordinarily a
// Class_Position that gets copied on the stack does a deep copy of
// the representation of its position vector; when we want to pass
// internally managed data without that overhead, we use
// ClassPosNoCopy.
//
class OO_STORAGE_SPECIFIER ClassPosNoCopy : public oasHeapData
{
    friend class Class_Position;
    friend class d_Class;
    friend class ::otmEntry;
public:
  inline ClassPosNoCopy(size_t);
  inline ClassPosNoCopy();
  virtual ~ClassPosNoCopy() {;}
  size_t		position() const { return _position; }
  ClassPosNoCopy *	nextP() const { return _nextP; }
  void			set_position(size_t pos) { _position = pos; }
  void			set_nextP(ClassPosNoCopy *nP) { _nextP = nP; }

private:
  size_t		_position;
  ClassPosNoCopy *	_nextP;
  size_t		_offset;
  ooTypeNumber		_shapeNumber;
  const d_Attribute *   _leafAttributeP;
};

ClassPosNoCopy::ClassPosNoCopy(size_t p)
  : _position(p),
    _nextP(NULL),
    _offset(oocUninitializedSize_t),
    _shapeNumber(0),
    _leafAttributeP(NULL)
{;}

ClassPosNoCopy::ClassPosNoCopy()
  : _position(oocUninitializedSize_t),
    _nextP(NULL),
    _offset(oocUninitializedSize_t),
    _shapeNumber(0),
    _leafAttributeP(NULL)
{;}

// If more than one level of inheritance exists between an attribute and its
// defining class, Class_Position can express the inheritance path in terms of
// nested class position numbers.  Class_Position is a property of a class,
// not of an attribute or attribute type, since an attribute's defining class
// may be inherited by different classes at different base class positions.
// Typically, a Class_Position is obtained by calling
// d_Class::position_in_class(const char *memName).  Class_Position is
// not part of the ODMG standard.

class OO_STORAGE_SPECIFIER Class_Position : public ClassPosNoCopy
{
  friend class ::otmEntry;
public:
  int			operator==(const Class_Position &) const;
  Class_Position &	operator=(const Class_Position &);
  inline int		operator!() const;
                        operator size_t() const;
  bool		        is_convertible_to_uint() const {
    return (nextP() == NULL);
  }
  Class_Position();
  Class_Position(size_t, Class_Position * = NULL);
  Class_Position(const Class_Position &);
  virtual ~Class_Position();
  static const Class_Position		null;

  int		        operator==(void *) const;
  int		        operator!=(void *) const;
  size_t                offset(ooTypeNumber) const;
  const d_Attribute *   leafAttributeP(ooTypeNumber) const;
};

inline int
Class_Position::operator!() const
{
  return (this->position() == oocUninitializedSize_t);
}

// d_Class is part of the ODMG standard.  It describes a stand-alone
// or embedded database type composed of attributes and relationships.
// The ODMG class hierarchy implies that d_Relationship and d_Attribute
// are disjunct, but because of Objectivity's architecture, d_Attribute
// has been made an immediate base class of d_Relationship.
//
// Classes can be looked up via hash tables in a schema module by name or
// Objectivity type number.  The members of a class may be iterated, or a
// named member looked up in the class scope.  Relationships, base
// classes, and sub-classes (derived classes) of a class may be iterated.

class OO_STORAGE_SPECIFIER d_Class : public d_Type, public d_Scope
{
  friend class d_Module_Int;
  friend class d_Attribute;
  friend class attribute_plus_inherited_iterator;
  friend class base_class_plus_inherited_iterator;
  friend class otmSchemaAccessOverrides;
  friend class ::otmEntry;
  friend class asAutoCleanOtiClassDelete;
  friend class Class_Object;
  friend class Class_Object_Int;

public:
  // Virtual member functions of d_Scope base
  //
  virtual meta_object_iterator	defines_begin() const;
  virtual meta_object_iterator	defines_end() const;

  inheritance_iterator		sub_class_list_begin() const;
  inheritance_iterator		sub_class_list_end() const;

  inheritance_iterator		base_class_list_begin() const;
  inheritance_iterator		base_class_list_end() const;

  attribute_iterator		defines_attribute_begin() const;
  attribute_iterator		defines_attribute_end() const;
  relationship_iterator		defines_relationship_begin() const;
  relationship_iterator		defines_relationship_end() const;

  const d_Attribute &		resolve_attribute(const char *) const;
  const d_Relationship &	resolve_relationship(const char *) const;
  virtual d_Boolean		persistent_capable() const;
  d_Boolean			has_extent() const;

  // Virtual member functions of d_Type base
  //
  inline virtual		operator size_t() const;
  inline virtual uint32		id() const;
  inline virtual ooTypeNumber	type_number() const;

  // Virtual member functions of d_Scope base
  //
  virtual const d_Meta_Object &	resolve(const char *,		// class name
					int32 = oocLatestVersion,
					const char * = NULL	// namespace
				) const;

  // Base classes are treated similarly to embedded class attributes.
  // They occupy a single "position," rather than a position for every
  // inherited attribute.  Consider:
  //
  //    class base : public ooObj {
  //        int32 x; };
  //
  //    class der : public base {
  //        int32 y; };
  //
  // An iteration over "der" using defines_attribute_begin() will hit two
  // attributes, "base" and "y," rather than three, "ooObj," "x." and "y."
  //
  // To iterate with base classes flattened into inherited attributes,
  // use attributes_plus_inherited_begin().  When obtaining attribute
  // positions in that context, using d_Class::position_in_class() is more
  // intuitive than using d_Attribute::position().  A d_Attribute only
  // knows its position relative to its defining class; it can't guess what
  // position you care about if you're using its class somewhere in
  // an inheritance hierarchy.
  //
  // For example, iterating "der" with attributes_plus_inherited_begin()
  // will visit "ooObj," "x," and "y," but note that if you call
  // d_Attribute::position() on either "x" or "y," the return value will
  // be 1--an apparent conflict.  That's because d_Attribute doesn't
  // know anything about its inheritance context.  Specify that context
  // by calling d_Class::position_in_class("y"), and the return value will
  // be unique in the derived class context.  The following methods are
  // additions to the ODMG standard.
  //
  attribute_plus_inherited_iterator
				attributes_plus_inherited_begin() const;
  attribute_plus_inherited_iterator
				attributes_plus_inherited_end() const;

  // Similarly, base_classes_plus_inherited_begin() returns an iterator
  // which visits every inherited class, as opposed to base_class_list_-
  // begin(), whose iterator visits only the immediate base classes.
  //
  base_class_plus_inherited_iterator
				base_classes_plus_inherited_begin() const;
  base_class_plus_inherited_iterator
				base_classes_plus_inherited_end() const;

  // attribute_at_position() returns the attribute at index N, where N
  // varies from 0 to one less than number_of_attributes().
  //
  const d_Attribute &	attribute_at_position(const Class_Position &)const;
  const d_Attribute &	attribute_at_position(size_t) const;
  const d_Attribute &	attribute_with_id(uint32) const;
  const Class_Position  position_in_class(const char *) const;
  const Class_Position  position_in_class(const d_Attribute &) const;
  virtual bool		is_class() const { return true; }
  virtual bool		is_string_type() const;
  virtual ooAsType	descriptor_kind() const { return d_Class_t; }
  bool			is_internal() const { return _isInternal; }
  bool			is_deleted() const;
  bool			has_base_class(const char *) const;
  virtual bool		has_virtual_table() const { return false; }
  virtual bool		has_virtual_attribute() const { return false; }
  //
  // When a class is evolved, shape_number() becomes greater than
  // type_number().
  //
  ooTypeNumber		shape_number() const;
  //
  // next_shape() and previous_shape() return the following and preceding
  // shapes of an evolved class, respectively.
  //
  const d_Class &	next_shape() const;
  const d_Class &	previous_shape() const;
  //
  // The version_number() function returns the number of a changed class
  // where "schema versioning" was used rather than "schema evolution."
  //
  virtual int32		version_number() const { return 0; }
  const d_Class &	latest_version() const;
  OO_REF_TYPE		get_static_ref() const;
  ooStatus		set_static_ref(const OO_REF_TYPE &);
  const Namespace &	defined_in_namespace() const;
  virtual const char *	namespace_name() const;
  const char *		raw_class_name() const;
  static void		enable_root_descent();
  static void		disable_root_descent();
  static bool		root_descent_is_enabled();

  // The following methods are intended for internal Objectivity use only
  virtual size_t	align() const { return 0; }
  bool                  created_by_active_schema() const {
    return _createdByActiveSchema;
  }
  uint32                highest_attribute_id() const { return _highestAttID; }
  void                  set_highest_attribute_id(uint32 val) {
    _highestAttID = val;
  }
  uint32		class_category() const; // Rare: otiClassFD, etc.
  virtual ~d_Class();
  static const d_Class  null;
  size_t offset_in_class(const char *name) const;
  size_t offset_in_class(const d_Attribute &mASAt) const;
  size_t offset_in_class(const Class_Position &mASPos) const;

protected:
  d_Class() : _classNumber(0) {;}
  d_Class(ooIsNull) : d_Type(oocIsNull), _classNumber(0) {;}
  d_Class(d_Module *modP)
    : d_Type(modP,
	     NULL,			// name
	     oocUninitializedSize_t,	// eltSize
	     true) {;}			// isShape

private:
  d_Attribute *		_attributeArray;
  d_Class *		_latestVersionCP;
  ooTVArray(listElementP<d_Attribute >)
			_attributes;
  ooTVArray(listElementP<d_Relationship >)
			_relationships;
  ooTVArray(listElementP<d_Inheritance >)
			_base_class_list;
  ooTVArray(listElementP<d_Inheritance >)
			_sub_class_list;
  OO_REF_TYPE		_staticRef;
  ooTypeNumber		_classNumber;
  int32			_version;
  uint32                _highestAttID;
  unsigned int		_currentlyAttachingMembers : 1;
  unsigned int		_isPersistent              : 1;
  unsigned int		_isInternal                : 1;
  unsigned int		_isRootObj                 : 1;
  unsigned int		_createdByActiveSchema     : 1;
  unsigned int          _isForward                 : 1;
  static bool		_rootDescent;
};

inline const d_Class &
d_Class::latest_version() const
{
  return *const_cast<const d_Class *>(
    _latestVersionCP ? _latestVersionCP : this);
}

inline
d_Class::operator size_t() const
{
  return (_isNull ? 0 : this->shape_number());
}

inline uint32
d_Class::id() const
{
  return (_isNull ? 0 : this->type_number());
}

inline ooTypeNumber
d_Class::type_number() const {
  return ((_classNumber > 0) ? _classNumber : this->shape_number());
}

// d_Module is part of the ODMG standard.  It describes a domain of class
// descriptors in the database schema.  A d_Module in Objectivity can be
// the "default schema" (named "*") or a user-created "named schema."
//
// The top level module--that is, the default schema for the federated
// database--serves also as the name scope of the other modules, or named
// schemas.
//
// The function resolve_type() can be used to look up either name strings
// or type numbers, matching only entries which are types, casting the
// result in all cases to (const d_Type &).  The function resolve_class()
// can be used to look up either name strings or type numbers, matching
// only entries which are classes, and casting the result in all cases to
// (const d_Class &).  It takes an optional second integer argument which
// can be used to specify a particular version if the class was created
// using the Objectivity versioning feature.
//
// Looking up a name or type number in the top level module scope causes
// all other modules to be searched as well.

class OO_STORAGE_SPECIFIER d_Module
    : public d_Meta_Object, public d_Scope
{
  friend class ::otmEntry;
  friend class ::otmFdSchema;
  friend class d_Meta_Object;
  friend class d_Meta_Object_Int;
  friend class d_Module_Int;
  friend class Proposed_Class;
  friend class Proposed_Class_Int;
  friend class otmSchemaAccessOverrides;
  friend class otmEvolveOverrides;

public:
  virtual meta_object_iterator	defines_begin() const;
  virtual meta_object_iterator	defines_end() const;

  // The method top_level() returns a representation of the default schema
  // (named "*").  It is defined by ODMG to return a const object; to
  // invoke non-const methods added in Active Schema, that result must be
  // cast to d_Module &.  The optional argument is a 64-bit key which
  // must be provided to access the schema if it has been locked.
  //
  static const d_Module & top_level(uint64 = 0);
  //
  // The method defines_types_begin() returns an iterator over the
  // type number hash table of this d_Module.
  //
  type_iterator		defines_types_begin() const;
  type_iterator		defines_types_end() const;

  // Virtual member function of d_Meta_Object
  //
  virtual uint32	id() const;

  // Virtual member function of d_Scope
  //
  const d_Meta_Object &	resolve(const char *,			// name
				int32 = oocLatestVersion,	// version
				const char * = NULL) const;	// namespace

  // The following methods are additions to the ODMG standard.
  //
  const d_Type &	resolve_type(const char *) const;
  const d_Type &	resolve_type(ooTypeNumber) const;
  const d_Class &	resolve_class(const char *,		// name
				      const char *) const;      // namespace
  const d_Class &	resolve_class(const char *,		// name
				      int32 = oocLatestVersion,	// version
				      const char *		// namespace
				          = NULL) const;
  const d_Class &	resolve_class(ooTypeNumber) const;
  //
  // The function resolve_module() can be used to look up named schemas
  // (modules) in the scope of the top level module.  Lookup of any module
  // in the scope of a module other than the top level module will return
  // the null result.
  //
  const d_Module &	resolve_module(const char *) const;
  const Namespace &	resolve_namespace(const char *) const;
  virtual module_iterator
			named_modules_begin() const;
  virtual module_iterator
			named_modules_end() const;
  namespace_iterator
			namespaces_begin() const;
  namespace_iterator
			namespaces_end() const;
  virtual bool		is_module() const { return true; }
  virtual bool		is_top_level() const { return false; }

  virtual const char *  module_name() const { return _name; }

  virtual ooAsType	descriptor_kind() const { return d_Module_t; }
  ooTypeNumber		module_number() const { return _schemaNumber; }
  ooTypeNumber		schema_number() const { return _schemaNumber; }
  ooTypeNumber		next_type_number() const;
  ooAssocNumber		next_assoc_number() const;
  static ooStatus	lock_schema(uint64);
  static ooStatus	lock_schema(uint64, uint64);
  static ooStatus	unlock_schema(uint64);
  static bool		schema_is_locked(ooStatus * = NULL);

  // The following methods are available only when the "evolve" library
  // is loaded.
  Proposed_Class &	resolve_proposed_class(const char *,       // name
					       const char * = NULL // namespace
					       ) const;
  proposed_class_iterator
			proposed_classes_begin() const;
  proposed_class_iterator
			proposed_classes_end() const;
  Proposed_Class &	propose_new_class(const char *,		// name
					  ooTypeNumber = 0,	// shape #
					  const char * = NULL);	// namespace
  Proposed_Class &	propose_new_class(Proposed_Class *);
  Proposed_Class &	propose_evolved_class(
			    const char *,		// name
			    ooTypeNumber = 0,
			    bool = false,		// internal
			    const char * = NULL);	// namespace
  Proposed_Class &      propose_evolved_class(const char *name,
					      ooTypeNumber tnum,
					      const char *); // namespace
  Proposed_Class &	propose_versioned_class(
			    const char *,
			    ooTypeNumber = 0,
			    bool = false,		// internal
			    const char * = NULL);	// namespace
  // Support schema history load scenarios--require that non-current
  // shapes be identical, current shapes be compatible
  Proposed_Class &	propose_history_shape(
			    const char *,
			    ooTypeNumber = 0,
			    const char * = NULL);	// namespace
  ooStatus		delete_proposal(const char *,
                                        const char * = NULL);  // namespace
  ooStatus		activate_proposals(ooTrans &,
					   OO_FD_HANDLE_TYPE &,
					   const ooMode =
						static_cast<ooMode>(
						 oocCurrentMrow),
					   const int32 = oocCurrentTransWait,
					   const ooIndexMode =
					   	static_cast<ooIndexMode>(
						 oocCurrentSensitivity),
					   bool = true	// Also activate
					   );		//   submodules
  ooStatus		activate_proposals(ooSession &,
					   const ooMode =
						static_cast<ooMode>(
						 oocCurrentMrow),
					   const int32 = oocCurrentTransWait,
					   const ooIndexMode =
					   	static_cast<ooIndexMode>(
						 oocCurrentSensitivity),
					   bool = true	// Also activate
					   );		//   submodules
  ooStatus		activate_proposals(OO_FD_HANDLE_TYPE &);
  ooStatus		activate_remote_schema_changes(
				ooTrans &,
				OO_FD_HANDLE_TYPE &,
				size_t * = NULL,
				bool = true, // Also activate submodules
				otmMutexBlock * = NULL); // alreadyMutexedP
  ooStatus		activate_remote_schema_changes(
				ooSession &,
				size_t * = NULL,
				bool = true); // Also activate submodules
  ooStatus		activate_remote_schema_changes(OO_FD_HANDLE_TYPE &);
  void		        clear_proposals();
  ooStatus		set_next_type_number(ooTypeNumber);
  ooStatus		set_next_assoc_number(ooAssocNumber);
  static d_Module &	add_module(const char *, uint32 = 0);
  static void		(*evolution_message_handler())(const char *);
  static void		set_evolution_message_handler(void (*)(const char *));
  static ooStatus       special_tool(const char *); // Internal use only
  static void           set_recreate_history(bool flag); // Internal use only SPR 20792
  static bool		relationship_integrity_checking();
  static bool		relationship_integrity_checking(bool);
  ooStatus		delete_namespace(const Namespace &, bool = true);

  // The following methods are intended for internal Objectivity use only
  //
  bool                  namesInitialized() const { return _namesInitialized; }
  virtual		~d_Module();
  ost_table *           defines() { return _defines; }
  ooTVArray(listElementP<d_Meta_Object >) &
                        definesList() { return _definesList._vector; }
  otmFdSchema *         fdSchemaP() { return _rootP; }
  uint32 *		protected_list();
  uint32 		protected_list_length();
  void set_namesInitialized(bool TorF) { _namesInitialized = TorF; }
  static d_Access_Kind  otiVisToODMGaccess(int);
  const Namespace &     add_namespace(const char *,
				      ooAsLanguages =
				      ooAsLanguageActiveSchema);
  static const d_Module null;

protected:
  d_Module(ooIsNull) : d_Meta_Object(oocIsNull) {;}
  d_Module(ooHandleBase *,
	   otmFdSchema *,
	   Top_Level_Module *,
	   const otmMutexBlock &);
  d_Module() {;}
  const d_Meta_Object &	resolvePossibleClass(const char *, // Method added
					     int32,        // for SPR 20600
					     const char *,
					     bool,
					     bool = false) const;

private:
  otmFdSchema *         _rootP;
  ooId                  _otiSchemaDesc;
  ost_table *           _defines;
  metaObjectVector      _definesList;
  ooTypeNumber		_schemaNumber;
  Top_Level_Module *	_toTopLevelModuleP;
  ooTVArray(listElementP<Proposed_Class >)
			_proposedClasses;
  ooTVArray(listElementP<Namespace >)
			_namespaceList;
  ooTVArray(listElementP<d_Class >)
			_newShapeList;
  ooTVArray(listElementP<d_Class >)
			_oldShapeList;
  ooTypeNumber          _highestProposedShapeNumber;
  ooTypeNumber          _highestProposedAssocNumber;
  bool                  _namesInitialized;
  static void		(*_evolutionMsgHandler)(const char *);
  static bool		_integrityChecking;
};

class OO_STORAGE_SPECIFIER Schema_Trans
{
  friend class otmEvolveOverrides;
public:
  ooStatus prepare();
  ooStatus commit();
  ooStatus abort();
  Schema_Trans() : _schemaTransP(NULL) {;}
  ~Schema_Trans();

private:
  ooTrans *_schemaTransP;
};

class OO_STORAGE_SPECIFIER Top_Level_Module : public d_Module
{
  friend class d_Module;
  friend class ::otmFdSchema;
public:
  virtual module_iterator	named_modules_begin() const;
  virtual module_iterator	named_modules_end() const;
  virtual bool			is_top_level() const { return true; }
  virtual			~Top_Level_Module() {;}
  Top_Level_Module(otmFdSchema *, const otmMutexBlock &);

protected:
  Top_Level_Module();
  ooTVArray(listElementP<d_Module >) &
				named_modules() { return _namedModules; }

private:
  ooTVArray(listElementP<d_Module >)
				_namedModules;
};

#endif // !OOTM_BOOTSTRAPPING

#ifndef OO_NO_NAMESPACE
} // namespace ooas
#endif // !OO_NO_NAMESPACE

#endif // !_OOSCHEMAODMG_H
