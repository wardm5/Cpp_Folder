#include "bintree.h"

using namespace std;
BinTree::BinTree() {  // tree constructor which sets root to NULL
    root = NULL;
}

BinTree::BinTree(const BinTree & tree) {  // tree constructor that takes in a tree and deep copies it.
    *this = tree;
}

BinTree::~BinTree() {}  // tree deconstructor

//------------------------- isEmpty ---------------------------------
// Displays a binary tree as though you are viewing it from the side;
// hard coded displaying to standard output.
// Preconditions: NONE
// Postconditions: BinTree remains unchanged.
bool BinTree::isEmpty() const {
    return root == NULL;
}

//------------------------- makeEmpty ---------------------------------
// Displays a binary tree as though you are viewing it from the side;
// hard coded displaying to standard output.
// Preconditions: NONE
// Postconditions: BinTree remains unchanged.
void BinTree::makeEmpty() {
    makeEmptyHelper(root);
    root = NULL;
}

void BinTree::makeEmptyHelper(Node * current) {
    if (current != NULL) {
        makeEmptyHelper(current->left);
        makeEmptyHelper(current->right);
        //delete current->data;
        //delete current;
    } else {
        return;
    }
}

//------------------------- retrieve ---------------------------------
// Displays a binary tree as though you are viewing it from the side;
// hard coded displaying to standard output.
// Preconditions: NONE
// Postconditions: BinTree remains unchanged.
bool BinTree::retrieve(const NodeData & input, NodeData* & output) {
    Node* temp = root;
    while((temp != NULL) && (*(temp->data) != input)) {
        if (input < *(temp->data)) {
            temp = temp->left;  // Search key comes before this node.
        } else{
            temp = temp->right; // Search key comes after this node
        }
    }
    if (temp == NULL) {
        return false;    // Search key not found
    } else {
        output = temp->data;
        return true;
    }
}

BinTree& BinTree::operator=(const BinTree & currTree)  {
    root = currTree.root;
    return *this;
}

bool BinTree::operator==(const BinTree & current) const {
    return operatorHelper(root, current.root);
}

bool BinTree::operatorHelper(Node* current1, Node* current2) const {
    if (current1 == NULL && current2 == NULL) {
        return true;
    } else if (*(current1->data) == *(current2->data)) {
        return operatorHelper(current1->left, current2->left) && operatorHelper(current1->right, current2->right);
    }
    return false;
}


bool BinTree::operator!=(const BinTree & current) const {
    return !operatorHelper(root, current.root);
}

//------------------------- bstreeToArray ---------------------------------
// Displays a binary tree as though you are viewing it from the side;
// hard coded displaying to standard output.
// Preconditions: NONE
// Postconditions: BinTree remains unchanged.
void BinTree::bstreeToArray(NodeData* arr[]) {
    int tracker = 0;
    bstreeToArrayHelper(arr , root, tracker);
    makeEmpty();
}

void BinTree::bstreeToArrayHelper(NodeData* arr[] , Node* current, int & tracker) {
    if (current != NULL) {
        bstreeToArrayHelper(arr, current->left, tracker);
        arr[tracker] = new NodeData;
        arr[tracker] = current->data;
        tracker += 1;
        bstreeToArrayHelper(arr, current->right, tracker);
    }
}

//------------------------- arrayToBSTree ---------------------------------
// Displays a binary tree as though you are viewing it from the side;
// hard coded displaying to standard output.
// Preconditions: NONE
// Postconditions: BinTree remains unchanged.
void BinTree::arrayToBSTree(NodeData* arr[]) {
    if (arr[0] == 0) {
        return;
    } else {
        int end = 0;
        while (arr[end] != 0) {
            end++;
        }
        root = arraytoBSTree(arr, 0, end - 1);
    }
    
}

/* A function that constructs Balanced Binary Search Tree from a sorted array */
BinTree::Node* BinTree::arraytoBSTree(NodeData* arr[], int start, int end) {
    if (start > end)
        return NULL;
    int mid = (start + end)/2;
    Node* current = new Node();
    current->data = arr[mid];
    current->left =  arraytoBSTree(arr, start, mid-1);
    current->right = arraytoBSTree(arr, mid+1, end);
    return current;
}

//------------------------- inorderHelper ---------------------------------
// Displays a binary tree as though you are viewing it from the side;
// hard coded displaying to standard output.
// Preconditions: NONE
// Postconditions: BinTree remains unchanged.
void BinTree::inorderHelper(Node* root) const {
    if (root == NULL)
        return;
    inorderHelper(root->left);
    cout << *(root->data) << " " ;
    inorderHelper(root->right);
}


//---------------------------- Insert -------------------------------------
// Insert and helper method for insert.
// Preconditions: NONE
// Postconditions:  Adds node to tree.
bool BinTree::insert(NodeData* newData) {
    if (root == NULL) {
        Node* temp = new Node();
        temp->data = newData;
        temp->left = NULL;
        temp->right = NULL;
        root = temp;
        return true;
    }
    return insert(newData, root);
}

bool BinTree::insert(NodeData* newData, Node* & current) {
    if (current == NULL) {
        current = new Node();
        current->data = newData;
        current->left = NULL;
        current->right = NULL;
        return true;
    } else if (*(current->data) == *(newData)) {
        return false;
    }else if (*(current->data) > *(newData)) {
        return insert(newData, current->left);
    }
    else {
        return insert(newData, current->right);
    }
}

//------------------------- getHeight ---------------------------------
// Provides the height of a given nodedata
// hard coded displaying to standard output.
// Preconditions: NONE
// Postconditions: BinTree remains unchanged.
int BinTree::getHeight(const NodeData & data) const {  // getHeight call method, uses helper
                                                        // to get the actual height
    return getHeight(data, root, 0);
}

int BinTree::getHeight(const NodeData & data, Node* current, int updateLevel) const {
    int heightLeft = 0;  // set left height to 0
    int heightRight = 0;  // set right height to 0
    if (current == NULL) {  // if current node is null
        return updateLevel;  // return update update level
    }
    else if ((*(current->data) == data)) {  // if the data matches the node's data...
        updateLevel++;  // update the level and then search through entire tree
        heightLeft = getHeight(data, current->left, updateLevel);
        heightRight = getHeight(data, current->right, updateLevel);
        if (heightRight > heightLeft) {  // if the right height is greater than left's
            return heightRight; // return the aggregated sum of those steps
        }
        return heightLeft;  // else return the aggrated sum of the left
    }
    else {
        if (updateLevel == 0) {  // if node with data has not been found.
            heightRight = getHeight(data, current->right, updateLevel); // continue searching right side of tree
            heightLeft = getHeight(data, current->left, updateLevel);  /// continue searching right side of tree
        }
        else {
            updateLevel++; // if node has been found, add to update level...
            heightRight = getHeight(data, current->right, updateLevel); // continue down right side of tree
            heightLeft = getHeight(data, current->left, updateLevel); // continue down right side of tree
        }
        if (heightRight > heightLeft) {  // if right height is greater than left, then return right
            return heightRight;
        }
        return heightLeft;  // else return left height.
    }
}

//------------------------- displaySideways ---------------------------------
// Displays a binary tree as though you are viewing it from the side;
// hard coded displaying to standard output.
// Preconditions: NONE
// Postconditions: BinTree remains unchanged.
void BinTree::displaySideways() const {
    sideways(root, 0);
}

//---------------------------- Sideways -------------------------------------
// Helper method for displaySideways
// Preconditions: NONE
// Postconditions: BinTree remains unchanged.
void BinTree::sideways(Node* current, int level) const {
    if (current != NULL) {
        level++;
        sideways(current->right, level);
        
        // indent for readability, 4 spaces per depth level
        for (int i = level; i >= 0; i--) {
            cout << "    ";
        }
        
        cout << *current->data << endl;        // display information of object
        sideways(current->left, level);
    }
}

//-------------------------- operator<< --------------------------------------
ostream& operator<<(ostream& output, const BinTree& t) {
    t.inorderHelper(t.root);
    cout << endl;
    return output;
}


