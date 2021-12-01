#include<iostream>
using namespace std;
// Striver Tree Series : Maximum Path Sum of Binary Tree (Leetcode 124. Binary Tree Maximum Path Sum)

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

int maxPath(Node * root, int &maxi){
    if(root == NULL)
        return 0;

    // If we encounter -ve node value than we'll ignore it and replace the return value with 0
    int leftSum = max(0, maxPath(root->left, maxi));    // here leftSum is the max path sum on left side
    int rightSum = max(0, maxPath(root->right, maxi));  // here rightSum is the max path sum on right side

    // Calculating max path value at node which is assume as root node of reverse U path
    maxi = max(maxi, root->data + leftSum + rightSum);

    // here we're returning max path on either side(whether its left or right)
    return root->data + max(leftSum, rightSum);
}

int maxPathSum(Node * root){
    int maxi = INT32_MIN;
    int maxpath = maxPath(root, maxi);
    return maxi;
}

int main(){
    Node* root = new Node(-10);
    root->left = new Node(9);
    root->right = new Node(20);
    root->right->left = new Node(15);
    root->right->right = new Node(7);

    cout << "Maximum Sum Path : " << maxPathSum(root);

    cout << endl;
    return 0;
}