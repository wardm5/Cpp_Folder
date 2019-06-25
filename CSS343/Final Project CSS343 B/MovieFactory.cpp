//--------------------MovieFactory.cpp--------------------
//Group 4 CSS 343 Section B
//Creation Date: 2/28/18
//Last Modification: 3/14/18
//-----------------------------------------------
//Purpose - Implementation file for the MovieFactory class
//contains create movie factor to create new movies
//-----------------------------------------------

#include "MovieFactory.h"

MovieFactory::MovieFactory()  // constructor
{
}
MovieFactory::~MovieFactory()  // deconstructor
{
}
//creates movie or
// returns a NULL if ttrying to create invalid genre
Movie * MovieFactory::creatMovie(char inputGenre)  
{
	Movie * ptr = NULL;
	switch (inputGenre)
	{
	case'D':
		ptr = new DramaMovie();
		return ptr;
	case'F':
		ptr = new ComedyMovie();
		return ptr;
	case'C':
		ptr = new ClassicalMovie();
		return ptr;

	default:
		return ptr;
	}
}
