/*
 * Magazine.cpp
 *
 */

#include <Magazine.h>
#include <iostream>
using namespace std;

Magazine::Magazine()
{
	this->title = NULL;
	this->publish_month_year = NULL;
}

Magazine::~Magazine()
{
	delete this->title;
	this->title = NULL;
	delete this->publish_month_year;
	this->publish_month_year = NULL;
}

void Magazine::setTitle(char* title)
{
	this->title = title;
}

void Magazine::setPublishInfo(char* publishInfo)
{
	this->publish_month_year = publishInfo;
}

void Magazine::viewDetails()
{
	cout<<"Title:: "<<this->title<<" and Month & Year of Publish:: "<<this->publish_month_year<<endl;
}
