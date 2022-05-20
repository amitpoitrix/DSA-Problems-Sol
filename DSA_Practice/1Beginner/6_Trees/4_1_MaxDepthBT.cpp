#include<iostream>
#include<vector>
using namespace std;
// Striver Tree Series : L14. Maximum Depth in Binary Tree | Height of Binary Tree
// Application:
// 1. For Checking Balanced BT
// 2. Diameter of BT
// 3. Max path sum of BT(with some modification)

// TC - O(n)
// SC - O(n) ~ Auxilliary Stack Space 
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

int depth(Node * root){
    if(root == NULL)
        return 0;
    
    int leftHeight = depth(root->left);
    int rightHeight = depth(root->right);

    return 1 + max(leftHeight, rightHeight);
}

int main(){
    Node * root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->right->left = new Node(4);
    root->right->right = new Node(6);
    root->right->left->left = new Node(5);

    cout << "Max Height : " << depth(root);
    
    return 0;
}