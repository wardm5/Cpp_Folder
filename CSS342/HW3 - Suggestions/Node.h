#pragma once
#include <string>
#include <iostream>

#ifndef _NODE
#define _NODE

using namespace std;

template <class T>
class Node
{
private:
	T value;
	Node<T>* prev;
	Node<T>* next;

public:
	Node();
	Node(Node<T> & in_prev, Node<T>& in_next, T in_value);
	~Node();
	Node<T>* getNextNode();
	void setNextNode(Node<T>* input);
	Node<T>* getPrevNode();
	void setPrevNode(Node<T>* input);
	T getValue();
	void setValue(T val);
};

//#include "Node.cpp"
#endif


/*      NODE.CPP         */
template<class T>
Node<T>::Node()
{
	prev = NULL;
	next = NULL;
	value = NULL;
}

template<class T>
Node<T>::Node(Node<T>& in_prev, Node<T>& in_next, T in_value) {
	prev = &in_prev;
	next = &in_next;
	value = in_value;
}

template<class T>
Node<T>::~Node() {}

template<class T>
Node<T>* Node<T>::getNextNode()
{
	return next;
}

template<class T>
Node<T>* Node<T>::getPrevNode()
{
	return prev;
}

template<class T>
T Node<T>::getValue()
{
	return value;
}

template<class T>
void Node<T>::setNextNode(Node<T>* input) {
	next = input;
}

template<class T>
void Node<T>::setPrevNode(Node<T>* input) {
	prev = input;
}

template<class T>
void Node<T>::setValue(T val)
{
	value = val;
}
