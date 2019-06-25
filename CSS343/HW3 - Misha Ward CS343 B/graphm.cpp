// ------------------------------------------------ graphm.cpp --------------------------------------------------------
// Misha Ward CS343 Section B
// Febuary 12, 2018
// Febuary 17, 2018
// --------------------------------------------------------------------------------------------------------------------
// This program is designed to create a graph as a data structure using file input using adj. matrixes.
// --------------------------------------------------------------------------------------------------------------------
// Notes on specifications, special algorithms, and assumptions.
//  -  displayAll() - this function displays the results of the graph to the user
//  -  buildGraph(ifstream& infile) - function is used to build the graph using adj. lists
//  -  findShortestPath() - uses Dijkstra's algorithm to search through nodes for the shortest path
//  -  display(int From, int To) - this function displays
//  --- Assumptions - Inputs from the file are correct. 
// --------------------------------------------------------------------------------------------------------------------

#include "graphm.h"
#include <limits.h>
#include <fstream>

// ------------------------------------Graph Constructor----------------------------------------------
// Description:  This constructor builds the graph and sets all values to default values.
// ---------------------------------------------------------------------------------------------------
GraphM::GraphM() {  // default constructor, data is set to an empty string
    size = 0;
    for (int i = 0; i < MAXNODES; i++) { // loops through the columns
        for (int j = 0; j < MAXNODES; j++) {  // loops through the rows
            C[i][j] = INT_MAX;  // sets new info to infinity
            T[i][j].dist = INT_MAX;     // sets new info to infinity
            T[i][j].path = 0;  // sets path to 0
            T[i][j].visited = false;  // sets default to false
        }
    }
}

// ------------------------------------buildGraph-----------------------------------------------------
// Description:  Build graph is responsilbe for reading the file and creating the nodes and data for
// the graph.
// ---------------------------------------------------------------------------------------------------
void GraphM::buildGraph(ifstream& infile) {
    string s = "";  // generic string placeholder
    int a = 0;      // generic int placeholder
    infile >> a;  // input amount of strings to loop through...
    size = a;     // node size equals to a
    for (int i = 0; i <= a; i ++) {  // loop thorugh size
        if (infile.eof()) break;   // break if no more lines of data
        data[i].setData(infile);   // set the location strings to the data array.
    }
    int From = -1, To = -1, Width = -1;  // create ints to keep track of From, To, and Width
    while (From != 0 && To !=0 && Width != 0) {  // while From, To, and Width are not equal to 0
        infile >> a;  // next int input equals a
        From = a;     // From equals a
        infile >> a;  // next int input equals a
        To = a;       // To equals a
        infile >> a;  // next int input equals a
        Width = a;     // Width equals a
        if (From == 0 && To == 0 && Width == 0) {
            break;  // break from loop if From, To, and Width equals 0
        }
        C[From][To] = Width; // else create the edge.
    }
}

// ------------------------------------insertEdge-----------------------------------------------------
// Description:  This fucntion inserts an edge into the adjacentcy matrix.
// ---------------------------------------------------------------------------------------------------
void GraphM::insertEdge(int From, int To, int Weight) {
    C[From][To] = Weight;  // sets Weight as value in adjacentcy matrix
}

// ------------------------------------removeEdge-----------------------------------------------------
// Description:  This fucntion inserts an edge into the adjacentcy matrix.
// ---------------------------------------------------------------------------------------------------
void GraphM::removeEdge(int From, int To) { // remove an edge between two given nodes
    C[From][To] = INT_MAX;  // sets adjacentcy matrix value back to infinity
}

// ------------------------------------findShortestPath-----------------------------------------------
// Description:   This function finds the shortest path and fills in the helper matrix that holds the
//                updated weights and paths.
// ---------------------------------------------------------------------------------------------------
void GraphM::findShortestPath() {
    int v = 0; // set vertex to current position at 0
    int w = 0; // set w to current position at 0
    for (int source = 1; source <= size; source++) { //start at source = 1
        T[source][source].dist = 0; //Set at 0
        for (int i = 1; i<= size; i++) {
            int min = INT_MAX;
            for (int j = 1; j <= size; j++) {  // loops through the row to determine v
                if (T[source][j].visited == false && T[source][j].dist <= min) {  // if source is not visited and
                                                                                  // source is less than min...
                    min = T[source][j].dist;  // set min to the column weight
                    v = j;  // set v to the column index
                }
            }
            T[source][v].visited = true;    //  mark v as visited
            for (int i = 1; i < size+1; i++) {  // loop through the row
                w = i; //current position at state in algorithm
                if (T[source][w].visited == false && C[v][w] != INT_MAX) {  //  If the helper matrix postion has been not visted
                                                                            // and the adj. matrix is not infinity...
                    if (!(T[source][w].dist < (T[source][v].dist + C[v][w]))) {  // if the helper matrix weight is less than
                                                                            // the current weight plus the new weight
                        T[source][w].dist = (T[source][v].dist + C[v][w]);  // set weight for helper matrix to helper matrix
                                                                            // plus the adj matrix weight
                        T[source][w].path = v; //Add v to the path
                    }
                }
            }
        }
        resetVisited(); // reset all visted values to false
    }
}

// ------------------------------------resetVisited---------------------------------------------------
// Description:  This method resets the visited data to false in the helper matrix
// ---------------------------------------------------------------------------------------------------
void GraphM::resetVisited() {
    for(int i = 1; i < size+1; i++) {  // loops through the columns
        for (int j = 1;j< size+1;j++) {  // loops through the rows
            T[i][j].visited = false; //set all "visits" to false
        }
    }
}

// ------------------------------------displayAll-----------------------------------------------------
// Description:  This function displays the graph data in a summary table.
// ---------------------------------------------------------------------------------------------------
void GraphM::displayAll() const {
    string space1 = "          ";  // generic string for space
    string space2 = "            ";    // generic string for space
    string space3 = "                               ";    // generic string for space
    
    // creates the header for the display
    cout << "Description              From Node    To Node    Dijikstra's      Path" << endl;
    for (int i = 1;i < size + 1; i++) {  // loops through the columns
        cout << data[i] << endl; // couts the description of the first node.
        for(int j = 1; j < size + 1; j++) {  //  loop for rows
            if (T[i][j].dist > 0 && T[i][j].dist < INT_MAX) {  // if the weight of the helper node
                                                    // is greater than 0 and less than infinitiy...
                cout << space3 <<right<< i << space1 << j;  // print out the To and From
                cout << space2 << T[i][j].dist << space1;  // Print out the distance/weight
                getPath(i,j); // call print the path function
                cout << endl;
            } else if (i != j) { // if the path does not exist...
                cout << space3 << right<< i << space1 << j << space2;  // cout the To and From
                cout << "----" << space1 << endl; // show the return of ---- for no path
            }
        }
    }
    cout << endl;
}

// ------------------------------------display--------------------------------------------------------
// Description:  Displays data from one node (From) to another (To) to the user on the console.
// ---------------------------------------------------------------------------------------------------
void GraphM::display(int From, int To) const {
    string space = "         ";  // generic space string
    if(T[From][To].dist != INT_MAX) {  // if the helper matrix does not equal infinity
        cout << space << From << space << To << space;  // print From and To with spaces
        cout << T[From][To].dist << "        ";  // cout the weight of the path
        getPath(From, To);  // call getPath to get the numerical values of the path
        getPathData(From, To); // call getPathdData to get the description of the locations
    } else {  // If the path weight equals infinity...
        cout << left << space << From <<  space << To;  // print the From and To values
        cout << space << "---- No path" << endl;  // then cout the result of no path
    }
    cout << endl;  // end with printing out an end line
}

// ------------------------------------getPath--------------------------------------------------------
// Description:  This helper function gets the path int data.
// ---------------------------------------------------------------------------------------------------
void GraphM::getPath(int From, int To) const {
    if (From != To) { // if From does not equal To value
        if (T[From][To].path != 0) { // if the helper matrix of From/To's path does not equal 0...
            getPath(From, T[From][To].path);  // call getPath again to find the last node
        }
    }
    cout << To << " "; // couts the path with spaces imbetween to the console
}

// ------------------------------------getPathData----------------------------------------------------
// Description:   Helper function that gets the path data of the nodes.
// ---------------------------------------------------------------------------------------------------
void GraphM::getPathData(int From, int To) const {
    if (From != To) {  // if From does not equal To value
        if (T[From][To].path != 0) {  // if the helper matrix of From/To's path does not equal 0...
            getPathData(From, T[From][To].path);   // call getPathData again to find the last node
        }
    }
    cout << endl <<data[To] << endl; // cout the string data of the locations out to console
}
