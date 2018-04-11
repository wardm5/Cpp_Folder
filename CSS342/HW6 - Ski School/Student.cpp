#include "Student.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;

Student::Student() {name = "";}  // constructor
Student::~Student() {}  // deconstructor
Student::Student(string newName) { name = newName;}  // constructor with name
