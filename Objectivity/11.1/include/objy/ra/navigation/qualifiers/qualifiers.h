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

#ifndef ra_navigation_qualifiers_h
#define ra_navigation_qualifiers_h

#include <objy/ra/navigation/Navigator.h>

class oraQualifier;

namespace objy {namespace ra {namespace navigation {namespace qualifiers
{

  //-----------------------------------------------------------------------------
  class OO_RA_STORAGE_SPECIFIER ObjectIdQualifier : public Qualifier
  {
  public:

    ObjectIdQualifier(const ooId& targetObject, ooTypeNumber typeN = 0);

    bool qualify(Path& path);

    const ooId&  getTargetId();
    ooTypeNumber getTargetType();
    Kind getKind();


  private:

    const ooId _targetOid;
    const ooTypeNumber _targetType;
  };

  //-----------------------------------------------------------------------------
  class OO_RA_STORAGE_SPECIFIER PredicateQualifier : public Qualifier
  {
  public:

    PredicateQualifier(ooTypeNumber typeN);
    PredicateQualifier(ooTypeNumber typeN, const char* predicate);
    PredicateQualifier(ooTypeNumber typeN, const wchar_t* predicate);
    PredicateQualifier(const objy::query::ObjectQualifier& objQualifier);

    ~PredicateQualifier();

    const char*  getPredicate();
    const wchar_t*  getWPredicate();
    const oraQualifier* getQualifier() const { return _qualifier; }

    ooTypeNumber getTargetType();
    Kind getKind();

    bool qualify(Path& path);

  private :

    ooTypeNumber _targetType;
    oraQualifier* _qualifier;
  };

  //-----------------------------------------------------------------------------
  class OO_RA_STORAGE_SPECIFIER CustomQualifier : public Qualifier
  {
  public:

    virtual bool qualify(Path& path) = 0;
    virtual ooTypeNumber getTargetType();
    Kind getKind();
  };


} // end namespace qualifiers
} // end namespace navigation
} // end namespace ra
} // end namespace objy

#endif /* ra_navigation_qualifiers_h */
