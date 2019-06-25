// ------------------------------------------------ Item.h -------------------------------------------------------
//Group 23 CSS 343 Section B
// Creation Date: 2/28/18
// Date of Last Modification: 2/28/18
// --------------------------------------------------------------------------------------------------------------------
// Purpose -
//is a template for all the different types of Items that are in the
//store(movie, food, etc.).The creation of a particular Item is managed by the itemFactory.
// -------------------------------------------------------------------------------------------------------------------- 
#include <string>
using namespace std;
class Item
{
public:

//------------Default Consturctor------
//This will set the Item type to empty
	Item();
	
	//Deconstructor
	~Item();
	

//-------------getType()---------------
//This function gets the type of item. For example if the item is movie
//This will be able to return movie.
	string getType();

//-------------Comparison operators---------------
//The comparison operators are used to compare two items
//so we are able to store them in our inventory
	virtual bool operator > (const Item &) =0;
	virtual bool operator < (const Item &)=0;
	virtual bool operator == (const Item &)=0;

private:
	string Type;
};

