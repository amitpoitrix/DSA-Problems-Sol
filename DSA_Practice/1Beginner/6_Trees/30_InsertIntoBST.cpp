#include<iostream>
using namespace std;
// Striver Tree Series : Leetcode 701. Insert into a Binary Search Tree

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

Node * insertIntoBST(Node * root, int val){
    if(root == NULL){
        // if root is NULL create new node with val & return
        return new Node(val);
    }
    
    Node * cur = root;  // We'll take a copy of node

    while (true){
        // move right if val is greater than equal to current node data
        if(val >= cur->data){
            // If its not NULL than move right
            if(cur->right)
                cur = cur->right;
            else{
                // If its NULL than create new node with val & break
                cur->right = new Node(val);
                break;
            }
        }
        // move left if val is smaller thancurrent node data
        else{
            // If its not NULL than move left
            if(cur->left)
                cur = cur->left;
            else{
                // If its NULL than create new node with val & break
                cur->left = new Node(val);
                break;
            }
        }
    }
    
    return root;
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
    Node * root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(7);
    root->left->left = new Node(1);
    root->left->right = new Node(3);
    displayBST(root);
    cout << endl;

    int val = 5;
    Node * result = insertIntoBST(root, val);
    displayBST(result);

    return 0;
}