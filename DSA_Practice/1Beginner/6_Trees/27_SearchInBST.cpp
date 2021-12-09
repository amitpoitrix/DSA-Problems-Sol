#include<iostream>
using namespace std;
// Striver Tree Series : Leetcode 700. Search in a Binary Search Tree

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

Node * searchInBST(Node * root, int val){
    if(root == NULL)
        return root;
    
    // We'll move from root node till we found desired node or NULL 
    while (root != NULL && root->data != val){
        root = val < root->data? root->left : root->right;
    }
    
    return root;
}

void displayBST(Node * root){
    if(root == NULL)
        return;

    cout << root->data << " ";
    displayBST(root->left);
    displayBST(root->right);
}

int main(){
    Node * root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(7);
    root->left->left = new Node(1);
    root->left->right = new Node(3);
    displayBST(root);
    cout << endl;

    int val = 2;
    Node * result = searchInBST(root, val);
    displayBST(result);

    return 0;
}