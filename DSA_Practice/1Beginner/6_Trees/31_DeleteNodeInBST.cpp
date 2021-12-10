#include<iostream>
using namespace std;
// Striver Tree Series : 450. Delete Node in a BST
// TC - O(LogN), SC - O(1)
// There are Two Ways to delete a node in BST
// 1. Join currentNode->left to deleteNode->left & Join deleteNode->right to deleteNode->left largest node value
// 2. Join currentNode->left to deleteNode->right & Join deleteNode->left to deleteNode->right smallest node value  

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

// Function to go extreme right of subtree and return the last right side node of tree
Node * lastRightNode(Node * root){
    if(root->right == NULL)
        return root;

    return lastRightNode(root->right);
}

// Function to delete the node to be deleted and maintain the BST property
Node * helper(Node * root){
    // Edge Case - if either leftChild or rightChild exist
    if(root->left == NULL)
        return root->right;
    else if(root->right == NULL)
        return root->left;
    
    Node * rightNode = root->right;
    Node * lastLeftChildNode = lastRightNode(root->left);
    lastLeftChildNode->right = rightNode;
    return root->left;
}

// Function to delete a Node in BST
Node * deleteNode(Node * root, int key){
    if(root == NULL)
        return root;
    
    if(root->data == key)
        return helper(root);
    
    Node * dummy = root;    // we'll take copy of root as this will modified

    while (root != NULL){
        if(key < root->data){
            // Check on Left Subtree
            if(root->left != NULL && root->left->data == key){
                root->left = helper(root->left);
                break;
            }
            else
                root = root->left;
        }
        else{
            // Check on Right Subtree
            if(root->right != NULL && root->right->data == key){
                root->right = helper(root->right);
                break;
            }
            else
                root = root->right;
        }
    }
    
    return dummy;
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
    Node * root = new Node(5);
    root->left = new Node(3);
    root->right = new Node(6);
    root->left->left = new Node(2);
    root->left->right = new Node(4);
    root->right->right = new Node(7);
    displayBST(root);
    cout << endl;

    int val = 3;
    Node * result = deleteNode(root, val);
    displayBST(result);

    return 0;
}