//--------------------Movielist.cpp--------------------
//Group 4 CSS 343 Section B
//Creation Date: 2/28/18
//Last Modification: 3/14/18
//-----------------------------------------------
//Purpose - Implementation file for the MovieList class
// allows for the storage of different genre movies
//-----------------------------------------------


#include "Movielist.h"
//initilizing array of Movie tree the size is three... one for each genre
Movielist::Movielist()
{
	for (int i = 0; i < NUMBEROFGENRES; i++)
	{
		movieList[i] = new MovieBST();
	}
}

//Going through the array and deleting each tree of the 3 genres
Movielist::~Movielist()
{
	for (int i = 0; i < NUMBEROFGENRES; i++)
	{
		movieList[i]->makeEmpty();

	}
}

//Insert movie the correct tree depending on genre
bool Movielist::insertMovie(Movie* addMov)
{
	if (addMov->GetGenre() == 'F')
	{
		movieList[0]->addMovie(addMov);
		return true;
	}
	else if (addMov->GetGenre() == 'D')
	{
		movieList[1]->addMovie(addMov);
		return true;
	}
	else if (addMov->GetGenre() == 'C')
	{
		movieList[2]->addMovie(addMov);
		return true;
	}
	else
	{
		return false;
	}
}
void Movielist::displayComedy()const
{
	movieList[0]->outputInOrder();
}
void Movielist::displayDramas()const
{
	movieList[1]->outputInOrder();
}
void Movielist::displayClassical()const
{
	movieList[2]->outputInOrder();
}

//goes through and deletes the tree for the three indexes
void Movielist::ClearInventory()
{
	for (int i = 0; i < NUMBEROFGENRES; i++)
	{
		movieList[i]->makeEmpty();
	}

}
