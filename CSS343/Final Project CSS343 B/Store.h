//--------------------store.h--------------------
//Group 4 CSS 343 Section B
//Creation Date: 2/28/18
//Last Modification: 3/14/18
//-----------------------------------------------
//Purpose - Header file for the Store class
//contains all function/field declarations
//Store class meant to contain lists for all relevant
//data for running a movie rental store as well as
//function to interface with the store and all its components
//-----------------------------------------------
//Notes - Written to be extensible in the future
//for many types of new functionality
//If any new types of transactions or items are added,
//they will need to be included here
//-----------------------------------------------

#ifndef STORE_H
#define STORE_H

#include <istream>
#include <fstream>
#include <string>
#include "MovieFactory.h"
#include "Movielist.h"
#include "Customer.h"
static const int CUSTOMERLENGTH = 10000;
using namespace std;

class Store
{

private:
	MovieFactory MovieFact;
	Customer* customers[CUSTOMERLENGTH];
	Movielist inventory;

public:
	//---------------constructor/destructors---------------
	//default constructor initializes all of the private data structures
	//(which are all lists) as empty
	Store();

	//default destructor which deletes the hashmap (which deletes customers)
	//deletes all inventory items and all transactions
	//then deletes the private data structures themselves for cleanup
	~Store();

	//---------------Creators---------------
	// creates inventory, customer, transactions
	void CreateInventory();
	void CreateCustomers();
	void CreateTransactions();

	//---------------AddNewCustomer---------------
	// adds a new customer item
	bool AddNewCustomer(Customer&);

	//---------------Hash function---------------
	// hashes the customer for storage by name
	int hash(Customer&);

	//---------------DisplayInventory---------------
	// displays the inventory of the store
	void DisplayInventory();

	//---------------Transactions---------------
	// creates inventory, history, borrow, return transactions
	void InventoryTransaction(ifstream&);
	void HistoryTransaction(ifstream & fin);
	void BorrowTransaction(ifstream&);
	void ReturnTransaction(ifstream&);

	//---------------CustomerExist---------------
	// returns the value if the customer exists or not
	bool CustomerExist(int);

	//---------------Borrow actions---------------
	// creates borrow actions for genre
	void BorrowCommedy(ifstream&, Movie*, int);
	void BorrowDrama(ifstream&, Movie*, int);
	void BorrowClassical(ifstream &, Movie *, int);

	//---------------Return Actions---------------
	// creates return actions for genre
	void ReturnComedy(ifstream& , Movie*, int);
	void ReturnDrama(ifstream&, Movie*, int);
	void ReturnClassical(ifstream &, Movie*, int);

	//---------------GetEveryCustHist---------------
	//  gets complete customer history
	void GetEveryCustHist();
};
#endif
