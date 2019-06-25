// ------------------------------------------------ transaction.h ----------------------------------------------------------
// Group 23 CS 343 Section B
// Creation Date: 2/23/18
// Creation Date: 3/1/18
// --------------------------------------------------------------------------------------------------------------------
// Purpose - Header file for the Transaction Class.
// This program is designed to replicate transactions such as buy, return, and borrow.
// --------------------------------------------------------------------------------------------------------------------
// Notes on specifications, special algorithms, and assumptions.
//  -- N/a (look in the .cpp file)
// --------------------------------------------------------------------------------------------------------------------

#ifndef TRANSACTION_h
#define TRANSACTION_h
#include <fstream>
#include <iostream>
#include <string>
#include "items.h"
using namespace std;

class Transaction {
public:
    //---------------constructor/destructors---------------
    //constructor which initializes the borrow class
    Transaction();
    
    //default destructor
    virtual ~Transaction();
    
    //---------------other functions---------------
    // returns the string of the unique ID
    string getUniqueID();
    
     // gets the customer ID
    int getCustID();
    
    // gets the date
    date getDate();
    
    // gets the Item
    virtual Item getItem(Item* current) = 0;

private:
    //-----------------private fields(data)------------------
    string uniqueID;
    int custID;
    
    // date information
    date Date;
    
    // items array of pointers
    Items** items;
};

#endif
