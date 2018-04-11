#pragma once
#include <string>
#include <iostream>

using namespace std;

class Node
{
private:
    int value; 
    Node* prev;
    Node* next;

public:
    Node();
    Node(Node & in_prev, Node& in_next, int in_value);
    ~Node();
    Node* getNextNode(); 
    void setNextNode(Node* input); 
    Node* getPrevNode();
    void setPrevNode(Node* input);
    int getValue();
    void setValue(int val);
};
