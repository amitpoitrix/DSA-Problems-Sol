#include<bits/stdc++.h>
using namespace std;
// Striver Tree series : Leetcode 105. Construct Binary Tree from Preorder and Inorder Traversal
// From InOrder & Pre/PostOrder Traversal we can create unique BT but from PreOrder & PostOrder we can't create unique BT 

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

Node * buildBT(vector<int> &inorder, int inStart, int inEnd, vector<int> &preorder, int preStart, int preEnd, map<int, int> &inMap){
    if(inStart > inEnd || preStart > preEnd)
        return NULL;

    // Starting from PreOrder Traversal Node i.e., Root Node of actual BT
    Node * root = new Node(preorder[preStart]);
    int inRoot = inMap[root->data]; // Getting the pos(index) of root node in InOrder Traversal 
    int numsLeft = inRoot - inStart;

    root->left = buildBT(inorder, inStart, inRoot-1, preorder, preStart+1, preStart + numsLeft, inMap);
    root->right = buildBT(inorder, inRoot+1, inEnd, preorder, preStart+numsLeft+1, preEnd, inMap);

    return root;
} 

Node * buildTree(vector<int> &inorder, vector<int> &preorder){
    map<int, int> inMap;
    // Creating inorder Hash Map 
    for (int i = 0; i < inorder.size(); i++){
        inMap[inorder[i]] = i;
    }

    Node * root = buildBT(inorder, 0, inorder.size()-1, preorder, 0, preorder.size()-1, inMap);

    return root;
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
    vector<int> inorder = {9,3,15,20,7};
    vector<int> preorder = {3,9,20,15,7};

    Node * root = buildTree(inorder, preorder);
    displayBT(root);

    cout << endl;
    return 0;
}