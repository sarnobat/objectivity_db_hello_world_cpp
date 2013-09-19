//***************************************************************************//
//                                                                           //
//                Copyright © 2011 Objectivity Inc, USA.                     //
//                                                                           //
//    All Rights Reserved. Unauthorized use, duplication or distribution     //
//         of this software, or any portion of it, is prohibited.            //
//                                                                           //
//***************************************************************************//

// Declarations for the server administration security plugin

#ifndef OO_SERVER_SECURITY_H
#define OO_SERVER_SECURITY_H "@(#)$Id$"

class ooClientIdentity
{
public:
  virtual const char *           getHostName()   = 0;
  virtual bool                   isCurrentHost() = 0;
  virtual const struct sockaddr* getHostAddress()= 0;
  virtual const char *           getUserName()   = 0;
};

class ooPluginArguments
{
public:
  virtual const char* getValue(const char* name) const = 0;
  virtual bool nextPair(const char** name_ptr, const char** value_ptr) = 0;
};

// The plugin is defined as a subclass of this:
class ooServerAdminSecurity
{
public:
  // Called once when the server starts:
  virtual void initialize(const char* server_name, int argc, char **argv,
                          ooPluginArguments& pluginArgs)
  { }
  // Called once when the server stops:
  virtual void terminate() { }
  // Called to authorize a request from "ookillls":
  virtual bool allowStopping(ooClientIdentity & client) { return true; }
  // Called to authorize an exclusive lock, such as from tools which
  // create or delete a federation or database:
  virtual bool allowExclusiveLock(ooClientIdentity & client, unsigned FD,
                                  unsigned DB, unsigned container)
    { return true; }
  // Virtual table placeholders for future methods:
  virtual bool future1(ooClientIdentity & client, ...) { return true; }
  virtual bool future2(ooClientIdentity & client, ...) { return true; }
};

#endif
