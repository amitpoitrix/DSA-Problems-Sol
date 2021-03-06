#include<iostream>
#include<vector>
using namespace std;
// Striver Tree Series : Boundary Traversal of Binary Tree (Anti-Clockwise)

// Algo: Anti-Clockwise 
// 1. Left Boundary excluding leaf
// Take result vector ds and push root node into it if its not a leaf than traverse on left side of nodes(i.e., start from 
// root->left) & push it into ds.
// If there doesn't exist left than check on right till it reaches leaf node

// 2. Leaf nodes
// Do inorder traversal on leaf nodes & push it into ds.

// 3. Right Boundary excluding leaf
// For reverse order we'll use another ds(vector) and start traversing from root->right. If there doesn't exist a right than 
// go to left till it reaches leaf nodes.
// Now take top element from ds and push it into result ds.

// NOTE : This Code is working fine in Online Compiler. Not giving output here in VS Code

struct Node{
    int data;
    Node * left;
    Node * right;

    Node(int data){
        this->data = data;
        this->left = left;
        this->right = right;
    }
};

// Check if given node is a leaf node or not
bool isLeaf(Node * root){
    return !root->left && !root->right;
}

// Adding Left Boundary
void addLeftBoundary(Node * root, vector<int> &result){
    // Starting from left node
    Node * curr = root->left;

    while (curr){
        if(!isLeaf(curr))
            result.push_back(curr->data);

        // For Left Boundary Traversal First we'll check if left node exist if not than we'll consider right
        if(curr->left)
            curr = curr->left;
        else
            curr = curr->right;
    }
}

// Adding Right Boundary
void addRightBoundary(Node * root, vector<int> &result){
    // starting from right node
    Node * curr = root->right;
    vector<int> temp;   // to store right BT nodes which will be further used to push element into res vec in reverse order

    while (curr){
        if(!isLeaf(curr))
            temp.push_back(curr->data);
        
        // For Right Boundary Traversal First we'll check if right node exist if not than we'll consider left
        if(curr->right)
            curr = curr->right;
        else
            curr = curr->left;
    }

    // Adding the node data of right most BT nodes back to result vector in reverse order
    for (int i = temp.size()-1; i >= 0; --i){
        result.push_back(temp[i]);
    }
}

// Add Leaf Nodes
void addLeaves(Node * root, vector<int> &result){
    if(isLeaf(root)){
        result.push_back(root->data);
        return;
    }

    // Checking if Left & than right node exist or not if yes than check if its a leaf node or not if yes than add it to 
    // result vector
    if(root->left)
        addLeaves(root->left, result);
    
    if(root->right)
        addLeaves(root->right, result);
}

vector<int> boundaryTraversal(Node * root){
    vector<int> result;
    if(root == NULL)
        return result;
    
    if(!isLeaf(root))
        result.push_back(root->data);

    // For Anti-clockwise Boundary Traversal 
    // 1. Add Left Boundary
    addLeftBoundary(root, result);
    // 2. Add Leaf Nodes
    addLeaves(root, result);
    // 3. Add Right Boundary
    addRightBoundary(root, result);

    return result;
}

int main(){
    Node * root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(7);
    root->left->left = new Node(3);
    root->right->right = new Node(8);
    root->left->left->right = new Node(4);
    root->right->right->left = new Node(9);
    root->left->left->right->left = new Node(5);
    root->left->left->right->right = new Node(6);
    root->right->right->left->left = new Node(10);
    root->right->right->left->right = new Node(11);

    vector<int> res = boundaryTraversal(root);

    for (auto x : res){
        cout << x << " ";
    }
    
    return 0;
}