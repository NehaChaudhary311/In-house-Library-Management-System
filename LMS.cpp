//============================================================================
// Name        : LMS.cpp
// Author      : Neha Chaudhary
// Version     :
// Copyright   : No part of this program may be reproduced
// Description : In-house Library Management System
//============================================================================

#include <iostream>
using namespace std;

#include <Library.h>

int main()
{
	Library* lib = new Library();
	lib->init();
	//lib->addBook();

	bool flag=true;
	cout<<endl<<"**********************************************"<<endl;
	cout<<"Welcome to In-house Library Management System";

	while(flag)
	{
		int choice;
		cout<<endl<<"**********************************************"<<endl;
		cout<<"Menu :: "<<endl;
		cout<<"1. View Library"<<endl;
		cout<<"2. Add Book"<<endl;
		cout<<"3. Remove Book"<<endl;
		cout<<"4. Search Book"<<endl;
		cout<<"5. Exit";
		cout<<endl<<"**********************************************"<<endl;
		cout<<"Enter your choice now ::";
		cin>>choice;

		switch(choice)
		{
		case 1:
			lib->viewLibrary();
			break;
		case 2:
			lib->addBook();
			break;
		case 3:
			lib->removeBook();
			break;
		case 4:
			lib->searchBook();
			break;
		case 5:
			flag=false;
			cout<<"Bye ... Bye ... Bye ..."<<endl;
			cout<<"!!! See U Soon !!!"<<endl;
			break;
		}
	}

	return 0;
}
