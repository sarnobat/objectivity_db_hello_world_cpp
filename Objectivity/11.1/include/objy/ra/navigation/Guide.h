//***************************************************************************//
//
//                Copyright © 2012 Objectivity Inc, USA.
//
//    All Rights Reserved. Unauthorized use, duplication or distribution
//         of this software, or any portion of it, is prohibited.
//
//***************************************************************************//

#if _MSC_VER > 1000
#pragma once
#endif

#ifndef ra_navigation_Guide_h
#define ra_navigation_Guide_h

#include <ooRA.h>

namespace objy {namespace ra {namespace navigation
{

  //-----------------------------------------------------------------------------
  typedef ooTVArrayT<PathStep> HopList;

  //-----------------------------------------------------------------------------
  class OO_RA_STORAGE_SPECIFIER Guide
  {
  public:

      // General Strategy types
      enum Strategy {BREADTH_FIRST, DEPTH_FIRST };

      // Overridden by guide implementations
      virtual Strategy getHopOrder(const ooHandle(ooObj)& currentObj, HopList& order) = 0;

      // Default Guide implementations
      static Guide* const SIMPLE_DEPTH_FIRST;
      static Guide* const SIMPLE_BREADTH_FIRST;
      static Guide* const NONE;

  };


} // end namespace navigation
} // end namespace ra
} // end namespace objy

#endif /* ra_navigation_Guide_h */
