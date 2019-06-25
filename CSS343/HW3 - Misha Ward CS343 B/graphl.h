// ------------------------------------------------ graphl.h ----------------------------------------------------------
// Misha Ward CS343 Section B
// Febuary 12, 2018
// Febuary 17, 2018
// --------------------------------------------------------------------------------------------------------------------
// This program is designed to create a graph as a data structure using adjacency lists.
// --------------------------------------------------------------------------------------------------------------------
// Notes on specifications, special algorithms, and assumptions.
//  -- N/a (look in the .cpp file)
// --------------------------------------------------------------------------------------------------------------------

#ifndef graphl_h
#define graphl_h
#include <fstream>
#include <iostream>
#include "nodedata.h"
using namespace std;

struct EdgeNode;      // forward reference for the compiler
struct GraphNode {    // structs used for simplicity, use classes if desired
    EdgeNode* edgeHead; // head of the list of edges
    NodeData* data;     // data information about each node
    bool visited;      // bool keeping track if node has been visited
};

struct EdgeNode {
    int adjGraphNode;  // subscript of the adjacent graph node
    EdgeNode* nextEdge; 
};

class GraphL {
public:
    GraphL();  // graph constructor
    ~GraphL(); // graph deconstructor
    void buildGraph(ifstream& infile); // builds up graph node information and adjacency list of edges between each node reading from a data file.
    void insert(int From, int To); // inserts a node and edge.
    void displayGraph(); //  displays the graph information to user
    void depthFirstSearch(); // function to initiate DFS for a node

private:
    int sizeOfArray; // size of current array
    GraphNode* adjList; // array of GraphNodes
    // helper functions:
    void removeNode(int Value); // removes first node from value given
    void resetVisited(); //Set all visited to false
    void dfs(int Value); // helper function to find DFS node
};

#endif /* graphl_hpp */
