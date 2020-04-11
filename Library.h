/*
 * Library.h
 *
 */

#ifndef LIBRARY_H_
#define LIBRARY_H_

#include <Shelf.h>
#include <MediaType.h>
#include <Book.h>
#include <Magazine.h>

class Library
{
private:
	Shelf* ls;
public:
	Library();
	void init();
	void viewLibrary();
	void searchBook();
	void addBook();
	void removeBook();
	~Library();
};

#endif /* LIBRARY_H_ */
