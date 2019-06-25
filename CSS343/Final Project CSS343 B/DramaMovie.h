//--------------------DramaMovie.h--------------------
//Group 4 CSS 343 Section B
//Creation Date: 2/28/18
//Last Modification: 3/14/18
//-----------------------------------------------
//Purpose - Header file for the DramaMovie class
//contains comparison functions as well as 
// display
//-----------------------------------------------


#include "Movie.h"
#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
class DramaMovie : public Movie
{
public:
		//---------------constructor/destructors---------------
	DramaMovie(); // constructor
	virtual ~DramaMovie();  // deconstructor

	//---------------comparison operators---------------
	bool operator > (const Movie & inputMov);  // greater than operator
	bool operator < (const Movie & inputMov);  // less than operator
	bool operator == (const Movie & inputMov);  // equals operator

	//---------------display---------------
	virtual void OutputInfo();  // display info
};
