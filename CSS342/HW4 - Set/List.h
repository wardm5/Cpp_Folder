//#include "stdafx.h"
#pragma once
#include <string>
#include <iostream>
#include "Node.h"
using namespace std;

#ifndef _LIST
#define _LIST
template<class T>   // template T
class List
{
public:
	List();    // creates list object
	List(Node<T> & in_next);   // creates constructor for list object
	~List();   // deconstructor for list object
	Node<T>* search(T value);  /* searches the list for a specific value,
							   returns node if found along with message
							   saying item was found or not.             */

							   //Node<T>* advancedSearch(T value);
							   /* searches the list for a specific value,
							   returns node if found along with message
							   saying item was found or not along with the nearest results. */
	virtual void add(T in_value);    // adds a node with a value to the list.
	virtual void print();   // prints the values in the nodes starting at the head.
	void printFromTail();  // prints the values in the nodes starting with the tail.
	virtual void swap(Node<T>* a, Node<T>* b); // swaps the values in node* a and node* b
	void sortAsc();   // sorts the list by ascending value
	void sortDesc();   // sorts the list by descending value
	Node<T>* head;  // creates a head node
	void remove(T removeValue);
	Node<T>* getHead();
	void setHead(Node<T>* input);

};


#endif

/*      LIST.CPP         */
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
	return newNode;  // return newNode (NULL) since nothing was found.
}

template<class T>
void List<T>::swap(Node<T>* a, Node<T>* b)  // swap method, input is node a, node b
{
	T tempA = a->getValue();  // set tempA to a node value
	T tempB = b->getValue();  // set tempB to b node value
	a->setValue(tempB);  // set node a's value to tempB's value
	b->setValue(tempA);  // set node b's value to tempA's value

}

template<class T>
void List<T>::sortAsc()
{
	Node<T>* input = head;  // set input to current head
	T firstVal;  // first value variable
	T minVal; //  minimum value variable
	T currVal; // current value variable
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
}

template<class T>
void List<T>::sortDesc()  // same comments as above except if current value is greater than min value, then min value = current value.
{
	Node<T>* input = head;
	T firstVal;
	T minVal;
	T currVal;
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
}

template<class T>
void List<T>::remove(T removeValue) {
	Node<T>* input = head;    // sets the input to the current head node
	Node<T>* newNode = NULL;
	while (input != NULL)     // when the current head is not null loop through
	{
		if (input->getValue() == removeValue)  // if the current head value equels the value that is being searched...
		{
			if (input->getCount() > 1)
			{
				int count = input->getCount();
				count--;
				input->setCount(count);
				cout << "Item \"" << removeValue << "\" found. Count for item is: " << count << endl;  // print out value found.
				return;
			}
			else if (input->getNextNode() != NULL && input->getPrevNode() != NULL)
			{
				Node<T>* prevNode = input->getPrevNode();
				Node<T>* nextNode = input->getNextNode();
				prevNode->setNextNode(input->getNextNode());
				nextNode->setPrevNode(input->getPrevNode());
				cout << "Item \"" << removeValue << "\" found and removed." << endl;  // print out value found.
				delete input;
				return;
			}
			else
			{
				cout << "Item \"" << removeValue << "\" found and removed." << endl;  // print out value found.
				delete input;
				return;
			}

		}
		input = input->getNextNode();  // point to the next node
	}
	cout << "Item \"" << removeValue << "\" was not found." << endl;  // if nothing was found, say nothing was found
	return;  // return newNode (NULL) since nothing was found.
}

template<class T>
Node<T>* List<T>::getHead()
{
	return head;
}

template<class T>
void List<T>::setHead(Node<T>* input)
{
	head = input;
}
