/*
 * Magazine.h
 *
 */

#ifndef MAGAZINE_H_
#define MAGAZINE_H_

#include <MediaType.h>

class Magazine : public MediaType
{
private:
	char* title;
	char* publish_month_year;
public:
	Magazine();
	~Magazine();
	void setTitle(char*);
	void setPublishInfo(char*);
	void viewDetails();
};



#endif /* MAGAZINE_H_ */
