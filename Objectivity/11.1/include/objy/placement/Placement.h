//***************************************************************************//
//                                                                           //
//                   Copyright © 2011 Objectivity Inc, USA.                  //
//                                                                           //
//    All Rights Reserved. Unauthorized use, duplication or distribution     //
//         of this software, or any portion of it, is prohibited.            //
//                                                                           //
//***************************************************************************//

#if _MSC_VER > 1000
  #pragma once
#endif 

#ifndef placement_Placement_h
#define placement_Placement_h

#ifndef OO_DDL_TRANSLATION

#ifndef ooObjy_h
#include "ooObjy.h"
#endif

#if defined(_MSC_VER) && defined(_DLL)
#   ifdef PLACEMENT_EXPORTS
#      define PLACEMENT_EXPORT __declspec(dllexport)
#   else    
#      define PLACEMENT_EXPORT __declspec(dllimport)
#      ifdef _DEBUG
#        pragma comment(lib, "Placementd.lib")
#      else
#        pragma comment(lib, "Placement.lib")
#      endif
#   endif
#else
#   define PLACEMENT_EXPORT
#endif 

#endif // #ifndef OO_DDL_TRANSLATION

#endif

