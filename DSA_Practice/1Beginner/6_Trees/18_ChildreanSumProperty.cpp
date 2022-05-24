#include<iostream>
using namespace std;
// striver Tree Series : L29. Children Sum Property in Binary Tree | O(N) Approach
// Children Sum Property of BT : Means the sum of children Nodes data should be equal to root Node
// Condition : We can increase the size of any node by +1 any no. of times
// Goodnotes

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

void childrenSumBT(Node * root){
    // Base Case
    if(root == NULL)
        return;
    
    // Top to bottom
    int child = 0;
    if(root->left)
        child += root->left->data;
    if(root->right)
        child += root->right->data;
    
    // here we're checking the child sum whether its equal to or greater than root node or not
    if(child >= root->data)
        root->data = child;

    // If child Sum is smaller than assign the root node value to both its child (i.e., left & right)
    else{   
        if(root->left)
            root->left->data = root->data;
        if(root->right)
            root->right->data = root->data;
    }

    // Traversal
    childrenSumBT(root->left);
    childrenSumBT(root->right);

    // Bottom to Top - Backtracking
    int total = 0;
    if(root->left)
        total += root->left->data;
    if(root->right)
        total += root->right->data;
    // Either left or right exist just assign the total value to root node of particular subtree/ tree
    if(root->left || root->right)
        root->data = total;

    return;
}

// InOrder Display of Binary Tree
void displayBT(Node * root){
    if(root == NULL)
        return;
    
    displayBT(root->left);
    cout << root->data << " ";
    displayBT(root->right);
}

int main(){
    Node * root = new Node(2);
    root->left = new Node(35);
    root->right = new Node(10);
    root->left->left = new Node(2);
    root->left->right = new Node(3);
    root->right->left = new Node(5);
    root->right->right = new Node(2);

    displayBT(root);
    cout << endl;
    childrenSumBT(root);
    displayBT(root);

    return 0;
}
