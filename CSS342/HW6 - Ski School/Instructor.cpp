#include "Instructor.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>
using namespace std;

Instructor::Instructor(){ name = "";}  //  instructor constructor
Instructor::~Instructor(){}  // instructor deconstructor
Instructor::Instructor(string newName) {name = newName;}  // instructor constructor with data

void Instructor::AddStudent(string newName){  // add student
    vectStudent.push_back(new Student(newName));  // adds student to student vector
}

void Instructor::RemoveStudent(string input) {  // removes student
    vector<Student*>::iterator it;  // creates iterator
    for (int i = 0; i < vectStudent.size(); i++){   // loops through student vector..
        if (vectStudent[i]->getName() == input){  // if student name matches input...
            it = find(vectStudent.begin(),vectStudent.end() , vectStudent[i]);  // find the student value with iterator
            vectStudent.erase(it);  // delete student from vector
        }
    }
}

Student* Instructor::getStudent(string input) {  //  get student
    for (int i = 0; i < vectStudent.size() ; i ++) {  // loop through student vector
        if(vectStudent[i]->getName() == input) {  // if student name matches input..
            return vectStudent[i];  // return student
        }
    }
    cout << "No student matches your input. " << endl;  // if no student is found, then let user know.
    return new Student(); // return blank student
}

vector<Student*> Instructor::getVector(){ return vectStudent;}  // get vector method
