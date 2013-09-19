//-----------------------------------------------------------------------------
//  Copyright Objectivity Inc. 2011
//-----------------------------------------------------------------------------

#include <iostream>
using namespace std;

#include <time.h>

//  The Session class encapsulates Objectivity behavior
#include "Session.h"

//  in this example we use Objectivity handles and the overloaded new operator
#define Ref(A) ooHandle(A)

int main()
{
	try
	{
		//  let the Session constructor take care of Objy startup
		static Session session("data/example1.2.boot");

		Ref(ooObj) oRef;
		clock_t start,end;
		start = clock();

		//  create objects
		cout << "Creating objects";
		int i = 0;
		for (i = 0; i < 1000; i++)
		{
			oRef = new ooObj();
		}
		end = clock();
		cout << endl << "created " << i << " objects in " << (end-start)/CLOCKS_PER_SEC << " seconds" << endl;
	}
	catch(const ooException & ex)
	{
		cerr << "Objectivity exception in main " << ex.what() << endl;
	}
	catch(...)
	{
		cerr << "unknown exception in main" << endl;
	}
	return 0;

	// let the Session destructor take care of Objy shutdown

}
