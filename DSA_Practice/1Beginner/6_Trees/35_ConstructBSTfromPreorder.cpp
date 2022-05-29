#include<iostream>
#include<vector>
using namespace std;
// Striver Tree Series : Leetcode 1008. Construct Binary Search Tree from Preorder Traversal
// https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/

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
    // Here we have to modify vector & i so we pass it by reference
    Node * build(vector<int> &preorder, int &i, int upperBound){
        // Edge Case
        if(i == preorder.size() || preorder[i] > upperBound)
            return NULL;
        
        // Creating new node for each element of preorder vector
        Node * root = new Node(preorder[i]);
        i++;
        // For left child we'll pass the upperBound as current node value
        root->left = build(preorder, i, root->data);
        // For right child we'll pass the upperBound as current root bound(INT_MAX) 
        root->right = build(preorder, i, upperBound);    

        return root;
    }

public:
    Node * bstFromPreorder(vector<int> &preorder){
        int i = 0;  // Here i is pointer to preorder vector
        return build(preorder, i, INT8_MAX);
    }
};

// Display BST
void displayBST(Node * root){
    if(root == NULL)
        return;

    cout << root->data << " ";
    displayBST(root->left);
    displayBST(root->right);
}

int main(){
    vector<int> preorder = {8,5,1,7,10,12};

    Solution obj;
    Node * result = obj.bstFromPreorder(preorder);

    displayBST(result);

    return 0;
}