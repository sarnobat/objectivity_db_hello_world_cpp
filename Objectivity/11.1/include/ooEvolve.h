/**************************************************************************
		    Copyright (c) 1989-2009 Objectivity, Inc.
			  All Rights Reserved	

	THIS IS UNPUBLISHED PROPRIETARY SOURCE CODE OF OBJECTIVITY, INC.
	
	The copyright notice above does not evidence any	
	actual or intended publication of such source code.

*****************************************************************************/

#ifndef _OOEVOLVE_H
#define _OOEVOLVE_H

#include <ooSchemaODMG.h>	      // For d_Meta_Object, etc.
#include <ooSchemaNumeric.h>	      // For Numeric_Value
#include <ooActiveSchemaException.h>  // For asException, etc.

#if defined(OO_NT)
#  if !defined(EV_STORAGE_SPECIFIER) && !defined(AS_STORAGE_SPECIFIER)
#    if defined(_MSC_VER) && defined(_DLL)
#      define EV_STORAGE_SPECIFIER    __declspec(dllimport)
#      ifdef _DEBUG
         // Dynamic debug link
#        pragma comment(lib, "ooEvolveid.lib")
#      else  // following is for: !_DEBUG
         // Dynamic non-debug link
#        pragma comment(lib, "ooEvolvei.lib")
#      endif // _DEBUG (else)
#    else  // following is for: !_MSC_VER || !_DLL
#      define EV_STORAGE_SPECIFIER
#    endif // _MSC_VER && _DLL (else)
#  elif !defined(EV_STORAGE_SPECIFIER)
#      define EV_STORAGE_SPECIFIER
#  endif // EV_STORAGE_SPECIFIER
#else // following is for: !OO_NT
#  define EV_STORAGE_SPECIFIER
#endif // OO_NT

class OO_STORAGE_SPECIFIER ooSession;
class OO_STORAGE_SPECIFIER otiClassRef;

#ifndef OO_NO_NAMESPACE
namespace ooas {
#endif // !OO_NO_NAMESPACE

enum ooEvolOrVersState {
  oocNoProposedEvolOrVers,
  oocProposedEvol,
  oocProposedVers
};

enum ooChangeKind {
  oocNoChange = 0,
  oocAdd = 1,
  oocReplace = 2,
  oocVersion = 3,
  oocImport = 4,
  oocEvolve = 5,
  oocUpgrade = 6
};

enum ooDescriptionLevel {
  oocNotInCompilationUnit = 2,
  oocCompilationUnitDependency = 4,
  oocInCompilationUnit = 6
};

class EV_STORAGE_SPECIFIER Proposed_Property
: public Property_Descriptor
{
  friend class ooEvolveSession;
  friend class d_Module;
  friend class d_Module_Int;
  friend class d_Class;
  friend class Class_Object;
  friend class Proposed_Class;
  friend class Proposed_Class_Int;
  friend class Proposed_Attribute;
  friend class Proposed_Property_Int;
  friend class Proposed_Embedded_Class_Attribute;
  friend class Proposed_Ref_Attribute;
  friend class Proposed_Base_Class;
  friend class Proposed_Base_Class_Int;
  friend class Proposed_Relationship;
  friend class Proposed_Relationship_Int;
  friend class Proposed_VArray_Attribute;
  friend class otmEvolveOverrides;
public:
  d_Access_Kind		access_kind() const { return _visibility; }

  virtual bool		is_basic_type() const { return false; }
  virtual bool		is_relationship_type() const {
    return false;
  }
  virtual bool		is_ref_type() const { return false; }
  virtual bool		is_embedded_class_type() const {
    return false;
  }
  virtual bool		is_varray_type() const { return false; }
  virtual bool		is_varray_basic_type() const {
    return false;
  }
  inline virtual bool	is_varray_embedded_class_type() const;
  virtual bool		is_varray_ref_type() const { return false; }
  virtual bool		is_class_descriptor() const { return true; }
  size_t		array_size() const { return _arraySize; }
  const char *		previous_name() const { return _previousName; }
  ooStatus		rename(const char *);
  ooStatus		change_access(d_Access_Kind);
  Proposed_Class &	defined_in_class() const;
  size_t		position() const;
  virtual int		operator==(const Proposed_Property &) const;
  virtual int		operator!=(const Proposed_Property &) const;
			operator size_t() const;
  void                  set_id(uint32 i) { _id = i; }
  virtual bool		has_default_value() const { return false; }
  virtual Numeric_Value	default_value() const { return Numeric_Value(); }
  virtual ooBaseType	base_type() const { return oocTypeNONE; }
  virtual ooStatus	change_base_type(ooBaseType) { return oocError; }
  virtual ooBaseType	element_base_type() const { return oocTypeNONE; }
  virtual bool	        element_is_short() const { return false; }
  virtual bool          is_short() const { return false; }
  Proposed_Class &      other_class();
  Type_Descriptor &     type_of() const; // From Property_Descriptor

  // Virtual member functions of Property_Descriptor
  virtual const char *  other_class_name() const { return NULL; }
  virtual const char *  other_class_namespace_name() const { return NULL; }

  Proposed_Property(const char *,	// name
		    size_t,		// arraySize
		    d_Access_Kind,	// visibility
		    ooMemberType);
  Proposed_Property(ooIsNull);	// Just for creating null object(s)
  Proposed_Property();
  virtual		~Proposed_Property();
  static const Proposed_Property
			null;
  virtual void *	defaultValueAddress() const { return NULL; }

protected:
  enum ooMemberChangeType {
    oocMatch,
    oocNonPersist,
    oocPersist,
    oocInvalid,
    oocNew,
    oocUndefined
  };
  virtual void          store() {;}
  virtual bool          storeChanges (bool) { return false; }
  virtual bool          compare(otiClassRef &, int) { return false;}
  virtual bool          isPhysical() const { return false;}
  virtual bool          isMember() const { return false;}
  virtual bool          isSame(otiClassRef&, int) const { return false;}
  virtual bool          isBase() const { return false;}
  virtual bool          hasVirtual() const { return false;}
  virtual ooMemberChangeType
                        evolve(otiClassRef& classRef, int &otiPos) {
    return oocUndefined;
  }
  virtual ooMemberChangeType
                        markAdded() {
    return oocUndefined;
  }
  virtual void setNewAssoc() {
    _newAssoc = true;
  }
  virtual bool isNewAssoc() {
    return _newAssoc;
  }

private:
  char *		_previousName;
  Proposed_Class *      _otherClassP;
  size_t		_arraySize;
  size_t                _elementRepetition; // 0 in current implementations
  ooMemberChangeType    _memberChangeType;
  bool                  _newAssoc;
};

bool
Proposed_Property::is_varray_embedded_class_type() const
{
  return false;
}
typedef Proposed_Class *Proposed_ClassP;

class EV_STORAGE_SPECIFIER Proposed_Attribute
  : public Proposed_Property
{
public:
    ooStatus			change_array_size(size_t);
protected:
    Proposed_Attribute(const Proposed_Attribute &);
    Proposed_Attribute &operator=(const Proposed_Attribute &);
    Proposed_Attribute(const char *,	// name
		       size_t,		// arraySize
		       d_Access_Kind,	// visibility
		       ooMemberType);
    virtual void store();
    virtual bool storeChanges (bool) ;
    virtual bool compare(otiClassRef &, int);
    virtual ooMemberChangeType evolve(otiClassRef& classRef, int &otiPos );
    virtual ooMemberChangeType markAdded() ;
    virtual bool isSame(otiClassRef&, int) const;
    bool varrayCompare(otiClassRef &, int);
    bool storeBasic();
    bool storeVArray();
    bool storeRef();
    bool storeEmbedded();

    virtual bool isPhysical() const {
        return true;
    }
    virtual bool isMember() const {
        return true;
    }
    virtual bool isBase() const {
        return false;
    }
    void retranslate90onlyTypes();
};

class EV_STORAGE_SPECIFIER Proposed_Basic_Attribute
    : public Proposed_Attribute
{
  friend class d_Module;
  friend class d_Module_Int;
  friend class Proposed_Class;
  friend class Proposed_Property;
  friend class Proposed_Attribute;
  friend class otmEvolveOverrides;
public:
  virtual ooBaseType	base_type() const { return _baseType; }
  virtual bool	        is_basic_type() const { return true; }
  virtual bool	        has_default_value() const;
  virtual Numeric_Value	default_value() const { return _defaultVal; }
  virtual ooStatus	change_base_type(ooBaseType);
  virtual ooAsType	descriptor_kind() const {
    return Proposed_Basic_Attribute_t;
  }

protected: // External calls prohibited
  Proposed_Basic_Attribute(const Proposed_Basic_Attribute &);
  Proposed_Basic_Attribute &operator=(const Proposed_Basic_Attribute &);

  Proposed_Basic_Attribute(const char *,	// name
			   ooIntegerType,	// baseType
			   d_Access_Kind,	// visibility
			   size_t);		// arraySize
  Proposed_Basic_Attribute(const char *,	// name
			   ooUINT64_t,	// baseType
			   d_Access_Kind,	// visibility
			   size_t);		// arraySize
  Proposed_Basic_Attribute(const char *,	// name
			   ooPTR_t,		// baseType
			   d_Access_Kind,	// visibility
			   size_t);		// arraySize
  Proposed_Basic_Attribute(const char *,	// name
			   ooFloatType,	// baseType
			   d_Access_Kind,	// visibility
			   size_t);		// arraySize
  Proposed_Basic_Attribute(const char *,	// name
			   ooIntegerType,	// baseType
			   d_Access_Kind,	// visibility
			   size_t,		// arraySize
			   int64);		// defaultVal
  Proposed_Basic_Attribute(const char *,	// name
			   ooUINT64_t,	// baseType
			   d_Access_Kind,	// visibility
			   size_t,		// arraySize
			   uint64);		// defaultVal
  Proposed_Basic_Attribute(const char *,	// name
			   ooPTR_t,		// baseType
			   d_Access_Kind,	// visibility
			   size_t,		// arraySize
			   void *);		// defaultVal
  Proposed_Basic_Attribute(const char *,	// name
			   ooFloatType,	// baseType
			   d_Access_Kind,	// visibility
			   size_t,		// arraySize
			   float64);		// defaultVal
  bool                  defaultValueIsValid() const;
  virtual void *        defaultValueAddress() const;

private:
  ooBaseType		_baseType;
  Numeric_Value	        _defaultVal;
};

class EV_STORAGE_SPECIFIER Proposed_Embedded_Class_Attribute
    : public Proposed_Attribute
{
  friend class Proposed_Class;
  friend class otmEvolveOverrides;
public:
  virtual bool	is_embedded_class_type() const { return true; }
  const char *	embedded_class_name() const;
  const char *	embedded_class_namespace_name() const;
  // Note: the following change is for special system usage and
  // will ordinarily be flagged as illegal
  ooStatus		change_embedded_class(const char *);
  virtual ooAsType	descriptor_kind() const {
                          return Proposed_Embedded_Class_Attribute_t;
  }
  virtual const char *  other_class_name() const;
  virtual const char *  other_class_namespace_name() const;
  virtual bool hasVirtual() const;

protected: // External calls prohibited
  Proposed_Embedded_Class_Attribute(const Proposed_Embedded_Class_Attribute &);
  Proposed_Embedded_Class_Attribute &operator=(
    const Proposed_Embedded_Class_Attribute &);
  Proposed_Embedded_Class_Attribute(const char *,	 // name
				    const char *,	 // otherClassName
				    d_Access_Kind,	 // visibility
				    size_t,		 // arraySize
				    const char * = NULL);// otherClassNamespace
  virtual ~Proposed_Embedded_Class_Attribute();
};

class EV_STORAGE_SPECIFIER Proposed_Ref_Attribute
    : public Proposed_Attribute
{
  friend class d_Module;
  friend class Proposed_Class;
  friend class Proposed_Property;
  friend class otmEvolveOverrides;
public:
  virtual bool	is_ref_type() const { return true; }
  inline const char *	referenced_class_name() const;
  inline const char *	referenced_class_namespace_name() const;
  virtual bool		is_short() const;
  ooStatus		change_short(bool);
  // Note: the following change is for special system usage and
  // will ordinarily be flagged as illegal
  ooStatus		change_referenced_class(const char *);
  virtual ooAsType	descriptor_kind() const {
    return Proposed_Ref_Attribute_t;
  }

protected: // External calls prohibited
  Proposed_Ref_Attribute(const Proposed_Ref_Attribute &);
  Proposed_Ref_Attribute &operator=(const Proposed_Ref_Attribute &);
  Proposed_Ref_Attribute(const char *,	// name
			 d_Access_Kind,	// visibility
			 size_t,	// arraySize
			 const char *,	// referencedClassName
			 ooAsType,	// d_Ref_Type_t|Short_Ref_Type_t
			 const char * = NULL);	// referencedClass namespace
  virtual ~Proposed_Ref_Attribute();
  virtual const char *  other_class_name() const;
  virtual const char *  other_class_namespace_name() const;

private:
  ooAsType		_refType;
};

inline const char *
Proposed_Ref_Attribute::referenced_class_name() const
{
  return _otherClassName;
}

inline const char *
Proposed_Ref_Attribute::referenced_class_namespace_name() const
{
  return _otherClassNamespaceName;
}

class EV_STORAGE_SPECIFIER Proposed_Relationship
  : public Proposed_Property
{
  friend class d_Module;
  friend class d_Module_Int;
  friend class Proposed_Class;
  friend class Proposed_Property;
  friend class Proposed_Relationship_Int;
  friend class otmEvolveOverrides;

public:    
  inline const char *	related_class_name() const;
  inline const char *	related_class_namespace_name() const;
  virtual bool	is_relationship_type() const { return true; }
  bool		is_bidirectional() const;
  bool		is_inline() const { return _isInline; }
  virtual bool	is_short() const { return _isShort; }
  bool		is_to_many() const { return _isToMany; }
  bool		is_unknown() const { return _isUnknown; }
  virtual ooAsType	descriptor_kind() const { return Proposed_Relationship_t; }
  uint8		        copy_mode() const { return _copyMode; }
  uint8		        versioning() const { return _versioning; }
  uint8		        propagation() const { return _propagation; }
  const char *	        inverse_name() const { return _inverseName; }
  bool		        inverse_is_to_many() const { return _inverseIsToMany; }
  inline ooAssocNumber  specified_assoc_number() const;
  ooStatus		change_inline(bool);
  ooStatus		change_short(bool);
  ooStatus		change_copy_mode(uint8);
  ooStatus		change_propagation(uint8);
  ooStatus		change_versioning(uint8);
  ooStatus              set_unknown(bool);
  // Note: the following 7 changes are for special system usage and
  // will ordinarily be flagged as illegal
  ooStatus		change_inverse_name(const char *);
  ooStatus		change_inverse_is_to_many(bool);
  ooStatus		change_to_many(bool);
  ooStatus		change_to_unidirectional(ooAssocNumber = 0);
  ooStatus		change_to_bidirectional(const char *,
						bool,
						ooAssocNumber = 0);
  ooStatus		change_related_class(const char *);
  ooStatus		change_inverse(const char *);
  ooStatus		change_inverse_attribute_id(uint32);
  virtual const char *  other_class_name() const;
  virtual const char *  other_class_namespace_name() const;
  uint32		inverse_id() const { return _inverseID; }

protected:
  Proposed_Relationship(d_Access_Kind, // visibility 
			const char *,  // name
			const char *,  // otherClassName
			bool,		 // isInline
			bool,		 // isShort
			bool,		 // isToMany
			uint8,	 // copyMode
			uint8,	 // versioning
			uint8,	 // propagation
			const char * = NULL,	// otherAssocName
			bool = false,		// otherIsToMany
			ooAssocNumber = 0,	// specifiedAssocNumber
			const char * = NULL); // otherClassNamespaceName
  Proposed_Relationship();
  virtual ~Proposed_Relationship();
  virtual bool isSame(otiClassRef&, int) const;
  virtual void store();
  virtual bool storeChanges (bool) ;
  virtual bool compare(otiClassRef &, int);
  virtual ooMemberChangeType evolve(otiClassRef& classRef, int &otiPos);
  virtual ooMemberChangeType markAdded();
  virtual bool isPhysical() const {
    return this->is_inline();
  }
  virtual bool isMember() const {
    return false;
  }
  virtual bool isBase() const {
    return false;
  }
  virtual bool hasVirtual() const {
    return false;
  }

private:
  unsigned long *
                _code;
  const char *	_inverseName;
  const char *	_previousInverseName;
  unsigned long	_specifiedAssocNum;
  unsigned long	_specifiedRawAssocNum;
  int32		_inverseID;
  bool		_isInline;
  bool		_isShort;
  bool		_isToMany;
  bool		_inverseIsToMany;
  bool          _isUnknown;
  uint8		_copyMode;
  uint8		_versioning;
  uint8		_propagation;
  bool          _isAdded;
  uint8         _direction; // SPR 20526
};

inline ooTypeNumber
Proposed_Relationship::specified_assoc_number() const
{
    return _specifiedAssocNum;
}

inline const char *
Proposed_Relationship::related_class_name() const
{
  return _otherClassName;
}

inline const char *
Proposed_Relationship::related_class_namespace_name() const
{
  return _otherClassNamespaceName;
}

class EV_STORAGE_SPECIFIER Proposed_Collection_Attribute
    : public Proposed_Attribute
{
    friend class Proposed_Class;
    friend class Proposed_VArray_Attribute;
public:
    virtual d_Kind		kind() const = 0; // will return ARRAY
protected: // External calls prohibited
    Proposed_Collection_Attribute(const Proposed_Collection_Attribute &);
    Proposed_Collection_Attribute &operator=
	(const Proposed_Collection_Attribute &);
    virtual			~Proposed_Collection_Attribute() {;}
    Proposed_Collection_Attribute(const char *,		// name
				  size_t,		// arraySize
				  d_Access_Kind,	// visibility
				  ooMemberType);
};

class EV_STORAGE_SPECIFIER Proposed_VArray_Attribute
    : public Proposed_Collection_Attribute
{
  friend class d_Module;
  friend class Proposed_Class;
  friend class Proposed_Property;
  friend class otmEvolveOverrides;

public:
  const char *	element_embedded_class_name() const;
  const char *	element_embedded_class_namespace_name() const;
  const char *	element_referenced_class_name() const;
  const char *	element_referenced_class_namespace_name() const;
  virtual bool	is_varray_type() const { return true; }
  virtual bool	is_varray_basic_type() const;
  virtual bool	is_varray_embedded_class_type() const;
  virtual bool	is_varray_ref_type() const;
  virtual d_Kind	kind() const { return ARRAY; }
  virtual ooBaseType	element_base_type() const;
  virtual bool		is_short() const { return this->element_is_short(); }
  virtual bool		element_is_short() const;
  ooStatus		change_element_base_type(ooBaseType);
  ooStatus		change_element_short(bool);
  // Note: the following two changes are for special system usage and
  // will ordinarily be flagged as illegal
  ooStatus		change_element_referenced_class(const char *);
  ooStatus		change_element_embedded_class(const char *);
  virtual ooAsType	descriptor_kind() const {
    return Proposed_VArray_Attribute_t;
  }
  virtual const char *  other_class_name() const;
  virtual const char *  other_class_namespace_name() const;
  virtual ooTypeNumber  other_class_number() const;
  void set_elementTypeIsShapeNumber(bool TorF) {
    _elementTypeIsShapeNumber = TorF;
  }

protected: // External calls prohibited
  Proposed_VArray_Attribute(const Proposed_VArray_Attribute &);
  Proposed_VArray_Attribute &operator=(const Proposed_VArray_Attribute &);
  Proposed_VArray_Attribute(const char *,	// name
			    ooBaseType,	// baseType
			    d_Access_Kind,	// visibility
			    size_t);		// arraySize
  Proposed_VArray_Attribute(const char *,	// name
			    const char *,	// otherClassName
			    d_Access_Kind,	// visibility
			    size_t,		// arraySize
			    const char *	// otherClass
			    = NULL);	//   NamespaceName
  Proposed_VArray_Attribute(const char *,	// name
			    ooAsType,	// d_Ref_Type_t|Short_Ref_Type_t
			    const char *,	// otherClassName
			    d_Access_Kind,	// visibility
			    size_t,		// arraySize
			    const char *	// otherClass
			    = NULL);	//   NamespaceName
  virtual ~Proposed_VArray_Attribute();
private:
  ooBaseType		_baseType;
  ooAsType		_refType;
  bool                  _elementTypeIsShapeNumber;
};

class EV_STORAGE_SPECIFIER Proposed_Base_Class
  : public Proposed_Property
{
  friend class Proposed_Class;
  friend class Proposed_Class_Int;
  friend class Proposed_Base_Class_Int;
  friend class d_Module;
  friend class d_Module_Int;
  friend class otmEvolveOverrides;
public:
  d_Access_Kind	        access_kind() const { return _visibility; }
  d_Boolean		persistent_capable() const;
  size_t		position() const;
  Proposed_Class &	defined_in_class() const;
  Proposed_Class &      base_class() const;
  ooStatus		change_access(d_Access_Kind);
  const char *	        previous_name() const { return _previousName; }
  virtual const char *	namespace_name() const { return _namespaceName; }
  const char *	        previous_namespace_name() const {
    return _previousNamespaceName;
  }
  virtual ooAsType	descriptor_kind() const { return Proposed_Base_Class_t; }
  virtual int		operator==(const Proposed_Property &) const;
  virtual int		operator!=(const Proposed_Property &) const;
  operator size_t() const;
  bool                  is_virtual() const { return _isVirtual; }

  static const Proposed_Base_Class
                        null;
  virtual ~Proposed_Base_Class();
  Proposed_Base_Class &operator=(const Proposed_Base_Class &);
  Proposed_Base_Class(const d_Class &, d_Access_Kind);
  Proposed_Base_Class(const char *,		// name
		      d_Access_Kind,		// visibility
		      const char * = NULL,	// previousName
		      const char * = NULL,	// namespaceName
		      const char * = NULL);	// previousNamespaceName
  Proposed_Base_Class(ooIsNull);	// Just for creating null object(s)
  Proposed_Base_Class();

protected:
  virtual bool     isSame(otiClassRef&, int) const;
  virtual void     store();
  virtual bool     storeChanges(bool);
  virtual bool     compare(otiClassRef &, int);
  virtual bool     isPhysical() const {
    return true;
  }
  virtual ooMemberChangeType
                   evolve(otiClassRef& classRef, int &otiPos);
  virtual ooMemberChangeType
                   markAdded() ;
  virtual bool     isMember() const {
    return false;
  }
  virtual bool     isBase() const {
    return true;
  }
  virtual bool     hasVirtual() const;

private:
  bool                 _isVirtual;
  bool                 _toDerived ;
  uint32               _oldMemberId;
  uint32               _oldMemberBase;
  Proposed_Class *     _baseClassP;
  bool		       _persistentCapable;
  const char *	       _namespaceName;
  const char *	       _previousNamespaceName;
};

#if defined(_MSC_VER) && _MSC_VER > 1300
ooExplicitTemplateInstantiation EV_STORAGE_SPECIFIER ooTVArray(uint32);
ooExplicitTemplateInstantiation EV_STORAGE_SPECIFIER ooTVArray(listElementP<Proposed_Base_Class >);
ooExplicitTemplateInstantiation EV_STORAGE_SPECIFIER ooTVArray(listElementP<Proposed_Property >);
ooExplicitTemplateInstantiation EV_STORAGE_SPECIFIER ooTVArray(listElementP<Proposed_Base_Change >);
#endif

class EV_STORAGE_SPECIFIER Proposed_Base_Change
{
  friend class Proposed_Class;
public:
  size_t		direction() const { return _changeDirection; }
  uint32		id() const { return _id; }
  uint32		old_id() const { return _oldID; }
  uint32		path_length() const { return _pathLength; }
  const ooTVArray(uint32) &
			path() const { return _path; }
  void			add_path_node(uint32 pos);

private:
  ooTVArray(uint32)	_path;
  uint32		_id;
  uint32		_oldID;
  uint8			_changeDirection;
  uint32		_pathLength;
};

class EV_STORAGE_SPECIFIER Proposed_Class : public Type_Descriptor
{
  friend class d_Module;
  friend class d_Module_Int;
  friend class Proposed_Attribute;
  friend class Proposed_Property;
  friend class Proposed_Embedded_Class_Attribute;
  friend class Proposed_Relationship;
  friend class Proposed_Relationship_Int;
  friend class Proposed_Base_Class;
  friend class Proposed_Base_Class_Int;
  friend class Proposed_Class_Int;
  friend class list_iterator<Proposed_Property >;
  friend class ooEvolveSession;
  friend class otmEvolveOverrides;
public:
  virtual d_Boolean		persistent_capable() const;

  proposed_base_class_iterator  base_class_list_begin() const;
  proposed_base_class_iterator  base_class_list_end() const;

  proposed_property_iterator	defines_property_begin() const;
  proposed_property_iterator	defines_property_end() const;

  const d_Module &		proposed_in_module() const;
  inline const d_Module &	defined_in_module() const; // same as above
  const char *		        previous_name() const;
  Proposed_Property &		resolve_property(const char *);
  Proposed_Base_Class &	        resolve_base_class(
                                  const char *,         // name
                                  const char * = NULL); // namespace
  inline size_t		number_of_attribute_positions() const;
  inline size_t		number_of_base_classes() const;
  const Class_Position	position_in_class(const char *) const;
  inline ooTypeNumber	specified_shape_number() const;
  inline ooTypeNumber	current_shape_number() const;
  ooTypeNumber		shape_number() const;
  inline void		set_specified_shape_number(ooTypeNumber);
  inline void		set_current_shape_number(ooTypeNumber);
  bool			is_deleted() const { return _deleteClass; }
  virtual const char *	namespace_name() const { return _namespaceName; }
  virtual const char *	module_name() const;
  const char *		previous_namespace_name() const {
    return _previousNamespaceName;
  }

  Proposed_Property &	add_basic_attribute(int32,        // position
					    d_Access_Kind,// visibility
					    const char *, // name
					    size_t,       // arraySize
					    ooNumberType);// baseType
  Proposed_Property &	add_basic_attribute(int32,        // position
					    d_Access_Kind,// visibility
					    const char *, // name
					    size_t,       // arraySize
					    ooIntegerType,// ooUINT32, etc.
					    int64);       // defaultVal
  Proposed_Property &	add_basic_attribute(int32,        // position
					    d_Access_Kind,// visibility
					    const char *, // name
					    size_t,       // arraySize
					    ooUINT64_t,
					    uint64);       // defaultVal
  Proposed_Property &	add_basic_attribute(int32,        // position
					    d_Access_Kind,// visibility
					    const char *, // name
					    size_t,       // arraySize
					    ooPTR_t,
					    void *);      // defaultVal
  Proposed_Property &	add_basic_attribute(int32,        // position
					    d_Access_Kind,// visibility
					    const char *, // name
					    size_t,       // arraySize
					    ooFloatType,  // ooFLOAT32, etc.
					    float64);     // defaultVal
  Proposed_Property &	add_embedded_class_attribute(
    int32,	   // position
    d_Access_Kind, // visibility
    const char *,  // name
    size_t,	   // arraySize
    const char *,  // className
    const char *
    = NULL);       // namespace
  Proposed_Property &	add_unidirectional_relationship(int32,  // position
						d_Access_Kind, // visibility
						const char *,  // name
						const char *,  // otherClassName
						bool,	    // isInline
						bool,	    // isShort
						bool,	    // isToMany
						uint8,	    // copyMode
						uint8,	    // versioning
						uint8,	    // propagation
						ooAssocNumber  // specified assoc
						  = 0,	    //     number
						const char *   // otherClass
						  = NULL);   //   Namespace
  Proposed_Property &	add_bidirectional_relationship(int32, // position
					       d_Access_Kind, // visibility
					       const char *,  // name
					       const char *,  // otherClassName
					       bool,	   // isInline
					       bool,	   // isShort
					       bool,	   // isToMany
					       uint8,	   // copyMode
					       uint8,	   // versioning
					       uint8,	   // propagation
					       const char *,  // otherName
					       bool,	   // otherIsToMany
					       ooAssocNumber  // specified assoc
						 = 0,       //     number
					       const char *  // otherClass
						 = NULL);   //   Namespace
  Proposed_Property &	add_ref_attribute(int32,        // position
					  d_Access_Kind,// visibility
					  const char *, // name
					  size_t,       // arraySize
					  const char *, // referencedClassName
					  bool,		// isShort
					  const char *
					  = NULL);  // refClassNamespace
  // Array of basic primitives
  Proposed_Property &   add_varray_attribute(int32,        // position
					     d_Access_Kind,// visibility
					     const char *, // name
					     size_t,       // arraySize
					     ooNumberType); // ooFLOAT64, etc.
  // Array of embedded class instances
  Proposed_Property &	add_varray_attribute(int32,        // position
					     d_Access_Kind,// visibility
					     const char *, // name
					     size_t,       // arraySize
					     const char *, // otherClassName
					     const char *  // otherClass
					     = NULL);      //   Namespace
  // Array of ooRefs (OIDs)
  Proposed_Property &	add_varray_attribute(int32,        // position
					     d_Access_Kind,// visibility
					     const char *, // name
					     size_t,       // arraySize
					     bool,	   // isShort
					     const char *, // otherClassName
					     const char *  // otherClass
					     = NULL); //    Namespace
  Proposed_Property &	add_base_class(int32,		  // position
				       d_Access_Kind,	  // visibility
				       const char *,	  // name
				       const char * = NULL); // namespace
  Proposed_Property &	add_property(int32,
				     d_Access_Kind,
				     const d_Property &);
  Proposed_Property &	delete_property(const char *);
  Proposed_Property &	delete_base_class(const char *,		// name
					  const char * = NULL);	// namespace
  Proposed_Property &	move_property(const char *, size_t);
  Proposed_Property &	move_base_class(
    const char *,		// name
    size_t,			// new position
    const char * = NULL);	// namespace
  Proposed_Property &	change_base_class(
    const char *,		// previous name
    const char *,		// new name
    const char * = NULL,	// previous namespace
    const char * = NULL);	// new namespace
  // The following method variant is currently for internal use only
  Proposed_Base_Change &change_base_class(
    uint32,			// memberID
    uint32,			// oldMemberID
    uint8,			// changeDirection
    size_t,			// pathLength
    size_t *);			// pathP
  // For ANameSpace::A, rename("B") means change the name from A to B
  // but leave it in ANameSpace; rename("B", NULL) or rename("B", "")
  // means also move it to the default namespace.
  Proposed_Class &	rename(const char *); // name
  Proposed_Class &	rename(const char *,	// name
			       const char *);	// namespace
  ooStatus		delete_class();
  ooStatus		set_language(int);
  ooStatus		add_virtual_table(bool TorF = true);
  virtual ooAsType	descriptor_kind() const { return Proposed_Class_t; }
  ooStatus              set_created_by_active_schema(bool);
  bool                  created_by_active_schema() const;
  virtual bool		is_proposed() const { return true; }
  void                  handleException(char *, ooException &);
  uint32                highest_attribute_id() const { return _highestAttID; }
  void                  set_highest_attribute_id(uint32 val) {
    if (val > _highestAttID) { _highestAttID = val; }
  }
  static bool		enable_delete_dynamic_relationships_in_place(
                          bool = true);
  static bool           enable_proposal_reuse(bool);
  static bool           proposal_reuse_is_enabled();
  virtual int		operator==(const Proposed_Class &) const;
  virtual int		operator!=(const Proposed_Class &) const;
                        operator size_t() const;
  Proposed_Class(const d_Class &,
		 ooTypeNumber,
		 bool internal = false);
  Proposed_Class(const char *,		// class name
		 const d_Module &,
		 ooTypeNumber,
		 const char * = NULL);	// namespaceName
  Proposed_Class(const char *cN,
		 const char *sN,
		 unsigned long *c,
		 const char* nN);
  Proposed_Class(ooIsNull, bool) // Extra arg just for unambiguous signature
    : Type_Descriptor(oocIsNull), _previousName(NULL) {;}
  Proposed_Class() {;}
  Proposed_Class(const Proposed_Class &) {;}

  virtual ~Proposed_Class();

  static const Proposed_Class null;
  static ost_table    *validated;
  static ost_table    *renamed;
  static ost_table    *renamed_new;
  static ost_table    *deleted;

protected:
  enum vTableStatus { vt_added, vt_dropped, vt_unchanged, vt_unknown };
  enum status { st_new, st_version, st_unchanged, st_add_associations,
		st_forward, st_evolved };
  enum evolution { evol_undefined, evol_unchanged, evol_new_shape,
		   evol_inplace, evol_new_class, evol_drop_class} ;
  ooStatus                attachProposedAttribute(Proposed_Property *, int32);
  ooStatus                attachProposedBaseClass(Proposed_Base_Class *,
						  int32);
  d_Class *               previousShapeP() const { return _previousShapeP; }
  d_Class *               currentShapeP() const { return _currentShapeP; }
  bool                    isActivated() const { return _isActivated; }
  bool                    evProcessed() const { return _evProcessed; }
  Proposed_Property &     resolvePropertyByPreviousName(const char *);
  ClassPosNoCopy *        posInProposedClass(const char *, // memName
					     bool, // nowMatchingQualifiers
					     d_Module &) const;
  ClassPosNoCopy *        posInProposedOrRealClassQualified(
    const char *, // memName
    d_Module &) const;
  bool                isInternallyHeapAllocated() const {
    return _internallyHeapAllocated;
  }
  bool                nonExplicit() const { return _nonExplicit; }
  d_Boolean           persistentCapable(d_Module &);
  d_Boolean           isContainer() const { return _isContainer; }
  Proposed_Property & nthProperty(unsigned int);
  void                set_previousShapeP(const d_Class *prevCP) {
    _previousShapeP = ooConstCast(d_Class *, prevCP);
  }
  void                set_currentShapeP(const d_Class *curCP) {
    _currentShapeP = ooConstCast(d_Class *, curCP);
  }
  void                set_previousName(const char *);
  void                set_previousNamespaceName(const char *);
  void                set_isActivated(bool b) {
    _isActivated = b;
  }
  void                set_evProcessed(bool b) {
    _evProcessed = b;
  }
  unsigned long *code() const;
  void dropOldName();
  bool compare(otiClassRef &, int);
    
  void begin();
  void end();

  bool isVTABLE_PTR(otiClassRef &, int);
  void createForward();
  void createShape() ;

  void versionBiAssocs();
  void versionUniAssocs();
  bool evolve(ooChangeKind);
  bool evolvedPhysically() const {
    if ((_evolType == evol_new_shape) || (_evolType == evol_drop_class)){
      return true;
    } else {
      return false;
    }
  }
  bool comparePhysical(otiClassRef &, int);
  bool compareOnePhysicalMember(otiClassRef &,
				Proposed_Property &,
				int, // type
				int &, // highestCurPhysPos
				ooEvolveSession *,
				bool &); // done
  bool compareNonPhysical(otiClassRef &, int);
  bool countMembers(otiClassRef &cR);
  bool derived(ooTVArray(Proposed_ClassP) &);
  bool bases(ooTVArray(Proposed_ClassP) &);
  bool referencing_classes(ooTVArray(Proposed_ClassP)& );
  void setDifferent() {
    _diff = true;
    _diffNonPhysical = true;
  }
  bool isDifferent() {
    return _diff;
  }
  void clearDifferent() {
    _diff = false;
    _diffNonPhysical = false;
  }
  void setDifferentNonPhysical() {
    _diffNonPhysical = true;
  }
  bool isDifferentNonPhysical() {
    // diff || diffNonPhysical, compensating for bool values
    // not necessarily being exactly equal to bool values
    return ((_diff != false) || (_diffNonPhysical != false));
  }
  void clearDifferentNonPhysical() {
    _diffNonPhysical = false;
  }
  void setUndefined() {
    _undefined = true;
  }
  bool isUndefined() {
    return _undefined;
  }
  void retrieveCodes();
    
  Proposed_Relationship* matching_BiAssoc(const char *) ;
  bool prepareToChange();
  bool storeChanges();
  bool leftMostBaseClassHasVirtualTable();
  void setVirtuals();
  void forward() {
    if (_st != st_unchanged) {
      this->createForward();
    } else if (_ast == st_add_associations) {
      // createAssoc();
    }
  }
  bool compare();
  bool INTERNALcompare(otiClassRef &, int);
  void store();
  void markChanged() {
    if (_evolType != evol_new_class) {
      _st = st_evolved;
      _evolType = evol_new_shape ;
    }
  }
  bool isVersion() const {
    return (_st == st_version) ? true : false;
  }
  bool isUnchanged() {
    return (_st == st_unchanged) ? true : false;
  }
  bool isForward() {
    return (_st == st_forward) ? true : false;
  }
  bool isNew() {
    return (_st == st_new) ? true : false;
  }
  void setNew() {
    _st = st_new;
  }
  void setVersion() {
    _st = st_version;
  }
  void setForward() {
    _st = st_forward;
  }
  void clearAddAssociation() {
    _ast = st_version;
  }
  void setAddAssociation() {
    _ast = st_add_associations;
  }
  bool isAddAssociation() {
    return (_ast == st_add_associations);
  }
  bool isHistoryUpdate() const { return _mayHaveProposedPastShapes; }

  static bool initRenamed(bool) ;
  static void removeRenamed();
  static bool addToRenamed(Proposed_Class* aClass) ;
  static Proposed_Class* hasBeenRenamed(const char* class_name, 
					const char* namespace_name, 
					const char* module_name);
  static Proposed_Class* isRenamedAs(const char* class_name, 
				     const char* namespace_name, 
				     const char* module_name);
  static bool addToDeleted(Proposed_Class* aClass);
  static bool hasBeenDeleted(const char* class_name,
			     const char* namespace_name,
			     const char* module_name);

private:
  ooTVArray(listElementP<Proposed_Base_Class >)
			_base_class_list;
  ooTVArray(listElementP<Proposed_Property >)
			_attributes;
  ooTVArray(listElementP<Proposed_Base_Change >)
			_baseChanges;
  ooTVArray(listElementP<Proposed_Property >)
			_removedAttributes;
  ooId                  _currentOtiDesc;
  ooId                  _prevNamedOtiDesc;
  d_Module *		_moduleP;
  d_Class *		_previousShapeP;
  d_Class *		_currentShapeP;
  size_t		_align;
  size_t		_baseClassCount;
  char *		_previousName;
  char *		_previousNamespaceName;
  unsigned long *       _cd;
  ooTypeNumber	        _specifiedShapeNum;
  ooTypeNumber	        _currentShapeNum;
  int			_currentOTIdescOpenMode;
  uint32                _highestAttID;
  vTableStatus          _vTableChange;
  evolution             _evolType;
  status                _st;
  status                _ast;
  ooDescriptionLevel    _descriptionLevel;
  bool		        _isActivated;
  bool                  _otiHasVtablePtr;  // TODO: FIX THIS XXX
  bool		        _internallyHeapAllocated;
  bool		        _nonExplicit;
  bool		        _deleteClass;
  bool                  _evAdded;                    // Internal progress
  bool                  _evProcessed;                // Internal progress
  bool                  _evProposedDependentClasses; // Internal progress
  bool                  _createdByActiveSchema;
  bool                  _diff;
  bool                  _diffNonPhysical;
  bool                  _undefined;
  bool                  _isProposedPastShape;
  bool                  _mayHaveProposedPastShapes;
  bool                  _repairingUnknownOtherMember;
  bool                  _mustBePersistent;
  uint8                 _language;
  bool                  _pastAttributesAdded;
  bool                  _stored;
  static bool		_deleteDynamicRelationshipsInPlace;
  static bool		_proposalReuse;

  friend class ooEvolveSession;
};

inline size_t
Proposed_Class::number_of_attribute_positions() const
{
  return _memberCount;
}

inline size_t
Proposed_Class::number_of_base_classes() const
{
  return _baseClassCount;
}

inline ooTypeNumber
Proposed_Class::specified_shape_number() const
{
  return _specifiedShapeNum;
}

inline ooTypeNumber
Proposed_Class::current_shape_number() const
{
    return _currentShapeNum;
}

inline void
Proposed_Class::set_specified_shape_number(ooTypeNumber sn)
{
    _specifiedShapeNum = sn;
}

inline void
Proposed_Class::set_current_shape_number(ooTypeNumber sn)
{
    _currentShapeNum = sn;
}

inline bool
Proposed_Class::created_by_active_schema() const
{
  return _createdByActiveSchema;
}

inline ooStatus
Proposed_Class::set_created_by_active_schema(bool TorF)
{
  _createdByActiveSchema = TorF;
  return oocSuccess;
}

inline const d_Module &
Proposed_Class::defined_in_module() const
{
  return this->proposed_in_module();
}

class EV_STORAGE_SPECIFIER ProposeVArrayPersistentError
    : public asException
{
public:
    Proposed_VArray_Attribute &	proposed_attribute_of();
    ProposeVArrayPersistentError(Proposed_VArray_Attribute &);
    virtual void		throw_this() { throw *this; }
    static void			disable() { _thisExcEnabled = false; }
    static void			enable() { _thisExcEnabled = true; }
    static bool			enabled() { return _thisExcEnabled; }
protected: // External calls prohibited
    bool			thisExceptionEnabled() const {
				    return _thisExcEnabled;
				}
private:
    Proposed_VArray_Attribute *	_propVArrAttP;
    static bool			_thisExcEnabled;
};

class EV_STORAGE_SPECIFIER InheritsFromSelfError : public asException
{
public:
    InheritsFromSelfError(const d_Class *);
    InheritsFromSelfError(Proposed_Class *);
    const d_Class &	class_of() const { return *_derivedP; }
    Proposed_Class &	proposed_class_of();
    virtual void	throw_this() { throw *this; }
    static void		disable() { _thisExcEnabled = false; }
    static void		enable() { _thisExcEnabled = true; }
    static bool		enabled() { return _thisExcEnabled; }
protected: // External calls prohibited
    bool		thisExceptionEnabled() const { return _thisExcEnabled; }
private:
    const d_Class *	_derivedP;
    Proposed_Class *	_derivedProposedP;
    static bool		_thisExcEnabled;
};

class EV_STORAGE_SPECIFIER EvolutionError : public asException
{
public:
    virtual void	throw_this() { throw *this; }
    EvolutionError(const char *, bool = false);
    static void		disable() { _thisExcEnabled = false; }
    static void		enable() { _thisExcEnabled = true; }
    static bool		enabled() { return _thisExcEnabled; }
protected: // External calls prohibited
    bool		thisExceptionEnabled() const { return _thisExcEnabled; }
private:
    static bool		_thisExcEnabled;
};

class EV_STORAGE_SPECIFIER ProposeBadRel : public asException
{
public:
    ProposeBadRel(Proposed_Relationship &);
    Proposed_Relationship &	proposed_relationship_of() const;
    virtual void		throw_this() { throw *this; }
    static void			disable() { _thisExcEnabled = false; }
    static void			enable() { _thisExcEnabled = true; }
    static bool			enabled() { return _thisExcEnabled; }
protected: // External calls prohibited
    bool			thisExceptionEnabled() const {
				    return _thisExcEnabled;
				}
private:
    Proposed_Relationship *	_propRelP;
    static bool			_thisExcEnabled;
};

class EV_STORAGE_SPECIFIER ProposeEvolutionOfInternal : public asException
{
public:
    const char *	class_name() const { return _className; }
    ProposeEvolutionOfInternal(const char *);
    virtual void	throw_this() { throw *this; }
    static void		disable() { _thisExcEnabled = false; }
    static void		enable() { _thisExcEnabled = true; }
    static bool		enabled() { return _thisExcEnabled; }
protected: // External calls prohibited
    bool		thisExceptionEnabled() const { return _thisExcEnabled; }
private:
    const char *	_className;
    static bool		_thisExcEnabled;
};

class EV_STORAGE_SPECIFIER ProposeEvolAndVers : public asException
{
public:
    const char *	module_name() const { return _moduleName; }
    ProposeEvolAndVers(const char *);
    virtual void	throw_this() { throw *this; }
    static void		disable() { _thisExcEnabled = false; }
    static void		enable() { _thisExcEnabled = true; }
    static bool		enabled() { return _thisExcEnabled; }
protected: // External calls prohibited
    bool		thisExceptionEnabled() const { return _thisExcEnabled; }
private:
    const char *	_moduleName;
    static bool		_thisExcEnabled;
};

class EV_STORAGE_SPECIFIER ProposeDynShortRel : public asException
{
public:
    ProposeDynShortRel(Proposed_Relationship &);
    Proposed_Relationship &	proposed_relationship_of() const;
    virtual void		throw_this() { throw *this; }
    static void			disable() { _thisExcEnabled = false; }
    static void			enable() { _thisExcEnabled = true; }
    static bool		enabled() { return _thisExcEnabled; }
protected: // External calls prohibited
    bool		thisExceptionEnabled() const { return _thisExcEnabled; }
private:
    Proposed_Relationship *	_propRelP;
    static bool		_thisExcEnabled;
};

class EV_STORAGE_SPECIFIER AlreadyProposedInClass : public asException
{
public:
    AlreadyProposedInClass(const char *,		// name
			   const char *,		// propertyName
			   const char *,		// className
			   const char *,                // propType
			   const char * = NULL);	// namespaceName
    const char *	property_name() const { return _propertyName; }
    const char *	class_name() const { return _className; }
    virtual const char *namespace_name() const { return _namespaceName; }
    virtual void	throw_this() { throw *this; }
    static void		disable() { _thisExcEnabled = false; }
    static void		enable() { _thisExcEnabled = true; }
    static bool		enabled() { return _thisExcEnabled; }
protected: // External calls prohibited
    bool		thisExceptionEnabled() const { return _thisExcEnabled; }
private:
    const char *	_propertyName;
    const char *	_className;
    const char *	_namespaceName;
    static bool		_thisExcEnabled;
};

class EV_STORAGE_SPECIFIER ProposedBasicAttributeTypeError
    : public asException
{
public:
    ProposedBasicAttributeTypeError(const char *,	// basic type name
				    ooBaseType,
				    Proposed_Class *,
				    size_t,		// position
				    d_Access_Kind,
				    const char *,	// attribute name
				    size_t);		// array size
    ooBaseType			base_type() const { return _btype; }
    Proposed_Class &		proposed_class() { return *_propClassP; }
    size_t			position() const { return _position; }
    d_Access_Kind		access_kind() const { return _accessKind; }
    const char *		attribute_name() const { return _attrName; }
    size_t			array_size() const { return _arrSiz; }
    virtual void		throw_this() { throw *this; }
    static void			disable() { _thisExcEnabled = false; }
    static void			enable() { _thisExcEnabled = true; }
    static bool			enabled() { return _thisExcEnabled; }
protected: // External calls prohibited
    bool			thisExceptionEnabled() const {
				    return _thisExcEnabled;
    				}
private:
    ooBaseType			_btype;
    Proposed_Class *		_propClassP;
    size_t			_position;
    d_Access_Kind		_accessKind;
    const char *		_attrName;
    size_t			_arrSiz;
    static bool			_thisExcEnabled;
};

class EV_STORAGE_SPECIFIER DefaultValueForUnevolvedClass
    : public asException
{
public:
    const char *	attribute_name() const { return _memName; }
    Proposed_Class &	proposed_class_of() const { return *_propCP; }
    Numeric_Value &	value() const { return *_valP; }

    DefaultValueForUnevolvedClass(const char *,
				  Proposed_Class *,
				  Numeric_Value &);
    virtual void	throw_this() { throw *this; }
    static void		disable() { _thisExcEnabled = false; }
    static void		enable() { _thisExcEnabled = true; }
    static bool		enabled() { return _thisExcEnabled; }
protected: // External calls prohibited
    bool		thisExceptionEnabled() const { return _thisExcEnabled; }
private:
    const char *	_memName;
    Proposed_Class *	_propCP;
    Numeric_Value *	_valP;
    static bool		_thisExcEnabled;
};

class EV_STORAGE_SPECIFIER ooEvolveInitializer {
public:
  ooEvolveInitializer();
};
static ooEvolveInitializer __evolveInitializer;

#ifndef OO_NO_NAMESPACE
} // namespace ooas
#endif // !OO_NO_NAMESPACE

#endif // !_OOEVOLVE_H
