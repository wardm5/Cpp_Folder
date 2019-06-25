//-----------------customer.h--------------------
//Group 23 CSS 343 Section B
//Creation Date: 2/23/18
//Last Modification: 3/1/18
//-----------------------------------------------
//Purpose - Header file for the Customer class
//contains all function/field declarations
//Holds the name of a customer and their entire
//associated transaction history
//-----------------------------------------------
//Notes - Customer ID is not stored by the customer
//class because Customer ID is simply used as the key
//to associate customers in the hash map
//-----------------------------------------------

#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>
#include <list>
#include <iostream>
//transaction, factory, and all children
#include "transaction.h"
#include "transfactory.h"
#include "borrow.h"
#include "return.h"
#include "buy.h"

class Customer {
public:
	//---------------constructor/destructors---------------
	//constructor which initializes the customer with a name
	Customer(std::string name);

	//default destructor
	virtual ~Customer();

	//---------------overloaded operators------------------
	//overloaded << operator to output the transaction history of a customer to
	//a standard ostream.
	//This could be used for searching or viewing a customer's history
	//Each transaction is on a new line of the ostream
	friend std::ostream& operator<<(std::ostream& os, const Customer& cust);

	//-------------------other functions-------------------
	//returns the name of the customer
	string getName() const;

	//prints the history of all of the transactions for this customer
	//uses the overloaded << operator to get history list
	void showHistory() const;

	//adds a transaction to this customer's history
	//does not copy the transaction (does not manage the transaction memory)
	void addTransaction(const Transaction*);
private:
	//-----------------private fields(data)------------------
	//name of customer
	std::string name;
	//linked list of transactions associated with this customer for referencing
	std::list<Transaction*> history;
};

#endif