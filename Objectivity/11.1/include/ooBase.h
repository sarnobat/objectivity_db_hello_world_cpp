/**************************************************************************
	    Copyright (c) 1989-2002, 2004, 2007 Objectivity, Inc.
			  All Rights Reserved

	THIS IS UNPUBLISHED PROPRIETARY SOURCE CODE OF OBJECTIVITY, INC.

	The copyright notice above does not evidence any
	actual or intended publication of such source code.

*****************************************************************************/

#ifndef OO_BASE_H
#define OO_BASE_H "@(#)$Id$"

/* This file is for declarations that are needed in both the C++ public API
   and in lower-level internal components that don't include "oo.h".
   (Use "ociBase.h" instead for things that are only referenced internally.)
 */

#include <ooConfig.h>
#include <stdio.h>

#ifndef __cplusplus
#error "C++ header being compiled in C mode"
#endif

#if defined(_MSC_VER) && !defined(OO_DDL_TRANSLATION)
#pragma pack(push,8)
#endif

const unsigned ooMaxComparisonArraySize = 250;
const unsigned ooMinPageSizePreR9 = 512;
const unsigned ooMinPageSize = 1024;
const unsigned ooMaxPageSize = 0x10000; // 64K (see SPR 15892)
const unsigned ooDefaultMinBufferSpace = 5000000; // currently 5 MB
const unsigned ooDefaultMaxBufferSpace = 100000000; // currently 100 MB
const unsigned ooDefaultMinPages = 222; // flags to use ooDefaultMinBufferSpace (initial buffer memory size)
const unsigned ooDefaultMaxPages = 9999; // flags to use ooDefaultMaxBufferSpace (max buffer memory size)

const unsigned oocDefaultMaxOpenFiles = 12; // number of files open per session

#define  OOMDEL_DONT_REMOVE_BIASSOC     0
#define  OOMDEL_REMOVE_BIASSOC          1

#define oocSuccess		((ooStatus) 1)
#define oocError		((ooStatus) 0)

#define oocNoWait		0
#define oocWait			-1
#define oocTransNoWait	-12753

#define oocAssocUnknown		0
#define oocAssoc_11		1     /* bidirectional one-to-one */
#define oocAssoc_1n		2     /* bidirectional one-to-many */
#define oocAssoc_n1		3     /* bidirectional many-to-one */
#define oocAssoc_nn		4     /* bidirectional many-to-many */
#define oocUssoc_1		5     /* unidirectional to-one */
#define oocUssoc_n		6     /* unidirectional to-many */

#define oocSAssoc_11	7     /* short bidirectional one-to-one */
#define oocSAssoc_1n	8     /* short bidirectional one-to-many */
#define oocSAssoc_n1	9     /* short bidirectional many-to-one */
#define oocSAssoc_nn	10    /* short bidirectional many-to-many */
#define oocSUssoc_1		11    /* short unidirectional to-one */
#define oocSUssoc_n		12    /* short unidirectional to-many */

#define oocMapInitHashBinSize	11
#define oocMapMaxAvgDensity	5
#define oocMapPercentGrow	100

#define oocVArrayNotExist	0xffff
#define oocVArrayNotOpen	0xfffe

#define oocNoTimestamp		0xffffffff

#define ooGetMemberOffset(type,identifier)		\
    ((unsigned long)(&(((type *) 0)->identifier)))

#define ooGetMemberSize(type,identifier)		\
    (sizeof(((type *) 0)->identifier))

// Values for the _state field of ooHandleBase:
#define oocHandlePTR	0  // handle points to open object (or null)
#define oocHandleOID	1  // closed handle with OID of object
#define oocHandleFD	2  // FD handle */
#define oocHandleDB	3  // DB handle */
#define oocHandleAP	4  // AP handle */

typedef int32	ooStatus;
typedef uint32	ooTypeNumber;
typedef uint32	ooAssocNumber;
typedef uint32	ooMemberID;
typedef uint32	ociTypeNumber;
typedef uint32	ociAssocId;

const int ooUniqueIdLength = 4;
typedef uint32 ooUniqueId[ooUniqueIdLength]; // used by ooFederation and ootools::backup

typedef enum {
    oocNoOpen = 0,	  /* used in iteration, only ooIdBase is returned */
    oocIRead   = 4,	  /* open for read */
    oocReadOnly = 1,      /* open for read only, same as oocRead in R1.1 */
    oocRead = 1,
    oocIUpdate = 5,       /* open for update */
    oocUpdate = 2,        /* open for exclusive update */
    oocXUpdate = 3,
    oocNoMROW = 0,        /* no MROW mode */
    oocMROW = 8,          /* MROW mode */
    oocBackup = 2,        /* special MROW mode for backup/oogc transactions only */ 
    oocMROWIfAllowed = 9, /* not supported; don't use */
    oocErrorOpen = 10
} ooMode;

typedef enum {
    oocCloseOnly = 0,		/* normal close mode */
    oocUnlock,			/* close and unlock a container */
    oocErrorClose
} ooCloseMode;

typedef enum {
    oocLockRead = 0,		/* lock for read */
    oocLockUpdate,		/* lock for update */
    oocErrorLock,
	oocLockExclusiveUpdate	/* SPR 15900 -- support for exclusive update lock on database */
} ooLockMode;

typedef enum {
    oocNoDowngrade = 0,
    oocDowngradeAll
} ooDowngradeMode;		/* commitAndHold() downgrade options */

typedef enum {
    oocNoVers = 0,		/* no versioning */
    oocLinearVers ,		/* linear versioning */
    oocBranchVers,		/* branch versioning */
    oocErrorVers
} ooVersMode;

typedef enum {
    oocIgnore,			/* ignore offline status of APs */
    oocEnforce			/* enforce offline status of APs */
} ooOfflineMode;

typedef enum {
    oocLocal = 0,		/* local file name */
    oocNative = 0,		/* local file name */
    oocHost = 1,		/* host:localPath file name */
    oocHostLocal = 1,		/* host:localPath file name */
    oocErrorFormat
} ooFileNameFormat;

typedef enum {
    oocHandleToNull = 0,	/* change handle to NULL */
    oocHandleToOID,		/* change handle to ooIdBase */
    oocErrorHandle
} ooHandleMode;

typedef enum {
    oocPublic = 0,		/* public data member */
    oocAll,			/* protected/private data member to be exposed */
    oocErrorAccess
} ooAccessMode;

enum ooAvailability { /* availability of a replicated database */
  oocUnknownAvailability = -1,   /* unknown; error */
  oocUnavailable = 0,            /* no available images */
  oocNonQuorumReadAvailable = 1, /* at least one available, but not quorum */
  oocQuorumAvailable = 2,        /* quorum of images available, but not all */
  oocAllAvailable = 3            /* all images available */
};

typedef enum {
    oocTypeNONE             = 0,	/* used by Index Interface           */
    oocTypeCHAR             = 1,        /* WARNING: DO NOT CHANGE THE ORDER  */
    oocTypeINT8             = 2,        /* of these enums as they are stored */
    oocTypeUINT8            = 3,        /* persistently by DBs with indexes. */
    oocTypeINT16            = 4,
    oocTypeUINT16           = 5,
    oocTypeINT32            = 6,
    oocTypeUINT32           = 7,
    oocTypeFLOAT32          = 8,
    oocTypeFLOAT64          = 9,
    oocTypeCHAR_PTR         = 10,
    oocTypeFUNCTION_PTR     = 11,
    oocTypeVTABLE_PTR       = 12,
    oocTypePTR              = 13,
    oocTypeDEFAULT_VARRAY   = 14,
    oocTypeVARRAYCHAR       = 15,
    oocTypeVARRAYCHAR_fixed = 16,
    oocTypeVSTRING          = 17,
    oocTypeVSTRING_fixed    = 18,
    oocTypeSTRING           = 19,
    oocTypeSTRING_fixed     = 20,
    oocTypeUTF8STRING       = 21,
    oocTypeUTF8STRING_fixed = 22,
    oocTypeINT64            = 23,
    oocTypeUINT64           = 24,
    oocTypeCHAR16           = 25,
    oocTypeCHAR32           = 26,
    oocTypeBOOLEAN          = 27,
    oocTypeVARRAYCHAR16       = 28,// 28-35 added for indexing wchar strings
    oocTypeVARRAYCHAR16_fixed = 29,
    oocTypeVARRAYCHAR32       = 30,
    oocTypeVARRAYCHAR32_fixed = 31,
    oocTypeUTF16STRING       = 32,
    oocTypeUTF16STRING_fixed = 33,
    oocTypeUTF32STRING       = 34,
    oocTypeUTF32STRING_fixed = 35
} ooBaseType;

typedef enum {
    oocNoRelatOp = 0,
    oocLT,			/* Less Than.			*/
    oocLE,			/* Less Than or Equal to.	*/
    oocEQ,			/* Equal to.			*/
    oocGT,			/* Greater Than.		*/
    oocGE			/* Greater Than or Equal to.	*/
} ooRelatOp;

typedef enum {			/* used by query */
    qrycTrue = 1,
    qrycFalse = 0,
    qrycNull = -1
} qryTruthValue;

/* Key object */

typedef enum {
    oocUint16,			/* 16 bit unsigned */
    oocUint32,			/* 32 bit unsigned */
    oocUint64,			/* 64 bit unsigned */
    oocInt16,			/* 16 bit signed */
    oocInt32,			/* 32 bit signed */
    oocInt64,			/* 64 bit signed */
    oocString,			/* string type */
    oocCharArray,		/* character array */
    oocErrorKeyType
} ooKeyType;

typedef struct {
    ooKeyType	type;		/* key type */
    uint32	offset;		/* key offset from the start of the object */
    uint32	size;		/* length in number of bytes */
    void *	value;		/* pointer to the key value */
} ooKey;


enum ooIndexOp {
	oocIOpInsert = 3,		/* Inserting an index object.	*/
	oocIOpUpdate = 4		/* Updating an index object.	*/
};
typedef enum ooIndexOp ooIndexOp;

enum ooIndexMode {
	oocTransNoSensitive	= 0,  /* mode not specified in trans */
	oocInsensitive		= 1,
	oocSensitive		= 2,
	oocExplicitUpdate	= 3
};
typedef enum ooIndexMode ooIndexMode;

typedef enum {
    oocAllObjs = 0x3,		/* all objs */
    oocNotTransferred = 0x4,	/* objs whose control is NOT transferred */
      oocInBootAP = oocNotTransferred,		/* old misleading name */
    oocTransferred = 0x5,	/* objs whose control is transferred */
      oocNotInBootAP = oocTransferred		/* old misleading name */
} ooContainsFilter;

typedef enum {
    oocAMSPreferred,	/* use Advanced Multithreaded Server, if available */
    oocAMSOnly,		/* use AMS exclusively */
    oocNoAMS,		/* do not use AMS */
	oocAMSLocalAndRemote /* use it for both local and remote operations */
} ooAMSUsage;

typedef uint32 ooTransId;

typedef enum oo2PCTransState {
    oo2PCTransStateInDoubt = 0,
    oo2PCTransStateCommit,
    oo2PCTransStateAbort
} oo2PCTransState;

typedef enum {
  oocSameId = 1,
  oocSamePage = 2,
  oocOtherPage = 4,
  oocNewPage = 8,
  oocNewContainer = 16,
  oocNewDatabase = 32
} ooClusterPriorities;

const int ooAllButSameId = oocSamePage + oocOtherPage + oocNewPage + oocNewContainer + oocNewDatabase;
/* return value for the 2PC status program */
#define OO_2PC_IN_DOUBT 100
#define OO_2PC_COMMIT 101
#define OO_2PC_ABORT 102

/* arguments to ooTrans::prepare */
#define OO_2PC_TYPE_NONE 0
#define OO_2PC_TYPE_ORBIX_OTS 1
#define OO_2PC_TYPE_XA 2
#define OO_2PC_TYPE_NET 3

/* Offset for putting length and ':' in recovery data for .NET prepare */
#define OO_2PC_NET_OFFSET 2

/* XA encoding needs 256 characters for data plus format and delimiters */
#define OO_2PC_MAX_DATA 268

typedef struct {
    uint32 type;  /* one of the OO_2PC_TYPE_* values above */
    char data[OO_2PC_MAX_DATA]; /* null terminated printable ascii encoding */
} ooExternalTransId;

typedef oo2PCTransState (*ooGlobalTransStatusFunc) (ooExternalTransId *globalTransId);

/*****************************************************************
The following type and macro declarations except those documented
in the reference manual are only for internal system usage.
They are subject to change in any future release.  Do not use them.
*/

/* Forward declarations to avoid nested class by C++ */
class osmBC;
struct oomOCB;
typedef struct otmObjectShape otmObjectShape;
struct ocmSession;

/* Type "oomVCB" places constraints on the location of field "_omField". */
typedef struct osmHandle {
    uint16	_omField;
    uint16	_SN;
    osmBC *_pBc;			/* Buffer control pointer     */
    char	*_pObject;		/* in buffer address	      */
} osmHandle;

/* "VCBH._omField" must be at the same offset as "_pers" in "opiVAheapHK". */
struct OO_STORAGE_SPECIFIER oomVCB {
    osmHandle	   VCBH;		/* must be first field */
    struct oomOCB  *pOCB;		/* ptr-> this VCBs OCB		*/
    struct oomVCB  *pNOpenVCB;
    struct oomVCB  *pPOpenVCB;
};

typedef struct oomOCB {
    struct oomOCB  *pNOpenOCB;
    struct otmObjectShape *ptypeAndOpenMode;
    osmHandle	   OCBH;
} oomOCB;

class OO_STORAGE_SPECIFIER ooIdBase {
// members below for Objectivity internal use only
  public:
    uint16  _DB;
    uint16  _OC;
    uint16  _page;
    uint16  _slot;

    void nullify()
    { _DB = 0; _OC = 0; _page = 0; _slot = 0; }

    ooBoolean isNull() const
    { return (_DB | _OC | _page | _slot) == 0; }
};

class OO_STORAGE_SPECIFIER ooShortIdBase {
  public:
    uint16  _page;
    uint16  _slot;
};

// Base class for ooLongId.
// It is a separate class because:
//  * It has no references to handles, so it can be used by lower-level
//    components that don't include "oo.h".
//  * It has no constructor or assignment operators so it can be
//    used in unions.
// This class is intended for internal use only; use ooLongId instead.
OO_CLI_PUBLIC
class OO_STORAGE_SPECIFIER ooLongIdBase 
{
  protected:
    uint16  _region;
    uint8   _reserved1;
    uint8   _reserved2;
    uint16  _DB;
    uint16  _OC;
    uint16  _page;
    uint16  _slot;
  public:
    unsigned int get_region() const  { return _region; }
    unsigned int get_DB() const	     { return _DB; }
    unsigned int get_OC() const	     { return _OC; }
    unsigned int get_page() const    { return _page; }
    unsigned int get_slot() const    { return _slot; }
    void set_region(uint16 r)  { _region = (uint16) r; }
    void set_DB(uint16 DB)     { _DB = (uint16) DB; }
    void set_OC(uint16 OC)     { _OC = (uint16) OC; }
    void set_page(uint16 page) { _page = (uint16) page; }
    void set_slot(uint16 slot) { _slot = (uint16) slot; }

    void nullify()
	{ _region = _DB = _OC = _page = _slot = 0; }
    ooBoolean isNull() const
	{ return ( _DB | _OC | _page | _slot | _region ) == 0; }
};

class OO_STORAGE_SPECIFIER ooObj;
class OO_STORAGE_SPECIFIER ooId;
class OO_STORAGE_SPECIFIER ooHandleBase;
class OO_STORAGE_SPECIFIER ooShortId;

typedef oomOCB ooOCB;

class OO_STORAGE_SPECIFIER ooObjectTypeFilter
{
  public:
    virtual void cleanup() {}
    virtual ooBoolean passes(char*, ooBoolean, ooTypeNumber,ooTypeNumber) = 0;
};

/* Function pointer declarations */
typedef ooBoolean (*ooIsDeletedType) (ooTypeNumber);
typedef ooStatus (*ooDeleteFunc) (osmHandle*);
typedef void (*ooClearHandlePtr) (ooIdBase*, int, ooHandleBase*);
typedef void (*ooMoveHandlePtr) (ooIdBase*,int,ooHandleBase*,ooHandleBase*);
typedef void (*ooDtPtr) (char*);
typedef void (*ooVoidFuncPtr) ();
typedef void (*ooConversionWrap) (ooIdBase*, ooVoidFuncPtr, void*, void*, void*, void*);
typedef ooRelatOp (*ooRelatOpFuncPtr) (void *, void *);
typedef uint32 (*ooNameHashFuncPtr) (const char*, uint32);

struct ooPtrBase {
    char	*_obj;
    ooOCB	*_ocb;
};

class OO_STORAGE_SPECIFIER oomOpenCloseCatalogs;

// This class is for internal use only; use ooHandle(ooObj) instead.
OO_CLI_PUBLIC
class OO_STORAGE_SPECIFIER ooHandleBase
{
  public: // Objectivity Internal Use Only!
    uint8 _state;
    uint8 _session_id;// session ID for error checking
    uint16 _region; // indicates which FD the ooIdBase is relative to
    ooPtrBase _ptr;
    ooIdBase  _id;
    ooHandleBase *_next;
    ooHandleBase *_prev;

    ooBoolean isNull() const {
#if defined(OO_NATIVE_INT_64) && ( defined(OO_PTR_64) || !defined(__sparc) )
      return (*(uint64*)&_id) == 0;
#else
      return _id.isNull();
#endif
    }
    void nullifyHandleBase() // doesn't close or unlink
    { _state = 0; _region = 0; 
#if defined(OO_NATIVE_INT_64) && ( defined(OO_PTR_64) || !defined(__sparc) )
      *(uint64*)&_id = 0;
#else
      _id.nullify();
#endif
      _ptr._obj = NULL; _ptr._ocb = NULL; }
 
    static ooHandleBase*    createHandleStackDummyHead();
	ocmSession* session() const;
    ooBoolean isGoodPTR() const { return _state == oocHandlePTR && _ptr._ocb;}
	ooStatus closeObj(int ClMode, ocmSession* session);
	ooStatus openObj(ooMode OpenMode, ooBoolean openRedChild, ocmSession* session);
	ooStatus openObj1(ooMode OpenMode, ooBoolean openRedChild, ocmSession* session);
	ooStatus openObj2(ooMode OpenMode, ooBoolean, ocmSession* session, bool requireIndexUpdate = true);
	ooStatus deleteObj(ooClearHandlePtr fncPtr, // f() which cleans up C++ handle stack
		      ooDtPtr destPtr,
          oomOpenCloseCatalogs& cats,// destructor for object
		      uint32 remove_biassoc = OOMDEL_REMOVE_BIASSOC);
	ooStatus do_slower_open(ooMode openMode, ooStatus sm_status, osmHandle *handle_p,
			int flags, int openRedChild, ocmSession* session);
	ooStatus do_version(ocmSession* session);
	ooStatus do_upgrade(ooMode openMode, int flags, ocmSession* session, bool requireIndexUpdate = true);
	ooStatus setHandleBaseFromOCB(oomOCB *pOCB); // doesn't close or link
	void     setHandleBaseFromOID(const ooIdBase* pOID); // doesn't close
	void     setHandleBaseFromOID(const ooLongIdBase* pOID);
	const ooIdBase& getOidFromOpenHandle() const { return _id; }

#if defined(OO_DEBUG) && defined(OO_INTERNAL)
    ooHandleBase() 
     { // Try initializing these fields to invalid values to be sure
       // that they don't need to be initialized.
       *((uint32*)this) = 0xFFFFFFFF;
       _prev = _next = (ooHandleBase*)1;
     }
#endif
};

#define OOM_NULL_HANDLE (ooHandleBase *) 0

#define OCI_NULL_HANDLE (ooHandleBase *) 0
typedef oomVCB	   ooVCB;

/*****************************************************************
Type and association numbers
*/

/* Type numbers for system persistent classes */
const uint32 oocAbstractObjTypeN = 1000;
const uint32 oocObjTypeN = 1001;
const uint32 oocContObjTypeN = 1002;
const uint32 oocFDObjTypeN = 1003;
const uint32 oocDBObjTypeN = 1004;
const uint32 oocDefaultContObjTypeN = 1005;
const uint32 oocCheckOutInfoObjTypeN = 1006;
const uint32 oocGeneObjTypeN = 1007;
const uint32 oocSysIndexTypeN = 1008;
const uint32 oocAPObjTypeN = 1009;

/* Type numbers 2001 through 2114 are used in "tm/otiDDL.ddl"
   and "tm/otiTMI.ddl". */

const uint32 oocMapTypeN = 4001;
const uint32 oocMapElemTypeN = 4002;
/* Type numbers 4010 through 4048 are used in "co/ooCollections.ddl" 
   and "pi/ooCollectionBase.ddl" */
const uint32 oocIndexBaseTypeN = 4098;
const uint32 oocKeyedIndexTypeN = 4099;
const uint32 oocKeyFieldTypeN = 4100;
const uint32 oocIndexDescBaseTypeN = 4101;
const uint32 oocKeyDescTypeN = 4102;
const uint32 oocstring_holderTypeN = 4097;
const uint32 oocIndexContObjTypeN = 4103;

/* Type numbers for system non-persistent classes */
const uint32 oocIdTypeN = 2071;
const uint32 oocShortIdTypeN = 2072;
const uint32 oocLongIdTypeN = 2073;

const uint32 oocIdBaseTypeN = 5001;
const uint32 oocShortIdBaseTypeN = 5002;
const uint32 oocInlineVArrayTypeN = 5003;
const uint32 oocShortInlineVArrayTypeN = 5004;

const uint32 oocVStringTypeN = 5005;
const uint32 oocChar_ooVArrayTypeN = 5006;
const uint32 oocUtf8StringTypeN = 5013;
const uint32 oocLongIdBaseTypeN = 5014;
const uint32 oocUtf16StringTypeN = 5015;
const uint32 oocUtf32StringTypeN = 5016;
const uint32 oocChar16_ooVArrayTypeN = 5020;
const uint32 oocChar32_ooVArrayTypeN = 5021;

/* unused
#define oocMap_ooRefTypeN		5007
#define oocMap_ooShortRefTypeN		5008
*/
const uint32 oocMapBinTypeN = 5009;
/* unused
#define oocMapBin_ooVArrayTypeN		5010
#define oocMapElem_ooRefTypeN		5011
#define oocMapElem_ooShortRefTypeN	5012
#define oocKeyField_ooRefTypeN		5017
#define oocKeyField_ooShortRefTypeN	5018
#define oocKeyField_ooRef_ooVArrayTypeN 5019
#define oocQryStringTypeN		5016
*/
const uint32 ooc_d_TimeTypeN         = 5031;
const uint32 ooc_d_DateTypeN         = 5032;
const uint32 ooc_d_TimestampTypeN    = 5033;
const uint32 ooc_d_IntervalTypeN     = 5034;
const uint32 oocDotNetDateTimeTypeN  = 5035;
const uint32 oocDateTimeTypeN        = 5036;  
const uint32 oocDateTypeN            = 5037;  
const uint32 oocTimeTypeN            = 5038;  
const uint32 oocIntervalTypeN        = 5039;
const uint32 oocDateTimeOffsetTypeN  = 5040;  

/* persistent wrappers for embedded classes */
const uint32 oocVStringHolderTypeN     = 5105;
const uint32 oocUtf8StringHolderTypeN  = 5113;
const uint32 oocUtf16StringHolderTypeN = 5115;
const uint32 oocUtf32StringHolderTypeN = 5116;

/* Type numbers 6001 through 6005 are used in "br/ooJournal.ddl". */
/* Type numbers 7000 through 7200 are used in "ootools/oobackup.ddl". */

const uint32 oocActiveSchema7777 = 7777;

/* Type numbers 8226-8237 were for old query classes */

/* Type numbers for the smalltalk classes */
const uint32 oocGCContObjTypeN = 8500;
const uint32 oocGCRootsContTypeN = 8501;

const uint32 oocSTUInt8VArrayTypeN = 8502;
const uint32 oocSTUInt16VArrayTypeN = 8503;
const uint32 oocSTUInt32VArrayTypeN = 8504;
const uint32 oocSTFloat32VArrayTypeN = 8505;
const uint32 oocSTFloat64VArrayTypeN = 8506;
const uint32 oocSTOoIdVArrayTypeN = 8507;
const uint32 oocSTStringTypeN = 8508;

/* Type numbers 8600-8609 used to be used by oogc */

/* Type numbers for SQL builtin tables */
const uint32 oocsysdbauth = 9000;
const uint32 oocsys_chk_constrs = 9001;
const uint32 oocsys_tbl_constrs = 9002;
const uint32 oocsys_ref_constrs = 9003;
const uint32 oocsys_chkcol_usage = 9004;
const uint32 oocsys_keycol_usage = 9005;
const uint32 oocsyssynonyms = 9006;
const uint32 oocsysviews = 9007;
const uint32 oocsystabauth = 9008;
const uint32 oocsyscolauth = 9009;
const uint32 oocsysidxstat = 9010;
const uint32 oocsystblstat = 9011;
const uint32 oocsyscolstat = 9012;
const uint32 oocsysvarcharstat = 9013;
const uint32 oocsyssmintstat = 9014;
const uint32 oocsysintstat = 9015;
const uint32 oocsysnumstat = 9016;
const uint32 oocsysdatestat = 9017;
const uint32 oocsysfloatstat = 9018;
const uint32 oocsysmoneystat = 9019;
const uint32 oocsystimestat = 9020;
const uint32 oocsysrealstat = 9021;
const uint32 oocsyscharstat = 9022;
const uint32 oocsyststat = 9023;
const uint32 oocsysdatatypes = 9024;
const uint32 oocsyscalctable = 9025;
const uint32 oocsysscopes = 9026;
const uint32 oocsysprocauth = 9027;
const uint32 oocsysdblinks = 9028;
const uint32 oocsysattachtbls = 9029;
const uint32 oocsysproccolumns = 9030;
const uint32 oocsysprocedures = 9031;
const uint32 oocsysproctext = 9032;
const uint32 oocsystrigcols = 9033;
const uint32 oocsystrigger = 9034;

const uint32 oocsqldate = 9070;
const uint32 oocsqltime = 9071;
const uint32 oocsqltimestamp = 9072;
const uint32 oocsqlnumeric = 9073;
const uint32 oocsqlmoney = 9074;
const uint32 oocsqlnull = 9075;
const uint32 oocsqlnull_char_1 = 9076;
const uint32 oocsqlnull_int8 = 9077;
const uint32 oocsqlnull_uint8 = 9078;
const uint32 oocsqlnull_int16 = 9079;
const uint32 oocsqlnull_uint16 = 9080;
const uint32 oocsqlnull_int32 = 9081;
const uint32 oocsqlnull_uint32 = 9082;
const uint32 oocsqlnull_float32 = 9083;
const uint32 oocsqlnull_float64 = 9084;
const uint32 oocsqlnull_date = 9085;
const uint32 oocsqlnull_time = 9086;
const uint32 oocsqlnull_timestamp = 9087;
const uint32 oocsqlnull_numeric = 9088;
const uint32 oocsqlnull_money = 9089;
const uint32 oocsqlnull_int64 = 9090;
const uint32 oocsqlnull_uint64 = 9091;

/* type numbers for java types */
const uint32 oocjint64 = 9100;
const uint32 oocjint32 = 9101;
const uint32 oocjint16 = 9102;
const uint32 oocjint8 = 9103;
const uint32 oocjboolean = 9104;
const uint32 oocjcharacter = 9105;
const uint32 oocjfloat = 9106;
const uint32 oocjdouble = 9107;
const uint32 oocjdate = 9108;
const uint32 oocjtime = 9109;
const uint32 oocjtimestamp = 9110;
const uint32 oocjbiginteger = 9111;
const uint32 oocjbigdecimal = 9112;
const uint32 oocjarrayofobject = 9113;
const uint32 oocjarrayofint64 = 9114;
const uint32 oocjarrayofint32 = 9115;
const uint32 oocjarrayofint16 = 9116;
const uint32 oocjarrayofint8 = 9117;
const uint32 oocjarrayofboolean = 9118;
const uint32 oocjarrayofcharacter = 9119;
const uint32 oocjarrayoffloat = 9120;
const uint32 oocjarrayofdouble = 9121;

/* Type numbers 91000 through 91073 are used in "pi/opiCatalog.ddl" */
/* Type numbers 910x0 are used in "pi/ooCollectionBase.ddl" */

/* C association numbers for system persistent classes */
/* See table in "ootm.h" that specifies the encoding of association numbers. */
const uint32 ociAssocN_nextVers_ooObj = 0x240003e8;
const uint32 ociAssocN_prevVers_ooObj = 0x180003e8;
const uint32 ociAssocN_geneObj_ooObj = 0x140003e9;
const uint32 ociAssocN_defaultToGeneObj_ooObj = 0x340003ea;
const uint32 ociAssocN_derivatives_ooObj = 0x40003ed;
const uint32 ociAssocN_derivedFrom_ooObj = 0x80003ed;
const uint32 ociAssocN_checkoutInfo_ooObj = 0x240003eb;
const uint32 ociAssocN_nameScope_ooObj = 0x40003ec;
const uint32 ociAssocN_nameObj_ooObj = 0x80003ec;
const uint32 ociAssocN_indexes_ooContObj = 0xe40003f0;
const uint32 ociAssocN_checkout_ooCheckOutInfoObj	= 0x180003eb;
const uint32 ociAssocN_allVers_ooGeneObj = 0x280003e9;
const uint32 ociAssocN_defaultVers_ooGeneObj = 0x380003ea;
const uint32 ociAssocN_container_ooSysIndex = 0xd80003f0;
const uint32 ociAssocN_owner_ooObj = 0x140003f2;
const uint32 ociAssocN_owns_ooObj  = 0x280003f2;

#ifndef OO_H  /*{*/

// obsololete code - ???mats

// Declarations used in C++ programs that do not include oo.h.
//#define ooHandle(T) opiHandle<T >
//template<class T>
//class opiHandle;

//class ooObj {
//    int	 (**_vtbl)();
//    char *_assocVArray;
//} ;

//class OO_STORAGE_SPECIFIER ooHandle(ooObj); // forward declaration

#endif	/*!defined(OO_H)*//*}*/

/*****************************************************************
Define ooDeclare and ooImplement.
*/

#define ooDeclare(a,typeName)	ooConcat2(a,declare)(typeName)
#define ooImplement(a,typeName) ooConcat2(a,implement)(typeName)

/*
storage_declare is similar to declare except that it supports an additional
parameter storageSpecifier, intended to be a C preprocessor variable defined
either as a Microsoft C++ storage attribute (eg. __declspec(dllexport)) or
as nothing.

ooStorageDeclare was originally identical to storage_declare.

At some point Dave Hu got confused and changed ooStorageDeclare to not
suppport the storageSpecifier parameter and instead always use the
Objectivity internal storage specifier OO_STORAGE_SPECIFIER, and also
changed storage_declare to ignore its storageSpecifier parameter when
OO_STORAGE_SPECIFIER is defined as nothing.  He should probably instead
have introduced a new macro, perhaps ooStorageSpecifierDeclare with the
semantics of the current ooStorageDeclare.
*/

#ifdef OO_STORAGE_SPECIFIER_IS_NULL
/* 
  SPR 20761 - Remove multi-line comment from ooBase.h
//#define storage_declare(aggregate,typeName,storageSpecifier) \
//    ooConcat2(aggregate,declare)(typeName)
*/
#define ooStorageDeclare(aggregate,typeName) \
    ooConcat2(aggregate,declare)(typeName)
#else
/*
  SPR 20761 - Remove multi-line comment from ooBase.h
//#define storage_declare(aggregate,typeName,storageSpecifier) \
//    ooConcat2(aggregate,sdeclare)(typeName,storageSpecifier)
*/
#define ooStorageDeclare(aggregate,typeName) \
    ooConcat2(aggregate,sdeclare)(typeName,OO_STORAGE_SPECIFIER)
#endif

#if defined(_MSC_VER) && !defined(OO_DDL_TRANSLATION)
#pragma pack(pop)
#endif

#define OO_OID_BUFFER_SIZE 32 // recommended buffer size for sprint

class OO_STORAGE_SPECIFIER ooId : public ooIdBase
{
  public:
    ooId()
	{ _DB = _OC = _page = _slot = 0; }
    ooId(const ooId& id)
	{ _DB = id._DB;	 _OC = id._OC;	_page = id._page;  _slot = id._slot; }
    ooId& operator=(const ooIdBase& id)
	{ _DB = id._DB;	_OC = id._OC;	_page = id._page;  _slot = id._slot;
	  return *this; }
    ooId& operator=(const ooShortId& shortId);
    ooId& operator=(const ooHandleBase& objHandle);
    ooId& operator=(const ooObj *  pObject);
    ooStatus update();
    ooObj* vm(ooMode openMode = oocRead);
    ooObj* pin(ooMode openMode = oocRead) const;
    void unpin() const;
    operator int() const
	{ return (int) (! isNull()); }
    ooBoolean isValid() const;
    unsigned getPageFreeSpace() const;
    ooBoolean operator==(const ooIdBase& id) const
	{  return _slot == id._slot && _page == id._page &&
		  _OC == id._OC && _DB == id._DB; }
    ooBoolean operator!=(const ooIdBase& id) const
	{ return ! operator==(id); }
    ooBoolean operator==(const ooShortId& shortId) const;
    ooBoolean operator!=(const ooShortId& shortId) const;
    ooBoolean operator==(const ooHandleBase& objH) const;
    ooBoolean operator!=(const ooHandleBase& objHandle) const
	{ return ! operator==(objHandle); }
    ooBoolean operator==(const ooObj* pObject) const;
    ooBoolean operator!=(const ooObj* pObject) const
	{ return ! operator==(pObject); }
			/* optional ooBoolean flag for internal use only */
    void print(FILE* fp = stdout, ooBoolean newLine = oocTrue) const;
    char* sprint(char* buf = (char*)NULL) const;
    // Special forms to resolve ambiguities for various C++ translators
    ooBoolean operator==(int  zero) const
	{ return (zero) ? ! isNull(): isNull(); }
    ooBoolean operator!=(int  zero) const
	{ return ! operator==(zero); }
    ooBoolean operator==(short zero) const
	{ return (zero) ? ! isNull(): isNull(); }
    ooBoolean operator!=(short  zero) const
	{ return ! operator==(zero); }
    OO_FORCE_INLINE ooBoolean operator==(long  zero) const
	{ return (zero) ? ! isNull(): isNull(); }
    ooBoolean operator!=(long  zero) const
	{ return ! operator==(zero); }
    ooBoolean operator==(unsigned int  zero) const
	{ return (zero) ? ! isNull(): isNull(); }
    ooBoolean operator!=(unsigned int  zero) const
	{ return ! operator==(zero); }
    ooBoolean operator==(unsigned short  zero) const
	{ return (zero) ? ! isNull(): isNull(); }
    ooBoolean operator!=(unsigned short  zero) const
	{ return ! operator==(zero); }
    ooBoolean operator==(unsigned long  zero) const
	{ return (zero) ? ! isNull(): isNull(); }
    ooBoolean operator!=(unsigned long  zero) const
	{ return ! operator==(zero); }
    /* ooId(const ooHandle(ooObj)& objHandle);
       ooId(const ooObj* pObject);
       These two constructors are not supported.
       Otherwise there is a short path in breaking the type safe handle */
    ooBoolean isOK() const
	{  // PQE ESA uses OC 0 for transient pages belonging to pseudo databases
           return (_DB != 0 && /*_OC != 0 && */ _page != 0) ? oocTrue : oocFalse; }
    uint16 get_DB() const	     { return _DB; }
    uint16 get_OC() const	     { return _OC; }
    uint16 get_page() const	     { return _page; }
    uint16 get_slot() const	     { return _slot; }
    void set_DB(const uint16 db)     { _DB = db; }
    void set_OC(const uint16 cont)     { _OC = cont; }
    void set_page(const uint16 page) { _page = page; }
    void set_slot(const uint16 slot) { _slot = slot; }
};

class OO_STORAGE_SPECIFIER ooShortId : public ooShortIdBase
{
  public:
    ooShortId()
	{ _page = _slot = 0; }
    ooShortId& operator=(const ooShortId& shortId)
	{ _page = shortId._page;  _slot = shortId._slot;  return *this; }
    ooShortId& operator=(const ooId& id)
	{ _page = id.get_page();  _slot = id.get_slot();  return *this; }
    ooShortId& operator=(const ooHandleBase& objHandle);
    ooShortId& operator=(const ooObj *  pObject);
    operator int() const
	{ return (int) (! isNull()); }
    ooBoolean operator==(const ooShortId& shortId) const
	{ return _slot == shortId._slot && _page == shortId._page; }
    ooBoolean operator!=(const ooShortId& shortId) const
	{ return ! operator==(shortId); }
    ooBoolean operator==(const ooId& id) const
	{ return _slot == id.get_slot() && _page == id.get_page(); }
    ooBoolean operator!=(const ooId& id) const
	{ return ! operator==(id); }
    ooBoolean operator==(const ooHandleBase& objH) const;
    ooBoolean operator!=(const ooHandleBase& objHandle) const
	{ return ! operator==(objHandle); }
    ooBoolean operator==(const ooObj* pObject) const;
    ooBoolean operator!=(const ooObj* pObject) const
	{ return ! operator==(pObject); }
			/* optional ooBoolean flag for internal use only */
    void print(FILE* fp = stdout, ooBoolean newLine = oocTrue) const;
    char* sprint(char* buf = (char*)NULL) const;
    /********************************************************************
     *									*
     * Note: The following methods are only for internal system usage.	*
     *	     It is subject to change in any future release.		*
     *	     You are not allowed to use it.				*
     *									*
     ********************************************************************/
    /* ooShortId(const ooId& id);
       ooShortId(const ooHandle(ooObj)& objHandle);
       ooShortId(ooObj* pObject);
       These three constructors are not supported.
       Otherwise there is a short path in breaking the type safe handle */
    /* Use operator=(0) instead */
    /* OBSOLETE */void nullify()
	{ _page = _slot = 0; }
    /* Use operator==(0) instead */
    /* OBSOLETE */ooBoolean isNull() const
	{ return _page == 0 && _slot == 0; }
    // Special forms to resolve ambiguities for various C++ translators
    ooBoolean operator==(int  zero) const
	{ return (zero) ? ! isNull(): isNull(); }
    ooBoolean operator!=(int  zero) const
	{ return ! operator==(zero); }
    ooBoolean operator==(short  zero) const
	{ return (zero) ? ! isNull(): isNull(); }
    ooBoolean operator!=(short  zero) const
	{ return ! operator==(zero); }
    ooBoolean operator==(long  zero) const
	{ return (zero) ? ! isNull(): isNull(); }
    ooBoolean operator!=(long  zero) const
	{ return ! operator==(zero); }
    ooBoolean operator==(unsigned int  zero) const
	{ return (zero) ? ! isNull(): isNull(); }
    ooBoolean operator!=(unsigned int  zero) const
	{ return ! operator==(zero); }
    ooBoolean operator==(unsigned short  zero) const
	{ return (zero) ? ! isNull(): isNull(); }
    ooBoolean operator!=(unsigned short  zero) const
	{ return ! operator==(zero); }
    ooBoolean operator==(unsigned long  zero) const
	{ return (zero) ? ! isNull(): isNull(); }
    ooBoolean operator!=(unsigned long  zero) const
	{ return ! operator==(zero); }
    uint16 get_page() const	     { return _page; }
    uint16 get_slot() const	     { return _slot; }
    void set_page(const uint16 page) { _page = page; }
    void set_slot(const uint16 slot) { _slot = slot; }
};

#ifndef OO_LONG_REF
  #define OO_LONG_REF 1
#endif

#if OO_LONG_REF
/* Warning: this class is not yet fully supported; not all of the
   declared methods are actually defined. */
OO_CLI_PUBLIC
class OO_STORAGE_SPECIFIER ooLongId : public ooLongIdBase 
{
  public:
    ooLongId() { _reserved1 = 0; _reserved2 = 0; nullify(); }
    ooLongId(const ooHandleBase& objHandle);
    ooLongId& operator=(const ooHandleBase& objHandle);
    ooLongId& operator=(const ooLongId& id)
	  { *ooStaticCast(ooLongIdBase*,this) =
	      *ooStaticCast(const ooLongIdBase*, &id);
	    return *this; }

    operator int() const
	{ return (int) (! isNull()); }
    ooBoolean operator==(const ooLongId& id) const
	{  return _slot == id._slot && _page == id._page &&
		  _OC == id._OC && _DB == id._DB && _region == id._region; }
    ooBoolean operator!=(const ooLongId& id) const
	{ return ! operator==(id); }
    ooBoolean operator==(const ooHandleBase& objH) const;
    ooBoolean operator!=(const ooHandleBase& objH) const;
			/* optional ooBoolean flag for internal use only */
    void printl(FILE* fp = stdout, ooBoolean newLine = oocTrue) const;
    char* sprintl(char* buf = (char*)NULL) const;

    // Special forms to resolve ambiguities for various C++ translators
    ooBoolean operator==(int  zero) const
	{ return (zero) ? ! isNull(): isNull(); }
    ooBoolean operator!=(int  zero) const
	{ return ! operator==(zero); }
    ooBoolean operator==(short zero) const
	{ return (zero) ? ! isNull(): isNull(); }
    ooBoolean operator!=(short  zero) const
	{ return ! operator==(zero); }
    ooBoolean operator==(long  zero) const
	{ return (zero) ? ! isNull(): isNull(); }
    ooBoolean operator!=(long  zero) const
	{ return ! operator==(zero); }
    ooBoolean operator==(unsigned int  zero) const
	{ return (zero) ? ! isNull(): isNull(); }
    ooBoolean operator!=(unsigned int  zero) const
	{ return ! operator==(zero); }
    ooBoolean operator==(unsigned short  zero) const
	{ return (zero) ? ! isNull(): isNull(); }
    ooBoolean operator!=(unsigned short  zero) const
	{ return ! operator==(zero); }
    ooBoolean operator==(unsigned long  zero) const
	{ return (zero) ? ! isNull(): isNull(); }
    ooBoolean operator!=(unsigned long  zero) const
	{ return ! operator==(zero); }
};
#endif /* OO_LONG_REF */

OO_STORAGE_SPECIFIER ooStatus ooStartInternalLS(const char* fdname = 0, void (*threadfn)() = 0);
OO_STORAGE_SPECIFIER ooStatus ooStopInternalLS(int wait = (int)(((unsigned)~0)>>1), // INT_MAX
		 ooBoolean force = oocFalse);
OO_STORAGE_SPECIFIER ooBoolean ooCheckLS(const char * host = (char*)NULL);
extern "C" OO_STORAGE_SPECIFIER void otmStealVtbls(ooTypeNumber, char*);
inline void otmStealVtbls(ooTypeNumber t, void* obj)
{ otmStealVtbls(t, (char*) obj); }
OO_STORAGE_SPECIFIER int otmAddToVTableInitList(void (*func)(void));
OO_STORAGE_SPECIFIER void otmSignalInitError(const char *);
OO_STORAGE_SPECIFIER ooAssocNumber otmRegisterAssoc(ooAssocNumber *, ooAssocNumber);

enum oomChoosePartitions_t {
  oocAllPartitions,
  oocAvailablePartitions
};

class osmFileReplDesc;

// An instance of this class implements a single scan over the
// partitions in a federation.
class OO_STORAGE_SPECIFIER oomAPIterator
{
public:
  oomAPIterator(oomChoosePartitions_t option = oocAllPartitions, ocmSession* session = 0);

  // next_ap gets the next LFD ID in the global catalog.
  //
  // returns OOMEOK if the next LFD was successfully found:
  //     The LFD ID is stored in *pLFDID.
  // returns OOMEDONE if there are no more LFDs.
  // returns OOMEFATAL if an error occurred and has been reported.

  ooStatus next_ap(uint16* pLFDID);
  ocmSession* getSession();
  void reset() { at_beginning = oocTrue; }
private:
  ooBoolean  at_beginning;
  oomChoosePartitions_t option;
  osmFileReplDesc * next_replica;
  ocmSession* session;
};

struct d_IteratorBase
{
  void *	vector;
  int		index;		// -1 is "before start".
  unsigned int	max_index;
};

extern "C"
{
	typedef int (*smalltalk_callback)(const ooUInt32, const ooUInt32);
}

#ifndef _JAVASOFT_JNI_H_
#ifdef OO_JAVA
#include <jni.h> // Java Native Interface include file
#else // fake it to avoid dependency of JDK
class _jobject; // forward declaration allows jni.h to be included later.
typedef _jobject* jobject;
struct JNIEnv_;
typedef JNIEnv_ JNIEnv;
#endif
#endif

enum ooDiskFormat {
    oocNoDiskFormat,
    ooc_alphaosf1,
    ooc_alphaosf1_32,
    ooc_altix,
    ooc_hprisc,
    ooc_ibmrs6000,
    ooc_iris,
    ooc_linux86,
    ooc_linux86gcc3,
    ooc_lynxppc,
    ooc_solaris4,
    ooc_solaris7,
    ooc_sparc64,
    ooc_win32,
    ooc_hpuxia64,
    ooc_linux86_64,
    ooc_solaris86_64,
    ooc_win64,
    ooc_mac86gcc,
    ooc_mac86_64
};

OO_STORAGE_SPECIFIER ooDiskFormat opiDiskFormatFromString(const char *);
OO_STORAGE_SPECIFIER const char *opiDiskFormatString(ooDiskFormat);

class OO_STORAGE_SPECIFIER ooEventListener 
{ 
	public: 
	enum ooVArrayType { 
		oocNormalVArray, 
		oocDefaultAssocVArray, 
		oocInlineAssocVArray 
	}; 

        enum ooCollectionIterationKind {
                oocIterateMapKeys,
                oocIterateMapValues,
                oocIterateElements
        };

        // Called when a transaction is started
        virtual void onTransBegin( 
                     const ooTransId tranID); 

        // Called at the beginning of a transaction commit
        virtual void onTransStartCommit( 
                     const ooTransId tranID);  

        // Called when a transaction commit is finished
        virtual void onTransFinishCommit( 
                     const ooTransId tranID);  

        // Called when a transaction is aborted
        virtual void onTransAbort( 
                     const ooTransId tranID);  

        // Called when a database page is read from disk to a buffer
        virtual void onSmallObjectPageRead( 
                     // OID (DB-CO-PN-0) of page
                     const ooId &pageOID, 
                     // Number of small page buffer entries currently in use
                     unsigned numPageBuffersInUse); 

        // Called when a database page is written from a buffer to disk
        virtual void onSmallObjectPageWrite( 
                     // OID (DB-CO-PN-0) of page
                     const ooId &pageOID, 
                     // Number of small page buffer entries currently in use
                     unsigned numPageBuffersInUse);

        // Called when a database page is created in Memory
        virtual void onSmallObjectPageCreate( 
                     // OID (DB-CO-PN-0) of page
                     const ooId &pageOID, 
                     // Number of small page buffer entries currently in use
                     unsigned numPageBuffersInUse, 
                     // size in bytes of the page being created
                     unsigned size, 
                     // architecture format of the page being created
                     // (ooDiskFormat is yet to be defined--probably
                     // should be an enum in ooBase.h).
                     ooDiskFormat diskFormat); 

        // Called when an unmodified page is flushed from the cache
        virtual void onSmallObjectPageDiscard( 
                     // OID (DB-CO-PN-0) of page
                     const ooId &pageOID, 
                     // Number of small page buffer entries currently in use
                     unsigned numPageBuffersInUse); 

         // Called when we allocate more memory space for small objects
        virtual void onSmallObjectPageBufferPoolResize( 
                      // size in bytes of each page in this buffer pool
                      unsigned pageSize, 
                      // number of pages of the buffer pool before resize
                      unsigned fromSize, 
                      // number of pages of the buffer pool after resize
                      unsigned toSize); 

        // Called when a large object is read from disk
        virtual void onLargeObjectPagesRead( 
                     // OID (DB-CO-PN-0) of first page of the large object
                     // and also the OID of the object itself
                     const ooId &firstPageOID, 
                     // large object buffer entries currently in use
                     unsigned numLargeObjBuffersInUse, 
                     // amount of memory space being used by this large object
                     // limited by `ooSetLargeObjectMemoryLimit'
                     unsigned sizeThisObject,             
                     // number of pages used by this large object
                     unsigned numPagesThisObject); 

        // Called when a large object is written to disk
        virtual void onLargeObjectPagesWrite( 
                     // OID (DB-CO-PN-0) of first page of the large object
                     const ooId &firstPageOID, 
                     // large object page buffer entries currently in use
                     unsigned numLargeObjPageBuffersInUse, 
                     // number of pages used by this large object
                     unsigned numPagesThisObject); 

        // Called when a large object is created
        virtual void onLargeObjectPagesCreate( 
                     // OID (DB-CO-PN-0) of first page of the large object
                     const ooId &firstPageOID, 
                     // large object page buffer entries currently in use
                     unsigned numLargeObjPageBuffersInUse, 
                     // number of pages used by this large object
                     unsigned numPagesThisObject); 

        // Called when an unmodified large object is flushed from the cache
        virtual void onLargeObjectPagesDiscard( 
                     // OID (DB-CO-PN-0) of first page of the large object
                     const ooId &firstPageOID, 
                     // large object page buffer entries currently in use
                     unsigned numLargeObjPageBuffersInUse, 
                     // number of pages used by this large object
                     unsigned numPagesThisObject); 

         // Called when we allocate more memory space for large objects
        virtual void onLargeObjectPageBufferPoolResize( 
                     // size in bytes of buffers in this buffer pool
                     unsigned bufferSize, 
                     // number of buffers in the buffer pool before resize
                     unsigned fromSize, 
                     // number of buffers in the buffer pool after resize
                     unsigned toSize); 

        // Called when an object is created
        virtual void onObjectCreate( 
                     // OID (DB-CO-PN-SN) of the object
                     const ooId &OID, 
                     // type (class) number of the object
                     ooTypeNumber typeNumber, 
                     // number of open objects in the object manager
                     // cache including this object
                     unsigned numOpenObjects, 
                     // architecture format of the object on disk
                     // (ooDiskFormat is yet to be defined--probably
                     // should be an enum in ooBase.h).
                     ooDiskFormat diskFormat); 

        // Called when an object is opened
        // NOTE: Does not include re-opening an object that is already open
        //       or creating a new object.
        virtual void onObjectOpen( 
                     // OID (DB-CO-PN-SN) of the object
                     const ooId &OID, 
                     // type (class) number of the object
                     ooTypeNumber typeNumber, 
                     // number of open objects in the object manager
                     // cache including this object
                     unsigned numOpenObjects,
                     // architecture format of the object on disk
                     // (ooDiskFormat is yet to be defined--probably
                     // should be an enum in ooBase.h).
                     ooDiskFormat diskFormat, 
                     // OID of redirected object if object is redirected
                     const ooId &redirectionOID /*= *(ooId*)NULL*/); 

        // Called when an object is closed
        virtual void onObjectClose( 
                     // OID (DB-CO-PN-SN) of the object
                     const ooId &OID, 
                     // type (class) number of the object
                     ooTypeNumber typeNumber, 
                     // number of open objects in the object manager
                     // cache including this object
                     unsigned numOpenObjects); 

        // Called when an object is deleted
        virtual void onObjectDelete( 
                     // OID (DB-CO-PN-SN) of the object
                     const ooId &OID, 
                     // type (class) number of the object
                     ooTypeNumber typeNumber, 
                     // number of open objects in the object manager
                     // cache including this object
                     unsigned numOpenObjects); 

        // Called when an object is resized
        virtual void onObjectResize( 
                     // OID (DB-CO-PN-SN) of the object
                     const ooId &OID, 
                     // type (class) number of the object
                     ooTypeNumber typeNumber, 
                     // number of open objects in the object manager
                     // cache including this object
                     unsigned numOpenObjects, 
                     // size of the object in bytes before resize
                     unsigned oldSize, 
                     // size of the object in bytes after resize
                     unsigned newSize, 
                     // OID of redirected object if object is redirected
                     const ooId &redirectionOID); 

        // Called when a VArray is created
        virtual void onVarrayCreate( 
                     // OID (DB-CO-PN-SN) of the VArray
                     const ooId &OID, 
                     // number of elements allocated
                     unsigned numElements, 
                     // size in bytes of an element on the running architecture
                     unsigned elementSize, 
                     // one of: oocNormalVArray, oocDefaultAssocVArray,
                     // or oocInlineAssocVArray
                     ooVArrayType VArrayType, 
                     // architecture format of the object on disk
                     // (ooDiskFormat is yet to be defined--probably
                     // should be an enum in ooBase.h).
                     ooDiskFormat diskFormat); 

        // Called when a VArray is opened
        virtual void onVarrayOpen( 
                     // OID (DB-CO-PN-SN) of the VArray
                     const ooId &OID, 
                     // number of elements allocated
                     unsigned numElements, 
                     // size in bytes of an element on the running architecture
                     unsigned elementSize, 
                     // architecture format of the object on disk
                     // (ooDiskFormat is yet to be defined--probably
                     // should be an enum in ooBase.h).
                     ooDiskFormat diskFormat); 

        // Called when a VArray is closed
        virtual void onVarrayClose( 
                     // OID (DB-CO-PN-SN) of the VArray
                     const ooId &OID, 
                     // number of elements allocated
                     unsigned numElements, 
                     // size in bytes of an element on the running architecture
                     unsigned elementSize);

        // Called when a VArray id deleted
        virtual void onVarrayDelete( 
                     // OID (DB-CO-PN-SN) of the VArray
                     const ooId &OID, 
                     // number of elements allocated
                     unsigned numElements, 
                     // size in bytes of an element on the
                     // application architecture
                     unsigned elementSize);

        // Called when a VArray is resized
        virtual void onVarrayResize( 
                     // OID (DB-CO-PN-SN) of the VArray
                     const ooId &OID, 
                     // number of elements allocated before resize
                     unsigned oldNumElements, 
                     // size in bytes of an element on the application
                     // architecture before resize
                     unsigned oldElementSize, 
                     // one of: oocNormalVArray, oocDefaultAssocVArray,
                     // or oocInlineAssocVArray
                     ooVArrayType VArrayType,
                     // number of elements allocated after resize
                     unsigned newNumElements, 
                     // size in bytes of an element on the application
                     // architecture after resize
                     unsigned newElementSize, 
                     // OID of parent object
                     const ooId &parentOID, 
                     // OID of redirected VArray if VArray is redirected
                     const ooId &redirectionOID); 

        // Called when a container is created
        virtual void onContainerCreate( 
                     // OID (DB-CO-0-0) of container
                     const ooId &OID); 

        // Called when a container is opened
        // NOTE: does not include repeated calls to open a container that is
        //       already open
        virtual void onContainerOpen( 
                     // OID (DB-CO-0-0) of container
                     const ooId &OID, 
                     // number of existing versions of this
                     // container
                     unsigned numVersions, 
                     // number of logical pages currently
                     // allocated to this container
                     unsigned numLogicalPages); 

        // Called when a container is closed
        virtual void onContainerClose( 
                     // OID (DB-CO-0-0) of container
                     const ooId &OID, 
                     // number of active update versions of this
                     // container
                     unsigned numVersions, 
                     // number of logical pages currently
                     // allocated to this container
                     unsigned numLogicalPages); 

        // Called when a container is deleted
        virtual void onContainerDelete( 
                     // OID (DB-CO-0-0) of container
                     const ooId &OID); 

        // Called when a container is resized
        virtual void onContainerResize( 
                     // OID (DB-CO-0-0) of container
                     const ooId &OID, 
                     // number of logical pages allocated to this
                     // container before resizing
                     unsigned oldSize, 
                     // number of logical pages allocated to this
                     // container after resizing
                     unsigned newSize); 

        // Called when a database is created
        virtual void onDatabaseCreate( 
                     // OID (DB-0-0-0) of database
                     const ooId &OID);

        // Called when a database is opened
        // NOTE: does not include repeated calls to open a database that is
        //       already open
        virtual void onDatabaseOpen( 
                     // OID (DB-0-0-0) of database
                     const ooId &OID); 

        // Called when a database is closed
        virtual void onDatabaseClose( 
                     // OID (DB-0-0-0) of database
                     const ooId &OID); 

        // Called when a database is deleted
        virtual void onDatabaseDelete( 
                     // OID (DB-0-0-0) of database
                     const ooId &OID); 

        // Called when a database is resized
        virtual void onDatabaseResize( 
                     // OID (DB-0-0-0) of database
                     const ooId &OID, 
                     // number of logical pages allocated to this
                     // database before resizing
                     unsigned oldSize, 
                     // number of logical pages allocated to this
                     // database after resizing
                     unsigned newSize); 

        // Called when an OS filehandle is closed to free a filehandle needed
        // to open another.  This is when the number of OS file handles has
        // reached the limit given in the `ooInit' call.
        virtual void onFileCloseToOpenAnother( 
                     // name of file host machine
                     const char *hostname, 
                     // pathname of file being closed
                     const char *pathname); 

	// Called when an OS filehandle is re-opened.
	virtual void onReopenFileIfNeeded( 
                     // name of file host machine
                     const char *hostname, 
                     // pathname of file being closed
                     const char *pathname); 

        // Called when an instance of an ooHandle class is created
        virtual void onHandleCreate( 
                     // OID (DB-CO-PN-SN) of the handle
                     const ooId &OID); 

        // Called when an instance of an ooHandle class is deleted
        virtual void onHandleDelete( 
                     // OID (DB-CO-PN-SN) of the handle
                     const ooId &OID); 

        // Called when an object iterator is created
        virtual void onIteratorInitialize( 
                     // OID (DB-CO-PN-SN) of the scope object or association
                     // VArray being iterated
                     const ooId &OID, 
                     // true if iteration is on a to-many association
                     ooBoolean isAssocScan, 
                     // true if iteration uses predicate query
                     ooBoolean isPredicateQuery); 

        // Called when an object iterator is deleted
        virtual void onIteratorTerminate( 
                     // OID (DB-CO-PN-SN) of the scope object or association
                     // VArray being iterated
                     const ooId &OID, 
                     // true if iteration is on a to-many association
                     ooBoolean isAssocScan, 
                     // true if iteration uses predicate query
                     ooBoolean isPredicateQuery, 
                     // true if iteration was able to use indexes
                     ooBoolean usedIndexes); 

        // Called when an object is given a scope name:
        virtual void onObjectNamed( 
                     // OID of the object being named
                     const ooId &object, 
                     // OID of the scope object
                     const ooId &scope);

        //  Objectivity internal - Non officially supported event
        //  WARNING: May change or be removed at any time
        virtual void onLockRequest(
                     const unsigned dbId,
                     const unsigned ocId,
                     ooMode mode,
                     bool success,
                     bool usesVersioning,
                     unsigned version,
                     uint32 time);

        // Called when an object is opened for update
        virtual void onObjectUpdate(
                     // OID (DB-CO-PN-SN) of the object
                     const ooId &OID,
                     // type (class) number of the object
                     ooTypeNumber typeNumber);

        // Called when a Scalable-Collection iterator is created
        virtual void onCollectionIteratorInitialize(
                     // OID (DB-CO-PN-SN) of the collection being iterated
                     const ooId &OID,
                     // Type (class) number of the collection being iterated
                     ooTypeNumber typeNumber,
                     // one of: oocIterateMapKeys, oocIterateMapValues, or
                     // oocIterateElements
                     ooCollectionIterationKind iterationKind);

        // Called when a Scalable-Collection iterator is deleted
        virtual void onCollectionIteratorTerminate(
                     // OID (DB-CO-PN-SN) of the collection being iterated
                     const ooId &OID,
                     // Type (class) number of the collection being iterated
                     ooTypeNumber typeNumber,
                     // one of: oocIterateMapKeys, oocIterateMapValues, or
                     // oocIterateElements
                     ooCollectionIterationKind iterationKind);

}; // End ooEventListener class


// ooEventListener registration function prototypes:
// Global registration function 
// attaches listener to current kernel session 
OO_STORAGE_SPECIFIER void ooSetEventListener(ooEventListener *);

// enable MROW readers at container delete when using R90 databases (new catalogs), set value with oochange tool
OO_STORAGE_SPECIFIER ooBoolean ooGetAllowReadersAtContainerDelete();


// snapshot API

//SPR19729 - constants changed to enumeration
enum ooSnapShotInfo
{
  oocNoInfo           = 0,
  oocHeaderInfo       = 1,
  oocSessionInfo      = 2,
  oocDatabasesInfo    = 4,
  oocContainersInfo   = 8,
  oocCachePagesInfo   = 16,
  oocShadowPagesInfo  = 32,
  oocObjectsInfo      = 64,
  oocVarraysInfo      = 128,
  oocPrintRecentPages = 256,
  oocAllInfo          = 511 };

//SPR19728 - renamed infoFormat to ooInfoFormat and sortOrder to ooSortOrder
enum ooInfoFormat
{
  oocReadable,
  oocCSV
};

enum ooSortOrder
{
  oocAscending,
  oocDescending,
  oocRecent
};

// Encryption Hooks - enumeration for the result values of methods of
//  the ooEncryptionProvider class
typedef enum
{
  oocEncryptionDone,         // encryption or decryption successfull
  oocEncryptionNotDone,      // the method chose not to perform encryption
                             //  or does not know how
  oocEncryptionUnauthorized, // failure of the operation because of a lack 
                             //  of authorization.
  oocEncryptionError         // failure for some other reason.
} ooEncryptionStatus;

// Encryption Hooks - contains a set of public virtual methods that can be 
//  overridden in a user-defined subclass to impliment page and/or object 
//  level encryption.
class ooEncryptionProvider 
{
  public:
    // Called prior to writing a page of small objects to disk.  
    inline virtual ooEncryptionStatus encryptPage(
        const ooUInt8*, 
        ooUInt8*,  
        unsigned,  
        const ooId&, 
        bool) 
    {return oocEncryptionNotDone; }

    // called after a small object is closed (converted back to disk format).
    inline virtual ooEncryptionStatus encryptObject(
        ooUInt8*, 
        unsigned,  
        const ooId &,  
        ooTypeNumber)
    {return oocEncryptionNotDone; }

    // called after a large object is closed (converted back to disk format).
    inline virtual ooEncryptionStatus encryptLargeObject(
        ooUInt8*, 
        unsigned,  
        const ooId&,  
        ooTypeNumber)
    {return oocEncryptionNotDone; }

    // called after an encrypted page of small objects (a page for which
    //  encryptPage returned oocEncryptionDone) has been read from disk 
    //  into memory.
    inline virtual ooEncryptionStatus decryptPage(
        ooUInt8*, 
        unsigned, 
        const ooId&,  
        bool)
    {return oocEncryptionNotDone; }

    // called before opening an encrypted small object (an object for 
    // which encryptObject returned oocEncryptionDone). 
    inline virtual ooEncryptionStatus decryptObject(
        ooUInt8*, 
        unsigned,  
        const ooId&,
        ooTypeNumber) //  SPR 20902 - add typeN in R10.2
    {return oocEncryptionNotDone; }

    // called before opening an encrypted large object (an object for which 
    //  encryptLargeObject returned oocEncryptionDone).
    inline virtual ooEncryptionStatus decryptLargeObject(
        ooUInt8*, 
        unsigned,  
        const ooId&,
        ooTypeNumber) //  SPR 20902 - add typeN in R10.2
    {return oocEncryptionNotDone; }

    inline virtual ~ooEncryptionProvider() 
    {}
};

// Tuner Extension Point
// A mechanism for attaching code to an Objectivity application program for 
// purposes such as monitoring performance and setting tuning parameters.
class ooPlugin;
class ooConnection;
class ooSession;
class ooTunerPlugin
{

  public:
    static bool onStartingCalled; // Keep track so we only call once.
    static bool onStartedCalled; // Keep track so we only call once.

    virtual void initialize(const ooPlugin*) { }
    virtual bool inObjyTool(int, char**, const char*)
      { return true; }
    virtual void onStarting() { }
    virtual void onStarted()  { }
    virtual void onConnectionCreated(ooConnection*) { }
    virtual void onThreadInitialized() { }
    virtual void onInternalSessionCreated(unsigned, ocmSession*) { }
    virtual void onSessionCreated(unsigned, ooSession*) { }
    virtual void onSessionInitialization(ocmSession*) { }
    virtual void onSchemaLoaded(ocmSession*) { }
    virtual void onSessionDeleted(unsigned, ooSession*) { }
    virtual void onInternalSessionDeleted(unsigned, ocmSession*) { }
    virtual void onThreadTerminated() { }
    virtual void onShutdown() { }
    virtual void onShutdownCompleted() { }
    virtual ~ooTunerPlugin() { }
};

struct OO_STORAGE_SPECIFIER ooContainerMemoryUsage
{
  unsigned mNumContainers;        // number of containers
  unsigned mCachedContainerPages; // number of pages cached
  size_t   mContainerTableSpace;  // memory space used by container tables

  void clear() {
    mNumContainers = 0;
    mCachedContainerPages = 0;
    mContainerTableSpace = 0;
  }
  ooContainerMemoryUsage() { clear(); }
};

struct OO_STORAGE_SPECIFIER ooContainerTableStatistics
{
  ooContainerMemoryUsage mOpen;   // data for currently open containers
  ooContainerMemoryUsage mClosed; // data for remembered closed containers

  // Get current usage numbers from the given session.
  void setFromSession(const ooSession* session);
  void setFromSession(const ocmSession* session); // for internal use
};

 // With io thread enabled, we'll use a special i/o thread one/session to read ahead 1 page while scanning a container (not an aindex scan)
OO_STORAGE_SPECIFIER void ooPermitReadAhead(bool ioThreadOk = false);
OO_STORAGE_SPECIFIER bool ooGetPermitReadAhead();

// sparse DB files saves disk space in some cases, non sparse DB files improves i/o speed
OO_STORAGE_SPECIFIER void ooPermitSparseDbFiles(bool sparse = false);
OO_STORAGE_SPECIFIER bool ooGetPermitSparseDbFiles();
#endif	/*OO_BASE_H*/
