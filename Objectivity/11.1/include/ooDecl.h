/**************************************************************************
		Copyright (c) 1989-2002 Objectivity, Inc.
			  All Rights Reserved

	THIS IS UNPUBLISHED PROPRIETARY SOURCE CODE OF OBJECTIVITY, INC.

	The copyright notice above does not evidence any
	actual or intended publication of such source code.

*****************************************************************************/

#define OO_DECL_H "@(#)$Id$"

/*
This file declares functions and variables that are dependent on the types
defined in ooSchema_ref.h.  Some of these functions and variables are
in turn required by the inline methods defined in ooSchema_ref.h.
 
This file is #included from file oo.h as follows:

	#include <oo.h>
	    #include <ooSchema.h>
		#include <ooSchema_ref.h>
		    #include <ooDecl.h>

It should never be #included in any other way.
*/


///////////////////////////////////////////////////////////////////////////////
// Some variables

OO_STORAGE_SPECIFIER extern ooHandle(ooObj)   oocNullHandle;
OO_STORAGE_SPECIFIER extern ooId              oocNullId;

OO_STORAGE_SPECIFIER ooHandle(ooFDObj)& opiGetTopFD();
OO_STORAGE_SPECIFIER ooHandle(ooAPObj)& opiGetTopAP();
OO_STORAGE_SPECIFIER ooHandle(ooDBObj)& opiGetTopDB();

// Deprecated public macros
#define oovTopFD opiGetTopFD()
#define oovTopAP opiGetTopAP()
#define oovTopDB opiGetTopDB()

OO_STORAGE_SPECIFIER
void *
opiNewObj(ooTypeNumber,
	  size_t,
	  const ooHandle(ooObj) &);

OO_STORAGE_SPECIFIER
void *
opiNewObj(ooTypeNumber,
	  size_t,
	  const ooObj *);

OO_STORAGE_SPECIFIER
void *
opiNewContObj(ooTypeNumber,
	      size_t,
	      const char *,
	      uint32,
	      uint32,
	      uint32,
	      const ooHandle(ooObj)&,
          uint16 userContID = 0,
		  ooBoolean externalContainer = oocFalse,
		  const char *hostName = 0, const char *pathName = 0,
		  const unsigned pageSize = 0,
	      bool zeroBasicFields = false);

OO_STORAGE_SPECIFIER
void *
opiNewContObj(ooTypeNumber,
	      size_t,
	      const char *,
	      uint32,
	      uint32,
	      uint32,
	      const ooObj *,
          uint32 ocId = 0,
	      bool zeroBasicFields = false);

OO_STORAGE_SPECIFIER
void *
opiNewContObjObj(ooTypeNumber             typeNo,
	         ooHandle(ooObj) &        result,
	         uint32                   contId,
	         const ooHandle(ooObj) &  nearHandle);

OO_STORAGE_SPECIFIER
uint32
opiNewContSForMacro(ooTypeNumber,
		    uint32,
		    const ooHandle(ooObj) &,
		    uint32,
		    uint32,
		    uint32);

OO_STORAGE_SPECIFIER
ooStatus
opiLookupObj(ooTypeNumber,
	     ooHandle(ooObj) &,
	     const ooHandle(ooObj) &,
	     const char *,
	     ooMode);

OO_STORAGE_SPECIFIER
ooStatus
opiLookupObj(ooTypeNumber,
	     ooHandle(ooObj) &,
	     const ooHandle(ooObj) &,
	     const ooKey &,
	     ooMode);

OO_STORAGE_SPECIFIER
ooStatus
opiInitAssocItr(ooHandle(ooObj)&,
		void *,
		ooAssocTypeN,
		ooMode);

OO_STORAGE_SPECIFIER
ooStatus
opiInitAssocVPredItr(ooHandle(ooObj)&,
		     void *,
		     ooAssocTypeN,
		     const char *,
		     ooAccessMode,
		     ooMode);

// SPR 20645: pass an ObjectQualifier instance as a predicate to association iterator
OO_STORAGE_SPECIFIER
ooStatus
opiInitAssocVQualItr(ooHandle(ooObj)&,
		     void *,
		     ooAssocTypeN,
		     const objy::query::ObjectQualifier&,
		     ooMode);

OO_STORAGE_SPECIFIER
ooStatus
opiInitIAssocVQualItr(ooHandle(ooObj)&,
		     void *,
		     const objy::query::ObjectQualifier&,
		     ooMode,
                     ooBoolean);

OO_STORAGE_SPECIFIER
ooStatus
opiAddAssoc(void *,
	    const ooHandle(ooObj)&,
	    ooAssocTypeN,
	    ooBoolean);

OO_STORAGE_SPECIFIER
ooStatus
opiSetAssoc(void *,
	    const ooHandle(ooObj)&,
	    ooAssocTypeN,
	    ooBoolean);

OO_STORAGE_SPECIFIER
ooStatus
opiSubAssoc(void *,
	    const ooHandle(ooObj) &,
	    ooAssocTypeN,
	    uint32 nmuber = 1);

OO_STORAGE_SPECIFIER
ooStatus
opiDelAssoc(void *,
	    ooAssocTypeN);

OO_STORAGE_SPECIFIER
ooStatus
opiDelAssoc_1(void *,
	      ooAssocTypeN);

OO_STORAGE_SPECIFIER
ooStatus
opiAddUssoc(void *,
	    const ooHandle(ooObj)&,
	    ooAssocTypeN);

OO_STORAGE_SPECIFIER
ooStatus
opiSetUssoc(void *,
	    const ooHandle(ooObj)&,
	    ooAssocTypeN);

OO_STORAGE_SPECIFIER
ooStatus
opiSubUssoc(void *,
	    const ooHandle(ooObj)&,
	    ooAssocTypeN,
	    uint32 nmuber = 1);

OO_STORAGE_SPECIFIER
ooStatus
opiDelUssoc(void *,
	    ooAssocTypeN);

OO_STORAGE_SPECIFIER
ooStatus
opiDelUssoc_1(void *,
	      ooAssocTypeN);

OO_STORAGE_SPECIFIER
ooStatus
opiGetAssoc(void *,
	    ooHandle(ooObj)&,
	    ooAssocTypeN,
	    ooMode);

OO_STORAGE_SPECIFIER
ooStatus
opiAddIAssoc(void *,
	     const ooHandle(ooObj)&,
	     ooAssocTypeN,
	     uint8);

OO_STORAGE_SPECIFIER
ooStatus
opiSubIAssoc(void *,
	     const ooHandle(ooObj)&,
	     ooAssocTypeN,
	     uint8,
	     uint32 nmuber = 1);

OO_STORAGE_SPECIFIER
ooStatus
opiDelIAssoc(void *,
	     ooAssocTypeN,
	     uint8);

OO_STORAGE_SPECIFIER
ooStatus
opiSetEAssoc(void *,
	     void *,
	     const ooHandle(ooObj)&,
	     ooAssocTypeN,
	     uint8);

OO_STORAGE_SPECIFIER
ooStatus
opiGetEAssoc(void *,
	     void *,
	     ooHandle(ooObj)&,
	     ooMode);

OO_STORAGE_SPECIFIER
ooStatus
opiDelEAssoc(void *,
	     void *,
	     ooAssocTypeN,
	     uint8);

OO_STORAGE_SPECIFIER
ooStatus
opiAddIUssoc(void *,
	     const ooHandle(ooObj)&,
	     ooAssocTypeN,
	     ooBoolean);

OO_STORAGE_SPECIFIER
ooStatus
opiSubIUssoc(void *,
	     const ooHandle(ooObj)&,
	     ooBoolean,
	     uint32 nmuber = 1);

OO_STORAGE_SPECIFIER
ooStatus
opiSetEUssoc(void *,
	     void *,
	     const ooHandle(ooObj)&,
	     ooBoolean);

OO_STORAGE_SPECIFIER
ooStatus
opiInitIAssocItr(ooHandle(ooObj)&,
		 void *,
		 ooMode,
		 ooBoolean);

OO_STORAGE_SPECIFIER
ooStatus
opiInitIAssocVPredItr(ooHandle(ooObj)&,
		      void *,
		      const char *,
		      ooAccessMode,
		      ooMode,
		      ooBoolean);

OO_STORAGE_SPECIFIER
ooBoolean
opiExistAssoc(void *,
	      ooAssocTypeN,
	      const ooHandle(ooObj)&);

OO_STORAGE_SPECIFIER
ooBoolean
opiExistEAssoc(void *,
	       void *,
	       const ooHandle(ooObj)&);

OO_STORAGE_SPECIFIER
ooBoolean
opiExistIAssoc(void *,
	       ooBoolean,
	       const ooHandle(ooObj)&);

