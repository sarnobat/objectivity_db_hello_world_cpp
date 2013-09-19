
#
# DBA stuff to set up for sample run
#

import os
import socket
hostname = socket.gethostname()
started_lockserver = 0

# Start the lockserver if it is not already running
print "\n\n*** Checking the lockserver...\n"
if os.system("oocheckls") != 0:
    if os.system("oolockserver") != 0:
            print "Could not start a lockserver....did you set you PATH and LD_LIBRARY_PATH to include the Objectivity installation?\n\n"
            exit(1)
    started_lockserver = 1


# Create the tutorial federation
try:
    open("tutorial.boot")
    print "\n\n*** Cleaning up the existing federation...\n"
    os.system("oodeletefd -force -standalone tutorial.boot")
except IOError:
    print ""

print "\n\n*** Creating the tutorial database...\n"
os.system("oonewfd -fdfilepath tutorial.fdb -lockserver " + hostname + " tutorial.boot")

# 
#  Initialize Objectivity resources for the process
#

print "\n\n*** Importing the Objectivity/Python module"
import oopython

print "*** Initializing Objectivity"
oopython.startup()

# Get a connection object for our tutorial federation

# connection = oopython.getConnection('tutorial.boot')

# Get a session object from the connection so that we may have 
# transactions.  We have not turned logging on, so we can specify 
# an empty session name

# session = connection.createSession('')

# Use a shortcut to the two above steps that creates a session with 
# all of the default parameters

print "*** Opening a session on the tutorial federation"
session = oopython.createSession('tutorial.boot')

# Start an update transaction
print "*** Beginning a transaction"
session.begin(oopython.oocUpdate)

#  Versions of the Python binding before release 7 use strings for the mode:
#  session.begin('oocUpdate')

#  Add a couple classes to the schema - to work with the schema 
#  Get the schema object from oopython and get the top module from it
schema = oopython.getSchema()
topModule = schema.getTopModule()

#  Now that we have the top module, we can add a new class to it
print "*** Adding a Person class to the schema"
personClass = topModule.addClass('Person')

#  Make it persistent capable and add members to it
personClass.addBaseClass('ooObj')
personClass.addEmbeddedMember('name', 'ooVString')
personClass.addIntMember('age', oopython.oocUInt8)
personClass.addBiDirMember('organization', 'Organization', 'members', 1, 0)

#  Add the Organization class
print "*** Adding an Organization class to the schema"
print "    including a bi-directional association"
orgClass = topModule.addClass('Organization')
orgClass.addBaseClass('ooObj')
orgClass.addEmbeddedMember('name', 'ooVString')
orgClass.addBiDirMember('members', 'Person', 'organization', 0, 1)

#  Activate proposals (this is necessary for schema modifications) 
#  and commit the transaction

#  In general, schema updates should be performed in a separate transaction 
#  from other types of database updates

schema.activateProposals()
print "*** Commit these schema changes"
session.commit()

#  Create some instances of the Person class.  
#  First we should create a database and container to put them into.

print "*** Beginning a new transaction"
session.begin(oopython.oocUpdate)
print "*** Create a Database and Container to hold our objects"
db = session.getFd().addDb('tutorial')
cont = db.addContainer('tutorialData')

cont.oid()

#  Add a Person object to the container

#  The first argument to addObject is where to place the new object.
#  The second is the type of object to create.  In our case we want 
#  a Person object created and placed into the container that we 
#  just created.

print "*** Create a persistent Person object"
sam = oopython.addObject(cont, 'Person')

#  Now set Sam's data members

print "*** Set the values of our Person object"
sam.name = 'Sam'
sam.age = 30
name = sam.name

#  Add a couple more Person objects
print "*** Create a few more person objects and set values"
lisa = oopython.addObject(cont, 'Person')
lisa.name = 'Lisa'
lisa.age = 28
john = oopython.addObject(cont, 'Person')
john.name = 'John'
john.age = 55
fred = oopython.addObject(cont, 'Person')
fred.name = 'Fred'
fred.age = 46
tom = oopython.addObject(cont, 'Person')
tom.name = 'Tom'
tom.age = 67

#  Add an Organization object
print "*** Create an Organization object, set the org name, and"
print "    add some of our Persons as members of the org using"
print "    two different methods."
accounting = oopython.addObject(cont, 'Organization')
accounting.name = 'Accounting'
accounting.members.add(sam)
accounting.members.add(lisa)
john.organization = accounting

#  Add a second Organization object
print "*** Create another Organization object, set the org name, and"
print "    add some of our Persons as members of the org."
sales = oopython.addObject(cont, 'Organization')
sales.name = 'Sales'
sales.members.add(fred)
tom.organization = sales

# Create a class that inherits from Persistent and includes an
# initializer that calls makePersistent. This provides the 
# ability to includes methods in the class.
class Person(oopython.Persistent):
    def __init__(self, container, name="", status=1):
        self.persist(container)
        self.name = name
        self.status = status

    def persist(self, container):
        self.makePersistent(container)

# Add other methods to the class:
    def printTest(self):
        print "\n\n*** Hello world!\n"

# Add a Person object using the Python initializer
sue = Person(cont)
sue.name = "Sue"
sue.age = 41
sue.organization = accounting

#  Commit the transaction
print "*** Commit the changes made in this session"
session.commit()

#  Start a read-only transaction
print "*** Beginning a new read-only transaction"
session.begin(oopython.oocRead)

#  Iterate over all the Orgainization objects in the container and
#  print the members

cont.oid()

print "*** Iterate over all Organization objects in the container"
print "    and print the Persons who are members of each."
for org in cont.getScanItr('Organization'):
   print 'Organization: ' + org.name
   for member in org.members.getObjs():
      print ' Member: %s Age: %s' % (member.name, member.age)

#  Commit the transaction (releases read locks)
print "*** Commit the transaction (to release the read locks)"
session.commit()

#  Shut down the Objectivity instance
print "*** The tutorial is complete....shutting down the Objectivity instance"
oopython.shutdown()


# If we started the lockserver we should stop it. We will leave the tutorial 
# federation and database so they can be inspected
if started_lockserver == 1:
    print "*** Stopping the lockserver..."
    os.system("ookillls")
