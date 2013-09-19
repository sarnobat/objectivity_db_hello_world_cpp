//-----------------------------------------------------------------------------
//  Copyright Objectivity Inc. 2003
//-----------------------------------------------------------------------------

#include <iostream>
using namespace std;
#include <ooObjy.h>
#include "../ddlFiles/HelloObject.h"

//-----------------------------------------------------------------------------
int main (int argc, char** argv)
{
	bool errors = true;
	cout << "Welcome to the Objectivity HelloWorld Example" << endl;

	const char* bootfile = "data/HelloWorld.boot";

	if (argc == 1)
	{
		cout << "No Objectivity FD Bootfile passed as argument; using default: " 
			<< bootfile << endl;
	}
	else
	{
		bootfile = argv[1];
		cout << "Using FD Bootfile passed as argument: " << bootfile << endl;
	}
	int count = 0;
	try
	{

		//
		//	initialize Objectivity/DB
		//
		ooObjy::startup();
		//
		//	establish connection to the Federation
		//
		ooConnection* connection;
		connection = ooObjy::getConnection(bootfile);
		//
		//	create a session
		//
		ooSession* session;
		session = connection->createSession("Main Session");
		//
		//	begin an update transaction
		//
		session->begin(oocUpdate);
		//
		//	get a reference to the federated database
		//
		ooHandle(ooFDObj) fd;
		fd = session->fd();
		//
		//	create a Hello object, and set its message
		//
		cout << "Create HelloObject and set message" << endl;
		const char* name = "HelloWorld";
		ooHandle(HelloObject) hello;
		hello = new HelloObject;
		hello->setHelloMsg(name);
		//
		//	commit the transaction
		//
		session->commit();
		//
		//	begin a read transaction
		//
		session->begin(oocRead);
		//
		//	lookup the Hello object
		//
		cout << "Looking for HelloObject..." << endl;
		//
		//	create a null HelloObject iterator
		//
		ooItr(HelloObject) helloItr;
		//
		//	initialize the object iterator using scan operation on the federation
		//	
		helloItr.scan(fd);
		while(helloItr.next())
		{
			if(strcmp(helloItr->getHelloMsg(), name) == 0)
			{
				cout << "Found it!: " << name << endl;
				errors = false;
			}
		}
		//
		//	commit the transaction
		//
		session->commit();
		//
		//	terminate interaction with Objectivity/DB
		//
		ooObjy::shutdown();
	}
	catch ( const ooException & ex )
	{
		cerr << "exception in main: " << ex.what() << endl;
		errors = true;
	}
	catch(...)
	{
		cerr << "unknown exception in main" << endl;
		errors = true;
	}

	if (errors)
	{
		cerr << endl << "HelloWorld test has FAILED" << endl;
	}
	else
	{
		cout << endl << "HelloWorld test has PASSED" << endl;
	}
	return 0;
}
