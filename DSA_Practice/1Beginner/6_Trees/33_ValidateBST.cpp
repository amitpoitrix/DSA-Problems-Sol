#include<iostream>
using namespace std;
// Striver Tree Series : Leetcode 98. Validate Binary Search Tree
// https://leetcode.com/problems/validate-binary-search-tree/
// Check whether a given BT is BST or not

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

// Approach 1 
class Solution{
private:
    bool validateBST(Node * root, Node * minValue, Node * maxValue){
        if(root == NULL)
            return true;
    
        if(minValue && minValue->data >= root->data || maxValue && root->data >= maxValue->data)
            return false;
    
        return validateBST(root->left, minValue, root) && validateBST(root->right, root, maxValue);
    }

public:
    bool isValidBST(Node * root){
        return validateBST(root, NULL, NULL);
    }
};


// Approach 2 : Using the concept of Inorder Traversal of BST which is in sorted(Ascending) order
class Solution1{
private:
    bool validateBST2(Node * root, Node * &prev){
        if(root == NULL)
            return true;
        // Acc. to InOrder Traversal - Left Root Right
        // First we'll check Left
        if(!validateBST2(root->left, prev))
            return false;
    
        // Print Root; Logic - if sorted order disrupt than return false
        if(prev != NULL && prev->data >= root->data)
            return false;
    
        prev = root;

        // Then we'll check right
        return validateBST2(root->right, prev);
    }

public:
    bool isValidBST2(Node * root){
        Node * prev = NULL;
        return validateBST2(root, prev);
    }
};

int main(){
    Node * root = new Node(5);
    root->left = new Node(1);
    root->right = new Node(7);
    root->right->left = new Node(6);
    root->right->right = new Node(8);

    Solution1 obj;
    if(obj.isValidBST2(root))
        cout << "Yes its a valid BST" << endl;
    else
        cout << "No its not a valid BST" << endl;

    return 0;
}