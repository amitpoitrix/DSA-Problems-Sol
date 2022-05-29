#include<iostream>
using namespace std;
// Striver Tree Series : Leetcode 450. Delete Node in a BST
// https://leetcode.com/problems/delete-node-in-a-bst/
// TC - O(LogN), SC - O(1)
// There are Two Ways to delete a node in BST
// 1. Join currentNode->left to deleteNode->left & Join deleteNode->right to deleteNode->left largest node value
// 2. Join currentNode->left to deleteNode->right & Join deleteNode->left to deleteNode->right smallest node value  

struct Node{
    int val;
    Node * left;
    Node * right;

    Node(int data){
        this->val = data;
        this->left = NULL;
        this->right = NULL;
    }
};

class Solution {
private:
    Node * deleteHelper(Node * root){
        // Edge Case - if either leftChild or rightChild exist
        if(root->left == NULL)
            return root->right;
        else if(root->right == NULL)
            return root->left;

        Node * prev = root->left;
        while(prev->right){
            prev = prev->right;
        }
        // Now prev->right is NULL
        prev->right = root->right;

        return root->left;
    }
    
public:
    Node * deleteNode(Node * root, int key) {
        if(root == NULL)
            return root;
        if(root->val == key)
            return deleteHelper(root);
    
        Node * dummy = root;    // we'll take copy of root as this will modified

        while (root != NULL){
            if(key < root->val){
                // Check on Left Subtree
                if(root->left != NULL && root->left->val == key){
                    root->left = deleteHelper(root->left);
                    break;
                }
                else
                    root = root->left;
            }
            else{
                // Check on Right Subtree
                if(root->right != NULL && root->right->val == key){
                    root->right = deleteHelper(root->right);
                    break;
                }
                else
                    root = root->right;
            }
        }

        return dummy;
    }
};

// Display BST
void displayBST(Node * root){
    if(root == NULL)
        return;

    cout << root->val << " ";
    displayBST(root->left);
    displayBST(root->right);
}

int main(){
    Node * root = new Node(5);
    root->left = new Node(3);
    root->right = new Node(6);
    root->left->left = new Node(2);
    root->left->right = new Node(4);
    root->right->right = new Node(7);
    displayBST(root);
    cout << endl;

    Solution obj;
    int val = 3;
    Node * result = obj.deleteNode(root, val);
    displayBST(result);

    return 0;
}