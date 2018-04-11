//#include "stdafx.h"
#pragma once
#include <string>
#include <iostream>
#include "SetData.h"

#ifndef _NODE
#define _NODE

using namespace std;

template <class T>
class Node
{
private:
	SetData<T> value;
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
	int getCount();
	void setCount(T val);
	void setValue(T val);
	void setNewValue(T val, bool exists);
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
	SetData<T>* a = new SetData<T>(in_value);
	value = *a;
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
	return value.getter();
}

template<class T>
int Node<T>::getCount()
{
	return value.getterCount();
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
	value.setValue(val);
}

template<class T>
void Node<T>::setCount(T val)
{
	value.setCount(val);
}

template<class T>
void Node<T>::setNewValue(T val, bool exists)
{
	value.setter(val, exists);
}
