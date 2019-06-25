// ------------------------------------------------ graphm.h ----------------------------------------------------------
// Misha Ward CS343 Section B
// Febuary 12, 2018
// Febuary 17, 2018
// --------------------------------------------------------------------------------------------------------------------
// This program is designed to create a graph as a data structure using file input using adj. matrixes.
// --------------------------------------------------------------------------------------------------------------------
// Notes on specifications, special algorithms, and assumptions.
//  -- N/a (look in the .cpp file)
// --------------------------------------------------------------------------------------------------------------------

#ifndef graphm_hpp
#define graphm_hpp
#include <fstream>
#include "nodedata.h"

const int MAXNODES = 101; // 101 nodes as index 0 is skipped over

struct TableType {
    bool visited;          // whether node has been visited
    int dist;              // shortest distance from source known so far
    int path;              // previous node in path of min dist
};

class GraphM {
public:
    GraphM(); // data member T is initialized to sets all dist to infinity,
              // sets all visited to false, and sets all path to 0.
    void buildGraph(ifstream& infile);  // build the graph with file input
    void findShortestPath();  // to find all current data
    void insertEdge(int From, int To, int Weight); // insert an edge into graph between two given nodes
    void removeEdge(int From, int To); // remove an edge between two given nodes
    void displayAll() const;  // default call to display all data
    void display(int From,int To) const; // display info for node from/to

private:
    NodeData data[MAXNODES];              // data for graph nodes
    int C[MAXNODES][MAXNODES];            // Cost array, the adjacency matrix
    int size;                             // number of nodes in the graph
    TableType T[MAXNODES][MAXNODES];      // stores visited, distance, path
    
    // Private Helper Functions:
    void resetVisited();                  // this function helps reset the visited nodes to false
    void getPath(int From, int To) const;  // gets the path from one node to another and couts the output
    void getPathData(int From, int To) const;  // gets the location path and couts the string of the location
};

#endif
