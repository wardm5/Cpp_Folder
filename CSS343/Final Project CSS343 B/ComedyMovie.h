//--------------------ComedyMovie.h--------------------
//Group 4 CSS 343 Section B
//Creation Date: 2/28/18
//Last Modification: 3/14/18
//-----------------------------------------------
//Purpose - Header file for the Store class
//contains comparison functions as well as
// display
//-----------------------------------------------


#include "Movie.h"
#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>
class ComedyMovie : public Movie
{
public:
	//---------------constructor/deconstructor---------------
	ComedyMovie(); // constructor
	virtual~ComedyMovie();  // deconstructor

	//---------------comparison opperators---------------
	bool operator > (const Movie & inputMov);  // greater than opperator
	bool operator < (const Movie & inputMov);  // less than opperator
	bool operator == (const Movie & inputMov);  // equals operator

	//---------------Display---------------
	virtual void OutputInfo();  // displays the info of the comedy movie
};
