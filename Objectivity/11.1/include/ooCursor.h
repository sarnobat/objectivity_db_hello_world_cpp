//=============================================================================
//
// File: ooCursor.h
//
// Author: Marc Gille
// Company: MICRAM Object Technology GmbH
//
// Purpose: Macro definitions for cursor declaration and implementation
//
//=============================================================================

#ifndef CURS_H
#define CURS_H

// Include directives for standard C/C++ headers

#include <stdlib.h>
#include <string.h>

// Include Objectivity/DB headers

#include <oo.h>
#include <ooMap.h>
#include <ooString.h>
#ifdef SQL
#include <ooSQL.h>
#ifdef WIN32
#include <ooSQLtyp.h>
#else
#include <ooSQLtypes.h>
#endif
#endif

//---------------------------------------------------------------------------
// Type definitions
//---------------------------------------------------------------------------

typedef const ooBoolean (*ooCursorFuncPtr)(const uint32);

//---------------------------------------------------------------------------
// Macro definition ooCursor(X)
//---------------------------------------------------------------------------

#define ooCursor(X) ooConcat2(X,_ooCursor)

#ifndef CDB_IMPORT
//---------------------------------------------------------------------------
class ooCursor(ooObj)
//---------------------------------------------------------------------------
{
protected:

	ooCursorFuncPtr         FuncPtr;
   ooHandle(ooObj)        *HndArr;
   ooVArray(ooRef(ooObj))  RefArr;
	ooMapItr               *MapItr;
	ooBoolean               SQLFlag;
   uint32                  InitSize;
   uint32                  QuerySize;
   uint32                  VisSize;
   uint32                  PercGrow;
   uint32                  Index;
#ifdef SQL
   UCHAR                   ooIdBase[12];
   HSTMT                   Stat;
   HENV                    Env;
   HDBC                    Conn;
#endif

// ooCursor protocol 

   virtual ooHandle(ooObj) fetchEntry(const uint32 SearchIndex);

public:

   ooCursor(ooObj)(const uint32 NewVisSize=30,
                   const uint32 NewInitSize=30,
                   const uint32 NewPercGrow=10);
  ~ooCursor(ooObj)();

// ooCursor protocol 

   virtual ooStatus  init(const ooHandle(ooObj) &Scope,
                          const char            *Pred = NULL);
	virtual ooBoolean isQueryComplete();

// ooCursor services

   ooStatus        init(ooMapItr *NewMapItr);
   void            resize(const uint32 NewSize);
   ooStatus			 clear();
   ooStatus        addEntry(const ooHandle(ooObj) &Hnd);
   ooStatus        insEntry(const ooHandle(ooObj) &Hnd,
                            const uint32           Pos);
   ooStatus        insEntryBefore(const ooHandle(ooObj) &Hnd,
                                  const ooHandle(ooObj) &Scope);
   ooStatus        insEntryAfter(const ooHandle(ooObj) &Hnd,
                                 const ooHandle(ooObj) &Scope);
   ooStatus        delEntry(const ooHandle(ooObj) &Hnd);
   ooStatus        delEntry(const uint32 Pos);
   ooHandle(ooObj) getAbsoluteEntry(const uint32 SearchIndex);
   ooHandle(ooObj) getEntry(const uint32 SearchIndex);
   ooBoolean       next(const uint32 StepNum);
   ooBoolean       prev(const uint32 StepNum);
   ooBoolean       first();
   ooBoolean       last();
   uint32          getQuerySize() const;
	ooStatus        registerCallback(ooCursorFuncPtr Func);
   ooStatus        operator+=(const ooHandle(ooObj) &);
   ooHandle(ooObj) operator[](const uint32);
	ooStatus        connectCursor(const char *SQLPred,
											const char *Server,
											const char *User,
											const char *PassWord);
	ooRef(ooObj)   &getNextRef(ooRef(ooObj) &);
};
#else
//---------------------------------------------------------------------------
class ooCursor(ooObj);	// class ooObj -- Classify/DB
//---------------------------------------------------------------------------
#endif	/* ifndef CDB_IMPORT	*/

#ifdef CDB_IMPORT
//---------------------------------------------------------------------------
// Macro definition DecCursor(X) -- Classify/DB
//---------------------------------------------------------------------------
#define ooCursordeclare(X)  class ooCursor(X); 

#else
//---------------------------------------------------------------------------
// Macro definition DecCursor(X)
//---------------------------------------------------------------------------
#define ooCursordeclare(X)                                         \
                                                                   \
class ooCursor(X): public ooCursor(ooObj)                          \
{                                                                  \
   friend int ooConcat2(qsortCompare,X) (const void *,	          \
                                         const void *);	          \
													                            \
	ooItr(X)    *CursItr;                                           \
   virtual ooHandle(ooObj) fetchEntry(const uint32 SearchIndex);   \
public:                                                            \
                                                                   \
   ooCursor(X)(const uint32 NewVisSize = 10,                       \
               const uint32 NewInitSize = 50,		                \
               const uint32 NewPercGrow = 30);                     \
                                                                   \
   virtual ooStatus    init(const ooHandle(ooObj) &Scope,          \
                            const char            *Pred = NULL);   \
   virtual ooStatus    init(ooItr(X) &Itr);		                   \
   virtual ooStatus    init(const char *SQLPred,	                \
								    const char *Server,                    \
								    const char *User,                      \
								    const char *PassWord);                 \
	virtual ooStatus    completeQuery();                            \
	virtual ooBoolean   isQueryComplete();                          \
	virtual ooBoolean   otherFilter(const ooHandle(X) &);           \
                                                                   \
   ooHandle(X) getEntry(const uint32 SearchIndex);                 \
   ooStatus    insEntrySort(const ooHandle(X) &Hnd,                \
                            int (*OrdFunc) (const ooHandle(X) &,   \
                                            const ooHandle(X) &)); \
   ooBoolean   findEntry(const ooHandle(X) &TestEntry,             \
								 uint32            &EntryIndex);           \
   ooStatus    sort(int (*OrdFunc) (const ooHandle(X) &,           \
                                    const ooHandle(X) &));         \
   ooHandle(X) getAbsoluteEntry(const uint32 SearchIndex);         \
   ooHandle(X) operator[](const uint32);	               		    \
                                                                   \
};
#endif	/* ifdef CDB_IMPORT */

#ifdef CDB_IMPORT
//---------------------------------------------------------------------------
// Macro definition ImpCursor(X) -- Classify/DB 
//---------------------------------------------------------------------------
#define ooCursorimplement(X)

#else	/* ifdef CDB_IMPORT */
//---------------------------------------------------------------------------
// Macro definition ImpCursor(X)
//---------------------------------------------------------------------------
#define ooCursorimplement(X)                                                            \
                                                                                        \
ooCursor(X)::ooCursor(X)(const uint32 NewVisSize,                                       \
                         const uint32 NewInitSize,                                      \
                         const uint32 NewPercGrow): 	     									    \
             ooCursor(ooObj)(NewVisSize,															    \
									  NewInitSize,															    \
									  NewPercGrow)																 \
{                                                                                       \
	CursItr = NULL;                                                                      \
	SQLFlag = oocFalse;                                                                  \
}                                                                                       \
ooStatus ooCursor(X)::init(const ooHandle(ooObj) &Scope,                                \
                           const char            *Pred)                                 \
{                                                                                       \
	CursItr = new ooItr(X);                                                              \
	MapItr  = NULL;                                                                      \
	SQLFlag = oocFalse;                                                                  \
																													 \
   if ((*CursItr).scan(Scope, Pred) != oocSuccess)				             			       \
	{                                                                                    \
      return oocError;								     					 					 		    \
	}                                                                                    \
                                                                                        \
	while (QuerySize < InitSize)                                                         \
	{                                                                                    \
		if ((*CursItr).next())	                                                          \
		{                                                                                 \
			if (otherFilter((*CursItr)))                                                   \
			{                                                                              \
				RefArr[QuerySize] = (*CursItr);                                             \
				QuerySize++;                                                                \
				if (FuncPtr != NULL)                                                        \
				{                                                                           \
					if ((*FuncPtr)(QuerySize) != oocTrue)                                    \
					{                                                                        \
						break;    				                                                 \
					}                                                                        \
				}                                                                           \
			}                                                                              \
		}                                                                                 \
		else                                                                              \
		{                                                                                 \
			CursItr = NULL;                                                                \
			break;			                                                                \
		}                                                                                 \
	}                                                                                    \
   first();                                              			                      \
                                                                                        \
	return oocSuccess;                                                                   \
}                                                                                       \
ooStatus ooCursor(X)::init(ooItr(X) &Itr)															    \
{																												    \
	CursItr = &Itr;                                                                      \
	MapItr  = NULL;                                                                      \
	SQLFlag = oocFalse;                                                                  \
	while (QuerySize < InitSize)                                                         \
	{                                                                                    \
		if ((*CursItr).next())                                                            \
		{                                                                                 \
			if (otherFilter((*CursItr)))                                                   \
			{                                                                              \
				RefArr[QuerySize] = (*CursItr);                                             \
				QuerySize++;                                                                \
				if (FuncPtr != NULL)                                                        \
				{                                                                           \
					if ((*FuncPtr)(QuerySize) != oocTrue)                                    \
					{                                                                        \
						break;    				                                                 \
					}                                                                        \
				}                                                                           \
			}                                                                              \
		}                                                                                 \
		else                                                                              \
		{                                                                                 \
			CursItr = NULL;                                                                \
			break;			                                                                \
		}                                                                                 \
	}                                                                                    \
   first();                                              			                      \
	return oocSuccess;                                                                   \
}																												    \
ooStatus ooCursor(X)::init(const char *SQLPred,                                         \
								   const char *Server,                                          \
								   const char *User,                                            \
								   const char *PassWord)                                        \
{                                                                                       \
	CursItr = NULL;                                                                      \
	MapItr  = NULL;                                                                      \
	SQLFlag = oocTrue;                                                                   \
   connectCursor(SQLPred,                                                               \
					  Server,                                                                \
					  User,                                                                  \
					  PassWord);                                                             \
	for (uint32 N = 0; N < InitSize; N++)                                                \
	{                                                                                    \
		if (getNextRef(RefArr[N]) == NULL)                                                \
		{                                                                                 \
			SQLFlag = oocFalse;                                                            \
			break;                                                                         \
		}                                                                                 \
		else                                                                              \
		{                                                                                 \
			if (otherFilter((ooRef(X) &)RefArr[N]))                                        \
			{                                                                              \
				QuerySize++;                                                                \
				if (FuncPtr != NULL)                                                        \
				{                                                                           \
					if ((*FuncPtr)(QuerySize) != oocTrue)                                    \
					{                                                                        \
						break;                                                                \
					}                                                                        \
				}                                                                           \
			}                                                                              \
		}                                                                                 \
	}                                                                                    \
   first();                                              			                      \
   return oocSuccess;                                                                   \
}                                                                                       \
ooStatus ooCursor(X)::completeQuery()                                                   \
{                                                                                       \
	int i = QuerySize;																					    \
	while(getAbsoluteEntry(i) != NULL)																    \
	{																											    \
		i++;																									    \
	}																											    \
	return oocSuccess;                                                                   \
}                                                                                       \
ooBoolean ooCursor(X)::isQueryComplete()                                                \
{                                                                                       \
	if (CursItr != NULL ||                                                               \
		 MapItr  != NULL ||                                                               \
		 SQLFlag != NULL)                                                                 \
	{                                                                                    \
		return oocFalse;                                                                  \
	}                                                                                    \
	return oocTrue;                                                                      \
}                                                                                       \
ooBoolean ooCursor(X)::otherFilter(const ooHandle(X) &)                                 \
{                                                                                       \
	return oocTrue;                                                                      \
}                                                                                       \
ooHandle(X) ooCursor(X)::getEntry(const uint32 SearchIndex)                             \
{                                                                                       \
   return ((ooHandle(X)&)ooCursor(ooObj)::getEntry(SearchIndex));							    \
}                                                                                       \
ooStatus ooCursor(X)::insEntrySort(const ooHandle(X) &Hnd,                              \
                                   int (*OrdFunc) (const ooHandle(X) &,                 \
                                                   const ooHandle(X) &))                \
{                                                                                       \
   uint32 N = 0;                                                                        \
                                                                                        \
   while (N < QuerySize &&                                                              \
          (*OrdFunc)(Hnd,                                                               \
                     (ooRef(X) &)RefArr[N]) >= 0)                                       \
   {                                                                                    \
      N++;                                                                              \
   }                                                                                    \
                                                                                        \
   return insEntry(Hnd,                                                                 \
                   N);                                                                  \
}                                                                                       \
ooHandle(X) ooCursor(X)::getAbsoluteEntry(const uint32 SearchIndex)                     \
{                                                                                       \
	return (ooHandle(X) &)fetchEntry(SearchIndex);                                       \
}                                                                                       \
ooHandle(ooObj) ooCursor(X)::fetchEntry(const uint32 SearchIndex)                       \
{                                                                                       \
	if (SearchIndex < QuerySize)                                                         \
	{                                                                                    \
		return (ooRef(ooObj) &)RefArr[SearchIndex];                                       \
	}                                                                                    \
	else if (CursItr != NULL)                                                            \
	{                                                                                    \
		while (QuerySize < SearchIndex + 1)                                               \
		{                                                                                 \
			if ((*CursItr).next())                                                         \
			{                                                                              \
			   if (otherFilter((*CursItr)))                                                \
				{                                                                           \
					if (RefArr.size() == QuerySize)                                          \
					{                                                                        \
						int NewSize = (int)(RefArr.size() * (1 + PercGrow * 0.01));				 \
						if (NewSize <= RefArr.size())														 \
							NewSize = RefArr.size()+1;														 \
						RefArr.resize(NewSize);											                \
					}                                                                        \
					RefArr[QuerySize] = (*CursItr);                                          \
					QuerySize++;                                                             \
					if (FuncPtr != NULL)                                                     \
					{                                                                        \
						if ((*FuncPtr)(QuerySize) != oocTrue)                                 \
						{                                                                     \
							return NULL;                                                       \
						}                                                                     \
					}                                                                        \
				}                                                                           \
			}                                                                              \
			else                                                                           \
			{                                                                              \
				CursItr = NULL;                                                             \
				return NULL;                                                                \
			}                                                                              \
		}                                                                                 \
		return (ooRef(ooObj) &)RefArr[SearchIndex];                                       \
	}                                                                                    \
	else if (MapItr != NULL)                                                        		 \
	{                                                                                    \
		while (QuerySize < SearchIndex + 1)                                               \
		{                                                                                 \
			if ((*MapItr).next())  	                                                       \
			{                                                                              \
			   if (otherFilter((ooRef(X) &)(*MapItr)->oid()))                              \
				{                                                                           \
					if (RefArr.size() == QuerySize)                                          \
					{                                                                        \
						int NewSize = (int)(RefArr.size() * (1 + PercGrow * 0.01));				 \
						if (NewSize <= RefArr.size())														 \
							NewSize = RefArr.size()+1;														 \
						RefArr.resize(NewSize);											                \
					}                                                                        \
					RefArr[QuerySize] = (*MapItr)->oid();                                    \
					QuerySize++;                                                             \
					if (FuncPtr != NULL)                                                     \
					{                                                                        \
						if ((*FuncPtr)(QuerySize) != oocTrue)                                 \
						{                                                                     \
							return NULL;                                                       \
						}                                                                     \
					}                                                                        \
				}                                                                           \
			}                                                                              \
			else                                                                           \
			{                                                                              \
				MapItr = NULL;                                                              \
				return NULL;                                                                \
			}                                                                              \
		}                                                                                 \
		return (ooRef(ooObj) &)RefArr[SearchIndex];                                       \
	}                                                                                    \
	else if (SQLFlag)                                                                    \
	{                                                                                    \
		ooRef(ooObj) TmpRef;                                                              \
		while (QuerySize < SearchIndex + 1)                                               \
		{                                                                                 \
			if (getNextRef(TmpRef) != NULL)                                                \
			{                                                                              \
				if (otherFilter((ooRef(X) &)TmpRef))                                        \
				{                                                                           \
					if (RefArr.size() == QuerySize)                                          \
					{                                                                        \
						RefArr.resize(RefArr.size() * (1 + PercGrow * 0.01));                 \
					}                                                                        \
					RefArr[QuerySize] = (ooRef(ooObj) &)TmpRef;                              \
					QuerySize++;                                                             \
					if (FuncPtr != NULL)                                                     \
					{                                                                        \
						if ((*FuncPtr)(QuerySize) != oocTrue)                                 \
						{                                                                     \
							return NULL;                                                       \
						}                                                                     \
					}                                                                        \
				}                                                                           \
			}                                                                              \
			else                                                                           \
			{                                                                              \
				SQLFlag = oocFalse;                                                         \
				return NULL;                                                                \
			}                                                                              \
		}                                                                                 \
		return (ooRef(ooObj) &)RefArr[SearchIndex];                                       \
	}                                                                                    \
	return NULL;                                                                         \
}                                                                                       \
ooBoolean ooCursor(X)::findEntry(const ooHandle(X) &TestEntry,                          \
								         uint32            &EntryIndex)                         \
{                                                                                       \
	for (uint32 N = 0; N < QuerySize; N++)                                               \
	{                                                                                    \
		if (RefArr[N] == TestEntry)                                                       \
		{                                                                                 \
			EntryIndex = N;                                                                \
			return oocTrue;                                                                \
		}                                                                                 \
	}                                                                                    \
	return oocFalse;                                                                     \
}                                                                                       \
int (*ooConcat2(QSortOrdFunc,X)) (const ooHandle(X) &,			                         \
                                  const ooHandle(X) &);				                      \
ooStatus ooCursor(X)::sort(int (*OrdFunc)(const ooHandle(X) &,                          \
                                          const ooHandle(X) &))			                \
{										                                                          \
	ooHandle(X) **BuffArr;																		          \
	ooStatus     TmpStatus = oocSuccess;			                                        \
						                                                                      \
   ooConcat2(QSortOrdFunc,X) = OrdFunc;						                               \
																													 \
	if (CursItr != NULL)                                                            		 \
	{                                                                                    \
		completeQuery();                                                                  \
	}																												 \
	BuffArr = new ooHandle(X)*[QuerySize];                                			       \
	for (uint32 N = 0; N < QuerySize; N++)                                               \
	{                                                                                    \
		 BuffArr[N] = new ooHandle(X);                                                    \
		*BuffArr[N] = (ooRef(X) &)RefArr[N];                                              \
	}                                                                                    \
	qsort(BuffArr,					                                                          \
         QuerySize,						                                                    \
         sizeof(ooHandle(X) *),					                                           \
         ooConcat2(qsortCompare,X));						                                  \
	for (N = 0; N < QuerySize; N++)                                                      \
	{                                                                                    \
		RefArr[N] = *BuffArr[N];                                                          \
	}                                                                                    \
	for (N = 0; N < QuerySize; N++)                                                      \
	{                                                                                    \
		delete BuffArr[N];                                                                \
	}                                                                                    \
	delete [] BuffArr;                                                                   \
   first();						                                                             \
																	                                     \
   if (TmpStatus != oocSuccess) 						                                        \
	{                                                                                    \
      return oocError; 								                                           \
	}                                                                                    \
   else 									                                                       \
	{                                                                                    \
      return oocSuccess;                                                                \
	}                                                                                    \
}										                                                          \
int ooConcat2(qsortCompare,X)(const void *LH,		                                     \
                              const void *RH)				                               \
{					                                                                         \
	ooHandle(X) LeftHandle = **((ooHandle(X) **)LH);                                     \
	ooHandle(X) RightHandle = **((ooHandle(X) **)RH);                                    \
																													 \
   if (LeftHandle.open(oocRead) != oocSuccess ||                                        \
       RightHandle.open(oocRead) != oocSuccess)                                         \
   {										                                                       \
      return 0;                                                                         \
   }										                                                       \
   else										                                                    \
	{                                                                                    \
      return (ooConcat2(QSortOrdFunc,X)(LeftHandle,                                     \
                                        RightHandle));                                  \
   }                                                                                    \
}										                                                          \
ooHandle(X) ooCursor(X)::operator[](const uint32 SearchIndex)	                         \
{									                                                             \
   return getAbsoluteEntry(SearchIndex);						                               \
}                                                                                       
#endif	/* ifdef CDB_IMPORT */

#endif
