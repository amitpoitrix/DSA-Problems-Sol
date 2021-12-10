#include<iostream>
using namespace std;
// Striver Tree Series : Leetcode 235. Lowest Common Ancestor of a Binary Search Tree

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

Node * lowestCommonAncestor(Node * root, Node * p, Node * q){
    if(root == NULL)
        return root;
    
    // If both p & q nodes lie on left of the subtree
    if(p->data < root->data && q->data < root->data)
        return lowestCommonAncestor(root->left, p, q);
    
    // If both p & q nodes lie on left of the subtree
    if(p->data > root->data && q->data > root->data)
        return lowestCommonAncestor(root->right, p, q);

    return root;
}

int main(){
    Node * root = new Node(6);
    root->left = new Node(2);
    root->right = new Node(8);
    root->left->left = new Node(0);
    root->left->right = new Node(4);
    root->right->left = new Node(7);
    root->right->right = new Node(9);
    root->left->right->left = new Node(3);
    root->left->right->right = new Node(5);

    Node * p = new Node(2);
    Node * q = new Node(4);
    Node * lca = lowestCommonAncestor(root, p, q);

    cout << "Lowest Common Ancestor of " << p->data << " & " << q->data << " is " << lca->data;

    return 0;
}