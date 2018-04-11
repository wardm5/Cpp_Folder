#pragma once
#include <string>
#include <iostream>
#include "Node.h"

using namespace std;

class List
{

public:
    List();
    List(Node & in_next);
    ~List();
    Node* search(int value);
    void add(int in_value); 
    // void deleteNode(); ?
    void print();
    void printFromTail();
    void swap(Node* a, Node* b);
    void sortAsc();
    void sortDesc();
    Node* head;

};