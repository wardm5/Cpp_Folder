// ------------------------------------------------ ClassicalMovie.h -------------------------------------------------------
//Group 23 CSS 343 Section B
// Creation Date: 2/28/18
// Date of Last Modification: 2/28/18
// --------------------------------------------------------------------------------------------------------------------
// Purpose -
//We use the ClassicalMovie to represent 
//The classical Movies we have in our inventory
// -------------------------------------------------------------------------------------------------------------------- 
#include "Movie.h"
class ClassicalMovie : public Movie
{
public:
	//--------Default Constructor--------
	//Sets all the member variables to null
	ClassicalMovie();


	//--------GetTitle()--------
	//Member variable getter for Title
	string GetTitle();

	//--------GetDirector()--------
	//Member variable getter for Director
	string GetDirector();

	//--------GetReleaseYear()--------
	//Member variable getter for ReleaseYear
	string GetReleaseYear();

	//--------GetLeadActor()--------
	//Member variable getter for LeadActor
	string GetLeadActor();

	//-------------Comparison operators---------------
	//The comparison operators are used to compare two Classical movies
	//so we are able to store them in our inventorysprted
	virtual bool operator > (const Item &);
	virtual bool operator < (const Item &);
	virtual bool operator == (const Item &);

	//Sets all the member variables to null
	~ClassicalMovie();


private:
	string Title;
	int ReleaseYear;
	string Director;
	string LeadActor;

};

