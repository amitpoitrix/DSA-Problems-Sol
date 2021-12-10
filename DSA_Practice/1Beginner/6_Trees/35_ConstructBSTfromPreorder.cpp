#include<iostream>
#include<vector>
using namespace std;
// Striver Tree Series : Leetcode 1008. Construct Binary Search Tree from Preorder Traversal

struct Node{
    int data;
    Node * left;
    Node * right;

    Node(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

// Here we have to modify vector & i so we pass it by reference
Node * build(vector<int> &preorder, int &i, int bound){
    // Edge Case
    if(i == preorder.size() || preorder[i] > bound)
        return NULL;
    
    // Creating new node for each element of preorder vector
    Node * root = new Node(preorder[i]);
    i++;
    root->left = build(preorder, i, root->data);    // For left child we'll pass the maxBound as current node value
    root->right = build(preorder, i, bound);    // For right child we'll pass the maxBound as bound(INT_MAX) 

    return root;
}

Node * bstFromPreorder(vector<int> &preorder){
    int i = 0;  // Here i act as global variable
    return build(preorder, i, INT8_MAX);
}

// Display BST
void displayBST(Node * root){
    if(root == NULL)
        return;

    cout << root->data << " ";
    displayBST(root->left);
    displayBST(root->right);
}

int main(){
    vector<int> preorder = {8,5,1,7,10,12};

    Node * result = bstFromPreorder(preorder);

    displayBST(result);

    return 0;
}