//#include "stdafx.h"
#include <string>
#include <iostream>
#include "Node.h"
#include "List.h"
#include "Set.h"
#include "SetData.h"
#include <cstdlib>
#include <ctime>
#include <sstream>
#include <vector>

using namespace std;

Set<string> populateStringSet(vector<string> & v, int value);  // creates a new set with string values
Set<int> populateSet(int value); // populates set with random ints
List<int> populateList(int value);  // populates list with random ints
void demostration(); // runs driver tests

// HOW TO RUN: please place files in IDE or on Linux machine to run. Just run as usual, no user input is needed.

int main()
{
	demostration();
	return 0;
}

List<int> populateList(int value)   // populate list of the int value provided.
{
	List<int> x = List<int>();
	srand((unsigned)time(0)); //initialize random seed
	for (int i = 1; i <= value; i++)  // loops through to add the given amount of list items specified by value
	{
		int randomNum = rand() % 10 + 1;    // creates a random number
		x.add(randomNum);   // adds the random number into the list
	}
	return x; // returns the list
}

Set<int> populateSet(int value)   // populate Set of the int value provided.
{
	Set<int> x = Set<int>();
	srand((unsigned)time(0)); //initialize random seed
	for (int i = 1; i <= value; i++)  // loops through to add the given amount of Set items specified by value
	{
		int randomNum = rand() % 10 + 1;    // creates a random number
		x.add(randomNum);   // adds the random number into the Set
	}
	return x; // returns the set
}

Set<string> populateStringSet(vector<string> & v, int value)
{
	Set<string> x = Set<string>(); // new set
	for (int i = 0; i < value - 1; i++)  // loops through to add the given amount of Set items specified by value
	{
		x.add(v[i]);   // adds the string into the Set
	}
	return x; // returns the set
}

void demostration()
{
	cout << endl << "CREATED SET OF TEN INTS: " << endl;
	Set<int> a = populateSet(10);   // populates Set with 10 items
	a.print();  // print Set
	a.sortAsc();  // sort set
	cout << endl << endl << "SORT SET OF TEN INTS BY COUNT VALUE: " << endl;
	a.print();  // print sorted set

	cout << endl << endl << "RETREIVE TOP THREE ITEMS BY COUNT: " << endl;
	a.topThree();  // prints the top three values (after sorting the set)

	cout <<  endl << endl << "CREATED NEW SET TO TEST GET (search) FUNCTION: " << endl;
	Set<int> b = Set<int>();

	cout << "Created set, when searching for value of 5, I expect to find nothing:  " << endl;
	cout << b.searchSet(5) << endl;   // expect to find nothing
	b.add(5);
	cout << endl << "Added 5 to set, when searching for value of 5, I expect to find 5 and count of 1:  " << endl;
	cout << b.searchSet(5) << endl;  // expect to find a 5 with count 1
	b.add(5);
	cout << endl << "Added another 5 to set, when searching for value of 5, I expect to find 5 and count of 2:  " << endl;
	cout << b.searchSet(5) << endl;  // expect to find a 5 with count 2
	cout << endl << "Removed 5 from set, when searching for value of 5, I expect to find 5 and count of 1:  " << endl;
	b.remove(5);
	cout << endl << "Removed 5 again from set, when searching for value of 5, I expect that the value 5 to be removed from set:  " << endl;
	b.remove(5);

	string sentence = "Hello, my name name is Misha and I am am in CS342.";
	vector<string> stringVector;  // new string vector

	int counter = 0;
	istringstream iss(sentence);  // string stream
	while (iss) {  //  while next word
		string word;  // string word
		iss >> word;  // if string is word, then add to variable word
		stringVector.push_back(word);  // push word into vector
		counter++;  // add to counter
	}
	Set<string> c = populateStringSet(stringVector, counter);
	cout << endl << endl << "CREATED SET OF A SENTENCE: Hello, my name name is Misha and I am am in CS342." << endl;
	c.print();
	cin.ignore();
}
