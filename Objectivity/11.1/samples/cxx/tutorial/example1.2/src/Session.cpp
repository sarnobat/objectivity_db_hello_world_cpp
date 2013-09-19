//-----------------------------------------------------------------------------
//  Copyright Objectivity Inc. 2011
//-----------------------------------------------------------------------------

#include <iostream>
using namespace std;

#include "Session.h"

//	Session constructor
Session::Session(const char* bootfile)
{
	try
	{
		//  Initialize Objectivity
		ooObjy::startup();

		//  get a connection to the federation
		mConnection = ooObjy::getConnection(bootfile);

		//  establish a session
		mSession = mConnection->createSession("Main_session");

		//  begin an update transaction
		mSession->begin(oocUpdate);

		//  leave the constructor with the session open
	}
	catch(ooException& ex)
	{
		cerr << "Objy exception" << ex.what() << endl;
	}
	catch(...)
	{
		cerr << "unknown exception" << endl;
	}
}

//	Session destructor
Session::~Session()
{
	try
	{
		//  commit the transaction
		mSession->commit();

		//  and shutdown Objy
		ooObjy::shutdown();
	}
	catch(ooException& ex)
	{
		cerr << "Objy exception" << ex.what() << endl;
	}
	catch(...)
	{
		cerr << "unknown exception" << endl;
	}
}
