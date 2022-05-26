#include<bits/stdc++.h>
using namespace std;
// Striver Tree series : Leetcode 105. Construct Binary Tree from Preorder and Inorder Traversal
// https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
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

class Solution{
private:
    Node * buildBT(vector<int> &inorder, int inStart, int inEnd, vector<int> &preorder, int preStart, int preEnd, map<int, int> &inMap){
        if(inStart > inEnd || preStart > preEnd)
            return NULL;

        // Starting from PreOrder Traversal Node i.e., Root Node of actual BT
        Node * root = new Node(preorder[preStart]);
        int inRoot = inMap[root->data]; // Getting the pos(index) of root node in InOrder array 
        int numsLeft = inRoot - inStart; // No. of elements left on the left side of root node idx in inorder array

        root->left = buildBT(inorder, inStart, inRoot-1, preorder, preStart+1, preStart + numsLeft, inMap);
        root->right = buildBT(inorder, inRoot+1, inEnd, preorder, preStart+numsLeft+1, preEnd, inMap);

        return root;
    } 

public:
    Node * buildTree(vector<int> &inorder, vector<int> &preorder){
        if(inorder.size() != preorder.size())
            return NULL;

        map<int, int> inMap;
        // Creating inorder Hash Map in order to determine root node idx inside inorder array
        for (int i = 0; i < inorder.size(); i++){
            inMap[inorder[i]] = i;
        }

        Node * root = buildBT(inorder, 0, inorder.size()-1, preorder, 0, preorder.size()-1, inMap);

        return root;
    }
};

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

    Solution obj;
    Node * root = obj.buildTree(inorder, preorder);
    displayBT(root);

    cout << endl;
    return 0;
}