#include<iostream>
using namespace std;
// Striver Tree Series : L49. Inorder Successor/Predecessor in BST
// If we want to find successor of last element of inorder BST than return NULL
// TC - O(H) - H - Height of Tree - O(logN) (base 2)
// SC - O(1) - becoz we are moving left & right and we are not taking any external extra space

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

// Logic to get successor of a node in Inorder BST
Node * inorderSuccessorBST(Node * root, Node * p){
    Node * successor = NULL;

    while (root != NULL){
        // For Successor first we'll cross val to the right(becoz we want just next largest value) and than go left
        if(p->data >= root->data)
            root = root->right;
        else{
            successor = root;
            root = root->left;
        }
    }

    return successor;
}

// Logic to get predecessor of a node in Inorder BST
Node * inorderPredecessorBST(Node * root, Node * p){
    Node * predecessor = NULL;

    while (root != NULL){
        // For Predecessor first we'll cross val to the left(becoz we want just next smallest value) and than go right
        if(p->data <= root->data)
            root = root->left;
        else{
            predecessor = root;
            root = root->right;
        }
    }

    return predecessor;
}


int main(){
    Node * root = new Node(5);
    root->left = new Node(2);
    root->right = new Node(7);
    root->left->left = new Node(1);
    root->left->right = new Node(4);
    root->right->left = new Node(6);
    root->right->right = new Node(9);
    root->left->right->left = new Node(3);
    root->right->right->left = new Node(8);
    root->right->right->right = new Node(10);

    Node * p = new Node(8);
    Node * successor = inorderSuccessorBST(root, p);
    Node * predecessor = inorderPredecessorBST(root, p);

    cout << "Successor of " << p->data << " is " << successor->data << endl;
    cout << "Predecessor of " << p->data << " is " << predecessor->data << endl;

    return 0;
}