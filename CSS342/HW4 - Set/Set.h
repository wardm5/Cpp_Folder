#pragma once
#include <string>
#include <iostream>
#include "Node.h"
#include "List.h"
#include "SetData.h"

using namespace std;

template <class T>
class Set : public List<T>
{
public:
	//void playFootball() { cout << "I can play Football." << endl; }

	//template<class T>
	void add(T in_value) {  // adds new node to list
		bool exists = 0;
		Node<T>* head = this->getHead();
		Node<T>* input = head;
		SetData<T>* a = new SetData<T>();
		while (input != NULL)  // when the current head is not null loop through
		{
			if (input->getValue() == in_value)
			{
				bool exists = true;
				input->setNewValue(in_value, exists);
				//a->setter(in_value, exists);
				return;
			}
			input = input->getNextNode();
		}
		Node<T> *p = NULL;  //  creates a pointer node p*
		Node<T>* x = new Node<T>(*p, *head, in_value);  // creates a new node with the pointer *p pointing to null, pointer to the next node, and then the value.
		if (head != NULL)  // if the next node is null,
		{
			head->setPrevNode(x); // set next node's previous pointer to the current node (creates the double linked list).
		}
		this->setHead(x);  // otherwise head will equal x  (this is for new nodes)
	}

	void print() {
		Node<T>* input = this->getHead();  // sets the input to the current head
		int counter = 1;
		while (input != NULL)  // when the current head is not null loop through
		{
			cout << "[ITEM IN SET: " << counter << "]  " ;
			cout << "Value: " << input->getValue() << ",  ";  // print out the current head value
			cout << "Count: " << input->getCount() << endl ;  // print out the current head value
			counter++;
			input = input->getNextNode();  // set the input to the next head
		}
	}

	void sortAsc()
	{
		Node<T>* input = this->getHead();  // sets the input to the current head
		T firstVal;  // first value variable
		T minVal; //  minimum value variable
		T currVal; // current value variable
		Node<T>* minNode;  // create pointer to the minimum node
		while (input != NULL)    // when the current head is not null loop through
		{
			firstVal = input->getCount();  // set first value variable to current head value
			minVal = firstVal;   // set minimum value variable to first value
			minNode = input;   // set minimum node value to the current head
			Node<T>* nextInput = input->getNextNode();  // set pointer to the next head

			while (nextInput != NULL) // if the next head is not null
			{
				currVal = nextInput->getCount(); // set current value to the next head's input value

				if (currVal > minVal)  // if current value is less than min value, then..
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

	//template<class T>
	void swap(Node<T>* a, Node<T>* b)  // swap method, input is node a, node b
	{
		T tempA = a->getValue();  // set tempA to a node value
		T tempB = b->getValue();  // set tempB to b node value
		a->setValue(tempB);  // set node a's value to tempB's value
		b->setValue(tempA);  // set node b's value to tempA's value
		tempA = a->getCount();  // set tempA to a node value
		tempB = b->getCount();  // set tempB to b node value
		a->setCount(tempB);  // set node a's value to tempB's value
		b->setCount(tempA);  // set node b's value to tempA's value
	}

	//template<class T>
	T searchSet(T value)
	{
		Node<T>* input = this->getHead();  // sets the input to the current head
		Node<T>* newNode = NULL;
		while (input != NULL)     // when the current head is not null loop through
		{
			if (input->getValue() == value)  // if the current head value equels the value that is being searched...
			{
				cout << "Item \"" << value << "\" found." << endl;  // print out value found.
				newNode = input;
				cout << "Count of item in Set: ";
				return newNode->getCount();  // return the node, exit loop
			}
			input = input->getNextNode();  // point to the next node
		}
		cout << "Item \"" << value << "\" was not found." << endl;  // if nothing was found, say nothing was found
		cout << "Count of item in Set: ";
		return NULL;  // return newNode (NULL) since nothing was found.
	}

	void topThree()
	{
		sortAsc();
		Node<T>* input = this->getHead();  // sets the input to the current head
		for (int i = 0; i < 3; i++)
		{
			if (input != NULL)
			{
				cout << "[Item " << i << "]  " << " Value: " << input->getCount() << ", " << " Count: " << input->getCount() << endl;
				input = input->getNextNode();
			}
		}
	}
};
