/**************************************************************************
		  Copyright (c) 1999-2008 Objectivity, Inc.
			  All Rights Reserved

	THIS IS UNPUBLISHED PROPRIETARY SOURCE CODE OF OBJECTIVITY, INC.

	The copyright notice above does not evidence any
	actual or intended publication of such source code.

*****************************************************************************/

#ifndef _OOSCHEMAEXCEPTION_H
#define _OOSCHEMAEXCEPTION_H

#include <ooSchemaODMG.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <oo.h>
#include <ooException.h>

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

#ifndef OO_NO_NAMESPACE
namespace ooas {
#endif // !OO_NO_NAMESPACE

class AS_STORAGE_SPECIFIER Numeric_Value;

class AS_STORAGE_SPECIFIER asError
{
public:
			asError(unsigned, const char *, ...);
    const char *	what() const OO_WHAT_THROW_NONE;
    void		objectivity_error();
    uint32		code() const { return _code; }
    virtual bool	is_system_error() { return true; }
protected:
    //
    // Note: This source is also used to construct the public header "ooas.h,"
    // WITH THE PROTECTED MEMBERS STRIPPED.  Beware adding virtual protected
    // methods, as this might cause the class layout size seen at library
    // build time to differ from that seen at library use time.
    //
    char *		msgP() { return _msg; }
    void		set_code(uint32 c) { _code = c; }
			asError(unsigned);
private:
    uint32		_code;
    char		_msg[1024];
};

class AS_STORAGE_SPECIFIER asException : public ooException, public asError
{
public:
			asException(unsigned, const char *, ...);
    virtual void	throw_this() = 0;
    void		signal();
    ooException *	next() const { return _nextP; }
    void		set_next(ooException *nP) { _nextP = nP; }
    static void		enable_exceptions() { _enabled = true; }
    static void		disable_exceptions() { _enabled = false; }
    static bool		exceptions_are_enabled() { return _enabled; }
    bool		enabled() { return this->thisExceptionEnabled(); }

    // Virtual member function of ooException base
    //
    const char *	what() const OO_WHAT_THROW_NONE {
			    return asError::what(); }

    // Virtual member function of asError base
    //
    virtual bool	is_system_error() { return false; }

protected: // External calls prohibited
    virtual bool	thisExceptionEnabled() const = 0;

private:
    ooException *	_nextP;
    static bool		_enabled;
};

// OBJY-16847: added new error code SET_INVALID_INVERSE
enum ooAsDynRelAccessErrorCode {
    ACCESS_TO_MANY,
    ITER_TO_ONE,
    SET_TO_MANY,
    ADD_TO_ONE,
    SUB_FROM_ONE,
    SET_INVALID_INVERSE 
};

enum ooAsGetAssocErrorCode {
    OPIGETASSOC,
    OPIGETEASSOC
};

enum ooAsSetAssocErrorCode {
    OPISETASSOC,
    OPISETEASSOC,
    OPISETUSSOC,
    OPISETEUSSOC
};

enum ooAsDelAssocErrorCode {
    OPIDELASSOC,
    OPIDELASSOC_1,
    OPIDELEASSOC,
    OPIDELIASSOC,
    OPIDELUSSOC,
    OPIDELUSSOC_1
};

enum ooAsAddAssocErrorCode {
    OPIADDASSOC,
    OPIADDIASSOC,
    OPIADDUSSOC,
    OPIADDIUSSOC
};

enum ooAsSubAssocErrorCode {
    OPISUBASSOC,
    OPISUBIASSOC,
    OPISUBUSSOC,
    OPISUBIUSSOC
};

enum ooAsAddModuleErrorCode {
    NULL_NAME,
    NAME_ALREADY_USED,
    CREATE_FAILED
};

class AS_STORAGE_SPECIFIER LostNameOfEvolvedClass : public asException
{
public:
    LostNameOfEvolvedClass(const char *,	// name
			   const char *,	// previous name
			   const char * = NULL,	// namespace
			   const char * = NULL); // previous namespace
    virtual void	throw_this() { throw *this; }
    static void		disable() { _thisExcEnabled = false; }
    static void		enable() { _thisExcEnabled = true; }
    static bool		enabled() { return _thisExcEnabled; }
protected: // External calls prohibited
    bool		thisExceptionEnabled() const { return _thisExcEnabled; }
private:
    static bool		_thisExcEnabled;
};

class AS_STORAGE_SPECIFIER CantFindRelInverse : public asException
{
public:
    CantFindRelInverse(d_Relationship *);
    const d_Relationship &	relationship() const { return *_relP; }
    virtual void		throw_this() { throw *this; }
    static void			disable() { _thisExcEnabled = false; }
    static void			enable() { _thisExcEnabled = true; }
    static bool			enabled() { return _thisExcEnabled; }
protected: // External calls prohibited
    bool			thisExceptionEnabled() const {
				    return _thisExcEnabled; }
private:
    static bool			_thisExcEnabled;
    const d_Relationship *	_relP;
};

class AS_STORAGE_SPECIFIER AccessDenied : public asException
{
public:
    AccessDenied();
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

class AS_STORAGE_SPECIFIER ModuleInitError : public asException
{
public:
    ModuleInitError(const char *);
    const char *	module_name() const { return _moduleName; }
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

class AS_STORAGE_SPECIFIER FailedToFindClassByNumberError
    : public asException
{
public:
    FailedToFindClassByNumberError(ooTypeNumber);
    ooTypeNumber	type_number() const { return _typeNumber; }
    virtual void	throw_this() { throw *this; }
    static void		disable() { _thisExcEnabled = false; }
    static void		enable() { _thisExcEnabled = true; }
    static bool		enabled() { return _thisExcEnabled; }
protected: // External calls prohibited
    bool		thisExceptionEnabled() const { return _thisExcEnabled; }
private:
    ooTypeNumber	_typeNumber;
    static bool		_thisExcEnabled;
};

class AS_STORAGE_SPECIFIER FailedToFindClassByNameError
    : public asException
{
public:
    FailedToFindClassByNameError(const char *, const d_Module &);
    const char *	class_name() const { return _name; }
    const d_Module &	module() const { return *_moduleP; }
    virtual void	throw_this() { throw *this; }
    static void		disable() { _thisExcEnabled = false; }
    static void		enable() { _thisExcEnabled = true; }
    static bool		enabled() { return _thisExcEnabled; }
protected: // External calls prohibited
    bool		thisExceptionEnabled() const { return _thisExcEnabled; }
private:
    const char *	_name;
    const d_Module *	_moduleP;
    static bool		_thisExcEnabled;
};

class AS_STORAGE_SPECIFIER FailedToFindMemberByNameError
    : public asException
{
public:
    FailedToFindMemberByNameError(const char *, const d_Class &);
    const char *	member_name() const { return _name; }
    const d_Class &	class_of() const { return *_classP; }
    virtual void	throw_this() { throw *this; }
    static void		disable() { _thisExcEnabled = false; }
    static void		enable() { _thisExcEnabled = true; }
    static bool		enabled() { return _thisExcEnabled; }
protected: // External calls prohibited
    bool		thisExceptionEnabled() const { return _thisExcEnabled; }
private:
    const char *	_name;
    const d_Class *	_classP;
    static bool		_thisExcEnabled;
};

class AS_STORAGE_SPECIFIER AttributeTypeError : public asException
{
public:
    const d_Class &	class_of();
    const d_Attribute &	attribute_of() const { return _attR; }
    ooAsType		formal_type() const { return _formalType; }

    AttributeTypeError(ooAsType,		// formal type
		       const d_Attribute &,
		       const d_Class &);
    virtual void	throw_this() { throw *this; }
    static void		disable() { _thisExcEnabled = false; }
    static void		enable() { _thisExcEnabled = true; }
    static bool		enabled() { return _thisExcEnabled; }
protected: // External calls prohibited
    bool		thisExceptionEnabled() const { return _thisExcEnabled; }
private:
    const d_Attribute &	_attR;
    const d_Class *	_dclassP;
    ooAsType		_formalType;
    static bool		_thisExcEnabled;
};

class AS_STORAGE_SPECIFIER ConstructNumericValueError : public asException
{
public:
    ooBaseType		base_type() const { return _btype; }
    ooBaseType		actual_type() const { return _actualType; }
    ConstructNumericValueError(ooBaseType);
    ConstructNumericValueError(ooBaseType, ooBaseType);
    virtual void	throw_this() { throw *this; }
    static void		disable() { _thisExcEnabled = false; }
    static void		enable() { _thisExcEnabled = true; }
    static bool		enabled() { return _thisExcEnabled; }
protected: // External calls prohibited
    bool		thisExceptionEnabled() const { return _thisExcEnabled; }
private:
    ooBaseType		_btype;
    ooBaseType		_actualType;
    static bool		_thisExcEnabled;
};

class AS_STORAGE_SPECIFIER UnnamedObjectError : public asException
{
public:
    UnnamedObjectError(const char *);
    const char *	context_of() const { return _context; }
    virtual void	throw_this() { throw *this; }
    static void		disable() { _thisExcEnabled = false; }
    static void		enable() { _thisExcEnabled = true; }
    static bool		enabled() { return _thisExcEnabled; }
protected: // External calls prohibited
    bool		thisExceptionEnabled() const { return _thisExcEnabled; }
private:
    const char *	_context;
    static bool		_thisExcEnabled;
};

class AS_STORAGE_SPECIFIER AddProposedPropertyErrorHi : public asException
{
public:
    AddProposedPropertyErrorHi(Proposed_Property *,
			       Proposed_Class *,
			       size_t);			// position
    Proposed_Property &		proposed_property_of() const;
    Proposed_Class &		proposed_embedding_class_of() const;
    size_t			position() const { return _position; }
    virtual void		throw_this() { throw *this; }
    static void			disable() { _thisExcEnabled = false; }
    static void			enable() { _thisExcEnabled = true; }
    static bool			enabled() { return _thisExcEnabled; }
protected: // External calls prohibited
    bool			thisExceptionEnabled() const {
				    return _thisExcEnabled;
				}
private:
    Proposed_Property *		_propPropP;
    Proposed_Class *		_propEmbeddingClP;
    size_t			_position;
    static bool			_thisExcEnabled;
};

class AS_STORAGE_SPECIFIER AddProposedPropertyErrorLo : public asException
{
public:
    AddProposedPropertyErrorLo(Proposed_Property *,
			       Proposed_Class *,
			       size_t);
    Proposed_Property &		proposed_property_of() const;
    Proposed_Class &		proposed_embedding_class_of() const;
    size_t			position() const { return _position; }
    virtual void		throw_this() { throw *this; }
    static void			disable() { _thisExcEnabled = false; }
    static void			enable() { _thisExcEnabled = true; }
    static bool			enabled() { return _thisExcEnabled; }
protected: // External calls prohibited
    bool			thisExceptionEnabled() const {
				    return _thisExcEnabled;
				}
private:
    Proposed_Property *		_propPropP;
    Proposed_Class *		_propEmbeddingClP;
    size_t			_position;
    static bool			_thisExcEnabled;
};

class AS_STORAGE_SPECIFIER AddProposedBaseClassError : public asException
{
public:
    AddProposedBaseClassError(Proposed_Base_Class *,
			      Proposed_Class *,
			      size_t);
    Proposed_Base_Class &	proposed_base_class_of() const;
    Proposed_Class &		proposed_derived_class_of() const;
    size_t			position() const { return _position; }
    virtual void		throw_this() { throw *this; }
    static void			disable() { _thisExcEnabled = false; }
    static void			enable() { _thisExcEnabled = true; }
    static bool			enabled() { return _thisExcEnabled; }
protected: // External calls prohibited
    bool			thisExceptionEnabled() const {
				    return _thisExcEnabled;
				}
private:
    Proposed_Base_Class *	_propBaseClP;
    Proposed_Class *		_propDerClP;
    size_t			_position;
    static bool			_thisExcEnabled;
};

class AS_STORAGE_SPECIFIER CantFindModule : public asException
{
public:
    CantFindModule(const char *);
    const char *	module_name() const { return _moduleName; }
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

class AS_STORAGE_SPECIFIER CantOpenModule : public asException
{
public:
    CantOpenModule(const char *);
    const char *	module_name() const { return _moduleName; }
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

class AS_STORAGE_SPECIFIER NameAlreadyInModule : public asException
{
public:
    NameAlreadyInModule(const char *,		// name
			const char *,		// module
			const char * = NULL);	// namespace
    const char *	class_name() const { return _className; }
    const char *	module_name() const { return _moduleName; }
    const char *	namespace_name() const { return _namespaceName; }
    virtual void	throw_this() { throw *this; }
    static void		disable() { _thisExcEnabled = false; }
    static void		enable() { _thisExcEnabled = true; }
    static bool		enabled() { return _thisExcEnabled; }
protected: // External calls prohibited
    bool		thisExceptionEnabled() const { return _thisExcEnabled; }
private:
    const char *	_className;
    const char *	_moduleName;
    const char *	_namespaceName;
    static bool		_thisExcEnabled;
};

class AS_STORAGE_SPECIFIER NameNotInModule : public asException
{
public:
    NameNotInModule(const char *,		// name
		    const char *,		// module
		    const char * = NULL);	// namespace
    const char *	class_name() const { return _className; }
    const char *	module_name() const { return _moduleName; }
    const char *	namespace_name() const { return _namespaceName; }
    virtual void	throw_this() { throw *this; }
    static void		disable() { _thisExcEnabled = false; }
    static void		enable() { _thisExcEnabled = true; }
    static bool		enabled() { return _thisExcEnabled; }
protected: // External calls prohibited
    bool		thisExceptionEnabled() const { return _thisExcEnabled; }
private:
    const char *	_className;
    const char *	_moduleName;
    const char *	_namespaceName;
    static bool		_thisExcEnabled;
};

class AS_STORAGE_SPECIFIER NameAlreadyProposedInModule : public asException
{
public:
    NameAlreadyProposedInModule(const char *,		// name
				const char *,		// module
				const char * = NULL);	// namespace
    const char *	class_name() const { return _className; }
    const char *	module_name() const { return _moduleName; }
    const char *	namespace_name() const { return _namespaceName; }
    virtual void	throw_this() { throw *this; }
    static void		disable() { _thisExcEnabled = false; }
    static void		enable() { _thisExcEnabled = true; }
    static bool		enabled() { return _thisExcEnabled; }
protected: // External calls prohibited
    bool		thisExceptionEnabled() const { return _thisExcEnabled; }
private:
    const char *	_className;
    const char *	_moduleName;
    const char *	_namespaceName;
    static bool		_thisExcEnabled;
};

class AS_STORAGE_SPECIFIER CantAddModule : public asException
{
public:
    CantAddModule(const char *, uint32, ooAsAddModuleErrorCode);
    const char *		module_name() const { return _name; }
    uint32			module_number() const { return _number; }
    ooAsAddModuleErrorCode	error_code() const { return _errCode; }
    virtual void		throw_this() { throw *this; }
    static void			disable() { _thisExcEnabled = false; }
    static void			enable() { _thisExcEnabled = true; }
    static bool			enabled() { return _thisExcEnabled; }
protected: // External calls prohibited
    bool			thisExceptionEnabled() const {
				    return _thisExcEnabled;
				}
private:
    const char *		_name;
    uint32			_number;
    ooAsAddModuleErrorCode	_errCode;
    static bool			_thisExcEnabled;
};

class AS_STORAGE_SPECIFIER ConvertDeepPositionToInt : public asException
{
public:
    ConvertDeepPositionToInt(size_t);
    virtual void	throw_this() { throw *this; }
    static void		disable() { _thisExcEnabled = false; }
    static void		enable() { _thisExcEnabled = true; }
    static bool		enabled() { return _thisExcEnabled; }
protected: // External calls prohibited
    bool		thisExceptionEnabled() const { return _thisExcEnabled; }
private:
    size_t		_derivedPosition;
    static bool		_thisExcEnabled;
};

class AS_STORAGE_SPECIFIER BadProposedVArrayElementType
    : public asException
{
public:
    BadProposedVArrayElementType(const char *,	// attrName
				 ooAsType,	// type
				 const char *,	// otherClassName
				 d_Access_Kind,	// visibility
				 size_t);	// arraySize
    const char *	proposed_attribute_name() const { return _attrName; }
    ooAsType		proposed_type() const { return _type; }
    const char *	other_class_name() const { return _otherClassName; }
    d_Access_Kind	visibility() const { return _visibility; }
    size_t		array_size() const { return _arrSiz; }
    virtual void	throw_this() { throw *this; }
    static void		disable() { _thisExcEnabled = false; }
    static void		enable() { _thisExcEnabled = true; }
    static bool		enabled() { return _thisExcEnabled; }
protected: // External calls prohibited
    bool		thisExceptionEnabled() const { return _thisExcEnabled; }
private:
    const char *	_attrName;
    ooAsType		_type;
    const char *	_otherClassName;
    d_Access_Kind	_visibility;
    size_t		_arrSiz;
    static bool		_thisExcEnabled;
};

class AS_STORAGE_SPECIFIER InvalidHandle : public asException
{
public:
    InvalidHandle(ooId &);
    ooRef(ooObj) &	reference_object_of() const;
    virtual void	throw_this() { throw *this; }
    static void		disable() { _thisExcEnabled = false; }
    static void		enable() { _thisExcEnabled = true; }
    static bool		enabled() { return _thisExcEnabled; }
protected: // External calls prohibited
    bool		thisExceptionEnabled() const { return _thisExcEnabled; }
private:
    ooId *		_refP;
    static bool		_thisExcEnabled;
};

class AS_STORAGE_SPECIFIER InvalidShape : public asException
{
public:
    ooId &		object_id() const { return *_oidP; }
    ooTypeNumber	shape_number() const { return _shapeNum; }
    const d_Class &	class_of() const;

    InvalidShape(ooId &, ooTypeNumber, const d_Class &);
    virtual void	throw_this() { throw *this; }
    static void		disable() { _thisExcEnabled = false; }
    static void		enable() { _thisExcEnabled = true; }
    static bool		enabled() { return _thisExcEnabled; }
protected: // External calls prohibited
    bool		thisExceptionEnabled() const { return _thisExcEnabled; }
private:
    ooId *		_oidP;
    ooTypeNumber	_shapeNum;
    const d_Class *	_classP;
    static bool		_thisExcEnabled;
};

inline const d_Class &
InvalidShape::class_of() const
{
    return *ooConstCast(const d_Class *, _classP);
}

class AS_STORAGE_SPECIFIER AssignToNullMO : public asException
{
public:
    virtual void	throw_this() { throw *this; }
    AssignToNullMO();
    static void		disable() { _thisExcEnabled = false; }
    static void		enable() { _thisExcEnabled = true; }
    static bool		enabled() { return _thisExcEnabled; }
protected: // External calls prohibited
    bool		thisExceptionEnabled() const { return _thisExcEnabled; }
private:
    static bool		_thisExcEnabled;
};

class AS_STORAGE_SPECIFIER AssignToMO : public asException
{
public:
    const d_Meta_Object &	meta_object_of() const { return *_moP; }
    AssignToMO(const d_Meta_Object &moR);
    virtual void		throw_this() { throw *this; }
    static void			disable() { _thisExcEnabled = false; }
    static void			enable() { _thisExcEnabled = true; }
    static bool			enabled() { return _thisExcEnabled; }
protected: // External calls prohibited
    bool			thisExceptionEnabled() const {
				    return _thisExcEnabled;
				}
private:
    const d_Meta_Object *	_moP;
    static bool			_thisExcEnabled;
};

class AS_STORAGE_SPECIFIER AttributeOutOfRange : public asException
{
public:
    AttributeOutOfRange(size_t, const d_Class &);
    const d_Class &	class_of() const;
    size_t		position_of() const { return _position; }
    virtual void	throw_this() { throw *this; }
    static void		disable() { _thisExcEnabled = false; }
    static void		enable() { _thisExcEnabled = true; }
    static bool		enabled() { return _thisExcEnabled; }
protected: // External calls prohibited
    bool		thisExceptionEnabled() const { return _thisExcEnabled; }
private:
    const d_Class *	_classP;
    size_t		_position;
    static bool		_thisExcEnabled;
};

class AS_STORAGE_SPECIFIER FailedToReopenFD : public asException
{
public:
    const char *	fd_name() const { return _fdName; }
    ooMode		mode() const { return _mode; }
    FailedToReopenFD(const char *, ooMode);
    virtual void	throw_this() { throw *this; }
    static void		disable() { _thisExcEnabled = false; }
    static void		enable() { _thisExcEnabled = true; }
    static bool		enabled() { return _thisExcEnabled; }
protected: // External calls prohibited
    bool		thisExceptionEnabled() const { return _thisExcEnabled; }
private:
    const char *	_fdName;
    ooMode		_mode;
    static bool		_thisExcEnabled;
};

class AS_STORAGE_SPECIFIER FailedToRestartTransaction : public asException
{
public:
    FailedToRestartTransaction(const char *);
    virtual void	throw_this() { throw *this; }
    static void		disable() { _thisExcEnabled = false; }
    static void		enable() { _thisExcEnabled = true; }
    static bool		enabled() { return _thisExcEnabled; }
protected: // External calls prohibited
    bool		thisExceptionEnabled() const { return _thisExcEnabled; }
private:
    static bool		_thisExcEnabled;
};

class AS_STORAGE_SPECIFIER IllegalNumericCompare : public asException
{
public:
    IllegalNumericCompare(const Numeric_Value *, const Numeric_Value *);
    virtual void	throw_this() { throw *this; }
    Numeric_Value &	value0() const { return *_v0P; }
    Numeric_Value &	value1() const { return *_v1P; }
    static void		disable() { _thisExcEnabled = false; }
    static void		enable() { _thisExcEnabled = true; }
    static bool		enabled() { return _thisExcEnabled; }
protected: // External calls prohibited
    bool		thisExceptionEnabled() const { return _thisExcEnabled; }
private:
    Numeric_Value *	_v0P;
    Numeric_Value *	_v1P;
    static bool		_thisExcEnabled;
};

class AS_STORAGE_SPECIFIER IllegalNumericConvert : public asException
{
public:
    IllegalNumericConvert(const Numeric_Value *, ooBaseType);
    virtual void	throw_this() { throw *this; }
    Numeric_Value &	value() const { return *_vP; }
    ooBaseType		destination_type() { return _type; }
    static void		disable() { _thisExcEnabled = false; }
    static void		enable() { _thisExcEnabled = true; }
    static bool		enabled() { return _thisExcEnabled; }
protected: // External calls prohibited
    bool		thisExceptionEnabled() const { return _thisExcEnabled; }
private:
    Numeric_Value *	_vP;
    ooBaseType		_type;
    static bool		_thisExcEnabled;
};

class AS_STORAGE_SPECIFIER InactiveTransactionOpen : public asException
{
public:
    ooId &		object_id() const { return *_oidP; }
    InactiveTransactionOpen(ooId &);
    virtual void	throw_this() { throw *this; }
    static void		disable() { _thisExcEnabled = false; }
    static void		enable() { _thisExcEnabled = true; }
    static bool		enabled() { return _thisExcEnabled; }
protected: // External calls prohibited
    bool		thisExceptionEnabled() const { return _thisExcEnabled; }
private:
    ooId *		_oidP;
    static bool		_thisExcEnabled;
};

class AS_STORAGE_SPECIFIER NotOptimizedStringType : public asException
{
public:
    const d_Type &	type_of() const { return *_typeP; }
    NotOptimizedStringType(const d_Type *);
    virtual void	throw_this() { throw *this; }
    static void		disable() { _thisExcEnabled = false; }
    static void		enable() { _thisExcEnabled = true; }
    static bool		enabled() { return _thisExcEnabled; }
protected: // External calls prohibited
    bool		thisExceptionEnabled() const { return _thisExcEnabled; }
private:
    const d_Type *	_typeP;
    static bool		_thisExcEnabled;
};

class AS_STORAGE_SPECIFIER FailedToCreatePersistentObject
    : public asException
{
public:
    FailedToCreatePersistentObject(const d_Class &,
				   ooRef(ooObj) &nearHandle);
    const d_Class &	class_of() const;
    ooRef(ooObj)	near_handle() const;
    virtual void	throw_this() { throw *this; }
    static void		disable() { _thisExcEnabled = false; }
    static void		enable() { _thisExcEnabled = true; }
    static bool		enabled() { return _thisExcEnabled; }
protected: // External calls prohibited
    bool		thisExceptionEnabled() const { return _thisExcEnabled; }
private:
    const d_Class *	_classP;
    ooRef(ooObj)	_nearH;
    static bool		_thisExcEnabled;
};

class AS_STORAGE_SPECIFIER IllegalCategoryOfClassObject : public asException
{
public:
    const ooId &	oid_of() const;
    IllegalCategoryOfClassObject(const ooId *, uint8);
    bool		is_FD() const;
    bool		is_DB() const;
    bool		is_AP() const;
    virtual void	throw_this() { throw *this; }
    static void		disable() { _thisExcEnabled = false; }
    static void		enable() { _thisExcEnabled = true; }
    static bool		enabled() { return _thisExcEnabled; }
protected: // External calls prohibited
    bool		thisExceptionEnabled() const { return _thisExcEnabled; }
private:
    const ooId *	_oidP;
    uint8		_category;
    static bool		_thisExcEnabled;
};

class AS_STORAGE_SPECIFIER MaxNameLengthExceeded : public asException
{ // Add for SPR 20600
public:
    MaxNameLengthExceeded(const char *, int bitfield);
    const char *	name() const { return _name; }
    int                 which_limit_class_ns_or_mod() const { return _bitfield; }
    virtual void	throw_this() { throw *this; }
    static void		disable() { _thisExcEnabled = false; }
    static void		enable() { _thisExcEnabled = true; }
    static bool		enabled() { return _thisExcEnabled; }
protected: // External calls prohibited
    bool		thisExceptionEnabled() const { return _thisExcEnabled; }
private:
    const char *	_name;
    int                 _bitfield;
    static bool		_thisExcEnabled;
};

static const unsigned int asCode_ServiceError = 15550;
static const unsigned int asCode_FailedToFindClassByNumberError = 15551;
static const unsigned int asCode_ConstructNumericValueError = 15552;
static const unsigned int asCode_UnnamedObjectError = 15553;
static const unsigned int asCode_AddProposedPropertyErrorHi = 15554;
static const unsigned int asCode_AddProposedPropertyErrorLo = 15555;
static const unsigned int asCode_NonHandleClassObject = 15556;
static const unsigned int asCode_ModuleInitError = 15557;
static const unsigned int asCode_CantFindModule = 15558;
static const unsigned int asCode_CantOpenModule = 15559;
static const unsigned int asCode_FailedToRestartTransaction = 15560;
static const unsigned int asCode_NameAlreadyInModule = 15561;
static const unsigned int asCode_NameNotInModule = 15562;
static const unsigned int asCode_NameAlreadyProposedInModule = 15563;
static const unsigned int asCode_ConvertDeepPositionToInt = 15564;
static const unsigned int asCode_InvalidHandle = 15565;
static const unsigned int asCode_AssignToNullMO = 15566;
static const unsigned int asCode_BadVArrayIterator = 15567;
static const unsigned int asCode_EvolutionError = 15568;
static const unsigned int asCode_AttributeTypeError = 15569;
static const unsigned int asCode_ArrayBoundsError = 15570;
static const unsigned int asCode_VArrayBoundsError = 15571;
static const unsigned int asCode_BasicModifyError = 15572;
static const unsigned int asCode_DeletedClassObjectDependency = 15573;
static const unsigned int asCode_BadProposedVArrayElementType = 15574;
static const unsigned int asCode_AddProposedBaseClassError = 15575;
static const unsigned int asCode_InvalidShape = 15576;
static const unsigned int asCode_BadVArrayType = 15577;
static const unsigned int asCode_AccessToManyRelAsToOne = 15578;
static const unsigned int asCode_IterateToOneRel = 15579;
static const unsigned int asCode_SetToManyRelAsToOne = 15580;
static const unsigned int asCode_AddToOneRel = 15581;
static const unsigned int asCode_UnknownRelAccess = 15582;
static const unsigned int asCode_GetAssocError = 15583;
static const unsigned int asCode_SetAssocError = 15584;
static const unsigned int asCode_DelAssocError = 15585;
static const unsigned int asCode_AddAssocError = 15586;
static const unsigned int asCode_SubAssocError = 15587;
static const unsigned int asCode_InitItrError = 15588;
static const unsigned int asCode_ProposedBasicAttributeTypeError = 15589;
static const unsigned int asCode_ProposeVArrayPersistentError = 15590;
static const unsigned int asCode_DefaultValueForUnevolvedClass = 15591;
static const unsigned int asCode_InheritsFromSelfError = 15592;
static const unsigned int asCode_NonPersistentClassObject = 15593;
static const unsigned int asCode_FailedToOpenObject = 15594;
static const unsigned int asCode_WrongStringType = 15595;
static const unsigned int asCode_CantAddNullNamedModule = 15596;
static const unsigned int asCode_CantAddModuleAlreadyExists = 15597;
static const unsigned int asCode_CantAddModule = 15598;
static const unsigned int asCode_AccessDeletedAttribute = 15599;
static const unsigned int asCode_SubFromOneRel = 15600;
static const unsigned int asCode_FailedToFindClassByNameError = 15601;
static const unsigned int asCode_ProposeBadRel = 15602;
static const unsigned int asCode_AttributeOutOfRange = 15603;
static const unsigned int asCode_FailedToReopenFD = 15604;
static const unsigned int asCode_LostNameOfEvolvedClass = 15605;
static const unsigned int asCode_CantFindRelInverse = 15606;
static const unsigned int asCode_AssignToMO = 15607;
static const unsigned int asCode_ProposeEvolutionOfInternal = 15608;
static const unsigned int asCode_AccessDenied = 15609;
static const unsigned int asCode_StringBoundsError = 15610;
static const unsigned int asCode_NewFail = 15611;
static const unsigned int asCode_IllegalNumericCompare = 15612;
static const unsigned int asCode_IllegalNumericConvert = 15613;
static const unsigned int asCode_InactiveTransactionOpen = 15614;
static const unsigned int asCode_NotOptimizedStringType = 15615;
static const unsigned int asCode_WrongCategoryOfNewObject = 15616;
static const unsigned int asCode_ProposeEvolAndVers = 15617;
static const unsigned int asCode_ProposeDynShortRel = 15618;
static const unsigned int asCode_FailedToFindMemberByNameError = 15619;
static const unsigned int asCode_FailedToCreatePersistentObject = 15620;
static const unsigned int asCode_IllegalCategoryOfClassObject = 15621;
static const unsigned int asCode_AlreadyProposedInClass = 15622;
static const unsigned int asCode_MaxNameLengthExceeded = 15623;
static const unsigned int asSET_INVALID_INVERSE = 15624; // OBJY-16847

class AS_STORAGE_SPECIFIER ooSchemaAccessInitializer {
public:
  ooSchemaAccessInitializer();
};
static ooSchemaAccessInitializer __schemaAccessInitializer;

#ifndef OO_NO_NAMESPACE
}
#endif // !OO_NO_NAMESPACE

#endif // ! _OOSCHEMAEXCEPTION_H
