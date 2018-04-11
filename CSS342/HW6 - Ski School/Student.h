#pragma once
#include "Person.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Student : public Person
{
public:
    Student();  
    ~Student();
    Student(string newName);
};

