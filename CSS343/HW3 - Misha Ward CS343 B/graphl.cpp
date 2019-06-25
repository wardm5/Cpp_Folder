// ------------------------------------------------ graphl.cpp --------------------------------------------------------
// Misha Ward CS343 Section B
// Febuary 12, 2018
// Febuary 17, 2018
// --------------------------------------------------------------------------------------------------------------------
// This program is designed to create a graph as a data structure using adjacency lists.
// --------------------------------------------------------------------------------------------------------------------
// Notes on specifications, special algorithms, and assumptions.
//  - buildGraph(ifstream& infile) - function is used to build the graph using adj. lists
//  - ~GraphL() - deconstructor, automatically called to remove data
//  - depthFirstSearch() - uses DFS algorithm to search through nodes for the shortest path
//  - displayGraph() - this function displays the results of the graph to the user
//  --- Assumptions - Inputs from the file are correct.
// --------------------------------------------------------------------------------------------------------------------

#include "graphl.h"

// ------------------------------------GraphL Constructor---------------------------------------------
// Description:  This constructor creates a graph data structure with the default array size of 0
// ---------------------------------------------------------------------------------------------------
GraphL::GraphL() {
    sizeOfArray = 0;  // set size of array to 0 as default
}

// ------------------------------------GraphL Deconstructor-------------------------------------------
// Description:  This deconstructor goes through the array and deletes the data, and array and sets
//               values back to NULL to ensure no data leaks.
// ---------------------------------------------------------------------------------------------------
GraphL::~GraphL() {
    if (sizeOfArray > 0) {  // if the array size is greater than 0..
        for(int i = 0; i <= sizeOfArray;i++) {  // loop through the array
            while (adjList[i].edgeHead != NULL) {  // while the head node does not equal NUll
                removeNode(i);  // remove the node
            }
            delete adjList[i].data;  //  delete the adj. list data
            adjList[i].data = NULL;  // set the data value to NULL
        }
        sizeOfArray = 0;  // set size of the array to 0
        delete [] adjList;  // delete the adj. list array
        adjList = NULL;  // set the adj. list array to NULL
    }
}

// ------------------------------------removeNode-----------------------------------------------------
// Description:  This function removes the node and is a helper function for the deconstructor.
// ---------------------------------------------------------------------------------------------------
void GraphL::removeNode(int Value) {
    EdgeNode *cur; // create an EdgeNode current pointer
    cur = adjList[Value].edgeHead;  // set the current edge node to the value's edge node
    adjList[Value].edgeHead = adjList[Value].edgeHead->nextEdge;  //  set the current edge head
                                                                // to the next edge head value
    cur->nextEdge = NULL;  // set the current edge node's next edge to NULL
    delete cur;  // delete current
    cur = NULL;  // set current to NULL to avoid data leaks
}

// ------------------------------------buildGraph-----------------------------------------------------
// Description:  Build graph is responsilbe for reading the file and creating the nodes and data for
//               the graph.
// ---------------------------------------------------------------------------------------------------
void GraphL::buildGraph(ifstream& infile) {
    int a = 0;  // intialize int variable to 0
    infile >> a;  // input amount of strings to loop through...
    sizeOfArray = a;     // node size equals to a

    //infile.get();
    if (sizeOfArray > 0) {  // if the size of array is greater than 0
        adjList = new GraphNode[sizeOfArray + 1];  // create an new adj. list
        for (int i = 0; i <= sizeOfArray; i ++) {  // loop through the array
            adjList[i].data = new NodeData;  // create a new node
            adjList[i].data->setData(infile);  //  set the data to the input file
            adjList[i].visited = false;  //  set node to false
            adjList[i].edgeHead = NULL;  //  set edgehead to NULL
        }
        int From = -1, To = -1;  // create ints to keep track of From, To
        while (From != 0 && To !=0) {  // while From and To are not equal to 0
            infile >> a;  // next int input equals a
            From = a;     // From equals a
            infile >> a;  // next int input equals a
            To = a;       // To equals a
            if (From == 0 && To == 0) {
                break;  // break from loop if From and To equals 0
            }
            insert(From, To); // Insert into linked list
        }
    }
}

// ------------------------------------insert---------------------------------------------------------
// Description:  This method resets the visited data to false in the helper array
// ---------------------------------------------------------------------------------------------------
void GraphL::insert(int From, int To) {
    EdgeNode *temp = new EdgeNode; // create a new temp edge node
    temp->adjGraphNode = To; // set the temp's adj node to To
    if (adjList[From].edgeHead == NULL) { // if the node of From is equal to NULL
        temp->nextEdge = NULL; //  set temp's next edge to NULL
        adjList[From].edgeHead = temp;  // set the node in the array to temp node
    } else {  // else if not empty...
        temp->nextEdge = adjList[From].edgeHead;  // temp's next edge equals the node's edge head
        adjList[From].edgeHead = temp; // set the node's edge head to temp
    }
}

// ------------------------------------depthFirstSearch-----------------------------------------------------
// Description:  this function initiates the DFS to print out nodes in order
// ---------------------------------------------------------------------------------------------------
void GraphL::depthFirstSearch() {
    resetVisited(); //  ensure all vertexs are set to false
    cout << "Depth-first ordering: ";
    for(int v = 1; v < sizeOfArray; v++) { //  loop through the entire array of vertexes
        if(adjList[v].visited == false) { //  if the vertex was not visited...
            dfs(v); //  call the DFS helper function
        }
    }
    cout << endl;
}

// ------------------------------------dfs helper-----------------------------------------------------
// Description:  This method resets the visited data to false in the helper array
// ---------------------------------------------------------------------------------------------------
void GraphL::dfs(int v) {
    adjList[v].visited = true; // set v in adj. list to true
    cout << v << " ";  // cout value
    for(EdgeNode *tempEdge = adjList[v].edgeHead; tempEdge != NULL;  // loop through temp edges
                                                        // while temp edges are not NULL
        tempEdge = tempEdge->nextEdge) { // set the temp edge to temp edge's next edge...
        if (adjList[tempEdge->adjGraphNode].visited == false) {  // if temp edge's adj. node
                                                         // is not visited, then...
            dfs(tempEdge->adjGraphNode); //call dfs on temp edge's adjacent node
        }
    }
}

// ------------------------------------resetVisited--------------------------------------------------
// Description:  This method resets the visited data to false in the helper array
// ---------------------------------------------------------------------------------------------------
void GraphL::resetVisited() {
    for (int i = 1; i < sizeOfArray; i++) {  // loop through the array
        adjList[i].visited = false;  // set visited values to false
    }
}

// ------------------------------------displayGraph---------------------------------------------------
// Description:  This method is used to display the graph to the user.
// ---------------------------------------------------------------------------------------------------
void GraphL::displayGraph() {
    string space = "               ";  // generic space string
    cout << "Graph:" << endl;
    for(int i = 1; i < sizeOfArray + 1; i++) {  // loop through the array
        cout << "Node" << i;
        cout << space << *adjList[i].data << endl << endl; // print out description of location
        if (adjList[i].edgeHead != NULL) {  // if the item's edge's head equals NULL...
            EdgeNode *temp; //  create a temp EdgeNode pointer
            temp = adjList[i].edgeHead; // set temp to the adj. list's EdgeHead
            while (temp != NULL) {  // if temp does not equal NULL
                cout << "  edge  " << i << "  " << temp->adjGraphNode << endl;  // print out
                                                                    // the value  and the adj. node
                temp = temp->nextEdge; //  set temp to the the adj. node
            }
        }
    }
    cout << endl;
}




