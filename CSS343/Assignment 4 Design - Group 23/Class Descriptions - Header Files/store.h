//--------------------store.h--------------------
//Group 23 CSS 343 Section B
//Creation Date: 2/23/18
//Last Modification: 3/1/18
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

#include <string>
#include <vector>
#include <ctime>
#include "hashmap.h"
//transaction, factory, and all children
#include "transaction.h"
#include "transfactory.h"
#include "borrow.h"
#include "return.h"
#include "buy.h"
//item, factory, and all children
#include "item.h"
#include "itemfactory.h"
#include "food.h"
#include "movie.h"
#include "dramamovie.h"
#include "classicalmovie.h"
#include "comedymovie.h"

class Store {
public:
	//---------------constructor/destructors---------------
	//default constructor initializes all of the private data structures
	//(which are all lists) as empty
	Store();

	//default destructor which deletes the hashmap (which deletes customers)
	//deletes all inventory items and all transactions
	//then deletes the private data structures themselves for cleanup
	virtual ~Store();

	//-----------------processing functions----------------
	//function for parsing a command and calling the appropriate function in
	//order to carry out the command, also handles bad input by printing errors
	void doAction(std::string cmd);
	//	parse command action type
	//	if action type is H
	//		parse customerID
	//		custList.get(customerID).showHistory()
	//	else if action type is I
	//		for i in inventory
	//			print inventory[i]
	//	else if action type is B
	//		parse customerID
	//		parse Item
	//		if itemsAvailable(item)>0
	//			transFactory.createTx(tx)
	//	else if action type is R
	//		parse customerID
	//		parse Item
	//		transFactory.createTx(tx)
	//	else
	//		print error

	//function for adding a new item to the store inventory
	//will create the new Item with the ItemFactory to add
	//to the inventory vector
	void loadItem(std::string item, int quantity);
	//	parse item type
	//	if invalid item type
	//		print error and return
	//	else
	//		parse quantity
	//		parse item
	//		newInv = new invItem
	//		newInv.item = itemFactory.createItem(item)
	//		newInv.quantity = quantity
	//		add invItem to inventory vector

	//function for adding a new customer to the store custList
	//Will create a new customer object then add it to the hashmap with the key
	void loadCustomer(int key, std::string name);
	//	parse customerID
	//	parse customerName
	//	custList.put(key, name)

	//generates and adds a transaction with the associated transaction type
	//and customer for the related item. Adds the transaction to both the
	//master store list and specific customer history
	void createTransaction(std::string txType, int custID, std::string item);
	//	if txType is B
	//		if custList.get(custID) exists
	//			if itemsAvailable(item) > 0
	//				parse item
	//				find related customer
	//				generate due date
	//				tx = transFactory.createTx(tx)
	//				add tx to customer history
	//				add tx to txList
	//				create and add new checkedItems to checkedItemLog with tx
	//				find and update related item quantity in inventory
	//	if txType is R
	//		parse item
	//		find related customer
	//		find related B tx
	//		calculate price based on B tx due date with/without extra fees
	//		tx = transFactory.createTx(tx)
	//		add tx to customer history
	//		add tx to txList
	//		find and remove related checkedItems from checkedItemLog with tx
	//		find and update related item quantity in inventory

	//function for checking all the items that are checked out in the store,
	//their associated customer, and their associated due date which can be
	//used for auditing or other reasons
	//Will print out all items the store has currently checked out
	void checkDueItems();
	//	for i in checkedItemLog
	//		print checkedItemLog[i]

	//function for finding an item by searching the inventory,
	//then returning how many of those items are available in the store
	//Returns -1 if item was not found or doesn't exist
	int itemsAvailable(std::string item)
	//	search sorted inventory vector for item
	//	if not found, return -1
	//	if found, return intItem.quantity
private:
	//-------------------private structs-------------------
	//struct for storing items with their associated quantity for the inventory
	struct invItem {
		Item Item;
		int quantity;
	}

	//Node for checkedItemLog linked list to keep track of the store's checked
	//items for easy reference 
	struct checkedItems {
		Transaction* txID;
		std::time_t date;
		checkedItems* next;
	}

	//------------------private functions------------------
	//private function for sorting the inventory vector
	//using overloaded Item comparators
	void sortInv();

	//-----------------private fields(data)------------------
	//hashmap of customers for quick lookup by customer id (which is the key)
	HashMap custList;
	//sorted vector of inventory items and associated quantity for quick lookup
	//of inventory items
	std::vector<invItem> inventory;
	//linked list of checked items for easy lookup of items which are currently
	//checked/rented out and their associated due dates
	checkedItems* checkedItemLog;
	//vector of entire transaction history for the whole store
	//useful for auditing purposes
	std::vector<Transaction*> txList;
};

#endif
