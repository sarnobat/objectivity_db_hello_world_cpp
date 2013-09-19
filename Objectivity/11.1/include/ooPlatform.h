
#define OO_MACOS
#define OO_I586
#define OO_INTEL386
#define OO_GNU_CXX 4
#define OO_STD_IOSTREAM

#if defined(OO_DDL_TRANSLATION)
#define __attribute__(x)
#define __asm(x)

/* more type traits used in headers for gcc 4.5 (OBJY-17887) */
#define __is_empty(x) false /* used in bits/allocator.h */
class oo_dummy_typeof_result;
#define __typeof__(x) oo_dummy_typeof_result  /* used in ext/type_traits.h */
#define __is_pod(t) true    /* used in bits/stl_tree.h */
#endif

#if defined(_LP64)

/* Objectivity platform definitions specific to 64Bit builds */
#define OO_ARCH_VERS "Architecture: x86_64"
#define OO_OS_VERS "OS: Mac OS X"
#define OO_X86_64
#define OO_PTR_64
#define OO_NATIVE_PTR_64

#else

/* Objectivity platform definitions specific to 32Bit builds */
#define OO_ARCH_VERS "Architecture: x86"
#define OO_OS_VERS "OS: Mac OS X"

#endif
