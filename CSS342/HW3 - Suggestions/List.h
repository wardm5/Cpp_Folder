#pragma once
#include <string>
#include <iostream>
#include "Node.h"
#include <sys/time.h>


#ifndef _LIST
#define _LIST

using namespace std;
template<class T>  // template T
class List
{

public:
	List();    // creates list object 
	List(Node<T> & in_next);   // creates constructor for list object 
	~List();   // deconstructor for list object
	Node<T>* search(T value);  /* searches the list for a specific value,
							  returns node if found along with message
							  saying item was found or not.             */

	Node<T>* advancedSearch(T value); /* searches the list for a specific value,
									 returns node if found along with message
									  saying item was found or not along with the nearest results. */
	void add(T in_value);    // adds a node with a value to the list.
	void print();   // prints the values in the nodes starting at the head.
	void printFromTail();  // prints the values in the nodes starting with the tail.
	void swap(Node<T>* a, Node<T>* b); // swaps the values in node* a and node* b
	void sortAsc();   // sorts the list by ascending value
	void sortDesc();   // sorts the list by descending value
	Node<T>* head;  // creates a head node

};

//#include "node.cpp"
#endif


/*      LIST.CPP         */

struct timeval startTime, endTime;  // constructing time
template<class T>    // template T
List<T>::List()
{
	head = NULL;  // creates a null head for the list
}


template<class T>
List<T>::List(Node<T> & in_next) {
	head = &in_next;   // constructor for list which creates a reference for the head for to the next head
}

template<class T>
List<T>::~List() {}


template<class T>
void List<T>::add(T in_value) {  // adds new node to list
	Node<T> *p = NULL;  //  creates a pointer node p*
	Node<T>* x = new Node<T>(*p, *head, in_value);  // creates a new node with the pointer *p pointing to null, pointer to the next node, and then the value. 
	if (head != NULL)  // if the next node is null, 
	{
		head->setPrevNode(x); // set next node's previous pointer to the current node (creates the double linked list). 
	}
	head = x;  // otherwise head will equal x  (this is for new nodes)
}


template<class T>
void List<T>::print() {
	Node<T>* input = head;  // sets the input to the current head
	while (input != NULL)  // when the current head is not null loop through
	{
		cout << input->getValue() << " ";  // print out the current head value
		input = input->getNextNode();  // set the input to the next head
	}
	cout << endl;  // end line statement
}

template<class T>
void List<T>::printFromTail() {
	Node<T>* input = head;  // sets the input to the current head node
	while (input != NULL && input->getNextNode() != NULL)   // when the current head is not null loop through
	{
		input = input->getNextNode();  // set the input to the next head
	}
	while (input != NULL)   // when the current head is not null loop through
	{
		cout << input->getValue() << " ";    // print out the current head value
		input = input->getPrevNode();    // set the input to the previous  head
	}
	cout << endl;  // end line statement
}

template<class T>
Node<T>* List<T>::search(T value)
{
	gettimeofday( &startTime, NULL );	// Before execution time
	Node<T>* input = head;    // sets the input to the current head node
	Node<T>* newNode = NULL;
	while (input != NULL)     // when the current head is not null loop through
	{
		if (input->getValue() == value)  // if the current head value equels the value that is being searched...
		{
			cout << "Item \"" << value << "\" found." << endl;  // print out value found.
			newNode = input;
			return newNode;  // return the node, exit loop
		}
		input = input->getNextNode();  // point to the next node
	}
	cout << "Item \"" << value << "\" was not found." << endl;  // if nothing was found, say nothing was found
	gettimeofday( &endTime, NULL );		// After execution  time after code is finished
	cout << "Execution Time:  " << (endTime.tv_usec  -  startTime.tv_usec ) << " millisecond(s)." << endl;  // print out time it took for search to not find anything
	return newNode;  // return newNode (NULL) since nothing was found.
}

template<class T>
void List<T>::swap(Node<T>* a, Node<T>* b)  // swap method, input is node a, node b
{
	int tempA = a->getValue();  // set tempA to a node value
	int tempB = b->getValue();  // set tempB to b node value
	a->setValue(tempB);  // set node a's value to tempB's value
	b->setValue(tempA);  // set node b's value to tempA's value
}

template<class T>
void List<T>::sortAsc()
{
	gettimeofday( &startTime, NULL );	// Before execution set timer
	Node<T>* input = head;  // set input to current head
	int firstVal;  // first value variable
	int minVal; //  minimum value variable
	int currVal; // current value variable
	Node<T>* minNode;  // create pointer to the minimum node 
	while (input != NULL)    // when the current head is not null loop through
	{
		firstVal = input->getValue();  // set first value variable to current head value
		minVal = firstVal;   // set minimum value variable to first value 
		minNode = input;   // set minimum node value to the current head 
		Node<T>* nextInput = input->getNextNode();  // set pointer to the next head

		while (nextInput != NULL) // if the next head is not null
		{
			currVal = nextInput->getValue(); // set current value to the next head's input value

			if (currVal < minVal)  // if current value is less than min value, then..
			{
				minVal = currVal;  // set min value to current value

				minNode = nextInput;  // set the min node to the next head node.
			}
			nextInput = nextInput->getNextNode();  // set next head node to the next next head.
		}
		if (minVal != firstVal) // if min value does not equal first value...
		{
			swap(minNode, input); // swap the the value from min node and current head node.
		}
		input = input->getNextNode(); // set current head to next head
	}
	gettimeofday( &endTime, NULL );		// After execution get time
	cout << "Execution Time:  " << (endTime.tv_usec  -  startTime.tv_usec ) << " millisecond(s)." << endl;     // print out time it took for search to not find anything
}

template<class T>
void List<T>::sortDesc()  // same comments as above except if current value is greater than min value, then min value = current value.
{
	gettimeofday( &startTime, NULL );	
	Node<T>* input = head;
	int firstVal;
	int minVal;
	int currVal;
	Node<T>* minNode;
	while (input != NULL)
	{
		firstVal = input->getValue();
		minVal = firstVal;
		minNode = input;
		Node<T>* nextInput = input->getNextNode();

		while (nextInput != NULL)
		{
			currVal = nextInput->getValue();

			if (currVal > minVal)
			{
				minVal = currVal;

				minNode = nextInput;
			}
			nextInput = nextInput->getNextNode();
		}
		if (minVal != firstVal)
		{
			swap(minNode, input);
		}
		input = input->getNextNode();
	}
	gettimeofday( &endTime, NULL );		// After execution
	cout << "Execution Time:  " << (endTime.tv_usec  -  startTime.tv_usec ) << " millisecond(s)." << endl;
}

template<class T>
Node<T>* List<T>::advancedSearch(T value)
{
	gettimeofday( &startTime, NULL );	// Before execution time
	Node<T>* input = head;    // sets the input to the current head node
	Node<T>* newNode = NULL;
	if (input->getValue() > value)
	{
		cout << "Item \"" << value << "\" is not in the list." << endl;
		cout << "The closest item in the list to what you searched for is " << input->getValue() << "." << endl;
		cout << "The second closest item in the list you searched for is " << input->getNextNode()->getValue() << ".  " << endl;
		cout << "The third closest item in the list you searched for is " << input->getNextNode()->getNextNode()->getValue() << ".  ";

		gettimeofday( &endTime, NULL );		// After execution time
		cout << "Execution Time:  " << (endTime.tv_usec  -  startTime.tv_usec ) << " millisecond(s)." << endl;  // print out time it took for search
		return newNode;
	}

	while (input != NULL)     // when the current head is not null loop through
	{
		if (input->getValue() >= value)  // if the current head value equels the value that is being searched...
		{
			if (input->getValue() == value)
			{
				cout << "Item \"" << value << "\" found.  " << endl;  // print out value found.
				newNode = input;
				if (input->getPrevNode() == NULL)
				{
					break;
				}
				cout << "The closest previous item to what you searched for was \"" << input->getPrevNode()->getValue() << "\".  " << endl;
				if (input->getPrevNode()->getPrevNode() == NULL)
				{
					break;
				}
				cout << "The second closest previous item to what you searched for was \"" << input->getPrevNode()->getPrevNode()->getValue() << "\".  " ;


				input = input->getNextNode();  // point to the next node


				gettimeofday( &endTime, NULL );		// After execution time
				cout << "Execution Time:  " << (endTime.tv_usec  -  startTime.tv_usec ) << " millisecond(s)." << endl;  // print out time it took for search
				break;
			}
			if (input->getPrevNode() == NULL)
			{
				break;
			}
			if (input->getValue()< value && input->getNextNode()->getValue() >value)
			{
				cout << "The closest item in your search was \"" << input->getValue() << "\".  " ;  // print out value found.

				gettimeofday( &endTime, NULL );		// After execution time
				cout << "Execution Time:  " << (endTime.tv_usec  -  startTime.tv_usec ) << " millisecond(s)." << endl;  // print out time it took for search
			}

			cout << "The closest previous item to what you searched for was \"" << input->getPrevNode()->getValue() << "\".  " ;


			gettimeofday( &endTime, NULL );		// After execution time
			cout << "Execution Time:  " << (endTime.tv_usec  -  startTime.tv_usec ) << " millisecond(s)." << endl;  // print out time it took for search


			break;  // return the node, exit loop
		}
		input = input->getNextNode();  // point to the next node
	}
	while (input != NULL)     // when the current head is not null loop through
	{
		if (input->getValue() > value)  // if the current head value equels the value that is being searched...
		{
			cout << "The closest next item to what you searched for was \"" << input->getValue() << "\".  "  << endl;
			if (input->getNextNode() == NULL)
			{
				break;
			}
			cout << "The second closest next item to what you searched for was \"" << input->getNextNode()->getValue() << "\".  " << endl;

			if (input->getNextNode()->getNextNode() == NULL)
			{
				break;
			}
			cout << "The third closest next item to what you searched for was \"" << input->getNextNode()->getNextNode()->getValue() << "\".  ";

			gettimeofday( &endTime, NULL );		// After execution time
			cout << "Execution Time:  " << (endTime.tv_usec  -  startTime.tv_usec ) << " millisecond(s)." << endl;  // print out time it took for search

			return newNode;  // return the node, exit loop
		}
		input = input->getNextNode();  // point to the next node
	}

	if (newNode == NULL)
	{
		cout << "Item \"" << value << "\" was not found.  ";  // if nothing was found, say nothing was found
		gettimeofday( &endTime, NULL );		// After execution  time after code is finished
		cout << "Execution Time:  " << (endTime.tv_usec  -  startTime.tv_usec ) << " millisecond(s)." << endl;  // print out time it took for search to not find anything
	}
	gettimeofday( &endTime, NULL );		// After execution  time after code is finished
	cout << "Execution Time:  " << (endTime.tv_usec  -  startTime.tv_usec ) << " millisecond(s)." << endl;  // print out time it took for search to not find anything
	return newNode;  // return null since nothing was found.
}

