#include "Person.h"
#include <iostream>
#include <string>

using namespace std;

Person::Person() { name = ""; }  // constructor
Person::~Person() {}             // deconstructor
Person::Person(string input) { name = input;}  // constructor with name

string Person::getName()  {  // gets the person's name
    if (!NULL) {  // while name not null
        return name;  // return name
    } else {  // else...
        cout << "No student was found with this name or the professor did not exist." << endl ;  // return statement alerting user.
        return NULL;  // return null
    }
}

void Person::setName(string input) { name = input; }  // set name method. 
