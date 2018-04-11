#pragma once
#include "Pizza.h"
#include <string>
#include <iostream>
using namespace std;

const int pizzaCalories = 285;  // Pizza calories constant, from internet.

class Pizza
{
private:
	int numOfPizzas;  // variable for keeping track of pizza slices

public:
	Pizza();  // New pizza class
	~Pizza();  // Deconstructor

	void addPizzaSlices(int a);  // method to add pizza slices to someone's tracker
	int getPizzaSlices();     // Method to return pizza slices from's tracker
	Pizza operator+(Pizza);   // Addition Operator Overide
	Pizza operator-(Pizza);   // Subtraction Operator Overide
	Pizza operator/(Pizza);   // Division Operator Overide
	Pizza& Pizza::operator+=(const Pizza& apo);   // += Compound Operator Overide
	Pizza& Pizza::operator-=(const Pizza& apo);   // -= Compound Operator Overide
	bool Pizza::operator==(const Pizza &apo);   // == Compound Operator Overide
	bool Pizza::operator>(const Pizza &apo);   // > Compound Operator Overide
	bool Pizza::operator<(const Pizza &apo);   // < Compound Operator Overide
	Pizza(int numpizza);   // instanlize number of Pizza slices
};
