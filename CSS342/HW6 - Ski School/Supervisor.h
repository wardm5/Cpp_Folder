#pragma once
#include <vector>
#include <string>
#include "Person.h"
#include "Instructor.h"
using namespace std;

class Supervisor : public Person
{
public:
	Supervisor();
	~Supervisor();
    Supervisor(string newName);
	void addInstructor(string newName);
    void addStudent(string newName);
    void addStudent(string newName, string profName);
    void removeStudent(string newName);
    void removeInstructor(string newName);
	//vector<Instructor> search();
    Instructor* getInstructor(string name);
    vector<Instructor*> getVector();
    vector<Instructor*> vectInstruct;
    void Print();
    Supervisor * root;
};
