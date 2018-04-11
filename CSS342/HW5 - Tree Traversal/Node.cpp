//#include "stdafx.h"
#include "Node.h"
#include <cstddef>

Node::Node(int data)
{
	this->value = data;  // creates node with value
	this->right = NULL;
	this->left = NULL;
}

Node::~Node()  // deconstructor
{
}
