#include <string>
#include <iostream>
#include "Node.h"

using namespace std;


Node::Node() 
{
    prev = NULL;
    next = NULL;
    value = 0;
}

Node::Node(Node& in_prev, Node& in_next, int in_value) {
    prev = &in_prev;
    next = &in_next; 
    value = in_value;
}

Node::~Node() {}

Node* Node::getNextNode()
{
    return next;
}

Node* Node::getPrevNode()
{
    return prev;
}

int Node::getValue() 
{
    return value;
}

void Node::setNextNode(Node* input) {
    next = input;
}

void Node::setPrevNode(Node* input) {
    prev = input;
}

void Node::setValue(int val)
{
    value = val;
}
