#include <iostream>
#include <string>
#include "Supervisor.h"
using namespace std;

/*************************************************+
*                 Instructions:                   *
*   Place files into usual testing folder, and    *
*   run as usual, all outputs should be shown.    *
*   Additional note: Supervisor, Instructor, and  *
*   Student all inherited from Person.            *
+*************************************************/

void Demostration();

int main() {
    Demostration();
    return 0;
}

void Demostration(){
    cout << "TESTING INSERTING 3 Generic TEACHERS AND 20 Generic STUDENTS: Notice students were assigned as expected (in word document). " ;
    Supervisor c("Supervisor");  // creates new Supervisor "c" with name "Supervisor"
    string super;  // string to hold teacher string
    string student;  // string to hold student string
    for (int i = 1; i <= 3; i++){    // loop to create Teachers 1-3
        super = "Teacher " + to_string(i) ;
        c.addInstructor(super);
    }
    for (int i = 1; i <= 19; i++){      // loop to create Students 1-19
        super = "Student " + to_string(i) ;
        c.addStudent(super);
    }
    c.Print();  // Prints teachers and students.
    
    cout << "TESTING REMOVING \"TEACHER 1\":  Notice that students from Teacher 1 are moved to Teacher 2 & 3 as expected. ";
    // expected values can be found in a word doc attached.
    c.removeInstructor("Teacher 1");  // remove "Teacher 1"
    c.Print();  // Print to see results (also found in the word doc).
    
    cout << "TESTING ADDING STUDENT 'MISHA' TO TEACHER 3 AND FINDING THOSE VALUES: " << endl;
    c.addStudent("Misha", "Teacher 3");  // add student named "Misha" to "Teacher 2"
    cout << "Printing out Teacher 3's name:     " << c.getInstructor("Teacher 3")->getName() << endl;
    cout << "Printing out Misha's name:         " << c.getInstructor("Teacher 3")->getStudent("Misha")->getName() << endl;
    
    cout << endl <<"TESTING ADDING STUDENT 'PANDA' TO TEACHER 1 (who was deleted) AND FINDING THAT VALUE: " << endl;
    cout << "  EXPECATION:  \n  I expect to have notices that the input does not match for both the student and instructor as the instructor is gone and the student was not able to attend with that selected instructor. This seems fair as if I wanted a certain instructor, and he left the ski company, then I might go else where to take lessons with him. " << endl << endl;
    
    c.addStudent("PANDA" , "Teacher 1");  // add "PANDA" to "Teacher 1" - wont work since there is no Teacher 1.
    c.getInstructor("Teacher 1")->getStudent("PANDA")->getName();
    
    cout << endl <<"TESTING DELETING STUDENT 'Misha' FROM \"TEACHER 3\": " << endl;
    c.removeStudent("Misha");   // Removes student "Misha"
    c.getInstructor("Teacher 3")->getStudent("Misha")->getName();  // Expect to show there is no student anymore.
    
}
