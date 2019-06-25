// ------------------------------------------------ return.h ----------------------------------------------------------
// Group 23 CS 343 Section B
// Creation Date: 2/23/18
// Creation Date: 3/1/18
// --------------------------------------------------------------------------------------------------------------------
// Purpose - Header file for the Return Class.
// This class is designed to replicate returning an item to the store.
// --------------------------------------------------------------------------------------------------------------------
// Notes on specifications, special algorithms, and assumptions.
//  -- N/a (look in the .cpp file)
// --------------------------------------------------------------------------------------------------------------------


#ifndef RETURN_h
#define RETURN_h
#include <fstream>
#include <iostream>
#include <string>
#include "Transaction.h"
using namespace std;

class Return : public Transaction {
public:
    //---------------constructor/destructors---------------
    //constructor which initializes the borrow class
    Return(); 
    
    //default destructor
    virtual ~Return();
    
    //---------------other functions---------------
    // returns the price of the item
    string getCondition();
    
    // return the fee of the rental.
    int getFee();
    
    // returns the pointer to a borrow transaction.
    Borrow* getBorrowTx();
    
private:
    //-----------------private fields(data)------------------
    // string denoting the condition of the item
    string condition;
    
    // fee for late return
    int fee;
    
    // pointer to a borrowed transaction
    Borrow* ptr;
};

#endif /* Return_h */
