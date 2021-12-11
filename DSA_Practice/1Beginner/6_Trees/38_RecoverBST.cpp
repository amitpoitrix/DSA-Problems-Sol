#include<iostream>
#include<stack>
using namespace std;
// Striver Tree Series : Leetcode 99. Recover Binary Search Tree
// Here mainly 2 nodes of BST is swapped so we have to recover this BST 

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
    Node * first;   // First doubtful element
    Node * middle;  // Element just next to first doubtfull element
    Node * second;  // Second doubtful element
    Node * prev;    // Iterator on inorder vector

    // Inorder BST -> Left Root Right
    void inorder(Node * root){
        if(root == NULL)
            return;
        
        // Left
        inorder(root->left);

        // Print
        if(prev != NULL && root->data < prev->data ){
            // if this is First violation
            if(first == NULL){
                first = prev;
                middle = root;
            }
            else{   // If this is second violation
                second = root;
            }
        }
        
        prev = root;

        // Right
        inorder(root->right);
    }

public:
    void recoverTree(Node * root){
        first = middle = second = prev = NULL;

        inorder(root);

        // Case 1 : If elements to be swapped are not adjacent
        if(first && second)
            swap(first->data, second->data);
        // Case 1 : If elements to be swapped are adjacent
        else if (first && middle)
            swap(first->data, middle->data);
    }
};

// Display Inorder BST
void displayBST(Node * root){
    if(root == NULL)
        return;
    
    displayBST(root->left);
    cout << root->data << " ";
    displayBST(root->right);
}

int main(){
    Node * root = new Node(1);
    root->left = new Node(3);
    root->left->right = new Node(2);

    Solution * sol = new Solution();

    sol->recoverTree(root);
    displayBST(root);

    return 0;
}