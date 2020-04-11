/*
 * Shelf.cpp
 *
 */

#include <iostream>
#include <fstream>
#include <string>
#include <limits>
using namespace std;

#include <Shelf.h>
#include <string.h>
#include <Book.h>
#include <Magazine.h>

Shelf::Shelf()
{
	this->max_cap=MAX_SHELF_CAP;
	this->curr_cap=0;
}

Shelf::~Shelf()
{
	//Insert code to delete all MediaType objects
	this->mediaList.clear();
}

std::list<MediaType*> Shelf::getMediaList()
{
	return this->mediaList;
}

void Shelf::viewBooks()
{
	//MediaType* ptr = NULL;
	cout<<"Shelf size :: "<<mediaList.size()<<endl;
	for (std::list<MediaType*>::iterator it=mediaList.begin(); it != mediaList.end(); ++it)
	{
		(*it)->viewDetails();
		//ptr = *it;
		//ptr->viewDetails();
		//std::cout << ' ' << *it;
	}
}

void Shelf::init(const char* ShelfName)
{
	//Read the Shelf text file & create as many entries it has of MediaType.

	if(strcmp(ShelfName,"Book")==0)
	{
		ifstream myfile;
		myfile.open("Book_Shelf");//Book Shelf

		if (myfile.is_open())
		{
			Book* book = NULL;//new Book();
			string line;
			char* start = NULL;
			char* pos = NULL;
			char* data= NULL;
			int strlen=0;

			while ( getline (myfile,line) )
			{
				//cout << line <<endl;
				// Allocate memory for book object
				book = new Book();
				// Read book title
				start = (char*)line.c_str();
				pos=(char*)strchr(start,';');
				strlen = pos-start;
				data = new char[strlen+1];
				strncpy(data,start,strlen);
				data[strlen]='\0';
				book->setTitle(data);

				//Read book author
				start = ++pos;
				pos=(char*)strchr(start,';');
				strlen = pos-start;
				data = new char[strlen+1];
				strncpy(data,start,strlen);
				data[strlen]='\0';
				book->setAuthor(data);

				this->mediaList.push_back(book);
				this->curr_cap++;
			}
		myfile.close();
		}
		else
		  cout <<"Unable to open file"<<endl;
	}
	else if(strcmp(ShelfName,"Magazine")==0)
	{
		ifstream myfile;
		myfile.open("Magazine_Shelf");//Magazine Shelf

		if (myfile.is_open())
		{
			Magazine* mag = NULL;//new Magazine();
			string line;
			char* start = NULL;
			char* pos = NULL;
			char* data= NULL;
			int strlen=0;

			while ( getline (myfile,line) )
			{
				//cout << line <<endl;
				//Create Magazine Object
				mag = new Magazine();
				// Read Magazine title
				start = (char*)line.c_str();
				pos=(char*)strchr(start,';');
				strlen = pos-start;
				data = new char[strlen+1];
				strncpy(data,start,strlen);
				data[strlen]='\0';
				//book->setTitle(data);
				mag->setTitle(data);

				//Read Magazine Publish Info
				start = ++pos;
				pos=(char*)strchr(start,';');
				strlen = pos-start;
				data = new char[strlen+1];
				strncpy(data,start,strlen);
				data[strlen]='\0';
				//book->setAuthor(data);
				mag->setPublishInfo(data);

				this->mediaList.push_back(mag);
				this->curr_cap++;
			}
			myfile.close();
		}
		else
		  cout <<"Unable to open file"<<endl;
	}
	else
		cout<<"Invalid Shelf Name"<<endl;
}

void Shelf::searchBook(int resp)
{
	if(resp==1)
	{
		ifstream myfile;
		myfile.open("Book_Shelf");//Book Shelf

		if (myfile.is_open())
		{
			string line;
			char* start = NULL;
			char* pos = NULL;
			char* title= NULL;
			char* author= NULL;
			char toSearch[51];
			int strlen=0;
			int count=0;

			cout<<"Enter Book title :: "<<endl;
			cin.ignore(numeric_limits<streamsize>::max(),'\n');
			cin.getline(toSearch,51);

			while ( getline (myfile,line) )
			{
				// Read book title
				start = (char*)line.c_str();
				pos=(char*)strchr(start,';');
				strlen = pos-start;
				title = new char[strlen+1];
				strncpy(title,start,strlen);
				title[strlen]='\0';

				if(strcmp(title,toSearch) == 0)
				{
					//Read book author
					start = ++pos;
					pos=(char*)strchr(start,';');
					strlen = pos-start;
					author = new char[strlen+1];
					strncpy(author,start,strlen);
					author[strlen]='\0';

					cout<<"Title :: "<<title<<" and Author :: "<<author<<endl;
					count++;
					delete author;
					author=NULL;
				}
				delete title;
				title=NULL;
			}
			cout<<"Total found books :: "<<count<<endl;
		myfile.close();
		}
		else
		  cout <<"Unable to open file"<<endl;
	}
	else if(resp==2)
	{
		ifstream myfile;
		myfile.open("Magazine_Shelf");//Magazine Shelf

		if (myfile.is_open())
		{
			string line;
			char* start = NULL;
			char* pos = NULL;
			char* title= NULL;
			char* publishInfo= NULL;
			char toSearch[51];
			int strlen=0;
			int count=0;

			cout<<"Enter Magazine title :: "<<endl;
			cin.ignore(numeric_limits<streamsize>::max(),'\n');
			cin.getline(toSearch,51);

			while ( getline (myfile,line) )
			{
				// Read book title
				start = (char*)line.c_str();
				pos=(char*)strchr(start,';');
				strlen = pos-start;
				title = new char[strlen+1];
				strncpy(title,start,strlen);
				title[strlen]='\0';

				if(strcmp(title,toSearch) == 0)
				{
					//Read book author
					start = ++pos;
					pos=(char*)strchr(start,';');
					strlen = pos-start;
					publishInfo = new char[strlen+1];
					strncpy(publishInfo,start,strlen);
					publishInfo[strlen]='\0';

					cout<<"Title :: "<<title<<" and Month & Year of Publish:: "<<publishInfo<<endl;
					count++;

					delete publishInfo;
					publishInfo=NULL;
				}
				delete title;
				title=NULL;
			}
			cout<<"Total found Magazines :: "<<count<<endl;
			myfile.close();
		}
		else
		  cout <<"Unable to open file"<<endl;
	}
}

void Shelf::addBook(int resp)
{
	if(resp == 1)
	{
		//const char *data = "Data Structure";
		char data[51]; //max no of character that can read for title & author is 50.
		ofstream myfile;
		Book* book = NULL;
		if(curr_cap >= max_cap)
		{
			cout<<"!!! Sorry !!! Book Shelf is FULL."<<endl;
			return;
		}
		myfile.open("Book_Shelf",ios::app);
		if (myfile.is_open())
		{
			book = new Book();
			cout<<"Enter Book title :: "<<endl;
			//cin>>data;
			cin.ignore(numeric_limits<streamsize>::max(),'\n');
			cin.getline(data,51);
			char* title = new char[strlen(data)+1];
			strcpy(title,data);
			book->setTitle(title);
			myfile<<endl<<title<<";";

			//data = "Ram Kumar";
			cout<<endl<<"Enter Book Author Name :: "<<endl;
			//cin>>data;
			cin.getline(data,51);
			char* author = new char[strlen(data)+1];
			strcpy(author,data);
			book->setAuthor(author);
			myfile<<author<<";";
			mediaList.push_back(book);
			myfile.close();
			cout<<"!!! Book added Successfully !!!"<<endl;
		}
		else
			cout << "Unable to open file";
	}
	else if(resp == 2)
	{
		char data[51]; //max no of character that can read for title & author is 50.
		ofstream myfile;
		Magazine* mag = NULL;
		if(curr_cap >= max_cap)
		{
			cout<<"!!! Sorry !!! Magazine Shelf is FULL."<<endl;
			return;
		}
		myfile.open("Magazine_Shelf",ios::app);
		if (myfile.is_open())
		{
			mag = new Magazine();
			cout<<"Enter Magazine title :: "<<endl;
			//cin>>data; //https://www.geeksforgeeks.org/clearing-the-input-buffer-in-cc/
			cin.ignore(numeric_limits<streamsize>::max(),'\n');
			cin.getline(data,51);
			char* title = new char[strlen(data)+1];
			strcpy(title,data);
			mag->setTitle(title);
			myfile<<endl<<title<<";";

			//data = "Ram Kumar";
			cout<<endl<<"Enter Magazine Publish Info :: "<<endl;
			//cin>>data;
			cin.getline(data,51);
			char* publishInfo = new char[strlen(data)+1];
			strcpy(publishInfo,data);
			mag->setPublishInfo(publishInfo);
			myfile<<publishInfo<<";";
			mediaList.push_back(mag);
			myfile.close();
			cout<<"!!! Magazine added Successfully !!!"<<endl;
		}
		else
			cout << "Unable to open file";
	}
}

void Shelf::removeBook(int resp)
{
	cout<<"!!! Not yet !!!"<<endl;
}
