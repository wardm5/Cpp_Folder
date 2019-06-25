#include "nodedata.h"
using namespace std;
class BinTree {                // you add class/method comments and assumptions
    //...
    friend ostream & operator<<(ostream &, const BinTree &);
    
public:
    BinTree();                                // constructor
    BinTree(const BinTree &);                // copy constructor
    ~BinTree();                                // destructor, calls makeEmpty
    bool isEmpty() const;                    // true if tree is empty, otherwise false
    void makeEmpty();                        // make the tree empty so isEmpty returns true
    BinTree& operator=(const BinTree & current);
    bool operator==( const BinTree & current) const;
    bool operator!=(const BinTree &) const;
    bool insert(NodeData* newData) ;
    bool retrieve(const NodeData & input, NodeData* & output);
    void displaySideways() const;            // provided below, displays the tree sideways
    int getHeight(const NodeData & data) const;
    void bstreeToArray(NodeData* arr[]);
    void arrayToBSTree(NodeData* arr[]);
    
    //...
private:
    struct Node {
        NodeData* data;                        // pointer to data object
        Node* left;                            // left subtree pointer
        Node* right;                        // right subtree pointer
    };
    Node* root;                                // root of the tree
    // utility functions
    void inorderHelper(Node* root) const;
    void makeEmptyHelper(Node* current);
    void sideways(Node* current, int level) const;            // provided below, helper for displaySideways()
    bool insert(NodeData* newData, Node* & current);
    int getHeight(const NodeData & data, Node* root, int updateLevel) const;
    void bstreeToArrayHelper(NodeData* arr[] , Node* current, int & tracker);
    Node* arraytoBSTree(NodeData* arr[], int start, int end);
    void copyTreeHelper(Node* & tree2, Node* & tree);
    bool operatorHelper(Node* current1, Node* current2) const;
    //...
};







