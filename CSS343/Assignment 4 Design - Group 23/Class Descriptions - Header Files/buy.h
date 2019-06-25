// ------------------------------------------------ buy.h ----------------------------------------------------------
// Group 23 CS 343 Section B
// Creation Date: 2/23/18
// Creation Date: 3/1/18
// --------------------------------------------------------------------------------------------------------------------
// Purpose - Header file for the Buy Class.
// This class is designed to replicate borrowing an item from the store.
// --------------------------------------------------------------------------------------------------------------------
// Notes on specifications, special algorithms, and assumptions.
//  -- N/a (look in the .cpp file)
// --------------------------------------------------------------------------------------------------------------------

#ifndef BUY_h
#define BUY_h
#include <fstream>
#include <iostream>
#include "transaction.h"
using namespace std;

class Buy : public Transaction {
public:
    //---------------constructor/destructors---------------
    //constructor which initializes the Buy class
    Buy();
    
    //  default deconstructor
    virtual ~Buy();
    
    //---------------other functions---------------
    //  returns the price of the item
    int getPrice();

private:
    //-----------------private fields(data)------------------
    // price of the item
    int price;
};

#endif
