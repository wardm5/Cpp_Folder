// ------------------------------------------------ Movie.h -------------------------------------------------------
//Group 23 CSS 343 Section B
// Creation Date: 2/28/18
// Date of Last Modification: 2/28/18
// --------------------------------------------------------------------------------------------------------------------
// Purpose - This is an abstract class that represents the item movie
//We do this so we can have multiple items we perform trasnactions on in our database. 
//This class represents Movies in our inventory
// -------------------------------------------------------------------------------------------------------------------- 
#include "item.h"
class Movie : public Item
{
public:
	//--------Default Constructor--------
	//Sets all the member variables to null
	Movie();
	
	// destructor
	virtual ~Movie();
	
	//-------------Comparison operators---------------
	//The comparison operators are used to compare two Movies of differnet types
	//so we are able to store them in our inventory sorted
	virtual bool operator > (const Item *);
	virtual bool operator < (const Item *);
	virtual bool operator == (const Item *);

};

