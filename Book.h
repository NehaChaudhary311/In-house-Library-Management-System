/*
 * Book.h
 *
 */

#ifndef BOOK_H_
#define BOOK_H_

#include <MediaType.h>

class Book: public MediaType
{
private:
	char* title;
	char* author;
	//char* genre;
public:
	Book();
	~Book();
	void setAuthor(char*);
	void setTitle(char*);
	void viewDetails();

};

#endif /* BOOK_H_ */
