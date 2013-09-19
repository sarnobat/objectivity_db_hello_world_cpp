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

#ifndef ra_navigation_Navigator_h
#define ra_navigation_Navigator_h

#include <objy/ra/navigation/Guide.h>
#include <objy/ra/navigation/policies/policies.h>

namespace objy {namespace ra {namespace navigation
{

  class OO_RA_STORAGE_SPECIFIER Navigator;

  //-----------------------------------------------------------------------------
  class OO_RA_STORAGE_SPECIFIER Qualifier : public objy::ra::PathQualifier
  {
  public:

      enum Kind { ID, PREDICATE, CUSTOM };
      virtual Kind getKind() = 0;
      virtual ooTypeNumber getTargetType() = 0;
  };


  //-----------------------------------------------------------------------------
  class OO_RA_STORAGE_SPECIFIER NavigationResultHandler
  {
  public:
      virtual void handleResultPath(const objy::ra::Path& result, Navigator& navigator) = 0;
      virtual void handleNavigatorFinished(Navigator& navigator) = 0;
  };


  //-----------------------------------------------------------------------------
  class OO_RA_STORAGE_SPECIFIER Navigator
  {
  public:

      Navigator(
          const ooId& navigateFrom,
          GraphView& view,
          Qualifier& resultQualifier,
          NavigationResultHandler& resultHandler,
          const policies::PolicyList* policies = NULL,
          Qualifier* pathQualifier = NULL,
          Guide* guide = NULL);

      // Management of navigator run
      void start();
      void stop();

      // Access to navigator components
      GraphView&                getGraphView() const;
      Qualifier&                getResultQualifier() const;
      NavigationResultHandler&  getResultHandler() const;
      Qualifier*                getPathQualifier() const;
      Guide*                    getGuide() const;

      void addNavigationListener(NavigationListener* listener);

      // dtor
      ~Navigator();
      class Impl;

  private:
      Impl* mImpl;
  };


} // end namespace navigation
} // end namespace ra
} // end namespace objy

#endif /* ra_navigation_Navigator_h */
