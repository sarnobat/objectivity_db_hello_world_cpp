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

#ifndef ra_navigation_policies_h
#define ra_navigation_policies_h

#include <ooRA.h>

namespace objy {namespace ra {namespace navigation {namespace policies
{

  class PolicyListener;

  //-----------------------------------------------------------------------------
  class OO_RA_STORAGE_SPECIFIER NavigationPolicy
  {
  public:

    virtual void apply(PolicyListener& listener) const = 0;
    virtual bool validate(const PolicyListener& listener) const = 0;
    virtual ~NavigationPolicy(){}
  };

  //-----------------------------------------------------------------------------
  typedef ooTVArrayT<const NavigationPolicy*> PolicyList;


  //-----------------------------------------------------------------------------
  class OO_RA_STORAGE_SPECIFIER MaximumResultCountPolicy : public NavigationPolicy
  {
  public:

    // Policy setup and data
    MaximumResultCountPolicy(unsigned int resultCount = 1);
    unsigned int getResultCount() const;

    // Policy application
    void apply(PolicyListener& spec) const;
    bool validate(const PolicyListener& spec) const;

  private :

    unsigned int _resultCount;
  };

  //-----------------------------------------------------------------------------
  class OO_RA_STORAGE_SPECIFIER MaximumPathDepthPolicy : public NavigationPolicy
  {
  public:

    // Policy setup and data
    MaximumPathDepthPolicy(unsigned int maxDepth);
    unsigned int getMaximumPathDepth() const;

    // Policy application
    void apply(PolicyListener& spec) const;
    bool validate(const PolicyListener& spec) const;

  private :

    unsigned int _maxPathDepth;
  };

  //-----------------------------------------------------------------------------
  class OO_RA_STORAGE_SPECIFIER MaximumMemoryUsePolicy : public NavigationPolicy
  {
  public:

    // Policy setup and data
    MaximumMemoryUsePolicy(size_t bytes);
    size_t getMaximumMemoryUse() const;

    // Policy application
    void apply(PolicyListener& spec) const;
    bool validate(const PolicyListener& spec) const;

  private :

    size_t _maxMemoryUseBytes;
  };

  //-----------------------------------------------------------------------------
  class OO_RA_STORAGE_SPECIFIER MaximumBreadthPolicy : public NavigationPolicy
  {
  public:

  public:

    // Policy setup and data
    MaximumBreadthPolicy(unsigned long maxBreadth);
    unsigned long getMaximumBreadth() const;

    // Policy application
    void apply(PolicyListener& spec) const;
    bool validate(const PolicyListener& spec) const;

  private :

    unsigned long _maxBreadth;
  };

  //-----------------------------------------------------------------------------
  class OO_RA_STORAGE_SPECIFIER UseDistributedNavigation : public NavigationPolicy
  {
  public:

    // Policy setup and data
    UseDistributedNavigation(){};

    // Policy application
    void apply(PolicyListener& spec) const;
    bool validate(const PolicyListener& spec) const;
  };

  //-----------------------------------------------------------------------------
  class OO_RA_STORAGE_SPECIFIER UseIGModelPolicy : public NavigationPolicy
  {
  public:

    // Policy setup and data
    UseIGModelPolicy(){};

    // Policy application
    void apply(PolicyListener& spec) const;
    bool validate(const PolicyListener& spec) const;
  };

  //-----------------------------------------------------------------------------
  class OO_RA_STORAGE_SPECIFIER FanoutLimitPolicy : public NavigationPolicy
  {
  public:

    // Policy setup and data
    FanoutLimitPolicy(unsigned int fanoutLimit);
    unsigned int getFanoutLimit() const;

    // Policy application
    void apply(PolicyListener& spec) const;
    bool validate(const PolicyListener& spec) const;

  private :

    unsigned int _fanoutLimit;
  };

  //-----------------------------------------------------------------------------
  class OO_RA_STORAGE_SPECIFIER PathDepthBeyondShortestPolicy : public NavigationPolicy
  {
  public:

    // Policy setup and data
      PathDepthBeyondShortestPolicy(unsigned int pathDepthBeyondShortestLimit);
    unsigned int getNonShortestPathLimit() const;

    // Policy application
    void apply(PolicyListener& spec) const;
    bool validate(const PolicyListener& spec) const;

  private :

    unsigned int _pathDepthBeyondShortestLimit;
  };

  //-----------------------------------------------------------------------------
  class OO_RA_STORAGE_SPECIFIER NoRevisitPolicy : public NavigationPolicy
  {
  public:

    // Policy setup and data
    NoRevisitPolicy(){};

    // Policy application
    void apply(PolicyListener& spec) const;
    bool validate(const PolicyListener& spec) const;
  };

  //-----------------------------------------------------------------------------
  class OO_RA_STORAGE_SPECIFIER OneWayPathfindingPolicy : public NavigationPolicy
  {
  public:

    // Policy setup and data
    OneWayPathfindingPolicy(){};

    // Policy application
    void apply(PolicyListener& spec) const;
    bool validate(const PolicyListener& spec) const;
  };

  //-----------------------------------------------------------------------------
  class OO_RA_STORAGE_SPECIFIER ThreadPolicy : public NavigationPolicy
  {
  public:

    // Policy setup and data
    ThreadPolicy(unsigned int threadCount = 0);
    unsigned int getThreadCount() const;

    // Policy application
    void apply(PolicyListener& spec) const;
    bool validate(const PolicyListener& spec) const;

  private :

    unsigned int _threadCount;
  };

  //-----------------------------------------------------------------------------
  class OO_RA_STORAGE_SPECIFIER EdgeTraversalPolicy : public NavigationPolicy
  {
  public:

    // Flags for determining allowed traversal direction
    static const unsigned char ALLOW_ONEWAY;
    static const unsigned char ALLOW_INCOMING;
    static const unsigned char ALLOW_OUTGOING;
    static const unsigned char ALLOW_BIDIRECTIONAL;
    static const unsigned char DEFAULT;

    // Policy setup and application
    EdgeTraversalPolicy(unsigned char flags);
    unsigned char getFlags() const;

    // Policy application
    void apply(PolicyListener& spec) const;
    bool validate(const PolicyListener& spec) const;

  private :

    unsigned char _flags;
  };

} // end namespace policies
} // end namespace navigation
} // end namespace ra
} // end namespace objy


#endif /* ra_navigation_policies_h */
