#pragma once
#include <iostream>
#include <string>
using namespace std;

class Person
{
public:
	Person();
	~Person();
    Person(string input);
	string getName();
	void setName(string input);
    
protected:
	string name;
};


