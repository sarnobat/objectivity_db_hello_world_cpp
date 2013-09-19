
/**************************************************************************
		    Copyright (c) 2005 Objectivity, Inc.
			  All Rights Reserved	

	THIS IS UNPUBLISHED PROPRIETARY SOURCE CODE OF OBJECTIVITY, INC.
	
	The copyright notice above does not evidence any
	actual or intended publication of such source code.

*****************************************************************************/

// Parallel Query Engine public declarations

#ifndef OO_PQE_H
#define OO_PQE_H "@(#)$Id$"

#include <oo.h>

namespace objy { namespace query
{
  class ObjectQualifier;
  class Expression;
}}

// ----  Client-side customization hooks  ----

class OO_STORAGE_SPECIFIER ooQuerySplitter
{
 private:
  ooQuerySplitter* mSplitterImp;
 public:
  ooQuerySplitter();
  virtual ~ooQuerySplitter();
  virtual void initScan(const ooHandle(ooObj)& storageObject,
			ooTypeNumber typeN, const objy::query::Expression* predicate);
  virtual ooBoolean nextRange(ooLongId & start, ooLongId & end);
  virtual void endScan();
  virtual ooBoolean applicableDB(const ooHandle(ooDBObj)& dbh,
				 ooBoolean* filterContsPtr);
  virtual ooBoolean applicableCont(const ooHandle(ooContObj)& ch);
  virtual ooBoolean nextDB(ooHandle(ooDBObj)& dbh, ooBoolean* filterContsPtr);
  virtual ooBoolean nextCont(ooHandle(ooContObj)& conth);
  virtual ooBoolean applicableObject(const ooLongId & objId);
};

// OBJY-18505 - revised task assigner mechanism
class opqQueryAgent;
class OO_STORAGE_SPECIFIER ooTaskServerGroup {
 public:
  //  make an empty group
  static ooTaskServerGroup* create();
  // make a group with one host
  static ooTaskServerGroup* create(const char* hostName);
  // add host to group
  virtual void addHost(const char* hostName) = 0;
  // remove host from group
  virtual bool removeHost(const char* hostName) = 0;
  // return number of hosts in the group
  virtual int nHosts() const = 0;
  // return name of the Nth host
  virtual const char* getHostName(unsigned index) const = 0;
  virtual ~ooTaskServerGroup() {};

  // Internal use only:
  virtual opqQueryAgent* assignTask(const ooLongId& oid, ocmSession* session) = 0;
};

class OO_STORAGE_SPECIFIER ooTaskAssigner {
 public:
  virtual ooTaskServerGroup* assignTask(const ooLongId & oid);
};


class ooQueryFilter {
 public:
  virtual ooBoolean filter(ooHandle(ooObj)& objH) = 0;
  virtual ~ooQueryFilter() { }
};

// ----  Server-side customization hooks  ----
#ifndef OO_FILTER_DLL_EXPORT
#ifdef _DLL
#define OO_FILTER_DLL_EXPORT __declspec(dllexport)
#else
#define OO_FILTER_DLL_EXPORT
#endif
#endif

OO_FILTER_DLL_EXPORT
void ooInitQueryFilter ();

OO_FILTER_DLL_EXPORT
ooQueryFilter* 
ooNewQueryFilter(const char* filterName, ooTypeNumber typeN,
                 const char* predicate,
                 const void* filterData, int filterDataLength,
                 ooBoolean swapBytes);

// Size of stack for each Query Thread may be set by assigning to this
// variable in ooInitQueryFilter.  (Not applicable to Windows)
extern size_t oovQueryThreadStack;


// External Search Agent Query Manager class
//  Used by the agent to report results, report errors, etc..
class oqsResultsBuffer;
class oqsPageResultsBuffer;
class opqConnectionEntryBase;
class ooExternalQueryManager 
{
  public:
    ooExternalQueryManager(oqsResultsBuffer*, oqsPageResultsBuffer*, opqConnectionEntryBase*);
    ~ooExternalQueryManager();
    virtual void reportResult(ooHandle(ooObj)& result);
    virtual void reportError(const char* message);
    virtual ooBoolean cancelledScan();
  private:
    oqsResultsBuffer* oidResultsBuff;
    oqsPageResultsBuffer* pageResultsBuff;
    opqConnectionEntryBase* clientConnection;
    unsigned numReportedObjs;
    unsigned maxResults;
};

// External Query Agent
class ooClusterStrategy;
class ooExternalQueryManager;
class ooExternalQueryAgent
{
  public:
    // Called to execute the users search agent
    virtual void executeAgent(const char* agentParameters,
                              const objy::query::ObjectQualifier* qualifier,
                              ooClusterStrategy& clusterResults,
                              ooExternalQueryManager& manager) = 0;

    virtual ~ooExternalQueryAgent()
    {}
};
#endif // OO_PQE_H
