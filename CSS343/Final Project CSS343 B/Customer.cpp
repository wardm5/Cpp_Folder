//--------------------Customer.cpp--------------------
//Group 4 CSS 343 Section B
//Creation Date: 2/28/18
//Last Modification: 3/14/18
//-----------------------------------------------
//Purpose - Implementation file for the Customer class
//contains
//-----------------------------------------------

#include "Customer.h"

Customer::Customer()  // constructor
{
	head = NULL;
}

Customer::~Customer()  // deconstructor
{
	ClearCustHist();
}
//set customer from data file
bool Customer::setData(fstream & fin)
{
	string checkID= "";
	fin >> checkID;
	if (fin.eof())// if cant open file returns false
	{
		return false;
	}
	if (checkID.length() != 4)  // if length is not 4
	{
		cout << endl <<checkID << " is an invalid Customer ID";  // not valid ID
		return false;
	}
	else  // else
	{
		int TestIdValue = stoi(checkID);  // ID = input
		if (TestIdValue < 0) // if the input is less than 0
		{
			cout << "CustomerID is invalid" << endl;  // if the id is invalid
			return false;
		}
		else  // else  set info
		{
			fin >> lName;
			fin >> fName;
			id = checkID;
		}
	}

}

//Adds transaction to customer history linked list
void Customer::addToCustHistory(string inputActionType, string inputMovieTitle)
{
	if (head == NULL)  // if head is NULL
	{
		head = new HistoryNode;  // set info for head to parameters
		head->actionType = inputActionType;
		head->movieTitle = inputMovieTitle;
		head->next = NULL;  // set head  next to NULL
	}
	else  // create new head and set info to parameters
	{
		HistoryNode * temp = NULL;
		temp = new HistoryNode;
		temp->actionType = inputActionType;
		temp->movieTitle = inputMovieTitle;
		temp->next = head;
		head = temp;
	}

}

//outputs cusotmer history(Linked List)
void Customer::outputCustHistory()
{
	if (head == NULL)
	{
		cout << endl << fName << " " << lName <<
			" does not have any transactions." << endl;
	}
	else
	{
		HistoryNode * it = head;
		cout << endl;
		cout << fName << " " << lName
			<< " History: " << endl;
		while (it != NULL)
		{
			cout << "Transaction type: " << it->actionType
			<< " Movie Title " << it->movieTitle << ". ";
			cout << endl;
			it = it->next;
		}
		cout << endl;
	}
}

int Customer::GetidAsInt() // getter for id
{
	int intID = stoi(id);
	return intID;
}

string Customer::GetID()
{
	return id;
}

//delete customer history// Linked List
void Customer::ClearCustHist()
{
	if (head == NULL)  // if head equals NULL
	{
		return; // return NULL
	}
	else  // else
	{
		while (head != NULL)  // if head does not equal NULL
		{
			HistoryNode * it = head;  // set it to head
			head = head->next;  // head equals next
			it->next = NULL;  // it will be NULL
			delete it; // delete it
		}
		delete head;  // delete head
		head = NULL;  // set head to NULL
	}
}
