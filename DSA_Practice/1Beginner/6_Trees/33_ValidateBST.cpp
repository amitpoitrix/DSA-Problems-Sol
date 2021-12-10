#include<iostream>
using namespace std;
// Striver Tree Series : Leetcode 98. Validate Binary Search Tree
// Check whether a given BT is BST or not

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

// Approach 1 
bool validateBST(Node * root, Node * minValue, Node * maxValue){
    if(root == NULL)
        return true;
    
    if(minValue && minValue->data >= root->data || maxValue && root->data >= maxValue->data)
        return false;
    
    return validateBST(root->left, minValue, root) && validateBST(root->right, root, maxValue);
}

bool isValidBST(Node * root){
    return validateBST(root, NULL, NULL);
}


// Approach 2 : Using the concept of Inorder Traversal of BST which is in sorted(Ascending) order
bool validateBST2(Node * root, Node * &prev){
    if(root == NULL)
        return true;
    // Acc. to InOrder Traversal - Left Root Right
    // First we'll check Left
    if(!validateBST2(root->left, prev))
        return false;
    
    // Than we'll print Root
    if(prev != NULL && prev->data >= root->data)
        return false;
    
    prev = root;

    // Then we'll check right
    return validateBST2(root->right, prev);
}

bool isValidBST2(Node * root){
    Node * prev = NULL;
    return validateBST2(root, prev);
}

int main(){
    Node * root = new Node(5);
    root->left = new Node(1);
    root->right = new Node(7);
    root->right->left = new Node(6);
    root->right->right = new Node(8);

    if(isValidBST2(root))
        cout << "Yes its a valid BST" << endl;
    else
        cout << "No its not a valid BST" << endl;

    return 0;
}