#include "Pizza.h"
#include <string>
#include <iostream>
using namespace std;


Pizza::Pizza()  // Pizza constructor
{
	numOfPizzas = 0;
}

Pizza::Pizza( int numpizza)  // Pizza constructor with instalization of pizza slices
{
	numOfPizzas = numpizza;
}

void Pizza::addPizzaSlices(int a)  // Add pizza function, adds pizza slices to the person.
{
	numOfPizzas = a;
}

int Pizza::getPizzaSlices()  // returns pizza slices function, returns pizza slices of that person.
{
	return numOfPizzas;
}

// apo = another pizza object
Pizza Pizza::operator+(Pizza apo)     // Addition operator overide
{
	Pizza brandNew;
	brandNew.numOfPizzas = numOfPizzas + apo.numOfPizzas;
	return brandNew;
}

Pizza Pizza::operator-(Pizza apo)       // Subtraction operator overide
{
	Pizza brandNew;
	brandNew.numOfPizzas = numOfPizzas - apo.numOfPizzas;
	return brandNew;
}

Pizza Pizza::operator/(Pizza apo)         // Divider operator overide
{
	Pizza brandNew;
	brandNew.numOfPizzas = (double) (numOfPizzas / apo.numOfPizzas);
	return brandNew; 
}

Pizza& Pizza::operator+=(const Pizza& apo)       // += Compound operator overide
{
	this->numOfPizzas += apo.numOfPizzas;
	return *this;
}


Pizza& Pizza::operator-=(const Pizza& apo)       // -= Compound operator overide
{
	this->numOfPizzas -= apo.numOfPizzas;
	return *this;
}



bool Pizza::operator==(const Pizza &apo)         // == Comparison operator overide
{
	;
	if (numOfPizzas == apo.numOfPizzas)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Pizza::operator>(const Pizza &apo)       // == Comparison operator overide
{
	;
	if (numOfPizzas > apo.numOfPizzas)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Pizza::operator<(const Pizza &apo)       // == Comparison operator overide
{
	;
	if (numOfPizzas < apo.numOfPizzas)
	{
		return true;
	}
	else
	{
		return false;
	}
}

Pizza::~Pizza()  // Pizza destructor
{
}
