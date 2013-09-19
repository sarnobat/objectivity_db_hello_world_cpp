/**************************************************************************
		    Copyright (c) 1992-2000 Objectivity, Inc.
			  All Rights Reserved  	

	THIS IS UNPUBLISHED PROPRIETARY SOURCE CODE OF OBJECTIVITY, INC.
	
	The copyright notice above does not evidence any   	
	actual or intended publication of such source code.

*****************************************************************************/

#ifndef OO_RECOVER_H
#define OO_RECOVER_H

#if defined(_MSC_VER) && !defined(OO_DDL_TRANSLATION)
#pragma pack(push,8)
#endif

#include <ooBase.h>

/*
 * Recovery header file 
 *
 * The Recovery module consists of several functions to help in
 * development of problem detection and recovery aid tools relating
 * to Objectivity/DB applications.
 *
 * These functions are used by Objectivity/DB recovery utility OOCLEANUP.
 *
 */


#define oocInValidTransId	((ooTransId) 0)  /* invalid transaction id */

/* transaction information */

#define OO_TRANS_INFO_HOST_LEN 32
#define OO_TRANS_INFO_ARCH_LEN 32

enum ooTransState { oocUnknownTrans, oocReadOnlyTrans, oocUpdateTrans,
		    oocPreparedTrans, oocCommittedTrans };

typedef struct ooTransInfo
{
  ooTransId    tid;	    /* transaction id */
  char         host[OO_TRANS_INFO_HOST_LEN];    /* host name */
  char         arch[OO_TRANS_INFO_ARCH_LEN];    /* machine architecture type */
  unsigned int uid;    	    /* user id */
  unsigned int pid;    	    /* process id */
  ooTransState state;       /* transaction state */
  ooExternalTransId globalTid; /* global transaction, if any */
} ooTransInfo;

/* resource information */
typedef struct ooResource
{
  char         type[8];     /* resource type */
  char         mode[8];     /* lock mode */
  unsigned int fdId;        /* federated Id */
  unsigned int dbId;        /* database Id */
  unsigned int ocId;	    /* container Id */
  unsigned int pgId;        /* page id */
} ooResource;


OO_STORAGE_SPECIFIER ooStatus ooGetResourceOwners (
	ooTransInfo **ppOwners, ooResource *pResource, 
	char **ppBootFilePath, ooTransId tid);

OO_STORAGE_SPECIFIER ooStatus ooGetActiveTrans (
	ooTransInfo **ppTrans, char **ppBootFilePath, 
	char *pHost, unsigned int *pUid);

OO_STORAGE_SPECIFIER ooStatus ooCleanup (
	char **ppBootFilePath, ooTransId tid, 
	int ignHost = 0, int standalone = 0, 
	int override = 0, ooTransInfo *pLockOwner = 0,
	oo2PCTransState globalTransState = oo2PCTransStateInDoubt);

#if defined(_MSC_VER) && !defined(OO_DDL_TRANSLATION)
#pragma pack(pop)
#endif

#endif /*  OO_RECOVER_H */
