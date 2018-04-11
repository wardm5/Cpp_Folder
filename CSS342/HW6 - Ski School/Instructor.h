#pragma once
#include "Person.h"
#include "Student.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Instructor : public Person
{
public:
	Instructor();
	~Instructor();
    Instructor(string newName);
    void AddStudent(string newName);
    Student* getStudent(string name);
    void RemoveStudent(string input);
    vector<Student*> getVector();
    vector<Student*> vectStudent;
};

