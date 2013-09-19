//-----------------------------------------------------------------------------
//  Copyright Objectivity Inc. 2011
//-----------------------------------------------------------------------------

#include <iostream>
using namespace std;

#include <time.h>

//  oo.h contains the ooObj class definition
#include "oo.h"

//  in this example we use C++ pointers and the default new operator
#define Ref(A) A*

int main ()
{
	try
	{
		//  open(create) the file to persist the objects
		FILE* fp;
		if ((fp = fopen("TESTFILE","w")) == NULL)
		{
			printf("cant open file");
			return 99;
		}
		int count = 0;
		size_t s = sizeof(ooObj);
		// declare a pointer, oRef, to ooObj
		Ref(ooObj) oRef;
		clock_t start,end;
		start = clock();

		cout << "Creating objects";
		int i = 0;
		for (i = 0; i < 1000; i++)
		{
			//  create the objects
			oRef = new(0) ooObj();
			//  write out the object to the file
			fwrite(oRef,1,s,fp);
		}   
		end = clock();
		cout << endl << "created " << i << " objects in " << (end-start)/CLOCKS_PER_SEC << " seconds" << endl;
		// close the file
		fclose(fp);
	}
	catch(...)
	{
		cerr << "exception in main" << endl;
		return 99;
	}
	return 0;
}
