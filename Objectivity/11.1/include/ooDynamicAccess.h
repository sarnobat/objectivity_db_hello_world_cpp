#ifndef _OODYNAMICACCESS_H
#define _OODYNAMICACCESS_H

#include <ooSchemaODMG.h>
#include <ooSchemaNumeric.h>
#include <ooActiveSchemaException.h>

#define OO_NO_CXX_SMALLTALK

#ifndef OO_NO_NAMESPACE
namespace ooas {
#endif // !OO_NO_NAMESPACE

#ifdef OO_NT
#  pragma warning( disable : 4251 ) // Suppress warnings about dll-interface requirements on private STL data members
#  pragma warning( disable : 4786 ) // Suppress warnings about long AS template names
#endif // OO_NT

#if defined(_MSC_VER) && defined(_DLL) && \
 (!defined(AS_STORAGE_SPECIFIER) || defined(____AS_SP_defined_locally))
#  ifdef _DEBUG
     // Dynamic debug link
#    pragma comment(lib, "ooasd.lib")
#  else  // following is for: !_DEBUG
     // Dynamic non-debug link
#    pragma comment(lib, "ooas.lib")
#  endif // _DEBUG (else)
#endif   // _MSC_VER && _DLL

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

enum ooAsStringType {
    ooAsStringNONE,
    ooAsStringVSTRING,
    ooAsStringUTF8,
    ooAsStringOPTIMIZED,
    ooAsStringST,
    ooAsStringUTF16,
    ooAsStringUTF32
};

class AS_STORAGE_SPECIFIER Persistent_Data_Object;
class AS_STORAGE_SPECIFIER Optimized_String_Value;
class AS_STORAGE_SPECIFIER Class_Object;
class AS_STORAGE_SPECIFIER VArray_Object;
class AS_STORAGE_SPECIFIER Relationship_Object;
class AS_STORAGE_SPECIFIER linkedLong;
class AS_STORAGE_SPECIFIER embeddingData;

// Persistent_Data_Object is an abstract base class of Class_Object,
// VArray_Object, and Relationship_Object.  These classes are not part
// of the ODMG standard.

class AS_STORAGE_SPECIFIER Persistent_Data_Object
{
    friend class Class_Object;
    friend class Class_Object_Int;
    friend class VArray_Object;
    friend class Relationship_Object;
public:
    virtual bool	is_class_object() const { return false; }
    virtual bool	is_varray_object() const { return false; }
    virtual bool	is_relationship_object() const { return false; }
    static void		enable_auto_update();
    static void		disable_auto_update();
    static bool		auto_update_is_enabled();
    inline virtual	operator size_t() const;
    static const Persistent_Data_Object
			null;
    virtual		~Persistent_Data_Object() {;}

protected: // External calls prohibited
    virtual otmEntry *	reopen(ooMode,
			       otmMutexBlock * = NULL,
			       bool = false,
			       linkedLong * = NULL) { return NULL; }
    Persistent_Data_Object() : _nextDepP(NULL), _prevDepP(NULL) {;}
    Persistent_Data_Object *
			nextDependsP() const { return _nextDepP; }
    Persistent_Data_Object *
			prevDependsP() const { return _prevDepP; }
    void		set_nextDependsP(Persistent_Data_Object *dP) {
	_nextDepP = dP;
    }
    void		set_prevDependsP(Persistent_Data_Object *dP) {
	_prevDepP = dP;
    }
    inline void		insertDependency(Persistent_Data_Object *);
    inline void		removeFromDependencyList();
    ooStatus		lockingExceptionOrErrorStatus(Class_Object *,
						      ooMode);
#if (defined(OAS_DEBUG_CLASS_OBJ) || defined(OAS_DEBUG_HANDLE_STACK))
    virtual void	fprintf(FILE * = stdout, otmEntry * = NULL);
#endif

private:
    Persistent_Data_Object *
			_nextDepP;
    Persistent_Data_Object *
			_prevDepP;
    static bool		_autoUpdate;
};

inline
Persistent_Data_Object::operator size_t() const
{
    if (this == &(Persistent_Data_Object::null)) {
	return 0;
    } else {
	return ooReinterpretCast(size_t, this);
    }
}

// A Class_Object contains a pointer to an Objectivity handle and a
// d_Class object corresponding to the handle object's class, using the
// d_Class as a map for accessing the handle object's data.  It is
// never possible in Active Schema to obtain a pointer into persistent
// memory; any numerical value must be accessed by a get*() method or
// modified by a set*() method.  Special methods are provided for
// handling references, associations, and VArrays to closely emulate the
// C++ language interface to these attributes.

class AS_STORAGE_SPECIFIER Class_Object : public Persistent_Data_Object
{
    friend class VArray_Object;
    friend class Relationship_Object;
    friend class embeddingData;
    friend class asAutoCleanClassObject;
    friend class FailedToOpenObject;
    friend class AccessDeletedAttribute;
    friend class String_Value;
    friend class Optimized_String_Value;
    friend class Class_Object_Int;
    friend class VArray_Object_Int;
    friend class Relationship_Object_Int;
public:
    Numeric_Value	get(size_t) const;
    Class_Object	get_class_obj(size_t) const;
    VArray_Object	get_varray(size_t) const;
    Relationship_Object	get_relationship(size_t) const;
    ooRef(ooObj)	get_ooref(size_t) const;
    String_Value	get_string(size_t) const;

    ooStatus		set(size_t, const Numeric_Value);
    ooStatus		set_ooref(size_t, const ooRef(ooObj));
    ooStatus		set_string(size_t, const char *);

    // The same member functions, with an index argument for array members
    //
    Numeric_Value	get(size_t, size_t) const;
    Class_Object	get_class_obj(size_t, size_t) const;
    VArray_Object	get_varray(size_t, size_t) const;
    ooRef(ooObj)	get_ooref(size_t, size_t) const;
    String_Value	get_string(size_t, size_t) const;

    ooStatus		set(size_t, size_t, const Numeric_Value);
    ooStatus		set_ooref(size_t, size_t, const ooRef(ooObj));
    ooStatus		set_string(size_t, size_t, const char *);

    // The same member functions, with an index argument for array members,
    // and which accept a Class_Position
    //
    Numeric_Value	get(const Class_Position &, size_t = 0) const;
    Class_Object	get_class_obj(const Class_Position &,
				      size_t = 0) const;
    VArray_Object	get_varray(const Class_Position &,
				   size_t = 0) const;
    Relationship_Object	get_relationship(const Class_Position &) const;
    ooRef(ooObj)	get_ooref(const Class_Position &, size_t = 0) const;
    String_Value	get_string(const Class_Position &, size_t = 0) const;

    ooStatus		set(const Class_Position &, const Numeric_Value);
    ooStatus		set(const Class_Position &,	// attrPosR
			    size_t,			// arrayIndex
			    const Numeric_Value);
    ooStatus		set_ooref(const Class_Position &, const ooRef(ooObj));
    ooStatus		set_ooref(const Class_Position &,	// attrPosR
				  size_t,			// arrayIndex
				  const ooRef(ooObj));
    ooStatus		set_string(const Class_Position &, const char *);
    ooStatus		set_string(const Class_Position &,	// attrPosR
				   size_t,			// arrayIndex
				   const char *);

    // A parallel set of accessor/modifier methods prefixed with "n" (for
    // "name") which take an attribute name and always refetch the position.
    // This is less efficient, but more convenient and safer in multithreaded
    // contexts--the position is guaranteed not to evolve between the
    // computation of the position and the data access.
    //
    Numeric_Value	nget(const char *, size_t = 0) const;
    Class_Object	nget_class_obj(const char *, size_t = 0) const;
    VArray_Object	nget_varray(const char *, size_t = 0) const;
    Relationship_Object	nget_relationship(const char *) const;
    ooRef(ooObj)	nget_ooref(const char *, size_t = 0) const;
    String_Value	nget_string(const char *, size_t = 0) const;

    ooStatus		nset(const char *, const Numeric_Value);
    ooStatus		nset(const char *,		// attrName
			     size_t,			// arrayIndex
			     const Numeric_Value);
    ooStatus		nset_ooref(const char *, const ooRef(ooObj));
    ooStatus		nset_ooref(const char *,	// attrName
				   size_t,		// arrayIndex
				   const ooRef(ooObj));
    ooStatus		nset_string(const char *,	// attrName
				    const char *);      // value
    ooStatus		nset_string(const char *,	// attrName
				    size_t,		// arrayIndex
				    const char *);      // value

    int			default_association_varray_size() const;
    int			default_association_varray_capacity() const;
    ooStatus		set_default_association_varray_capacity(int);

    // Conversion to ooRef
    //
    operator		ooRef(ooObj)();
    operator		const ooRef(ooObj)() const;

    // Conversion to ooHandle
    //
    operator		ooHandle(ooObj)();
    operator		const ooHandle(ooObj)() const;

    // Conversion to void* for casting to an appropriate type supported in
    // the native binding, to use its accessors
    //
    operator            void *();

    // Assignment operator
    //
    Class_Object &	operator=(const Class_Object &);
    Class_Object &	operator=(const ooRef(ooObj) &);
    Class_Object &	operator=(const ooHandle(ooObj) &);

    // Emulate ULB language binding assignment operator (~ oocCopyCopy)
    Class_Object &	assign(const Class_Object &);
    // Emulate newH = oldH.copy();
    Class_Object &	copy(const Class_Object &);

    Class_Object &	contained_in() const;
    ooHandle(ooObj) &	object_handle() const { return *_objHanP; }
    const d_Class &	type_of() const;
    const Class_Position
			position_in_class(const char *) const;
    const d_Attribute &	resolve_attribute(const char *) const;

    static Class_Object	new_persistent_object(
	const d_Class &,
	const ooHandle(ooObj) &,	// near object for clustering
	ooClusterStrategy * = NULL,	// clustering strategy (optional)
	bool = false);			// set basic field values to zero

    // For compatibility with pre-9.0 releases
    static Class_Object	new_persistent_container_object(
	const d_Class &,
	const char *,			// system name
	const ooHandle(ooObj) &,	// near object for clustering
	uint32,				// hash
	uint32,				// initPages
	uint32,				// percentGrow
	bool = false);			// set basic field values to zero

    // This signature is preferred starting with Release 9.0
    static Class_Object	new_persistent_container_object(
	const d_Class &,
	const ooHandle(ooObj) &,	// near object for clustering
	uint32,				// initPages
	uint32,				// percentGrow
	const char *,			// system name
	uint16 = 0,                     // userContID
	ooBoolean = oocFalse,           // externalContainer
	const char * = 0,               // hostName
	const char * = 0,               // pathName
	const unsigned = 0,             // pageSize
	bool = false);                  // set basic field values to zero

    virtual bool	is_class_object() const { return true; }

    Class_Object();		// Default constructor

    // Copy constructor
    //
    Class_Object(const Class_Object &);

    // Ctor given handle/ref and d_Class object
    //
    Class_Object(ooHandle(ooObj) &, const d_Class &);
    Class_Object(ooRef(ooObj) &, const d_Class &);

    // Ctor given handle/ref, type number and schema
    //
    Class_Object(ooHandle(ooObj) &, ooTypeNumber, const d_Module &);
    Class_Object(ooRef(ooObj) &, ooTypeNumber, const d_Module &);

    // Ctor given only a handle/ref (uses the default schema module)
    //
    Class_Object(ooHandle(ooObj) &);
    Class_Object(const ooRef(ooObj) &);

    inline virtual	operator size_t() const;
    virtual		~Class_Object();

protected: // External calls prohibited
    virtual otmEntry *	reopen(ooMode,
			       otmMutexBlock * = NULL,
			       bool = false,
			       linkedLong * = NULL);
    Class_Object(void *,		// address of embedded member
		 Class_Object *,	// containing class object
		 const d_Attribute &,	// embedded attribute
		 const d_Class &,	// object class
		 size_t,		// embedded member position
		 Class_Position *,	// embedded member position nextP
		 size_t,		// array index
		 VArray_Object *,	// containing VArray
		 size_t);		// VArray index

  void *		dataP() const { return _dataP; }
  Class_Object *	origCOP() const {
    return ((_origCOP != NULL) ? _origCOP : this->initOrigCOP());
  }
  Class_Object *	initOrigCOP() const;
#if (defined(OAS_DEBUG_CLASS_OBJ) || defined(OAS_DEBUG_HANDLE_STACK))
  virtual void	fprintf(FILE * = stdout, otmEntry * = NULL);
#endif

private:
  ooTypeNumber		_objTypeN;
  d_Attribute *         _embeddingAttrP;
  void *		_dataP;
  ooHandle(ooObj) *	_objHanP;
  embeddingData *	_embeddingDataP;
  ooHandle(ooObj)	_handleData;
  Class_Object *	_origCOP;
};

inline
Class_Object::operator size_t() const
{
    if ((this == &(Persistent_Data_Object::null)) ||
	(_objHanP == NULL)) {
	return 0;
    } else {
	return ooReinterpretCast(size_t, this);
    }
}

class AS_STORAGE_SPECIFIER Collection_Object
    : public Persistent_Data_Object
{
public:
    Collection_Object() {;}
};

class AS_STORAGE_SPECIFIER VArray_Object : public Collection_Object
{
    friend class Class_Object;
    friend class Class_Object_Int;
    friend class VArray_Object_Int;
public:
    Numeric_Value	get(size_t) const;
    Class_Object	get_class_obj(size_t) const;
    ooRef(ooObj)	get_ooref(size_t) const;
    String_Value	get_string(size_t) const;

    ooStatus		set(size_t, Numeric_Value);
    ooStatus		set_ooref(size_t, const ooRef(ooObj));

    uint32		cardinality() const;
    uint32		size() const { return this->cardinality(); }
    d_Iterator<ooObj>	create_iterator() const;
    ooStatus		extend(const Numeric_Value);
    ooStatus		extend(const ooRef(ooObj));
    inline void		insert_element(const Numeric_Value);
    inline void		insert_element(const ooRef(ooObj));
    int			is_empty() const { return this->size() == 0; }
    void		remove_all() { this->resize(0); }
    inline void		replace_element_at(const Numeric_Value, uint32);
    inline void		replace_element_at(const ooRef(ooObj), uint32);
    void		replace_element_at(const Numeric_Value,
					   const d_Iterator<ooObj> &);
    void		replace_element_at(const ooRef(ooObj),
					   const d_Iterator<ooObj> &);
    ooStatus		resize(uint32);
    ooStatus		update();
    uint32		upper_bound() const { return this->size(); }

    const d_Type &	type_of() const { return _dattrP->type_of(); }
    inline Class_Object &
			contained_in() const;

    // Conversion to ooId
    //
    operator		ooId();
    operator		const ooId() const;

    // Assignment operator
    //
    VArray_Object &	operator=(const VArray_Object &);

    virtual bool	is_varray_object() const { return true; }
    // Copy all array elements; here, copy() and assign() do the same thing
    VArray_Object &     copy(const VArray_Object &);
    VArray_Object &     assign(const VArray_Object &);
    inline virtual	operator size_t() const;
    VArray_Object(const VArray_Object &);
    VArray_Object();
    virtual		~VArray_Object();

protected: // External calls prohibited
    virtual otmEntry *	reopen(ooMode,
			       otmMutexBlock * = NULL,
			       bool = false,
			       linkedLong * = NULL);
    VArray_Object(oomVCB *,
		  const d_Attribute &,
		  Class_Object *,	// containing class object
		  size_t,		// position in containing class
		  size_t);		// index if from array of VArrays
    VArray_Object(oomVCB *,
		  const d_Attribute &,
		  Class_Object *,	// containing class object
		  const Class_Position &, // position in containing class
		  size_t);		// index if from array of VArrays
#if (defined(OAS_DEBUG_CLASS_OBJ) || defined(OAS_DEBUG_HANDLE_STACK))
    virtual void	fprintf(FILE * = stdout, otmEntry * = NULL);
#endif

private:
    d_Attribute *	_dattrP;
    oomVCB *		_vcbP;
    Class_Object *	_classObjP;
    Class_Position	_positionWithinClassObj;
    size_t		_index;	// account for arrays of ooVArrays
};

inline Class_Object &
VArray_Object::contained_in() const
{
    Class_Object &containingCO = _classObjP->contained_in();
    if (!containingCO) {
	return *_classObjP;
    } else {
	return containingCO;
    }
}

inline void
VArray_Object::insert_element(const Numeric_Value val)
{
    this->extend(val);
}

inline void
VArray_Object::insert_element(const ooRef(ooObj) oid)
{
    this->extend(oid);
}

inline void
VArray_Object::replace_element_at(const Numeric_Value val, uint32 index)
{
    this->set(index, val);
}

inline void
VArray_Object::replace_element_at(const ooRef(ooObj) oid, uint32 index)
{
    this->set_ooref(index, oid);
}

inline
VArray_Object::operator size_t() const
{
    if ((this == &(Persistent_Data_Object::null)) ||
	(_classObjP == NULL)) {
	return 0;
    } else {
	return ooReinterpretCast(size_t, this);
    }
}

class AS_STORAGE_SPECIFIER Relationship_Object
    : public Persistent_Data_Object
{
    friend class Class_Object;
    friend class Relationship_Object_Int;
public:
    Class_Object	get_class_obj() const;
    ooRef(ooObj)	get_ooref() const;
    ooStatus		get_iterator(ooItr(ooObj) &, ooMode = oocNoOpen);

    bool		exist(const ooHandle(ooObj) &) const;
    inline bool		exist() const;
    ooStatus		set(const ooHandle(ooObj) &);
    ooStatus		del();
    ooStatus		add(const ooHandle(ooObj) &);
    ooStatus		sub(const ooHandle(ooObj) &, const uint32 = 1);
    d_Relationship &	relationship() const { return *_relP; }
    inline const d_Class &
			other_class() const;
    inline Class_Object &
			contained_in() const;
    int                 capacity() const; // allocated size of array
    int                 size() const;     // number of occupied elements
    ooStatus            setCapacity(int new_capacity); // resize the array
    virtual bool	is_relationship_object() const { return true; }
    Relationship_Object & // Emulate ULB assignment operator (~ oocCopyCopy)
                        assign(const Relationship_Object &);
    Relationship_Object & // Obey what the "copy" policy bits direct
                        copy(const Relationship_Object &);
    Relationship_Object(void *,				// assocDataP
			oomVCB *,			// dynVarrP
			const d_Relationship &,		// relR
			Class_Object *,			// classObjP
			size_t);	// position in containing class
    Relationship_Object(void *,				// assocDataP
			oomVCB *,			// dynVarrP
			const d_Relationship &,		// relR
			Class_Object *,			// classObjP
			const Class_Position &); // pos. in containing class
    Relationship_Object(const Relationship_Object &);
    Relationship_Object();
    Relationship_Object &
			operator=(const Relationship_Object &);
    inline virtual	operator size_t() const;
    virtual		~Relationship_Object();

protected: // External calls prohibited
    virtual otmEntry *	reopen(ooMode,
			       otmMutexBlock * = NULL,
			       bool = false,
			       linkedLong * = NULL);
#if (defined(OAS_DEBUG_CLASS_OBJ) || defined(OAS_DEBUG_HANDLE_STACK))
    virtual void	fprintf(FILE * = stdout, otmEntry * = NULL);
#endif

private:
    d_Relationship *	_relP;
    oomVCB *		_dynVarrP;
    void *		_dataP;
    Class_Object *	_classObjP;
    Class_Position	_positionWithinClassObj;
};

inline bool
Relationship_Object::exist() const
{
    return this->exist(*ooReinterpretCast(ooHandle(ooObj) *,
					  &oocNullHandle));
}

inline const d_Class &
Relationship_Object::other_class() const
{
    return this->relationship().other_class();
}

inline Class_Object &
Relationship_Object::contained_in() const
{
    return *_classObjP;
}

inline
Relationship_Object::operator size_t() const
{
    if ((this == &(Persistent_Data_Object::null)) ||
	(_classObjP == NULL)) {
	return 0;
    } else {
	return ooReinterpretCast(size_t, this);
    }
}

class AS_STORAGE_SPECIFIER String_Value
{
  friend class Optimized_String_Value;
  friend class Class_Object;
  friend class VArray_Object;
public:
  ooAsStringType	type() const { return _strType; }
  bool			is_vstring() const;
  bool			is_utf8string() const;
  bool			is_utf16string() const;
  bool			is_utf32string() const;
  bool			is_ststring() const;
  bool			is_optimized_string() const;
			operator ooVString *();
			operator ooUtf8String *();
			operator ooUtf16String *();
			operator ooUtf32String *();
#ifndef OO_NO_CXX_SMALLTALK
			operator ooSTString *();
#endif
  String_Value &	operator=(const String_Value &);	// Assignment
  ooStatus		update();
  // Copy a string attribute; here, copy() and assign() do the same thing
  String_Value &	copy(const String_Value &);
  String_Value &	assign(const String_Value &);
  String_Value(const String_Value &);		// Copy constructor
  String_Value();

protected:
  void *		stringP() const {
    return (void *)_stringP;
  }
  size_t		fixedLength() const { return _fixedLen; }

  String_Value(void *,
	       ooAsStringType,
	       Class_Object *,
	       size_t = 0);

private:
  void *		_stringP;
  ooAsStringType	_strType;
  size_t		_fixedLen;
  Class_Object *	_classObjP;
};

// Objectivity optimized strings are ordinarily created as non-persistent
// user classes which contain an ooVArray(int8) attribute followed by
// a fixed-length array of int8.  Optimized_String_Value emulates
// Objectivity's management of such structures according to the actual
// string value.  Optimized_String_Value is not part of the ODMG standard.

class AS_STORAGE_SPECIFIER Optimized_String_Value
{
    friend class String_Value;
public:
    const char &	operator[](uint32) const;
    char &		operator[](uint32);
    Optimized_String_Value &			// Assignment
			operator=(const Optimized_String_Value &);

    // length() returns the actual string length.
    //
    uint32		length() const;
    //
    // fixed_length() returns the length of the static character array in
    // the class layout.
    //
    inline uint32	fixed_length() const;
    ooStatus		resize(uint32);
    //
    // get_copy returns a copy of the string in the storage provided as
    // the first argument, or a heap-allocated character string.
    //
    char *		get_copy(char * = NULL) const;
    ooStatus		set(const char *);
    ooStatus		update();
    ooStatus		init();
    Optimized_String_Value(const String_Value &);
    Optimized_String_Value(const Optimized_String_Value &); // Copy constr.
protected:
    void *		stringP() const { return _stringP; }
    bool		isVArray() const;
    ooStatus		markFix();
    ooStatus		markVArray();
    ooStatus		clear();
private:
    void *		_stringP;
    size_t		_n;
    Class_Object *	_classObjP;
};

inline uint32
Optimized_String_Value::fixed_length() const
{
  return ooStaticCast(uint32, _n);
}

class AS_STORAGE_SPECIFIER ArrayBoundsError : public asException
{
public:
    Class_Object &	class_object();
    const d_Attribute &	attribute_of() const { return _attR; }
    size_t		actual_index() const { return _actualIndex; }

    ArrayBoundsError(size_t,			// actualIndex
		     const d_Attribute &,
		     Class_Object &);

    virtual void	throw_this() { throw *this; }
    static void		disable() { _thisExcEnabled = false; }
    static void		enable() { _thisExcEnabled = true; }
    static bool		enabled() { return _thisExcEnabled; }
protected: // External calls prohibited
    bool		thisExceptionEnabled() const { return _thisExcEnabled; }
private:
    size_t		_actualIndex;
    Class_Object *	_classObjP;
    const d_Attribute &	_attR;
    static bool		_thisExcEnabled;
};

class AS_STORAGE_SPECIFIER VArrayBoundsError : public asException
{
public:
    VArray_Object &	varray_object();
    const d_Attribute &	attribute_of() const { return _attR; }
    size_t		actual_index() const { return _actualIndex; }
    size_t		varray_size() const { return _varSize; }

    VArrayBoundsError(size_t,			// actualIndex
		      size_t,			// VArSize
		      const d_Attribute &,
		      VArray_Object &);
    virtual void	throw_this() { throw *this; }
    static void		disable() { _thisExcEnabled = false; }
    static void		enable() { _thisExcEnabled = true; }
    static bool		enabled() { return _thisExcEnabled; }
protected: // External calls prohibited
    bool		thisExceptionEnabled() const { return _thisExcEnabled; }
private:
    size_t		_actualIndex;
    size_t		_varSize;
    VArray_Object *	_varrayObjP;
    const d_Attribute &	_attR;
    static bool		_thisExcEnabled;
};

class AS_STORAGE_SPECIFIER BasicModifyError : public asException
{
public:
    Class_Object &	class_object();
    const d_Attribute &	attribute_of() const { return _attR; }

    BasicModifyError(const d_Attribute &, Class_Object &);
    virtual void	throw_this() { throw *this; }
    static void		disable() { _thisExcEnabled = false; }
    static void		enable() { _thisExcEnabled = true; }
    static bool		enabled() { return _thisExcEnabled; }
protected: // External calls prohibited
    bool		thisExceptionEnabled() const { return _thisExcEnabled; }
private:
    Class_Object *	_classObjP;
    const d_Attribute &	_attR;
    static bool		_thisExcEnabled;
};

class AS_STORAGE_SPECIFIER DynRelAccessError : public asException
{
public:
    DynRelAccessError(ooAsDynRelAccessErrorCode, Relationship_Object &);
    const Relationship_Object &
			relationship_object() { return *_relObjP; }
    virtual void	throw_this() { throw *this; }
    static void		disable() { _thisExcEnabled = false; }
    static void		enable() { _thisExcEnabled = true; }
    static bool		enabled() { return _thisExcEnabled; }
protected: // External calls prohibited
    bool		thisExceptionEnabled() const { return _thisExcEnabled; }
private:
    const Relationship_Object *
			_relObjP;
    static bool		_thisExcEnabled;
};

class AS_STORAGE_SPECIFIER GetAssocError : public asException
{
public:
    GetAssocError(ooAsGetAssocErrorCode,
		  Relationship_Object &);
    const Relationship_Object &
			relationship_object() { return *_relObjP; }
    virtual void	throw_this() { throw *this; }
    static void		disable() { _thisExcEnabled = false; }
    static void		enable() { _thisExcEnabled = true; }
    static bool		enabled() { return _thisExcEnabled; }
protected: // External calls prohibited
    bool		thisExceptionEnabled() const { return _thisExcEnabled; }
private:
    const Relationship_Object *
			_relObjP;
    static bool		_thisExcEnabled;
};

class AS_STORAGE_SPECIFIER SetAssocError : public asException
{
public:
    SetAssocError(ooAsSetAssocErrorCode,
		  Relationship_Object &);
    const Relationship_Object &
			relationship_object() { return *_relObjP; }
    virtual void	throw_this() { throw *this; }
    static void		disable() { _thisExcEnabled = false; }
    static void		enable() { _thisExcEnabled = true; }
    static bool		enabled() { return _thisExcEnabled; }
protected: // External calls prohibited
    bool		thisExceptionEnabled() const { return _thisExcEnabled; }
private:
    const Relationship_Object *
			_relObjP;
    static bool		_thisExcEnabled;
};

class AS_STORAGE_SPECIFIER DelAssocError : public asException
{
public:
    DelAssocError(ooAsDelAssocErrorCode,
		  Relationship_Object &);
    const Relationship_Object &
			relationship_object() { return *_relObjP; }
    virtual void	throw_this() { throw *this; }
    static void		disable() { _thisExcEnabled = false; }
    static void		enable() { _thisExcEnabled = true; }
    static bool		enabled() { return _thisExcEnabled; }
protected: // External calls prohibited
    bool		thisExceptionEnabled() const { return _thisExcEnabled; }
private:
    const Relationship_Object *
			_relObjP;
    static bool		_thisExcEnabled;
};

class AS_STORAGE_SPECIFIER AddAssocError : public asException
{
public:
    AddAssocError(ooAsAddAssocErrorCode,
		  Relationship_Object &);
    const Relationship_Object &
			relationship_object() { return *_relObjP; }
    virtual void	throw_this() { throw *this; }
    static void		disable() { _thisExcEnabled = false; }
    static void		enable() { _thisExcEnabled = true; }
    static bool		enabled() { return _thisExcEnabled; }
protected: // External calls prohibited
    bool		thisExceptionEnabled() const { return _thisExcEnabled; }
private:
    const Relationship_Object *
			_relObjP;
    static bool		_thisExcEnabled;
};

class AS_STORAGE_SPECIFIER SubAssocError : public asException
{
public:
    SubAssocError(ooAsSubAssocErrorCode,
		  Relationship_Object &);
    const Relationship_Object &
			relationship_object() { return *_relObjP; }
    virtual void	throw_this() { throw *this; }
    static void		disable() { _thisExcEnabled = false; }
    static void		enable() { _thisExcEnabled = true; }
    static bool		enabled() { return _thisExcEnabled; }
protected: // External calls prohibited
    bool		thisExceptionEnabled() const { return _thisExcEnabled; }
private:
    const Relationship_Object *
			_relObjP;
    static bool		_thisExcEnabled;
};

class AS_STORAGE_SPECIFIER InitItrError : public asException
{
public:
    InitItrError(d_Relationship &);
    const d_Relationship &
			relationship() { return *_relP; }
    virtual void	throw_this() { throw *this; }
    static void		disable() { _thisExcEnabled = false; }
    static void		enable() { _thisExcEnabled = true; }
    static bool		enabled() { return _thisExcEnabled; }
protected: // External calls prohibited
    bool		thisExceptionEnabled() const { return _thisExcEnabled; }
private:
    const d_Relationship *
			_relP;
    static bool		_thisExcEnabled;
};

class AS_STORAGE_SPECIFIER BadVArrayType : public asException
{
public:
    BadVArrayType(VArray_Object *, ooAsType);
    VArray_Object &	varray_object() const { return *_varObj; }
    ooAsType		formal_type() const { return _formalType; }
    virtual void	throw_this() { throw *this; }
    static void		disable() { _thisExcEnabled = false; }
    static void		enable() { _thisExcEnabled = true; }
    static bool		enabled() { return _thisExcEnabled; }
protected: // External calls prohibited
    bool		thisExceptionEnabled() const { return _thisExcEnabled; }
private:
    VArray_Object *	_varObj;
    ooAsType		_formalType;
    static bool		_thisExcEnabled;
};

class AS_STORAGE_SPECIFIER BadVArrayIterator : public asException
{
public:
    BadVArrayIterator(VArray_Object &, d_Iterator<ooObj> &);
    d_Iterator<ooObj> &	iterator_of() { return *_iter; }
    VArray_Object &	varray_object() { return *_varObj; }
    virtual void	throw_this() { throw *this; }
    static void		disable() { _thisExcEnabled = false; }
    static void		enable() { _thisExcEnabled = true; }
    static bool		enabled() { return _thisExcEnabled; }
protected: // External calls prohibited
    bool		thisExceptionEnabled() const { return _thisExcEnabled; }
private:
    d_Iterator<ooObj> *	_iter;
    VArray_Object *	_varObj;
    static bool		_thisExcEnabled;
};

class AS_STORAGE_SPECIFIER NonPersistentClassObject : public asException
{
public:
    NonPersistentClassObject(const d_Class &);
    const d_Class &	class_of() const { return *_classP; }
    virtual void	throw_this() { throw *this; }
    static void		disable() { _thisExcEnabled = false; }
    static void		enable() { _thisExcEnabled = true; }
    static bool		enabled() { return _thisExcEnabled; }
protected: // External calls prohibited
    bool		thisExceptionEnabled() const { return _thisExcEnabled; }
private:
    const d_Class *	_classP;
    static bool		_thisExcEnabled;
};

class AS_STORAGE_SPECIFIER FailedToOpenObject : public asException
{
public:
    FailedToOpenObject(Class_Object *,
		       ooRef(ooObj) &,
		       ooMode);
    Class_Object &	class_object() const { return *_classObjP; }
    ooMode		mode() const { return _mode; }
    virtual void	throw_this() { throw *this; }
    static void		disable() { _thisExcEnabled = false; }
    static void		enable() { _thisExcEnabled = true; }
    static bool		enabled() { return _thisExcEnabled; }
protected: // External calls prohibited
    bool		thisExceptionEnabled() const { return _thisExcEnabled; }
private:
    Class_Object *	_classObjP;
    ooMode		_mode;
    static bool		_thisExcEnabled;
};

class AS_STORAGE_SPECIFIER WrongStringType : public asException
{
public:
    WrongStringType(String_Value *, ooAsStringType);
    String_Value &	string_value() const { return *_stringValP; }
    ooAsStringType	formal_type() const { return _formalType; }
    virtual void	throw_this() { throw *this; }
    static void		disable() { _thisExcEnabled = false; }
    static void		enable() { _thisExcEnabled = true; }
    static bool		enabled() { return _thisExcEnabled; }
    String_Value &      assign(const String_Value &);
    String_Value &      copy(const String_Value &);
protected: // External calls prohibited
    bool		thisExceptionEnabled() const { return _thisExcEnabled; }
private:
    String_Value *	_stringValP;
    ooAsStringType	_formalType;
    static bool		_thisExcEnabled;
};

class AS_STORAGE_SPECIFIER AccessDeletedAttribute : public asException
{
public:
    AccessDeletedAttribute(Class_Object &,
			   const d_Attribute *,
			   ooRef(ooObj) &oid);
    Class_Object &	class_object() const { return *_classObjP; }
    const d_Attribute &	attribute_of() const { return *_attrP; }
    virtual void	throw_this() { throw *this; }
    static void		disable() { _thisExcEnabled = false; }
    static void		enable() { _thisExcEnabled = true; }
    static bool		enabled() { return _thisExcEnabled; }
protected: // External calls prohibited
    bool		thisExceptionEnabled() const { return _thisExcEnabled; }
private:
    Class_Object *	_classObjP;
    const d_Attribute * _attrP;
    static bool		_thisExcEnabled;
};

class AS_STORAGE_SPECIFIER DeletedClassObjectDependency : public asException
{
public:
    Persistent_Data_Object &
			persistent_data_object_of() const;
    DeletedClassObjectDependency(Persistent_Data_Object &);
    virtual void	throw_this() { throw *this; }
    static void		disable() { _thisExcEnabled = false; }
    static void		enable() { _thisExcEnabled = true; }
    static bool		enabled() { return _thisExcEnabled; }
protected: // External calls prohibited
    bool		thisExceptionEnabled() const { return _thisExcEnabled; }
private:
    Persistent_Data_Object *
			_persDataObjP;
    static bool		_thisExcEnabled;
};

class AS_STORAGE_SPECIFIER NonHandleClassObject : public asException
{
public:
    Class_Object &	class_object_of() const;
    NonHandleClassObject(Class_Object &, ooRef(ooObj) &);
    virtual void	throw_this() { throw *this; }
    static void		disable() { _thisExcEnabled = false; }
    static void		enable() { _thisExcEnabled = true; }
    static bool		enabled() { return _thisExcEnabled; }
protected: // External calls prohibited
    bool		thisExceptionEnabled() const { return _thisExcEnabled; }
private:
    Class_Object *	_classObjP;
    static bool		_thisExcEnabled;
};

class AS_STORAGE_SPECIFIER WrongCategoryOfNewObject : public asException
{
public:
    const char *	actual_category() const { return _actual; }
    const char *	formal_category() const { return _formal; }
    WrongCategoryOfNewObject(const char *, const char *);
    virtual void	throw_this() { throw *this; }
    static void		disable() { _thisExcEnabled = false; }
    static void		enable() { _thisExcEnabled = true; }
    static bool		enabled() { return _thisExcEnabled; }
protected: // External calls prohibited
    bool		thisExceptionEnabled() const { return _thisExcEnabled; }
private:
    const char *	_actual;
    const char *	_formal;
    static bool		_thisExcEnabled;
};

class AS_STORAGE_SPECIFIER StringBoundsError : public asException
{
public:
    Optimized_String_Value &
			optimized_string_of();
    size_t		actual_index() const { return _actualIndex; }
    size_t		string_length() const { return _strSize; }

    StringBoundsError(size_t,			// actualIndex
		      size_t,			// strSize
		      Optimized_String_Value &);
    virtual void	throw_this() { throw *this; }
    static void		disable() { _thisExcEnabled = false; }
    static void		enable() { _thisExcEnabled = true; }
    static bool		enabled() { return _thisExcEnabled; }
protected: // External calls prohibited
    bool		thisExceptionEnabled() const { return _thisExcEnabled; }
private:
    size_t		_actualIndex;
    size_t		_strSize;
    Optimized_String_Value *
			_strObjP;
    static bool		_thisExcEnabled;
};

class AS_STORAGE_SPECIFIER ooDynamicObjectAccessInitializer {
public:
  ooDynamicObjectAccessInitializer();
};
static ooDynamicObjectAccessInitializer __dynamicObjectAccessInitializer;

#ifndef OO_NO_NAMESPACE
} // namespace ooas
#endif // !OO_NO_NAMESPACE

#endif // !_OODYNAMICACCESS_H
