/**************************************************************************
	    Copyright (c) 1989-2002, 2004, 2007 Objectivity, Inc.
			  All Rights Reserved

	THIS IS UNPUBLISHED PROPRIETARY SOURCE CODE OF OBJECTIVITY, INC.

	The copyright notice above does not evidence any
	actual or intended publication of such source code.

*****************************************************************************/

#ifndef ooClusterStrategy_h
#define ooClusterStrategy_h

namespace objy {namespace placement {
  class PersistentObjectCreator;
  class Conditions;
}}

//-----------------------------------------------------------------------------
class OO_STORAGE_SPECIFIER ooClusterStrategy
{
  public:

    // constants to use with setPagesPerContainer
    enum { fastAccess = 0, reserveSpace = 65000, maximum = 65534 };

    ooClusterStrategy
      (int bits = oocSamePage | oocOtherPage | oocNewPage |
                  oocNewContainer | oocNewDatabase,
       bool ooGCCont = false,
       bool catalogPage = false /* Objectivity internal only */,
       bool ingorePlacementManager = false  /* Objectivity internal only */
      );

    ~ooClusterStrategy();

    // newContainer creates either an ooContObj or an oogcContObj, depending 
    // on the value of _oogcCont, in the same database as nearH. This default
    // behaviour can be changed by overriding newContainer in a sublass of 
    // ooClusterStrategy
    virtual ooHandle(ooContObj)newContainer(const ooHandle(ooObj)& nearH, 
                                            const char* name = 0);

    // newDB creates a new database in the federation of fdH, the database is
    // created in the default directory of fdH and the name of the dataOC is 
    // controlled by the prefix parameter. An index is appended to the prefix 
    // to make the name unique in the federation. This default behaviour can be
    // changed by overriding newDB in a sublass of ooClusterStrategy
    virtual ooHandle(ooDBObj) newDB(ooHandle(ooFDObj)& fdH, 
                                    const char* prefix = "autoDb");

    // tryCreate creates a new object of type typeN, using the specified properties, and 
    // can be called in an override of newObj.
    void* tryCreate(ooTypeNumber typeN, const ooId& nearId, int priority, 
                    bool throwException, int pageLimit);

    void* tryCreate(ooTypeNumber typeN, const ooId& nearId, int priority, 
                    bool throwException)
    {
      return tryCreate(typeN, nearId, priority, throwException, 
                       this->containerPageLimit);
    }
  
    void* tryCreate(ooTypeNumber typeN, const ooId& nearId, int priority)
    {
      return tryCreate(typeN, nearId, priority, this->signalClusteringError(), 
                       this->containerPageLimit);
    }
  
    void* tryCreate(ooTypeNumber typeN, const ooId& nearId)
    {
      return tryCreate(typeN, nearId, this->priorityBits(), 
                       this->signalClusteringError(), this->containerPageLimit);
    }

    // Virtual newObj creates a new object of type typeN, using the instance's _priorityBits, containerPageLimit, and so on.
    virtual void* newObj(ooTypeNumber typeN, const ooId& nearId);

    virtual void* newObj(ooTypeNumber typeN); 

    virtual void* newObj(ooTypeNumber typeN, 
                         const objy::placement::Conditions& conditions); 

    uint16 getContainerPageLimit() const
    {return containerPageLimit;}

    ocmSession* getSession()
    {return session;}

    // If "containerPageLimit" is 0 then we try to make sure that the container page map doesn't become a large object
    // See ooHandle(ooContObj)::maxPagesForSmallPageMap() const;
    void setContainerPageLimit(uint16 pagesPerContainer = reserveSpace)
    {
      containerPageLimit = pagesPerContainer;
      if (containerPageLimit > maximum)
      {
        containerPageLimit = (uint16) maximum;
      }
    }

    int priorityBits() const 
    {return _priorityBits;}

    void setPriorityBits(int bits) 
    {_priorityBits = bits;}

    bool ooGCCont() const 
    {return _ooGCCont;}

    void setOoGCCont(ooBoolean flag) 
    {_ooGCCont = flag;}

    bool signalClusteringError() 
    {return _signalClusteringError;}

    void setSignalClusteringError(ooBoolean s) 
    {_signalClusteringError = s;}

    bool zeroBasicFields() 
    {return _zeroBasicFields;}

    void setZeroBasicFields(ooBoolean zeroBasicFields);

    const objy::placement::PersistentObjectCreator* getPersistentObjectCreator() const
    {return mPersistentObjectCreator;}

    static bool isCollectionRoot(ooTypeNumber typeN);
    static bool isHashBucket(ooTypeNumber typeN);
    static bool isTreeNode(ooTypeNumber typeN);

  private:

    ocmSession* session;
    int _priorityBits;
    bool _ooGCCont;
    bool catalogPage;
    uint16 containerPageLimit;
    bool _signalClusteringError; 
    bool _zeroBasicFields;
    bool mIgnorePm;
    objy::placement::PersistentObjectCreator* mPersistentObjectCreator;

    bool useObjectCreator(ooTypeNumber typeN, const ooId& nearId)
    {
      if (nearId.isNull()) /* we always use the PM when there is no nearId*/ 
        return true;
      if (mIgnorePm)
        return false;
      return 
           nearId._DB != 1 /*not the system db*/ &&
           nearId._OC != 1 /*not the internal container*/ &&
           (
             nearId._OC != 2 /*not the default container*/ || 
             typeN >= 1000000 /*a user object*/
           );
    }

    void  setObjectCreatorIfNeeded();

    void* doTryCreate(ooTypeNumber typeN, const ooId& nearId, int priority, 
                      bool throwException, int pageLimit);

};

// returns the ooSession/ooContext installed ooClusterStrategy
OO_STORAGE_SPECIFIER ooClusterStrategy* ooGetClusterStrategy();
OO_STORAGE_SPECIFIER ooClusterStrategy* ooGetClusterStrategy(const ocmSession* session); // returns the ooSession/ooContext installed ooClusterStrategy
OO_STORAGE_SPECIFIER ooClusterStrategy* ooGetClusterStrategy(const ooHandle(ooObj)&);// returns the ooSession/ooContext installed ooClusterStrategy
OO_STORAGE_SPECIFIER ooClusterStrategy* ooSetClusterStrategy(ooClusterStrategy* strategy); // set the ooSession/ooContext installed ooClusterStrategy, returns the priorly installed ooClusterStrategy*.

OO_STORAGE_SPECIFIER void* ooNewObject(ooTypeNumber typeN, const objy::placement::Conditions& conditions); 

OO_STORAGE_SPECIFIER bool ooHavePlacementModel();


#endif
