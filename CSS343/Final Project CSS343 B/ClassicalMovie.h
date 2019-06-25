//--------------------ClassicalMovie.h--------------------
//Group 4 CSS 343 Section B
//Creation Date: 2/28/18
//Last Modification: 3/14/18
//-----------------------------------------------
//Purpose - Header file for the ClassicalMovie class
// contains comparison opperators
//-----------------------------------------------

#pragma once
#include "Movie.h"
#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>
class ClassicalMovie : public Movie
{
public:
	//---------------constructor/deconstructor---------------
	ClassicalMovie();  // constructor
	~ClassicalMovie();  // deconstructor

	//---------------Comparison Opperators---------------
	virtual bool setData(ifstream &);  // sets the data
	bool operator > (const Movie & inputMov); // more than opperator
	bool operator < (const Movie & inputMov);  // less than opperator
	bool operator == (const Movie & inputMov);  // equals operator

	//---------------Display---------------
	virtual void OutputInfo();  // displays the info of the classical movie
};
