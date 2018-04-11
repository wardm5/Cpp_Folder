#pragma once
#include "Node.h"
#include <string>

using namespace std;

class Tree
{
public:
	// Constructor/Destructor
	Tree();
	~Tree();

	Node * getRoot();  // gets root of the tree
	int getNodeCount();  // gets the node count
	void add(int data);  // add node to tree
	void add(Node * & root, int data);  // override add
	void print();  // print tree
	void print(Node * root, string space);  // print overide
	void inOrder();  // print tree in-Order
	void inOrder(Node * root);
	void preOrder();  // print tree pre-Order
	void preOrder(Node * root);
	void postOrder();  // print tree post-Order
	void postOrder(Node * root);
	void breadthFirst();  // print tree using breadth-first
	void breadthFirst(Node * root);
private:
	Node * root;  // creates root of the tree
	int nodeCount;  // node count
};
