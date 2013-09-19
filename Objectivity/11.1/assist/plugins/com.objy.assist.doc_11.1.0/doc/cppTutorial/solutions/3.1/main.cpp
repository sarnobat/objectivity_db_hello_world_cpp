#include <ooObjy.h>
#include <iostream>
using namespace std;

//  in this example we use Objectivity handles and the overloaded new operator
#define Ref(A) ooHandle(A)

int main( int argc, char ** argv ){
	try{
		//
		//	initialize Objectivity/DB
		//
		ooObjy::startup();
		//
		//	establish connection to the Federation
		//
		ooConnection* connection;
		connection = ooObjy::getConnection("data/RentalCompany.boot");
		//
		//	create a session
		//
		ooSession* session;
		session = connection->createSession("Main Session");
		//
		//	begin an update transaction (Lesson 3)
		//
		session->begin(oocUpdate);
		
		//
		//	get a reference to the federated database (Lesson 3)
		//
		ooHandle(ooFDObj) fd;
		fd = session->fd();
		
		//
		//	create objects (Lesson 3)
		//
		cout << "Creating objects..." << endl;

		Ref(ooObj) oRef;
		for (int i = 0; i < 1000; i++)
		{
			oRef = new ooObj();
		}
		
		//
		//	commit the transaction
		//
		session->commit();
		
		//
		//	begin a read transaction (Lesson 2)
		//
		session->begin(oocRead);
		
		//
		//	lookup the objects
		//
		cout << "Looking for objects..." << endl;
		
		//
		//	create a null object iterator (Lesson 3)
		//
		ooItr(ooObj) objItr;
		
		//
		//	initialize the object iterator using scan operation on the federation (Lesson 3)
		//	
		objItr.scan(fd);
		int count = 0;
		while (objItr.next())
		{
			count++;
		}
		cout << "Found " << count << " objects using iteration." << endl;
		
		//
		//	create a PQL query string (Lesson 8)
		//

		//
		//	create a Customer iterator (Lesson 8)
		//

		//
		//	initialize the customer iterator using scan operation on 
		//  the federation and iterate through the results (Lesson 8)
		//
		
		//
		//	commit the transaction
		//
		session->commit();
		
		//
		//	terminate interaction with Objectivity/DB
		//
		ooObjy::shutdown();
	}
	//catch objy kernel expections
	catch (ooKernelException &ex)
	{
		cout << endl << "Error.\n";
		cout << ex.what() << endl;
		return -1;
	}
	return 0;
}