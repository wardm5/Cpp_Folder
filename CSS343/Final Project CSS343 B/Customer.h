//--------------------Customer.h--------------------
//Group 4 CSS 343 Section B
//Creation Date: 2/28/18
//Last Modification: 3/14/18
//-----------------------------------------------
//Purpose - Header file for the Customer class
//contains
//-----------------------------------------------

#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <iostream>
#include<fstream>
#include <string>
using namespace std;
class Customer
{
public:
	//---------------constructor/destructors---------------
	Customer(); // constructor
	~Customer();  // destructor

	//---------------Customer actions---------------
	bool setData(fstream&);  // set data
	void addToCustHistory(string, string);  // add customer to history
	void outputCustHistory();  // display history
	int GetidAsInt();  // change ID to Int
	string GetID();  // get ID
	void ClearCustHist();  // clear history

private:
	// creates a new node
	struct HistoryNode
	{
		string actionType;
		string movieTitle;
		HistoryNode* next;
	};
	HistoryNode* head;
	string id;
	string fName;
	string lName;
};
#endif
