//***************************************************************************//
//                                                                           //
//                Copyright © 2000 Objectivity Inc, USA.                     //
//                                                                           //
//    All Rights Reserved. Unauthorized use, duplication or distribution     //
//         of this software, or any portion of it, is prohibited.            //
//                                                                           //
//***************************************************************************//

// "@(#)$Id$"

#ifndef ooInternalStatistics_h
#define ooInternalStatistics_h

#ifndef OO_H
#include "oo.h"
#endif

class ooLog;
class OO_STORAGE_SPECIFIER ooStatistics;

class OO_STORAGE_SPECIFIER ooPageBufferStatistics
{
public:
  ooPageBufferStatistics();

  uint32 mPageSize;
  uint32 mNumberOfBuffersAllocated;
  uint32 mNumberOfBuffersUsedNow;
  uint32 mNumberOfBuffersUsedMax;
  uint32 mNumberOfLargeBuffersAllocated;
  uint32 mNumberOfLargeBuffersUsedNow;
  uint32 mNumberOfLargeBuffersUsedMax;
};

const unsigned ooMaxNumberPageSizes = 4;

//-----------------------------------------------------------------------------
class OO_STORAGE_SPECIFIER ooInternalStatistics 
{
   public:

      ooInternalStatistics();

      void addToLog(ooLog* log, const char* label, ooBoolean terse) const;

      uint32 numberOfTransactionStarts() const
      {return mNumberOfTransactionStarts;}

      uint32 numberOfTransactionCheckpoints() const
      {return mNumberOfTransactionCheckpoints;}

      uint32 numberOfTransactionCommits() const
      {return mNumberOfTransactionCommits;}

      uint32 numberOfTransactionAborts() const
      {return mNumberOfTransactionAborts;}

      uint32 numberOfFederatedDatabasesCreated() const
      {return mNumberOfFederatedDatabasesCreated;}

      uint32 numberOfFederatedDatabasesOpened() const
      {return mNumberOfFederatedDatabasesOpened;}

      uint32 numberOfFederatedDatabasesClosed() const
      {return mNumberOfFederatedDatabasesClosed;}

      uint32 numberOfFederatedDatabasesDeleted() const
      {return mNumberOfFederatedDatabasesDeleted;}

      uint32 numberOfDatabasesCreated() const
      {return mNumberOfDatabasesCreated;}

      uint32 numberOfDatabasesOpened() const
      {return mNumberOfDatabasesOpened;}

      uint32 numberOfDatabasesClosed() const
      {return mNumberOfDatabasesClosed;}

      uint32 numberOfDatabasesDeleted() const
      {return mNumberOfDatabasesDeleted;}

      uint32 numberOfContainersCreated() const
      {return mNumberOfContainersCreated;}

      uint32 numberOfContainersOpened() const
      {return mNumberOfContainersOpened;}

      uint32 numberOfContainersClosed() const
      {return mNumberOfContainersClosed;}

      uint32 numberOfContainersDeleted() const
      {return mNumberOfContainersDeleted;}

      uint32 numberOfObjectsCreated() const
      {return mNumberOfObjectsCreated;}

      uint32 numberOfObjectsOpened() const
      {return mNumberOfObjectsOpened;}

      uint32 numberOfObjectsClosed() const
      {return mNumberOfObjectsClosed;}

      uint32 numberOfObjectsDeleted() const
      {return mNumberOfObjectsDeleted;}

      uint32 numberOfNewAssociations() const
      {return mNumberOfNewAssociations;}

      uint32 numberOfDisassociations() const
      {return mNumberOfDisassociations;}

      uint32 numberOfAssociationsResized() const
      {return mNumberOfAssociationsResized;}

      uint32 numberOfObjectsNamed() const
      {return mNumberOfObjectsNamed;}

      const ooPageBufferStatistics* pageBufferStatistics() const
      { return &mPageBuffers[0]; }

      uint32 numberOfBuffers() const
      {return mNumberOfBuffers;}

      uint32 numberOfLargeBufferEntries() const
      {return mNumberOfLargeBufferEntries;}

      uint32 numberOfBuffersDropped() const
      {return mNumberOfBuffersDropped;}

      uint32 numberOfLargeBuffersDropped() const
      {return mNumberOfLargeBuffersDropped;}

      uint32 numberOfNewOcbs() const
      {return mNumberOfNewOcbs;}

      uint32 numberOfBufferReads() const
      {return mNumberOfBufferReads;}

      uint32 numberOfDiskReads() const
      {return mNumberOfDiskReads;}

      uint32 numberOfOldPagesWritten() const
      {return mNumberOfOldPagesWritten;}

      uint32 numberOfNewPagesWritten() const
      {return mNumberOfNewPagesWritten;}

      uint32 numberOfTimesOcsExtended() const
      {return mNumberOfTimesOcsExtended;}

      uint32 numberOfPagesAddedToOcs() const
      {return mNumberOfPagesAddedToOcs;}

      uint32 numberOfSmObjectsOpened() const
      {return mNumberOfSmObjectsOpened;}

      uint32 numberOfSmObjectsCreated() const
      {return mNumberOfSmObjectsCreated;}

      uint32 numberOfOpenHashCalls() const
      {return mNumberOfOpenHashCalls;}

      uint32 numberOfHashOverflows() const
      {return mNumberOfHashOverflows;}

      uint32 numberOfVarraysResized() const
      {return mNumberOfVarraysResized;}

#ifdef OO_NATIVE_INT_64
      size_t largeObjectSpace() const
      { return ooStaticCast(size_t, mLargeObjectSpaceNow); }
      size_t largeObjectSpaceMax() const
      { return ooStaticCast(size_t, mLargeObjectSpaceMax); }
#else
      size_t largeObjectSpace() const
      { return mLargeObjectSpaceNow.low; }
      size_t largeObjectSpaceMax() const
      { return mLargeObjectSpaceMax.low; }
#endif

   private:

      uint32 mNumberOfTransactionStarts;
      uint32 mNumberOfTransactionCheckpoints;
      uint32 mNumberOfTransactionCommits;
      uint32 mNumberOfTransactionAborts;

      uint32 mNumberOfFederatedDatabasesCreated;
      uint32 mNumberOfFederatedDatabasesOpened;
      uint32 mNumberOfFederatedDatabasesClosed;
      uint32 mNumberOfFederatedDatabasesDeleted;

      uint32 mNumberOfDatabasesCreated;
      uint32 mNumberOfDatabasesOpened;
      uint32 mNumberOfDatabasesClosed;
      uint32 mNumberOfDatabasesDeleted;

      uint32 mNumberOfContainersCreated;
      uint32 mNumberOfContainersOpened;
      uint32 mNumberOfContainersClosed;
      uint32 mNumberOfContainersDeleted;

      uint32 mNumberOfObjectsCreated;
      uint32 mNumberOfObjectsOpened;
      uint32 mNumberOfObjectsClosed;
      uint32 mNumberOfObjectsDeleted;

      uint32 mNumberOfNewAssociations;
      uint32 mNumberOfDisassociations;
      uint32 mNumberOfAssociationsResized;

      uint32 mNumberOfObjectsNamed;

      uint32 mNumberOfBuffers;
      uint32 mNumberOfLargeBufferEntries;
      uint32 mNumberOfNewOcbs;

      uint32 mNumberOfBufferReads;
      uint32 mNumberOfDiskReads;

      uint32 mNumberOfOldPagesWritten;
      uint32 mNumberOfNewPagesWritten;

      uint32 mNumberOfTimesOcsExtended;
      uint32 mNumberOfPagesAddedToOcs;

      uint32 mNumberOfSmObjectsOpened;
      uint32 mNumberOfSmObjectsCreated;

      uint32 mNumberOfOpenHashCalls;
      uint32 mNumberOfHashOverflows;

      uint32 mNumberOfVarraysResized;

      uint32 mNumberOfBuffersDropped;
      uint32 mNumberOfLargeBuffersDropped;

      uint64 mLargeObjectSpaceNow;
      uint64 mLargeObjectSpaceMax;

      ooPageBufferStatistics mPageBuffers[ooMaxNumberPageSizes];

      void update(ocmSession * cm_session);

      void Subtract(const ooInternalStatistics& other);

      friend class ooStatistics;

};

#endif

