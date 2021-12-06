#include<iostream>
using namespace std;
// striver Tree series : Leetcode 101. Symmetric Tree

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

bool isSymmetricHelp(Node * rootL, Node * rootR){
    // if rootL & rootR are leaf Nodes (NULL)
    if(rootL == NULL || rootR == NULL)
        return rootL == rootR;

    // checking if rootL data is equal to rootR data
    if(rootL->data != rootR->data)
        return false;
    
    // Simultaneously checking if both left & right subtree are actual there mirror image or not
    return isSymmetricHelp(rootL->left, rootR->right) && isSymmetricHelp(rootL->right, rootR->left);
}

bool isSymmetric(Node * root){
    return root == NULL || isSymmetricHelp(root->left, root->right);
}

int main(){
    Node * root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(2);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(5);
    root->right->right = new Node(4);

    if(isSymmetric(root))
        cout << "Its a Symmetric Binary Tree";
    else
        cout << "Its not a Symmetric Binary Tree";
    
    return 0;
}
