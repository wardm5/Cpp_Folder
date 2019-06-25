// ------------------------------------------------ ItemFactory.h -------------------------------------------------------
//Group 23 CSS 343 Section B
// Creation Date: 2/28/18
// Date of Last Modification: 2/28/18
// --------------------------------------------------------------------------------------------------------------------
// Purpose -
//We use the itemFactory to create new items
//This is used to facilitate adding new children of items in the future.
// -------------------------------------------------------------------------------------------------------------------- 
#include <string>
#include "Item.h"
#include "Movie.h"
#include "dramaMovie.h"
#include "classicalMovie.h"
#include "comedyMovie.h"

class ItemFactory
{
public:
	//---------CreateItem()----------
	//This function is used to create the correct
	//Item type based on the type of Item passed in
	static Item* createItem(string name);
};

