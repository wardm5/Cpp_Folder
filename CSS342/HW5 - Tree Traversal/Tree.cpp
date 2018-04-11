//#include "stdafx.h"
#include "Tree.h"
#include "Node.h"
#include <iostream>
#include <queue>
#include <cstddef>
#include <string>
using namespace std;

Tree::Tree() // creates tree
{
	root = NULL;
}

Tree::~Tree()  // tree deconstructor
{
}

Node * Tree::getRoot()  // gets the root
{
	return root;
}

int Tree::getNodeCount()   // returns the node count
{
	return nodeCount;
}

void Tree::add(int data)  // wrapper class for adding new node
{
	if (root == NULL) {  // checks if root is null
		root = new Node(data);  // adds new root
		nodeCount++;  // increases the node count
		return;
	}
	else {
		add(root, data);  // recursion to add root
	}
}

void Tree::add(Node * & root, int data)
{
	if (root == NULL)   // if root equals null pointer
	{
		root = new Node(data);  // create a new node with the value
		nodeCount++;  // increase node count by one
		return;   // return
	}
	else if (data < root->value)  // if data is less than root's value...
	{
		add(root->left, data);  // add root to the left
	}
	else
	{
		add(root->right, data);  // add root to the right
	}
}

void Tree::print()  // wrapper class for printing tree
{
	if (root == NULL)   // if root equals null pointer
	{
		return;    // return
	}
	else
	{
		print(root, "");   // call overridden method print with root and space
		cout << endl << endl; // new line, new line
	}
}

void Tree::print(Node * root, string space)
{
	if (root == NULL)   // if root equals null pointer
	{
		return;   // return
	}
	for (int i = 0; i < 2; i++)
	{
		 space = space + "  ";  // print spaces
	}

	print(root->right, space);  // recursion for right child
	cout << endl;  // new line


	cout << space;
	cout << root->value;  // print value
	print(root->left, space);  // recursion for left child
}


void Tree::inOrder() // wrapper class for in-order traversal
{
	if (root == NULL)   // if root equals null pointer
	{
		return;  // return
	}
	else
	{
		inOrder(root);  // overide preorder method with root
		cout << endl;  // add line break
	}
}

void Tree::inOrder(Node * root)
{
	if (root == NULL)   // if root equals null pointer
	{
		return;  // return
	}
	inOrder(root->left);   // recursion on left child
	cout << root->value << " ";   // print out root value and space
	inOrder(root->right);   // recursion on right child
}

void Tree::preOrder() // wrapper class for pre-order traversal
{
	if (root == NULL)   // if root equals null pointer
	{
		return;  // return
	}
	else
	{
		preOrder(root);  // overide preorder method with root
		cout << endl;   // add extra line
	}
}

void Tree::preOrder(Node * root)
{
	if (root == NULL)  // if root equals null pointer
	{
		return;  // return
	}
	cout << root->value << " ";   // print out root value and space
	preOrder(root->left);   // recursion on left child
	preOrder(root->right);   // recursion on right child
}

void Tree::postOrder() // wrapper class for post-order traversal
{
	if (root == NULL)  // if root equals null pointer
	{
		return;   // return
	}
	else
	{
		postOrder(root);  // overide preorder method with root
		cout << endl;  // add extra line
	}
}

void Tree::postOrder(Node * root) // post order
{
	if (root == NULL)  // if root equals null pointer
	{
		return;  // return
	}
	postOrder(root->left);  // recursion on left child
	postOrder(root->right);  // recursion on right child
	cout << root->value << " ";  // print out root value and space
}

void Tree::breadthFirst()  // wrapper class for bredth first search
{
	if (root == NULL)  // if root equals null pointer
	{
		return;  // return
	}
	else
	{
		breadthFirst(root);  // overide preorder method with root
		cout << endl << endl;  // add extra line
	}
}

void Tree::breadthFirst(Node * root)
{
	queue<Node*> q;  // creates a new queue

	while (root != NULL)  // while root does not equal null pointer
	{
		cout << root->value << " ";  // print the root value with "  "

		if (root->left)  // if left child is not null
			q.push(root->left);  // add left child to queue

		if (root->right)  // if right child is not null
			q.push(root->right);   // add right child to queue

		if (!q.empty())  // if queue is not empty
		{
			root = q.front();  // root equals the queue's next item
			q.pop();  // pop that item
		}
		else
			root = NULL;  // else root will equal nullptr
	}
}
