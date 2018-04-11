#pragma once
class Node
{
public:
	Node(int data);  // creates a node
	~Node();  // deconstructor

	Node * right;  // right child
	Node * left;  // left child
	int value;  // int value
};
