#include<iostream>
using namespace std;
// striver Tree Series : Leetcode 236. Lowest Common Ancestor of a Binary Tree

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
    if(root == NULL || root == p || root == q)
        return root;

    Node * leftRoot = lowestCommonAncestor(root->left, p, q);
    Node * rightRoot = lowestCommonAncestor(root->right, p, q);

    if(leftRoot == NULL)
        return rightRoot;
    else if(rightRoot == NULL)
        return leftRoot;
    else    // here when both are not null that means we got the node
        return root;
}

int main(){
    Node * root = new Node(3);
    root->left = new Node(5);
    root->right = new Node(1);
    root->left->left = new Node(6);
    root->left->right = new Node(2);
    root->right->left = new Node(0);
    root->right->right = new Node(8);
    root->left->right->left = new Node(7);
    root->left->right->right = new Node(4);

    Node * p = root->left;
    Node * q = root->left->right->right;

    Node * result = lowestCommonAncestor(root, p, q);

    cout << "Lowest Common Ancestor : " << result->data;

    return 0;
}
