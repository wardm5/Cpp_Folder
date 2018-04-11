#include <string>
#include <iostream>
#include "Node.h"
#include "List.h"
#include <sys/time.h>
using namespace std;

struct timeval startTime, endTime;

List::List() 
{
    head = NULL;
}



List::List(Node & in_next) {
    head = & in_next;
}

List::~List() {}

void List::add(int in_value) {
    Node *p = NULL;
    Node* x = new Node(*p, *head, in_value);
    if (head != NULL)
    {
            head->setPrevNode(x);
    }
    head = x;
}


void List::print() {
    Node* input = head; 
    while (input != NULL)
    {
            cout << input->getValue() << " ";
            input = input->getNextNode();
    }
    cout << endl;
}

void List::printFromTail() {
    Node* input = head;
    while (input != NULL && input->getNextNode() != NULL)
    {
            input = input->getNextNode();
    }
    while (input != NULL)
    {
            cout << input->getValue() << " ";
            input = input->getPrevNode();
    }
    cout << endl;
}

Node* List::search(int value)
{
    gettimeofday( &startTime, NULL );	// Before execution
    Node* input = head;
    while (input != NULL)
    {
            if (input->getValue() == value)
            {
                    cout << "Item \"" << value << "\" found." << endl;
                    gettimeofday( &endTime, NULL );		// After execution
                    cout << "Execution Time:  " << (endTime.tv_usec  -  startTime.tv_usec ) << " millisecond(s)." << endl;
                    return input;
            }
            input = input->getNextNode();
    }
    cout << "Item \"" << value << " was not found." << endl;
    gettimeofday( &endTime, NULL );		// After execution
    cout << "Execution Time:  " << (endTime.tv_usec  -  startTime.tv_usec ) << " millisecond(s)." << endl;
    return NULL;

}

void List::swap(Node* a, Node* b)
{
    int tempA = a->getValue();
    int tempB = b->getValue();
    a->setValue(tempB);
    b->setValue(tempA);
}

void List::sortAsc()
{
    gettimeofday( &startTime, NULL );	// Before execution
    Node* input = head;
    int firstVal;
    int minVal;
    int currVal;
    Node* minNode;
    while (input != NULL)
    {
        firstVal = input->getValue();
        minVal = firstVal;
        minNode = input;
        Node* nextInput = input->getNextNode();

        while (nextInput != NULL)
        {
                currVal = nextInput->getValue();

                if (currVal < minVal)
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

void List::sortDesc()
{
    gettimeofday( &startTime, NULL );	// Before execution
    Node* input = head;
    int firstVal;
    int minVal;
    int currVal;
    Node* minNode;
    while (input != NULL)
    {
        firstVal = input->getValue();
        minVal = firstVal;
        minNode = input;
        Node* nextInput = input->getNextNode();

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