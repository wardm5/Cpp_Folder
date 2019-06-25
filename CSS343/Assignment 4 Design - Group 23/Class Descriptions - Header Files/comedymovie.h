// ------------------------------------------------ ComedyMovie.h -------------------------------------------------------
//Group 23 CSS 343 Section B
// Creation Date: 2/28/18
// Date of Last Modification: 2/28/18
// --------------------------------------------------------------------------------------------------------------------
// Purpose -
//We use the ComedyMovie to represent 
//The comedy Movies we have in our inventory
// -------------------------------------------------------------------------------------------------------------------- 
#include "Movie.h"
class ComedyMovie: public Movie
{
public:
//--------Default Constructor--------
//Sets all the member variables to null
	ComedyMovie();


//--------GetTitle()--------
//Member variable getter for Title
	string GetTitle();

//--------GetDirector()--------
//Member variable getter for Director
	string GetDirector();

//--------GetReleaseYear()--------
//Member variable getter for ReleaseYear
	string GetReleaseYear();

	//-------------Comparison operators---------------
	//The comparison operators are used to compare two comedy movies
	//so we are able to store them in our inventory sorted
	virtual bool operator > (const Item &);
	virtual bool operator < (const Item &);
	virtual bool operator == (const Item &);

//Sets all the member variables to null
	~ComedyMovie();
private:
	string Title;
	int ReleaseYear;
	string Director;

};

