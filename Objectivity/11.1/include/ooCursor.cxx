//=============================================================================
//
// File: ooCursor.cxx
//
// Author: Marc Gille
// Company: MICRAM Object Technology GmbH
//
// Purpose: Implementation of class ooCursor(ooObj)
//
//=============================================================================

#include <base.h>

// Include directives for package headers

#include "ooCursor.h"

//---------------------------------------------------------------------------
// Error messages
//---------------------------------------------------------------------------

uint32 ErrOffset = 100000;

ooError CursIndexExceedVisSizeErr   = {ErrOffset + 1, "Index exceeds visible size"};
ooError CursIndexExceedQuerySizeErr = {ErrOffset + 2, "Index exceeds query size."};
ooError CursScopeIsNullErr          = {ErrOffset + 3, "Search scope is NULL."};
ooError CursScopeNotFoundErr        = {ErrOffset + 4, "Search scope not found."};
ooError CursEntryIsNullErr          = {ErrOffset + 5, "Entry is NULL."};
ooError CursEntryNotFoundErr        = {ErrOffset + 6, "Entry not found."};
ooError CursSQLConnErr              = {ErrOffset + 7, "Connect to database failed."};
ooError CursQueryExecErr            = {ErrOffset + 8, "Query execution error."};
ooError CursFetchColErr             = {ErrOffset + 9, "Fetch column error."};

//-----------------------------------------------------------------------------
struct OIDStruct
//-----------------------------------------------------------------------------
{
   uint16 DB;
   uint16 Cont;
   uint16 Page;
   uint16 Slot;
};

//-----------------------------------------------------------------------------
ooRef(ooObj) &initRef(ooRef(ooObj) &RetRef,
                      const char   *RefStr)
//-----------------------------------------------------------------------------
{
   OIDStruct ooIdBase;
   char      Buff[20];
   int       N = 1;
   int       M = 0;

   while (RefStr[N] != '-')
   {
      Buff[M] = RefStr[N];
      N++;
      M++;
   }

   Buff[M] = '\0';
   M       = 0;
   N++;

   ooIdBase.DB = atoi(Buff);

   while (RefStr[N] != '-')
   {
      Buff[M] = RefStr[N];
      N++;
      M++;
   }

   Buff[M] = '\0';
   M       = 0;
   N++;

   ooIdBase.Cont = atoi(Buff);

   while (RefStr[N] != '-')
   {
      Buff[M] = RefStr[N];
      N++;
      M++;
   }

   Buff[M] = '\0';
   M       = 0;
   N++;

   ooIdBase.Page = atoi(Buff);
   ooIdBase.Slot = atoi(&RefStr[N]);

   return RetRef = *(ooId *)&ooIdBase;
}

//===========================================================================
// Methods of class ooCursor(ooObj)
//===========================================================================

//---------------------------------------------------------------------------
ooCursor(ooObj)::ooCursor(ooObj)(const uint32 NewVisSize,
                                 const uint32 NewInitSize,
                                 const uint32 NewPercGrow)
//---------------------------------------------------------------------------
{
// Initialize cursor attributes

   QuerySize  = 0;
   VisSize    = NewVisSize;
   InitSize   = NewInitSize;
   PercGrow   = NewPercGrow;
	FuncPtr    = NULL;
   HndArr     = new ooHandle(ooObj)[VisSize];
   Index      = 0;
	MapItr     = NULL;

// Resize cursor array

	RefArr.resize(NewInitSize);
}

//---------------------------------------------------------------------------
ooStatus ooCursor(ooObj)::init(const ooHandle(ooObj) &Scope,
                         	    const char            *Pred)
//---------------------------------------------------------------------------
{
	assert(0);
	return oocError;
}
//---------------------------------------------------------------------------
ooStatus ooCursor(ooObj)::init(ooMapItr *NewMapItr)
//---------------------------------------------------------------------------
{
	MapItr  = NewMapItr;
	SQLFlag = oocFalse;                                                                  
																													 
	while (QuerySize < InitSize)                                                         
	{                                                                                    
		if ((*MapItr).next())                                                            
		{                                                                                 
			RefArr[QuerySize] = (*MapItr)->oid();                                                
			QuerySize++;                                                                   
			if (FuncPtr != NULL)                                                           
			{                                                                              
				if ((*FuncPtr)(QuerySize) != oocTrue)                                      
				{                                                                           
					break;    				                                                    
				}                                                                           
			}                                                                             
		}                                                                               
		else                                                                           
		{                                                                               
			MapItr = NULL;                                                               
			break;			                                                              
		}                                                                              
	}                                                                                
   first();                                              			                 
                                                                                  
	return oocSuccess;                                                            
}
//---------------------------------------------------------------------------
ooStatus ooCursor(ooObj)::clear()
//---------------------------------------------------------------------------
{
	QuerySize  = 0;
   Index      = 0;

   for (int32 i =0; i< VisSize;i++)
   {
		HndArr[i] = NULL;
	}

// Resize cursor array
 
   return RefArr.resize(InitSize);
	
}
//---------------------------------------------------------------------------
ooBoolean ooCursor(ooObj)::isQueryComplete()
//---------------------------------------------------------------------------
{
	//assert(0); geht nicht, da auch ein Cursor auf ooObj benutzt wird
	return oocTrue;
}
//---------------------------------------------------------------------------
void ooCursor(ooObj)::resize(const uint32 NewSize)
//---------------------------------------------------------------------------
{
   RefArr.resize(NewSize);
}
//---------------------------------------------------------------------------
ooCursor(ooObj)::~ooCursor(ooObj)()
//---------------------------------------------------------------------------
{
   delete [] HndArr;
}
//---------------------------------------------------------------------------
ooStatus ooCursor(ooObj)::addEntry(const ooHandle(ooObj)& Hnd)
//---------------------------------------------------------------------------
{
	if (Hnd == NULL)
	{
		ooSignal(oocUserError,
					CursEntryIsNullErr,
					NULL);

		return oocError;
	}

	if (RefArr.size() == QuerySize)                                             
	{                                                                           
// Cursor array need to be resized

		RefArr.resize(RefArr.size() * (1 + PercGrow * 0.01));                    
	}                                                                           
	RefArr[QuerySize] = Hnd;

	QuerySize++;

	return oocSuccess;
}
//---------------------------------------------------------------------------
ooStatus ooCursor(ooObj)::insEntry(const ooHandle(ooObj) &Hnd,
                                   const uint32           Pos)
//---------------------------------------------------------------------------
{
	if (Pos > QuerySize)
	{
		ooSignal(oocUserError,
					CursIndexExceedVisSizeErr,
					NULL);

		return oocError;
	}

	if (RefArr.size() == QuerySize)                                             
	{                                                                           
// Cursor array need to be resized

		RefArr.resize(RefArr.size() * (1 + PercGrow * 0.01));                    
	}                                                                           

   for (uint32 N = QuerySize; N > Pos; N--)
   {
      RefArr[N] = RefArr[N - 1];
   }

   RefArr[Pos] = Hnd;

   QuerySize++;

	if (Pos >= Index &&
		 Pos < Index + VisSize)
   {
// Refresh visible area

      for (uint32 M = 0; M < VisSize; M++)
      {
         HndArr[M] = RefArr[M + Index];
      }
	}

	return oocSuccess;
}
//---------------------------------------------------------------------------
ooStatus ooCursor(ooObj)::insEntryBefore(const ooHandle(ooObj) &Hnd,
                                         const ooHandle(ooObj) &Scope)
//---------------------------------------------------------------------------
{
	if (Scope == NULL)
	{
		ooSignal(oocUserError,
					CursScopeIsNullErr,
					NULL);

		return oocError;
	}

// Lookup scope entry

   for (uint32 N = 0; N < QuerySize; N++)
   {
      if (RefArr[N] == Scope)
      {
         return insEntry(Hnd,
                         N);
      }
   }

	ooSignal(oocUserError,
				CursScopeNotFoundErr,
				&Scope);

	return oocError;
}
//---------------------------------------------------------------------------
ooStatus ooCursor(ooObj)::insEntryAfter(const ooHandle(ooObj) &Hnd,
                                        const ooHandle(ooObj) &Scope)
//---------------------------------------------------------------------------
{
	if (Scope == NULL)
	{
		ooSignal(oocUserError,
					CursScopeIsNullErr,
					NULL);

		return oocError;
	}

// Search scope entry

   for (uint32 N = 0; N < QuerySize; N++)
   {
      if (RefArr[N] == Scope)
      {
         return insEntry(Hnd,
                         N + 1);
      }
   }

	ooSignal(oocUserError,
				CursScopeNotFoundErr,
				&Scope);

	return oocError;
}
//---------------------------------------------------------------------------
ooHandle(ooObj) ooCursor(ooObj)::getAbsoluteEntry(const uint32 NewIndex)
//---------------------------------------------------------------------------
{
	return fetchEntry(NewIndex);
}
//---------------------------------------------------------------------------
ooHandle(ooObj) ooCursor(ooObj)::getEntry(const uint32 NewIndex)
//---------------------------------------------------------------------------
{
	if (NewIndex >= VisSize)
	{
		ooSignal(oocUserError,
					CursIndexExceedVisSizeErr,
					NULL);
		return NULL;
	}

	return HndArr[NewIndex];
}
//---------------------------------------------------------------------------
ooHandle(ooObj) ooCursor(ooObj)::fetchEntry(const uint32 SearchIndex)
//---------------------------------------------------------------------------
{
	if (SearchIndex < QuerySize)
	{
		return (ooRef(ooObj) &)RefArr[SearchIndex];
	}                                
	else if (MapItr != NULL)                                                        		 
	{                                                                                    
		while (QuerySize < SearchIndex + 1)                                               
		{                                                                                 
			if ((*MapItr).next())                                                         
			{                                                                              
				if (RefArr.size() == QuerySize)                                             
				{                                                                           
					int NewSize = (int)(RefArr.size() * (1 + PercGrow * 0.01));					 
					if (NewSize <= RefArr.size())															 
						NewSize = RefArr.size()+1;															 
					RefArr.resize(NewSize);											                   
				}                                                                           
				RefArr[QuerySize] = (*MapItr)->oid();                                             
				QuerySize++;                                                                
				if (FuncPtr != NULL)                                                        
				{                                                                           
					if ((*FuncPtr)(QuerySize) != oocTrue)                                    
					{                                                                        
						return NULL;                                                          
					}                                                                        
				}                                                                           
			}                                                                              
			else                                                                           
			{                                                                              
				MapItr = NULL;                                                             
				return NULL;                                                                
			}                                                                              
		}                                                                                 
		return (ooRef(ooObj) &)RefArr[SearchIndex];                                           
	}                                                                                    
	else if (SQLFlag)
	{
		ooRef(ooObj) TmpRef;
		while (QuerySize < SearchIndex + 1)
		{
			if (getNextRef(TmpRef) != NULL)
			{
				if (RefArr.size() == QuerySize)
				{
					RefArr.resize(RefArr.size() * (1 + PercGrow * 0.01));
				}
				RefArr[QuerySize] = (ooRef(ooObj) &)TmpRef;
				QuerySize++;
				if (FuncPtr != NULL)
				{
					if ((*FuncPtr)(QuerySize) != oocTrue)
					{
						return NULL;
					}
				}
			}
			else
			{
				SQLFlag = oocFalse;
				return NULL;
			}
		}
		return (ooRef(ooObj) &)RefArr[SearchIndex];
	}
	return NULL;
}

//---------------------------------------------------------------------------
ooStatus ooCursor(ooObj)::delEntry(const ooHandle(ooObj) &Hnd)
//---------------------------------------------------------------------------
{
	if (Hnd == NULL)
	{
		ooSignal(oocUserError,
					CursEntryIsNullErr,
					NULL);

		return oocError;
	}

// Search object

   for (uint32 N = 0; N < QuerySize; N++)
   {
      if (RefArr[N] == Hnd)
      {
         return delEntry(N);
      }
   }

	ooSignal(oocUserError,
				CursEntryNotFoundErr,
				&Hnd);

   return oocError;
}
//---------------------------------------------------------------------------
ooStatus ooCursor(ooObj)::delEntry(const uint32 Pos)
//---------------------------------------------------------------------------
{
   if (Pos >= QuerySize)
   {
		ooSignal(oocUserError,
					CursIndexExceedQuerySizeErr,
					NULL);

      return oocError;
   }

// Shift array entries

   for (uint32 N = Pos + 1; N  < QuerySize; N++)
   {
      RefArr[N - 1] = RefArr[N];
   }  

	QuerySize--;

	if (Pos <= Index + VisSize)
   {
// Shift visible area

		prev(1);
	}

   return oocSuccess;
}
//---------------------------------------------------------------------------
ooBoolean ooCursor(ooObj)::next(const uint32 StepNum)
//---------------------------------------------------------------------------
{
   if ((int)(Index + StepNum) <= (int)(QuerySize - VisSize))
   {
      Index += StepNum;

      for (uint32 N = 0; N < VisSize; N++)
      {
         HndArr[N] = RefArr[N + Index];
      }

      return oocTrue;
   }
   else
   {
      return oocFalse;
   }
}
//---------------------------------------------------------------------------
ooBoolean ooCursor(ooObj)::prev(const uint32 StepNum)
//---------------------------------------------------------------------------
{
   if (StepNum <= Index)
   {
      Index -= StepNum;

      for (uint32 N = 0; N < VisSize; N++)
      {
         HndArr[N] = RefArr[N + Index];
      }

      return oocTrue;
   }
   else
   {
      return oocFalse;
   }
}
//---------------------------------------------------------------------------
ooBoolean ooCursor(ooObj)::first()
//---------------------------------------------------------------------------
{
   uint32 N;

   Index = 0;

   if (QuerySize < VisSize)
   {
      for ( N = 0; N < QuerySize; N++)
      {
         HndArr[N] = RefArr[N];
      }

      for (; N < VisSize; N++)
      {
         HndArr[N] = NULL;
      }
   }
   else
   {
      for ( N = 0; N < VisSize; N++)
      {
         HndArr[N] = RefArr[N];
      }
   }

   return oocTrue;
}
//---------------------------------------------------------------------------
ooBoolean ooCursor(ooObj)::last()
//---------------------------------------------------------------------------
{
   Index = QuerySize - VisSize;

   for (uint32 N = 0; N < VisSize; N++)
   {
      HndArr[N] = RefArr[N + Index];
   }

   return oocTrue;
}
//---------------------------------------------------------------------------
uint32 ooCursor(ooObj)::getQuerySize() const
//---------------------------------------------------------------------------
{
   return QuerySize;
}
//---------------------------------------------------------------------------
ooStatus ooCursor(ooObj)::operator+=(const ooHandle(ooObj) &Hndl)
//---------------------------------------------------------------------------
{
   return addEntry(Hndl);
}

//---------------------------------------------------------------------------
ooHandle(ooObj) ooCursor(ooObj)::operator[](const uint32 SearchIndex)
//---------------------------------------------------------------------------
{
   return fetchEntry(SearchIndex);
};
//---------------------------------------------------------------------------
ooStatus ooCursor(ooObj)::registerCallback(ooCursorFuncPtr NewFuncPtr)
//---------------------------------------------------------------------------
{
	FuncPtr = NewFuncPtr;

	return oocSuccess;
}
//-----------------------------------------------------------------------------
ooStatus ooCursor(ooObj)::connectCursor(const char *QueryExpr,
													 const char *Server,
													 const char *User,
													 const char *PassWord)
//-----------------------------------------------------------------------------
{
#ifdef SQL	
   RETCODE RetCode;
   SDWORD  OIDSize;

// Allocate environment

   ooSQLAllocEnv(&Env);
   ooSQLAllocConnect(Env,
                     &Conn);

// Connect to database

   RetCode = ooSQLConnect(Conn,
                          (UCHAR *)Server,
                          SQL_NTS,
                          (UCHAR *)User,
                          SQL_NTS,
                          (UCHAR *)PassWord,
                          SQL_NTS);

   if (RetCode != SQL_SUCCESS &&
       RetCode != SQL_SUCCESS_WITH_INFO)
   {
// Signal connection error

		ooSignal(oocUserError,
					CursSQLConnErr,
					NULL);

      return oocError;
   }
                        
// Allocate statement

   ooSQLAllocStmt(Conn,
                  &Stat);

// Initialize SQL query

   RetCode = ooSQLExecDirect(Stat,
                             (UCHAR *)QueryExpr,
                             SQL_NTS);

   if (RetCode != SQL_SUCCESS)
   {
		ooSignal(oocUserError,
					CursQueryExecErr,
					NULL);

      return oocError;
   }

// Bind columns

   ooSQLBindCol(Stat,
                1,
                SQL_C_CHAR,
                ooIdBase,
                12,
                &OIDSize);
#endif
	return oocSuccess;
}
//-----------------------------------------------------------------------------
ooRef(ooObj) &ooCursor(ooObj)::getNextRef(ooRef(ooObj) &RetRef)
//-----------------------------------------------------------------------------
{
#ifdef SQL
   RETCODE RetCode;

// Fetch new column

	RetCode = ooSQLFetch(Stat);

	if (RetCode == SQL_ERROR ||
		 RetCode == SQL_SUCCESS_WITH_INFO)
	{
		return (RetRef = NULL);
	}
	else if (RetCode == SQL_SUCCESS ||
				RetCode == SQL_SUCCESS_WITH_INFO)
	{
// Convert ooIdBase string to reference

		return initRef(RetRef,
							(char *)ooIdBase);
	}
	else
	{
// Signal fetch column error

		ooSignal(oocUserError,
					CursFetchColErr,
					NULL);

		return (RetRef = NULL);
	}
#else
	return (RetRef = NULL);
#endif
}
