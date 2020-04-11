/*
 * Shelf.h
 *
 */

#ifndef SHELF_H_
#define SHELF_H_

#include <MediaType.h>
#include <list>

#define MAX_SHELF_CAP 10

class Shelf
{
private:
	std::list<MediaType*> mediaList;
	int max_cap;
	int curr_cap;
public:
	Shelf();
	~Shelf();
	void init(const char*);
	std::list<MediaType*> getMediaList();

	void viewBooks();

	void searchBook(int);
	void addBook(int);
	void removeBook(int);
};

#endif /* SHELF_H_ */
