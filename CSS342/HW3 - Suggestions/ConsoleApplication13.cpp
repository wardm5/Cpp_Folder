//#include "stdafx.h"
#include <string>
#include <iostream>
#include "Node.h"
#include "List.h"
#include <cstdlib>
#include <ctime>

using namespace std;

List<int> populateList(int value);
void demostration();

// HOW TO RUN: please place files in IDE or on Linux machine to run. Just run as usual, no user input is needed.

int main()
{
	//int pause;
	cout << endl;
	cout << endl;
	cout << "BIG O ANALYSIS: ASCENDING " << endl;
	List<int> a = populateList(10);   // populates list with 10 items
	List<int> b = populateList(100);   // populates list with 100 items
	List<int> c = populateList(1000);   // populates list with 1000 items
	cout << "10 item list ascending sort: ";
	a.sortAsc();   // sorts list a by ascending
	cout << "100 item list ascending sort: ";
	b.sortAsc(); // sorts list b by ascending
	cout << "1000 item list ascending sort: ";
	c.sortAsc(); // sorts list c by ascending
	cout << endl;
	cout << endl;

	cout << "SEARCH BIG O ANALYSIS: " << endl;
	cout << "10 item list: "  << endl;
	a.advancedSearch(7); // searches list a by ascending
	cout << endl;


	cout << "100 item list: "  << endl;
	b.advancedSearch(7); // searches list b by ascending
	cout << endl;

	cout << "1000 item list: "  << endl;
	c.advancedSearch(7); // searches list c by ascending
	cout << endl;
	
	demostration();  // calls function demostration
	//cin >> pause;
	return 0;
}


List<int> populateList(int value)   // populate list of the int value provided.
{
	List<int> x = List<int>();
	srand((unsigned)time(0)); //initialize random seed
	for (int i = 1; i <= value; i++)  // loops through to add the given amount of list items specified by value
	{
		int randomNum = rand() % 1000 + 1;    // creates a random number
		x.add(randomNum);   // adds the random number into the list
	}
	return x;
}

void demostration()
{
	cout << endl << "DEMOSTATION METHOD:";
	// doubly-linked list structure with at	least 10 objects
	List<int> alpha = List<int>();
	alpha.add(1);
	alpha.add(6);
	alpha.add(5);
	alpha.add(4);
	alpha.add(9);
	alpha.add(10);
	alpha.add(2);
	alpha.add(7);
	alpha.add(3);
	alpha.add(8);
	alpha.add(18);
	cout << endl;

	// Accending Sort
	cout << "Accending Sort: Expects to print 1 2 3 4 5 6 7 8 9 10 " << endl;
	alpha.sortAsc();  // expects to print 1 2 3 4 5 6 7 8 9 10
	alpha.print();
	cout << endl;

	// Search
	cout << "SEARCH:" << endl;
	cout << "Expects to find 6: " << endl;
	alpha.advancedSearch(6);
	cout << endl;
	cout << endl;
	cout << "Expects to not find -1 but provide the two closest matches: " << endl;
	alpha.advancedSearch(-1);
	cout << endl;
	cout << endl;
	cout << "Expects to find 1 and provide the closest match: " << endl;
	alpha.advancedSearch(1);
	cout << endl;
	cout << endl;
	cout << "Expects to not find 11 but provide the closet two matches (10 and 18): " << endl;
	alpha.advancedSearch(11);
	cout << endl;
	cout << endl;
	// Add
	cout << "Added 11 into list: ";

	alpha.add(11);
	alpha.sortAsc();
	cout << "Expects to  find 11 and provide the closet two matches (10 and 18): " << endl;
	alpha.advancedSearch(11);


}
