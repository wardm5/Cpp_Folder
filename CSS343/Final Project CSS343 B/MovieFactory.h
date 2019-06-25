//--------------------MovieFactory.h--------------------
//Group 4 CSS 343 Section B
//Creation Date: 2/28/18
//Last Modification: 3/14/18
//-----------------------------------------------
//Purpose - Header file for the MovieFactory class
//contains method to create a new movie
//-----------------------------------------------

#ifndef MOVIEFACTORY_H
#define MOVIEFACTORY_H
#include "Movie.h"
#include "DramaMovie.h"
#include "ClassicalMovie.h"
#include "ComedyMovie.h"
class MovieFactory
{
public:
	MovieFactory();  // constructor
	Movie * creatMovie(char);  // creates movies
	~MovieFactory();  // deconstructor
};
#endif
