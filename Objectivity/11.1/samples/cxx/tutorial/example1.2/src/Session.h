//-----------------------------------------------------------------------------
//  Copyright Objectivity Inc. 2011
//-----------------------------------------------------------------------------

#include <ooObjy.h>

static char dbName[7] = "TestDB";

// Class Session represents some basic database functionality
class Session
{
	public:
		// constructor
		Session(const char*);

		// destructor
		virtual ~Session();

	protected:

	private:
		ooConnection*         mConnection;
		ooSession*            mSession;   
};

extern Session session;
