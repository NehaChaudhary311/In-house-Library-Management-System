/*
 * Library.cpp
 *
 */

#include <Library.h>
#include <iostream>
using namespace std;

Library::Library()
{
}

void Library::init()
{
	//create shelves as per the config.ini file
	ls = new Shelf[2];

	//1st shelf is for books
	//ls[0].setCapacity(100);
	ls[0].init("Book");

	//2nd shelf is for magazines
	//ls[1].setCapacity(100);
	ls[1].init("Magazine");

}

void Library::viewLibrary()
{
	cout<<"Book ";
	ls[0].viewBooks();

	cout<<"Magazine ";
	ls[1].viewBooks();

	/*
	MediaType* ptr = NULL;
	cout<<"Book Shelf :: "<<ls[0].getMediaList().size()<<endl;
	for (std::list<MediaType*>::iterator it=ls[0].getMediaList().begin(); it != ls[0].getMediaList().end(); ++it)
	{
		ptr = *it;
		ptr->viewDetails();
		//std::cout << ' ' << *it;
	}

	cout<<"Magazine Shelf :: "<<ls[1].getMediaList().size()<<endl;
	for (std::list<MediaType*>::iterator it=ls[1].getMediaList().begin(); it != ls[1].getMediaList().end(); ++it)
	{
		(*it)->viewDetails();
		//std::cout << ' ' << *it;
	}
	*/
}

void Library::searchBook()
{
	int resp;
	cout<<"Press '1' for searching Book or '2' for searching Magazine."<<endl;
	cin>>resp;
	if(resp == 1)
	{
		// Searching on Book Shelf
		ls[0].searchBook(resp);
	}
	else if(resp == 2)
	{
		//Searching on Magazine Shelf
		ls[1].searchBook(resp);
	}
	else
		cout<<"Invalid number entered!"<<endl;

}

void Library::addBook()
{
	int resp;
	cout<<"Press '1' for adding Book or '2' for adding Magazine."<<endl;
	cin>>resp;
	if(resp == 1)
	{
		// Adding on Book Shelf
		ls[0].addBook(resp);
	}
	else if(resp == 2)
	{
		//Adding on Magazine Shelf
		ls[1].addBook(resp);
	}
	else
		cout<<"Invalid number entered!"<<endl;

}

void Library::removeBook()
{
	int resp;
	cout<<"Press '1' for removing Book or '2' for removing Magazine."<<endl;
	cin>>resp;
	if(resp == 1)
	{
		// Removing on Book Shelf
		ls[0].removeBook(resp);
	}
	else if(resp == 2)
	{
		//Removing on Magazine Shelf
		ls[1].removeBook(resp);
	}
	else
		cout<<"Invalid number entered!"<<endl;
}

Library::~Library()
{

}
