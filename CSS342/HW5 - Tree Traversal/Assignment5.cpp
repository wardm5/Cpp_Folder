//#include "stdafx.h"
#include <string>
#include "Tree.h"
#include <iostream>
using namespace std;

/*----------------------------------------------------------*/
/*                      Instructions                        */
/* Please place all .h and .cpp files into folder as usual. */
/* Run program as usual, output will be run through         */
/* demostration method.                                     */
/*----------------------------------------------------------*/

void demostration();  // runs demostration method
Tree populateTree(int value);  // creates tree with x (parameter) amount of random numbers
Tree leftUnBal();              // creates a pre-determined left un-balanced tree
Tree rightUnBal();             // creates a pre-determined right un-balanced tree
Tree Balanced();               // creates a pre-determined balanced tree

int main()
{
	demostration();
  getchar();
	return 0;
}

void demostration()
{
	cout << endl << "BALANCED TREE: " << endl;
	Tree a = Balanced();
	a.print();
	cout << "Balanced In-Order:   ";
	a.inOrder();
	cout << "Balanced Pre-Order:   ";
	a.preOrder();
	cout << "Balanced Post-Order:   ";
	a.postOrder();
	cout << "Balanced Bredth-First:   ";
	a.breadthFirst();

	cout << endl << "LEFT-UNBLANCED TREE: " << endl;
	Tree b = leftUnBal();
	b.print();
	cout << "Left-Unbalanced In-Order:   ";
	b.inOrder();
	cout << "Left-Unbalanced Pre-Order:   ";
	b.preOrder();
	cout << "Left-Unbalanced Post-Order:   ";
	b.postOrder();
	cout << "Left-Unbalanced Bredth-First:   ";
	b.breadthFirst();

	cout << endl << "RIGHT-UNBLANCED TREE: " << endl;
	Tree c = rightUnBal();
	c.print();
	cout << "Right-Unbalanced In-Order:   ";
	c.inOrder();
	cout << "Right-Unbalanced Pre-Order:   ";
	c.preOrder();
	cout << "Right-Unbalanced Post-Order:   ";
	c.postOrder();
	cout << "Right-Unbalanced Bredth-First:   ";
	c.breadthFirst();

}

Tree populateTree(int value)   // populate tree of the int value provided.
{
	Tree x = Tree();
	srand((unsigned)time(0)); //initialize random seed
	for (int i = 1; i <= value; i++)  // loops through to add the given amount of tree items specified by value
	{
		int randomNum = rand() % 100 + 1;    // creates a random number
		x.add(randomNum);   // adds the random number into the tree
	}
	return x; // returns the tree
}

Tree leftUnBal()    // creates a left unbalanced tree of ten ints  (from 1-10)
{
	Tree x = Tree();
	x.add(8);
	x.add(9);
	x.add(10);
	x.add(6);
	x.add(5);
	x.add(7);
	x.add(3);
	x.add(2);
	x.add(1);
	x.add(4);
	return x;
}

Tree rightUnBal()    // creates a right unbalanced tree of ten ints  (from 1-10)
{
	Tree x = Tree();
	x.add(3);
	x.add(1);
	x.add(2);
	x.add(6);
	x.add(8);
	x.add(9);
	x.add(5);
	x.add(4);
	x.add(10);
	x.add(7);
	return x;
}

Tree Balanced()   // creates a balanced tree of ten ints  (from 1-10)
{
	Tree x = Tree();
	x.add(6);
	x.add(3);
	x.add(2);
	x.add(4);
	x.add(1);
	x.add(5);
	x.add(8);
	x.add(7);
	x.add(9);
	x.add(10);
	return x;
}
