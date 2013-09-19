#ifndef OOTOOLS_H
#define OOTOOLS_H "@(#)$Id$"

#include <oo.h>
#include <time.h>

#ifndef  OOTOOLS // {
#if defined(_MSC_VER) && defined(_DLL) // {
#define OOTOOLS    __declspec(dllimport)
#ifdef _DEBUG
/* Dynamic debug link */
#pragma comment(lib, "ootoolsd.lib")
#else
/* Dynamic non-debug link */
#pragma comment(lib, "ootools.lib")
#endif
#else
// }{
#define OOTOOLS
#endif // }
#endif // }

class OOTOOLS ootoolsEventListener
{
public:
  virtual void onBackupContainer(unsigned dbNum, unsigned ocNum, const char* name, const char* host, const char* path, unsigned pageSize, unsigned containerVersion) {}
  virtual bool onBackupContainerLockConflictIsError(unsigned dbNum, unsigned ocNum) { return false; }
  virtual void onBackupDatabase(unsigned dbNum, const char* name, const char* host, const char* path, unsigned pageSize) {}
  virtual bool onBackupDatabaseLockConflictIsError(unsigned dbNum) { return false; }
  virtual void onBackupFinished(unsigned pagesUpdated) {}
  virtual void onBackupPage(unsigned dbNum, unsigned ocNum, unsigned pageNum, unsigned compressedSize, unsigned containerVersion) {}
  virtual void onBackupReplacePage(unsigned dbNum, unsigned ocNum, unsigned pageNum, unsigned compressedSize, time_t fromTime) {}
  virtual void onBackupPageUpToDate(unsigned dbNum, unsigned ocNum, unsigned pageNum, unsigned containerVersion) {}
  virtual void onBackupSomeDbPathAddedOrChanged() {}
  virtual void onBackupStarted(time_t time) {}

  virtual void onRestoreAp(unsigned apId, const char* name, const char* host, const char* path) {}
  virtual void onRestoreContainer(time_t time, unsigned dbNum, unsigned ocNum, const char* name, const char* host, const char* path, unsigned pageSize) {}
  virtual void onRestoreDatabase(time_t time, unsigned dbNum, const char* name, const char* host, const char* path, unsigned pageSize) {}
  virtual void onRestoreFinished(unsigned pagesRestored) {}
  virtual void onRestorePage(time_t time, unsigned dbNum, unsigned ocNum, unsigned pageNum) {}
  virtual void onRestoreReplica(unsigned dbNum, const char* host, const char* path) {}
  virtual void onRestoreStarted() {}
  virtual bool onRestoreReplaceExistingDatabase(unsigned dbNum, const char* host, const char* path) { return false; }
  virtual bool onRestoreReplaceExistingContainerFile(unsigned dbNum, unsigned ocNum, const char* host, const char* path){ return false; }
};

// New enumeration type backup can be for an entire federated database, a
// selected database, or a selected container
enum ooBackupScope
{
  oocFdScope,
  oocDbScope,
  oocContainerScope
};

class OOTOOLS ooBackupFdEvent;
class OOTOOLS ooBackupDbEvent;
class OOTOOLS ooBackupContainerEvent;
class OOTOOLS ooBackupPageEvent;
class OOTOOLS ootools;

// A federation-wide backup is transiently exposed as an ooBackupFdEvent
class OOTOOLS ooBackupFdEvent
{
  friend class OOTOOLS ootools;
  friend class OOTOOLS ooBackupDbEvent;
  friend class ooTVArrayT<ooBackupFdEvent>;
  time_t when;
  char bootfile[512];
  unsigned fdNumber;
  unsigned fdMrowVersion;
  ooBackupScope backupScope;
  uint64 dataSize;
  uint64 dataSizeCompressed;
  bool computedEventSizeData;
  void computeEventDataSizeData();
  bool incremental;
protected:
  ooBackupFdEvent(time_t when = 0, const char* bootFile = 0, bool incremental = false);
public:
  const char* archiveFdBootfile() const { return bootfile; }
  uint64 dataSizeThisEvent();
  uint64 dataSizeCompressedThisEvent();
//  uint64 fullRestoreDataSize() const;
//  uint64 fullRestoreDataSizeCompressed() const;
  const time_t& time() const { return when; }
  void databases(ooTVArrayT<ooBackupDbEvent>& databaseEvents, ooSession* archiveSession) const;
  void databases(ooTVArrayT<ooBackupDbEvent>& databaseEvents, ooRef(ooDBObj)& dbR, ooSession* archiveSession) const;
  void containers(ooTVArrayT<ooBackupContainerEvent>& containerEvents) const;
  bool isFull() const { return !incremental; }
  void pages(ooTVArrayT<ooBackupPageEvent>& pageEvents) const;
};

// A database backup is transiently exposed as an ooBackupDbEvent
class OOTOOLS ooBackupDbEvent
{
  friend class OOTOOLS ootools;
  friend class OOTOOLS ooBackupContainerEvent;
  friend class OOTOOLS ooBackupFdEvent;
  friend class ooTVArrayT<ooBackupDbEvent>;
  time_t when; // Time when this backup was created
  uint16 dbNumber;
  unsigned fdMrowVersion;
  unsigned pageSize;
  uint64 dataSize; // Unit is bytes
  uint64 dataSizeCompressed;
  bool computedEventSizeData;
  void computeEventDataSizeData();
protected:
  ooBackupDbEvent(): dataSize(0), dataSizeCompressed(0), pageSize(0), computedEventSizeData(false) {}
  ooBackupDbEvent(uint16 dbNumber, const ooBackupFdEvent& backupFdEvent): dataSize(0), backupFdEvent(backupFdEvent), dataSizeCompressed(0), dbNumber(dbNumber), pageSize(0), computedEventSizeData(false) {}
  ooBackupDbEvent(time_t when, uint16 dbNumber, unsigned fdMrowVersion, unsigned pageSize, const ooBackupFdEvent& backupFdEvent):
      when(when), dbNumber(dbNumber), fdMrowVersion(fdMrowVersion), backupFdEvent(backupFdEvent), pageSize(pageSize), computedEventSizeData(false){}
public:
  uint64 dataSizeThisEvent();
  uint64 dataSizeCompressedThisEvent();
//  uint64 fullRestoreDataSize() const;
//  uint64 fullRestoreDataSizeCompressed() const;
  void containers(ooTVArrayT<ooBackupContainerEvent>& containerEvents, ooSession* archiveSession) const;
  void containers(ooTVArrayT<ooBackupContainerEvent>& containerEvents, ooRef(ooContObj)& contR, ooSession* archiveSession) const;
  uint16 number() const { return dbNumber; }
  const time_t& time() const { return when; }
  ooBackupFdEvent backupFdEvent;
  bool isDeleted() { return pageSize == 0; }
};

// a container backup is transiently exposed as an ooBackupContainerEvent
class OOTOOLS ooBackupContainerEvent
{
  friend class OOTOOLS ooBackupPageEvent;
  friend class OOTOOLS ooBackupFdEvent;
  friend class OOTOOLS ooBackupDbEvent;
  friend class ooTVArrayT<ooBackupContainerEvent>;
protected:  
  time_t when; // Time when this backup was created
  uint16 containerNumber;
  uint64 dataSize;
  uint64 dataSizeCompressed;
  ooBackupContainerEvent(): dataSize(0), dataSizeCompressed(0) {}
  ooBackupContainerEvent(const ooBackupContainerEvent& toCopy): dataSize(toCopy.dataSize), dataSizeCompressed(toCopy.dataSizeCompressed), when(toCopy.when), containerNumber(toCopy.containerNumber), dbEvent(toCopy.dbEvent) {}
  ooBackupContainerEvent(time_t when, uint16 containerNumber, ooBackupDbEvent& dbEvent);
public:
  // Uncompressed size of all pages backed up for this container backup event
  uint64 dataSizeThisEvent() { return dataSize; }
  // Compressed size of all pages backed up for this container backup event
  uint64 dataSizeCompressedThisEvent() { return dataSizeCompressed; }
  // Uncompressed size of all pages backed up for this container,
  // Including all backup events up to this one (same as dataSizeMB
  // If this backup event is full, not incremental)
  uint64 fullRestoreDataSize() const;
  // Compressed size of all pages backed up for this
  // Container including all backup events up to this one
  uint64 fullRestoreDataSizeCompressed() const;
  uint16 number() const { return containerNumber; }
  // Pages that were backed up as part of this container backup
  void pages(ooTVArrayT<ooBackupPageEvent>& pageEvents, ooSession* archiveSession);
  const time_t& time() const { return when; }
  ooBackupDbEvent dbEvent; // The associated database backup event (if any)
};

// A backup of a container page is exposed as an ooBackupEventPage
class OOTOOLS ooBackupPageEvent
{
  friend class OOTOOLS ooBackupFdEvent;
  friend class OOTOOLS ooBackupContainerEvent;
  friend class ooTVArrayT<ooBackupPageEvent>;
  // The associated container backup event
  ooBackupContainerEvent containerEvent;
  uint16 pageNumber; // Logical page in a container
  unsigned zipSize;
  unsigned dataSize;
  ooBackupPageEvent() {}
  ooBackupPageEvent(const ooBackupPageEvent& toCopy): pageNumber(toCopy.pageNumber), containerEvent(toCopy.containerEvent) {}
  ooBackupPageEvent(uint16 pageNumber, unsigned dataSize, unsigned compressedSize, ooBackupContainerEvent& containerEvent);
public:
  uint16 number() const { return pageNumber; }
  unsigned compressedSize() { return zipSize; }
  unsigned size() { return dataSize; }
  ooBackupContainerEvent& container() { return containerEvent; }
};

// A federation-wide full backup
class archiveFile;
class archiveFileFd;
class OO_STORAGE_SPECIFIER ossString;
class OOTOOLS ooFullBackupFdEvent
{
  archiveFile* af;
  archiveFileFd* archiveFd;
  int index;
  ossString* tempStr; // used for return value for archiveBootfile(), archiveDir() and archiveHost()
public:
  ooFullBackupFdEvent(const char* repositoryDirOrBasename = "backup", const char* repositoryHost = 0, time_t when = 1);
  ~ooFullBackupFdEvent();
  const char* archiveBootfile() const;
  const char* archiveDir() const;
  const char* archiveHost() const;
  int currentArchiveIndex() const { return index; }
  int nextArchive(); // moves to the next archive and return index of this archive in repository file or -1 if out of bounds
  int prevArchive(); // moves to the previous archive and return index of this archive in repository file or -1 if out of bounds
  const time_t time() const;
};

class OOTOOLS ooBackupFdInfo
{
  archiveFile* af;
  archiveFileFd* archiveFd;
  int index;
  char fdBoot[512];
  char fdHost[256];
public:
  ooUniqueId uniqueId;
  ooBackupFdInfo(const char* repositoryPath, const char* repositoryHost, time_t upToTime, bool standalone);
  const char* fdBootfile() { return fdBoot; }
  const char* fdHostname() { return fdHost; }
};

class OO_STORAGE_SPECIFIER osmOc; // Objectivity internal use
class oomappings;
class oobackupArchiveWriter; // Objectivity internal use
class ooRestoreFdWriter; // Objectivity internal use
class oobackupDatabase; // Objectivity internal use
class oobackupContainer; // Objectivity internal use
class OO_STORAGE_SPECIFIER ooDatabaseByNameLookup; // Objectivity internal use

class OOTOOLS ootools
{
  friend class oobackupArchiveWriter;
  friend class ooRestoreFdWriter;
  friend void ooqueryarchiveEventData(char* repositoryDirOrBasename, char* repositoryHost, time_t upToTime, bool standalone, FILE* outfile, ootools& tool);
public: 
  enum BackupType {
      automatic = 1,
      forceFull = 2,
      forceIncremental = 3
  };
protected:
  void backup(ooId& oid,
              const char* repositoryDirOrBasename,
              const char* repositoryHost,
              BackupType backupType,
              const char* newArchiveDir,
              const char* newArchiveHost,
              bool deleteReplacedPages,
              bool systemDbOnly);

   void backupEvents(ooTVArrayT<ooBackupFdEvent>& fdEvents,
                    ooSession& archiveSession) const;

   void backupEvents(ooRef(ooContObj)& contR,
                     ooTVArrayT<ooBackupContainerEvent>& contEvents,
                     ooSession* archiveSession) const;

   void backupEventsByTime(ooTVArrayT<ooBackupFdEvent>& fdEvents,
                     const char* repositoryDirOrBasename = "backup",
                     const char* repositoryHost = 0,
                     time_t upToTime = 0) const; 

   void backupEventsByTime(ooRef(ooDBObj) dbR,
                     ooTVArrayT<ooBackupDbEvent>& dbEvents,
                     const char* repositoryDirOrBasename = "backup",
                     const char* repositoryHost = 0,
                     time_t upToTime = 0) const;

   void backupEventsByTime(ooRef(ooContObj) contR,
                     ooTVArrayT<ooBackupContainerEvent>& contEvents,
                     const char* repositoryDirOrBasename = "backup",
                     const char* repositoryHost = 0,
                     time_t upToTime = 0) const;

  void collectDatabasesToBackup(oobackupArchiveWriter& toWrite,
                                archiveFile& af,
                                ocmSession* session,
                                ooSession* userSession);

  void collectContainerDataToBackup(osmOc *pOc, oobackupContainer* backupContainer,
                                    uint32 containerVersion,
                                    oobackupArchiveWriter& toWrite,
                                    archiveFile& af);

  bool collectDbDataToBackup(ooHandle(ooDBObj)& dbH,
                      oobackupDatabase* dbToBackup,
                      ooDatabaseByNameLookup& dbNameTable,
                      bool containerFilesOnly,
                      oobackupArchiveWriter& toWrite,
                      archiveFile& af,
                      ocmSession* session);

   const char* restore(ooId& oid,
                      const char* repositoryDirOrBasename,
                      const char* repositoryHost,
                      const char* toDirectory,
                      const char* toHost,
                      time_t upToTime,
                      bool oocheck,
                      bool forceNewFd,
                      bool purgeAps);
  void checkBackupMappings();
  void checkRestoreMappings();
  ooConnection* archiveConnection;
  ooSession* archiveSession;
  ooTransId tranId;
  bool inSameTransaction; // keep track of multiple calls to backup withing a single transaction
  ossString* errorMessage;
  void realHostPath(const char* inHost, const char* inPath, ossString& realHost, ossString& realPath);
  ootoolsEventListener* listener;
  oomappings* mappings;
  bool standalone;
public: 
  ootools(ootoolsEventListener* listener = 0, bool standalone = false);
  ~ootools();

  void backup(const char* repositoryDirOrBasename = "backup",
              const char* repositoryHost = 0,
              BackupType backupType = automatic,
              const char* newArchiveDir = 0,
              const char* newArchiveHost = 0,
              bool deleteReplacedPages = false,
              bool systemDbOnly = false);

   void backup(ooRef(ooDBObj) dbToBackupR,
               const char* repositoryDirOrBasename = "backup",
               const char* repositoryHost = 0,
               BackupType backupType = automatic,
               const char* newArchiveDir = 0,
               const char* newArchiveHost = 0,
               bool deleteReplacedPages = false);
   
   void backup(ooRef(ooContObj) contToBackupR,
               const char* repositoryDirOrBasename = "backup",
               const char* repositoryHost = 0,
               BackupType backupType = automatic,
               const char* newArchiveDir = 0,
               const char* newArchiveHost = 0,
               bool deleteReplacedPages = false);

   void backupEvents(ooTVArrayT<ooBackupFdEvent>& fdEvents,
                     const char* repositoryDirOrBasename = "backup",
                     const char* repositoryHost = 0,
                     int archiveIndex = -1) const;

   
   void backupEvents(ooRef(ooDBObj) dbR,
                     ooTVArrayT<ooBackupDbEvent>& dbEvents,
                     const char* repositoryDirOrBasename = "backup",
                     const char* repositoryHost = 0,
                     int archiveIndex = -1) const;


   void backupEvents(ooRef(ooContObj) contR,
                     ooTVArrayT<ooBackupContainerEvent>& contEvents,
                     const char* repositoryDirOrBasename = "backup",
                     const char* repositoryHost = 0,
                     int archiveIndex = -1) const;

   bool check(ooHandle(ooContObj)& contH);
   int convertContainer(const ooId& oid, ooDiskFormat architecture, bool quiet);

   void deleteBackupData(time_t upToTime = 0, bool latestonly = false,
                         const char* repositoryDirOrBasename = "backup",
                         const char* repositoryHost = 0);

   void newfd(uint32 fdId,
           const char* fdName,
           const char *fdFilePath,
           const char *fdFileHost,
           const char *lockServerHost,
           const char *jnlDirPath = 0,
           const char *jnlDirHost = 0,
           uint32 pageSize = 8192,
           const char* licenseFile = 0,
           bool standalone = false,
           uint32 weight = 1,
           FILE *outfile = stdout,
           bool bootOnly = false,
           bool useNewCats = true,
           unsigned apNum = 0,
           bool managedPlacement = false,
           bool noAutoFdIdAssign = false);

   void outputMapFile(FILE* outfile = stdout) const; // from user FD

   void outputMapFile(FILE* outfile,
                      const char* repositoryDirOrBasename, // from backup archive
                      const char* repositoryHost = 0,
                      time_t upToTime = 0) const;

   bool parseMapFile(const char* mapFile);
   
   // returns the bootfile name of the FD that is fully or partially restored
   const char* restore(const char* repositoryDirOrBasename = "backup", 
                      const char* repositoryHost = 0,
                      const char* toDirectory = 0,
                      const char* toHost = 0,
                      bool systemDbOnly = false,
                      time_t upToTime = 0,
                      bool purgeAps = false);

    const char* restore(ooRef(ooDBObj) dbToRestoreR,
                        const char* repositoryDirOrBasename = "backup",
                        const char* repositoryHost = 0,
                        const char* toDirectory = 0,
                        const char* toHost = 0,
                        time_t upToTime = 0,
                        bool oocheck = false);

    const char* restore(ooRef(ooContObj) contToRestoreR,
                        const char* repositoryDirOrBasename = "backup",
                        const char* repositoryHost = 0,
                        const char* toDirectory = 0,
                        const char* toHost = 0,
                        time_t upToTime = 0,
                        bool oocheck = false);

    static bool str2time(time_t &target_time, const char* targetTimeStr);
};

#endif
