// ------------------------------------------------ borrow.h ----------------------------------------------------------
// Group 23 CS 343 Section B
// Creation Date: 2/23/18
// Creation Date: 3/1/18
// --------------------------------------------------------------------------------------------------------------------
// Purpose - Header file for the Borrow Class.
// This class is designed to replicate borrowing an item from the store.
// --------------------------------------------------------------------------------------------------------------------
// Notes on specifications, special algorithms, and assumptions.
//  -- N/a (look in the .cpp file)
// --------------------------------------------------------------------------------------------------------------------

#ifndef BORROW_h
#define BORROW_h
#include <fstream>
#include <iostream>
#include "transaction.h"
using namespace std;

class Borrow : public Transaction {
public:
    //---------------constructor/destructors---------------
    //constructor which initializes the borrow class
    Borrow();
    
    //default destructor
    virtual ~Borrow();
    
    //---------------other functions---------------
    // returns the date of the item
    Date getTimeDue();  //  //
    
    //  returns the regular rate of the item
    int getRegularRate();
    
    //  returns the overdue rate of the item
    int getOverRate();
    
    // returns the max fee of the borrow
    int getMaxFee();

private:
    //-----------------private fields(data)------------------
    // price of the regular rate
    int regularRate;
	
	// price of the overdue rate
    int overDueRate;
	
	// price of the max fee
    int maxFee;
	
	// date due
	date timeDue;
};

#endif
