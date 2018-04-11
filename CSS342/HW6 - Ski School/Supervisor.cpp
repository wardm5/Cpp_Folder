#include "Supervisor.h"
#include "Instructor.h"
#include <iterator>
#include <algorithm>

Supervisor::Supervisor() { name = ""; }  // constructor
Supervisor::~Supervisor(){}   // deconstructor

Supervisor::Supervisor(string newName){ name = newName; }  // constructor with name

void Supervisor::addInstructor(string newName) {
    vectInstruct.push_back(new Instructor(newName));  // adds instructor to the instructor vector
}

void Supervisor::addStudent(string newName) {  // adds new student
    if (vectInstruct.size() == 0) {   // if instrcutor vector is empty, then say there are no instructors to add the student to
        cout << "There are no instructors to add student to." << endl;
    } else if (vectInstruct.size() == 1) {   // if there is one instrutor, then add student to that instructor
        vectInstruct[0]->AddStudent(newName);
    } else {  // else...
        for (int i = 0; i <= vectInstruct.size()-1; i++){  // for all instructors in the vector
            if ((vectInstruct[vectInstruct.size()-1]->getVector().size() >= 8 || vectInstruct[vectInstruct.size()-1]->getVector().size() < 8)
                && vectInstruct[i]->getVector().size() == vectInstruct[vectInstruct.size()-1]->getVector().size()) {  // check to see if the end vector is over 8 or less than 5 and if the current number of students current instructor matches the number for the last instructor
                vectInstruct[i]->AddStudent(newName);  // add new student
                break;  // break out of loop to avoid duplicates
            } else if ((vectInstruct[i]->getVector().size() >=5 && vectInstruct[i]->getVector().size() <= 7) && vectInstruct[vectInstruct.size()-1]->getVector().size() == 5) {  // else if the current instructor has between 5 and 8 and the last instructor has 5 students...
                vectInstruct[i]->AddStudent(newName);  // add student to only this professor.
                break;  // break out of loop
            }
        }
    }
}

void Supervisor::addStudent(string newName, string profName) {  // add student to specific instructors
    if (vectInstruct.size() == 0) {  // if vector has no instructors
        cout << "There are no instructors to add student to." << endl;  // let user know and do not add student
    } else if (vectInstruct.size() == 1) {  // else if their is only one instructor... add student
        vectInstruct[0]->AddStudent(newName);
    } else {
        for (int i = 0; i <= vectInstruct.size()-1; i++){  // if there are multiple instructors
            if ((vectInstruct[vectInstruct.size()-1]->getVector().size() >= 8 || vectInstruct[vectInstruct.size()-1]->getVector().size() < 8)
                && vectInstruct[i]->getVector().size() == vectInstruct[vectInstruct.size()-1]->getVector().size()) {  // check to see if the current instructor and last instructor have at least below 5 students or above 8 students.
                for (int k = 0 ; k  <= vectInstruct.size()-1 ; k++){ //check all instructors to see if they match the professor name
                    if (vectInstruct[k]->getName() == profName) {  // if the name matches...
                        vectInstruct[k]->AddStudent(newName);      // then add student to that specific instructor.
                        break;  // break from loop
                    }
                }
            } else if ((vectInstruct[vectInstruct.size()-1]->getVector().size() >= 8 || vectInstruct[vectInstruct.size()-1]->getVector().size() < 8)
               && vectInstruct[i]->getVector().size() == vectInstruct[vectInstruct.size()-1]->getVector().size()) {  // else check to see if the current instrutor and last instructor have at least below 5 students or above 8
               vectInstruct[i]->AddStudent(newName); // then add the student
                break;  // break from loop.
            } else if ((vectInstruct[i]->getVector().size() >=5 && vectInstruct[i]->getVector().size() <= 7) && vectInstruct[vectInstruct.size()-1]->getVector().size() == 5 ) {  // if instructors have between 5 and 8 students, then add to the first instructor that has less than 8 students.
                vectInstruct[i]->AddStudent(newName); // add student to professor.
                break;  // break from loop
            }
        }
    }
}

void Supervisor::Print() {  // print instructors and students
    for (int i = 0; i < vectInstruct.size(); i++) {  // for all instructors in the instructors vector...
        cout << endl << vectInstruct[i]->getName() << ": " << endl;  // print out the instructor name
        for (int k = 0; k < vectInstruct[i]->getVector().size(); k++) {  // for all students that are under the instructor...
            cout << "   " << vectInstruct[i]->getVector()[k]->getName() << endl;  // print out their names.
        }
    }
    cout << endl;  // end line
}

void Supervisor::removeInstructor(string newName) {  // removes instructor
    Instructor * temp = getInstructor(newName);  // creates temporary instructor
    vector<Instructor*>::iterator it;  // creates iterator
    for (int i = 0; i < vectInstruct.size(); i++) {  // for all instructors...
        if (vectInstruct[i]->getName() == newName && vectInstruct[i]->getVector().size() == 0) {   // if instructors match the name to remove and student vector is empty..
            it = find(vectInstruct.begin(),vectInstruct.end(), temp);  // then find the instructor
            vectInstruct.erase(it);  // remove the instructor from the vector.
            return ;  // exit method
        } else if (vectInstruct[i]->getName() == newName && vectInstruct[i]->getVector().size() > 0) {  // if instructor name matches the one to remove and there are more more than one student in their vector...
            vector<Student*> tempStudentVector = temp->vectStudent;  //copy the student vector
            it = find(vectInstruct.begin(),vectInstruct.end(), temp);  // find the instructor
            vectInstruct.erase(it);  // remove the instructor
            for (int k = 0; k < tempStudentVector.size(); k ++ ){  // loop through the student vector
                this->addStudent(tempStudentVector[k]->getName());  // add student to other instructors
            }
            return ;
        } else {
            return ;
        }
    }
    cout << "No instructor matches your input. " << endl;  // return message if nothing happens.
}

void Supervisor::removeStudent(string newName) {  // remove student method
    for (int i = 0 ; i < vectInstruct.size(); i++) {  // for all instructors loop through...
        vectInstruct[i]->RemoveStudent(newName);  // for that instructor, remove the student
    }
}

Instructor* Supervisor::getInstructor(string input) {  // get instructor method
    for (int i = 0; i < vectInstruct.size(); i ++) {  // for all instructors in vector...
        if(vectInstruct[i]->getName() == input) {  // if name of instructor matches input...
            return vectInstruct[i];  // then return the instructor object
        }
    }
    cout << "No instructor matches your input. " << endl;  // else, let user know there are no instructors left.
    return new Instructor();  // return blank instructor.
}

vector<Instructor*> Supervisor::getVector(){ return vectInstruct; }  // returns the vector containing all instructors
