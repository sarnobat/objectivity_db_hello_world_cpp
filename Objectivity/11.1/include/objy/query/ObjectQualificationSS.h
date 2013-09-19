//***************************************************************************//
//                                                                           //
//                Copyright © 2007 Objectivity Inc, USA.                     //
//                                                                           //
//    All Rights Reserved. Unauthorized use, duplication or distribution     //
//         of this software, or any portion of it, is prohibited.            //
//                                                                           //
//***************************************************************************//
#ifndef ObjectQualificationSS_h 
#define ObjectQualificationSS_h

//-----------------------------------------------------------------------------
#ifndef  OQ_STORAGE_SPECIFIER
#  if defined(_MSC_VER) && defined(_DLL)
#     define OQ_STORAGE_SPECIFIER    __declspec(dllimport)
#     ifdef _DEBUG
#       pragma comment(lib, "ooObjectQualificationd.lib")
#     else
#       pragma comment(lib, "ooObjectQualification.lib")
#     endif
#  else
#     define OQ_STORAGE_SPECIFIER
#  endif 
#endif 

#ifndef OO_H
#include "oo.h"
#endif

#ifndef OO_INDEX_H
#include "ooIndex.h"
#endif

#ifndef OO_TIME
#include "ooTime.h"
#endif

#include <vector>
#include <iostream>
#include <string>

class ooObjectBaseInt;
class ooClass;
class ooAttributeAccessor;

namespace objy {namespace query
{

//-----------------------------------------------------------------------------
// A list of names (used for token or attribute names).
class OQ_STORAGE_SPECIFIER NameList
{
   public:

      // Constructor
      NameList();
       
      // Destructor
      ~NameList();
       
      // Get the name at the given index from the list
      const char* getName(int index) const;

      // Add a name to the list
      void addName(const char* value);

      // Get the total number of names in the list
      int getNumberOfNames() const;

   private:

#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable : 4251)
#endif
      std::vector<const char*> mNameList;
#ifdef _MSC_VER
#pragma warning(pop)
#endif
};


//-----------------------------------------------------------------------------
// Utilities class for PQLParser
class PQLParserUtilities
{
  public:
    static void convertSpecialChars(const char* originalStr, char* convertedStr);
};

}/* end query namespace */} /* end objy namespace */

#endif
