#include <string>
#include <iostream>
#include "Node.h"
#include "List.h"
#include <cstdlib>
#include <ctime>
using namespace std;

List populateList(int value);
void demostration();

int main()
{
    int pause;
    cout << "BIG O ANALYSIS: ASCENDING " << endl;
    List a = populateList(10);
    List b = populateList(100);
    List c = populateList(1000);
    cout << "10 item list ascending sort: ";
    a.sortAsc();
    cout << "100 item list ascending sort: ";
    b.sortAsc();
    cout << "1000 item list ascending sort: ";
    c.sortAsc();
    a.search(7);
    b.search(7);
    c.search(7);
    cout << endl;
    
    cout << "BIG O ANALYSIS: DESCENDING " << endl;
    List m = populateList(10);
    List s = populateList(100);
    List n = populateList(1000);
    cout << "10 item list descending sort: ";
    m.sortDesc();
    cout << "100 item list descending sort: ";
    s.sortDesc();
    cout << "1000 item list descending sort: ";
    n.sortDesc();
    m.search(7);
    s.search(7);
    n.search(7);    
    
    demostration();
    cin >> pause;
    return 0;
}


List populateList(int value)
{
    List x = List();
    srand((unsigned)time(0)); //initialize random seed
    for (int i = 1; i <= value; i++)
    {
            int randomNum = rand() % 100 + 1;
            x.add(randomNum);
    }
    return x;
}

void demostration()
{
    cout << endl <<"DEMOSTATION METHOD:";
    // doubly-linked list structure with at	least 10 objects
    List alpha = List();
    alpha.add(1);
    alpha.add(6);
    alpha.add(5);
    alpha.add(4);
    alpha.add(9);
    alpha.add(10);
    alpha.add(2);
    alpha.add(7);
    alpha.add(3);
    alpha.add(8);
    cout << endl;
    // Printing from Head
    cout << "Print from Head:" << endl;
    cout << "Expects to print: 8 3 7 2 10 9 4 5 6 1" << endl;
    alpha.print();  // expects to print 8, 3, 7, 2, 10, 9, 4, 5, 6, 1
    cout << endl;
    // Printing from Tail
    cout << "Print from Tail:" << endl;
    cout << "Expects to print: 1 6 5 4 9 10 2 7 3 8" << endl;
    alpha.printFromTail();  // expects to print 1, 6, 5, 4, 9, 10, 2, 7, 3, 8
    cout << endl;
    // Accending Sort
    cout << "Accending Sort:" << endl;
    alpha.sortAsc();
    alpha.print();
    cout << endl;
    // Deccending Sort
    cout << "Deccending Sort:" << endl;
    alpha.sortDesc();
    alpha.print();
    cout << endl;

    // Search
    cout << "Search:" << endl;
    cout << "Expects to find 6: " << endl;
    alpha.search(6);
    cout << "Expects to not find 11: " << endl;
    alpha.search(11);

}