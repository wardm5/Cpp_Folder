//--------------------Movielist.h--------------------
//Group 4 CSS 343 Section B
//Creation Date: 2/28/18
//Last Modification: 3/14/18
//-----------------------------------------------
// Purpose - Header file for the MovieList class
// allows for the storage of different genre movies
//-----------------------------------------------

#ifndef MOVIELIST_H
#define MOVIELIST_H
#include "MovieBST.h"
static const int NUMBEROFGENRES = 3;

class Movielist
{
public:
	//---------------constructor/destructors---------------
	Movielist();  // movie constructor
	~Movielist();  // movie deconstructor

	//---------------Actions---------------
	bool insertMovie(Movie*);   // insert movie
	void displayClassical() const;  // display classical movies
	void ClearInventory();  // clears the inventory
	void displayDramas() const;  // display drama movies
	void displayComedy()const;  // display comedy movies
	MovieBST * movieList[NUMBEROFGENRES];  // movie BST for storage
};
#endif
