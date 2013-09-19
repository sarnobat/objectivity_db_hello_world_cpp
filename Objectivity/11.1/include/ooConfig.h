/**************************************************************************
		    Copyright (c) 1997-2003 Objectivity, Inc.
			  All Rights Reserved	

	THIS IS UNPUBLISHED PROPRIETARY SOURCE CODE OF OBJECTIVITY, INC.
	
	The copyright notice above does not evidence any	
	actual or intended publication of such source code.

*****************************************************************************/
/*
Product:  Objectivity
Module:   Configuration
File:     ooConfig.h
Content:  configuration
Language: C++/C
Access:   user internal
*/

#ifndef OO_CONFIG_H
#define OO_CONFIG_H "@(#)$Id$"

/* Note that this file is used from C as well as C++, 
   so don't use "//" comments here! */

#include <ooPlatform.h>

/*****************************************************************************/
/*
Exactly one of the following cpp variables is defined, specifying the machine:
	OO_ALPHA
	OO_ALPHANT
	OO_HP9000S700
	OO_I586
	OO_LYNX_PPC_SOL
	OO_IBM_RS6000
	OO_INTEL386
	OO_IA64
	OO_IRIS
	OO_SUN4
	OO_X86_64
Exactly one of the following cpp variables is defined, specifying the OS:
	OO_AIX
	OO_HPUX
	OO_IRIX
	OO_LINUX
	OO_LYNXOS
	OO_NT
	OO_OSF1
	OO_SOLARIS
	OO_SOLARIS7
        OO_MACOS
Exactly one of the following cpp variables is defined, specifying the compiler:
	OO_DEC_CXX
	OO_GNU_CXX
	OO_HP_CXX
	OO_IBM_CXXSET
	OO_MSC_VISUAL_CXX
	OO_SGI_CXXN32
	OO_SPARC_CXX40
	OO_SPARC_CXX50
	OO_SUN_CXX58
	OO_INTEL_CXX
Any of the following cpp variables may be defined or not:
	OO_NO_EH	no exception handling compatibility (not yet used)
	OO_NO_MT	no multi-threading compatibility
	OO_NO_NAMESPACE no namespace support
	OO_PTR_64	memory addresses are 64 bits instead of 32 bits
	OO_NATIVE_PTR_64 native 64-bit data format (not copy-out) 
	OO_STD_IOSTREAM use new streams in std namespace
*/


/*****************************************************************************/
/* Machine dependent stuff. */

/* Some Machiens are big-endian, others small-endian. */
#if defined(OO_HP9000S700) || defined(OO_IBM_RS6000) || defined(OO_LYNX_PPC_SOL) || defined(OO_IRIS) || defined(OO_SUN4)
#define OO_BIG_ENDIAN
#endif


/*****************************************************************************/
/* OS dependent stuff. */

/* Not all OS's support threads. */
#if !defined(OO_NO_MT) && (defined(OO_SOLARIS) || defined(OO_SOLARIS7) || defined(OO_SOLARIS10) || defined(OO_NT) || defined(OO_OSF1) || defined(OO_IRIX) || defined(OO_AIX) || defined(OO_LINUX) || defined(OO_LYNXOS) || (OO_HPUX >= 11) || defined(OO_MACOS))
#define OO_THREAD_SUPPORT
#endif


/*****************************************************************************/
/* Compiler dependent stuff. */

/* All current compilers support templates. */
#define OO_CPLUSPLUS_TEMPLATES

/* The Microsoft C++ compiler has trouble with macro(..,(),..). */
#ifdef OO_MSC_VISUAL_CXX
#define OO_NULL_CONSTRUCTOR
#else
#define OO_NULL_CONSTRUCTOR ()
#endif


/* Microsoft DLLs require different declarations when exported or imported. */
#ifndef OO_STORAGE_SPECIFIER
#if defined(OO_OO_DLL) || (defined(_DLL) && !defined(OO_OO_NO_DLL)) /*{*/
#define OO_STORAGE_SPECIFIER __declspec(dllimport)
#else
#define OO_STORAGE_SPECIFIER
#define OO_STORAGE_SPECIFIER_IS_NULL
#endif
#endif

#ifndef DB_STORAGE
#if defined(OO_OO_DLL) || (defined(_DLL) && !defined(OO_OO_NO_DLL)) /*{*/
#define DB_STORAGE  __declspec(dllimport)
#else
#define DB_STORAGE
#endif
#endif

#ifdef OO_BUILD /* for Objectivity builds; users can make their own choice */
#if !defined(_CRT_SECURE_NO_DEPRECATE) && (_MSC_VER >= 1400)
/* suppress warnings about "unsafe" string functions */
#define _CRT_SECURE_NO_DEPRECATE
#endif

#if !defined(_CRT_SECURE_NO_WARNINGS) && (_MSC_VER >= 1400)
/* suppress warnings about "unsafe" string functions (newer way) */
#define _CRT_SECURE_NO_WARNINGS
#endif
#endif

/* Not all compilers support placement delete operators yet. */
/* (Some compilers require this to avoid warnings, but for correctness, we
    should use it on all that support it; see SPR 16006.)
   Sun compilers before version 5.9 do support this, but occasionally generate
   incorrect code; users could define the flag at their own risk.  */
#if defined(OO_DEC_CXX) || defined(OO_DDL_TRANSLATION) || defined(OO_MSC_VISUAL_CXX) || defined(OO_INTEL_CXX) || (__SUNPRO_CC >= 0x590) || (OO_GNU_CXX >= 3) || (defined(OO_HP_CXX) && defined(OO_IA64))
#define OO_PLACEMENT_DELETE
#endif

#ifdef OO_STD_IOSTREAM
#define OO_STD std::
#else
#define OO_STD
#endif

/* Not all compilers support modern C++ cast operators yet. */
#if defined(__cplusplus) && ( __cplusplus >= 199711L || _MSC_VER-0 >= 1200 )
#define ooReinterpretCast(type, expression) \
    (reinterpret_cast< type >(expression))
#define ooStaticCast(type, expression) \
    (static_cast< type >(expression))
#define ooConstCast(type, expression) \
    (const_cast< type >(expression))
#else
#define ooReinterpretCast(type, expression) \
    ((type) (expression))
#define ooStaticCast(type, expression) \
    ((type) (expression))
#define ooConstCast(type, expression) \
    ((type) (expression))
#endif

#ifdef __cplusplus /* features not applicable to C */

/* The C++ keyword `explicit' is not supported by some older compilers. */
#if defined(OO_SPARC_CXX40) || defined(OO_IBM_CXXSET)
#define ooExplicit 
#else
#define ooExplicit explicit
#endif

#if defined(OO_DDL_TRANSLATION)
#define ooTemplateSpecialization
#else
/* Not all compilers support modern C++ template specialization syntax yet. */
#if defined(OO_HP_CXX) || \
    (defined(OO_IRIS) && defined(_STANDARD_C_PLUS_PLUS)) || \
    (defined(OO_MSC_VISUAL_CXX) && _MSC_VER > 1100) || \
    defined(OO_SPARC_CXX50) || defined(OO_SUN_CXX58) || \
    (defined(__xlC__) && __xlC__ >= 0x0500) || \
    (defined(OO_LINUX) && OO_GNU_CXX >= 3) || \
    (defined(OO_MACOS) && OO_GNU_CXX >= 3)
#define ooTemplateSpecialization template<>
#else
#define ooTemplateSpecialization
#endif
#endif

#if !defined(__xlC__) || __xlC__ >= 0x0500
#define ooExplicitTemplateInstantiation template class
#else
#define ooExplicitTemplateInstantiation class
#endif

#ifdef __cplusplus_cli
#define OO_CLI_PUBLIC public
#else
#define OO_CLI_PUBLIC
#endif

#endif /* end __cplusplus */

#if defined(OO_SPARC_CXX50) || defined(OO_SUN_CXX58) || defined(OO_HP_CXX) || defined(OO_GNU_CXX) || defined(OO_INTEL_CXX) || defined(OO_IBM_CXXSET) || defined(OO_MSC_VISUAL_CXX)
#define ooStaticInline static inline
#define ooExternInline extern inline
#else
#define ooStaticInline inline
#define ooExternInline inline
#endif

/* OO_ALWAYS_INLINE - inline even when doing a non optimized build */
#if (defined(OO_GNU_CXX) || defined(OO_HP_CXX) || defined(OO_INTEL_CXX)) && !defined(OO_DDL_TRANSLATION)
#define OO_ALWAYS_INLINE __attribute__((always_inline))
#else
#define OO_ALWAYS_INLINE
#endif

/* OO_FORCE_INLINE - tell compiler that we defenitly want some function be inlined */
#ifdef OO_MSC_VISUAL_CXX
#define OO_FORCE_INLINE __forceinline
#else
#define OO_FORCE_INLINE inline
#endif

/* parameter modifier "restrict" is new in C99 */
#if 0 /* none of the compilers accept this yet. */
#define OO_RESTRICT restrict
#else
#define OO_RESTRICT
#endif

/*****************************************************************************/
/* Language (C++/ANSI-C/K&R-C) dependent stuff. */

#ifdef __cplusplus /*{*/

/* C++ */
#define ooExternC               extern "C"
#define ooBeginExternC		ooExternC {
#define ooEndExternC		}
#define ooProto(arglist)	arglist
#define ooNoArg
#define ooConst			const
typedef void *			ooVoidPtr;

#else /*!defined(__cplusplus)*//*}{*/
#if defined(__STDC__) || defined(OO_MSC_VISUAL_CXX) /*{*/
/*__STDC__ is currently false for some compilers due to K&R compatibility. */
/*}#if (defined(__STDC__) && __STDC__) || defined(OO_MSC_VISUAL_CXX) / *{*/

/* ANSI C */
#define ooExternC               extern
#define ooBeginExternC
#define ooEndExternC
#define ooProto(arglist)	arglist
#define ooNoArg			void
#define ooConst			const
typedef void *			ooVoidPtr;

#else /*!((defined(__STDC__)&&__STDC__) || defined(OO_MSC_VISUAL_CXX))*//*}{*/
  
/* K&R C */
#define ooExternC               extern
#define ooBeginExternC		
#define ooEndExternC		
#define ooProto(arglist)	()
#define ooNoArg
#define ooConst
typedef char *			ooVoidPtr;

#endif /*!((defined(__STDC__)&&__STDC__) || defined(OO_MSC_VISUAL_CXX))*//*}*/
#endif /*!defined(__cplusplus)*//*}*/


/*****************************************************************************/
/* C preprocessor dependent stuff */


#if defined(__STDC__) || defined(__cplusplus) || defined(OO_MSC_VISUAL_CXX) /*{*/
/*__STDC__ is currently false for some compilers due to K&R compatibility. */
/*} #if (defined(__STDC__) && __STDC__) || defined(__cplusplus) || defined(OO_MSC_VISUAL_CXX) / *{*/

#define ooQuote(x)		#x
#define ooConcat2(a,b)		_ooConcat2_(a,b)
#define _ooConcat2_(a,b)	a##b
#define ooConcat3(a,b,c)	_ooConcat3_(a,b,c)
#define _ooConcat3_(a,b,c)	a##b##c
#define ooConcat4(a,b,c,d)	_ooConcat4_(a,b,c,d)
#define _ooConcat4_(a,b,c,d)	a##b##c##d

#else
      /*!((defined(__STDC__) && __STDC__) ||
	  defined(__cplusplus) ||
	  defined(OO_MSC_VISUAL_CXX))*//*}{*/
#ifdef BSD /*{*/

#define ooQuote(x)		"x"
#define ooConcat2(a,b)		a\
b
#define ooConcat3(a,b,c)	a\
b\
c
#define ooConcat4(a,b,c,d)	a\
b\
c\
d

#else /*!defined(BSD)*//*}{*/

#define ooQuote(x)		"x"
#define ooConcat2(a,b)		a/**/b
#define ooConcat3(a,b,c)	a/**/b/**/c
#define ooConcat4(a,b,c,d)	a/**/b/**/c/**/d

#endif /*!defined(BSD)*//*}*/
#endif
       /*!((defined(__STDC__) && __STDC__) ||
	   defined(__cplusplus) ||
	   defined(OO_MSC_VISUAL_CXX))*//*}*/


/*****************************************************************************/
/* Primitive types. */


typedef char                ooChar;
typedef signed char         ooInt8;
typedef unsigned char       ooUInt8;
typedef short int           ooInt16;
typedef unsigned short int  ooUInt16;
typedef int                 ooInt32;
typedef unsigned int        ooUInt32;

#ifdef OO_MSC_VISUAL_CXX
#define OO_NATIVE_INT_64
typedef __int64             ooInt64;
typedef unsigned __int64    ooUInt64;
#else
  /* Note: on 64-bit Macintosh, "long" and "long long" are both 64 bits,
     but use "long long" for consistency and compatibility with system 
     header types such as __uint64_t and uint64_t.  (SPR 20531) */
#if defined(OO_DEC_CXX) || (defined(__LP64__) && !defined(OO_MACOS))
#define OO_NATIVE_INT_64
typedef long                ooInt64;
typedef unsigned long       ooUInt64;
#else
#if defined(OO_SPARC_CXX40) || \
    defined(OO_SPARC_CXX50) || \
    defined(OO_SUN_CXX58) || \
    defined(OO_SGI_CXXN32) || \
    defined(OO_HP_CXX) || \
    defined(OO_GNU_CXX) || \
    defined(OO_IBM_CXXSET)
#define OO_NATIVE_INT_64
#if defined(OO_GNU_CXX) && !defined(OO_DDL_TRANSLATION)
__extension__ typedef long long           ooInt64;
__extension__ typedef unsigned long long  ooUInt64;
#else
typedef long long           ooInt64;
typedef unsigned long long  ooUInt64;
#endif
#else
#ifdef OO_BIG_ENDIAN
typedef struct ooInt64 {
  ooInt32   high;
  ooUInt32  low;
} ooInt64;
typedef struct ooUInt64 {
  ooUInt32  high;
  ooUInt32  low;
} ooUInt64;
#else
typedef struct ooInt64 {
  ooUInt32  low;
  ooInt32   high;
} ooInt64;
typedef struct ooUInt64 {
  ooUInt32  low;
  ooUInt32  high;
} ooUInt64;
#endif
#endif
#endif
#endif

#if defined(_MSC_VER) && _MSC_VER < 1300
#define OO_INT64_LITERAL(n) n##i64
#else
#define OO_INT64_LITERAL(n) n##LL
#endif

typedef float               ooFloat32;
typedef double              ooFloat64;


#ifdef OO_PTR_64
typedef ooUInt64 ooAddress;
#else
typedef ooUInt32 ooAddress;
#endif


/* AIX 4.3 defines int8, int16, int32 and int64 in <inttypes.h>, which
   should be accessed through <sys/types.h> */
#ifdef OO_AIX
#include <sys/types.h>
#else
typedef ooInt8     int8;
typedef ooInt16    int16;
#endif

typedef ooUInt8    uint8;
typedef ooUInt16   uint16;

#ifdef OO_USE_RPC_INTS
/* Some systems define int32, uint32, int64, and uint64 in rpc/types.h. */
#include <rpc/types.h>
#else
#ifndef OO_AIX
typedef ooInt32    int32;
typedef ooInt64    int64;
#endif
typedef ooUInt32   uint32;
typedef ooUInt64   uint64;
#endif

typedef ooFloat32  float32;
typedef ooFloat64  float64;

#if !defined(OO_DDL_TRANSLATION)
#  if defined(OO_IBM_CXXSET) || (_MSC_VER > 1310)
/* wchar_t is a keyword representing a 16-bit type */
#    define OO_WCHAR_16
#if defined(_MSC_VER)
#include <wchar.h>
#endif
typedef wchar_t ooChar16;
typedef ooUInt32 ooChar32;
#  else /* for: !OO_IBM_CXXSET */
#    if defined(_MSC_VER)
/* wchar_t is 16 bits, but not distinct from unsigned short */
#      define OO_WCHAR_16
typedef ooUInt32 ooChar32;
#    else /* for: !OO_MSC_VISUAL_CXX (&& !OO_IBM_CXXSET) */
/* other platforms define wchar_t as 32 bits, but ooChar16 is always 16. */
/* Using #define instead of typedef because wchar_t may be defined later. */
#      define ooChar32 wchar_t
#    endif /* OO_MSC_VISUAL_CXX (else) */
typedef ooUInt16 ooChar16;
#  endif /* OO_IBM_CXXSET (else) */
#endif /* !OO_DDL_TRANSLATION */

#if      !defined( __cplusplus ) ||  \
         defined( OO_SPARC_CXX40 ) ||  \
         (defined( OO_IBM_CXXSET ) && __xlC__ < 0x500) || defined( OO_LYNXOS )
#  if    !defined( OO_DDL_TRANSLATION )
    typedef unsigned char ooBoolean; /* Now a proper ooddlx type keyword */
#  endif /* !OO_DDL_TRANSLATION */
#  define oocTrue ((ooBoolean) (1))
#  define oocFalse ((ooBoolean) (0))
#elif    defined( OO_DDL_TRANSLATION )
         /* also: __cplusplus && !OO_SPARC_CXX40 &&
	    (!OO_IBM_CXXSET || __xlC__ >= 0x500) && !OO_LYNXOS */
  /* Use constants instead of macros for the values so that the names will
   be passed through. */
  const ooBoolean oocTrue  = ((ooBoolean) (1));
  const ooBoolean oocFalse = ((ooBoolean) (0));
#else    /* for: !OO_DDL_TRANSLATION & __cplusplus && !OO_SPARC_CXX40 &&
	    (!OO_IBM_CXXSET || __xlC__ >= 0x500) && !OO_LYNXOS */
  /* Where bool is defined as one byte, use that. */
  typedef bool ooBoolean;
#  define oocTrue true
#  define oocFalse false
#endif   /* !__cplusplus || OO_SPARC_CXX40 ... (else) */

#if defined(_MSC_VER) && _MSC_VER < 1300
// VC6.0++ emits these warnings
//#pragma warning(disable: 4251)
#pragma warning(disable: 4273)
//#pragma warning(disable: 4275)
#endif

#endif
