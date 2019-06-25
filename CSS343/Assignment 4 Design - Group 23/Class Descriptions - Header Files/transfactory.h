// ------------------------------------------------ transFactory.h ----------------------------------------------------------
// Group 23 CS 343 Section B
// Creation Date: 2/23/18
// Creation Date: 3/1/18
// --------------------------------------------------------------------------------------------------------------------
// Purpose - Header file for the transFactory Class.
// This class is designed to easily create new transactions types using parameters.
// --------------------------------------------------------------------------------------------------------------------
// Notes on specifications, special algorithms, and assumptions.
//  -- N/a (look in the .cpp file)
// --------------------------------------------------------------------------------------------------------------------

#ifndef transFactory_h
#define transFactory_h
#include "transaction.h"
#include "borrow.h"
#include "buy.h"
#include "return.h"

using namespace std;
class transFactory {
public:
    //---------------createTx---------------
    //constructor which initializes the specified Transaction type (borrow, buy, return, etc.)
    static Transaction* createTx(string name);
};

#endif
