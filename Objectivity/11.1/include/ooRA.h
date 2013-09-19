                                    /*  -*- indent-tabs-mode: nil -*-  */
//***************************************************************************//
//                                                                           //
//             Copyright © 2010, 2012 Objectivity Inc, USA.                  //
//                                                                           //
//    All Rights Reserved. Unauthorized use, duplication or distribution     //
//         of this software, or any portion of it, is prohibited.            //
//                                                                           //
//***************************************************************************//

// This file declares the public interface for the generic link iterator
// and path finder.

#ifndef OO_RA_H
#define OO_RA_H

#include <oo.h>

// Increment this number when a change is made to the public API.
#define OO_RA_API_VERSION 6

namespace ooas
{
  class d_Class;
  class d_Attribute;
}

#ifndef OO_RA_STORAGE_SPECIFIER
#define OO_RA_STORAGE_SPECIFIER OO_STORAGE_SPECIFIER
#endif

class oraGraphViewData;
class oraIterator;
class oraPathIterator;
class oraParallelIterator;
class oraServerPlugin;
class OO_STORAGE_SPECIFIER ooTaskAssigner;

namespace objy { namespace task {
  struct TaskGroupStatistics;
} }

namespace objy { namespace query {
  class ObjectQualifier;
}}

namespace objy { namespace ra
{

class OO_RA_STORAGE_SPECIFIER GraphView
{
public:
  GraphView(const ooHandle(ooFDObj)& fd);
  GraphView(const GraphView& base);
  ~GraphView();

  void excludeClass(ooTypeNumber typeN, const char* predicate = NULL);
  void excludeClass(ooTypeNumber typeN, const wchar_t* predicate);
  void excludeClass(const objy::query::ObjectQualifier& objQualifier);

  void includeClass(ooTypeNumber typeN, const char* predicate = NULL);
  void includeClass(ooTypeNumber typeN, const wchar_t* predicate);
  void includeClass(const objy::query::ObjectQualifier& objQualifier);

  void excludeAttribute(const ooas::d_Attribute& attribute);
  void excludeAttribute(ooTypeNumber typeN, const char* attribute_name);

  void excludeObject(const ooId& obj);

  ooStatus edgeClass(ooTypeNumber typeN, const char* fromLink = NULL,
                     const char* toLink = NULL, bool hidden = false,
                     ooTypeNumber fromTypeN = 0, ooTypeNumber toTypeN = 0);

  // For internal use only:
  const oraGraphViewData* getInternalData() const { return viewData; }
private:
  oraGraphViewData* viewData;
  GraphView & operator=(const GraphView &); // not defined
};

class OO_RA_STORAGE_SPECIFIER PathStep
{
public:
  PathStep();
  const ooas::d_Attribute* attribute;
  ooRef(ooObj)             edgeObject;
  const ooas::d_Class *    edgeClass;
  ooRef(ooObj)             relatedObject;
  const ooas::d_Class *    relatedClass;
};
   
class OO_RA_STORAGE_SPECIFIER Path : public ooTVArrayT<PathStep>
{
public:
  Path() { }

  // Inherited methods:
  //  uint32      size() const;  // number of array elements
  //  PathStep* head() const;  // the array of steps
  //  PathStep& operator[](uint32 index) const; // an individual step

  ooRef(ooObj) startingObject;
  PathStep& getFinalStep() const; // shortcut to the last step
};

class PathQualifier
{
public:
  virtual bool qualify(Path& path) = 0;
  virtual ~PathQualifier() { }
};

// Statistical counters.  (Experimental; likely to change)
struct OO_RA_STORAGE_SPECIFIER GraphTraversalCounters
{
  unsigned long targetNodesReported;
  unsigned long targetNodesDisqualifiedByPredicate;
  unsigned long targetNodesDisqualifiedByResultQualifier;
  unsigned long nodeObjectsOpened;
  unsigned long edgeObjectsOpened;
  unsigned long disqualifiedByClass; // instances of unconditionally excluded subclass of included link class
  unsigned long disqualifiedByPredicate; // objects excluded by predicate
  unsigned long pathsDisqualifiedByUser; // path qualifier returned false
  unsigned long prunedObjectByDepthLimit;// objects not opened because of depth limit
  unsigned long prunedLinkByDepthLimit;// links not followed because of depth limit
  unsigned long prunedObjectInNonShortestPath; // seen before in shorter path
  unsigned long referencesQueued;     // OIDs queued to be visited
  unsigned long referencesSeenBefore; // references skipped because queued previously
  unsigned      invalidReferences; // invalid references ignored
  unsigned      invalidObjects;    // corrupted objects ignored
  unsigned      relevantClasses;   // classes included in the graph
  unsigned      automaticallyExcludedClasses; // classes with no relevant data
  unsigned      automaticallyExcludedCollectionLinks; // links to collections with irrelevant element type
  unsigned long largeGroupsSkipped; // how many times the fan-out limit was imposed
  unsigned long objectIdsSeen;      // number of OIDs in hash table (1st visit)
  unsigned long objectIdsRevisited; // number of OIDs in secondary path
  long          referencesInQueue;  // OIDs currently in visitation queue
  unsigned long prunedByReverseScan; // didn't intersect destination set
  unsigned long nonDestAtDepthLimit; // node at max depth is not destination
};

typedef bool (*SurrogateFn)(/* in: */ ooHandle(ooObj)& surrogateH,
			/* out: */ ooHandle(ooObj)& realNodeH,
			/* out: */ ooTypeNumber* class_number_ptr);

// Abstract base class for user-defined visitation customization:
class OO_RA_STORAGE_SPECIFIER CustomVisitor
{
 public:
  CustomVisitor() : iterator_state(NULL) { }
  virtual ~CustomVisitor() { }

  // The user-written subclass needs to define this method
  // which will be called for each applicable object:
  virtual ooStatus
  visit(ooHandle(ooObj)& handle,  // the object being visited
        ooTypeNumber typeN,       // the shape number of the object
        bool reverseDirection     // in reverse scan of two-way path finder?
        ) = 0;
  // This method is provided, to be called by the user-written visit method
  // for each related object:
  void report(const ooId& oid,       // object to be visited (ignored if null)
              ooTypeNumber typeN = 0,// shape of referenced object, if known
              const ooId* destOid=0, // OID of node if known when `oid' is edge
              ooTypeNumber destType=0); // shape of connected node

  // This provided method may be called to test whether a class is 
  // relevant to the navigation.  Returns false if the class is
  // unconditionally excluded or has no relevant data. 
  bool includedClass(ooTypeNumber typeN);

  // This provided method may be called to test whether an edge object should
  // be included in the navigation.  This differs from includedClass in that
  // it will also consider any applicable predicate qualifier.
  bool qualifiedObject(ooTypeNumber typeN, ooHandle(ooObj) & object_handle);
  bool qualifiedObject(ooTypeNumber typeN, const ooId & object_id);

 private:
  friend class ::oraIterator;
  oraIterator* iterator_state;
};

struct OO_RA_STORAGE_SPECIFIER ParallelTraversalCounters;

struct OO_RA_STORAGE_SPECIFIER NavigationParameters
{
  ooId starting_object;
  ooId destination_object;
  const ooas::d_Class * destination_class;
  int starting_depth;
  int maximum_depth; 
  long maximum_breadth;
  unsigned fanout_limit;
  int non_shortest_path_limit; 
  bool depth_first; 
  bool all_paths;
  bool sorted_page_order;
  bool parallel;
};

class OO_RA_STORAGE_SPECIFIER NavigationListener
{
public:
  virtual void onNavigationStart(const NavigationParameters& params) { }
  virtual void onNavigationEnd(const GraphTraversalCounters* counters,
                               const ParallelTraversalCounters* pc,
                               const GraphTraversalCounters* cumulative,
                               const objy::task::TaskGroupStatistics* tc)
    { }
  virtual ~NavigationListener() { }
};

// A listener that writes statistics to the session log.
class OO_RA_STORAGE_SPECIFIER NavigationLogger : public NavigationListener
{
public:
  NavigationLogger() { }
  void onNavigationStart(const NavigationParameters& params);
  void onNavigationEnd(const GraphTraversalCounters* counters,
                       const ParallelTraversalCounters* parallel_counters,
                       const GraphTraversalCounters* cumulative,
                       const objy::task::TaskGroupStatistics* task_counters);
};

class OO_RA_STORAGE_SPECIFIER ItrRelatedBase
{
 public:
  // Constructor
  ItrRelatedBase(ooTypeNumber targetTypeN,
                 bool depth_first = false, bool all_paths = false);
  ~ItrRelatedBase();

  // Methods modeled after ooItr(T):
  ooStatus navigate(const ooId& sourceObject, const char* predicate = NULL);
  ooStatus navigate(const ooId& sourceObject, const wchar_t* predicate);
  ooStatus navigate(const ooId& sourceObject,
                    const objy::query::ObjectQualifier& objQualifier);
  void set_typeN(const ooTypeNumber typeN); 

  void optimizeScanOrder(bool state);
  bool getOptimizeScanOrder() const;
  static void setDefaultOptimizeScanOrder(bool state);
  static bool defaultOptimizeScanOrder();

  void cancel(); // stop navigation (may be called from another thread)

  void addNavigationListener(NavigationListener* listener);

protected:
  ItrRelatedBase(oraIterator* in_iterator); // internal use only
  bool get_next_result(/* out: */ ooHandle(ooObj)* phandle);
  void end_iteration();

  ItrRelatedBase() { };

public:
  // Locally defined methods to set search parameters
  void applyView(const GraphView& view); // for internal use
  void setMaximumSeparation(unsigned int); // maximum depth
  // Set maximum breadth. [experimental]
  // A breadth-first navigation will end if the next level has more than 
  // this many objects to be visited.
  void setMaximumBreadth(unsigned long); 
  // Set maximum memory usage. [experimental]
  // An exception will be thrown if the limit is exceeded.
  void setMaximumMemory(size_t bytes);
  void setFanoutLimit(unsigned max_edges); // maximum edges from one node
  void setNonShortestPathLimit(int n);

  void usePlugin(const char* name,
                 const char* options = NULL, size_t optionsLength = 0);
  void setPathQualifier(PathQualifier& qualifier,
                        ooTypeNumber typeN = oocObjTypeN, // ooTypeN(ooObj)
                        const char* predicate = NULL);
  void setPathQualifier(PathQualifier& qualifier,
                        const objy::query::ObjectQualifier& objQualifier);
  ooStatus surrogateNodeClass(ooTypeNumber typeN, SurrogateFn callback);
  ooStatus customVisitor(ooTypeNumber objectType, CustomVisitor& visitor,
                         bool replaceDefaultProcessing,
                         ooTypeNumber referencedBaseType = oocObjTypeN);
  void setResultQualifier(PathQualifier& qualifier);

  GraphView* getView();

  // Locally defined methods related to the current object
  unsigned int separation() const;
  void path( /* out: */ Path& pathReturnVal) const;
  void prune();

  GraphTraversalCounters count;

 protected:
  oraIterator* iterator_state;
  bool validate_state() const;
  friend class ::oraServerPlugin;
};

template<class T>
class ItrRelated : public ooHandle(T), public ItrRelatedBase
{
 public:
  ItrRelated(const GraphView& view,
               bool depth_first = false, bool all_paths = false)
    : ItrRelatedBase(ooTypeN(T), depth_first, all_paths)
    { applyView(view); }

  ItrRelated(bool depth_first = false, bool all_paths = false)
    : ItrRelatedBase(ooTypeN(T), depth_first, all_paths)
    { }

  bool next() { return get_next_result(this); }

  void end() // end the iteration
    {
      ooHandle(T)::nullify();  // clear the handle
      end_iteration(); // release resources
    }
 protected:
  // for internal use only
  ItrRelated(oraIterator* in_iterator) : ItrRelatedBase(in_iterator) { }
};

// Path finder
class OO_RA_STORAGE_SPECIFIER PathIterator : public Path,
                                             public ItrRelatedBase
{
public:
  PathIterator(const ooId& sourceObject, const ooId& otherObject);
  PathIterator(const ooId& sourceObject, const ooId& otherObject,
               const GraphView& view, bool all_paths = true,
               bool depth_first = false, bool enable_two_way = true);
  ~PathIterator();
  bool getTwoWayOption() const { return two_way; } // was two-way scan used?
  bool next();
  void end();

protected:
  const ooId start;
  const ooId destination;
  bool two_way;
  bool setup_done;
  oraPathIterator* path_iterator;
  // for internal use only
  PathIterator(oraIterator* in_iterator, const ooId& sourceObject,
               const ooId& otherObject, const GraphView& view);

private:
  // Block the inherited method `path' which is not needed here.
  void path( /* out: */ Path& pathReturnVal) const;
  // The following are declared private to block use of the inherited method.
  ooStatus navigate(const ooId& sourceObject, const char* predicate = NULL);
  ooStatus navigate(const ooId& sourceObject, const wchar_t* predicate);
  ooStatus navigate(const ooId& sourceObject, const objy::query::ObjectQualifier& objQualifier);
  void set_typeN(const ooTypeNumber typeN); 
  void setResultQualifier(PathQualifier& qualifier);
};

// Abstract base class for user-defined plugins:
class NavigatorPlugin
{
  public:
    virtual ~NavigatorPlugin() { }
    // Called exactly once, after constructing:
    virtual void parseOptions(const char* options, size_t optionsLength) = 0;
    // Called for each task:
    virtual void* setTaskOptions(ItrRelatedBase& iterator) = 0;
    // Called at the end of the task:
    virtual void taskEnded(ItrRelatedBase& iterator, void*) = 0;
};

// Statistical counters.  (Experimental; likely to change)
struct OO_RA_STORAGE_SPECIFIER ParallelTraversalCounters {
  unsigned tasksGenerated;   // number of parallel tasks queued
  unsigned resultsReceived;  // results received from parallel tasks
  unsigned duplicateTargets; // same result from more than one task
  unsigned reSplitTasks;     // new sub-tasks from remote split
  unsigned nonShortestPaths; // ignored paths longer than the shortest
};

class OO_RA_STORAGE_SPECIFIER ParallelItrRelatedBase : public ItrRelatedBase
{
public:
  ParallelItrRelatedBase(ooTypeNumber typeN, 
                         bool depth_first = false, bool all_paths = false,
                         unsigned int maximum_depth = 0,
                         bool return_paths = true, bool shortest_only = true);
  ~ParallelItrRelatedBase();
  bool waitNext(int milliseconds);

  void setAssigner(ooTaskAssigner& assigner);
  ooTaskAssigner& getAssigner() const;

  ParallelTraversalCounters parallel_counters;
  // The cumulative_counters are totals from the parallel tasks.
  // Not all fields are maintained here, so some will remain zero.
  // This is experimental and subject to change.
  GraphTraversalCounters    cumulative_counters;
  const objy::task::TaskGroupStatistics* taskCounters() const;

private:
  // Block inheritance of these which won't work for parallel navigation.
  void prune();
  void optimizeScanOrder(bool state);
  bool getOptimizeScanOrder() const;
  ooStatus surrogateNodeClass(ooTypeNumber typeN, SurrogateFn callback);

protected:
  void applyView(const GraphView& view);
  // Internal data:
  oraParallelIterator* parallel_iterator_state;
};

template<class T>
class ParallelItrRelated : public ooHandle(T), public ParallelItrRelatedBase
{
 public:
  ParallelItrRelated(const GraphView& view,
                     unsigned int maximum_depth = 0,
                     bool return_paths = true, bool all_paths = false,
                     bool shortest_only = false,
                     bool depth_first = false)
    : ParallelItrRelatedBase(ooTypeN(T), depth_first, all_paths,
                             maximum_depth, return_paths, shortest_only)
    { applyView(view); }

  ParallelItrRelated(unsigned int maximum_depth = 0,
                     bool return_paths = true, bool all_paths = false,
                     bool shortest_only = false)
    : ParallelItrRelatedBase(ooTypeN(T), false, all_paths,
                             maximum_depth, return_paths, shortest_only)
    { }

  bool next() { return get_next_result(this); }

  void end() // end the iteration
    {
      ooHandle(T)::nullify();  // clear the handle
      end_iteration(); // release resources
    }
};

class OO_RA_STORAGE_SPECIFIER ParallelPathIterator : public Path,
                                                 public ParallelItrRelatedBase
{
public:
  ParallelPathIterator(const ooId& sourceObject,
                       const ooId& otherObject,
                       unsigned int maximum_depth = 0,
                       bool shortest_only = false);
  ParallelPathIterator(const ooId& sourceObject,
                       const ooId& otherObject, const GraphView& view,
                       unsigned int maximum_depth = 0,
                       bool shortest_only = false, bool all_paths = true,
                       bool depth_first = false, bool enable_two_way = true);
  bool getTwoWayOption() const { return two_way; } // was two-way scan used?
  bool next();
  void end() { end_iteration(); }

  ooStatus complete_setup(); // for internal use
private:
  const ooId start;
  const ooId destination;
  bool two_way;
  bool setup_done;
};

} // end namespace ra
} // end namespace objy
#endif
