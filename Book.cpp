/*
 * Book.cpp
 *
 */

#include <Book.h>
#include <iostream>
using namespace std;

Book::Book()
{
	this->title = NULL;
	this->author = NULL;
}

Book::~Book()
{
	delete this->title;
	this->title = NULL;

	delete this->author;
	this->author = NULL;

}

void Book::setTitle(char* title)
{
	this->title = title;
}

void Book::setAuthor(char* author)
{
	this->author = author;
}

void Book::viewDetails()
{
	cout<<"Title:: "<<this->title<<" and Author:: "<<this->author<<endl;
}
