#include<bits/stdc++.h>
using namespace std;
// Striver Tree series : 106. Construct Binary Tree from Inorder and Postorder Traversal
// From InOrder & Pre/PostOrder Traversal we can create unique BT but from PreOrder & PostOrder we can't create unique BT 
// TC - O(N) or O(NlogN) as LogN due to Hash map & SC - O(N)

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

Node * buildBTUsingInPost(vector<int> &inorder, int inStart, int inEnd, vector<int> &postorder, int postStart, int postEnd, map<int, int> &inMap){
    if(inStart > inEnd || postStart > postEnd)
        return NULL;

    // Starting from postorder Traversal Node i.e., Root Node of actual BT
    Node * root = new Node(postorder[postEnd]);
    int inRoot = inMap[root->data]; // Getting the pos(index) of root node in InOrder Traversal 
    int numsLeft = inRoot - inStart;

    root->left = buildBTUsingInPost(inorder, inStart, inRoot-1, postorder, postStart, postStart + numsLeft - 1, inMap);
    root->right = buildBTUsingInPost(inorder, inRoot+1, inEnd, postorder, postStart+numsLeft, postEnd - 1, inMap);

    return root;
} 

Node * buildTree(vector<int> &inorder, vector<int> &postorder){
    if(inorder.size() != postorder.size())
        return NULL;

    map<int, int> inMap;
    // Creating inorder Hash Map 
    for (int i = 0; i < inorder.size(); i++){
        inMap[inorder[i]] = i;
    }

    Node * root = buildBTUsingInPost(inorder, 0, inorder.size()-1, postorder, 0, postorder.size()-1, inMap);

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
    vector<int> postorder = {9,15,7,20,3};

    Node * root = buildTree(inorder, postorder);
    displayBT(root);

    cout << endl;
    return 0;
}