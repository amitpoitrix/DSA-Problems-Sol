#include<bits/stdc++.h>
using namespace std;
// Striver Tree series : Leetcode 222. Count Complete Tree Nodes
// We've to count no. of nodes in Complete Binary Tree in less than O(n) time complexity

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

// Calculating height from Left side of BT
int calLeftHeight(Node * root){
    int hgt = 0;

    while (root != NULL){
        hgt++;
        root = root->left;
    }
    
    return hgt;
}

// Calculating height from right side of BT
int calRightHeight(Node * root){
    int hgt = 0;
    
    while (root != NULL){
        hgt++;
        root = root->right;
    }
    
    return hgt;
}

int countNodes(Node * root){
    if(root == NULL)
        return 0;

    // Here while calculating the left and right side height of BT we'll pass root node instead of root->left/right
    // And we'll Calculate height of BT with some modification 
    int leftheight = calLeftHeight(root);
    int rightHeight = calRightHeight(root);

    if(leftheight == rightHeight)
        return (1 << leftheight) - 1;     // 2^height - 1 => No. of nodes
    else{
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
}

int main(){
    Node * root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);

    cout << "No. of Nodes of given Binary Tree : " << countNodes(root);
    
    return 0;
}